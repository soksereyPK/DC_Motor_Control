/*
 * File: Position_Control_Single_Loop.h
 *
 * Code generated for Simulink model 'Position_Control_Single_Loop'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Jun 24 10:33:56 2023
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
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include <math.h>
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
  int64m_T J6_Response;                /* '<S1>/Gain' */
  real_T Constant7;                    /* '<Root>/Constant7' */
  real_T ManualSwitch1;                /* '<Root>/Manual Switch1' */
  real_T Sum3;                         /* '<Root>/Sum3' */
  real_T Derivative4;                  /* '<Root>/Derivative4' */
  real_T Gain7;                        /* '<Root>/Gain7' */
  real_T J6_Desire;                    /* '<S1>/J6_Desire' */
} B_Position_Control_Single_Loo_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S1>/Encoder' */
  codertarget_arduinobase_int_b_T obj_o;/* '<S1>/PWM2' */
  codertarget_arduinobase_int_b_T obj_b;/* '<S1>/PWM1' */
  real_T TimeStampA;                   /* '<Root>/Derivative4' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative4' */
  real_T TimeStampB;                   /* '<Root>/Derivative4' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative4' */
  real_T TimeStampA_b;                 /* '<Root>/Derivative5' */
  real_T LastUAtTimeA_c;               /* '<Root>/Derivative5' */
  real_T TimeStampB_e;                 /* '<Root>/Derivative5' */
  real_T LastUAtTimeB_e;               /* '<Root>/Derivative5' */
  real_T TimeStampA_i;                 /* '<Root>/Derivative3' */
  real_T LastUAtTimeA_f;               /* '<Root>/Derivative3' */
  real_T TimeStampB_a;                 /* '<Root>/Derivative3' */
  real_T LastUAtTimeB_d;               /* '<Root>/Derivative3' */
  real_T TimeStampA_in;                /* '<Root>/Derivative2' */
  real_T LastUAtTimeA_cj;              /* '<Root>/Derivative2' */
  real_T TimeStampB_c;                 /* '<Root>/Derivative2' */
  real_T LastUAtTimeB_b;               /* '<Root>/Derivative2' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<S1>/Scope1' */
} DW_Position_Control_Single_Lo_T;

/* Parameters (default storage) */
struct P_Position_Control_Single_Loo_T_ {
  real_T a;                            /* Variable: a
                                        * Referenced by: '<Root>/Gain8'
                                        */
  real_T b;                            /* Variable: b
                                        * Referenced by:
                                        *   '<Root>/Gain8'
                                        *   '<Root>/Gain9'
                                        */
  real_T kd4;                          /* Variable: kd4
                                        * Referenced by: '<Root>/Gain7'
                                        */
  real_T kp4;                          /* Variable: kp4
                                        * Referenced by: '<Root>/Gain6'
                                        */
  real_T Encoder_SampleTime;           /* Expression: 0.01
                                        * Referenced by: '<S1>/Encoder'
                                        */
  real_T Constant5_Value;              /* Expression: 2*pi
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant7_Value;              /* Expression: pi/3
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T J6_Desire_Value;              /* Expression: pi/3
                                        * Referenced by: '<S1>/J6_Desire'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S1>/Gain'
                                        */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch1'
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
 * '<S1>'   : 'Position_Control_Single_Loop/Right motor2'
 * '<S2>'   : 'Position_Control_Single_Loop/Right motor2/MATLAB Function1'
 */
#endif                          /* RTW_HEADER_Position_Control_Single_Loop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
