/*
 * File: position.c
 *
 * Code generated for Simulink model 'position'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Jun  5 17:03:28 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "position.h"
#include "rtwtypes.h"
#include <math.h>
#include "position_types.h"
#include "rt_nonfinite.h"
#include "position_private.h"

/* Block signals (default storage) */
B_position_T position_B;

/* Block states (default storage) */
DW_position_T position_DW;

/* Real-time model */
static RT_MODEL_position_T position_M_;
RT_MODEL_position_T *const position_M = &position_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void position_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(position_M, 2));
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
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (position_M->Timing.TaskCounters.TID[1] == 0) {
    position_M->Timing.RateInteraction.TID1_2 =
      (position_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (position_M->Timing.TaskCounters.TID[2])++;
  if ((position_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.01s, 0.0s] */
    position_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model step function for TID0 */
void position_step0(void)              /* Sample time: [0.0s, 0.0s] */
{
  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  {
    codertarget_arduinobase_int_h_T *obj;
    real_T pwm_cal;
    real_T rtb_Derivative9;
    real_T rtb_Gain11;
    real_T rtb_Gain13;
    real_T *lastU;

    /* RateTransition generated from: '<Root>/Sum2' */
    if (position_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition generated from: '<Root>/Sum2' */
      position_B.TmpRTBAtSum2Inport2 = position_DW.TmpRTBAtSum2Inport2_Buffer0;
    }

    /* End of RateTransition generated from: '<Root>/Sum2' */

    /* ManualSwitch: '<Root>/Manual Switch2' incorporates:
     *  Constant: '<Root>/Constant8'
     *  Constant: '<Root>/Constant9'
     */
    if (position_P.ManualSwitch2_CurrentSetting == 1) {
      pwm_cal = position_P.Constant8_Value;
    } else {
      pwm_cal = position_P.Constant9_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch2' */

    /* Sum: '<Root>/Sum2' */
    position_B.Sum2 = pwm_cal - position_B.TmpRTBAtSum2Inport2;

    /* Derivative: '<Root>/Derivative7' incorporates:
     *  Derivative: '<Root>/Derivative1'
     *  Derivative: '<Root>/Derivative8'
     *  Derivative: '<Root>/Derivative9'
     */
    pwm_cal = position_M->Timing.t[0];
    if ((position_DW.TimeStampA >= pwm_cal) && (position_DW.TimeStampB >=
         pwm_cal)) {
      /* Derivative: '<Root>/Derivative7' */
      position_B.Derivative7 = 0.0;
    } else {
      rtb_Derivative9 = position_DW.TimeStampA;
      lastU = &position_DW.LastUAtTimeA;
      if (position_DW.TimeStampA < position_DW.TimeStampB) {
        if (position_DW.TimeStampB < pwm_cal) {
          rtb_Derivative9 = position_DW.TimeStampB;
          lastU = &position_DW.LastUAtTimeB;
        }
      } else if (position_DW.TimeStampA >= pwm_cal) {
        rtb_Derivative9 = position_DW.TimeStampB;
        lastU = &position_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/Derivative7' */
      position_B.Derivative7 = (position_B.Sum2 - *lastU) / (pwm_cal -
        rtb_Derivative9);
    }

    /* End of Derivative: '<Root>/Derivative7' */

    /* Derivative: '<Root>/Derivative8' */
    if ((position_DW.TimeStampA_a >= pwm_cal) && (position_DW.TimeStampB_c >=
         pwm_cal)) {
      rtb_Derivative9 = 0.0;
    } else {
      rtb_Derivative9 = position_DW.TimeStampA_a;
      lastU = &position_DW.LastUAtTimeA_k;
      if (position_DW.TimeStampA_a < position_DW.TimeStampB_c) {
        if (position_DW.TimeStampB_c < pwm_cal) {
          rtb_Derivative9 = position_DW.TimeStampB_c;
          lastU = &position_DW.LastUAtTimeB_h;
        }
      } else if (position_DW.TimeStampA_a >= pwm_cal) {
        rtb_Derivative9 = position_DW.TimeStampB_c;
        lastU = &position_DW.LastUAtTimeB_h;
      }

      rtb_Derivative9 = (position_B.Derivative7 - *lastU) / (pwm_cal -
        rtb_Derivative9);
    }

    /* Gain: '<Root>/Gain13' */
    rtb_Gain13 = 1.0 / position_P.b * rtb_Derivative9;

    /* Derivative: '<Root>/Derivative1' */
    if ((position_DW.TimeStampA_i >= pwm_cal) && (position_DW.TimeStampB_cf >=
         pwm_cal)) {
      rtb_Derivative9 = 0.0;
    } else {
      rtb_Derivative9 = position_DW.TimeStampA_i;
      lastU = &position_DW.LastUAtTimeA_c;
      if (position_DW.TimeStampA_i < position_DW.TimeStampB_cf) {
        if (position_DW.TimeStampB_cf < pwm_cal) {
          rtb_Derivative9 = position_DW.TimeStampB_cf;
          lastU = &position_DW.LastUAtTimeB_b;
        }
      } else if (position_DW.TimeStampA_i >= pwm_cal) {
        rtb_Derivative9 = position_DW.TimeStampB_cf;
        lastU = &position_DW.LastUAtTimeB_b;
      }

      rtb_Derivative9 = (position_B.Sum2 - *lastU) / (pwm_cal - rtb_Derivative9);
    }

    /* Gain: '<Root>/Gain11' */
    rtb_Gain11 = (position_P.b * position_P.k2 + position_P.a) / position_P.b *
      rtb_Derivative9;

    /* RateTransition generated from: '<Root>/Derivative9' */
    if (position_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition generated from: '<Root>/Derivative9' */
      position_B.TmpRTBAtDerivative9Inport1 =
        position_DW.TmpRTBAtDerivative9Inport1_Buff;
    }

    /* End of RateTransition generated from: '<Root>/Derivative9' */

    /* Derivative: '<Root>/Derivative9' */
    if ((position_DW.TimeStampA_b >= pwm_cal) && (position_DW.TimeStampB_e >=
         pwm_cal)) {
      rtb_Derivative9 = 0.0;
    } else {
      rtb_Derivative9 = position_DW.TimeStampA_b;
      lastU = &position_DW.LastUAtTimeA_c0;
      if (position_DW.TimeStampA_b < position_DW.TimeStampB_e) {
        if (position_DW.TimeStampB_e < pwm_cal) {
          rtb_Derivative9 = position_DW.TimeStampB_e;
          lastU = &position_DW.LastUAtTimeB_e;
        }
      } else if (position_DW.TimeStampA_b >= pwm_cal) {
        rtb_Derivative9 = position_DW.TimeStampB_e;
        lastU = &position_DW.LastUAtTimeB_e;
      }

      rtb_Derivative9 = (position_B.TmpRTBAtDerivative9Inport1 - *lastU) /
        (pwm_cal - rtb_Derivative9);
    }

    /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
     *  Gain: '<Root>/Gain12'
     *  Gain: '<Root>/Gain3'
     *  Sum: '<Root>/Add1'
     *  Sum: '<Root>/Sum5'
     */
    pwm_cal = ((position_P.k1 * position_B.Sum2 - rtb_Derivative9) *
               position_P.k2 + (rtb_Gain13 + rtb_Gain11)) * 254.0 / 22.9;
    if (pwm_cal > 0.0) {
      rtb_Gain13 = 0.0;
    } else if (pwm_cal < 0.0) {
      rtb_Gain13 = fabs(pwm_cal);
      pwm_cal = 0.0;
    } else {
      rtb_Gain13 = 0.0;
      pwm_cal = 0.0;
    }

    /* End of MATLAB Function: '<S1>/MATLAB Function1' */

    /* MATLABSystem: '<S1>/PWM1' */
    obj = &position_DW.obj_o;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
    if (!(rtb_Gain13 <= 255.0)) {
      rtb_Gain13 = 255.0;
    }

    MW_PWM_SetDutyCycle(position_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE, rtb_Gain13);

    /* End of MATLABSystem: '<S1>/PWM1' */

    /* MATLABSystem: '<S1>/PWM2' */
    obj = &position_DW.obj_h;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7U);
    if (!(pwm_cal <= 255.0)) {
      pwm_cal = 255.0;
    }

    MW_PWM_SetDutyCycle(position_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE, pwm_cal);

    /* End of MATLABSystem: '<S1>/PWM2' */
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative7' */
    if (position_DW.TimeStampA == (rtInf)) {
      position_DW.TimeStampA = position_M->Timing.t[0];
      lastU = &position_DW.LastUAtTimeA;
    } else if (position_DW.TimeStampB == (rtInf)) {
      position_DW.TimeStampB = position_M->Timing.t[0];
      lastU = &position_DW.LastUAtTimeB;
    } else if (position_DW.TimeStampA < position_DW.TimeStampB) {
      position_DW.TimeStampA = position_M->Timing.t[0];
      lastU = &position_DW.LastUAtTimeA;
    } else {
      position_DW.TimeStampB = position_M->Timing.t[0];
      lastU = &position_DW.LastUAtTimeB;
    }

    *lastU = position_B.Sum2;

    /* End of Update for Derivative: '<Root>/Derivative7' */

    /* Update for Derivative: '<Root>/Derivative8' */
    if (position_DW.TimeStampA_a == (rtInf)) {
      position_DW.TimeStampA_a = position_M->Timing.t[0];
      lastU = &position_DW.LastUAtTimeA_k;
    } else if (position_DW.TimeStampB_c == (rtInf)) {
      position_DW.TimeStampB_c = position_M->Timing.t[0];
      lastU = &position_DW.LastUAtTimeB_h;
    } else if (position_DW.TimeStampA_a < position_DW.TimeStampB_c) {
      position_DW.TimeStampA_a = position_M->Timing.t[0];
      lastU = &position_DW.LastUAtTimeA_k;
    } else {
      position_DW.TimeStampB_c = position_M->Timing.t[0];
      lastU = &position_DW.LastUAtTimeB_h;
    }

    *lastU = position_B.Derivative7;

    /* End of Update for Derivative: '<Root>/Derivative8' */

    /* Update for Derivative: '<Root>/Derivative1' */
    if (position_DW.TimeStampA_i == (rtInf)) {
      position_DW.TimeStampA_i = position_M->Timing.t[0];
      lastU = &position_DW.LastUAtTimeA_c;
    } else if (position_DW.TimeStampB_cf == (rtInf)) {
      position_DW.TimeStampB_cf = position_M->Timing.t[0];
      lastU = &position_DW.LastUAtTimeB_b;
    } else if (position_DW.TimeStampA_i < position_DW.TimeStampB_cf) {
      position_DW.TimeStampA_i = position_M->Timing.t[0];
      lastU = &position_DW.LastUAtTimeA_c;
    } else {
      position_DW.TimeStampB_cf = position_M->Timing.t[0];
      lastU = &position_DW.LastUAtTimeB_b;
    }

    *lastU = position_B.Sum2;

    /* End of Update for Derivative: '<Root>/Derivative1' */

    /* Update for Derivative: '<Root>/Derivative9' */
    if (position_DW.TimeStampA_b == (rtInf)) {
      position_DW.TimeStampA_b = position_M->Timing.t[0];
      lastU = &position_DW.LastUAtTimeA_c0;
    } else if (position_DW.TimeStampB_e == (rtInf)) {
      position_DW.TimeStampB_e = position_M->Timing.t[0];
      lastU = &position_DW.LastUAtTimeB_e;
    } else if (position_DW.TimeStampA_b < position_DW.TimeStampB_e) {
      position_DW.TimeStampA_b = position_M->Timing.t[0];
      lastU = &position_DW.LastUAtTimeA_c0;
    } else {
      position_DW.TimeStampB_e = position_M->Timing.t[0];
      lastU = &position_DW.LastUAtTimeB_e;
    }

    *lastU = position_B.TmpRTBAtDerivative9Inport1;

    /* End of Update for Derivative: '<Root>/Derivative9' */
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  position_M->Timing.t[0] =
    ((time_T)(++position_M->Timing.clockTick0)) * position_M->Timing.stepSize0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  position_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void position_step2(void)              /* Sample time: [0.01s, 0.0s] */
{
  int32_T rtb_Encoder_0;

  /* MATLABSystem: '<S1>/Encoder' */
  if (position_DW.obj.SampleTime != position_P.Encoder_SampleTime) {
    position_DW.obj.SampleTime = position_P.Encoder_SampleTime;
  }

  if (position_DW.obj.TunablePropsChanged) {
    position_DW.obj.TunablePropsChanged = false;
  }

  MW_EncoderRead(position_DW.obj.Index, &rtb_Encoder_0);

  /* Gain: '<S1>/Gain' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  MATLABSystem: '<S1>/Encoder'
   */
  position_B.Gain = position_P.Gain_Gain * (real_T)rtb_Encoder_0;

  /* RateTransition generated from: '<Root>/Derivative9' */
  position_DW.TmpRTBAtDerivative9Inport1_Buff = position_B.Gain;

  /* RateTransition generated from: '<Root>/Sum2' */
  position_DW.TmpRTBAtSum2Inport2_Buffer0 = position_B.Gain;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  position_M->Timing.clockTick2++;
}

/* Model initialize function */
void position_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&position_M->solverInfo,
                          &position_M->Timing.simTimeStep);
    rtsiSetTPtr(&position_M->solverInfo, &rtmGetTPtr(position_M));
    rtsiSetStepSizePtr(&position_M->solverInfo, &position_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&position_M->solverInfo, (&rtmGetErrorStatus
      (position_M)));
    rtsiSetRTModelPtr(&position_M->solverInfo, position_M);
  }

  rtsiSetSimTimeStep(&position_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&position_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(position_M, &position_M->Timing.tArray[0]);
  rtmSetTFinal(position_M, 8.0);
  position_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  position_M->Sizes.checksums[0] = (153973187U);
  position_M->Sizes.checksums[1] = (874869111U);
  position_M->Sizes.checksums[2] = (3937283990U);
  position_M->Sizes.checksums[3] = (2775954354U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    position_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(position_M->extModeInfo,
      &position_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(position_M->extModeInfo, position_M->Sizes.checksums);
    rteiSetTPtr(position_M->extModeInfo, rtmGetTPtr(position_M));
  }

  {
    codertarget_arduinobase_int_h_T *obj;

    /* Start for RateTransition generated from: '<Root>/Sum2' */
    position_B.TmpRTBAtSum2Inport2 = position_P.TmpRTBAtSum2Inport2_InitialCond;

    /* Start for RateTransition generated from: '<Root>/Derivative9' */
    position_B.TmpRTBAtDerivative9Inport1 =
      position_P.TmpRTBAtDerivative9Inport1_Init;

    /* InitializeConditions for RateTransition generated from: '<Root>/Sum2' */
    position_DW.TmpRTBAtSum2Inport2_Buffer0 =
      position_P.TmpRTBAtSum2Inport2_InitialCond;

    /* InitializeConditions for Derivative: '<Root>/Derivative7' */
    position_DW.TimeStampA = (rtInf);
    position_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative8' */
    position_DW.TimeStampA_a = (rtInf);
    position_DW.TimeStampB_c = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative1' */
    position_DW.TimeStampA_i = (rtInf);
    position_DW.TimeStampB_cf = (rtInf);

    /* InitializeConditions for RateTransition generated from: '<Root>/Derivative9' */
    position_DW.TmpRTBAtDerivative9Inport1_Buff =
      position_P.TmpRTBAtDerivative9Inport1_Init;

    /* InitializeConditions for Derivative: '<Root>/Derivative9' */
    position_DW.TimeStampA_b = (rtInf);
    position_DW.TimeStampB_e = (rtInf);

    /* Start for MATLABSystem: '<S1>/PWM1' */
    position_DW.obj_o.matlabCodegenIsDeleted = true;
    position_DW.obj_o.isInitialized = 0;
    position_DW.obj_o.matlabCodegenIsDeleted = false;
    obj = &position_DW.obj_o;
    position_DW.obj_o.isSetupComplete = false;
    position_DW.obj_o.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6U, 0.0, 0.0);
    position_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM2' */
    position_DW.obj_h.matlabCodegenIsDeleted = true;
    position_DW.obj_h.isInitialized = 0;
    position_DW.obj_h.matlabCodegenIsDeleted = false;
    obj = &position_DW.obj_h;
    position_DW.obj_h.isSetupComplete = false;
    position_DW.obj_h.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(7U, 0.0, 0.0);
    position_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Encoder' */
    position_DW.obj.Index = 0U;
    position_DW.obj.matlabCodegenIsDeleted = false;
    position_DW.obj.SampleTime = position_P.Encoder_SampleTime;
    position_DW.obj.isSetupComplete = false;
    position_DW.obj.isInitialized = 1;
    MW_EncoderSetup(2U, 3U, &position_DW.obj.Index);
    position_DW.obj.isSetupComplete = true;
    position_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S1>/Encoder' */
    MW_EncoderReset(position_DW.obj.Index);
  }
}

/* Model terminate function */
void position_terminate(void)
{
  codertarget_arduinobase_int_h_T *obj;

  /* Terminate for MATLABSystem: '<S1>/PWM1' */
  obj = &position_DW.obj_o;
  if (!position_DW.obj_o.matlabCodegenIsDeleted) {
    position_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((position_DW.obj_o.isInitialized == 1) &&
        position_DW.obj_o.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
      MW_PWM_SetDutyCycle(position_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
      MW_PWM_Close(position_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM1' */

  /* Terminate for MATLABSystem: '<S1>/PWM2' */
  obj = &position_DW.obj_h;
  if (!position_DW.obj_h.matlabCodegenIsDeleted) {
    position_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((position_DW.obj_h.isInitialized == 1) &&
        position_DW.obj_h.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7U);
      MW_PWM_SetDutyCycle(position_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7U);
      MW_PWM_Close(position_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM2' */

  /* Terminate for MATLABSystem: '<S1>/Encoder' */
  if (!position_DW.obj.matlabCodegenIsDeleted) {
    position_DW.obj.matlabCodegenIsDeleted = true;
    if ((position_DW.obj.isInitialized == 1) && position_DW.obj.isSetupComplete)
    {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
