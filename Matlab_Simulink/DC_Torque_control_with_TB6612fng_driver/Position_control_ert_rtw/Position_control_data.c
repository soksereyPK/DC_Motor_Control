/*
 * File: position_control_data.c
 *
 * Code generated for Simulink model 'position_control'.
 *
 * Model version                  : 2.44
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Apr 26 12:25:19 2023
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

  /* Expression: -(2*pi)/(100*4*19.2)
   * Referenced by: '<S1>/Gain'
   */
  -0.00081812308687234192,

  /* Expression: 180/pi
   * Referenced by: '<S3>/Gain'
   */
  57.295779513082323
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
