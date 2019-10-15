/*
 * File: AcOsh0.h
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

#ifndef RTW_HEADER_AcOsh0_h_
#define RTW_HEADER_AcOsh0_h_
#include <string.h>
#include <stddef.h>
#ifndef AcOsh0_COMMON_INCLUDES_
# define AcOsh0_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* AcOsh0_COMMON_INCLUDES_ */

#include "AcOsh0_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T IntegralControl_states[42];   /* '<S1>/Integral Control' */
} DW_AcOsh0_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Reference[42];                /* '<Root>/Reference' */
  real_T Feedback[42];                 /* '<Root>/Feedback' */
} ExtU_AcOsh0_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Output[42];                   /* '<Root>/Output' */
} ExtY_AcOsh0_T;

/* Real-time Model Data Structure */
struct tag_RTM_AcOsh0_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_AcOsh0_T AcOsh0_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_AcOsh0_T AcOsh0_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_AcOsh0_T AcOsh0_Y;

/* Model entry point functions */
extern void AcOsh0_initialize(void);
extern void AcOsh0_step(void);
extern void AcOsh0_terminate(void);

/* Real-time Model object */
extern RT_MODEL_AcOsh0_T *const AcOsh0_M;

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
 * hilite_system('acoshCoder/AcOsh')    - opens subsystem acoshCoder/AcOsh
 * hilite_system('acoshCoder/AcOsh/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'acoshCoder'
 * '<S1>'   : 'acoshCoder/AcOsh'
 */
#endif                                 /* RTW_HEADER_AcOsh0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
