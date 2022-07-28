/*
 * File: position_control_PD_with_Due_data.c
 *
 * Code generated for Simulink model 'position_control_PD_with_Due'.
 *
 * Model version                  : 2.13
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Jul 28 08:24:25 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "position_control_PD_with_Due.h"

/* Block parameters (default storage) */
P_position_control_PD_with_Du_T position_control_PD_with_Due_P = {
  /* Variable: kd2
   * Referenced by: '<Root>/Gain11'
   */
  574.45344129554655,

  /* Variable: kp2
   * Referenced by: '<Root>/Gain12'
   */
  209878.54251012145,

  /* Variable: pi
   * Referenced by:
   *   '<Root>/Constant'
   *   '<Root>/Constant4'
   *   '<Root>/Sine Wave'
   */
  180.0,

  /* Expression: 0.01
   * Referenced by: '<Root>/Encoder'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S1>/Gain1'
   */
  { { 0UL, 0x1UL } },

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<Root>/Gain'
   */
  1227133513,

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
