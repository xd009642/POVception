/*
 * File: bldc_motor_controller_full_count.c
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

/*
 * System initialize for atomic system:
 *    '<S1>/Motor Controller'
 *    '<S3>/Motor Controller'
 */
void bldc_motor_MotorController_Init(real_T *rty_2,
  DW_MotorController_bldc_motor_T *localDW, P_MotorController_bldc_motor__T
  *localP)
{
  localDW->is_active_c3_bldc_motor_control = 0U;
  localDW->is_c3_bldc_motor_controller_ful = bldc_motor_c_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Function Call SubSystem: '<S1>/Motor Count Condition' */
  /* SystemInitialize for Outport: '<S6>/count_out' */
  *rty_2 = localP->count_out_Y0;

  /* End of SystemInitialize for SubSystem: '<S1>/Motor Count Condition' */
}

/*
 * Output and update for atomic system:
 *    '<S1>/Motor Controller'
 *    '<S3>/Motor Controller'
 */
void bldc_motor_cont_MotorController(real_T rtu_count_in, boolean_T
  rtu_hallEffectTrig, boolean_T rtu_arm_motor_req, boolean_T rtu_halt_motor_req,
  real_T rtu_4, uint8_T *rty_motor_state, boolean_T *rty_count_load, real_T
  *rty_2, DW_MotorController_bldc_motor_T *localDW)
{
  /* Gateway: Inner Motor Controller/Motor Controller */
  /* During: Inner Motor Controller/Motor Controller */
  if (localDW->is_active_c3_bldc_motor_control == 0U) {
    /* Entry: Inner Motor Controller/Motor Controller */
    localDW->is_active_c3_bldc_motor_control = 1U;

    /* Entry Internal: Inner Motor Controller/Motor Controller */
    /* Transition: '<S5>:16' */
    localDW->is_c3_bldc_motor_controller_ful = bldc_motor_controller_f_IN_idle;

    /* Entry 'idle': '<S5>:15' */
    /* '<S5>:15:1' count_load = true; */
    *rty_count_load = true;

    /* '<S5>:15:1' motor_state = 0; */
    *rty_motor_state = 0U;
  } else {
    switch (localDW->is_c3_bldc_motor_controller_ful) {
     case bldc_motor_control_IN_arm_motor:
      *rty_motor_state = 2U;

      /* During 'arm_motor': '<S5>:18' */
      /* '<S5>:17:1' sf_internal_predicateOutput = ... */
      /* '<S5>:17:1' hallEffectTrig; */
      if (rtu_hallEffectTrig) {
        /* Transition: '<S5>:17' */
        localDW->is_c3_bldc_motor_controller_ful =
          bldc_motor_control_IN_trig_idle;

        /* Entry 'trig_idle': '<S5>:1' */
        /* '<S5>:1:1' motor_state = 3; */
        *rty_motor_state = 3U;

        /* '<S5>:1:1' count_load = false; */
        *rty_count_load = false;
      }
      break;

     case bldc_motor_controller_f_IN_idle:
      *rty_motor_state = 0U;
      *rty_count_load = true;

      /* During 'idle': '<S5>:15' */
      /* '<S5>:19:1' sf_internal_predicateOutput = ... */
      /* '<S5>:19:1' arm_motor_req == 1; */
      if (rtu_arm_motor_req) {
        /* Transition: '<S5>:19' */
        localDW->is_c3_bldc_motor_controller_ful =
          bldc_motor_control_IN_arm_motor;

        /* Entry 'arm_motor': '<S5>:18' */
        /* '<S5>:18:1' motor_state = 2; */
        *rty_motor_state = 2U;
      }
      break;

     case bldc_motor_contro_IN_halt_motor:
      *rty_motor_state = 1U;

      /* During 'halt_motor': '<S5>:23' */
      /* '<S5>:26:1' sf_internal_predicateOutput = ... */
      /* '<S5>:26:1' halt_motor_req == 0 && count_in <= 0; */
      if ((!rtu_halt_motor_req) && (rtu_count_in <= 0.0)) {
        /* Transition: '<S5>:26' */
        localDW->is_c3_bldc_motor_controller_ful =
          bldc_motor_controller_f_IN_idle;

        /* Entry 'idle': '<S5>:15' */
        /* '<S5>:15:1' count_load = true; */
        *rty_count_load = true;

        /* '<S5>:15:1' motor_state = 0; */
        *rty_motor_state = 0U;
      }
      break;

     case bldc_motor_IN_interrupt_trigger:
      /* During 'interrupt_trigger': '<S5>:5' */
      /* Transition: '<S5>:11' */
      localDW->is_c3_bldc_motor_controller_ful = bldc_motor_c_IN_speed_calc_done;

      /* Entry 'speed_calc_done': '<S5>:10' */
      /* '<S5>:10:1' count_load = true; */
      *rty_count_load = true;
      break;

     case bldc_motor_c_IN_speed_calc_done:
      /* During 'speed_calc_done': '<S5>:10' */
      /* Transition: '<S5>:7' */
      localDW->is_c3_bldc_motor_controller_ful = bldc_motor_control_IN_trig_idle;

      /* Entry 'trig_idle': '<S5>:1' */
      /* '<S5>:1:1' motor_state = 3; */
      *rty_motor_state = 3U;

      /* '<S5>:1:1' count_load = false; */
      *rty_count_load = false;
      break;

     default:
      *rty_motor_state = 3U;
      *rty_count_load = false;

      /* During 'trig_idle': '<S5>:1' */
      /* '<S5>:24:1' sf_internal_predicateOutput = ... */
      /* '<S5>:24:1' halt_motor_req == 1; */
      if (rtu_halt_motor_req) {
        /* Transition: '<S5>:24' */
        localDW->is_c3_bldc_motor_controller_ful =
          bldc_motor_contro_IN_halt_motor;

        /* Entry 'halt_motor': '<S5>:23' */
        /* '<S5>:23:1' motor_state = 1; */
        *rty_motor_state = 1U;
      } else {
        /* '<S5>:25:1' sf_internal_predicateOutput = ... */
        /* '<S5>:25:1' hallEffectTrig; */
        if (rtu_hallEffectTrig) {
          /* Transition: '<S5>:25' */
          localDW->is_c3_bldc_motor_controller_ful =
            bldc_motor_IN_interrupt_trigger;

          /* Outputs for Function Call SubSystem: '<S1>/Motor Count Condition' */
          /* Inport: '<S6>/count_in' */
          /* Entry 'interrupt_trigger': '<S5>:5' */
          /* '<S5>:5:1' trigOut; */
          /* Event: '<S5>:9' */
          *rty_2 = rtu_4;

          /* End of Outputs for SubSystem: '<S1>/Motor Count Condition' */
        }
      }
      break;
    }
  }
}

/* Model step function */
void bldc_motor_controller_full_count_step(void)
{
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_g;
  real_T rtb_Sum;
  real_T rtb_Saturation;
  boolean_T rtb_Compare_c;
  real_T rtb_Saturation_k;
  real_T rtb_Switch3_b;
  real_T tmp;

  /* RelationalOperator: '<S25>/Compare' incorporates:
   *  Constant: '<S25>/Constant'
   *  UnitDelay: '<S20>/X1'
   */
  rtb_Compare = (bldc_motor_controller_full_c_DW.X >=
                 bldc_motor_controller_full_co_P.FastCompare_const);

  /* Chart: '<S3>/Motor Controller' incorporates:
   *  Inport: '<Root>/arm_motor_req'
   *  Inport: '<Root>/halt_motor_req'
   *  Inport: '<Root>/outer_hall_effect_trig'
   *  Inport: '<Root>/outer_rotation_count_in'
   *  Outport: '<Root>/outer_rot_count_load'
   *  UnitDelay: '<S3>/X'
   */
  bldc_motor_cont_MotorController(bldc_motor_controller_full_c_DW.X_i,
    bldc_motor_controller_full_co_U.outer_hall_effect_trig,
    bldc_motor_controller_full_co_U.arm_motor_req,
    bldc_motor_controller_full_co_U.halt_motor_req,
    bldc_motor_controller_full_co_U.outer_rotation_count_in,
    &bldc_motor_controller_full_co_B.motor_state,
    &bldc_motor_controller_full_co_Y.outer_rot_count_load,
    &bldc_motor_controller_full_co_B.count_in,
    &bldc_motor_controller_full_c_DW.sf_MotorController);

  /* RelationalOperator: '<S22>/Compare' incorporates:
   *  Constant: '<S22>/Constant'
   */
  rtb_Compare_g = (bldc_motor_controller_full_co_B.motor_state ==
                   bldc_motor_controller_full_co_P.LoadCompare_const);

  /* Switch: '<S20>/Switch1' incorporates:
   *  Constant: '<S21>/Constant'
   *  Constant: '<S23>/Fast Increment'
   *  Constant: '<S26>/Constant'
   *  Logic: '<S23>/Logical Operator'
   *  RelationalOperator: '<S21>/Compare'
   *  RelationalOperator: '<S26>/Compare'
   *  Switch: '<S23>/Switch1'
   *  Switch: '<S23>/Switch2'
   *  UnitDelay: '<S20>/X1'
   */
  if (bldc_motor_controller_full_co_B.motor_state ==
      bldc_motor_controller_full_co_P.HaltCompare_const) {
    /* Switch: '<S23>/Switch3' incorporates:
     *  Constant: '<S23>/Fast Decrement'
     *  Constant: '<S23>/Idle'
     *  Constant: '<S24>/Constant'
     *  RelationalOperator: '<S24>/Compare'
     *  Switch: '<S23>/Switch6'
     *  UnitDelay: '<S20>/X1'
     */
    if (bldc_motor_controller_full_c_DW.X <=
        bldc_motor_controller_full_co_P.Constant_Value) {
      tmp = bldc_motor_controller_full_co_P.Idle_Value;
    } else if (rtb_Compare) {
      /* Switch: '<S23>/Switch6' incorporates:
       *  Constant: '<S23>/Slow Decrement'
       */
      tmp = bldc_motor_controller_full_co_P.SlowDecrement_Value_p;
    } else {
      tmp = bldc_motor_controller_full_co_P.FastDecrement_Value_m;
    }

    /* End of Switch: '<S23>/Switch3' */
  } else if ((bldc_motor_controller_full_c_DW.X >=
              bldc_motor_controller_full_co_P.MaxPulseCompare_const) ||
             rtb_Compare_g) {
    /* Switch: '<S23>/Switch2' incorporates:
     *  Constant: '<S23>/Idle'
     */
    tmp = bldc_motor_controller_full_co_P.Idle_Value;
  } else if (rtb_Compare) {
    /* Switch: '<S23>/Switch1' incorporates:
     *  Constant: '<S23>/Slow Increment'
     *  Switch: '<S23>/Switch2'
     */
    tmp = bldc_motor_controller_full_co_P.SlowIncrement_Value_e;
  } else {
    tmp = bldc_motor_controller_full_co_P.FastIncrement_Value_g;
  }

  /* End of Switch: '<S20>/Switch1' */

  /* Sum: '<S20>/Sum' incorporates:
   *  UnitDelay: '<S20>/X'
   */
  rtb_Sum = tmp + bldc_motor_controller_full_c_DW.X_f;

  /* Saturate: '<S18>/Saturation' */
  if (rtb_Sum > bldc_motor_controller_full_co_P.Saturation_UpperSat) {
    rtb_Saturation = bldc_motor_controller_full_co_P.Saturation_UpperSat;
  } else if (rtb_Sum < bldc_motor_controller_full_co_P.Saturation_LowerSat) {
    rtb_Saturation = bldc_motor_controller_full_co_P.Saturation_LowerSat;
  } else {
    rtb_Saturation = rtb_Sum;
  }

  /* End of Saturate: '<S18>/Saturation' */

  /* Outport: '<Root>/outer_motor_pwm' incorporates:
   *  Constant: '<S4>/PWM Period us'
   *  Product: '<S4>/Divide'
   */
  bldc_motor_controller_full_co_Y.outer_motor_pwm = rtb_Saturation /
    bldc_motor_controller_full_co_P.PWMPeriodus_Value;

  /* Switch: '<S19>/Switch' incorporates:
   *  Inport: '<Root>/outer_rotation_count_in'
   */
  if (bldc_motor_controller_full_co_B.count_in != 0.0) {
    tmp = bldc_motor_controller_full_co_B.count_in;
  } else {
    tmp = bldc_motor_controller_full_co_U.outer_rotation_count_in;
  }

  /* End of Switch: '<S19>/Switch' */

  /* Outport: '<Root>/outer_ring_position_ratio' incorporates:
   *  Inport: '<Root>/outer_rotation_count_in'
   *  Product: '<S19>/Divide1'
   */
  bldc_motor_controller_full_co_Y.outer_ring_position_ratio = (real32_T)
    (bldc_motor_controller_full_co_U.outer_rotation_count_in / tmp);

  /* Outport: '<Root>/outer_motor_speed_flag' incorporates:
   *  Constant: '<S18>/Terminal'
   *  RelationalOperator: '<S18>/RelOpt'
   */
  bldc_motor_controller_full_co_Y.outer_motor_speed_flag =
    (bldc_motor_controller_full_co_P.Terminal_Value <= rtb_Saturation);

  /* RelationalOperator: '<S14>/Compare' incorporates:
   *  Constant: '<S14>/Constant'
   *  UnitDelay: '<S9>/X1'
   */
  rtb_Compare = (bldc_motor_controller_full_c_DW.X_d >=
                 bldc_motor_controller_full_co_P.FastCompare_const_c);

  /* Chart: '<S1>/Motor Controller' incorporates:
   *  Inport: '<Root>/arm_motor_req'
   *  Inport: '<Root>/halt_motor_req'
   *  Inport: '<Root>/inner_hall_effect_trig'
   *  Inport: '<Root>/inner_rotation_count_in'
   *  Outport: '<Root>/inner_rot_count_load'
   *  UnitDelay: '<S1>/X'
   */
  bldc_motor_cont_MotorController(bldc_motor_controller_full_c_DW.X_j,
    bldc_motor_controller_full_co_U.inner_hall_effect_trig,
    bldc_motor_controller_full_co_U.arm_motor_req,
    bldc_motor_controller_full_co_U.halt_motor_req,
    bldc_motor_controller_full_co_U.inner_rotation_count_in,
    &bldc_motor_controller_full_co_B.motor_state_i,
    &bldc_motor_controller_full_co_Y.inner_rot_count_load,
    &bldc_motor_controller_full_co_B.count_in_i,
    &bldc_motor_controller_full_c_DW.sf_MotorController_o);

  /* RelationalOperator: '<S11>/Compare' incorporates:
   *  Constant: '<S11>/Constant'
   */
  rtb_Compare_c = (bldc_motor_controller_full_co_B.motor_state_i ==
                   bldc_motor_controller_full_co_P.LoadCompare_const_n);

  /* Switch: '<S9>/Switch1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S12>/Fast Increment'
   *  Constant: '<S15>/Constant'
   *  Logic: '<S12>/Logical Operator'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S15>/Compare'
   *  Switch: '<S12>/Switch1'
   *  Switch: '<S12>/Switch2'
   *  UnitDelay: '<S9>/X1'
   */
  if (bldc_motor_controller_full_co_B.motor_state_i ==
      bldc_motor_controller_full_co_P.HaltCompare_const_n) {
    /* Switch: '<S12>/Switch3' incorporates:
     *  Constant: '<S12>/Fast Decrement'
     *  Constant: '<S12>/Idle'
     *  Constant: '<S13>/Constant'
     *  RelationalOperator: '<S13>/Compare'
     *  Switch: '<S12>/Switch6'
     *  UnitDelay: '<S9>/X1'
     */
    if (bldc_motor_controller_full_c_DW.X_d <=
        bldc_motor_controller_full_co_P.Constant_Value_o) {
      tmp = bldc_motor_controller_full_co_P.Idle_Value_i;
    } else if (rtb_Compare) {
      /* Switch: '<S12>/Switch6' incorporates:
       *  Constant: '<S12>/Slow Decrement'
       */
      tmp = bldc_motor_controller_full_co_P.SlowDecrement_Value;
    } else {
      tmp = bldc_motor_controller_full_co_P.FastDecrement_Value;
    }

    /* End of Switch: '<S12>/Switch3' */
  } else if ((bldc_motor_controller_full_c_DW.X_d >=
              bldc_motor_controller_full_co_P.MaxPulseCompare_const_p) ||
             rtb_Compare_c) {
    /* Switch: '<S12>/Switch2' incorporates:
     *  Constant: '<S12>/Idle'
     */
    tmp = bldc_motor_controller_full_co_P.Idle_Value_i;
  } else if (rtb_Compare) {
    /* Switch: '<S12>/Switch1' incorporates:
     *  Constant: '<S12>/Slow Increment'
     *  Switch: '<S12>/Switch2'
     */
    tmp = bldc_motor_controller_full_co_P.SlowIncrement_Value;
  } else {
    tmp = bldc_motor_controller_full_co_P.FastIncrement_Value;
  }

  /* End of Switch: '<S9>/Switch1' */

  /* Sum: '<S9>/Sum' incorporates:
   *  UnitDelay: '<S9>/X'
   */
  rtb_Switch3_b = tmp + bldc_motor_controller_full_c_DW.X_fo;

  /* Saturate: '<S7>/Saturation' */
  if (rtb_Switch3_b > bldc_motor_controller_full_co_P.Saturation_UpperSat_k) {
    rtb_Saturation_k = bldc_motor_controller_full_co_P.Saturation_UpperSat_k;
  } else if (rtb_Switch3_b <
             bldc_motor_controller_full_co_P.Saturation_LowerSat_f) {
    rtb_Saturation_k = bldc_motor_controller_full_co_P.Saturation_LowerSat_f;
  } else {
    rtb_Saturation_k = rtb_Switch3_b;
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

  /* Update for UnitDelay: '<S20>/X1' */
  bldc_motor_controller_full_c_DW.X = rtb_Sum;

  /* Update for UnitDelay: '<S3>/X' */
  bldc_motor_controller_full_c_DW.X_i = rtb_Saturation;

  /* Switch: '<S20>/Switch' */
  if (rtb_Compare_g) {
    /* Update for UnitDelay: '<S20>/X' incorporates:
     *  Constant: '<S20>/load_var'
     */
    bldc_motor_controller_full_c_DW.X_f =
      bldc_motor_controller_full_co_P.load_var_Value_b;
  } else {
    /* Update for UnitDelay: '<S20>/X' */
    bldc_motor_controller_full_c_DW.X_f = rtb_Sum;
  }

  /* End of Switch: '<S20>/Switch' */

  /* Update for UnitDelay: '<S9>/X1' */
  bldc_motor_controller_full_c_DW.X_d = rtb_Switch3_b;

  /* Update for UnitDelay: '<S1>/X' */
  bldc_motor_controller_full_c_DW.X_j = rtb_Saturation_k;

  /* Switch: '<S9>/Switch' */
  if (rtb_Compare_c) {
    /* Update for UnitDelay: '<S9>/X' incorporates:
     *  Constant: '<S9>/load_var'
     */
    bldc_motor_controller_full_c_DW.X_fo =
      bldc_motor_controller_full_co_P.load_var_Value;
  } else {
    /* Update for UnitDelay: '<S9>/X' */
    bldc_motor_controller_full_c_DW.X_fo = rtb_Switch3_b;
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

  /* InitializeConditions for UnitDelay: '<S20>/X1' */
  bldc_motor_controller_full_c_DW.X =
    bldc_motor_controller_full_co_P.X1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S3>/X' */
  bldc_motor_controller_full_c_DW.X_i =
    bldc_motor_controller_full_co_P.X_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S20>/X' */
  bldc_motor_controller_full_c_DW.X_f =
    bldc_motor_controller_full_co_P.X_InitialCondition_e;

  /* InitializeConditions for UnitDelay: '<S9>/X1' */
  bldc_motor_controller_full_c_DW.X_d =
    bldc_motor_controller_full_co_P.X1_InitialCondition_l;

  /* InitializeConditions for UnitDelay: '<S1>/X' */
  bldc_motor_controller_full_c_DW.X_j =
    bldc_motor_controller_full_co_P.X_InitialCondition_ey;

  /* InitializeConditions for UnitDelay: '<S9>/X' */
  bldc_motor_controller_full_c_DW.X_fo =
    bldc_motor_controller_full_co_P.X_InitialCondition_m;

  /* SystemInitialize for Chart: '<S3>/Motor Controller' */
  bldc_motor_MotorController_Init(&bldc_motor_controller_full_co_B.count_in,
    &bldc_motor_controller_full_c_DW.sf_MotorController,
    (P_MotorController_bldc_motor__T *)
    &bldc_motor_controller_full_co_P.sf_MotorController);

  /* SystemInitialize for Chart: '<S1>/Motor Controller' */
  bldc_motor_MotorController_Init(&bldc_motor_controller_full_co_B.count_in_i,
    &bldc_motor_controller_full_c_DW.sf_MotorController_o,
    (P_MotorController_bldc_motor__T *)
    &bldc_motor_controller_full_co_P.sf_MotorController_o);
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
