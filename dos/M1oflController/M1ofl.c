/*
 * File: M1ofl.c
 *
 * Code generated for Simulink model 'M1ofl'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Wed Sep  4 11:42:46 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M1ofl.h"
#include "M1ofl_private.h"

/* Block states (default storage) */
DW_M1ofl_T M1ofl_DW;

/* External inputs (root inport signals with default storage) */
ExtU_M1ofl_T M1ofl_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_M1ofl_T M1ofl_Y;

/* Real-time model */
RT_MODEL_M1ofl_T M1ofl_M_;
RT_MODEL_M1ofl_T *const M1ofl_M = &M1ofl_M_;

/* Model step function */
void M1ofl_step(void)
{
  int32_T j;
  int32_T numIdx;
  real_T rtb_FzController;
  real_T rtb_FyController;
  real_T MHP[6];
  real_T MHP_j[6];
  real_T MHP_n[6];
  real_T MHP_g[6];
  real_T MHP_c[6];
  real_T MHP_g2[6];
  real_T MHP_b[6];
  real_T rtb_MzController_0[6];
  int32_T i;
  real_T tmp[6];

  /* DiscreteTransferFcn: '<S2>/Mx Controller' */
  rtb_FzController = 0.0;
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FzController += M1ofl_ConstP.pooled6[numIdx] *
      M1ofl_DW.MxController_states[j];
    numIdx++;
  }

  /* End of DiscreteTransferFcn: '<S2>/Mx Controller' */

  /* DiscreteTransferFcn: '<S2>/My Controller' */
  rtb_FyController = 0.0;
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FyController += M1ofl_ConstP.pooled6[numIdx] *
      M1ofl_DW.MyController_states[j];
    numIdx++;
  }

  /* End of DiscreteTransferFcn: '<S2>/My Controller' */

  /* SignalConversion: '<S2>/TmpSignal ConversionAtForce balanceInport1' incorporates:
   *  DiscreteTransferFcn: '<S2>/Fx Controller'
   *  DiscreteTransferFcn: '<S2>/Fy Controller'
   *  DiscreteTransferFcn: '<S2>/Fz Controller'
   *  DiscreteTransferFcn: '<S2>/Mz Controller'
   */
  rtb_MzController_0[0] = (0.0031075654819996759 * M1ofl_DW.FxController_states
    [0] + -0.0062083257567339973 * M1ofl_DW.FxController_states[1]) +
    0.0031046389635168946 * M1ofl_DW.FxController_states[2];
  rtb_MzController_0[1] = (0.0031075654819996759 * M1ofl_DW.FyController_states
    [0] + -0.0062083257567339973 * M1ofl_DW.FyController_states[1]) +
    0.0031046389635168946 * M1ofl_DW.FyController_states[2];
  rtb_MzController_0[2] = (0.0033988205505334976 * M1ofl_DW.FzController_states
    [0] + -0.0067736068594331216 * M1ofl_DW.FzController_states[1]) +
    0.0033881700821686029 * M1ofl_DW.FzController_states[2];
  rtb_MzController_0[3] = rtb_FzController;
  rtb_MzController_0[4] = rtb_FyController;
  rtb_MzController_0[5] = (0.0034318558266773552 * M1ofl_DW.MzController_states
    [0] + -0.0068430176624178825 * M1ofl_DW.MzController_states[1]) +
    0.0034246827558012866 * M1ofl_DW.MzController_states[2];

  /* Gain: '<S2>/Force balance' incorporates:
   *  Outport: '<Root>/Output'
   */
  for (numIdx = 0; numIdx < 335; numIdx++) {
    M1ofl_Y.Output[numIdx] = 0.0;
    j = 0;
    for (i = 0; i < 6; i++) {
      M1ofl_Y.Output[numIdx] += M1ofl_ConstP.pooled10[j + numIdx] *
        rtb_MzController_0[i];
      j += 335;
    }
  }

  /* End of Gain: '<S2>/Force balance' */

  /* DiscreteTransferFcn: '<S4>/Mx Controller' */
  rtb_FzController = 0.0;
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FzController += M1ofl_ConstP.pooled6[numIdx] *
      M1ofl_DW.MxController_states_k[j];
    numIdx++;
  }

  /* End of DiscreteTransferFcn: '<S4>/Mx Controller' */

  /* DiscreteTransferFcn: '<S4>/My Controller' */
  rtb_FyController = 0.0;
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FyController += M1ofl_ConstP.pooled6[numIdx] *
      M1ofl_DW.MyController_states_b[j];
    numIdx++;
  }

  /* End of DiscreteTransferFcn: '<S4>/My Controller' */

  /* SignalConversion: '<S4>/TmpSignal ConversionAtForce balanceInport1' incorporates:
   *  DiscreteTransferFcn: '<S4>/Fx Controller'
   *  DiscreteTransferFcn: '<S4>/Fy Controller'
   *  DiscreteTransferFcn: '<S4>/Fz Controller'
   *  DiscreteTransferFcn: '<S4>/Mz Controller'
   */
  rtb_MzController_0[0] = (0.0031075654819996759 *
    M1ofl_DW.FxController_states_m[0] + -0.0062083257567339973 *
    M1ofl_DW.FxController_states_m[1]) + 0.0031046389635168946 *
    M1ofl_DW.FxController_states_m[2];
  rtb_MzController_0[1] = (0.0031075654819996759 *
    M1ofl_DW.FyController_states_h[0] + -0.0062083257567339973 *
    M1ofl_DW.FyController_states_h[1]) + 0.0031046389635168946 *
    M1ofl_DW.FyController_states_h[2];
  rtb_MzController_0[2] = (0.0033988205505334976 *
    M1ofl_DW.FzController_states_n[0] + -0.0067736068594331216 *
    M1ofl_DW.FzController_states_n[1]) + 0.0033881700821686029 *
    M1ofl_DW.FzController_states_n[2];
  rtb_MzController_0[3] = rtb_FzController;
  rtb_MzController_0[4] = rtb_FyController;
  rtb_MzController_0[5] = (0.0034318558266773552 *
    M1ofl_DW.MzController_states_e[0] + -0.0068430176624178825 *
    M1ofl_DW.MzController_states_e[1]) + 0.0034246827558012866 *
    M1ofl_DW.MzController_states_e[2];

  /* Gain: '<S4>/Force balance' incorporates:
   *  Outport: '<Root>/Output'
   */
  for (numIdx = 0; numIdx < 335; numIdx++) {
    M1ofl_Y.Output[numIdx + 335] = 0.0;
    j = 0;
    for (i = 0; i < 6; i++) {
      M1ofl_Y.Output[numIdx + 335] += M1ofl_ConstP.pooled10[j + numIdx] *
        rtb_MzController_0[i];
      j += 335;
    }
  }

  /* End of Gain: '<S4>/Force balance' */

  /* DiscreteTransferFcn: '<S6>/Mx Controller' */
  rtb_FzController = 0.0;
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FzController += M1ofl_ConstP.pooled6[numIdx] *
      M1ofl_DW.MxController_states_kb[j];
    numIdx++;
  }

  /* End of DiscreteTransferFcn: '<S6>/Mx Controller' */

  /* DiscreteTransferFcn: '<S6>/My Controller' */
  rtb_FyController = 0.0;
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FyController += M1ofl_ConstP.pooled6[numIdx] *
      M1ofl_DW.MyController_states_f[j];
    numIdx++;
  }

  /* End of DiscreteTransferFcn: '<S6>/My Controller' */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtForce balanceInport1' incorporates:
   *  DiscreteTransferFcn: '<S6>/Fx Controller'
   *  DiscreteTransferFcn: '<S6>/Fy Controller'
   *  DiscreteTransferFcn: '<S6>/Fz Controller'
   *  DiscreteTransferFcn: '<S6>/Mz Controller'
   */
  rtb_MzController_0[0] = (0.0031075654819996759 *
    M1ofl_DW.FxController_states_p[0] + -0.0062083257567339973 *
    M1ofl_DW.FxController_states_p[1]) + 0.0031046389635168946 *
    M1ofl_DW.FxController_states_p[2];
  rtb_MzController_0[1] = (0.0031075654819996759 *
    M1ofl_DW.FyController_states_b[0] + -0.0062083257567339973 *
    M1ofl_DW.FyController_states_b[1]) + 0.0031046389635168946 *
    M1ofl_DW.FyController_states_b[2];
  rtb_MzController_0[2] = (0.0033988205505334976 *
    M1ofl_DW.FzController_states_l[0] + -0.0067736068594331216 *
    M1ofl_DW.FzController_states_l[1]) + 0.0033881700821686029 *
    M1ofl_DW.FzController_states_l[2];
  rtb_MzController_0[3] = rtb_FzController;
  rtb_MzController_0[4] = rtb_FyController;
  rtb_MzController_0[5] = (0.0034318558266773552 *
    M1ofl_DW.MzController_states_g[0] + -0.0068430176624178825 *
    M1ofl_DW.MzController_states_g[1]) + 0.0034246827558012866 *
    M1ofl_DW.MzController_states_g[2];

  /* Gain: '<S6>/Force balance' incorporates:
   *  Outport: '<Root>/Output'
   */
  for (numIdx = 0; numIdx < 335; numIdx++) {
    M1ofl_Y.Output[numIdx + 670] = 0.0;
    j = 0;
    for (i = 0; i < 6; i++) {
      M1ofl_Y.Output[numIdx + 670] += M1ofl_ConstP.pooled10[j + numIdx] *
        rtb_MzController_0[i];
      j += 335;
    }
  }

  /* End of Gain: '<S6>/Force balance' */

  /* DiscreteTransferFcn: '<S8>/Mx Controller' */
  rtb_FzController = 0.0;
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FzController += M1ofl_ConstP.pooled6[numIdx] *
      M1ofl_DW.MxController_states_kz[j];
    numIdx++;
  }

  /* End of DiscreteTransferFcn: '<S8>/Mx Controller' */

  /* DiscreteTransferFcn: '<S8>/My Controller' */
  rtb_FyController = 0.0;
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FyController += M1ofl_ConstP.pooled6[numIdx] *
      M1ofl_DW.MyController_states_m[j];
    numIdx++;
  }

  /* End of DiscreteTransferFcn: '<S8>/My Controller' */

  /* SignalConversion: '<S8>/TmpSignal ConversionAtForce balanceInport1' incorporates:
   *  DiscreteTransferFcn: '<S8>/Fx Controller'
   *  DiscreteTransferFcn: '<S8>/Fy Controller'
   *  DiscreteTransferFcn: '<S8>/Fz Controller'
   *  DiscreteTransferFcn: '<S8>/Mz Controller'
   */
  rtb_MzController_0[0] = (0.0031075654819996759 *
    M1ofl_DW.FxController_states_pp[0] + -0.0062083257567339973 *
    M1ofl_DW.FxController_states_pp[1]) + 0.0031046389635168946 *
    M1ofl_DW.FxController_states_pp[2];
  rtb_MzController_0[1] = (0.0031075654819996759 *
    M1ofl_DW.FyController_states_g[0] + -0.0062083257567339973 *
    M1ofl_DW.FyController_states_g[1]) + 0.0031046389635168946 *
    M1ofl_DW.FyController_states_g[2];
  rtb_MzController_0[2] = (0.0033988205505334976 *
    M1ofl_DW.FzController_states_a[0] + -0.0067736068594331216 *
    M1ofl_DW.FzController_states_a[1]) + 0.0033881700821686029 *
    M1ofl_DW.FzController_states_a[2];
  rtb_MzController_0[3] = rtb_FzController;
  rtb_MzController_0[4] = rtb_FyController;
  rtb_MzController_0[5] = (0.0034318558266773552 *
    M1ofl_DW.MzController_states_c[0] + -0.0068430176624178825 *
    M1ofl_DW.MzController_states_c[1]) + 0.0034246827558012866 *
    M1ofl_DW.MzController_states_c[2];

  /* Gain: '<S8>/Force balance' incorporates:
   *  Outport: '<Root>/Output'
   */
  for (numIdx = 0; numIdx < 335; numIdx++) {
    M1ofl_Y.Output[numIdx + 1005] = 0.0;
    j = 0;
    for (i = 0; i < 6; i++) {
      M1ofl_Y.Output[numIdx + 1005] += M1ofl_ConstP.pooled10[j + numIdx] *
        rtb_MzController_0[i];
      j += 335;
    }
  }

  /* End of Gain: '<S8>/Force balance' */

  /* DiscreteTransferFcn: '<S10>/Mx Controller' */
  rtb_FzController = 0.0;
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FzController += M1ofl_ConstP.pooled6[numIdx] *
      M1ofl_DW.MxController_states_l[j];
    numIdx++;
  }

  /* End of DiscreteTransferFcn: '<S10>/Mx Controller' */

  /* DiscreteTransferFcn: '<S10>/My Controller' */
  rtb_FyController = 0.0;
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FyController += M1ofl_ConstP.pooled6[numIdx] *
      M1ofl_DW.MyController_states_bn[j];
    numIdx++;
  }

  /* End of DiscreteTransferFcn: '<S10>/My Controller' */

  /* SignalConversion: '<S10>/TmpSignal ConversionAtForce balanceInport1' incorporates:
   *  DiscreteTransferFcn: '<S10>/Fx Controller'
   *  DiscreteTransferFcn: '<S10>/Fy Controller'
   *  DiscreteTransferFcn: '<S10>/Fz Controller'
   *  DiscreteTransferFcn: '<S10>/Mz Controller'
   */
  rtb_MzController_0[0] = (0.0031075654819996759 *
    M1ofl_DW.FxController_states_c[0] + -0.0062083257567339973 *
    M1ofl_DW.FxController_states_c[1]) + 0.0031046389635168946 *
    M1ofl_DW.FxController_states_c[2];
  rtb_MzController_0[1] = (0.0031075654819996759 *
    M1ofl_DW.FyController_states_m[0] + -0.0062083257567339973 *
    M1ofl_DW.FyController_states_m[1]) + 0.0031046389635168946 *
    M1ofl_DW.FyController_states_m[2];
  rtb_MzController_0[2] = (0.0033988205505334976 *
    M1ofl_DW.FzController_states_d[0] + -0.0067736068594331216 *
    M1ofl_DW.FzController_states_d[1]) + 0.0033881700821686029 *
    M1ofl_DW.FzController_states_d[2];
  rtb_MzController_0[3] = rtb_FzController;
  rtb_MzController_0[4] = rtb_FyController;
  rtb_MzController_0[5] = (0.0034318558266773552 *
    M1ofl_DW.MzController_states_l[0] + -0.0068430176624178825 *
    M1ofl_DW.MzController_states_l[1]) + 0.0034246827558012866 *
    M1ofl_DW.MzController_states_l[2];

  /* Gain: '<S10>/Force balance' incorporates:
   *  Outport: '<Root>/Output'
   */
  for (numIdx = 0; numIdx < 335; numIdx++) {
    M1ofl_Y.Output[numIdx + 1340] = 0.0;
    j = 0;
    for (i = 0; i < 6; i++) {
      M1ofl_Y.Output[numIdx + 1340] += M1ofl_ConstP.pooled10[j + numIdx] *
        rtb_MzController_0[i];
      j += 335;
    }
  }

  /* End of Gain: '<S10>/Force balance' */

  /* DiscreteTransferFcn: '<S12>/Mx Controller' */
  rtb_FzController = 0.0;
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FzController += M1ofl_ConstP.pooled6[numIdx] *
      M1ofl_DW.MxController_states_g[j];
    numIdx++;
  }

  /* End of DiscreteTransferFcn: '<S12>/Mx Controller' */

  /* DiscreteTransferFcn: '<S12>/My Controller' */
  rtb_FyController = 0.0;
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FyController += M1ofl_ConstP.pooled6[numIdx] *
      M1ofl_DW.MyController_states_l[j];
    numIdx++;
  }

  /* End of DiscreteTransferFcn: '<S12>/My Controller' */

  /* SignalConversion: '<S12>/TmpSignal ConversionAtForce balanceInport1' incorporates:
   *  DiscreteTransferFcn: '<S12>/Fx Controller'
   *  DiscreteTransferFcn: '<S12>/Fy Controller'
   *  DiscreteTransferFcn: '<S12>/Fz Controller'
   *  DiscreteTransferFcn: '<S12>/Mz Controller'
   */
  rtb_MzController_0[0] = (0.0031075654819996759 *
    M1ofl_DW.FxController_states_pd[0] + -0.0062083257567339973 *
    M1ofl_DW.FxController_states_pd[1]) + 0.0031046389635168946 *
    M1ofl_DW.FxController_states_pd[2];
  rtb_MzController_0[1] = (0.0031075654819996759 *
    M1ofl_DW.FyController_states_ms[0] + -0.0062083257567339973 *
    M1ofl_DW.FyController_states_ms[1]) + 0.0031046389635168946 *
    M1ofl_DW.FyController_states_ms[2];
  rtb_MzController_0[2] = (0.0033988205505334976 *
    M1ofl_DW.FzController_states_e[0] + -0.0067736068594331216 *
    M1ofl_DW.FzController_states_e[1]) + 0.0033881700821686029 *
    M1ofl_DW.FzController_states_e[2];
  rtb_MzController_0[3] = rtb_FzController;
  rtb_MzController_0[4] = rtb_FyController;
  rtb_MzController_0[5] = (0.0034318558266773552 *
    M1ofl_DW.MzController_states_k[0] + -0.0068430176624178825 *
    M1ofl_DW.MzController_states_k[1]) + 0.0034246827558012866 *
    M1ofl_DW.MzController_states_k[2];

  /* Gain: '<S12>/Force balance' incorporates:
   *  Outport: '<Root>/Output'
   */
  for (numIdx = 0; numIdx < 335; numIdx++) {
    M1ofl_Y.Output[numIdx + 1675] = 0.0;
    j = 0;
    for (i = 0; i < 6; i++) {
      M1ofl_Y.Output[numIdx + 1675] += M1ofl_ConstP.pooled10[j + numIdx] *
        rtb_MzController_0[i];
      j += 335;
    }
  }

  /* End of Gain: '<S12>/Force balance' */

  /* SignalConversion: '<S15>/TmpSignal ConversionAtForce balanceInport1' incorporates:
   *  DiscreteTransferFcn: '<S15>/Fx Controller'
   *  DiscreteTransferFcn: '<S15>/Fy Controller'
   *  DiscreteTransferFcn: '<S15>/Fz Controller'
   *  DiscreteTransferFcn: '<S15>/Mx Controller'
   *  DiscreteTransferFcn: '<S15>/My Controller'
   *  DiscreteTransferFcn: '<S15>/Mz Controller'
   */
  rtb_MzController_0[0] = (0.0027629307658847734 *
    M1ofl_DW.FxController_states_mx[0] + -0.0055185117837635517 *
    M1ofl_DW.FxController_states_mx[1]) + 0.0027590287412410657 *
    M1ofl_DW.FxController_states_mx[2];
  rtb_MzController_0[1] = (1.6875923962320881E-7 *
    M1ofl_DW.FyController_states_bh[0] + 3.3751847924641762E-7 *
    M1ofl_DW.FyController_states_bh[1]) + 1.6875923962320881E-7 *
    M1ofl_DW.FyController_states_bh[2];
  rtb_MzController_0[2] = (0.0033988205505334976 *
    M1ofl_DW.FzController_states_ei[0] + -0.0067736068594331216 *
    M1ofl_DW.FzController_states_ei[1]) + 0.0033881700821686029 *
    M1ofl_DW.FzController_states_ei[2];
  rtb_MzController_0[3] = (1.6875923962320881E-7 *
    M1ofl_DW.MxController_states_h[0] + 3.3751847924641762E-7 *
    M1ofl_DW.MxController_states_h[1]) + 1.6875923962320881E-7 *
    M1ofl_DW.MxController_states_h[2];
  rtb_MzController_0[4] = (1.6875923962320881E-7 *
    M1ofl_DW.MyController_states_k[0] + 3.3751847924641762E-7 *
    M1ofl_DW.MyController_states_k[1]) + 1.6875923962320881E-7 *
    M1ofl_DW.MyController_states_k[2];
  rtb_MzController_0[5] = (1.6875923962320881E-7 *
    M1ofl_DW.MzController_states_m[0] + 3.3751847924641762E-7 *
    M1ofl_DW.MzController_states_m[1]) + 1.6875923962320881E-7 *
    M1ofl_DW.MzController_states_m[2];

  /* Gain: '<S15>/Force balance' incorporates:
   *  Outport: '<Root>/Output'
   */
  for (numIdx = 0; numIdx < 306; numIdx++) {
    M1ofl_Y.Output[numIdx + 2010] = 0.0;
    j = 0;
    for (i = 0; i < 6; i++) {
      M1ofl_Y.Output[numIdx + 2010] += M1ofl_ConstP.Forcebalance_Gain[j + numIdx]
        * rtb_MzController_0[i];
      j += 306;
    }
  }

  /* End of Gain: '<S15>/Force balance' */

  /* Sum: '<S3>/Sum1' incorporates:
   *  Gain: '<S2>/MHP'
   *  Gain: '<S3>/HpK'
   *  Inport: '<Root>/Feedback'
   *  Inport: '<Root>/Reference'
   *  Sum: '<S3>/Sum9'
   */
  for (numIdx = 0; numIdx < 6; numIdx++) {
    rtb_MzController_0[numIdx] = (M1ofl_U.Feedback[numIdx + 6] -
      M1ofl_U.Feedback[numIdx]) * 1.5743999886111712E+8 -
      M1ofl_U.Reference[numIdx];
  }

  /* End of Sum: '<S3>/Sum1' */
  for (numIdx = 0; numIdx < 6; numIdx++) {
    /* Gain: '<S2>/MHP' */
    MHP[numIdx] = 0.0;
    j = 0;
    for (i = 0; i < 6; i++) {
      MHP[numIdx] += M1ofl_ConstP.MHP_Gain[j + numIdx] * rtb_MzController_0[i];
      j += 6;
    }

    /* Sum: '<S5>/Sum1' incorporates:
     *  Gain: '<S2>/MHP'
     *  Gain: '<S4>/MHP'
     *  Gain: '<S5>/HpK'
     *  Inport: '<Root>/Feedback'
     *  Inport: '<Root>/Reference'
     *  Sum: '<S5>/Sum9'
     */
    tmp[numIdx] = (M1ofl_U.Feedback[numIdx + 18] - M1ofl_U.Feedback[numIdx + 12])
      * 1.5743999886111712E+8 - M1ofl_U.Reference[numIdx + 6];
  }

  for (numIdx = 0; numIdx < 6; numIdx++) {
    /* Gain: '<S4>/MHP' */
    MHP_j[numIdx] = 0.0;
    j = 0;
    for (i = 0; i < 6; i++) {
      MHP_j[numIdx] += M1ofl_ConstP.MHP_Gain_p[j + numIdx] * tmp[i];
      j += 6;
    }

    /* Sum: '<S7>/Sum1' incorporates:
     *  Gain: '<S4>/MHP'
     *  Gain: '<S6>/MHP'
     *  Gain: '<S7>/HpK'
     *  Inport: '<Root>/Feedback'
     *  Inport: '<Root>/Reference'
     *  Sum: '<S7>/Sum9'
     */
    rtb_MzController_0[numIdx] = (M1ofl_U.Feedback[numIdx + 30] -
      M1ofl_U.Feedback[numIdx + 24]) * 1.5743999886111712E+8 -
      M1ofl_U.Reference[numIdx + 12];
  }

  for (numIdx = 0; numIdx < 6; numIdx++) {
    /* Gain: '<S6>/MHP' */
    MHP_n[numIdx] = 0.0;
    j = 0;
    for (i = 0; i < 6; i++) {
      MHP_n[numIdx] += M1ofl_ConstP.MHP_Gain_b[j + numIdx] *
        rtb_MzController_0[i];
      j += 6;
    }

    /* Sum: '<S9>/Sum1' incorporates:
     *  Gain: '<S6>/MHP'
     *  Gain: '<S8>/MHP'
     *  Gain: '<S9>/HpK'
     *  Inport: '<Root>/Feedback'
     *  Inport: '<Root>/Reference'
     *  Sum: '<S9>/Sum9'
     */
    tmp[numIdx] = (M1ofl_U.Feedback[numIdx + 42] - M1ofl_U.Feedback[numIdx + 36])
      * 1.5743999886111712E+8 - M1ofl_U.Reference[numIdx + 18];
  }

  for (numIdx = 0; numIdx < 6; numIdx++) {
    /* Gain: '<S8>/MHP' */
    MHP_g[numIdx] = 0.0;
    j = 0;
    for (i = 0; i < 6; i++) {
      MHP_g[numIdx] += M1ofl_ConstP.MHP_Gain_e[j + numIdx] * tmp[i];
      j += 6;
    }

    /* Sum: '<S11>/Sum1' incorporates:
     *  Gain: '<S10>/MHP'
     *  Gain: '<S11>/HpK'
     *  Gain: '<S8>/MHP'
     *  Inport: '<Root>/Feedback'
     *  Inport: '<Root>/Reference'
     *  Sum: '<S11>/Sum9'
     */
    rtb_MzController_0[numIdx] = (M1ofl_U.Feedback[numIdx + 54] -
      M1ofl_U.Feedback[numIdx + 48]) * 1.5743999886111712E+8 -
      M1ofl_U.Reference[numIdx + 24];
  }

  for (numIdx = 0; numIdx < 6; numIdx++) {
    /* Gain: '<S10>/MHP' */
    MHP_c[numIdx] = 0.0;
    j = 0;
    for (i = 0; i < 6; i++) {
      MHP_c[numIdx] += M1ofl_ConstP.MHP_Gain_j[j + numIdx] *
        rtb_MzController_0[i];
      j += 6;
    }

    /* Sum: '<S13>/Sum1' incorporates:
     *  Gain: '<S10>/MHP'
     *  Gain: '<S12>/MHP'
     *  Gain: '<S13>/HpK'
     *  Inport: '<Root>/Feedback'
     *  Inport: '<Root>/Reference'
     *  Sum: '<S13>/Sum9'
     */
    tmp[numIdx] = (M1ofl_U.Feedback[numIdx + 66] - M1ofl_U.Feedback[numIdx + 60])
      * 1.5743999886111712E+8 - M1ofl_U.Reference[numIdx + 30];
  }

  for (numIdx = 0; numIdx < 6; numIdx++) {
    /* Gain: '<S12>/MHP' */
    MHP_g2[numIdx] = 0.0;
    j = 0;
    for (i = 0; i < 6; i++) {
      MHP_g2[numIdx] += M1ofl_ConstP.MHP_Gain_c[j + numIdx] * tmp[i];
      j += 6;
    }

    /* Sum: '<S14>/Sum1' incorporates:
     *  Gain: '<S12>/MHP'
     *  Gain: '<S14>/HpK'
     *  Gain: '<S15>/MHP'
     *  Inport: '<Root>/Feedback'
     *  Inport: '<Root>/Reference'
     *  Sum: '<S14>/Sum9'
     */
    rtb_MzController_0[numIdx] = (M1ofl_U.Feedback[numIdx + 78] -
      M1ofl_U.Feedback[numIdx + 72]) * 1.5743999886111712E+8 -
      M1ofl_U.Reference[numIdx + 36];
  }

  /* Gain: '<S15>/MHP' */
  for (numIdx = 0; numIdx < 6; numIdx++) {
    MHP_b[numIdx] = 0.0;
    j = 0;
    for (i = 0; i < 6; i++) {
      MHP_b[numIdx] += M1ofl_ConstP.MHP_Gain_m[j + numIdx] *
        rtb_MzController_0[i];
      j += 6;
    }
  }

  /* Update for DiscreteTransferFcn: '<S2>/Fx Controller' */
  rtb_FzController = ((MHP[0] - -2.97089706562984 *
                       M1ofl_DW.FxController_states[0]) - 2.9430254610319251 *
                      M1ofl_DW.FxController_states[1]) - -0.9721283954020854 *
    M1ofl_DW.FxController_states[2];
  M1ofl_DW.FxController_states[2] = M1ofl_DW.FxController_states[1];
  M1ofl_DW.FxController_states[1] = M1ofl_DW.FxController_states[0];
  M1ofl_DW.FxController_states[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S2>/Fy Controller' */
  rtb_FzController = ((MHP[1] - -2.97089706562984 *
                       M1ofl_DW.FyController_states[0]) - 2.9430254610319251 *
                      M1ofl_DW.FyController_states[1]) - -0.9721283954020854 *
    M1ofl_DW.FyController_states[2];
  M1ofl_DW.FyController_states[2] = M1ofl_DW.FyController_states[1];
  M1ofl_DW.FyController_states[1] = M1ofl_DW.FyController_states[0];
  M1ofl_DW.FyController_states[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S2>/Fz Controller' */
  rtb_FzController = ((MHP[2] - -2.935316245552321 *
                       M1ofl_DW.FzController_states[0]) - 2.8744564263243495 *
                      M1ofl_DW.FzController_states[1]) - -0.93914018077202877 *
    M1ofl_DW.FzController_states[2];
  M1ofl_DW.FzController_states[2] = M1ofl_DW.FzController_states[1];
  M1ofl_DW.FzController_states[1] = M1ofl_DW.FzController_states[0];
  M1ofl_DW.FzController_states[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S2>/Mx Controller' */
  rtb_FzController = MHP[3];
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FzController -= M1ofl_ConstP.pooled7[numIdx] *
      M1ofl_DW.MxController_states[j];
    numIdx++;
  }

  M1ofl_DW.MxController_states[4] = M1ofl_DW.MxController_states[3];
  M1ofl_DW.MxController_states[3] = M1ofl_DW.MxController_states[2];
  M1ofl_DW.MxController_states[2] = M1ofl_DW.MxController_states[1];
  M1ofl_DW.MxController_states[1] = M1ofl_DW.MxController_states[0];
  M1ofl_DW.MxController_states[0] = rtb_FzController;

  /* End of Update for DiscreteTransferFcn: '<S2>/Mx Controller' */

  /* Update for DiscreteTransferFcn: '<S2>/My Controller' */
  rtb_FzController = MHP[4];
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FzController -= M1ofl_ConstP.pooled7[numIdx] *
      M1ofl_DW.MyController_states[j];
    numIdx++;
  }

  M1ofl_DW.MyController_states[4] = M1ofl_DW.MyController_states[3];
  M1ofl_DW.MyController_states[3] = M1ofl_DW.MyController_states[2];
  M1ofl_DW.MyController_states[2] = M1ofl_DW.MyController_states[1];
  M1ofl_DW.MyController_states[1] = M1ofl_DW.MyController_states[0];
  M1ofl_DW.MyController_states[0] = rtb_FzController;

  /* End of Update for DiscreteTransferFcn: '<S2>/My Controller' */

  /* Update for DiscreteTransferFcn: '<S2>/Mz Controller' */
  rtb_FzController = ((MHP[5] - -2.9551479035479664 *
                       M1ofl_DW.MzController_states[0]) - 2.9141589271132933 *
                      M1ofl_DW.MzController_states[1]) - -0.95901102356532664 *
    M1ofl_DW.MzController_states[2];
  M1ofl_DW.MzController_states[2] = M1ofl_DW.MzController_states[1];
  M1ofl_DW.MzController_states[1] = M1ofl_DW.MzController_states[0];
  M1ofl_DW.MzController_states[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S4>/Fx Controller' */
  rtb_FzController = ((MHP_j[0] - -2.97089706562984 *
                       M1ofl_DW.FxController_states_m[0]) - 2.9430254610319251 *
                      M1ofl_DW.FxController_states_m[1]) - -0.9721283954020854 *
    M1ofl_DW.FxController_states_m[2];
  M1ofl_DW.FxController_states_m[2] = M1ofl_DW.FxController_states_m[1];
  M1ofl_DW.FxController_states_m[1] = M1ofl_DW.FxController_states_m[0];
  M1ofl_DW.FxController_states_m[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S4>/Fy Controller' */
  rtb_FzController = ((MHP_j[1] - -2.97089706562984 *
                       M1ofl_DW.FyController_states_h[0]) - 2.9430254610319251 *
                      M1ofl_DW.FyController_states_h[1]) - -0.9721283954020854 *
    M1ofl_DW.FyController_states_h[2];
  M1ofl_DW.FyController_states_h[2] = M1ofl_DW.FyController_states_h[1];
  M1ofl_DW.FyController_states_h[1] = M1ofl_DW.FyController_states_h[0];
  M1ofl_DW.FyController_states_h[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S4>/Fz Controller' */
  rtb_FzController = ((MHP_j[2] - -2.935316245552321 *
                       M1ofl_DW.FzController_states_n[0]) - 2.8744564263243495 *
                      M1ofl_DW.FzController_states_n[1]) - -0.93914018077202877 *
    M1ofl_DW.FzController_states_n[2];
  M1ofl_DW.FzController_states_n[2] = M1ofl_DW.FzController_states_n[1];
  M1ofl_DW.FzController_states_n[1] = M1ofl_DW.FzController_states_n[0];
  M1ofl_DW.FzController_states_n[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S4>/Mx Controller' */
  rtb_FzController = MHP_j[3];
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FzController -= M1ofl_ConstP.pooled7[numIdx] *
      M1ofl_DW.MxController_states_k[j];
    numIdx++;
  }

  M1ofl_DW.MxController_states_k[4] = M1ofl_DW.MxController_states_k[3];
  M1ofl_DW.MxController_states_k[3] = M1ofl_DW.MxController_states_k[2];
  M1ofl_DW.MxController_states_k[2] = M1ofl_DW.MxController_states_k[1];
  M1ofl_DW.MxController_states_k[1] = M1ofl_DW.MxController_states_k[0];
  M1ofl_DW.MxController_states_k[0] = rtb_FzController;

  /* End of Update for DiscreteTransferFcn: '<S4>/Mx Controller' */

  /* Update for DiscreteTransferFcn: '<S4>/My Controller' */
  rtb_FzController = MHP_j[4];
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FzController -= M1ofl_ConstP.pooled7[numIdx] *
      M1ofl_DW.MyController_states_b[j];
    numIdx++;
  }

  M1ofl_DW.MyController_states_b[4] = M1ofl_DW.MyController_states_b[3];
  M1ofl_DW.MyController_states_b[3] = M1ofl_DW.MyController_states_b[2];
  M1ofl_DW.MyController_states_b[2] = M1ofl_DW.MyController_states_b[1];
  M1ofl_DW.MyController_states_b[1] = M1ofl_DW.MyController_states_b[0];
  M1ofl_DW.MyController_states_b[0] = rtb_FzController;

  /* End of Update for DiscreteTransferFcn: '<S4>/My Controller' */

  /* Update for DiscreteTransferFcn: '<S4>/Mz Controller' */
  rtb_FzController = ((MHP_j[5] - -2.9551479035479664 *
                       M1ofl_DW.MzController_states_e[0]) - 2.9141589271132933 *
                      M1ofl_DW.MzController_states_e[1]) - -0.95901102356532664 *
    M1ofl_DW.MzController_states_e[2];
  M1ofl_DW.MzController_states_e[2] = M1ofl_DW.MzController_states_e[1];
  M1ofl_DW.MzController_states_e[1] = M1ofl_DW.MzController_states_e[0];
  M1ofl_DW.MzController_states_e[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S6>/Fx Controller' */
  rtb_FzController = ((MHP_n[0] - -2.97089706562984 *
                       M1ofl_DW.FxController_states_p[0]) - 2.9430254610319251 *
                      M1ofl_DW.FxController_states_p[1]) - -0.9721283954020854 *
    M1ofl_DW.FxController_states_p[2];
  M1ofl_DW.FxController_states_p[2] = M1ofl_DW.FxController_states_p[1];
  M1ofl_DW.FxController_states_p[1] = M1ofl_DW.FxController_states_p[0];
  M1ofl_DW.FxController_states_p[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S6>/Fy Controller' */
  rtb_FzController = ((MHP_n[1] - -2.97089706562984 *
                       M1ofl_DW.FyController_states_b[0]) - 2.9430254610319251 *
                      M1ofl_DW.FyController_states_b[1]) - -0.9721283954020854 *
    M1ofl_DW.FyController_states_b[2];
  M1ofl_DW.FyController_states_b[2] = M1ofl_DW.FyController_states_b[1];
  M1ofl_DW.FyController_states_b[1] = M1ofl_DW.FyController_states_b[0];
  M1ofl_DW.FyController_states_b[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S6>/Fz Controller' */
  rtb_FzController = ((MHP_n[2] - -2.935316245552321 *
                       M1ofl_DW.FzController_states_l[0]) - 2.8744564263243495 *
                      M1ofl_DW.FzController_states_l[1]) - -0.93914018077202877 *
    M1ofl_DW.FzController_states_l[2];
  M1ofl_DW.FzController_states_l[2] = M1ofl_DW.FzController_states_l[1];
  M1ofl_DW.FzController_states_l[1] = M1ofl_DW.FzController_states_l[0];
  M1ofl_DW.FzController_states_l[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S6>/Mx Controller' */
  rtb_FzController = MHP_n[3];
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FzController -= M1ofl_ConstP.pooled7[numIdx] *
      M1ofl_DW.MxController_states_kb[j];
    numIdx++;
  }

  M1ofl_DW.MxController_states_kb[4] = M1ofl_DW.MxController_states_kb[3];
  M1ofl_DW.MxController_states_kb[3] = M1ofl_DW.MxController_states_kb[2];
  M1ofl_DW.MxController_states_kb[2] = M1ofl_DW.MxController_states_kb[1];
  M1ofl_DW.MxController_states_kb[1] = M1ofl_DW.MxController_states_kb[0];
  M1ofl_DW.MxController_states_kb[0] = rtb_FzController;

  /* End of Update for DiscreteTransferFcn: '<S6>/Mx Controller' */

  /* Update for DiscreteTransferFcn: '<S6>/My Controller' */
  rtb_FzController = MHP_n[4];
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FzController -= M1ofl_ConstP.pooled7[numIdx] *
      M1ofl_DW.MyController_states_f[j];
    numIdx++;
  }

  M1ofl_DW.MyController_states_f[4] = M1ofl_DW.MyController_states_f[3];
  M1ofl_DW.MyController_states_f[3] = M1ofl_DW.MyController_states_f[2];
  M1ofl_DW.MyController_states_f[2] = M1ofl_DW.MyController_states_f[1];
  M1ofl_DW.MyController_states_f[1] = M1ofl_DW.MyController_states_f[0];
  M1ofl_DW.MyController_states_f[0] = rtb_FzController;

  /* End of Update for DiscreteTransferFcn: '<S6>/My Controller' */

  /* Update for DiscreteTransferFcn: '<S6>/Mz Controller' */
  rtb_FzController = ((MHP_n[5] - -2.9551479035479664 *
                       M1ofl_DW.MzController_states_g[0]) - 2.9141589271132933 *
                      M1ofl_DW.MzController_states_g[1]) - -0.95901102356532664 *
    M1ofl_DW.MzController_states_g[2];
  M1ofl_DW.MzController_states_g[2] = M1ofl_DW.MzController_states_g[1];
  M1ofl_DW.MzController_states_g[1] = M1ofl_DW.MzController_states_g[0];
  M1ofl_DW.MzController_states_g[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S8>/Fx Controller' */
  rtb_FzController = ((MHP_g[0] - -2.97089706562984 *
                       M1ofl_DW.FxController_states_pp[0]) - 2.9430254610319251 *
                      M1ofl_DW.FxController_states_pp[1]) - -0.9721283954020854 *
    M1ofl_DW.FxController_states_pp[2];
  M1ofl_DW.FxController_states_pp[2] = M1ofl_DW.FxController_states_pp[1];
  M1ofl_DW.FxController_states_pp[1] = M1ofl_DW.FxController_states_pp[0];
  M1ofl_DW.FxController_states_pp[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S8>/Fy Controller' */
  rtb_FzController = ((MHP_g[1] - -2.97089706562984 *
                       M1ofl_DW.FyController_states_g[0]) - 2.9430254610319251 *
                      M1ofl_DW.FyController_states_g[1]) - -0.9721283954020854 *
    M1ofl_DW.FyController_states_g[2];
  M1ofl_DW.FyController_states_g[2] = M1ofl_DW.FyController_states_g[1];
  M1ofl_DW.FyController_states_g[1] = M1ofl_DW.FyController_states_g[0];
  M1ofl_DW.FyController_states_g[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S8>/Fz Controller' */
  rtb_FzController = ((MHP_g[2] - -2.935316245552321 *
                       M1ofl_DW.FzController_states_a[0]) - 2.8744564263243495 *
                      M1ofl_DW.FzController_states_a[1]) - -0.93914018077202877 *
    M1ofl_DW.FzController_states_a[2];
  M1ofl_DW.FzController_states_a[2] = M1ofl_DW.FzController_states_a[1];
  M1ofl_DW.FzController_states_a[1] = M1ofl_DW.FzController_states_a[0];
  M1ofl_DW.FzController_states_a[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S8>/Mx Controller' */
  rtb_FzController = MHP_g[3];
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FzController -= M1ofl_ConstP.pooled7[numIdx] *
      M1ofl_DW.MxController_states_kz[j];
    numIdx++;
  }

  M1ofl_DW.MxController_states_kz[4] = M1ofl_DW.MxController_states_kz[3];
  M1ofl_DW.MxController_states_kz[3] = M1ofl_DW.MxController_states_kz[2];
  M1ofl_DW.MxController_states_kz[2] = M1ofl_DW.MxController_states_kz[1];
  M1ofl_DW.MxController_states_kz[1] = M1ofl_DW.MxController_states_kz[0];
  M1ofl_DW.MxController_states_kz[0] = rtb_FzController;

  /* End of Update for DiscreteTransferFcn: '<S8>/Mx Controller' */

  /* Update for DiscreteTransferFcn: '<S8>/My Controller' */
  rtb_FzController = MHP_g[4];
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FzController -= M1ofl_ConstP.pooled7[numIdx] *
      M1ofl_DW.MyController_states_m[j];
    numIdx++;
  }

  M1ofl_DW.MyController_states_m[4] = M1ofl_DW.MyController_states_m[3];
  M1ofl_DW.MyController_states_m[3] = M1ofl_DW.MyController_states_m[2];
  M1ofl_DW.MyController_states_m[2] = M1ofl_DW.MyController_states_m[1];
  M1ofl_DW.MyController_states_m[1] = M1ofl_DW.MyController_states_m[0];
  M1ofl_DW.MyController_states_m[0] = rtb_FzController;

  /* End of Update for DiscreteTransferFcn: '<S8>/My Controller' */

  /* Update for DiscreteTransferFcn: '<S8>/Mz Controller' */
  rtb_FzController = ((MHP_g[5] - -2.9551479035479664 *
                       M1ofl_DW.MzController_states_c[0]) - 2.9141589271132933 *
                      M1ofl_DW.MzController_states_c[1]) - -0.95901102356532664 *
    M1ofl_DW.MzController_states_c[2];
  M1ofl_DW.MzController_states_c[2] = M1ofl_DW.MzController_states_c[1];
  M1ofl_DW.MzController_states_c[1] = M1ofl_DW.MzController_states_c[0];
  M1ofl_DW.MzController_states_c[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S10>/Fx Controller' */
  rtb_FzController = ((MHP_c[0] - -2.97089706562984 *
                       M1ofl_DW.FxController_states_c[0]) - 2.9430254610319251 *
                      M1ofl_DW.FxController_states_c[1]) - -0.9721283954020854 *
    M1ofl_DW.FxController_states_c[2];
  M1ofl_DW.FxController_states_c[2] = M1ofl_DW.FxController_states_c[1];
  M1ofl_DW.FxController_states_c[1] = M1ofl_DW.FxController_states_c[0];
  M1ofl_DW.FxController_states_c[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S10>/Fy Controller' */
  rtb_FzController = ((MHP_c[1] - -2.97089706562984 *
                       M1ofl_DW.FyController_states_m[0]) - 2.9430254610319251 *
                      M1ofl_DW.FyController_states_m[1]) - -0.9721283954020854 *
    M1ofl_DW.FyController_states_m[2];
  M1ofl_DW.FyController_states_m[2] = M1ofl_DW.FyController_states_m[1];
  M1ofl_DW.FyController_states_m[1] = M1ofl_DW.FyController_states_m[0];
  M1ofl_DW.FyController_states_m[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S10>/Fz Controller' */
  rtb_FzController = ((MHP_c[2] - -2.935316245552321 *
                       M1ofl_DW.FzController_states_d[0]) - 2.8744564263243495 *
                      M1ofl_DW.FzController_states_d[1]) - -0.93914018077202877 *
    M1ofl_DW.FzController_states_d[2];
  M1ofl_DW.FzController_states_d[2] = M1ofl_DW.FzController_states_d[1];
  M1ofl_DW.FzController_states_d[1] = M1ofl_DW.FzController_states_d[0];
  M1ofl_DW.FzController_states_d[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S10>/Mx Controller' */
  rtb_FzController = MHP_c[3];
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FzController -= M1ofl_ConstP.pooled7[numIdx] *
      M1ofl_DW.MxController_states_l[j];
    numIdx++;
  }

  M1ofl_DW.MxController_states_l[4] = M1ofl_DW.MxController_states_l[3];
  M1ofl_DW.MxController_states_l[3] = M1ofl_DW.MxController_states_l[2];
  M1ofl_DW.MxController_states_l[2] = M1ofl_DW.MxController_states_l[1];
  M1ofl_DW.MxController_states_l[1] = M1ofl_DW.MxController_states_l[0];
  M1ofl_DW.MxController_states_l[0] = rtb_FzController;

  /* End of Update for DiscreteTransferFcn: '<S10>/Mx Controller' */

  /* Update for DiscreteTransferFcn: '<S10>/My Controller' */
  rtb_FzController = MHP_c[4];
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FzController -= M1ofl_ConstP.pooled7[numIdx] *
      M1ofl_DW.MyController_states_bn[j];
    numIdx++;
  }

  M1ofl_DW.MyController_states_bn[4] = M1ofl_DW.MyController_states_bn[3];
  M1ofl_DW.MyController_states_bn[3] = M1ofl_DW.MyController_states_bn[2];
  M1ofl_DW.MyController_states_bn[2] = M1ofl_DW.MyController_states_bn[1];
  M1ofl_DW.MyController_states_bn[1] = M1ofl_DW.MyController_states_bn[0];
  M1ofl_DW.MyController_states_bn[0] = rtb_FzController;

  /* End of Update for DiscreteTransferFcn: '<S10>/My Controller' */

  /* Update for DiscreteTransferFcn: '<S10>/Mz Controller' */
  rtb_FzController = ((MHP_c[5] - -2.9551479035479664 *
                       M1ofl_DW.MzController_states_l[0]) - 2.9141589271132933 *
                      M1ofl_DW.MzController_states_l[1]) - -0.95901102356532664 *
    M1ofl_DW.MzController_states_l[2];
  M1ofl_DW.MzController_states_l[2] = M1ofl_DW.MzController_states_l[1];
  M1ofl_DW.MzController_states_l[1] = M1ofl_DW.MzController_states_l[0];
  M1ofl_DW.MzController_states_l[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S12>/Fx Controller' */
  rtb_FzController = ((MHP_g2[0] - -2.97089706562984 *
                       M1ofl_DW.FxController_states_pd[0]) - 2.9430254610319251 *
                      M1ofl_DW.FxController_states_pd[1]) - -0.9721283954020854 *
    M1ofl_DW.FxController_states_pd[2];
  M1ofl_DW.FxController_states_pd[2] = M1ofl_DW.FxController_states_pd[1];
  M1ofl_DW.FxController_states_pd[1] = M1ofl_DW.FxController_states_pd[0];
  M1ofl_DW.FxController_states_pd[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S12>/Fy Controller' */
  rtb_FzController = ((MHP_g2[1] - -2.97089706562984 *
                       M1ofl_DW.FyController_states_ms[0]) - 2.9430254610319251 *
                      M1ofl_DW.FyController_states_ms[1]) - -0.9721283954020854 *
    M1ofl_DW.FyController_states_ms[2];
  M1ofl_DW.FyController_states_ms[2] = M1ofl_DW.FyController_states_ms[1];
  M1ofl_DW.FyController_states_ms[1] = M1ofl_DW.FyController_states_ms[0];
  M1ofl_DW.FyController_states_ms[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S12>/Fz Controller' */
  rtb_FzController = ((MHP_g2[2] - -2.935316245552321 *
                       M1ofl_DW.FzController_states_e[0]) - 2.8744564263243495 *
                      M1ofl_DW.FzController_states_e[1]) - -0.93914018077202877 *
    M1ofl_DW.FzController_states_e[2];
  M1ofl_DW.FzController_states_e[2] = M1ofl_DW.FzController_states_e[1];
  M1ofl_DW.FzController_states_e[1] = M1ofl_DW.FzController_states_e[0];
  M1ofl_DW.FzController_states_e[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S12>/Mx Controller' */
  rtb_FzController = MHP_g2[3];
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FzController -= M1ofl_ConstP.pooled7[numIdx] *
      M1ofl_DW.MxController_states_g[j];
    numIdx++;
  }

  M1ofl_DW.MxController_states_g[4] = M1ofl_DW.MxController_states_g[3];
  M1ofl_DW.MxController_states_g[3] = M1ofl_DW.MxController_states_g[2];
  M1ofl_DW.MxController_states_g[2] = M1ofl_DW.MxController_states_g[1];
  M1ofl_DW.MxController_states_g[1] = M1ofl_DW.MxController_states_g[0];
  M1ofl_DW.MxController_states_g[0] = rtb_FzController;

  /* End of Update for DiscreteTransferFcn: '<S12>/Mx Controller' */

  /* Update for DiscreteTransferFcn: '<S12>/My Controller' */
  rtb_FzController = MHP_g2[4];
  numIdx = 1;
  for (j = 0; j < 5; j++) {
    rtb_FzController -= M1ofl_ConstP.pooled7[numIdx] *
      M1ofl_DW.MyController_states_l[j];
    numIdx++;
  }

  M1ofl_DW.MyController_states_l[4] = M1ofl_DW.MyController_states_l[3];
  M1ofl_DW.MyController_states_l[3] = M1ofl_DW.MyController_states_l[2];
  M1ofl_DW.MyController_states_l[2] = M1ofl_DW.MyController_states_l[1];
  M1ofl_DW.MyController_states_l[1] = M1ofl_DW.MyController_states_l[0];
  M1ofl_DW.MyController_states_l[0] = rtb_FzController;

  /* End of Update for DiscreteTransferFcn: '<S12>/My Controller' */

  /* Update for DiscreteTransferFcn: '<S12>/Mz Controller' */
  rtb_FzController = ((MHP_g2[5] - -2.9551479035479664 *
                       M1ofl_DW.MzController_states_k[0]) - 2.9141589271132933 *
                      M1ofl_DW.MzController_states_k[1]) - -0.95901102356532664 *
    M1ofl_DW.MzController_states_k[2];
  M1ofl_DW.MzController_states_k[2] = M1ofl_DW.MzController_states_k[1];
  M1ofl_DW.MzController_states_k[1] = M1ofl_DW.MzController_states_k[0];
  M1ofl_DW.MzController_states_k[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S15>/Fx Controller' */
  rtb_FzController = ((MHP_b[0] - -2.97089706562984 *
                       M1ofl_DW.FxController_states_mx[0]) - 2.9430254610319251 *
                      M1ofl_DW.FxController_states_mx[1]) - -0.9721283954020854 *
    M1ofl_DW.FxController_states_mx[2];
  M1ofl_DW.FxController_states_mx[2] = M1ofl_DW.FxController_states_mx[1];
  M1ofl_DW.FxController_states_mx[1] = M1ofl_DW.FxController_states_mx[0];
  M1ofl_DW.FxController_states_mx[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S15>/Fy Controller' */
  rtb_FzController = ((MHP_b[1] - -2.9736051405026691 *
                       M1ofl_DW.FyController_states_bh[0]) - 2.9475609495552049 *
                      M1ofl_DW.FyController_states_bh[1]) - -0.97395580905253565
    * M1ofl_DW.FyController_states_bh[2];
  M1ofl_DW.FyController_states_bh[2] = M1ofl_DW.FyController_states_bh[1];
  M1ofl_DW.FyController_states_bh[1] = M1ofl_DW.FyController_states_bh[0];
  M1ofl_DW.FyController_states_bh[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S15>/Fz Controller' */
  rtb_FzController = ((MHP_b[2] - -2.935316245552321 *
                       M1ofl_DW.FzController_states_ei[0]) - 2.8744564263243495 *
                      M1ofl_DW.FzController_states_ei[1]) - -0.93914018077202877
    * M1ofl_DW.FzController_states_ei[2];
  M1ofl_DW.FzController_states_ei[2] = M1ofl_DW.FzController_states_ei[1];
  M1ofl_DW.FzController_states_ei[1] = M1ofl_DW.FzController_states_ei[0];
  M1ofl_DW.FzController_states_ei[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S15>/Mx Controller' */
  rtb_FzController = ((MHP_b[3] - -2.9736051405026691 *
                       M1ofl_DW.MxController_states_h[0]) - 2.9475609495552049 *
                      M1ofl_DW.MxController_states_h[1]) - -0.97395580905253565 *
    M1ofl_DW.MxController_states_h[2];
  M1ofl_DW.MxController_states_h[2] = M1ofl_DW.MxController_states_h[1];
  M1ofl_DW.MxController_states_h[1] = M1ofl_DW.MxController_states_h[0];
  M1ofl_DW.MxController_states_h[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S15>/My Controller' */
  rtb_FzController = ((MHP_b[4] - -2.9736051405026691 *
                       M1ofl_DW.MyController_states_k[0]) - 2.9475609495552049 *
                      M1ofl_DW.MyController_states_k[1]) - -0.97395580905253565 *
    M1ofl_DW.MyController_states_k[2];
  M1ofl_DW.MyController_states_k[2] = M1ofl_DW.MyController_states_k[1];
  M1ofl_DW.MyController_states_k[1] = M1ofl_DW.MyController_states_k[0];
  M1ofl_DW.MyController_states_k[0] = rtb_FzController;

  /* Update for DiscreteTransferFcn: '<S15>/Mz Controller' */
  rtb_FzController = ((MHP_b[5] - -2.9736051405026691 *
                       M1ofl_DW.MzController_states_m[0]) - 2.9475609495552049 *
                      M1ofl_DW.MzController_states_m[1]) - -0.97395580905253565 *
    M1ofl_DW.MzController_states_m[2];
  M1ofl_DW.MzController_states_m[2] = M1ofl_DW.MzController_states_m[1];
  M1ofl_DW.MzController_states_m[1] = M1ofl_DW.MzController_states_m[0];
  M1ofl_DW.MzController_states_m[0] = rtb_FzController;
}

/* Model initialize function */
void M1ofl_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(M1ofl_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&M1ofl_DW, 0,
                sizeof(DW_M1ofl_T));

  /* external inputs */
  (void)memset((void *)&M1ofl_U, 0, sizeof(ExtU_M1ofl_T));

  /* external outputs */
  (void) memset(&M1ofl_Y.Output[0], 0,
                2316U*sizeof(real_T));
}

/* Model terminate function */
void M1ofl_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
