/*
 * File: Current_test.c
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

#include "Current_test.h"
#include "rtwtypes.h"
#include "Current_test_private.h"
#include "Current_test_types.h"
#include <string.h>
#include <stddef.h>
#include <math.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_Current_test_T Current_test_B;

/* Continuous states */
X_Current_test_T Current_test_X;

/* Block states (default storage) */
DW_Current_test_T Current_test_DW;

/* Real-time model */
static RT_MODEL_Current_test_T Current_test_M_;
RT_MODEL_Current_test_T *const Current_test_M = &Current_test_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Current_test_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(Current_test_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Current_test_M->Timing.TaskCounters.TID[2])++;
  if ((Current_test_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [0.1s, 0.0s] */
    Current_test_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Current_test_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* System initialize for atomic system: */
void Curre_Calibrationwrite_Init(DW_Calibrationwrite_Current_t_T *localDW)
{
  MW_I2C_Mode_Type modename;
  uint32_T i2cname;
  codertarget_arduinobase_inter_T *obj;
  uint32_T varargin_1;

  /* Start for MATLABSystem: '<S2>/Calibration write' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj.isInitialized = 0L;
  localDW->obj.I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1L;
  modename = MW_I2C_MASTER;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, modename);
  localDW->obj.BusSpeed = 100000UL;
  varargin_1 = localDW->obj.BusSpeed;
  MW_I2C_SetBusSpeed(localDW->obj.I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void Current_te_Calibrationwrite(int16_T rtu_0, DW_Calibrationwrite_Current_t_T *
  localDW)
{
  int16_T b_x;
  uint8_T b_SwappedDataBytes[3];
  uint8_T SwappedDataBytes[2];
  uint8_T b_x_0[2];

  /* MATLABSystem: '<S2>/Calibration write' */
  memcpy((void *)&SwappedDataBytes[0], (void *)&rtu_0, (uint16_T)((size_t)2 *
          sizeof(uint8_T)));
  b_x_0[0] = SwappedDataBytes[1];
  b_x_0[1] = SwappedDataBytes[0];
  memcpy((void *)&b_x, (void *)&b_x_0[0], (uint16_T)((size_t)1 * sizeof(int16_T)));
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_x, (uint16_T)((size_t)2 *
          sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 5U;
  b_SwappedDataBytes[1] = SwappedDataBytes[0];
  b_SwappedDataBytes[2] = SwappedDataBytes[1];
  MW_I2C_MasterWrite(localDW->obj.I2CDriverObj.MW_I2C_HANDLE, 64UL,
                     &b_SwappedDataBytes[0], 3UL, false, false);
}

/* Termination for atomic system: */
void Curre_Calibrationwrite_Term(DW_Calibrationwrite_Current_t_T *localDW)
{
  /* Terminate for MATLABSystem: '<S2>/Calibration write' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1L) && localDW->obj.isSetupComplete) {
      MW_I2C_Close(localDW->obj.I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Calibration write' */
}

/* Model step function for TID0 */
void Current_test_step0(void)          /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  int16_T rtb_DataTypeConversion;
  if (rtmIsMajorTimeStep(Current_test_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Current_test_M->solverInfo,
                          ((Current_test_M->Timing.clockTick0+1)*
      Current_test_M->Timing.stepSize0));

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Current_test_M)) {
    Current_test_M->Timing.t[0] = rtsiGetT(&Current_test_M->solverInfo);
  }

  {
    codertarget_arduinobase_i_dvd_T *obj;
    real_T rtb_Integrator2;
    real_T rtb_Lpwm;
    real_T *lastU;
    int32_T rtb_Encoder2_0;

    /* MATLABSystem: '<S1>/Encoder2' */
    if (Current_test_DW.obj_m.SampleTime != Current_test_P.Encoder2_SampleTime)
    {
      Current_test_DW.obj_m.SampleTime = Current_test_P.Encoder2_SampleTime;
    }

    if (Current_test_DW.obj_m.TunablePropsChanged) {
      Current_test_DW.obj_m.TunablePropsChanged = false;
    }

    MW_EncoderRead(Current_test_DW.obj_m.Index, &rtb_Encoder2_0);

    /* Gain: '<S1>/Gain22' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion2'
     *  MATLABSystem: '<S1>/Encoder2'
     */
    Current_test_B.Gain22 = Current_test_P.Gain22_Gain * (real_T)rtb_Encoder2_0;

    /* Derivative: '<Root>/Derivative9' incorporates:
     *  Derivative: '<Root>/Derivative8'
     */
    rtb_Integrator2 = Current_test_M->Timing.t[0];
    if ((Current_test_DW.TimeStampA >= rtb_Integrator2) &&
        (Current_test_DW.TimeStampB >= rtb_Integrator2)) {
      /* Derivative: '<Root>/Derivative9' */
      Current_test_B.Derivative9 = 0.0;
    } else {
      rtb_Lpwm = Current_test_DW.TimeStampA;
      lastU = &Current_test_DW.LastUAtTimeA;
      if (Current_test_DW.TimeStampA < Current_test_DW.TimeStampB) {
        if (Current_test_DW.TimeStampB < rtb_Integrator2) {
          rtb_Lpwm = Current_test_DW.TimeStampB;
          lastU = &Current_test_DW.LastUAtTimeB;
        }
      } else if (Current_test_DW.TimeStampA >= rtb_Integrator2) {
        rtb_Lpwm = Current_test_DW.TimeStampB;
        lastU = &Current_test_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/Derivative9' */
      Current_test_B.Derivative9 = (Current_test_B.Gain22 - *lastU) /
        (rtb_Integrator2 - rtb_Lpwm);
    }

    /* End of Derivative: '<Root>/Derivative9' */
    if (rtmIsMajorTimeStep(Current_test_M)) {
      /* Gain: '<Root>/Gain17' incorporates:
       *  Constant: '<Root>/Constant6'
       */
      Current_test_B.Gain17 = (((Current_test_P.R * Current_test_P.D /
        Current_test_P.Kt + Current_test_P.Kt) + Current_test_P.kpi *
        Current_test_P.D) + Current_test_P.kii * Current_test_P.J) *
        Current_test_P.Constant6_Value;
    }

    /* Derivative: '<Root>/Derivative8' incorporates:
     *  Constant: '<Root>/Constant6'
     */
    if ((Current_test_DW.TimeStampA_p >= rtb_Integrator2) &&
        (Current_test_DW.TimeStampB_b >= rtb_Integrator2)) {
      rtb_Integrator2 = 0.0;
    } else {
      rtb_Lpwm = Current_test_DW.TimeStampA_p;
      lastU = &Current_test_DW.LastUAtTimeA_d;
      if (Current_test_DW.TimeStampA_p < Current_test_DW.TimeStampB_b) {
        if (Current_test_DW.TimeStampB_b < rtb_Integrator2) {
          rtb_Lpwm = Current_test_DW.TimeStampB_b;
          lastU = &Current_test_DW.LastUAtTimeB_o;
        }
      } else if (Current_test_DW.TimeStampA_p >= rtb_Integrator2) {
        rtb_Lpwm = Current_test_DW.TimeStampB_b;
        lastU = &Current_test_DW.LastUAtTimeB_o;
      }

      rtb_Integrator2 = (Current_test_P.Constant6_Value - *lastU) /
        (rtb_Integrator2 - rtb_Lpwm);
    }

    /* RateTransition generated from: '<Root>/Sum8' */
    if (rtmIsMajorTimeStep(Current_test_M)) {
      /* RateTransition generated from: '<Root>/Sum8' */
      Current_test_B.TmpRTBAtSum8Inport2 = Current_test_B.Gain23;
    }

    /* End of RateTransition generated from: '<Root>/Sum8' */

    /* Sum: '<Root>/Sum7' incorporates:
     *  Constant: '<Root>/Constant6'
     */
    Current_test_B.e_w = Current_test_P.Constant6_Value -
      Current_test_B.Derivative9;

    /* Sum: '<Root>/Sum8' incorporates:
     *  Gain: '<Root>/Kp_o1'
     */
    Current_test_B.e_T = Current_test_P.kpo * Current_test_B.e_w -
      Current_test_B.TmpRTBAtSum8Inport2;

    /* Sum: '<Root>/Sum9' incorporates:
     *  Gain: '<Root>/Gain13'
     *  Gain: '<Root>/Gain19'
     *  Gain: '<Root>/Kp_i2'
     *  Integrator: '<Root>/Integrator1'
     *  Integrator: '<Root>/Integrator2'
     *  Sum: '<Root>/Sum13'
     *  Sum: '<Root>/Sum4'
     */
    Current_test_B.Sum9 = (((Current_test_P.R * Current_test_P.J /
      Current_test_P.Kt + Current_test_P.kpi * Current_test_P.J) *
      rtb_Integrator2 + (Current_test_X.Integrator1_CSTATE +
                         Current_test_B.Gain17)) + (Current_test_P.kpi *
      Current_test_B.e_T + Current_test_X.Integrator2_CSTATE)) -
      Current_test_P.Kt * Current_test_B.Derivative9;
    if (rtmIsMajorTimeStep(Current_test_M)) {
    }

    /* MATLAB Function: '<S1>/MATLAB Function4' */
    rtb_Integrator2 = Current_test_B.Sum9 * 254.0 / 22.9;
    if (rtb_Integrator2 > 0.0) {
      rtb_Lpwm = 0.0;
    } else if (rtb_Integrator2 < 0.0) {
      rtb_Lpwm = fabs(rtb_Integrator2);
      rtb_Integrator2 = 0.0;
    } else {
      rtb_Lpwm = 0.0;
      rtb_Integrator2 = 0.0;
    }

    /* End of MATLAB Function: '<S1>/MATLAB Function4' */

    /* MATLABSystem: '<S1>/PWM3' */
    obj = &Current_test_DW.obj_b;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
    if (!(rtb_Lpwm <= 255.0)) {
      rtb_Lpwm = 255.0;
    }

    MW_PWM_SetDutyCycle(Current_test_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
                        rtb_Lpwm);

    /* End of MATLABSystem: '<S1>/PWM3' */

    /* MATLABSystem: '<S1>/PWM4' */
    obj = &Current_test_DW.obj_k;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
    if (!(rtb_Integrator2 <= 255.0)) {
      rtb_Integrator2 = 255.0;
    }

    MW_PWM_SetDutyCycle(Current_test_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE,
                        rtb_Integrator2);

    /* End of MATLABSystem: '<S1>/PWM4' */
    if (rtmIsMajorTimeStep(Current_test_M)) {
    }

    /* Gain: '<Root>/Ki_i2' */
    Current_test_B.Ki_i2 = Current_test_P.kii * Current_test_B.e_T;
    if (rtmIsMajorTimeStep(Current_test_M)) {
      /* Sum: '<Root>/Sum5' incorporates:
       *  Constant: '<Root>/Constant6'
       *  Constant: '<Root>/Constant7'
       *  Gain: '<Root>/Gain21'
       *  Gain: '<Root>/Gain24'
       */
      Current_test_B.Sum5 = Current_test_P.kii * Current_test_P.D *
        Current_test_P.Constant6_Value + Current_test_P.kii * Current_test_P.Tc;

      /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
       *  Constant: '<S2>/Constant2'
       */
      rtb_Integrator2 = floor(Current_test_P.Constant2_Value_e);
      if (rtIsNaN(rtb_Integrator2) || rtIsInf(rtb_Integrator2)) {
        rtb_Integrator2 = 0.0;
      } else {
        rtb_Integrator2 = fmod(rtb_Integrator2, 65536.0);
      }

      /* DataTypeConversion: '<S2>/Data Type Conversion' */
      rtb_DataTypeConversion = rtb_Integrator2 < 0.0 ? -(int16_T)(uint16_T)
        -rtb_Integrator2 : (int16_T)(uint16_T)rtb_Integrator2;
      Current_te_Calibrationwrite(rtb_DataTypeConversion,
        &Current_test_DW.Calibrationwrite);
    }
  }

  if (rtmIsMajorTimeStep(Current_test_M)) {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative9' */
    if (Current_test_DW.TimeStampA == (rtInf)) {
      Current_test_DW.TimeStampA = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeA;
    } else if (Current_test_DW.TimeStampB == (rtInf)) {
      Current_test_DW.TimeStampB = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeB;
    } else if (Current_test_DW.TimeStampA < Current_test_DW.TimeStampB) {
      Current_test_DW.TimeStampA = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeA;
    } else {
      Current_test_DW.TimeStampB = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeB;
    }

    *lastU = Current_test_B.Gain22;

    /* End of Update for Derivative: '<Root>/Derivative9' */

    /* Update for Derivative: '<Root>/Derivative8' incorporates:
     *  Constant: '<Root>/Constant6'
     */
    if (Current_test_DW.TimeStampA_p == (rtInf)) {
      Current_test_DW.TimeStampA_p = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeA_d;
    } else if (Current_test_DW.TimeStampB_b == (rtInf)) {
      Current_test_DW.TimeStampB_b = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeB_o;
    } else if (Current_test_DW.TimeStampA_p < Current_test_DW.TimeStampB_b) {
      Current_test_DW.TimeStampA_p = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeA_d;
    } else {
      Current_test_DW.TimeStampB_b = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeB_o;
    }

    *lastU = Current_test_P.Constant6_Value;

    /* End of Update for Derivative: '<Root>/Derivative8' */
    {
      extmodeErrorCode_T returnCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentSimTime = (extmodeSimulationTime_T)
        ((Current_test_M->Timing.clockTick0 * 1) + 0)
        ;

      /* Trigger External Mode event */
      returnCode = extmodeEvent(1,currentSimTime);
      if (returnCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Current_test_M)) {
    rt_ertODEUpdateContinuousStates(&Current_test_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++Current_test_M->Timing.clockTick0;
    Current_test_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Current_test_M->solverInfo);
    switch (Current_test_M->Timing.rtmDbBufReadBuf3) {
     case 0:
      Current_test_M->Timing.rtmDbBufWriteBuf3 = 1;
      break;

     case 1:
      Current_test_M->Timing.rtmDbBufWriteBuf3 = 0;
      break;

     default:
      Current_test_M->Timing.rtmDbBufWriteBuf3 =
        !Current_test_M->Timing.rtmDbBufLastBufWr3;
      break;
    }

    Current_test_M->Timing.rtmDbBufClockTick3
      [Current_test_M->Timing.rtmDbBufWriteBuf3] =
      Current_test_M->Timing.clockTick0;
    Current_test_M->Timing.rtmDbBufLastBufWr3 =
      Current_test_M->Timing.rtmDbBufWriteBuf3;
    Current_test_M->Timing.rtmDbBufWriteBuf3 = 0xFF;

    /* Update absolute time */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Current_test_M->Timing.clockTick1++;
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Current_test_derivatives(void)
{
  XDot_Current_test_T *_rtXdot;
  _rtXdot = ((XDot_Current_test_T *) Current_test_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Current_test_B.Sum5;

  /* Derivatives for Integrator: '<Root>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = Current_test_B.Ki_i2;
}

/* Model step function for TID2 */
void Current_test_step2(void)          /* Sample time: [0.1s, 0.0s] */
{
  int16_T b_output;
  int16_T b_output_0;
  uint8_T b_x[2];
  uint8_T output_raw[2];
  uint8_T status;

  /* MATLABSystem: '<S1>/Current Reg read1' */
  if (Current_test_DW.obj.SampleTime !=
      Current_test_P.CurrentRegread1_SampleTime) {
    Current_test_DW.obj.SampleTime = Current_test_P.CurrentRegread1_SampleTime;
  }

  status = 4U;
  status = MW_I2C_MasterWrite(Current_test_DW.obj.I2CDriverObj.MW_I2C_HANDLE,
    64UL, &status, 1UL, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(Current_test_DW.obj.I2CDriverObj.MW_I2C_HANDLE, 64UL,
                      &output_raw[0], 2UL, false, true);
    memcpy((void *)&b_output_0, (void *)&output_raw[0], (uint16_T)((size_t)1 *
            sizeof(int16_T)));
    memcpy((void *)&output_raw[0], (void *)&b_output_0, (uint16_T)((size_t)2 *
            sizeof(uint8_T)));
    b_x[0] = output_raw[1];
    b_x[1] = output_raw[0];
    memcpy((void *)&b_output, (void *)&b_x[0], (uint16_T)((size_t)1 * sizeof
            (int16_T)));
  } else {
    b_output = 0;
  }

  /* Gain: '<Root>/Gain23' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion3'
   *  Gain: '<S1>/Gain23'
   *  Gain: '<S1>/Gain25'
   *  MATLABSystem: '<S1>/Current Reg read1'
   */
  Current_test_B.Gain23 = (real_T)((int32_T)Current_test_P.Gain23_Gain *
    b_output) * 1.9073486328125E-6 * Current_test_P.Gain25_Gain *
    Current_test_P.Kt;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Current_test_M->Timing.clockTick2++;
}

/* Model initialize function */
void Current_test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Current_test_M->solverInfo,
                          &Current_test_M->Timing.simTimeStep);
    rtsiSetTPtr(&Current_test_M->solverInfo, &rtmGetTPtr(Current_test_M));
    rtsiSetStepSizePtr(&Current_test_M->solverInfo,
                       &Current_test_M->Timing.stepSize0);
    rtsiSetdXPtr(&Current_test_M->solverInfo, &Current_test_M->derivs);
    rtsiSetContStatesPtr(&Current_test_M->solverInfo, (real_T **)
                         &Current_test_M->contStates);
    rtsiSetNumContStatesPtr(&Current_test_M->solverInfo,
      &Current_test_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Current_test_M->solverInfo,
      &Current_test_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Current_test_M->solverInfo,
      &Current_test_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Current_test_M->solverInfo,
      &Current_test_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Current_test_M->solverInfo, (&rtmGetErrorStatus
      (Current_test_M)));
    rtsiSetRTModelPtr(&Current_test_M->solverInfo, Current_test_M);
  }

  rtsiSetSimTimeStep(&Current_test_M->solverInfo, MAJOR_TIME_STEP);
  Current_test_M->intgData.f[0] = Current_test_M->odeF[0];
  Current_test_M->contStates = ((X_Current_test_T *) &Current_test_X);
  rtsiSetSolverData(&Current_test_M->solverInfo, (void *)
                    &Current_test_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&Current_test_M->solverInfo, false);
  rtsiSetSolverName(&Current_test_M->solverInfo,"ode1");
  rtmSetTPtr(Current_test_M, &Current_test_M->Timing.tArray[0]);
  rtmSetTFinal(Current_test_M, 5.0);
  Current_test_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Current_test_M->Sizes.checksums[0] = (3856688273U);
  Current_test_M->Sizes.checksums[1] = (846330304U);
  Current_test_M->Sizes.checksums[2] = (1892479899U);
  Current_test_M->Sizes.checksums[3] = (2027128956U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    Current_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Current_test_M->extModeInfo,
      &Current_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Current_test_M->extModeInfo,
                        Current_test_M->Sizes.checksums);
    rteiSetTPtr(Current_test_M->extModeInfo, rtmGetTPtr(Current_test_M));
  }

  {
    /* local block i/o variables */
    int16_T rtb_DataTypeConversion_b;
    codertarget_arduinobase_i_dvd_T *obj;
    codertarget_arduinobase_in_dv_T *obj_0;
    codertarget_arduinobase_inter_T *obj_1;
    int16_T rtb_DataTypeConversion_p;
    uint8_T SwappedDataBytes[2];
    uint8_T b_x[2];
    Current_test_M->Timing.rtmDbBufReadBuf3 = 0xFF;
    Current_test_M->Timing.rtmDbBufWriteBuf3 = 0xFF;
    Current_test_M->Timing.rtmDbBufLastBufWr3 = 0;

    /* InitializeConditions for Derivative: '<Root>/Derivative9' */
    Current_test_DW.TimeStampA = (rtInf);
    Current_test_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Integrator: '<Root>/Integrator1' */
    Current_test_X.Integrator1_CSTATE = Current_test_P.Integrator1_IC;

    /* InitializeConditions for Derivative: '<Root>/Derivative8' */
    Current_test_DW.TimeStampA_p = (rtInf);
    Current_test_DW.TimeStampB_b = (rtInf);

    /* InitializeConditions for Integrator: '<Root>/Integrator2' */
    Current_test_X.Integrator2_CSTATE = Current_test_P.Integrator2_IC;

    /* SystemInitialize for Atomic SubSystem: '<S1>/Initialize Function1' */
    /* Start for MATLABSystem: '<S5>/Configuration write' */
    Current_test_DW.obj_f.matlabCodegenIsDeleted = true;
    Current_test_DW.obj_f.DefaultMaximumBusSpeedInHz = 400000.0;
    Current_test_DW.obj_f.isInitialized = 0L;
    Current_test_DW.obj_f.I2CDriverObj.MW_I2C_HANDLE = NULL;
    Current_test_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_1 = &Current_test_DW.obj_f;
    Current_test_DW.obj_f.isSetupComplete = false;
    Current_test_DW.obj_f.isInitialized = 1L;
    Current_test_B.modename = MW_I2C_MASTER;
    Current_test_B.i2cname = 0;
    obj_1->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(Current_test_B.i2cname,
      Current_test_B.modename);
    Current_test_DW.obj_f.BusSpeed = 100000UL;
    Current_test_B.varargin_1 = Current_test_DW.obj_f.BusSpeed;
    MW_I2C_SetBusSpeed(Current_test_DW.obj_f.I2CDriverObj.MW_I2C_HANDLE,
                       Current_test_B.varargin_1);
    Current_test_DW.obj_f.isSetupComplete = true;
    Curre_Calibrationwrite_Init(&Current_test_DW.Calibrationwrite_p);

    /* End of SystemInitialize for SubSystem: '<S1>/Initialize Function1' */

    /* Start for MATLABSystem: '<S1>/Encoder2' */
    Current_test_DW.obj_m.Index = 0U;
    Current_test_DW.obj_m.matlabCodegenIsDeleted = false;
    Current_test_DW.obj_m.SampleTime = Current_test_P.Encoder2_SampleTime;
    Current_test_DW.obj_m.isSetupComplete = false;
    Current_test_DW.obj_m.isInitialized = 1L;
    MW_EncoderSetup(2UL, 3UL, &Current_test_DW.obj_m.Index);
    Current_test_DW.obj_m.isSetupComplete = true;
    Current_test_DW.obj_m.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S1>/Encoder2' */
    MW_EncoderReset(Current_test_DW.obj_m.Index);

    /* Start for MATLABSystem: '<S1>/PWM3' */
    Current_test_DW.obj_b.matlabCodegenIsDeleted = true;
    Current_test_DW.obj_b.isInitialized = 0L;
    Current_test_DW.obj_b.matlabCodegenIsDeleted = false;
    obj = &Current_test_DW.obj_b;
    Current_test_DW.obj_b.isSetupComplete = false;
    Current_test_DW.obj_b.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(8UL, 0.0, 0.0);
    Current_test_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM4' */
    Current_test_DW.obj_k.matlabCodegenIsDeleted = true;
    Current_test_DW.obj_k.isInitialized = 0L;
    Current_test_DW.obj_k.matlabCodegenIsDeleted = false;
    obj = &Current_test_DW.obj_k;
    Current_test_DW.obj_k.isSetupComplete = false;
    Current_test_DW.obj_k.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
    Current_test_DW.obj_k.isSetupComplete = true;
    Curre_Calibrationwrite_Init(&Current_test_DW.Calibrationwrite);

    /* Start for MATLABSystem: '<S1>/Current Reg read1' */
    Current_test_DW.obj.matlabCodegenIsDeleted = true;
    Current_test_DW.obj.DefaultMaximumBusSpeedInHz = 400000.0;
    Current_test_DW.obj.isInitialized = 0L;
    Current_test_DW.obj.SampleTime = -1.0;
    Current_test_DW.obj.I2CDriverObj.MW_I2C_HANDLE = NULL;
    Current_test_DW.obj.matlabCodegenIsDeleted = false;
    Current_test_DW.obj.SampleTime = Current_test_P.CurrentRegread1_SampleTime;
    obj_0 = &Current_test_DW.obj;
    Current_test_DW.obj.isSetupComplete = false;
    Current_test_DW.obj.isInitialized = 1L;
    Current_test_B.modename = MW_I2C_MASTER;
    Current_test_B.i2cname = 0;
    obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(Current_test_B.i2cname,
      Current_test_B.modename);
    Current_test_DW.obj.BusSpeed = 100000UL;
    Current_test_B.varargin_1 = Current_test_DW.obj.BusSpeed;
    MW_I2C_SetBusSpeed(Current_test_DW.obj.I2CDriverObj.MW_I2C_HANDLE,
                       Current_test_B.varargin_1);
    Current_test_DW.obj.isSetupComplete = true;

    /* Outputs for Atomic SubSystem: '<S1>/Initialize Function1' */
    /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
     *  Constant: '<S5>/Constant3'
     */
    Current_test_B.d = floor(Current_test_P.Constant3_Value);
    if (rtIsNaN(Current_test_B.d) || rtIsInf(Current_test_B.d)) {
      Current_test_B.d = 0.0;
    } else {
      Current_test_B.d = fmod(Current_test_B.d, 65536.0);
    }

    rtb_DataTypeConversion_p = Current_test_B.d < 0.0 ? -(int16_T)(uint16_T)
      -Current_test_B.d : (int16_T)(uint16_T)Current_test_B.d;

    /* End of DataTypeConversion: '<S5>/Data Type Conversion' */

    /* MATLABSystem: '<S5>/Configuration write' */
    memcpy((void *)&SwappedDataBytes[0], (void *)&rtb_DataTypeConversion_p,
           (uint16_T)((size_t)2 * sizeof(uint8_T)));
    b_x[0] = SwappedDataBytes[1];
    b_x[1] = SwappedDataBytes[0];
    memcpy((void *)&rtb_DataTypeConversion_p, (void *)&b_x[0], (uint16_T)
           ((size_t)1 * sizeof(int16_T)));
    memcpy((void *)&SwappedDataBytes[0], (void *)&rtb_DataTypeConversion_p,
           (uint16_T)((size_t)2 * sizeof(uint8_T)));
    Current_test_B.b_SwappedDataBytes[0] = 0U;
    Current_test_B.b_SwappedDataBytes[1] = SwappedDataBytes[0];
    Current_test_B.b_SwappedDataBytes[2] = SwappedDataBytes[1];
    MW_I2C_MasterWrite(Current_test_DW.obj_f.I2CDriverObj.MW_I2C_HANDLE, 64UL,
                       &Current_test_B.b_SwappedDataBytes[0], 3UL, false, false);

    /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
     *  Constant: '<S6>/Constant2'
     */
    Current_test_B.d = floor(Current_test_P.Constant2_Value);
    if (rtIsNaN(Current_test_B.d) || rtIsInf(Current_test_B.d)) {
      Current_test_B.d = 0.0;
    } else {
      Current_test_B.d = fmod(Current_test_B.d, 65536.0);
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion' */
    rtb_DataTypeConversion_b = Current_test_B.d < 0.0 ? -(int16_T)(uint16_T)
      -Current_test_B.d : (int16_T)(uint16_T)Current_test_B.d;
    Current_te_Calibrationwrite(rtb_DataTypeConversion_b,
      &Current_test_DW.Calibrationwrite_p);

    /* End of Outputs for SubSystem: '<S1>/Initialize Function1' */
  }
}

/* Model terminate function */
void Current_test_terminate(void)
{
  codertarget_arduinobase_i_dvd_T *obj;

  /* Terminate for MATLABSystem: '<S1>/Encoder2' */
  if (!Current_test_DW.obj_m.matlabCodegenIsDeleted) {
    Current_test_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Current_test_DW.obj_m.isInitialized == 1L) &&
        Current_test_DW.obj_m.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder2' */
  /* Terminate for MATLABSystem: '<S1>/PWM3' */
  obj = &Current_test_DW.obj_b;
  if (!Current_test_DW.obj_b.matlabCodegenIsDeleted) {
    Current_test_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Current_test_DW.obj_b.isInitialized == 1L) &&
        Current_test_DW.obj_b.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
      MW_PWM_SetDutyCycle(Current_test_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
      MW_PWM_Close(Current_test_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM3' */

  /* Terminate for MATLABSystem: '<S1>/PWM4' */
  obj = &Current_test_DW.obj_k;
  if (!Current_test_DW.obj_k.matlabCodegenIsDeleted) {
    Current_test_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((Current_test_DW.obj_k.isInitialized == 1L) &&
        Current_test_DW.obj_k.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(Current_test_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(Current_test_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM4' */
  Curre_Calibrationwrite_Term(&Current_test_DW.Calibrationwrite);

  /* Terminate for MATLABSystem: '<S1>/Current Reg read1' */
  if (!Current_test_DW.obj.matlabCodegenIsDeleted) {
    Current_test_DW.obj.matlabCodegenIsDeleted = true;
    if ((Current_test_DW.obj.isInitialized == 1L) &&
        Current_test_DW.obj.isSetupComplete) {
      MW_I2C_Close(Current_test_DW.obj.I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Current Reg read1' */

  /* Terminate for Atomic SubSystem: '<S1>/Initialize Function1' */
  /* Terminate for MATLABSystem: '<S5>/Configuration write' */
  if (!Current_test_DW.obj_f.matlabCodegenIsDeleted) {
    Current_test_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((Current_test_DW.obj_f.isInitialized == 1L) &&
        Current_test_DW.obj_f.isSetupComplete) {
      MW_I2C_Close(Current_test_DW.obj_f.I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Configuration write' */
  Curre_Calibrationwrite_Term(&Current_test_DW.Calibrationwrite_p);

  /* End of Terminate for SubSystem: '<S1>/Initialize Function1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
