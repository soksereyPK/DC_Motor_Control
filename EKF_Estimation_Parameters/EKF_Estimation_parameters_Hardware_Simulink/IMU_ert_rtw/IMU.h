/*
 * File: IMU.h
 *
 * Code generated for Simulink model 'IMU'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Aug 10 17:40:42 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_IMU_h_
#define RTW_HEADER_IMU_h_
#ifndef IMU_COMMON_INCLUDES_
#define IMU_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_I2C.h"
#include "io_wrappers.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#endif                                 /* IMU_COMMON_INCLUDES_ */

#include "IMU_types.h"
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
} DW_Calibrationwrite_IMU_T;

/* Block signals (default storage) */
typedef struct {
  real_T Ak[16];
  real_T Ak_m[16];
  real_T UnitDelay2[4];                /* '<Root>/Unit Delay2' */
  real_T x_est[4];                     /* '<Root>/EKF2' */
  real_T Wk[4];
  real_T BNO055IMUSensor_o1[3];        /* '<Root>/BNO055 IMU Sensor' */
  real_T BNO055IMUSensor_o2[3];        /* '<Root>/BNO055 IMU Sensor' */
  int8_T b_I[16];
  uint32_T i2cname;
  MW_I2C_Mode_Type modename;
  uint32_T i2cname_c;
  MW_I2C_Mode_Type modename_k;
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T Gain;                         /* '<S4>/Gain' */
  real_T uk2;
  real_T Derivative2;
  real_T y;
  real_T y_tmp;
  real_T d;
  int16_T b_RegisterValue[3];
  int16_T b_RegisterValue_c[3];
  uint32_T varargin_1;
  uint32_T varargin_1_b;
  uint8_T b_SwappedDataBytes[3];
  uint8_T SwappedDataBytes[2];
  uint8_T b_x[2];
  uint8_T b_SwappedDataBytes_p[2];
  uint8_T SwappedDataBytes_c[2];
  int16_T DataTypeConversion_m;        /* '<S5>/Data Type Conversion' */
  int16_T DataTypeConversion_mm;       /* '<S6>/Data Type Conversion' */
  int16_T DataTypeConversion;          /* '<S1>/Data Type Conversion' */
  uint8_T CastedData;
  uint8_T SwappedDataBytes_f;
  uint8_T status;
} B_IMU_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_no_T obj; /* '<Root>/BNO055 IMU Sensor' */
  codertarget_arduinobase_i_noj_T obj_n;/* '<Root>/Current Reg read' */
  codertarget_arduinobase_int_n_T obj_b;/* '<S4>/Encoder' */
  codertarget_arduinobase_inter_T obj_h;/* '<S5>/Configuration write' */
  codertarget_arduinobase__nojn_T obj_p;/* '<S4>/PWM9' */
  codertarget_arduinobase__nojn_T obj_e;/* '<S4>/PWM10' */
  real_T UnitDelay2_DSTATE[4];         /* '<Root>/Unit Delay2' */
  real_T TimeStampA;                   /* '<Root>/Derivative2' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative2' */
  real_T TimeStampB;                   /* '<Root>/Derivative2' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative2' */
  real_T x_est_p[4];                   /* '<Root>/EKF2' */
  real_T P[16];                        /* '<Root>/EKF2' */
  real_T Qd_est[16];                   /* '<Root>/EKF2' */
  real_T R_est;                        /* '<Root>/EKF2' */
  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  DW_Calibrationwrite_IMU_T Calibrationwrite_p;/* '<S1>/Calibration write' */
  DW_Calibrationwrite_IMU_T Calibrationwrite;/* '<S1>/Calibration write' */
} DW_IMU_T;

/* Parameters (default storage) */
struct P_IMU_T_ {
  real_T BNO055IMUSensor_SampleTime;   /* Expression: 0.01
                                        * Referenced by: '<Root>/BNO055 IMU Sensor'
                                        */
  real_T CurrentRegread_SampleTime;    /* Expression: 0.1
                                        * Referenced by: '<Root>/Current Reg read'
                                        */
  real_T Constant3_Value;              /* Expression: hex2dec("399F")
                                        * Referenced by: '<S5>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: hex2dec("0x2800")
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S4>/Encoder'
                                        */
  real_T UnitDelay2_InitialCondition[4];/* Expression: [0;0;0;0]
                                         * Referenced by: '<Root>/Unit Delay2'
                                         */
  real_T Gain_Gain;                    /* Expression: (2*pi)/(11*4*19.2)
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T uk2_Amp;                      /* Expression: 11
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
  real_T Constant2_Value_a;            /* Expression: hex2dec("2800")
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.001
                                        * Referenced by: '<Root>/Gain1'
                                        */
  int16_T Gain_Gain_g;                 /* Computed Parameter: Gain_Gain_g
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_IMU_T {
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
extern P_IMU_T IMU_P;

/* Block signals (default storage) */
extern B_IMU_T IMU_B;

/* Block states (default storage) */
extern DW_IMU_T IMU_DW;

/* External function called from main */
extern void IMU_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void IMU_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void IMU_initialize(void);
extern void IMU_step0(void);
extern void IMU_step2(void);
extern void IMU_terminate(void);

/* Real-time Model object */
extern RT_MODEL_IMU_T *const IMU_M;
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
 * '<Root>' : 'IMU'
 * '<S1>'   : 'IMU/Calibration every time step'
 * '<S2>'   : 'IMU/EKF2'
 * '<S3>'   : 'IMU/Initialize Function'
 * '<S4>'   : 'IMU/Subsystem1'
 * '<S5>'   : 'IMU/Initialize Function/Subsystem'
 * '<S6>'   : 'IMU/Initialize Function/Subsystem1'
 * '<S7>'   : 'IMU/Subsystem1/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_IMU_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
