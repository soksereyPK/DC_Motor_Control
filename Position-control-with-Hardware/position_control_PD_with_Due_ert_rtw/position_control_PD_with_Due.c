/*
 * File: position_control_PD_with_Due.c
 *
 * Code generated for Simulink model 'position_control_PD_with_Due'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Jul  9 10:25:01 2022
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
    real_T pwm_cal;
    real_T rtb_Derivative2;
    real_T rtb_Gain8;
    real_T rtb_Gain9;
    real_T rtb_Sum3;
    real_T *lastU;
    int32_T rtb_dir;

    /* Derivative: '<Root>/Derivative4' incorporates:
     *  Derivative: '<Root>/Derivative2'
     *  Derivative: '<Root>/Derivative3'
     *  Derivative: '<Root>/Derivative5'
     */
    pwm_cal = position_control_PD_with_Due_M->Timing.t[0];
    if ((position_control_PD_with_Due_DW.TimeStampA >= pwm_cal) &&
        (position_control_PD_with_Due_DW.TimeStampB >= pwm_cal)) {
      /* Derivative: '<Root>/Derivative4' */
      position_control_PD_with_Due_B.Derivative4 = 0.0;
    } else {
      rtb_Derivative2 = position_control_PD_with_Due_DW.TimeStampA;
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeA;
      if (position_control_PD_with_Due_DW.TimeStampA <
          position_control_PD_with_Due_DW.TimeStampB) {
        if (position_control_PD_with_Due_DW.TimeStampB < pwm_cal) {
          rtb_Derivative2 = position_control_PD_with_Due_DW.TimeStampB;
          lastU = &position_control_PD_with_Due_DW.LastUAtTimeB;
        }
      } else if (position_control_PD_with_Due_DW.TimeStampA >= pwm_cal) {
        rtb_Derivative2 = position_control_PD_with_Due_DW.TimeStampB;
        lastU = &position_control_PD_with_Due_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/Derivative4' incorporates:
       *  Constant: '<Root>/Constant5'
       */
      position_control_PD_with_Due_B.Derivative4 =
        (position_control_PD_with_Due_P.Constant5_Value - *lastU) / (pwm_cal -
        rtb_Derivative2);
    }

    /* End of Derivative: '<Root>/Derivative4' */

    /* Derivative: '<Root>/Derivative5' */
    if ((position_control_PD_with_Due_DW.TimeStampA_o >= pwm_cal) &&
        (position_control_PD_with_Due_DW.TimeStampB_g >= pwm_cal)) {
      rtb_Derivative2 = 0.0;
    } else {
      rtb_Derivative2 = position_control_PD_with_Due_DW.TimeStampA_o;
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeA_f;
      if (position_control_PD_with_Due_DW.TimeStampA_o <
          position_control_PD_with_Due_DW.TimeStampB_g) {
        if (position_control_PD_with_Due_DW.TimeStampB_g < pwm_cal) {
          rtb_Derivative2 = position_control_PD_with_Due_DW.TimeStampB_g;
          lastU = &position_control_PD_with_Due_DW.LastUAtTimeB_f;
        }
      } else if (position_control_PD_with_Due_DW.TimeStampA_o >= pwm_cal) {
        rtb_Derivative2 = position_control_PD_with_Due_DW.TimeStampB_g;
        lastU = &position_control_PD_with_Due_DW.LastUAtTimeB_f;
      }

      rtb_Derivative2 = (position_control_PD_with_Due_B.Derivative4 - *lastU) /
        (pwm_cal - rtb_Derivative2);
    }

    /* Gain: '<Root>/Gain9' */
    rtb_Gain9 = 1.0 / position_control_PD_with_Due_P.b * rtb_Derivative2;

    /* Derivative: '<Root>/Derivative3' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    if ((position_control_PD_with_Due_DW.TimeStampA_n >= pwm_cal) &&
        (position_control_PD_with_Due_DW.TimeStampB_c >= pwm_cal)) {
      rtb_Derivative2 = 0.0;
    } else {
      rtb_Derivative2 = position_control_PD_with_Due_DW.TimeStampA_n;
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeA_e;
      if (position_control_PD_with_Due_DW.TimeStampA_n <
          position_control_PD_with_Due_DW.TimeStampB_c) {
        if (position_control_PD_with_Due_DW.TimeStampB_c < pwm_cal) {
          rtb_Derivative2 = position_control_PD_with_Due_DW.TimeStampB_c;
          lastU = &position_control_PD_with_Due_DW.LastUAtTimeB_f3;
        }
      } else if (position_control_PD_with_Due_DW.TimeStampA_n >= pwm_cal) {
        rtb_Derivative2 = position_control_PD_with_Due_DW.TimeStampB_c;
        lastU = &position_control_PD_with_Due_DW.LastUAtTimeB_f3;
      }

      rtb_Derivative2 = (position_control_PD_with_Due_P.Constant5_Value - *lastU)
        / (pwm_cal - rtb_Derivative2);
    }

    /* Gain: '<Root>/Gain8' */
    rtb_Gain8 = position_control_PD_with_Due_P.a /
      position_control_PD_with_Due_P.b * rtb_Derivative2;

    /* S-Function (readEncDUEpin8_9): '<S1>/Encoder1' */
    readEncDUEpin8_9_Outputs_wrapper(&position_control_PD_with_Due_B.Encoder1,
      &position_control_PD_with_Due_DW.Encoder1_DSTATE);

    /* MATLAB Function: '<S1>/Convert pulse to rad1' incorporates:
     *  Constant: '<S1>/gearRatio'
     *  Constant: '<S1>/totalPPR'
     */
    rtb_Sum3 = (real_T)position_control_PD_with_Due_B.Encoder1 -
      position_control_PD_with_Due_DW.counter_num;
    if (rtb_Sum3 > 40000.0) {
      position_control_PD_with_Due_DW.over_flag--;
    } else if (rtb_Sum3 < -40000.0) {
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

    /* Sum: '<Root>/Sum3' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    rtb_Sum3 = position_control_PD_with_Due_P.Constant5_Value -
      position_control_PD_with_Due_B.outGearBox;

    /* Gain: '<Root>/Gain7' */
    position_control_PD_with_Due_B.Gain7 = position_control_PD_with_Due_P.kd4 *
      rtb_Sum3;

    /* Derivative: '<Root>/Derivative2' */
    if ((position_control_PD_with_Due_DW.TimeStampA_g >= pwm_cal) &&
        (position_control_PD_with_Due_DW.TimeStampB_d >= pwm_cal)) {
      rtb_Derivative2 = 0.0;
    } else {
      rtb_Derivative2 = position_control_PD_with_Due_DW.TimeStampA_g;
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeA_b;
      if (position_control_PD_with_Due_DW.TimeStampA_g <
          position_control_PD_with_Due_DW.TimeStampB_d) {
        if (position_control_PD_with_Due_DW.TimeStampB_d < pwm_cal) {
          rtb_Derivative2 = position_control_PD_with_Due_DW.TimeStampB_d;
          lastU = &position_control_PD_with_Due_DW.LastUAtTimeB_c;
        }
      } else if (position_control_PD_with_Due_DW.TimeStampA_g >= pwm_cal) {
        rtb_Derivative2 = position_control_PD_with_Due_DW.TimeStampB_d;
        lastU = &position_control_PD_with_Due_DW.LastUAtTimeB_c;
      }

      rtb_Derivative2 = (position_control_PD_with_Due_B.Gain7 - *lastU) /
        (pwm_cal - rtb_Derivative2);
    }

    /* Sum: '<Root>/Add2' incorporates:
     *  Gain: '<Root>/Gain6'
     */
    position_control_PD_with_Due_B.Add2 = ((rtb_Gain9 + rtb_Gain8) +
      position_control_PD_with_Due_P.kp4 * rtb_Sum3) + rtb_Derivative2;

    /* MATLAB Function: '<S1>/MATLAB Function2' */
    pwm_cal = position_control_PD_with_Due_B.Add2 * 254.0 / 22.9;
    if (pwm_cal > 0.0) {
      rtb_dir = 0;
    } else if (pwm_cal < 0.0) {
      pwm_cal = fabs(pwm_cal);
      rtb_dir = 1;
    } else {
      pwm_cal = 0.0;
      rtb_dir = 0;
    }

    /* End of MATLAB Function: '<S1>/MATLAB Function2' */

    /* MATLABSystem: '<S1>/Digital Output' */
    writeDigitalPin(7, (uint8_T)rtb_dir);

    /* MATLABSystem: '<S1>/PWM' */
    obj = &position_control_PD_with_Due_DW.obj_n;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
    if (!(pwm_cal <= 255.0)) {
      pwm_cal = 255.0;
    }

    MW_PWM_SetDutyCycle
      (position_control_PD_with_Due_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE, pwm_cal);

    /* End of MATLABSystem: '<S1>/PWM' */
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative4' incorporates:
     *  Constant: '<Root>/Constant5'
     */
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

    *lastU = position_control_PD_with_Due_P.Constant5_Value;

    /* End of Update for Derivative: '<Root>/Derivative4' */

    /* Update for Derivative: '<Root>/Derivative5' */
    if (position_control_PD_with_Due_DW.TimeStampA_o == (rtInf)) {
      position_control_PD_with_Due_DW.TimeStampA_o =
        position_control_PD_with_Due_M->Timing.t[0];
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeA_f;
    } else if (position_control_PD_with_Due_DW.TimeStampB_g == (rtInf)) {
      position_control_PD_with_Due_DW.TimeStampB_g =
        position_control_PD_with_Due_M->Timing.t[0];
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeB_f;
    } else if (position_control_PD_with_Due_DW.TimeStampA_o <
               position_control_PD_with_Due_DW.TimeStampB_g) {
      position_control_PD_with_Due_DW.TimeStampA_o =
        position_control_PD_with_Due_M->Timing.t[0];
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeA_f;
    } else {
      position_control_PD_with_Due_DW.TimeStampB_g =
        position_control_PD_with_Due_M->Timing.t[0];
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeB_f;
    }

    *lastU = position_control_PD_with_Due_B.Derivative4;

    /* End of Update for Derivative: '<Root>/Derivative5' */

    /* Update for Derivative: '<Root>/Derivative3' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    if (position_control_PD_with_Due_DW.TimeStampA_n == (rtInf)) {
      position_control_PD_with_Due_DW.TimeStampA_n =
        position_control_PD_with_Due_M->Timing.t[0];
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeA_e;
    } else if (position_control_PD_with_Due_DW.TimeStampB_c == (rtInf)) {
      position_control_PD_with_Due_DW.TimeStampB_c =
        position_control_PD_with_Due_M->Timing.t[0];
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeB_f3;
    } else if (position_control_PD_with_Due_DW.TimeStampA_n <
               position_control_PD_with_Due_DW.TimeStampB_c) {
      position_control_PD_with_Due_DW.TimeStampA_n =
        position_control_PD_with_Due_M->Timing.t[0];
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeA_e;
    } else {
      position_control_PD_with_Due_DW.TimeStampB_c =
        position_control_PD_with_Due_M->Timing.t[0];
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeB_f3;
    }

    *lastU = position_control_PD_with_Due_P.Constant5_Value;

    /* End of Update for Derivative: '<Root>/Derivative3' */

    /* Update for S-Function (readEncDUEpin8_9): '<S1>/Encoder1' */

    /* S-Function "readEncDUEpin8_9_wrapper" Block: <S1>/Encoder1 */
    readEncDUEpin8_9_Update_wrapper(&position_control_PD_with_Due_B.Encoder1,
      &position_control_PD_with_Due_DW.Encoder1_DSTATE);

    /* Update for Derivative: '<Root>/Derivative2' */
    if (position_control_PD_with_Due_DW.TimeStampA_g == (rtInf)) {
      position_control_PD_with_Due_DW.TimeStampA_g =
        position_control_PD_with_Due_M->Timing.t[0];
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeA_b;
    } else if (position_control_PD_with_Due_DW.TimeStampB_d == (rtInf)) {
      position_control_PD_with_Due_DW.TimeStampB_d =
        position_control_PD_with_Due_M->Timing.t[0];
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeB_c;
    } else if (position_control_PD_with_Due_DW.TimeStampA_g <
               position_control_PD_with_Due_DW.TimeStampB_d) {
      position_control_PD_with_Due_DW.TimeStampA_g =
        position_control_PD_with_Due_M->Timing.t[0];
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeA_b;
    } else {
      position_control_PD_with_Due_DW.TimeStampB_d =
        position_control_PD_with_Due_M->Timing.t[0];
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeB_c;
    }

    *lastU = position_control_PD_with_Due_B.Gain7;

    /* End of Update for Derivative: '<Root>/Derivative2' */
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
  position_control_PD_with_Due_M->Sizes.checksums[0] = (3545071460U);
  position_control_PD_with_Due_M->Sizes.checksums[1] = (3190283224U);
  position_control_PD_with_Due_M->Sizes.checksums[2] = (196492255U);
  position_control_PD_with_Due_M->Sizes.checksums[3] = (571998339U);

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

    /* InitializeConditions for Derivative: '<Root>/Derivative4' */
    position_control_PD_with_Due_DW.TimeStampA = (rtInf);
    position_control_PD_with_Due_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative5' */
    position_control_PD_with_Due_DW.TimeStampA_o = (rtInf);
    position_control_PD_with_Due_DW.TimeStampB_g = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative3' */
    position_control_PD_with_Due_DW.TimeStampA_n = (rtInf);
    position_control_PD_with_Due_DW.TimeStampB_c = (rtInf);

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

    /* InitializeConditions for Derivative: '<Root>/Derivative2' */
    position_control_PD_with_Due_DW.TimeStampA_g = (rtInf);
    position_control_PD_with_Due_DW.TimeStampB_d = (rtInf);

    /* Start for MATLABSystem: '<S1>/Digital Output' */
    position_control_PD_with_Due_DW.obj.matlabCodegenIsDeleted = false;
    position_control_PD_with_Due_DW.obj.isInitialized = 1;
    digitalIOSetup(7, 1);
    position_control_PD_with_Due_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM' */
    position_control_PD_with_Due_DW.obj_n.matlabCodegenIsDeleted = true;
    position_control_PD_with_Due_DW.obj_n.isInitialized = 0;
    position_control_PD_with_Due_DW.obj_n.matlabCodegenIsDeleted = false;
    obj = &position_control_PD_with_Due_DW.obj_n;
    position_control_PD_with_Due_DW.obj_n.isSetupComplete = false;
    position_control_PD_with_Due_DW.obj_n.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6U, 0.0, 0.0);
    position_control_PD_with_Due_DW.obj_n.isSetupComplete = true;
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
  obj = &position_control_PD_with_Due_DW.obj_n;
  if (!position_control_PD_with_Due_DW.obj_n.matlabCodegenIsDeleted) {
    position_control_PD_with_Due_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((position_control_PD_with_Due_DW.obj_n.isInitialized == 1) &&
        position_control_PD_with_Due_DW.obj_n.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
      MW_PWM_SetDutyCycle
        (position_control_PD_with_Due_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
      MW_PWM_Close
        (position_control_PD_with_Due_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
