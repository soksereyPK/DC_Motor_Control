/*
 * File: position_control.c
 *
 * Code generated for Simulink model 'position_control'.
 *
 * Model version                  : 2.142
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Sep 13 10:01:04 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "position_control.h"
#include "rtwtypes.h"
#include <math.h>
#include "position_control_types.h"
#include "rt_nonfinite.h"
#include "position_control_private.h"

/* Block states (default storage) */
DW_position_control_T position_control_DW;

/* Real-time model */
static RT_MODEL_position_control_T position_control_M_;
RT_MODEL_position_control_T *const position_control_M = &position_control_M_;

/* Model step function */
void position_control_step(void)
{
  codertarget_arduinobase_inter_T *obj;
  real_T pwm_cal;
  real_T rtb_Lpwm;

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  Sin: '<Root>/Sine Wave1'
   */
  pwm_cal = (sin(position_control_P.SineWave1_Freq *
                 position_control_M->Timing.t[0] +
                 position_control_P.SineWave1_Phase) *
             position_control_P.SineWave1_Amp +
             position_control_P.SineWave1_Bias) * 254.0 / 22.9;
  if (pwm_cal > 0.0) {
    rtb_Lpwm = 0.0;
  } else if (pwm_cal < 0.0) {
    rtb_Lpwm = fabs(pwm_cal);
    pwm_cal = 0.0;
  } else {
    rtb_Lpwm = 0.0;
    pwm_cal = 0.0;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function2' */

  /* MATLABSystem: '<Root>/PWM1' */
  obj = &position_control_DW.obj_l;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
  if (!(rtb_Lpwm <= 255.0)) {
    rtb_Lpwm = 255.0;
  }

  MW_PWM_SetDutyCycle(position_control_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE,
                      rtb_Lpwm);

  /* End of MATLABSystem: '<Root>/PWM1' */

  /* MATLABSystem: '<Root>/PWM2' */
  obj = &position_control_DW.obj;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
  if (!(pwm_cal <= 255.0)) {
    pwm_cal = 255.0;
  }

  MW_PWM_SetDutyCycle(position_control_DW.obj.PWMDriverObj.MW_PWM_HANDLE,
                      pwm_cal);

  /* End of MATLABSystem: '<Root>/PWM2' */
  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((position_control_M->Timing.clockTick0 * 1) + 0)
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
      ((position_control_M->Timing.clockTick1 * 1) + 0)
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
  position_control_M->Timing.t[0] =
    ((time_T)(++position_control_M->Timing.clockTick0)) *
    position_control_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    position_control_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void position_control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&position_control_M->solverInfo,
                          &position_control_M->Timing.simTimeStep);
    rtsiSetTPtr(&position_control_M->solverInfo, &rtmGetTPtr(position_control_M));
    rtsiSetStepSizePtr(&position_control_M->solverInfo,
                       &position_control_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&position_control_M->solverInfo, (&rtmGetErrorStatus
      (position_control_M)));
    rtsiSetRTModelPtr(&position_control_M->solverInfo, position_control_M);
  }

  rtsiSetSimTimeStep(&position_control_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&position_control_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(position_control_M, &position_control_M->Timing.tArray[0]);
  rtmSetTFinal(position_control_M, -1);
  position_control_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  position_control_M->Sizes.checksums[0] = (1000885025U);
  position_control_M->Sizes.checksums[1] = (3318409239U);
  position_control_M->Sizes.checksums[2] = (934745877U);
  position_control_M->Sizes.checksums[3] = (1540150697U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    position_control_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(position_control_M->extModeInfo,
      &position_control_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(position_control_M->extModeInfo,
                        position_control_M->Sizes.checksums);
    rteiSetTPtr(position_control_M->extModeInfo, rtmGetTPtr(position_control_M));
  }

  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<Root>/PWM1' */
    position_control_DW.obj_l.matlabCodegenIsDeleted = true;
    position_control_DW.obj_l.isInitialized = 0L;
    position_control_DW.obj_l.matlabCodegenIsDeleted = false;
    obj = &position_control_DW.obj_l;
    position_control_DW.obj_l.isSetupComplete = false;
    position_control_DW.obj_l.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6UL, 0.0, 0.0);
    position_control_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM2' */
    position_control_DW.obj.matlabCodegenIsDeleted = true;
    position_control_DW.obj.isInitialized = 0L;
    position_control_DW.obj.matlabCodegenIsDeleted = false;
    obj = &position_control_DW.obj;
    position_control_DW.obj.isSetupComplete = false;
    position_control_DW.obj.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
    position_control_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void position_control_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/PWM1' */
  obj = &position_control_DW.obj_l;
  if (!position_control_DW.obj_l.matlabCodegenIsDeleted) {
    position_control_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((position_control_DW.obj_l.isInitialized == 1L) &&
        position_control_DW.obj_l.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_SetDutyCycle(position_control_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_Close(position_control_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM1' */

  /* Terminate for MATLABSystem: '<Root>/PWM2' */
  obj = &position_control_DW.obj;
  if (!position_control_DW.obj.matlabCodegenIsDeleted) {
    position_control_DW.obj.matlabCodegenIsDeleted = true;
    if ((position_control_DW.obj.isInitialized == 1L) &&
        position_control_DW.obj.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(position_control_DW.obj.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(position_control_DW.obj.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
