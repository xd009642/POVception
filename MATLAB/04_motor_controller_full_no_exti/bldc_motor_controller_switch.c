/*
 * File: bldc_motor_controller_switch.c
 *
 * Code generated for Simulink model 'bldc_motor_controller_switch'.
 *
 * Model version                  : 1.587
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sat Dec 09 22:33:48 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "bldc_motor_controller_switch.h"

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
void bldc_motor_controller_switch_step(void)
{
  real_T rtb_FilterCoefficient;
  real_T rtb_Add;
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
    /* Transition: '<S6>:16' */
    rtDW.is_c3_bldc_motor_controller_swi = IN_idle;

    /* Entry 'idle': '<S6>:15' */
    /* '<S6>:15:1' count_load = true; */
    rtDW.count_load = true;

    /* '<S6>:15:1' motor_state = 0; */
    rtDW.motor_state = 0U;
  } else {
    switch (rtDW.is_c3_bldc_motor_controller_swi) {
     case IN_arm_motor:
      rtDW.motor_state = 1U;

      /* During 'arm_motor': '<S6>:18' */
      /* '<S6>:17:1' sf_internal_predicateOutput = ... */
      /* '<S6>:17:1' hallEffectTrig; */
      if (rtU.hall_effect_trig) {
        /* Transition: '<S6>:17' */
        rtDW.is_c3_bldc_motor_controller_swi = IN_trig_idle;

        /* Entry 'trig_idle': '<S6>:1' */
        /* '<S6>:1:1' motor_state = 2; */
        rtDW.motor_state = 2U;

        /* '<S6>:1:1' count_load = false; */
        rtDW.count_load = false;
      }
      break;

     case IN_idle:
      rtDW.count_load = true;
      rtDW.motor_state = 0U;

      /* During 'idle': '<S6>:15' */
      /* '<S6>:19:1' sf_internal_predicateOutput = ... */
      /* '<S6>:19:1' arm_motor_req == 1; */
      if (rtU.arm_motor_req) {
        /* Transition: '<S6>:19' */
        rtDW.is_c3_bldc_motor_controller_swi = IN_arm_motor;

        /* Entry 'arm_motor': '<S6>:18' */
        /* '<S6>:18:1' motor_state = 1; */
        rtDW.motor_state = 1U;

        /* exit: motor_state = 2; */
      }
      break;

     case IN_halt_motor:
      rtDW.motor_state = 3U;

      /* During 'halt_motor': '<S6>:23' */
      /* '<S6>:26:1' sf_internal_predicateOutput = ... */
      /* '<S6>:26:1' halt_motor_req == 0 && count_in <= 1060; */
      if ((!rtU.halt_motor_req) && (rtDW.X_l <= 1060.0)) {
        /* Transition: '<S6>:26' */
        rtDW.is_c3_bldc_motor_controller_swi = IN_idle;

        /* Entry 'idle': '<S6>:15' */
        /* '<S6>:15:1' count_load = true; */
        rtDW.count_load = true;

        /* '<S6>:15:1' motor_state = 0; */
        rtDW.motor_state = 0U;
      }
      break;

     case IN_interrupt_trigger:
      /* During 'interrupt_trigger': '<S6>:5' */
      /* Transition: '<S6>:11' */
      rtDW.is_c3_bldc_motor_controller_swi = IN_speed_calc_done;

      /* Entry 'speed_calc_done': '<S6>:10' */
      /* '<S6>:10:1' count_load = true; */
      rtDW.count_load = true;
      break;

     case IN_speed_calc_done:
      /* During 'speed_calc_done': '<S6>:10' */
      /* Transition: '<S6>:7' */
      rtDW.is_c3_bldc_motor_controller_swi = IN_trig_idle;

      /* Entry 'trig_idle': '<S6>:1' */
      /* '<S6>:1:1' motor_state = 2; */
      rtDW.motor_state = 2U;

      /* '<S6>:1:1' count_load = false; */
      rtDW.count_load = false;
      break;

     default:
      rtDW.count_load = false;
      rtDW.motor_state = 2U;

      /* During 'trig_idle': '<S6>:1' */
      /* '<S6>:24:1' sf_internal_predicateOutput = ... */
      /* '<S6>:24:1' halt_motor_req == 1; */
      if (rtU.halt_motor_req) {
        /* Transition: '<S6>:24' */
        rtDW.is_c3_bldc_motor_controller_swi = IN_halt_motor;

        /* Entry 'halt_motor': '<S6>:23' */
        /* '<S6>:23:1' motor_state = 3; */
        rtDW.motor_state = 3U;
      } else {
        /* '<S6>:25:1' sf_internal_predicateOutput = ... */
        /* '<S6>:25:1' hallEffectTrig; */
        if (rtU.hall_effect_trig) {
          /* Transition: '<S6>:25' */
          rtDW.is_c3_bldc_motor_controller_swi = IN_interrupt_trigger;

          /* Outputs for Function Call SubSystem: '<S1>/Motor Count Condition' */
          /* Gain: '<S7>/Gearing Ratio' incorporates:
           *  Constant: '<S11>/Increment'
           *  Constant: '<S7>/rps to rpm'
           *  Gain: '<S7>/Clock Period'
           *  Product: '<S7>/Divide'
           *  Sum: '<S11>/Sum'
           *  UnitDelay: '<S11>/X'
           */
          /* Entry 'interrupt_trigger': '<S6>:5' */
          /* '<S6>:5:1' trigOut; */
          /* Event: '<S6>:9' */
          rtDW.GearingRatio = 60.0 / ((1.0 + rtDW.X_p) * 5.56E-9) *
            0.26666666666666666;

          /* End of Outputs for SubSystem: '<S1>/Motor Count Condition' */
        }
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Motor Controller' */

  /* If: '<S1>/If' */
  if (rtDW.motor_state != 2) {
    /* Outputs for IfAction SubSystem: '<S1>/Motor Halt and Arm' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Switch: '<S12>/Switch1' incorporates:
     *  Constant: '<S12>/Decrement'
     *  Constant: '<S12>/Increment'
     *  Constant: '<S4>/Constant'
     *  RelationalOperator: '<S4>/Compare'
     */
    if (rtDW.motor_state == 3) {
      tmp = -10;
    } else {
      tmp = 10;
    }

    /* End of Switch: '<S12>/Switch1' */

    /* Sum: '<S12>/Sum' incorporates:
     *  UnitDelay: '<S12>/X'
     */
    rtb_FilterCoefficient = (real_T)tmp + rtDW.X_h;

    /* Saturate: '<S8>/Saturation1' */
    if (rtb_FilterCoefficient > 1196.0) {
      rtb_Add = 1196.0;
    } else if (rtb_FilterCoefficient < 0.0) {
      rtb_Add = 0.0;
    } else {
      rtb_Add = rtb_FilterCoefficient;
    }

    /* End of Saturate: '<S8>/Saturation1' */

    /* Switch: '<S12>/Switch' incorporates:
     *  Constant: '<S5>/Constant'
     *  RelationalOperator: '<S5>/Compare'
     */
    if (rtDW.motor_state == 0) {
      /* Update for UnitDelay: '<S12>/X' incorporates:
       *  Constant: '<S12>/load_var'
       */
      rtDW.X_h = 0.0;
    } else {
      /* Update for UnitDelay: '<S12>/X' */
      rtDW.X_h = rtb_FilterCoefficient;
    }

    /* End of Switch: '<S12>/Switch' */
    /* End of Outputs for SubSystem: '<S1>/Motor Halt and Arm' */
  } else {
    /* Outputs for IfAction SubSystem: '<S1>/Motor PID Controlelr' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Gain: '<S14>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S14>/Filter'
     *  Gain: '<S14>/Derivative Gain'
     *  Sum: '<S14>/Sum3'
     *  Sum: '<S14>/SumD'
     */
    rtb_FilterCoefficient = ((213.33333333333334 - rtDW.GearingRatio) * 0.0 -
      rtDW.Filter_DSTATE) * 100.0;

    /* Sum: '<S13>/Add' incorporates:
     *  Constant: '<S13>/PWM Offset Factor'
     *  DiscreteIntegrator: '<S14>/Integrator'
     *  Gain: '<S13>/PWM Gain Factor'
     *  Sum: '<S14>/Sum'
     *  Sum: '<S14>/Sum1'
     */
    rtb_Add = (((213.33333333333334 - rtDW.GearingRatio) +
                rtDW.Integrator_DSTATE) + rtb_FilterCoefficient) * 0.1709 +
      1060.0;

    /* Outport: '<Root>/motor_speed_flag' incorporates:
     *  Constant: '<S9>/Terminal'
     *  RelationalOperator: '<S9>/RelOpt'
     */
    rtY.motor_speed_flag = (1093.0 <= rtb_Add);

    /* Saturate: '<S9>/Saturation' */
    if (rtb_Add > 1860.0) {
      rtb_Add = 1860.0;
    } else {
      if (rtb_Add < 0.0) {
        rtb_Add = 0.0;
      }
    }

    /* End of Saturate: '<S9>/Saturation' */

    /* Update for DiscreteIntegrator: '<S14>/Integrator' incorporates:
     *  Sum: '<S14>/Sum2'
     */
    rtDW.Integrator_DSTATE += (213.33333333333334 - rtDW.GearingRatio) * 0.001;

    /* Update for DiscreteIntegrator: '<S14>/Filter' */
    rtDW.Filter_DSTATE += 0.001 * rtb_FilterCoefficient;

    /* End of Outputs for SubSystem: '<S1>/Motor PID Controlelr' */
  }

  /* End of If: '<S1>/If' */

  /* Outport: '<Root>/outer_motor_pwm' incorporates:
   *  Constant: '<S2>/PWM Period us'
   *  Product: '<S2>/Divide'
   */
  rtY.outer_motor_pwm = rtb_Add / 20000.0;

  /* Outport: '<Root>/ring_position_ratio' incorporates:
   *  Constant: '<S11>/Increment'
   *  Product: '<S10>/Divide'
   *  Product: '<S10>/Divide1'
   *  Sum: '<S11>/Sum'
   *  UnitDelay: '<S11>/X'
   */
  rtY.ring_position_ratio = (real32_T)((1.0 + rtDW.X_p) / (real32_T)
    (rtDW.GearingRatio / 5.5600000159472529E-9));

  /* Update for UnitDelay: '<S1>/X' */
  rtDW.X_l = rtb_Add;

  /* Switch: '<S11>/Switch' */
  if (rtDW.count_load) {
    /* Update for UnitDelay: '<S11>/X' incorporates:
     *  Constant: '<S11>/Load'
     */
    rtDW.X_p = 0.0;
  } else {
    /* Update for UnitDelay: '<S11>/X' incorporates:
     *  Constant: '<S11>/Increment'
     *  Sum: '<S11>/Sum'
     *  UnitDelay: '<S11>/X'
     */
    rtDW.X_p++;
  }

  /* End of Switch: '<S11>/Switch' */
}

/* Model initialize function */
void bldc_motor_controller_switch_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
