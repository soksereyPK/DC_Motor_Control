/*
 * File: position.h
 *
 * Code generated for Simulink model 'position'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Jun  5 17:03:28 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_position_h_
#define RTW_HEADER_position_h_
#ifndef position_COMMON_INCLUDES_
#define position_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#endif                                 /* position_COMMON_INCLUDES_ */

#include "position_types.h"
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T TmpRTBAtSum2Inport2;          /* '<Root>/Right motor1' */
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T Derivative7;                  /* '<Root>/Derivative7' */
  real_T TmpRTBAtDerivative9Inport1;   /* '<Root>/Right motor1' */
  real_T Gain;                         /* '<S1>/Gain' */
} B_position_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S1>/Encoder' */
  codertarget_arduinobase_int_h_T obj_h;/* '<S1>/PWM2' */
  codertarget_arduinobase_int_h_T obj_o;/* '<S1>/PWM1' */
  real_T TmpRTBAtSum2Inport2_Buffer0;  /* synthesized block */
  real_T TimeStampA;                   /* '<Root>/Derivative7' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative7' */
  real_T TimeStampB;                   /* '<Root>/Derivative7' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative7' */
  real_T TimeStampA_a;                 /* '<Root>/Derivative8' */
  real_T LastUAtTimeA_k;               /* '<Root>/Derivative8' */
  real_T TimeStampB_c;                 /* '<Root>/Derivative8' */
  real_T LastUAtTimeB_h;               /* '<Root>/Derivative8' */
  real_T TimeStampA_i;                 /* '<Root>/Derivative1' */
  real_T LastUAtTimeA_c;               /* '<Root>/Derivative1' */
  real_T TimeStampB_cf;                /* '<Root>/Derivative1' */
  real_T LastUAtTimeB_b;               /* '<Root>/Derivative1' */
  real_T TmpRTBAtDerivative9Inport1_Buff;/* synthesized block */
  real_T TimeStampA_b;                 /* '<Root>/Derivative9' */
  real_T LastUAtTimeA_c0;              /* '<Root>/Derivative9' */
  real_T TimeStampB_e;                 /* '<Root>/Derivative9' */
  real_T LastUAtTimeB_e;               /* '<Root>/Derivative9' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope7_PWORK;                      /* '<Root>/Scope7' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_h;                    /* '<S1>/Scope1' */
} DW_position_T;

/* Parameters (default storage) */
struct P_position_T_ {
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
  real_T TmpRTBAtSum2Inport2_InitialCond;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpRTBAtDerivative9Inport1_Init;/* Expression: 0
                                          * Referenced by:
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
struct tag_RTM_position_T {
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
    uint32_T clockTick2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_position_T position_P;

/* Block signals (default storage) */
extern B_position_T position_B;

/* Block states (default storage) */
extern DW_position_T position_DW;

/* External function called from main */
extern void position_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void position_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void position_initialize(void);
extern void position_step0(void);
extern void position_step2(void);
extern void position_terminate(void);

/* Real-time Model object */
extern RT_MODEL_position_T *const position_M;
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
 * '<Root>' : 'position'
 * '<S1>'   : 'position/Right motor1'
 * '<S2>'   : 'position/Right motor1/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_position_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
