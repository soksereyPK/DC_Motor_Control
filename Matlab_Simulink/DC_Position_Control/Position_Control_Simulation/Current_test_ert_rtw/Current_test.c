/*
 * File: Current_test.c
 *
 * Code generated for Simulink model 'Current_test'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Aug 15 16:44:46 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Current_test.h"
#include "rtwtypes.h"
#include <math.h>
#include "Current_test_types.h"
#include "rt_nonfinite.h"
#include "Current_test_private.h"

/* Block signals (default storage) */
B_Current_test_T Current_test_B;

/* Block states (default storage) */
DW_Current_test_T Current_test_DW;

/* Real-time model */
static RT_MODEL_Current_test_T Current_test_M_;
RT_MODEL_Current_test_T *const Current_test_M = &Current_test_M_;

/* Model step function */
void Current_test_step(void)
{
  {
    codertarget_arduinobase_int_d_T *obj;
    real_T rtb_Derivative;
    real_T rtb_Lpwm;
    real_T *lastU;
    int32_T rtb_Encoder1_0;

    /* MATLABSystem: '<S1>/Encoder1' */
    if (Current_test_DW.obj.SampleTime != Current_test_P.Encoder1_SampleTime) {
      Current_test_DW.obj.SampleTime = Current_test_P.Encoder1_SampleTime;
    }

    if (Current_test_DW.obj.TunablePropsChanged) {
      Current_test_DW.obj.TunablePropsChanged = false;
    }

    MW_EncoderRead(Current_test_DW.obj.Index, &rtb_Encoder1_0);

    /* Gain: '<S1>/Gain2' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion1'
     *  MATLABSystem: '<S1>/Encoder1'
     */
    Current_test_B.Gain2 = Current_test_P.Gain2_Gain * (real_T)rtb_Encoder1_0;

    /* Sum: '<Root>/Sum1' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    Current_test_B.Sum1 = Current_test_P.Constant3_Value - Current_test_B.Gain2;

    /* Gain: '<Root>/Gain4' */
    Current_test_B.Gain4 = Current_test_P.kd2 * Current_test_B.Sum1;

    /* Derivative: '<Root>/Derivative' */
    rtb_Derivative = Current_test_M->Timing.t[0];
    if ((Current_test_DW.TimeStampA >= rtb_Derivative) &&
        (Current_test_DW.TimeStampB >= rtb_Derivative)) {
      rtb_Derivative = 0.0;
    } else {
      rtb_Lpwm = Current_test_DW.TimeStampA;
      lastU = &Current_test_DW.LastUAtTimeA;
      if (Current_test_DW.TimeStampA < Current_test_DW.TimeStampB) {
        if (Current_test_DW.TimeStampB < rtb_Derivative) {
          rtb_Lpwm = Current_test_DW.TimeStampB;
          lastU = &Current_test_DW.LastUAtTimeB;
        }
      } else if (Current_test_DW.TimeStampA >= rtb_Derivative) {
        rtb_Lpwm = Current_test_DW.TimeStampB;
        lastU = &Current_test_DW.LastUAtTimeB;
      }

      rtb_Derivative = (Current_test_B.Gain4 - *lastU) / (rtb_Derivative -
        rtb_Lpwm);
    }

    /* End of Derivative: '<Root>/Derivative' */

    /* Sum: '<Root>/Add' incorporates:
     *  Gain: '<Root>/Gain3'
     */
    Current_test_B.Add = Current_test_P.kp2 * Current_test_B.Sum1 +
      rtb_Derivative;

    /* MATLAB Function: '<S1>/MATLAB Function2' */
    rtb_Derivative = Current_test_B.Add * 254.0 / 22.9;
    if (rtb_Derivative > 0.0) {
      rtb_Lpwm = 0.0;
    } else if (rtb_Derivative < 0.0) {
      rtb_Lpwm = fabs(rtb_Derivative);
      rtb_Derivative = 0.0;
    } else {
      rtb_Lpwm = 0.0;
      rtb_Derivative = 0.0;
    }

    /* End of MATLAB Function: '<S1>/MATLAB Function2' */

    /* MATLABSystem: '<S1>/PWM1' */
    obj = &Current_test_DW.obj_n;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
    if (!(rtb_Lpwm <= 255.0)) {
      rtb_Lpwm = 255.0;
    }

    MW_PWM_SetDutyCycle(Current_test_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE,
                        rtb_Lpwm);

    /* End of MATLABSystem: '<S1>/PWM1' */

    /* MATLABSystem: '<S1>/PWM2' */
    obj = &Current_test_DW.obj_g;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
    if (!(rtb_Derivative <= 255.0)) {
      rtb_Derivative = 255.0;
    }

    MW_PWM_SetDutyCycle(Current_test_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                        rtb_Derivative);

    /* End of MATLABSystem: '<S1>/PWM2' */
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative' */
    if (Current_test_DW.TimeStampA == (rtInf)) {
      Current_test_DW.TimeStampA = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeA;
    } else if (Current_test_DW.TimeStampB == (rtInf)) {
      Current_test_DW.TimeStampB = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeB;
    } else if (Current_test_DW.TimeStampA < Current_test_DW.TimeStampB) {
      Current_test_DW.TimeStampA = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeA;
    } else {
      Current_test_DW.TimeStampB = Current_test_M->Timing.t[0];
      lastU = &Current_test_DW.LastUAtTimeB;
    }

    *lastU = Current_test_B.Gain4;

    /* End of Update for Derivative: '<Root>/Derivative' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Current_test_M->Timing.clockTick0 * 1) + 0)
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
      ((Current_test_M->Timing.clockTick1 * 1) + 0)
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
  Current_test_M->Timing.t[0] =
    ((time_T)(++Current_test_M->Timing.clockTick0)) *
    Current_test_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Current_test_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Current_test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Current_test_M->solverInfo,
                          &Current_test_M->Timing.simTimeStep);
    rtsiSetTPtr(&Current_test_M->solverInfo, &rtmGetTPtr(Current_test_M));
    rtsiSetStepSizePtr(&Current_test_M->solverInfo,
                       &Current_test_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Current_test_M->solverInfo, (&rtmGetErrorStatus
      (Current_test_M)));
    rtsiSetRTModelPtr(&Current_test_M->solverInfo, Current_test_M);
  }

  rtsiSetSimTimeStep(&Current_test_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Current_test_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Current_test_M, &Current_test_M->Timing.tArray[0]);
  rtmSetTFinal(Current_test_M, 5.0);
  Current_test_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Current_test_M->Sizes.checksums[0] = (3020517578U);
  Current_test_M->Sizes.checksums[1] = (895825566U);
  Current_test_M->Sizes.checksums[2] = (1293135787U);
  Current_test_M->Sizes.checksums[3] = (2978977018U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    Current_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Current_test_M->extModeInfo,
      &Current_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Current_test_M->extModeInfo,
                        Current_test_M->Sizes.checksums);
    rteiSetTPtr(Current_test_M->extModeInfo, rtmGetTPtr(Current_test_M));
  }

  {
    codertarget_arduinobase_int_d_T *obj;

    /* InitializeConditions for Derivative: '<Root>/Derivative' */
    Current_test_DW.TimeStampA = (rtInf);
    Current_test_DW.TimeStampB = (rtInf);

    /* Start for MATLABSystem: '<S1>/Encoder1' */
    Current_test_DW.obj.Index = 0U;
    Current_test_DW.obj.matlabCodegenIsDeleted = false;
    Current_test_DW.obj.SampleTime = Current_test_P.Encoder1_SampleTime;
    Current_test_DW.obj.isSetupComplete = false;
    Current_test_DW.obj.isInitialized = 1L;
    MW_EncoderSetup(2UL, 3UL, &Current_test_DW.obj.Index);
    Current_test_DW.obj.isSetupComplete = true;
    Current_test_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S1>/Encoder1' */
    MW_EncoderReset(Current_test_DW.obj.Index);

    /* Start for MATLABSystem: '<S1>/PWM1' */
    Current_test_DW.obj_n.matlabCodegenIsDeleted = true;
    Current_test_DW.obj_n.isInitialized = 0L;
    Current_test_DW.obj_n.matlabCodegenIsDeleted = false;
    obj = &Current_test_DW.obj_n;
    Current_test_DW.obj_n.isSetupComplete = false;
    Current_test_DW.obj_n.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(8UL, 0.0, 0.0);
    Current_test_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM2' */
    Current_test_DW.obj_g.matlabCodegenIsDeleted = true;
    Current_test_DW.obj_g.isInitialized = 0L;
    Current_test_DW.obj_g.matlabCodegenIsDeleted = false;
    obj = &Current_test_DW.obj_g;
    Current_test_DW.obj_g.isSetupComplete = false;
    Current_test_DW.obj_g.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
    Current_test_DW.obj_g.isSetupComplete = true;
  }
}

/* Model terminate function */
void Current_test_terminate(void)
{
  codertarget_arduinobase_int_d_T *obj;

  /* Terminate for MATLABSystem: '<S1>/Encoder1' */
  if (!Current_test_DW.obj.matlabCodegenIsDeleted) {
    Current_test_DW.obj.matlabCodegenIsDeleted = true;
    if ((Current_test_DW.obj.isInitialized == 1L) &&
        Current_test_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder1' */
  /* Terminate for MATLABSystem: '<S1>/PWM1' */
  obj = &Current_test_DW.obj_n;
  if (!Current_test_DW.obj_n.matlabCodegenIsDeleted) {
    Current_test_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Current_test_DW.obj_n.isInitialized == 1L) &&
        Current_test_DW.obj_n.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
      MW_PWM_SetDutyCycle(Current_test_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8UL);
      MW_PWM_Close(Current_test_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM1' */

  /* Terminate for MATLABSystem: '<S1>/PWM2' */
  obj = &Current_test_DW.obj_g;
  if (!Current_test_DW.obj_g.matlabCodegenIsDeleted) {
    Current_test_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Current_test_DW.obj_g.isInitialized == 1L) &&
        Current_test_DW.obj_g.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(Current_test_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(Current_test_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
