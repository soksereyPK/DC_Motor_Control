/*
 * File: Position.h
 *
 * Code generated for Simulink model 'Position'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Aug 26 11:18:31 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Position_h_
#define RTW_HEADER_Position_h_
#ifndef Position_COMMON_INCLUDES_
#define Position_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_I2C.h"
#include "MW_arduino_digitalio.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#endif                                 /* Position_COMMON_INCLUDES_ */

#include "Position_types.h"
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
} DW_Calibrationwrite_Position_T;

/* Block signals (default storage) */
typedef struct {
  uint32_T i2cname;
  MW_I2C_Mode_Type modename;
  real_T Gain;                         /* '<S7>/Gain' */
  real_T Sum3;                         /* '<Root>/Sum3' */
  real_T Derivative6;                  /* '<Root>/Derivative6' */
  real_T Gain10;                       /* '<Root>/Gain10' */
  real_T Add3;                         /* '<Root>/Add3' */
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T d;
  real_T pwm_cal;
  uint32_T varargin_1;
  uint8_T b_SwappedDataBytes[3];
} B_Position_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_cv_T obj; /* '<Root>/Current Reg read' */
  codertarget_arduinobase_int_c_T obj_k;/* '<S3>/Encoder1' */
  codertarget_arduinobase_inter_T obj_a;/* '<S4>/Configuration write' */
  codertarget_arduinobase_block_T obj_l;/* '<S3>/Digital Output1' */
  codertarget_arduinobase_block_T obj_n;/* '<S3>/Digital Output' */
  codertarget_arduinobase_i_cva_T obj_no;/* '<S3>/PWM' */
  real_T TimeStampA;                   /* '<Root>/Derivative6' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative6' */
  real_T TimeStampB;                   /* '<Root>/Derivative6' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative6' */
  real_T TimeStampA_a;                 /* '<Root>/Derivative7' */
  real_T LastUAtTimeA_k;               /* '<Root>/Derivative7' */
  real_T TimeStampB_c;                 /* '<Root>/Derivative7' */
  real_T LastUAtTimeB_h;               /* '<Root>/Derivative7' */
  real_T TimeStampA_i;                 /* '<Root>/Derivative5' */
  real_T LastUAtTimeA_c;               /* '<Root>/Derivative5' */
  real_T TimeStampB_cf;                /* '<Root>/Derivative5' */
  real_T LastUAtTimeB_b;               /* '<Root>/Derivative5' */
  real_T TimeStampA_g;                 /* '<Root>/Derivative4' */
  real_T LastUAtTimeA_d;               /* '<Root>/Derivative4' */
  real_T TimeStampB_i;                 /* '<Root>/Derivative4' */
  real_T LastUAtTimeB_a;               /* '<Root>/Derivative4' */
  struct {
    void *LoggedData;
  } Scope16_PWORK;                     /* '<Root>/Scope16' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<S3>/Scope5' */

  struct {
    void *LoggedData;
  } Scope7_PWORK;                      /* '<Root>/Scope7' */

  struct {
    void *LoggedData;
  } Scope8_PWORK;                      /* '<Root>/Scope8' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  DW_Calibrationwrite_Position_T Calibrationwrite_p;/* '<S1>/Calibration write' */
  DW_Calibrationwrite_Position_T Calibrationwrite;/* '<S1>/Calibration write' */
} DW_Position_T;

/* Parameters (default storage) */
struct P_Position_T_ {
  real_T a;                            /* Variable: a
                                        * Referenced by: '<Root>/Gain11'
                                        */
  real_T b;                            /* Variable: b
                                        * Referenced by:
                                        *   '<Root>/Gain11'
                                        *   '<Root>/Gain12'
                                        */
  real_T kd4;                          /* Variable: kd4
                                        * Referenced by: '<Root>/Gain10'
                                        */
  real_T kp4;                          /* Variable: kp4
                                        * Referenced by: '<Root>/Gain9'
                                        */
  real_T CurrentRegread_SampleTime;    /* Expression: 0.1
                                        * Referenced by: '<Root>/Current Reg read'
                                        */
  real_T Constant3_Value;              /* Expression: hex2dec("399F")
                                        * Referenced by: '<S4>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: hex2dec("0x2800")
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Encoder1_SampleTime;          /* Expression: -1
                                        * Referenced by: '<S3>/Encoder1'
                                        */
  real_T Constant2_Value_b;            /* Expression: hex2dec("2800")
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Gain2_Gain;                   /* Expression: -(2*pi)/(14*4*370)
                                        * Referenced by: '<S3>/Gain2'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T Constant5_Value;              /* Expression: 360
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.001
                                        * Referenced by: '<Root>/Gain1'
                                        */
  int16_T Gain_Gain_j;                 /* Computed Parameter: Gain_Gain_j
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Position_T {
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
extern P_Position_T Position_P;

/* Block signals (default storage) */
extern B_Position_T Position_B;

/* Block states (default storage) */
extern DW_Position_T Position_DW;

/* External function called from main */
extern void Position_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Position_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void Position_initialize(void);
extern void Position_step0(void);
extern void Position_step2(void);
extern void Position_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Position_T *const Position_M;
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
 * '<Root>' : 'Position'
 * '<S1>'   : 'Position/Calibration every time step'
 * '<S2>'   : 'Position/Initialize Function'
 * '<S3>'   : 'Position/Right motor2'
 * '<S4>'   : 'Position/Initialize Function/Subsystem'
 * '<S5>'   : 'Position/Initialize Function/Subsystem1'
 * '<S6>'   : 'Position/Right motor2/MATLAB Function4'
 * '<S7>'   : 'Position/Right motor2/Radians to Degrees'
 */
#endif                                 /* RTW_HEADER_Position_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
