/*
 * File: position_control_data.c
 *
 * Code generated for Simulink model 'position_control'.
 *
 * Model version                  : 2.47
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Apr 26 12:52:06 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "position_control.h"

/* Block parameters (default storage) */
P_position_control_T position_control_P = {
  /* Variable: a
   * Referenced by: '<Root>/Gain8'
   */
  26.85,

  /* Variable: b
   * Referenced by:
   *   '<Root>/Gain8'
   *   '<Root>/Gain9'
   */
  85.68,

  /* Variable: kd4
   * Referenced by: '<Root>/Gain7'
   */
  -0.16670902644305355,

  /* Variable: kp4
   * Referenced by: '<Root>/Gain6'
   */
  0.46076584505552554,

  /* Expression: 0.01
   * Referenced by: '<S1>/Encoder'
   */
  0.01,

  /* Expression: 30
   * Referenced by: '<Root>/Constant5'
   */
  30.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S3>/Gain'
   */
  { { 0x70698F08UL, 0x7297UL } },

  /* Computed Parameter: Gain_Gain_j
   * Referenced by: '<S1>/Gain'
   */
  -1799071694
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
