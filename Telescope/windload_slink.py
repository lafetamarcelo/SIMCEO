import cupy as cp
import numpy as np

import pickle
import logging
import h5py

import scipy.io as spio


DEFAULT_ITEMS = ["CRING", "GIR", 
                "M1", "M1Cell", 
                "M2", "M2Cell", 
                "Truss", "TopEnd"]


class Windloads:
    def __init__(self, verbose=logging.INFO, **kwargs):
        self.logger = logging.getLogger(self.__class__.__name__)
        self.logger.setLevel(verbose)
        self.logger.info('Instantiate')
        if kwargs:
            self.Start(**kwargs)

    def Start(self, load_filename=None,
                distributed_filename=None,
                savefiles_path=None):
        self.logger.info('Starting wind loads...')

        if savefiles_path is not None:
            self.savepath = savefiles_path
        else:
            self.savepath = './'

        self.mem_data  = dict()
        if load_filename is not None:
            load_data = spio.loadmat(load_filename)['IMLoads']
            for element in DEFAULT_ITEMS:
                cpu_array = load_data[element][0,0]['signals'][0,0]['values'][0,0].T
                filename  = self.savepath + '/' + element + '.dat'
                fileshape = cpu_array.shape
                self.mem_data[element] = np.memmap(filename, dtype=np.float32, mode='w+', shape=fileshape)
        else:
            self.logger.info('No wind load file found!')

        if distributed_filename is not None:
            distributed = h5py.File(distributed_filename, 'r')
            cpu_array = np.array(distributed['transientWindM1']['signals']['values'])
            filename  = self.savepath + '/distributed.dat'
            fileshape = cpu_array.shape
            self.mem_data['distributed'] = np.memmap(filename, dtype=np.float32, mode='w+', shape=fileshape)
        else:
            self.logger.info('No distributed wind file found!')


    def Init(self, dt=0.5e-3, fs=20 ,
            inputs=None, outputs=None):
        
        self.dt = dt
        self.k : int = 0
        self.time_ref : int = 0
        self.i : int = 0

        Tv : float = 1 / fs
        self.pv = int( np.ceil( Tv / dt ) )
        self.fv = int( 1 / Tv)

        self.b_coefs,  self.a_coefs  = dict(), dict()
        self.gpu_data, self.outputs = dict(), dict()
        for element in self.mem_data:
            cpu_array = self.mem_data[element][:,0].view(dtype=np.float32, type=np.ndarray)
            self.gpu_data[element] = cp.asarray(cpu_array, dtype=np.float32)
    
    def Update(self):
        
        for s in self.gpu_data:
            if (self.k % self.pv) == 0: # if rigth moment
                # update the coefficients
                self.b_coefs[s] = self.gpu_data[s][:, self.i]
                # user defined kernel to get coeficient
                self.a_coefs[s] = getcoef(self.fv, self.gpu_data[s][:, self.i + 1], self.b_coefs[s])
        
        if (self.k % self.pv) == 0: # if rigth moment
            self.i, self.time_ref = self.i + 1, self.k # update indexes

        t_k = (self.k - self.time_ref) * self.dt               # determine the reference moment
        for s in self.gpu_data:
            gpu_array = getwind(self.a_coefs[s], self.b_coefs[s], t_k) # interpolate v_k -- user defined kernel
            self.outputs[s] = gpu_array.get()
        
        self.k =  self.k + 1

    def Outputs(self, **kwargs):
        
        return self.outputs



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