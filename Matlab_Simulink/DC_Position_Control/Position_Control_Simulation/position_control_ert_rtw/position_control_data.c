/*
 * File: position_control_data.c
 *
 * Code generated for Simulink model 'position_control'.
 *
 * Model version                  : 2.88
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu May 25 11:35:04 2023
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
  0.27328994464795386,

  /* Variable: kp4
   * Referenced by: '<Root>/Gain6'
   */
  7.3722535208884086,

  /* Expression: 0.01
   * Referenced by: '<S1>/Encoder'
   */
  0.01,

  /* Expression: pi
   * Referenced by: '<Root>/Constant5'
   */
  3.1415926535897931,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S1>/Gain'
   */
  -1799071694
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
