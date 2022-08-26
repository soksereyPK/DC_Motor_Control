/*
 * File: hw_ekf_est_all_para_data.c
 *
 * Code generated for Simulink model 'hw_ekf_est_all_para'.
 *
 * Model version                  : 4.4
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Aug 26 10:32:21 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "hw_ekf_est_all_para.h"

/* Block parameters (default storage) */
P_hw_ekf_est_all_para_T hw_ekf_est_all_para_P = {
  /* Expression: 0.01
   * Referenced by: '<Root>/Current Reg read'
   */
  0.01,

  /* Expression: hex2dec("399F")
   * Referenced by: '<S7>/Constant3'
   */
  14751.0,

  /* Expression: hex2dec("0x2800")
   * Referenced by: '<S8>/Constant2'
   */
  10240.0,

  /* Expression: -1
   * Referenced by: '<S4>/Encoder1'
   */
  -1.0,

  /* Expression: 1e0*diag([10,1,30,10])
   * Referenced by: '<S6>/Delay1'
   */
  { 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 30.0, 0.0, 0.0, 0.0, 0.0,
    10.0 },

  /* Expression: [0;0;0;0]
   * Referenced by: '<S6>/Delay'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: -(2*pi)/(14*4*370)
   * Referenced by: '<S4>/Gain2'
   */
  -0.00030324253413028889,

  /* Expression: 180/pi
   * Referenced by: '<S10>/Gain'
   */
  57.295779513082323,

  /* Expression: 10
   * Referenced by: '<Root>/Sine Wave'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 2*pi*0.4
   * Referenced by: '<Root>/Sine Wave'
   */
  2.5132741228718345,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: [5;0.4]
   * Referenced by: '<S5>/Delay3'
   */
  { 5.0, 0.4 },

  /* Expression: 0.001
   * Referenced by: '<Root>/Gain1'
   */
  0.001,

  /* Expression: diag([5,0.1])
   * Referenced by: '<S5>/Delay2'
   */
  { 5.0, 0.0, 0.0, 0.1 },

  /* Expression: hex2dec("2800")
   * Referenced by: '<S1>/Constant2'
   */
  10240.0,

  /* Computed Parameter: Gain_Gain_e
   * Referenced by: '<Root>/Gain'
   */
  20972
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
