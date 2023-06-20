/*
 * File: Position_Control_Single_Loop.h
 *
 * Code generated for Simulink model 'Position_Control_Single_Loop'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Jun  5 16:56:52 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Position_Control_Single_Loop_h_
#define RTW_HEADER_Position_Control_Single_Loop_h_
#ifndef Position_Control_Single_Loop_COMMON_INCLUDES_
#define Position_Control_Single_Loop_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#endif                       /* Position_Control_Single_Loop_COMMON_INCLUDES_ */

#include "Position_Control_Single_Loop_types.h"
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
  real_T Gain;                         /* '<S1>/Gain' */
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T Derivative7;                  /* '<Root>/Derivative7' */
} B_Position_Control_Single_Loo_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S1>/Encoder' */
  codertarget_arduinobase_int_b_T obj_e;/* '<S1>/PWM2' */
  codertarget_arduinobase_int_b_T obj_l;/* '<S1>/PWM1' */
  real_T TimeStampA;                   /* '<Root>/Derivative7' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative7' */
  real_T TimeStampB;                   /* '<Root>/Derivative7' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative7' */
  real_T TimeStampA_k;                 /* '<Root>/Derivative8' */
  real_T LastUAtTimeA_p;               /* '<Root>/Derivative8' */
  real_T TimeStampB_a;                 /* '<Root>/Derivative8' */
  real_T LastUAtTimeB_d;               /* '<Root>/Derivative8' */
  real_T TimeStampA_g;                 /* '<Root>/Derivative1' */
  real_T LastUAtTimeA_j;               /* '<Root>/Derivative1' */
  real_T TimeStampB_c;                 /* '<Root>/Derivative1' */
  real_T LastUAtTimeB_k;               /* '<Root>/Derivative1' */
  real_T TimeStampA_b;                 /* '<Root>/Derivative9' */
  real_T LastUAtTimeA_e;               /* '<Root>/Derivative9' */
  real_T TimeStampB_j;                 /* '<Root>/Derivative9' */
  real_T LastUAtTimeB_g;               /* '<Root>/Derivative9' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope7_PWORK;                      /* '<Root>/Scope7' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_m;                    /* '<S1>/Scope1' */
} DW_Position_Control_Single_Lo_T;

/* Parameters (default storage) */
struct P_Position_Control_Single_Loo_T_ {
  real_T a;                            /* Variable: a
                                        * Referenced by: '<Root>/Gain11'
                                        */
  real_T b;                            /* Variable: b
                                        * Referenced by:
                                        *   '<Root>/Gain11'
                                        *   '<Root>/Gain13'
                                        */
  real_T k1;                           /* Variable: k1
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T k2;                           /* Variable: k2
                                        * Referenced by:
                                        *   '<Root>/Gain11'
                                        *   '<Root>/Gain12'
                                        */
  real_T Encoder_SampleTime;           /* Expression: 0.01
                                        * Referenced by: '<S1>/Encoder'
                                        */
  real_T Constant8_Value;              /* Expression: 2*pi
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T Constant9_Value;              /* Expression: pi
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T Gain_Gain;                    /* Expression: -(2*pi)/(100*4*19.2)
                                        * Referenced by: '<S1>/Gain'
                                        */
  uint8_T ManualSwitch2_CurrentSetting;
                             /* Computed Parameter: ManualSwitch2_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch2'
                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_Position_Control_Sing_T {
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
extern P_Position_Control_Single_Loo_T Position_Control_Single_Loop_P;

/* Block signals (default storage) */
extern B_Position_Control_Single_Loo_T Position_Control_Single_Loop_B;

/* Block states (default storage) */
extern DW_Position_Control_Single_Lo_T Position_Control_Single_Loop_DW;

/* Model entry point functions */
extern void Position_Control_Single_Loop_initialize(void);
extern void Position_Control_Single_Loop_step(void);
extern void Position_Control_Single_Loop_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Position_Control_Sin_T *const Position_Control_Single_Loop_M;
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
 * '<Root>' : 'Position_Control_Single_Loop'
 * '<S1>'   : 'Position_Control_Single_Loop/Right motor1'
 * '<S2>'   : 'Position_Control_Single_Loop/Right motor1/MATLAB Function1'
 */
#endif                          /* RTW_HEADER_Position_Control_Single_Loop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
