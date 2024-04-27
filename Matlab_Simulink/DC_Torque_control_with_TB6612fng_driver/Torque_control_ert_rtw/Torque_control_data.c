/*
 * File: Torque_control_data.c
 *
 * Code generated for Simulink model 'Torque_control'.
 *
 * Model version                  : 2.7
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Apr 27 10:18:12 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Torque_control.h"

/* Block parameters (default storage) */
P_Torque_control_T Torque_control_P = {
  /* Variable: a
   * Referenced by: '<Root>/Gain11'
   */
  9.3,

  /* Variable: b
   * Referenced by:
   *   '<Root>/Gain11'
   *   '<Root>/Gain12'
   */
  165.8,

  /* Variable: kd4
   * Referenced by: '<Root>/Gain10'
   */
  0.095493011029664315,

  /* Variable: kp4
   * Referenced by: '<Root>/Gain9'
   */
  0.95243468285542654,

  /* Expression: -1
   * Referenced by: '<S1>/Encoder1'
   */
  -1.0,

  /* Expression: (2*pi)/(11*4*6.5)
   * Referenced by: '<S1>/Gain2'
   */
  0.02196917939573282,

  /* Expression: 6.28
   * Referenced by: '<Root>/Constant5'
   */
  6.28
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
