/*
 * File: position_control_PD_with_Due_private.h
 *
 * Code generated for Simulink model 'position_control_PD_with_Due'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Jul  9 10:25:01 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_position_control_PD_with_Due_private_h_
#define RTW_HEADER_position_control_PD_with_Due_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void readEncDUEpin8_9_Start_wrapper(real_T *xD);
SFB_EXTERN_C void readEncDUEpin8_9_Outputs_wrapper(int32_T *count,
  const real_T *xD);
SFB_EXTERN_C void readEncDUEpin8_9_Update_wrapper(int32_T *count,
  real_T *xD);
SFB_EXTERN_C void readEncDUEpin8_9_Terminate_wrapper(real_T *xD);

#undef SFB_EXTERN_C
#endif                  /* RTW_HEADER_position_control_PD_with_Due_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
