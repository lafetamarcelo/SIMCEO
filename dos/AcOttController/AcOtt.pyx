cdef extern from "AcOtt.h":
	ctypedef double real_T
	ctypedef struct ExtU_AcOtt_T:
		real_T Reference[21] #                /* '<Root>/Reference' */
		real_T Feedback[84] #                /* '<Root>/Feedback' */
	ctypedef struct ExtY_AcOtt_T:
		real_T Output[21] #                  /* '<Root>/Output' */
	ExtU_AcOtt_T AcOtt_U
	ExtY_AcOtt_T AcOtt_Y
	void AcOtt_initialize()
	void AcOtt_step()
	void AcOtt_terminate()

cimport numpy as np
import numpy as np

class AcOtt: 

	'''
	This class was automatically generated from the simulink subsystem 'AcOtt'.

	For more information on how this code was generated access:
	https://github.com/feippolito/NSEElib/tree/master/MATLAB/%2Bcompile - pycreate.m

	Generated on 04-Sep-2019.
	'''

	def __init__(self, reference = np.zeros(21)):
		self.reference = reference
		self.__yout = np.zeros(0)

	def init(self):
		AcOtt_initialize()
		for k in range(21):
			AcOtt_U.Reference[k] = self.reference[k]
		self.__yout = np.zeros(21)

	def update(self, np.ndarray u):
		cdef double[:] __u
		cdef int k
		__u = np.ravel(np.asarray(u))
		for k in range(84):
			AcOtt_U.Feedback[k] = __u[k]
		AcOtt_step()

	def output(self):
		cdef int k
		for k in range(21):
			self.__yout[k] = AcOtt_Y.Output[k]
		return np.atleast_2d(self.__yout)

	def terminate(self):
		AcOtt_terminate()