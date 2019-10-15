cdef extern from "M1Pos.h":
	ctypedef double real_T
	ctypedef struct ExtU_M1Pos_T:
		real_T Feedback[42] #                /* '<Root>/Feedback' */
	ctypedef struct ExtY_M1Pos_T:
		real_T Output[42] #                  /* '<Root>/Output' */
	ExtU_M1Pos_T M1Pos_U
	ExtY_M1Pos_T M1Pos_Y
	void M1Pos_initialize()
	void M1Pos_step()
	void M1Pos_terminate()

cimport numpy as np
import numpy as np

class M1Pos: 

	def __init__(self, reference = np.zeros(1)):
		self.reference = reference
		self.__yout = np.zeros(0)

	def init(self):
		M1Pos_initialize()
		self.__yout = np.zeros(42)

	def update(self, np.ndarray u):
		#cdef double[:] __u
		cdef int k
		if u == None:
			__u = np.ravel(np.zeros(42))
		else:
			__u = np.ravel(np.asarray(u))
		print("DEBUG------------- SUPPORT M1POS")
		print(u, __u)
		for k in range(42):
			M1Pos_U.Feedback[k] = __u[k]
		M1Pos_step()

	def output(self):
		cdef int k
		for k in range(42):
			self.__yout[k] = M1Pos_Y.Output[k]
		return np.atleast_2d(self.__yout)

	def terminate(self):
		M1Pos_terminate()