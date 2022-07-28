/*
 * File: position_control_PD_with_Due.c
 *
 * Code generated for Simulink model 'position_control_PD_with_Due'.
 *
 * Model version                  : 2.5
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Jul 23 11:28:58 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "position_control_PD_with_Due.h"
#include "rtwtypes.h"
#include <math.h>
#include "multiword_types.h"
#include "position_control_PD_with_Due_types.h"
#include "rt_nonfinite.h"
#include "position_control_PD_with_Due_private.h"

/* Block signals (default storage) */
B_position_control_PD_with_Du_T position_control_PD_with_Due_B;

/* Block states (default storage) */
DW_position_control_PD_with_D_T position_control_PD_with_Due_DW;

/* Real-time model */
static RT_MODEL_position_control_PD__T position_control_PD_with_Due_M_;
RT_MODEL_position_control_PD__T *const position_control_PD_with_Due_M =
  &position_control_PD_with_Due_M_;
real_T sMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real_T y;
  int32_T exp_0;
  int32_T i;
  uint32_T cb;
  uint32_T u1i;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648U) != 0U) {
    cb = 1U;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= ldexp(cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += ldexp(u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

void sMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T ni;
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T cb1;
  uint32_T cb2;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;
  boolean_T isNegative1;
  boolean_T isNegative2;
  isNegative1 = ((u1[n1 - 1] & 2147483648U) != 0U);
  isNegative2 = ((u2[n2 - 1] & 2147483648U) != 0U);
  cb1 = 1U;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    cb2 = 1U;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1U;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

/* Model step function */
void position_control_PD_with_Due_step(void)
{
  {
    codertarget_arduinobase_int_i_T *obj;
    int64m_T tmp;
    real_T lastTime;
    real_T rtb_Derivative;
    real_T rtb_Gain1;
    real_T *lastU;
    int32_T rtb_dir;
    uint32_T tmp_0;
    uint32_T tmp_1;

    /* MATLABSystem: '<S1>/Encoder' */
    if (position_control_PD_with_Due_DW.obj.SampleTime !=
        position_control_PD_with_Due_P.Encoder_SampleTime) {
      position_control_PD_with_Due_DW.obj.SampleTime =
        position_control_PD_with_Due_P.Encoder_SampleTime;
    }

    if (position_control_PD_with_Due_DW.obj.TunablePropsChanged) {
      position_control_PD_with_Due_DW.obj.TunablePropsChanged = false;
    }

    MW_EncoderRead(position_control_PD_with_Due_DW.obj.Index, &rtb_dir);

    /* Gain: '<S1>/Gain' incorporates:
     *  MATLABSystem: '<S1>/Encoder'
     */
    tmp_0 = (uint32_T)position_control_PD_with_Due_P.Gain_Gain;
    tmp_1 = (uint32_T)rtb_dir;
    sMultiWordMul(&tmp_0, 1, &tmp_1, 1, &tmp.chunks[0U], 2);

    /* Gain: '<Root>/Gain2' incorporates:
     *  Constant: '<Root>/Constant3'
     *  Sum: '<Root>/Sum1'
     */
    position_control_PD_with_Due_B.Gain2 =
      position_control_PD_with_Due_P.Constant3_Value - sMultiWord2Double
      (&tmp.chunks[0U], 2, 0) * 1.862645149230957E-9;

    /* Gain: '<Root>/Gain1' */
    rtb_Gain1 = position_control_PD_with_Due_P.kp2 *
      position_control_PD_with_Due_B.Gain2;

    /* Gain: '<Root>/Gain2' */
    position_control_PD_with_Due_B.Gain2 *= position_control_PD_with_Due_P.kd2;

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

    /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
     *  Sum: '<Root>/Add'
     */
    rtb_Gain1 = (rtb_Gain1 + rtb_Derivative) * 254.0 / 22.9;
    if (rtb_Gain1 > 0.0) {
      rtb_dir = 0;
    } else if (rtb_Gain1 < 0.0) {
      rtb_Gain1 = fabs(rtb_Gain1);
      rtb_dir = 1;
    } else {
      rtb_Gain1 = 0.0;
      rtb_dir = 0;
    }

    /* End of MATLAB Function: '<S1>/MATLAB Function2' */

    /* MATLABSystem: '<S1>/Digital Output' */
    writeDigitalPin(7, (uint8_T)rtb_dir);

    /* MATLABSystem: '<S1>/PWM' */
    obj = &position_control_PD_with_Due_DW.obj_i;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
    if (!(rtb_Gain1 <= 255.0)) {
      rtb_Gain1 = 255.0;
    }

    MW_PWM_SetDutyCycle
      (position_control_PD_with_Due_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE,
       rtb_Gain1);

    /* End of MATLABSystem: '<S1>/PWM' */
  }

  {
    real_T *lastU;

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
  position_control_PD_with_Due_M->Timing.stepSize0 = 0.01;

  {
    codertarget_arduinobase_int_i_T *obj;

    /* InitializeConditions for Derivative: '<Root>/Derivative' */
    position_control_PD_with_Due_DW.TimeStampA = (rtInf);
    position_control_PD_with_Due_DW.TimeStampB = (rtInf);

    /* Start for MATLABSystem: '<S1>/Encoder' */
    position_control_PD_with_Due_DW.obj.Index = 0U;
    position_control_PD_with_Due_DW.obj.matlabCodegenIsDeleted = false;
    position_control_PD_with_Due_DW.obj.SampleTime =
      position_control_PD_with_Due_P.Encoder_SampleTime;
    position_control_PD_with_Due_DW.obj.isSetupComplete = false;
    position_control_PD_with_Due_DW.obj.isInitialized = 1;
    MW_EncoderSetup(2U, 3U, &position_control_PD_with_Due_DW.obj.Index);
    position_control_PD_with_Due_DW.obj.isSetupComplete = true;
    position_control_PD_with_Due_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S1>/Encoder' */
    MW_EncoderReset(position_control_PD_with_Due_DW.obj.Index);

    /* Start for MATLABSystem: '<S1>/Digital Output' */
    position_control_PD_with_Due_DW.obj_j.matlabCodegenIsDeleted = false;
    position_control_PD_with_Due_DW.obj_j.isInitialized = 1;
    digitalIOSetup(7, 1);
    position_control_PD_with_Due_DW.obj_j.isSetupComplete = true;

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
  codertarget_arduinobase_int_i_T *obj;

  /* Terminate for MATLABSystem: '<S1>/Encoder' */
  if (!position_control_PD_with_Due_DW.obj.matlabCodegenIsDeleted) {
    position_control_PD_with_Due_DW.obj.matlabCodegenIsDeleted = true;
    if ((position_control_PD_with_Due_DW.obj.isInitialized == 1) &&
        position_control_PD_with_Due_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder' */

  /* Terminate for MATLABSystem: '<S1>/Digital Output' */
  if (!position_control_PD_with_Due_DW.obj_j.matlabCodegenIsDeleted) {
    position_control_PD_with_Due_DW.obj_j.matlabCodegenIsDeleted = true;
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
