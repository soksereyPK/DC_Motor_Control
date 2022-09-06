/*
 * File: Torque_control_data.c
 *
 * Code generated for Simulink model 'Torque_control'.
 *
 * Model version                  : 1.154
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Sep  6 14:29:50 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Torque_control.h"

/* Block parameters (default storage) */
P_Torque_control_T Torque_control_P = {
  /* Variable: a
   * Referenced by: '<Root>/Gain11'
   */
  176.0,

  /* Variable: b
   * Referenced by:
   *   '<Root>/Gain11'
   *   '<Root>/Gain12'
   */
  140000.0,

  /* Variable: kd4
   * Referenced by: '<Root>/Gain10'
   */
  -0.0011673830670402914,

  /* Variable: kp4
   * Referenced by: '<Root>/Gain9'
   */
  0.00028198869717398168,

  /* Expression: 0.001
   * Referenced by: '<S1>/Encoder1'
   */
  0.001,

  /* Expression: -(2*pi)/(11*4)
   * Referenced by: '<S1>/Gain2'
   */
  -0.14279966607226333,

  /* Expression: 180/pi
   * Referenced by: '<S3>/Gain'
   */
  57.295779513082323,

  /* Expression: 50
   * Referenced by: '<Root>/Constant5'
   */
  50.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
