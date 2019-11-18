import cupy as cp
import numpy as np

import pickle
import logging
import h5py

import scipy.io as spio
import scipy.signal as ssig


DEFAULT_ITEMS = ["CRING", "GIR", 
                "M1", "M1Cell", 
                "M2", "M2Cell", 
                "Truss", "TopEnd"]


class WindLoad:

    '''
        The wind loads class that runs in CUDA-GPU.
    '''

    def __init__(self, verbose=logging.INFO, **kwargs):
        self.logger = logging.getLogger(self.__class__.__name__)
        self.logger.setLevel(verbose)
        self.logger.info('Instantiate')
        if kwargs:
            self.Start(**kwargs)

    def Start(self, 
                load_filename=None,
                distributed_filename=None,
                savefiles_path=None,
                bumpless_loads=False,
                fs=200):
        self.logger.info('Starting wind loads...')

        if savefiles_path is not None:
            self.savepath = savefiles_path
        else:
            self.savepath = './variables'
        self.fs = fs

        self.mem_data  = dict()
        if load_filename is not None:
            load_data = spio.loadmat(load_filename)['IMLoads']
            for element in DEFAULT_ITEMS:
                cpu_array = load_data[element][0,0]['signals'][0,0]['values'][0,0].T
                filename  = self.savepath + element + '.dat'
                fileshape = cpu_array.shape
                self.mem_data[element] = np.memmap(filename, dtype=np.float32, mode='w+', shape=fileshape)
                self.mem_data[element][:,:] = cpu_array[:,:]
                
                self.logger.info('  * ' + element + ' Memory Map:')
                fs = int(1 / load_data[element][0,0]['time'][0,0][1] - load_data[element][0,0]['time'][0,0][0])
                self.logger.info('   |- frequency: ' + str(fs) + ' (Hz)')
                self.logger.info('   |- shape: ' + str(fileshape))
                self.logger.info('   |- in: ' + filename)
                self.tmax_dim = fileshape[1]
        else:
            self.logger.info('No wind load file found!')
            self.tmax_dim = 0

        if distributed_filename is not None:
            distributed = h5py.File(distributed_filename, 'r')
            cpu_array = np.array(distributed['transientWindM1']['signals']['values'])
            filename  = self.savepath + 'Distributed.dat'
            fileshape = cpu_array.shape
            self.mem_data['Distributed'] = np.memmap(filename, dtype=np.float32, mode='w+', shape=fileshape)
            self.mem_data['Distributed'][:,:] = cpu_array[:,:]
            
            self.logger.info('  * ' + "Distributed" + ' Memory Map:')
            fs = int( 1 / distributed['transientWindM1']['time'][1] - distributed['transientWindM1']['time'][0])
            self.logger.info('   |- frequency: ' + str(fs) + ' (Hz)')
            self.logger.info('   |- shape: ' + str(fileshape))
            self.logger.info('   |- in: ' + filename)
            self.tmax_dim = min([self.tmax_dim, fileshape[1]])
        else:
            self.logger.info('No distributed wind file found!')

        filename, fileshape  = self.savepath + 'gravity.dat', (3, self.tmax_dim)
        self.mem_data['Gravity'] = np.memmap(filename, dtype=np.float32, mode='w+', shape=fileshape)
        self.mem_data['Gravity'][:2,:] = np.zeros((2, self.tmax_dim), dtype=np.float32)
        self.mem_data['Gravity'][2, :] = - np.ones((1, self.tmax_dim), dtype=np.float32)
        
        self.logger.info('  * ' + "Gravity" + ' Memory Map:')
        self.logger.info('   |- shape: ' + str(fileshape))
        self.logger.info('   |- in: ' + filename)

        if bumpless_loads:
            self.logger.info(' ** Computing bumpless filter...')
            self.bumpless_fitler()

        self.logger.info('*** SIMULATION MAXIMUM TIME: ' + str(self.tmax_dim / fs) + ' seconds!!')

        return "WindLoad"

    def bumpless_fitler(self):

        dt = 1 / self.fs    
        time_vec = dt * np.array(range(self.tmax_dim))

        # Create the bumpless discrete filter
        settling_time = 3 # (seconds)
        bump_filt_ctf = ((4.5/settling_time)**2, [1, 2*4/settling_time, (4.5/settling_time)**2])
        bump_filt = ssig.cont2discrete(bump_filt_ctf, dt)

        for element in DEFAULT_ITEMS:
            offset = self.mem_data[element][:,0]
            smooth_offset = np.zeros((self.mem_data[element].shape), dtype=np.float32)
            response = ssig.step(bump_filt, T=time_vec)[0]
            for k in range(offset.shape[0]):
                smooth_offset[k,:] = offset[k] * response
            # Compute the bumpless signals
            offset = offset.reshape(offset.shape[0], 1)
            self.mem_data[element][:,:] = self.mem_data[element][:,:] + smooth_offset - offset


    def Init(self, dt=0.5e-3, fs=20 ,
            inputs=None, outputs=None):
        
        self.dt = dt
        self.k : int = 0
        self.time_ref : int = 0
        self.i : int = 0

        Tv : float = 1 / fs
        self.pv = int( np.ceil( Tv / dt ) )
        self.fv = int( 1 / Tv)

        self.b_coefs,  self.a_coefs = dict(), dict()
        self.gpu_data, self.outputs = dict(), dict()
        for element in self.mem_data:
            cpu_array = self.mem_data[element][:,0:2].view(dtype=np.float32, type=np.ndarray)
            self.gpu_data[element] = cp.asarray(cpu_array, dtype=np.float32)

    
    def Update(self, **kwargs):
        
        for s in self.gpu_data:
            if (self.k % self.pv) == 0: # if rigth moment
                cpu_array = self.mem_data[s][:,self.i:self.i+2].view(dtype=np.float32, type=np.ndarray)
                self.gpu_data[s] = cp.asarray(cpu_array, dtype=np.float32)
                # update the coefficients
                self.b_coefs[s] = self.gpu_data[s][:,0]
                # user defined kernel to get coeficient
                self.a_coefs[s] = getcoef(self.fv, self.gpu_data[s][:,1], self.b_coefs[s])
        
        if (self.k % self.pv) == 0: # if rigth moment
            self.i, self.time_ref = self.i + 1, self.k # update indexes

        t_k = (self.k - self.time_ref) * self.dt               # determine the reference moment
        for s in self.gpu_data:
            gpu_array = getwind(self.a_coefs[s], self.b_coefs[s], t_k) # interpolate v_k -- user defined kernel
            self.outputs[s] = gpu_array.get()
        
        self.k =  self.k + 1

    def Outputs(self, **kwargs):
        
        return self.outputs

    def Terminate(self, **kwargs):
        return "Wind loads deleted!"
        



getwind = cp.ElementwiseKernel(
    'T a, T b, T t',
    'T v',
    '''
        v = a * t + b
    ''',
    'getwind'
)

getcoef = cp.ElementwiseKernel(
    'T a, T vii, T vi',
    'T v',
    '''
        v = a * ( vii - vi )
    ''',
    'getwind'
)

@cp.fuse()
def getCoef(a,vi,v):
    return a * (vi-v)

@cp.fuse()
def getWind(a,b,t):
    return a * t + b