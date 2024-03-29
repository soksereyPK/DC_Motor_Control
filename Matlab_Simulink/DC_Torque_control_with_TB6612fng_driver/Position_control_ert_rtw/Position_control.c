/*
 * File: position_control.c
 *
 * Code generated for Simulink model 'position_control'.
 *
 * Model version                  : 2.44
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Apr 26 12:25:19 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "position_control.h"
#include "rtwtypes.h"
#include <math.h>
#include "position_control_types.h"
#include "rt_nonfinite.h"
#include "position_control_private.h"

/* Block signals (default storage) */
B_position_control_T position_control_B;

/* Block states (default storage) */
DW_position_control_T position_control_DW;

/* Real-time model */
static RT_MODEL_position_control_T position_control_M_;
RT_MODEL_position_control_T *const position_control_M = &position_control_M_;

/* Model step function */
void position_control_step(void)
{
  {
    codertarget_arduinobase_int_b_T *obj;
    real_T pwm_cal;
    real_T rtb_Derivative2;
    real_T rtb_Gain8;
    real_T rtb_Gain9;
    real_T rtb_Sum3;
    real_T *lastU;
    int32_T rtb_Encoder_0;

    /* Derivative: '<Root>/Derivative4' incorporates:
     *  Derivative: '<Root>/Derivative2'
     *  Derivative: '<Root>/Derivative3'
     *  Derivative: '<Root>/Derivative5'
     */
    pwm_cal = position_control_M->Timing.t[0];
    if ((position_control_DW.TimeStampA >= pwm_cal) &&
        (position_control_DW.TimeStampB >= pwm_cal)) {
      /* Derivative: '<Root>/Derivative4' */
      position_control_B.Derivative4 = 0.0;
    } else {
      rtb_Derivative2 = position_control_DW.TimeStampA;
      lastU = &position_control_DW.LastUAtTimeA;
      if (position_control_DW.TimeStampA < position_control_DW.TimeStampB) {
        if (position_control_DW.TimeStampB < pwm_cal) {
          rtb_Derivative2 = position_control_DW.TimeStampB;
          lastU = &position_control_DW.LastUAtTimeB;
        }
      } else if (position_control_DW.TimeStampA >= pwm_cal) {
        rtb_Derivative2 = position_control_DW.TimeStampB;
        lastU = &position_control_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/Derivative4' incorporates:
       *  Constant: '<Root>/Constant5'
       */
      position_control_B.Derivative4 = (position_control_P.Constant5_Value -
        *lastU) / (pwm_cal - rtb_Derivative2);
    }

    /* End of Derivative: '<Root>/Derivative4' */

    /* Derivative: '<Root>/Derivative5' */
    if ((position_control_DW.TimeStampA_o >= pwm_cal) &&
        (position_control_DW.TimeStampB_g >= pwm_cal)) {
      rtb_Derivative2 = 0.0;
    } else {
      rtb_Derivative2 = position_control_DW.TimeStampA_o;
      lastU = &position_control_DW.LastUAtTimeA_f;
      if (position_control_DW.TimeStampA_o < position_control_DW.TimeStampB_g) {
        if (position_control_DW.TimeStampB_g < pwm_cal) {
          rtb_Derivative2 = position_control_DW.TimeStampB_g;
          lastU = &position_control_DW.LastUAtTimeB_f;
        }
      } else if (position_control_DW.TimeStampA_o >= pwm_cal) {
        rtb_Derivative2 = position_control_DW.TimeStampB_g;
        lastU = &position_control_DW.LastUAtTimeB_f;
      }

      rtb_Derivative2 = (position_control_B.Derivative4 - *lastU) / (pwm_cal -
        rtb_Derivative2);
    }

    /* Gain: '<Root>/Gain9' */
    rtb_Gain9 = 1.0 / position_control_P.b * rtb_Derivative2;

    /* Derivative: '<Root>/Derivative3' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    if ((position_control_DW.TimeStampA_n >= pwm_cal) &&
        (position_control_DW.TimeStampB_c >= pwm_cal)) {
      rtb_Derivative2 = 0.0;
    } else {
      rtb_Derivative2 = position_control_DW.TimeStampA_n;
      lastU = &position_control_DW.LastUAtTimeA_e;
      if (position_control_DW.TimeStampA_n < position_control_DW.TimeStampB_c) {
        if (position_control_DW.TimeStampB_c < pwm_cal) {
          rtb_Derivative2 = position_control_DW.TimeStampB_c;
          lastU = &position_control_DW.LastUAtTimeB_f3;
        }
      } else if (position_control_DW.TimeStampA_n >= pwm_cal) {
        rtb_Derivative2 = position_control_DW.TimeStampB_c;
        lastU = &position_control_DW.LastUAtTimeB_f3;
      }

      rtb_Derivative2 = (position_control_P.Constant5_Value - *lastU) / (pwm_cal
        - rtb_Derivative2);
    }

    /* Gain: '<Root>/Gain8' */
    rtb_Gain8 = position_control_P.a / position_control_P.b * rtb_Derivative2;

    /* MATLABSystem: '<S1>/Encoder' */
    if (position_control_DW.obj.SampleTime !=
        position_control_P.Encoder_SampleTime) {
      position_control_DW.obj.SampleTime = position_control_P.Encoder_SampleTime;
    }

    if (position_control_DW.obj.TunablePropsChanged) {
      position_control_DW.obj.TunablePropsChanged = false;
    }

    MW_EncoderRead(position_control_DW.obj.Index, &rtb_Encoder_0);

    /* Gain: '<S3>/Gain' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     *  Gain: '<S1>/Gain'
     *  MATLABSystem: '<S1>/Encoder'
     */
    position_control_B.Gain = position_control_P.Gain_Gain * (real_T)
      rtb_Encoder_0 * position_control_P.Gain_Gain_f;

    /* Sum: '<Root>/Sum3' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    rtb_Sum3 = position_control_P.Constant5_Value - position_control_B.Gain;

    /* Gain: '<Root>/Gain7' */
    position_control_B.Gain7 = position_control_P.kd4 * rtb_Sum3;

    /* Derivative: '<Root>/Derivative2' */
    if ((position_control_DW.TimeStampA_g >= pwm_cal) &&
        (position_control_DW.TimeStampB_d >= pwm_cal)) {
      rtb_Derivative2 = 0.0;
    } else {
      rtb_Derivative2 = position_control_DW.TimeStampA_g;
      lastU = &position_control_DW.LastUAtTimeA_b;
      if (position_control_DW.TimeStampA_g < position_control_DW.TimeStampB_d) {
        if (position_control_DW.TimeStampB_d < pwm_cal) {
          rtb_Derivative2 = position_control_DW.TimeStampB_d;
          lastU = &position_control_DW.LastUAtTimeB_c;
        }
      } else if (position_control_DW.TimeStampA_g >= pwm_cal) {
        rtb_Derivative2 = position_control_DW.TimeStampB_d;
        lastU = &position_control_DW.LastUAtTimeB_c;
      }

      rtb_Derivative2 = (position_control_B.Gain7 - *lastU) / (pwm_cal -
        rtb_Derivative2);
    }

    /* Sum: '<Root>/Add2' incorporates:
     *  Gain: '<Root>/Gain6'
     */
    position_control_B.Add2 = ((rtb_Gain9 + rtb_Gain8) + position_control_P.kp4 *
      rtb_Sum3) + rtb_Derivative2;

    /* MATLAB Function: '<S1>/MATLAB Function1' */
    pwm_cal = position_control_B.Add2 * 254.0 / 22.9;
    if (pwm_cal > 0.0) {
      rtb_Gain9 = 0.0;
    } else if (pwm_cal < 0.0) {
      rtb_Gain9 = fabs(pwm_cal);
      pwm_cal = 0.0;
    } else {
      rtb_Gain9 = 0.0;
      pwm_cal = 0.0;
    }

    /* End of MATLAB Function: '<S1>/MATLAB Function1' */

    /* MATLABSystem: '<S1>/PWM1' */
    obj = &position_control_DW.obj_a;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
    if (!(rtb_Gain9 <= 255.0)) {
      rtb_Gain9 = 255.0;
    }

    MW_PWM_SetDutyCycle(position_control_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE,
                        rtb_Gain9);

    /* End of MATLABSystem: '<S1>/PWM1' */

    /* MATLABSystem: '<S1>/PWM2' */
    obj = &position_control_DW.obj_d;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7U);
    if (!(pwm_cal <= 255.0)) {
      pwm_cal = 255.0;
    }

    MW_PWM_SetDutyCycle(position_control_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE,
                        pwm_cal);

    /* End of MATLABSystem: '<S1>/PWM2' */
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative4' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    if (position_control_DW.TimeStampA == (rtInf)) {
      position_control_DW.TimeStampA = position_control_M->Timing.t[0];
      lastU = &position_control_DW.LastUAtTimeA;
    } else if (position_control_DW.TimeStampB == (rtInf)) {
      position_control_DW.TimeStampB = position_control_M->Timing.t[0];
      lastU = &position_control_DW.LastUAtTimeB;
    } else if (position_control_DW.TimeStampA < position_control_DW.TimeStampB)
    {
      position_control_DW.TimeStampA = position_control_M->Timing.t[0];
      lastU = &position_control_DW.LastUAtTimeA;
    } else {
      position_control_DW.TimeStampB = position_control_M->Timing.t[0];
      lastU = &position_control_DW.LastUAtTimeB;
    }

    *lastU = position_control_P.Constant5_Value;

    /* End of Update for Derivative: '<Root>/Derivative4' */

    /* Update for Derivative: '<Root>/Derivative5' */
    if (position_control_DW.TimeStampA_o == (rtInf)) {
      position_control_DW.TimeStampA_o = position_control_M->Timing.t[0];
      lastU = &position_control_DW.LastUAtTimeA_f;
    } else if (position_control_DW.TimeStampB_g == (rtInf)) {
      position_control_DW.TimeStampB_g = position_control_M->Timing.t[0];
      lastU = &position_control_DW.LastUAtTimeB_f;
    } else if (position_control_DW.TimeStampA_o <
               position_control_DW.TimeStampB_g) {
      position_control_DW.TimeStampA_o = position_control_M->Timing.t[0];
      lastU = &position_control_DW.LastUAtTimeA_f;
    } else {
      position_control_DW.TimeStampB_g = position_control_M->Timing.t[0];
      lastU = &position_control_DW.LastUAtTimeB_f;
    }

    *lastU = position_control_B.Derivative4;

    /* End of Update for Derivative: '<Root>/Derivative5' */

    /* Update for Derivative: '<Root>/Derivative3' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    if (position_control_DW.TimeStampA_n == (rtInf)) {
      position_control_DW.TimeStampA_n = position_control_M->Timing.t[0];
      lastU = &position_control_DW.LastUAtTimeA_e;
    } else if (position_control_DW.TimeStampB_c == (rtInf)) {
      position_control_DW.TimeStampB_c = position_control_M->Timing.t[0];
      lastU = &position_control_DW.LastUAtTimeB_f3;
    } else if (position_control_DW.TimeStampA_n <
               position_control_DW.TimeStampB_c) {
      position_control_DW.TimeStampA_n = position_control_M->Timing.t[0];
      lastU = &position_control_DW.LastUAtTimeA_e;
    } else {
      position_control_DW.TimeStampB_c = position_control_M->Timing.t[0];
      lastU = &position_control_DW.LastUAtTimeB_f3;
    }

    *lastU = position_control_P.Constant5_Value;

    /* End of Update for Derivative: '<Root>/Derivative3' */

    /* Update for Derivative: '<Root>/Derivative2' */
    if (position_control_DW.TimeStampA_g == (rtInf)) {
      position_control_DW.TimeStampA_g = position_control_M->Timing.t[0];
      lastU = &position_control_DW.LastUAtTimeA_b;
    } else if (position_control_DW.TimeStampB_d == (rtInf)) {
      position_control_DW.TimeStampB_d = position_control_M->Timing.t[0];
      lastU = &position_control_DW.LastUAtTimeB_c;
    } else if (position_control_DW.TimeStampA_g <
               position_control_DW.TimeStampB_d) {
      position_control_DW.TimeStampA_g = position_control_M->Timing.t[0];
      lastU = &position_control_DW.LastUAtTimeA_b;
    } else {
      position_control_DW.TimeStampB_d = position_control_M->Timing.t[0];
      lastU = &position_control_DW.LastUAtTimeB_c;
    }

    *lastU = position_control_B.Gain7;

    /* End of Update for Derivative: '<Root>/Derivative2' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((position_control_M->Timing.clockTick0 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  {                                    /* Sample time: [0.01s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((position_control_M->Timing.clockTick1 * 1) + 0)
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
  position_control_M->Timing.t[0] =
    ((time_T)(++position_control_M->Timing.clockTick0)) *
    position_control_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    position_control_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void position_control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&position_control_M->solverInfo,
                          &position_control_M->Timing.simTimeStep);
    rtsiSetTPtr(&position_control_M->solverInfo, &rtmGetTPtr(position_control_M));
    rtsiSetStepSizePtr(&position_control_M->solverInfo,
                       &position_control_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&position_control_M->solverInfo, (&rtmGetErrorStatus
      (position_control_M)));
    rtsiSetRTModelPtr(&position_control_M->solverInfo, position_control_M);
  }

  rtsiSetSimTimeStep(&position_control_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&position_control_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(position_control_M, &position_control_M->Timing.tArray[0]);
  rtmSetTFinal(position_control_M, 10.0);
  position_control_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  position_control_M->Sizes.checksums[0] = (316714405U);
  position_control_M->Sizes.checksums[1] = (3083894040U);
  position_control_M->Sizes.checksums[2] = (156597380U);
  position_control_M->Sizes.checksums[3] = (3487608308U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    position_control_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(position_control_M->extModeInfo,
      &position_control_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(position_control_M->extModeInfo,
                        position_control_M->Sizes.checksums);
    rteiSetTPtr(position_control_M->extModeInfo, rtmGetTPtr(position_control_M));
  }

  {
    codertarget_arduinobase_int_b_T *obj;

    /* InitializeConditions for Derivative: '<Root>/Derivative4' */
    position_control_DW.TimeStampA = (rtInf);
    position_control_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative5' */
    position_control_DW.TimeStampA_o = (rtInf);
    position_control_DW.TimeStampB_g = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative3' */
    position_control_DW.TimeStampA_n = (rtInf);
    position_control_DW.TimeStampB_c = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative2' */
    position_control_DW.TimeStampA_g = (rtInf);
    position_control_DW.TimeStampB_d = (rtInf);

    /* Start for MATLABSystem: '<S1>/Encoder' */
    position_control_DW.obj.Index = 0U;
    position_control_DW.obj.matlabCodegenIsDeleted = false;
    position_control_DW.obj.SampleTime = position_control_P.Encoder_SampleTime;
    position_control_DW.obj.isSetupComplete = false;
    position_control_DW.obj.isInitialized = 1;
    MW_EncoderSetup(2U, 3U, &position_control_DW.obj.Index);
    position_control_DW.obj.isSetupComplete = true;
    position_control_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S1>/Encoder' */
    MW_EncoderReset(position_control_DW.obj.Index);

    /* Start for MATLABSystem: '<S1>/PWM1' */
    position_control_DW.obj_a.matlabCodegenIsDeleted = true;
    position_control_DW.obj_a.isInitialized = 0;
    position_control_DW.obj_a.matlabCodegenIsDeleted = false;
    obj = &position_control_DW.obj_a;
    position_control_DW.obj_a.isSetupComplete = false;
    position_control_DW.obj_a.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6U, 0.0, 0.0);
    position_control_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM2' */
    position_control_DW.obj_d.matlabCodegenIsDeleted = true;
    position_control_DW.obj_d.isInitialized = 0;
    position_control_DW.obj_d.matlabCodegenIsDeleted = false;
    obj = &position_control_DW.obj_d;
    position_control_DW.obj_d.isSetupComplete = false;
    position_control_DW.obj_d.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(7U, 0.0, 0.0);
    position_control_DW.obj_d.isSetupComplete = true;
  }
}

/* Model terminate function */
void position_control_terminate(void)
{
  codertarget_arduinobase_int_b_T *obj;

  /* Terminate for MATLABSystem: '<S1>/Encoder' */
  if (!position_control_DW.obj.matlabCodegenIsDeleted) {
    position_control_DW.obj.matlabCodegenIsDeleted = true;
    if ((position_control_DW.obj.isInitialized == 1) &&
        position_control_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder' */
  /* Terminate for MATLABSystem: '<S1>/PWM1' */
  obj = &position_control_DW.obj_a;
  if (!position_control_DW.obj_a.matlabCodegenIsDeleted) {
    position_control_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((position_control_DW.obj_a.isInitialized == 1) &&
        position_control_DW.obj_a.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
      MW_PWM_SetDutyCycle(position_control_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
      MW_PWM_Close(position_control_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM1' */

  /* Terminate for MATLABSystem: '<S1>/PWM2' */
  obj = &position_control_DW.obj_d;
  if (!position_control_DW.obj_d.matlabCodegenIsDeleted) {
    position_control_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((position_control_DW.obj_d.isInitialized == 1) &&
        position_control_DW.obj_d.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7U);
      MW_PWM_SetDutyCycle(position_control_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7U);
      MW_PWM_Close(position_control_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
