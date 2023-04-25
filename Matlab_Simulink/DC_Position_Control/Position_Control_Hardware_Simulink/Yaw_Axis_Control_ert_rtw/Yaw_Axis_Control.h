/*
 * File: Yaw_Axis_Control.h
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

#ifndef RTW_HEADER_Yaw_Axis_Control_h_
#define RTW_HEADER_Yaw_Axis_Control_h_
#ifndef Yaw_Axis_Control_COMMON_INCLUDES_
#define Yaw_Axis_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#endif                                 /* Yaw_Axis_Control_COMMON_INCLUDES_ */

#include "Yaw_Axis_Control_types.h"
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
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Merge;                        /* '<Root>/Merge' */
  int32_T Encoder1;                    /* '<Root>/Encoder1' */
} B_Yaw_Axis_Control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S2>/Serial Transmit2' */
  real_T DelayInput1_DSTATE;           /* '<S1>/Delay Input1' */
  real_T Encoder1_DSTATE;              /* '<Root>/Encoder1' */
  struct {
    void *LoggedData;
  } Scope18_PWORK;                     /* '<Root>/Scope18' */

  int8_T IfActionSubsystem1_SubsysRanBC;/* '<Root>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<Root>/If Action Subsystem' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<Root>/If Action Subsystem2' */
  int8_T EnabledSubsystem2_SubsysRanBC;/* '<Root>/Enabled Subsystem2' */
} DW_Yaw_Axis_Control_T;

/* Parameters (default storage) */
struct P_Yaw_Axis_Control_T_ {
  real_T DetectChange2_vinit;          /* Mask Parameter: DetectChange2_vinit
                                        * Referenced by: '<S1>/Delay Input1'
                                        */
  real_T SerialTransmit2_Protocol;     /* Expression: 0
                                        * Referenced by: '<S2>/Serial Transmit2'
                                        */
  real_T Constant6_Value;              /* Expression: 3
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant4_Value;              /* Expression: 25
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant3_Value;              /* Expression: 20
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<Root>/Merge'
                                       */
};

/* Real-time Model Data Structure */
struct tag_RTM_Yaw_Axis_Control_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

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
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Yaw_Axis_Control_T Yaw_Axis_Control_P;

/* Block signals (default storage) */
extern B_Yaw_Axis_Control_T Yaw_Axis_Control_B;

/* Block states (default storage) */
extern DW_Yaw_Axis_Control_T Yaw_Axis_Control_DW;

/* Model entry point functions */
extern void Yaw_Axis_Control_initialize(void);
extern void Yaw_Axis_Control_step(void);
extern void Yaw_Axis_Control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Yaw_Axis_Control_T *const Yaw_Axis_Control_M;
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
 * '<Root>' : 'Yaw_Axis_Control'
 * '<S1>'   : 'Yaw_Axis_Control/Detect Change2'
 * '<S2>'   : 'Yaw_Axis_Control/Enabled Subsystem2'
 * '<S3>'   : 'Yaw_Axis_Control/If Action Subsystem'
 * '<S4>'   : 'Yaw_Axis_Control/If Action Subsystem1'
 * '<S5>'   : 'Yaw_Axis_Control/If Action Subsystem2'
 */
#endif                                 /* RTW_HEADER_Yaw_Axis_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
