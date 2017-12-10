/*
 * File: bldc_motor_controller_full_count.h
 *
 * Code generated for Simulink model 'bldc_motor_controller_full_count'.
 *
 * Model version                  : 1.115
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sun Dec 10 17:36:51 2017
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

/* Block states (auto storage) for system '<S1>/Motor Controller' */
typedef struct {
  uint8_T is_active_c1_bldc_motor_control;/* '<S1>/Motor Controller' */
  uint8_T is_c1_bldc_motor_controller_ful;/* '<S1>/Motor Controller' */
} DW_MotorController_bldc_motor_T;

/* Block signals (auto storage) */
typedef struct {
  real_T count_in;                     /* '<S14>/count_in' */
  real_T count_in_i;                   /* '<S6>/count_in' */
  uint8_T motor_state;                 /* '<S3>/Motor Controller' */
  uint8_T motor_state_m;               /* '<S1>/Motor Controller' */
} B_bldc_motor_controller_full__T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T X;                            /* '<S3>/X' */
  real_T X_m;                          /* '<S17>/X' */
  real_T X_j;                          /* '<S1>/X' */
  real_T X_e;                          /* '<S9>/X' */
  boolean_T X_n;                       /* '<S17>/X1' */
  boolean_T X_h;                       /* '<S9>/X1' */
  DW_MotorController_bldc_motor_T sf_MotorController;/* '<S3>/Motor Controller' */
  DW_MotorController_bldc_motor_T sf_MotorController_d;/* '<S1>/Motor Controller' */
} DW_bldc_motor_controller_full_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  boolean_T outer_hall_effect_trig;    /* '<Root>/outer_hall_effect_trig' */
  real_T outer_rotation_count_in;      /* '<Root>/outer_rotation_count_in' */
  boolean_T arm_motor_req;             /* '<Root>/arm_motor_req' */
  boolean_T halt_motor_req;            /* '<Root>/halt_motor_req' */
  boolean_T inner_hall_effect_trig;    /* '<Root>/inner_hall_effect_trig' */
  real_T inner_rotation_count_in;      /* '<Root>/inner_rotation_count_in' */
} ExtU_bldc_motor_controller_fu_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T outer_motor_pwm;              /* '<Root>/outer_motor_pwm' */
  real32_T outer_ring_position_ratio;  /* '<Root>/outer_ring_position_ratio' */
  boolean_T outer_motor_speed_flag;    /* '<Root>/outer_motor_speed_flag' */
  boolean_T outer_rot_count_load;      /* '<Root>/outer_rot_count_load' */
  real_T inner_motor_pwm;              /* '<Root>/inner_motor_pwm' */
  real32_T inner_ring_position_ratio;  /* '<Root>/inner_ring_position_ratio' */
  boolean_T inner_motor_speed_flag;    /* '<Root>/inner_motor_speed_flag' */
  boolean_T inner_rot_count_load;      /* '<Root>/inner_rot_count_load' */
} ExtY_bldc_motor_controller_fu_T;

/* Parameters for system: '<S1>/Motor Controller' */
struct P_MotorController_bldc_motor__T_ {
  real_T count_out_Y0;                 /* Computed Parameter: count_out_Y0
                                        * Referenced by: '<S6>/count_out'
                                        */
};

/* Parameters (auto storage) */
struct P_bldc_motor_controller_full__T_ {
  real_T HaltCompare_const;            /* Mask Parameter: HaltCompare_const
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T HaltCompare_const_k;          /* Mask Parameter: HaltCompare_const_k
                                        * Referenced by: '<S20>/Constant'
                                        */
  uint8_T HaltCompare_const_g;         /* Mask Parameter: HaltCompare_const_g
                                        * Referenced by: '<S18>/Constant'
                                        */
  uint8_T HaltCompare_const_n;         /* Mask Parameter: HaltCompare_const_n
                                        * Referenced by: '<S10>/Constant'
                                        */
  uint8_T LoadCompare_const;           /* Mask Parameter: LoadCompare_const
                                        * Referenced by: '<S11>/Constant'
                                        */
  uint8_T LoadCompare_const_i;         /* Mask Parameter: LoadCompare_const_i
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T Increment_Value;              /* Expression: 100
                                        * Referenced by: '<S9>/Increment'
                                        */
  real_T Decrement_Value;              /* Expression: -100
                                        * Referenced by: '<S9>/Decrement'
                                        */
  real_T Idle_Value;                   /* Expression: 0
                                        * Referenced by: '<S9>/Idle'
                                        */
  real_T load_var_Value;               /* Expression: 0
                                        * Referenced by: '<S9>/load_var'
                                        */
  real_T Increment_Value_e;            /* Expression: 100
                                        * Referenced by: '<S17>/Increment'
                                        */
  real_T Decrement_Value_m;            /* Expression: -100
                                        * Referenced by: '<S17>/Decrement'
                                        */
  real_T Idle_Value_h;                 /* Expression: 0
                                        * Referenced by: '<S17>/Idle'
                                        */
  real_T load_var_Value_d;             /* Expression: 0
                                        * Referenced by: '<S17>/load_var'
                                        */
  real_T X_InitialCondition;           /* Expression: 0
                                        * Referenced by: '<S3>/X'
                                        */
  real_T X_InitialCondition_d;         /* Expression: 0
                                        * Referenced by: '<S17>/X'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1250
                                        * Referenced by: '<S15>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -0.5
                                        * Referenced by: '<S15>/Saturation'
                                        */
  real_T PWMPeriodus_Value;            /* Expression: 20000
                                        * Referenced by: '<S4>/PWM Period us'
                                        */
  real_T Terminal_Value;               /* Expression: 1093
                                        * Referenced by: '<S15>/Terminal'
                                        */
  real_T X_InitialCondition_e;         /* Expression: 0
                                        * Referenced by: '<S1>/X'
                                        */
  real_T X_InitialCondition_c;         /* Expression: 0
                                        * Referenced by: '<S9>/X'
                                        */
  real_T Saturation_UpperSat_k;        /* Expression: 1100
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Saturation_LowerSat_f;        /* Expression: -0.5
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T PWMPeriodus_Value_j;          /* Expression: 20000
                                        * Referenced by: '<S2>/PWM Period us'
                                        */
  real_T Terminal_Value_f;             /* Expression: 1085
                                        * Referenced by: '<S7>/Terminal'
                                        */
  boolean_T X1_InitialCondition;       /* Computed Parameter: X1_InitialCondition
                                        * Referenced by: '<S17>/X1'
                                        */
  boolean_T X1_InitialCondition_l;     /* Computed Parameter: X1_InitialCondition_l
                                        * Referenced by: '<S9>/X1'
                                        */
  P_MotorController_bldc_motor__T sf_MotorController;/* '<S3>/Motor Controller' */
  P_MotorController_bldc_motor__T sf_MotorController_d;/* '<S1>/Motor Controller' */
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
 * '<S1>'   : 'bldc_motor_controller_full_count/Inner Motor Controller'
 * '<S2>'   : 'bldc_motor_controller_full_count/Inner PWM Driver'
 * '<S3>'   : 'bldc_motor_controller_full_count/Outer Motor Controller'
 * '<S4>'   : 'bldc_motor_controller_full_count/Outer PWM Driver'
 * '<S5>'   : 'bldc_motor_controller_full_count/Inner Motor Controller/Motor Controller'
 * '<S6>'   : 'bldc_motor_controller_full_count/Inner Motor Controller/Motor Count Condition'
 * '<S7>'   : 'bldc_motor_controller_full_count/Inner Motor Controller/Motor Drive'
 * '<S8>'   : 'bldc_motor_controller_full_count/Inner Motor Controller/Ring Position Calc'
 * '<S9>'   : 'bldc_motor_controller_full_count/Inner Motor Controller/Motor Drive/Counter'
 * '<S10>'  : 'bldc_motor_controller_full_count/Inner Motor Controller/Motor Drive/Halt Compare'
 * '<S11>'  : 'bldc_motor_controller_full_count/Inner Motor Controller/Motor Drive/Load Compare'
 * '<S12>'  : 'bldc_motor_controller_full_count/Inner Motor Controller/Motor Drive/Counter/Halt Compare'
 * '<S13>'  : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Controller'
 * '<S14>'  : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Count Condition'
 * '<S15>'  : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Drive'
 * '<S16>'  : 'bldc_motor_controller_full_count/Outer Motor Controller/Ring Position Calc'
 * '<S17>'  : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Drive/Counter'
 * '<S18>'  : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Drive/Halt Compare'
 * '<S19>'  : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Drive/Load Compare'
 * '<S20>'  : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Drive/Counter/Halt Compare'
 */
#endif                                 /* RTW_HEADER_bldc_motor_controller_full_count_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
