/*
 * File: bldc_motor_controller_full_count_data.c
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

#include "bldc_motor_controller_full_count.h"
#include "bldc_motor_controller_full_count_private.h"

/* Block parameters (auto storage) */
P_bldc_motor_controller_full__T bldc_motor_controller_full_co_P = {
  1000.0,                              /* Mask Parameter: FastCompare_const
                                        * Referenced by: '<S25>/Constant'
                                        */
  1860.0,                              /* Mask Parameter: MaxPulseCompare_const
                                        * Referenced by: '<S26>/Constant'
                                        */
  1000.0,                              /* Mask Parameter: FastCompare_const_c
                                        * Referenced by: '<S14>/Constant'
                                        */
  1860.0,                              /* Mask Parameter: MaxPulseCompare_const_p
                                        * Referenced by: '<S15>/Constant'
                                        */
  1U,                                  /* Mask Parameter: HaltCompare_const
                                        * Referenced by: '<S21>/Constant'
                                        */
  0U,                                  /* Mask Parameter: LoadCompare_const
                                        * Referenced by: '<S22>/Constant'
                                        */
  1U,                                  /* Mask Parameter: HaltCompare_const_n
                                        * Referenced by: '<S10>/Constant'
                                        */
  0U,                                  /* Mask Parameter: LoadCompare_const_n
                                        * Referenced by: '<S11>/Constant'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S12>/Fast Increment'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S12>/Slow Increment'
                                        */
  -10.0,                               /* Expression: -10
                                        * Referenced by: '<S12>/Fast Decrement'
                                        */
  -0.1,                                /* Expression: -0.1
                                        * Referenced by: '<S12>/Slow Decrement'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/load_var'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S23>/Fast Increment'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S23>/Slow Increment'
                                        */
  -10.0,                               /* Expression: -10
                                        * Referenced by: '<S23>/Fast Decrement'
                                        */
  -0.1,                                /* Expression: -0.1
                                        * Referenced by: '<S23>/Slow Decrement'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/load_var'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S23>/Idle'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/X1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S24>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/X'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/X'
                                        */
  1250.0,                              /* Expression: 1250
                                        * Referenced by: '<S18>/Saturation'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<S18>/Saturation'
                                        */
  20000.0,                             /* Expression: 20000
                                        * Referenced by: '<S4>/PWM Period us'
                                        */
  1093.0,                              /* Expression: 1093
                                        * Referenced by: '<S18>/Terminal'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Idle'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/X1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/X'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/X'
                                        */
  1200.0,                              /* Expression: 1200
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

  /* Start of '<S3>/Motor Controller' */
  {
    0.0                                /* Computed Parameter: count_out_Y0
                                        * Referenced by: '<S17>/count_out'
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
