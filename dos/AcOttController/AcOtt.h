/*
 * File: AcOtt.h
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

#ifndef RTW_HEADER_AcOtt_h_
#define RTW_HEADER_AcOtt_h_
#include <string.h>
#include <stddef.h>
#ifndef AcOtt_COMMON_INCLUDES_
# define AcOtt_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* AcOtt_COMMON_INCLUDES_ */

#include "AcOtt_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay1_DSTATE[315];           /* '<S2>/Delay1' */
  real_T TTOpticalController_states[21];/* '<S2>/TTOpticalController' */
} DW_AcOtt_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: PCEO.DGNF_LOS'
   * Referenced by: '<S1>/PsuedoCEO LOS1'
   */
  real_T PsuedoCEOLOS1_Gain[1764];

  /* Expression: diag([1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0])
   * Referenced by: '<S2>/Remove Piston'
   */
  real_T RemovePiston_Gain[441];

  /* Expression: PCEO.Decouple
   * Referenced by: '<S2>/LOS2PTT'
   */
  real_T LOS2PTT_Gain[441];
} ConstP_AcOtt_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Feedback[84];                 /* '<Root>/Feedback' */
  real_T Reference[21];                /* '<Root>/Reference' */
} ExtU_AcOtt_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Output[21];                   /* '<Root>/Output' */
} ExtY_AcOtt_T;

/* Real-time Model Data Structure */
struct tag_RTM_AcOtt_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_AcOtt_T AcOtt_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_AcOtt_T AcOtt_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_AcOtt_T AcOtt_Y;

/* Constant parameters (default storage) */
extern const ConstP_AcOtt_T AcOtt_ConstP;

/* Model entry point functions */
extern void AcOtt_initialize(void);
extern void AcOtt_step(void);
extern void AcOtt_terminate(void);

/* Real-time Model object */
extern RT_MODEL_AcOtt_T *const AcOtt_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Modify Gain' : Eliminated nontunable gain of 1
 * Block '<S2>/Switch Optical Feedback' : Eliminated due to constant selection input
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('AcOttCoder/AcOtt')    - opens subsystem AcOttCoder/AcOtt
 * hilite_system('AcOttCoder/AcOtt/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'AcOttCoder'
 * '<S1>'   : 'AcOttCoder/AcOtt'
 * '<S2>'   : 'AcOttCoder/AcOtt/PsuedoCEO M2 Control'
 */
#endif                                 /* RTW_HEADER_AcOtt_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
