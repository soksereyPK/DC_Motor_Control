/*
 * File: untitled.h
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Aug 17 10:23:45 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_untitled_h_
#define RTW_HEADER_untitled_h_
#ifndef untitled_COMMON_INCLUDES_
#define untitled_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_I2C.h"
#include "MW_PWM.h"
#endif                                 /* untitled_COMMON_INCLUDES_ */

#include "untitled_types.h"
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

/* Block states (default storage) for system '<S1>/Calibration write' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S1>/Calibration write' */
  boolean_T objisempty;                /* '<S1>/Calibration write' */
} DW_Calibrationwrite_untitled_T;

/* Block signals (default storage) */
typedef struct {
  uint32_T i2cname;
  MW_I2C_Mode_Type modename;
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T d;
  uint32_T varargin_1;
  uint8_T b_SwappedDataBytes[3];
} B_untitled_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_b_T obj; /* '<Root>/Current Reg read' */
  codertarget_arduinobase_inter_T obj_m;/* '<S4>/Configuration write' */
  codertarget_arduinobase_in_b5_T obj_l;/* '<Root>/PWM2' */
  codertarget_arduinobase_in_b5_T obj_j;/* '<Root>/PWM1' */
  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  DW_Calibrationwrite_untitled_T Calibrationwrite_p;/* '<S1>/Calibration write' */
  DW_Calibrationwrite_untitled_T Calibrationwrite;/* '<S1>/Calibration write' */
} DW_untitled_T;

/* Parameters (default storage) */
struct P_untitled_T_ {
  real_T CurrentRegread_SampleTime;    /* Expression: 0.1
                                        * Referenced by: '<Root>/Current Reg read'
                                        */
  real_T Constant3_Value;              /* Expression: hex2dec("399F")
                                        * Referenced by: '<S4>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: hex2dec("0x2800")
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Constant2_Value_a;            /* Expression: hex2dec("2800")
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T SineWave1_Amp;                /* Expression: 16
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Bias;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Freq;               /* Expression: 0.5
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Phase;              /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.001
                                        * Referenced by: '<Root>/Gain1'
                                        */
  int16_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_untitled_T {
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
    uint32_T clockTick3;
    uint8_T rtmDbBufReadBuf3;
    uint8_T rtmDbBufWriteBuf3;
    boolean_T rtmDbBufLastBufWr3;
    uint32_T rtmDbBufClockTick3[2];
    struct {
      uint8_T TID[3];
    } TaskCounters;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[4];
  } Timing;
};

/* Block parameters (default storage) */
extern P_untitled_T untitled_P;

/* Block signals (default storage) */
extern B_untitled_T untitled_B;

/* Block states (default storage) */
extern DW_untitled_T untitled_DW;

/* External function called from main */
extern void untitled_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void untitled_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void untitled_initialize(void);
extern void untitled_step0(void);
extern void untitled_step2(void);
extern void untitled_terminate(void);

/* Real-time Model object */
extern RT_MODEL_untitled_T *const untitled_M;
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
 * '<Root>' : 'untitled'
 * '<S1>'   : 'untitled/Calibration every time step'
 * '<S2>'   : 'untitled/Initialize Function'
 * '<S3>'   : 'untitled/MATLAB Function2'
 * '<S4>'   : 'untitled/Initialize Function/Subsystem'
 * '<S5>'   : 'untitled/Initialize Function/Subsystem1'
 */
#endif                                 /* RTW_HEADER_untitled_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
