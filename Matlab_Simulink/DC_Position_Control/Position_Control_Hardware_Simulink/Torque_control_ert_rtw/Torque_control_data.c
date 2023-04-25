/*
 * File: Torque_control_data.c
 *
 * Code generated for Simulink model 'Torque_control'.
 *
 * Model version                  : 1.234
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Apr 22 18:22:06 2023
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
   * Referenced by: '<Root>/Gain5'
   */
  26.85,

  /* Variable: b
   * Referenced by:
   *   '<Root>/Gain5'
   *   '<Root>/Gain8'
   */
  85.68,

  /* Variable: k1
   * Referenced by: '<Root>/Gain6'
   */
  0.46076584505552554,

  /* Variable: k2
   * Referenced by: '<Root>/Gain7'
   */
  -0.16670902644305355,

  /* Expression: 0.01
   * Referenced by: '<S1>/Encoder1'
   */
  0.01,

  /* Expression: 10
   * Referenced by: '<Root>/Constant2'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: (2*pi)/(100*19.2)
   * Referenced by: '<S1>/Gain15'
   */
  0.0032724923474893677,

  /* Expression: 180/pi
   * Referenced by: '<S3>/Gain'
   */
  57.295779513082323
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
