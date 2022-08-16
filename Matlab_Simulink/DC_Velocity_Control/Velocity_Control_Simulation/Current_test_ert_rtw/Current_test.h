/*
 * File: Current_test.h
 *
 * Code generated for Simulink model 'Current_test'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Aug 16 09:43:42 2022
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
#include "ext_mode.h"
#include "MW_I2C.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#endif                                 /* Current_test_COMMON_INCLUDES_ */

#include "Current_test_types.h"
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

/* Block states (default storage) for system '<S2>/Calibration write' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S2>/Calibration write' */
  boolean_T objisempty;                /* '<S2>/Calibration write' */
} DW_Calibrationwrite_Current_t_T;

/* Block signals (default storage) */
typedef struct {
  uint32_T i2cname;
  MW_I2C_Mode_Type modename;
  real_T Gain22;                       /* '<S1>/Gain22' */
  real_T Derivative9;                  /* '<Root>/Derivative9' */
  real_T Gain17;                       /* '<Root>/Gain17' */
  real_T TmpRTBAtSum8Inport2;          /* '<Root>/Gain23' */
  real_T e_w;                          /* '<Root>/Sum7' */
  real_T e_T;                          /* '<Root>/Sum8' */
  real_T Sum9;                         /* '<Root>/Sum9' */
  real_T Ki_i2;                        /* '<Root>/Ki_i2' */
  real_T Sum5;                         /* '<Root>/Sum5' */
  real_T Gain23;                       /* '<Root>/Gain23' */
  real_T d;
  uint32_T varargin_1;
  uint8_T b_SwappedDataBytes[3];
} B_Current_test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_dv_T obj; /* '<S1>/Current Reg read1' */
  codertarget_arduinobase_int_d_T obj_m;/* '<S1>/Encoder2' */
  codertarget_arduinobase_inter_T obj_f;/* '<S5>/Configuration write' */
  codertarget_arduinobase_i_dvd_T obj_k;/* '<S1>/PWM4' */
  codertarget_arduinobase_i_dvd_T obj_b;/* '<S1>/PWM3' */
  real_T TimeStampA;                   /* '<Root>/Derivative9' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative9' */
  real_T TimeStampB;                   /* '<Root>/Derivative9' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative9' */
  real_T TimeStampA_p;                 /* '<Root>/Derivative8' */
  real_T LastUAtTimeA_d;               /* '<Root>/Derivative8' */
  real_T TimeStampB_b;                 /* '<Root>/Derivative8' */
  real_T LastUAtTimeB_o;               /* '<Root>/Derivative8' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope19_PWORK;                     /* '<Root>/Scope19' */

  struct {
    void *LoggedData;
  } Scope18_PWORK;                     /* '<Root>/Scope18' */

  struct {
    void *LoggedData;
  } Scope17_PWORK;                     /* '<Root>/Scope17' */

  DW_Calibrationwrite_Current_t_T Calibrationwrite_p;/* '<S2>/Calibration write' */
  DW_Calibrationwrite_Current_t_T Calibrationwrite;/* '<S2>/Calibration write' */
} DW_Current_test_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
} X_Current_test_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
} XDot_Current_test_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<Root>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<Root>/Integrator2' */
} XDis_Current_test_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (default storage) */
struct P_Current_test_T_ {
  real_T D;                            /* Variable: D
                                        * Referenced by:
                                        *   '<Root>/Gain17'
                                        *   '<Root>/Gain21'
                                        */
  real_T J;                            /* Variable: J
                                        * Referenced by:
                                        *   '<Root>/Gain13'
                                        *   '<Root>/Gain17'
                                        */
  real_T Kt;                           /* Variable: Kt
                                        * Referenced by:
                                        *   '<Root>/Gain13'
                                        *   '<Root>/Gain17'
                                        *   '<Root>/Gain19'
                                        *   '<Root>/Gain23'
                                        */
  real_T R;                            /* Variable: R
                                        * Referenced by:
                                        *   '<Root>/Gain13'
                                        *   '<Root>/Gain17'
                                        */
  real_T Tc;                           /* Variable: Tc
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T kii;                          /* Variable: kii
                                        * Referenced by:
                                        *   '<Root>/Gain17'
                                        *   '<Root>/Gain21'
                                        *   '<Root>/Gain24'
                                        *   '<Root>/Ki_i2'
                                        */
  real_T kpi;                          /* Variable: kpi
                                        * Referenced by:
                                        *   '<Root>/Gain13'
                                        *   '<Root>/Gain17'
                                        *   '<Root>/Kp_i2'
                                        */
  real_T kpo;                          /* Variable: kpo
                                        * Referenced by: '<Root>/Kp_o1'
                                        */
  real_T CurrentRegread1_SampleTime;   /* Expression: 0.1
                                        * Referenced by: '<S1>/Current Reg read1'
                                        */
  real_T Encoder2_SampleTime;          /* Expression: -1
                                        * Referenced by: '<S1>/Encoder2'
                                        */
  real_T Constant3_Value;              /* Expression: hex2dec("399F")
                                        * Referenced by: '<S5>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: hex2dec("0x2800")
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T Gain22_Gain;                  /* Expression: (2*pi)/(11*4*19.2)
                                        * Referenced by: '<S1>/Gain22'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T Constant6_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator2'
                                        */
  real_T Constant2_Value_e;            /* Expression: hex2dec("2800")
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T Gain25_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<S1>/Gain25'
                                        */
  int16_T Gain23_Gain;                 /* Computed Parameter: Gain23_Gain
                                        * Referenced by: '<S1>/Gain23'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Current_test_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_Current_test_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][2];
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

/* Continuous states (default storage) */
extern X_Current_test_T Current_test_X;

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
 * '<S1>'   : 'Current_test/Subsystem'
 * '<S2>'   : 'Current_test/Subsystem/Calibration every time step1'
 * '<S3>'   : 'Current_test/Subsystem/Initialize Function1'
 * '<S4>'   : 'Current_test/Subsystem/MATLAB Function4'
 * '<S5>'   : 'Current_test/Subsystem/Initialize Function1/Subsystem'
 * '<S6>'   : 'Current_test/Subsystem/Initialize Function1/Subsystem1'
 */
#endif                                 /* RTW_HEADER_Current_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
