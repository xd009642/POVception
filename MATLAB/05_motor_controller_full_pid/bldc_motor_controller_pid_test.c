/*
 * File: bldc_motor_controller_pid_test.c
 *
 * Code generated for Simulink model 'bldc_motor_controller_pid_test'.
 *
 * Model version                  : 1.616
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sun Dec 10 13:28:42 2017
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
#define IN_interrupt_trigger           ((uint8_T)4U)
#define IN_speed_calc_done             ((uint8_T)5U)
#define IN_trig_idle                   ((uint8_T)6U)

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
  real_T rtb_Switch_j;
  real_T rtb_Saturation;
  int32_T tmp;

  /* Chart: '<S1>/Motor Controller' incorporates:
   *  Inport: '<Root>/arm_motor_req'
   *  Inport: '<Root>/hall_effect_trig'
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
    rtDW.count_load = true;

    /* '<S3>:15:1' motor_state = 0; */
    rtDW.motor_state = 0U;
  } else {
    switch (rtDW.is_c3_bldc_motor_controller_pid) {
     case IN_arm_motor:
      rtDW.motor_state = 2U;

      /* During 'arm_motor': '<S3>:18' */
      /* '<S3>:17:1' sf_internal_predicateOutput = ... */
      /* '<S3>:17:1' hallEffectTrig; */
      if (rtU.hall_effect_trig) {
        /* Transition: '<S3>:17' */
        rtDW.is_c3_bldc_motor_controller_pid = IN_trig_idle;

        /* Entry 'trig_idle': '<S3>:1' */
        /* '<S3>:1:1' motor_state = 3; */
        rtDW.motor_state = 3U;

        /* '<S3>:1:1' count_load = false; */
        rtDW.count_load = false;
      }
      break;

     case IN_idle:
      rtDW.motor_state = 0U;
      rtDW.count_load = true;

      /* During 'idle': '<S3>:15' */
      /* '<S3>:19:1' sf_internal_predicateOutput = ... */
      /* '<S3>:19:1' arm_motor_req == 1; */
      if (rtU.arm_motor_req) {
        /* Transition: '<S3>:19' */
        rtDW.is_c3_bldc_motor_controller_pid = IN_arm_motor;

        /* Entry 'arm_motor': '<S3>:18' */
        /* '<S3>:18:1' motor_state = 2; */
        rtDW.motor_state = 2U;
      }
      break;

     case IN_halt_motor:
      rtDW.motor_state = 1U;

      /* During 'halt_motor': '<S3>:23' */
      /* '<S3>:26:1' sf_internal_predicateOutput = ... */
      /* '<S3>:26:1' halt_motor_req == 0 && count_in <= 1060; */
      if ((!rtU.halt_motor_req) && (rtDW.X_b <= 1060.0)) {
        /* Transition: '<S3>:26' */
        rtDW.is_c3_bldc_motor_controller_pid = IN_idle;

        /* Entry 'idle': '<S3>:15' */
        /* '<S3>:15:1' count_load = true; */
        rtDW.count_load = true;

        /* '<S3>:15:1' motor_state = 0; */
        rtDW.motor_state = 0U;
      }
      break;

     case IN_interrupt_trigger:
      /* During 'interrupt_trigger': '<S3>:5' */
      /* Transition: '<S3>:11' */
      rtDW.is_c3_bldc_motor_controller_pid = IN_speed_calc_done;

      /* Entry 'speed_calc_done': '<S3>:10' */
      /* '<S3>:10:1' count_load = true; */
      rtDW.count_load = true;
      break;

     case IN_speed_calc_done:
      /* During 'speed_calc_done': '<S3>:10' */
      /* Transition: '<S3>:7' */
      rtDW.is_c3_bldc_motor_controller_pid = IN_trig_idle;

      /* Entry 'trig_idle': '<S3>:1' */
      /* '<S3>:1:1' motor_state = 3; */
      rtDW.motor_state = 3U;

      /* '<S3>:1:1' count_load = false; */
      rtDW.count_load = false;
      break;

     default:
      rtDW.motor_state = 3U;
      rtDW.count_load = false;

      /* During 'trig_idle': '<S3>:1' */
      /* '<S3>:24:1' sf_internal_predicateOutput = ... */
      /* '<S3>:24:1' halt_motor_req == 1; */
      if (rtU.halt_motor_req) {
        /* Transition: '<S3>:24' */
        rtDW.is_c3_bldc_motor_controller_pid = IN_halt_motor;

        /* Entry 'halt_motor': '<S3>:23' */
        /* '<S3>:23:1' motor_state = 1; */
        rtDW.motor_state = 1U;
      } else {
        /* '<S3>:25:1' sf_internal_predicateOutput = ... */
        /* '<S3>:25:1' hallEffectTrig; */
        if (rtU.hall_effect_trig) {
          /* Transition: '<S3>:25' */
          rtDW.is_c3_bldc_motor_controller_pid = IN_interrupt_trigger;

          /* Outputs for Function Call SubSystem: '<S1>/Motor Count Condition' */
          /* Gain: '<S4>/Gearing Ratio' incorporates:
           *  Constant: '<S4>/rps to rpm'
           *  Constant: '<S7>/Increment'
           *  Gain: '<S4>/Clock Period'
           *  Product: '<S4>/Divide'
           *  Sum: '<S7>/Sum'
           *  UnitDelay: '<S7>/X'
           */
          /* Entry 'interrupt_trigger': '<S3>:5' */
          /* '<S3>:5:1' trigOut; */
          /* Event: '<S3>:9' */
          rtDW.GearingRatio = 60.0 / ((1.0 + rtDW.X_p) * 5.56E-9) *
            0.26666666666666666;

          /* End of Outputs for SubSystem: '<S1>/Motor Count Condition' */
        }
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Motor Controller' */

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Reference Speed (rpm)'
   *  Constant: '<S8>/Stop Speed (rpm)'
   */
  if (rtDW.motor_state > 1) {
    tmp = 800;
  } else {
    tmp = 0;
  }

  /* End of Switch: '<S8>/Switch' */

  /* Gain: '<S8>/Gearing Ratio' */
  rtb_GearingRatio = 0.26666666666666666 * (real_T)tmp;

  /* Gain: '<S9>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S9>/Filter'
   *  Gain: '<S9>/Derivative Gain'
   *  Sum: '<S9>/Sum3'
   *  Sum: '<S9>/SumD'
   */
  rtb_FilterCoefficient = ((rtb_GearingRatio - rtDW.GearingRatio) * 0.0 -
    rtDW.Filter_DSTATE) * 100.0;

  /* Sum: '<S8>/Add' incorporates:
   *  Constant: '<S8>/PWM Offset Factor'
   *  DiscreteIntegrator: '<S9>/Integrator'
   *  Gain: '<S8>/PWM Gain Factor'
   *  Sum: '<S9>/Sum'
   *  Sum: '<S9>/Sum1'
   */
  rtb_Switch_j = (((rtb_GearingRatio - rtDW.GearingRatio) +
                   rtDW.Integrator_DSTATE) + rtb_FilterCoefficient) * 0.1709 +
    1060.0;

  /* Saturate: '<S5>/Saturation' */
  if (rtb_Switch_j > 1860.0) {
    rtb_Saturation = 1860.0;
  } else if (rtb_Switch_j < 0.0) {
    rtb_Saturation = 0.0;
  } else {
    rtb_Saturation = rtb_Switch_j;
  }

  /* End of Saturate: '<S5>/Saturation' */

  /* Outport: '<Root>/outer_motor_pwm' incorporates:
   *  Constant: '<S2>/PWM Period us'
   *  Product: '<S2>/Divide'
   */
  rtY.outer_motor_pwm = rtb_Saturation / 20000.0;

  /* Outport: '<Root>/motor_speed_flag' incorporates:
   *  Constant: '<S5>/Terminal'
   *  RelationalOperator: '<S5>/RelOpt'
   */
  rtY.motor_speed_flag = (1093.0 <= rtb_Switch_j);

  /* Product: '<S6>/Divide' incorporates:
   *  Constant: '<S6>/Clock Period Const'
   */
  rtb_Switch_j = rtDW.GearingRatio / 5.56E-9;

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S7>/Increment'
   *  Sum: '<S7>/Sum'
   *  UnitDelay: '<S7>/X'
   */
  if (!(rtb_Switch_j != 0.0)) {
    rtb_Switch_j = 1.0 + rtDW.X_p;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Outport: '<Root>/ring_position_ratio' incorporates:
   *  Constant: '<S7>/Increment'
   *  Product: '<S6>/Divide1'
   *  Sum: '<S7>/Sum'
   *  UnitDelay: '<S7>/X'
   */
  rtY.ring_position_ratio = (real32_T)((1.0 + rtDW.X_p) / rtb_Switch_j);

  /* Update for UnitDelay: '<S1>/X' */
  rtDW.X_b = rtb_Saturation;

  /* Switch: '<S7>/Switch' */
  if (rtDW.count_load) {
    /* Update for UnitDelay: '<S7>/X' incorporates:
     *  Constant: '<S7>/Load'
     */
    rtDW.X_p = 0.0;
  } else {
    /* Update for UnitDelay: '<S7>/X' incorporates:
     *  Constant: '<S7>/Increment'
     *  Sum: '<S7>/Sum'
     *  UnitDelay: '<S7>/X'
     */
    rtDW.X_p++;
  }

  /* End of Switch: '<S7>/Switch' */

  /* Update for DiscreteIntegrator: '<S9>/Integrator' incorporates:
   *  Sum: '<S9>/Sum2'
   */
  rtDW.Integrator_DSTATE += rtb_GearingRatio - rtDW.GearingRatio;

  /* Update for DiscreteIntegrator: '<S9>/Filter' */
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
