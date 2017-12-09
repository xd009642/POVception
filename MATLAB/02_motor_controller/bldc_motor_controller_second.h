/*
 * File: bldc_motor_controller_second.h
 *
 * Code generated for Simulink model 'bldc_motor_controller_second'.
 *
 * Model version                  : 1.59
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sat Dec 09 16:29:33 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_bldc_motor_controller_second_h_
#define RTW_HEADER_bldc_motor_controller_second_h_
#include <string.h>
#include <stddef.h>
#ifndef bldc_motor_controller_second_COMMON_INCLUDES_
# define bldc_motor_controller_second_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* bldc_motor_controller_second_COMMON_INCLUDES_ */

#include "bldc_motor_controller_second_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T X;                            /* '<Root>/X' */
  real_T X_l;                          /* '<S1>/X' */
  uint8_T is_active_c3_bldc_motor_control;/* '<Root>/Motor Controller' */
  uint8_T is_c3_bldc_motor_controller_sec;/* '<Root>/Motor Controller' */
} DW_bldc_motor_controller_seco_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T arm_motor_req;                /* '<Root>/arm_motor_req' */
  real_T halt_motor_req;               /* '<Root>/halt_motor_req' */
} ExtU_bldc_motor_controller_se_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T motor_pwm;                    /* '<Root>/motor_pwm' */
} ExtY_bldc_motor_controller_se_T;

/* Parameters (auto storage) */
struct P_bldc_motor_controller_secon_T_ {
  real_T Decrement_Value;              /* Expression: -1
                                        * Referenced by: '<S1>/Decrement'
                                        */
  real_T Increment_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Increment'
                                        */
  real_T load_var_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/load_var'
                                        */
  real_T X_InitialCondition;           /* Expression: 0
                                        * Referenced by: '<Root>/X'
                                        */
  real_T X_InitialCondition_l;         /* Expression: 0
                                        * Referenced by: '<S1>/X'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1070
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T PWMPeriodus_Value;            /* Expression: 20000
                                        * Referenced by: '<S3>/PWM Period us'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_bldc_motor_controller_T {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern P_bldc_motor_controller_secon_T bldc_motor_controller_second_P;

/* Block states (auto storage) */
extern DW_bldc_motor_controller_seco_T bldc_motor_controller_second_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_bldc_motor_controller_se_T bldc_motor_controller_second_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_bldc_motor_controller_se_T bldc_motor_controller_second_Y;

/* Model entry point functions */
extern void bldc_motor_controller_second_initialize(void);
extern void bldc_motor_controller_second_step(void);
extern void bldc_motor_controller_second_terminate(void);

/* Real-time Model object */
extern RT_MODEL_bldc_motor_controlle_T *const bldc_motor_controller_second_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/RelOpt' : Unused code path elimination
 * Block '<S1>/Terminal' : Unused code path elimination
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
 * '<Root>' : 'bldc_motor_controller_second'
 * '<S1>'   : 'bldc_motor_controller_second/Counter'
 * '<S2>'   : 'bldc_motor_controller_second/Motor Controller'
 * '<S3>'   : 'bldc_motor_controller_second/PWM Driver'
 */
#endif                                 /* RTW_HEADER_bldc_motor_controller_second_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
