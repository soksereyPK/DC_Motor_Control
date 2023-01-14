/*
 * File: Torque_control.c
 *
 * Code generated for Simulink model 'Torque_control'.
 *
 * Model version                  : 1.164
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Nov 15 09:57:12 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Torque_control.h"
#include "rtwtypes.h"
#include <math.h>
#include "Torque_control_types.h"
#include "rt_nonfinite.h"
#include "Torque_control_private.h"

/* Block signals (default storage) */
B_Torque_control_T Torque_control_B;

/* Block states (default storage) */
DW_Torque_control_T Torque_control_DW;

/* Real-time model */
static RT_MODEL_Torque_control_T Torque_control_M_;
RT_MODEL_Torque_control_T *const Torque_control_M = &Torque_control_M_;

/* Model step function */
void Torque_control_step(void)
{
  codertarget_arduinobase_int_h_T *obj;
  real_T pwm_cal;
  int32_T rtb_Encoder1_0;
  int16_T rtb_IN1;
  int16_T rtb_IN2;

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Sin: '<Root>/uk1'
   */
  if (Torque_control_P.ManualSwitch_CurrentSetting == 1) {
    pwm_cal = sin(Torque_control_P.uk1_Freq * Torque_control_M->Timing.t[0] +
                  Torque_control_P.uk1_Phase) * Torque_control_P.uk1_Amp +
      Torque_control_P.uk1_Bias;
  } else {
    pwm_cal = Torque_control_P.Constant1_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* MATLAB Function: '<Root>/MATLAB Function4' */
  pwm_cal = pwm_cal * 254.0 / 12.0;
  if (pwm_cal > 0.0) {
    rtb_IN1 = 1;
    rtb_IN2 = 0;
  } else if (pwm_cal < 0.0) {
    pwm_cal = fabs(pwm_cal);
    rtb_IN1 = 0;
    rtb_IN2 = 1;
  } else {
    pwm_cal = 0.0;
    rtb_IN1 = 0;
    rtb_IN2 = 0;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function4' */

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(5, (uint8_T)rtb_IN1);

  /* MATLABSystem: '<Root>/Digital Output1' */
  writeDigitalPin(7, (uint8_T)rtb_IN2);

  /* MATLABSystem: '<Root>/PWM' */
  obj = &Torque_control_DW.obj_h;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
  if (!(pwm_cal <= 255.0)) {
    pwm_cal = 255.0;
  }

  MW_PWM_SetDutyCycle(Torque_control_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE,
                      pwm_cal);

  /* End of MATLABSystem: '<Root>/PWM' */

  /* MATLABSystem: '<Root>/Encoder1' */
  if (Torque_control_DW.obj.SampleTime != Torque_control_P.Encoder1_SampleTime)
  {
    Torque_control_DW.obj.SampleTime = Torque_control_P.Encoder1_SampleTime;
  }

  if (Torque_control_DW.obj.TunablePropsChanged) {
    Torque_control_DW.obj.TunablePropsChanged = false;
  }

  MW_EncoderRead(Torque_control_DW.obj.Index, &rtb_Encoder1_0);

  /* Gain: '<S2>/Gain' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion8'
   *  Gain: '<Root>/Gain15'
   *  MATLABSystem: '<Root>/Encoder1'
   */
  Torque_control_B.Gain = Torque_control_P.Gain15_Gain * (real_T)rtb_Encoder1_0 *
    Torque_control_P.Gain_Gain;

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Torque_control_M->Timing.clockTick0 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  {                                    /* Sample time: [0.001s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Torque_control_M->Timing.clockTick1 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Torque_control_M->Timing.t[0] =
    ((time_T)(++Torque_control_M->Timing.clockTick0)) *
    Torque_control_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Torque_control_M->Timing.clockTick1++;
  }
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
    rtsiSetErrorStatusPtr(&Torque_control_M->solverInfo, (&rtmGetErrorStatus
      (Torque_control_M)));
    rtsiSetRTModelPtr(&Torque_control_M->solverInfo, Torque_control_M);
  }

  rtsiSetSimTimeStep(&Torque_control_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Torque_control_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Torque_control_M, &Torque_control_M->Timing.tArray[0]);
  rtmSetTFinal(Torque_control_M, 3.0);
  Torque_control_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Torque_control_M->Sizes.checksums[0] = (1324454194U);
  Torque_control_M->Sizes.checksums[1] = (1704833871U);
  Torque_control_M->Sizes.checksums[2] = (869825197U);
  Torque_control_M->Sizes.checksums[3] = (4125553747U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    Torque_control_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Torque_control_M->extModeInfo,
      &Torque_control_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Torque_control_M->extModeInfo,
                        Torque_control_M->Sizes.checksums);
    rteiSetTPtr(Torque_control_M->extModeInfo, rtmGetTPtr(Torque_control_M));
  }

  {
    codertarget_arduinobase_int_h_T *obj;

    /* Start for MATLABSystem: '<Root>/Digital Output' */
    Torque_control_DW.obj_g.matlabCodegenIsDeleted = false;
    Torque_control_DW.obj_g.isInitialized = 1L;
    digitalIOSetup(5, 1);
    Torque_control_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output1' */
    Torque_control_DW.obj_e.matlabCodegenIsDeleted = false;
    Torque_control_DW.obj_e.isInitialized = 1L;
    digitalIOSetup(7, 1);
    Torque_control_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM' */
    Torque_control_DW.obj_h.matlabCodegenIsDeleted = true;
    Torque_control_DW.obj_h.isInitialized = 0L;
    Torque_control_DW.obj_h.matlabCodegenIsDeleted = false;
    obj = &Torque_control_DW.obj_h;
    Torque_control_DW.obj_h.isSetupComplete = false;
    Torque_control_DW.obj_h.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(4UL, 0.0, 0.0);
    Torque_control_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Encoder1' */
    Torque_control_DW.obj.Index = 0U;
    Torque_control_DW.obj.matlabCodegenIsDeleted = false;
    Torque_control_DW.obj.SampleTime = Torque_control_P.Encoder1_SampleTime;
    Torque_control_DW.obj.isSetupComplete = false;
    Torque_control_DW.obj.isInitialized = 1L;
    MW_EncoderSetup(2UL, 3UL, &Torque_control_DW.obj.Index);
    Torque_control_DW.obj.isSetupComplete = true;
    Torque_control_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<Root>/Encoder1' */
    MW_EncoderReset(Torque_control_DW.obj.Index);
  }
}

/* Model terminate function */
void Torque_control_terminate(void)
{
  codertarget_arduinobase_int_h_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!Torque_control_DW.obj_g.matlabCodegenIsDeleted) {
    Torque_control_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!Torque_control_DW.obj_e.matlabCodegenIsDeleted) {
    Torque_control_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  obj = &Torque_control_DW.obj_h;
  if (!Torque_control_DW.obj_h.matlabCodegenIsDeleted) {
    Torque_control_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Torque_control_DW.obj_h.isInitialized == 1L) &&
        Torque_control_DW.obj_h.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_SetDutyCycle(Torque_control_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_Close(Torque_control_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */

  /* Terminate for MATLABSystem: '<Root>/Encoder1' */
  if (!Torque_control_DW.obj.matlabCodegenIsDeleted) {
    Torque_control_DW.obj.matlabCodegenIsDeleted = true;
    if ((Torque_control_DW.obj.isInitialized == 1L) &&
        Torque_control_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
