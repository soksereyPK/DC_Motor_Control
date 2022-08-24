/*
 * File: Current_test.c
 *
 * Code generated for Simulink model 'Current_test'.
 *
 * Model version                  : 1.39
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Aug 24 13:41:38 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Current_test.h"
#include "rtwtypes.h"
#include <math.h>
#include "Current_test_types.h"
#include "rt_nonfinite.h"
#include "Current_test_private.h"

/* Block signals (default storage) */
B_Current_test_T Current_test_B;

/* Block states (default storage) */
DW_Current_test_T Current_test_DW;

/* Real-time model */
static RT_MODEL_Current_test_T Current_test_M_;
RT_MODEL_Current_test_T *const Current_test_M = &Current_test_M_;

/* Model step function */
void Current_test_step(void)
{
  {
    codertarget_arduinobase_int_d_T *obj;
    real_T pwm_cal;
    real_T rtb_Derivative4;
    real_T rtb_Gain11;
    real_T rtb_Gain12;
    real_T *lastU;
    int32_T rtb_Encoder1_0;
    int16_T rtb_IN1;
    int16_T rtb_IN2;

    /* MATLABSystem: '<S1>/Encoder1' */
    if (Current_test_DW.obj.SampleTime != Current_test_P.Encoder1_SampleTime) {
      Current_test_DW.obj.SampleTime = Current_test_P.Encoder1_SampleTime;
    }

    if (Current_test_DW.obj.TunablePropsChanged) {
      Current_test_DW.obj.TunablePropsChanged = false;
    }

    MW_EncoderRead(Current_test_DW.obj.Index, &rtb_Encoder1_0);

    /* Gain: '<S1>/Gain2' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion1'
     *  MATLABSystem: '<S1>/Encoder1'
     */
    Current_test_B.Gain2 = Current_test_P.Gain2_Gain * (real_T)rtb_Encoder1_0;

    /* Sum: '<Root>/Sum3' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    Current_test_B.Sum3 = Current_test_P.Constant5_Value - Current_test_B.Gain2;

    /* Derivative: '<Root>/Derivative6' incorporates:
     *  Derivative: '<Root>/Derivative4'
     *  Derivative: '<Root>/Derivative5'
     *  Derivative: '<Root>/Derivative7'
     */
    pwm_cal = Current_test_M->Timing.t[0];
    if ((Current_test_DW.TimeStampA >= pwm_cal) && (Current_test_DW.TimeStampB >=
         pwm_cal)) {
      /* Derivative: '<Root>/Derivative6' */
      Current_test_B.Derivative6 = 0.0;
    } else {
      rtb_Derivative4 = Current_test_DW.TimeStampA;
      lastU = &Current_test_DW.LastUAtTimeA;
      if (Current_test_DW.TimeStampA < Current_test_DW.TimeStampB) {
        if (Current_test_DW.TimeStampB < pwm_cal) {
          rtb_Derivative4 = Current_test_DW.TimeStampB;
          lastU = &Current_test_DW.LastUAtTimeB;
        }
      } else if (Current_test_DW.TimeStampA >= pwm_cal) {
        rtb_Derivative4 = Current_test_DW.TimeStampB;
        lastU = &Current_test_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/Derivative6' incorporates:
       *  Constant: '<Root>/Constant5'
       */
      Current_test_B.Derivative6 = (Current_test_P.Constant5_Value - *lastU) /
        (pwm_cal - rtb_Derivative4);
    }

    /* End of Derivative: '<Root>/Derivative6' */

    /* Derivative: '<Root>/Derivative7' */
    if ((Current_test_DW.TimeStampA_b >= pwm_cal) &&
        (Current_test_DW.TimeStampB_g >= pwm_cal)) {
      rtb_Derivative4 = 0.0;
    } else {
      rtb_Derivative4 = Current_test_DW.TimeStampA_b;
      lastU = &Current_test_DW.LastUAtTimeA_b;
      if (Current_test_DW.TimeStampA_b < Current_test_DW.TimeStampB_g) {
        if (Current_test_DW.TimeStampB_g < pwm_cal) {
          rtb_Derivative4 = Current_test_DW.TimeStampB_g;
          lastU = &Current_test_DW.LastUAtTimeB_a;
        }
      } else if (Current_test_DW.TimeStampA_b >= pwm_cal) {
        rtb_Derivative4 = Current_test_DW.TimeStampB_g;
        lastU = &Current_test_DW.LastUAtTimeB_a;
      }

      rtb_Derivative4 = (Current_test_B.Derivative6 - *lastU) / (pwm_cal -
        rtb_Derivative4);
    }

    /* Gain: '<Root>/Gain12' */
    rtb_Gain12 = 1.0 / Current_test_P.b * rtb_Derivative4;

    /* Derivative: '<Root>/Derivative5' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    if ((Current_test_DW.TimeStampA_m >= pwm_cal) &&
        (Current_test_DW.TimeStampB_n >= pwm_cal)) {
      rtb_Derivative4 = 0.0;
    } else {
      rtb_Derivative4 = Current_test_DW.TimeStampA_m;
      lastU = &Current_test_DW.LastUAtTimeA_g;
      if (Current_test_DW.TimeStampA_m < Current_test_DW.TimeStampB_n) {
        if (Current_test_DW.TimeStampB_n < pwm_cal) {
          rtb_Derivative4 = Current_test_DW.TimeStampB_n;
          lastU = &Current_test_DW.LastUAtTimeB_b;
        }
      } else if (Current_test_DW.TimeStampA_m >= pwm_cal) {
        rtb_Derivative4 = Current_test_DW.TimeStampB_n;
        lastU = &Current_test_DW.LastUAtTimeB_b;
      }

      rtb_Derivative4 = (Current_test_P.Constant5_Value - *lastU) / (pwm_cal -
        rtb_Derivative4);
    }

    /* Gain: '<Root>/Gain11' */
    rtb_Gain11 = Current_test_P.a / Current_test_P.b * rtb_Derivative4;

    /* Gain: '<Root>/Gain10' */
    Current_test_B.Gain10 = Current_test_P.kd4 * Current_test_B.Sum3;

    /* Derivative: '<Root>/Derivative4' */
    if ((Current_test_DW.TimeStampA_n >= pwm_cal) &&
        (Current_test_DW.TimeStampB_b >= pwm_cal)) {
      rtb_Derivative4 = 0.0;
    } else {
      rtb_Derivative4 = Current_test_DW.TimeStampA_n;
      lastU = &Current_test_DW.LastUAtTimeA_j;
      if (Current_test_DW.TimeStampA_n < Current_test_DW.TimeStampB_b) {
        if (Current_test_DW.TimeStampB_b < pwm_cal) {
          rtb_Derivative4 = Current_test_DW.TimeStampB_b;
          lastU = &Current_test_DW.LastUAtTimeB_m;
        }
      } else if (Current_test_DW.TimeStampA_n >= pwm_cal) {
        rtb_Derivative4 = Current_test_DW.TimeStampB_b;
        lastU = &Current_test_DW.LastUAtTimeB_m;
      }

      rtb_Derivative4 = (Current_test_B.Gain10 - *lastU) / (pwm_cal -
        rtb_Derivative4);
    }

    /* Sum: '<Root>/Add3' incorporates:
     *  Gain: '<Root>/Gain9'
     */
    Current_test_B.Add3 = ((rtb_Gain12 + rtb_Gain11) + Current_test_P.kp4 *
      Current_test_B.Sum3) + rtb_Derivative4;

    /* MATLAB Function: '<S1>/MATLAB Function4' */
    pwm_cal = Current_test_B.Add3 * 254.0 / 12.0;
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

    /* End of MATLAB Function: '<S1>/MATLAB Function4' */

    /* MATLABSystem: '<S1>/Digital Output' */
    writeDigitalPin(5, (uint8_T)rtb_IN1);

    /* MATLABSystem: '<S1>/Digital Output1' */
    writeDigitalPin(7, (uint8_T)rtb_IN2);

    /* MATLABSystem: '<S1>/PWM' */
    obj = &Current_test_DW.obj_h;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
    if (!(pwm_cal <= 255.0)) {
      pwm_cal = 255.0;
    }

    MW_PWM_SetDutyCycle(Current_test_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE,
                        pwm_cal);

    /* End of MATLABSystem: '<S1>/PWM' */
    /* Gain: '<S3>/Gain' */
    Current_test_B.Gain = Current_test_P.Gain_Gain * Current_test_B.Gain2;
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative6' incorporates:
     *  Constant: '<Root>/Constant5'
     */
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

    *lastU = Current_test_P.Constant5_Value;

    /* End of Update for Derivative: '<Root>/Derivative6' */

    /* Update for Derivative: '<Root>/Derivative7' */
    if (Current_test_DW.TimeStampA_b == (rtInf)) {
      Current_test_DW.TimeStampA_b = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeA_b;
    } else if (Current_test_DW.TimeStampB_g == (rtInf)) {
      Current_test_DW.TimeStampB_g = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeB_a;
    } else if (Current_test_DW.TimeStampA_b < Current_test_DW.TimeStampB_g) {
      Current_test_DW.TimeStampA_b = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeA_b;
    } else {
      Current_test_DW.TimeStampB_g = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeB_a;
    }

    *lastU = Current_test_B.Derivative6;

    /* End of Update for Derivative: '<Root>/Derivative7' */

    /* Update for Derivative: '<Root>/Derivative5' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    if (Current_test_DW.TimeStampA_m == (rtInf)) {
      Current_test_DW.TimeStampA_m = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeA_g;
    } else if (Current_test_DW.TimeStampB_n == (rtInf)) {
      Current_test_DW.TimeStampB_n = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeB_b;
    } else if (Current_test_DW.TimeStampA_m < Current_test_DW.TimeStampB_n) {
      Current_test_DW.TimeStampA_m = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeA_g;
    } else {
      Current_test_DW.TimeStampB_n = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeB_b;
    }

    *lastU = Current_test_P.Constant5_Value;

    /* End of Update for Derivative: '<Root>/Derivative5' */

    /* Update for Derivative: '<Root>/Derivative4' */
    if (Current_test_DW.TimeStampA_n == (rtInf)) {
      Current_test_DW.TimeStampA_n = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeA_j;
    } else if (Current_test_DW.TimeStampB_b == (rtInf)) {
      Current_test_DW.TimeStampB_b = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeB_m;
    } else if (Current_test_DW.TimeStampA_n < Current_test_DW.TimeStampB_b) {
      Current_test_DW.TimeStampA_n = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeA_j;
    } else {
      Current_test_DW.TimeStampB_b = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeB_m;
    }

    *lastU = Current_test_B.Gain10;

    /* End of Update for Derivative: '<Root>/Derivative4' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Current_test_M->Timing.clockTick0 * 1) + 0)
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
      ((Current_test_M->Timing.clockTick1 * 1) + 0)
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
  Current_test_M->Timing.t[0] =
    ((time_T)(++Current_test_M->Timing.clockTick0)) *
    Current_test_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Current_test_M->Timing.clockTick1++;
  }
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
  Current_test_M->Sizes.checksums[0] = (3290361825U);
  Current_test_M->Sizes.checksums[1] = (3528571779U);
  Current_test_M->Sizes.checksums[2] = (3811198885U);
  Current_test_M->Sizes.checksums[3] = (2549592049U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    Current_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Current_test_M->extModeInfo,
      &Current_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Current_test_M->extModeInfo,
                        Current_test_M->Sizes.checksums);
    rteiSetTPtr(Current_test_M->extModeInfo, rtmGetTPtr(Current_test_M));
  }

  {
    codertarget_arduinobase_int_d_T *obj;

    /* InitializeConditions for Derivative: '<Root>/Derivative6' */
    Current_test_DW.TimeStampA = (rtInf);
    Current_test_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative7' */
    Current_test_DW.TimeStampA_b = (rtInf);
    Current_test_DW.TimeStampB_g = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative5' */
    Current_test_DW.TimeStampA_m = (rtInf);
    Current_test_DW.TimeStampB_n = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative4' */
    Current_test_DW.TimeStampA_n = (rtInf);
    Current_test_DW.TimeStampB_b = (rtInf);

    /* Start for MATLABSystem: '<S1>/Encoder1' */
    Current_test_DW.obj.Index = 0U;
    Current_test_DW.obj.matlabCodegenIsDeleted = false;
    Current_test_DW.obj.SampleTime = Current_test_P.Encoder1_SampleTime;
    Current_test_DW.obj.isSetupComplete = false;
    Current_test_DW.obj.isInitialized = 1L;
    MW_EncoderSetup(2UL, 3UL, &Current_test_DW.obj.Index);
    Current_test_DW.obj.isSetupComplete = true;
    Current_test_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S1>/Encoder1' */
    MW_EncoderReset(Current_test_DW.obj.Index);

    /* Start for MATLABSystem: '<S1>/Digital Output' */
    Current_test_DW.obj_g.matlabCodegenIsDeleted = false;
    Current_test_DW.obj_g.isInitialized = 1L;
    digitalIOSetup(5, 1);
    Current_test_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Output1' */
    Current_test_DW.obj_e.matlabCodegenIsDeleted = false;
    Current_test_DW.obj_e.isInitialized = 1L;
    digitalIOSetup(7, 1);
    Current_test_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM' */
    Current_test_DW.obj_h.matlabCodegenIsDeleted = true;
    Current_test_DW.obj_h.isInitialized = 0L;
    Current_test_DW.obj_h.matlabCodegenIsDeleted = false;
    obj = &Current_test_DW.obj_h;
    Current_test_DW.obj_h.isSetupComplete = false;
    Current_test_DW.obj_h.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(4UL, 0.0, 0.0);
    Current_test_DW.obj_h.isSetupComplete = true;
  }
}

/* Model terminate function */
void Current_test_terminate(void)
{
  codertarget_arduinobase_int_d_T *obj;

  /* Terminate for MATLABSystem: '<S1>/Encoder1' */
  if (!Current_test_DW.obj.matlabCodegenIsDeleted) {
    Current_test_DW.obj.matlabCodegenIsDeleted = true;
    if ((Current_test_DW.obj.isInitialized == 1L) &&
        Current_test_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder1' */
  /* Terminate for MATLABSystem: '<S1>/Digital Output' */
  if (!Current_test_DW.obj_g.matlabCodegenIsDeleted) {
    Current_test_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output' */

  /* Terminate for MATLABSystem: '<S1>/Digital Output1' */
  if (!Current_test_DW.obj_e.matlabCodegenIsDeleted) {
    Current_test_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S1>/PWM' */
  obj = &Current_test_DW.obj_h;
  if (!Current_test_DW.obj_h.matlabCodegenIsDeleted) {
    Current_test_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Current_test_DW.obj_h.isInitialized == 1L) &&
        Current_test_DW.obj_h.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_SetDutyCycle(Current_test_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_Close(Current_test_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
