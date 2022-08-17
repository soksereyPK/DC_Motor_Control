/*
 * File: IMU_data.c
 *
 * Code generated for Simulink model 'IMU'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Aug 10 17:40:42 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "IMU.h"

/* Block parameters (default storage) */
P_IMU_T IMU_P = {
  /* Expression: 0.01
   * Referenced by: '<Root>/BNO055 IMU Sensor'
   */
  0.01,

  /* Expression: 0.1
   * Referenced by: '<Root>/Current Reg read'
   */
  0.1,

  /* Expression: hex2dec("399F")
   * Referenced by: '<S5>/Constant3'
   */
  14751.0,

  /* Expression: hex2dec("0x2800")
   * Referenced by: '<S6>/Constant2'
   */
  10240.0,

  /* Expression: -1
   * Referenced by: '<S4>/Encoder'
   */
  -1.0,

  /* Expression: [0;0;0;0]
   * Referenced by: '<Root>/Unit Delay2'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: (2*pi)/(11*4*19.2)
   * Referenced by: '<S4>/Gain'
   */
  0.0074374826079303819,

  /* Expression: 11
   * Referenced by: '<Root>/uk2'
   */
  11.0,

  /* Expression: 0
   * Referenced by: '<Root>/uk2'
   */
  0.0,

  /* Expression: 2*pi*0.4
   * Referenced by: '<Root>/uk2'
   */
  2.5132741228718345,

  /* Expression: 0
   * Referenced by: '<Root>/uk2'
   */
  0.0,

  /* Expression: hex2dec("2800")
   * Referenced by: '<S1>/Constant2'
   */
  10240.0,

  /* Expression: 0.001
   * Referenced by: '<Root>/Gain1'
   */
  0.001,

  /* Computed Parameter: Gain_Gain_g
   * Referenced by: '<Root>/Gain'
   */
  20972
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
