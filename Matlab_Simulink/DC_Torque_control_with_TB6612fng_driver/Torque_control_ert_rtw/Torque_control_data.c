/*
 * File: Torque_control_data.c
 *
 * Code generated for Simulink model 'Torque_control'.
 *
<<<<<<< HEAD
 * Model version                  : 1.177
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Oct 15 08:20:33 2022
=======
 * Model version                  : 1.200
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Apr 22 17:06:25 2023
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713
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
<<<<<<< HEAD
  11.67,
=======
  26.85,
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713

  /* Variable: b
   * Referenced by:
   *   '<Root>/Gain5'
   *   '<Root>/Gain8'
   */
<<<<<<< HEAD
  1307.66,
=======
  85.68,
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713

  /* Variable: k1
   * Referenced by: '<Root>/Gain6'
   */
<<<<<<< HEAD
  0.48304198466705328,
=======
  0.46076584505552554,
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713

  /* Variable: k2
   * Referenced by: '<Root>/Gain7'
   */
<<<<<<< HEAD
  0.029514921659633764,

  /* Expression: 0.1
   * Referenced by: '<Root>/Current Reg read'
   */
  0.1,

  /* Expression: hex2dec("399F")
   * Referenced by: '<S4>/Constant3'
   */
  14751.0,

  /* Expression: hex2dec("0x2800")
   * Referenced by: '<S5>/Constant2'
   */
  10240.0,

  /* Expression: 0.001
   * Referenced by: '<S3>/Encoder1'
=======
  -0.16670902644305355,

  /* Expression: 0.01
   * Referenced by: '<S1>/Encoder1'
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713
   */
  0.01,

<<<<<<< HEAD
  /* Expression: hex2dec("2800")
   * Referenced by: '<S1>/Constant2'
   */
  10240.0,

  /* Expression: 100
   * Referenced by: '<Root>/Constant2'
   */
  100.0,
=======
  /* Expression: 10
   * Referenced by: '<Root>/Constant2'
   */
  10.0,
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

<<<<<<< HEAD
  /* Expression: -(2*pi)/(11*4*370)
   * Referenced by: '<S3>/Gain2'
   */
  -0.00038594504343854953,
=======
  /* Expression: (2*pi)/(100*4*19.2)
   * Referenced by: '<S1>/Gain15'
   */
  0.00081812308687234192,
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713

  /* Expression: 180/pi
   * Referenced by: '<S7>/Gain'
   */
<<<<<<< HEAD
  57.295779513082323,

  /* Expression: 0.001
   * Referenced by: '<Root>/Gain1'
   */
  0.001,

  /* Computed Parameter: Gain_Gain_p
   * Referenced by: '<Root>/Gain'
   */
  20972
=======
  57.295779513082323
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
