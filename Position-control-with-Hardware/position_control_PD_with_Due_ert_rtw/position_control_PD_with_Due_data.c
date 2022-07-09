/*
 * File: position_control_PD_with_Due_data.c
 *
 * Code generated for Simulink model 'position_control_PD_with_Due'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Jul  9 09:27:34 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "position_control_PD_with_Due.h"
#include "position_control_PD_with_Due_private.h"

/* Block parameters (default storage) */
P_position_control_PD_with_Du_T position_control_PD_with_Due_P = {
  /* Variable: kd2
   * Referenced by: '<Root>/Gain2'
   */
  -0.020042702746051078,

  /* Variable: kp2
   * Referenced by: '<Root>/Gain1'
   */
  1.8430633802221021,

  /* Expression: 100*2
   * Referenced by: '<S1>/totalPPR'
   */
  200.0,

  /* Expression: 19.3*3.75
   * Referenced by: '<S1>/gearRatio'
   */
  72.375,

  /* Expression: 30
   * Referenced by: '<Root>/Constant3'
   */
  30.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
