/*
 * File: motor_test.h
 *
 * Code generated for Simulink model 'motor_test'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sat Dec 09 15:02:08 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_motor_test_h_
#define RTW_HEADER_motor_test_h_
#include <stddef.h>
#include <string.h>
#ifndef motor_test_COMMON_INCLUDES_
# define motor_test_COMMON_INCLUDES_
#include "stdint.h"
#endif                                 /* motor_test_COMMON_INCLUDES_ */

#include "motor_test_types.h"
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
  float X;                            /* '<S1>/X' */
} DW_motor_test_t;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  float count_load;                   /* '<Root>/count_load' */
} ExtU_motor_test_t;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  float motor_pwm;                    /* '<Root>/motor_pwm' */
} ExtY_motor_test_t;

/* Parameters (auto storage) */
struct P_motor_test_t_ {
  float Load_Value;                   /* Expression: 0
                                        * Referenced by: '<S1>/Load'
                                        */
  float Increment_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Increment'
                                        */
  float X_InitialCondition;           /* Expression: 0
                                        * Referenced by: '<S1>/X'
                                        */
  float Saturation_UpperSat;          /* Expression: 1070
                                        * Referenced by: '<Root>/Saturation'
                                        */
  float Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  float PWMPeriodus_Value;            /* Expression: 20000
                                        * Referenced by: '<S2>/PWM Period us'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_motor_test_t {
  const char *errorStatus;
};

/* Block parameters (auto storage) */
extern P_motor_test_t motor_test_P;

/* Block states (auto storage) */
extern DW_motor_test_t motor_test_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_motor_test_t motor_test_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_motor_test_t motor_test_Y;

/* Model entry point functions */
extern void motor_test_initialize(void);
extern void motor_test_step(void);
extern void motor_test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_motor_test_t *const motor_test_M;

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
 * '<Root>' : 'motor_test'
 * '<S1>'   : 'motor_test/Counter'
 * '<S2>'   : 'motor_test/PWM Driver'
 */
#endif                                 /* RTW_HEADER_motor_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
