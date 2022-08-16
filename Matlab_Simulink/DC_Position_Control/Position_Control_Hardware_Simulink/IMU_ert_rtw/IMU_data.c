/*
 * File: IMU_data.c
 *
 * Code generated for Simulink model 'IMU'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Aug 10 16:46:32 2022
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
   * Referenced by: '<S4>/Constant3'
   */
  14751.0,

  /* Expression: hex2dec("0x2800")
   * Referenced by: '<S5>/Constant2'
   */
  10240.0,

  /* Expression: hex2dec("2800")
   * Referenced by: '<S1>/Constant2'
   */
  10240.0,

  /* Expression: 11
   * Referenced by: '<Root>/Sine Wave1'
   */
  11.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.0,

  /* Expression: 0.001
   * Referenced by: '<Root>/Gain1'
   */
  0.001,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<Root>/Gain'
   */
  20972
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
