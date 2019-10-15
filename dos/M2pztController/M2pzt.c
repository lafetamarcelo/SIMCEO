/*
 * File: M2pzt.c
 *
 * Code generated for Simulink model 'M2pzt'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Wed Sep  4 11:57:16 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M2pzt.h"
#include "M2pzt_private.h"

/* Block states (default storage) */
DW_M2pzt_T M2pzt_DW;

/* External inputs (root inport signals with default storage) */
ExtU_M2pzt_T M2pzt_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_M2pzt_T M2pzt_Y;

/* Real-time model */
RT_MODEL_M2pzt_T M2pzt_M_;
RT_MODEL_M2pzt_T *const M2pzt_M = &M2pzt_M_;

/* Model step function */
void M2pzt_step(void)
{
  /* local block i/o variables */
  real_T rtb_Sum[3];
  real_T rtb_Sum_g[3];
  real_T rtb_Sum_a[3];
  real_T rtb_Sum_l[3];
  real_T rtb_Sum_m[3];
  real_T rtb_Sum_n[3];
  real_T rtb_Sum_h[3];
  real_T rtb_Internal;
  real_T rtb_Internal_c;
  real_T rtb_Internal_d;
  real_T rtb_Internal_a;
  real_T rtb_Internal_m;
  real_T rtb_Internal_cn;
  real_T rtb_Internal_f;
  real_T rtb_Internal_f3;
  real_T rtb_Internal_k;
  real_T rtb_Internal_m3;
  real_T rtb_Internal_n;
  real_T rtb_Internal_c4;
  real_T rtb_Internal_b;
  real_T rtb_Internal_fl;
  real_T rtb_Internal_fu;
  real_T rtb_Internal_h;
  real_T rtb_Internal_bq;
  real_T rtb_Internal_nj;
  real_T rtb_Internal_dn;
  real_T rtb_Internal_ko;
  real_T rtb_Internal_g;
  real_T rtb_Internal_an;
  real_T rtb_Internal_cm;
  real_T rtb_Internal_l;
  real_T rtb_Internal_lr;
  real_T rtb_Internal_fc;
  real_T rtb_Internal_p;
  real_T rtb_Internal_e;
  real_T rtb_Internal_mt;
  real_T rtb_Internal_d5;
  real_T rtb_Internal_j;
  real_T rtb_Internal_p3;
  real_T rtb_Internal_dr;
  real_T rtb_Internal_nq;
  real_T rtb_Internal_g2;
  real_T rtb_Internal_fj;
  real_T rtb_Internal_bx;
  real_T rtb_Internal_pk;
  real_T rtb_Internal_hb;
  real_T rtb_Internal_e1;
  real_T rtb_Internal_au;
  real_T rtb_Internal_l3;
  real_T rtb_Internal_dz;
  real_T rtb_Internal_dk;
  real_T rtb_Internal_nw;
  real_T rtb_Internal_bo;
  real_T rtb_Internal_o;
  real_T rtb_Internal_bf;
  real_T rtb_Internal_eu;
  real_T rtb_Internal_jg;
  real_T rtb_Internal_m1;
  real_T rtb_Internal_mp;
  real_T rtb_Internal_b4;
  real_T rtb_Internal_gf;
  real_T rtb_Internal_dq;
  real_T rtb_Internal_as;
  real_T rtb_Internal_dy;
  real_T rtb_Internal_nr;
  real_T rtb_Internal_lu;
  real_T rtb_Internal_o1;
  real_T rtb_Internal_b4t;
  real_T rtb_Internal_et;
  real_T rtb_Internal_am;
  real_T rtb_Internal_ag;
  real_T rtb_Internal_o3;
  real_T rtb_Internal_da;
  real_T rtb_Internal_fe;
  real_T rtb_Internal_h4;
  real_T rtb_Internal_di;
  real_T rtb_Internal_cq;
  real_T rtb_Internal_lz;
  real_T rtb_Internal_auu;
  real_T rtb_Internal_ce;
  real_T rtb_Internal_hf;
  real_T rtb_Internal_dru;
  real_T rtb_Internal_p2;
  real_T rtb_Internal_ml;
  real_T rtb_Internal_cv;
  real_T rtb_Internal_m0;
  real_T rtb_Internal_c1;
  real_T rtb_Internal_oi;
  real_T rtb_Internal_b5;
  real_T rtb_Internal_bl;
  real_T rtb_Internal_js;
  real_T rtb_Internal_en;
  real_T rtb_Internal_nv;
  real_T rtb_Internal_p2h;
  real_T rtb_delta3[6];
  real_T rtb_delta3_l[6];
  real_T rtb_delta3_j[6];
  real_T rtb_delta3_p[6];
  real_T rtb_delta3_b1[6];
  real_T rtb_delta3_e[6];
  int32_T i;
  real_T tmp[6];
  real_T tmp_0[3];
  int32_T i_0;
  real_T tmp_1[3];
  real_T tmp_2[3];
  real_T tmp_3[3];
  real_T tmp_4[3];
  real_T tmp_5[3];
  real_T tmp_6[3];

  /* DiscreteStateSpace: '<S12>/Internal' */
  {
    rtb_Internal_en = (0.694)*M2pzt_DW.Internal_DSTATE[0] + (-4.036)*
      M2pzt_DW.Internal_DSTATE[1];
  }

  /* DiscreteStateSpace: '<S13>/Internal' */
  {
    rtb_Internal_nv = (0.694)*M2pzt_DW.Internal_DSTATE_d[0] + (-4.036)*
      M2pzt_DW.Internal_DSTATE_d[1];
  }

  /* DiscreteStateSpace: '<S14>/Internal' */
  {
    rtb_Internal_p2h = (0.694)*M2pzt_DW.Internal_DSTATE_o[0] + (-4.036)*
      M2pzt_DW.Internal_DSTATE_o[1];
  }

  /* Gain: '<S2>/delta3' incorporates:
   *  SignalConversion: '<S2>/TmpSignal ConversionAtdelta3Inport1'
   */
  for (i = 0; i < 6; i++) {
    rtb_delta3[i] = 0.0;
    rtb_delta3[i] += M2pzt_ConstP.pooled6[i] * rtb_Internal_en;
    rtb_delta3[i] += M2pzt_ConstP.pooled6[i + 6] * rtb_Internal_nv;
    rtb_delta3[i] += M2pzt_ConstP.pooled6[i + 12] * rtb_Internal_p2h;
  }

  /* End of Gain: '<S2>/delta3' */

  /* DiscreteStateSpace: '<S72>/Internal' */
  {
    rtb_Internal_p2h = (0.694)*M2pzt_DW.Internal_DSTATE_a[0] + (-4.036)*
      M2pzt_DW.Internal_DSTATE_a[1];
  }

  /* DiscreteStateSpace: '<S73>/Internal' */
  {
    rtb_Internal_nv = (0.694)*M2pzt_DW.Internal_DSTATE_h[0] + (-4.036)*
      M2pzt_DW.Internal_DSTATE_h[1];
  }

  /* DiscreteStateSpace: '<S74>/Internal' */
  {
    rtb_Internal_en = (0.694)*M2pzt_DW.Internal_DSTATE_m[0] + (-4.036)*
      M2pzt_DW.Internal_DSTATE_m[1];
  }

  /* Gain: '<S3>/delta3' incorporates:
   *  SignalConversion: '<S3>/TmpSignal ConversionAtdelta3Inport1'
   */
  for (i = 0; i < 6; i++) {
    rtb_delta3_l[i] = 0.0;
    rtb_delta3_l[i] += M2pzt_ConstP.pooled6[i] * rtb_Internal_p2h;
    rtb_delta3_l[i] += M2pzt_ConstP.pooled6[i + 6] * rtb_Internal_nv;
    rtb_delta3_l[i] += M2pzt_ConstP.pooled6[i + 12] * rtb_Internal_en;
  }

  /* End of Gain: '<S3>/delta3' */

  /* DiscreteStateSpace: '<S132>/Internal' */
  {
    rtb_Internal_p2h = (0.694)*M2pzt_DW.Internal_DSTATE_e[0] + (-4.036)*
      M2pzt_DW.Internal_DSTATE_e[1];
  }

  /* DiscreteStateSpace: '<S133>/Internal' */
  {
    rtb_Internal_nv = (0.694)*M2pzt_DW.Internal_DSTATE_b[0] + (-4.036)*
      M2pzt_DW.Internal_DSTATE_b[1];
  }

  /* DiscreteStateSpace: '<S134>/Internal' */
  {
    rtb_Internal_en = (0.694)*M2pzt_DW.Internal_DSTATE_m5[0] + (-4.036)*
      M2pzt_DW.Internal_DSTATE_m5[1];
  }

  /* Gain: '<S4>/delta3' incorporates:
   *  SignalConversion: '<S4>/TmpSignal ConversionAtdelta3Inport1'
   */
  for (i = 0; i < 6; i++) {
    rtb_delta3_j[i] = 0.0;
    rtb_delta3_j[i] += M2pzt_ConstP.pooled6[i] * rtb_Internal_p2h;
    rtb_delta3_j[i] += M2pzt_ConstP.pooled6[i + 6] * rtb_Internal_nv;
    rtb_delta3_j[i] += M2pzt_ConstP.pooled6[i + 12] * rtb_Internal_en;
  }

  /* End of Gain: '<S4>/delta3' */

  /* DiscreteStateSpace: '<S192>/Internal' */
  {
    rtb_Internal_p2h = (0.694)*M2pzt_DW.Internal_DSTATE_k[0] + (-4.036)*
      M2pzt_DW.Internal_DSTATE_k[1];
  }

  /* DiscreteStateSpace: '<S193>/Internal' */
  {
    rtb_Internal_nv = (0.694)*M2pzt_DW.Internal_DSTATE_f[0] + (-4.036)*
      M2pzt_DW.Internal_DSTATE_f[1];
  }

  /* DiscreteStateSpace: '<S194>/Internal' */
  {
    rtb_Internal_en = (0.694)*M2pzt_DW.Internal_DSTATE_c[0] + (-4.036)*
      M2pzt_DW.Internal_DSTATE_c[1];
  }

  /* Gain: '<S5>/delta3' incorporates:
   *  SignalConversion: '<S5>/TmpSignal ConversionAtdelta3Inport1'
   */
  for (i = 0; i < 6; i++) {
    rtb_delta3_p[i] = 0.0;
    rtb_delta3_p[i] += M2pzt_ConstP.pooled6[i] * rtb_Internal_p2h;
    rtb_delta3_p[i] += M2pzt_ConstP.pooled6[i + 6] * rtb_Internal_nv;
    rtb_delta3_p[i] += M2pzt_ConstP.pooled6[i + 12] * rtb_Internal_en;
  }

  /* End of Gain: '<S5>/delta3' */

  /* DiscreteStateSpace: '<S252>/Internal' */
  {
    rtb_Internal_p2h = (0.694)*M2pzt_DW.Internal_DSTATE_cp[0] + (-4.036)*
      M2pzt_DW.Internal_DSTATE_cp[1];
  }

  /* DiscreteStateSpace: '<S253>/Internal' */
  {
    rtb_Internal_nv = (0.694)*M2pzt_DW.Internal_DSTATE_bl[0] + (-4.036)*
      M2pzt_DW.Internal_DSTATE_bl[1];
  }

  /* DiscreteStateSpace: '<S254>/Internal' */
  {
    rtb_Internal_en = (0.694)*M2pzt_DW.Internal_DSTATE_hn[0] + (-4.036)*
      M2pzt_DW.Internal_DSTATE_hn[1];
  }

  /* Gain: '<S6>/delta3' incorporates:
   *  SignalConversion: '<S6>/TmpSignal ConversionAtdelta3Inport1'
   */
  for (i = 0; i < 6; i++) {
    rtb_delta3_b1[i] = 0.0;
    rtb_delta3_b1[i] += M2pzt_ConstP.pooled6[i] * rtb_Internal_p2h;
    rtb_delta3_b1[i] += M2pzt_ConstP.pooled6[i + 6] * rtb_Internal_nv;
    rtb_delta3_b1[i] += M2pzt_ConstP.pooled6[i + 12] * rtb_Internal_en;
  }

  /* End of Gain: '<S6>/delta3' */

  /* DiscreteStateSpace: '<S312>/Internal' */
  {
    rtb_Internal_p2h = (0.694)*M2pzt_DW.Internal_DSTATE_es[0] + (-4.036)*
      M2pzt_DW.Internal_DSTATE_es[1];
  }

  /* DiscreteStateSpace: '<S313>/Internal' */
  {
    rtb_Internal_nv = (0.694)*M2pzt_DW.Internal_DSTATE_k1[0] + (-4.036)*
      M2pzt_DW.Internal_DSTATE_k1[1];
  }

  /* DiscreteStateSpace: '<S314>/Internal' */
  {
    rtb_Internal_en = (0.694)*M2pzt_DW.Internal_DSTATE_g[0] + (-4.036)*
      M2pzt_DW.Internal_DSTATE_g[1];
  }

  /* Gain: '<S7>/delta3' incorporates:
   *  SignalConversion: '<S7>/TmpSignal ConversionAtdelta3Inport1'
   */
  for (i = 0; i < 6; i++) {
    rtb_delta3_e[i] = 0.0;
    rtb_delta3_e[i] += M2pzt_ConstP.pooled6[i] * rtb_Internal_p2h;
    rtb_delta3_e[i] += M2pzt_ConstP.pooled6[i + 6] * rtb_Internal_nv;
    rtb_delta3_e[i] += M2pzt_ConstP.pooled6[i + 12] * rtb_Internal_en;
  }

  /* End of Gain: '<S7>/delta3' */

  /* DiscreteStateSpace: '<S372>/Internal' */
  {
    rtb_Internal_p2h = (0.694)*M2pzt_DW.Internal_DSTATE_ai[0] + (-4.036)*
      M2pzt_DW.Internal_DSTATE_ai[1];
  }

  /* DiscreteStateSpace: '<S373>/Internal' */
  {
    rtb_Internal_nv = (0.694)*M2pzt_DW.Internal_DSTATE_p[0] + (-4.036)*
      M2pzt_DW.Internal_DSTATE_p[1];
  }

  /* DiscreteStateSpace: '<S374>/Internal' */
  {
    rtb_Internal_en = (0.694)*M2pzt_DW.Internal_DSTATE_oj[0] + (-4.036)*
      M2pzt_DW.Internal_DSTATE_oj[1];
  }

  for (i = 0; i < 6; i++) {
    /* Gain: '<S8>/delta3' incorporates:
     *  Outport: '<Root>/Output'
     *  SignalConversion: '<S8>/TmpSignal ConversionAtdelta3Inport1'
     */
    tmp[i] = 0.0;
    tmp[i] += M2pzt_ConstP.pooled6[i] * rtb_Internal_p2h;
    tmp[i] += M2pzt_ConstP.pooled6[i + 6] * rtb_Internal_nv;
    tmp[i] += M2pzt_ConstP.pooled6[i + 12] * rtb_Internal_en;

    /* Outport: '<Root>/Output' incorporates:
     *  Gain: '<S8>/delta3'
     */
    M2pzt_Y.Output[i] = rtb_delta3[i];
    M2pzt_Y.Output[i + 6] = rtb_delta3_l[i];
    M2pzt_Y.Output[i + 12] = rtb_delta3_j[i];
    M2pzt_Y.Output[i + 18] = rtb_delta3_p[i];
    M2pzt_Y.Output[i + 24] = rtb_delta3_b1[i];
    M2pzt_Y.Output[i + 30] = rtb_delta3_e[i];
    M2pzt_Y.Output[i + 36] = tmp[i];
  }

  for (i = 0; i < 3; i++) {
    /* Gain: '<S2>/RelativeDisplace' incorporates:
     *  Inport: '<Root>/Feedback'
     *  Sum: '<S2>/Sum'
     */
    tmp_0[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp_0[i] += M2pzt_ConstP.pooled8[3 * i_0 + i] * M2pzt_U.Feedback[i_0];
    }

    /* End of Gain: '<S2>/RelativeDisplace' */

    /* Sum: '<S2>/Sum' incorporates:
     *  Gain: '<S2>/PTT2PZT'
     *  Inport: '<Root>/Reference'
     */
    rtb_Sum[i] = (M2pzt_ConstP.pooled7[i + 6] * M2pzt_U.Reference[2] +
                  (M2pzt_ConstP.pooled7[i + 3] * M2pzt_U.Reference[1] +
                   M2pzt_ConstP.pooled7[i] * M2pzt_U.Reference[0])) - tmp_0[i];

    /* Gain: '<S3>/RelativeDisplace' incorporates:
     *  Inport: '<Root>/Feedback'
     *  Sum: '<S3>/Sum'
     */
    tmp_1[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp_1[i] += M2pzt_ConstP.pooled8[3 * i_0 + i] * M2pzt_U.Feedback[6 + i_0];
    }

    /* End of Gain: '<S3>/RelativeDisplace' */

    /* Sum: '<S3>/Sum' incorporates:
     *  Gain: '<S3>/PTT2PZT'
     *  Inport: '<Root>/Reference'
     */
    rtb_Sum_g[i] = (M2pzt_ConstP.pooled7[i + 6] * M2pzt_U.Reference[5] +
                    (M2pzt_ConstP.pooled7[i + 3] * M2pzt_U.Reference[4] +
                     M2pzt_ConstP.pooled7[i] * M2pzt_U.Reference[3])) - tmp_1[i];

    /* Gain: '<S4>/RelativeDisplace' incorporates:
     *  Inport: '<Root>/Feedback'
     *  Sum: '<S4>/Sum'
     */
    tmp_2[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp_2[i] += M2pzt_ConstP.pooled8[3 * i_0 + i] * M2pzt_U.Feedback[12 + i_0];
    }

    /* End of Gain: '<S4>/RelativeDisplace' */

    /* Sum: '<S4>/Sum' incorporates:
     *  Gain: '<S4>/PTT2PZT'
     *  Inport: '<Root>/Reference'
     */
    rtb_Sum_a[i] = (M2pzt_ConstP.pooled7[i + 6] * M2pzt_U.Reference[8] +
                    (M2pzt_ConstP.pooled7[i + 3] * M2pzt_U.Reference[7] +
                     M2pzt_ConstP.pooled7[i] * M2pzt_U.Reference[6])) - tmp_2[i];

    /* Gain: '<S5>/RelativeDisplace' incorporates:
     *  Inport: '<Root>/Feedback'
     *  Sum: '<S5>/Sum'
     */
    tmp_3[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp_3[i] += M2pzt_ConstP.pooled8[3 * i_0 + i] * M2pzt_U.Feedback[18 + i_0];
    }

    /* End of Gain: '<S5>/RelativeDisplace' */

    /* Sum: '<S5>/Sum' incorporates:
     *  Gain: '<S5>/PTT2PZT'
     *  Inport: '<Root>/Reference'
     */
    rtb_Sum_l[i] = (M2pzt_ConstP.pooled7[i + 6] * M2pzt_U.Reference[11] +
                    (M2pzt_ConstP.pooled7[i + 3] * M2pzt_U.Reference[10] +
                     M2pzt_ConstP.pooled7[i] * M2pzt_U.Reference[9])) - tmp_3[i];

    /* Gain: '<S6>/RelativeDisplace' incorporates:
     *  Inport: '<Root>/Feedback'
     *  Sum: '<S6>/Sum'
     */
    tmp_4[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp_4[i] += M2pzt_ConstP.pooled8[3 * i_0 + i] * M2pzt_U.Feedback[24 + i_0];
    }

    /* End of Gain: '<S6>/RelativeDisplace' */

    /* Sum: '<S6>/Sum' incorporates:
     *  Gain: '<S6>/PTT2PZT'
     *  Inport: '<Root>/Reference'
     */
    rtb_Sum_m[i] = (M2pzt_ConstP.pooled7[i + 6] * M2pzt_U.Reference[14] +
                    (M2pzt_ConstP.pooled7[i + 3] * M2pzt_U.Reference[13] +
                     M2pzt_ConstP.pooled7[i] * M2pzt_U.Reference[12])) - tmp_4[i];

    /* Gain: '<S7>/RelativeDisplace' incorporates:
     *  Inport: '<Root>/Feedback'
     *  Sum: '<S7>/Sum'
     */
    tmp_5[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp_5[i] += M2pzt_ConstP.pooled8[3 * i_0 + i] * M2pzt_U.Feedback[30 + i_0];
    }

    /* End of Gain: '<S7>/RelativeDisplace' */

    /* Sum: '<S7>/Sum' incorporates:
     *  Gain: '<S7>/PTT2PZT'
     *  Inport: '<Root>/Reference'
     */
    rtb_Sum_n[i] = (M2pzt_ConstP.pooled7[i + 6] * M2pzt_U.Reference[17] +
                    (M2pzt_ConstP.pooled7[i + 3] * M2pzt_U.Reference[16] +
                     M2pzt_ConstP.pooled7[i] * M2pzt_U.Reference[15])) - tmp_5[i];

    /* Gain: '<S8>/RelativeDisplace' incorporates:
     *  Inport: '<Root>/Feedback'
     *  Sum: '<S8>/Sum'
     */
    tmp_6[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp_6[i] += M2pzt_ConstP.pooled8[3 * i_0 + i] * M2pzt_U.Feedback[36 + i_0];
    }

    /* End of Gain: '<S8>/RelativeDisplace' */

    /* Sum: '<S8>/Sum' incorporates:
     *  Gain: '<S8>/PTT2PZT'
     *  Inport: '<Root>/Reference'
     */
    rtb_Sum_h[i] = (M2pzt_ConstP.pooled7[i + 6] * M2pzt_U.Reference[20] +
                    (M2pzt_ConstP.pooled7[i + 3] * M2pzt_U.Reference[19] +
                     M2pzt_ConstP.pooled7[i] * M2pzt_U.Reference[18])) - tmp_6[i];
  }

  /* DiscreteStateSpace: '<S9>/Internal' */
  {
    rtb_Internal = (9.3563552113359361)*M2pzt_DW.Internal_DSTATE_j[0]
      + (18.271835534636281)*M2pzt_DW.Internal_DSTATE_j[1]
      + (8.9256280204502634)*M2pzt_DW.Internal_DSTATE_j[2];
  }

  /* DiscreteStateSpace: '<S15>/Internal' */
  {
    rtb_Internal_c = (-0.40853755149358228)*M2pzt_DW.Internal_DSTATE_ml[0]
      + (0.40853755149358228)*M2pzt_DW.Internal_DSTATE_ml[1];
    rtb_Internal_c += 1.0*rtb_Internal;
  }

  /* DiscreteStateSpace: '<S18>/Internal' */
  {
    rtb_Internal_d = 1.0*rtb_Internal_c;
  }

  /* DiscreteStateSpace: '<S21>/Internal' */
  {
    rtb_Internal_a = 1.0*rtb_Internal_d;
  }

  /* DiscreteStateSpace: '<S10>/Internal' */
  {
    rtb_Internal_m = (9.3563552113359361)*M2pzt_DW.Internal_DSTATE_gx[0]
      + (18.271835534636281)*M2pzt_DW.Internal_DSTATE_gx[1]
      + (8.9256280204502634)*M2pzt_DW.Internal_DSTATE_gx[2];
  }

  /* DiscreteStateSpace: '<S16>/Internal' */
  {
    rtb_Internal_cn = (-0.40853755149358228)*M2pzt_DW.Internal_DSTATE_jo[0]
      + (0.40853755149358228)*M2pzt_DW.Internal_DSTATE_jo[1];
    rtb_Internal_cn += 1.0*rtb_Internal_m;
  }

  /* DiscreteStateSpace: '<S19>/Internal' */
  {
    rtb_Internal_f = 1.0*rtb_Internal_cn;
  }

  /* DiscreteStateSpace: '<S22>/Internal' */
  {
    rtb_Internal_f3 = 1.0*rtb_Internal_f;
  }

  /* DiscreteStateSpace: '<S11>/Internal' */
  {
    rtb_Internal_k = (9.3563552113359361)*M2pzt_DW.Internal_DSTATE_bl1[0]
      + (18.271835534636281)*M2pzt_DW.Internal_DSTATE_bl1[1]
      + (8.9256280204502634)*M2pzt_DW.Internal_DSTATE_bl1[2];
  }

  /* DiscreteStateSpace: '<S17>/Internal' */
  {
    rtb_Internal_m3 = (-0.40853755149358228)*M2pzt_DW.Internal_DSTATE_fq[0]
      + (0.40853755149358228)*M2pzt_DW.Internal_DSTATE_fq[1];
    rtb_Internal_m3 += 1.0*rtb_Internal_k;
  }

  /* DiscreteStateSpace: '<S20>/Internal' */
  {
    rtb_Internal_n = 1.0*rtb_Internal_m3;
  }

  /* DiscreteStateSpace: '<S23>/Internal' */
  {
    rtb_Internal_c4 = 1.0*rtb_Internal_n;
  }

  /* DiscreteStateSpace: '<S69>/Internal' */
  {
    rtb_Internal_b = (9.3563552113359361)*M2pzt_DW.Internal_DSTATE_fr[0]
      + (18.271835534636281)*M2pzt_DW.Internal_DSTATE_fr[1]
      + (8.9256280204502634)*M2pzt_DW.Internal_DSTATE_fr[2];
  }

  /* DiscreteStateSpace: '<S75>/Internal' */
  {
    rtb_Internal_fl = (-0.40853755149358228)*M2pzt_DW.Internal_DSTATE_l[0]
      + (0.40853755149358228)*M2pzt_DW.Internal_DSTATE_l[1];
    rtb_Internal_fl += 1.0*rtb_Internal_b;
  }

  /* DiscreteStateSpace: '<S78>/Internal' */
  {
    rtb_Internal_fu = 1.0*rtb_Internal_fl;
  }

  /* DiscreteStateSpace: '<S81>/Internal' */
  {
    rtb_Internal_h = 1.0*rtb_Internal_fu;
  }

  /* DiscreteStateSpace: '<S70>/Internal' */
  {
    rtb_Internal_bq = (9.3563552113359361)*M2pzt_DW.Internal_DSTATE_gi[0]
      + (18.271835534636281)*M2pzt_DW.Internal_DSTATE_gi[1]
      + (8.9256280204502634)*M2pzt_DW.Internal_DSTATE_gi[2];
  }

  /* DiscreteStateSpace: '<S76>/Internal' */
  {
    rtb_Internal_nj = (-0.40853755149358228)*M2pzt_DW.Internal_DSTATE_i[0]
      + (0.40853755149358228)*M2pzt_DW.Internal_DSTATE_i[1];
    rtb_Internal_nj += 1.0*rtb_Internal_bq;
  }

  /* DiscreteStateSpace: '<S79>/Internal' */
  {
    rtb_Internal_dn = 1.0*rtb_Internal_nj;
  }

  /* DiscreteStateSpace: '<S82>/Internal' */
  {
    rtb_Internal_ko = 1.0*rtb_Internal_dn;
  }

  /* DiscreteStateSpace: '<S71>/Internal' */
  {
    rtb_Internal_g = (9.3563552113359361)*M2pzt_DW.Internal_DSTATE_or[0]
      + (18.271835534636281)*M2pzt_DW.Internal_DSTATE_or[1]
      + (8.9256280204502634)*M2pzt_DW.Internal_DSTATE_or[2];
  }

  /* DiscreteStateSpace: '<S77>/Internal' */
  {
    rtb_Internal_an = (-0.40853755149358228)*M2pzt_DW.Internal_DSTATE_ku[0]
      + (0.40853755149358228)*M2pzt_DW.Internal_DSTATE_ku[1];
    rtb_Internal_an += 1.0*rtb_Internal_g;
  }

  /* DiscreteStateSpace: '<S80>/Internal' */
  {
    rtb_Internal_cm = 1.0*rtb_Internal_an;
  }

  /* DiscreteStateSpace: '<S83>/Internal' */
  {
    rtb_Internal_l = 1.0*rtb_Internal_cm;
  }

  /* DiscreteStateSpace: '<S129>/Internal' */
  {
    rtb_Internal_lr = (9.3563552113359361)*M2pzt_DW.Internal_DSTATE_ke[0]
      + (18.271835534636281)*M2pzt_DW.Internal_DSTATE_ke[1]
      + (8.9256280204502634)*M2pzt_DW.Internal_DSTATE_ke[2];
  }

  /* DiscreteStateSpace: '<S135>/Internal' */
  {
    rtb_Internal_fc = (-0.40853755149358228)*M2pzt_DW.Internal_DSTATE_lj[0]
      + (0.40853755149358228)*M2pzt_DW.Internal_DSTATE_lj[1];
    rtb_Internal_fc += 1.0*rtb_Internal_lr;
  }

  /* DiscreteStateSpace: '<S138>/Internal' */
  {
    rtb_Internal_p = 1.0*rtb_Internal_fc;
  }

  /* DiscreteStateSpace: '<S141>/Internal' */
  {
    rtb_Internal_e = 1.0*rtb_Internal_p;
  }

  /* DiscreteStateSpace: '<S130>/Internal' */
  {
    rtb_Internal_mt = (9.3563552113359361)*M2pzt_DW.Internal_DSTATE_bo[0]
      + (18.271835534636281)*M2pzt_DW.Internal_DSTATE_bo[1]
      + (8.9256280204502634)*M2pzt_DW.Internal_DSTATE_bo[2];
  }

  /* DiscreteStateSpace: '<S136>/Internal' */
  {
    rtb_Internal_d5 = (-0.40853755149358228)*M2pzt_DW.Internal_DSTATE_an[0]
      + (0.40853755149358228)*M2pzt_DW.Internal_DSTATE_an[1];
    rtb_Internal_d5 += 1.0*rtb_Internal_mt;
  }

  /* DiscreteStateSpace: '<S139>/Internal' */
  {
    rtb_Internal_j = 1.0*rtb_Internal_d5;
  }

  /* DiscreteStateSpace: '<S142>/Internal' */
  {
    rtb_Internal_p3 = 1.0*rtb_Internal_j;
  }

  /* DiscreteStateSpace: '<S131>/Internal' */
  {
    rtb_Internal_dr = (9.3563552113359361)*M2pzt_DW.Internal_DSTATE_af[0]
      + (18.271835534636281)*M2pzt_DW.Internal_DSTATE_af[1]
      + (8.9256280204502634)*M2pzt_DW.Internal_DSTATE_af[2];
  }

  /* DiscreteStateSpace: '<S137>/Internal' */
  {
    rtb_Internal_nq = (-0.40853755149358228)*M2pzt_DW.Internal_DSTATE_ph[0]
      + (0.40853755149358228)*M2pzt_DW.Internal_DSTATE_ph[1];
    rtb_Internal_nq += 1.0*rtb_Internal_dr;
  }

  /* DiscreteStateSpace: '<S140>/Internal' */
  {
    rtb_Internal_g2 = 1.0*rtb_Internal_nq;
  }

  /* DiscreteStateSpace: '<S143>/Internal' */
  {
    rtb_Internal_fj = 1.0*rtb_Internal_g2;
  }

  /* DiscreteStateSpace: '<S189>/Internal' */
  {
    rtb_Internal_bx = (9.3563552113359361)*M2pzt_DW.Internal_DSTATE_ec[0]
      + (18.271835534636281)*M2pzt_DW.Internal_DSTATE_ec[1]
      + (8.9256280204502634)*M2pzt_DW.Internal_DSTATE_ec[2];
  }

  /* DiscreteStateSpace: '<S195>/Internal' */
  {
    rtb_Internal_pk = (-0.40853755149358228)*M2pzt_DW.Internal_DSTATE_mg[0]
      + (0.40853755149358228)*M2pzt_DW.Internal_DSTATE_mg[1];
    rtb_Internal_pk += 1.0*rtb_Internal_bx;
  }

  /* DiscreteStateSpace: '<S198>/Internal' */
  {
    rtb_Internal_hb = 1.0*rtb_Internal_pk;
  }

  /* DiscreteStateSpace: '<S201>/Internal' */
  {
    rtb_Internal_e1 = 1.0*rtb_Internal_hb;
  }

  /* DiscreteStateSpace: '<S190>/Internal' */
  {
    rtb_Internal_au = (9.3563552113359361)*M2pzt_DW.Internal_DSTATE_jx[0]
      + (18.271835534636281)*M2pzt_DW.Internal_DSTATE_jx[1]
      + (8.9256280204502634)*M2pzt_DW.Internal_DSTATE_jx[2];
  }

  /* DiscreteStateSpace: '<S196>/Internal' */
  {
    rtb_Internal_l3 = (-0.40853755149358228)*M2pzt_DW.Internal_DSTATE_c4[0]
      + (0.40853755149358228)*M2pzt_DW.Internal_DSTATE_c4[1];
    rtb_Internal_l3 += 1.0*rtb_Internal_au;
  }

  /* DiscreteStateSpace: '<S199>/Internal' */
  {
    rtb_Internal_dz = 1.0*rtb_Internal_l3;
  }

  /* DiscreteStateSpace: '<S202>/Internal' */
  {
    rtb_Internal_dk = 1.0*rtb_Internal_dz;
  }

  /* DiscreteStateSpace: '<S191>/Internal' */
  {
    rtb_Internal_nw = (9.3563552113359361)*M2pzt_DW.Internal_DSTATE_pf[0]
      + (18.271835534636281)*M2pzt_DW.Internal_DSTATE_pf[1]
      + (8.9256280204502634)*M2pzt_DW.Internal_DSTATE_pf[2];
  }

  /* DiscreteStateSpace: '<S197>/Internal' */
  {
    rtb_Internal_bo = (-0.40853755149358228)*M2pzt_DW.Internal_DSTATE_o1[0]
      + (0.40853755149358228)*M2pzt_DW.Internal_DSTATE_o1[1];
    rtb_Internal_bo += 1.0*rtb_Internal_nw;
  }

  /* DiscreteStateSpace: '<S200>/Internal' */
  {
    rtb_Internal_o = 1.0*rtb_Internal_bo;
  }

  /* DiscreteStateSpace: '<S203>/Internal' */
  {
    rtb_Internal_bf = 1.0*rtb_Internal_o;
  }

  /* DiscreteStateSpace: '<S249>/Internal' */
  {
    rtb_Internal_eu = (9.3563552113359361)*M2pzt_DW.Internal_DSTATE_gw[0]
      + (18.271835534636281)*M2pzt_DW.Internal_DSTATE_gw[1]
      + (8.9256280204502634)*M2pzt_DW.Internal_DSTATE_gw[2];
  }

  /* DiscreteStateSpace: '<S255>/Internal' */
  {
    rtb_Internal_jg = (-0.40853755149358228)*M2pzt_DW.Internal_DSTATE_cu[0]
      + (0.40853755149358228)*M2pzt_DW.Internal_DSTATE_cu[1];
    rtb_Internal_jg += 1.0*rtb_Internal_eu;
  }

  /* DiscreteStateSpace: '<S258>/Internal' */
  {
    rtb_Internal_m1 = 1.0*rtb_Internal_jg;
  }

  /* DiscreteStateSpace: '<S261>/Internal' */
  {
    rtb_Internal_mp = 1.0*rtb_Internal_m1;
  }

  /* DiscreteStateSpace: '<S250>/Internal' */
  {
    rtb_Internal_b4 = (9.3563552113359361)*M2pzt_DW.Internal_DSTATE_o5[0]
      + (18.271835534636281)*M2pzt_DW.Internal_DSTATE_o5[1]
      + (8.9256280204502634)*M2pzt_DW.Internal_DSTATE_o5[2];
  }

  /* DiscreteStateSpace: '<S256>/Internal' */
  {
    rtb_Internal_gf = (-0.40853755149358228)*M2pzt_DW.Internal_DSTATE_fj[0]
      + (0.40853755149358228)*M2pzt_DW.Internal_DSTATE_fj[1];
    rtb_Internal_gf += 1.0*rtb_Internal_b4;
  }

  /* DiscreteStateSpace: '<S259>/Internal' */
  {
    rtb_Internal_dq = 1.0*rtb_Internal_gf;
  }

  /* DiscreteStateSpace: '<S262>/Internal' */
  {
    rtb_Internal_as = 1.0*rtb_Internal_dq;
  }

  /* DiscreteStateSpace: '<S251>/Internal' */
  {
    rtb_Internal_dy = (9.3563552113359361)*M2pzt_DW.Internal_DSTATE_id[0]
      + (18.271835534636281)*M2pzt_DW.Internal_DSTATE_id[1]
      + (8.9256280204502634)*M2pzt_DW.Internal_DSTATE_id[2];
  }

  /* DiscreteStateSpace: '<S257>/Internal' */
  {
    rtb_Internal_nr = (-0.40853755149358228)*M2pzt_DW.Internal_DSTATE_c4r[0]
      + (0.40853755149358228)*M2pzt_DW.Internal_DSTATE_c4r[1];
    rtb_Internal_nr += 1.0*rtb_Internal_dy;
  }

  /* DiscreteStateSpace: '<S260>/Internal' */
  {
    rtb_Internal_lu = 1.0*rtb_Internal_nr;
  }

  /* DiscreteStateSpace: '<S263>/Internal' */
  {
    rtb_Internal_o1 = 1.0*rtb_Internal_lu;
  }

  /* DiscreteStateSpace: '<S309>/Internal' */
  {
    rtb_Internal_b4t = (9.3563552113359361)*M2pzt_DW.Internal_DSTATE_n[0]
      + (18.271835534636281)*M2pzt_DW.Internal_DSTATE_n[1]
      + (8.9256280204502634)*M2pzt_DW.Internal_DSTATE_n[2];
  }

  /* DiscreteStateSpace: '<S315>/Internal' */
  {
    rtb_Internal_et = (-0.40853755149358228)*M2pzt_DW.Internal_DSTATE_dn[0]
      + (0.40853755149358228)*M2pzt_DW.Internal_DSTATE_dn[1];
    rtb_Internal_et += 1.0*rtb_Internal_b4t;
  }

  /* DiscreteStateSpace: '<S318>/Internal' */
  {
    rtb_Internal_am = 1.0*rtb_Internal_et;
  }

  /* DiscreteStateSpace: '<S321>/Internal' */
  {
    rtb_Internal_ag = 1.0*rtb_Internal_am;
  }

  /* DiscreteStateSpace: '<S310>/Internal' */
  {
    rtb_Internal_o3 = (9.3563552113359361)*M2pzt_DW.Internal_DSTATE_mln[0]
      + (18.271835534636281)*M2pzt_DW.Internal_DSTATE_mln[1]
      + (8.9256280204502634)*M2pzt_DW.Internal_DSTATE_mln[2];
  }

  /* DiscreteStateSpace: '<S316>/Internal' */
  {
    rtb_Internal_da = (-0.40853755149358228)*M2pzt_DW.Internal_DSTATE_pb[0]
      + (0.40853755149358228)*M2pzt_DW.Internal_DSTATE_pb[1];
    rtb_Internal_da += 1.0*rtb_Internal_o3;
  }

  /* DiscreteStateSpace: '<S319>/Internal' */
  {
    rtb_Internal_fe = 1.0*rtb_Internal_da;
  }

  /* DiscreteStateSpace: '<S322>/Internal' */
  {
    rtb_Internal_h4 = 1.0*rtb_Internal_fe;
  }

  /* DiscreteStateSpace: '<S311>/Internal' */
  {
    rtb_Internal_di = (9.3563552113359361)*M2pzt_DW.Internal_DSTATE_pl[0]
      + (18.271835534636281)*M2pzt_DW.Internal_DSTATE_pl[1]
      + (8.9256280204502634)*M2pzt_DW.Internal_DSTATE_pl[2];
  }

  /* DiscreteStateSpace: '<S317>/Internal' */
  {
    rtb_Internal_cq = (-0.40853755149358228)*M2pzt_DW.Internal_DSTATE_pd[0]
      + (0.40853755149358228)*M2pzt_DW.Internal_DSTATE_pd[1];
    rtb_Internal_cq += 1.0*rtb_Internal_di;
  }

  /* DiscreteStateSpace: '<S320>/Internal' */
  {
    rtb_Internal_lz = 1.0*rtb_Internal_cq;
  }

  /* DiscreteStateSpace: '<S323>/Internal' */
  {
    rtb_Internal_auu = 1.0*rtb_Internal_lz;
  }

  /* DiscreteStateSpace: '<S369>/Internal' */
  {
    rtb_Internal_ce = (10.692977384383928)*M2pzt_DW.Internal_DSTATE_is[0]
      + (20.882097753870056)*M2pzt_DW.Internal_DSTATE_is[1]
      + (10.200717737657198)*M2pzt_DW.Internal_DSTATE_is[2];
  }

  /* DiscreteStateSpace: '<S376>/Internal' */
  {
    rtb_Internal_hf = (-0.43572274192046034)*M2pzt_DW.Internal_DSTATE_j1[0]
      + (0.43572274192046012)*M2pzt_DW.Internal_DSTATE_j1[1];
    rtb_Internal_hf += 1.0*rtb_Internal_ce;
  }

  /* DiscreteStateSpace: '<S377>/Internal' */
  {
    rtb_Internal_dru = 1.0*rtb_Internal_hf;
  }

  /* DiscreteStateSpace: '<S379>/Internal' */
  {
    rtb_Internal_p2 = 1.0*rtb_Internal_dru;
  }

  /* DiscreteStateSpace: '<S370>/Internal' */
  {
    rtb_Internal_ml = (10.692977384383928)*M2pzt_DW.Internal_DSTATE_kk[0]
      + (20.882097753870056)*M2pzt_DW.Internal_DSTATE_kk[1]
      + (10.200717737657198)*M2pzt_DW.Internal_DSTATE_kk[2];
  }

  /* DiscreteStateSpace: '<S375>/Internal' */
  {
    rtb_Internal_cv = (-0.43572274192046034)*M2pzt_DW.Internal_DSTATE_pfw[0]
      + (0.43572274192046012)*M2pzt_DW.Internal_DSTATE_pfw[1];
    rtb_Internal_cv += 1.0*rtb_Internal_ml;
  }

  /* DiscreteStateSpace: '<S378>/Internal' */
  {
    rtb_Internal_m0 = 1.0*rtb_Internal_cv;
  }

  /* DiscreteStateSpace: '<S381>/Internal' */
  {
    rtb_Internal_c1 = 1.0*rtb_Internal_m0;
  }

  /* DiscreteStateSpace: '<S371>/Internal' */
  {
    rtb_Internal_oi = (10.692977384383928)*M2pzt_DW.Internal_DSTATE_fz[0]
      + (20.882097753870056)*M2pzt_DW.Internal_DSTATE_fz[1]
      + (10.200717737657198)*M2pzt_DW.Internal_DSTATE_fz[2];
  }

  /* DiscreteStateSpace: '<S380>/Internal' */
  {
    rtb_Internal_b5 = (-0.43572274192046034)*M2pzt_DW.Internal_DSTATE_bh[0]
      + (0.43572274192046012)*M2pzt_DW.Internal_DSTATE_bh[1];
    rtb_Internal_b5 += 1.0*rtb_Internal_oi;
  }

  /* DiscreteStateSpace: '<S382>/Internal' */
  {
    rtb_Internal_bl = 1.0*rtb_Internal_b5;
  }

  /* DiscreteStateSpace: '<S383>/Internal' */
  {
    rtb_Internal_js = 1.0*rtb_Internal_bl;
  }

  /* Update for DiscreteStateSpace: '<S12>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (0.2621)*M2pzt_DW.Internal_DSTATE[0] + (-0.16376)*
      M2pzt_DW.Internal_DSTATE[1];
    xnew[0] += 4.0*rtb_Internal_a;
    xnew[1] = (0.125)*M2pzt_DW.Internal_DSTATE[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S13>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (0.2621)*M2pzt_DW.Internal_DSTATE_d[0] + (-0.16376)*
      M2pzt_DW.Internal_DSTATE_d[1];
    xnew[0] += 4.0*rtb_Internal_f3;
    xnew[1] = (0.125)*M2pzt_DW.Internal_DSTATE_d[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_d[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S14>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (0.2621)*M2pzt_DW.Internal_DSTATE_o[0] + (-0.16376)*
      M2pzt_DW.Internal_DSTATE_o[1];
    xnew[0] += 4.0*rtb_Internal_c4;
    xnew[1] = (0.125)*M2pzt_DW.Internal_DSTATE_o[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_o[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S72>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (0.2621)*M2pzt_DW.Internal_DSTATE_a[0] + (-0.16376)*
      M2pzt_DW.Internal_DSTATE_a[1];
    xnew[0] += 4.0*rtb_Internal_h;
    xnew[1] = (0.125)*M2pzt_DW.Internal_DSTATE_a[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_a[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S73>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (0.2621)*M2pzt_DW.Internal_DSTATE_h[0] + (-0.16376)*
      M2pzt_DW.Internal_DSTATE_h[1];
    xnew[0] += 4.0*rtb_Internal_ko;
    xnew[1] = (0.125)*M2pzt_DW.Internal_DSTATE_h[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_h[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S74>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (0.2621)*M2pzt_DW.Internal_DSTATE_m[0] + (-0.16376)*
      M2pzt_DW.Internal_DSTATE_m[1];
    xnew[0] += 4.0*rtb_Internal_l;
    xnew[1] = (0.125)*M2pzt_DW.Internal_DSTATE_m[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_m[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S132>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (0.2621)*M2pzt_DW.Internal_DSTATE_e[0] + (-0.16376)*
      M2pzt_DW.Internal_DSTATE_e[1];
    xnew[0] += 4.0*rtb_Internal_e;
    xnew[1] = (0.125)*M2pzt_DW.Internal_DSTATE_e[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_e[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S133>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (0.2621)*M2pzt_DW.Internal_DSTATE_b[0] + (-0.16376)*
      M2pzt_DW.Internal_DSTATE_b[1];
    xnew[0] += 4.0*rtb_Internal_p3;
    xnew[1] = (0.125)*M2pzt_DW.Internal_DSTATE_b[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_b[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S134>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (0.2621)*M2pzt_DW.Internal_DSTATE_m5[0]
      + (-0.16376)*M2pzt_DW.Internal_DSTATE_m5[1];
    xnew[0] += 4.0*rtb_Internal_fj;
    xnew[1] = (0.125)*M2pzt_DW.Internal_DSTATE_m5[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_m5[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S192>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (0.2621)*M2pzt_DW.Internal_DSTATE_k[0] + (-0.16376)*
      M2pzt_DW.Internal_DSTATE_k[1];
    xnew[0] += 4.0*rtb_Internal_e1;
    xnew[1] = (0.125)*M2pzt_DW.Internal_DSTATE_k[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_k[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S193>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (0.2621)*M2pzt_DW.Internal_DSTATE_f[0] + (-0.16376)*
      M2pzt_DW.Internal_DSTATE_f[1];
    xnew[0] += 4.0*rtb_Internal_dk;
    xnew[1] = (0.125)*M2pzt_DW.Internal_DSTATE_f[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_f[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S194>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (0.2621)*M2pzt_DW.Internal_DSTATE_c[0] + (-0.16376)*
      M2pzt_DW.Internal_DSTATE_c[1];
    xnew[0] += 4.0*rtb_Internal_bf;
    xnew[1] = (0.125)*M2pzt_DW.Internal_DSTATE_c[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_c[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S252>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (0.2621)*M2pzt_DW.Internal_DSTATE_cp[0]
      + (-0.16376)*M2pzt_DW.Internal_DSTATE_cp[1];
    xnew[0] += 4.0*rtb_Internal_mp;
    xnew[1] = (0.125)*M2pzt_DW.Internal_DSTATE_cp[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_cp[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S253>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (0.2621)*M2pzt_DW.Internal_DSTATE_bl[0]
      + (-0.16376)*M2pzt_DW.Internal_DSTATE_bl[1];
    xnew[0] += 4.0*rtb_Internal_as;
    xnew[1] = (0.125)*M2pzt_DW.Internal_DSTATE_bl[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_bl[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S254>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (0.2621)*M2pzt_DW.Internal_DSTATE_hn[0]
      + (-0.16376)*M2pzt_DW.Internal_DSTATE_hn[1];
    xnew[0] += 4.0*rtb_Internal_o1;
    xnew[1] = (0.125)*M2pzt_DW.Internal_DSTATE_hn[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_hn[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S312>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (0.2621)*M2pzt_DW.Internal_DSTATE_es[0]
      + (-0.16376)*M2pzt_DW.Internal_DSTATE_es[1];
    xnew[0] += 4.0*rtb_Internal_ag;
    xnew[1] = (0.125)*M2pzt_DW.Internal_DSTATE_es[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_es[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S313>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (0.2621)*M2pzt_DW.Internal_DSTATE_k1[0]
      + (-0.16376)*M2pzt_DW.Internal_DSTATE_k1[1];
    xnew[0] += 4.0*rtb_Internal_h4;
    xnew[1] = (0.125)*M2pzt_DW.Internal_DSTATE_k1[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_k1[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S314>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (0.2621)*M2pzt_DW.Internal_DSTATE_g[0] + (-0.16376)*
      M2pzt_DW.Internal_DSTATE_g[1];
    xnew[0] += 4.0*rtb_Internal_auu;
    xnew[1] = (0.125)*M2pzt_DW.Internal_DSTATE_g[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_g[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S372>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (0.2621)*M2pzt_DW.Internal_DSTATE_ai[0]
      + (-0.16376)*M2pzt_DW.Internal_DSTATE_ai[1];
    xnew[0] += 4.0*rtb_Internal_c1;
    xnew[1] = (0.125)*M2pzt_DW.Internal_DSTATE_ai[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_ai[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S373>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (0.2621)*M2pzt_DW.Internal_DSTATE_p[0] + (-0.16376)*
      M2pzt_DW.Internal_DSTATE_p[1];
    xnew[0] += 4.0*rtb_Internal_p2;
    xnew[1] = (0.125)*M2pzt_DW.Internal_DSTATE_p[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_p[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S374>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (0.2621)*M2pzt_DW.Internal_DSTATE_oj[0]
      + (-0.16376)*M2pzt_DW.Internal_DSTATE_oj[1];
    xnew[0] += 4.0*rtb_Internal_js;
    xnew[1] = (0.125)*M2pzt_DW.Internal_DSTATE_oj[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_oj[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S9>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (2.9015866073096861)*M2pzt_DW.Internal_DSTATE_j[0]
      + (-1.4058219239928555)*M2pzt_DW.Internal_DSTATE_j[1]
      + (0.91005724067602489)*M2pzt_DW.Internal_DSTATE_j[2];
    xnew[0] += 64.0*rtb_Sum[0];
    xnew[1] = (2.0)*M2pzt_DW.Internal_DSTATE_j[0];
    xnew[2] = (0.5)*M2pzt_DW.Internal_DSTATE_j[1];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_j[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S15>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (1.7334083541509879)*M2pzt_DW.Internal_DSTATE_ml[0]
      + (-0.7851326187966754)*M2pzt_DW.Internal_DSTATE_ml[1];
    xnew[0] += 0.5*rtb_Internal;
    xnew[1] = (1.0)*M2pzt_DW.Internal_DSTATE_ml[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_ml[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S10>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (2.9015866073096861)*M2pzt_DW.Internal_DSTATE_gx[0]
      + (-1.4058219239928555)*M2pzt_DW.Internal_DSTATE_gx[1]
      + (0.91005724067602489)*M2pzt_DW.Internal_DSTATE_gx[2];
    xnew[0] += 64.0*rtb_Sum[1];
    xnew[1] = (2.0)*M2pzt_DW.Internal_DSTATE_gx[0];
    xnew[2] = (0.5)*M2pzt_DW.Internal_DSTATE_gx[1];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_gx[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S16>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (1.7334083541509879)*M2pzt_DW.Internal_DSTATE_jo[0]
      + (-0.7851326187966754)*M2pzt_DW.Internal_DSTATE_jo[1];
    xnew[0] += 0.5*rtb_Internal_m;
    xnew[1] = (1.0)*M2pzt_DW.Internal_DSTATE_jo[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_jo[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S11>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (2.9015866073096861)*M2pzt_DW.Internal_DSTATE_bl1[0]
      + (-1.4058219239928555)*M2pzt_DW.Internal_DSTATE_bl1[1]
      + (0.91005724067602489)*M2pzt_DW.Internal_DSTATE_bl1[2];
    xnew[0] += 64.0*rtb_Sum[2];
    xnew[1] = (2.0)*M2pzt_DW.Internal_DSTATE_bl1[0];
    xnew[2] = (0.5)*M2pzt_DW.Internal_DSTATE_bl1[1];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_bl1[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S17>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (1.7334083541509879)*M2pzt_DW.Internal_DSTATE_fq[0]
      + (-0.7851326187966754)*M2pzt_DW.Internal_DSTATE_fq[1];
    xnew[0] += 0.5*rtb_Internal_k;
    xnew[1] = (1.0)*M2pzt_DW.Internal_DSTATE_fq[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_fq[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S69>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (2.9015866073096861)*M2pzt_DW.Internal_DSTATE_fr[0]
      + (-1.4058219239928555)*M2pzt_DW.Internal_DSTATE_fr[1]
      + (0.91005724067602489)*M2pzt_DW.Internal_DSTATE_fr[2];
    xnew[0] += 64.0*rtb_Sum_g[0];
    xnew[1] = (2.0)*M2pzt_DW.Internal_DSTATE_fr[0];
    xnew[2] = (0.5)*M2pzt_DW.Internal_DSTATE_fr[1];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_fr[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S75>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (1.7334083541509879)*M2pzt_DW.Internal_DSTATE_l[0]
      + (-0.7851326187966754)*M2pzt_DW.Internal_DSTATE_l[1];
    xnew[0] += 0.5*rtb_Internal_b;
    xnew[1] = (1.0)*M2pzt_DW.Internal_DSTATE_l[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_l[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S70>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (2.9015866073096861)*M2pzt_DW.Internal_DSTATE_gi[0]
      + (-1.4058219239928555)*M2pzt_DW.Internal_DSTATE_gi[1]
      + (0.91005724067602489)*M2pzt_DW.Internal_DSTATE_gi[2];
    xnew[0] += 64.0*rtb_Sum_g[1];
    xnew[1] = (2.0)*M2pzt_DW.Internal_DSTATE_gi[0];
    xnew[2] = (0.5)*M2pzt_DW.Internal_DSTATE_gi[1];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_gi[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S76>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (1.7334083541509879)*M2pzt_DW.Internal_DSTATE_i[0]
      + (-0.7851326187966754)*M2pzt_DW.Internal_DSTATE_i[1];
    xnew[0] += 0.5*rtb_Internal_bq;
    xnew[1] = (1.0)*M2pzt_DW.Internal_DSTATE_i[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_i[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S71>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (2.9015866073096861)*M2pzt_DW.Internal_DSTATE_or[0]
      + (-1.4058219239928555)*M2pzt_DW.Internal_DSTATE_or[1]
      + (0.91005724067602489)*M2pzt_DW.Internal_DSTATE_or[2];
    xnew[0] += 64.0*rtb_Sum_g[2];
    xnew[1] = (2.0)*M2pzt_DW.Internal_DSTATE_or[0];
    xnew[2] = (0.5)*M2pzt_DW.Internal_DSTATE_or[1];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_or[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S77>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (1.7334083541509879)*M2pzt_DW.Internal_DSTATE_ku[0]
      + (-0.7851326187966754)*M2pzt_DW.Internal_DSTATE_ku[1];
    xnew[0] += 0.5*rtb_Internal_g;
    xnew[1] = (1.0)*M2pzt_DW.Internal_DSTATE_ku[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_ku[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S129>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (2.9015866073096861)*M2pzt_DW.Internal_DSTATE_ke[0]
      + (-1.4058219239928555)*M2pzt_DW.Internal_DSTATE_ke[1]
      + (0.91005724067602489)*M2pzt_DW.Internal_DSTATE_ke[2];
    xnew[0] += 64.0*rtb_Sum_a[0];
    xnew[1] = (2.0)*M2pzt_DW.Internal_DSTATE_ke[0];
    xnew[2] = (0.5)*M2pzt_DW.Internal_DSTATE_ke[1];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_ke[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S135>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (1.7334083541509879)*M2pzt_DW.Internal_DSTATE_lj[0]
      + (-0.7851326187966754)*M2pzt_DW.Internal_DSTATE_lj[1];
    xnew[0] += 0.5*rtb_Internal_lr;
    xnew[1] = (1.0)*M2pzt_DW.Internal_DSTATE_lj[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_lj[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S130>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (2.9015866073096861)*M2pzt_DW.Internal_DSTATE_bo[0]
      + (-1.4058219239928555)*M2pzt_DW.Internal_DSTATE_bo[1]
      + (0.91005724067602489)*M2pzt_DW.Internal_DSTATE_bo[2];
    xnew[0] += 64.0*rtb_Sum_a[1];
    xnew[1] = (2.0)*M2pzt_DW.Internal_DSTATE_bo[0];
    xnew[2] = (0.5)*M2pzt_DW.Internal_DSTATE_bo[1];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_bo[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S136>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (1.7334083541509879)*M2pzt_DW.Internal_DSTATE_an[0]
      + (-0.7851326187966754)*M2pzt_DW.Internal_DSTATE_an[1];
    xnew[0] += 0.5*rtb_Internal_mt;
    xnew[1] = (1.0)*M2pzt_DW.Internal_DSTATE_an[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_an[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S131>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (2.9015866073096861)*M2pzt_DW.Internal_DSTATE_af[0]
      + (-1.4058219239928555)*M2pzt_DW.Internal_DSTATE_af[1]
      + (0.91005724067602489)*M2pzt_DW.Internal_DSTATE_af[2];
    xnew[0] += 64.0*rtb_Sum_a[2];
    xnew[1] = (2.0)*M2pzt_DW.Internal_DSTATE_af[0];
    xnew[2] = (0.5)*M2pzt_DW.Internal_DSTATE_af[1];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_af[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S137>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (1.7334083541509879)*M2pzt_DW.Internal_DSTATE_ph[0]
      + (-0.7851326187966754)*M2pzt_DW.Internal_DSTATE_ph[1];
    xnew[0] += 0.5*rtb_Internal_dr;
    xnew[1] = (1.0)*M2pzt_DW.Internal_DSTATE_ph[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_ph[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S189>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (2.9015866073096861)*M2pzt_DW.Internal_DSTATE_ec[0]
      + (-1.4058219239928555)*M2pzt_DW.Internal_DSTATE_ec[1]
      + (0.91005724067602489)*M2pzt_DW.Internal_DSTATE_ec[2];
    xnew[0] += 64.0*rtb_Sum_l[0];
    xnew[1] = (2.0)*M2pzt_DW.Internal_DSTATE_ec[0];
    xnew[2] = (0.5)*M2pzt_DW.Internal_DSTATE_ec[1];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_ec[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S195>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (1.7334083541509879)*M2pzt_DW.Internal_DSTATE_mg[0]
      + (-0.7851326187966754)*M2pzt_DW.Internal_DSTATE_mg[1];
    xnew[0] += 0.5*rtb_Internal_bx;
    xnew[1] = (1.0)*M2pzt_DW.Internal_DSTATE_mg[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_mg[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S190>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (2.9015866073096861)*M2pzt_DW.Internal_DSTATE_jx[0]
      + (-1.4058219239928555)*M2pzt_DW.Internal_DSTATE_jx[1]
      + (0.91005724067602489)*M2pzt_DW.Internal_DSTATE_jx[2];
    xnew[0] += 64.0*rtb_Sum_l[1];
    xnew[1] = (2.0)*M2pzt_DW.Internal_DSTATE_jx[0];
    xnew[2] = (0.5)*M2pzt_DW.Internal_DSTATE_jx[1];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_jx[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S196>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (1.7334083541509879)*M2pzt_DW.Internal_DSTATE_c4[0]
      + (-0.7851326187966754)*M2pzt_DW.Internal_DSTATE_c4[1];
    xnew[0] += 0.5*rtb_Internal_au;
    xnew[1] = (1.0)*M2pzt_DW.Internal_DSTATE_c4[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_c4[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S191>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (2.9015866073096861)*M2pzt_DW.Internal_DSTATE_pf[0]
      + (-1.4058219239928555)*M2pzt_DW.Internal_DSTATE_pf[1]
      + (0.91005724067602489)*M2pzt_DW.Internal_DSTATE_pf[2];
    xnew[0] += 64.0*rtb_Sum_l[2];
    xnew[1] = (2.0)*M2pzt_DW.Internal_DSTATE_pf[0];
    xnew[2] = (0.5)*M2pzt_DW.Internal_DSTATE_pf[1];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_pf[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S197>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (1.7334083541509879)*M2pzt_DW.Internal_DSTATE_o1[0]
      + (-0.7851326187966754)*M2pzt_DW.Internal_DSTATE_o1[1];
    xnew[0] += 0.5*rtb_Internal_nw;
    xnew[1] = (1.0)*M2pzt_DW.Internal_DSTATE_o1[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_o1[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S249>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (2.9015866073096861)*M2pzt_DW.Internal_DSTATE_gw[0]
      + (-1.4058219239928555)*M2pzt_DW.Internal_DSTATE_gw[1]
      + (0.91005724067602489)*M2pzt_DW.Internal_DSTATE_gw[2];
    xnew[0] += 64.0*rtb_Sum_m[0];
    xnew[1] = (2.0)*M2pzt_DW.Internal_DSTATE_gw[0];
    xnew[2] = (0.5)*M2pzt_DW.Internal_DSTATE_gw[1];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_gw[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S255>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (1.7334083541509879)*M2pzt_DW.Internal_DSTATE_cu[0]
      + (-0.7851326187966754)*M2pzt_DW.Internal_DSTATE_cu[1];
    xnew[0] += 0.5*rtb_Internal_eu;
    xnew[1] = (1.0)*M2pzt_DW.Internal_DSTATE_cu[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_cu[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S250>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (2.9015866073096861)*M2pzt_DW.Internal_DSTATE_o5[0]
      + (-1.4058219239928555)*M2pzt_DW.Internal_DSTATE_o5[1]
      + (0.91005724067602489)*M2pzt_DW.Internal_DSTATE_o5[2];
    xnew[0] += 64.0*rtb_Sum_m[1];
    xnew[1] = (2.0)*M2pzt_DW.Internal_DSTATE_o5[0];
    xnew[2] = (0.5)*M2pzt_DW.Internal_DSTATE_o5[1];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_o5[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S256>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (1.7334083541509879)*M2pzt_DW.Internal_DSTATE_fj[0]
      + (-0.7851326187966754)*M2pzt_DW.Internal_DSTATE_fj[1];
    xnew[0] += 0.5*rtb_Internal_b4;
    xnew[1] = (1.0)*M2pzt_DW.Internal_DSTATE_fj[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_fj[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S251>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (2.9015866073096861)*M2pzt_DW.Internal_DSTATE_id[0]
      + (-1.4058219239928555)*M2pzt_DW.Internal_DSTATE_id[1]
      + (0.91005724067602489)*M2pzt_DW.Internal_DSTATE_id[2];
    xnew[0] += 64.0*rtb_Sum_m[2];
    xnew[1] = (2.0)*M2pzt_DW.Internal_DSTATE_id[0];
    xnew[2] = (0.5)*M2pzt_DW.Internal_DSTATE_id[1];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_id[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S257>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (1.7334083541509879)*M2pzt_DW.Internal_DSTATE_c4r[0]
      + (-0.7851326187966754)*M2pzt_DW.Internal_DSTATE_c4r[1];
    xnew[0] += 0.5*rtb_Internal_dy;
    xnew[1] = (1.0)*M2pzt_DW.Internal_DSTATE_c4r[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_c4r[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S309>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (2.9015866073096861)*M2pzt_DW.Internal_DSTATE_n[0]
      + (-1.4058219239928555)*M2pzt_DW.Internal_DSTATE_n[1]
      + (0.91005724067602489)*M2pzt_DW.Internal_DSTATE_n[2];
    xnew[0] += 64.0*rtb_Sum_n[0];
    xnew[1] = (2.0)*M2pzt_DW.Internal_DSTATE_n[0];
    xnew[2] = (0.5)*M2pzt_DW.Internal_DSTATE_n[1];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_n[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S315>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (1.7334083541509879)*M2pzt_DW.Internal_DSTATE_dn[0]
      + (-0.7851326187966754)*M2pzt_DW.Internal_DSTATE_dn[1];
    xnew[0] += 0.5*rtb_Internal_b4t;
    xnew[1] = (1.0)*M2pzt_DW.Internal_DSTATE_dn[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_dn[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S310>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (2.9015866073096861)*M2pzt_DW.Internal_DSTATE_mln[0]
      + (-1.4058219239928555)*M2pzt_DW.Internal_DSTATE_mln[1]
      + (0.91005724067602489)*M2pzt_DW.Internal_DSTATE_mln[2];
    xnew[0] += 64.0*rtb_Sum_n[1];
    xnew[1] = (2.0)*M2pzt_DW.Internal_DSTATE_mln[0];
    xnew[2] = (0.5)*M2pzt_DW.Internal_DSTATE_mln[1];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_mln[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S316>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (1.7334083541509879)*M2pzt_DW.Internal_DSTATE_pb[0]
      + (-0.7851326187966754)*M2pzt_DW.Internal_DSTATE_pb[1];
    xnew[0] += 0.5*rtb_Internal_o3;
    xnew[1] = (1.0)*M2pzt_DW.Internal_DSTATE_pb[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_pb[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S311>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (2.9015866073096861)*M2pzt_DW.Internal_DSTATE_pl[0]
      + (-1.4058219239928555)*M2pzt_DW.Internal_DSTATE_pl[1]
      + (0.91005724067602489)*M2pzt_DW.Internal_DSTATE_pl[2];
    xnew[0] += 64.0*rtb_Sum_n[2];
    xnew[1] = (2.0)*M2pzt_DW.Internal_DSTATE_pl[0];
    xnew[2] = (0.5)*M2pzt_DW.Internal_DSTATE_pl[1];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_pl[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S317>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (1.7334083541509879)*M2pzt_DW.Internal_DSTATE_pd[0]
      + (-0.7851326187966754)*M2pzt_DW.Internal_DSTATE_pd[1];
    xnew[0] += 0.5*rtb_Internal_di;
    xnew[1] = (1.0)*M2pzt_DW.Internal_DSTATE_pd[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_pd[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S369>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (2.9015866073096861)*M2pzt_DW.Internal_DSTATE_is[0]
      + (-1.4058219239928555)*M2pzt_DW.Internal_DSTATE_is[1]
      + (0.91005724067602489)*M2pzt_DW.Internal_DSTATE_is[2];
    xnew[0] += 32.0*rtb_Sum_h[1];
    xnew[1] = (2.0)*M2pzt_DW.Internal_DSTATE_is[0];
    xnew[2] = (0.5)*M2pzt_DW.Internal_DSTATE_is[1];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_is[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S376>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (1.7109598108457003)*M2pzt_DW.Internal_DSTATE_j1[0]
      + (-0.77047182639207978)*M2pzt_DW.Internal_DSTATE_j1[1];
    xnew[0] += 0.5*rtb_Internal_ce;
    xnew[1] = (1.0)*M2pzt_DW.Internal_DSTATE_j1[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_j1[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S370>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (2.9015866073096861)*M2pzt_DW.Internal_DSTATE_kk[0]
      + (-1.4058219239928555)*M2pzt_DW.Internal_DSTATE_kk[1]
      + (0.91005724067602489)*M2pzt_DW.Internal_DSTATE_kk[2];
    xnew[0] += 32.0*rtb_Sum_h[0];
    xnew[1] = (2.0)*M2pzt_DW.Internal_DSTATE_kk[0];
    xnew[2] = (0.5)*M2pzt_DW.Internal_DSTATE_kk[1];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_kk[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S375>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (1.7109598108457003)*M2pzt_DW.Internal_DSTATE_pfw[0]
      + (-0.77047182639207978)*M2pzt_DW.Internal_DSTATE_pfw[1];
    xnew[0] += 0.5*rtb_Internal_ml;
    xnew[1] = (1.0)*M2pzt_DW.Internal_DSTATE_pfw[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_pfw[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S371>/Internal' */
  {
    real_T xnew[3];
    xnew[0] = (2.9015866073096861)*M2pzt_DW.Internal_DSTATE_fz[0]
      + (-1.4058219239928555)*M2pzt_DW.Internal_DSTATE_fz[1]
      + (0.91005724067602489)*M2pzt_DW.Internal_DSTATE_fz[2];
    xnew[0] += 32.0*rtb_Sum_h[2];
    xnew[1] = (2.0)*M2pzt_DW.Internal_DSTATE_fz[0];
    xnew[2] = (0.5)*M2pzt_DW.Internal_DSTATE_fz[1];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_fz[0], xnew,
                  sizeof(real_T)*3);
  }

  /* Update for DiscreteStateSpace: '<S380>/Internal' */
  {
    real_T xnew[2];
    xnew[0] = (1.7109598108457003)*M2pzt_DW.Internal_DSTATE_bh[0]
      + (-0.77047182639207978)*M2pzt_DW.Internal_DSTATE_bh[1];
    xnew[0] += 0.5*rtb_Internal_oi;
    xnew[1] = (1.0)*M2pzt_DW.Internal_DSTATE_bh[0];
    (void) memcpy(&M2pzt_DW.Internal_DSTATE_bh[0], xnew,
                  sizeof(real_T)*2);
  }
}

/* Model initialize function */
void M2pzt_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(M2pzt_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&M2pzt_DW, 0,
                sizeof(DW_M2pzt_T));

  /* external inputs */
  (void)memset((void *)&M2pzt_U, 0, sizeof(ExtU_M2pzt_T));

  /* external outputs */
  (void) memset(&M2pzt_Y.Output[0], 0,
                42U*sizeof(real_T));
}

/* Model terminate function */
void M2pzt_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
