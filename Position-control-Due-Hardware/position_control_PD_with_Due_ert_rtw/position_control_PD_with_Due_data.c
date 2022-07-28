/*
 * File: position_control_PD_with_Due_data.c
 *
 * Code generated for Simulink model 'position_control_PD_with_Due'.
 *
 * Model version                  : 2.5
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Jul 23 11:28:58 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "position_control_PD_with_Due.h"

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

  /* Expression: -1
   * Referenced by: '<S1>/Encoder'
   */
  -1.0,

  /* Expression: 30
   * Referenced by: '<Root>/Constant3'
   */
  30.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S1>/Gain'
   */
  1220698255
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
