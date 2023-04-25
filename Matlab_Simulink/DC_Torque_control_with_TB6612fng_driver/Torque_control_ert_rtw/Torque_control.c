/*
 * File: Torque_control.c
 *
 * Code generated for Simulink model 'Torque_control'.
 *
<<<<<<< HEAD
 * Model version                  : 1.177
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Oct 15 08:20:33 2022
=======
 * Model version                  : 1.200
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Apr 22 17:06:25 2023
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Torque_control.h"
#include "rtwtypes.h"
<<<<<<< HEAD
#include "Torque_control_private.h"
#include "Torque_control_types.h"
#include <string.h>
#include <stddef.h>
#include <math.h>
=======
#include <math.h>
#include "Torque_control_types.h"
#include "Torque_control_private.h"
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_Torque_control_T Torque_control_B;

/* Continuous states */
X_Torque_control_T Torque_control_X;

/* Block states (default storage) */
DW_Torque_control_T Torque_control_DW;

/* Real-time model */
static RT_MODEL_Torque_control_T Torque_control_M_;
RT_MODEL_Torque_control_T *const Torque_control_M = &Torque_control_M_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Torque_control_M->Timing.TaskCounters.TID[2])++;
  if ((Torque_control_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [0.1s, 0.0s] */
    Torque_control_M->Timing.TaskCounters.TID[2] = 0;
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
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Torque_control_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* System initialize for atomic system: */
void Torque_co_Calibrationwrite_Init(DW_Calibrationwrite_Torque_co_T *localDW)
{
  MW_I2C_Mode_Type modename;
  uint32_T i2cname;
  codertarget_arduinobase_inter_T *obj;
  uint32_T varargin_1;

  /* Start for MATLABSystem: '<S1>/Calibration write' */
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
void Torque_control_Calibrationwrite(int16_T rtu_0,
  DW_Calibrationwrite_Torque_co_T *localDW)
{
  int16_T b_x;
  uint8_T b_SwappedDataBytes[3];
  uint8_T SwappedDataBytes[2];
  uint8_T b_x_0[2];

  /* MATLABSystem: '<S1>/Calibration write' */
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
void Torque_co_Calibrationwrite_Term(DW_Calibrationwrite_Torque_co_T *localDW)
{
  /* Terminate for MATLABSystem: '<S1>/Calibration write' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1L) && localDW->obj.isSetupComplete) {
      MW_I2C_Close(localDW->obj.I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Calibration write' */
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
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Torque_control_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void Torque_control_step(void)
{
<<<<<<< HEAD
  /* local block i/o variables */
  int16_T rtb_DataTypeConversion;
=======
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713
  if (rtmIsMajorTimeStep(Torque_control_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Torque_control_M->solverInfo,
                          ((Torque_control_M->Timing.clockTick0+1)*
      Torque_control_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */
<<<<<<< HEAD

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Torque_control_M)) {
    Torque_control_M->Timing.t[0] = rtsiGetT(&Torque_control_M->solverInfo);
  }

  {
    codertarget_arduinobase_i_h3r_T *obj;
    real_T lastTime;
    real_T rtb_Integrator;
    real_T tmp;
    real_T *lastU;
    int32_T rtb_Encoder1_0;
    int16_T rtb_IN1;
    int16_T rtb_IN2;
    uint8_T b_x[2];
    uint8_T output_raw[2];
    uint8_T status;
    if (rtmIsMajorTimeStep(Torque_control_M) &&
        Torque_control_M->Timing.TaskCounters.TID[1] == 0) {
      /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
       *  Constant: '<S1>/Constant2'
       */
      tmp = floor(Torque_control_P.Constant2_Value_f);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 65536.0);
      }

      /* DataTypeConversion: '<S1>/Data Type Conversion' */
      rtb_DataTypeConversion = tmp < 0.0 ? -(int16_T)(uint16_T)-tmp : (int16_T)
        (uint16_T)tmp;
      Torque_control_Calibrationwrite(rtb_DataTypeConversion,
        &Torque_control_DW.Calibrationwrite);
    }

    /* Derivative: '<Root>/Derivative1' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Derivative: '<Root>/Derivative2'
     */
    tmp = Torque_control_M->Timing.t[0];
    if ((Torque_control_DW.TimeStampA >= tmp) && (Torque_control_DW.TimeStampB >=
         tmp)) {
      rtb_Integrator = 0.0;
    } else {
      lastTime = Torque_control_DW.TimeStampA;
      lastU = &Torque_control_DW.LastUAtTimeA;
      if (Torque_control_DW.TimeStampA < Torque_control_DW.TimeStampB) {
        if (Torque_control_DW.TimeStampB < tmp) {
          lastTime = Torque_control_DW.TimeStampB;
          lastU = &Torque_control_DW.LastUAtTimeB;
        }
      } else if (Torque_control_DW.TimeStampA >= tmp) {
        lastTime = Torque_control_DW.TimeStampB;
        lastU = &Torque_control_DW.LastUAtTimeB;
      }

      rtb_Integrator = (Torque_control_P.Constant2_Value_i - *lastU) / (tmp -
        lastTime);
    }

    /* End of Derivative: '<Root>/Derivative1' */
    if (rtmIsMajorTimeStep(Torque_control_M) &&
        Torque_control_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain: '<Root>/Gain5' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      Torque_control_B.Gain5 = Torque_control_P.a / Torque_control_P.b *
        Torque_control_P.Constant2_Value_i;

      /* MATLABSystem: '<S3>/Encoder1' */
      if (Torque_control_DW.obj_j.SampleTime !=
          Torque_control_P.Encoder1_SampleTime) {
        Torque_control_DW.obj_j.SampleTime =
          Torque_control_P.Encoder1_SampleTime;
      }

      if (Torque_control_DW.obj_j.TunablePropsChanged) {
        Torque_control_DW.obj_j.TunablePropsChanged = false;
      }

      MW_EncoderRead(Torque_control_DW.obj_j.Index, &rtb_Encoder1_0);

      /* Gain: '<S7>/Gain' incorporates:
       *  DataTypeConversion: '<S3>/Data Type Conversion1'
       *  Gain: '<S3>/Gain2'
       *  MATLABSystem: '<S3>/Encoder1'
       */
      Torque_control_B.Gain = Torque_control_P.Gain2_Gain * (real_T)
        rtb_Encoder1_0 * Torque_control_P.Gain_Gain;
    }

    /* Derivative: '<Root>/Derivative2' */
    if ((Torque_control_DW.TimeStampA_p >= tmp) &&
        (Torque_control_DW.TimeStampB_n >= tmp)) {
      /* Derivative: '<Root>/Derivative2' */
      Torque_control_B.Derivative2 = 0.0;
    } else {
      lastTime = Torque_control_DW.TimeStampA_p;
      lastU = &Torque_control_DW.LastUAtTimeA_g;
      if (Torque_control_DW.TimeStampA_p < Torque_control_DW.TimeStampB_n) {
        if (Torque_control_DW.TimeStampB_n < tmp) {
          lastTime = Torque_control_DW.TimeStampB_n;
          lastU = &Torque_control_DW.LastUAtTimeB_c;
        }
      } else if (Torque_control_DW.TimeStampA_p >= tmp) {
        lastTime = Torque_control_DW.TimeStampB_n;
        lastU = &Torque_control_DW.LastUAtTimeB_c;
      }

      /* Derivative: '<Root>/Derivative2' */
      Torque_control_B.Derivative2 = (Torque_control_B.Gain - *lastU) / (tmp -
        lastTime);
    }

    /* Sum: '<Root>/Sum2' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    Torque_control_B.Sum2 = Torque_control_P.Constant2_Value_i -
      Torque_control_B.Derivative2;

    /* Sum: '<Root>/Add1' incorporates:
     *  Gain: '<Root>/Gain7'
     *  Gain: '<Root>/Gain8'
     *  Integrator: '<Root>/Integrator'
     *  Sum: '<Root>/Add2'
     */
    Torque_control_B.Add1 = ((1.0 / Torque_control_P.b * rtb_Integrator +
      Torque_control_B.Gain5) + Torque_control_X.Integrator_CSTATE) +
      Torque_control_P.k2 * Torque_control_B.Sum2;
    if (rtmIsMajorTimeStep(Torque_control_M) &&
        Torque_control_M->Timing.TaskCounters.TID[1] == 0) {
    }

    /* MATLAB Function: '<S3>/MATLAB Function4' */
    rtb_Integrator = Torque_control_B.Add1 * 254.0 / 12.0;
    if (rtb_Integrator > 0.0) {
      rtb_IN1 = 1;
      rtb_IN2 = 0;
    } else if (rtb_Integrator < 0.0) {
      rtb_Integrator = fabs(rtb_Integrator);
      rtb_IN1 = 0;
      rtb_IN2 = 1;
    } else {
      rtb_Integrator = 0.0;
      rtb_IN1 = 0;
      rtb_IN2 = 0;
    }

    /* End of MATLAB Function: '<S3>/MATLAB Function4' */

    /* MATLABSystem: '<S3>/Digital Output' */
    writeDigitalPin(5, (uint8_T)rtb_IN1);

    /* MATLABSystem: '<S3>/Digital Output1' */
    writeDigitalPin(7, (uint8_T)rtb_IN2);

    /* MATLABSystem: '<S3>/PWM' */
    obj = &Torque_control_DW.obj_jy;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
    if (!(rtb_Integrator <= 255.0)) {
      rtb_Integrator = 255.0;
    }

    MW_PWM_SetDutyCycle(Torque_control_DW.obj_jy.PWMDriverObj.MW_PWM_HANDLE,
                        rtb_Integrator);

    /* End of MATLABSystem: '<S3>/PWM' */
    if (rtmIsMajorTimeStep(Torque_control_M) &&
        Torque_control_M->Timing.TaskCounters.TID[1] == 0) {
    }

    /* Gain: '<Root>/Gain6' */
    Torque_control_B.Gain6 = Torque_control_P.k1 * Torque_control_B.Sum2;
    if (rtmIsMajorTimeStep(Torque_control_M) &&
        Torque_control_M->Timing.TaskCounters.TID[1] == 0) {
    }

    if (rtmIsMajorTimeStep(Torque_control_M) &&
        Torque_control_M->Timing.TaskCounters.TID[2] == 0) {
      /* MATLABSystem: '<Root>/Current Reg read' */
      if (Torque_control_DW.obj.SampleTime !=
          Torque_control_P.CurrentRegread_SampleTime) {
        Torque_control_DW.obj.SampleTime =
          Torque_control_P.CurrentRegread_SampleTime;
      }

      status = 4U;
      status = MW_I2C_MasterWrite
        (Torque_control_DW.obj.I2CDriverObj.MW_I2C_HANDLE, 64UL, &status, 1UL,
         true, false);
      if (status == 0) {
        MW_I2C_MasterRead(Torque_control_DW.obj.I2CDriverObj.MW_I2C_HANDLE, 64UL,
                          &output_raw[0], 2UL, false, true);
        memcpy((void *)&rtb_IN2, (void *)&output_raw[0], (uint16_T)((size_t)1 *
                sizeof(int16_T)));
        memcpy((void *)&output_raw[0], (void *)&rtb_IN2, (uint16_T)((size_t)2 *
                sizeof(uint8_T)));
        b_x[0] = output_raw[1];
        b_x[1] = output_raw[0];
        memcpy((void *)&rtb_IN1, (void *)&b_x[0], (uint16_T)((size_t)1 * sizeof
                (int16_T)));
      } else {
        rtb_IN1 = 0;
      }

      /* Gain: '<Root>/Gain1' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion'
       *  Gain: '<Root>/Gain'
       *  MATLABSystem: '<Root>/Current Reg read'
       */
      Torque_control_B.Gain1 = (real_T)((int32_T)Torque_control_P.Gain_Gain_p *
        rtb_IN1) * 1.9073486328125E-6 * Torque_control_P.Gain1_Gain;
    }
  }

=======

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Torque_control_M)) {
    Torque_control_M->Timing.t[0] = rtsiGetT(&Torque_control_M->solverInfo);
  }

  {
    codertarget_arduinobase_int_h_T *obj;
    real_T lastTime;
    real_T rtb_Integrator;
    real_T tmp;
    real_T *lastU;
    int32_T rtb_dir;

    /* Derivative: '<Root>/Derivative1' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Derivative: '<Root>/Derivative2'
     */
    tmp = Torque_control_M->Timing.t[0];
    if ((Torque_control_DW.TimeStampA >= tmp) && (Torque_control_DW.TimeStampB >=
         tmp)) {
      rtb_Integrator = 0.0;
    } else {
      lastTime = Torque_control_DW.TimeStampA;
      lastU = &Torque_control_DW.LastUAtTimeA;
      if (Torque_control_DW.TimeStampA < Torque_control_DW.TimeStampB) {
        if (Torque_control_DW.TimeStampB < tmp) {
          lastTime = Torque_control_DW.TimeStampB;
          lastU = &Torque_control_DW.LastUAtTimeB;
        }
      } else if (Torque_control_DW.TimeStampA >= tmp) {
        lastTime = Torque_control_DW.TimeStampB;
        lastU = &Torque_control_DW.LastUAtTimeB;
      }

      rtb_Integrator = (Torque_control_P.Constant2_Value - *lastU) / (tmp -
        lastTime);
    }

    /* End of Derivative: '<Root>/Derivative1' */
    if (rtmIsMajorTimeStep(Torque_control_M)) {
      /* Gain: '<Root>/Gain5' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      Torque_control_B.Gain5 = Torque_control_P.a / Torque_control_P.b *
        Torque_control_P.Constant2_Value;

      /* MATLABSystem: '<S1>/Encoder1' */
      if (Torque_control_DW.obj.SampleTime !=
          Torque_control_P.Encoder1_SampleTime) {
        Torque_control_DW.obj.SampleTime = Torque_control_P.Encoder1_SampleTime;
      }

      if (Torque_control_DW.obj.TunablePropsChanged) {
        Torque_control_DW.obj.TunablePropsChanged = false;
      }

      MW_EncoderRead(Torque_control_DW.obj.Index, &rtb_dir);

      /* Gain: '<S3>/Gain' incorporates:
       *  DataTypeConversion: '<S1>/Data Type Conversion8'
       *  Gain: '<S1>/Gain15'
       *  MATLABSystem: '<S1>/Encoder1'
       */
      Torque_control_B.Gain = Torque_control_P.Gain15_Gain * (real_T)rtb_dir *
        Torque_control_P.Gain_Gain;
    }

    /* Derivative: '<Root>/Derivative2' */
    if ((Torque_control_DW.TimeStampA_p >= tmp) &&
        (Torque_control_DW.TimeStampB_n >= tmp)) {
      /* Derivative: '<Root>/Derivative2' */
      Torque_control_B.Derivative2 = 0.0;
    } else {
      lastTime = Torque_control_DW.TimeStampA_p;
      lastU = &Torque_control_DW.LastUAtTimeA_g;
      if (Torque_control_DW.TimeStampA_p < Torque_control_DW.TimeStampB_n) {
        if (Torque_control_DW.TimeStampB_n < tmp) {
          lastTime = Torque_control_DW.TimeStampB_n;
          lastU = &Torque_control_DW.LastUAtTimeB_c;
        }
      } else if (Torque_control_DW.TimeStampA_p >= tmp) {
        lastTime = Torque_control_DW.TimeStampB_n;
        lastU = &Torque_control_DW.LastUAtTimeB_c;
      }

      /* Derivative: '<Root>/Derivative2' */
      Torque_control_B.Derivative2 = (Torque_control_B.Gain - *lastU) / (tmp -
        lastTime);
    }

    /* Sum: '<Root>/Sum2' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    Torque_control_B.Sum2 = Torque_control_P.Constant2_Value -
      Torque_control_B.Derivative2;

    /* Sum: '<Root>/Add1' incorporates:
     *  Gain: '<Root>/Gain7'
     *  Gain: '<Root>/Gain8'
     *  Integrator: '<Root>/Integrator'
     *  Sum: '<Root>/Add2'
     */
    Torque_control_B.Add1 = ((1.0 / Torque_control_P.b * rtb_Integrator +
      Torque_control_B.Gain5) + Torque_control_X.Integrator_CSTATE) +
      Torque_control_P.k2 * Torque_control_B.Sum2;
    if (rtmIsMajorTimeStep(Torque_control_M)) {
    }

    /* MATLAB Function: '<S1>/MATLAB Function2' */
    rtb_Integrator = Torque_control_B.Add1 * 254.0 / 22.9;
    if (rtb_Integrator > 0.0) {
      rtb_dir = 0;
    } else if (rtb_Integrator < 0.0) {
      rtb_Integrator = fabs(rtb_Integrator);
      rtb_dir = 1;
    } else {
      rtb_Integrator = 0.0;
      rtb_dir = 0;
    }

    /* End of MATLAB Function: '<S1>/MATLAB Function2' */

    /* MATLABSystem: '<S1>/PWM1' */
    obj = &Torque_control_DW.obj_n;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
    if (!(rtb_Integrator <= 255.0)) {
      rtb_Integrator = 255.0;
    }

    MW_PWM_SetDutyCycle(Torque_control_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE,
                        rtb_Integrator);

    /* End of MATLABSystem: '<S1>/PWM1' */

    /* MATLABSystem: '<S1>/PWM2' */
    obj = &Torque_control_DW.obj_b;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7U);
    MW_PWM_SetDutyCycle(Torque_control_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)rtb_dir);
    if (rtmIsMajorTimeStep(Torque_control_M)) {
    }

    /* Gain: '<Root>/Gain6' */
    Torque_control_B.Gain6 = Torque_control_P.k1 * Torque_control_B.Sum2;
    if (rtmIsMajorTimeStep(Torque_control_M)) {
    }
  }

>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713
  if (rtmIsMajorTimeStep(Torque_control_M)) {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative1' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    if (Torque_control_DW.TimeStampA == (rtInf)) {
      Torque_control_DW.TimeStampA = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeA;
    } else if (Torque_control_DW.TimeStampB == (rtInf)) {
      Torque_control_DW.TimeStampB = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeB;
    } else if (Torque_control_DW.TimeStampA < Torque_control_DW.TimeStampB) {
      Torque_control_DW.TimeStampA = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeA;
    } else {
      Torque_control_DW.TimeStampB = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeB;
    }

<<<<<<< HEAD
    *lastU = Torque_control_P.Constant2_Value_i;
=======
    *lastU = Torque_control_P.Constant2_Value;
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713

    /* End of Update for Derivative: '<Root>/Derivative1' */

    /* Update for Derivative: '<Root>/Derivative2' */
    if (Torque_control_DW.TimeStampA_p == (rtInf)) {
      Torque_control_DW.TimeStampA_p = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeA_g;
    } else if (Torque_control_DW.TimeStampB_n == (rtInf)) {
      Torque_control_DW.TimeStampB_n = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeB_c;
    } else if (Torque_control_DW.TimeStampA_p < Torque_control_DW.TimeStampB_n)
    {
      Torque_control_DW.TimeStampA_p = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeA_g;
    } else {
      Torque_control_DW.TimeStampB_n = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeB_c;
    }

    *lastU = Torque_control_B.Gain;

    /* End of Update for Derivative: '<Root>/Derivative2' */
    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
<<<<<<< HEAD
        ((Torque_control_M->Timing.clockTick0 * 1) + 0)
        ;
=======
        Torque_control_M->Timing.t[0];
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

<<<<<<< HEAD
    if (rtmIsMajorTimeStep(Torque_control_M) &&
        Torque_control_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.001s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((Torque_control_M->Timing.clockTick1 * 1) + 0)
        ;
=======
    if (rtmIsMajorTimeStep(Torque_control_M)) {/* Sample time: [0.01s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((Torque_control_M->Timing.clockTick1) * 0.01);
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
<<<<<<< HEAD

    if (rtmIsMajorTimeStep(Torque_control_M) &&
        Torque_control_M->Timing.TaskCounters.TID[2] == 0) {/* Sample time: [0.1s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((Torque_control_M->Timing.clockTick2 * 100) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(2,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
=======
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Torque_control_M)) {
    rt_ertODEUpdateContinuousStates(&Torque_control_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++Torque_control_M->Timing.clockTick0;
    Torque_control_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Torque_control_M->solverInfo);

    {
<<<<<<< HEAD
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
=======
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      Torque_control_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

<<<<<<< HEAD
    if (rtmIsMajorTimeStep(Torque_control_M) &&
        Torque_control_M->Timing.TaskCounters.TID[2] == 0) {
      /* Update absolute timer for sample time: [0.1s, 0.0s] */
      /* The "clockTick2" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.1, which is the step size
       * of the task. Size of "clockTick2" ensures timer will not overflow during the
       * application lifespan selected.
       */
      Torque_control_M->Timing.clockTick2++;
    }

    switch (Torque_control_M->Timing.rtmDbBufReadBuf3) {
     case 0:
      Torque_control_M->Timing.rtmDbBufWriteBuf3 = 1;
      break;

     case 1:
      Torque_control_M->Timing.rtmDbBufWriteBuf3 = 0;
      break;

     default:
      Torque_control_M->Timing.rtmDbBufWriteBuf3 =
        !Torque_control_M->Timing.rtmDbBufLastBufWr3;
      break;
    }

    Torque_control_M->Timing.rtmDbBufClockTick3
      [Torque_control_M->Timing.rtmDbBufWriteBuf3] =
      Torque_control_M->Timing.clockTick0;
    Torque_control_M->Timing.rtmDbBufLastBufWr3 =
      Torque_control_M->Timing.rtmDbBufWriteBuf3;
    Torque_control_M->Timing.rtmDbBufWriteBuf3 = 0xFF;
    rate_scheduler();
  }                                    /* end MajorTimeStep */
}

=======
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713
/* Derivatives for root system: '<Root>' */
void Torque_control_derivatives(void)
{
  XDot_Torque_control_T *_rtXdot;
  _rtXdot = ((XDot_Torque_control_T *) Torque_control_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = Torque_control_B.Gain6;
}

/* Model initialize function */
void Torque_control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Torque_control_M->solverInfo,
                          &Torque_control_M->Timing.simTimeStep);
    rtsiSetTPtr(&Torque_control_M->solverInfo, &rtmGetTPtr(Torque_control_M));
    rtsiSetStepSizePtr(&Torque_control_M->solverInfo,
                       &Torque_control_M->Timing.stepSize0);
    rtsiSetdXPtr(&Torque_control_M->solverInfo, &Torque_control_M->derivs);
    rtsiSetContStatesPtr(&Torque_control_M->solverInfo, (real_T **)
                         &Torque_control_M->contStates);
    rtsiSetNumContStatesPtr(&Torque_control_M->solverInfo,
      &Torque_control_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Torque_control_M->solverInfo,
      &Torque_control_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Torque_control_M->solverInfo,
      &Torque_control_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Torque_control_M->solverInfo,
      &Torque_control_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Torque_control_M->solverInfo, (&rtmGetErrorStatus
      (Torque_control_M)));
    rtsiSetRTModelPtr(&Torque_control_M->solverInfo, Torque_control_M);
  }

  rtsiSetSimTimeStep(&Torque_control_M->solverInfo, MAJOR_TIME_STEP);
  Torque_control_M->intgData.f[0] = Torque_control_M->odeF[0];
  Torque_control_M->contStates = ((X_Torque_control_T *) &Torque_control_X);
  rtsiSetSolverData(&Torque_control_M->solverInfo, (void *)
                    &Torque_control_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&Torque_control_M->solverInfo, false);
  rtsiSetSolverName(&Torque_control_M->solverInfo,"ode1");
  rtmSetTPtr(Torque_control_M, &Torque_control_M->Timing.tArray[0]);
  rtmSetTFinal(Torque_control_M, -1);
<<<<<<< HEAD
  Torque_control_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Torque_control_M->Sizes.checksums[0] = (2803362073U);
  Torque_control_M->Sizes.checksums[1] = (1516702071U);
  Torque_control_M->Sizes.checksums[2] = (124454554U);
  Torque_control_M->Sizes.checksums[3] = (2727842215U);
=======
  Torque_control_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Torque_control_M->Sizes.checksums[0] = (1242110801U);
  Torque_control_M->Sizes.checksums[1] = (1066942541U);
  Torque_control_M->Sizes.checksums[2] = (962801922U);
  Torque_control_M->Sizes.checksums[3] = (340573686U);
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
<<<<<<< HEAD
    static const sysRanDType *systemRan[11];
=======
    static const sysRanDType *systemRan[5];
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713
    Torque_control_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
<<<<<<< HEAD
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
=======
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713
    rteiSetModelMappingInfoPtr(Torque_control_M->extModeInfo,
      &Torque_control_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Torque_control_M->extModeInfo,
                        Torque_control_M->Sizes.checksums);
    rteiSetTPtr(Torque_control_M->extModeInfo, rtmGetTPtr(Torque_control_M));
  }

  {
    /* local block i/o variables */
    int16_T rtb_DataTypeConversion_j;
    codertarget_arduinobase_i_h3r_T *obj;
    codertarget_arduinobase_in_h3_T *obj_0;
    codertarget_arduinobase_inter_T *obj_1;
    int16_T rtb_DataTypeConversion_g;
    uint8_T SwappedDataBytes[2];
    uint8_T b_x[2];
    Torque_control_M->Timing.rtmDbBufReadBuf3 = 0xFF;
    Torque_control_M->Timing.rtmDbBufWriteBuf3 = 0xFF;
    Torque_control_M->Timing.rtmDbBufLastBufWr3 = 0;

    /* InitializeConditions for Derivative: '<Root>/Derivative1' */
    Torque_control_DW.TimeStampA = (rtInf);
    Torque_control_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Integrator: '<Root>/Integrator' */
    Torque_control_X.Integrator_CSTATE = Torque_control_P.Integrator_IC;

    /* InitializeConditions for Derivative: '<Root>/Derivative2' */
    Torque_control_DW.TimeStampA_p = (rtInf);
    Torque_control_DW.TimeStampB_n = (rtInf);
<<<<<<< HEAD

    /* SystemInitialize for Atomic SubSystem: '<Root>/Initialize Function' */
    /* Start for MATLABSystem: '<S4>/Configuration write' */
    Torque_control_DW.obj_l.matlabCodegenIsDeleted = true;
    Torque_control_DW.obj_l.DefaultMaximumBusSpeedInHz = 400000.0;
    Torque_control_DW.obj_l.isInitialized = 0L;
    Torque_control_DW.obj_l.I2CDriverObj.MW_I2C_HANDLE = NULL;
    Torque_control_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_1 = &Torque_control_DW.obj_l;
    Torque_control_DW.obj_l.isSetupComplete = false;
    Torque_control_DW.obj_l.isInitialized = 1L;
    Torque_control_B.modename = MW_I2C_MASTER;
    Torque_control_B.i2cname = 0;
    obj_1->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(Torque_control_B.i2cname,
      Torque_control_B.modename);
    Torque_control_DW.obj_l.BusSpeed = 100000UL;
    Torque_control_B.varargin_1 = Torque_control_DW.obj_l.BusSpeed;
    MW_I2C_SetBusSpeed(Torque_control_DW.obj_l.I2CDriverObj.MW_I2C_HANDLE,
                       Torque_control_B.varargin_1);
    Torque_control_DW.obj_l.isSetupComplete = true;
    Torque_co_Calibrationwrite_Init(&Torque_control_DW.Calibrationwrite_p);
=======
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713

    /* End of SystemInitialize for SubSystem: '<Root>/Initialize Function' */
    Torque_co_Calibrationwrite_Init(&Torque_control_DW.Calibrationwrite);

    /* Start for MATLABSystem: '<S3>/Encoder1' */
    Torque_control_DW.obj_j.Index = 0U;
    Torque_control_DW.obj_j.matlabCodegenIsDeleted = false;
    Torque_control_DW.obj_j.SampleTime = Torque_control_P.Encoder1_SampleTime;
    Torque_control_DW.obj_j.isSetupComplete = false;
    Torque_control_DW.obj_j.isInitialized = 1L;
    MW_EncoderSetup(2UL, 3UL, &Torque_control_DW.obj_j.Index);
    Torque_control_DW.obj_j.isSetupComplete = true;
    Torque_control_DW.obj_j.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S3>/Encoder1' */
    MW_EncoderReset(Torque_control_DW.obj_j.Index);

    /* Start for MATLABSystem: '<S3>/Digital Output' */
    Torque_control_DW.obj_n.matlabCodegenIsDeleted = false;
    Torque_control_DW.obj_n.isInitialized = 1L;
    digitalIOSetup(5, 1);
    Torque_control_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Output1' */
    Torque_control_DW.obj_d.matlabCodegenIsDeleted = false;
    Torque_control_DW.obj_d.isInitialized = 1L;
    digitalIOSetup(7, 1);
    Torque_control_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM' */
    Torque_control_DW.obj_jy.matlabCodegenIsDeleted = true;
    Torque_control_DW.obj_jy.isInitialized = 0L;
    Torque_control_DW.obj_jy.matlabCodegenIsDeleted = false;
    obj = &Torque_control_DW.obj_jy;
    Torque_control_DW.obj_jy.isSetupComplete = false;
    Torque_control_DW.obj_jy.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(4UL, 0.0, 0.0);
    Torque_control_DW.obj_jy.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Current Reg read' */
    Torque_control_DW.obj.matlabCodegenIsDeleted = true;
    Torque_control_DW.obj.DefaultMaximumBusSpeedInHz = 400000.0;
    Torque_control_DW.obj.isInitialized = 0L;
    Torque_control_DW.obj.SampleTime = -1.0;
    Torque_control_DW.obj.I2CDriverObj.MW_I2C_HANDLE = NULL;
    Torque_control_DW.obj.matlabCodegenIsDeleted = false;
    Torque_control_DW.obj.SampleTime =
      Torque_control_P.CurrentRegread_SampleTime;
    obj_0 = &Torque_control_DW.obj;
    Torque_control_DW.obj.isSetupComplete = false;
<<<<<<< HEAD
    Torque_control_DW.obj.isInitialized = 1L;
    Torque_control_B.modename = MW_I2C_MASTER;
    Torque_control_B.i2cname = 0;
    obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(Torque_control_B.i2cname,
      Torque_control_B.modename);
    Torque_control_DW.obj.BusSpeed = 100000UL;
    Torque_control_B.varargin_1 = Torque_control_DW.obj.BusSpeed;
    MW_I2C_SetBusSpeed(Torque_control_DW.obj.I2CDriverObj.MW_I2C_HANDLE,
                       Torque_control_B.varargin_1);
=======
    Torque_control_DW.obj.isInitialized = 1;
    MW_EncoderSetup(2U, 3U, &Torque_control_DW.obj.Index);
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713
    Torque_control_DW.obj.isSetupComplete = true;

    /* Outputs for Atomic SubSystem: '<Root>/Initialize Function' */
    /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
     *  Constant: '<S4>/Constant3'
     */
    Torque_control_B.d = floor(Torque_control_P.Constant3_Value);
    if (rtIsNaN(Torque_control_B.d) || rtIsInf(Torque_control_B.d)) {
      Torque_control_B.d = 0.0;
    } else {
      Torque_control_B.d = fmod(Torque_control_B.d, 65536.0);
    }

<<<<<<< HEAD
    rtb_DataTypeConversion_g = Torque_control_B.d < 0.0 ? -(int16_T)(uint16_T)
      -Torque_control_B.d : (int16_T)(uint16_T)Torque_control_B.d;

    /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

    /* MATLABSystem: '<S4>/Configuration write' */
    memcpy((void *)&SwappedDataBytes[0], (void *)&rtb_DataTypeConversion_g,
           (uint16_T)((size_t)2 * sizeof(uint8_T)));
    b_x[0] = SwappedDataBytes[1];
    b_x[1] = SwappedDataBytes[0];
    memcpy((void *)&rtb_DataTypeConversion_g, (void *)&b_x[0], (uint16_T)
           ((size_t)1 * sizeof(int16_T)));
    memcpy((void *)&SwappedDataBytes[0], (void *)&rtb_DataTypeConversion_g,
           (uint16_T)((size_t)2 * sizeof(uint8_T)));
    Torque_control_B.b_SwappedDataBytes[0] = 0U;
    Torque_control_B.b_SwappedDataBytes[1] = SwappedDataBytes[0];
    Torque_control_B.b_SwappedDataBytes[2] = SwappedDataBytes[1];
    MW_I2C_MasterWrite(Torque_control_DW.obj_l.I2CDriverObj.MW_I2C_HANDLE, 64UL,
                       &Torque_control_B.b_SwappedDataBytes[0], 3UL, false,
                       false);

    /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
     *  Constant: '<S5>/Constant2'
     */
    Torque_control_B.d = floor(Torque_control_P.Constant2_Value);
    if (rtIsNaN(Torque_control_B.d) || rtIsInf(Torque_control_B.d)) {
      Torque_control_B.d = 0.0;
    } else {
      Torque_control_B.d = fmod(Torque_control_B.d, 65536.0);
    }

    /* DataTypeConversion: '<S5>/Data Type Conversion' */
    rtb_DataTypeConversion_j = Torque_control_B.d < 0.0 ? -(int16_T)(uint16_T)
      -Torque_control_B.d : (int16_T)(uint16_T)Torque_control_B.d;
    Torque_control_Calibrationwrite(rtb_DataTypeConversion_j,
      &Torque_control_DW.Calibrationwrite_p);

    /* End of Outputs for SubSystem: '<Root>/Initialize Function' */
=======
    /* Start for MATLABSystem: '<S1>/PWM1' */
    Torque_control_DW.obj_n.matlabCodegenIsDeleted = true;
    Torque_control_DW.obj_n.isInitialized = 0;
    Torque_control_DW.obj_n.matlabCodegenIsDeleted = false;
    obj = &Torque_control_DW.obj_n;
    Torque_control_DW.obj_n.isSetupComplete = false;
    Torque_control_DW.obj_n.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6U, 0.0, 0.0);
    Torque_control_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM2' */
    Torque_control_DW.obj_b.matlabCodegenIsDeleted = true;
    Torque_control_DW.obj_b.isInitialized = 0;
    Torque_control_DW.obj_b.matlabCodegenIsDeleted = false;
    obj = &Torque_control_DW.obj_b;
    Torque_control_DW.obj_b.isSetupComplete = false;
    Torque_control_DW.obj_b.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(7U, 0.0, 0.0);
    Torque_control_DW.obj_b.isSetupComplete = true;
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713
  }
}

/* Model terminate function */
void Torque_control_terminate(void)
{
  codertarget_arduinobase_i_h3r_T *obj;
  Torque_co_Calibrationwrite_Term(&Torque_control_DW.Calibrationwrite);

<<<<<<< HEAD
  /* Terminate for MATLABSystem: '<S3>/Encoder1' */
  if (!Torque_control_DW.obj_j.matlabCodegenIsDeleted) {
    Torque_control_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Torque_control_DW.obj_j.isInitialized == 1L) &&
        Torque_control_DW.obj_j.isSetupComplete) {
=======
  /* Terminate for MATLABSystem: '<S1>/Encoder1' */
  if (!Torque_control_DW.obj.matlabCodegenIsDeleted) {
    Torque_control_DW.obj.matlabCodegenIsDeleted = true;
    if ((Torque_control_DW.obj.isInitialized == 1) &&
        Torque_control_DW.obj.isSetupComplete) {
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713
      MW_EncoderRelease();
    }
  }

<<<<<<< HEAD
  /* End of Terminate for MATLABSystem: '<S3>/Encoder1' */
  /* Terminate for MATLABSystem: '<S3>/Digital Output' */
  if (!Torque_control_DW.obj_n.matlabCodegenIsDeleted) {
    Torque_control_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Output' */

  /* Terminate for MATLABSystem: '<S3>/Digital Output1' */
  if (!Torque_control_DW.obj_d.matlabCodegenIsDeleted) {
    Torque_control_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S3>/PWM' */
  obj = &Torque_control_DW.obj_jy;
  if (!Torque_control_DW.obj_jy.matlabCodegenIsDeleted) {
    Torque_control_DW.obj_jy.matlabCodegenIsDeleted = true;
    if ((Torque_control_DW.obj_jy.isInitialized == 1L) &&
        Torque_control_DW.obj_jy.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_SetDutyCycle(Torque_control_DW.obj_jy.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_Close(Torque_control_DW.obj_jy.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM' */
  /* Terminate for MATLABSystem: '<Root>/Current Reg read' */
  if (!Torque_control_DW.obj.matlabCodegenIsDeleted) {
    Torque_control_DW.obj.matlabCodegenIsDeleted = true;
    if ((Torque_control_DW.obj.isInitialized == 1L) &&
        Torque_control_DW.obj.isSetupComplete) {
      MW_I2C_Close(Torque_control_DW.obj.I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Current Reg read' */
  /* Terminate for Atomic SubSystem: '<Root>/Initialize Function' */
  /* Terminate for MATLABSystem: '<S4>/Configuration write' */
  if (!Torque_control_DW.obj_l.matlabCodegenIsDeleted) {
    Torque_control_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Torque_control_DW.obj_l.isInitialized == 1L) &&
        Torque_control_DW.obj_l.isSetupComplete) {
      MW_I2C_Close(Torque_control_DW.obj_l.I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Configuration write' */
  Torque_co_Calibrationwrite_Term(&Torque_control_DW.Calibrationwrite_p);

  /* End of Terminate for SubSystem: '<Root>/Initialize Function' */
=======
  /* End of Terminate for MATLABSystem: '<S1>/Encoder1' */
  /* Terminate for MATLABSystem: '<S1>/PWM1' */
  obj = &Torque_control_DW.obj_n;
  if (!Torque_control_DW.obj_n.matlabCodegenIsDeleted) {
    Torque_control_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Torque_control_DW.obj_n.isInitialized == 1) &&
        Torque_control_DW.obj_n.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
      MW_PWM_SetDutyCycle(Torque_control_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
      MW_PWM_Close(Torque_control_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM1' */

  /* Terminate for MATLABSystem: '<S1>/PWM2' */
  obj = &Torque_control_DW.obj_b;
  if (!Torque_control_DW.obj_b.matlabCodegenIsDeleted) {
    Torque_control_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Torque_control_DW.obj_b.isInitialized == 1) &&
        Torque_control_DW.obj_b.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7U);
      MW_PWM_SetDutyCycle(Torque_control_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7U);
      MW_PWM_Close(Torque_control_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM2' */
>>>>>>> 765bc2ca8affdd805e4c846c813bca333c8e6713
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
