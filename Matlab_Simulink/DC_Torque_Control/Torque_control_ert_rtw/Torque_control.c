/*
 * File: Torque_control.c
 *
 * Code generated for Simulink model 'Torque_control'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Aug 17 10:45:39 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Torque_control.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "Torque_control_types.h"
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
    real_T Derivative2;
    real_T y;
    real_T y_tmp_1;
    real_T *lastU;
    int32_T rtb_Encoder_0;
    int16_T Ak_tmp;
    int16_T Ak_tmp_tmp;
    int16_T i;
    int16_T y_tmp_tmp;
    int8_T y_tmp[4];
    int8_T y_tmp_0[4];
    int8_T y_tmp_2;

    /* UnitDelay: '<S1>/Unit Delay2' */
    Torque_control_B.UnitDelay2[0] = Torque_control_DW.UnitDelay2_DSTATE[0];
    Torque_control_B.UnitDelay2[1] = Torque_control_DW.UnitDelay2_DSTATE[1];
    Torque_control_B.UnitDelay2[2] = Torque_control_DW.UnitDelay2_DSTATE[2];
    Torque_control_B.UnitDelay2[3] = Torque_control_DW.UnitDelay2_DSTATE[3];

    /* MATLABSystem: '<S3>/Encoder' */
    if (Torque_control_DW.obj.SampleTime != Torque_control_P.Encoder_SampleTime)
    {
      Torque_control_DW.obj.SampleTime = Torque_control_P.Encoder_SampleTime;
    }

    if (Torque_control_DW.obj.TunablePropsChanged) {
      Torque_control_DW.obj.TunablePropsChanged = false;
    }

    MW_EncoderRead(Torque_control_DW.obj.Index, &rtb_Encoder_0);

    /* Gain: '<S3>/Gain' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion'
     *  MATLABSystem: '<S3>/Encoder'
     */
    Torque_control_B.Gain = Torque_control_P.Gain_Gain * (real_T)rtb_Encoder_0;

    /* Derivative: '<S1>/Derivative2' */
    Derivative2 = Torque_control_M->Timing.t[0];
    if ((Torque_control_DW.TimeStampA >= Derivative2) &&
        (Torque_control_DW.TimeStampB >= Derivative2)) {
      /* Derivative: '<S1>/Derivative2' */
      Derivative2 = 0.0;
    } else {
      Torque_control_B.uk2 = Torque_control_DW.TimeStampA;
      lastU = &Torque_control_DW.LastUAtTimeA;
      if (Torque_control_DW.TimeStampA < Torque_control_DW.TimeStampB) {
        if (Torque_control_DW.TimeStampB < Derivative2) {
          Torque_control_B.uk2 = Torque_control_DW.TimeStampB;
          lastU = &Torque_control_DW.LastUAtTimeB;
        }
      } else if (Torque_control_DW.TimeStampA >= Derivative2) {
        Torque_control_B.uk2 = Torque_control_DW.TimeStampB;
        lastU = &Torque_control_DW.LastUAtTimeB;
      }

      /* Derivative: '<S1>/Derivative2' */
      Derivative2 = (Torque_control_B.Gain - *lastU) / (Derivative2 -
        Torque_control_B.uk2);
    }

    /* End of Derivative: '<S1>/Derivative2' */

    /* Sin: '<Root>/uk2' */
    Torque_control_B.uk2 = sin(Torque_control_P.uk2_Freq *
      Torque_control_M->Timing.t[0] + Torque_control_P.uk2_Phase) *
      Torque_control_P.uk2_Amp + Torque_control_P.uk2_Bias;

    /* MATLAB Function: '<S1>/EKF2' */
    y_tmp[0] = 1;
    y_tmp_0[0] = 1;
    y_tmp[1] = 0;
    y_tmp_0[1] = 0;
    y_tmp[2] = 0;
    y_tmp_0[2] = 0;
    y_tmp[3] = 0;
    y_tmp_0[3] = 0;
    y_tmp_1 = 0.0;
    for (i = 0; i < 4; i++) {
      y_tmp_tmp = i << 2;
      y_tmp_1 += (((Torque_control_DW.P[y_tmp_tmp + 1] * 0.0 +
                    Torque_control_DW.P[y_tmp_tmp]) +
                   Torque_control_DW.P[y_tmp_tmp + 2] * 0.0) +
                  Torque_control_DW.P[y_tmp_tmp + 3] * 0.0) * (real_T)y_tmp[i];
    }

    y = y_tmp_1 + Torque_control_DW.R_est;
    y_tmp_1 = 0.0;
    for (i = 0; i < 4; i++) {
      Torque_control_B.Wk[i] = (((Torque_control_DW.P[i + 4] * 0.0 +
        Torque_control_DW.P[i]) + Torque_control_DW.P[i + 8] * 0.0) +
        Torque_control_DW.P[i + 12] * 0.0) / y;
      y_tmp_1 += (real_T)y_tmp_0[i] * Torque_control_DW.x_est_p[i];
    }

    Derivative2 -= 0.0 * Torque_control_B.uk2 + y_tmp_1;
    for (i = 0; i < 4; i++) {
      y_tmp_2 = y_tmp_0[i];
      Torque_control_DW.x_est_p[i] += Torque_control_B.Wk[i] * Derivative2;
      y_tmp_tmp = i << 2;
      Torque_control_B.Ak[y_tmp_tmp] = Torque_control_B.Wk[0] * (real_T)y_tmp_2;
      Torque_control_B.Ak[y_tmp_tmp + 1] = Torque_control_B.Wk[1] * (real_T)
        y_tmp_2;
      Torque_control_B.Ak[y_tmp_tmp + 2] = Torque_control_B.Wk[2] * (real_T)
        y_tmp_2;
      Torque_control_B.Ak[y_tmp_tmp + 3] = Torque_control_B.Wk[3] * (real_T)
        y_tmp_2;
    }

    if (rtIsNaN(Torque_control_DW.x_est_p[0])) {
      Derivative2 = Torque_control_DW.x_est_p[0];
    } else if (Torque_control_DW.x_est_p[0] < 0.0) {
      Derivative2 = -1.0;
    } else {
      Derivative2 = (Torque_control_DW.x_est_p[0] > 0.0);
    }

    Torque_control_B.x_est[0] = ((-Torque_control_DW.x_est_p[1] *
      Torque_control_DW.x_est_p[0] + Torque_control_B.uk2 *
      Torque_control_DW.x_est_p[2]) - Torque_control_DW.x_est_p[3] * Derivative2)
      * 0.01 + Torque_control_DW.x_est_p[0];
    Torque_control_B.x_est[1] = Torque_control_DW.x_est_p[1];
    Torque_control_B.x_est[2] = Torque_control_DW.x_est_p[2];
    Torque_control_B.x_est[3] = Torque_control_DW.x_est_p[3];
    for (i = 0; i < 4; i++) {
      for (y_tmp_tmp = 0; y_tmp_tmp < 4; y_tmp_tmp++) {
        Ak_tmp_tmp = y_tmp_tmp << 2;
        Ak_tmp = Ak_tmp_tmp + i;
        Torque_control_B.Ak_m[Ak_tmp] = Torque_control_DW.P[Ak_tmp] -
          (((Torque_control_DW.P[Ak_tmp_tmp + 1] * Torque_control_B.Ak[i + 4] +
             Torque_control_DW.P[Ak_tmp_tmp] * Torque_control_B.Ak[i]) +
            Torque_control_DW.P[Ak_tmp_tmp + 2] * Torque_control_B.Ak[i + 8]) +
           Torque_control_DW.P[Ak_tmp_tmp + 3] * Torque_control_B.Ak[i + 12]);
      }
    }

    for (i = 0; i < 16; i++) {
      Torque_control_DW.P[i] = Torque_control_B.Ak_m[i];
      Torque_control_B.b_I[i] = 0;
    }

    Torque_control_B.Ak[0] = 0.01 * -Torque_control_DW.x_est_p[1] + 1.0;
    Torque_control_B.Ak[1] = Torque_control_B.b_I[1];
    Torque_control_B.Ak[2] = Torque_control_B.b_I[2];
    Torque_control_B.Ak[3] = Torque_control_B.b_I[3];
    Torque_control_B.Ak[4] = 0.01 * -Torque_control_DW.x_est_p[0] + (real_T)
      Torque_control_B.b_I[4];
    Torque_control_B.Ak[5] = 1.0;
    Torque_control_B.Ak[6] = Torque_control_B.b_I[6];
    Torque_control_B.Ak[7] = Torque_control_B.b_I[7];
    Torque_control_B.Ak[8] = 0.01 * Torque_control_B.uk2 + (real_T)
      Torque_control_B.b_I[8];
    Torque_control_B.Ak[9] = Torque_control_B.b_I[9];
    Torque_control_B.Ak[10] = 1.0;
    Torque_control_B.Ak[11] = Torque_control_B.b_I[11];
    if (rtIsNaN(Torque_control_DW.x_est_p[0])) {
      Derivative2 = Torque_control_DW.x_est_p[0];
    } else if (Torque_control_DW.x_est_p[0] < 0.0) {
      Derivative2 = -1.0;
    } else {
      Derivative2 = (Torque_control_DW.x_est_p[0] > 0.0);
    }

    Torque_control_B.Ak[12] = 0.01 * -Derivative2 + (real_T)
      Torque_control_B.b_I[12];
    Torque_control_B.Ak[13] = Torque_control_B.b_I[13];
    Torque_control_B.Ak[14] = Torque_control_B.b_I[14];
    Torque_control_B.Ak[15] = 1.0;
    for (i = 0; i < 4; i++) {
      for (y_tmp_tmp = 0; y_tmp_tmp < 4; y_tmp_tmp++) {
        Ak_tmp_tmp = i << 2;
        Ak_tmp = y_tmp_tmp + Ak_tmp_tmp;
        Torque_control_B.Ak_m[Ak_tmp] = 0.0;
        Torque_control_B.Ak_m[Ak_tmp] += Torque_control_DW.P[Ak_tmp_tmp] *
          Torque_control_B.Ak[y_tmp_tmp];
        Torque_control_B.Ak_m[Ak_tmp] += Torque_control_DW.P[Ak_tmp_tmp + 1] *
          Torque_control_B.Ak[y_tmp_tmp + 4];
        Torque_control_B.Ak_m[Ak_tmp] += Torque_control_DW.P[Ak_tmp_tmp + 2] *
          Torque_control_B.Ak[y_tmp_tmp + 8];
        Torque_control_B.Ak_m[Ak_tmp] += Torque_control_DW.P[Ak_tmp_tmp + 3] *
          Torque_control_B.Ak[y_tmp_tmp + 12];
      }
    }

    for (y_tmp_tmp = 0; y_tmp_tmp < 4; y_tmp_tmp++) {
      for (i = 0; i < 4; i++) {
        Ak_tmp_tmp = (i << 2) + y_tmp_tmp;
        Torque_control_DW.P[Ak_tmp_tmp] = (((Torque_control_B.Ak_m[y_tmp_tmp + 4]
          * Torque_control_B.Ak[i + 4] + Torque_control_B.Ak_m[y_tmp_tmp] *
          Torque_control_B.Ak[i]) + Torque_control_B.Ak_m[y_tmp_tmp + 8] *
          Torque_control_B.Ak[i + 8]) + Torque_control_B.Ak_m[y_tmp_tmp + 12] *
          Torque_control_B.Ak[i + 12]) + Torque_control_DW.Qd_est[Ak_tmp_tmp];
      }

      Torque_control_DW.x_est_p[y_tmp_tmp] = Torque_control_B.x_est[y_tmp_tmp];
    }

    /* End of MATLAB Function: '<S1>/EKF2' */

    /* MATLAB Function: '<S3>/MATLAB Function' */
    Derivative2 = Torque_control_B.uk2 / 24.0 * 254.0;
    if (Derivative2 > 0.0) {
      Torque_control_B.uk2 = Derivative2;
      Derivative2 = 0.0;
    } else if (Derivative2 < 0.0) {
      Torque_control_B.uk2 = 0.0;
      Derivative2 = fabs(Derivative2);
    } else {
      Torque_control_B.uk2 = 0.0;
      Derivative2 = 0.0;
    }

    /* End of MATLAB Function: '<S3>/MATLAB Function' */

    /* MATLABSystem: '<S3>/PWM10' */
    obj = &Torque_control_DW.obj_n;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
    if (!(Torque_control_B.uk2 <= 255.0)) {
      Torque_control_B.uk2 = 255.0;
    }

    MW_PWM_SetDutyCycle(Torque_control_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE,
                        Torque_control_B.uk2);

    /* End of MATLABSystem: '<S3>/PWM10' */

    /* MATLABSystem: '<S3>/PWM9' */
    obj = &Torque_control_DW.obj_j;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
    if (!(Derivative2 <= 255.0)) {
      Derivative2 = 255.0;
    }

    MW_PWM_SetDutyCycle(Torque_control_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE,
                        Derivative2);

    /* End of MATLABSystem: '<S3>/PWM9' */
  }

  {
    real_T *lastU;

    /* Update for UnitDelay: '<S1>/Unit Delay2' */
    Torque_control_DW.UnitDelay2_DSTATE[0] = Torque_control_B.x_est[0];
    Torque_control_DW.UnitDelay2_DSTATE[1] = Torque_control_B.x_est[1];
    Torque_control_DW.UnitDelay2_DSTATE[2] = Torque_control_B.x_est[2];
    Torque_control_DW.UnitDelay2_DSTATE[3] = Torque_control_B.x_est[3];

    /* Update for Derivative: '<S1>/Derivative2' */
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

    *lastU = Torque_control_B.Gain;

    /* End of Update for Derivative: '<S1>/Derivative2' */
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

  {                                    /* Sample time: [0.01s, 0.0s] */
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
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
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
  rtmSetTFinal(Torque_control_M, 20.0);
  Torque_control_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Torque_control_M->Sizes.checksums[0] = (1378061630U);
  Torque_control_M->Sizes.checksums[1] = (1303406071U);
  Torque_control_M->Sizes.checksums[2] = (4000824812U);
  Torque_control_M->Sizes.checksums[3] = (1247014861U);

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
    int16_T i;
    static const int8_T tmp[16] = { 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0,
      2 };

    static const real_T b[16] = { 0.0001, 0.0, 0.0, 0.0, 0.0, 0.00025, 0.0, 0.0,
      0.0, 0.0, 0.00025, 0.0, 0.0, 0.0, 0.0, 1.0E-5 };

    /* InitializeConditions for Derivative: '<S1>/Derivative2' */
    Torque_control_DW.TimeStampA = (rtInf);
    Torque_control_DW.TimeStampB = (rtInf);

    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay2' */
    Torque_control_DW.UnitDelay2_DSTATE[0] =
      Torque_control_P.UnitDelay2_InitialCondition[0];

    /* SystemInitialize for MATLAB Function: '<S1>/EKF2' */
    Torque_control_DW.x_est_p[0] = 2.0;

    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay2' */
    Torque_control_DW.UnitDelay2_DSTATE[1] =
      Torque_control_P.UnitDelay2_InitialCondition[1];

    /* SystemInitialize for MATLAB Function: '<S1>/EKF2' */
    Torque_control_DW.x_est_p[1] = 13.0;

    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay2' */
    Torque_control_DW.UnitDelay2_DSTATE[2] =
      Torque_control_P.UnitDelay2_InitialCondition[2];

    /* SystemInitialize for MATLAB Function: '<S1>/EKF2' */
    Torque_control_DW.x_est_p[2] = 25.0;

    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay2' */
    Torque_control_DW.UnitDelay2_DSTATE[3] =
      Torque_control_P.UnitDelay2_InitialCondition[3];

    /* SystemInitialize for MATLAB Function: '<S1>/EKF2' */
    Torque_control_DW.x_est_p[3] = 1.0;
    for (i = 0; i < 16; i++) {
      Torque_control_DW.P[i] = tmp[i];
      Torque_control_DW.Qd_est[i] = b[i] * 0.01;
    }

    Torque_control_DW.R_est = 0.02;

    /* Start for MATLABSystem: '<S3>/Encoder' */
    Torque_control_DW.obj.Index = 0U;
    Torque_control_DW.obj.matlabCodegenIsDeleted = false;
    Torque_control_DW.obj.SampleTime = Torque_control_P.Encoder_SampleTime;
    Torque_control_DW.obj.isSetupComplete = false;
    Torque_control_DW.obj.isInitialized = 1L;
    MW_EncoderSetup(2UL, 3UL, &Torque_control_DW.obj.Index);
    Torque_control_DW.obj.isSetupComplete = true;
    Torque_control_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S3>/Encoder' */
    MW_EncoderReset(Torque_control_DW.obj.Index);

    /* Start for MATLABSystem: '<S3>/PWM10' */
    Torque_control_DW.obj_n.matlabCodegenIsDeleted = true;
    Torque_control_DW.obj_n.isInitialized = 0L;
    Torque_control_DW.obj_n.matlabCodegenIsDeleted = false;
    obj = &Torque_control_DW.obj_n;
    Torque_control_DW.obj_n.isSetupComplete = false;
    Torque_control_DW.obj_n.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(8UL, 0.0, 0.0);
    Torque_control_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM9' */
    Torque_control_DW.obj_j.matlabCodegenIsDeleted = true;
    Torque_control_DW.obj_j.isInitialized = 0L;
    Torque_control_DW.obj_j.matlabCodegenIsDeleted = false;
    obj = &Torque_control_DW.obj_j;
    Torque_control_DW.obj_j.isSetupComplete = false;
    Torque_control_DW.obj_j.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
    Torque_control_DW.obj_j.isSetupComplete = true;
  }
}

/* Model terminate function */
void Torque_control_terminate(void)
{
  codertarget_arduinobase_int_h_T *obj;

  /* Terminate for MATLABSystem: '<S3>/Encoder' */
  if (!Torque_control_DW.obj.matlabCodegenIsDeleted) {
    Torque_control_DW.obj.matlabCodegenIsDeleted = true;
    if ((Torque_control_DW.obj.isInitialized == 1L) &&
        Torque_control_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder' */

  /* Terminate for MATLABSystem: '<S3>/PWM10' */
  obj = &Torque_control_DW.obj_n;
  if (!Torque_control_DW.obj_n.matlabCodegenIsDeleted) {
    Torque_control_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Torque_control_DW.obj_n.isInitialized == 1L) &&
        Torque_control_DW.obj_n.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
      MW_PWM_SetDutyCycle(Torque_control_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
      MW_PWM_Close(Torque_control_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM10' */

  /* Terminate for MATLABSystem: '<S3>/PWM9' */
  obj = &Torque_control_DW.obj_j;
  if (!Torque_control_DW.obj_j.matlabCodegenIsDeleted) {
    Torque_control_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Torque_control_DW.obj_j.isInitialized == 1L) &&
        Torque_control_DW.obj_j.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(Torque_control_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(Torque_control_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM9' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
