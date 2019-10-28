cdef extern from "AcOshPos.h":
	ctypedef double real_T
	ctypedef struct ExtU_AcOshPos_T:
		real_T Reference[42] #                /* '<Root>/Reference' */
		real_T Feedback[42] #                /* '<Root>/Feedback' */
	ctypedef struct ExtY_AcOshPos_T:
		real_T Output[42] #                  /* '<Root>/Output' */
	ExtU_AcOshPos_T AcOshPos_U
	ExtY_AcOshPos_T AcOshPos_Y
	void AcOshPos_initialize()
	void AcOshPos_step()
	void AcOshPos_terminate()

cimport numpy as np
import numpy as np

class AcOshPos: 

	def __init__(self, reference = np.zeros(42)):
		self.reference = reference
		self.__yout = np.zeros(42)

	def init(self):
		AcOshPos_initialize()
		for k in range(42):
			AcOshPos_U.Reference[k] = self.reference[k]
		self.__yout = np.zeros(42)

	def update(self, np.ndarray u):
		cdef double[:] __u
		cdef int k
		__u = np.ravel(np.asarray(u))
		for k in range(42):
			AcOshPos_U.Feedback[k] = __u[k]
		AcOshPos_step()

	def output(self):
		cdef int k
		for k in range(42):
			self.__yout[k] = AcOshPos_Y.Output[k]
		return np.atleast_2d(self.__yout)

	def terminate(self):
		AcOshPos_terminate()