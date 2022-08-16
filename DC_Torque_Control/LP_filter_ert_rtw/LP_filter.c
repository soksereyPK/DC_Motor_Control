/*
 * File: LP_filter.c
 *
 * Code generated for Simulink model 'LP_filter'.
 *
 * Model version                  : 2.1
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Aug 16 14:15:09 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LP_filter.h"
#include "rtwtypes.h"
#include "LP_filter_private.h"
#include "LP_filter_types.h"
#include <string.h>
#include <stddef.h>
#include <math.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_LP_filter_T LP_filter_B;

/* Block states (default storage) */
DW_LP_filter_T LP_filter_DW;

/* Real-time model */
static RT_MODEL_LP_filter_T LP_filter_M_;
RT_MODEL_LP_filter_T *const LP_filter_M = &LP_filter_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void LP_filter_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(LP_filter_M, 2));
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
  (LP_filter_M->Timing.TaskCounters.TID[2])++;
  if ((LP_filter_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.1s, 0.0s] */
    LP_filter_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* System initialize for atomic system: */
void LP_fi_Calibrationwrite_Init(DW_Calibrationwrite_LP_filter_T *localDW)
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
void LP_filter_Calibrationwrite(int16_T rtu_0, DW_Calibrationwrite_LP_filter_T
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
void LP_fi_Calibrationwrite_Term(DW_Calibrationwrite_LP_filter_T *localDW)
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
void LP_filter_step0(void)             /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  int16_T rtb_DataTypeConversion;
  codertarget_arduinobase_in_f2_T *obj;
  real_T pwm_cal;
  real_T rtb_Lpwm;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Constant: '<S1>/Constant2'
   */
  pwm_cal = floor(LP_filter_P.Constant2_Value_h);
  if (rtIsNaN(pwm_cal) || rtIsInf(pwm_cal)) {
    pwm_cal = 0.0;
  } else {
    pwm_cal = fmod(pwm_cal, 65536.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  rtb_DataTypeConversion = pwm_cal < 0.0 ? -(int16_T)(uint16_T)-pwm_cal :
    (int16_T)(uint16_T)pwm_cal;
  LP_filter_Calibrationwrite(rtb_DataTypeConversion,
    &LP_filter_DW.Calibrationwrite);

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  Sin: '<Root>/Sine Wave1'
   */
  pwm_cal = (sin(LP_filter_P.SineWave1_Freq * LP_filter_M->Timing.t[0] +
                 LP_filter_P.SineWave1_Phase) * LP_filter_P.SineWave1_Amp +
             LP_filter_P.SineWave1_Bias) * 254.0 / 22.9;
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
  obj = &LP_filter_DW.obj_e;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
  if (!(rtb_Lpwm <= 255.0)) {
    rtb_Lpwm = 255.0;
  }

  MW_PWM_SetDutyCycle(LP_filter_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, rtb_Lpwm);

  /* End of MATLABSystem: '<Root>/PWM1' */

  /* MATLABSystem: '<Root>/PWM2' */
  obj = &LP_filter_DW.obj_d;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
  if (!(pwm_cal <= 255.0)) {
    pwm_cal = 255.0;
  }

  MW_PWM_SetDutyCycle(LP_filter_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE, pwm_cal);

  /* End of MATLABSystem: '<Root>/PWM2' */

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  LP_filter_M->Timing.t[0] =
    ((time_T)(++LP_filter_M->Timing.clockTick0)) * LP_filter_M->Timing.stepSize0;
  switch (LP_filter_M->Timing.rtmDbBufReadBuf3) {
   case 0:
    LP_filter_M->Timing.rtmDbBufWriteBuf3 = 1;
    break;

   case 1:
    LP_filter_M->Timing.rtmDbBufWriteBuf3 = 0;
    break;

   default:
    LP_filter_M->Timing.rtmDbBufWriteBuf3 =
      !LP_filter_M->Timing.rtmDbBufLastBufWr3;
    break;
  }

  LP_filter_M->Timing.rtmDbBufClockTick3[LP_filter_M->Timing.rtmDbBufWriteBuf3] =
    LP_filter_M->Timing.clockTick0;
  LP_filter_M->Timing.rtmDbBufLastBufWr3 = LP_filter_M->Timing.rtmDbBufWriteBuf3;
  LP_filter_M->Timing.rtmDbBufWriteBuf3 = 0xFF;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  LP_filter_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void LP_filter_step2(void)             /* Sample time: [0.1s, 0.0s] */
{
  b_dsp_FIRFilter_0_LP_filter_T *obj_0;
  b_dspcodegen_FIRFilter_LP_fil_T *obj;
  real_T acc1;
  real_T zCurr;
  real_T zNext;
  int16_T b_output;
  int16_T b_output_0;
  uint8_T b_x[2];
  uint8_T output_raw[2];
  uint8_T status;

  /* MATLABSystem: '<Root>/Current Reg read' */
  if (LP_filter_DW.obj_n.SampleTime != LP_filter_P.CurrentRegread_SampleTime) {
    LP_filter_DW.obj_n.SampleTime = LP_filter_P.CurrentRegread_SampleTime;
  }

  status = 4U;
  status = MW_I2C_MasterWrite(LP_filter_DW.obj_n.I2CDriverObj.MW_I2C_HANDLE,
    64UL, &status, 1UL, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(LP_filter_DW.obj_n.I2CDriverObj.MW_I2C_HANDLE, 64UL,
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
  LP_filter_B.Gain1 = (real_T)((int32_T)LP_filter_P.Gain_Gain * b_output) *
    1.9073486328125E-6 * LP_filter_P.Gain1_Gain;

  /* MATLABSystem: '<Root>/Lowpass Filter' */
  obj = LP_filter_DW.obj.FilterObj;
  if (obj->isInitialized != 1L) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1L;
    obj->isSetupComplete = true;

    /* System object Initialization function: dsp.FIRFilter */
    for (b_output = 0; b_output < 38; b_output++) {
      obj->cSFunObject.W0_states[b_output] = obj->cSFunObject.P0_InitialStates;
    }
  }

  obj_0 = &obj->cSFunObject;

  /* System object Outputs function: dsp.FIRFilter */
  acc1 = 0.0;

  /* load input sample */
  zNext = LP_filter_B.Gain1;
  for (b_output = 0; b_output < 38; b_output++) {
    /* shift state */
    zCurr = zNext;
    zNext = obj_0->W0_states[(int32_T)b_output];
    obj_0->W0_states[(int32_T)b_output] = zCurr;

    /* compute one tap */
    zCurr *= obj_0->P1_Coefficients[(int32_T)b_output];
    acc1 += zCurr;
  }

  /* compute last tap */
  zCurr = obj->cSFunObject.P1_Coefficients[(int32_T)b_output] * zNext;

  /* MATLABSystem: '<Root>/Lowpass Filter' */
  /* store output sample */
  LP_filter_B.LowpassFilter = acc1 + zCurr;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  LP_filter_M->Timing.clockTick2++;
}

/* Model initialize function */
void LP_filter_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&LP_filter_M->solverInfo,
                          &LP_filter_M->Timing.simTimeStep);
    rtsiSetTPtr(&LP_filter_M->solverInfo, &rtmGetTPtr(LP_filter_M));
    rtsiSetStepSizePtr(&LP_filter_M->solverInfo, &LP_filter_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&LP_filter_M->solverInfo, (&rtmGetErrorStatus
      (LP_filter_M)));
    rtsiSetRTModelPtr(&LP_filter_M->solverInfo, LP_filter_M);
  }

  rtsiSetSimTimeStep(&LP_filter_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&LP_filter_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(LP_filter_M, &LP_filter_M->Timing.tArray[0]);
  rtmSetTFinal(LP_filter_M, 10.0);
  LP_filter_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  LP_filter_M->Sizes.checksums[0] = (2059701415U);
  LP_filter_M->Sizes.checksums[1] = (1612077815U);
  LP_filter_M->Sizes.checksums[2] = (3698780134U);
  LP_filter_M->Sizes.checksums[3] = (3990433538U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    LP_filter_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(LP_filter_M->extModeInfo,
      &LP_filter_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(LP_filter_M->extModeInfo, LP_filter_M->Sizes.checksums);
    rteiSetTPtr(LP_filter_M->extModeInfo, rtmGetTPtr(LP_filter_M));
  }

  {
    /* local block i/o variables */
    int16_T rtb_DataTypeConversion_ab;
    b_dspcodegen_FIRFilter_LP_fil_T *iobj_0;
    codertarget_arduinobase_in_f2_T *obj;
    codertarget_arduinobase_int_f_T *obj_0;
    codertarget_arduinobase_inter_T *obj_1;
    static const real_T tmp[39] = { -0.00059194361517663689,
      -0.0020231187609940074, -0.0021060229913033154, 0.0012560050342482782,
      0.0045836073548239592, 0.00081354750291903971, -0.0074945947911449614,
      -0.0059854409238031476, 0.0089175430449157777, 0.014763032770771055,
      -0.0061136921890367051, -0.026666288251129273, -0.00451612337795531,
      0.040069256336854729, 0.028624786731400381, -0.052515463472640085,
      -0.082387824369927212, 0.061352556551937866, 0.30991387818783289,
      0.43544828894513982, 0.30991387818783289, 0.061352556551937866,
      -0.082387824369927212, -0.052515463472640085, 0.028624786731400381,
      0.040069256336854729, -0.00451612337795531, -0.026666288251129273,
      -0.0061136921890367051, 0.014763032770771055, 0.0089175430449157777,
      -0.0059854409238031476, -0.0074945947911449614, 0.00081354750291903971,
      0.0045836073548239592, 0.0012560050342482782, -0.0021060229913033154,
      -0.0020231187609940074, -0.00059194361517663689 };

    LP_filter_M->Timing.rtmDbBufReadBuf3 = 0xFF;
    LP_filter_M->Timing.rtmDbBufWriteBuf3 = 0xFF;
    LP_filter_M->Timing.rtmDbBufLastBufWr3 = 0;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Initialize Function' */
    /* Start for MATLABSystem: '<S4>/Configuration write' */
    LP_filter_DW.obj_f.matlabCodegenIsDeleted = true;
    LP_filter_DW.obj_f.DefaultMaximumBusSpeedInHz = 400000.0;
    LP_filter_DW.obj_f.isInitialized = 0L;
    LP_filter_DW.obj_f.I2CDriverObj.MW_I2C_HANDLE = NULL;
    LP_filter_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_1 = &LP_filter_DW.obj_f;
    LP_filter_DW.obj_f.isSetupComplete = false;
    LP_filter_DW.obj_f.isInitialized = 1L;
    LP_filter_B.modename = MW_I2C_MASTER;
    LP_filter_B.i2cname = 0;
    obj_1->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(LP_filter_B.i2cname,
      LP_filter_B.modename);
    LP_filter_DW.obj_f.BusSpeed = 100000UL;
    LP_filter_B.varargin_1 = LP_filter_DW.obj_f.BusSpeed;
    MW_I2C_SetBusSpeed(LP_filter_DW.obj_f.I2CDriverObj.MW_I2C_HANDLE,
                       LP_filter_B.varargin_1);
    LP_filter_DW.obj_f.isSetupComplete = true;
    LP_fi_Calibrationwrite_Init(&LP_filter_DW.Calibrationwrite_p);

    /* End of SystemInitialize for SubSystem: '<Root>/Initialize Function' */
    LP_fi_Calibrationwrite_Init(&LP_filter_DW.Calibrationwrite);

    /* Start for MATLABSystem: '<Root>/PWM1' */
    LP_filter_DW.obj_e.matlabCodegenIsDeleted = true;
    LP_filter_DW.obj_e.isInitialized = 0L;
    LP_filter_DW.obj_e.matlabCodegenIsDeleted = false;
    obj = &LP_filter_DW.obj_e;
    LP_filter_DW.obj_e.isSetupComplete = false;
    LP_filter_DW.obj_e.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(8UL, 0.0, 0.0);
    LP_filter_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM2' */
    LP_filter_DW.obj_d.matlabCodegenIsDeleted = true;
    LP_filter_DW.obj_d.isInitialized = 0L;
    LP_filter_DW.obj_d.matlabCodegenIsDeleted = false;
    obj = &LP_filter_DW.obj_d;
    LP_filter_DW.obj_d.isSetupComplete = false;
    LP_filter_DW.obj_d.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
    LP_filter_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Current Reg read' */
    LP_filter_DW.obj_n.matlabCodegenIsDeleted = true;
    LP_filter_DW.obj_n.DefaultMaximumBusSpeedInHz = 400000.0;
    LP_filter_DW.obj_n.isInitialized = 0L;
    LP_filter_DW.obj_n.SampleTime = -1.0;
    LP_filter_DW.obj_n.I2CDriverObj.MW_I2C_HANDLE = NULL;
    LP_filter_DW.obj_n.matlabCodegenIsDeleted = false;
    LP_filter_DW.obj_n.SampleTime = LP_filter_P.CurrentRegread_SampleTime;
    obj_0 = &LP_filter_DW.obj_n;
    LP_filter_DW.obj_n.isSetupComplete = false;
    LP_filter_DW.obj_n.isInitialized = 1L;
    LP_filter_B.modename = MW_I2C_MASTER;
    LP_filter_B.i2cname = 0;
    obj_0->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(LP_filter_B.i2cname,
      LP_filter_B.modename);
    LP_filter_DW.obj_n.BusSpeed = 100000UL;
    LP_filter_B.varargin_1 = LP_filter_DW.obj_n.BusSpeed;
    MW_I2C_SetBusSpeed(LP_filter_DW.obj_n.I2CDriverObj.MW_I2C_HANDLE,
                       LP_filter_B.varargin_1);
    LP_filter_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Lowpass Filter' */
    LP_filter_DW.obj._pobj0.matlabCodegenIsDeleted = true;
    LP_filter_DW.obj.matlabCodegenIsDeleted = true;
    LP_filter_DW.obj.isInitialized = 0L;
    LP_filter_DW.obj.NumChannels = -1L;
    LP_filter_DW.obj.matlabCodegenIsDeleted = false;
    LP_filter_DW.obj.isSetupComplete = false;
    LP_filter_DW.obj.isInitialized = 1L;
    iobj_0 = &LP_filter_DW.obj._pobj0;
    iobj_0->isInitialized = 0L;
    iobj_0->isInitialized = 0L;

    /* System object Constructor function: dsp.FIRFilter */
    iobj_0->cSFunObject.P0_InitialStates = 0.0;
    for (LP_filter_B.i = 0; LP_filter_B.i < 39; LP_filter_B.i++) {
      iobj_0->cSFunObject.P1_Coefficients[LP_filter_B.i] = tmp[LP_filter_B.i];
    }

    iobj_0->matlabCodegenIsDeleted = false;
    LP_filter_DW.obj.FilterObj = iobj_0;
    LP_filter_DW.obj.NumChannels = 1L;
    LP_filter_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Lowpass Filter' */

    /* InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter' */
    iobj_0 = LP_filter_DW.obj.FilterObj;
    if (iobj_0->isInitialized == 1L) {
      /* System object Initialization function: dsp.FIRFilter */
      for (LP_filter_B.i = 0; LP_filter_B.i < 38; LP_filter_B.i++) {
        iobj_0->cSFunObject.W0_states[LP_filter_B.i] =
          iobj_0->cSFunObject.P0_InitialStates;
      }
    }

    /* End of InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter' */

    /* Outputs for Atomic SubSystem: '<Root>/Initialize Function' */
    /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
     *  Constant: '<S4>/Constant3'
     */
    LP_filter_B.d = floor(LP_filter_P.Constant3_Value);
    if (rtIsNaN(LP_filter_B.d) || rtIsInf(LP_filter_B.d)) {
      LP_filter_B.d = 0.0;
    } else {
      LP_filter_B.d = fmod(LP_filter_B.d, 65536.0);
    }

    LP_filter_B.i = LP_filter_B.d < 0.0 ? -(int16_T)(uint16_T)-LP_filter_B.d :
      (int16_T)(uint16_T)LP_filter_B.d;

    /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

    /* MATLABSystem: '<S4>/Configuration write' */
    memcpy((void *)&LP_filter_B.SwappedDataBytes[0], (void *)&LP_filter_B.i,
           (uint16_T)((size_t)2 * sizeof(uint8_T)));
    LP_filter_B.b_x[0] = LP_filter_B.SwappedDataBytes[1];
    LP_filter_B.b_x[1] = LP_filter_B.SwappedDataBytes[0];
    memcpy((void *)&LP_filter_B.i, (void *)&LP_filter_B.b_x[0], (uint16_T)
           ((size_t)1 * sizeof(int16_T)));
    memcpy((void *)&LP_filter_B.SwappedDataBytes[0], (void *)&LP_filter_B.i,
           (uint16_T)((size_t)2 * sizeof(uint8_T)));
    LP_filter_B.b_SwappedDataBytes[0] = 0U;
    LP_filter_B.b_SwappedDataBytes[1] = LP_filter_B.SwappedDataBytes[0];
    LP_filter_B.b_SwappedDataBytes[2] = LP_filter_B.SwappedDataBytes[1];
    MW_I2C_MasterWrite(LP_filter_DW.obj_f.I2CDriverObj.MW_I2C_HANDLE, 64UL,
                       &LP_filter_B.b_SwappedDataBytes[0], 3UL, false, false);

    /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
     *  Constant: '<S5>/Constant2'
     */
    LP_filter_B.d = floor(LP_filter_P.Constant2_Value);
    if (rtIsNaN(LP_filter_B.d) || rtIsInf(LP_filter_B.d)) {
      LP_filter_B.d = 0.0;
    } else {
      LP_filter_B.d = fmod(LP_filter_B.d, 65536.0);
    }

    /* DataTypeConversion: '<S5>/Data Type Conversion' */
    rtb_DataTypeConversion_ab = LP_filter_B.d < 0.0 ? -(int16_T)(uint16_T)
      -LP_filter_B.d : (int16_T)(uint16_T)LP_filter_B.d;
    LP_filter_Calibrationwrite(rtb_DataTypeConversion_ab,
      &LP_filter_DW.Calibrationwrite_p);

    /* End of Outputs for SubSystem: '<Root>/Initialize Function' */
  }
}

/* Model terminate function */
void LP_filter_terminate(void)
{
  b_dspcodegen_FIRFilter_LP_fil_T *obj_0;
  codertarget_arduinobase_in_f2_T *obj;
  LP_fi_Calibrationwrite_Term(&LP_filter_DW.Calibrationwrite);

  /* Terminate for MATLABSystem: '<Root>/PWM1' */
  obj = &LP_filter_DW.obj_e;
  if (!LP_filter_DW.obj_e.matlabCodegenIsDeleted) {
    LP_filter_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((LP_filter_DW.obj_e.isInitialized == 1L) &&
        LP_filter_DW.obj_e.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
      MW_PWM_SetDutyCycle(LP_filter_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
      MW_PWM_Close(LP_filter_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM1' */

  /* Terminate for MATLABSystem: '<Root>/PWM2' */
  obj = &LP_filter_DW.obj_d;
  if (!LP_filter_DW.obj_d.matlabCodegenIsDeleted) {
    LP_filter_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((LP_filter_DW.obj_d.isInitialized == 1L) &&
        LP_filter_DW.obj_d.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(LP_filter_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(LP_filter_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM2' */

  /* Terminate for MATLABSystem: '<Root>/Current Reg read' */
  if (!LP_filter_DW.obj_n.matlabCodegenIsDeleted) {
    LP_filter_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((LP_filter_DW.obj_n.isInitialized == 1L) &&
        LP_filter_DW.obj_n.isSetupComplete) {
      MW_I2C_Close(LP_filter_DW.obj_n.I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Current Reg read' */

  /* Terminate for MATLABSystem: '<Root>/Lowpass Filter' */
  if (!LP_filter_DW.obj.matlabCodegenIsDeleted) {
    LP_filter_DW.obj.matlabCodegenIsDeleted = true;
    if ((LP_filter_DW.obj.isInitialized == 1L) &&
        LP_filter_DW.obj.isSetupComplete) {
      obj_0 = LP_filter_DW.obj.FilterObj;
      if (obj_0->isInitialized == 1L) {
        obj_0->isInitialized = 2L;
      }

      LP_filter_DW.obj.NumChannels = -1L;
    }
  }

  obj_0 = &LP_filter_DW.obj._pobj0;
  if (!obj_0->matlabCodegenIsDeleted) {
    obj_0->matlabCodegenIsDeleted = true;
    if (obj_0->isInitialized == 1L) {
      obj_0->isInitialized = 2L;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Lowpass Filter' */
  /* Terminate for Atomic SubSystem: '<Root>/Initialize Function' */
  /* Terminate for MATLABSystem: '<S4>/Configuration write' */
  if (!LP_filter_DW.obj_f.matlabCodegenIsDeleted) {
    LP_filter_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((LP_filter_DW.obj_f.isInitialized == 1L) &&
        LP_filter_DW.obj_f.isSetupComplete) {
      MW_I2C_Close(LP_filter_DW.obj_f.I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Configuration write' */
  LP_fi_Calibrationwrite_Term(&LP_filter_DW.Calibrationwrite_p);

  /* End of Terminate for SubSystem: '<Root>/Initialize Function' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
