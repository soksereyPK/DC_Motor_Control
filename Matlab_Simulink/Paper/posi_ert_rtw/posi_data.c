/*
 * File: posi_data.c
 *
 * Code generated for Simulink model 'posi'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Jun  5 17:06:02 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "posi.h"

/* Block parameters (default storage) */
P_posi_T posi_P = {
  /* Variable: a
   * Referenced by: '<Root>/Gain11'
   */
  26.85,

  /* Variable: b
   * Referenced by:
   *   '<Root>/Gain11'
   *   '<Root>/Gain13'
   */
  85.68,

  /* Variable: k1
   * Referenced by: '<Root>/Gain3'
   */
  26.975941359222656,

  /* Variable: k2
   * Referenced by:
   *   '<Root>/Gain11'
   *   '<Root>/Gain12'
   */
  0.27328994464795386,

  /* Expression: 0.01
   * Referenced by: '<S1>/Encoder'
   */
  0.01,

  /* Expression: 2*pi
   * Referenced by: '<Root>/Constant8'
   */
  6.2831853071795862,

  /* Expression: pi
   * Referenced by: '<Root>/Constant9'
   */
  3.1415926535897931,

  /* Expression: -(2*pi)/(100*4*19.2)
   * Referenced by: '<S1>/Gain'
   */
  -0.00081812308687234192,

  /* Computed Parameter: ManualSwitch2_CurrentSetting
   * Referenced by: '<Root>/Manual Switch2'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
