/*
 * File: M1Pos.c
 *
 * Code generated for Simulink model 'M1Pos'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Wed Sep  4 11:54:33 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M1Pos.h"
#include "M1Pos_private.h"

/* Block states (default storage) */
DW_M1Pos_T M1Pos_DW;

/* External inputs (root inport signals with default storage) */
ExtU_M1Pos_T M1Pos_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_M1Pos_T M1Pos_Y;

/* Real-time model */
RT_MODEL_M1Pos_T M1Pos_M_;
RT_MODEL_M1Pos_T *const M1Pos_M = &M1Pos_M_;

/* Model step function */
void M1Pos_step(void)
{
  int32_T k;
  real_T denAccum;
  int32_T memOffset;
  real_T rtb_HpK8[6];
  real_T rtb_HpK3[6];
  real_T rtb_HpK4[6];
  real_T rtb_HpK5[6];
  real_T rtb_HpK6[6];
  real_T rtb_HpK1[6];
  real_T rtb_HpK2[6];
  int32_T rtb_HpK8_tmp;
  for (k = 0; k < 6; k++) {
    /* DiscreteFilter: '<S1>/Discrete Filter' incorporates:
     *  Gain: '<S1>/HpK8'
     */
    memOffset = k << 2;
    rtb_HpK8[k] = (((M1Pos_DW.DiscreteFilter_states[memOffset + 1] *
                     -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                     M1Pos_DW.DiscreteFilter_states[memOffset]) +
                    M1Pos_DW.DiscreteFilter_states[memOffset + 2] *
                    -5.40605452685298E-5) +
                   M1Pos_DW.DiscreteFilter_states[memOffset + 3] *
                   5.4366873931528294E-5) * 1.5743999886111712E+8;
  }

  for (k = 0; k < 6; k++) {
    /* DiscreteFilter: '<S1>/Discrete Filter3' incorporates:
     *  Gain: '<S1>/HpK3'
     */
    memOffset = k << 2;
    rtb_HpK3[k] = (((M1Pos_DW.DiscreteFilter3_states[memOffset + 1] *
                     -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                     M1Pos_DW.DiscreteFilter3_states[memOffset]) +
                    M1Pos_DW.DiscreteFilter3_states[memOffset + 2] *
                    -5.40605452685298E-5) +
                   M1Pos_DW.DiscreteFilter3_states[memOffset + 3] *
                   5.4366873931528294E-5) * 1.5743999886111712E+8;
  }

  for (k = 0; k < 6; k++) {
    /* DiscreteFilter: '<S1>/Discrete Filter4' incorporates:
     *  Gain: '<S1>/HpK4'
     */
    memOffset = k << 2;
    rtb_HpK4[k] = (((M1Pos_DW.DiscreteFilter4_states[memOffset + 1] *
                     -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                     M1Pos_DW.DiscreteFilter4_states[memOffset]) +
                    M1Pos_DW.DiscreteFilter4_states[memOffset + 2] *
                    -5.40605452685298E-5) +
                   M1Pos_DW.DiscreteFilter4_states[memOffset + 3] *
                   5.4366873931528294E-5) * 1.5743999886111712E+8;
  }

  for (k = 0; k < 6; k++) {
    /* DiscreteFilter: '<S1>/Discrete Filter5' incorporates:
     *  Gain: '<S1>/HpK5'
     */
    memOffset = k << 2;
    rtb_HpK5[k] = (((M1Pos_DW.DiscreteFilter5_states[memOffset + 1] *
                     -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                     M1Pos_DW.DiscreteFilter5_states[memOffset]) +
                    M1Pos_DW.DiscreteFilter5_states[memOffset + 2] *
                    -5.40605452685298E-5) +
                   M1Pos_DW.DiscreteFilter5_states[memOffset + 3] *
                   5.4366873931528294E-5) * 1.5743999886111712E+8;
  }

  for (k = 0; k < 6; k++) {
    /* DiscreteFilter: '<S1>/Discrete Filter6' incorporates:
     *  Gain: '<S1>/HpK6'
     */
    memOffset = k << 2;
    rtb_HpK6[k] = (((M1Pos_DW.DiscreteFilter6_states[memOffset + 1] *
                     -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                     M1Pos_DW.DiscreteFilter6_states[memOffset]) +
                    M1Pos_DW.DiscreteFilter6_states[memOffset + 2] *
                    -5.40605452685298E-5) +
                   M1Pos_DW.DiscreteFilter6_states[memOffset + 3] *
                   5.4366873931528294E-5) * 1.5743999886111712E+8;
  }

  for (k = 0; k < 6; k++) {
    /* DiscreteFilter: '<S1>/Discrete Filter1' incorporates:
     *  Gain: '<S1>/HpK1'
     */
    memOffset = k << 2;
    rtb_HpK1[k] = (((M1Pos_DW.DiscreteFilter1_states[memOffset + 1] *
                     -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                     M1Pos_DW.DiscreteFilter1_states[memOffset]) +
                    M1Pos_DW.DiscreteFilter1_states[memOffset + 2] *
                    -5.40605452685298E-5) +
                   M1Pos_DW.DiscreteFilter1_states[memOffset + 3] *
                   5.4366873931528294E-5) * 1.5743999886111712E+8;
  }

  for (k = 0; k < 6; k++) {
    /* DiscreteFilter: '<S1>/Discrete Filter2' */
    memOffset = k << 2;
    rtb_HpK2[k] = ((M1Pos_DW.DiscreteFilter2_states[memOffset + 1] *
                    -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                    M1Pos_DW.DiscreteFilter2_states[memOffset]) +
                   M1Pos_DW.DiscreteFilter2_states[memOffset + 2] *
                   -5.40605452685298E-5) +
      M1Pos_DW.DiscreteFilter2_states[memOffset + 3] * 5.4366873931528294E-5;

    /* Gain: '<S1>/HpK2' */
    rtb_HpK2[k] *= 1.5743999886111712E+8;

    /* Outport: '<Root>/Output' */
    M1Pos_Y.Output[k] = rtb_HpK8[k];
    M1Pos_Y.Output[k + 6] = rtb_HpK1[k];
    M1Pos_Y.Output[k + 12] = rtb_HpK2[k];
    M1Pos_Y.Output[k + 18] = rtb_HpK3[k];
    M1Pos_Y.Output[k + 24] = rtb_HpK4[k];
    M1Pos_Y.Output[k + 30] = rtb_HpK5[k];
    M1Pos_Y.Output[k + 36] = rtb_HpK6[k];

    /* Gain: '<S1>/CG2Hp1' */
    rtb_HpK8[k] = 0.0;

    /* Gain: '<S1>/CG2Hp2' */
    rtb_HpK3[k] = 0.0;

    /* Gain: '<S1>/CG2Hp3' */
    rtb_HpK4[k] = 0.0;

    /* Gain: '<S1>/CG2Hp4' */
    rtb_HpK5[k] = 0.0;

    /* Gain: '<S1>/CG2Hp5' */
    rtb_HpK6[k] = 0.0;

    /* Gain: '<S1>/CG2Hp6' */
    rtb_HpK1[k] = 0.0;

    /* Gain: '<S1>/CG2Hp8' */
    rtb_HpK2[k] = 0.0;
    for (memOffset = 0; memOffset < 6; memOffset++) {
      /* Gain: '<S1>/CG2Hp1' incorporates:
       *  Gain: '<S1>/CG2Hp2'
       *  Gain: '<S1>/CG2Hp3'
       *  Gain: '<S1>/CG2Hp4'
       *  Gain: '<S1>/CG2Hp5'
       *  Gain: '<S1>/CG2Hp6'
       *  Gain: '<S1>/CG2Hp8'
       *  Inport: '<Root>/Feedback'
       */
      rtb_HpK8_tmp = 6 * memOffset + k;
      rtb_HpK8[k] += M1Pos_ConstP.CG2Hp1_Gain[rtb_HpK8_tmp] * M1Pos_U.Feedback
        [12 + memOffset];

      /* Gain: '<S1>/CG2Hp2' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      rtb_HpK3[k] += M1Pos_ConstP.CG2Hp2_Gain[rtb_HpK8_tmp] * M1Pos_U.Feedback
        [18 + memOffset];

      /* Gain: '<S1>/CG2Hp3' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      rtb_HpK4[k] += M1Pos_ConstP.CG2Hp3_Gain[rtb_HpK8_tmp] * M1Pos_U.Feedback
        [24 + memOffset];

      /* Gain: '<S1>/CG2Hp4' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      rtb_HpK5[k] += M1Pos_ConstP.CG2Hp4_Gain[rtb_HpK8_tmp] * M1Pos_U.Feedback
        [30 + memOffset];

      /* Gain: '<S1>/CG2Hp5' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      rtb_HpK6[k] += M1Pos_ConstP.CG2Hp5_Gain[rtb_HpK8_tmp] * M1Pos_U.Feedback
        [36 + memOffset];

      /* Gain: '<S1>/CG2Hp6' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      rtb_HpK1[k] += M1Pos_ConstP.CG2Hp6_Gain[rtb_HpK8_tmp] *
        M1Pos_U.Feedback[memOffset];

      /* Gain: '<S1>/CG2Hp8' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      rtb_HpK2[k] += M1Pos_ConstP.CG2Hp8_Gain[rtb_HpK8_tmp] * M1Pos_U.Feedback[6
        + memOffset];
    }
  }

  /* Update for DiscreteFilter: '<S1>/Discrete Filter' */
  for (k = 0; k < 6; k++) {
    memOffset = k << 2;
    denAccum = (((rtb_HpK1[k] - -3.9658259936667708 *
                  M1Pos_DW.DiscreteFilter_states[memOffset]) -
                 M1Pos_DW.DiscreteFilter_states[memOffset + 1] *
                 5.8976852476007764) - M1Pos_DW.DiscreteFilter_states[memOffset
                + 2] * -3.8978920261025323) -
      M1Pos_DW.DiscreteFilter_states[memOffset + 3] * 0.96603277266632026;
    M1Pos_DW.DiscreteFilter_states[memOffset + 3] =
      M1Pos_DW.DiscreteFilter_states[memOffset + 2];
    M1Pos_DW.DiscreteFilter_states[memOffset + 2] =
      M1Pos_DW.DiscreteFilter_states[memOffset + 1];
    M1Pos_DW.DiscreteFilter_states[memOffset + 1] =
      M1Pos_DW.DiscreteFilter_states[memOffset];
    M1Pos_DW.DiscreteFilter_states[memOffset] = denAccum;
  }

  /* End of Update for DiscreteFilter: '<S1>/Discrete Filter' */

  /* Update for DiscreteFilter: '<S1>/Discrete Filter3' */
  for (k = 0; k < 6; k++) {
    memOffset = k << 2;
    denAccum = (((rtb_HpK3[k] - -3.9658259936667708 *
                  M1Pos_DW.DiscreteFilter3_states[memOffset]) -
                 M1Pos_DW.DiscreteFilter3_states[memOffset + 1] *
                 5.8976852476007764) - M1Pos_DW.DiscreteFilter3_states[memOffset
                + 2] * -3.8978920261025323) -
      M1Pos_DW.DiscreteFilter3_states[memOffset + 3] * 0.96603277266632026;
    M1Pos_DW.DiscreteFilter3_states[memOffset + 3] =
      M1Pos_DW.DiscreteFilter3_states[memOffset + 2];
    M1Pos_DW.DiscreteFilter3_states[memOffset + 2] =
      M1Pos_DW.DiscreteFilter3_states[memOffset + 1];
    M1Pos_DW.DiscreteFilter3_states[memOffset + 1] =
      M1Pos_DW.DiscreteFilter3_states[memOffset];
    M1Pos_DW.DiscreteFilter3_states[memOffset] = denAccum;
  }

  /* End of Update for DiscreteFilter: '<S1>/Discrete Filter3' */

  /* Update for DiscreteFilter: '<S1>/Discrete Filter4' */
  for (k = 0; k < 6; k++) {
    memOffset = k << 2;
    denAccum = (((rtb_HpK4[k] - -3.9658259936667708 *
                  M1Pos_DW.DiscreteFilter4_states[memOffset]) -
                 M1Pos_DW.DiscreteFilter4_states[memOffset + 1] *
                 5.8976852476007764) - M1Pos_DW.DiscreteFilter4_states[memOffset
                + 2] * -3.8978920261025323) -
      M1Pos_DW.DiscreteFilter4_states[memOffset + 3] * 0.96603277266632026;
    M1Pos_DW.DiscreteFilter4_states[memOffset + 3] =
      M1Pos_DW.DiscreteFilter4_states[memOffset + 2];
    M1Pos_DW.DiscreteFilter4_states[memOffset + 2] =
      M1Pos_DW.DiscreteFilter4_states[memOffset + 1];
    M1Pos_DW.DiscreteFilter4_states[memOffset + 1] =
      M1Pos_DW.DiscreteFilter4_states[memOffset];
    M1Pos_DW.DiscreteFilter4_states[memOffset] = denAccum;
  }

  /* End of Update for DiscreteFilter: '<S1>/Discrete Filter4' */

  /* Update for DiscreteFilter: '<S1>/Discrete Filter5' */
  for (k = 0; k < 6; k++) {
    memOffset = k << 2;
    denAccum = (((rtb_HpK5[k] - -3.9658259936667708 *
                  M1Pos_DW.DiscreteFilter5_states[memOffset]) -
                 M1Pos_DW.DiscreteFilter5_states[memOffset + 1] *
                 5.8976852476007764) - M1Pos_DW.DiscreteFilter5_states[memOffset
                + 2] * -3.8978920261025323) -
      M1Pos_DW.DiscreteFilter5_states[memOffset + 3] * 0.96603277266632026;
    M1Pos_DW.DiscreteFilter5_states[memOffset + 3] =
      M1Pos_DW.DiscreteFilter5_states[memOffset + 2];
    M1Pos_DW.DiscreteFilter5_states[memOffset + 2] =
      M1Pos_DW.DiscreteFilter5_states[memOffset + 1];
    M1Pos_DW.DiscreteFilter5_states[memOffset + 1] =
      M1Pos_DW.DiscreteFilter5_states[memOffset];
    M1Pos_DW.DiscreteFilter5_states[memOffset] = denAccum;
  }

  /* End of Update for DiscreteFilter: '<S1>/Discrete Filter5' */

  /* Update for DiscreteFilter: '<S1>/Discrete Filter6' */
  for (k = 0; k < 6; k++) {
    memOffset = k << 2;
    denAccum = (((rtb_HpK6[k] - -3.9658259936667708 *
                  M1Pos_DW.DiscreteFilter6_states[memOffset]) -
                 M1Pos_DW.DiscreteFilter6_states[memOffset + 1] *
                 5.8976852476007764) - M1Pos_DW.DiscreteFilter6_states[memOffset
                + 2] * -3.8978920261025323) -
      M1Pos_DW.DiscreteFilter6_states[memOffset + 3] * 0.96603277266632026;
    M1Pos_DW.DiscreteFilter6_states[memOffset + 3] =
      M1Pos_DW.DiscreteFilter6_states[memOffset + 2];
    M1Pos_DW.DiscreteFilter6_states[memOffset + 2] =
      M1Pos_DW.DiscreteFilter6_states[memOffset + 1];
    M1Pos_DW.DiscreteFilter6_states[memOffset + 1] =
      M1Pos_DW.DiscreteFilter6_states[memOffset];
    M1Pos_DW.DiscreteFilter6_states[memOffset] = denAccum;
  }

  /* End of Update for DiscreteFilter: '<S1>/Discrete Filter6' */

  /* Update for DiscreteFilter: '<S1>/Discrete Filter1' */
  for (k = 0; k < 6; k++) {
    memOffset = k << 2;
    denAccum = (((rtb_HpK2[k] - -3.9658259936667708 *
                  M1Pos_DW.DiscreteFilter1_states[memOffset]) -
                 M1Pos_DW.DiscreteFilter1_states[memOffset + 1] *
                 5.8976852476007764) - M1Pos_DW.DiscreteFilter1_states[memOffset
                + 2] * -3.8978920261025323) -
      M1Pos_DW.DiscreteFilter1_states[memOffset + 3] * 0.96603277266632026;
    M1Pos_DW.DiscreteFilter1_states[memOffset + 3] =
      M1Pos_DW.DiscreteFilter1_states[memOffset + 2];
    M1Pos_DW.DiscreteFilter1_states[memOffset + 2] =
      M1Pos_DW.DiscreteFilter1_states[memOffset + 1];
    M1Pos_DW.DiscreteFilter1_states[memOffset + 1] =
      M1Pos_DW.DiscreteFilter1_states[memOffset];
    M1Pos_DW.DiscreteFilter1_states[memOffset] = denAccum;
  }

  /* End of Update for DiscreteFilter: '<S1>/Discrete Filter1' */

  /* Update for DiscreteFilter: '<S1>/Discrete Filter2' */
  for (k = 0; k < 6; k++) {
    memOffset = k << 2;
    denAccum = (((rtb_HpK8[k] - -3.9658259936667708 *
                  M1Pos_DW.DiscreteFilter2_states[memOffset]) -
                 M1Pos_DW.DiscreteFilter2_states[memOffset + 1] *
                 5.8976852476007764) - M1Pos_DW.DiscreteFilter2_states[memOffset
                + 2] * -3.8978920261025323) -
      M1Pos_DW.DiscreteFilter2_states[memOffset + 3] * 0.96603277266632026;
    M1Pos_DW.DiscreteFilter2_states[memOffset + 3] =
      M1Pos_DW.DiscreteFilter2_states[memOffset + 2];
    M1Pos_DW.DiscreteFilter2_states[memOffset + 2] =
      M1Pos_DW.DiscreteFilter2_states[memOffset + 1];
    M1Pos_DW.DiscreteFilter2_states[memOffset + 1] =
      M1Pos_DW.DiscreteFilter2_states[memOffset];
    M1Pos_DW.DiscreteFilter2_states[memOffset] = denAccum;
  }

  /* End of Update for DiscreteFilter: '<S1>/Discrete Filter2' */
}

/* Model initialize function */
void M1Pos_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(M1Pos_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&M1Pos_DW, 0,
                sizeof(DW_M1Pos_T));

  /* external inputs */
  (void)memset((void *)&M1Pos_U, 0, sizeof(ExtU_M1Pos_T));

  /* external outputs */
  (void) memset(&M1Pos_Y.Output[0], 0,
                42U*sizeof(real_T));
}

/* Model terminate function */
void M1Pos_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
