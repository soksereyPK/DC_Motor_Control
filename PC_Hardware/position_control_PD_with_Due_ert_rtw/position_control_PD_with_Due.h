/*
 * File: position_control_PD_with_Due.h
 *
 * Code generated for Simulink model 'position_control_PD_with_Due'.
 *
 * Model version                  : 2.13
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Jul 28 08:24:25 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_position_control_PD_with_Due_h_
#define RTW_HEADER_position_control_PD_with_Due_h_
#ifndef position_control_PD_with_Due_COMMON_INCLUDES_
#define position_control_PD_with_Due_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_arduino_digitalio.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#endif                       /* position_control_PD_with_Due_COMMON_INCLUDES_ */

#include "position_control_PD_with_Due_types.h"
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
  int128m_T r;
  int64m_T Gain1;                      /* '<S1>/Gain1' */
  real_T Sum5;                         /* '<Root>/Sum5' */
  real_T Gain11;                       /* '<Root>/Gain11' */
  real_T Add4;                         /* '<Root>/Add4' */
  int32_T Encoder;                     /* '<Root>/Encoder' */
} B_position_control_PD_with_Du_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Encoder' */
  codertarget_arduinobase_block_T obj_f;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_block_T obj_d;/* '<Root>/Digital Output' */
  codertarget_arduinobase_int_i_T obj_n;/* '<Root>/PWM' */
  real_T TimeStampA;                   /* '<Root>/Derivative7' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative7' */
  real_T TimeStampB;                   /* '<Root>/Derivative7' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative7' */
  struct {
    void *LoggedData;
  } Scope11_PWORK;                     /* '<Root>/Scope11' */

  struct {
    void *LoggedData;
  } Scope12_PWORK;                     /* '<Root>/Scope12' */

  struct {
    void *LoggedData;
  } Scope9_PWORK;                      /* '<Root>/Scope9' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<Root>/Scope5' */
} DW_position_control_PD_with_D_T;

/* Parameters (default storage) */
struct P_position_control_PD_with_Du_T_ {
  real_T kd2;                          /* Variable: kd2
                                        * Referenced by: '<Root>/Gain11'
                                        */
  real_T kp2;                          /* Variable: kp2
                                        * Referenced by: '<Root>/Gain12'
                                        */
  real_T pi;                           /* Variable: pi
                                        * Referenced by:
                                        *   '<Root>/Constant'
                                        *   '<Root>/Constant4'
                                        *   '<Root>/Sine Wave'
                                        */
  real_T Encoder_SampleTime;           /* Expression: 0.01
                                        * Referenced by: '<Root>/Encoder'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  int64m_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S1>/Gain1'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
};

/* Real-time Model Data Structure */
struct tag_RTM_position_control_PD_w_T {
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
extern P_position_control_PD_with_Du_T position_control_PD_with_Due_P;

/* Block signals (default storage) */
extern B_position_control_PD_with_Du_T position_control_PD_with_Due_B;

/* Block states (default storage) */
extern DW_position_control_PD_with_D_T position_control_PD_with_Due_DW;

/* Model entry point functions */
extern void position_control_PD_with_Due_initialize(void);
extern void position_control_PD_with_Due_step(void);
extern void position_control_PD_with_Due_terminate(void);

/* Real-time Model object */
extern RT_MODEL_position_control_PD__T *const position_control_PD_with_Due_M;
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
 * '<Root>' : 'position_control_PD_with_Due'
 * '<S1>'   : 'position_control_PD_with_Due/Degrees to Radians'
 * '<S2>'   : 'position_control_PD_with_Due/MATLAB Function'
 */
#endif                          /* RTW_HEADER_position_control_PD_with_Due_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
