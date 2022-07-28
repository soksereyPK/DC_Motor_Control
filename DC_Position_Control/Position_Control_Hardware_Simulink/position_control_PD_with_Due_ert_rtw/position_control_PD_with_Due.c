/*
 * File: position_control_PD_with_Due.c
 *
 * Code generated for Simulink model 'position_control_PD_with_Due'.
 *
 * Model version                  : 2.26
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Jul 28 12:14:00 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
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
void sMultiWord2sMultiWordSat(const uint32_T u1[], int16_T n1, uint32_T y[],
  int16_T n)
{
  uint32_T ys;
  int16_T i;
  int16_T nm1;
  boolean_T doSaturation = false;
  nm1 = n - 1;
  ys = (u1[n1 - 1] & 2147483648UL) != 0UL ? MAX_uint32_T : 0UL;
  if (n1 > n) {
    doSaturation = (((u1[n1 - 1] ^ u1[n - 1]) & 2147483648UL) != 0UL);
    i = n1 - 1;
    while ((!doSaturation) && (i >= n)) {
      doSaturation = (u1[i] != ys);
      i--;
    }
  }

  if (doSaturation) {
    ys = ~ys;
    for (i = 0; i < nm1; i++) {
      y[i] = ys;
    }

    y[i] = ys ^ 2147483648UL;
  } else {
    nm1 = n1 < n ? n1 : n;
    for (i = 0; i < nm1; i++) {
      y[i] = u1[i];
    }

    while (i < n) {
      y[i] = ys;
      i++;
    }
  }
}

void sMultiWordShr(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T y[],
                   int16_T n)
{
  uint32_T u1i;
  uint32_T yi;
  uint32_T ys;
  int16_T i;
  int16_T i1;
  int16_T nb;
  int16_T nc;
  uint16_T nr;
  nb = (int16_T)(n2 >> 5);
  i = 0;
  ys = (u1[n1 - 1] & 2147483648UL) != 0UL ? MAX_uint32_T : 0UL;
  if (nb < n1) {
    nc = n + nb;
    if (nc > n1) {
      nc = n1;
    }

    nr = n2 - ((uint16_T)nb << 5);
    if (nr > 0U) {
      u1i = u1[nb];
      for (i1 = nb + 1; i1 < nc; i1++) {
        yi = u1i >> nr;
        u1i = u1[i1];
        y[i] = u1i << (32U - nr) | yi;
        i++;
      }

      y[i] = (nc < n1 ? u1[nc] : ys) << (32U - nr) | u1i >> nr;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

void sMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T
                   n2, uint32_T y[], int16_T n)
{
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
  int16_T i;
  int16_T j;
  int16_T k;
  int16_T ni;
  boolean_T isNegative1;
  boolean_T isNegative2;
  isNegative1 = ((u1[n1 - 1] & 2147483648UL) != 0UL);
  isNegative2 = ((u2[n2 - 1] & 2147483648UL) != 0UL);
  cb1 = 1UL;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0UL;
  }

  for (i = 0; i < n1; i++) {
    cb = 0UL;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535UL;
    cb2 = 1UL;
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
      u1i &= 65535UL;
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
    cb = 1UL;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

real_T sMultiWord2Double(const uint32_T u1[], int16_T n1, int16_T e1)
{
  real_T y;
  uint32_T cb;
  uint32_T u1i;
  int16_T exp_0;
  int16_T i;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648UL) != 0UL) {
    cb = 1UL;
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

/* Model step function */
void position_control_PD_with_Due_step(void)
{
  {
    codertarget_arduinobase_int_i_T *obj;
    int64m_T tmp;
    real_T lastTime;
    real_T rtb_Derivative6;
    real_T rtb_Sum4;
    real_T *lastU;
    int32_T rtb_Encoder_0;
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

    MW_EncoderRead(position_control_PD_with_Due_DW.obj.Index, &rtb_Encoder_0);

    /* Gain: '<S3>/Gain' */
    position_control_PD_with_Due_B.Gain =
      position_control_PD_with_Due_P.Gain_Gain;

    /* Gain: '<S1>/Gain' incorporates:
     *  MATLABSystem: '<S1>/Encoder'
     */
    tmp_0 = (uint32_T)position_control_PD_with_Due_P.Gain_Gain_j;
    tmp_1 = (uint32_T)rtb_Encoder_0;
    sMultiWordMul(&tmp_0, 1, &tmp_1, 1, &tmp.chunks[0U], 2);

    /* Gain: '<S3>/Gain' */
    sMultiWordMul(&position_control_PD_with_Due_P.Gain_Gain.chunks[0U], 2,
                  &tmp.chunks[0U], 2, &position_control_PD_with_Due_B.r1.chunks
                  [0U], 4);
    sMultiWordShr(&position_control_PD_with_Due_B.r1.chunks[0U], 4, 37U,
                  &position_control_PD_with_Due_B.r.chunks[0U], 4);
    sMultiWord2sMultiWordSat(&position_control_PD_with_Due_B.r.chunks[0U], 4,
      &position_control_PD_with_Due_B.Gain.chunks[0U], 2);

    /* Sum: '<Root>/Sum4' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Gain: '<S3>/Gain'
     */
    rtb_Sum4 = position_control_PD_with_Due_P.Constant2_Value -
      sMultiWord2Double(&position_control_PD_with_Due_B.Gain.chunks[0U], 2, 0) *
      7.2759576141834259E-12;

    /* Gain: '<Root>/Gain10' */
    position_control_PD_with_Due_B.Gain10 = position_control_PD_with_Due_P.kd2 *
      rtb_Sum4;

    /* Derivative: '<Root>/Derivative6' */
    rtb_Derivative6 = position_control_PD_with_Due_M->Timing.t[0];
    if ((position_control_PD_with_Due_DW.TimeStampA >= rtb_Derivative6) &&
        (position_control_PD_with_Due_DW.TimeStampB >= rtb_Derivative6)) {
      rtb_Derivative6 = 0.0;
    } else {
      lastTime = position_control_PD_with_Due_DW.TimeStampA;
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeA;
      if (position_control_PD_with_Due_DW.TimeStampA <
          position_control_PD_with_Due_DW.TimeStampB) {
        if (position_control_PD_with_Due_DW.TimeStampB < rtb_Derivative6) {
          lastTime = position_control_PD_with_Due_DW.TimeStampB;
          lastU = &position_control_PD_with_Due_DW.LastUAtTimeB;
        }
      } else if (position_control_PD_with_Due_DW.TimeStampA >= rtb_Derivative6)
      {
        lastTime = position_control_PD_with_Due_DW.TimeStampB;
        lastU = &position_control_PD_with_Due_DW.LastUAtTimeB;
      }

      rtb_Derivative6 = (position_control_PD_with_Due_B.Gain10 - *lastU) /
        (rtb_Derivative6 - lastTime);
    }

    /* End of Derivative: '<Root>/Derivative6' */

    /* Sum: '<Root>/Add3' incorporates:
     *  Gain: '<Root>/Gain5'
     */
    position_control_PD_with_Due_B.Add3 = position_control_PD_with_Due_P.kp2 *
      rtb_Sum4 + rtb_Derivative6;

    /* MATLAB Function: '<S1>/MATLAB Function2' */
    rtb_Sum4 = position_control_PD_with_Due_B.Add3 * 254.0 / 22.9;
    if (rtb_Sum4 > 0.0) {
      rtb_Derivative6 = 0.0;
    } else if (rtb_Sum4 < 0.0) {
      rtb_Derivative6 = fabs(rtb_Sum4);
      rtb_Sum4 = 0.0;
    } else {
      rtb_Derivative6 = 0.0;
      rtb_Sum4 = 0.0;
    }

    /* End of MATLAB Function: '<S1>/MATLAB Function2' */

    /* MATLABSystem: '<S1>/PWM' */
    obj = &position_control_PD_with_Due_DW.obj_f;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
    if (!(rtb_Derivative6 <= 255.0)) {
      rtb_Derivative6 = 255.0;
    }

    MW_PWM_SetDutyCycle
      (position_control_PD_with_Due_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE,
       rtb_Derivative6);

    /* End of MATLABSystem: '<S1>/PWM' */

    /* MATLABSystem: '<S1>/PWM1' */
    obj = &position_control_PD_with_Due_DW.obj_k;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
    if (!(rtb_Sum4 <= 255.0)) {
      rtb_Sum4 = 255.0;
    }

    MW_PWM_SetDutyCycle
      (position_control_PD_with_Due_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE,
       rtb_Sum4);

    /* End of MATLABSystem: '<S1>/PWM1' */
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative6' */
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

    *lastU = position_control_PD_with_Due_B.Gain10;

    /* End of Update for Derivative: '<Root>/Derivative6' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((position_control_PD_with_Due_M->Timing.clockTick0 * 1) + 0)
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
      ((position_control_PD_with_Due_M->Timing.clockTick1 * 1) + 0)
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
  rtmSetTFinal(position_control_PD_with_Due_M, -1);
  position_control_PD_with_Due_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  position_control_PD_with_Due_M->Sizes.checksums[0] = (1569711913U);
  position_control_PD_with_Due_M->Sizes.checksums[1] = (2584086993U);
  position_control_PD_with_Due_M->Sizes.checksums[2] = (3772120990U);
  position_control_PD_with_Due_M->Sizes.checksums[3] = (848670986U);

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
    codertarget_arduinobase_int_i_T *obj;

    /* InitializeConditions for Derivative: '<Root>/Derivative6' */
    position_control_PD_with_Due_DW.TimeStampA = (rtInf);
    position_control_PD_with_Due_DW.TimeStampB = (rtInf);

    /* Start for MATLABSystem: '<S1>/Encoder' */
    position_control_PD_with_Due_DW.obj.Index = 0U;
    position_control_PD_with_Due_DW.obj.matlabCodegenIsDeleted = false;
    position_control_PD_with_Due_DW.obj.SampleTime =
      position_control_PD_with_Due_P.Encoder_SampleTime;
    position_control_PD_with_Due_DW.obj.isSetupComplete = false;
    position_control_PD_with_Due_DW.obj.isInitialized = 1L;
    MW_EncoderSetup(2UL, 3UL, &position_control_PD_with_Due_DW.obj.Index);
    position_control_PD_with_Due_DW.obj.isSetupComplete = true;
    position_control_PD_with_Due_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S1>/Encoder' */
    MW_EncoderReset(position_control_PD_with_Due_DW.obj.Index);

    /* Start for MATLABSystem: '<S1>/PWM' */
    position_control_PD_with_Due_DW.obj_f.matlabCodegenIsDeleted = true;
    position_control_PD_with_Due_DW.obj_f.isInitialized = 0L;
    position_control_PD_with_Due_DW.obj_f.matlabCodegenIsDeleted = false;
    obj = &position_control_PD_with_Due_DW.obj_f;
    position_control_PD_with_Due_DW.obj_f.isSetupComplete = false;
    position_control_PD_with_Due_DW.obj_f.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
    position_control_PD_with_Due_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM1' */
    position_control_PD_with_Due_DW.obj_k.matlabCodegenIsDeleted = true;
    position_control_PD_with_Due_DW.obj_k.isInitialized = 0L;
    position_control_PD_with_Due_DW.obj_k.matlabCodegenIsDeleted = false;
    obj = &position_control_PD_with_Due_DW.obj_k;
    position_control_PD_with_Due_DW.obj_k.isSetupComplete = false;
    position_control_PD_with_Due_DW.obj_k.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0, 0.0);
    position_control_PD_with_Due_DW.obj_k.isSetupComplete = true;
  }
}

/* Model terminate function */
void position_control_PD_with_Due_terminate(void)
{
  codertarget_arduinobase_int_i_T *obj;

  /* Terminate for MATLABSystem: '<S1>/Encoder' */
  if (!position_control_PD_with_Due_DW.obj.matlabCodegenIsDeleted) {
    position_control_PD_with_Due_DW.obj.matlabCodegenIsDeleted = true;
    if ((position_control_PD_with_Due_DW.obj.isInitialized == 1L) &&
        position_control_PD_with_Due_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder' */
  /* Terminate for MATLABSystem: '<S1>/PWM' */
  obj = &position_control_PD_with_Due_DW.obj_f;
  if (!position_control_PD_with_Due_DW.obj_f.matlabCodegenIsDeleted) {
    position_control_PD_with_Due_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((position_control_PD_with_Due_DW.obj_f.isInitialized == 1L) &&
        position_control_PD_with_Due_DW.obj_f.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle
        (position_control_PD_with_Due_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close
        (position_control_PD_with_Due_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM' */

  /* Terminate for MATLABSystem: '<S1>/PWM1' */
  obj = &position_control_PD_with_Due_DW.obj_k;
  if (!position_control_PD_with_Due_DW.obj_k.matlabCodegenIsDeleted) {
    position_control_PD_with_Due_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((position_control_PD_with_Due_DW.obj_k.isInitialized == 1L) &&
        position_control_PD_with_Due_DW.obj_k.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle
        (position_control_PD_with_Due_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_Close
        (position_control_PD_with_Due_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
