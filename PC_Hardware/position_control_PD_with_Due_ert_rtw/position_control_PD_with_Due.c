/*
 * File: position_control_PD_with_Due.c
 *
 * Code generated for Simulink model 'position_control_PD_with_Due'.
 *
 * Model version                  : 2.13
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Jul 28 08:24:25 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "position_control_PD_with_Due.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "position_control_PD_with_Due_types.h"
#include "multiword_types.h"
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
    int128m_T tmp;
    int64m_T tmp_0;
    real_T rtb_Derivative7;
    real_T rtb_ManualSwitch;
    real_T *lastU;
    uint32_T tmp_1;
    uint32_T tmp_2;

    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/Constant'
     *  Sin: '<Root>/Sine Wave'
     */
    if (position_control_PD_with_Due_P.ManualSwitch_CurrentSetting == 1) {
      rtb_ManualSwitch = sin(2.0 * position_control_PD_with_Due_P.pi * 0.25 *
        position_control_PD_with_Due_M->Timing.t[0] +
        position_control_PD_with_Due_P.SineWave_Phase) * (2.0 *
        position_control_PD_with_Due_P.pi) +
        position_control_PD_with_Due_P.SineWave_Bias;
    } else {
      rtb_ManualSwitch = 2.0 * position_control_PD_with_Due_P.pi;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */

    /* MATLAB Function: '<Root>/MATLAB Function' */
    if (rtIsNaN(rtb_ManualSwitch)) {
      rtb_Derivative7 = rtb_ManualSwitch;
    } else if (rtb_ManualSwitch < 0.0) {
      rtb_Derivative7 = -1.0;
    } else {
      rtb_Derivative7 = (rtb_ManualSwitch > 0.0);
    }

    /* MATLABSystem: '<Root>/Digital Output' incorporates:
     *  DataTypeConversion: '<Root>/Cast To Boolean'
     *  MATLAB Function: '<Root>/MATLAB Function'
     */
    writeDigitalPin(6, (uint8_T)((rtb_Derivative7 + 1.0) / 2.0 != 0.0));

    /* MATLAB Function: '<Root>/MATLAB Function' */
    if (rtIsNaN(rtb_ManualSwitch)) {
      rtb_Derivative7 = rtb_ManualSwitch;
    } else if (rtb_ManualSwitch < 0.0) {
      rtb_Derivative7 = -1.0;
    } else {
      rtb_Derivative7 = (rtb_ManualSwitch > 0.0);
    }

    /* MATLABSystem: '<Root>/Digital Output1' incorporates:
     *  DataTypeConversion: '<Root>/Cast To Boolean'
     *  Logic: '<Root>/Logical Operator'
     *  MATLAB Function: '<Root>/MATLAB Function'
     */
    writeDigitalPin(7, (uint8_T)!((rtb_Derivative7 + 1.0) / 2.0 != 0.0));

    /* MATLABSystem: '<Root>/PWM' */
    obj = &position_control_PD_with_Due_DW.obj_n;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

    /* Abs: '<Root>/Abs' */
    rtb_Derivative7 = fabs(rtb_ManualSwitch);

    /* MATLABSystem: '<Root>/PWM' */
    if (!(rtb_Derivative7 <= 255.0)) {
      rtb_Derivative7 = 255.0;
    }

    MW_PWM_SetDutyCycle
      (position_control_PD_with_Due_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE,
       rtb_Derivative7);

    /* MATLABSystem: '<Root>/Encoder' */
    if (position_control_PD_with_Due_DW.obj.SampleTime !=
        position_control_PD_with_Due_P.Encoder_SampleTime) {
      position_control_PD_with_Due_DW.obj.SampleTime =
        position_control_PD_with_Due_P.Encoder_SampleTime;
    }

    if (position_control_PD_with_Due_DW.obj.TunablePropsChanged) {
      position_control_PD_with_Due_DW.obj.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<Root>/Encoder' */
    MW_EncoderRead(position_control_PD_with_Due_DW.obj.Index,
                   &position_control_PD_with_Due_B.Encoder);

    /* Gain: '<S1>/Gain1' */
    position_control_PD_with_Due_B.Gain1 =
      position_control_PD_with_Due_P.Gain1_Gain;

    /* Gain: '<Root>/Gain' */
    tmp_1 = (uint32_T)position_control_PD_with_Due_P.Gain_Gain;
    tmp_2 = (uint32_T)position_control_PD_with_Due_B.Encoder;
    sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_0.chunks[0U], 2);

    /* Gain: '<S1>/Gain1' */
    sMultiWordMul(&position_control_PD_with_Due_P.Gain1_Gain.chunks[0U], 2,
                  &tmp_0.chunks[0U], 2, &tmp.chunks[0U], 4);
    sMultiWordShr(&tmp.chunks[0U], 4, 32U,
                  &position_control_PD_with_Due_B.r.chunks[0U], 4);
    sMultiWord2sMultiWordSat(&position_control_PD_with_Due_B.r.chunks[0U], 4,
      &position_control_PD_with_Due_B.Gain1.chunks[0U], 2);

    /* Sum: '<Root>/Sum5' incorporates:
     *  Constant: '<Root>/Constant4'
     *  Gain: '<S1>/Gain1'
     */
    position_control_PD_with_Due_B.Sum5 = 2.0 *
      position_control_PD_with_Due_P.pi - sMultiWord2Double
      (&position_control_PD_with_Due_B.Gain1.chunks[0U], 2, 0) *
      2.3283064365386963E-10;

    /* Gain: '<Root>/Gain11' */
    position_control_PD_with_Due_B.Gain11 = position_control_PD_with_Due_P.kd2 *
      position_control_PD_with_Due_B.Sum5;

    /* Derivative: '<Root>/Derivative7' */
    rtb_Derivative7 = position_control_PD_with_Due_M->Timing.t[0];
    if ((position_control_PD_with_Due_DW.TimeStampA >= rtb_Derivative7) &&
        (position_control_PD_with_Due_DW.TimeStampB >= rtb_Derivative7)) {
      rtb_Derivative7 = 0.0;
    } else {
      rtb_ManualSwitch = position_control_PD_with_Due_DW.TimeStampA;
      lastU = &position_control_PD_with_Due_DW.LastUAtTimeA;
      if (position_control_PD_with_Due_DW.TimeStampA <
          position_control_PD_with_Due_DW.TimeStampB) {
        if (position_control_PD_with_Due_DW.TimeStampB < rtb_Derivative7) {
          rtb_ManualSwitch = position_control_PD_with_Due_DW.TimeStampB;
          lastU = &position_control_PD_with_Due_DW.LastUAtTimeB;
        }
      } else if (position_control_PD_with_Due_DW.TimeStampA >= rtb_Derivative7)
      {
        rtb_ManualSwitch = position_control_PD_with_Due_DW.TimeStampB;
        lastU = &position_control_PD_with_Due_DW.LastUAtTimeB;
      }

      rtb_Derivative7 = (position_control_PD_with_Due_B.Gain11 - *lastU) /
        (rtb_Derivative7 - rtb_ManualSwitch);
    }

    /* End of Derivative: '<Root>/Derivative7' */

    /* Sum: '<Root>/Add4' incorporates:
     *  Gain: '<Root>/Gain12'
     */
    position_control_PD_with_Due_B.Add4 = position_control_PD_with_Due_P.kp2 *
      position_control_PD_with_Due_B.Sum5 + rtb_Derivative7;
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative7' */
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

    *lastU = position_control_PD_with_Due_B.Gain11;

    /* End of Update for Derivative: '<Root>/Derivative7' */
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
  rtmSetTFinal(position_control_PD_with_Due_M, 6.0);
  position_control_PD_with_Due_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  position_control_PD_with_Due_M->Sizes.checksums[0] = (1385806593U);
  position_control_PD_with_Due_M->Sizes.checksums[1] = (1944012732U);
  position_control_PD_with_Due_M->Sizes.checksums[2] = (3536636926U);
  position_control_PD_with_Due_M->Sizes.checksums[3] = (2817918582U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    position_control_PD_with_Due_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(position_control_PD_with_Due_M->extModeInfo,
      &position_control_PD_with_Due_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(position_control_PD_with_Due_M->extModeInfo,
                        position_control_PD_with_Due_M->Sizes.checksums);
    rteiSetTPtr(position_control_PD_with_Due_M->extModeInfo, rtmGetTPtr
                (position_control_PD_with_Due_M));
  }

  {
    codertarget_arduinobase_int_i_T *obj;

    /* InitializeConditions for Derivative: '<Root>/Derivative7' */
    position_control_PD_with_Due_DW.TimeStampA = (rtInf);
    position_control_PD_with_Due_DW.TimeStampB = (rtInf);

    /* Start for MATLABSystem: '<Root>/Digital Output' */
    position_control_PD_with_Due_DW.obj_d.matlabCodegenIsDeleted = false;
    position_control_PD_with_Due_DW.obj_d.isInitialized = 1L;
    digitalIOSetup(6, 1);
    position_control_PD_with_Due_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output1' */
    position_control_PD_with_Due_DW.obj_f.matlabCodegenIsDeleted = false;
    position_control_PD_with_Due_DW.obj_f.isInitialized = 1L;
    digitalIOSetup(7, 1);
    position_control_PD_with_Due_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM' */
    position_control_PD_with_Due_DW.obj_n.matlabCodegenIsDeleted = true;
    position_control_PD_with_Due_DW.obj_n.isInitialized = 0L;
    position_control_PD_with_Due_DW.obj_n.matlabCodegenIsDeleted = false;
    obj = &position_control_PD_with_Due_DW.obj_n;
    position_control_PD_with_Due_DW.obj_n.isSetupComplete = false;
    position_control_PD_with_Due_DW.obj_n.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 0.0, 0.0);
    position_control_PD_with_Due_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Encoder' */
    position_control_PD_with_Due_DW.obj.Index = 0U;
    position_control_PD_with_Due_DW.obj.matlabCodegenIsDeleted = false;
    position_control_PD_with_Due_DW.obj.SampleTime =
      position_control_PD_with_Due_P.Encoder_SampleTime;
    position_control_PD_with_Due_DW.obj.isSetupComplete = false;
    position_control_PD_with_Due_DW.obj.isInitialized = 1L;
    MW_EncoderSetup(2UL, 3UL, &position_control_PD_with_Due_DW.obj.Index);
    position_control_PD_with_Due_DW.obj.isSetupComplete = true;
    position_control_PD_with_Due_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<Root>/Encoder' */
    MW_EncoderReset(position_control_PD_with_Due_DW.obj.Index);
  }
}

/* Model terminate function */
void position_control_PD_with_Due_terminate(void)
{
  codertarget_arduinobase_int_i_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!position_control_PD_with_Due_DW.obj_d.matlabCodegenIsDeleted) {
    position_control_PD_with_Due_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!position_control_PD_with_Due_DW.obj_f.matlabCodegenIsDeleted) {
    position_control_PD_with_Due_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  obj = &position_control_PD_with_Due_DW.obj_n;
  if (!position_control_PD_with_Due_DW.obj_n.matlabCodegenIsDeleted) {
    position_control_PD_with_Due_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((position_control_PD_with_Due_DW.obj_n.isInitialized == 1L) &&
        position_control_PD_with_Due_DW.obj_n.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle
        (position_control_PD_with_Due_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_Close
        (position_control_PD_with_Due_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */

  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!position_control_PD_with_Due_DW.obj.matlabCodegenIsDeleted) {
    position_control_PD_with_Due_DW.obj.matlabCodegenIsDeleted = true;
    if ((position_control_PD_with_Due_DW.obj.isInitialized == 1L) &&
        position_control_PD_with_Due_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
