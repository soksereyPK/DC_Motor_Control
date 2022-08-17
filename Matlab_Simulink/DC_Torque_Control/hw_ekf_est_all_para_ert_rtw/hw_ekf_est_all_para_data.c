/*
 * File: hw_ekf_est_all_para_data.c
 *
 * Code generated for Simulink model 'hw_ekf_est_all_para'.
 *
 * Model version                  : 4.5
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Aug 17 11:47:30 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "hw_ekf_est_all_para.h"

/* Block parameters (default storage) */
P_hw_ekf_est_all_para_T hw_ekf_est_all_para_P = {
  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S2>/Constant'
   */
  0.5,

  /* Expression: 0.01
   * Referenced by: '<Root>/Current Reg read'
   */
  0.01,

  /* Expression: hex2dec("399F")
   * Referenced by: '<S8>/Constant3'
   */
  14751.0,

  /* Expression: hex2dec("0x2800")
   * Referenced by: '<S9>/Constant2'
   */
  10240.0,

  /* Computed Parameter: x_Y0
   * Referenced by: '<S5>/x'
   */
  0.0,

  /* Expression: diag([5,0.1])
   * Referenced by: '<S5>/Delay2'
   */
  { 5.0, 0.0, 0.0, 0.1 },

  /* Expression: [5;0.4]
   * Referenced by: '<S5>/Delay3'
   */
  { 5.0, 0.4 },

  /* Expression: -1
   * Referenced by: '<S6>/Encoder'
   */
  -1.0,

  /* Expression: 1e0*diag([10,1,30,10])
   * Referenced by: '<S7>/Delay1'
   */
  { 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 30.0, 0.0, 0.0, 0.0, 0.0,
    10.0 },

  /* Expression: [0;0;0;0]
   * Referenced by: '<S7>/Delay'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: -(2*pi)/(11*4*19.2)
   * Referenced by: '<S6>/Gain'
   */
  -0.0074374826079303819,

  /* Expression: 10
   * Referenced by: '<Root>/Sine Wave'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 2*pi*1.2
   * Referenced by: '<Root>/Sine Wave'
   */
  7.5398223686155035,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<Root>/Transfer Fcn'
   */
  -10.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<Root>/Transfer Fcn'
   */
  10.0,

  /* Expression: 0.001
   * Referenced by: '<Root>/Gain1'
   */
  0.001,

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
