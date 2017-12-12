/*
 * File: bldc_motor_controller_full_count.h
 *
 * Code generated for Simulink model 'bldc_motor_controller_full_count'.
 *
 * Model version                  : 1.208
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Tue Dec 12 17:57:37 2017
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
  uint8_T is_active_c3_bldc_motor_control;/* '<S1>/Motor Controller' */
  uint8_T is_c3_bldc_motor_controller_ful;/* '<S1>/Motor Controller' */
} DW_MotorController_bldc_motor_T;

/* Block signals (auto storage) */
typedef struct {
  real_T count_in;                     /* '<S17>/count_in' */
  real_T count_in_i;                   /* '<S6>/count_in' */
  uint8_T motor_state;                 /* '<S3>/Motor Controller' */
  uint8_T motor_state_i;               /* '<S1>/Motor Controller' */
} B_bldc_motor_controller_full__T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T X;                            /* '<S20>/X1' */
  real_T X_i;                          /* '<S3>/X' */
  real_T X_f;                          /* '<S20>/X' */
  real_T X_d;                          /* '<S9>/X1' */
  real_T X_j;                          /* '<S1>/X' */
  real_T X_fo;                         /* '<S9>/X' */
  DW_MotorController_bldc_motor_T sf_MotorController;/* '<S3>/Motor Controller' */
  DW_MotorController_bldc_motor_T sf_MotorController_o;/* '<S1>/Motor Controller' */
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
  real_T FastCompare_const;            /* Mask Parameter: FastCompare_const
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T MaxPulseCompare_const;        /* Mask Parameter: MaxPulseCompare_const
                                        * Referenced by: '<S26>/Constant'
                                        */
  real_T FastCompare_const_c;          /* Mask Parameter: FastCompare_const_c
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T MaxPulseCompare_const_p;      /* Mask Parameter: MaxPulseCompare_const_p
                                        * Referenced by: '<S15>/Constant'
                                        */
  uint8_T HaltCompare_const;           /* Mask Parameter: HaltCompare_const
                                        * Referenced by: '<S21>/Constant'
                                        */
  uint8_T LoadCompare_const;           /* Mask Parameter: LoadCompare_const
                                        * Referenced by: '<S22>/Constant'
                                        */
  uint8_T HaltCompare_const_n;         /* Mask Parameter: HaltCompare_const_n
                                        * Referenced by: '<S10>/Constant'
                                        */
  uint8_T LoadCompare_const_n;         /* Mask Parameter: LoadCompare_const_n
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T FastIncrement_Value;          /* Expression: 10
                                        * Referenced by: '<S12>/Fast Increment'
                                        */
  real_T SlowIncrement_Value;          /* Expression: 0.1
                                        * Referenced by: '<S12>/Slow Increment'
                                        */
  real_T FastDecrement_Value;          /* Expression: -10
                                        * Referenced by: '<S12>/Fast Decrement'
                                        */
  real_T SlowDecrement_Value;          /* Expression: -0.1
                                        * Referenced by: '<S12>/Slow Decrement'
                                        */
  real_T load_var_Value;               /* Expression: 0
                                        * Referenced by: '<S9>/load_var'
                                        */
  real_T FastIncrement_Value_g;        /* Expression: 10
                                        * Referenced by: '<S23>/Fast Increment'
                                        */
  real_T SlowIncrement_Value_e;        /* Expression: 0.1
                                        * Referenced by: '<S23>/Slow Increment'
                                        */
  real_T FastDecrement_Value_m;        /* Expression: -10
                                        * Referenced by: '<S23>/Fast Decrement'
                                        */
  real_T SlowDecrement_Value_p;        /* Expression: -0.1
                                        * Referenced by: '<S23>/Slow Decrement'
                                        */
  real_T load_var_Value_b;             /* Expression: 0
                                        * Referenced by: '<S20>/load_var'
                                        */
  real_T Idle_Value;                   /* Expression: 0
                                        * Referenced by: '<S23>/Idle'
                                        */
  real_T X1_InitialCondition;          /* Expression: 0
                                        * Referenced by: '<S20>/X1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T X_InitialCondition;           /* Expression: 0
                                        * Referenced by: '<S3>/X'
                                        */
  real_T X_InitialCondition_e;         /* Expression: 0
                                        * Referenced by: '<S20>/X'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1250
                                        * Referenced by: '<S18>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -0.5
                                        * Referenced by: '<S18>/Saturation'
                                        */
  real_T PWMPeriodus_Value;            /* Expression: 20000
                                        * Referenced by: '<S4>/PWM Period us'
                                        */
  real_T Terminal_Value;               /* Expression: 1093
                                        * Referenced by: '<S18>/Terminal'
                                        */
  real_T Idle_Value_i;                 /* Expression: 0
                                        * Referenced by: '<S12>/Idle'
                                        */
  real_T X1_InitialCondition_l;        /* Expression: 0
                                        * Referenced by: '<S9>/X1'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T X_InitialCondition_ey;        /* Expression: 0
                                        * Referenced by: '<S1>/X'
                                        */
  real_T X_InitialCondition_m;         /* Expression: 0
                                        * Referenced by: '<S9>/X'
                                        */
  real_T Saturation_UpperSat_k;        /* Expression: 1200
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
  P_MotorController_bldc_motor__T sf_MotorController;/* '<S3>/Motor Controller' */
  P_MotorController_bldc_motor__T sf_MotorController_o;/* '<S1>/Motor Controller' */
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
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<S3>/Scope1' : Unused code path elimination
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
 * '<S12>'  : 'bldc_motor_controller_full_count/Inner Motor Controller/Motor Drive/Counter/Count Variation Calc'
 * '<S13>'  : 'bldc_motor_controller_full_count/Inner Motor Controller/Motor Drive/Counter/Count Variation Calc/Compare To Zero'
 * '<S14>'  : 'bldc_motor_controller_full_count/Inner Motor Controller/Motor Drive/Counter/Count Variation Calc/Fast Compare'
 * '<S15>'  : 'bldc_motor_controller_full_count/Inner Motor Controller/Motor Drive/Counter/Count Variation Calc/Max Pulse Compare'
 * '<S16>'  : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Controller'
 * '<S17>'  : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Count Condition'
 * '<S18>'  : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Drive'
 * '<S19>'  : 'bldc_motor_controller_full_count/Outer Motor Controller/Ring Position Calc'
 * '<S20>'  : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Drive/Counter'
 * '<S21>'  : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Drive/Halt Compare'
 * '<S22>'  : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Drive/Load Compare'
 * '<S23>'  : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Drive/Counter/Count Variation Calc'
 * '<S24>'  : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Drive/Counter/Count Variation Calc/Compare To Zero'
 * '<S25>'  : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Drive/Counter/Count Variation Calc/Fast Compare'
 * '<S26>'  : 'bldc_motor_controller_full_count/Outer Motor Controller/Motor Drive/Counter/Count Variation Calc/Max Pulse Compare'
 */
#endif                                 /* RTW_HEADER_bldc_motor_controller_full_count_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
