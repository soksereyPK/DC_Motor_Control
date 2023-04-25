/*
 * File: Torque_control.h
 *
 * Code generated for Simulink model 'Torque_control'.
 *
 * Model version                  : 1.177
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Oct 15 08:20:33 2022
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
} DW_Calibrationwrite_Torque_co_T;

/* Block signals (default storage) */
typedef struct {
  uint32_T i2cname;
  MW_I2C_Mode_Type modename;
  real_T Gain5;                        /* '<Root>/Gain5' */
  real_T Gain;                         /* '<S7>/Gain' */
  real_T Derivative2;                  /* '<Root>/Derivative2' */
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T Add1;                         /* '<Root>/Add1' */
  real_T Gain6;                        /* '<Root>/Gain6' */
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T d;
  uint32_T varargin_1;
  uint8_T b_SwappedDataBytes[3];
} B_Torque_control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_h3_T obj; /* '<Root>/Current Reg read' */
  codertarget_arduinobase_int_h_T obj_j;/* '<S3>/Encoder1' */
  codertarget_arduinobase_inter_T obj_l;/* '<S4>/Configuration write' */
  codertarget_arduinobase_block_T obj_d;/* '<S3>/Digital Output1' */
  codertarget_arduinobase_block_T obj_n;/* '<S3>/Digital Output' */
  codertarget_arduinobase_i_h3r_T obj_jy;/* '<S3>/PWM' */
  real_T TimeStampA;                   /* '<Root>/Derivative1' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative1' */
  real_T TimeStampB;                   /* '<Root>/Derivative1' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative1' */
  real_T TimeStampA_p;                 /* '<Root>/Derivative2' */
  real_T LastUAtTimeA_g;               /* '<Root>/Derivative2' */
  real_T TimeStampB_n;                 /* '<Root>/Derivative2' */
  real_T LastUAtTimeB_c;               /* '<Root>/Derivative2' */
  struct {
    void *LoggedData;
  } Scope29_PWORK;                     /* '<Root>/Scope29' */

  struct {
    void *LoggedData;
  } Scope28_PWORK;                     /* '<Root>/Scope28' */

  struct {
    void *LoggedData;
  } Scope9_PWORK;                      /* '<Root>/Scope9' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<S3>/Scope5' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  DW_Calibrationwrite_Torque_co_T Calibrationwrite_p;/* '<S1>/Calibration write' */
  DW_Calibrationwrite_Torque_co_T Calibrationwrite;/* '<S1>/Calibration write' */
} DW_Torque_control_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
} X_Torque_control_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
} XDot_Torque_control_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
} XDis_Torque_control_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (default storage) */
struct P_Torque_control_T_ {
  real_T a;                            /* Variable: a
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T b;                            /* Variable: b
                                        * Referenced by:
                                        *   '<Root>/Gain5'
                                        *   '<Root>/Gain8'
                                        */
  real_T k1;                           /* Variable: k1
                                        * Referenced by: '<Root>/Gain6'
                                        */
  real_T k2;                           /* Variable: k2
                                        * Referenced by: '<Root>/Gain7'
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
  real_T Encoder1_SampleTime;          /* Expression: 0.001
                                        * Referenced by: '<S3>/Encoder1'
                                        */
  real_T Constant2_Value_f;            /* Expression: hex2dec("2800")
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant2_Value_i;            /* Expression: 100
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T Gain2_Gain;                   /* Expression: -(2*pi)/(11*4*370)
                                        * Referenced by: '<S3>/Gain2'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.001
                                        * Referenced by: '<Root>/Gain1'
                                        */
  int16_T Gain_Gain_p;                 /* Computed Parameter: Gain_Gain_p
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Torque_control_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_Torque_control_T *contStates;
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
extern P_Torque_control_T Torque_control_P;

/* Block signals (default storage) */
extern B_Torque_control_T Torque_control_B;

/* Continuous states (default storage) */
extern X_Torque_control_T Torque_control_X;

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
 * '<S1>'   : 'Torque_control/Calibration every time step'
 * '<S2>'   : 'Torque_control/Initialize Function'
 * '<S3>'   : 'Torque_control/Right motor3'
 * '<S4>'   : 'Torque_control/Initialize Function/Subsystem'
 * '<S5>'   : 'Torque_control/Initialize Function/Subsystem1'
 * '<S6>'   : 'Torque_control/Right motor3/MATLAB Function4'
 * '<S7>'   : 'Torque_control/Right motor3/Radians to Degrees'
 */
#endif                                 /* RTW_HEADER_Torque_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
