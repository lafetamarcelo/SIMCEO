/*
 * File: AcOshPos.c
 *
 * Code generated for Simulink model 'AcOshPos'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Mon Oct 14 18:51:21 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AcOshPos.h"
#include "AcOshPos_private.h"

/* Block states (default storage) */
DW_AcOshPos_T AcOshPos_DW;

/* External inputs (root inport signals with default storage) */
ExtU_AcOshPos_T AcOshPos_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_AcOshPos_T AcOshPos_Y;

/* Real-time model */
RT_MODEL_AcOshPos_T AcOshPos_M_;
RT_MODEL_AcOshPos_T *const AcOshPos_M = &AcOshPos_M_;

/* Model step function */
void AcOshPos_step(void)
{
  real_T denAccum;
  int32_T memOffset;
  int32_T memOffset_0;
  int32_T memOffset_1;
  int32_T memOffset_2;
  int32_T memOffset_3;
  int32_T memOffset_4;
  real_T rtb_Gain[42];
  real_T CG2Hp1[6];
  real_T CG2Hp2[6];
  real_T CG2Hp3[6];
  real_T CG2Hp4[6];
  real_T CG2Hp5[6];
  real_T CG2Hp6[6];
  real_T CG2Hp8[6];
  int32_T i;
  real_T IntegralControl_tmp[42];
  int32_T CG2Hp1_tmp;
  for (i = 0; i < 42; i++) {
    /* DiscreteTransferFcn: '<S1>/Integral Control' incorporates:
     *  Gain: '<S1>/Gain'
     *  Inport: '<Root>/Feedback'
     *  Inport: '<Root>/Reference'
     *  Sum: '<S1>/Sum2'
     */
    denAccum = (AcOshPos_U.Reference[i] - AcOshPos_U.Feedback[i]) -
      (-AcOshPos_DW.IntegralControl_states[i]);
    IntegralControl_tmp[i] = denAccum;
    rtb_Gain[i] = (0.0031415926535897933 * denAccum + 0.0 *
                   AcOshPos_DW.IntegralControl_states[i]) * 0.04;
  }

  for (i = 0; i < 6; i++) {
    /* Gain: '<S1>/CG2Hp1' */
    CG2Hp1[i] = 0.0;

    /* Gain: '<S1>/CG2Hp2' */
    CG2Hp2[i] = 0.0;

    /* Gain: '<S1>/CG2Hp3' */
    CG2Hp3[i] = 0.0;

    /* Gain: '<S1>/CG2Hp4' */
    CG2Hp4[i] = 0.0;

    /* Gain: '<S1>/CG2Hp5' */
    CG2Hp5[i] = 0.0;

    /* Gain: '<S1>/CG2Hp6' */
    CG2Hp6[i] = 0.0;

    /* Gain: '<S1>/CG2Hp8' */
    CG2Hp8[i] = 0.0;
    for (memOffset = 0; memOffset < 6; memOffset++) {
      /* Gain: '<S1>/CG2Hp1' incorporates:
       *  Gain: '<S1>/CG2Hp2'
       *  Gain: '<S1>/CG2Hp3'
       *  Gain: '<S1>/CG2Hp4'
       *  Gain: '<S1>/CG2Hp5'
       *  Gain: '<S1>/CG2Hp6'
       *  Gain: '<S1>/CG2Hp8'
       */
      CG2Hp1_tmp = 6 * memOffset + i;
      CG2Hp1[i] += AcOshPos_ConstP.CG2Hp1_Gain[CG2Hp1_tmp] * rtb_Gain[12 +
        memOffset];

      /* Gain: '<S1>/CG2Hp2' */
      CG2Hp2[i] += AcOshPos_ConstP.CG2Hp2_Gain[CG2Hp1_tmp] * rtb_Gain[18 +
        memOffset];

      /* Gain: '<S1>/CG2Hp3' */
      CG2Hp3[i] += AcOshPos_ConstP.CG2Hp3_Gain[CG2Hp1_tmp] * rtb_Gain[24 +
        memOffset];

      /* Gain: '<S1>/CG2Hp4' */
      CG2Hp4[i] += AcOshPos_ConstP.CG2Hp4_Gain[CG2Hp1_tmp] * rtb_Gain[30 +
        memOffset];

      /* Gain: '<S1>/CG2Hp5' */
      CG2Hp5[i] += AcOshPos_ConstP.CG2Hp5_Gain[CG2Hp1_tmp] * rtb_Gain[36 +
        memOffset];

      /* Gain: '<S1>/CG2Hp6' */
      CG2Hp6[i] += AcOshPos_ConstP.CG2Hp6_Gain[CG2Hp1_tmp] * rtb_Gain[memOffset];

      /* Gain: '<S1>/CG2Hp8' */
      CG2Hp8[i] += AcOshPos_ConstP.CG2Hp8_Gain[CG2Hp1_tmp] * rtb_Gain[6 +
        memOffset];
    }

    /* DiscreteFilter: '<S1>/Discrete Filter' */
    memOffset = i << 2;

    /* DiscreteFilter: '<S1>/Discrete Filter3' */
    CG2Hp1_tmp = i << 2;

    /* DiscreteFilter: '<S1>/Discrete Filter4' */
    memOffset_0 = i << 2;

    /* DiscreteFilter: '<S1>/Discrete Filter5' */
    memOffset_1 = i << 2;

    /* DiscreteFilter: '<S1>/Discrete Filter6' */
    memOffset_2 = i << 2;

    /* DiscreteFilter: '<S1>/Discrete Filter1' */
    memOffset_3 = i << 2;

    /* DiscreteFilter: '<S1>/Discrete Filter2' */
    memOffset_4 = i << 2;

    /* Outport: '<Root>/Output' incorporates:
     *  DiscreteFilter: '<S1>/Discrete Filter'
     *  DiscreteFilter: '<S1>/Discrete Filter1'
     *  DiscreteFilter: '<S1>/Discrete Filter2'
     *  DiscreteFilter: '<S1>/Discrete Filter3'
     *  DiscreteFilter: '<S1>/Discrete Filter4'
     *  DiscreteFilter: '<S1>/Discrete Filter5'
     *  DiscreteFilter: '<S1>/Discrete Filter6'
     *  Gain: '<S1>/HpK1'
     *  Gain: '<S1>/HpK2'
     *  Gain: '<S1>/HpK3'
     *  Gain: '<S1>/HpK4'
     *  Gain: '<S1>/HpK5'
     *  Gain: '<S1>/HpK6'
     *  Gain: '<S1>/HpK8'
     */
    AcOshPos_Y.Output[i] = (((AcOshPos_DW.DiscreteFilter_states[memOffset + 1] *
      -5.5465887689329465E-5 + 5.5160056819196816E-5 *
      AcOshPos_DW.DiscreteFilter_states[memOffset]) +
      AcOshPos_DW.DiscreteFilter_states[memOffset + 2] * -5.40605452685298E-5) +
      AcOshPos_DW.DiscreteFilter_states[memOffset + 3] * 5.4366873931528294E-5) *
      1.5743999886111712E+8;
    AcOshPos_Y.Output[i + 6] = (((AcOshPos_DW.DiscreteFilter1_states[memOffset_3
      + 1] * -5.5465887689329465E-5 + 5.5160056819196816E-5 *
      AcOshPos_DW.DiscreteFilter1_states[memOffset_3]) +
      AcOshPos_DW.DiscreteFilter1_states[memOffset_3 + 2] * -5.40605452685298E-5)
      + AcOshPos_DW.DiscreteFilter1_states[memOffset_3 + 3] *
      5.4366873931528294E-5) * 1.5743999886111712E+8;
    AcOshPos_Y.Output[i + 12] =
      (((AcOshPos_DW.DiscreteFilter2_states[memOffset_4 + 1] *
         -5.5465887689329465E-5 + 5.5160056819196816E-5 *
         AcOshPos_DW.DiscreteFilter2_states[memOffset_4]) +
        AcOshPos_DW.DiscreteFilter2_states[memOffset_4 + 2] *
        -5.40605452685298E-5) + AcOshPos_DW.DiscreteFilter2_states[memOffset_4 +
       3] * 5.4366873931528294E-5) * 1.5743999886111712E+8;
    AcOshPos_Y.Output[i + 18] = (((AcOshPos_DW.DiscreteFilter3_states[CG2Hp1_tmp
      + 1] * -5.5465887689329465E-5 + 5.5160056819196816E-5 *
      AcOshPos_DW.DiscreteFilter3_states[CG2Hp1_tmp]) +
      AcOshPos_DW.DiscreteFilter3_states[CG2Hp1_tmp + 2] * -5.40605452685298E-5)
      + AcOshPos_DW.DiscreteFilter3_states[CG2Hp1_tmp + 3] *
      5.4366873931528294E-5) * 1.5743999886111712E+8;
    AcOshPos_Y.Output[i + 24] =
      (((AcOshPos_DW.DiscreteFilter4_states[memOffset_0 + 1] *
         -5.5465887689329465E-5 + 5.5160056819196816E-5 *
         AcOshPos_DW.DiscreteFilter4_states[memOffset_0]) +
        AcOshPos_DW.DiscreteFilter4_states[memOffset_0 + 2] *
        -5.40605452685298E-5) + AcOshPos_DW.DiscreteFilter4_states[memOffset_0 +
       3] * 5.4366873931528294E-5) * 1.5743999886111712E+8;
    AcOshPos_Y.Output[i + 30] =
      (((AcOshPos_DW.DiscreteFilter5_states[memOffset_1 + 1] *
         -5.5465887689329465E-5 + 5.5160056819196816E-5 *
         AcOshPos_DW.DiscreteFilter5_states[memOffset_1]) +
        AcOshPos_DW.DiscreteFilter5_states[memOffset_1 + 2] *
        -5.40605452685298E-5) + AcOshPos_DW.DiscreteFilter5_states[memOffset_1 +
       3] * 5.4366873931528294E-5) * 1.5743999886111712E+8;
    AcOshPos_Y.Output[i + 36] =
      (((AcOshPos_DW.DiscreteFilter6_states[memOffset_2 + 1] *
         -5.5465887689329465E-5 + 5.5160056819196816E-5 *
         AcOshPos_DW.DiscreteFilter6_states[memOffset_2]) +
        AcOshPos_DW.DiscreteFilter6_states[memOffset_2 + 2] *
        -5.40605452685298E-5) + AcOshPos_DW.DiscreteFilter6_states[memOffset_2 +
       3] * 5.4366873931528294E-5) * 1.5743999886111712E+8;
  }

  /* Update for DiscreteTransferFcn: '<S1>/Integral Control' */
  memcpy(&AcOshPos_DW.IntegralControl_states[0], &IntegralControl_tmp[0], 42U *
         sizeof(real_T));
  for (i = 0; i < 6; i++) {
    /* Update for DiscreteFilter: '<S1>/Discrete Filter' */
    memOffset = i << 2;
    denAccum = (((CG2Hp6[i] - -3.9658259936667708 *
                  AcOshPos_DW.DiscreteFilter_states[memOffset]) -
                 AcOshPos_DW.DiscreteFilter_states[memOffset + 1] *
                 5.8976852476007764) -
                AcOshPos_DW.DiscreteFilter_states[memOffset + 2] *
                -3.8978920261025323) -
      AcOshPos_DW.DiscreteFilter_states[memOffset + 3] * 0.96603277266632026;
    AcOshPos_DW.DiscreteFilter_states[memOffset + 3] =
      AcOshPos_DW.DiscreteFilter_states[memOffset + 2];
    AcOshPos_DW.DiscreteFilter_states[memOffset + 2] =
      AcOshPos_DW.DiscreteFilter_states[memOffset + 1];
    AcOshPos_DW.DiscreteFilter_states[memOffset + 1] =
      AcOshPos_DW.DiscreteFilter_states[memOffset];
    AcOshPos_DW.DiscreteFilter_states[memOffset] = denAccum;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter3' */
    memOffset = i << 2;
    denAccum = (((CG2Hp2[i] - -3.9658259936667708 *
                  AcOshPos_DW.DiscreteFilter3_states[memOffset]) -
                 AcOshPos_DW.DiscreteFilter3_states[memOffset + 1] *
                 5.8976852476007764) -
                AcOshPos_DW.DiscreteFilter3_states[memOffset + 2] *
                -3.8978920261025323) -
      AcOshPos_DW.DiscreteFilter3_states[memOffset + 3] * 0.96603277266632026;
    AcOshPos_DW.DiscreteFilter3_states[memOffset + 3] =
      AcOshPos_DW.DiscreteFilter3_states[memOffset + 2];
    AcOshPos_DW.DiscreteFilter3_states[memOffset + 2] =
      AcOshPos_DW.DiscreteFilter3_states[memOffset + 1];
    AcOshPos_DW.DiscreteFilter3_states[memOffset + 1] =
      AcOshPos_DW.DiscreteFilter3_states[memOffset];
    AcOshPos_DW.DiscreteFilter3_states[memOffset] = denAccum;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter4' */
    memOffset = i << 2;
    denAccum = (((CG2Hp3[i] - -3.9658259936667708 *
                  AcOshPos_DW.DiscreteFilter4_states[memOffset]) -
                 AcOshPos_DW.DiscreteFilter4_states[memOffset + 1] *
                 5.8976852476007764) -
                AcOshPos_DW.DiscreteFilter4_states[memOffset + 2] *
                -3.8978920261025323) -
      AcOshPos_DW.DiscreteFilter4_states[memOffset + 3] * 0.96603277266632026;
    AcOshPos_DW.DiscreteFilter4_states[memOffset + 3] =
      AcOshPos_DW.DiscreteFilter4_states[memOffset + 2];
    AcOshPos_DW.DiscreteFilter4_states[memOffset + 2] =
      AcOshPos_DW.DiscreteFilter4_states[memOffset + 1];
    AcOshPos_DW.DiscreteFilter4_states[memOffset + 1] =
      AcOshPos_DW.DiscreteFilter4_states[memOffset];
    AcOshPos_DW.DiscreteFilter4_states[memOffset] = denAccum;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter5' */
    memOffset = i << 2;
    denAccum = (((CG2Hp4[i] - -3.9658259936667708 *
                  AcOshPos_DW.DiscreteFilter5_states[memOffset]) -
                 AcOshPos_DW.DiscreteFilter5_states[memOffset + 1] *
                 5.8976852476007764) -
                AcOshPos_DW.DiscreteFilter5_states[memOffset + 2] *
                -3.8978920261025323) -
      AcOshPos_DW.DiscreteFilter5_states[memOffset + 3] * 0.96603277266632026;
    AcOshPos_DW.DiscreteFilter5_states[memOffset + 3] =
      AcOshPos_DW.DiscreteFilter5_states[memOffset + 2];
    AcOshPos_DW.DiscreteFilter5_states[memOffset + 2] =
      AcOshPos_DW.DiscreteFilter5_states[memOffset + 1];
    AcOshPos_DW.DiscreteFilter5_states[memOffset + 1] =
      AcOshPos_DW.DiscreteFilter5_states[memOffset];
    AcOshPos_DW.DiscreteFilter5_states[memOffset] = denAccum;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter6' */
    memOffset = i << 2;
    denAccum = (((CG2Hp5[i] - -3.9658259936667708 *
                  AcOshPos_DW.DiscreteFilter6_states[memOffset]) -
                 AcOshPos_DW.DiscreteFilter6_states[memOffset + 1] *
                 5.8976852476007764) -
                AcOshPos_DW.DiscreteFilter6_states[memOffset + 2] *
                -3.8978920261025323) -
      AcOshPos_DW.DiscreteFilter6_states[memOffset + 3] * 0.96603277266632026;
    AcOshPos_DW.DiscreteFilter6_states[memOffset + 3] =
      AcOshPos_DW.DiscreteFilter6_states[memOffset + 2];
    AcOshPos_DW.DiscreteFilter6_states[memOffset + 2] =
      AcOshPos_DW.DiscreteFilter6_states[memOffset + 1];
    AcOshPos_DW.DiscreteFilter6_states[memOffset + 1] =
      AcOshPos_DW.DiscreteFilter6_states[memOffset];
    AcOshPos_DW.DiscreteFilter6_states[memOffset] = denAccum;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter1' */
    memOffset = i << 2;
    denAccum = (((CG2Hp8[i] - -3.9658259936667708 *
                  AcOshPos_DW.DiscreteFilter1_states[memOffset]) -
                 AcOshPos_DW.DiscreteFilter1_states[memOffset + 1] *
                 5.8976852476007764) -
                AcOshPos_DW.DiscreteFilter1_states[memOffset + 2] *
                -3.8978920261025323) -
      AcOshPos_DW.DiscreteFilter1_states[memOffset + 3] * 0.96603277266632026;
    AcOshPos_DW.DiscreteFilter1_states[memOffset + 3] =
      AcOshPos_DW.DiscreteFilter1_states[memOffset + 2];
    AcOshPos_DW.DiscreteFilter1_states[memOffset + 2] =
      AcOshPos_DW.DiscreteFilter1_states[memOffset + 1];
    AcOshPos_DW.DiscreteFilter1_states[memOffset + 1] =
      AcOshPos_DW.DiscreteFilter1_states[memOffset];
    AcOshPos_DW.DiscreteFilter1_states[memOffset] = denAccum;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter2' */
    memOffset = i << 2;
    denAccum = (((CG2Hp1[i] - -3.9658259936667708 *
                  AcOshPos_DW.DiscreteFilter2_states[memOffset]) -
                 AcOshPos_DW.DiscreteFilter2_states[memOffset + 1] *
                 5.8976852476007764) -
                AcOshPos_DW.DiscreteFilter2_states[memOffset + 2] *
                -3.8978920261025323) -
      AcOshPos_DW.DiscreteFilter2_states[memOffset + 3] * 0.96603277266632026;
    AcOshPos_DW.DiscreteFilter2_states[memOffset + 3] =
      AcOshPos_DW.DiscreteFilter2_states[memOffset + 2];
    AcOshPos_DW.DiscreteFilter2_states[memOffset + 2] =
      AcOshPos_DW.DiscreteFilter2_states[memOffset + 1];
    AcOshPos_DW.DiscreteFilter2_states[memOffset + 1] =
      AcOshPos_DW.DiscreteFilter2_states[memOffset];
    AcOshPos_DW.DiscreteFilter2_states[memOffset] = denAccum;
  }
}

/* Model initialize function */
void AcOshPos_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(AcOshPos_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&AcOshPos_DW, 0,
                sizeof(DW_AcOshPos_T));

  /* external inputs */
  (void)memset((void *)&AcOshPos_U, 0, sizeof(ExtU_AcOshPos_T));

  /* external outputs */
  (void) memset(&AcOshPos_Y.Output[0], 0,
                42U*sizeof(real_T));
}

/* Model terminate function */
void AcOshPos_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
