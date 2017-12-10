/*
 * File: bldc_motor_controller_full_count_data.c
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

#include "bldc_motor_controller_full_count.h"
#include "bldc_motor_controller_full_count_private.h"

/* Block parameters (auto storage) */
P_bldc_motor_controller_full__T bldc_motor_controller_full_co_P = {
  1860.0,                              /* Mask Parameter: HaltCompare_const
                                        * Referenced by: '<S12>/Constant'
                                        */
  1860.0,                              /* Mask Parameter: HaltCompare_const_k
                                        * Referenced by: '<S20>/Constant'
                                        */
  1U,                                  /* Mask Parameter: HaltCompare_const_g
                                        * Referenced by: '<S18>/Constant'
                                        */
  1U,                                  /* Mask Parameter: HaltCompare_const_n
                                        * Referenced by: '<S10>/Constant'
                                        */
  0U,                                  /* Mask Parameter: LoadCompare_const
                                        * Referenced by: '<S11>/Constant'
                                        */
  0U,                                  /* Mask Parameter: LoadCompare_const_i
                                        * Referenced by: '<S19>/Constant'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S9>/Increment'
                                        */
  -100.0,                              /* Expression: -100
                                        * Referenced by: '<S9>/Decrement'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Idle'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/load_var'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S17>/Increment'
                                        */
  -100.0,                              /* Expression: -100
                                        * Referenced by: '<S17>/Decrement'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Idle'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/load_var'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/X'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/X'
                                        */
  1250.0,                              /* Expression: 1250
                                        * Referenced by: '<S15>/Saturation'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<S15>/Saturation'
                                        */
  20000.0,                             /* Expression: 20000
                                        * Referenced by: '<S4>/PWM Period us'
                                        */
  1093.0,                              /* Expression: 1093
                                        * Referenced by: '<S15>/Terminal'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/X'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/X'
                                        */
  1100.0,                              /* Expression: 1100
                                        * Referenced by: '<S7>/Saturation'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<S7>/Saturation'
                                        */
  20000.0,                             /* Expression: 20000
                                        * Referenced by: '<S2>/PWM Period us'
                                        */
  1085.0,                              /* Expression: 1085
                                        * Referenced by: '<S7>/Terminal'
                                        */
  0,                                   /* Computed Parameter: X1_InitialCondition
                                        * Referenced by: '<S17>/X1'
                                        */
  0,                                   /* Computed Parameter: X1_InitialCondition_l
                                        * Referenced by: '<S9>/X1'
                                        */

  /* Start of '<S3>/Motor Controller' */
  {
    0.0                                /* Computed Parameter: count_out_Y0
                                        * Referenced by: '<S14>/count_out'
                                        */
  }
  ,

  /* End of '<S3>/Motor Controller' */

  /* Start of '<S1>/Motor Controller' */
  {
    0.0                                /* Computed Parameter: count_out_Y0
                                        * Referenced by: '<S6>/count_out'
                                        */
  }
  /* End of '<S1>/Motor Controller' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
