/*
 * File: hardware_ekf_est_4para_myrobot_new_driver_private.h
 *
 * Code generated for Simulink model 'hardware_ekf_est_4para_myrobot_new_driver'.
 *
 * Model version                  : 3.17
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Jun 28 16:28:18 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_hardware_ekf_est_4para_myrobot_new_driver_private_h_
#define RTW_HEADER_hardware_ekf_est_4para_myrobot_new_driver_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "hardware_ekf_est_4para_myrobot_new_driver.h"

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

extern "C" {

#endif

  extern void readEncDUEpin8_9_Start_wrapper(real_T *xD);
  extern void readEncDUEpin8_9_Outputs_wrapper(int32_T *count,
    const real_T *xD);
  extern void readEncDUEpin8_9_Update_wrapper(int32_T *count,
    real_T *xD);
  extern void readEncDUEpin8_9_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void readEncDUEpin10_11_Start_wrapper(real_T *xD);
  extern void readEncDUEpin10_11_Outputs_wrapper(int32_T *countt,
    const real_T *xD);
  extern void readEncDUEpin10_11_Update_wrapper(int32_T *countt,
    real_T *xD);
  extern void readEncDUEpin10_11_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif

extern void hardware_ekf_est_4par_EKF2_Init(DW_EKF2_hardware_ekf_est_4par_T
  *localDW);
extern void hardware_ekf_est_4para_myr_EKF2(real_T rtu_uk, real_T rtu_y_true,
  real_T rty_x_est[4], B_EKF2_hardware_ekf_est_4para_T *localB,
  DW_EKF2_hardware_ekf_est_4par_T *localDW);
extern void hardware_ekf_Convertpulsetorad2(int32_T rtu_u, real_T rtu_ppr,
  real_T rtu_gearRatio, real_T *rty_outGearBox, DW_Convertpulsetorad2_hardwar_T *
  localDW);

#endif     /* RTW_HEADER_hardware_ekf_est_4para_myrobot_new_driver_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
