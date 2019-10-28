cdef extern from "M2pzt.h":
	ctypedef double real_T
	ctypedef struct ExtU_M2pzt_T:
		real_T Reference[21] #                /* '<Root>/Reference' */
		real_T Feedback[42] #                /* '<Root>/Feedback' */
	ctypedef struct ExtY_M2pzt_T:
		real_T Output[42] #                  /* '<Root>/Output' */
	ExtU_M2pzt_T M2pzt_U
	ExtY_M2pzt_T M2pzt_Y
	void M2pzt_initialize()
	void M2pzt_step()
	void M2pzt_terminate()

cimport numpy as np
import numpy as np

class M2pzt: 

	'''
	This class was automatically generated from the simulink subsystem 'M2pzt'.

	For more information on how this code was generated access:
	https://github.com/feippolito/NSEElib/tree/master/MATLAB/%2Bcompile - pycreate.m

	Generated on 04-Sep-2019.
	'''

	def __init__(self, reference = np.zeros(21)):
		self.reference = reference
		self.__yout = np.zeros(0)

	def init(self):
		M2pzt_initialize()
		for k in range(21):
			M2pzt_U.Reference[k] = self.reference[k]
		self.__yout = np.zeros(42)

	def update(self, np.ndarray u):
		cdef double[:] __u
		cdef int k
		__u = np.ravel(np.asarray(u))
		for k in range(42):
			M2pzt_U.Feedback[k] = __u[k]
		M2pzt_step()

	def output(self):
		cdef int k
		for k in range(42):
			self.__yout[k] = M2pzt_Y.Output[k]
		return np.atleast_2d(self.__yout)

	def terminate(self):
		M2pzt_terminate()