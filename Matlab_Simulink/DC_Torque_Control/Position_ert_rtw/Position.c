/*
 * File: Position.c
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

#include "Position.h"
#include "rtwtypes.h"
#include "Position_private.h"
#include "Position_types.h"
#include <string.h>
#include <stddef.h>
#include <math.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_Position_T Position_B;

/* Block states (default storage) */
DW_Position_T Position_DW;

/* Real-time model */
static RT_MODEL_Position_T Position_M_;
RT_MODEL_Position_T *const Position_M = &Position_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Position_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(Position_M, 2));
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
  (Position_M->Timing.TaskCounters.TID[2])++;
  if ((Position_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.1s, 0.0s] */
    Position_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* System initialize for atomic system: */
void Posit_Calibrationwrite_Init(DW_Calibrationwrite_Position_T *localDW)
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
void Position_Calibrationwrite(int16_T rtu_0, DW_Calibrationwrite_Position_T
  *localDW)
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
void Posit_Calibrationwrite_Term(DW_Calibrationwrite_Position_T *localDW)
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

/* Model step function for TID0 */
void Position_step0(void)              /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  int16_T rtb_DataTypeConversion;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  {
    codertarget_arduinobase_i_cva_T *obj;
    real_T rtb_Derivative4;
    real_T rtb_Gain11;
    real_T rtb_Gain12;
    real_T *lastU;
    int32_T rtb_Encoder1_0;
    int16_T rtb_IN1;
    int16_T rtb_IN2;

    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  Constant: '<S1>/Constant2'
     */
    Position_B.pwm_cal = floor(Position_P.Constant2_Value_b);
    if (rtIsNaN(Position_B.pwm_cal) || rtIsInf(Position_B.pwm_cal)) {
      Position_B.pwm_cal = 0.0;
    } else {
      Position_B.pwm_cal = fmod(Position_B.pwm_cal, 65536.0);
    }

    /* DataTypeConversion: '<S1>/Data Type Conversion' */
    rtb_DataTypeConversion = Position_B.pwm_cal < 0.0 ? -(int16_T)(uint16_T)
      -Position_B.pwm_cal : (int16_T)(uint16_T)Position_B.pwm_cal;
    Position_Calibrationwrite(rtb_DataTypeConversion,
      &Position_DW.Calibrationwrite);

    /* MATLABSystem: '<S3>/Encoder1' */
    if (Position_DW.obj_k.SampleTime != Position_P.Encoder1_SampleTime) {
      Position_DW.obj_k.SampleTime = Position_P.Encoder1_SampleTime;
    }

    if (Position_DW.obj_k.TunablePropsChanged) {
      Position_DW.obj_k.TunablePropsChanged = false;
    }

    MW_EncoderRead(Position_DW.obj_k.Index, &rtb_Encoder1_0);

    /* Gain: '<S7>/Gain' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion1'
     *  Gain: '<S3>/Gain2'
     *  MATLABSystem: '<S3>/Encoder1'
     */
    Position_B.Gain = Position_P.Gain2_Gain * (real_T)rtb_Encoder1_0 *
      Position_P.Gain_Gain;

    /* Sum: '<Root>/Sum3' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    Position_B.Sum3 = Position_P.Constant5_Value - Position_B.Gain;

    /* Derivative: '<Root>/Derivative6' incorporates:
     *  Derivative: '<Root>/Derivative4'
     *  Derivative: '<Root>/Derivative5'
     *  Derivative: '<Root>/Derivative7'
     */
    Position_B.pwm_cal = Position_M->Timing.t[0];
    if ((Position_DW.TimeStampA >= Position_B.pwm_cal) &&
        (Position_DW.TimeStampB >= Position_B.pwm_cal)) {
      /* Derivative: '<Root>/Derivative6' */
      Position_B.Derivative6 = 0.0;
    } else {
      rtb_Derivative4 = Position_DW.TimeStampA;
      lastU = &Position_DW.LastUAtTimeA;
      if (Position_DW.TimeStampA < Position_DW.TimeStampB) {
        if (Position_DW.TimeStampB < Position_B.pwm_cal) {
          rtb_Derivative4 = Position_DW.TimeStampB;
          lastU = &Position_DW.LastUAtTimeB;
        }
      } else if (Position_DW.TimeStampA >= Position_B.pwm_cal) {
        rtb_Derivative4 = Position_DW.TimeStampB;
        lastU = &Position_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/Derivative6' incorporates:
       *  Constant: '<Root>/Constant5'
       */
      Position_B.Derivative6 = (Position_P.Constant5_Value - *lastU) /
        (Position_B.pwm_cal - rtb_Derivative4);
    }

    /* End of Derivative: '<Root>/Derivative6' */

    /* Derivative: '<Root>/Derivative7' */
    if ((Position_DW.TimeStampA_a >= Position_B.pwm_cal) &&
        (Position_DW.TimeStampB_c >= Position_B.pwm_cal)) {
      rtb_Derivative4 = 0.0;
    } else {
      rtb_Derivative4 = Position_DW.TimeStampA_a;
      lastU = &Position_DW.LastUAtTimeA_k;
      if (Position_DW.TimeStampA_a < Position_DW.TimeStampB_c) {
        if (Position_DW.TimeStampB_c < Position_B.pwm_cal) {
          rtb_Derivative4 = Position_DW.TimeStampB_c;
          lastU = &Position_DW.LastUAtTimeB_h;
        }
      } else if (Position_DW.TimeStampA_a >= Position_B.pwm_cal) {
        rtb_Derivative4 = Position_DW.TimeStampB_c;
        lastU = &Position_DW.LastUAtTimeB_h;
      }

      rtb_Derivative4 = (Position_B.Derivative6 - *lastU) / (Position_B.pwm_cal
        - rtb_Derivative4);
    }

    /* Gain: '<Root>/Gain12' */
    rtb_Gain12 = 1.0 / Position_P.b * rtb_Derivative4;

    /* Derivative: '<Root>/Derivative5' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    if ((Position_DW.TimeStampA_i >= Position_B.pwm_cal) &&
        (Position_DW.TimeStampB_cf >= Position_B.pwm_cal)) {
      rtb_Derivative4 = 0.0;
    } else {
      rtb_Derivative4 = Position_DW.TimeStampA_i;
      lastU = &Position_DW.LastUAtTimeA_c;
      if (Position_DW.TimeStampA_i < Position_DW.TimeStampB_cf) {
        if (Position_DW.TimeStampB_cf < Position_B.pwm_cal) {
          rtb_Derivative4 = Position_DW.TimeStampB_cf;
          lastU = &Position_DW.LastUAtTimeB_b;
        }
      } else if (Position_DW.TimeStampA_i >= Position_B.pwm_cal) {
        rtb_Derivative4 = Position_DW.TimeStampB_cf;
        lastU = &Position_DW.LastUAtTimeB_b;
      }

      rtb_Derivative4 = (Position_P.Constant5_Value - *lastU) /
        (Position_B.pwm_cal - rtb_Derivative4);
    }

    /* Gain: '<Root>/Gain11' */
    rtb_Gain11 = Position_P.a / Position_P.b * rtb_Derivative4;

    /* Gain: '<Root>/Gain10' */
    Position_B.Gain10 = Position_P.kd4 * Position_B.Sum3;

    /* Derivative: '<Root>/Derivative4' */
    if ((Position_DW.TimeStampA_g >= Position_B.pwm_cal) &&
        (Position_DW.TimeStampB_i >= Position_B.pwm_cal)) {
      rtb_Derivative4 = 0.0;
    } else {
      rtb_Derivative4 = Position_DW.TimeStampA_g;
      lastU = &Position_DW.LastUAtTimeA_d;
      if (Position_DW.TimeStampA_g < Position_DW.TimeStampB_i) {
        if (Position_DW.TimeStampB_i < Position_B.pwm_cal) {
          rtb_Derivative4 = Position_DW.TimeStampB_i;
          lastU = &Position_DW.LastUAtTimeB_a;
        }
      } else if (Position_DW.TimeStampA_g >= Position_B.pwm_cal) {
        rtb_Derivative4 = Position_DW.TimeStampB_i;
        lastU = &Position_DW.LastUAtTimeB_a;
      }

      rtb_Derivative4 = (Position_B.Gain10 - *lastU) / (Position_B.pwm_cal -
        rtb_Derivative4);
    }

    /* Sum: '<Root>/Add3' incorporates:
     *  Gain: '<Root>/Gain9'
     */
    Position_B.Add3 = ((rtb_Gain12 + rtb_Gain11) + Position_P.kp4 *
                       Position_B.Sum3) + rtb_Derivative4;

    /* MATLAB Function: '<S3>/MATLAB Function4' */
    Position_B.pwm_cal = Position_B.Add3 * 254.0 / 12.0;
    if (Position_B.pwm_cal > 0.0) {
      rtb_IN1 = 1;
      rtb_IN2 = 0;
    } else if (Position_B.pwm_cal < 0.0) {
      Position_B.pwm_cal = fabs(Position_B.pwm_cal);
      rtb_IN1 = 0;
      rtb_IN2 = 1;
    } else {
      Position_B.pwm_cal = 0.0;
      rtb_IN1 = 0;
      rtb_IN2 = 0;
    }

    /* End of MATLAB Function: '<S3>/MATLAB Function4' */

    /* MATLABSystem: '<S3>/Digital Output' */
    writeDigitalPin(5, (uint8_T)rtb_IN1);

    /* MATLABSystem: '<S3>/Digital Output1' */
    writeDigitalPin(7, (uint8_T)rtb_IN2);

    /* MATLABSystem: '<S3>/PWM' */
    obj = &Position_DW.obj_no;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
    if (!(Position_B.pwm_cal <= 255.0)) {
      Position_B.pwm_cal = 255.0;
    }

    MW_PWM_SetDutyCycle(Position_DW.obj_no.PWMDriverObj.MW_PWM_HANDLE,
                        Position_B.pwm_cal);

    /* End of MATLABSystem: '<S3>/PWM' */
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative6' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    if (Position_DW.TimeStampA == (rtInf)) {
      Position_DW.TimeStampA = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeA;
    } else if (Position_DW.TimeStampB == (rtInf)) {
      Position_DW.TimeStampB = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeB;
    } else if (Position_DW.TimeStampA < Position_DW.TimeStampB) {
      Position_DW.TimeStampA = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeA;
    } else {
      Position_DW.TimeStampB = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeB;
    }

    *lastU = Position_P.Constant5_Value;

    /* End of Update for Derivative: '<Root>/Derivative6' */

    /* Update for Derivative: '<Root>/Derivative7' */
    if (Position_DW.TimeStampA_a == (rtInf)) {
      Position_DW.TimeStampA_a = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeA_k;
    } else if (Position_DW.TimeStampB_c == (rtInf)) {
      Position_DW.TimeStampB_c = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeB_h;
    } else if (Position_DW.TimeStampA_a < Position_DW.TimeStampB_c) {
      Position_DW.TimeStampA_a = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeA_k;
    } else {
      Position_DW.TimeStampB_c = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeB_h;
    }

    *lastU = Position_B.Derivative6;

    /* End of Update for Derivative: '<Root>/Derivative7' */

    /* Update for Derivative: '<Root>/Derivative5' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    if (Position_DW.TimeStampA_i == (rtInf)) {
      Position_DW.TimeStampA_i = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeA_c;
    } else if (Position_DW.TimeStampB_cf == (rtInf)) {
      Position_DW.TimeStampB_cf = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeB_b;
    } else if (Position_DW.TimeStampA_i < Position_DW.TimeStampB_cf) {
      Position_DW.TimeStampA_i = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeA_c;
    } else {
      Position_DW.TimeStampB_cf = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeB_b;
    }

    *lastU = Position_P.Constant5_Value;

    /* End of Update for Derivative: '<Root>/Derivative5' */

    /* Update for Derivative: '<Root>/Derivative4' */
    if (Position_DW.TimeStampA_g == (rtInf)) {
      Position_DW.TimeStampA_g = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeA_d;
    } else if (Position_DW.TimeStampB_i == (rtInf)) {
      Position_DW.TimeStampB_i = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeB_a;
    } else if (Position_DW.TimeStampA_g < Position_DW.TimeStampB_i) {
      Position_DW.TimeStampA_g = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeA_d;
    } else {
      Position_DW.TimeStampB_i = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeB_a;
    }

    *lastU = Position_B.Gain10;

    /* End of Update for Derivative: '<Root>/Derivative4' */
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Position_M->Timing.t[0] =
    ((time_T)(++Position_M->Timing.clockTick0)) * Position_M->Timing.stepSize0;
  switch (Position_M->Timing.rtmDbBufReadBuf3) {
   case 0:
    Position_M->Timing.rtmDbBufWriteBuf3 = 1;
    break;

   case 1:
    Position_M->Timing.rtmDbBufWriteBuf3 = 0;
    break;

   default:
    Position_M->Timing.rtmDbBufWriteBuf3 =
      !Position_M->Timing.rtmDbBufLastBufWr3;
    break;
  }

  Position_M->Timing.rtmDbBufClockTick3[Position_M->Timing.rtmDbBufWriteBuf3] =
    Position_M->Timing.clockTick0;
  Position_M->Timing.rtmDbBufLastBufWr3 = Position_M->Timing.rtmDbBufWriteBuf3;
  Position_M->Timing.rtmDbBufWriteBuf3 = 0xFF;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Position_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void Position_step2(void)              /* Sample time: [0.1s, 0.0s] */
{
  int16_T b_output;
  int16_T b_output_0;
  uint8_T b_x[2];
  uint8_T output_raw[2];
  uint8_T status;

  /* MATLABSystem: '<Root>/Current Reg read' */
  if (Position_DW.obj.SampleTime != Position_P.CurrentRegread_SampleTime) {
    Position_DW.obj.SampleTime = Position_P.CurrentRegread_SampleTime;
  }

  status = 4U;
  status = MW_I2C_MasterWrite(Position_DW.obj.I2CDriverObj.MW_I2C_HANDLE, 64UL,
    &status, 1UL, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(Position_DW.obj.I2CDriverObj.MW_I2C_HANDLE, 64UL,
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

  /* Gain: '<Root>/Gain1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Gain: '<Root>/Gain'
   *  MATLABSystem: '<Root>/Current Reg read'
   */
  Position_B.Gain1 = (real_T)((int32_T)Position_P.Gain_Gain_j * b_output) *
    1.9073486328125E-6 * Position_P.Gain1_Gain;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Position_M->Timing.clockTick2++;
}

/* Model initialize function */
void Position_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Position_M->solverInfo,
                          &Position_M->Timing.simTimeStep);
    rtsiSetTPtr(&Position_M->solverInfo, &rtmGetTPtr(Position_M));
    rtsiSetStepSizePtr(&Position_M->solverInfo, &Position_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Position_M->solverInfo, (&rtmGetErrorStatus
      (Position_M)));
    rtsiSetRTModelPtr(&Position_M->solverInfo, Position_M);
  }

  rtsiSetSimTimeStep(&Position_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Position_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Position_M, &Position_M->Timing.tArray[0]);
  rtmSetTFinal(Position_M, -1);
  Position_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Position_M->Sizes.checksums[0] = (3538820170U);
  Position_M->Sizes.checksums[1] = (550169561U);
  Position_M->Sizes.checksums[2] = (3122994650U);
  Position_M->Sizes.checksums[3] = (4276601127U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
    Position_M->extModeInfo = (&rt_ExtModeInfo);
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
    systemRan[10] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Position_M->extModeInfo,
      &Position_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Position_M->extModeInfo, Position_M->Sizes.checksums);
    rteiSetTPtr(Position_M->extModeInfo, rtmGetTPtr(Position_M));
  }

  {
    /* local block i/o variables */
    int16_T rtb_DataTypeConversion_j;
    codertarget_arduinobase_i_cva_T *obj;
    codertarget_arduinobase_in_cv_T *obj_0;
    codertarget_arduinobase_inter_T *obj_1;
    int16_T rtb_DataTypeConversion_m;
    uint8_T SwappedDataBytes[2];
    uint8_T b_x[2];
    Position_M->Timing.rtmDbBufReadBuf3 = 0xFF;
    Position_M->Timing.rtmDbBufWriteBuf3 = 0xFF;
    Position_M->Timing.rtmDbBufLastBufWr3 = 0;

    /* InitializeConditions for Derivative: '<Root>/Derivative6' */
    Position_DW.TimeStampA = (rtInf);
    Position_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative7' */
    Position_DW.TimeStampA_a = (rtInf);
    Position_DW.TimeStampB_c = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative5' */
    Position_DW.TimeStampA_i = (rtInf);
    Position_DW.TimeStampB_cf = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative4' */
    Position_DW.TimeStampA_g = (rtInf);
    Position_DW.TimeStampB_i = (rtInf);

    /* SystemInitialize for Atomic SubSystem: '<Root>/Initialize Function' */
    /* Start for MATLABSystem: '<S4>/Configuration write' */
    Position_DW.obj_a.matlabCodegenIsDeleted = true;
    Position_DW.obj_a.DefaultMaximumBusSpeedInHz = 400000.0;
    Position_DW.obj_a.isInitialized = 0L;
    Position_DW.obj_a.I2CDriverObj.MW_I2C_HANDLE = NULL;
    Position_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_1 = &Position_DW.obj_a;
    Position_DW.obj_a.isSetupComplete = false;
    Position_DW.obj_a.isInitialized = 1L;
    Position_B.modename = MW_I2C_MASTER;
    Position_B.i2cname = 0;
    obj_1->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(Position_B.i2cname,
      Position_B.modename);
    Position_DW.obj_a.BusSpeed = 100000UL;
    Position_B.varargin_1 = Position_DW.obj_a.BusSpeed;
    MW_I2C_SetBusSpeed(Position_DW.obj_a.I2CDriverObj.MW_I2C_HANDLE,
                       Position_B.varargin_1);
    Position_DW.obj_a.isSetupComplete = true;
    Posit_Calibrationwrite_Init(&Position_DW.Calibrationwrite_p);

    /* End of SystemInitialize for SubSystem: '<Root>/Initialize Function' */
    Posit_Calibrationwrite_Init(&Position_DW.Calibrationwrite);

    /* Start for MATLABSystem: '<S3>/Encoder1' */
    Position_DW.obj_k.Index = 0U;
    Position_DW.obj_k.matlabCodegenIsDeleted = false;
    Position_DW.obj_k.SampleTime = Position_P.Encoder1_SampleTime;
    Position_DW.obj_k.isSetupComplete = false;
    Position_DW.obj_k.isInitialized = 1L;
    MW_EncoderSetup(2UL, 3UL, &Position_DW.obj_k.Index);
    Position_DW.obj_k.isSetupComplete = true;
    Position_DW.obj_k.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S3>/Encoder1' */
    MW_EncoderReset(Position_DW.obj_k.Index);

    /* Start for MATLABSystem: '<S3>/Digital Output' */
    Position_DW.obj_n.matlabCodegenIsDeleted = false;
    Position_DW.obj_n.isInitialized = 1L;
    digitalIOSetup(5, 1);
    Position_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Output1' */
    Position_DW.obj_l.matlabCodegenIsDeleted = false;
    Position_DW.obj_l.isInitialized = 1L;
    digitalIOSetup(7, 1);
    Position_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM' */
    Position_DW.obj_no.matlabCodegenIsDeleted = true;
    Position_DW.obj_no.isInitialized = 0L;
    Position_DW.obj_no.matlabCodegenIsDeleted = false;
    obj = &Position_DW.obj_no;
    Position_DW.obj_no.isSetupComplete = false;
    Position_DW.obj_no.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(4UL, 0.0, 0.0);
    Position_DW.obj_no.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Current Reg read' */
    Position_DW.obj.matlabCodegenIsDeleted = true;
    Position_DW.obj.DefaultMaximumBusSpeedInHz = 400000.0;
    Position_DW.obj.isInitialized = 0L;
    Position_DW.obj.SampleTime = -1.0;
    Position_DW.obj.I2CDriverObj.MW_I2C_HANDLE = NULL;
    Position_DW.obj.matlabCodegenIsDeleted = false;
    Position_DW.obj.SampleTime = Position_P.CurrentRegread_SampleTime;
    obj_0 = &Position_DW.obj;
    Position_DW.obj.isSetupComplete = false;
    Position_DW.obj.isInitialized = 1L;
    Position_B.modename = MW_I2C_MASTER;
    Position_B.i2cname = 0;
    obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(Position_B.i2cname,
      Position_B.modename);
    Position_DW.obj.BusSpeed = 100000UL;
    Position_B.varargin_1 = Position_DW.obj.BusSpeed;
    MW_I2C_SetBusSpeed(Position_DW.obj.I2CDriverObj.MW_I2C_HANDLE,
                       Position_B.varargin_1);
    Position_DW.obj.isSetupComplete = true;

    /* Outputs for Atomic SubSystem: '<Root>/Initialize Function' */
    /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
     *  Constant: '<S4>/Constant3'
     */
    Position_B.d = floor(Position_P.Constant3_Value);
    if (rtIsNaN(Position_B.d) || rtIsInf(Position_B.d)) {
      Position_B.d = 0.0;
    } else {
      Position_B.d = fmod(Position_B.d, 65536.0);
    }

    rtb_DataTypeConversion_m = Position_B.d < 0.0 ? -(int16_T)(uint16_T)
      -Position_B.d : (int16_T)(uint16_T)Position_B.d;

    /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

    /* MATLABSystem: '<S4>/Configuration write' */
    memcpy((void *)&SwappedDataBytes[0], (void *)&rtb_DataTypeConversion_m,
           (uint16_T)((size_t)2 * sizeof(uint8_T)));
    b_x[0] = SwappedDataBytes[1];
    b_x[1] = SwappedDataBytes[0];
    memcpy((void *)&rtb_DataTypeConversion_m, (void *)&b_x[0], (uint16_T)
           ((size_t)1 * sizeof(int16_T)));
    memcpy((void *)&SwappedDataBytes[0], (void *)&rtb_DataTypeConversion_m,
           (uint16_T)((size_t)2 * sizeof(uint8_T)));
    Position_B.b_SwappedDataBytes[0] = 0U;
    Position_B.b_SwappedDataBytes[1] = SwappedDataBytes[0];
    Position_B.b_SwappedDataBytes[2] = SwappedDataBytes[1];
    MW_I2C_MasterWrite(Position_DW.obj_a.I2CDriverObj.MW_I2C_HANDLE, 64UL,
                       &Position_B.b_SwappedDataBytes[0], 3UL, false, false);

    /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
     *  Constant: '<S5>/Constant2'
     */
    Position_B.d = floor(Position_P.Constant2_Value);
    if (rtIsNaN(Position_B.d) || rtIsInf(Position_B.d)) {
      Position_B.d = 0.0;
    } else {
      Position_B.d = fmod(Position_B.d, 65536.0);
    }

    /* DataTypeConversion: '<S5>/Data Type Conversion' */
    rtb_DataTypeConversion_j = Position_B.d < 0.0 ? -(int16_T)(uint16_T)
      -Position_B.d : (int16_T)(uint16_T)Position_B.d;
    Position_Calibrationwrite(rtb_DataTypeConversion_j,
      &Position_DW.Calibrationwrite_p);

    /* End of Outputs for SubSystem: '<Root>/Initialize Function' */
  }
}

/* Model terminate function */
void Position_terminate(void)
{
  codertarget_arduinobase_i_cva_T *obj;
  Posit_Calibrationwrite_Term(&Position_DW.Calibrationwrite);

  /* Terminate for MATLABSystem: '<S3>/Encoder1' */
  if (!Position_DW.obj_k.matlabCodegenIsDeleted) {
    Position_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((Position_DW.obj_k.isInitialized == 1L) &&
        Position_DW.obj_k.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder1' */
  /* Terminate for MATLABSystem: '<S3>/Digital Output' */
  if (!Position_DW.obj_n.matlabCodegenIsDeleted) {
    Position_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Output' */

  /* Terminate for MATLABSystem: '<S3>/Digital Output1' */
  if (!Position_DW.obj_l.matlabCodegenIsDeleted) {
    Position_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S3>/PWM' */
  obj = &Position_DW.obj_no;
  if (!Position_DW.obj_no.matlabCodegenIsDeleted) {
    Position_DW.obj_no.matlabCodegenIsDeleted = true;
    if ((Position_DW.obj_no.isInitialized == 1L) &&
        Position_DW.obj_no.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_SetDutyCycle(Position_DW.obj_no.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_Close(Position_DW.obj_no.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM' */
  /* Terminate for MATLABSystem: '<Root>/Current Reg read' */
  if (!Position_DW.obj.matlabCodegenIsDeleted) {
    Position_DW.obj.matlabCodegenIsDeleted = true;
    if ((Position_DW.obj.isInitialized == 1L) && Position_DW.obj.isSetupComplete)
    {
      MW_I2C_Close(Position_DW.obj.I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Current Reg read' */
  /* Terminate for Atomic SubSystem: '<Root>/Initialize Function' */
  /* Terminate for MATLABSystem: '<S4>/Configuration write' */
  if (!Position_DW.obj_a.matlabCodegenIsDeleted) {
    Position_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Position_DW.obj_a.isInitialized == 1L) &&
        Position_DW.obj_a.isSetupComplete) {
      MW_I2C_Close(Position_DW.obj_a.I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Configuration write' */
  Posit_Calibrationwrite_Term(&Position_DW.Calibrationwrite_p);

  /* End of Terminate for SubSystem: '<Root>/Initialize Function' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
