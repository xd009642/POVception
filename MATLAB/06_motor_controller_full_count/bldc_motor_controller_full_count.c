/*
 * File: bldc_motor_controller_full_count.c
 *
 * Code generated for Simulink model 'bldc_motor_controller_full_count'.
 *
 * Model version                  : 1.206
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Tue Dec 12 16:44:14 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "bldc_motor_controller_full_count.h"
#include "bldc_motor_controller_full_count_private.h"

/* Named constants for Chart: '<S1>/Motor Controller' */
#define bldc_motor_IN_interrupt_trigger ((uint8_T)4U)
#define bldc_motor_c_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define bldc_motor_c_IN_speed_calc_done ((uint8_T)5U)
#define bldc_motor_contro_IN_halt_motor ((uint8_T)3U)
#define bldc_motor_control_IN_arm_motor ((uint8_T)1U)
#define bldc_motor_control_IN_trig_idle ((uint8_T)6U)
#define bldc_motor_controller_f_IN_idle ((uint8_T)2U)

/* Block signals (auto storage) */
B_bldc_motor_controller_full__T bldc_motor_controller_full_co_B;

/* Block states (auto storage) */
DW_bldc_motor_controller_full_T bldc_motor_controller_full_c_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_bldc_motor_controller_fu_T bldc_motor_controller_full_co_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_bldc_motor_controller_fu_T bldc_motor_controller_full_co_Y;

/* Real-time model */
RT_MODEL_bldc_motor_controlle_T bldc_motor_controller_full_c_M_;
RT_MODEL_bldc_motor_controlle_T *const bldc_motor_controller_full_c_M =
  &bldc_motor_controller_full_c_M_;

/* Model step function */
void bldc_motor_controller_full_count_step(void)
{
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_g;
  real_T rtb_Sum;
  real_T rtb_Saturation;
  real_T rtb_Saturation_k;
  real_T rtb_Switch2_n;
  real_T tmp;

  /* RelationalOperator: '<S24>/Compare' incorporates:
   *  Constant: '<S24>/Constant'
   *  UnitDelay: '<S19>/X1'
   */
  rtb_Compare = (bldc_motor_controller_full_c_DW.X >=
                 bldc_motor_controller_full_co_P.FastCompare_const);

  /* Chart: '<S3>/Motor Controller' incorporates:
   *  Inport: '<Root>/arm_motor_req'
   *  Inport: '<Root>/halt_motor_req'
   *  Inport: '<Root>/outer_hall_effect_trig'
   *  Inport: '<Root>/outer_rotation_count_in'
   *  Inport: '<S16>/count_in'
   *  UnitDelay: '<S3>/X'
   */
  /* Gateway: Outer Motor Controller/Motor Controller */
  /* During: Outer Motor Controller/Motor Controller */
  if (bldc_motor_controller_full_c_DW.is_active_c2_bldc_motor_control == 0U) {
    /* Entry: Outer Motor Controller/Motor Controller */
    bldc_motor_controller_full_c_DW.is_active_c2_bldc_motor_control = 1U;

    /* Entry Internal: Outer Motor Controller/Motor Controller */
    /* Transition: '<S15>:16' */
    bldc_motor_controller_full_c_DW.is_c2_bldc_motor_controller_ful =
      bldc_motor_controller_f_IN_idle;

    /* Outport: '<Root>/outer_rot_count_load' */
    /* Entry 'idle': '<S15>:15' */
    /* '<S15>:15:1' count_load = true; */
    bldc_motor_controller_full_co_Y.outer_rot_count_load = true;

    /* '<S15>:15:1' motor_state = 0; */
    bldc_motor_controller_full_co_B.motor_state = 0U;
  } else {
    switch (bldc_motor_controller_full_c_DW.is_c2_bldc_motor_controller_ful) {
     case bldc_motor_control_IN_arm_motor:
      bldc_motor_controller_full_co_B.motor_state = 2U;

      /* During 'arm_motor': '<S15>:18' */
      /* '<S15>:17:1' sf_internal_predicateOutput = ... */
      /* '<S15>:17:1' hallEffectTrig; */
      if (bldc_motor_controller_full_co_U.outer_hall_effect_trig) {
        /* Transition: '<S15>:17' */
        bldc_motor_controller_full_c_DW.is_c2_bldc_motor_controller_ful =
          bldc_motor_control_IN_trig_idle;

        /* Entry 'trig_idle': '<S15>:1' */
        /* '<S15>:1:1' motor_state = 3; */
        bldc_motor_controller_full_co_B.motor_state = 3U;

        /* Outport: '<Root>/outer_rot_count_load' */
        /* '<S15>:1:1' count_load = false; */
        bldc_motor_controller_full_co_Y.outer_rot_count_load = false;
      }
      break;

     case bldc_motor_controller_f_IN_idle:
      bldc_motor_controller_full_co_B.motor_state = 0U;

      /* Outport: '<Root>/outer_rot_count_load' */
      bldc_motor_controller_full_co_Y.outer_rot_count_load = true;

      /* During 'idle': '<S15>:15' */
      /* '<S15>:19:1' sf_internal_predicateOutput = ... */
      /* '<S15>:19:1' arm_motor_req == 1; */
      if (bldc_motor_controller_full_co_U.arm_motor_req) {
        /* Transition: '<S15>:19' */
        bldc_motor_controller_full_c_DW.is_c2_bldc_motor_controller_ful =
          bldc_motor_control_IN_arm_motor;

        /* Entry 'arm_motor': '<S15>:18' */
        /* '<S15>:18:1' motor_state = 2; */
        bldc_motor_controller_full_co_B.motor_state = 2U;
      }
      break;

     case bldc_motor_contro_IN_halt_motor:
      bldc_motor_controller_full_co_B.motor_state = 1U;

      /* During 'halt_motor': '<S15>:23' */
      /* '<S15>:26:1' sf_internal_predicateOutput = ... */
      /* '<S15>:26:1' halt_motor_req == 0 && count_in <= 0; */
      if ((!bldc_motor_controller_full_co_U.halt_motor_req) &&
          (bldc_motor_controller_full_c_DW.X_i <= 0.0)) {
        /* Transition: '<S15>:26' */
        bldc_motor_controller_full_c_DW.is_c2_bldc_motor_controller_ful =
          bldc_motor_controller_f_IN_idle;

        /* Outport: '<Root>/outer_rot_count_load' */
        /* Entry 'idle': '<S15>:15' */
        /* '<S15>:15:1' count_load = true; */
        bldc_motor_controller_full_co_Y.outer_rot_count_load = true;

        /* '<S15>:15:1' motor_state = 0; */
        bldc_motor_controller_full_co_B.motor_state = 0U;
      }
      break;

     case bldc_motor_IN_interrupt_trigger:
      /* During 'interrupt_trigger': '<S15>:5' */
      /* Transition: '<S15>:11' */
      bldc_motor_controller_full_c_DW.is_c2_bldc_motor_controller_ful =
        bldc_motor_c_IN_speed_calc_done;

      /* Outport: '<Root>/outer_rot_count_load' */
      /* Entry 'speed_calc_done': '<S15>:10' */
      /* '<S15>:10:1' count_load = true; */
      bldc_motor_controller_full_co_Y.outer_rot_count_load = true;
      break;

     case bldc_motor_c_IN_speed_calc_done:
      /* During 'speed_calc_done': '<S15>:10' */
      /* Transition: '<S15>:7' */
      bldc_motor_controller_full_c_DW.is_c2_bldc_motor_controller_ful =
        bldc_motor_control_IN_trig_idle;

      /* Entry 'trig_idle': '<S15>:1' */
      /* '<S15>:1:1' motor_state = 3; */
      bldc_motor_controller_full_co_B.motor_state = 3U;

      /* Outport: '<Root>/outer_rot_count_load' */
      /* '<S15>:1:1' count_load = false; */
      bldc_motor_controller_full_co_Y.outer_rot_count_load = false;
      break;

     default:
      bldc_motor_controller_full_co_B.motor_state = 3U;

      /* Outport: '<Root>/outer_rot_count_load' */
      bldc_motor_controller_full_co_Y.outer_rot_count_load = false;

      /* During 'trig_idle': '<S15>:1' */
      /* '<S15>:24:1' sf_internal_predicateOutput = ... */
      /* '<S15>:24:1' halt_motor_req == 1; */
      if (bldc_motor_controller_full_co_U.halt_motor_req) {
        /* Transition: '<S15>:24' */
        bldc_motor_controller_full_c_DW.is_c2_bldc_motor_controller_ful =
          bldc_motor_contro_IN_halt_motor;

        /* Entry 'halt_motor': '<S15>:23' */
        /* '<S15>:23:1' motor_state = 1; */
        bldc_motor_controller_full_co_B.motor_state = 1U;
      } else {
        /* '<S15>:25:1' sf_internal_predicateOutput = ... */
        /* '<S15>:25:1' hallEffectTrig; */
        if (bldc_motor_controller_full_co_U.outer_hall_effect_trig) {
          /* Transition: '<S15>:25' */
          bldc_motor_controller_full_c_DW.is_c2_bldc_motor_controller_ful =
            bldc_motor_IN_interrupt_trigger;

          /* Outputs for Function Call SubSystem: '<S3>/Motor Count Condition' */
          /* Entry 'interrupt_trigger': '<S15>:5' */
          /* '<S15>:5:1' trigOut; */
          /* Event: '<S15>:9' */
          bldc_motor_controller_full_co_B.count_in =
            bldc_motor_controller_full_co_U.outer_rotation_count_in;

          /* End of Outputs for SubSystem: '<S3>/Motor Count Condition' */
        }
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Motor Controller' */

  /* RelationalOperator: '<S21>/Compare' incorporates:
   *  Constant: '<S21>/Constant'
   */
  rtb_Compare_g = (bldc_motor_controller_full_co_B.motor_state ==
                   bldc_motor_controller_full_co_P.LoadCompare_const);

  /* Switch: '<S19>/Switch1' incorporates:
   *  Constant: '<S20>/Constant'
   *  Constant: '<S22>/Fast Increment'
   *  Constant: '<S25>/Constant'
   *  Logic: '<S22>/Logical Operator'
   *  RelationalOperator: '<S20>/Compare'
   *  RelationalOperator: '<S25>/Compare'
   *  Switch: '<S22>/Switch1'
   *  Switch: '<S22>/Switch2'
   *  UnitDelay: '<S19>/X1'
   */
  if (bldc_motor_controller_full_co_B.motor_state ==
      bldc_motor_controller_full_co_P.HaltCompare_const_g) {
    /* Switch: '<S22>/Switch3' incorporates:
     *  Constant: '<S22>/Fast Decrement'
     *  Constant: '<S22>/Idle'
     *  Constant: '<S23>/Constant'
     *  RelationalOperator: '<S23>/Compare'
     *  Switch: '<S22>/Switch6'
     *  UnitDelay: '<S19>/X1'
     */
    if (bldc_motor_controller_full_c_DW.X <=
        bldc_motor_controller_full_co_P.Constant_Value) {
      tmp = bldc_motor_controller_full_co_P.Idle_Value;
    } else if (rtb_Compare) {
      /* Switch: '<S22>/Switch6' incorporates:
       *  Constant: '<S22>/Slow Decrement'
       */
      tmp = bldc_motor_controller_full_co_P.SlowDecrement_Value_p;
    } else {
      tmp = bldc_motor_controller_full_co_P.FastDecrement_Value_m;
    }

    /* End of Switch: '<S22>/Switch3' */
  } else if ((bldc_motor_controller_full_c_DW.X >=
              bldc_motor_controller_full_co_P.MaxPulseCompare_const) ||
             rtb_Compare_g) {
    /* Switch: '<S22>/Switch2' incorporates:
     *  Constant: '<S22>/Idle'
     */
    tmp = bldc_motor_controller_full_co_P.Idle_Value;
  } else if (rtb_Compare) {
    /* Switch: '<S22>/Switch1' incorporates:
     *  Constant: '<S22>/Slow Increment'
     *  Switch: '<S22>/Switch2'
     */
    tmp = bldc_motor_controller_full_co_P.SlowIncrement_Value_e;
  } else {
    tmp = bldc_motor_controller_full_co_P.FastIncrement_Value_g;
  }

  /* End of Switch: '<S19>/Switch1' */

  /* Sum: '<S19>/Sum' incorporates:
   *  UnitDelay: '<S19>/X'
   */
  rtb_Sum = tmp + bldc_motor_controller_full_c_DW.X_f;

  /* Saturate: '<S17>/Saturation' */
  if (rtb_Sum > bldc_motor_controller_full_co_P.Saturation_UpperSat) {
    rtb_Saturation = bldc_motor_controller_full_co_P.Saturation_UpperSat;
  } else if (rtb_Sum < bldc_motor_controller_full_co_P.Saturation_LowerSat) {
    rtb_Saturation = bldc_motor_controller_full_co_P.Saturation_LowerSat;
  } else {
    rtb_Saturation = rtb_Sum;
  }

  /* End of Saturate: '<S17>/Saturation' */

  /* Outport: '<Root>/outer_motor_pwm' incorporates:
   *  Constant: '<S4>/PWM Period us'
   *  Product: '<S4>/Divide'
   */
  bldc_motor_controller_full_co_Y.outer_motor_pwm = rtb_Saturation /
    bldc_motor_controller_full_co_P.PWMPeriodus_Value;

  /* Switch: '<S18>/Switch' incorporates:
   *  Inport: '<Root>/outer_rotation_count_in'
   */
  if (bldc_motor_controller_full_co_B.count_in != 0.0) {
    tmp = bldc_motor_controller_full_co_B.count_in;
  } else {
    tmp = bldc_motor_controller_full_co_U.outer_rotation_count_in;
  }

  /* End of Switch: '<S18>/Switch' */

  /* Outport: '<Root>/outer_ring_position_ratio' incorporates:
   *  Inport: '<Root>/outer_rotation_count_in'
   *  Product: '<S18>/Divide1'
   */
  bldc_motor_controller_full_co_Y.outer_ring_position_ratio = (real32_T)
    (bldc_motor_controller_full_co_U.outer_rotation_count_in / tmp);

  /* Outport: '<Root>/outer_motor_speed_flag' incorporates:
   *  Constant: '<S17>/Terminal'
   *  RelationalOperator: '<S17>/RelOpt'
   */
  bldc_motor_controller_full_co_Y.outer_motor_speed_flag =
    (bldc_motor_controller_full_co_P.Terminal_Value <= rtb_Saturation);

  /* RelationalOperator: '<S14>/Compare' incorporates:
   *  Constant: '<S14>/Constant'
   *  UnitDelay: '<S9>/X1'
   */
  rtb_Compare = (bldc_motor_controller_full_c_DW.X_h >=
                 bldc_motor_controller_full_co_P.HaltCompare1_const);

  /* Chart: '<S1>/Motor Controller' incorporates:
   *  Inport: '<Root>/arm_motor_req'
   *  Inport: '<Root>/halt_motor_req'
   *  Inport: '<Root>/inner_hall_effect_trig'
   *  Inport: '<Root>/inner_rotation_count_in'
   *  Inport: '<S6>/count_in'
   *  UnitDelay: '<S1>/X'
   */
  /* Gateway: Inner Motor Controller/Motor Controller */
  /* During: Inner Motor Controller/Motor Controller */
  if (bldc_motor_controller_full_c_DW.is_active_c1_bldc_motor_control == 0U) {
    /* Entry: Inner Motor Controller/Motor Controller */
    bldc_motor_controller_full_c_DW.is_active_c1_bldc_motor_control = 1U;

    /* Entry Internal: Inner Motor Controller/Motor Controller */
    /* Transition: '<S5>:16' */
    bldc_motor_controller_full_c_DW.is_c1_bldc_motor_controller_ful =
      bldc_motor_controller_f_IN_idle;

    /* Outport: '<Root>/inner_rot_count_load' */
    /* Entry 'idle': '<S5>:15' */
    /* '<S5>:15:1' count_load = true; */
    bldc_motor_controller_full_co_Y.inner_rot_count_load = true;

    /* '<S5>:15:1' motor_state = 0; */
    bldc_motor_controller_full_co_B.motor_state_m = 0U;
  } else {
    switch (bldc_motor_controller_full_c_DW.is_c1_bldc_motor_controller_ful) {
     case bldc_motor_control_IN_arm_motor:
      bldc_motor_controller_full_co_B.motor_state_m = 2U;

      /* During 'arm_motor': '<S5>:18' */
      /* '<S5>:17:1' sf_internal_predicateOutput = ... */
      /* '<S5>:17:1' hallEffectTrig; */
      if (bldc_motor_controller_full_co_U.inner_hall_effect_trig) {
        /* Transition: '<S5>:17' */
        bldc_motor_controller_full_c_DW.is_c1_bldc_motor_controller_ful =
          bldc_motor_control_IN_trig_idle;

        /* Entry 'trig_idle': '<S5>:1' */
        /* '<S5>:1:1' motor_state = 3; */
        bldc_motor_controller_full_co_B.motor_state_m = 3U;

        /* Outport: '<Root>/inner_rot_count_load' */
        /* '<S5>:1:1' count_load = false; */
        bldc_motor_controller_full_co_Y.inner_rot_count_load = false;
      }
      break;

     case bldc_motor_controller_f_IN_idle:
      bldc_motor_controller_full_co_B.motor_state_m = 0U;

      /* Outport: '<Root>/inner_rot_count_load' */
      bldc_motor_controller_full_co_Y.inner_rot_count_load = true;

      /* During 'idle': '<S5>:15' */
      /* '<S5>:19:1' sf_internal_predicateOutput = ... */
      /* '<S5>:19:1' arm_motor_req == 1; */
      if (bldc_motor_controller_full_co_U.arm_motor_req) {
        /* Transition: '<S5>:19' */
        bldc_motor_controller_full_c_DW.is_c1_bldc_motor_controller_ful =
          bldc_motor_control_IN_arm_motor;

        /* Entry 'arm_motor': '<S5>:18' */
        /* '<S5>:18:1' motor_state = 2; */
        bldc_motor_controller_full_co_B.motor_state_m = 2U;
      }
      break;

     case bldc_motor_contro_IN_halt_motor:
      bldc_motor_controller_full_co_B.motor_state_m = 1U;

      /* During 'halt_motor': '<S5>:23' */
      /* '<S5>:26:1' sf_internal_predicateOutput = ... */
      /* '<S5>:26:1' halt_motor_req == 0 && count_in <= 1060; */
      if ((!bldc_motor_controller_full_co_U.halt_motor_req) &&
          (bldc_motor_controller_full_c_DW.X_j <= 1060.0)) {
        /* Transition: '<S5>:26' */
        bldc_motor_controller_full_c_DW.is_c1_bldc_motor_controller_ful =
          bldc_motor_controller_f_IN_idle;

        /* Outport: '<Root>/inner_rot_count_load' */
        /* Entry 'idle': '<S5>:15' */
        /* '<S5>:15:1' count_load = true; */
        bldc_motor_controller_full_co_Y.inner_rot_count_load = true;

        /* '<S5>:15:1' motor_state = 0; */
        bldc_motor_controller_full_co_B.motor_state_m = 0U;
      }
      break;

     case bldc_motor_IN_interrupt_trigger:
      /* During 'interrupt_trigger': '<S5>:5' */
      /* Transition: '<S5>:11' */
      bldc_motor_controller_full_c_DW.is_c1_bldc_motor_controller_ful =
        bldc_motor_c_IN_speed_calc_done;

      /* Outport: '<Root>/inner_rot_count_load' */
      /* Entry 'speed_calc_done': '<S5>:10' */
      /* '<S5>:10:1' count_load = true; */
      bldc_motor_controller_full_co_Y.inner_rot_count_load = true;
      break;

     case bldc_motor_c_IN_speed_calc_done:
      /* During 'speed_calc_done': '<S5>:10' */
      /* Transition: '<S5>:7' */
      bldc_motor_controller_full_c_DW.is_c1_bldc_motor_controller_ful =
        bldc_motor_control_IN_trig_idle;

      /* Entry 'trig_idle': '<S5>:1' */
      /* '<S5>:1:1' motor_state = 3; */
      bldc_motor_controller_full_co_B.motor_state_m = 3U;

      /* Outport: '<Root>/inner_rot_count_load' */
      /* '<S5>:1:1' count_load = false; */
      bldc_motor_controller_full_co_Y.inner_rot_count_load = false;
      break;

     default:
      bldc_motor_controller_full_co_B.motor_state_m = 3U;

      /* Outport: '<Root>/inner_rot_count_load' */
      bldc_motor_controller_full_co_Y.inner_rot_count_load = false;

      /* During 'trig_idle': '<S5>:1' */
      /* '<S5>:24:1' sf_internal_predicateOutput = ... */
      /* '<S5>:24:1' halt_motor_req == 1; */
      if (bldc_motor_controller_full_co_U.halt_motor_req) {
        /* Transition: '<S5>:24' */
        bldc_motor_controller_full_c_DW.is_c1_bldc_motor_controller_ful =
          bldc_motor_contro_IN_halt_motor;

        /* Entry 'halt_motor': '<S5>:23' */
        /* '<S5>:23:1' motor_state = 1; */
        bldc_motor_controller_full_co_B.motor_state_m = 1U;
      } else {
        /* '<S5>:25:1' sf_internal_predicateOutput = ... */
        /* '<S5>:25:1' hallEffectTrig; */
        if (bldc_motor_controller_full_co_U.inner_hall_effect_trig) {
          /* Transition: '<S5>:25' */
          bldc_motor_controller_full_c_DW.is_c1_bldc_motor_controller_ful =
            bldc_motor_IN_interrupt_trigger;

          /* Outputs for Function Call SubSystem: '<S1>/Motor Count Condition' */
          /* Entry 'interrupt_trigger': '<S5>:5' */
          /* '<S5>:5:1' trigOut; */
          /* Event: '<S5>:9' */
          bldc_motor_controller_full_co_B.count_in_i =
            bldc_motor_controller_full_co_U.inner_rotation_count_in;

          /* End of Outputs for SubSystem: '<S1>/Motor Count Condition' */
        }
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Motor Controller' */

  /* Switch: '<S9>/Switch1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S13>/Constant'
   *  Constant: '<S9>/Fast Increment'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S13>/Compare'
   *  Switch: '<S9>/Switch3'
   *  Switch: '<S9>/Switch5'
   *  UnitDelay: '<S9>/X1'
   */
  if (bldc_motor_controller_full_co_B.motor_state_m ==
      bldc_motor_controller_full_co_P.HaltCompare_const_n) {
    /* Switch: '<S9>/Switch2' incorporates:
     *  Constant: '<S12>/Constant'
     *  Constant: '<S9>/Fast Decrement'
     *  Constant: '<S9>/Idle'
     *  RelationalOperator: '<S12>/Compare'
     *  Switch: '<S9>/Switch4'
     *  UnitDelay: '<S9>/X1'
     */
    if (bldc_motor_controller_full_c_DW.X_h <=
        bldc_motor_controller_full_co_P.Constant_Value_n) {
      tmp = bldc_motor_controller_full_co_P.Idle_Value_a;
    } else if (rtb_Compare) {
      /* Switch: '<S9>/Switch4' incorporates:
       *  Constant: '<S9>/Slow Decrement'
       */
      tmp = bldc_motor_controller_full_co_P.SlowDecrement_Value;
    } else {
      tmp = bldc_motor_controller_full_co_P.FastDecrement_Value;
    }

    /* End of Switch: '<S9>/Switch2' */
  } else if (bldc_motor_controller_full_c_DW.X_h >=
             bldc_motor_controller_full_co_P.HaltCompare_const) {
    /* Switch: '<S9>/Switch3' incorporates:
     *  Constant: '<S9>/Idle'
     */
    tmp = bldc_motor_controller_full_co_P.Idle_Value_a;
  } else if (rtb_Compare) {
    /* Switch: '<S9>/Switch5' incorporates:
     *  Constant: '<S9>/Slow Increment'
     *  Switch: '<S9>/Switch3'
     */
    tmp = bldc_motor_controller_full_co_P.SlowIncrement_Value;
  } else {
    tmp = bldc_motor_controller_full_co_P.FastIncrement_Value;
  }

  /* End of Switch: '<S9>/Switch1' */

  /* Sum: '<S9>/Sum' incorporates:
   *  UnitDelay: '<S9>/X'
   */
  rtb_Switch2_n = tmp + bldc_motor_controller_full_c_DW.X_e;

  /* Saturate: '<S7>/Saturation' */
  if (rtb_Switch2_n > bldc_motor_controller_full_co_P.Saturation_UpperSat_k) {
    rtb_Saturation_k = bldc_motor_controller_full_co_P.Saturation_UpperSat_k;
  } else if (rtb_Switch2_n <
             bldc_motor_controller_full_co_P.Saturation_LowerSat_f) {
    rtb_Saturation_k = bldc_motor_controller_full_co_P.Saturation_LowerSat_f;
  } else {
    rtb_Saturation_k = rtb_Switch2_n;
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Outport: '<Root>/inner_motor_pwm' incorporates:
   *  Constant: '<S2>/PWM Period us'
   *  Product: '<S2>/Divide'
   */
  bldc_motor_controller_full_co_Y.inner_motor_pwm = rtb_Saturation_k /
    bldc_motor_controller_full_co_P.PWMPeriodus_Value_j;

  /* Switch: '<S8>/Switch' incorporates:
   *  Inport: '<Root>/inner_rotation_count_in'
   */
  if (bldc_motor_controller_full_co_B.count_in_i != 0.0) {
    tmp = bldc_motor_controller_full_co_B.count_in_i;
  } else {
    tmp = bldc_motor_controller_full_co_U.inner_rotation_count_in;
  }

  /* End of Switch: '<S8>/Switch' */

  /* Outport: '<Root>/inner_ring_position_ratio' incorporates:
   *  Inport: '<Root>/inner_rotation_count_in'
   *  Product: '<S8>/Divide1'
   */
  bldc_motor_controller_full_co_Y.inner_ring_position_ratio = (real32_T)
    (bldc_motor_controller_full_co_U.inner_rotation_count_in / tmp);

  /* Outport: '<Root>/inner_motor_speed_flag' incorporates:
   *  Constant: '<S7>/Terminal'
   *  RelationalOperator: '<S7>/RelOpt'
   */
  bldc_motor_controller_full_co_Y.inner_motor_speed_flag =
    (bldc_motor_controller_full_co_P.Terminal_Value_f <= rtb_Saturation_k);

  /* Update for UnitDelay: '<S19>/X1' */
  bldc_motor_controller_full_c_DW.X = rtb_Sum;

  /* Update for UnitDelay: '<S3>/X' */
  bldc_motor_controller_full_c_DW.X_i = rtb_Saturation;

  /* Switch: '<S19>/Switch' */
  if (rtb_Compare_g) {
    /* Update for UnitDelay: '<S19>/X' incorporates:
     *  Constant: '<S19>/load_var'
     */
    bldc_motor_controller_full_c_DW.X_f =
      bldc_motor_controller_full_co_P.load_var_Value_b;
  } else {
    /* Update for UnitDelay: '<S19>/X' */
    bldc_motor_controller_full_c_DW.X_f = rtb_Sum;
  }

  /* End of Switch: '<S19>/Switch' */

  /* Update for UnitDelay: '<S9>/X1' */
  bldc_motor_controller_full_c_DW.X_h = rtb_Switch2_n;

  /* Update for UnitDelay: '<S1>/X' */
  bldc_motor_controller_full_c_DW.X_j = rtb_Saturation_k;

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S11>/Constant'
   *  RelationalOperator: '<S11>/Compare'
   */
  if (bldc_motor_controller_full_co_B.motor_state_m ==
      bldc_motor_controller_full_co_P.LoadCompare_const_n) {
    /* Update for UnitDelay: '<S9>/X' incorporates:
     *  Constant: '<S9>/load_var'
     */
    bldc_motor_controller_full_c_DW.X_e =
      bldc_motor_controller_full_co_P.load_var_Value;
  } else {
    /* Update for UnitDelay: '<S9>/X' */
    bldc_motor_controller_full_c_DW.X_e = rtb_Switch2_n;
  }

  /* End of Switch: '<S9>/Switch' */
}

/* Model initialize function */
void bldc_motor_controller_full_count_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(bldc_motor_controller_full_c_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &bldc_motor_controller_full_co_B), 0,
                sizeof(B_bldc_motor_controller_full__T));

  /* states (dwork) */
  (void) memset((void *)&bldc_motor_controller_full_c_DW, 0,
                sizeof(DW_bldc_motor_controller_full_T));

  /* external inputs */
  (void)memset((void *)&bldc_motor_controller_full_co_U, 0, sizeof
               (ExtU_bldc_motor_controller_fu_T));

  /* external outputs */
  (void) memset((void *)&bldc_motor_controller_full_co_Y, 0,
                sizeof(ExtY_bldc_motor_controller_fu_T));

  /* InitializeConditions for UnitDelay: '<S19>/X1' */
  bldc_motor_controller_full_c_DW.X =
    bldc_motor_controller_full_co_P.X1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S3>/X' */
  bldc_motor_controller_full_c_DW.X_i =
    bldc_motor_controller_full_co_P.X_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S19>/X' */
  bldc_motor_controller_full_c_DW.X_f =
    bldc_motor_controller_full_co_P.X_InitialCondition_e;

  /* InitializeConditions for UnitDelay: '<S9>/X1' */
  bldc_motor_controller_full_c_DW.X_h =
    bldc_motor_controller_full_co_P.X1_InitialCondition_l;

  /* InitializeConditions for UnitDelay: '<S1>/X' */
  bldc_motor_controller_full_c_DW.X_j =
    bldc_motor_controller_full_co_P.X_InitialCondition_ey;

  /* InitializeConditions for UnitDelay: '<S9>/X' */
  bldc_motor_controller_full_c_DW.X_e =
    bldc_motor_controller_full_co_P.X_InitialCondition_c;
  bldc_motor_controller_full_c_DW.is_active_c2_bldc_motor_control = 0U;
  bldc_motor_controller_full_c_DW.is_c2_bldc_motor_controller_ful =
    bldc_motor_c_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<S3>/Motor Controller' incorporates:
   *  SystemInitialize for SubSystem: '<S3>/Motor Count Condition'
   */
  /* SystemInitialize for Outport: '<S16>/count_out' */
  bldc_motor_controller_full_co_B.count_in =
    bldc_motor_controller_full_co_P.count_out_Y0_c;
  bldc_motor_controller_full_c_DW.is_active_c1_bldc_motor_control = 0U;
  bldc_motor_controller_full_c_DW.is_c1_bldc_motor_controller_ful =
    bldc_motor_c_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<S1>/Motor Controller' incorporates:
   *  SystemInitialize for SubSystem: '<S1>/Motor Count Condition'
   */
  /* SystemInitialize for Outport: '<S6>/count_out' */
  bldc_motor_controller_full_co_B.count_in_i =
    bldc_motor_controller_full_co_P.count_out_Y0;
}

/* Model terminate function */
void bldc_motor_controller_full_count_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
