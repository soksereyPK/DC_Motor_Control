/*
 * File: Position_Control_Single_Loop_data.c
 *
 * Code generated for Simulink model 'Position_Control_Single_Loop'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Jun 24 10:33:56 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Position_Control_Single_Loop.h"

/* Block parameters (default storage) */
P_Position_Control_Single_Loo_T Position_Control_Single_Loop_P = {
  /* Variable: a
   * Referenced by: '<Root>/Gain8'
   */
  26.85,

  /* Variable: b
   * Referenced by:
   *   '<Root>/Gain8'
   *   '<Root>/Gain9'
   */
  85.68,

  /* Variable: kd4
   * Referenced by: '<Root>/Gain7'
   */
  0.27328994464795386,

  /* Variable: kp4
   * Referenced by: '<Root>/Gain6'
   */
  7.3722535208884086,

  /* Expression: 0.01
   * Referenced by: '<S1>/Encoder'
   */
  0.01,

  /* Expression: 2*pi
   * Referenced by: '<Root>/Constant5'
   */
  6.2831853071795862,

  /* Expression: pi/3
   * Referenced by: '<Root>/Constant7'
   */
  1.0471975511965976,

  /* Expression: pi/3
   * Referenced by: '<S1>/J6_Desire'
   */
  1.0471975511965976,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S1>/Gain'
   */
  -1799071694,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<Root>/Manual Switch1'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
