/*
 * File: posi.c
 *
 * Code generated for Simulink model 'posi'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Jun  5 16:54:54 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "posi.h"
#include "rtwtypes.h"
#include <math.h>
#include "posi_types.h"
#include "rt_nonfinite.h"
#include "posi_private.h"

/* Block signals (default storage) */
B_posi_T posi_B;

/* Block states (default storage) */
DW_posi_T posi_DW;

/* Real-time model */
static RT_MODEL_posi_T posi_M_;
RT_MODEL_posi_T *const posi_M = &posi_M_;

/* Model step function */
void posi_step(void)
{
  {
    codertarget_arduinobase_int_j_T *obj;
    real_T pwm_cal;
    real_T rtb_Derivative1;
    real_T rtb_Gain12;
    real_T rtb_Gain13;
    real_T *lastU;
    int32_T rtb_Encoder_0;

    /* MATLABSystem: '<S1>/Encoder' */
    if (posi_DW.obj.SampleTime != posi_P.Encoder_SampleTime) {
      posi_DW.obj.SampleTime = posi_P.Encoder_SampleTime;
    }

    if (posi_DW.obj.TunablePropsChanged) {
      posi_DW.obj.TunablePropsChanged = false;
    }

    MW_EncoderRead(posi_DW.obj.Index, &rtb_Encoder_0);

    /* Gain: '<S1>/Gain' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     *  MATLABSystem: '<S1>/Encoder'
     */
    posi_B.Gain = posi_P.Gain_Gain * (real_T)rtb_Encoder_0;

    /* Derivative: '<Root>/Derivative9' incorporates:
     *  Derivative: '<Root>/Derivative1'
     *  Derivative: '<Root>/Derivative7'
     *  Derivative: '<Root>/Derivative8'
     */
    pwm_cal = posi_M->Timing.t[0];
    if ((posi_DW.TimeStampA >= pwm_cal) && (posi_DW.TimeStampB >= pwm_cal)) {
      rtb_Derivative1 = 0.0;
    } else {
      rtb_Derivative1 = posi_DW.TimeStampA;
      lastU = &posi_DW.LastUAtTimeA;
      if (posi_DW.TimeStampA < posi_DW.TimeStampB) {
        if (posi_DW.TimeStampB < pwm_cal) {
          rtb_Derivative1 = posi_DW.TimeStampB;
          lastU = &posi_DW.LastUAtTimeB;
        }
      } else if (posi_DW.TimeStampA >= pwm_cal) {
        rtb_Derivative1 = posi_DW.TimeStampB;
        lastU = &posi_DW.LastUAtTimeB;
      }

      rtb_Derivative1 = (posi_B.Gain - *lastU) / (pwm_cal - rtb_Derivative1);
    }

    /* End of Derivative: '<Root>/Derivative9' */

    /* ManualSwitch: '<Root>/Manual Switch2' incorporates:
     *  Constant: '<Root>/Constant8'
     *  Constant: '<Root>/Constant9'
     */
    if (posi_P.ManualSwitch2_CurrentSetting == 1) {
      rtb_Gain12 = posi_P.Constant8_Value;
    } else {
      rtb_Gain12 = posi_P.Constant9_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch2' */

    /* Sum: '<Root>/Sum2' */
    posi_B.Sum2 = rtb_Gain12 - posi_B.Gain;

    /* Gain: '<Root>/Gain12' incorporates:
     *  Gain: '<Root>/Gain3'
     *  Sum: '<Root>/Sum5'
     */
    rtb_Gain12 = (posi_P.k1 * posi_B.Sum2 - rtb_Derivative1) * posi_P.k2;

    /* Derivative: '<Root>/Derivative7' */
    if ((posi_DW.TimeStampA_i >= pwm_cal) && (posi_DW.TimeStampB_a >= pwm_cal))
    {
      /* Derivative: '<Root>/Derivative7' */
      posi_B.Derivative7 = 0.0;
    } else {
      rtb_Derivative1 = posi_DW.TimeStampA_i;
      lastU = &posi_DW.LastUAtTimeA_f;
      if (posi_DW.TimeStampA_i < posi_DW.TimeStampB_a) {
        if (posi_DW.TimeStampB_a < pwm_cal) {
          rtb_Derivative1 = posi_DW.TimeStampB_a;
          lastU = &posi_DW.LastUAtTimeB_d;
        }
      } else if (posi_DW.TimeStampA_i >= pwm_cal) {
        rtb_Derivative1 = posi_DW.TimeStampB_a;
        lastU = &posi_DW.LastUAtTimeB_d;
      }

      /* Derivative: '<Root>/Derivative7' */
      posi_B.Derivative7 = (posi_B.Sum2 - *lastU) / (pwm_cal - rtb_Derivative1);
    }

    /* Derivative: '<Root>/Derivative8' */
    if ((posi_DW.TimeStampA_a >= pwm_cal) && (posi_DW.TimeStampB_c >= pwm_cal))
    {
      rtb_Derivative1 = 0.0;
    } else {
      rtb_Derivative1 = posi_DW.TimeStampA_a;
      lastU = &posi_DW.LastUAtTimeA_k;
      if (posi_DW.TimeStampA_a < posi_DW.TimeStampB_c) {
        if (posi_DW.TimeStampB_c < pwm_cal) {
          rtb_Derivative1 = posi_DW.TimeStampB_c;
          lastU = &posi_DW.LastUAtTimeB_h;
        }
      } else if (posi_DW.TimeStampA_a >= pwm_cal) {
        rtb_Derivative1 = posi_DW.TimeStampB_c;
        lastU = &posi_DW.LastUAtTimeB_h;
      }

      rtb_Derivative1 = (posi_B.Derivative7 - *lastU) / (pwm_cal -
        rtb_Derivative1);
    }

    /* Gain: '<Root>/Gain13' */
    rtb_Gain13 = 1.0 / posi_P.b * rtb_Derivative1;

    /* Derivative: '<Root>/Derivative1' */
    if ((posi_DW.TimeStampA_in >= pwm_cal) && (posi_DW.TimeStampB_cf >= pwm_cal))
    {
      rtb_Derivative1 = 0.0;
    } else {
      rtb_Derivative1 = posi_DW.TimeStampA_in;
      lastU = &posi_DW.LastUAtTimeA_c;
      if (posi_DW.TimeStampA_in < posi_DW.TimeStampB_cf) {
        if (posi_DW.TimeStampB_cf < pwm_cal) {
          rtb_Derivative1 = posi_DW.TimeStampB_cf;
          lastU = &posi_DW.LastUAtTimeB_b;
        }
      } else if (posi_DW.TimeStampA_in >= pwm_cal) {
        rtb_Derivative1 = posi_DW.TimeStampB_cf;
        lastU = &posi_DW.LastUAtTimeB_b;
      }

      rtb_Derivative1 = (posi_B.Sum2 - *lastU) / (pwm_cal - rtb_Derivative1);
    }

    /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
     *  Gain: '<Root>/Gain11'
     *  Sum: '<Root>/Add1'
     */
    pwm_cal = (((posi_P.b * posi_P.k2 + posi_P.a) / posi_P.b * rtb_Derivative1 +
                rtb_Gain13) + rtb_Gain12) * 254.0 / 22.9;
    if (pwm_cal > 0.0) {
      rtb_Derivative1 = 0.0;
    } else if (pwm_cal < 0.0) {
      rtb_Derivative1 = fabs(pwm_cal);
      pwm_cal = 0.0;
    } else {
      rtb_Derivative1 = 0.0;
      pwm_cal = 0.0;
    }

    /* End of MATLAB Function: '<S1>/MATLAB Function1' */

    /* MATLABSystem: '<S1>/PWM1' */
    obj = &posi_DW.obj_o;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
    if (!(rtb_Derivative1 <= 255.0)) {
      rtb_Derivative1 = 255.0;
    }

    MW_PWM_SetDutyCycle(posi_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE,
                        rtb_Derivative1);

    /* End of MATLABSystem: '<S1>/PWM1' */

    /* MATLABSystem: '<S1>/PWM2' */
    obj = &posi_DW.obj_h;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7U);
    if (!(pwm_cal <= 255.0)) {
      pwm_cal = 255.0;
    }

    MW_PWM_SetDutyCycle(posi_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE, pwm_cal);

    /* End of MATLABSystem: '<S1>/PWM2' */
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative9' */
    if (posi_DW.TimeStampA == (rtInf)) {
      posi_DW.TimeStampA = posi_M->Timing.t[0];
      lastU = &posi_DW.LastUAtTimeA;
    } else if (posi_DW.TimeStampB == (rtInf)) {
      posi_DW.TimeStampB = posi_M->Timing.t[0];
      lastU = &posi_DW.LastUAtTimeB;
    } else if (posi_DW.TimeStampA < posi_DW.TimeStampB) {
      posi_DW.TimeStampA = posi_M->Timing.t[0];
      lastU = &posi_DW.LastUAtTimeA;
    } else {
      posi_DW.TimeStampB = posi_M->Timing.t[0];
      lastU = &posi_DW.LastUAtTimeB;
    }

    *lastU = posi_B.Gain;

    /* End of Update for Derivative: '<Root>/Derivative9' */

    /* Update for Derivative: '<Root>/Derivative7' */
    if (posi_DW.TimeStampA_i == (rtInf)) {
      posi_DW.TimeStampA_i = posi_M->Timing.t[0];
      lastU = &posi_DW.LastUAtTimeA_f;
    } else if (posi_DW.TimeStampB_a == (rtInf)) {
      posi_DW.TimeStampB_a = posi_M->Timing.t[0];
      lastU = &posi_DW.LastUAtTimeB_d;
    } else if (posi_DW.TimeStampA_i < posi_DW.TimeStampB_a) {
      posi_DW.TimeStampA_i = posi_M->Timing.t[0];
      lastU = &posi_DW.LastUAtTimeA_f;
    } else {
      posi_DW.TimeStampB_a = posi_M->Timing.t[0];
      lastU = &posi_DW.LastUAtTimeB_d;
    }

    *lastU = posi_B.Sum2;

    /* End of Update for Derivative: '<Root>/Derivative7' */

    /* Update for Derivative: '<Root>/Derivative8' */
    if (posi_DW.TimeStampA_a == (rtInf)) {
      posi_DW.TimeStampA_a = posi_M->Timing.t[0];
      lastU = &posi_DW.LastUAtTimeA_k;
    } else if (posi_DW.TimeStampB_c == (rtInf)) {
      posi_DW.TimeStampB_c = posi_M->Timing.t[0];
      lastU = &posi_DW.LastUAtTimeB_h;
    } else if (posi_DW.TimeStampA_a < posi_DW.TimeStampB_c) {
      posi_DW.TimeStampA_a = posi_M->Timing.t[0];
      lastU = &posi_DW.LastUAtTimeA_k;
    } else {
      posi_DW.TimeStampB_c = posi_M->Timing.t[0];
      lastU = &posi_DW.LastUAtTimeB_h;
    }

    *lastU = posi_B.Derivative7;

    /* End of Update for Derivative: '<Root>/Derivative8' */

    /* Update for Derivative: '<Root>/Derivative1' */
    if (posi_DW.TimeStampA_in == (rtInf)) {
      posi_DW.TimeStampA_in = posi_M->Timing.t[0];
      lastU = &posi_DW.LastUAtTimeA_c;
    } else if (posi_DW.TimeStampB_cf == (rtInf)) {
      posi_DW.TimeStampB_cf = posi_M->Timing.t[0];
      lastU = &posi_DW.LastUAtTimeB_b;
    } else if (posi_DW.TimeStampA_in < posi_DW.TimeStampB_cf) {
      posi_DW.TimeStampA_in = posi_M->Timing.t[0];
      lastU = &posi_DW.LastUAtTimeA_c;
    } else {
      posi_DW.TimeStampB_cf = posi_M->Timing.t[0];
      lastU = &posi_DW.LastUAtTimeB_b;
    }

    *lastU = posi_B.Sum2;

    /* End of Update for Derivative: '<Root>/Derivative1' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      posi_M->Timing.t[0];

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
      ((posi_M->Timing.clockTick1) * 0.01);

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
  posi_M->Timing.t[0] =
    ((time_T)(++posi_M->Timing.clockTick0)) * posi_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    posi_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void posi_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&posi_M->solverInfo, &posi_M->Timing.simTimeStep);
    rtsiSetTPtr(&posi_M->solverInfo, &rtmGetTPtr(posi_M));
    rtsiSetStepSizePtr(&posi_M->solverInfo, &posi_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&posi_M->solverInfo, (&rtmGetErrorStatus(posi_M)));
    rtsiSetRTModelPtr(&posi_M->solverInfo, posi_M);
  }

  rtsiSetSimTimeStep(&posi_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&posi_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(posi_M, &posi_M->Timing.tArray[0]);
  rtmSetTFinal(posi_M, 10.0);
  posi_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  posi_M->Sizes.checksums[0] = (2617610923U);
  posi_M->Sizes.checksums[1] = (3321671595U);
  posi_M->Sizes.checksums[2] = (144243207U);
  posi_M->Sizes.checksums[3] = (435957366U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    posi_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(posi_M->extModeInfo,
      &posi_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(posi_M->extModeInfo, posi_M->Sizes.checksums);
    rteiSetTPtr(posi_M->extModeInfo, rtmGetTPtr(posi_M));
  }

  {
    codertarget_arduinobase_int_j_T *obj;

    /* InitializeConditions for Derivative: '<Root>/Derivative9' */
    posi_DW.TimeStampA = (rtInf);
    posi_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative7' */
    posi_DW.TimeStampA_i = (rtInf);
    posi_DW.TimeStampB_a = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative8' */
    posi_DW.TimeStampA_a = (rtInf);
    posi_DW.TimeStampB_c = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative1' */
    posi_DW.TimeStampA_in = (rtInf);
    posi_DW.TimeStampB_cf = (rtInf);

    /* Start for MATLABSystem: '<S1>/Encoder' */
    posi_DW.obj.Index = 0U;
    posi_DW.obj.matlabCodegenIsDeleted = false;
    posi_DW.obj.SampleTime = posi_P.Encoder_SampleTime;
    posi_DW.obj.isSetupComplete = false;
    posi_DW.obj.isInitialized = 1;
    MW_EncoderSetup(2U, 3U, &posi_DW.obj.Index);
    posi_DW.obj.isSetupComplete = true;
    posi_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S1>/Encoder' */
    MW_EncoderReset(posi_DW.obj.Index);

    /* Start for MATLABSystem: '<S1>/PWM1' */
    posi_DW.obj_o.matlabCodegenIsDeleted = true;
    posi_DW.obj_o.isInitialized = 0;
    posi_DW.obj_o.matlabCodegenIsDeleted = false;
    obj = &posi_DW.obj_o;
    posi_DW.obj_o.isSetupComplete = false;
    posi_DW.obj_o.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6U, 0.0, 0.0);
    posi_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM2' */
    posi_DW.obj_h.matlabCodegenIsDeleted = true;
    posi_DW.obj_h.isInitialized = 0;
    posi_DW.obj_h.matlabCodegenIsDeleted = false;
    obj = &posi_DW.obj_h;
    posi_DW.obj_h.isSetupComplete = false;
    posi_DW.obj_h.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(7U, 0.0, 0.0);
    posi_DW.obj_h.isSetupComplete = true;
  }
}

/* Model terminate function */
void posi_terminate(void)
{
  codertarget_arduinobase_int_j_T *obj;

  /* Terminate for MATLABSystem: '<S1>/Encoder' */
  if (!posi_DW.obj.matlabCodegenIsDeleted) {
    posi_DW.obj.matlabCodegenIsDeleted = true;
    if ((posi_DW.obj.isInitialized == 1) && posi_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder' */
  /* Terminate for MATLABSystem: '<S1>/PWM1' */
  obj = &posi_DW.obj_o;
  if (!posi_DW.obj_o.matlabCodegenIsDeleted) {
    posi_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((posi_DW.obj_o.isInitialized == 1) && posi_DW.obj_o.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
      MW_PWM_SetDutyCycle(posi_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
      MW_PWM_Close(posi_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM1' */

  /* Terminate for MATLABSystem: '<S1>/PWM2' */
  obj = &posi_DW.obj_h;
  if (!posi_DW.obj_h.matlabCodegenIsDeleted) {
    posi_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((posi_DW.obj_h.isInitialized == 1) && posi_DW.obj_h.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7U);
      MW_PWM_SetDutyCycle(posi_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7U);
      MW_PWM_Close(posi_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
