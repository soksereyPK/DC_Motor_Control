/*
 * File: Position_Control_Single_Loop.c
 *
 * Code generated for Simulink model 'Position_Control_Single_Loop'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Jun 24 10:33:56 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Position_Control_Single_Loop.h"
#include "rtwtypes.h"
#include <math.h>
#include "Position_Control_Single_Loop_types.h"
#include "rt_nonfinite.h"
#include "Position_Control_Single_Loop_private.h"

/* Block signals (default storage) */
B_Position_Control_Single_Loo_T Position_Control_Single_Loop_B;

/* Block states (default storage) */
DW_Position_Control_Single_Lo_T Position_Control_Single_Loop_DW;

/* Real-time model */
static RT_MODEL_Position_Control_Sin_T Position_Control_Single_Loop_M_;
RT_MODEL_Position_Control_Sin_T *const Position_Control_Single_Loop_M =
  &Position_Control_Single_Loop_M_;
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

/* Model step function */
void Position_Control_Single_Loop_step(void)
{
  {
    codertarget_arduinobase_int_b_T *obj;
    real_T pwm_cal;
    real_T rtb_Derivative2;
    real_T rtb_Gain8;
    real_T rtb_Gain9;
    real_T *lastU;
    int32_T rtb_Encoder_0;
    uint32_T tmp;
    uint32_T tmp_0;

    /* Constant: '<Root>/Constant7' */
    Position_Control_Single_Loop_B.Constant7 =
      Position_Control_Single_Loop_P.Constant7_Value;

    /* ManualSwitch: '<Root>/Manual Switch1' */
    if (Position_Control_Single_Loop_P.ManualSwitch1_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
       *  Constant: '<Root>/Constant5'
       */
      Position_Control_Single_Loop_B.ManualSwitch1 =
        Position_Control_Single_Loop_P.Constant5_Value;
    } else {
      /* ManualSwitch: '<Root>/Manual Switch1' */
      Position_Control_Single_Loop_B.ManualSwitch1 =
        Position_Control_Single_Loop_B.Constant7;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch1' */

    /* MATLABSystem: '<S1>/Encoder' */
    if (Position_Control_Single_Loop_DW.obj.SampleTime !=
        Position_Control_Single_Loop_P.Encoder_SampleTime) {
      Position_Control_Single_Loop_DW.obj.SampleTime =
        Position_Control_Single_Loop_P.Encoder_SampleTime;
    }

    if (Position_Control_Single_Loop_DW.obj.TunablePropsChanged) {
      Position_Control_Single_Loop_DW.obj.TunablePropsChanged = false;
    }

    MW_EncoderRead(Position_Control_Single_Loop_DW.obj.Index, &rtb_Encoder_0);

    /* Gain: '<S1>/Gain' incorporates:
     *  MATLABSystem: '<S1>/Encoder'
     */
    tmp = (uint32_T)Position_Control_Single_Loop_P.Gain_Gain;
    tmp_0 = (uint32_T)rtb_Encoder_0;
    sMultiWordMul(&tmp, 1, &tmp_0, 1,
                  &Position_Control_Single_Loop_B.J6_Response.chunks[0U], 2);

    /* Sum: '<Root>/Sum3' incorporates:
     *  Gain: '<S1>/Gain'
     */
    Position_Control_Single_Loop_B.Sum3 =
      Position_Control_Single_Loop_B.ManualSwitch1 - sMultiWord2Double
      (&Position_Control_Single_Loop_B.J6_Response.chunks[0U], 2, 0) *
      4.5474735088646412E-13;

    /* Derivative: '<Root>/Derivative4' incorporates:
     *  Derivative: '<Root>/Derivative2'
     *  Derivative: '<Root>/Derivative3'
     *  Derivative: '<Root>/Derivative5'
     */
    pwm_cal = Position_Control_Single_Loop_M->Timing.t[0];
    if ((Position_Control_Single_Loop_DW.TimeStampA >= pwm_cal) &&
        (Position_Control_Single_Loop_DW.TimeStampB >= pwm_cal)) {
      /* Derivative: '<Root>/Derivative4' */
      Position_Control_Single_Loop_B.Derivative4 = 0.0;
    } else {
      rtb_Derivative2 = Position_Control_Single_Loop_DW.TimeStampA;
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA;
      if (Position_Control_Single_Loop_DW.TimeStampA <
          Position_Control_Single_Loop_DW.TimeStampB) {
        if (Position_Control_Single_Loop_DW.TimeStampB < pwm_cal) {
          rtb_Derivative2 = Position_Control_Single_Loop_DW.TimeStampB;
          lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB;
        }
      } else if (Position_Control_Single_Loop_DW.TimeStampA >= pwm_cal) {
        rtb_Derivative2 = Position_Control_Single_Loop_DW.TimeStampB;
        lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/Derivative4' */
      Position_Control_Single_Loop_B.Derivative4 =
        (Position_Control_Single_Loop_B.ManualSwitch1 - *lastU) / (pwm_cal -
        rtb_Derivative2);
    }

    /* End of Derivative: '<Root>/Derivative4' */

    /* Derivative: '<Root>/Derivative5' */
    if ((Position_Control_Single_Loop_DW.TimeStampA_b >= pwm_cal) &&
        (Position_Control_Single_Loop_DW.TimeStampB_e >= pwm_cal)) {
      rtb_Derivative2 = 0.0;
    } else {
      rtb_Derivative2 = Position_Control_Single_Loop_DW.TimeStampA_b;
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA_c;
      if (Position_Control_Single_Loop_DW.TimeStampA_b <
          Position_Control_Single_Loop_DW.TimeStampB_e) {
        if (Position_Control_Single_Loop_DW.TimeStampB_e < pwm_cal) {
          rtb_Derivative2 = Position_Control_Single_Loop_DW.TimeStampB_e;
          lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_e;
        }
      } else if (Position_Control_Single_Loop_DW.TimeStampA_b >= pwm_cal) {
        rtb_Derivative2 = Position_Control_Single_Loop_DW.TimeStampB_e;
        lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_e;
      }

      rtb_Derivative2 = (Position_Control_Single_Loop_B.Derivative4 - *lastU) /
        (pwm_cal - rtb_Derivative2);
    }

    /* Gain: '<Root>/Gain9' */
    rtb_Gain9 = 1.0 / Position_Control_Single_Loop_P.b * rtb_Derivative2;

    /* Derivative: '<Root>/Derivative3' */
    if ((Position_Control_Single_Loop_DW.TimeStampA_i >= pwm_cal) &&
        (Position_Control_Single_Loop_DW.TimeStampB_a >= pwm_cal)) {
      rtb_Derivative2 = 0.0;
    } else {
      rtb_Derivative2 = Position_Control_Single_Loop_DW.TimeStampA_i;
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA_f;
      if (Position_Control_Single_Loop_DW.TimeStampA_i <
          Position_Control_Single_Loop_DW.TimeStampB_a) {
        if (Position_Control_Single_Loop_DW.TimeStampB_a < pwm_cal) {
          rtb_Derivative2 = Position_Control_Single_Loop_DW.TimeStampB_a;
          lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_d;
        }
      } else if (Position_Control_Single_Loop_DW.TimeStampA_i >= pwm_cal) {
        rtb_Derivative2 = Position_Control_Single_Loop_DW.TimeStampB_a;
        lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_d;
      }

      rtb_Derivative2 = (Position_Control_Single_Loop_B.ManualSwitch1 - *lastU) /
        (pwm_cal - rtb_Derivative2);
    }

    /* Gain: '<Root>/Gain8' */
    rtb_Gain8 = Position_Control_Single_Loop_P.a /
      Position_Control_Single_Loop_P.b * rtb_Derivative2;

    /* Gain: '<Root>/Gain7' */
    Position_Control_Single_Loop_B.Gain7 = Position_Control_Single_Loop_P.kd4 *
      Position_Control_Single_Loop_B.Sum3;

    /* Derivative: '<Root>/Derivative2' */
    if ((Position_Control_Single_Loop_DW.TimeStampA_in >= pwm_cal) &&
        (Position_Control_Single_Loop_DW.TimeStampB_c >= pwm_cal)) {
      rtb_Derivative2 = 0.0;
    } else {
      rtb_Derivative2 = Position_Control_Single_Loop_DW.TimeStampA_in;
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA_cj;
      if (Position_Control_Single_Loop_DW.TimeStampA_in <
          Position_Control_Single_Loop_DW.TimeStampB_c) {
        if (Position_Control_Single_Loop_DW.TimeStampB_c < pwm_cal) {
          rtb_Derivative2 = Position_Control_Single_Loop_DW.TimeStampB_c;
          lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_b;
        }
      } else if (Position_Control_Single_Loop_DW.TimeStampA_in >= pwm_cal) {
        rtb_Derivative2 = Position_Control_Single_Loop_DW.TimeStampB_c;
        lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_b;
      }

      rtb_Derivative2 = (Position_Control_Single_Loop_B.Gain7 - *lastU) /
        (pwm_cal - rtb_Derivative2);
    }

    /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
     *  Gain: '<Root>/Gain6'
     *  Sum: '<Root>/Add2'
     */
    pwm_cal = (((rtb_Gain9 + rtb_Gain8) + Position_Control_Single_Loop_P.kp4 *
                Position_Control_Single_Loop_B.Sum3) + rtb_Derivative2) * 254.0 /
      22.9;
    if (pwm_cal > 0.0) {
      rtb_Gain9 = 0.0;
    } else if (pwm_cal < 0.0) {
      rtb_Gain9 = fabs(pwm_cal);
      pwm_cal = 0.0;
    } else {
      rtb_Gain9 = 0.0;
      pwm_cal = 0.0;
    }

    /* End of MATLAB Function: '<S1>/MATLAB Function1' */

    /* MATLABSystem: '<S1>/PWM1' */
    obj = &Position_Control_Single_Loop_DW.obj_b;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
    if (!(rtb_Gain9 <= 255.0)) {
      rtb_Gain9 = 255.0;
    }

    MW_PWM_SetDutyCycle
      (Position_Control_Single_Loop_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
       rtb_Gain9);

    /* End of MATLABSystem: '<S1>/PWM1' */

    /* MATLABSystem: '<S1>/PWM2' */
    obj = &Position_Control_Single_Loop_DW.obj_o;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7U);
    if (!(pwm_cal <= 255.0)) {
      pwm_cal = 255.0;
    }

    MW_PWM_SetDutyCycle
      (Position_Control_Single_Loop_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE, pwm_cal);

    /* End of MATLABSystem: '<S1>/PWM2' */
    /* Constant: '<S1>/J6_Desire' */
    Position_Control_Single_Loop_B.J6_Desire =
      Position_Control_Single_Loop_P.J6_Desire_Value;
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative4' */
    if (Position_Control_Single_Loop_DW.TimeStampA == (rtInf)) {
      Position_Control_Single_Loop_DW.TimeStampA =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA;
    } else if (Position_Control_Single_Loop_DW.TimeStampB == (rtInf)) {
      Position_Control_Single_Loop_DW.TimeStampB =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB;
    } else if (Position_Control_Single_Loop_DW.TimeStampA <
               Position_Control_Single_Loop_DW.TimeStampB) {
      Position_Control_Single_Loop_DW.TimeStampA =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA;
    } else {
      Position_Control_Single_Loop_DW.TimeStampB =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB;
    }

    *lastU = Position_Control_Single_Loop_B.ManualSwitch1;

    /* End of Update for Derivative: '<Root>/Derivative4' */

    /* Update for Derivative: '<Root>/Derivative5' */
    if (Position_Control_Single_Loop_DW.TimeStampA_b == (rtInf)) {
      Position_Control_Single_Loop_DW.TimeStampA_b =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA_c;
    } else if (Position_Control_Single_Loop_DW.TimeStampB_e == (rtInf)) {
      Position_Control_Single_Loop_DW.TimeStampB_e =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_e;
    } else if (Position_Control_Single_Loop_DW.TimeStampA_b <
               Position_Control_Single_Loop_DW.TimeStampB_e) {
      Position_Control_Single_Loop_DW.TimeStampA_b =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA_c;
    } else {
      Position_Control_Single_Loop_DW.TimeStampB_e =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_e;
    }

    *lastU = Position_Control_Single_Loop_B.Derivative4;

    /* End of Update for Derivative: '<Root>/Derivative5' */

    /* Update for Derivative: '<Root>/Derivative3' */
    if (Position_Control_Single_Loop_DW.TimeStampA_i == (rtInf)) {
      Position_Control_Single_Loop_DW.TimeStampA_i =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA_f;
    } else if (Position_Control_Single_Loop_DW.TimeStampB_a == (rtInf)) {
      Position_Control_Single_Loop_DW.TimeStampB_a =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_d;
    } else if (Position_Control_Single_Loop_DW.TimeStampA_i <
               Position_Control_Single_Loop_DW.TimeStampB_a) {
      Position_Control_Single_Loop_DW.TimeStampA_i =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA_f;
    } else {
      Position_Control_Single_Loop_DW.TimeStampB_a =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_d;
    }

    *lastU = Position_Control_Single_Loop_B.ManualSwitch1;

    /* End of Update for Derivative: '<Root>/Derivative3' */

    /* Update for Derivative: '<Root>/Derivative2' */
    if (Position_Control_Single_Loop_DW.TimeStampA_in == (rtInf)) {
      Position_Control_Single_Loop_DW.TimeStampA_in =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA_cj;
    } else if (Position_Control_Single_Loop_DW.TimeStampB_c == (rtInf)) {
      Position_Control_Single_Loop_DW.TimeStampB_c =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_b;
    } else if (Position_Control_Single_Loop_DW.TimeStampA_in <
               Position_Control_Single_Loop_DW.TimeStampB_c) {
      Position_Control_Single_Loop_DW.TimeStampA_in =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeA_cj;
    } else {
      Position_Control_Single_Loop_DW.TimeStampB_c =
        Position_Control_Single_Loop_M->Timing.t[0];
      lastU = &Position_Control_Single_Loop_DW.LastUAtTimeB_b;
    }

    *lastU = Position_Control_Single_Loop_B.Gain7;

    /* End of Update for Derivative: '<Root>/Derivative2' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      Position_Control_Single_Loop_M->Timing.t[0];

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
      ((Position_Control_Single_Loop_M->Timing.clockTick1) * 0.01);

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
  Position_Control_Single_Loop_M->Timing.t[0] =
    ((time_T)(++Position_Control_Single_Loop_M->Timing.clockTick0)) *
    Position_Control_Single_Loop_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Position_Control_Single_Loop_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Position_Control_Single_Loop_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Position_Control_Single_Loop_M->solverInfo,
                          &Position_Control_Single_Loop_M->Timing.simTimeStep);
    rtsiSetTPtr(&Position_Control_Single_Loop_M->solverInfo, &rtmGetTPtr
                (Position_Control_Single_Loop_M));
    rtsiSetStepSizePtr(&Position_Control_Single_Loop_M->solverInfo,
                       &Position_Control_Single_Loop_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Position_Control_Single_Loop_M->solverInfo,
                          (&rtmGetErrorStatus(Position_Control_Single_Loop_M)));
    rtsiSetRTModelPtr(&Position_Control_Single_Loop_M->solverInfo,
                      Position_Control_Single_Loop_M);
  }

  rtsiSetSimTimeStep(&Position_Control_Single_Loop_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetSolverName(&Position_Control_Single_Loop_M->solverInfo,
                    "FixedStepDiscrete");
  rtmSetTPtr(Position_Control_Single_Loop_M,
             &Position_Control_Single_Loop_M->Timing.tArray[0]);
  rtmSetTFinal(Position_Control_Single_Loop_M, 10.0);
  Position_Control_Single_Loop_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Position_Control_Single_Loop_M->Sizes.checksums[0] = (1613854868U);
  Position_Control_Single_Loop_M->Sizes.checksums[1] = (2623184912U);
  Position_Control_Single_Loop_M->Sizes.checksums[2] = (4016207087U);
  Position_Control_Single_Loop_M->Sizes.checksums[3] = (3123172349U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    Position_Control_Single_Loop_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Position_Control_Single_Loop_M->extModeInfo,
      &Position_Control_Single_Loop_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Position_Control_Single_Loop_M->extModeInfo,
                        Position_Control_Single_Loop_M->Sizes.checksums);
    rteiSetTPtr(Position_Control_Single_Loop_M->extModeInfo, rtmGetTPtr
                (Position_Control_Single_Loop_M));
  }

  {
    codertarget_arduinobase_int_b_T *obj;

    /* InitializeConditions for Derivative: '<Root>/Derivative4' */
    Position_Control_Single_Loop_DW.TimeStampA = (rtInf);
    Position_Control_Single_Loop_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative5' */
    Position_Control_Single_Loop_DW.TimeStampA_b = (rtInf);
    Position_Control_Single_Loop_DW.TimeStampB_e = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative3' */
    Position_Control_Single_Loop_DW.TimeStampA_i = (rtInf);
    Position_Control_Single_Loop_DW.TimeStampB_a = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative2' */
    Position_Control_Single_Loop_DW.TimeStampA_in = (rtInf);
    Position_Control_Single_Loop_DW.TimeStampB_c = (rtInf);

    /* Start for MATLABSystem: '<S1>/Encoder' */
    Position_Control_Single_Loop_DW.obj.Index = 0U;
    Position_Control_Single_Loop_DW.obj.matlabCodegenIsDeleted = false;
    Position_Control_Single_Loop_DW.obj.SampleTime =
      Position_Control_Single_Loop_P.Encoder_SampleTime;
    Position_Control_Single_Loop_DW.obj.isSetupComplete = false;
    Position_Control_Single_Loop_DW.obj.isInitialized = 1;
    MW_EncoderSetup(2U, 3U, &Position_Control_Single_Loop_DW.obj.Index);
    Position_Control_Single_Loop_DW.obj.isSetupComplete = true;
    Position_Control_Single_Loop_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S1>/Encoder' */
    MW_EncoderReset(Position_Control_Single_Loop_DW.obj.Index);

    /* Start for MATLABSystem: '<S1>/PWM1' */
    Position_Control_Single_Loop_DW.obj_b.matlabCodegenIsDeleted = true;
    Position_Control_Single_Loop_DW.obj_b.isInitialized = 0;
    Position_Control_Single_Loop_DW.obj_b.matlabCodegenIsDeleted = false;
    obj = &Position_Control_Single_Loop_DW.obj_b;
    Position_Control_Single_Loop_DW.obj_b.isSetupComplete = false;
    Position_Control_Single_Loop_DW.obj_b.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6U, 0.0, 0.0);
    Position_Control_Single_Loop_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PWM2' */
    Position_Control_Single_Loop_DW.obj_o.matlabCodegenIsDeleted = true;
    Position_Control_Single_Loop_DW.obj_o.isInitialized = 0;
    Position_Control_Single_Loop_DW.obj_o.matlabCodegenIsDeleted = false;
    obj = &Position_Control_Single_Loop_DW.obj_o;
    Position_Control_Single_Loop_DW.obj_o.isSetupComplete = false;
    Position_Control_Single_Loop_DW.obj_o.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(7U, 0.0, 0.0);
    Position_Control_Single_Loop_DW.obj_o.isSetupComplete = true;
  }
}

/* Model terminate function */
void Position_Control_Single_Loop_terminate(void)
{
  codertarget_arduinobase_int_b_T *obj;

  /* Terminate for MATLABSystem: '<S1>/Encoder' */
  if (!Position_Control_Single_Loop_DW.obj.matlabCodegenIsDeleted) {
    Position_Control_Single_Loop_DW.obj.matlabCodegenIsDeleted = true;
    if ((Position_Control_Single_Loop_DW.obj.isInitialized == 1) &&
        Position_Control_Single_Loop_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder' */
  /* Terminate for MATLABSystem: '<S1>/PWM1' */
  obj = &Position_Control_Single_Loop_DW.obj_b;
  if (!Position_Control_Single_Loop_DW.obj_b.matlabCodegenIsDeleted) {
    Position_Control_Single_Loop_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Position_Control_Single_Loop_DW.obj_b.isInitialized == 1) &&
        Position_Control_Single_Loop_DW.obj_b.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
      MW_PWM_SetDutyCycle
        (Position_Control_Single_Loop_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6U);
      MW_PWM_Close
        (Position_Control_Single_Loop_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM1' */

  /* Terminate for MATLABSystem: '<S1>/PWM2' */
  obj = &Position_Control_Single_Loop_DW.obj_o;
  if (!Position_Control_Single_Loop_DW.obj_o.matlabCodegenIsDeleted) {
    Position_Control_Single_Loop_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Position_Control_Single_Loop_DW.obj_o.isInitialized == 1) &&
        Position_Control_Single_Loop_DW.obj_o.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7U);
      MW_PWM_SetDutyCycle
        (Position_Control_Single_Loop_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7U);
      MW_PWM_Close
        (Position_Control_Single_Loop_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
