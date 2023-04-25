/*
 * File: Yaw_Axis_Control_data.c
 *
 * Code generated for Simulink model 'Yaw_Axis_Control'.
 *
 * Model version                  : 1.325
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Apr  4 15:11:38 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Yaw_Axis_Control.h"

/* Block parameters (default storage) */
P_Yaw_Axis_Control_T Yaw_Axis_Control_P = {
  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S2>/UD'
   */
  0.0,

  /* Mask Parameter: DetectChange2_vinit
   * Referenced by: '<S1>/Delay Input1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Serial Transmit2'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<Root>/Encoder'
   */
  0.01,

  /* Expression: 3
   * Referenced by: '<Root>/Constant6'
   */
  3.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant7'
   */
  0.0,

  /* Expression: 30
   * Referenced by: '<Root>/Constant4'
   */
  30.0,

  /* Expression: 20
   * Referenced by: '<Root>/Constant3'
   */
  20.0,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<Root>/Merge'
   */
  0.0,

  /* Expression: (2*pi)/(1000*4)
   * Referenced by: '<Root>/Gain1'
   */
  0.0015707963267948967,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S2>/TSamp'
   */
  100.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
