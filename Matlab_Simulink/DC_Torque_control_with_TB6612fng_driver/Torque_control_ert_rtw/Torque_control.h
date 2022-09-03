/*
 * File: Torque_control.h
 *
 * Code generated for Simulink model 'Torque_control'.
 *
 * Model version                  : 1.39
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Sep  3 11:18:33 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Torque_control_h_
#define RTW_HEADER_Torque_control_h_
#ifndef Torque_control_COMMON_INCLUDES_
#define Torque_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_I2C.h"
#include "MW_arduino_digitalio.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#endif                                 /* Torque_control_COMMON_INCLUDES_ */

#include "Torque_control_types.h"
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

/* Block states (default storage) for system '<S1>/Calibration write' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S1>/Calibration write' */
  boolean_T objisempty;                /* '<S1>/Calibration write' */
} DW_Calibrationwrite_Torque_co_T;

/* Block signals (default storage) */
typedef struct {
  real_T Ak[16];
  real_T b_I[16];
  real_T Ak_m[16];
  real_T Wk[4];
  uint32_T i2cname;
  MW_I2C_Mode_Type modename;
  real_T Gain2;                        /* '<S5>/Gain2' */
  real_T Derivative;                   /* '<Root>/Derivative' */
  real_T SineWave;                     /* '<Root>/Sine Wave' */
  real_T current_A;                    /* '<Root>/Gain3' */
  real_T x[4];                         /* '<S7>/MATLAB Function3' */
  real_T P[16];                        /* '<S7>/MATLAB Function3' */
  real_T x_a[2];                       /* '<S6>/MATLAB Function1' */
  real_T P_n[4];                       /* '<S6>/MATLAB Function1' */
  real_T pwm_cal;
  real_T y_tmp;
  real_T y_tmp_idx_0;
  real_T y_tmp_idx_0_tmp;
  real_T d;
  real32_T a;                          /* '<Root>/Data Type Conversion6' */
  real32_T DataTypeConversion4;        /* '<Root>/Data Type Conversion4' */
  real32_T DataTypeConversion5;        /* '<Root>/Data Type Conversion5' */
  real32_T b;                          /* '<Root>/Data Type Conversion2' */
  real32_T c;                          /* '<Root>/Data Type Conversion3' */
  real32_T w;                          /* '<Root>/Data Type Conversion7' */
  real32_T Ra;                         /* '<Root>/MATLAB Function3' */
  real32_T kt;                         /* '<Root>/MATLAB Function3' */
  real32_T Tc;                         /* '<Root>/MATLAB Function3' */
  real32_T D;                          /* '<Root>/MATLAB Function3' */
  real32_T J;                          /* '<Root>/MATLAB Function3' */
  int32_T Encoder1;                    /* '<S5>/Encoder1' */
  uint32_T varargin_1;
  uint8_T b_SwappedDataBytes[3];
} B_Torque_control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_h3_T obj; /* '<Root>/Current Reg read1' */
  codertarget_arduinobase_int_h_T obj_j;/* '<S5>/Encoder1' */
  codertarget_arduinobase_inter_T obj_c;/* '<S8>/Configuration write' */
  codertarget_arduinobase_block_T obj_b;/* '<S5>/Digital Output1' */
  codertarget_arduinobase_block_T obj_l;/* '<S5>/Digital Output' */
  codertarget_arduinobase_i_h3r_T obj_f;/* '<S5>/PWM' */
  real_T Delay1_DSTATE[16];            /* '<S7>/Delay1' */
  real_T Delay_DSTATE[4];              /* '<S7>/Delay' */
  real_T Delay2_DSTATE[4];             /* '<S6>/Delay2' */
  real_T Delay3_DSTATE[2];             /* '<S6>/Delay3' */
  real_T TimeStampA;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative' */
  real_T TimeStampB;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative' */
  struct {
    void *LoggedData;
  } Scope15_PWORK;                     /* '<Root>/Scope15' */

  struct {
    void *LoggedData;
  } Scope10_PWORK;                     /* '<Root>/Scope10' */

  struct {
    void *LoggedData;
  } Scope11_PWORK;                     /* '<Root>/Scope11' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope12_PWORK;                     /* '<Root>/Scope12' */

  struct {
    void *LoggedData;
  } Scope13_PWORK;                     /* '<Root>/Scope13' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<Root>/Scope5' */

  struct {
    void *LoggedData;
  } Scope22_PWORK;                     /* '<Root>/Scope22' */

  struct {
    void *LoggedData;
  } Scope20_PWORK;                     /* '<Root>/Scope20' */

  struct {
    void *LoggedData;
  } Scope14_PWORK;                     /* '<Root>/Scope14' */

  struct {
    void *LoggedData;
  } Scope6_PWORK;                      /* '<Root>/Scope6' */

  struct {
    void *LoggedData[2];
  } Scope23_PWORK;                     /* '<Root>/Scope23' */

  struct {
    void *LoggedData;
  } Scope5_PWORK_o;                    /* '<S5>/Scope5' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_d;                    /* '<S5>/Scope1' */

  int8_T Subsystem1_SubsysRanBC;       /* '<Root>/Subsystem1' */
  boolean_T Subsystem1_MODE;           /* '<Root>/Subsystem1' */
  DW_Calibrationwrite_Torque_co_T Calibrationwrite_p;/* '<S1>/Calibration write' */
  DW_Calibrationwrite_Torque_co_T Calibrationwrite;/* '<S1>/Calibration write' */
} DW_Torque_control_T;

/* Parameters (default storage) */
struct P_Torque_control_T_ {
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S2>/Constant'
                                       */
  real_T CurrentRegread1_SampleTime;   /* Expression: 0.01
                                        * Referenced by: '<Root>/Current Reg read1'
                                        */
  real_T Constant3_Value;              /* Expression: hex2dec("399F")
                                        * Referenced by: '<S8>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: hex2dec("0x2800")
                                        * Referenced by: '<S9>/Constant2'
                                        */
  real_T Encoder1_SampleTime;          /* Expression: -1
                                        * Referenced by: '<S5>/Encoder1'
                                        */
  real_T x_Y0;                         /* Computed Parameter: x_Y0
                                        * Referenced by: '<S6>/x'
                                        */
  real_T Delay2_InitialCondition[4];   /* Expression: diag([5,0.1])
                                        * Referenced by: '<S6>/Delay2'
                                        */
  real_T Delay3_InitialCondition[2];   /* Expression: [5;0.4]
                                        * Referenced by: '<S6>/Delay3'
                                        */
  real_T Delay1_InitialCondition[16];  /* Expression: 1e0*diag([10,1,30,10])
                                        * Referenced by: '<S7>/Delay1'
                                        */
  real_T Delay_InitialCondition[4];    /* Expression: [0;0;0;0]
                                        * Referenced by: '<S7>/Delay'
                                        */
  real_T Gain2_Gain;                   /* Expression: -(2*pi)/(11*4)
                                        * Referenced by: '<S5>/Gain2'
                                        */
  real_T SineWave_Amp;                 /* Expression: 12
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 2*pi*0.4
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T Gain3_Gain;                   /* Expression: 0.001
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Constant2_Value_a;            /* Expression: hex2dec("2800")
                                        * Referenced by: '<S1>/Constant2'
                                        */
  int16_T Gain2_Gain_h;                /* Computed Parameter: Gain2_Gain_h
                                        * Referenced by: '<Root>/Gain2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Torque_control_T {
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
    uint8_T rtmDbBufReadBuf2;
    uint8_T rtmDbBufWriteBuf2;
    boolean_T rtmDbBufLastBufWr2;
    uint32_T rtmDbBufClockTick2[2];
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Torque_control_T Torque_control_P;

/* Block signals (default storage) */
extern B_Torque_control_T Torque_control_B;

/* Block states (default storage) */
extern DW_Torque_control_T Torque_control_DW;

/* Model entry point functions */
extern void Torque_control_initialize(void);
extern void Torque_control_step(void);
extern void Torque_control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Torque_control_T *const Torque_control_M;
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
 * '<Root>' : 'Torque_control'
 * '<S1>'   : 'Torque_control/Calibration every time step1'
 * '<S2>'   : 'Torque_control/Compare To Constant'
 * '<S3>'   : 'Torque_control/Initialize Function1'
 * '<S4>'   : 'Torque_control/MATLAB Function3'
 * '<S5>'   : 'Torque_control/Right motor1'
 * '<S6>'   : 'Torque_control/Subsystem1'
 * '<S7>'   : 'Torque_control/Subsystem2'
 * '<S8>'   : 'Torque_control/Initialize Function1/Subsystem'
 * '<S9>'   : 'Torque_control/Initialize Function1/Subsystem1'
 * '<S10>'  : 'Torque_control/Right motor1/MATLAB Function4'
 * '<S11>'  : 'Torque_control/Subsystem1/MATLAB Function1'
 * '<S12>'  : 'Torque_control/Subsystem2/MATLAB Function'
 * '<S13>'  : 'Torque_control/Subsystem2/MATLAB Function3'
 */
#endif                                 /* RTW_HEADER_Torque_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
