/*
 * File: position_control_data.c
 *
 * Code generated for Simulink model 'position_control'.
 *
 * Model version                  : 2.34
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Apr 22 18:03:52 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "position_control.h"

/* Block parameters (default storage) */
P_position_control_T position_control_P = {
  /* Variable: kd2
   * Referenced by: '<Root>/Gain10'
   */
  -0.16670902644305355,

  /* Variable: kp2
   * Referenced by: '<Root>/Gain5'
   */
  0.46076584505552554,

  /* Expression: 0.01
   * Referenced by: '<S1>/Encoder'
   */
  0.01,

  /* Expression: 50
   * Referenced by: '<Root>/Constant2'
   */
  50.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S3>/Gain'
   */
  { { 0xEE0D31E1UL, 0xE52UL } },

  /* Computed Parameter: Gain_Gain_j
   * Referenced by: '<S1>/Gain'
   */
  -2044399652
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
