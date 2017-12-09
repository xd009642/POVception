/*
 * File: motor_test.c
 *
 * Code generated for Simulink model 'motor_test'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sat Dec 09 15:02:08 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motor_test.h"
#include "motor_test_private.h"

/* Block states (auto storage) */
DW_motor_test_t motor_test_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_motor_test_t motor_test_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_motor_test_t motor_test_Y;

/* Real-time model */
RT_MODEL_motor_test_t motor_test_M_;
RT_MODEL_motor_test_t *const motor_test_M = &motor_test_M_;

/* Model step function */
void motor_test_step(void)
{
  float rtb_Sum;
  float rtb_Sum_0;

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Increment'
   *  UnitDelay: '<S1>/X'
   */
  rtb_Sum = motor_test_P.Increment_Value + motor_test_DW.X;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Sum > motor_test_P.Saturation_UpperSat) {
    rtb_Sum_0 = motor_test_P.Saturation_UpperSat;
  } else if (rtb_Sum < motor_test_P.Saturation_LowerSat) {
    rtb_Sum_0 = motor_test_P.Saturation_LowerSat;
  } else {
    rtb_Sum_0 = rtb_Sum;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Outport: '<Root>/motor_pwm' incorporates:
   *  Constant: '<S2>/PWM Period us'
   *  Product: '<S2>/Divide'
   */
  motor_test_Y.motor_pwm = rtb_Sum_0 / motor_test_P.PWMPeriodus_Value;

  /* Switch: '<S1>/Switch' incorporates:
   *  Inport: '<Root>/count_load'
   */
  if (motor_test_U.count_load != 0.0) {
    /* Update for UnitDelay: '<S1>/X' incorporates:
     *  Constant: '<S1>/Load'
     */
    motor_test_DW.X = motor_test_P.Load_Value;
  } else {
    /* Update for UnitDelay: '<S1>/X' */
    motor_test_DW.X = rtb_Sum;
  }

  /* End of Switch: '<S1>/Switch' */
}

/* Model initialize function */
void motor_test_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(motor_test_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&motor_test_DW, 0,
                sizeof(DW_motor_test_t));

  /* external inputs */
  motor_test_U.count_load = 0.0;

  /* external outputs */
  motor_test_Y.motor_pwm = 0.0;

  /* InitializeConditions for UnitDelay: '<S1>/X' */
  motor_test_DW.X = motor_test_P.X_InitialCondition;
}

/* Model terminate function */
void motor_test_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
