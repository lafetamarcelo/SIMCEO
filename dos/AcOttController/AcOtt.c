/*
 * File: AcOtt.c
 *
 * Code generated for Simulink model 'AcOtt'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Wed Sep  4 11:25:36 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AcOtt.h"
#include "AcOtt_private.h"

/* Block states (default storage) */
DW_AcOtt_T AcOtt_DW;

/* External inputs (root inport signals with default storage) */
ExtU_AcOtt_T AcOtt_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_AcOtt_T AcOtt_Y;

/* Real-time model */
RT_MODEL_AcOtt_T AcOtt_M_;
RT_MODEL_AcOtt_T *const AcOtt_M = &AcOtt_M_;

/* Model step function */
void AcOtt_step(void)
{
  real_T denAccum;
  int32_T k;
  int32_T j;
  real_T tmp[21];
  real_T tmp_0[21];
  real_T TTOpticalController_tmp[21];
  int32_T k_0;
  int_T Delay1_DSTATE_tmp;
  for (k = 0; k < 21; k++) {
    /* DiscreteFilter: '<S2>/TTOpticalController' incorporates:
     *  Delay: '<S2>/Delay1'
     *  Delay: '<S2>/Delay1'
     */
    denAccum = AcOtt_DW.Delay1_DSTATE[k] -
      (-AcOtt_DW.TTOpticalController_states[k]);
    TTOpticalController_tmp[k] = denAccum;
    denAccum *= 0.012566370614359173;

    /* Outport: '<Root>/Output' incorporates:
     *  Delay: '<S2>/Delay1'
     *  DiscreteFilter: '<S2>/TTOpticalController'
     *  DiscreteFilter: '<S2>/TTOpticalController'
     */
    AcOtt_Y.Output[k] = 0.0 * AcOtt_DW.TTOpticalController_states[k] + denAccum;
  }

  /* Update for Delay: '<S2>/Delay1' incorporates:
   *  DiscreteFilter: '<S2>/TTOpticalController'
   *  DiscreteFilter: '<S2>/TTOpticalController'
   */
  k_0 = 0;
  for (k = 0; k < 14; k++) {
    for (j = 0; j < 21; j++) {
      Delay1_DSTATE_tmp = j + k_0;
      AcOtt_DW.Delay1_DSTATE[Delay1_DSTATE_tmp] =
        AcOtt_DW.Delay1_DSTATE[Delay1_DSTATE_tmp + 21];
    }

    k_0 += 21;
  }

  /* Gain: '<S1>/PsuedoCEO LOS1' incorporates:
   *  Gain: '<S2>/Remove Piston'
   *  Inport: '<Root>/Feedback'
   */
  for (k_0 = 0; k_0 < 21; k_0++) {
    tmp[k_0] = 0.0;
    j = 0;
    for (k = 0; k < 84; k++) {
      tmp[k_0] += AcOtt_ConstP.PsuedoCEOLOS1_Gain[j + k_0] * AcOtt_U.Feedback[k];
      j += 21;
    }
  }

  /* End of Gain: '<S1>/PsuedoCEO LOS1' */

  /* Sum: '<S2>/Sum1' incorporates:
   *  Gain: '<S2>/LOS2PTT'
   *  Gain: '<S2>/Remove Piston'
   *  Inport: '<Root>/Reference'
   */
  for (k_0 = 0; k_0 < 21; k_0++) {
    denAccum = 0.0;
    j = 0;
    for (k = 0; k < 21; k++) {
      denAccum += AcOtt_ConstP.RemovePiston_Gain[j + k_0] * tmp[k];
      j += 21;
    }

    tmp_0[k_0] = AcOtt_U.Reference[k_0] - denAccum;
  }

  /* End of Sum: '<S2>/Sum1' */
  for (k = 0; k < 21; k++) {
    /* Update for Delay: '<S2>/Delay1' incorporates:
     *  Gain: '<S2>/LOS2PTT'
     */
    AcOtt_DW.Delay1_DSTATE[k + 294] = 0.0;
    k_0 = 0;
    for (j = 0; j < 21; j++) {
      AcOtt_DW.Delay1_DSTATE[k + 294] += AcOtt_ConstP.LOS2PTT_Gain[k_0 + k] *
        tmp_0[j];
      k_0 += 21;
    }

    /* Update for DiscreteFilter: '<S2>/TTOpticalController' incorporates:
     *  Gain: '<S2>/LOS2PTT'
     */
    AcOtt_DW.TTOpticalController_states[k] = TTOpticalController_tmp[k];
  }
}

/* Model initialize function */
void AcOtt_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(AcOtt_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&AcOtt_DW, 0,
                sizeof(DW_AcOtt_T));

  /* external inputs */
  (void)memset((void *)&AcOtt_U, 0, sizeof(ExtU_AcOtt_T));

  /* external outputs */
  (void) memset(&AcOtt_Y.Output[0], 0,
                21U*sizeof(real_T));
}

/* Model terminate function */
void AcOtt_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
