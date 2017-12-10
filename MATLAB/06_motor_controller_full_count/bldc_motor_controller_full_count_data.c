/*
 * File: bldc_motor_controller_full_count_data.c
 *
 * Code generated for Simulink model 'bldc_motor_controller_full_count'.
 *
 * Model version                  : 1.106
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sun Dec 10 17:18:46 2017
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
  1860.0,                              /* Mask Parameter: HaltCompare_const
                                        * Referenced by: '<S10>/Constant'
                                        */
  1U,                                  /* Mask Parameter: HaltCompare_const_g
                                        * Referenced by: '<S8>/Constant'
                                        */
  0U,                                  /* Mask Parameter: LoadCompare_const
                                        * Referenced by: '<S9>/Constant'
                                        */
  0.0,                                 /* Computed Parameter: count_out_Y0
                                        * Referenced by: '<S4>/count_out'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S7>/Increment'
                                        */
  -100.0,                              /* Expression: -100
                                        * Referenced by: '<S7>/Decrement'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Idle'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/load_var'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/X'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/X'
                                        */
  1196.0,                              /* Expression: 1196
                                        * Referenced by: '<S5>/Saturation'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<S5>/Saturation'
                                        */
  20000.0,                             /* Expression: 20000
                                        * Referenced by: '<S2>/PWM Period us'
                                        */
  1093.0,                              /* Expression: 1093
                                        * Referenced by: '<S5>/Terminal'
                                        */
  0                                    /* Computed Parameter: X1_InitialCondition
                                        * Referenced by: '<S7>/X1'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
