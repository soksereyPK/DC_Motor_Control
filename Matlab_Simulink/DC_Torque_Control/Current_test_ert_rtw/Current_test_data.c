/*
 * File: Current_test_data.c
 *
 * Code generated for Simulink model 'Current_test'.
 *
 * Model version                  : 1.39
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Aug 24 13:41:38 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Current_test.h"

/* Block parameters (default storage) */
P_Current_test_T Current_test_P = {
  /* Variable: a
   * Referenced by: '<Root>/Gain11'
   */
  24.43,

  /* Variable: b
   * Referenced by:
   *   '<Root>/Gain11'
   *   '<Root>/Gain12'
   */
  40.34,

  /* Variable: kd4
   * Referenced by: '<Root>/Gain10'
   */
  0.017420456834862298,

  /* Variable: kp4
   * Referenced by: '<Root>/Gain9'
   */
  3.9145679330051988,

  /* Expression: -1
   * Referenced by: '<S1>/Encoder1'
   */
  -1.0,

  /* Expression: (2*pi)/(11*4*370)
   * Referenced by: '<S1>/Gain2'
   */
  0.00038594504343854953,

  /* Expression: 50
   * Referenced by: '<Root>/Constant5'
   */
  50.0,

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
