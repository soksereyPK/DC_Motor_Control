/*
 * File: Torque_control_data.c
 *
 * Code generated for Simulink model 'Torque_control'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Aug 26 16:07:10 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Torque_control.h"

/* Block parameters (default storage) */
P_Torque_control_T Torque_control_P = {
  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S2>/Constant'
   */
  1.0,

  /* Expression: 0.01
   * Referenced by: '<Root>/Current Reg read1'
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

  /* Expression: -1
   * Referenced by: '<S5>/Encoder1'
   */
  -1.0,

  /* Computed Parameter: x_Y0
   * Referenced by: '<S6>/x'
   */
  0.0,

  /* Expression: diag([5,0.1])
   * Referenced by: '<S6>/Delay2'
   */
  { 5.0, 0.0, 0.0, 0.1 },

  /* Expression: [5;0.4]
   * Referenced by: '<S6>/Delay3'
   */
  { 5.0, 0.4 },

  /* Expression: 1e0*diag([10,1,30,10])
   * Referenced by: '<S7>/Delay1'
   */
  { 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 30.0, 0.0, 0.0, 0.0, 0.0,
    10.0 },

  /* Expression: [0;0;0;0]
   * Referenced by: '<S7>/Delay'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: -(2*pi)/(14*4*370)
   * Referenced by: '<S5>/Gain2'
   */
  -0.00030324253413028889,

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

  /* Expression: 0.001
   * Referenced by: '<Root>/Gain3'
   */
  0.001,

  /* Expression: hex2dec("2800")
   * Referenced by: '<S1>/Constant2'
   */
  10240.0,

  /* Computed Parameter: Gain2_Gain_h
   * Referenced by: '<Root>/Gain2'
   */
  20972
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
