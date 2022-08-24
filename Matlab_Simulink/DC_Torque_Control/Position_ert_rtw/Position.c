/*
 * File: Position.c
 *
 * Code generated for Simulink model 'Position'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Aug 24 13:44:21 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Position.h"
#include "rtwtypes.h"
#include <math.h>
#include "Position_types.h"
#include "rt_nonfinite.h"
#include "Position_private.h"

/* Block signals (default storage) */
B_Position_T Position_B;

/* Block states (default storage) */
DW_Position_T Position_DW;

/* Real-time model */
static RT_MODEL_Position_T Position_M_;
RT_MODEL_Position_T *const Position_M = &Position_M_;

/* Model step function */
void Position_step(void)
{
  {
    codertarget_arduinobase_int_c_T *obj;
    real_T pwm_cal;
    real_T rtb_Derivative4;
    real_T rtb_Gain11;
    real_T rtb_Gain12;
    real_T *lastU;
    int32_T rtb_Encoder1_0;
    int16_T rtb_IN1;
    int16_T rtb_IN2;

    /* MATLABSystem: '<S1>/Encoder1' */
    if (Position_DW.obj.SampleTime != Position_P.Encoder1_SampleTime) {
      Position_DW.obj.SampleTime = Position_P.Encoder1_SampleTime;
    }

    if (Position_DW.obj.TunablePropsChanged) {
      Position_DW.obj.TunablePropsChanged = false;
    }

    MW_EncoderRead(Position_DW.obj.Index, &rtb_Encoder1_0);

    /* Gain: '<S1>/Gain2' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion1'
     *  MATLABSystem: '<S1>/Encoder1'
     */
    Position_B.Gain2 = Position_P.Gain2_Gain * (real_T)rtb_Encoder1_0;

    /* Sum: '<Root>/Sum3' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    Position_B.Sum3 = Position_P.Constant5_Value - Position_B.Gain2;

    /* Derivative: '<Root>/Derivative6' incorporates:
     *  Derivative: '<Root>/Derivative4'
     *  Derivative: '<Root>/Derivative5'
     *  Derivative: '<Root>/Derivative7'
     */
    pwm_cal = Position_M->Timing.t[0];
    if ((Position_DW.TimeStampA >= pwm_cal) && (Position_DW.TimeStampB >=
         pwm_cal)) {
      /* Derivative: '<Root>/Derivative6' */
      Position_B.Derivative6 = 0.0;
    } else {
      rtb_Derivative4 = Position_DW.TimeStampA;
      lastU = &Position_DW.LastUAtTimeA;
      if (Position_DW.TimeStampA < Position_DW.TimeStampB) {
        if (Position_DW.TimeStampB < pwm_cal) {
          rtb_Derivative4 = Position_DW.TimeStampB;
          lastU = &Position_DW.LastUAtTimeB;
        }
      } else if (Position_DW.TimeStampA >= pwm_cal) {
        rtb_Derivative4 = Position_DW.TimeStampB;
        lastU = &Position_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/Derivative6' incorporates:
       *  Constant: '<Root>/Constant5'
       */
      Position_B.Derivative6 = (Position_P.Constant5_Value - *lastU) / (pwm_cal
        - rtb_Derivative4);
    }

    /* End of Derivative: '<Root>/Derivative6' */

    /* Derivative: '<Root>/Derivative7' */
    if ((Position_DW.TimeStampA_a >= pwm_cal) && (Position_DW.TimeStampB_c >=
         pwm_cal)) {
      rtb_Derivative4 = 0.0;
    } else {
      rtb_Derivative4 = Position_DW.TimeStampA_a;
      lastU = &Position_DW.LastUAtTimeA_k;
      if (Position_DW.TimeStampA_a < Position_DW.TimeStampB_c) {
        if (Position_DW.TimeStampB_c < pwm_cal) {
          rtb_Derivative4 = Position_DW.TimeStampB_c;
          lastU = &Position_DW.LastUAtTimeB_h;
        }
      } else if (Position_DW.TimeStampA_a >= pwm_cal) {
        rtb_Derivative4 = Position_DW.TimeStampB_c;
        lastU = &Position_DW.LastUAtTimeB_h;
      }

      rtb_Derivative4 = (Position_B.Derivative6 - *lastU) / (pwm_cal -
        rtb_Derivative4);
    }

    /* Gain: '<Root>/Gain12' */
    rtb_Gain12 = 1.0 / Position_P.b * rtb_Derivative4;

    /* Derivative: '<Root>/Derivative5' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    if ((Position_DW.TimeStampA_i >= pwm_cal) && (Position_DW.TimeStampB_cf >=
         pwm_cal)) {
      rtb_Derivative4 = 0.0;
    } else {
      rtb_Derivative4 = Position_DW.TimeStampA_i;
      lastU = &Position_DW.LastUAtTimeA_c;
      if (Position_DW.TimeStampA_i < Position_DW.TimeStampB_cf) {
        if (Position_DW.TimeStampB_cf < pwm_cal) {
          rtb_Derivative4 = Position_DW.TimeStampB_cf;
          lastU = &Position_DW.LastUAtTimeB_b;
        }
      } else if (Position_DW.TimeStampA_i >= pwm_cal) {
        rtb_Derivative4 = Position_DW.TimeStampB_cf;
        lastU = &Position_DW.LastUAtTimeB_b;
      }

      rtb_Derivative4 = (Position_P.Constant5_Value - *lastU) / (pwm_cal -
        rtb_Derivative4);
    }

    /* Gain: '<Root>/Gain11' */
    rtb_Gain11 = Position_P.a / Position_P.b * rtb_Derivative4;

    /* Gain: '<Root>/Gain10' */
    Position_B.Gain10 = Position_P.kd4 * Position_B.Sum3;

    /* Derivative: '<Root>/Derivative4' */
    if ((Position_DW.TimeStampA_g >= pwm_cal) && (Position_DW.TimeStampB_i >=
         pwm_cal)) {
      rtb_Derivative4 = 0.0;
    } else {
      rtb_Derivative4 = Position_DW.TimeStampA_g;
      lastU = &Position_DW.LastUAtTimeA_d;
      if (Position_DW.TimeStampA_g < Position_DW.TimeStampB_i) {
        if (Position_DW.TimeStampB_i < pwm_cal) {
          rtb_Derivative4 = Position_DW.TimeStampB_i;
          lastU = &Position_DW.LastUAtTimeB_a;
        }
      } else if (Position_DW.TimeStampA_g >= pwm_cal) {
        rtb_Derivative4 = Position_DW.TimeStampB_i;
        lastU = &Position_DW.LastUAtTimeB_a;
      }

      rtb_Derivative4 = (Position_B.Gain10 - *lastU) / (pwm_cal -
        rtb_Derivative4);
    }

    /* Sum: '<Root>/Add3' incorporates:
     *  Gain: '<Root>/Gain9'
     */
    Position_B.Add3 = ((rtb_Gain12 + rtb_Gain11) + Position_P.kp4 *
                       Position_B.Sum3) + rtb_Derivative4;

    /* MATLAB Function: '<S1>/MATLAB Function4' */
    pwm_cal = Position_B.Add3 * 254.0 / 12.0;
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
    obj = &Position_DW.obj_no;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
    if (!(pwm_cal <= 255.0)) {
      pwm_cal = 255.0;
    }

    MW_PWM_SetDutyCycle(Position_DW.obj_no.PWMDriverObj.MW_PWM_HANDLE, pwm_cal);

    /* End of MATLABSystem: '<S1>/PWM' */
    /* Gain: '<S3>/Gain' */
    Position_B.Gain = Position_P.Gain_Gain * Position_B.Gain2;
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative6' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    if (Position_DW.TimeStampA == (rtInf)) {
      Position_DW.TimeStampA = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeA;
    } else if (Position_DW.TimeStampB == (rtInf)) {
      Position_DW.TimeStampB = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeB;
    } else if (Position_DW.TimeStampA < Position_DW.TimeStampB) {
      Position_DW.TimeStampA = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeA;
    } else {
      Position_DW.TimeStampB = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeB;
    }

    *lastU = Position_P.Constant5_Value;

    /* End of Update for Derivative: '<Root>/Derivative6' */

    /* Update for Derivative: '<Root>/Derivative7' */
    if (Position_DW.TimeStampA_a == (rtInf)) {
      Position_DW.TimeStampA_a = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeA_k;
    } else if (Position_DW.TimeStampB_c == (rtInf)) {
      Position_DW.TimeStampB_c = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeB_h;
    } else if (Position_DW.TimeStampA_a < Position_DW.TimeStampB_c) {
      Position_DW.TimeStampA_a = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeA_k;
    } else {
      Position_DW.TimeStampB_c = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeB_h;
    }

    *lastU = Position_B.Derivative6;

    /* End of Update for Derivative: '<Root>/Derivative7' */

    /* Update for Derivative: '<Root>/Derivative5' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    if (Position_DW.TimeStampA_i == (rtInf)) {
      Position_DW.TimeStampA_i = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeA_c;
    } else if (Position_DW.TimeStampB_cf == (rtInf)) {
      Position_DW.TimeStampB_cf = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeB_b;
    } else if (Position_DW.TimeStampA_i < Position_DW.TimeStampB_cf) {
      Position_DW.TimeStampA_i = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeA_c;
    } else {
      Position_DW.TimeStampB_cf = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeB_b;
    }

    *lastU = Position_P.Constant5_Value;

    /* End of Update for Derivative: '<Root>/Derivative5' */

    /* Update for Derivative: '<Root>/Derivative4' */
    if (Position_DW.TimeStampA_g == (rtInf)) {
      Position_DW.TimeStampA_g = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeA_d;
    } else if (Position_DW.TimeStampB_i == (rtInf)) {
      Position_DW.TimeStampB_i = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeB_a;
    } else if (Position_DW.TimeStampA_g < Position_DW.TimeStampB_i) {
      Position_DW.TimeStampA_g = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeA_d;
    } else {
      Position_DW.TimeStampB_i = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeB_a;
    }

    *lastU = Position_B.Gain10;

    /* End of Update for Derivative: '<Root>/Derivative4' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Position_M->Timing.clockTick0 * 1) + 0)
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
      ((Position_M->Timing.clockTick1 * 1) + 0)
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
  Position_M->Timing.t[0] =
    ((time_T)(++Position_M->Timing.clockTick0)) * Position_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Position_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Position_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Position_M->solverInfo,
                          &Position_M->Timing.simTimeStep);
    rtsiSetTPtr(&Position_M->solverInfo, &rtmGetTPtr(Position_M));
    rtsiSetStepSizePtr(&Position_M->solverInfo, &Position_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Position_M->solverInfo, (&rtmGetErrorStatus
      (Position_M)));
    rtsiSetRTModelPtr(&Position_M->solverInfo, Position_M);
  }

  rtsiSetSimTimeStep(&Position_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Position_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Position_M, &Position_M->Timing.tArray[0]);
  rtmSetTFinal(Position_M, -1);
  Position_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Position_M->Sizes.checksums[0] = (4072283506U);
  Position_M->Sizes.checksums[1] = (2002647260U);
  Position_M->Sizes.checksums[2] = (792228030U);
  Position_M->Sizes.checksums[3] = (1517280839U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    Position_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Position_M->extModeInfo,
      &Position_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Position_M->extModeInfo, Position_M->Sizes.checksums);
    rteiSetTPtr(Position_M->extModeInfo, rtmGetTPtr(Position_M));
  }

  {
    codertarget_arduinobase_int_c_T *obj;

    /* InitializeConditions for Derivative: '<Root>/Derivative6' */
    Position_DW.TimeStampA = (rtInf);
    Position_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative7' */
    Position_DW.TimeStampA_a = (rtInf);
    Position_DW.TimeStampB_c = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative5' */
    Position_DW.TimeStampA_i = (rtInf);
    Position_DW.TimeStampB_cf = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative4' */
    Position_DW.TimeStampA_g = (rtInf);
    Position_DW.TimeStampB_i = (rtInf);

    /* Start for MATLABSystem: '<S1>/Encoder1' */
    Position_DW.obj.Index = 0U;
    Position_DW.obj.matlabCodegenIsDeleted = false;
    Position_DW.obj.SampleTime = Position_P.Encoder1_SampleTime;
    Position_DW.obj.isSetupComplete = false;
    Position_DW.obj.isInitialized = 1L;
    MW_EncoderSetup(2UL, 3UL, &Position_DW.obj.Index);
    Position_DW.obj.isSetupComplete = true;
    Position_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S1>/Encoder1' */
    MW_EncoderReset(Position_DW.obj.Index);

    /* Start for MATLABSystem: '<S1>/Digital Output' */
    Position_DW.obj_n.matlabCodegenIsDeleted = false;
    Position_DW.obj_n.isInitialized = 1L;
    digitalIOSetup(5, 1);
    Position_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Output1' */
    Position_DW.obj_l.matlabCodegenIsDeleted = false;
    Position_DW.obj_l.isInitialized = 1L;
    digitalIOSetup(7, 1);
    Position_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM' */
    Position_DW.obj_no.matlabCodegenIsDeleted = true;
    Position_DW.obj_no.isInitialized = 0L;
    Position_DW.obj_no.matlabCodegenIsDeleted = false;
    obj = &Position_DW.obj_no;
    Position_DW.obj_no.isSetupComplete = false;
    Position_DW.obj_no.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(4UL, 0.0, 0.0);
    Position_DW.obj_no.isSetupComplete = true;
  }
}

/* Model terminate function */
void Position_terminate(void)
{
  codertarget_arduinobase_int_c_T *obj;

  /* Terminate for MATLABSystem: '<S1>/Encoder1' */
  if (!Position_DW.obj.matlabCodegenIsDeleted) {
    Position_DW.obj.matlabCodegenIsDeleted = true;
    if ((Position_DW.obj.isInitialized == 1L) && Position_DW.obj.isSetupComplete)
    {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder1' */
  /* Terminate for MATLABSystem: '<S1>/Digital Output' */
  if (!Position_DW.obj_n.matlabCodegenIsDeleted) {
    Position_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output' */

  /* Terminate for MATLABSystem: '<S1>/Digital Output1' */
  if (!Position_DW.obj_l.matlabCodegenIsDeleted) {
    Position_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S1>/PWM' */
  obj = &Position_DW.obj_no;
  if (!Position_DW.obj_no.matlabCodegenIsDeleted) {
    Position_DW.obj_no.matlabCodegenIsDeleted = true;
    if ((Position_DW.obj_no.isInitialized == 1L) &&
        Position_DW.obj_no.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_SetDutyCycle(Position_DW.obj_no.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_Close(Position_DW.obj_no.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
