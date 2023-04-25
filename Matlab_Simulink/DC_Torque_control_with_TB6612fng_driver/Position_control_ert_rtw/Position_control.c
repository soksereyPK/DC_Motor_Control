/*
 * File: Position_control.c
 *
 * Code generated for Simulink model 'Position_control'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Sep  8 10:36:03 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Position_control.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "Position_control_types.h"
#include "Position_control_private.h"

/* Block signals (default storage) */
B_Position_control_T Position_control_B;

/* Block states (default storage) */
DW_Position_control_T Position_control_DW;

/* Real-time model */
static RT_MODEL_Position_control_T Position_control_M_;
RT_MODEL_Position_control_T *const Position_control_M = &Position_control_M_;

/* Model step function */
void Position_control_step(void)
{
  {
    codertarget_arduinobase_int_o_T *obj;
    real_T lastTime;
    real_T pwm_cal;
    real_T *lastU;
    int32_T rtb_Encoder_0;
    int16_T Ak_tmp;
    int16_T Ak_tmp_tmp;
    int16_T rtb_IN1;
    int16_T rtb_IN2;
    int8_T y_tmp[4];
    int8_T y_tmp_0[4];
    int8_T y_tmp_1;

    /* UnitDelay: '<S1>/Unit Delay2' */
    Position_control_B.UnitDelay2[0] = Position_control_DW.UnitDelay2_DSTATE[0];
    Position_control_B.UnitDelay2[1] = Position_control_DW.UnitDelay2_DSTATE[1];
    Position_control_B.UnitDelay2[2] = Position_control_DW.UnitDelay2_DSTATE[2];
    Position_control_B.UnitDelay2[3] = Position_control_DW.UnitDelay2_DSTATE[3];

    /* Sin: '<Root>/uk2' */
    Position_control_B.uk2 = sin(Position_control_P.uk2_Freq *
      Position_control_M->Timing.t[0] + Position_control_P.uk2_Phase) *
      Position_control_P.uk2_Amp + Position_control_P.uk2_Bias;

    /* MATLABSystem: '<S3>/Encoder' */
    if (Position_control_DW.obj.SampleTime !=
        Position_control_P.Encoder_SampleTime) {
      Position_control_DW.obj.SampleTime = Position_control_P.Encoder_SampleTime;
    }

    if (Position_control_DW.obj.TunablePropsChanged) {
      Position_control_DW.obj.TunablePropsChanged = false;
    }

    MW_EncoderRead(Position_control_DW.obj.Index, &rtb_Encoder_0);

    /* Gain: '<S3>/Gain' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion'
     *  MATLABSystem: '<S3>/Encoder'
     */
    Position_control_B.Gain = Position_control_P.Gain_Gain * (real_T)
      rtb_Encoder_0;

    /* Derivative: '<S1>/Derivative2' */
    pwm_cal = Position_control_M->Timing.t[0];
    if ((Position_control_DW.TimeStampA >= pwm_cal) &&
        (Position_control_DW.TimeStampB >= pwm_cal)) {
      /* Derivative: '<S1>/Derivative2' */
      Position_control_B.Derivative2 = 0.0;
    } else {
      lastTime = Position_control_DW.TimeStampA;
      lastU = &Position_control_DW.LastUAtTimeA;
      if (Position_control_DW.TimeStampA < Position_control_DW.TimeStampB) {
        if (Position_control_DW.TimeStampB < pwm_cal) {
          lastTime = Position_control_DW.TimeStampB;
          lastU = &Position_control_DW.LastUAtTimeB;
        }
      } else if (Position_control_DW.TimeStampA >= pwm_cal) {
        lastTime = Position_control_DW.TimeStampB;
        lastU = &Position_control_DW.LastUAtTimeB;
      }

      /* Derivative: '<S1>/Derivative2' */
      Position_control_B.Derivative2 = (Position_control_B.Gain - *lastU) /
        (pwm_cal - lastTime);
    }

    /* End of Derivative: '<S1>/Derivative2' */

    /* MATLAB Function: '<S1>/EKF2' */
    y_tmp[0] = 1;
    y_tmp_0[0] = 1;
    y_tmp[1] = 0;
    y_tmp_0[1] = 0;
    y_tmp[2] = 0;
    y_tmp_0[2] = 0;
    y_tmp[3] = 0;
    y_tmp_0[3] = 0;
    pwm_cal = 0.0;
    for (rtb_IN1 = 0; rtb_IN1 < 4; rtb_IN1++) {
      rtb_IN2 = rtb_IN1 << 2;
      pwm_cal += (((Position_control_DW.P[rtb_IN2 + 1] * 0.0 +
                    Position_control_DW.P[rtb_IN2]) +
                   Position_control_DW.P[rtb_IN2 + 2] * 0.0) +
                  Position_control_DW.P[rtb_IN2 + 3] * 0.0) * (real_T)
        y_tmp[rtb_IN1];
    }

    lastTime = pwm_cal + Position_control_DW.R_est;
    pwm_cal = 0.0;
    for (rtb_IN1 = 0; rtb_IN1 < 4; rtb_IN1++) {
      Position_control_B.Wk[rtb_IN1] = (((Position_control_DW.P[rtb_IN1 + 4] *
        0.0 + Position_control_DW.P[rtb_IN1]) + Position_control_DW.P[rtb_IN1 +
        8] * 0.0) + Position_control_DW.P[rtb_IN1 + 12] * 0.0) / lastTime;
      pwm_cal += (real_T)y_tmp_0[rtb_IN1] * Position_control_DW.x_est_p[rtb_IN1];
    }

    pwm_cal = Position_control_B.Derivative2 - (0.0 * Position_control_B.uk2 +
      pwm_cal);
    for (rtb_IN1 = 0; rtb_IN1 < 4; rtb_IN1++) {
      y_tmp_1 = y_tmp_0[rtb_IN1];
      Position_control_DW.x_est_p[rtb_IN1] += Position_control_B.Wk[rtb_IN1] *
        pwm_cal;
      rtb_IN2 = rtb_IN1 << 2;
      Position_control_B.Ak[rtb_IN2] = Position_control_B.Wk[0] * (real_T)
        y_tmp_1;
      Position_control_B.Ak[rtb_IN2 + 1] = Position_control_B.Wk[1] * (real_T)
        y_tmp_1;
      Position_control_B.Ak[rtb_IN2 + 2] = Position_control_B.Wk[2] * (real_T)
        y_tmp_1;
      Position_control_B.Ak[rtb_IN2 + 3] = Position_control_B.Wk[3] * (real_T)
        y_tmp_1;
    }

    if (rtIsNaN(Position_control_DW.x_est_p[0])) {
      pwm_cal = Position_control_DW.x_est_p[0];
    } else if (Position_control_DW.x_est_p[0] < 0.0) {
      pwm_cal = -1.0;
    } else {
      pwm_cal = (Position_control_DW.x_est_p[0] > 0.0);
    }

    Position_control_B.x_est[0] = ((-Position_control_DW.x_est_p[1] *
      Position_control_DW.x_est_p[0] + Position_control_B.uk2 *
      Position_control_DW.x_est_p[2]) - Position_control_DW.x_est_p[3] * pwm_cal)
      * 0.01 + Position_control_DW.x_est_p[0];
    Position_control_B.x_est[1] = Position_control_DW.x_est_p[1];
    Position_control_B.x_est[2] = Position_control_DW.x_est_p[2];
    Position_control_B.x_est[3] = Position_control_DW.x_est_p[3];
    for (rtb_IN1 = 0; rtb_IN1 < 4; rtb_IN1++) {
      for (rtb_IN2 = 0; rtb_IN2 < 4; rtb_IN2++) {
        Ak_tmp_tmp = rtb_IN2 << 2;
        Ak_tmp = Ak_tmp_tmp + rtb_IN1;
        Position_control_B.Ak_m[Ak_tmp] = Position_control_DW.P[Ak_tmp] -
          (((Position_control_DW.P[Ak_tmp_tmp + 1] *
             Position_control_B.Ak[rtb_IN1 + 4] +
             Position_control_DW.P[Ak_tmp_tmp] * Position_control_B.Ak[rtb_IN1])
            + Position_control_DW.P[Ak_tmp_tmp + 2] *
            Position_control_B.Ak[rtb_IN1 + 8]) +
           Position_control_DW.P[Ak_tmp_tmp + 3] * Position_control_B.Ak[rtb_IN1
           + 12]);
      }
    }

    for (rtb_IN1 = 0; rtb_IN1 < 16; rtb_IN1++) {
      Position_control_DW.P[rtb_IN1] = Position_control_B.Ak_m[rtb_IN1];
      Position_control_B.b_I[rtb_IN1] = 0;
    }

    Position_control_B.Ak[0] = 0.01 * -Position_control_DW.x_est_p[1] + 1.0;
    Position_control_B.Ak[1] = Position_control_B.b_I[1];
    Position_control_B.Ak[2] = Position_control_B.b_I[2];
    Position_control_B.Ak[3] = Position_control_B.b_I[3];
    Position_control_B.Ak[4] = 0.01 * -Position_control_DW.x_est_p[0] + (real_T)
      Position_control_B.b_I[4];
    Position_control_B.Ak[5] = 1.0;
    Position_control_B.Ak[6] = Position_control_B.b_I[6];
    Position_control_B.Ak[7] = Position_control_B.b_I[7];
    Position_control_B.Ak[8] = 0.01 * Position_control_B.uk2 + (real_T)
      Position_control_B.b_I[8];
    Position_control_B.Ak[9] = Position_control_B.b_I[9];
    Position_control_B.Ak[10] = 1.0;
    Position_control_B.Ak[11] = Position_control_B.b_I[11];
    if (rtIsNaN(Position_control_DW.x_est_p[0])) {
      pwm_cal = Position_control_DW.x_est_p[0];
    } else if (Position_control_DW.x_est_p[0] < 0.0) {
      pwm_cal = -1.0;
    } else {
      pwm_cal = (Position_control_DW.x_est_p[0] > 0.0);
    }

    Position_control_B.Ak[12] = 0.01 * -pwm_cal + (real_T)
      Position_control_B.b_I[12];
    Position_control_B.Ak[13] = Position_control_B.b_I[13];
    Position_control_B.Ak[14] = Position_control_B.b_I[14];
    Position_control_B.Ak[15] = 1.0;
    for (rtb_IN1 = 0; rtb_IN1 < 4; rtb_IN1++) {
      for (rtb_IN2 = 0; rtb_IN2 < 4; rtb_IN2++) {
        Ak_tmp_tmp = rtb_IN1 << 2;
        Ak_tmp = rtb_IN2 + Ak_tmp_tmp;
        Position_control_B.Ak_m[Ak_tmp] = 0.0;
        Position_control_B.Ak_m[Ak_tmp] += Position_control_DW.P[Ak_tmp_tmp] *
          Position_control_B.Ak[rtb_IN2];
        Position_control_B.Ak_m[Ak_tmp] += Position_control_DW.P[Ak_tmp_tmp + 1]
          * Position_control_B.Ak[rtb_IN2 + 4];
        Position_control_B.Ak_m[Ak_tmp] += Position_control_DW.P[Ak_tmp_tmp + 2]
          * Position_control_B.Ak[rtb_IN2 + 8];
        Position_control_B.Ak_m[Ak_tmp] += Position_control_DW.P[Ak_tmp_tmp + 3]
          * Position_control_B.Ak[rtb_IN2 + 12];
      }
    }

    for (rtb_IN2 = 0; rtb_IN2 < 4; rtb_IN2++) {
      for (rtb_IN1 = 0; rtb_IN1 < 4; rtb_IN1++) {
        Ak_tmp_tmp = (rtb_IN1 << 2) + rtb_IN2;
        Position_control_DW.P[Ak_tmp_tmp] = (((Position_control_B.Ak_m[rtb_IN2 +
          4] * Position_control_B.Ak[rtb_IN1 + 4] +
          Position_control_B.Ak_m[rtb_IN2] * Position_control_B.Ak[rtb_IN1]) +
          Position_control_B.Ak_m[rtb_IN2 + 8] * Position_control_B.Ak[rtb_IN1 +
          8]) + Position_control_B.Ak_m[rtb_IN2 + 12] *
          Position_control_B.Ak[rtb_IN1 + 12]) +
          Position_control_DW.Qd_est[Ak_tmp_tmp];
      }

      Position_control_DW.x_est_p[rtb_IN2] = Position_control_B.x_est[rtb_IN2];
    }

    /* End of MATLAB Function: '<S1>/EKF2' */
    /* MATLAB Function: '<S3>/MATLAB Function4' */
    pwm_cal = Position_control_B.uk2 * 254.0 / 12.0;
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

    /* End of MATLAB Function: '<S3>/MATLAB Function4' */

    /* MATLABSystem: '<S3>/Digital Output' */
    writeDigitalPin(5, (uint8_T)rtb_IN1);

    /* MATLABSystem: '<S3>/Digital Output1' */
    writeDigitalPin(7, (uint8_T)rtb_IN2);

    /* MATLABSystem: '<S3>/PWM' */
    obj = &Position_control_DW.obj_bg;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
    if (!(pwm_cal <= 255.0)) {
      pwm_cal = 255.0;
    }

    MW_PWM_SetDutyCycle(Position_control_DW.obj_bg.PWMDriverObj.MW_PWM_HANDLE,
                        pwm_cal);

    /* End of MATLABSystem: '<S3>/PWM' */
  }

  {
    real_T *lastU;

    /* Update for UnitDelay: '<S1>/Unit Delay2' */
    Position_control_DW.UnitDelay2_DSTATE[0] = Position_control_B.x_est[0];
    Position_control_DW.UnitDelay2_DSTATE[1] = Position_control_B.x_est[1];
    Position_control_DW.UnitDelay2_DSTATE[2] = Position_control_B.x_est[2];
    Position_control_DW.UnitDelay2_DSTATE[3] = Position_control_B.x_est[3];

    /* Update for Derivative: '<S1>/Derivative2' */
    if (Position_control_DW.TimeStampA == (rtInf)) {
      Position_control_DW.TimeStampA = Position_control_M->Timing.t[0];
      lastU = &Position_control_DW.LastUAtTimeA;
    } else if (Position_control_DW.TimeStampB == (rtInf)) {
      Position_control_DW.TimeStampB = Position_control_M->Timing.t[0];
      lastU = &Position_control_DW.LastUAtTimeB;
    } else if (Position_control_DW.TimeStampA < Position_control_DW.TimeStampB)
    {
      Position_control_DW.TimeStampA = Position_control_M->Timing.t[0];
      lastU = &Position_control_DW.LastUAtTimeA;
    } else {
      Position_control_DW.TimeStampB = Position_control_M->Timing.t[0];
      lastU = &Position_control_DW.LastUAtTimeB;
    }

    *lastU = Position_control_B.Gain;

    /* End of Update for Derivative: '<S1>/Derivative2' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Position_control_M->Timing.clockTick0 * 1) + 0)
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
      ((Position_control_M->Timing.clockTick1 * 1) + 0)
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
  Position_control_M->Timing.t[0] =
    ((time_T)(++Position_control_M->Timing.clockTick0)) *
    Position_control_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Position_control_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Position_control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Position_control_M->solverInfo,
                          &Position_control_M->Timing.simTimeStep);
    rtsiSetTPtr(&Position_control_M->solverInfo, &rtmGetTPtr(Position_control_M));
    rtsiSetStepSizePtr(&Position_control_M->solverInfo,
                       &Position_control_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Position_control_M->solverInfo, (&rtmGetErrorStatus
      (Position_control_M)));
    rtsiSetRTModelPtr(&Position_control_M->solverInfo, Position_control_M);
  }

  rtsiSetSimTimeStep(&Position_control_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Position_control_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Position_control_M, &Position_control_M->Timing.tArray[0]);
  rtmSetTFinal(Position_control_M, -1);
  Position_control_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Position_control_M->Sizes.checksums[0] = (1534117210U);
  Position_control_M->Sizes.checksums[1] = (3270001847U);
  Position_control_M->Sizes.checksums[2] = (1403713514U);
  Position_control_M->Sizes.checksums[3] = (2855244195U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    Position_control_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Position_control_M->extModeInfo,
      &Position_control_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Position_control_M->extModeInfo,
                        Position_control_M->Sizes.checksums);
    rteiSetTPtr(Position_control_M->extModeInfo, rtmGetTPtr(Position_control_M));
  }

  {
    codertarget_arduinobase_int_o_T *obj;
    int16_T i;
    static const int8_T tmp[16] = { 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0,
      2 };

    static const real_T b[16] = { 0.01, 0.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0,
      0.0, 0.01, 0.0, 0.0, 0.0, 0.0, 0.001 };

    /* InitializeConditions for Derivative: '<S1>/Derivative2' */
    Position_control_DW.TimeStampA = (rtInf);
    Position_control_DW.TimeStampB = (rtInf);

    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay2' */
    Position_control_DW.UnitDelay2_DSTATE[0] =
      Position_control_P.UnitDelay2_InitialCondition[0];

    /* SystemInitialize for MATLAB Function: '<S1>/EKF2' */
    Position_control_DW.x_est_p[0] = 2.0;

    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay2' */
    Position_control_DW.UnitDelay2_DSTATE[1] =
      Position_control_P.UnitDelay2_InitialCondition[1];

    /* SystemInitialize for MATLAB Function: '<S1>/EKF2' */
    Position_control_DW.x_est_p[1] = 16.0;

    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay2' */
    Position_control_DW.UnitDelay2_DSTATE[2] =
      Position_control_P.UnitDelay2_InitialCondition[2];

    /* SystemInitialize for MATLAB Function: '<S1>/EKF2' */
    Position_control_DW.x_est_p[2] = 3.5;

    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay2' */
    Position_control_DW.UnitDelay2_DSTATE[3] =
      Position_control_P.UnitDelay2_InitialCondition[3];

    /* SystemInitialize for MATLAB Function: '<S1>/EKF2' */
    Position_control_DW.x_est_p[3] = 2.0;
    for (i = 0; i < 16; i++) {
      Position_control_DW.P[i] = tmp[i];
      Position_control_DW.Qd_est[i] = b[i] * 0.01;
    }

    Position_control_DW.R_est = 0.02;

    /* Start for MATLABSystem: '<S3>/Encoder' */
    Position_control_DW.obj.Index = 0U;
    Position_control_DW.obj.matlabCodegenIsDeleted = false;
    Position_control_DW.obj.SampleTime = Position_control_P.Encoder_SampleTime;
    Position_control_DW.obj.isSetupComplete = false;
    Position_control_DW.obj.isInitialized = 1L;
    MW_EncoderSetup(2UL, 3UL, &Position_control_DW.obj.Index);
    Position_control_DW.obj.isSetupComplete = true;
    Position_control_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S3>/Encoder' */
    MW_EncoderReset(Position_control_DW.obj.Index);

    /* Start for MATLABSystem: '<S3>/Digital Output' */
    Position_control_DW.obj_d.matlabCodegenIsDeleted = false;
    Position_control_DW.obj_d.isInitialized = 1L;
    digitalIOSetup(5, 1);
    Position_control_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Output1' */
    Position_control_DW.obj_b.matlabCodegenIsDeleted = false;
    Position_control_DW.obj_b.isInitialized = 1L;
    digitalIOSetup(7, 1);
    Position_control_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM' */
    Position_control_DW.obj_bg.matlabCodegenIsDeleted = true;
    Position_control_DW.obj_bg.isInitialized = 0L;
    Position_control_DW.obj_bg.matlabCodegenIsDeleted = false;
    obj = &Position_control_DW.obj_bg;
    Position_control_DW.obj_bg.isSetupComplete = false;
    Position_control_DW.obj_bg.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(4UL, 0.0, 0.0);
    Position_control_DW.obj_bg.isSetupComplete = true;
  }
}

/* Model terminate function */
void Position_control_terminate(void)
{
  codertarget_arduinobase_int_o_T *obj;

  /* Terminate for MATLABSystem: '<S3>/Encoder' */
  if (!Position_control_DW.obj.matlabCodegenIsDeleted) {
    Position_control_DW.obj.matlabCodegenIsDeleted = true;
    if ((Position_control_DW.obj.isInitialized == 1L) &&
        Position_control_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder' */
  /* Terminate for MATLABSystem: '<S3>/Digital Output' */
  if (!Position_control_DW.obj_d.matlabCodegenIsDeleted) {
    Position_control_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Output' */

  /* Terminate for MATLABSystem: '<S3>/Digital Output1' */
  if (!Position_control_DW.obj_b.matlabCodegenIsDeleted) {
    Position_control_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S3>/PWM' */
  obj = &Position_control_DW.obj_bg;
  if (!Position_control_DW.obj_bg.matlabCodegenIsDeleted) {
    Position_control_DW.obj_bg.matlabCodegenIsDeleted = true;
    if ((Position_control_DW.obj_bg.isInitialized == 1L) &&
        Position_control_DW.obj_bg.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_SetDutyCycle(Position_control_DW.obj_bg.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_Close(Position_control_DW.obj_bg.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
