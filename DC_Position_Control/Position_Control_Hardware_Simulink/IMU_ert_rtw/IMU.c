/*
 * File: IMU.c
 *
 * Code generated for Simulink model 'IMU'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Aug 10 16:46:32 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "IMU.h"
#include "rtwtypes.h"
#include "IMU_types.h"
#include "IMU_private.h"
#include <string.h>
#include <stddef.h>
#include <math.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_IMU_T IMU_B;

/* Block states (default storage) */
DW_IMU_T IMU_DW;

/* Real-time model */
static RT_MODEL_IMU_T IMU_M_;
RT_MODEL_IMU_T *const IMU_M = &IMU_M_;

/* Forward declaration for local functions */
static void IMU_SystemCore_setup(codertarget_arduinobase_int_n_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void IMU_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(IMU_M, 2));
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
  (IMU_M->Timing.TaskCounters.TID[2])++;
  if ((IMU_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.1s, 0.0s] */
    IMU_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* System initialize for atomic system: */
void IMU_Calibrationwrite_Init(DW_Calibrationwrite_IMU_T *localDW)
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
void IMU_Calibrationwrite(int16_T rtu_0, DW_Calibrationwrite_IMU_T *localDW)
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
void IMU_Calibrationwrite_Term(DW_Calibrationwrite_IMU_T *localDW)
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

static void IMU_SystemCore_setup(codertarget_arduinobase_int_n_T *obj)
{
  i_codertarget_arduinobase_int_T *obj_0;
  obj->isSetupComplete = false;
  obj->isInitialized = 1L;
  obj_0 = &obj->i2cObj;
  IMU_B.modename_c = MW_I2C_MASTER;
  IMU_B.i2cname_m = 0;
  obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(IMU_B.i2cname_m,
    IMU_B.modename_c);
  obj->i2cObj.BusSpeed = 100000UL;
  IMU_B.varargin_1_k = obj->i2cObj.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, IMU_B.varargin_1_k);
  MW_delay_in_milliseconds(600UL);
  IMU_B.status = 0U;
  memcpy((void *)&IMU_B.SwappedDataBytes_p, (void *)&IMU_B.status, (uint16_T)
         ((size_t)1 * sizeof(uint8_T)));
  IMU_B.status = MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL,
    &IMU_B.SwappedDataBytes_p, 1UL, true, false);
  if (IMU_B.status == 0) {
    MW_I2C_MasterRead(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL,
                      &IMU_B.status, 1UL, false, true);
    memcpy((void *)&IMU_B.CastedData, (void *)&IMU_B.status, (uint16_T)((size_t)
            1 * sizeof(uint8_T)));
  } else {
    IMU_B.CastedData = 0U;
  }

  obj->isBNOcorrect = (IMU_B.CastedData == 160);
  if (obj->isBNOcorrect) {
    IMU_B.CastedData = 0U;
    memcpy((void *)&IMU_B.b_SwappedDataBytes_c[1], (void *)&IMU_B.CastedData,
           (uint16_T)((size_t)1 * sizeof(uint8_T)));
    IMU_B.b_SwappedDataBytes_c[0] = 61U;
    memcpy((void *)&IMU_B.SwappedDataBytes_b[0], (void *)
           &IMU_B.b_SwappedDataBytes_c[0], (uint16_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL,
                       &IMU_B.SwappedDataBytes_b[0], 2UL, false, false);
    MW_delay_in_milliseconds(25UL);
    IMU_B.CastedData = 32U;
    memcpy((void *)&IMU_B.b_SwappedDataBytes_c[1], (void *)&IMU_B.CastedData,
           (uint16_T)((size_t)1 * sizeof(uint8_T)));
    IMU_B.b_SwappedDataBytes_c[0] = 63U;
    memcpy((void *)&IMU_B.SwappedDataBytes_b[0], (void *)
           &IMU_B.b_SwappedDataBytes_c[0], (uint16_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL,
                       &IMU_B.SwappedDataBytes_b[0], 2UL, false, false);
    IMU_B.status = 0U;
    memcpy((void *)&IMU_B.SwappedDataBytes_p, (void *)&IMU_B.status, (uint16_T)
           ((size_t)1 * sizeof(uint8_T)));
    IMU_B.status = MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE,
      40UL, &IMU_B.SwappedDataBytes_p, 1UL, true, false);
    if (IMU_B.status == 0) {
      MW_I2C_MasterRead(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL,
                        &IMU_B.status, 1UL, false, true);
      memcpy((void *)&IMU_B.CastedData, (void *)&IMU_B.status, (uint16_T)
             ((size_t)1 * sizeof(uint8_T)));
    } else {
      IMU_B.CastedData = 0U;
    }

    obj->isBNOcorrect = (IMU_B.CastedData == 160);
    while (!obj->isBNOcorrect) {
      MW_delay_in_milliseconds(10UL);
      IMU_B.status = 0U;
      memcpy((void *)&IMU_B.SwappedDataBytes_p, (void *)&IMU_B.status, (uint16_T)
             ((size_t)1 * sizeof(uint8_T)));
      IMU_B.status = MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE,
        40UL, &IMU_B.SwappedDataBytes_p, 1UL, true, false);
      if (IMU_B.status == 0) {
        MW_I2C_MasterRead(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL,
                          &IMU_B.status, 1UL, false, true);
        memcpy((void *)&IMU_B.CastedData, (void *)&IMU_B.status, (uint16_T)
               ((size_t)1 * sizeof(uint8_T)));
      } else {
        IMU_B.CastedData = 0U;
      }

      obj->isBNOcorrect = (IMU_B.CastedData == 160);
    }

    MW_delay_in_milliseconds(50UL);
    IMU_B.CastedData = 0U;
    memcpy((void *)&IMU_B.b_SwappedDataBytes_c[1], (void *)&IMU_B.CastedData,
           (uint16_T)((size_t)1 * sizeof(uint8_T)));
    IMU_B.b_SwappedDataBytes_c[0] = 62U;
    memcpy((void *)&IMU_B.SwappedDataBytes_b[0], (void *)
           &IMU_B.b_SwappedDataBytes_c[0], (uint16_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL,
                       &IMU_B.SwappedDataBytes_b[0], 2UL, false, false);
    IMU_B.CastedData = 0U;
    memcpy((void *)&IMU_B.b_SwappedDataBytes_c[1], (void *)&IMU_B.CastedData,
           (uint16_T)((size_t)1 * sizeof(uint8_T)));
    IMU_B.b_SwappedDataBytes_c[0] = 63U;
    memcpy((void *)&IMU_B.SwappedDataBytes_b[0], (void *)
           &IMU_B.b_SwappedDataBytes_c[0], (uint16_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL,
                       &IMU_B.SwappedDataBytes_b[0], 2UL, false, false);
    IMU_B.CastedData = 0U;
    memcpy((void *)&IMU_B.b_SwappedDataBytes_c[1], (void *)&IMU_B.CastedData,
           (uint16_T)((size_t)1 * sizeof(uint8_T)));
    IMU_B.b_SwappedDataBytes_c[0] = 7U;
    memcpy((void *)&IMU_B.SwappedDataBytes_b[0], (void *)
           &IMU_B.b_SwappedDataBytes_c[0], (uint16_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL,
                       &IMU_B.SwappedDataBytes_b[0], 2UL, false, false);
    MW_delay_in_milliseconds(10UL);
    IMU_B.CastedData = 128U;
    memcpy((void *)&IMU_B.b_SwappedDataBytes_c[1], (void *)&IMU_B.CastedData,
           (uint16_T)((size_t)1 * sizeof(uint8_T)));
    IMU_B.b_SwappedDataBytes_c[0] = 59U;
    memcpy((void *)&IMU_B.SwappedDataBytes_b[0], (void *)
           &IMU_B.b_SwappedDataBytes_c[0], (uint16_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL,
                       &IMU_B.SwappedDataBytes_b[0], 2UL, false, false);
    IMU_B.CastedData = 12U;
    memcpy((void *)&IMU_B.b_SwappedDataBytes_c[1], (void *)&IMU_B.CastedData,
           (uint16_T)((size_t)1 * sizeof(uint8_T)));
    IMU_B.b_SwappedDataBytes_c[0] = 61U;
    memcpy((void *)&IMU_B.SwappedDataBytes_b[0], (void *)
           &IMU_B.b_SwappedDataBytes_c[0], (uint16_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL,
                       &IMU_B.SwappedDataBytes_b[0], 2UL, false, false);
    MW_delay_in_milliseconds(25UL);
  }

  obj->isSetupComplete = true;
}

/* Model step function for TID0 */
void IMU_step0(void)                   /* Sample time: [0.0s, 0.0s] */
{
  codertarget_arduinobase_i_noj_T *obj_0;
  i_codertarget_arduinobase_int_T *obj;
  real_T pwm_cal;
  real_T rtb_Lpwm;
  int16_T b_RegisterValue[3];
  int16_T b_RegisterValue_0[3];
  uint8_T output_raw[6];
  uint8_T SwappedDataBytes;
  uint8_T status;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<Root>/BNO055 IMU Sensor' */
  if (IMU_DW.obj.SampleTime != IMU_P.BNO055IMUSensor_SampleTime) {
    IMU_DW.obj.SampleTime = IMU_P.BNO055IMUSensor_SampleTime;
  }

  obj = &IMU_DW.obj.i2cObj;
  status = 8U;
  memcpy((void *)&SwappedDataBytes, (void *)&status, (uint16_T)((size_t)1 *
          sizeof(uint8_T)));
  status = MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 40UL,
    &SwappedDataBytes, 1UL, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(obj->I2CDriverObj.MW_I2C_HANDLE, 40UL, &output_raw[0], 6UL,
                      false, true);
    memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (uint16_T)
           ((size_t)3 * sizeof(int16_T)));
  } else {
    b_RegisterValue[0] = 0;
    b_RegisterValue[1] = 0;
    b_RegisterValue[2] = 0;
  }

  obj = &IMU_DW.obj.i2cObj;
  status = 26U;
  memcpy((void *)&SwappedDataBytes, (void *)&status, (uint16_T)((size_t)1 *
          sizeof(uint8_T)));
  status = MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 40UL,
    &SwappedDataBytes, 1UL, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(obj->I2CDriverObj.MW_I2C_HANDLE, 40UL, &output_raw[0], 6UL,
                      false, true);
    memcpy((void *)&b_RegisterValue_0[0], (void *)&output_raw[0], (uint16_T)
           ((size_t)3 * sizeof(int16_T)));
  } else {
    b_RegisterValue_0[0] = 0;
    b_RegisterValue_0[1] = 0;
    b_RegisterValue_0[2] = 0;
  }

  /* MATLABSystem: '<Root>/BNO055 IMU Sensor' */
  IMU_B.BNO055IMUSensor_o1[0] = (real_T)b_RegisterValue[0] / 100.0;

  /* MATLABSystem: '<Root>/BNO055 IMU Sensor' */
  IMU_B.BNO055IMUSensor_o2[0] = (real_T)b_RegisterValue_0[0] / 16.0;

  /* MATLABSystem: '<Root>/BNO055 IMU Sensor' */
  IMU_B.BNO055IMUSensor_o1[1] = (real_T)b_RegisterValue[1] / 100.0;

  /* MATLABSystem: '<Root>/BNO055 IMU Sensor' */
  IMU_B.BNO055IMUSensor_o2[1] = (real_T)b_RegisterValue_0[1] / 16.0;

  /* MATLABSystem: '<Root>/BNO055 IMU Sensor' */
  IMU_B.BNO055IMUSensor_o1[2] = (real_T)b_RegisterValue[2] / 100.0;

  /* MATLABSystem: '<Root>/BNO055 IMU Sensor' */
  IMU_B.BNO055IMUSensor_o2[2] = (real_T)b_RegisterValue_0[2] / 16.0;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Constant: '<S1>/Constant2'
   */
  pwm_cal = floor(IMU_P.Constant2_Value_a);
  if (rtIsNaN(pwm_cal) || rtIsInf(pwm_cal)) {
    pwm_cal = 0.0;
  } else {
    pwm_cal = fmod(pwm_cal, 65536.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  IMU_B.DataTypeConversion = pwm_cal < 0.0 ? -(int16_T)(uint16_T)-pwm_cal :
    (int16_T)(uint16_T)pwm_cal;
  IMU_Calibrationwrite(IMU_B.DataTypeConversion, &IMU_DW.Calibrationwrite);

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  Sin: '<Root>/Sine Wave1'
   */
  pwm_cal = (sin(IMU_P.SineWave1_Freq * IMU_M->Timing.t[0] +
                 IMU_P.SineWave1_Phase) * IMU_P.SineWave1_Amp +
             IMU_P.SineWave1_Bias) * 254.0 / 22.9;
  if (pwm_cal > 0.0) {
    rtb_Lpwm = 0.0;
  } else if (pwm_cal < 0.0) {
    rtb_Lpwm = fabs(pwm_cal);
    pwm_cal = 0.0;
  } else {
    rtb_Lpwm = 0.0;
    pwm_cal = 0.0;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function2' */

  /* MATLABSystem: '<Root>/PWM1' */
  obj_0 = &IMU_DW.obj_m;
  obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
  if (!(rtb_Lpwm <= 255.0)) {
    rtb_Lpwm = 255.0;
  }

  MW_PWM_SetDutyCycle(IMU_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, rtb_Lpwm);

  /* End of MATLABSystem: '<Root>/PWM1' */

  /* MATLABSystem: '<Root>/PWM2' */
  obj_0 = &IMU_DW.obj_e;
  obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
  if (!(pwm_cal <= 255.0)) {
    pwm_cal = 255.0;
  }

  MW_PWM_SetDutyCycle(IMU_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, pwm_cal);

  /* End of MATLABSystem: '<Root>/PWM2' */

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  IMU_M->Timing.t[0] =
    ((time_T)(++IMU_M->Timing.clockTick0)) * IMU_M->Timing.stepSize0;
  switch (IMU_M->Timing.rtmDbBufReadBuf3) {
   case 0:
    IMU_M->Timing.rtmDbBufWriteBuf3 = 1;
    break;

   case 1:
    IMU_M->Timing.rtmDbBufWriteBuf3 = 0;
    break;

   default:
    IMU_M->Timing.rtmDbBufWriteBuf3 = !IMU_M->Timing.rtmDbBufLastBufWr3;
    break;
  }

  IMU_M->Timing.rtmDbBufClockTick3[IMU_M->Timing.rtmDbBufWriteBuf3] =
    IMU_M->Timing.clockTick0;
  IMU_M->Timing.rtmDbBufLastBufWr3 = IMU_M->Timing.rtmDbBufWriteBuf3;
  IMU_M->Timing.rtmDbBufWriteBuf3 = 0xFF;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  IMU_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void IMU_step2(void)                   /* Sample time: [0.1s, 0.0s] */
{
  int16_T b_output;
  int16_T b_output_0;
  uint8_T b_x[2];
  uint8_T output_raw[2];
  uint8_T status;

  /* MATLABSystem: '<Root>/Current Reg read' */
  if (IMU_DW.obj_n.SampleTime != IMU_P.CurrentRegread_SampleTime) {
    IMU_DW.obj_n.SampleTime = IMU_P.CurrentRegread_SampleTime;
  }

  status = 4U;
  status = MW_I2C_MasterWrite(IMU_DW.obj_n.I2CDriverObj.MW_I2C_HANDLE, 64UL,
    &status, 1UL, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(IMU_DW.obj_n.I2CDriverObj.MW_I2C_HANDLE, 64UL,
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
  IMU_B.Gain1 = (real_T)((int32_T)IMU_P.Gain_Gain * b_output) *
    1.9073486328125E-6 * IMU_P.Gain1_Gain;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  IMU_M->Timing.clockTick2++;
}

/* Model initialize function */
void IMU_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&IMU_M->solverInfo, &IMU_M->Timing.simTimeStep);
    rtsiSetTPtr(&IMU_M->solverInfo, &rtmGetTPtr(IMU_M));
    rtsiSetStepSizePtr(&IMU_M->solverInfo, &IMU_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&IMU_M->solverInfo, (&rtmGetErrorStatus(IMU_M)));
    rtsiSetRTModelPtr(&IMU_M->solverInfo, IMU_M);
  }

  rtsiSetSimTimeStep(&IMU_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&IMU_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(IMU_M, &IMU_M->Timing.tArray[0]);
  rtmSetTFinal(IMU_M, -1);
  IMU_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  IMU_M->Sizes.checksums[0] = (2326191042U);
  IMU_M->Sizes.checksums[1] = (641400143U);
  IMU_M->Sizes.checksums[2] = (2126163011U);
  IMU_M->Sizes.checksums[3] = (3785162689U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    IMU_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(IMU_M->extModeInfo,
      &IMU_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(IMU_M->extModeInfo, IMU_M->Sizes.checksums);
    rteiSetTPtr(IMU_M->extModeInfo, rtmGetTPtr(IMU_M));
  }

  {
    codertarget_arduinobase_i_noj_T *obj_0;
    codertarget_arduinobase_in_no_T *obj_1;
    codertarget_arduinobase_inter_T *obj_2;
    i_codertarget_arduinobase_int_T *obj;
    IMU_M->Timing.rtmDbBufReadBuf3 = 0xFF;
    IMU_M->Timing.rtmDbBufWriteBuf3 = 0xFF;
    IMU_M->Timing.rtmDbBufLastBufWr3 = 0;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Initialize Function' */
    /* Start for MATLABSystem: '<S4>/Configuration write' */
    IMU_DW.obj_h.matlabCodegenIsDeleted = true;
    IMU_DW.obj_h.DefaultMaximumBusSpeedInHz = 400000.0;
    IMU_DW.obj_h.isInitialized = 0L;
    IMU_DW.obj_h.I2CDriverObj.MW_I2C_HANDLE = NULL;
    IMU_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_2 = &IMU_DW.obj_h;
    IMU_DW.obj_h.isSetupComplete = false;
    IMU_DW.obj_h.isInitialized = 1L;
    IMU_B.modename = MW_I2C_MASTER;
    IMU_B.i2cname = 0;
    obj_2->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(IMU_B.i2cname,
      IMU_B.modename);
    IMU_DW.obj_h.BusSpeed = 100000UL;
    IMU_B.varargin_1 = IMU_DW.obj_h.BusSpeed;
    MW_I2C_SetBusSpeed(IMU_DW.obj_h.I2CDriverObj.MW_I2C_HANDLE, IMU_B.varargin_1);
    IMU_DW.obj_h.isSetupComplete = true;
    IMU_Calibrationwrite_Init(&IMU_DW.Calibrationwrite_p);

    /* End of SystemInitialize for SubSystem: '<Root>/Initialize Function' */

    /* Start for MATLABSystem: '<Root>/BNO055 IMU Sensor' */
    IMU_DW.obj.i2cObj.matlabCodegenIsDeleted = true;
    IMU_DW.obj.matlabCodegenIsDeleted = true;
    IMU_DW.obj.isInitialized = 0L;
    IMU_DW.obj.SampleTime = -1.0;
    obj = &IMU_DW.obj.i2cObj;
    IMU_DW.obj.i2cObj.DefaultMaximumBusSpeedInHz = 400000.0;
    IMU_DW.obj.i2cObj.isInitialized = 0L;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    IMU_DW.obj.i2cObj.matlabCodegenIsDeleted = false;
    IMU_DW.obj.matlabCodegenIsDeleted = false;
    IMU_DW.obj.SampleTime = IMU_P.BNO055IMUSensor_SampleTime;
    IMU_SystemCore_setup(&IMU_DW.obj);
    IMU_Calibrationwrite_Init(&IMU_DW.Calibrationwrite);

    /* Start for MATLABSystem: '<Root>/PWM1' */
    IMU_DW.obj_m.matlabCodegenIsDeleted = true;
    IMU_DW.obj_m.isInitialized = 0L;
    IMU_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_0 = &IMU_DW.obj_m;
    IMU_DW.obj_m.isSetupComplete = false;
    IMU_DW.obj_m.isInitialized = 1L;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(8UL, 0.0, 0.0);
    IMU_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM2' */
    IMU_DW.obj_e.matlabCodegenIsDeleted = true;
    IMU_DW.obj_e.isInitialized = 0L;
    IMU_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &IMU_DW.obj_e;
    IMU_DW.obj_e.isSetupComplete = false;
    IMU_DW.obj_e.isInitialized = 1L;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
    IMU_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Current Reg read' */
    IMU_DW.obj_n.matlabCodegenIsDeleted = true;
    IMU_DW.obj_n.DefaultMaximumBusSpeedInHz = 400000.0;
    IMU_DW.obj_n.isInitialized = 0L;
    IMU_DW.obj_n.SampleTime = -1.0;
    IMU_DW.obj_n.I2CDriverObj.MW_I2C_HANDLE = NULL;
    IMU_DW.obj_n.matlabCodegenIsDeleted = false;
    IMU_DW.obj_n.SampleTime = IMU_P.CurrentRegread_SampleTime;
    obj_1 = &IMU_DW.obj_n;
    IMU_DW.obj_n.isSetupComplete = false;
    IMU_DW.obj_n.isInitialized = 1L;
    IMU_B.modename = MW_I2C_MASTER;
    IMU_B.i2cname = 0;
    obj_1->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(IMU_B.i2cname,
      IMU_B.modename);
    IMU_DW.obj_n.BusSpeed = 100000UL;
    IMU_B.varargin_1 = IMU_DW.obj_n.BusSpeed;
    MW_I2C_SetBusSpeed(IMU_DW.obj_n.I2CDriverObj.MW_I2C_HANDLE, IMU_B.varargin_1);
    IMU_DW.obj_n.isSetupComplete = true;

    /* Outputs for Atomic SubSystem: '<Root>/Initialize Function' */
    /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
     *  Constant: '<S4>/Constant3'
     */
    IMU_B.d = floor(IMU_P.Constant3_Value);
    if (rtIsNaN(IMU_B.d) || rtIsInf(IMU_B.d)) {
      IMU_B.d = 0.0;
    } else {
      IMU_B.d = fmod(IMU_B.d, 65536.0);
    }

    IMU_B.DataTypeConversion_m = IMU_B.d < 0.0 ? -(int16_T)(uint16_T)-IMU_B.d :
      (int16_T)(uint16_T)IMU_B.d;

    /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

    /* MATLABSystem: '<S4>/Configuration write' */
    memcpy((void *)&IMU_B.SwappedDataBytes[0], (void *)
           &IMU_B.DataTypeConversion_m, (uint16_T)((size_t)2 * sizeof(uint8_T)));
    IMU_B.b_x[0] = IMU_B.SwappedDataBytes[1];
    IMU_B.b_x[1] = IMU_B.SwappedDataBytes[0];
    memcpy((void *)&IMU_B.DataTypeConversion_m, (void *)&IMU_B.b_x[0], (uint16_T)
           ((size_t)1 * sizeof(int16_T)));
    memcpy((void *)&IMU_B.SwappedDataBytes[0], (void *)
           &IMU_B.DataTypeConversion_m, (uint16_T)((size_t)2 * sizeof(uint8_T)));
    IMU_B.b_SwappedDataBytes[0] = 0U;
    IMU_B.b_SwappedDataBytes[1] = IMU_B.SwappedDataBytes[0];
    IMU_B.b_SwappedDataBytes[2] = IMU_B.SwappedDataBytes[1];
    MW_I2C_MasterWrite(IMU_DW.obj_h.I2CDriverObj.MW_I2C_HANDLE, 64UL,
                       &IMU_B.b_SwappedDataBytes[0], 3UL, false, false);

    /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
     *  Constant: '<S5>/Constant2'
     */
    IMU_B.d = floor(IMU_P.Constant2_Value);
    if (rtIsNaN(IMU_B.d) || rtIsInf(IMU_B.d)) {
      IMU_B.d = 0.0;
    } else {
      IMU_B.d = fmod(IMU_B.d, 65536.0);
    }

    /* DataTypeConversion: '<S5>/Data Type Conversion' */
    IMU_B.DataTypeConversion_mm = IMU_B.d < 0.0 ? -(int16_T)(uint16_T)-IMU_B.d :
      (int16_T)(uint16_T)IMU_B.d;
    IMU_Calibrationwrite(IMU_B.DataTypeConversion_mm, &IMU_DW.Calibrationwrite_p);

    /* End of Outputs for SubSystem: '<Root>/Initialize Function' */
  }
}

/* Model terminate function */
void IMU_terminate(void)
{
  codertarget_arduinobase_i_noj_T *obj_0;
  i_codertarget_arduinobase_int_T *obj;

  /* Terminate for MATLABSystem: '<Root>/BNO055 IMU Sensor' */
  if (!IMU_DW.obj.matlabCodegenIsDeleted) {
    IMU_DW.obj.matlabCodegenIsDeleted = true;
    if ((IMU_DW.obj.isInitialized == 1L) && IMU_DW.obj.isSetupComplete) {
      obj = &IMU_DW.obj.i2cObj;
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  obj = &IMU_DW.obj.i2cObj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1L) {
      obj->isInitialized = 2L;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/BNO055 IMU Sensor' */
  IMU_Calibrationwrite_Term(&IMU_DW.Calibrationwrite);

  /* Terminate for MATLABSystem: '<Root>/PWM1' */
  obj_0 = &IMU_DW.obj_m;
  if (!IMU_DW.obj_m.matlabCodegenIsDeleted) {
    IMU_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((IMU_DW.obj_m.isInitialized == 1L) && IMU_DW.obj_m.isSetupComplete) {
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
      MW_PWM_SetDutyCycle(IMU_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
      MW_PWM_Close(IMU_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM1' */

  /* Terminate for MATLABSystem: '<Root>/PWM2' */
  obj_0 = &IMU_DW.obj_e;
  if (!IMU_DW.obj_e.matlabCodegenIsDeleted) {
    IMU_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((IMU_DW.obj_e.isInitialized == 1L) && IMU_DW.obj_e.isSetupComplete) {
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(IMU_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(IMU_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM2' */

  /* Terminate for MATLABSystem: '<Root>/Current Reg read' */
  if (!IMU_DW.obj_n.matlabCodegenIsDeleted) {
    IMU_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((IMU_DW.obj_n.isInitialized == 1L) && IMU_DW.obj_n.isSetupComplete) {
      MW_I2C_Close(IMU_DW.obj_n.I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Current Reg read' */
  /* Terminate for Atomic SubSystem: '<Root>/Initialize Function' */
  /* Terminate for MATLABSystem: '<S4>/Configuration write' */
  if (!IMU_DW.obj_h.matlabCodegenIsDeleted) {
    IMU_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((IMU_DW.obj_h.isInitialized == 1L) && IMU_DW.obj_h.isSetupComplete) {
      MW_I2C_Close(IMU_DW.obj_h.I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Configuration write' */
  IMU_Calibrationwrite_Term(&IMU_DW.Calibrationwrite_p);

  /* End of Terminate for SubSystem: '<Root>/Initialize Function' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
