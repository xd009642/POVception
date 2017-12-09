/*
 * File: bldc_motor_controller_second.c
 *
 * Code generated for Simulink model 'bldc_motor_controller_second'.
 *
 * Model version                  : 1.59
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sat Dec 09 16:29:33 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "bldc_motor_controller_second.h"
#include "bldc_motor_controller_second_private.h"

/* Named constants for Chart: '<Root>/Motor Controller' */
#define bldc_motor_c_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define bldc_motor_contro_IN_halt_motor ((uint8_T)3U)
#define bldc_motor_control_IN_arm_motor ((uint8_T)1U)
#define bldc_motor_controller_s_IN_idle ((uint8_T)2U)

/* Block states (auto storage) */
DW_bldc_motor_controller_seco_T bldc_motor_controller_second_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_bldc_motor_controller_se_T bldc_motor_controller_second_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_bldc_motor_controller_se_T bldc_motor_controller_second_Y;

/* Real-time model */
RT_MODEL_bldc_motor_controlle_T bldc_motor_controller_second_M_;
RT_MODEL_bldc_motor_controlle_T *const bldc_motor_controller_second_M =
  &bldc_motor_controller_second_M_;

/* Model step function */
void bldc_motor_controller_second_step(void)
{
  real_T rtb_motor_state;
  int32_T rtb_motor_idle;
  real_T rtb_motor_state_0;

  /* Chart: '<Root>/Motor Controller' incorporates:
   *  Inport: '<Root>/arm_motor_req'
   *  Inport: '<Root>/halt_motor_req'
   *  UnitDelay: '<Root>/X'
   */
  /* Gateway: Motor Controller */
  /* During: Motor Controller */
  if (bldc_motor_controller_second_DW.is_active_c3_bldc_motor_control == 0U) {
    /* Entry: Motor Controller */
    bldc_motor_controller_second_DW.is_active_c3_bldc_motor_control = 1U;

    /* Entry Internal: Motor Controller */
    /* Transition: '<S2>:16' */
    bldc_motor_controller_second_DW.is_c3_bldc_motor_controller_sec =
      bldc_motor_controller_s_IN_idle;

    /* Entry 'idle': '<S2>:15' */
    /* '<S2>:15:1' motor_state = 0; */
    rtb_motor_state = 0.0;

    /* '<S2>:15:1' motor_idle = 1; */
    rtb_motor_idle = 1;
  } else {
    switch (bldc_motor_controller_second_DW.is_c3_bldc_motor_controller_sec) {
     case bldc_motor_control_IN_arm_motor:
      rtb_motor_idle = 0;
      rtb_motor_state = 1.0;

      /* During 'arm_motor': '<S2>:18' */
      /* '<S2>:24:1' sf_internal_predicateOutput = ... */
      /* '<S2>:24:1' halt_motor_req == 1; */
      if (bldc_motor_controller_second_U.halt_motor_req == 1.0) {
        /* Transition: '<S2>:24' */
        bldc_motor_controller_second_DW.is_c3_bldc_motor_controller_sec =
          bldc_motor_contro_IN_halt_motor;

        /* Entry 'halt_motor': '<S2>:23' */
        /* '<S2>:23:1' motor_state = 0; */
        rtb_motor_state = 0.0;

        /* '<S2>:23:1' motor_idle = 0; */
      }
      break;

     case bldc_motor_controller_s_IN_idle:
      rtb_motor_idle = 1;
      rtb_motor_state = 0.0;

      /* During 'idle': '<S2>:15' */
      /* '<S2>:19:1' sf_internal_predicateOutput = ... */
      /* '<S2>:19:1' arm_motor_req == 1; */
      if (bldc_motor_controller_second_U.arm_motor_req == 1.0) {
        /* Transition: '<S2>:19' */
        bldc_motor_controller_second_DW.is_c3_bldc_motor_controller_sec =
          bldc_motor_control_IN_arm_motor;

        /* Entry 'arm_motor': '<S2>:18' */
        /* '<S2>:18:1' motor_state = 1; */
        rtb_motor_state = 1.0;

        /* '<S2>:18:1' motor_idle = 0; */
        rtb_motor_idle = 0;
      }
      break;

     default:
      rtb_motor_idle = 0;
      rtb_motor_state = 0.0;

      /* During 'halt_motor': '<S2>:23' */
      /* '<S2>:26:1' sf_internal_predicateOutput = ... */
      /* '<S2>:26:1' halt_motor_req == 0 && count_in <= 1060; */
      if ((bldc_motor_controller_second_U.halt_motor_req == 0.0) &&
          (bldc_motor_controller_second_DW.X <= 1060.0)) {
        /* Transition: '<S2>:26' */
        bldc_motor_controller_second_DW.is_c3_bldc_motor_controller_sec =
          bldc_motor_controller_s_IN_idle;

        /* Entry 'idle': '<S2>:15' */
        /* '<S2>:15:1' motor_state = 0; */
        /* '<S2>:15:1' motor_idle = 1; */
        rtb_motor_idle = 1;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Motor Controller' */

  /* Switch: '<S1>/Switch1' incorporates:
   *  Constant: '<S1>/Decrement'
   *  Constant: '<S1>/Increment'
   */
  if (rtb_motor_state != 0.0) {
    rtb_motor_state = bldc_motor_controller_second_P.Increment_Value;
  } else {
    rtb_motor_state = bldc_motor_controller_second_P.Decrement_Value;
  }

  /* End of Switch: '<S1>/Switch1' */

  /* Sum: '<S1>/Sum' incorporates:
   *  UnitDelay: '<S1>/X'
   */
  rtb_motor_state += bldc_motor_controller_second_DW.X_l;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_motor_state > bldc_motor_controller_second_P.Saturation_UpperSat) {
    rtb_motor_state_0 = bldc_motor_controller_second_P.Saturation_UpperSat;
  } else if (rtb_motor_state <
             bldc_motor_controller_second_P.Saturation_LowerSat) {
    rtb_motor_state_0 = bldc_motor_controller_second_P.Saturation_LowerSat;
  } else {
    rtb_motor_state_0 = rtb_motor_state;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Outport: '<Root>/motor_pwm' incorporates:
   *  Constant: '<S3>/PWM Period us'
   *  Product: '<S3>/Divide'
   */
  bldc_motor_controller_second_Y.motor_pwm = rtb_motor_state_0 /
    bldc_motor_controller_second_P.PWMPeriodus_Value;

  /* Update for UnitDelay: '<Root>/X' */
  bldc_motor_controller_second_DW.X = rtb_motor_state;

  /* Switch: '<S1>/Switch' */
  if (rtb_motor_idle != 0) {
    /* Update for UnitDelay: '<S1>/X' incorporates:
     *  Constant: '<S1>/load_var'
     */
    bldc_motor_controller_second_DW.X_l =
      bldc_motor_controller_second_P.load_var_Value;
  } else {
    /* Update for UnitDelay: '<S1>/X' */
    bldc_motor_controller_second_DW.X_l = rtb_motor_state;
  }

  /* End of Switch: '<S1>/Switch' */
}

/* Model initialize function */
void bldc_motor_controller_second_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(bldc_motor_controller_second_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&bldc_motor_controller_second_DW, 0,
                sizeof(DW_bldc_motor_controller_seco_T));

  /* external inputs */
  (void)memset((void *)&bldc_motor_controller_second_U, 0, sizeof
               (ExtU_bldc_motor_controller_se_T));

  /* external outputs */
  bldc_motor_controller_second_Y.motor_pwm = 0.0;

  /* InitializeConditions for UnitDelay: '<Root>/X' */
  bldc_motor_controller_second_DW.X =
    bldc_motor_controller_second_P.X_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S1>/X' */
  bldc_motor_controller_second_DW.X_l =
    bldc_motor_controller_second_P.X_InitialCondition_l;

  /* SystemInitialize for Chart: '<Root>/Motor Controller' */
  bldc_motor_controller_second_DW.is_active_c3_bldc_motor_control = 0U;
  bldc_motor_controller_second_DW.is_c3_bldc_motor_controller_sec =
    bldc_motor_c_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void bldc_motor_controller_second_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
