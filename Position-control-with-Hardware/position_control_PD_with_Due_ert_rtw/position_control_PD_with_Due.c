/*
 * File: position_control_PD_with_Due.c
 *
 * Code generated for Simulink model 'position_control_PD_with_Due'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Jul  9 09:27:34 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "position_control_PD_with_Due.h"
#include "position_control_PD_with_Due_private.h"

/* Block signals (default storage) */
B_position_control_PD_with_Du_T position_control_PD_with_Due_B;

/* Block states (default storage) */
DW_position_control_PD_with_D_T position_control_PD_with_Due_DW;

/* Real-time model */
static RT_MODEL_position_control_PD__T position_control_PD_with_Due_M_;
RT_MODEL_position_control_PD__T *const position_control_PD_with_Due_M =
  &position_control_PD_with_Due_M_;

/* Model step function */
void position_control_PD_with_Due_step(void)
{
  {
    codertarget_arduinobase_inter_T *obj;
    real_T lastTime;
    real_T rtb_Derivative;
    real_T rtb_Sum1;
    real_T *lastU;
    int32_T rtb_dir;

    /* S-Function (readEncDUEpin8_9): '<S1>/Encoder1' */
    readEncDUEpin8_9_Outputs_wrapper(&position_control_PD_with_Due_B.Encoder1,
      &position_control_PD_with_Due_DW.Encoder1_DSTATE);

    /* MATLAB Function: '<S1>/Convert pulse to rad1' incorporates:
     *  Constant: '<S1>/gearRatio'
     *  Constant: '<S1>/totalPPR'
     */
    rtb_Derivative = (real_T)position_control_PD_with_Due_B.Encoder1 -
      position_control_PD_with_Due_DW.counter_num;
    if (rtb_Derivative > 40000.0) {
      position_control_PD_with_Due_DW.over_flag--;
    } else if (rtb_Derivative < -40000.0) {
      position_control_PD_with_Due_DW.over_flag++;
    }

    position_control_PD_with_Due_B.outGearBox =
      (position_control_PD_with_Due_DW.over_flag * 4.294967295E+9 + (real_T)
       position_control_PD_with_Due_B.Encoder1) * (6.2831853071795862 /
      position_control_PD_with_Due_P.totalPPR_Value) /
      position_control_PD_with_Due_P.gearRatio_Value;
    position_control_PD_with_Due_DW.counter_num =
      position_control_PD_with_Due_B.Encoder1;

    /* End of MATLAB Function: '<S1>/Convert pulse to rad1' */
    /* Sum: '<Root>/Sum1' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    rtb_Sum1 = position_control_PD_with_Due_P.Constant3_Value -
      position_control_PD_with_Due_B.outGearBox;

    /* Gain: '<Root>/Gain2' */
    position_control_PD_with_Due_B.Gain2 = position_control_PD_with_Due_P.kd2 *
      rtb_Sum1;

    /* Derivative: '<Root>/Derivative' */
    rtb_Derivative = position_control_PD_with_Due_M->Timing.t[0];
    if ((position_control_PD_with_Due_DW.TimeStampA >= rtb_Derivative) &&
        (position_control_PD_with_Due_DW.TimeStampB >= rtb_Derivative)) {
      rtb_Derivative = 0.0;
    } else {
      lastTime = position_control_PD_with_Due_DW.TimeStampA;
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeA;
      if (position_control_PD_with_Due_DW.TimeStampA <
          position_control_PD_with_Due_DW.TimeStampB) {
        if (position_control_PD_with_Due_DW.TimeStampB < rtb_Derivative) {
          lastTime = position_control_PD_with_Due_DW.TimeStampB;
          lastU = &position_control_PD_with_Due_DW.LastUAtTimeB;
        }
      } else if (position_control_PD_with_Due_DW.TimeStampA >= rtb_Derivative) {
        lastTime = position_control_PD_with_Due_DW.TimeStampB;
        lastU = &position_control_PD_with_Due_DW.LastUAtTimeB;
      }

      rtb_Derivative = (position_control_PD_with_Due_B.Gain2 - *lastU) /
        (rtb_Derivative - lastTime);
    }

    /* End of Derivative: '<Root>/Derivative' */

    /* Sum: '<Root>/Add' incorporates:
     *  Gain: '<Root>/Gain1'
     */
    position_control_PD_with_Due_B.Add = position_control_PD_with_Due_P.kp2 *
      rtb_Sum1 + rtb_Derivative;

    /* MATLAB Function: '<S1>/MATLAB Function2' */
    rtb_Sum1 = position_control_PD_with_Due_B.Add * 254.0 / 22.9;
    if (rtb_Sum1 > 0.0) {
      rtb_dir = 0;
    } else if (rtb_Sum1 < 0.0) {
      rtb_Sum1 = fabs(rtb_Sum1);
      rtb_dir = 1;
    } else {
      rtb_Sum1 = 0.0;
      rtb_dir = 0;
    }

    /* End of MATLAB Function: '<S1>/MATLAB Function2' */

    /* MATLABSystem: '<S1>/Digital Output' */
    writeDigitalPin(7, (uint8_T)rtb_dir);

    /* MATLABSystem: '<S1>/PWM' */
    obj = &position_control_PD_with_Due_DW.obj_i;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
    if (!(rtb_Sum1 <= 255.0)) {
      rtb_Sum1 = 255.0;
    }

    MW_PWM_SetDutyCycle
      (position_control_PD_with_Due_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE,
       rtb_Sum1);

    /* End of MATLABSystem: '<S1>/PWM' */
  }

  {
    real_T *lastU;

    /* Update for S-Function (readEncDUEpin8_9): '<S1>/Encoder1' */

    /* S-Function "readEncDUEpin8_9_wrapper" Block: <S1>/Encoder1 */
    readEncDUEpin8_9_Update_wrapper(&position_control_PD_with_Due_B.Encoder1,
      &position_control_PD_with_Due_DW.Encoder1_DSTATE);

    /* Update for Derivative: '<Root>/Derivative' */
    if (position_control_PD_with_Due_DW.TimeStampA == (rtInf)) {
      position_control_PD_with_Due_DW.TimeStampA =
        position_control_PD_with_Due_M->Timing.t[0];
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeA;
    } else if (position_control_PD_with_Due_DW.TimeStampB == (rtInf)) {
      position_control_PD_with_Due_DW.TimeStampB =
        position_control_PD_with_Due_M->Timing.t[0];
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeB;
    } else if (position_control_PD_with_Due_DW.TimeStampA <
               position_control_PD_with_Due_DW.TimeStampB) {
      position_control_PD_with_Due_DW.TimeStampA =
        position_control_PD_with_Due_M->Timing.t[0];
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeA;
    } else {
      position_control_PD_with_Due_DW.TimeStampB =
        position_control_PD_with_Due_M->Timing.t[0];
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeB;
    }

    *lastU = position_control_PD_with_Due_B.Gain2;

    /* End of Update for Derivative: '<Root>/Derivative' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      position_control_PD_with_Due_M->Timing.t[0];

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
      ((position_control_PD_with_Due_M->Timing.clockTick1) * 0.01);

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
  position_control_PD_with_Due_M->Timing.t[0] =
    ((time_T)(++position_control_PD_with_Due_M->Timing.clockTick0)) *
    position_control_PD_with_Due_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    position_control_PD_with_Due_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void position_control_PD_with_Due_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&position_control_PD_with_Due_M->solverInfo,
                          &position_control_PD_with_Due_M->Timing.simTimeStep);
    rtsiSetTPtr(&position_control_PD_with_Due_M->solverInfo, &rtmGetTPtr
                (position_control_PD_with_Due_M));
    rtsiSetStepSizePtr(&position_control_PD_with_Due_M->solverInfo,
                       &position_control_PD_with_Due_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&position_control_PD_with_Due_M->solverInfo,
                          (&rtmGetErrorStatus(position_control_PD_with_Due_M)));
    rtsiSetRTModelPtr(&position_control_PD_with_Due_M->solverInfo,
                      position_control_PD_with_Due_M);
  }

  rtsiSetSimTimeStep(&position_control_PD_with_Due_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetSolverName(&position_control_PD_with_Due_M->solverInfo,
                    "FixedStepDiscrete");
  rtmSetTPtr(position_control_PD_with_Due_M,
             &position_control_PD_with_Due_M->Timing.tArray[0]);
  rtmSetTFinal(position_control_PD_with_Due_M, 5.0);
  position_control_PD_with_Due_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  position_control_PD_with_Due_M->Sizes.checksums[0] = (725965226U);
  position_control_PD_with_Due_M->Sizes.checksums[1] = (2717445140U);
  position_control_PD_with_Due_M->Sizes.checksums[2] = (3644411971U);
  position_control_PD_with_Due_M->Sizes.checksums[3] = (1055603575U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    position_control_PD_with_Due_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(position_control_PD_with_Due_M->extModeInfo,
      &position_control_PD_with_Due_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(position_control_PD_with_Due_M->extModeInfo,
                        position_control_PD_with_Due_M->Sizes.checksums);
    rteiSetTPtr(position_control_PD_with_Due_M->extModeInfo, rtmGetTPtr
                (position_control_PD_with_Due_M));
  }

  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for S-Function (readEncDUEpin8_9): '<S1>/Encoder1' */

    /* S-Function Block: <S1>/Encoder1 */
    readEncDUEpin8_9_Start_wrapper
      (&position_control_PD_with_Due_DW.Encoder1_DSTATE);

    /* InitializeConditions for S-Function (readEncDUEpin8_9): '<S1>/Encoder1' */

    /* S-Function Block: <S1>/Encoder1 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          position_control_PD_with_Due_DW.Encoder1_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for Derivative: '<Root>/Derivative' */
    position_control_PD_with_Due_DW.TimeStampA = (rtInf);
    position_control_PD_with_Due_DW.TimeStampB = (rtInf);

    /* Start for MATLABSystem: '<S1>/Digital Output' */
    position_control_PD_with_Due_DW.obj.matlabCodegenIsDeleted = false;
    position_control_PD_with_Due_DW.obj.isInitialized = 1;
    digitalIOSetup(7, 1);
    position_control_PD_with_Due_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM' */
    position_control_PD_with_Due_DW.obj_i.matlabCodegenIsDeleted = true;
    position_control_PD_with_Due_DW.obj_i.isInitialized = 0;
    position_control_PD_with_Due_DW.obj_i.matlabCodegenIsDeleted = false;
    obj = &position_control_PD_with_Due_DW.obj_i;
    position_control_PD_with_Due_DW.obj_i.isSetupComplete = false;
    position_control_PD_with_Due_DW.obj_i.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6U, 0.0, 0.0);
    position_control_PD_with_Due_DW.obj_i.isSetupComplete = true;
  }
}

/* Model terminate function */
void position_control_PD_with_Due_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S1>/Digital Output' */
  if (!position_control_PD_with_Due_DW.obj.matlabCodegenIsDeleted) {
    position_control_PD_with_Due_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Output' */

  /* Terminate for MATLABSystem: '<S1>/PWM' */
  obj = &position_control_PD_with_Due_DW.obj_i;
  if (!position_control_PD_with_Due_DW.obj_i.matlabCodegenIsDeleted) {
    position_control_PD_with_Due_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((position_control_PD_with_Due_DW.obj_i.isInitialized == 1) &&
        position_control_PD_with_Due_DW.obj_i.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
      MW_PWM_SetDutyCycle
        (position_control_PD_with_Due_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
      MW_PWM_Close
        (position_control_PD_with_Due_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
