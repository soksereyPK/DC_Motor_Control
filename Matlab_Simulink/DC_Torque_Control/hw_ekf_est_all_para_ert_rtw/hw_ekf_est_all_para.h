/*
 * File: hw_ekf_est_all_para.h
 *
 * Code generated for Simulink model 'hw_ekf_est_all_para'.
 *
 * Model version                  : 4.5
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Aug 17 11:47:30 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_hw_ekf_est_all_para_h_
#define RTW_HEADER_hw_ekf_est_all_para_h_
#ifndef hw_ekf_est_all_para_COMMON_INCLUDES_
#define hw_ekf_est_all_para_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_I2C.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#endif                                /* hw_ekf_est_all_para_COMMON_INCLUDES_ */

#include "hw_ekf_est_all_para_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
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
} DW_Calibrationwrite_hw_ekf_es_T;

/* Block signals (default storage) */
typedef struct {
  real_T Ak[16];
  real_T b_I[16];
  real_T Ak_m[16];
  real_T Wk[4];
  uint32_T i2cname;
  MW_I2C_Mode_Type modename;
  real_T Gain;                         /* '<S6>/Gain' */
  real_T Derivative;                   /* '<Root>/Derivative' */
  real_T SineWave;                     /* '<Root>/Sine Wave' */
  real_T TransferFcn;                  /* '<Root>/Transfer Fcn' */
  real_T current_A;                    /* '<Root>/Gain1' */
  real_T current_mA;                   /* '<Root>/Data Type Conversion' */
  real_T x[4];                         /* '<S7>/MATLAB Function3' */
  real_T P[16];                        /* '<S7>/MATLAB Function3' */
  real_T Delay2[4];                    /* '<S5>/Delay2' */
  real_T Delay3[2];                    /* '<S5>/Delay3' */
  real_T x_n[2];                       /* '<S5>/MATLAB Function1' */
  real_T P_h[4];                       /* '<S5>/MATLAB Function1' */
  real_T rpwm;                         /* '<S6>/MATLAB Function' */
  real_T y_tmp;
  real_T A_idx_1;
  real_T unnamed_idx_0;
  real_T d;
  real32_T DataTypeConversion5;        /* '<Root>/Data Type Conversion5' */
  real32_T DataTypeConversion4;        /* '<Root>/Data Type Conversion4' */
  real32_T DataTypeConversion3;        /* '<Root>/Data Type Conversion3' */
  real32_T DataTypeConversion1;        /* '<Root>/Data Type Conversion1' */
  real32_T DataTypeConversion2;        /* '<Root>/Data Type Conversion2' */
  real32_T w;                          /* '<Root>/Data Type Conversion6' */
  real32_T Ra;                         /* '<Root>/MATLAB Function3' */
  real32_T kt;                         /* '<Root>/MATLAB Function3' */
  real32_T Tc;                         /* '<Root>/MATLAB Function3' */
  real32_T D;                          /* '<Root>/MATLAB Function3' */
  real32_T J;                          /* '<Root>/MATLAB Function3' */
  uint32_T varargin_1;
  uint8_T b_SwappedDataBytes[3];
} B_hw_ekf_est_all_para_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_ls_T obj; /* '<Root>/Current Reg read' */
  codertarget_arduinobase_int_l_T obj_m;/* '<S6>/Encoder' */
  codertarget_arduinobase_inter_T obj_o;/* '<S8>/Configuration write' */
  codertarget_arduinobase_i_lsc_T obj_g;/* '<S6>/PWM9' */
  codertarget_arduinobase_i_lsc_T obj_k;/* '<S6>/PWM10' */
  real_T Delay1_DSTATE[16];            /* '<S7>/Delay1' */
  real_T Delay_DSTATE[4];              /* '<S7>/Delay' */
  real_T Delay2_DSTATE[4];             /* '<S5>/Delay2' */
  real_T Delay3_DSTATE[2];             /* '<S5>/Delay3' */
  real_T TimeStampA;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative' */
  real_T TimeStampB;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative' */
  struct {
    void *LoggedData;
  } Scope7_PWORK;                      /* '<Root>/Scope7' */

  struct {
    void *LoggedData;
  } Scope10_PWORK;                     /* '<Root>/Scope10' */

  struct {
    void *LoggedData;
  } Scope11_PWORK;                     /* '<Root>/Scope11' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<Root>/Scope5' */

  struct {
    void *LoggedData;
  } Scope9_PWORK;                      /* '<Root>/Scope9' */

  struct {
    void *LoggedData;
  } Scope8_PWORK;                      /* '<Root>/Scope8' */

  struct {
    void *LoggedData[2];
  } Scope6_PWORK;                      /* '<Root>/Scope6' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData[2];
  } Scope12_PWORK;                     /* '<Root>/Scope12' */

  int8_T Subsystem_SubsysRanBC;        /* '<Root>/Subsystem' */
  boolean_T Subsystem_MODE;            /* '<Root>/Subsystem' */
  DW_Calibrationwrite_hw_ekf_es_T Calibrationwrite_p;/* '<S1>/Calibration write' */
  DW_Calibrationwrite_hw_ekf_es_T Calibrationwrite;/* '<S1>/Calibration write' */
} DW_hw_ekf_est_all_para_T;

/* Continuous states (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
} X_hw_ekf_est_all_para_T;

/* State derivatives (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
} XDot_hw_ekf_est_all_para_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn_CSTATE;        /* '<Root>/Transfer Fcn' */
} XDis_hw_ekf_est_all_para_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (default storage) */
struct P_hw_ekf_est_all_para_T_ {
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S2>/Constant'
                                       */
  real_T CurrentRegread_SampleTime;    /* Expression: 0.01
                                        * Referenced by: '<Root>/Current Reg read'
                                        */
  real_T Constant3_Value;              /* Expression: hex2dec("399F")
                                        * Referenced by: '<S8>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: hex2dec("0x2800")
                                        * Referenced by: '<S9>/Constant2'
                                        */
  real_T x_Y0;                         /* Computed Parameter: x_Y0
                                        * Referenced by: '<S5>/x'
                                        */
  real_T Delay2_InitialCondition[4];   /* Expression: diag([5,0.1])
                                        * Referenced by: '<S5>/Delay2'
                                        */
  real_T Delay3_InitialCondition[2];   /* Expression: [5;0.4]
                                        * Referenced by: '<S5>/Delay3'
                                        */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S6>/Encoder'
                                        */
  real_T Delay1_InitialCondition[16];  /* Expression: 1e0*diag([10,1,30,10])
                                        * Referenced by: '<S7>/Delay1'
                                        */
  real_T Delay_InitialCondition[4];    /* Expression: [0;0;0;0]
                                        * Referenced by: '<S7>/Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: -(2*pi)/(11*4*19.2)
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T SineWave_Amp;                 /* Expression: 10
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 2*pi*1.2
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.001
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Constant2_Value_g;            /* Expression: hex2dec("2800")
                                        * Referenced by: '<S1>/Constant2'
                                        */
  int16_T Gain_Gain_e;                 /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_hw_ekf_est_all_para_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_hw_ekf_est_all_para_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][1];
  ODE1_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
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
extern P_hw_ekf_est_all_para_T hw_ekf_est_all_para_P;

/* Block signals (default storage) */
extern B_hw_ekf_est_all_para_T hw_ekf_est_all_para_B;

/* Continuous states (default storage) */
extern X_hw_ekf_est_all_para_T hw_ekf_est_all_para_X;

/* Block states (default storage) */
extern DW_hw_ekf_est_all_para_T hw_ekf_est_all_para_DW;

/* Model entry point functions */
extern void hw_ekf_est_all_para_initialize(void);
extern void hw_ekf_est_all_para_step(void);
extern void hw_ekf_est_all_para_terminate(void);

/* Real-time Model object */
extern RT_MODEL_hw_ekf_est_all_para_T *const hw_ekf_est_all_para_M;
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
 * '<Root>' : 'hw_ekf_est_all_para'
 * '<S1>'   : 'hw_ekf_est_all_para/Calibration every time step'
 * '<S2>'   : 'hw_ekf_est_all_para/Compare To Constant'
 * '<S3>'   : 'hw_ekf_est_all_para/Initialize Function'
 * '<S4>'   : 'hw_ekf_est_all_para/MATLAB Function3'
 * '<S5>'   : 'hw_ekf_est_all_para/Subsystem'
 * '<S6>'   : 'hw_ekf_est_all_para/Subsystem1'
 * '<S7>'   : 'hw_ekf_est_all_para/Subsystem2'
 * '<S8>'   : 'hw_ekf_est_all_para/Initialize Function/Subsystem'
 * '<S9>'   : 'hw_ekf_est_all_para/Initialize Function/Subsystem1'
 * '<S10>'  : 'hw_ekf_est_all_para/Subsystem/MATLAB Function1'
 * '<S11>'  : 'hw_ekf_est_all_para/Subsystem1/MATLAB Function'
 * '<S12>'  : 'hw_ekf_est_all_para/Subsystem2/MATLAB Function'
 * '<S13>'  : 'hw_ekf_est_all_para/Subsystem2/MATLAB Function3'
 */
#endif                                 /* RTW_HEADER_hw_ekf_est_all_para_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
