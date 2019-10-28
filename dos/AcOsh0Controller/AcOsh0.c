/*
 * File: AcOsh0.c
 *
 * Code generated for Simulink model 'AcOsh0'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Wed Sep  4 11:21:12 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AcOsh0.h"
#include "AcOsh0_private.h"

/* Block states (default storage) */
DW_AcOsh0_T AcOsh0_DW;

/* External inputs (root inport signals with default storage) */
ExtU_AcOsh0_T AcOsh0_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_AcOsh0_T AcOsh0_Y;

/* Real-time model */
RT_MODEL_AcOsh0_T AcOsh0_M_;
RT_MODEL_AcOsh0_T *const AcOsh0_M = &AcOsh0_M_;

/* Model step function */
void AcOsh0_step(void)
{
  real_T denAccum;
  int32_T i;
  for (i = 0; i < 42; i++) {
    /* DiscreteTransferFcn: '<S1>/Integral Control' incorporates:
     *  Inport: '<Root>/Feedback'
     *  Inport: '<Root>/Reference'
     *  Sum: '<S1>/Sum2'
     */
    denAccum = (AcOsh0_U.Reference[i] - AcOsh0_U.Feedback[i]) -
      (-AcOsh0_DW.IntegralControl_states[i]);
    AcOsh0_Y.Output[i] = 0.0031415926535897933 * denAccum + 0.0 *
      AcOsh0_DW.IntegralControl_states[i];

    /* Outport: '<Root>/Output' incorporates:
     *  Gain: '<S1>/Gain'
     */
    AcOsh0_Y.Output[i] *= 0.04;

    /* Update for DiscreteTransferFcn: '<S1>/Integral Control' */
    AcOsh0_DW.IntegralControl_states[i] = denAccum;
  }
}

/* Model initialize function */
void AcOsh0_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(AcOsh0_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&AcOsh0_DW, 0,
                sizeof(DW_AcOsh0_T));

  /* external inputs */
  (void)memset((void *)&AcOsh0_U, 0, sizeof(ExtU_AcOsh0_T));

  /* external outputs */
  (void) memset(&AcOsh0_Y.Output[0], 0,
                42U*sizeof(real_T));
}

/* Model terminate function */
void AcOsh0_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
