/*
 * File: bldc_motor_controller_full_count.c
 *
 * Code generated for Simulink model 'bldc_motor_controller_full_count'.
 *
 * Model version                  : 1.100
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sun Dec 10 16:52:45 2017
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
  real_T rtb_Sum;
  real_T rtb_Saturation;
  real_T rtb_Switch_p;

  /* Chart: '<S1>/Motor Controller' incorporates:
   *  Inport: '<Root>/arm_motor_req'
   *  Inport: '<Root>/hall_effect_trig'
   *  Inport: '<Root>/halt_motor_req'
   *  UnitDelay: '<S1>/X'
   */
  /* Gateway: Outer Motor Controller/Motor Controller */
  /* During: Outer Motor Controller/Motor Controller */
  if (bldc_motor_controller_full_c_DW.is_active_c3_bldc_motor_control == 0U) {
    /* Entry: Outer Motor Controller/Motor Controller */
    bldc_motor_controller_full_c_DW.is_active_c3_bldc_motor_control = 1U;

    /* Entry Internal: Outer Motor Controller/Motor Controller */
    /* Transition: '<S3>:16' */
    bldc_motor_controller_full_c_DW.is_c3_bldc_motor_controller_ful =
      bldc_motor_controller_f_IN_idle;

    /* Outport: '<Root>/rot_count_load' */
    /* Entry 'idle': '<S3>:15' */
    /* '<S3>:15:1' count_load = true; */
    bldc_motor_controller_full_co_Y.rot_count_load = true;

    /* '<S3>:15:1' motor_state = 0; */
    bldc_motor_controller_full_co_B.motor_state = 0U;
  } else {
    switch (bldc_motor_controller_full_c_DW.is_c3_bldc_motor_controller_ful) {
     case bldc_motor_control_IN_arm_motor:
      bldc_motor_controller_full_co_B.motor_state = 2U;

      /* During 'arm_motor': '<S3>:18' */
      /* '<S3>:17:1' sf_internal_predicateOutput = ... */
      /* '<S3>:17:1' hallEffectTrig; */
      if (bldc_motor_controller_full_co_U.hall_effect_trig) {
        /* Transition: '<S3>:17' */
        bldc_motor_controller_full_c_DW.is_c3_bldc_motor_controller_ful =
          bldc_motor_control_IN_trig_idle;

        /* Entry 'trig_idle': '<S3>:1' */
        /* '<S3>:1:1' motor_state = 3; */
        bldc_motor_controller_full_co_B.motor_state = 3U;

        /* Outport: '<Root>/rot_count_load' */
        /* '<S3>:1:1' count_load = false; */
        bldc_motor_controller_full_co_Y.rot_count_load = false;
      }
      break;

     case bldc_motor_controller_f_IN_idle:
      bldc_motor_controller_full_co_B.motor_state = 0U;

      /* Outport: '<Root>/rot_count_load' */
      bldc_motor_controller_full_co_Y.rot_count_load = true;

      /* During 'idle': '<S3>:15' */
      /* '<S3>:19:1' sf_internal_predicateOutput = ... */
      /* '<S3>:19:1' arm_motor_req == 1; */
      if (bldc_motor_controller_full_co_U.arm_motor_req) {
        /* Transition: '<S3>:19' */
        bldc_motor_controller_full_c_DW.is_c3_bldc_motor_controller_ful =
          bldc_motor_control_IN_arm_motor;

        /* Entry 'arm_motor': '<S3>:18' */
        /* '<S3>:18:1' motor_state = 2; */
        bldc_motor_controller_full_co_B.motor_state = 2U;
      }
      break;

     case bldc_motor_contro_IN_halt_motor:
      bldc_motor_controller_full_co_B.motor_state = 1U;

      /* During 'halt_motor': '<S3>:23' */
      /* '<S3>:26:1' sf_internal_predicateOutput = ... */
      /* '<S3>:26:1' halt_motor_req == 0 && count_in <= 1060; */
      if ((!bldc_motor_controller_full_co_U.halt_motor_req) &&
          (bldc_motor_controller_full_c_DW.X <= 1060.0)) {
        /* Transition: '<S3>:26' */
        bldc_motor_controller_full_c_DW.is_c3_bldc_motor_controller_ful =
          bldc_motor_controller_f_IN_idle;

        /* Outport: '<Root>/rot_count_load' */
        /* Entry 'idle': '<S3>:15' */
        /* '<S3>:15:1' count_load = true; */
        bldc_motor_controller_full_co_Y.rot_count_load = true;

        /* '<S3>:15:1' motor_state = 0; */
        bldc_motor_controller_full_co_B.motor_state = 0U;
      }
      break;

     case bldc_motor_IN_interrupt_trigger:
      /* During 'interrupt_trigger': '<S3>:5' */
      /* Transition: '<S3>:11' */
      bldc_motor_controller_full_c_DW.is_c3_bldc_motor_controller_ful =
        bldc_motor_c_IN_speed_calc_done;

      /* Outport: '<Root>/rot_count_load' */
      /* Entry 'speed_calc_done': '<S3>:10' */
      /* '<S3>:10:1' count_load = true; */
      bldc_motor_controller_full_co_Y.rot_count_load = true;
      break;

     case bldc_motor_c_IN_speed_calc_done:
      /* During 'speed_calc_done': '<S3>:10' */
      /* Transition: '<S3>:7' */
      bldc_motor_controller_full_c_DW.is_c3_bldc_motor_controller_ful =
        bldc_motor_control_IN_trig_idle;

      /* Entry 'trig_idle': '<S3>:1' */
      /* '<S3>:1:1' motor_state = 3; */
      bldc_motor_controller_full_co_B.motor_state = 3U;

      /* Outport: '<Root>/rot_count_load' */
      /* '<S3>:1:1' count_load = false; */
      bldc_motor_controller_full_co_Y.rot_count_load = false;
      break;

     default:
      bldc_motor_controller_full_co_B.motor_state = 3U;

      /* Outport: '<Root>/rot_count_load' */
      bldc_motor_controller_full_co_Y.rot_count_load = false;

      /* During 'trig_idle': '<S3>:1' */
      /* '<S3>:24:1' sf_internal_predicateOutput = ... */
      /* '<S3>:24:1' halt_motor_req == 1; */
      if (bldc_motor_controller_full_co_U.halt_motor_req) {
        /* Transition: '<S3>:24' */
        bldc_motor_controller_full_c_DW.is_c3_bldc_motor_controller_ful =
          bldc_motor_contro_IN_halt_motor;

        /* Entry 'halt_motor': '<S3>:23' */
        /* '<S3>:23:1' motor_state = 1; */
        bldc_motor_controller_full_co_B.motor_state = 1U;
      } else {
        /* '<S3>:25:1' sf_internal_predicateOutput = ... */
        /* '<S3>:25:1' hallEffectTrig; */
        if (bldc_motor_controller_full_co_U.hall_effect_trig) {
          /* Transition: '<S3>:25' */
          bldc_motor_controller_full_c_DW.is_c3_bldc_motor_controller_ful =
            bldc_motor_IN_interrupt_trigger;

          /* Outputs for Function Call SubSystem: '<S1>/Motor Count Condition' */
          /* Outport: '<Root>/prev_frame_speed' incorporates:
           *  Inport: '<Root>/rotation_count_in'
           *  Inport: '<S4>/count_in'
           */
          /* Entry 'interrupt_trigger': '<S3>:5' */
          /* '<S3>:5:1' trigOut; */
          /* Event: '<S3>:9' */
          bldc_motor_controller_full_co_Y.prev_frame_speed =
            bldc_motor_controller_full_co_U.rotation_count_in;

          /* End of Outputs for SubSystem: '<S1>/Motor Count Condition' */
        }
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Motor Controller' */

  /* Switch: '<S7>/Switch2' incorporates:
   *  Constant: '<S7>/Increment'
   *  Constant: '<S7>/zero'
   *  Constant: '<S8>/Constant'
   *  RelationalOperator: '<S8>/Compare'
   *  Switch: '<S7>/Switch1'
   *  UnitDelay: '<S7>/X1'
   */
  if (bldc_motor_controller_full_c_DW.X_o) {
    rtb_Sum = bldc_motor_controller_full_co_P.zero_Value;
  } else if (bldc_motor_controller_full_co_B.motor_state ==
             bldc_motor_controller_full_co_P.HaltCompare_const) {
    /* Switch: '<S7>/Switch1' incorporates:
     *  Constant: '<S7>/Decrement'
     */
    rtb_Sum = bldc_motor_controller_full_co_P.Decrement_Value;
  } else {
    rtb_Sum = bldc_motor_controller_full_co_P.Increment_Value;
  }

  /* End of Switch: '<S7>/Switch2' */

  /* Sum: '<S7>/Sum' incorporates:
   *  UnitDelay: '<S7>/X'
   */
  rtb_Sum += bldc_motor_controller_full_c_DW.X_m;

  /* Saturate: '<S5>/Saturation' */
  if (rtb_Sum > bldc_motor_controller_full_co_P.Saturation_UpperSat) {
    rtb_Saturation = bldc_motor_controller_full_co_P.Saturation_UpperSat;
  } else if (rtb_Sum < bldc_motor_controller_full_co_P.Saturation_LowerSat) {
    rtb_Saturation = bldc_motor_controller_full_co_P.Saturation_LowerSat;
  } else {
    rtb_Saturation = rtb_Sum;
  }

  /* End of Saturate: '<S5>/Saturation' */

  /* Outport: '<Root>/outer_motor_pwm' incorporates:
   *  Constant: '<S2>/PWM Period us'
   *  Product: '<S2>/Divide'
   */
  bldc_motor_controller_full_co_Y.outer_motor_pwm = rtb_Saturation /
    bldc_motor_controller_full_co_P.PWMPeriodus_Value;

  /* Product: '<S6>/Divide' incorporates:
   *  Constant: '<S6>/Clock Period Const'
   *  Outport: '<Root>/prev_frame_speed'
   */
  rtb_Switch_p = bldc_motor_controller_full_co_Y.prev_frame_speed /
    bldc_motor_controller_full_co_P.ClockPeriodConst_Value;

  /* Switch: '<S6>/Switch' incorporates:
   *  Inport: '<Root>/rotation_count_in'
   */
  if (!(rtb_Switch_p != 0.0)) {
    rtb_Switch_p = bldc_motor_controller_full_co_U.rotation_count_in;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Outport: '<Root>/ring_position_ratio' incorporates:
   *  Inport: '<Root>/rotation_count_in'
   *  Product: '<S6>/Divide1'
   */
  bldc_motor_controller_full_co_Y.ring_position_ratio = (real32_T)
    (bldc_motor_controller_full_co_U.rotation_count_in / rtb_Switch_p);

  /* Outport: '<Root>/motor_speed_flag' incorporates:
   *  Constant: '<S5>/Terminal'
   *  RelationalOperator: '<S5>/RelOpt'
   */
  bldc_motor_controller_full_co_Y.motor_speed_flag =
    (bldc_motor_controller_full_co_P.Terminal_Value <= rtb_Saturation);

  /* Update for UnitDelay: '<S7>/X1' incorporates:
   *  Constant: '<S10>/Constant'
   *  RelationalOperator: '<S10>/Compare'
   */
  bldc_motor_controller_full_c_DW.X_o = (rtb_Sum >=
    bldc_motor_controller_full_co_P.Compare_const);

  /* Update for UnitDelay: '<S1>/X' */
  bldc_motor_controller_full_c_DW.X = rtb_Saturation;

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S9>/Constant'
   *  RelationalOperator: '<S9>/Compare'
   */
  if (bldc_motor_controller_full_co_B.motor_state ==
      bldc_motor_controller_full_co_P.LoadCompare_const) {
    /* Update for UnitDelay: '<S7>/X' incorporates:
     *  Constant: '<S7>/load_var'
     */
    bldc_motor_controller_full_c_DW.X_m =
      bldc_motor_controller_full_co_P.load_var_Value;
  } else {
    /* Update for UnitDelay: '<S7>/X' */
    bldc_motor_controller_full_c_DW.X_m = rtb_Sum;
  }

  /* End of Switch: '<S7>/Switch' */
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

  /* InitializeConditions for UnitDelay: '<S7>/X1' */
  bldc_motor_controller_full_c_DW.X_o =
    bldc_motor_controller_full_co_P.X1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S1>/X' */
  bldc_motor_controller_full_c_DW.X =
    bldc_motor_controller_full_co_P.X_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S7>/X' */
  bldc_motor_controller_full_c_DW.X_m =
    bldc_motor_controller_full_co_P.X_InitialCondition_d;
  bldc_motor_controller_full_c_DW.is_active_c3_bldc_motor_control = 0U;
  bldc_motor_controller_full_c_DW.is_c3_bldc_motor_controller_ful =
    bldc_motor_c_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<S1>/Motor Controller' incorporates:
   *  SystemInitialize for SubSystem: '<S1>/Motor Count Condition'
   */
  /* SystemInitialize for Outport: '<Root>/prev_frame_speed' incorporates:
   *  SystemInitialize for Outport: '<S4>/count_out'
   */
  bldc_motor_controller_full_co_Y.prev_frame_speed =
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
