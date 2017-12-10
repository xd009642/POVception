/*
 * File: bldc_motor_controller_full_count_data.c
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

#include "bldc_motor_controller_full_count.h"
#include "bldc_motor_controller_full_count_private.h"

/* Block parameters (auto storage) */
P_bldc_motor_controller_full__T bldc_motor_controller_full_co_P = {
  3U,                                  /* Mask Parameter: HaltCompare_const
                                        * Referenced by: '<S9>/Constant'
                                        */
  0U,                                  /* Mask Parameter: LoadCompare_const
                                        * Referenced by: '<S10>/Constant'
                                        */
  0.0,                                 /* Computed Parameter: motor_speed_err_Y0
                                        * Referenced by: '<S4>/motor_speed_err'
                                        */
  5.56E-9,                             /* Expression: 5.56*(10^-9)
                                        * Referenced by: '<S4>/Clock Period'
                                        */
  60.0,                                /* Expression: 60
                                        * Referenced by: '<S4>/rps to rpm'
                                        */
  0.26666666666666666,                 /* Expression: 16/60
                                        * Referenced by: '<S4>/Gearing Ratio'
                                        */
  -100.0,                              /* Expression: -100
                                        * Referenced by: '<S8>/Decrement'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S8>/Increment'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/load_var'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Load'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/X'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Increment'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/X'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/X'
                                        */
  20000.0,                             /* Expression: 20000
                                        * Referenced by: '<S2>/PWM Period us'
                                        */
  5.56E-9,                             /* Expression: 5.56*(10^-9)
                                        * Referenced by: '<S6>/Clock Period Const'
                                        */
  1093.0                               /* Expression: 1093
                                        * Referenced by: '<S5>/Terminal'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
