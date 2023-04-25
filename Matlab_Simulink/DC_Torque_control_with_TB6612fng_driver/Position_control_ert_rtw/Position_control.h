/*
 * File: Position_control.h
 *
 * Code generated for Simulink model 'Position_control'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Sep  8 10:36:03 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Position_control_h_
#define RTW_HEADER_Position_control_h_
#ifndef Position_control_COMMON_INCLUDES_
#define Position_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_arduino_digitalio.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#endif                                 /* Position_control_COMMON_INCLUDES_ */

#include "Position_control_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

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

/* Block signals (default storage) */
typedef struct {
  real_T Ak[16];
  real_T Ak_m[16];
  real_T UnitDelay2[4];                /* '<S1>/Unit Delay2' */
  real_T uk2;                          /* '<Root>/uk2' */
  real_T Gain;                         /* '<S3>/Gain' */
  real_T Derivative2;                  /* '<S1>/Derivative2' */
  real_T x_est[4];                     /* '<S1>/EKF2' */
  real_T Wk[4];
  int8_T b_I[16];
} B_Position_control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S3>/Encoder' */
  codertarget_arduinobase_block_T obj_b;/* '<S3>/Digital Output1' */
  codertarget_arduinobase_block_T obj_d;/* '<S3>/Digital Output' */
  codertarget_arduinobase_int_o_T obj_bg;/* '<S3>/PWM' */
  real_T UnitDelay2_DSTATE[4];         /* '<S1>/Unit Delay2' */
  real_T TimeStampA;                   /* '<S1>/Derivative2' */
  real_T LastUAtTimeA;                 /* '<S1>/Derivative2' */
  real_T TimeStampB;                   /* '<S1>/Derivative2' */
  real_T LastUAtTimeB;                 /* '<S1>/Derivative2' */
  real_T x_est_p[4];                   /* '<S1>/EKF2' */
  real_T P[16];                        /* '<S1>/EKF2' */
  real_T Qd_est[16];                   /* '<S1>/EKF2' */
  real_T R_est;                        /* '<S1>/EKF2' */
  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<S1>/Scope3' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<S1>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_j;                     /* '<S3>/Scope' */
} DW_Position_control_T;

/* Parameters (default storage) */
struct P_Position_control_T_ {
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S3>/Encoder'
                                        */
  real_T UnitDelay2_InitialCondition[4];/* Expression: [0;0;0;0]
                                         * Referenced by: '<S1>/Unit Delay2'
                                         */
  real_T uk2_Amp;                      /* Expression: 12
                                        * Referenced by: '<Root>/uk2'
                                        */
  real_T uk2_Bias;                     /* Expression: 0
                                        * Referenced by: '<Root>/uk2'
                                        */
  real_T uk2_Freq;                     /* Expression: 2*pi*1.2
                                        * Referenced by: '<Root>/uk2'
                                        */
  real_T uk2_Phase;                    /* Expression: 0
                                        * Referenced by: '<Root>/uk2'
                                        */
  real_T Gain_Gain;                    /* Expression: -(2*pi)/(11*4)
                                        * Referenced by: '<S3>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Position_control_T {
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
extern P_Position_control_T Position_control_P;

/* Block signals (default storage) */
extern B_Position_control_T Position_control_B;

/* Block states (default storage) */
extern DW_Position_control_T Position_control_DW;

/* Model entry point functions */
extern void Position_control_initialize(void);
extern void Position_control_step(void);
extern void Position_control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Position_control_T *const Position_control_M;
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
 * '<Root>' : 'Position_control'
 * '<S1>'   : 'Position_control/Estimated a,b,c parameters'
 * '<S2>'   : 'Position_control/Estimated a,b,c parameters/EKF2'
 * '<S3>'   : 'Position_control/Estimated a,b,c parameters/Subsystem1'
 * '<S4>'   : 'Position_control/Estimated a,b,c parameters/Subsystem1/MATLAB Function4'
 */
#endif                                 /* RTW_HEADER_Position_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
