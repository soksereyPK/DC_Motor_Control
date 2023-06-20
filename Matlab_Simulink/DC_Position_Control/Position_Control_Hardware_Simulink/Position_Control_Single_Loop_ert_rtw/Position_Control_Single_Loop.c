/*
 * File: Position_Control_Single_Loop.c
 *
 * Code generated for Simulink model 'Position_Control_Single_Loop'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Jun  5 16:56:52 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Position_Control_Single_Loop.h"
#include "rtwtypes.h"
#include <math.h>
#include "Position_Control_Single_Loop_types.h"
#include "rt_nonfinite.h"
#include "Position_Control_Single_Loop_private.h"

/* Block signals (default storage) */
B_Position_Control_Single_Loo_T Position_Control_Single_Loop_B;

/* Block states (default storage) */
DW_Position_Control_Single_Lo_T Position_Control_Single_Loop_DW;

/* Real-time model */
static RT_MODEL_Position_Control_Sin_T Position_Control_Single_Loop_M_;
RT_MODEL_Position_Control_Sin_T *const Position_Control_Single_Loop_M =
  &Position_Control_Single_Loop_M_;

/* Model step function */
void Position_Control_Single_Loop_step(void)
{
  {
    codertarget_arduinobase_int_b_T *obj;
    real_T pwm_cal;
    real_T rtb_Derivative9;
    real_T rtb_Gain11;
    real_T rtb_Gain13;
    real_T *lastU;
    int32_T rtb_Encoder_0;

    /* MATLABSystem: '<S1>/Encoder' */
    if (Position_Control_Single_Loop_DW.obj.SampleTime !=
        Position_Control_Single_Loop_P.Encoder_SampleTime) {
      Position_Control_Single_Loop_DW.obj.SampleTime =
        Position_Control_Single_Loop_P.Encoder_SampleTime;
    }

    if (Position_Control_Single_Loop_DW.obj.TunablePropsChanged) {
      Position_Control_Single_Loop_DW.obj.TunablePropsChanged = false;
    }

    MW_EncoderRead(Position_Control_Single_Loop_DW.obj.Index, &rtb_Encoder_0);

    /* Gain: '<S1>/Gain' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     *  MATLABSystem: '<S1>/Encoder'
     */
    Position_Control_Single_Loop_B.Gain =
      Position_Control_Single_Loop_P.Gain_Gain * (real_T)rtb_Encoder_0;

    /* ManualSwitch: '<Root>/Manual Switch2' incorporates:
     *  Constant: '<Root>/Constant8'
     *  Constant: '<Root>/Constant9'
     */
    if (Position_Control_Single_Loop_P.ManualSwitch2_CurrentSetting == 1) {
      pwm_cal = Position_Control_Single_Loop_P.Constant8_Value;
    } else {
      pwm_cal = Position_Control_Single_Loop_P.Constant9_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch2' */

    /* Sum: '<Root>/Sum2' */
    Position_Control_Single_Loop_B.Sum2 = pwm_cal -
      Position_Control_Single_Loop_B.Gain;

    /* Derivative: '<Root>/Derivative7' incorporates:
     *  Derivative: '<Root>/Derivative1'
     *  Derivative: '<Root>/Derivative8'
     *  Derivative: '<Root>/Derivative9'
     */
    pwm_cal = Position_Control_Single_Loop_M->Timing.t[0];
    if ((Position_Control_Single_Loop_DW.TimeStampA >= pwm_cal) &&
        (Position_Control_Single_Loop_DW.TimeStampB >= pwm_cal)) {
      /* Derivative: '<Root>/Derivative7' */
      Position_Control_Single_Loop_B.Derivative7 = 0.0;
    } else {
      rtb_Derivative9 = Position_Control_Single_Loop_DW.TimeStampA;
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA;
      if (Position_Control_Single_Loop_DW.TimeStampA <
          Position_Control_Single_Loop_DW.TimeStampB) {
        if (Position_Control_Single_Loop_DW.TimeStampB < pwm_cal) {
          rtb_Derivative9 = Position_Control_Single_Loop_DW.TimeStampB;
          lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB;
        }
      } else if (Position_Control_Single_Loop_DW.TimeStampA >= pwm_cal) {
        rtb_Derivative9 = Position_Control_Single_Loop_DW.TimeStampB;
        lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/Derivative7' */
      Position_Control_Single_Loop_B.Derivative7 =
        (Position_Control_Single_Loop_B.Sum2 - *lastU) / (pwm_cal -
        rtb_Derivative9);
    }

    /* End of Derivative: '<Root>/Derivative7' */

    /* Derivative: '<Root>/Derivative8' */
    if ((Position_Control_Single_Loop_DW.TimeStampA_k >= pwm_cal) &&
        (Position_Control_Single_Loop_DW.TimeStampB_a >= pwm_cal)) {
      rtb_Derivative9 = 0.0;
    } else {
      rtb_Derivative9 = Position_Control_Single_Loop_DW.TimeStampA_k;
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA_p;
      if (Position_Control_Single_Loop_DW.TimeStampA_k <
          Position_Control_Single_Loop_DW.TimeStampB_a) {
        if (Position_Control_Single_Loop_DW.TimeStampB_a < pwm_cal) {
          rtb_Derivative9 = Position_Control_Single_Loop_DW.TimeStampB_a;
          lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_d;
        }
      } else if (Position_Control_Single_Loop_DW.TimeStampA_k >= pwm_cal) {
        rtb_Derivative9 = Position_Control_Single_Loop_DW.TimeStampB_a;
        lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_d;
      }

      rtb_Derivative9 = (Position_Control_Single_Loop_B.Derivative7 - *lastU) /
        (pwm_cal - rtb_Derivative9);
    }

    /* Gain: '<Root>/Gain13' */
    rtb_Gain13 = 1.0 / Position_Control_Single_Loop_P.b * rtb_Derivative9;

    /* Derivative: '<Root>/Derivative1' */
    if ((Position_Control_Single_Loop_DW.TimeStampA_g >= pwm_cal) &&
        (Position_Control_Single_Loop_DW.TimeStampB_c >= pwm_cal)) {
      rtb_Derivative9 = 0.0;
    } else {
      rtb_Derivative9 = Position_Control_Single_Loop_DW.TimeStampA_g;
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA_j;
      if (Position_Control_Single_Loop_DW.TimeStampA_g <
          Position_Control_Single_Loop_DW.TimeStampB_c) {
        if (Position_Control_Single_Loop_DW.TimeStampB_c < pwm_cal) {
          rtb_Derivative9 = Position_Control_Single_Loop_DW.TimeStampB_c;
          lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_k;
        }
      } else if (Position_Control_Single_Loop_DW.TimeStampA_g >= pwm_cal) {
        rtb_Derivative9 = Position_Control_Single_Loop_DW.TimeStampB_c;
        lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_k;
      }

      rtb_Derivative9 = (Position_Control_Single_Loop_B.Sum2 - *lastU) /
        (pwm_cal - rtb_Derivative9);
    }

    /* Gain: '<Root>/Gain11' */
    rtb_Gain11 = (Position_Control_Single_Loop_P.b *
                  Position_Control_Single_Loop_P.k2 +
                  Position_Control_Single_Loop_P.a) /
      Position_Control_Single_Loop_P.b * rtb_Derivative9;

    /* Derivative: '<Root>/Derivative9' */
    if ((Position_Control_Single_Loop_DW.TimeStampA_b >= pwm_cal) &&
        (Position_Control_Single_Loop_DW.TimeStampB_j >= pwm_cal)) {
      rtb_Derivative9 = 0.0;
    } else {
      rtb_Derivative9 = Position_Control_Single_Loop_DW.TimeStampA_b;
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA_e;
      if (Position_Control_Single_Loop_DW.TimeStampA_b <
          Position_Control_Single_Loop_DW.TimeStampB_j) {
        if (Position_Control_Single_Loop_DW.TimeStampB_j < pwm_cal) {
          rtb_Derivative9 = Position_Control_Single_Loop_DW.TimeStampB_j;
          lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_g;
        }
      } else if (Position_Control_Single_Loop_DW.TimeStampA_b >= pwm_cal) {
        rtb_Derivative9 = Position_Control_Single_Loop_DW.TimeStampB_j;
        lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_g;
      }

      rtb_Derivative9 = (Position_Control_Single_Loop_B.Gain - *lastU) /
        (pwm_cal - rtb_Derivative9);
    }

    /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
     *  Gain: '<Root>/Gain12'
     *  Gain: '<Root>/Gain3'
     *  Sum: '<Root>/Add1'
     *  Sum: '<Root>/Sum5'
     */
    pwm_cal = ((Position_Control_Single_Loop_P.k1 *
                Position_Control_Single_Loop_B.Sum2 - rtb_Derivative9) *
               Position_Control_Single_Loop_P.k2 + (rtb_Gain13 + rtb_Gain11)) *
      254.0 / 22.9;
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
    obj = &Position_Control_Single_Loop_DW.obj_l;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
    if (!(rtb_Gain13 <= 255.0)) {
      rtb_Gain13 = 255.0;
    }

    MW_PWM_SetDutyCycle
      (Position_Control_Single_Loop_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE,
       rtb_Gain13);

    /* End of MATLABSystem: '<S1>/PWM1' */

    /* MATLABSystem: '<S1>/PWM2' */
    obj = &Position_Control_Single_Loop_DW.obj_e;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7U);
    if (!(pwm_cal <= 255.0)) {
      pwm_cal = 255.0;
    }

    MW_PWM_SetDutyCycle
      (Position_Control_Single_Loop_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, pwm_cal);

    /* End of MATLABSystem: '<S1>/PWM2' */
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative7' */
    if (Position_Control_Single_Loop_DW.TimeStampA == (rtInf)) {
      Position_Control_Single_Loop_DW.TimeStampA =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA;
    } else if (Position_Control_Single_Loop_DW.TimeStampB == (rtInf)) {
      Position_Control_Single_Loop_DW.TimeStampB =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB;
    } else if (Position_Control_Single_Loop_DW.TimeStampA <
               Position_Control_Single_Loop_DW.TimeStampB) {
      Position_Control_Single_Loop_DW.TimeStampA =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA;
    } else {
      Position_Control_Single_Loop_DW.TimeStampB =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB;
    }

    *lastU = Position_Control_Single_Loop_B.Sum2;

    /* End of Update for Derivative: '<Root>/Derivative7' */

    /* Update for Derivative: '<Root>/Derivative8' */
    if (Position_Control_Single_Loop_DW.TimeStampA_k == (rtInf)) {
      Position_Control_Single_Loop_DW.TimeStampA_k =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA_p;
    } else if (Position_Control_Single_Loop_DW.TimeStampB_a == (rtInf)) {
      Position_Control_Single_Loop_DW.TimeStampB_a =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_d;
    } else if (Position_Control_Single_Loop_DW.TimeStampA_k <
               Position_Control_Single_Loop_DW.TimeStampB_a) {
      Position_Control_Single_Loop_DW.TimeStampA_k =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA_p;
    } else {
      Position_Control_Single_Loop_DW.TimeStampB_a =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_d;
    }

    *lastU = Position_Control_Single_Loop_B.Derivative7;

    /* End of Update for Derivative: '<Root>/Derivative8' */

    /* Update for Derivative: '<Root>/Derivative1' */
    if (Position_Control_Single_Loop_DW.TimeStampA_g == (rtInf)) {
      Position_Control_Single_Loop_DW.TimeStampA_g =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA_j;
    } else if (Position_Control_Single_Loop_DW.TimeStampB_c == (rtInf)) {
      Position_Control_Single_Loop_DW.TimeStampB_c =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_k;
    } else if (Position_Control_Single_Loop_DW.TimeStampA_g <
               Position_Control_Single_Loop_DW.TimeStampB_c) {
      Position_Control_Single_Loop_DW.TimeStampA_g =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA_j;
    } else {
      Position_Control_Single_Loop_DW.TimeStampB_c =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_k;
    }

    *lastU = Position_Control_Single_Loop_B.Sum2;

    /* End of Update for Derivative: '<Root>/Derivative1' */

    /* Update for Derivative: '<Root>/Derivative9' */
    if (Position_Control_Single_Loop_DW.TimeStampA_b == (rtInf)) {
      Position_Control_Single_Loop_DW.TimeStampA_b =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA_e;
    } else if (Position_Control_Single_Loop_DW.TimeStampB_j == (rtInf)) {
      Position_Control_Single_Loop_DW.TimeStampB_j =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_g;
    } else if (Position_Control_Single_Loop_DW.TimeStampA_b <
               Position_Control_Single_Loop_DW.TimeStampB_j) {
      Position_Control_Single_Loop_DW.TimeStampA_b =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA_e;
    } else {
      Position_Control_Single_Loop_DW.TimeStampB_j =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_g;
    }

    *lastU = Position_Control_Single_Loop_B.Gain;

    /* End of Update for Derivative: '<Root>/Derivative9' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      Position_Control_Single_Loop_M->Timing.t[0];

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
      ((Position_Control_Single_Loop_M->Timing.clockTick1) * 0.01);

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
  Position_Control_Single_Loop_M->Timing.t[0] =
    ((time_T)(++Position_Control_Single_Loop_M->Timing.clockTick0)) *
    Position_Control_Single_Loop_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Position_Control_Single_Loop_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Position_Control_Single_Loop_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Position_Control_Single_Loop_M->solverInfo,
                          &Position_Control_Single_Loop_M->Timing.simTimeStep);
    rtsiSetTPtr(&Position_Control_Single_Loop_M->solverInfo, &rtmGetTPtr
                (Position_Control_Single_Loop_M));
    rtsiSetStepSizePtr(&Position_Control_Single_Loop_M->solverInfo,
                       &Position_Control_Single_Loop_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Position_Control_Single_Loop_M->solverInfo,
                          (&rtmGetErrorStatus(Position_Control_Single_Loop_M)));
    rtsiSetRTModelPtr(&Position_Control_Single_Loop_M->solverInfo,
                      Position_Control_Single_Loop_M);
  }

  rtsiSetSimTimeStep(&Position_Control_Single_Loop_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetSolverName(&Position_Control_Single_Loop_M->solverInfo,
                    "FixedStepDiscrete");
  rtmSetTPtr(Position_Control_Single_Loop_M,
             &Position_Control_Single_Loop_M->Timing.tArray[0]);
  rtmSetTFinal(Position_Control_Single_Loop_M, 8.0);
  Position_Control_Single_Loop_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Position_Control_Single_Loop_M->Sizes.checksums[0] = (3058565321U);
  Position_Control_Single_Loop_M->Sizes.checksums[1] = (10189223U);
  Position_Control_Single_Loop_M->Sizes.checksums[2] = (856896325U);
  Position_Control_Single_Loop_M->Sizes.checksums[3] = (4102932112U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    Position_Control_Single_Loop_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Position_Control_Single_Loop_M->extModeInfo,
      &Position_Control_Single_Loop_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Position_Control_Single_Loop_M->extModeInfo,
                        Position_Control_Single_Loop_M->Sizes.checksums);
    rteiSetTPtr(Position_Control_Single_Loop_M->extModeInfo, rtmGetTPtr
                (Position_Control_Single_Loop_M));
  }

  {
    codertarget_arduinobase_int_b_T *obj;

    /* InitializeConditions for Derivative: '<Root>/Derivative7' */
    Position_Control_Single_Loop_DW.TimeStampA = (rtInf);
    Position_Control_Single_Loop_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative8' */
    Position_Control_Single_Loop_DW.TimeStampA_k = (rtInf);
    Position_Control_Single_Loop_DW.TimeStampB_a = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative1' */
    Position_Control_Single_Loop_DW.TimeStampA_g = (rtInf);
    Position_Control_Single_Loop_DW.TimeStampB_c = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative9' */
    Position_Control_Single_Loop_DW.TimeStampA_b = (rtInf);
    Position_Control_Single_Loop_DW.TimeStampB_j = (rtInf);

    /* Start for MATLABSystem: '<S1>/Encoder' */
    Position_Control_Single_Loop_DW.obj.Index = 0U;
    Position_Control_Single_Loop_DW.obj.matlabCodegenIsDeleted = false;
    Position_Control_Single_Loop_DW.obj.SampleTime =
      Position_Control_Single_Loop_P.Encoder_SampleTime;
    Position_Control_Single_Loop_DW.obj.isSetupComplete = false;
    Position_Control_Single_Loop_DW.obj.isInitialized = 1;
    MW_EncoderSetup(2U, 3U, &Position_Control_Single_Loop_DW.obj.Index);
    Position_Control_Single_Loop_DW.obj.isSetupComplete = true;
    Position_Control_Single_Loop_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S1>/Encoder' */
    MW_EncoderReset(Position_Control_Single_Loop_DW.obj.Index);

    /* Start for MATLABSystem: '<S1>/PWM1' */
    Position_Control_Single_Loop_DW.obj_l.matlabCodegenIsDeleted = true;
    Position_Control_Single_Loop_DW.obj_l.isInitialized = 0;
    Position_Control_Single_Loop_DW.obj_l.matlabCodegenIsDeleted = false;
    obj = &Position_Control_Single_Loop_DW.obj_l;
    Position_Control_Single_Loop_DW.obj_l.isSetupComplete = false;
    Position_Control_Single_Loop_DW.obj_l.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6U, 0.0, 0.0);
    Position_Control_Single_Loop_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM2' */
    Position_Control_Single_Loop_DW.obj_e.matlabCodegenIsDeleted = true;
    Position_Control_Single_Loop_DW.obj_e.isInitialized = 0;
    Position_Control_Single_Loop_DW.obj_e.matlabCodegenIsDeleted = false;
    obj = &Position_Control_Single_Loop_DW.obj_e;
    Position_Control_Single_Loop_DW.obj_e.isSetupComplete = false;
    Position_Control_Single_Loop_DW.obj_e.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(7U, 0.0, 0.0);
    Position_Control_Single_Loop_DW.obj_e.isSetupComplete = true;
  }
}

/* Model terminate function */
void Position_Control_Single_Loop_terminate(void)
{
  codertarget_arduinobase_int_b_T *obj;

  /* Terminate for MATLABSystem: '<S1>/Encoder' */
  if (!Position_Control_Single_Loop_DW.obj.matlabCodegenIsDeleted) {
    Position_Control_Single_Loop_DW.obj.matlabCodegenIsDeleted = true;
    if ((Position_Control_Single_Loop_DW.obj.isInitialized == 1) &&
        Position_Control_Single_Loop_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder' */
  /* Terminate for MATLABSystem: '<S1>/PWM1' */
  obj = &Position_Control_Single_Loop_DW.obj_l;
  if (!Position_Control_Single_Loop_DW.obj_l.matlabCodegenIsDeleted) {
    Position_Control_Single_Loop_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Position_Control_Single_Loop_DW.obj_l.isInitialized == 1) &&
        Position_Control_Single_Loop_DW.obj_l.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
      MW_PWM_SetDutyCycle
        (Position_Control_Single_Loop_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
      MW_PWM_Close
        (Position_Control_Single_Loop_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM1' */

  /* Terminate for MATLABSystem: '<S1>/PWM2' */
  obj = &Position_Control_Single_Loop_DW.obj_e;
  if (!Position_Control_Single_Loop_DW.obj_e.matlabCodegenIsDeleted) {
    Position_Control_Single_Loop_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Position_Control_Single_Loop_DW.obj_e.isInitialized == 1) &&
        Position_Control_Single_Loop_DW.obj_e.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7U);
      MW_PWM_SetDutyCycle
        (Position_Control_Single_Loop_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7U);
      MW_PWM_Close
        (Position_Control_Single_Loop_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
