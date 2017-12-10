/*
 * File: bldc_motor_controller_pid_test.c
 *
 * Code generated for Simulink model 'bldc_motor_controller_pid_test'.
 *
 * Model version                  : 1.631
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sun Dec 10 14:14:50 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "bldc_motor_controller_pid_test.h"

/* Named constants for Chart: '<S1>/Motor Controller' */
#define IN_arm_motor                   ((uint8_T)1U)
#define IN_halt_motor                  ((uint8_T)3U)
#define IN_idle                        ((uint8_T)2U)
#define IN_trig_idle                   ((uint8_T)4U)

/* Block signals and states (auto storage) */
DW rtDW;

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void bldc_motor_controller_pid_test_step(void)
{
  real_T rtb_GearingRatio;
  real_T rtb_FilterCoefficient;
  real_T rtb_Add;
  real_T rtb_Saturation;
  uint8_T rtb_motor_state;
  int32_T rtb_motor_state_0;

  /* Chart: '<S1>/Motor Controller' incorporates:
   *  Inport: '<Root>/arm_motor_req'
   *  Inport: '<Root>/halt_motor_req'
   *  UnitDelay: '<S1>/X'
   */
  /* Gateway: Outer Motor Controller/Motor Controller */
  /* During: Outer Motor Controller/Motor Controller */
  if (rtDW.is_active_c3_bldc_motor_control == 0U) {
    /* Entry: Outer Motor Controller/Motor Controller */
    rtDW.is_active_c3_bldc_motor_control = 1U;

    /* Entry Internal: Outer Motor Controller/Motor Controller */
    /* Transition: '<S3>:16' */
    rtDW.is_c3_bldc_motor_controller_pid = IN_idle;

    /* Entry 'idle': '<S3>:15' */
    /* '<S3>:15:1' count_load = true; */
    /* '<S3>:15:1' motor_state = 0; */
    rtb_motor_state = 0U;
  } else {
    switch (rtDW.is_c3_bldc_motor_controller_pid) {
     case IN_arm_motor:
      /* During 'arm_motor': '<S3>:18' */
      /* Transition: '<S3>:17' */
      rtDW.is_c3_bldc_motor_controller_pid = IN_trig_idle;

      /* Entry 'trig_idle': '<S3>:1' */
      /* '<S3>:1:1' motor_state = 3; */
      rtb_motor_state = 3U;

      /* '<S3>:1:1' count_load = false; */
      break;

     case IN_idle:
      rtb_motor_state = 0U;

      /* During 'idle': '<S3>:15' */
      /* '<S3>:19:1' sf_internal_predicateOutput = ... */
      /* '<S3>:19:1' arm_motor_req == true; */
      if (rtU.arm_motor_req) {
        /* Transition: '<S3>:19' */
        rtDW.is_c3_bldc_motor_controller_pid = IN_arm_motor;

        /* Entry 'arm_motor': '<S3>:18' */
        /* '<S3>:18:1' motor_state = 2; */
        rtb_motor_state = 2U;
      }
      break;

     case IN_halt_motor:
      rtb_motor_state = 1U;

      /* During 'halt_motor': '<S3>:23' */
      /* '<S3>:26:1' sf_internal_predicateOutput = ... */
      /* '<S3>:26:1' halt_motor_req == 0 && count_in <= 1060; */
      if ((!rtU.halt_motor_req) && (rtDW.X_b <= 1060.0)) {
        /* Transition: '<S3>:26' */
        rtDW.is_c3_bldc_motor_controller_pid = IN_idle;

        /* Entry 'idle': '<S3>:15' */
        /* '<S3>:15:1' count_load = true; */
        /* '<S3>:15:1' motor_state = 0; */
        rtb_motor_state = 0U;
      }
      break;

     default:
      rtb_motor_state = 3U;

      /* During 'trig_idle': '<S3>:1' */
      /* '<S3>:24:1' sf_internal_predicateOutput = ... */
      /* '<S3>:24:1' halt_motor_req == true; */
      if (rtU.halt_motor_req) {
        /* Transition: '<S3>:24' */
        rtDW.is_c3_bldc_motor_controller_pid = IN_halt_motor;

        /* Entry 'halt_motor': '<S3>:23' */
        /* '<S3>:23:1' motor_state = 1; */
        rtb_motor_state = 1U;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Motor Controller' */

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Reference Speed (rpm)'
   *  Constant: '<S5>/Stop Speed (rpm)'
   */
  if (rtb_motor_state > 1) {
    rtb_motor_state_0 = 800;
  } else {
    rtb_motor_state_0 = 0;
  }

  /* End of Switch: '<S5>/Switch' */

  /* Gain: '<S5>/Gearing Ratio' */
  rtb_GearingRatio = 0.26666666666666666 * (real_T)rtb_motor_state_0;

  /* Gain: '<S6>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S6>/Filter'
   *  Gain: '<S6>/Derivative Gain'
   *  Sum: '<S6>/Sum3'
   *  Sum: '<S6>/SumD'
   *  UnitDelay: '<S1>/X1'
   */
  rtb_FilterCoefficient = ((rtb_GearingRatio - rtDW.X_p) * 0.0 -
    rtDW.Filter_DSTATE) * 100.0;

  /* Sum: '<S5>/Add' incorporates:
   *  Constant: '<S5>/PWM Offset Factor'
   *  DiscreteIntegrator: '<S6>/Integrator'
   *  Gain: '<S5>/PWM Gain Factor'
   *  Sum: '<S6>/Sum'
   *  Sum: '<S6>/Sum1'
   *  UnitDelay: '<S1>/X1'
   */
  rtb_Add = (((rtb_GearingRatio - rtDW.X_p) + rtDW.Integrator_DSTATE) +
             rtb_FilterCoefficient) * 0.1709 + 1060.0;

  /* Saturate: '<S4>/Saturation' */
  if (rtb_Add > 1860.0) {
    rtb_Saturation = 1860.0;
  } else if (rtb_Add < 0.0) {
    rtb_Saturation = 0.0;
  } else {
    rtb_Saturation = rtb_Add;
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* Outport: '<Root>/outer_motor_pwm' incorporates:
   *  Constant: '<S2>/PWM Period us'
   *  Product: '<S2>/Divide'
   */
  rtY.outer_motor_pwm = rtb_Saturation / 20000.0;

  /* Outport: '<Root>/motor_speed_flag' incorporates:
   *  Constant: '<S4>/Terminal'
   *  RelationalOperator: '<S4>/RelOpt'
   */
  rtY.motor_speed_flag = (1093.0 <= rtb_Add);

  /* Sum: '<S6>/Sum2' incorporates:
   *  UnitDelay: '<S1>/X1'
   */
  rtb_GearingRatio -= rtDW.X_p;

  /* Update for UnitDelay: '<S1>/X' */
  rtDW.X_b = rtb_Saturation;

  /* Update for UnitDelay: '<S1>/X1' incorporates:
   *  Constant: '<S1>/PWM Gain Factor'
   *  Constant: '<S1>/PWM Offset Factor'
   *  Product: '<S1>/Divide2'
   *  Sum: '<S1>/Sum'
   */
  rtDW.X_p = (rtb_Saturation - 1060.0) / 0.1709;

  /* Update for DiscreteIntegrator: '<S6>/Integrator' */
  rtDW.Integrator_DSTATE += rtb_GearingRatio;

  /* Update for DiscreteIntegrator: '<S6>/Filter' */
  rtDW.Filter_DSTATE += rtb_FilterCoefficient;
}

/* Model initialize function */
void bldc_motor_controller_pid_test_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
