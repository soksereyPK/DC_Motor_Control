/*
 * File: Current_test_data.c
 *
 * Code generated for Simulink model 'Current_test'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Aug 16 09:43:42 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Current_test.h"

/* Block parameters (default storage) */
P_Current_test_T Current_test_P = {
  /* Variable: D
   * Referenced by:
   *   '<Root>/Gain17'
   *   '<Root>/Gain21'
   */
  4.7E-6,

  /* Variable: J
   * Referenced by:
   *   '<Root>/Gain13'
   *   '<Root>/Gain17'
   */
  9.7E-6,

  /* Variable: Kt
   * Referenced by:
   *   '<Root>/Gain13'
   *   '<Root>/Gain17'
   *   '<Root>/Gain19'
   *   '<Root>/Gain23'
   */
  0.05,

  /* Variable: R
   * Referenced by:
   *   '<Root>/Gain13'
   *   '<Root>/Gain17'
   */
  14.3,

  /* Variable: Tc
   * Referenced by: '<Root>/Constant7'
   */
  0.00265,

  /* Variable: kii
   * Referenced by:
   *   '<Root>/Gain17'
   *   '<Root>/Gain21'
   *   '<Root>/Gain24'
   *   '<Root>/Ki_i2'
   */
  0.087618149841811807,

  /* Variable: kpi
   * Referenced by:
   *   '<Root>/Gain13'
   *   '<Root>/Gain17'
   *   '<Root>/Kp_i2'
   */
  0.0893784406784562,

  /* Variable: kpo
   * Referenced by: '<Root>/Kp_o1'
   */
  20.0,

  /* Expression: 0.1
   * Referenced by: '<S1>/Current Reg read1'
   */
  0.1,

  /* Expression: -1
   * Referenced by: '<S1>/Encoder2'
   */
  -1.0,

  /* Expression: hex2dec("399F")
   * Referenced by: '<S5>/Constant3'
   */
  14751.0,

  /* Expression: hex2dec("0x2800")
   * Referenced by: '<S6>/Constant2'
   */
  10240.0,

  /* Expression: (2*pi)/(11*4*19.2)
   * Referenced by: '<S1>/Gain22'
   */
  0.0074374826079303819,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant6'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator2'
   */
  0.0,

  /* Expression: hex2dec("2800")
   * Referenced by: '<S2>/Constant2'
   */
  10240.0,

  /* Expression: 0.001
   * Referenced by: '<S1>/Gain25'
   */
  0.001,

  /* Computed Parameter: Gain23_Gain
   * Referenced by: '<S1>/Gain23'
   */
  20972
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
