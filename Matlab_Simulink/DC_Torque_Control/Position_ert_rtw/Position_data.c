/*
 * File: Position_data.c
 *
 * Code generated for Simulink model 'Position'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Aug 25 12:50:48 2022
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
   * Referenced by: '<Root>/Gain5'
   */
  24.43,

  /* Variable: b
   * Referenced by:
   *   '<Root>/Gain5'
   *   '<Root>/Gain8'
   */
  40.34,

  /* Variable: k1
   * Referenced by: '<Root>/Gain6'
   */
  3.9145679330051988,

  /* Variable: k2
   * Referenced by: '<Root>/Gain7'
   */
  0.017420456834862298,

  /* Expression: -1
   * Referenced by: '<S1>/Encoder1'
   */
  -1.0,

  /* Expression: -(2*pi)/(14*4*370)
   * Referenced by: '<S1>/Gain2'
   */
  -0.00030324253413028889,

  /* Expression: 180/pi
   * Referenced by: '<S3>/Gain'
   */
  57.295779513082323,

  /* Expression: 20
   * Referenced by: '<Root>/Constant2'
   */
  20.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
