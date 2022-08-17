/*
 * File: Torque_control_data.c
 *
 * Code generated for Simulink model 'Torque_control'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Aug 17 10:45:39 2022
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
   * Referenced by: '<S3>/Encoder'
   */
  -1.0,

  /* Expression: [0;0;0;0]
   * Referenced by: '<S1>/Unit Delay2'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: (2*pi)/(11*4*19.2)
   * Referenced by: '<S3>/Gain'
   */
  0.0074374826079303819,

  /* Expression: 14
   * Referenced by: '<Root>/uk2'
   */
  14.0,

  /* Expression: 0
   * Referenced by: '<Root>/uk2'
   */
  0.0,

  /* Expression: 2*pi*1
   * Referenced by: '<Root>/uk2'
   */
  6.2831853071795862,

  /* Expression: 0
   * Referenced by: '<Root>/uk2'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
