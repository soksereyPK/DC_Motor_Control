/*
 * File: position_control_PD_with_Due_data.c
 *
 * Code generated for Simulink model 'position_control_PD_with_Due'.
 *
 * Model version                  : 2.26
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Jul 28 12:14:00 2022
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
   * Referenced by: '<Root>/Gain10'
   */
  0.44517766877011339,

  /* Variable: kp2
   * Referenced by: '<Root>/Gain5'
   */
  5.3530057768620249,

  /* Expression: 0.01
   * Referenced by: '<S1>/Encoder'
   */
  0.01,

  /* Expression: 50
   * Referenced by: '<Root>/Constant2'
   */
  50.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S3>/Gain'
   */
  { { 0x770698F0UL, 0x729UL } },

  /* Computed Parameter: Gain_Gain_j
   * Referenced by: '<S1>/Gain'
   */
  2044399652
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
