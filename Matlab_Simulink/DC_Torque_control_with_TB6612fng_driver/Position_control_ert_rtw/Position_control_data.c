/*
 * File: Position_control_data.c
 *
 * Code generated for Simulink model 'Position_control'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Sep  8 10:36:03 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Position_control.h"

/* Block parameters (default storage) */
P_Position_control_T Position_control_P = {
  /* Expression: -1
   * Referenced by: '<S3>/Encoder'
   */
  -1.0,

  /* Expression: [0;0;0;0]
   * Referenced by: '<S1>/Unit Delay2'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 12
   * Referenced by: '<Root>/uk2'
   */
  12.0,

  /* Expression: 0
   * Referenced by: '<Root>/uk2'
   */
  0.0,

  /* Expression: 2*pi*1.2
   * Referenced by: '<Root>/uk2'
   */
  7.5398223686155035,

  /* Expression: 0
   * Referenced by: '<Root>/uk2'
   */
  0.0,

  /* Expression: -(2*pi)/(11*4)
   * Referenced by: '<S3>/Gain'
   */
  -0.14279966607226333
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
