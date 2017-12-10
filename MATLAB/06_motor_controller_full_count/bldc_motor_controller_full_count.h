/*
 * File: bldc_motor_controller_full_count.h
 *
 * Code generated for Simulink model 'bldc_motor_controller_full_count'.
 *
 * Model version                  : 1.65
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sun Dec 10 15:45:57 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_bldc_motor_controller_full_count_h_
#define RTW_HEADER_bldc_motor_controller_full_count_h_
#include <string.h>
#include <stddef.h>
#ifndef bldc_motor_controller_full_count_COMMON_INCLUDES_
# define bldc_motor_controller_full_count_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* bldc_motor_controller_full_count_COMMON_INCLUDES_ */

#include "bldc_motor_controller_full_count_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#define bldc_motor_controller_full_count_M (bldc_motor_controller_full_c_M)

/* Block signals (auto storage) */
typedef struct {
  real_T GearingRatio;                 /* '<S4>/Gearing Ratio' */
  uint8_T motor_state;                 /* '<S1>/Motor Controller' */
  boolean_T count_load;                /* '<S1>/Motor Controller' */
} B_bldc_motor_controller_full__T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T X;                            /* '<S1>/X' */
  real_T X_d;                          /* '<S7>/X' */
  real_T X_m;                          /* '<S8>/X' */
  uint8_T is_active_c3_bldc_motor_control;/* '<S1>/Motor Controller' */
  uint8_T is_c3_bldc_motor_controller_ful;/* '<S1>/Motor Controller' */
} DW_bldc_motor_controller_full_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  boolean_T arm_motor_req;             /* '<Root>/arm_motor_req' */
  boolean_T halt_motor_req;            /* '<Root>/halt_motor_req' */
  boolean_T hall_effect_trig;          /* '<Root>/hall_effect_trig' */
} ExtU_bldc_motor_controller_fu_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T outer_motor_pwm;              /* '<Root>/outer_motor_pwm' */
  real32_T ring_position_ratio;        /* '<Root>/ring_position_ratio' */
  boolean_T motor_speed_flag;          /* '<Root>/motor_speed_flag' */
} ExtY_bldc_motor_controller_fu_T;

/* Parameters (auto storage) */
struct P_bldc_motor_controller_full__T_ {
  uint8_T HaltCompare_const;           /* Mask Parameter: HaltCompare_const
                                        * Referenced by: '<S9>/Constant'
                                        */
  uint8_T LoadCompare_const;           /* Mask Parameter: LoadCompare_const
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T motor_speed_err_Y0;           /* Computed Parameter: motor_speed_err_Y0
                                        * Referenced by: '<S4>/motor_speed_err'
                                        */
  real_T ClockPeriod_Gain;             /* Expression: 5.56*(10^-9)
                                        * Referenced by: '<S4>/Clock Period'
                                        */
  real_T rpstorpm_Value;               /* Expression: 60
                                        * Referenced by: '<S4>/rps to rpm'
                                        */
  real_T GearingRatio_Gain;            /* Expression: 16/60
                                        * Referenced by: '<S4>/Gearing Ratio'
                                        */
  real_T Decrement_Value;              /* Expression: -100
                                        * Referenced by: '<S8>/Decrement'
                                        */
  real_T Increment_Value;              /* Expression: 100
                                        * Referenced by: '<S8>/Increment'
                                        */
  real_T load_var_Value;               /* Expression: 0
                                        * Referenced by: '<S8>/load_var'
                                        */
  real_T Load_Value;                   /* Expression: 0
                                        * Referenced by: '<S7>/Load'
                                        */
  real_T X_InitialCondition;           /* Expression: 0
                                        * Referenced by: '<S1>/X'
                                        */
  real_T Increment_Value_p;            /* Expression: 1
                                        * Referenced by: '<S7>/Increment'
                                        */
  real_T X_InitialCondition_a;         /* Expression: 0
                                        * Referenced by: '<S7>/X'
                                        */
  real_T X_InitialCondition_d;         /* Expression: 0
                                        * Referenced by: '<S8>/X'
                                        */
  real_T PWMPeriodus_Value;            /* Expression: 20000
                                        * Referenced by: '<S2>/PWM Period us'
                                        */
  real_T ClockPeriodConst_Value;       /* Expression: 5.56*(10^-9)
                                        * Referenced by: '<S6>/Clock Period Const'
                                        */
  real_T Terminal_Value;               /* Expression: 1093
                                        * Referenced by: '<S5>/Terminal'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_bldc_motor_controller_T {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern P_bldc_motor_controller_full__T bldc_motor_controller_full_co_P;

/* Block signals (auto storage) */
extern B_bldc_motor_controller_full__T bldc_motor_controller_full_co_B;

/* Block states (auto storage) */
extern DW_bldc_motor_controller_full_T bldc_motor_controller_full_c_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_bldc_motor_controller_fu_T bldc_motor_controller_full_co_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_bldc_motor_controller_fu_T bldc_motor_controller_full_co_Y;

/* Model entry point functions */
extern void bldc_motor_controller_full_count_initialize(void);
extern void bldc_motor_controller_full_count_step(void);
extern void bldc_motor_controller_full_count_terminate(void);

/* Real-time Model object */
extern RT_MODEL_bldc_motor_controlle_T *const bldc_motor_controller_full_c_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/RelOpt' : Unused code path elimination
 * Block '<S8>/Terminal' : Unused code path elimination
 * Block '<S7>/RelOpt' : Unused code path elimination
 * Block '<S7>/Terminal' : Unused code path elimination
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
 * '<Root>' : 'bldc_motor_controller_full_count'
 * '<S1>'   : 'bldc_motor_controller_full_count/Outer Motor Controller'
 * '<S2>'   : 'bldc_motor_controller_full_count/PWM Driver'
 * '<S3>'   : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Controller'
 * '<S4>'   : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Count Condition'
 * '<S5>'   : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Drive'
 * '<S6>'   : 'bldc_motor_controller_full_count/Outer Motor Controller/Ring Position Calc'
 * '<S7>'   : 'bldc_motor_controller_full_count/Outer Motor Controller/Rotation Counter1'
 * '<S8>'   : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Drive/Counter'
 * '<S9>'   : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Drive/Halt Compare'
 * '<S10>'  : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Drive/Load Compare'
 */
#endif                                 /* RTW_HEADER_bldc_motor_controller_full_count_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
