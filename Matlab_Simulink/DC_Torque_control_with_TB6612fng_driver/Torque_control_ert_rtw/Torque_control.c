/*
 * File: Torque_control.c
 *
 * Code generated for Simulink model 'Torque_control'.
 *
 * Model version                  : 1.154
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Sep  6 14:29:50 2022
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
  {
    codertarget_arduinobase_int_h_T *obj;
    real_T pwm_cal;
    real_T rtb_Derivative4;
    real_T rtb_Gain11;
    real_T rtb_Gain12;
    real_T *lastU;
    int32_T rtb_Encoder1_0;
    int16_T rtb_IN1;
    int16_T rtb_IN2;

    /* MATLABSystem: '<S1>/Encoder1' */
    if (Torque_control_DW.obj.SampleTime != Torque_control_P.Encoder1_SampleTime)
    {
      Torque_control_DW.obj.SampleTime = Torque_control_P.Encoder1_SampleTime;
    }

    if (Torque_control_DW.obj.TunablePropsChanged) {
      Torque_control_DW.obj.TunablePropsChanged = false;
    }

    MW_EncoderRead(Torque_control_DW.obj.Index, &rtb_Encoder1_0);

    /* Gain: '<S3>/Gain' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion1'
     *  Gain: '<S1>/Gain2'
     *  MATLABSystem: '<S1>/Encoder1'
     */
    Torque_control_B.Gain = Torque_control_P.Gain2_Gain * (real_T)rtb_Encoder1_0
      * Torque_control_P.Gain_Gain;

    /* Sum: '<Root>/Sum3' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    Torque_control_B.Sum3 = Torque_control_P.Constant5_Value -
      Torque_control_B.Gain;

    /* Derivative: '<Root>/Derivative6' incorporates:
     *  Derivative: '<Root>/Derivative4'
     *  Derivative: '<Root>/Derivative5'
     *  Derivative: '<Root>/Derivative7'
     */
    pwm_cal = Torque_control_M->Timing.t[0];
    if ((Torque_control_DW.TimeStampA >= pwm_cal) &&
        (Torque_control_DW.TimeStampB >= pwm_cal)) {
      /* Derivative: '<Root>/Derivative6' */
      Torque_control_B.Derivative6 = 0.0;
    } else {
      rtb_Derivative4 = Torque_control_DW.TimeStampA;
      lastU = &Torque_control_DW.LastUAtTimeA;
      if (Torque_control_DW.TimeStampA < Torque_control_DW.TimeStampB) {
        if (Torque_control_DW.TimeStampB < pwm_cal) {
          rtb_Derivative4 = Torque_control_DW.TimeStampB;
          lastU = &Torque_control_DW.LastUAtTimeB;
        }
      } else if (Torque_control_DW.TimeStampA >= pwm_cal) {
        rtb_Derivative4 = Torque_control_DW.TimeStampB;
        lastU = &Torque_control_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/Derivative6' incorporates:
       *  Constant: '<Root>/Constant5'
       */
      Torque_control_B.Derivative6 = (Torque_control_P.Constant5_Value - *lastU)
        / (pwm_cal - rtb_Derivative4);
    }

    /* End of Derivative: '<Root>/Derivative6' */

    /* Derivative: '<Root>/Derivative7' */
    if ((Torque_control_DW.TimeStampA_b >= pwm_cal) &&
        (Torque_control_DW.TimeStampB_b >= pwm_cal)) {
      rtb_Derivative4 = 0.0;
    } else {
      rtb_Derivative4 = Torque_control_DW.TimeStampA_b;
      lastU = &Torque_control_DW.LastUAtTimeA_d;
      if (Torque_control_DW.TimeStampA_b < Torque_control_DW.TimeStampB_b) {
        if (Torque_control_DW.TimeStampB_b < pwm_cal) {
          rtb_Derivative4 = Torque_control_DW.TimeStampB_b;
          lastU = &Torque_control_DW.LastUAtTimeB_l;
        }
      } else if (Torque_control_DW.TimeStampA_b >= pwm_cal) {
        rtb_Derivative4 = Torque_control_DW.TimeStampB_b;
        lastU = &Torque_control_DW.LastUAtTimeB_l;
      }

      rtb_Derivative4 = (Torque_control_B.Derivative6 - *lastU) / (pwm_cal -
        rtb_Derivative4);
    }

    /* Gain: '<Root>/Gain12' */
    rtb_Gain12 = 1.0 / Torque_control_P.b * rtb_Derivative4;

    /* Derivative: '<Root>/Derivative5' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    if ((Torque_control_DW.TimeStampA_b4 >= pwm_cal) &&
        (Torque_control_DW.TimeStampB_p >= pwm_cal)) {
      rtb_Derivative4 = 0.0;
    } else {
      rtb_Derivative4 = Torque_control_DW.TimeStampA_b4;
      lastU = &Torque_control_DW.LastUAtTimeA_l;
      if (Torque_control_DW.TimeStampA_b4 < Torque_control_DW.TimeStampB_p) {
        if (Torque_control_DW.TimeStampB_p < pwm_cal) {
          rtb_Derivative4 = Torque_control_DW.TimeStampB_p;
          lastU = &Torque_control_DW.LastUAtTimeB_a;
        }
      } else if (Torque_control_DW.TimeStampA_b4 >= pwm_cal) {
        rtb_Derivative4 = Torque_control_DW.TimeStampB_p;
        lastU = &Torque_control_DW.LastUAtTimeB_a;
      }

      rtb_Derivative4 = (Torque_control_P.Constant5_Value - *lastU) / (pwm_cal -
        rtb_Derivative4);
    }

    /* Gain: '<Root>/Gain11' */
    rtb_Gain11 = Torque_control_P.a / Torque_control_P.b * rtb_Derivative4;

    /* Gain: '<Root>/Gain10' */
    Torque_control_B.Gain10 = Torque_control_P.kd4 * Torque_control_B.Sum3;

    /* Derivative: '<Root>/Derivative4' */
    if ((Torque_control_DW.TimeStampA_j >= pwm_cal) &&
        (Torque_control_DW.TimeStampB_e >= pwm_cal)) {
      rtb_Derivative4 = 0.0;
    } else {
      rtb_Derivative4 = Torque_control_DW.TimeStampA_j;
      lastU = &Torque_control_DW.LastUAtTimeA_j;
      if (Torque_control_DW.TimeStampA_j < Torque_control_DW.TimeStampB_e) {
        if (Torque_control_DW.TimeStampB_e < pwm_cal) {
          rtb_Derivative4 = Torque_control_DW.TimeStampB_e;
          lastU = &Torque_control_DW.LastUAtTimeB_j;
        }
      } else if (Torque_control_DW.TimeStampA_j >= pwm_cal) {
        rtb_Derivative4 = Torque_control_DW.TimeStampB_e;
        lastU = &Torque_control_DW.LastUAtTimeB_j;
      }

      rtb_Derivative4 = (Torque_control_B.Gain10 - *lastU) / (pwm_cal -
        rtb_Derivative4);
    }

    /* Sum: '<Root>/Add3' incorporates:
     *  Gain: '<Root>/Gain9'
     */
    Torque_control_B.Add3 = ((rtb_Gain12 + rtb_Gain11) + Torque_control_P.kp4 *
      Torque_control_B.Sum3) + rtb_Derivative4;

    /* MATLAB Function: '<S1>/MATLAB Function4' */
    pwm_cal = Torque_control_B.Add3 * 254.0 / 12.0;
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
    obj = &Torque_control_DW.obj_ir;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
    if (!(pwm_cal <= 255.0)) {
      pwm_cal = 255.0;
    }

    MW_PWM_SetDutyCycle(Torque_control_DW.obj_ir.PWMDriverObj.MW_PWM_HANDLE,
                        pwm_cal);

    /* End of MATLABSystem: '<S1>/PWM' */
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative6' incorporates:
     *  Constant: '<Root>/Constant5'
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

    *lastU = Torque_control_P.Constant5_Value;

    /* End of Update for Derivative: '<Root>/Derivative6' */

    /* Update for Derivative: '<Root>/Derivative7' */
    if (Torque_control_DW.TimeStampA_b == (rtInf)) {
      Torque_control_DW.TimeStampA_b = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeA_d;
    } else if (Torque_control_DW.TimeStampB_b == (rtInf)) {
      Torque_control_DW.TimeStampB_b = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeB_l;
    } else if (Torque_control_DW.TimeStampA_b < Torque_control_DW.TimeStampB_b)
    {
      Torque_control_DW.TimeStampA_b = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeA_d;
    } else {
      Torque_control_DW.TimeStampB_b = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeB_l;
    }

    *lastU = Torque_control_B.Derivative6;

    /* End of Update for Derivative: '<Root>/Derivative7' */

    /* Update for Derivative: '<Root>/Derivative5' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    if (Torque_control_DW.TimeStampA_b4 == (rtInf)) {
      Torque_control_DW.TimeStampA_b4 = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeA_l;
    } else if (Torque_control_DW.TimeStampB_p == (rtInf)) {
      Torque_control_DW.TimeStampB_p = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeB_a;
    } else if (Torque_control_DW.TimeStampA_b4 < Torque_control_DW.TimeStampB_p)
    {
      Torque_control_DW.TimeStampA_b4 = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeA_l;
    } else {
      Torque_control_DW.TimeStampB_p = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeB_a;
    }

    *lastU = Torque_control_P.Constant5_Value;

    /* End of Update for Derivative: '<Root>/Derivative5' */

    /* Update for Derivative: '<Root>/Derivative4' */
    if (Torque_control_DW.TimeStampA_j == (rtInf)) {
      Torque_control_DW.TimeStampA_j = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeA_j;
    } else if (Torque_control_DW.TimeStampB_e == (rtInf)) {
      Torque_control_DW.TimeStampB_e = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeB_j;
    } else if (Torque_control_DW.TimeStampA_j < Torque_control_DW.TimeStampB_e)
    {
      Torque_control_DW.TimeStampA_j = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeA_j;
    } else {
      Torque_control_DW.TimeStampB_e = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeB_j;
    }

    *lastU = Torque_control_B.Gain10;

    /* End of Update for Derivative: '<Root>/Derivative4' */
  }

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
  rtmSetTFinal(Torque_control_M, 30.0);
  Torque_control_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Torque_control_M->Sizes.checksums[0] = (1672753294U);
  Torque_control_M->Sizes.checksums[1] = (1749764596U);
  Torque_control_M->Sizes.checksums[2] = (291482187U);
  Torque_control_M->Sizes.checksums[3] = (3533586751U);

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

    /* InitializeConditions for Derivative: '<Root>/Derivative6' */
    Torque_control_DW.TimeStampA = (rtInf);
    Torque_control_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative7' */
    Torque_control_DW.TimeStampA_b = (rtInf);
    Torque_control_DW.TimeStampB_b = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative5' */
    Torque_control_DW.TimeStampA_b4 = (rtInf);
    Torque_control_DW.TimeStampB_p = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative4' */
    Torque_control_DW.TimeStampA_j = (rtInf);
    Torque_control_DW.TimeStampB_e = (rtInf);

    /* Start for MATLABSystem: '<S1>/Encoder1' */
    Torque_control_DW.obj.Index = 0U;
    Torque_control_DW.obj.matlabCodegenIsDeleted = false;
    Torque_control_DW.obj.SampleTime = Torque_control_P.Encoder1_SampleTime;
    Torque_control_DW.obj.isSetupComplete = false;
    Torque_control_DW.obj.isInitialized = 1L;
    MW_EncoderSetup(2UL, 3UL, &Torque_control_DW.obj.Index);
    Torque_control_DW.obj.isSetupComplete = true;
    Torque_control_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S1>/Encoder1' */
    MW_EncoderReset(Torque_control_DW.obj.Index);

    /* Start for MATLABSystem: '<S1>/Digital Output' */
    Torque_control_DW.obj_i.matlabCodegenIsDeleted = false;
    Torque_control_DW.obj_i.isInitialized = 1L;
    digitalIOSetup(5, 1);
    Torque_control_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Output1' */
    Torque_control_DW.obj_e.matlabCodegenIsDeleted = false;
    Torque_control_DW.obj_e.isInitialized = 1L;
    digitalIOSetup(7, 1);
    Torque_control_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM' */
    Torque_control_DW.obj_ir.matlabCodegenIsDeleted = true;
    Torque_control_DW.obj_ir.isInitialized = 0L;
    Torque_control_DW.obj_ir.matlabCodegenIsDeleted = false;
    obj = &Torque_control_DW.obj_ir;
    Torque_control_DW.obj_ir.isSetupComplete = false;
    Torque_control_DW.obj_ir.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(4UL, 0.0, 0.0);
    Torque_control_DW.obj_ir.isSetupComplete = true;
  }
}

/* Model terminate function */
void Torque_control_terminate(void)
{
  codertarget_arduinobase_int_h_T *obj;

  /* Terminate for MATLABSystem: '<S1>/Encoder1' */
  if (!Torque_control_DW.obj.matlabCodegenIsDeleted) {
    Torque_control_DW.obj.matlabCodegenIsDeleted = true;
    if ((Torque_control_DW.obj.isInitialized == 1L) &&
        Torque_control_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder1' */
  /* Terminate for MATLABSystem: '<S1>/Digital Output' */
  if (!Torque_control_DW.obj_i.matlabCodegenIsDeleted) {
    Torque_control_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output' */

  /* Terminate for MATLABSystem: '<S1>/Digital Output1' */
  if (!Torque_control_DW.obj_e.matlabCodegenIsDeleted) {
    Torque_control_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S1>/PWM' */
  obj = &Torque_control_DW.obj_ir;
  if (!Torque_control_DW.obj_ir.matlabCodegenIsDeleted) {
    Torque_control_DW.obj_ir.matlabCodegenIsDeleted = true;
    if ((Torque_control_DW.obj_ir.isInitialized == 1L) &&
        Torque_control_DW.obj_ir.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_SetDutyCycle(Torque_control_DW.obj_ir.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_Close(Torque_control_DW.obj_ir.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
