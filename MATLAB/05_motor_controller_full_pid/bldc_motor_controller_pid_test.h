/*
 * File: bldc_motor_controller_pid_test.h
 *
 * Code generated for Simulink model 'bldc_motor_controller_pid_test'.
 *
 * Model version                  : 1.616
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sun Dec 10 13:28:42 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_bldc_motor_controller_pid_test_h_
#define RTW_HEADER_bldc_motor_controller_pid_test_h_
#include <stddef.h>
#ifndef bldc_motor_controller_pid_test_COMMON_INCLUDES_
# define bldc_motor_controller_pid_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* bldc_motor_controller_pid_test_COMMON_INCLUDES_ */

#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#define bldc_motor_controller_pid_test_M (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  real_T GearingRatio;                 /* '<S4>/Gearing Ratio' */
  real_T X_b;                          /* '<S1>/X' */
  real_T X_p;                          /* '<S7>/X' */
  real_T Integrator_DSTATE;            /* '<S9>/Integrator' */
  real_T Filter_DSTATE;                /* '<S9>/Filter' */
  uint8_T motor_state;                 /* '<S1>/Motor Controller' */
  uint8_T is_active_c3_bldc_motor_control;/* '<S1>/Motor Controller' */
  uint8_T is_c3_bldc_motor_controller_pid;/* '<S1>/Motor Controller' */
  boolean_T count_load;                /* '<S1>/Motor Controller' */
} DW;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  boolean_T arm_motor_req;             /* '<Root>/arm_motor_req' */
  boolean_T halt_motor_req;            /* '<Root>/halt_motor_req' */
  boolean_T hall_effect_trig;          /* '<Root>/hall_effect_trig' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T outer_motor_pwm;              /* '<Root>/outer_motor_pwm' */
  boolean_T motor_speed_flag;          /* '<Root>/motor_speed_flag' */
  real32_T ring_position_ratio;        /* '<Root>/ring_position_ratio' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
};

/* Block signals and states (auto storage) */
extern DW rtDW;

/* External inputs (root inport signals with auto storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void bldc_motor_controller_pid_test_initialize(void);
extern void bldc_motor_controller_pid_test_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/RelOpt' : Unused code path elimination
 * Block '<S7>/Terminal' : Unused code path elimination
 * Block '<S9>/Integral Gain' : Eliminated nontunable gain of 1
 * Block '<S9>/Proportional Gain' : Eliminated nontunable gain of 1
 * Block '<S9>/Setpoint Weighting (Derivative)' : Eliminated nontunable gain of 1
 * Block '<S9>/Setpoint Weighting (Proportional)' : Eliminated nontunable gain of 1
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'bldc_motor_controller_pid_test'
 * '<S1>'   : 'bldc_motor_controller_pid_test/Outer Motor Controller'
 * '<S2>'   : 'bldc_motor_controller_pid_test/PWM Driver'
 * '<S3>'   : 'bldc_motor_controller_pid_test/Outer Motor Controller/Motor Controller'
 * '<S4>'   : 'bldc_motor_controller_pid_test/Outer Motor Controller/Motor Count Condition'
 * '<S5>'   : 'bldc_motor_controller_pid_test/Outer Motor Controller/Motor PID Controlelr'
 * '<S6>'   : 'bldc_motor_controller_pid_test/Outer Motor Controller/Ring Position Calc'
 * '<S7>'   : 'bldc_motor_controller_pid_test/Outer Motor Controller/Rotation Counter1'
 * '<S8>'   : 'bldc_motor_controller_pid_test/Outer Motor Controller/Motor PID Controlelr/PID Controller'
 * '<S9>'   : 'bldc_motor_controller_pid_test/Outer Motor Controller/Motor PID Controlelr/PID Controller/Discrete PID Controller (2DOF)'
 */
#endif                                 /* RTW_HEADER_bldc_motor_controller_pid_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
