cdef extern from "M1ofl.h":
	ctypedef double real_T
	ctypedef struct ExtU_M1ofl_T:
		real_T Reference[42] #                /* '<Root>/Reference' */
		real_T Feedback[84] #                /* '<Root>/Feedback' */
	ctypedef struct ExtY_M1ofl_T:
		real_T Output[2316] #                  /* '<Root>/Output' */
	ExtU_M1ofl_T M1ofl_U
	ExtY_M1ofl_T M1ofl_Y
	void M1ofl_initialize()
	void M1ofl_step()
	void M1ofl_terminate()

cimport numpy as np
import numpy as np

class M1ofl: 

	'''
	This class was automatically generated from the simulink subsystem 'M1ofl'.

	For more information on how this code was generated access:
	https://github.com/feippolito/NSEElib/tree/master/MATLAB/%2Bcompile - pycreate.m

	Generated on 04-Sep-2019.
	'''

	def __init__(self, reference = np.zeros(42)):
		self.reference = reference
		self.__yout = np.zeros(0)

	def init(self):
		M1ofl_initialize()
		for k in range(42):
			M1ofl_U.Reference[k] = self.reference[k]
		self.__yout = np.zeros(2316)

	def update(self, np.ndarray u):
		cdef double[:] __u
		cdef int k
		__u = np.ravel(np.asarray(u))
		for k in range(84):
			M1ofl_U.Feedback[k] = __u[k]
		M1ofl_step()

	def output(self):
		cdef int k
		for k in range(2316):
			self.__yout[k] = M1ofl_Y.Output[k]
		return np.atleast_2d(self.__yout)

	def terminate(self):
		M1ofl_terminate()