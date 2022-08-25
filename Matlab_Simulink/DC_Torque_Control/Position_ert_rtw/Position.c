/*
 * File: Position.c
 *
 * Code generated for Simulink model 'Position'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Aug 25 12:50:48 2022
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
#include "Position_private.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_Position_T Position_B;

/* Continuous states */
X_Position_T Position_X;

/* Block states (default storage) */
DW_Position_T Position_DW;

/* Real-time model */
static RT_MODEL_Position_T Position_M_;
RT_MODEL_Position_T *const Position_M = &Position_M_;

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
  Position_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void Position_step(void)
{
  if (rtmIsMajorTimeStep(Position_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Position_M->solverInfo,
                          ((Position_M->Timing.clockTick0+1)*
      Position_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Position_M)) {
    Position_M->Timing.t[0] = rtsiGetT(&Position_M->solverInfo);
  }

  {
    codertarget_arduinobase_int_c_T *obj;
    real_T lastTime;
    real_T rtb_Integrator;
    real_T rtb_Sum2;
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

    /* Gain: '<S3>/Gain' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion1'
     *  Gain: '<S1>/Gain2'
     *  MATLABSystem: '<S1>/Encoder1'
     */
    Position_B.Gain = Position_P.Gain2_Gain * (real_T)rtb_Encoder1_0 *
      Position_P.Gain_Gain;
    if (rtmIsMajorTimeStep(Position_M)) {
    }

    /* Derivative: '<Root>/Derivative2' incorporates:
     *  Derivative: '<Root>/Derivative1'
     */
    rtb_Integrator = Position_M->Timing.t[0];
    if ((Position_DW.TimeStampA >= rtb_Integrator) && (Position_DW.TimeStampB >=
         rtb_Integrator)) {
      /* Derivative: '<Root>/Derivative2' */
      Position_B.Derivative2 = 0.0;
    } else {
      lastTime = Position_DW.TimeStampA;
      lastU = &Position_DW.LastUAtTimeA;
      if (Position_DW.TimeStampA < Position_DW.TimeStampB) {
        if (Position_DW.TimeStampB < rtb_Integrator) {
          lastTime = Position_DW.TimeStampB;
          lastU = &Position_DW.LastUAtTimeB;
        }
      } else if (Position_DW.TimeStampA >= rtb_Integrator) {
        lastTime = Position_DW.TimeStampB;
        lastU = &Position_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/Derivative2' */
      Position_B.Derivative2 = (Position_B.Gain - *lastU) / (rtb_Integrator -
        lastTime);
    }

    /* End of Derivative: '<Root>/Derivative2' */
    if (rtmIsMajorTimeStep(Position_M)) {
    }

    /* Sum: '<Root>/Sum2' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    rtb_Sum2 = Position_P.Constant2_Value - Position_B.Derivative2;

    /* Derivative: '<Root>/Derivative1' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    if ((Position_DW.TimeStampA_a >= rtb_Integrator) &&
        (Position_DW.TimeStampB_o >= rtb_Integrator)) {
      rtb_Integrator = 0.0;
    } else {
      lastTime = Position_DW.TimeStampA_a;
      lastU = &Position_DW.LastUAtTimeA_i;
      if (Position_DW.TimeStampA_a < Position_DW.TimeStampB_o) {
        if (Position_DW.TimeStampB_o < rtb_Integrator) {
          lastTime = Position_DW.TimeStampB_o;
          lastU = &Position_DW.LastUAtTimeB_m;
        }
      } else if (Position_DW.TimeStampA_a >= rtb_Integrator) {
        lastTime = Position_DW.TimeStampB_o;
        lastU = &Position_DW.LastUAtTimeB_m;
      }

      rtb_Integrator = (Position_P.Constant2_Value - *lastU) / (rtb_Integrator -
        lastTime);
    }

    if (rtmIsMajorTimeStep(Position_M)) {
      /* Gain: '<Root>/Gain5' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      Position_B.Gain5 = Position_P.a / Position_P.b *
        Position_P.Constant2_Value;
    }

    /* MATLAB Function: '<S1>/MATLAB Function4' incorporates:
     *  Gain: '<Root>/Gain7'
     *  Gain: '<Root>/Gain8'
     *  Integrator: '<Root>/Integrator'
     *  Sum: '<Root>/Add1'
     *  Sum: '<Root>/Add2'
     */
    rtb_Integrator = (((1.0 / Position_P.b * rtb_Integrator + Position_B.Gain5)
                       + Position_X.Integrator_CSTATE) + Position_P.k2 *
                      rtb_Sum2) * 254.0 / 12.0;
    if (rtb_Integrator > 0.0) {
      rtb_IN1 = 1;
      rtb_IN2 = 0;
    } else if (rtb_Integrator < 0.0) {
      rtb_Integrator = fabs(rtb_Integrator);
      rtb_IN1 = 0;
      rtb_IN2 = 1;
    } else {
      rtb_Integrator = 0.0;
      rtb_IN1 = 0;
      rtb_IN2 = 0;
    }

    /* End of MATLAB Function: '<S1>/MATLAB Function4' */

    /* MATLABSystem: '<S1>/Digital Output' */
    writeDigitalPin(5, (uint8_T)rtb_IN1);

    /* MATLABSystem: '<S1>/Digital Output1' */
    writeDigitalPin(7, (uint8_T)rtb_IN2);

    /* MATLABSystem: '<S1>/PWM' */
    obj = &Position_DW.obj_m;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
    if (!(rtb_Integrator <= 255.0)) {
      rtb_Integrator = 255.0;
    }

    MW_PWM_SetDutyCycle(Position_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE,
                        rtb_Integrator);

    /* End of MATLABSystem: '<S1>/PWM' */

    /* Gain: '<Root>/Gain6' */
    Position_B.Gain6 = Position_P.k1 * rtb_Sum2;
  }

  if (rtmIsMajorTimeStep(Position_M)) {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative2' */
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

    *lastU = Position_B.Gain;

    /* End of Update for Derivative: '<Root>/Derivative2' */

    /* Update for Derivative: '<Root>/Derivative1' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    if (Position_DW.TimeStampA_a == (rtInf)) {
      Position_DW.TimeStampA_a = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeA_i;
    } else if (Position_DW.TimeStampB_o == (rtInf)) {
      Position_DW.TimeStampB_o = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeB_m;
    } else if (Position_DW.TimeStampA_a < Position_DW.TimeStampB_o) {
      Position_DW.TimeStampA_a = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeA_i;
    } else {
      Position_DW.TimeStampB_o = Position_M->Timing.t[0];
      lastU = &Position_DW.LastUAtTimeB_m;
    }

    *lastU = Position_P.Constant2_Value;

    /* End of Update for Derivative: '<Root>/Derivative1' */
    {                                  /* Sample time: [0.0s, 0.0s] */
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

    if (rtmIsMajorTimeStep(Position_M)) {/* Sample time: [0.01s, 0.0s] */
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
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Position_M)) {
    rt_ertODEUpdateContinuousStates(&Position_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++Position_M->Timing.clockTick0;
    Position_M->Timing.t[0] = rtsiGetSolverStopTime(&Position_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      Position_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Position_derivatives(void)
{
  XDot_Position_T *_rtXdot;
  _rtXdot = ((XDot_Position_T *) Position_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = Position_B.Gain6;
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
    rtsiSetdXPtr(&Position_M->solverInfo, &Position_M->derivs);
    rtsiSetContStatesPtr(&Position_M->solverInfo, (real_T **)
                         &Position_M->contStates);
    rtsiSetNumContStatesPtr(&Position_M->solverInfo,
      &Position_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Position_M->solverInfo,
      &Position_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Position_M->solverInfo,
      &Position_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Position_M->solverInfo,
      &Position_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Position_M->solverInfo, (&rtmGetErrorStatus
      (Position_M)));
    rtsiSetRTModelPtr(&Position_M->solverInfo, Position_M);
  }

  rtsiSetSimTimeStep(&Position_M->solverInfo, MAJOR_TIME_STEP);
  Position_M->intgData.f[0] = Position_M->odeF[0];
  Position_M->contStates = ((X_Position_T *) &Position_X);
  rtsiSetSolverData(&Position_M->solverInfo, (void *)&Position_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&Position_M->solverInfo, false);
  rtsiSetSolverName(&Position_M->solverInfo,"ode1");
  rtmSetTPtr(Position_M, &Position_M->Timing.tArray[0]);
  rtmSetTFinal(Position_M, -1);
  Position_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Position_M->Sizes.checksums[0] = (576973754U);
  Position_M->Sizes.checksums[1] = (3125044970U);
  Position_M->Sizes.checksums[2] = (2648756114U);
  Position_M->Sizes.checksums[3] = (778093589U);

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

    /* InitializeConditions for Derivative: '<Root>/Derivative2' */
    Position_DW.TimeStampA = (rtInf);
    Position_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative1' */
    Position_DW.TimeStampA_a = (rtInf);
    Position_DW.TimeStampB_o = (rtInf);

    /* InitializeConditions for Integrator: '<Root>/Integrator' */
    Position_X.Integrator_CSTATE = Position_P.Integrator_IC;

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
    Position_DW.obj_h.matlabCodegenIsDeleted = false;
    Position_DW.obj_h.isInitialized = 1L;
    digitalIOSetup(5, 1);
    Position_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Output1' */
    Position_DW.obj_b.matlabCodegenIsDeleted = false;
    Position_DW.obj_b.isInitialized = 1L;
    digitalIOSetup(7, 1);
    Position_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM' */
    Position_DW.obj_m.matlabCodegenIsDeleted = true;
    Position_DW.obj_m.isInitialized = 0L;
    Position_DW.obj_m.matlabCodegenIsDeleted = false;
    obj = &Position_DW.obj_m;
    Position_DW.obj_m.isSetupComplete = false;
    Position_DW.obj_m.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(4UL, 0.0, 0.0);
    Position_DW.obj_m.isSetupComplete = true;
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
  if (!Position_DW.obj_h.matlabCodegenIsDeleted) {
    Position_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output' */

  /* Terminate for MATLABSystem: '<S1>/Digital Output1' */
  if (!Position_DW.obj_b.matlabCodegenIsDeleted) {
    Position_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S1>/PWM' */
  obj = &Position_DW.obj_m;
  if (!Position_DW.obj_m.matlabCodegenIsDeleted) {
    Position_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Position_DW.obj_m.isInitialized == 1L) &&
        Position_DW.obj_m.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_SetDutyCycle(Position_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_Close(Position_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
