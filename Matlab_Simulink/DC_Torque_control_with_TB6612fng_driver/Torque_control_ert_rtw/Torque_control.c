/*
 * File: Torque_control.c
 *
 * Code generated for Simulink model 'Torque_control'.
 *
 * Model version                  : 1.200
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Apr 22 17:06:25 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Torque_control.h"
#include "rtwtypes.h"
#include <math.h>
#include "Torque_control_types.h"
#include "Torque_control_private.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_Torque_control_T Torque_control_B;

/* Continuous states */
X_Torque_control_T Torque_control_X;

/* Block states (default storage) */
DW_Torque_control_T Torque_control_DW;

/* Real-time model */
static RT_MODEL_Torque_control_T Torque_control_M_;
RT_MODEL_Torque_control_T *const Torque_control_M = &Torque_control_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Torque_control_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void Torque_control_step(void)
{
  if (rtmIsMajorTimeStep(Torque_control_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Torque_control_M->solverInfo,
                          ((Torque_control_M->Timing.clockTick0+1)*
      Torque_control_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Torque_control_M)) {
    Torque_control_M->Timing.t[0] = rtsiGetT(&Torque_control_M->solverInfo);
  }

  {
    codertarget_arduinobase_int_h_T *obj;
    real_T lastTime;
    real_T rtb_Integrator;
    real_T tmp;
    real_T *lastU;
    int32_T rtb_dir;

    /* Derivative: '<Root>/Derivative1' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Derivative: '<Root>/Derivative2'
     */
    tmp = Torque_control_M->Timing.t[0];
    if ((Torque_control_DW.TimeStampA >= tmp) && (Torque_control_DW.TimeStampB >=
         tmp)) {
      rtb_Integrator = 0.0;
    } else {
      lastTime = Torque_control_DW.TimeStampA;
      lastU = &Torque_control_DW.LastUAtTimeA;
      if (Torque_control_DW.TimeStampA < Torque_control_DW.TimeStampB) {
        if (Torque_control_DW.TimeStampB < tmp) {
          lastTime = Torque_control_DW.TimeStampB;
          lastU = &Torque_control_DW.LastUAtTimeB;
        }
      } else if (Torque_control_DW.TimeStampA >= tmp) {
        lastTime = Torque_control_DW.TimeStampB;
        lastU = &Torque_control_DW.LastUAtTimeB;
      }

      rtb_Integrator = (Torque_control_P.Constant2_Value - *lastU) / (tmp -
        lastTime);
    }

    /* End of Derivative: '<Root>/Derivative1' */
    if (rtmIsMajorTimeStep(Torque_control_M)) {
      /* Gain: '<Root>/Gain5' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      Torque_control_B.Gain5 = Torque_control_P.a / Torque_control_P.b *
        Torque_control_P.Constant2_Value;

      /* MATLABSystem: '<S1>/Encoder1' */
      if (Torque_control_DW.obj.SampleTime !=
          Torque_control_P.Encoder1_SampleTime) {
        Torque_control_DW.obj.SampleTime = Torque_control_P.Encoder1_SampleTime;
      }

      if (Torque_control_DW.obj.TunablePropsChanged) {
        Torque_control_DW.obj.TunablePropsChanged = false;
      }

      MW_EncoderRead(Torque_control_DW.obj.Index, &rtb_dir);

      /* Gain: '<S3>/Gain' incorporates:
       *  DataTypeConversion: '<S1>/Data Type Conversion8'
       *  Gain: '<S1>/Gain15'
       *  MATLABSystem: '<S1>/Encoder1'
       */
      Torque_control_B.Gain = Torque_control_P.Gain15_Gain * (real_T)rtb_dir *
        Torque_control_P.Gain_Gain;
    }

    /* Derivative: '<Root>/Derivative2' */
    if ((Torque_control_DW.TimeStampA_p >= tmp) &&
        (Torque_control_DW.TimeStampB_n >= tmp)) {
      /* Derivative: '<Root>/Derivative2' */
      Torque_control_B.Derivative2 = 0.0;
    } else {
      lastTime = Torque_control_DW.TimeStampA_p;
      lastU = &Torque_control_DW.LastUAtTimeA_g;
      if (Torque_control_DW.TimeStampA_p < Torque_control_DW.TimeStampB_n) {
        if (Torque_control_DW.TimeStampB_n < tmp) {
          lastTime = Torque_control_DW.TimeStampB_n;
          lastU = &Torque_control_DW.LastUAtTimeB_c;
        }
      } else if (Torque_control_DW.TimeStampA_p >= tmp) {
        lastTime = Torque_control_DW.TimeStampB_n;
        lastU = &Torque_control_DW.LastUAtTimeB_c;
      }

      /* Derivative: '<Root>/Derivative2' */
      Torque_control_B.Derivative2 = (Torque_control_B.Gain - *lastU) / (tmp -
        lastTime);
    }

    /* Sum: '<Root>/Sum2' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    Torque_control_B.Sum2 = Torque_control_P.Constant2_Value -
      Torque_control_B.Derivative2;

    /* Sum: '<Root>/Add1' incorporates:
     *  Gain: '<Root>/Gain7'
     *  Gain: '<Root>/Gain8'
     *  Integrator: '<Root>/Integrator'
     *  Sum: '<Root>/Add2'
     */
    Torque_control_B.Add1 = ((1.0 / Torque_control_P.b * rtb_Integrator +
      Torque_control_B.Gain5) + Torque_control_X.Integrator_CSTATE) +
      Torque_control_P.k2 * Torque_control_B.Sum2;
    if (rtmIsMajorTimeStep(Torque_control_M)) {
    }

    /* MATLAB Function: '<S1>/MATLAB Function2' */
    rtb_Integrator = Torque_control_B.Add1 * 254.0 / 22.9;
    if (rtb_Integrator > 0.0) {
      rtb_dir = 0;
    } else if (rtb_Integrator < 0.0) {
      rtb_Integrator = fabs(rtb_Integrator);
      rtb_dir = 1;
    } else {
      rtb_Integrator = 0.0;
      rtb_dir = 0;
    }

    /* End of MATLAB Function: '<S1>/MATLAB Function2' */

    /* MATLABSystem: '<S1>/PWM1' */
    obj = &Torque_control_DW.obj_n;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
    if (!(rtb_Integrator <= 255.0)) {
      rtb_Integrator = 255.0;
    }

    MW_PWM_SetDutyCycle(Torque_control_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE,
                        rtb_Integrator);

    /* End of MATLABSystem: '<S1>/PWM1' */

    /* MATLABSystem: '<S1>/PWM2' */
    obj = &Torque_control_DW.obj_b;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7U);
    MW_PWM_SetDutyCycle(Torque_control_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)rtb_dir);
    if (rtmIsMajorTimeStep(Torque_control_M)) {
    }

    /* Gain: '<Root>/Gain6' */
    Torque_control_B.Gain6 = Torque_control_P.k1 * Torque_control_B.Sum2;
    if (rtmIsMajorTimeStep(Torque_control_M)) {
    }
  }

  if (rtmIsMajorTimeStep(Torque_control_M)) {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative1' incorporates:
     *  Constant: '<Root>/Constant2'
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

    *lastU = Torque_control_P.Constant2_Value;

    /* End of Update for Derivative: '<Root>/Derivative1' */

    /* Update for Derivative: '<Root>/Derivative2' */
    if (Torque_control_DW.TimeStampA_p == (rtInf)) {
      Torque_control_DW.TimeStampA_p = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeA_g;
    } else if (Torque_control_DW.TimeStampB_n == (rtInf)) {
      Torque_control_DW.TimeStampB_n = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeB_c;
    } else if (Torque_control_DW.TimeStampA_p < Torque_control_DW.TimeStampB_n)
    {
      Torque_control_DW.TimeStampA_p = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeA_g;
    } else {
      Torque_control_DW.TimeStampB_n = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeB_c;
    }

    *lastU = Torque_control_B.Gain;

    /* End of Update for Derivative: '<Root>/Derivative2' */
    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        Torque_control_M->Timing.t[0];

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(Torque_control_M)) {/* Sample time: [0.01s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((Torque_control_M->Timing.clockTick1) * 0.01);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Torque_control_M)) {
    rt_ertODEUpdateContinuousStates(&Torque_control_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++Torque_control_M->Timing.clockTick0;
    Torque_control_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Torque_control_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      Torque_control_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Torque_control_derivatives(void)
{
  XDot_Torque_control_T *_rtXdot;
  _rtXdot = ((XDot_Torque_control_T *) Torque_control_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = Torque_control_B.Gain6;
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
    rtsiSetdXPtr(&Torque_control_M->solverInfo, &Torque_control_M->derivs);
    rtsiSetContStatesPtr(&Torque_control_M->solverInfo, (real_T **)
                         &Torque_control_M->contStates);
    rtsiSetNumContStatesPtr(&Torque_control_M->solverInfo,
      &Torque_control_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Torque_control_M->solverInfo,
      &Torque_control_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Torque_control_M->solverInfo,
      &Torque_control_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Torque_control_M->solverInfo,
      &Torque_control_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Torque_control_M->solverInfo, (&rtmGetErrorStatus
      (Torque_control_M)));
    rtsiSetRTModelPtr(&Torque_control_M->solverInfo, Torque_control_M);
  }

  rtsiSetSimTimeStep(&Torque_control_M->solverInfo, MAJOR_TIME_STEP);
  Torque_control_M->intgData.f[0] = Torque_control_M->odeF[0];
  Torque_control_M->contStates = ((X_Torque_control_T *) &Torque_control_X);
  rtsiSetSolverData(&Torque_control_M->solverInfo, (void *)
                    &Torque_control_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&Torque_control_M->solverInfo, false);
  rtsiSetSolverName(&Torque_control_M->solverInfo,"ode1");
  rtmSetTPtr(Torque_control_M, &Torque_control_M->Timing.tArray[0]);
  rtmSetTFinal(Torque_control_M, -1);
  Torque_control_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Torque_control_M->Sizes.checksums[0] = (1242110801U);
  Torque_control_M->Sizes.checksums[1] = (1066942541U);
  Torque_control_M->Sizes.checksums[2] = (962801922U);
  Torque_control_M->Sizes.checksums[3] = (340573686U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    Torque_control_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Torque_control_M->extModeInfo,
      &Torque_control_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Torque_control_M->extModeInfo,
                        Torque_control_M->Sizes.checksums);
    rteiSetTPtr(Torque_control_M->extModeInfo, rtmGetTPtr(Torque_control_M));
  }

  {
    codertarget_arduinobase_int_h_T *obj;

    /* InitializeConditions for Derivative: '<Root>/Derivative1' */
    Torque_control_DW.TimeStampA = (rtInf);
    Torque_control_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Integrator: '<Root>/Integrator' */
    Torque_control_X.Integrator_CSTATE = Torque_control_P.Integrator_IC;

    /* InitializeConditions for Derivative: '<Root>/Derivative2' */
    Torque_control_DW.TimeStampA_p = (rtInf);
    Torque_control_DW.TimeStampB_n = (rtInf);

    /* Start for MATLABSystem: '<S1>/Encoder1' */
    Torque_control_DW.obj.Index = 0U;
    Torque_control_DW.obj.matlabCodegenIsDeleted = false;
    Torque_control_DW.obj.SampleTime = Torque_control_P.Encoder1_SampleTime;
    Torque_control_DW.obj.isSetupComplete = false;
    Torque_control_DW.obj.isInitialized = 1;
    MW_EncoderSetup(2U, 3U, &Torque_control_DW.obj.Index);
    Torque_control_DW.obj.isSetupComplete = true;
    Torque_control_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S1>/Encoder1' */
    MW_EncoderReset(Torque_control_DW.obj.Index);

    /* Start for MATLABSystem: '<S1>/PWM1' */
    Torque_control_DW.obj_n.matlabCodegenIsDeleted = true;
    Torque_control_DW.obj_n.isInitialized = 0;
    Torque_control_DW.obj_n.matlabCodegenIsDeleted = false;
    obj = &Torque_control_DW.obj_n;
    Torque_control_DW.obj_n.isSetupComplete = false;
    Torque_control_DW.obj_n.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6U, 0.0, 0.0);
    Torque_control_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM2' */
    Torque_control_DW.obj_b.matlabCodegenIsDeleted = true;
    Torque_control_DW.obj_b.isInitialized = 0;
    Torque_control_DW.obj_b.matlabCodegenIsDeleted = false;
    obj = &Torque_control_DW.obj_b;
    Torque_control_DW.obj_b.isSetupComplete = false;
    Torque_control_DW.obj_b.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(7U, 0.0, 0.0);
    Torque_control_DW.obj_b.isSetupComplete = true;
  }
}

/* Model terminate function */
void Torque_control_terminate(void)
{
  codertarget_arduinobase_int_h_T *obj;

  /* Terminate for MATLABSystem: '<S1>/Encoder1' */
  if (!Torque_control_DW.obj.matlabCodegenIsDeleted) {
    Torque_control_DW.obj.matlabCodegenIsDeleted = true;
    if ((Torque_control_DW.obj.isInitialized == 1) &&
        Torque_control_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder1' */
  /* Terminate for MATLABSystem: '<S1>/PWM1' */
  obj = &Torque_control_DW.obj_n;
  if (!Torque_control_DW.obj_n.matlabCodegenIsDeleted) {
    Torque_control_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Torque_control_DW.obj_n.isInitialized == 1) &&
        Torque_control_DW.obj_n.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
      MW_PWM_SetDutyCycle(Torque_control_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
      MW_PWM_Close(Torque_control_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM1' */

  /* Terminate for MATLABSystem: '<S1>/PWM2' */
  obj = &Torque_control_DW.obj_b;
  if (!Torque_control_DW.obj_b.matlabCodegenIsDeleted) {
    Torque_control_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Torque_control_DW.obj_b.isInitialized == 1) &&
        Torque_control_DW.obj_b.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7U);
      MW_PWM_SetDutyCycle(Torque_control_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7U);
      MW_PWM_Close(Torque_control_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
