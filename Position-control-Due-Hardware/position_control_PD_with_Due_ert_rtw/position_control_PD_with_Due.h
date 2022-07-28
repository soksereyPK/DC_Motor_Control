/*
 * File: position_control_PD_with_Due.h
 *
 * Code generated for Simulink model 'position_control_PD_with_Due'.
 *
 * Model version                  : 2.5
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Jul 23 11:28:58 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_position_control_PD_with_Due_h_
#define RTW_HEADER_position_control_PD_with_Due_h_
#ifndef position_control_PD_with_Due_COMMON_INCLUDES_
#define position_control_PD_with_Due_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#endif                       /* position_control_PD_with_Due_COMMON_INCLUDES_ */

#include "position_control_PD_with_Due_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Gain2;                        /* '<Root>/Gain2' */
} B_position_control_PD_with_Du_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S1>/Encoder' */
  codertarget_arduinobase_block_T obj_j;/* '<S1>/Digital Output' */
  codertarget_arduinobase_int_i_T obj_i;/* '<S1>/PWM' */
  real_T TimeStampA;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative' */
  real_T TimeStampB;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative' */
} DW_position_control_PD_with_D_T;

/* Parameters (default storage) */
struct P_position_control_PD_with_Du_T_ {
  real_T kd2;                          /* Variable: kd2
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T kp2;                          /* Variable: kp2
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S1>/Encoder'
                                        */
  real_T Constant3_Value;              /* Expression: 30
                                        * Referenced by: '<Root>/Constant3'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S1>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_position_control_PD_w_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
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
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 */

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
 * '<S1>'   : 'position_control_PD_with_Due/Right motor'
 * '<S2>'   : 'position_control_PD_with_Due/Right motor/MATLAB Function2'
 */
#endif                          /* RTW_HEADER_position_control_PD_with_Due_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
