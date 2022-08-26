/*
 * File: Position_data.c
 *
 * Code generated for Simulink model 'Position'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Aug 26 11:18:31 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Position.h"

/* Block parameters (default storage) */
P_Position_T Position_P = {
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

  /* Expression: 0.1
   * Referenced by: '<Root>/Current Reg read'
   */
  0.1,

  /* Expression: hex2dec("399F")
   * Referenced by: '<S4>/Constant3'
   */
  14751.0,

  /* Expression: hex2dec("0x2800")
   * Referenced by: '<S5>/Constant2'
   */
  10240.0,

  /* Expression: -1
   * Referenced by: '<S3>/Encoder1'
   */
  -1.0,

  /* Expression: hex2dec("2800")
   * Referenced by: '<S1>/Constant2'
   */
  10240.0,

  /* Expression: -(2*pi)/(14*4*370)
   * Referenced by: '<S3>/Gain2'
   */
  -0.00030324253413028889,

  /* Expression: 180/pi
   * Referenced by: '<S7>/Gain'
   */
  57.295779513082323,

  /* Expression: 360
   * Referenced by: '<Root>/Constant5'
   */
  360.0,

  /* Expression: 0.001
   * Referenced by: '<Root>/Gain1'
   */
  0.001,

  /* Computed Parameter: Gain_Gain_j
   * Referenced by: '<Root>/Gain'
   */
  20972
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
