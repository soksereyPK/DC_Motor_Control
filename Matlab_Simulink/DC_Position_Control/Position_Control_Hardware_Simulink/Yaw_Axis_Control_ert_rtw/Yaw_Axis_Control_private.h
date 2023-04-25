/*
 * File: Yaw_Axis_Control_private.h
 *
 * Code generated for Simulink model 'Yaw_Axis_Control'.
 *
 * Model version                  : 1.360
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Apr  4 17:00:41 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Yaw_Axis_Control_private_h_
#define RTW_HEADER_Yaw_Axis_Control_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
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

extern real_T rt_roundd_snf(real_T u);

#endif                              /* RTW_HEADER_Yaw_Axis_Control_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
