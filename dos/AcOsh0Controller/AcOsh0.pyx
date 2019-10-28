cdef extern from "AcOsh0.h":
	ctypedef double real_T
	ctypedef struct ExtU_AcOsh0_T:
		real_T Reference[42] #                /* '<Root>/Reference' */
		real_T Feedback[42] #                /* '<Root>/Feedback' */
	ctypedef struct ExtY_AcOsh0_T:
		real_T Output[42] #                  /* '<Root>/Output' */
	ExtU_AcOsh0_T AcOsh0_U
	ExtY_AcOsh0_T AcOsh0_Y
	void AcOsh0_initialize()
	void AcOsh0_step()
	void AcOsh0_terminate()

cimport numpy as np
import  numpy as np

class AcOsh0: 

	def __init__(self, reference = np.zeros(42)):
		self.reference = reference
		self.__yout = np.zeros(42)

	def init(self):
		AcOsh0_initialize()
		for k in range(42):
			AcOsh0_U.Reference[k] = self.reference[k]
		self.__yout = np.zeros(42)

	def update(self, np.ndarray u):
		cdef double[:] __u
		cdef int k
		__u = np.ravel(np.asarray(u))
		for k in range(42):
			AcOsh0_U.Feedback[k] = __u[k]
		AcOsh0_step()

	def output(self):
		cdef int k
		for k in range(42):
			self.__yout[k] = AcOsh0_Y.Output[k]
		return np.atleast_2d(self.__yout)

	def terminate(self):
		AcOsh0_terminate()