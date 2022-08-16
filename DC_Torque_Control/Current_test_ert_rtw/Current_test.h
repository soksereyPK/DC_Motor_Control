/*
 * File: Current_test.h
 *
 * Code generated for Simulink model 'Current_test'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Aug 16 11:52:52 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Current_test_h_
#define RTW_HEADER_Current_test_h_
#ifndef Current_test_COMMON_INCLUDES_
#define Current_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_I2C.h"
#include "MW_PWM.h"
#endif                                 /* Current_test_COMMON_INCLUDES_ */

#include "Current_test_types.h"
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
} DW_Calibrationwrite_Current_t_T;

/* Block signals (default storage) */
typedef struct {
  uint32_T i2cname;
  MW_I2C_Mode_Type modename;
  real_T Gain26;                       /* '<Root>/Gain26' */
  real_T d;
  uint32_T varargin_1;
  uint8_T b_SwappedDataBytes[3];
} B_Current_test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_d_T obj; /* '<Root>/Current Reg read1' */
  codertarget_arduinobase_inter_T obj_d;/* '<S4>/Configuration write' */
  codertarget_arduinobase_in_dv_T obj_l;/* '<Root>/PWM2' */
  codertarget_arduinobase_in_dv_T obj_j;/* '<Root>/PWM1' */
  struct {
    void *LoggedData;
  } Scope22_PWORK;                     /* '<Root>/Scope22' */

  DW_Calibrationwrite_Current_t_T Calibrationwrite_p;/* '<S1>/Calibration write' */
  DW_Calibrationwrite_Current_t_T Calibrationwrite;/* '<S1>/Calibration write' */
} DW_Current_test_T;

/* Parameters (default storage) */
struct P_Current_test_T_ {
  real_T CurrentRegread1_SampleTime;   /* Expression: 0.1
                                        * Referenced by: '<Root>/Current Reg read1'
                                        */
  real_T Constant3_Value;              /* Expression: hex2dec("399F")
                                        * Referenced by: '<S4>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: hex2dec("0x2800")
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Constant2_Value_e;            /* Expression: hex2dec("2800")
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
  real_T Gain26_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<Root>/Gain26'
                                        */
  int16_T Gain25_Gain;                 /* Computed Parameter: Gain25_Gain
                                        * Referenced by: '<Root>/Gain25'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Current_test_T {
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
extern P_Current_test_T Current_test_P;

/* Block signals (default storage) */
extern B_Current_test_T Current_test_B;

/* Block states (default storage) */
extern DW_Current_test_T Current_test_DW;

/* External function called from main */
extern void Current_test_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Current_test_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void Current_test_initialize(void);
extern void Current_test_step0(void);
extern void Current_test_step2(void);
extern void Current_test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Current_test_T *const Current_test_M;
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
 * '<Root>' : 'Current_test'
 * '<S1>'   : 'Current_test/Calibration every time step1'
 * '<S2>'   : 'Current_test/Initialize Function1'
 * '<S3>'   : 'Current_test/MATLAB Function2'
 * '<S4>'   : 'Current_test/Initialize Function1/Subsystem'
 * '<S5>'   : 'Current_test/Initialize Function1/Subsystem1'
 */
#endif                                 /* RTW_HEADER_Current_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
