/*
 * File: Current_test.c
 *
 * Code generated for Simulink model 'Current_test'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Aug 17 10:21:59 2022
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

/* System initialize for atomic system: */
void Curre_Calibrationwrite_Init(DW_Calibrationwrite_Current_t_T *localDW)
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
void Current_te_Calibrationwrite(int16_T rtu_0, DW_Calibrationwrite_Current_t_T *
  localDW)
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
void Curre_Calibrationwrite_Term(DW_Calibrationwrite_Current_t_T *localDW)
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
void Current_test_step0(void)          /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  int16_T rtb_DataTypeConversion;
  codertarget_arduinobase_in_dv_T *obj;
  real_T pwm_cal;
  real_T rtb_Lpwm;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Constant: '<S1>/Constant2'
   */
  pwm_cal = floor(Current_test_P.Constant2_Value_a);
  if (rtIsNaN(pwm_cal) || rtIsInf(pwm_cal)) {
    pwm_cal = 0.0;
  } else {
    pwm_cal = fmod(pwm_cal, 65536.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  rtb_DataTypeConversion = pwm_cal < 0.0 ? -(int16_T)(uint16_T)-pwm_cal :
    (int16_T)(uint16_T)pwm_cal;
  Current_te_Calibrationwrite(rtb_DataTypeConversion,
    &Current_test_DW.Calibrationwrite);

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  Sin: '<Root>/Sine Wave1'
   */
  pwm_cal = (sin(Current_test_P.SineWave1_Freq * Current_test_M->Timing.t[0] +
                 Current_test_P.SineWave1_Phase) * Current_test_P.SineWave1_Amp
             + Current_test_P.SineWave1_Bias) * 254.0 / 22.9;
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
  obj = &Current_test_DW.obj_j;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
  if (!(rtb_Lpwm <= 255.0)) {
    rtb_Lpwm = 255.0;
  }

  MW_PWM_SetDutyCycle(Current_test_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE, rtb_Lpwm);

  /* End of MATLABSystem: '<Root>/PWM1' */

  /* MATLABSystem: '<Root>/PWM2' */
  obj = &Current_test_DW.obj_l;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
  if (!(pwm_cal <= 255.0)) {
    pwm_cal = 255.0;
  }

  MW_PWM_SetDutyCycle(Current_test_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, pwm_cal);

  /* End of MATLABSystem: '<Root>/PWM2' */

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Current_test_M->Timing.t[0] =
    ((time_T)(++Current_test_M->Timing.clockTick0)) *
    Current_test_M->Timing.stepSize0;
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
}

/* Model step function for TID2 */
void Current_test_step2(void)          /* Sample time: [0.1s, 0.0s] */
{
  int16_T b_output;
  int16_T b_output_0;
  uint8_T b_x[2];
  uint8_T output_raw[2];
  uint8_T status;

  /* MATLABSystem: '<Root>/Current Reg read' */
  if (Current_test_DW.obj.SampleTime != Current_test_P.CurrentRegread_SampleTime)
  {
    Current_test_DW.obj.SampleTime = Current_test_P.CurrentRegread_SampleTime;
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

  /* Gain: '<Root>/Gain1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Gain: '<Root>/Gain'
   *  MATLABSystem: '<Root>/Current Reg read'
   */
  Current_test_B.Gain1 = (real_T)((int32_T)Current_test_P.Gain_Gain * b_output) *
    1.9073486328125E-6 * Current_test_P.Gain1_Gain;

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
    rtsiSetErrorStatusPtr(&Current_test_M->solverInfo, (&rtmGetErrorStatus
      (Current_test_M)));
    rtsiSetRTModelPtr(&Current_test_M->solverInfo, Current_test_M);
  }

  rtsiSetSimTimeStep(&Current_test_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Current_test_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Current_test_M, &Current_test_M->Timing.tArray[0]);
  rtmSetTFinal(Current_test_M, -1);
  Current_test_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Current_test_M->Sizes.checksums[0] = (3404252529U);
  Current_test_M->Sizes.checksums[1] = (2443029520U);
  Current_test_M->Sizes.checksums[2] = (747284884U);
  Current_test_M->Sizes.checksums[3] = (2416485338U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
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
    rteiSetModelMappingInfoPtr(Current_test_M->extModeInfo,
      &Current_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Current_test_M->extModeInfo,
                        Current_test_M->Sizes.checksums);
    rteiSetTPtr(Current_test_M->extModeInfo, rtmGetTPtr(Current_test_M));
  }

  {
    /* local block i/o variables */
    int16_T rtb_DataTypeConversion_m;
    codertarget_arduinobase_in_dv_T *obj;
    codertarget_arduinobase_int_d_T *obj_0;
    codertarget_arduinobase_inter_T *obj_1;
    int16_T rtb_DataTypeConversion_p;
    uint8_T SwappedDataBytes[2];
    uint8_T b_x[2];
    Current_test_M->Timing.rtmDbBufReadBuf3 = 0xFF;
    Current_test_M->Timing.rtmDbBufWriteBuf3 = 0xFF;
    Current_test_M->Timing.rtmDbBufLastBufWr3 = 0;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Initialize Function' */
    /* Start for MATLABSystem: '<S4>/Configuration write' */
    Current_test_DW.obj_m.matlabCodegenIsDeleted = true;
    Current_test_DW.obj_m.DefaultMaximumBusSpeedInHz = 400000.0;
    Current_test_DW.obj_m.isInitialized = 0L;
    Current_test_DW.obj_m.I2CDriverObj.MW_I2C_HANDLE = NULL;
    Current_test_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_1 = &Current_test_DW.obj_m;
    Current_test_DW.obj_m.isSetupComplete = false;
    Current_test_DW.obj_m.isInitialized = 1L;
    Current_test_B.modename = MW_I2C_MASTER;
    Current_test_B.i2cname = 0;
    obj_1->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(Current_test_B.i2cname,
      Current_test_B.modename);
    Current_test_DW.obj_m.BusSpeed = 100000UL;
    Current_test_B.varargin_1 = Current_test_DW.obj_m.BusSpeed;
    MW_I2C_SetBusSpeed(Current_test_DW.obj_m.I2CDriverObj.MW_I2C_HANDLE,
                       Current_test_B.varargin_1);
    Current_test_DW.obj_m.isSetupComplete = true;
    Curre_Calibrationwrite_Init(&Current_test_DW.Calibrationwrite_p);

    /* End of SystemInitialize for SubSystem: '<Root>/Initialize Function' */
    Curre_Calibrationwrite_Init(&Current_test_DW.Calibrationwrite);

    /* Start for MATLABSystem: '<Root>/PWM1' */
    Current_test_DW.obj_j.matlabCodegenIsDeleted = true;
    Current_test_DW.obj_j.isInitialized = 0L;
    Current_test_DW.obj_j.matlabCodegenIsDeleted = false;
    obj = &Current_test_DW.obj_j;
    Current_test_DW.obj_j.isSetupComplete = false;
    Current_test_DW.obj_j.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(8UL, 0.0, 0.0);
    Current_test_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM2' */
    Current_test_DW.obj_l.matlabCodegenIsDeleted = true;
    Current_test_DW.obj_l.isInitialized = 0L;
    Current_test_DW.obj_l.matlabCodegenIsDeleted = false;
    obj = &Current_test_DW.obj_l;
    Current_test_DW.obj_l.isSetupComplete = false;
    Current_test_DW.obj_l.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
    Current_test_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Current Reg read' */
    Current_test_DW.obj.matlabCodegenIsDeleted = true;
    Current_test_DW.obj.DefaultMaximumBusSpeedInHz = 400000.0;
    Current_test_DW.obj.isInitialized = 0L;
    Current_test_DW.obj.SampleTime = -1.0;
    Current_test_DW.obj.I2CDriverObj.MW_I2C_HANDLE = NULL;
    Current_test_DW.obj.matlabCodegenIsDeleted = false;
    Current_test_DW.obj.SampleTime = Current_test_P.CurrentRegread_SampleTime;
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

    /* Outputs for Atomic SubSystem: '<Root>/Initialize Function' */
    /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
     *  Constant: '<S4>/Constant3'
     */
    Current_test_B.d = floor(Current_test_P.Constant3_Value);
    if (rtIsNaN(Current_test_B.d) || rtIsInf(Current_test_B.d)) {
      Current_test_B.d = 0.0;
    } else {
      Current_test_B.d = fmod(Current_test_B.d, 65536.0);
    }

    rtb_DataTypeConversion_p = Current_test_B.d < 0.0 ? -(int16_T)(uint16_T)
      -Current_test_B.d : (int16_T)(uint16_T)Current_test_B.d;

    /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

    /* MATLABSystem: '<S4>/Configuration write' */
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
    MW_I2C_MasterWrite(Current_test_DW.obj_m.I2CDriverObj.MW_I2C_HANDLE, 64UL,
                       &Current_test_B.b_SwappedDataBytes[0], 3UL, false, false);

    /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
     *  Constant: '<S5>/Constant2'
     */
    Current_test_B.d = floor(Current_test_P.Constant2_Value);
    if (rtIsNaN(Current_test_B.d) || rtIsInf(Current_test_B.d)) {
      Current_test_B.d = 0.0;
    } else {
      Current_test_B.d = fmod(Current_test_B.d, 65536.0);
    }

    /* DataTypeConversion: '<S5>/Data Type Conversion' */
    rtb_DataTypeConversion_m = Current_test_B.d < 0.0 ? -(int16_T)(uint16_T)
      -Current_test_B.d : (int16_T)(uint16_T)Current_test_B.d;
    Current_te_Calibrationwrite(rtb_DataTypeConversion_m,
      &Current_test_DW.Calibrationwrite_p);

    /* End of Outputs for SubSystem: '<Root>/Initialize Function' */
  }
}

/* Model terminate function */
void Current_test_terminate(void)
{
  codertarget_arduinobase_in_dv_T *obj;
  Curre_Calibrationwrite_Term(&Current_test_DW.Calibrationwrite);

  /* Terminate for MATLABSystem: '<Root>/PWM1' */
  obj = &Current_test_DW.obj_j;
  if (!Current_test_DW.obj_j.matlabCodegenIsDeleted) {
    Current_test_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Current_test_DW.obj_j.isInitialized == 1L) &&
        Current_test_DW.obj_j.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
      MW_PWM_SetDutyCycle(Current_test_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
      MW_PWM_Close(Current_test_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM1' */

  /* Terminate for MATLABSystem: '<Root>/PWM2' */
  obj = &Current_test_DW.obj_l;
  if (!Current_test_DW.obj_l.matlabCodegenIsDeleted) {
    Current_test_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Current_test_DW.obj_l.isInitialized == 1L) &&
        Current_test_DW.obj_l.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(Current_test_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(Current_test_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM2' */

  /* Terminate for MATLABSystem: '<Root>/Current Reg read' */
  if (!Current_test_DW.obj.matlabCodegenIsDeleted) {
    Current_test_DW.obj.matlabCodegenIsDeleted = true;
    if ((Current_test_DW.obj.isInitialized == 1L) &&
        Current_test_DW.obj.isSetupComplete) {
      MW_I2C_Close(Current_test_DW.obj.I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Current Reg read' */
  /* Terminate for Atomic SubSystem: '<Root>/Initialize Function' */
  /* Terminate for MATLABSystem: '<S4>/Configuration write' */
  if (!Current_test_DW.obj_m.matlabCodegenIsDeleted) {
    Current_test_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Current_test_DW.obj_m.isInitialized == 1L) &&
        Current_test_DW.obj_m.isSetupComplete) {
      MW_I2C_Close(Current_test_DW.obj_m.I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Configuration write' */
  Curre_Calibrationwrite_Term(&Current_test_DW.Calibrationwrite_p);

  /* End of Terminate for SubSystem: '<Root>/Initialize Function' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
