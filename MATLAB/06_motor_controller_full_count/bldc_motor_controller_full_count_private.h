/*
 * File: bldc_motor_controller_full_count_private.h
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

#ifndef RTW_HEADER_bldc_motor_controller_full_count_private_h_
#define RTW_HEADER_bldc_motor_controller_full_count_private_h_
#include "rtwtypes.h"
#include "bldc_motor_controller_full_count.h"

extern void bldc_motor_MotorController_Init(real_T *rty_2,
  DW_MotorController_bldc_motor_T *localDW, P_MotorController_bldc_motor__T
  *localP);
extern void bldc_motor_cont_MotorController(real_T rtu_count_in, boolean_T
  rtu_hallEffectTrig, boolean_T rtu_arm_motor_req, boolean_T rtu_halt_motor_req,
  real_T rtu_4, uint8_T *rty_motor_state, boolean_T *rty_count_load, real_T
  *rty_2, DW_MotorController_bldc_motor_T *localDW);

#endif                                 /* RTW_HEADER_bldc_motor_controller_full_count_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
