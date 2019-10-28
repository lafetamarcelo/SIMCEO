/*
 * File: M2pzt_data.c
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

/* Constant parameters (default storage) */
const ConstP_M2pzt_T M2pzt_ConstP = {
  /* Pooled Parameter (Expression: [-eye(3);eye(3)])
   * Referenced by:
   *   '<S2>/delta3'
   *   '<S3>/delta3'
   *   '<S4>/delta3'
   *   '<S5>/delta3'
   *   '<S6>/delta3'
   *   '<S7>/delta3'
   *   '<S8>/delta3'
   */
  { -1.0, -0.0, -0.0, 1.0, 0.0, 0.0, -0.0, -1.0, -0.0, 0.0, 1.0, 0.0, -0.0, -0.0,
    -1.0, 0.0, 0.0, 1.0 },

  /* Pooled Parameter (Expression: FSM(1).InCoordRM)
   * Referenced by:
   *   '<S2>/PTT2PZT'
   *   '<S3>/PTT2PZT'
   *   '<S4>/PTT2PZT'
   *   '<S5>/PTT2PZT'
   *   '<S6>/PTT2PZT'
   *   '<S7>/PTT2PZT'
   *   '<S8>/PTT2PZT'
   */
  { 1.0001940989694318, 1.0003320814364127, 1.0003696416576298,
    -0.31487453000750409, 0.1573788918719374, 0.15736608125511145,
    -2.047004139605562E-12, -0.27276493357389053, 0.27276493357286224 },

  /* Pooled Parameter (Expression: [-eye(3),eye(3)])
   * Referenced by:
   *   '<S2>/RelativeDisplace'
   *   '<S3>/RelativeDisplace'
   *   '<S4>/RelativeDisplace'
   *   '<S5>/RelativeDisplace'
   *   '<S6>/RelativeDisplace'
   *   '<S7>/RelativeDisplace'
   *   '<S8>/RelativeDisplace'
   */
  { -1.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -1.0, 1.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 1.0 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
