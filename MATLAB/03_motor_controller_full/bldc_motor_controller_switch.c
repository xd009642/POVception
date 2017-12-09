/*
 * File: bldc_motor_controller_switch.c
 *
 * Code generated for Simulink model 'bldc_motor_controller_switch'.
 *
 * Model version                  : 1.566
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sat Dec 09 19:48:59 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "bldc_motor_controller_switch.h"

/* Named constants for Chart: '<S1>/Motor ISR SF' */
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_idle                        ((uint8_T)1U)
#define IN_idle1                       ((uint8_T)2U)

/* Named constants for Chart: '<S1>/Motor Controller' */
#define IN_arm_motor                   ((uint8_T)1U)
#define IN_halt_motor                  ((uint8_T)3U)
#define IN_idle_d                      ((uint8_T)2U)
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
void EXTI1_IRQHandler(void);

/* Hardware Interrupt Block: '<Root>/Hardware Interrupt' */
void EXTI1_IRQHandler(void)
{
  /* Call the system: <S1>/Motor ISR SF */
  {
    /* S-Function (arm_cortex_m_interrupt): '<Root>/Hardware Interrupt' */

    /* Output and update for function-call system: '<S1>/Motor ISR SF' */

    /* Gateway: Outer Motor Controller/Motor ISR SF */
    /* Event: '<S10>:8' */
    /* During: Outer Motor Controller/Motor ISR SF */
    if (rtDW.is_active_c1_bldc_motor_control == 0U) {
      /* Entry: Outer Motor Controller/Motor ISR SF */
      rtDW.is_active_c1_bldc_motor_control = 1U;

      /* Entry Internal: Outer Motor Controller/Motor ISR SF */
      /* Transition: '<S10>:5' */
      rtDW.is_c1_bldc_motor_controller_swi = IN_idle;

      /* Outport: '<Root>/hallEffectTrigDebug' */
      /* Entry 'idle': '<S10>:1' */
      /* '<S10>:1:1' int_out = false; */
      rtY.hallEffectTrigDebug = false;
    } else if (rtDW.is_c1_bldc_motor_controller_swi == IN_idle) {
      /* During 'idle': '<S10>:1' */
      /* '<S10>:4:1' sf_internal_predicateOutput = ... */
      /* '<S10>:4:1' TrigIn; */
      /* Transition: '<S10>:4' */
      rtDW.is_c1_bldc_motor_controller_swi = IN_idle1;

      /* Outport: '<Root>/hallEffectTrigDebug' */
      /* Entry 'idle1': '<S10>:2' */
      /* '<S10>:2:1' int_out = true; */
      rtY.hallEffectTrigDebug = true;
    } else {
      /* During 'idle1': '<S10>:2' */
      /* Transition: '<S10>:6' */
      rtDW.is_c1_bldc_motor_controller_swi = IN_idle;

      /* Outport: '<Root>/hallEffectTrigDebug' */
      /* Entry 'idle': '<S10>:1' */
      /* '<S10>:1:1' int_out = false; */
      rtY.hallEffectTrigDebug = false;
    }

    /* End of Outputs for S-Function (arm_cortex_m_interrupt): '<Root>/Hardware Interrupt' */
  }
}

/* Model step function */
void bldc_motor_controller_switch_step(void)
{
  real_T rtb_X;
  real_T rtb_Add;
  int32_T tmp;

  /* UnitDelay: '<S1>/X' */
  rtb_X = rtDW.X_l;

  /* Chart: '<S1>/Motor Controller' incorporates:
   *  Inport: '<Root>/arm_motor_req'
   *  Inport: '<Root>/halt_motor_req'
   *  Outport: '<Root>/hallEffectTrigDebug'
   */
  /* Gateway: Outer Motor Controller/Motor Controller */
  /* During: Outer Motor Controller/Motor Controller */
  if (rtDW.is_active_c3_bldc_motor_control == 0U) {
    /* Entry: Outer Motor Controller/Motor Controller */
    rtDW.is_active_c3_bldc_motor_control = 1U;

    /* Entry Internal: Outer Motor Controller/Motor Controller */
    /* Transition: '<S7>:16' */
    rtDW.is_c3_bldc_motor_controller_swi = IN_idle_d;

    /* Entry 'idle': '<S7>:15' */
    /* '<S7>:15:1' count_load = true; */
    rtDW.count_load = true;

    /* '<S7>:15:1' motor_state = 0; */
    rtDW.motor_state = 0U;
  } else {
    switch (rtDW.is_c3_bldc_motor_controller_swi) {
     case IN_arm_motor:
      rtDW.motor_state = 1U;

      /* During 'arm_motor': '<S7>:18' */
      /* '<S7>:17:1' sf_internal_predicateOutput = ... */
      /* '<S7>:17:1' hallEffectTrig; */
      if (rtY.hallEffectTrigDebug) {
        /* Transition: '<S7>:17' */
        rtDW.is_c3_bldc_motor_controller_swi = IN_trig_idle;

        /* Entry 'trig_idle': '<S7>:1' */
        /* '<S7>:1:1' motor_state = 2; */
        rtDW.motor_state = 2U;

        /* '<S7>:1:1' count_load = false; */
        rtDW.count_load = false;
      }
      break;

     case IN_idle_d:
      rtDW.count_load = true;
      rtDW.motor_state = 0U;

      /* During 'idle': '<S7>:15' */
      /* '<S7>:19:1' sf_internal_predicateOutput = ... */
      /* '<S7>:19:1' arm_motor_req == 1; */
      if (rtU.arm_motor_req) {
        /* Transition: '<S7>:19' */
        rtDW.is_c3_bldc_motor_controller_swi = IN_arm_motor;

        /* Entry 'arm_motor': '<S7>:18' */
        /* '<S7>:18:1' motor_state = 1; */
        rtDW.motor_state = 1U;

        /* exit: motor_state = 2; */
      }
      break;

     case IN_halt_motor:
      rtDW.motor_state = 3U;

      /* During 'halt_motor': '<S7>:23' */
      /* '<S7>:26:1' sf_internal_predicateOutput = ... */
      /* '<S7>:26:1' halt_motor_req == 0 && count_in <= 1060; */
      if ((!rtU.halt_motor_req) && (rtb_X <= 1060.0)) {
        /* Transition: '<S7>:26' */
        rtDW.is_c3_bldc_motor_controller_swi = IN_idle_d;

        /* Entry 'idle': '<S7>:15' */
        /* '<S7>:15:1' count_load = true; */
        rtDW.count_load = true;

        /* '<S7>:15:1' motor_state = 0; */
        rtDW.motor_state = 0U;
      }
      break;

     case IN_interrupt_trigger:
      /* During 'interrupt_trigger': '<S7>:5' */
      /* Transition: '<S7>:11' */
      rtDW.is_c3_bldc_motor_controller_swi = IN_speed_calc_done;

      /* Entry 'speed_calc_done': '<S7>:10' */
      /* '<S7>:10:1' count_load = true; */
      rtDW.count_load = true;
      break;

     case IN_speed_calc_done:
      /* During 'speed_calc_done': '<S7>:10' */
      /* Transition: '<S7>:7' */
      rtDW.is_c3_bldc_motor_controller_swi = IN_trig_idle;

      /* Entry 'trig_idle': '<S7>:1' */
      /* '<S7>:1:1' motor_state = 2; */
      rtDW.motor_state = 2U;

      /* '<S7>:1:1' count_load = false; */
      rtDW.count_load = false;
      break;

     default:
      rtDW.count_load = false;
      rtDW.motor_state = 2U;

      /* During 'trig_idle': '<S7>:1' */
      /* '<S7>:24:1' sf_internal_predicateOutput = ... */
      /* '<S7>:24:1' halt_motor_req == 1; */
      if (rtU.halt_motor_req) {
        /* Transition: '<S7>:24' */
        rtDW.is_c3_bldc_motor_controller_swi = IN_halt_motor;

        /* Entry 'halt_motor': '<S7>:23' */
        /* '<S7>:23:1' motor_state = 3; */
        rtDW.motor_state = 3U;
      } else {
        /* '<S7>:25:1' sf_internal_predicateOutput = ... */
        /* '<S7>:25:1' hallEffectTrig; */
        if (rtY.hallEffectTrigDebug) {
          /* Transition: '<S7>:25' */
          rtDW.is_c3_bldc_motor_controller_swi = IN_interrupt_trigger;

          /* Outputs for Function Call SubSystem: '<S1>/Motor Count Condition' */
          /* Gain: '<S8>/Gearing Ratio' incorporates:
           *  Constant: '<S13>/Increment'
           *  Constant: '<S8>/rps to rpm'
           *  Gain: '<S8>/Clock Period'
           *  Product: '<S8>/Divide'
           *  Sum: '<S13>/Sum'
           *  UnitDelay: '<S13>/X'
           */
          /* Entry 'interrupt_trigger': '<S7>:5' */
          /* '<S7>:5:1' trigOut; */
          /* Event: '<S7>:9' */
          rtDW.GearingRatio = 60.0 / ((1.0 + rtDW.X_i) * 5.56E-9) *
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
     *  ActionPort: '<S9>/Action Port'
     */
    /* Switch: '<S14>/Switch1' incorporates:
     *  Constant: '<S14>/Decrement'
     *  Constant: '<S14>/Increment'
     *  Constant: '<S5>/Constant'
     *  RelationalOperator: '<S5>/Compare'
     */
    if (rtDW.motor_state == 3) {
      tmp = 10;
    } else {
      tmp = -10;
    }

    /* End of Switch: '<S14>/Switch1' */

    /* Sum: '<S14>/Sum' incorporates:
     *  UnitDelay: '<S14>/X'
     */
    rtb_X = (real_T)tmp + rtDW.X_h;

    /* Saturate: '<S9>/Saturation1' */
    if (rtb_X > 1196.0) {
      rtb_Add = 1196.0;
    } else if (rtb_X < 0.0) {
      rtb_Add = 0.0;
    } else {
      rtb_Add = rtb_X;
    }

    /* End of Saturate: '<S9>/Saturation1' */

    /* Switch: '<S14>/Switch' incorporates:
     *  Constant: '<S6>/Constant'
     *  RelationalOperator: '<S6>/Compare'
     */
    if (rtDW.motor_state == 0) {
      /* Update for UnitDelay: '<S14>/X' incorporates:
       *  Constant: '<S14>/load_var'
       */
      rtDW.X_h = 0.0;
    } else {
      /* Update for UnitDelay: '<S14>/X' */
      rtDW.X_h = rtb_X;
    }

    /* End of Switch: '<S14>/Switch' */
    /* End of Outputs for SubSystem: '<S1>/Motor Halt and Arm' */
  } else {
    /* Outputs for IfAction SubSystem: '<S1>/Motor PID Controlelr' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* Gain: '<S16>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S16>/Filter'
     *  Gain: '<S16>/Derivative Gain'
     *  Sum: '<S16>/Sum3'
     *  Sum: '<S16>/SumD'
     */
    rtb_X = ((213.33333333333334 - rtDW.GearingRatio) * 0.0 - rtDW.Filter_DSTATE)
      * 100.0;

    /* Sum: '<S15>/Add' incorporates:
     *  Constant: '<S15>/PWM Offset Factor'
     *  DiscreteIntegrator: '<S16>/Integrator'
     *  Gain: '<S15>/PWM Gain Factor'
     *  Sum: '<S16>/Sum'
     *  Sum: '<S16>/Sum1'
     */
    rtb_Add = (((213.33333333333334 - rtDW.GearingRatio) +
                rtDW.Integrator_DSTATE) + rtb_X) * 0.1709 + 1060.0;

    /* Outport: '<Root>/motor_speed_flag' incorporates:
     *  Constant: '<S11>/Terminal'
     *  RelationalOperator: '<S11>/RelOpt'
     */
    rtY.motor_speed_flag = (1093.0 <= rtb_Add);

    /* Saturate: '<S11>/Saturation' */
    if (rtb_Add > 1860.0) {
      rtb_Add = 1860.0;
    } else {
      if (rtb_Add < 0.0) {
        rtb_Add = 0.0;
      }
    }

    /* End of Saturate: '<S11>/Saturation' */

    /* Update for DiscreteIntegrator: '<S16>/Integrator' incorporates:
     *  Sum: '<S16>/Sum2'
     */
    rtDW.Integrator_DSTATE += (213.33333333333334 - rtDW.GearingRatio) * 0.001;

    /* Update for DiscreteIntegrator: '<S16>/Filter' */
    rtDW.Filter_DSTATE += 0.001 * rtb_X;

    /* End of Outputs for SubSystem: '<S1>/Motor PID Controlelr' */
  }

  /* End of If: '<S1>/If' */

  /* Outport: '<Root>/outer_motor_pwm' incorporates:
   *  Constant: '<S2>/PWM Period us'
   *  Product: '<S2>/Divide'
   */
  rtY.outer_motor_pwm = rtb_Add / 20000.0;

  /* Outport: '<Root>/ring_position_ratio' incorporates:
   *  Constant: '<S12>/Clock Period Const'
   *  Constant: '<S13>/Increment'
   *  Product: '<S12>/Divide'
   *  Product: '<S12>/Divide1'
   *  Sum: '<S13>/Sum'
   *  UnitDelay: '<S13>/X'
   */
  rtY.ring_position_ratio = (1.0 + rtDW.X_i) / (rtDW.GearingRatio / 5.56E-9);

  /* Update for UnitDelay: '<S1>/X' */
  rtDW.X_l = rtb_Add;

  /* Switch: '<S13>/Switch' */
  if (rtDW.count_load) {
    /* Update for UnitDelay: '<S13>/X' incorporates:
     *  Constant: '<S13>/Load'
     */
    rtDW.X_i = 0.0;
  } else {
    /* Update for UnitDelay: '<S13>/X' incorporates:
     *  Constant: '<S13>/Increment'
     *  Sum: '<S13>/Sum'
     *  UnitDelay: '<S13>/X'
     */
    rtDW.X_i++;
  }

  /* End of Switch: '<S13>/Switch' */
}

/* Model initialize function */
void bldc_motor_controller_switch_initialize(void)
{
  /* Start for S-Function (arm_cortex_m_interrupt): '<Root>/Hardware Interrupt' */

  /* Setting the priority for SysTick scheduler */
  NVIC_SetPriority((IRQn_Type)(-1), 1);
  NVIC_SetPriority((IRQn_Type)7, 0);
  NVIC_EnableIRQ((IRQn_Type)7);

  /* End of Start for S-Function (arm_cortex_m_interrupt): '<Root>/Hardware Interrupt' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
