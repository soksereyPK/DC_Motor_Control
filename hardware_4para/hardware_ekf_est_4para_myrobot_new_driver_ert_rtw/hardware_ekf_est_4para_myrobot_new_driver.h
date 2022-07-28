/*
 * File: hardware_ekf_est_4para_myrobot_new_driver.h
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

#ifndef RTW_HEADER_hardware_ekf_est_4para_myrobot_new_driver_h_
#define RTW_HEADER_hardware_ekf_est_4para_myrobot_new_driver_h_
#include <math.h>
#include <float.h>
#include <stddef.h>
#ifndef hardware_ekf_est_4para_myrobot_new_driver_COMMON_INCLUDES_
#define hardware_ekf_est_4para_myrobot_new_driver_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_work.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif          /* hardware_ekf_est_4para_myrobot_new_driver_COMMON_INCLUDES_ */

#include "hardware_ekf_est_4para_myrobot_new_driver_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#define hardware_ekf_est_4para_myrobot_new_driver_M (hardware_ekf_est_4para_myrob_M)

/* Block signals for system '<Root>/EKF2' */
typedef struct {
  real_T Ak[16];
  real_T Ak_m[16];
  real_T Wk[4];
} B_EKF2_hardware_ekf_est_4para_T;

/* Block states (default storage) for system '<Root>/EKF2' */
typedef struct {
  real_T x_est_p[4];                   /* '<Root>/EKF2' */
  real_T P[16];                        /* '<Root>/EKF2' */
  real_T Qd_est[16];                   /* '<Root>/EKF2' */
  real_T R_est;                        /* '<Root>/EKF2' */
} DW_EKF2_hardware_ekf_est_4par_T;

/* Block states (default storage) for system '<S3>/Convert pulse to rad2' */
typedef struct {
  real_T counter_num;                  /* '<S3>/Convert pulse to rad2' */
  real_T over_flag;                    /* '<S3>/Convert pulse to rad2' */
} DW_Convertpulsetorad2_hardwar_T;

/* Block signals (default storage) */
typedef struct {
  real_T UnitDelay3[4];                /* '<Root>/Unit Delay3' */
  real_T UnitDelay2[4];                /* '<Root>/Unit Delay2' */
  real_T outGearBox;                   /* '<S4>/Convert pulse to rad1' */
  real_T outGearBox_h;                 /* '<S3>/Convert pulse to rad2' */
  real_T Derivative3;
  real_T uk2;
  real_T Derivative2;
  int32_T Encoder1;                    /* '<S4>/Encoder1' */
  int32_T Encoder3;                    /* '<S3>/Encoder3' */
  int32_T dir_b;                       /* '<S3>/MATLAB Function3' */
  B_EKF2_hardware_ekf_est_4para_T sf_EKF3;/* '<Root>/EKF3' */
  B_EKF2_hardware_ekf_est_4para_T sf_EKF2;/* '<Root>/EKF2' */
} B_hardware_ekf_est_4para_myro_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<S4>/Digital Output' */
  codertarget_arduinobase_block_T obj_f;/* '<S3>/Digital Output1' */
  codertarget_arduinobase_inter_T obj_d;/* '<S4>/PWM' */
  codertarget_arduinobase_inter_T obj_h;/* '<S3>/PWM3' */
  real_T UnitDelay3_DSTATE[4];         /* '<Root>/Unit Delay3' */
  real_T UnitDelay2_DSTATE[4];         /* '<Root>/Unit Delay2' */
  real_T Encoder1_DSTATE;              /* '<S4>/Encoder1' */
  real_T Encoder3_DSTATE;              /* '<S3>/Encoder3' */
  real_T TimeStampA;                   /* '<Root>/Derivative2' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative2' */
  real_T TimeStampB;                   /* '<Root>/Derivative2' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative2' */
  real_T TimeStampA_g;                 /* '<Root>/Derivative3' */
  real_T LastUAtTimeA_i;               /* '<Root>/Derivative3' */
  real_T TimeStampB_p;                 /* '<Root>/Derivative3' */
  real_T LastUAtTimeB_d;               /* '<Root>/Derivative3' */
  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_UnitD;   /* synthesized block */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Uni_e;   /* synthesized block */

  DW_Convertpulsetorad2_hardwar_T sf_Convertpulsetorad1;/* '<S4>/Convert pulse to rad1' */
  DW_Convertpulsetorad2_hardwar_T sf_Convertpulsetorad2;/* '<S3>/Convert pulse to rad2' */
  DW_EKF2_hardware_ekf_est_4par_T sf_EKF3;/* '<Root>/EKF3' */
  DW_EKF2_hardware_ekf_est_4par_T sf_EKF2;/* '<Root>/EKF2' */
} DW_hardware_ekf_est_4para_myr_T;

/* Parameters (default storage) */
struct P_hardware_ekf_est_4para_myro_T_ {
  real_T UnitDelay3_InitialCondition[4];/* Expression: [0;0;0;0]
                                         * Referenced by: '<Root>/Unit Delay3'
                                         */
  real_T UnitDelay2_InitialCondition[4];/* Expression: [0;0;0;0]
                                         * Referenced by: '<Root>/Unit Delay2'
                                         */
  real_T totalPPR_Value;               /* Expression: 14*2
                                        * Referenced by: '<S4>/totalPPR'
                                        */
  real_T gearRatio_Value;              /* Expression: 19.2*3.75
                                        * Referenced by: '<S4>/gearRatio'
                                        */
  real_T uk2_Amp;                      /* Expression: 20
                                        * Referenced by: '<Root>/uk2'
                                        */
  real_T uk2_Bias;                     /* Expression: 0
                                        * Referenced by: '<Root>/uk2'
                                        */
  real_T uk2_Freq;                     /* Expression: 2*pi*0.4
                                        * Referenced by: '<Root>/uk2'
                                        */
  real_T uk2_Phase;                    /* Expression: 0
                                        * Referenced by: '<Root>/uk2'
                                        */
  real_T totalPPR1_Value;              /* Expression: 14*2
                                        * Referenced by: '<S3>/totalPPR1'
                                        */
  real_T gearRatio1_Value;             /* Expression: 19.2*3.75
                                        * Referenced by: '<S3>/gearRatio1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_hardware_ekf_est_4par_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_hardware_ekf_est_4para_myro_T hardware_ekf_est_4para_myrobo_P;

/* Block signals (default storage) */
extern B_hardware_ekf_est_4para_myro_T hardware_ekf_est_4para_myrobo_B;

/* Block states (default storage) */
extern DW_hardware_ekf_est_4para_myr_T hardware_ekf_est_4para_myrob_DW;

/* Model entry point functions */
extern void hardware_ekf_est_4para_myrobot_new_driver_initialize(void);
extern void hardware_ekf_est_4para_myrobot_new_driver_step(void);
extern void hardware_ekf_est_4para_myrobot_new_driver_terminate(void);

/* Real-time Model object */
extern RT_MODEL_hardware_ekf_est_4pa_T *const hardware_ekf_est_4para_myrob_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'hardware_ekf_est_4para_myrobot_new_driver'
 * '<S1>'   : 'hardware_ekf_est_4para_myrobot_new_driver/EKF2'
 * '<S2>'   : 'hardware_ekf_est_4para_myrobot_new_driver/EKF3'
 * '<S3>'   : 'hardware_ekf_est_4para_myrobot_new_driver/Left Motor'
 * '<S4>'   : 'hardware_ekf_est_4para_myrobot_new_driver/Right motor'
 * '<S5>'   : 'hardware_ekf_est_4para_myrobot_new_driver/Left Motor/Convert pulse to rad2'
 * '<S6>'   : 'hardware_ekf_est_4para_myrobot_new_driver/Left Motor/MATLAB Function3'
 * '<S7>'   : 'hardware_ekf_est_4para_myrobot_new_driver/Right motor/Convert pulse to rad1'
 * '<S8>'   : 'hardware_ekf_est_4para_myrobot_new_driver/Right motor/MATLAB Function2'
 */
#endif             /* RTW_HEADER_hardware_ekf_est_4para_myrobot_new_driver_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
