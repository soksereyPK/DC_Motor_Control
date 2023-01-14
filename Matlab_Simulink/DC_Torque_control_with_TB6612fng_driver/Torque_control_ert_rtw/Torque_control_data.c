/*
 * File: Torque_control_data.c
 *
 * Code generated for Simulink model 'Torque_control'.
 *
 * Model version                  : 1.164
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Nov 15 09:57:12 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Torque_control.h"

/* Block parameters (default storage) */
P_Torque_control_T Torque_control_P = {
  /* Expression: -1
   * Referenced by: '<Root>/Encoder1'
   */
  -1.0,

  /* Expression: 12
   * Referenced by: '<Root>/uk1'
   */
  12.0,

  /* Expression: 0
   * Referenced by: '<Root>/uk1'
   */
  0.0,

  /* Expression: 2*pi*1.2
   * Referenced by: '<Root>/uk1'
   */
  7.5398223686155035,

  /* Expression: 0
   * Referenced by: '<Root>/uk1'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<Root>/Constant1'
   */
  10.0,

  /* Expression: -(2*pi)/(11*4*370)
   * Referenced by: '<Root>/Gain15'
   */
  -0.00038594504343854953,

  /* Expression: 180/pi
   * Referenced by: '<S2>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
