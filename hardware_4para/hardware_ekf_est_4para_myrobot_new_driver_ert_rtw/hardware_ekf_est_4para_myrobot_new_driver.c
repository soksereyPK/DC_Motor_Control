/*
 * File: hardware_ekf_est_4para_myrobot_new_driver.c
 *
 * Code generated for Simulink model 'hardware_ekf_est_4para_myrobot_new_driver'.
 *
 * Model version                  : 3.17
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Jun 28 16:28:18 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "hardware_ekf_est_4para_myrobot_new_driver.h"
#include "hardware_ekf_est_4para_myrobot_new_driver_private.h"

/* Block signals (default storage) */
B_hardware_ekf_est_4para_myro_T hardware_ekf_est_4para_myrobo_B;

/* Block states (default storage) */
DW_hardware_ekf_est_4para_myr_T hardware_ekf_est_4para_myrob_DW;

/* Real-time model */
static RT_MODEL_hardware_ekf_est_4pa_T hardware_ekf_est_4para_myrob_M_;
RT_MODEL_hardware_ekf_est_4pa_T *const hardware_ekf_est_4para_myrob_M =
  &hardware_ekf_est_4para_myrob_M_;

/*
 * System initialize for atomic system:
 *    '<Root>/EKF2'
 *    '<Root>/EKF3'
 */
void hardware_ekf_est_4par_EKF2_Init(DW_EKF2_hardware_ekf_est_4par_T *localDW)
{
  static const real_T b[16] = { 0.0001, 0.0, 0.0, 0.0, 0.0, 0.00025, 0.0, 0.0,
    0.0, 0.0, 0.00025, 0.0, 0.0, 0.0, 0.0, 1.0E-5 };

  static const int8_T tmp[16] = { 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2
  };

  int32_T i;
  localDW->x_est_p[0] = 2.0;
  localDW->x_est_p[1] = 13.0;
  localDW->x_est_p[2] = 25.0;
  localDW->x_est_p[3] = 1.0;
  for (i = 0; i < 16; i++) {
    localDW->P[i] = tmp[i];
    localDW->Qd_est[i] = b[i] * 0.01;
  }

  localDW->R_est = 0.02;
}

/*
 * Output and update for atomic system:
 *    '<Root>/EKF2'
 *    '<Root>/EKF3'
 */
void hardware_ekf_est_4para_myr_EKF2(real_T rtu_uk, real_T rtu_y_true, real_T
  rty_x_est[4], B_EKF2_hardware_ekf_est_4para_T *localB,
  DW_EKF2_hardware_ekf_est_4par_T *localDW)
{
  real_T y_tmp_1;
  real_T y_tmp_2;
  int32_T Ak_tmp;
  int32_T Ak_tmp_tmp;
  int32_T i;
  int32_T y_tmp_tmp;
  int8_T b_I[16];
  int8_T y_tmp[4];
  int8_T y_tmp_0[4];
  int8_T y_tmp_3;
  y_tmp[0] = 1;
  y_tmp_0[0] = 1;
  y_tmp[1] = 0;
  y_tmp_0[1] = 0;
  y_tmp[2] = 0;
  y_tmp_0[2] = 0;
  y_tmp[3] = 0;
  y_tmp_0[3] = 0;
  y_tmp_1 = 0.0;
  for (i = 0; i < 4; i++) {
    y_tmp_tmp = i << 2;
    y_tmp_2 = localDW->P[y_tmp_tmp + 3] * 0.0 + (localDW->P[y_tmp_tmp + 2] * 0.0
      + (localDW->P[y_tmp_tmp + 1] * 0.0 + localDW->P[y_tmp_tmp]));
    y_tmp_1 += y_tmp_2 * (real_T)y_tmp[i];
  }

  y_tmp_2 = y_tmp_1 + localDW->R_est;
  y_tmp_1 = 0.0;
  for (i = 0; i < 4; i++) {
    localB->Wk[i] = (((localDW->P[i + 4] * 0.0 + localDW->P[i]) + localDW->P[i +
                      8] * 0.0) + localDW->P[i + 12] * 0.0) / y_tmp_2;
    y_tmp_1 += (real_T)y_tmp_0[i] * localDW->x_est_p[i];
  }

  y_tmp_1 = rtu_y_true - (0.0 * rtu_uk + y_tmp_1);
  for (i = 0; i < 4; i++) {
    y_tmp_3 = y_tmp_0[i];
    localDW->x_est_p[i] += localB->Wk[i] * y_tmp_1;
    y_tmp_tmp = i << 2;
    localB->Ak[y_tmp_tmp] = localB->Wk[0] * (real_T)y_tmp_3;
    localB->Ak[y_tmp_tmp + 1] = localB->Wk[1] * (real_T)y_tmp_3;
    localB->Ak[y_tmp_tmp + 2] = localB->Wk[2] * (real_T)y_tmp_3;
    localB->Ak[y_tmp_tmp + 3] = localB->Wk[3] * (real_T)y_tmp_3;
  }

  if (localDW->x_est_p[0] < 0.0) {
    y_tmp_1 = -1.0;
  } else if (localDW->x_est_p[0] > 0.0) {
    y_tmp_1 = 1.0;
  } else if (localDW->x_est_p[0] == 0.0) {
    y_tmp_1 = 0.0;
  } else {
    y_tmp_1 = (rtNaN);
  }

  rty_x_est[0] = ((-localDW->x_est_p[1] * localDW->x_est_p[0] + rtu_uk *
                   localDW->x_est_p[2]) - localDW->x_est_p[3] * y_tmp_1) * 0.01
    + localDW->x_est_p[0];
  rty_x_est[1] = localDW->x_est_p[1];
  rty_x_est[2] = localDW->x_est_p[2];
  rty_x_est[3] = localDW->x_est_p[3];
  for (i = 0; i < 4; i++) {
    for (y_tmp_tmp = 0; y_tmp_tmp < 4; y_tmp_tmp++) {
      Ak_tmp_tmp = i << 2;
      Ak_tmp = Ak_tmp_tmp + y_tmp_tmp;
      localB->Ak_m[Ak_tmp] = localDW->P[Ak_tmp] - (((localDW->P[Ak_tmp_tmp + 1] *
        localB->Ak[y_tmp_tmp + 4] + localDW->P[Ak_tmp_tmp] * localB->
        Ak[y_tmp_tmp]) + localDW->P[Ak_tmp_tmp + 2] * localB->Ak[y_tmp_tmp + 8])
        + localDW->P[Ak_tmp_tmp + 3] * localB->Ak[y_tmp_tmp + 12]);
    }
  }

  for (i = 0; i < 16; i++) {
    localDW->P[i] = localB->Ak_m[i];
    b_I[i] = 0;
  }

  localB->Ak[0] = 0.01 * -localDW->x_est_p[1] + 1.0;
  localB->Ak[1] = b_I[1];
  localB->Ak[2] = b_I[2];
  localB->Ak[3] = b_I[3];
  localB->Ak[4] = 0.01 * -localDW->x_est_p[0] + (real_T)b_I[4];
  localB->Ak[5] = 1.0;
  localB->Ak[6] = b_I[6];
  localB->Ak[7] = b_I[7];
  localB->Ak[8] = 0.01 * rtu_uk + (real_T)b_I[8];
  localB->Ak[9] = b_I[9];
  localB->Ak[10] = 1.0;
  localB->Ak[11] = b_I[11];
  if (localDW->x_est_p[0] < 0.0) {
    y_tmp_1 = -1.0;
  } else if (localDW->x_est_p[0] > 0.0) {
    y_tmp_1 = 1.0;
  } else if (localDW->x_est_p[0] == 0.0) {
    y_tmp_1 = 0.0;
  } else {
    y_tmp_1 = (rtNaN);
  }

  localB->Ak[12] = 0.01 * -y_tmp_1 + (real_T)b_I[12];
  localB->Ak[13] = b_I[13];
  localB->Ak[14] = b_I[14];
  localB->Ak[15] = 1.0;
  for (i = 0; i < 4; i++) {
    for (y_tmp_tmp = 0; y_tmp_tmp < 4; y_tmp_tmp++) {
      Ak_tmp_tmp = i << 2;
      Ak_tmp = y_tmp_tmp + Ak_tmp_tmp;
      localB->Ak_m[Ak_tmp] = 0.0;
      localB->Ak_m[Ak_tmp] += localDW->P[Ak_tmp_tmp] * localB->Ak[y_tmp_tmp];
      localB->Ak_m[Ak_tmp] += localDW->P[Ak_tmp_tmp + 1] * localB->Ak[y_tmp_tmp
        + 4];
      localB->Ak_m[Ak_tmp] += localDW->P[Ak_tmp_tmp + 2] * localB->Ak[y_tmp_tmp
        + 8];
      localB->Ak_m[Ak_tmp] += localDW->P[Ak_tmp_tmp + 3] * localB->Ak[y_tmp_tmp
        + 12];
    }
  }

  for (y_tmp_tmp = 0; y_tmp_tmp < 4; y_tmp_tmp++) {
    for (i = 0; i < 4; i++) {
      Ak_tmp_tmp = (i << 2) + y_tmp_tmp;
      localDW->P[Ak_tmp_tmp] = (((localB->Ak_m[y_tmp_tmp + 4] * localB->Ak[i + 4]
        + localB->Ak_m[y_tmp_tmp] * localB->Ak[i]) + localB->Ak_m[y_tmp_tmp + 8]
        * localB->Ak[i + 8]) + localB->Ak_m[y_tmp_tmp + 12] * localB->Ak[i + 12])
        + localDW->Qd_est[Ak_tmp_tmp];
    }

    localDW->x_est_p[y_tmp_tmp] = rty_x_est[y_tmp_tmp];
  }
}

/*
 * Output and update for atomic system:
 *    '<S3>/Convert pulse to rad2'
 *    '<S4>/Convert pulse to rad1'
 */
void hardware_ekf_Convertpulsetorad2(int32_T rtu_u, real_T rtu_ppr, real_T
  rtu_gearRatio, real_T *rty_outGearBox, DW_Convertpulsetorad2_hardwar_T
  *localDW)
{
  real_T tmp;
  tmp = (real_T)rtu_u - localDW->counter_num;
  if (tmp > 40000.0) {
    localDW->over_flag--;
  } else {
    if (tmp < -40000.0) {
      localDW->over_flag++;
    }
  }

  *rty_outGearBox = (localDW->over_flag * 4.294967295E+9 + (real_T)rtu_u) *
    (6.2831853071795862 / rtu_ppr) / rtu_gearRatio;
  localDW->counter_num = rtu_u;
}

/* Model step function */
void hardware_ekf_est_4para_myrobot_new_driver_step(void)
{
  {
    codertarget_arduinobase_inter_T *obj;
    real_T *lastU;

    /* UnitDelay: '<Root>/Unit Delay3' */
    hardware_ekf_est_4para_myrobo_B.UnitDelay3[0] =
      hardware_ekf_est_4para_myrob_DW.UnitDelay3_DSTATE[0];
    hardware_ekf_est_4para_myrobo_B.UnitDelay3[1] =
      hardware_ekf_est_4para_myrob_DW.UnitDelay3_DSTATE[1];
    hardware_ekf_est_4para_myrobo_B.UnitDelay3[2] =
      hardware_ekf_est_4para_myrob_DW.UnitDelay3_DSTATE[2];
    hardware_ekf_est_4para_myrobo_B.UnitDelay3[3] =
      hardware_ekf_est_4para_myrob_DW.UnitDelay3_DSTATE[3];

    /* UnitDelay: '<Root>/Unit Delay2' */
    hardware_ekf_est_4para_myrobo_B.UnitDelay2[0] =
      hardware_ekf_est_4para_myrob_DW.UnitDelay2_DSTATE[0];
    hardware_ekf_est_4para_myrobo_B.UnitDelay2[1] =
      hardware_ekf_est_4para_myrob_DW.UnitDelay2_DSTATE[1];
    hardware_ekf_est_4para_myrobo_B.UnitDelay2[2] =
      hardware_ekf_est_4para_myrob_DW.UnitDelay2_DSTATE[2];
    hardware_ekf_est_4para_myrobo_B.UnitDelay2[3] =
      hardware_ekf_est_4para_myrob_DW.UnitDelay2_DSTATE[3];

    /* S-Function (readEncDUEpin8_9): '<S4>/Encoder1' */
    readEncDUEpin8_9_Outputs_wrapper(&hardware_ekf_est_4para_myrobo_B.Encoder1,
      &hardware_ekf_est_4para_myrob_DW.Encoder1_DSTATE);

    /* MATLAB Function: '<S4>/Convert pulse to rad1' incorporates:
     *  Constant: '<S4>/gearRatio'
     *  Constant: '<S4>/totalPPR'
     */
    hardware_ekf_Convertpulsetorad2(hardware_ekf_est_4para_myrobo_B.Encoder1,
      hardware_ekf_est_4para_myrobo_P.totalPPR_Value,
      hardware_ekf_est_4para_myrobo_P.gearRatio_Value,
      &hardware_ekf_est_4para_myrobo_B.outGearBox,
      &hardware_ekf_est_4para_myrob_DW.sf_Convertpulsetorad1);

    /* Derivative: '<Root>/Derivative2' incorporates:
     *  Derivative: '<Root>/Derivative3'
     */
    hardware_ekf_est_4para_myrobo_B.Derivative3 =
      hardware_ekf_est_4para_myrob_M->Timing.t[0];
    if ((hardware_ekf_est_4para_myrob_DW.TimeStampA >=
         hardware_ekf_est_4para_myrobo_B.Derivative3) &&
        (hardware_ekf_est_4para_myrob_DW.TimeStampB >=
         hardware_ekf_est_4para_myrobo_B.Derivative3)) {
      /* Derivative: '<Root>/Derivative2' */
      hardware_ekf_est_4para_myrobo_B.Derivative2 = 0.0;
    } else {
      hardware_ekf_est_4para_myrobo_B.Derivative2 =
        hardware_ekf_est_4para_myrob_DW.TimeStampA;
      lastU = &hardware_ekf_est_4para_myrob_DW.LastUAtTimeA;
      if (hardware_ekf_est_4para_myrob_DW.TimeStampA <
          hardware_ekf_est_4para_myrob_DW.TimeStampB) {
        if (hardware_ekf_est_4para_myrob_DW.TimeStampB <
            hardware_ekf_est_4para_myrobo_B.Derivative3) {
          hardware_ekf_est_4para_myrobo_B.Derivative2 =
            hardware_ekf_est_4para_myrob_DW.TimeStampB;
          lastU = &hardware_ekf_est_4para_myrob_DW.LastUAtTimeB;
        }
      } else {
        if (hardware_ekf_est_4para_myrob_DW.TimeStampA >=
            hardware_ekf_est_4para_myrobo_B.Derivative3) {
          hardware_ekf_est_4para_myrobo_B.Derivative2 =
            hardware_ekf_est_4para_myrob_DW.TimeStampB;
          lastU = &hardware_ekf_est_4para_myrob_DW.LastUAtTimeB;
        }
      }

      /* Derivative: '<Root>/Derivative2' */
      hardware_ekf_est_4para_myrobo_B.Derivative2 =
        (hardware_ekf_est_4para_myrobo_B.outGearBox - *lastU) /
        (hardware_ekf_est_4para_myrobo_B.Derivative3 -
         hardware_ekf_est_4para_myrobo_B.Derivative2);
    }

    /* End of Derivative: '<Root>/Derivative2' */

    /* Sin: '<Root>/uk2' */
    hardware_ekf_est_4para_myrobo_B.uk2 = sin
      (hardware_ekf_est_4para_myrobo_P.uk2_Freq *
       hardware_ekf_est_4para_myrob_M->Timing.t[0] +
       hardware_ekf_est_4para_myrobo_P.uk2_Phase) *
      hardware_ekf_est_4para_myrobo_P.uk2_Amp +
      hardware_ekf_est_4para_myrobo_P.uk2_Bias;

    /* MATLAB Function: '<Root>/EKF2' incorporates:
     *  UnitDelay: '<Root>/Unit Delay2'
     */
    hardware_ekf_est_4para_myr_EKF2(hardware_ekf_est_4para_myrobo_B.uk2,
      hardware_ekf_est_4para_myrobo_B.Derivative2,
      hardware_ekf_est_4para_myrob_DW.UnitDelay2_DSTATE,
      &hardware_ekf_est_4para_myrobo_B.sf_EKF2,
      &hardware_ekf_est_4para_myrob_DW.sf_EKF2);

    /* S-Function (readEncDUEpin10_11): '<S3>/Encoder3' */
    readEncDUEpin10_11_Outputs_wrapper(&hardware_ekf_est_4para_myrobo_B.Encoder3,
      &hardware_ekf_est_4para_myrob_DW.Encoder3_DSTATE);

    /* MATLAB Function: '<S3>/Convert pulse to rad2' incorporates:
     *  Constant: '<S3>/gearRatio1'
     *  Constant: '<S3>/totalPPR1'
     */
    hardware_ekf_Convertpulsetorad2(hardware_ekf_est_4para_myrobo_B.Encoder3,
      hardware_ekf_est_4para_myrobo_P.totalPPR1_Value,
      hardware_ekf_est_4para_myrobo_P.gearRatio1_Value,
      &hardware_ekf_est_4para_myrobo_B.outGearBox_h,
      &hardware_ekf_est_4para_myrob_DW.sf_Convertpulsetorad2);

    /* Derivative: '<Root>/Derivative3' */
    if ((hardware_ekf_est_4para_myrob_DW.TimeStampA_g >=
         hardware_ekf_est_4para_myrobo_B.Derivative3) &&
        (hardware_ekf_est_4para_myrob_DW.TimeStampB_p >=
         hardware_ekf_est_4para_myrobo_B.Derivative3)) {
      /* Derivative: '<Root>/Derivative3' */
      hardware_ekf_est_4para_myrobo_B.Derivative3 = 0.0;
    } else {
      hardware_ekf_est_4para_myrobo_B.Derivative2 =
        hardware_ekf_est_4para_myrob_DW.TimeStampA_g;
      lastU = &hardware_ekf_est_4para_myrob_DW.LastUAtTimeA_i;
      if (hardware_ekf_est_4para_myrob_DW.TimeStampA_g <
          hardware_ekf_est_4para_myrob_DW.TimeStampB_p) {
        if (hardware_ekf_est_4para_myrob_DW.TimeStampB_p <
            hardware_ekf_est_4para_myrobo_B.Derivative3) {
          hardware_ekf_est_4para_myrobo_B.Derivative2 =
            hardware_ekf_est_4para_myrob_DW.TimeStampB_p;
          lastU = &hardware_ekf_est_4para_myrob_DW.LastUAtTimeB_d;
        }
      } else {
        if (hardware_ekf_est_4para_myrob_DW.TimeStampA_g >=
            hardware_ekf_est_4para_myrobo_B.Derivative3) {
          hardware_ekf_est_4para_myrobo_B.Derivative2 =
            hardware_ekf_est_4para_myrob_DW.TimeStampB_p;
          lastU = &hardware_ekf_est_4para_myrob_DW.LastUAtTimeB_d;
        }
      }

      /* Derivative: '<Root>/Derivative3' */
      hardware_ekf_est_4para_myrobo_B.Derivative3 =
        (hardware_ekf_est_4para_myrobo_B.outGearBox_h - *lastU) /
        (hardware_ekf_est_4para_myrobo_B.Derivative3 -
         hardware_ekf_est_4para_myrobo_B.Derivative2);
    }

    /* MATLAB Function: '<Root>/EKF3' incorporates:
     *  UnitDelay: '<Root>/Unit Delay3'
     */
    hardware_ekf_est_4para_myr_EKF2(hardware_ekf_est_4para_myrobo_B.uk2,
      hardware_ekf_est_4para_myrobo_B.Derivative3,
      hardware_ekf_est_4para_myrob_DW.UnitDelay3_DSTATE,
      &hardware_ekf_est_4para_myrobo_B.sf_EKF3,
      &hardware_ekf_est_4para_myrob_DW.sf_EKF3);

    /* MATLAB Function: '<S3>/MATLAB Function3' incorporates:
     *  MATLAB Function: '<S4>/MATLAB Function2'
     */
    hardware_ekf_est_4para_myrobo_B.Derivative3 =
      hardware_ekf_est_4para_myrobo_B.uk2 * 254.0 / 22.9;
    if (hardware_ekf_est_4para_myrobo_B.Derivative3 > 0.0) {
      hardware_ekf_est_4para_myrobo_B.uk2 =
        hardware_ekf_est_4para_myrobo_B.Derivative3;
      hardware_ekf_est_4para_myrobo_B.dir_b = 1;
    } else if (hardware_ekf_est_4para_myrobo_B.Derivative3 < 0.0) {
      hardware_ekf_est_4para_myrobo_B.uk2 = fabs
        (hardware_ekf_est_4para_myrobo_B.Derivative3);
      hardware_ekf_est_4para_myrobo_B.dir_b = 0;
    } else {
      hardware_ekf_est_4para_myrobo_B.uk2 = 0.0;
      hardware_ekf_est_4para_myrobo_B.dir_b = 0;
    }

    /* End of MATLAB Function: '<S3>/MATLAB Function3' */

    /* MATLABSystem: '<S3>/Digital Output1' */
    writeDigitalPin(4, (uint8_T)hardware_ekf_est_4para_myrobo_B.dir_b);

    /* MATLABSystem: '<S3>/PWM3' */
    obj = &hardware_ekf_est_4para_myrob_DW.obj_h;
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle
      (hardware_ekf_est_4para_myrob_DW.obj_h.PinPWM);
    if (!(hardware_ekf_est_4para_myrobo_B.uk2 < 255.0)) {
      hardware_ekf_est_4para_myrobo_B.uk2 = 255.0;
    }

    MW_PWM_SetDutyCycle(hardware_ekf_est_4para_myrob_DW.obj_h.MW_PWM_HANDLE,
                        hardware_ekf_est_4para_myrobo_B.uk2);

    /* End of MATLABSystem: '<S3>/PWM3' */

    /* MATLAB Function: '<S4>/MATLAB Function2' */
    if (hardware_ekf_est_4para_myrobo_B.Derivative3 > 0.0) {
      hardware_ekf_est_4para_myrobo_B.dir_b = 0;
    } else if (hardware_ekf_est_4para_myrobo_B.Derivative3 < 0.0) {
      hardware_ekf_est_4para_myrobo_B.Derivative3 = fabs
        (hardware_ekf_est_4para_myrobo_B.Derivative3);
      hardware_ekf_est_4para_myrobo_B.dir_b = 1;
    } else {
      hardware_ekf_est_4para_myrobo_B.Derivative3 = 0.0;
      hardware_ekf_est_4para_myrobo_B.dir_b = 0;
    }

    /* MATLABSystem: '<S4>/Digital Output' */
    writeDigitalPin(7, (uint8_T)hardware_ekf_est_4para_myrobo_B.dir_b);

    /* MATLABSystem: '<S4>/PWM' */
    obj = &hardware_ekf_est_4para_myrob_DW.obj_d;
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle
      (hardware_ekf_est_4para_myrob_DW.obj_d.PinPWM);
    if (!(hardware_ekf_est_4para_myrobo_B.Derivative3 < 255.0)) {
      hardware_ekf_est_4para_myrobo_B.Derivative3 = 255.0;
    }

    MW_PWM_SetDutyCycle(hardware_ekf_est_4para_myrob_DW.obj_d.MW_PWM_HANDLE,
                        hardware_ekf_est_4para_myrobo_B.Derivative3);

    /* End of MATLABSystem: '<S4>/PWM' */
  }

  {
    real_T *lastU;

    /* Update for S-Function (readEncDUEpin8_9): '<S4>/Encoder1' */

    /* S-Function "readEncDUEpin8_9_wrapper" Block: <S4>/Encoder1 */
    readEncDUEpin8_9_Update_wrapper(&hardware_ekf_est_4para_myrobo_B.Encoder1,
      &hardware_ekf_est_4para_myrob_DW.Encoder1_DSTATE);

    /* Update for Derivative: '<Root>/Derivative2' */
    if (hardware_ekf_est_4para_myrob_DW.TimeStampA == (rtInf)) {
      hardware_ekf_est_4para_myrob_DW.TimeStampA =
        hardware_ekf_est_4para_myrob_M->Timing.t[0];
      lastU = &hardware_ekf_est_4para_myrob_DW.LastUAtTimeA;
    } else if (hardware_ekf_est_4para_myrob_DW.TimeStampB == (rtInf)) {
      hardware_ekf_est_4para_myrob_DW.TimeStampB =
        hardware_ekf_est_4para_myrob_M->Timing.t[0];
      lastU = &hardware_ekf_est_4para_myrob_DW.LastUAtTimeB;
    } else if (hardware_ekf_est_4para_myrob_DW.TimeStampA <
               hardware_ekf_est_4para_myrob_DW.TimeStampB) {
      hardware_ekf_est_4para_myrob_DW.TimeStampA =
        hardware_ekf_est_4para_myrob_M->Timing.t[0];
      lastU = &hardware_ekf_est_4para_myrob_DW.LastUAtTimeA;
    } else {
      hardware_ekf_est_4para_myrob_DW.TimeStampB =
        hardware_ekf_est_4para_myrob_M->Timing.t[0];
      lastU = &hardware_ekf_est_4para_myrob_DW.LastUAtTimeB;
    }

    *lastU = hardware_ekf_est_4para_myrobo_B.outGearBox;

    /* End of Update for Derivative: '<Root>/Derivative2' */

    /* Update for S-Function (readEncDUEpin10_11): '<S3>/Encoder3' */

    /* S-Function "readEncDUEpin10_11_wrapper" Block: <S3>/Encoder3 */
    readEncDUEpin10_11_Update_wrapper(&hardware_ekf_est_4para_myrobo_B.Encoder3,
      &hardware_ekf_est_4para_myrob_DW.Encoder3_DSTATE);

    /* Update for Derivative: '<Root>/Derivative3' */
    if (hardware_ekf_est_4para_myrob_DW.TimeStampA_g == (rtInf)) {
      hardware_ekf_est_4para_myrob_DW.TimeStampA_g =
        hardware_ekf_est_4para_myrob_M->Timing.t[0];
      lastU = &hardware_ekf_est_4para_myrob_DW.LastUAtTimeA_i;
    } else if (hardware_ekf_est_4para_myrob_DW.TimeStampB_p == (rtInf)) {
      hardware_ekf_est_4para_myrob_DW.TimeStampB_p =
        hardware_ekf_est_4para_myrob_M->Timing.t[0];
      lastU = &hardware_ekf_est_4para_myrob_DW.LastUAtTimeB_d;
    } else if (hardware_ekf_est_4para_myrob_DW.TimeStampA_g <
               hardware_ekf_est_4para_myrob_DW.TimeStampB_p) {
      hardware_ekf_est_4para_myrob_DW.TimeStampA_g =
        hardware_ekf_est_4para_myrob_M->Timing.t[0];
      lastU = &hardware_ekf_est_4para_myrob_DW.LastUAtTimeA_i;
    } else {
      hardware_ekf_est_4para_myrob_DW.TimeStampB_p =
        hardware_ekf_est_4para_myrob_M->Timing.t[0];
      lastU = &hardware_ekf_est_4para_myrob_DW.LastUAtTimeB_d;
    }

    *lastU = hardware_ekf_est_4para_myrobo_B.outGearBox_h;

    /* End of Update for Derivative: '<Root>/Derivative3' */
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.0s, 0.0s] */
    rtExtModeUpload(0, (real_T)hardware_ekf_est_4para_myrob_M->Timing.t[0]);
  }

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(1, (real_T)
                    ((hardware_ekf_est_4para_myrob_M->Timing.clockTick1) * 0.01));
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(hardware_ekf_est_4para_myrob_M)!=-1) &&
        !((rtmGetTFinal(hardware_ekf_est_4para_myrob_M)-
           hardware_ekf_est_4para_myrob_M->Timing.t[0]) >
          hardware_ekf_est_4para_myrob_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(hardware_ekf_est_4para_myrob_M, "Simulation finished");
    }

    if (rtmGetStopRequested(hardware_ekf_est_4para_myrob_M)) {
      rtmSetErrorStatus(hardware_ekf_est_4para_myrob_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  hardware_ekf_est_4para_myrob_M->Timing.t[0] =
    ((time_T)(++hardware_ekf_est_4para_myrob_M->Timing.clockTick0)) *
    hardware_ekf_est_4para_myrob_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    hardware_ekf_est_4para_myrob_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void hardware_ekf_est_4para_myrobot_new_driver_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&hardware_ekf_est_4para_myrob_M->solverInfo,
                          &hardware_ekf_est_4para_myrob_M->Timing.simTimeStep);
    rtsiSetTPtr(&hardware_ekf_est_4para_myrob_M->solverInfo, &rtmGetTPtr
                (hardware_ekf_est_4para_myrob_M));
    rtsiSetStepSizePtr(&hardware_ekf_est_4para_myrob_M->solverInfo,
                       &hardware_ekf_est_4para_myrob_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&hardware_ekf_est_4para_myrob_M->solverInfo,
                          (&rtmGetErrorStatus(hardware_ekf_est_4para_myrob_M)));
    rtsiSetRTModelPtr(&hardware_ekf_est_4para_myrob_M->solverInfo,
                      hardware_ekf_est_4para_myrob_M);
  }

  rtsiSetSimTimeStep(&hardware_ekf_est_4para_myrob_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetSolverName(&hardware_ekf_est_4para_myrob_M->solverInfo,
                    "FixedStepDiscrete");
  rtmSetTPtr(hardware_ekf_est_4para_myrob_M,
             &hardware_ekf_est_4para_myrob_M->Timing.tArray[0]);
  rtmSetTFinal(hardware_ekf_est_4para_myrob_M, 50.0);
  hardware_ekf_est_4para_myrob_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  hardware_ekf_est_4para_myrob_M->Sizes.checksums[0] = (3182023210U);
  hardware_ekf_est_4para_myrob_M->Sizes.checksums[1] = (3866699514U);
  hardware_ekf_est_4para_myrob_M->Sizes.checksums[2] = (1817831606U);
  hardware_ekf_est_4para_myrob_M->Sizes.checksums[3] = (154852700U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
    hardware_ekf_est_4para_myrob_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(hardware_ekf_est_4para_myrob_M->extModeInfo,
      &hardware_ekf_est_4para_myrob_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(hardware_ekf_est_4para_myrob_M->extModeInfo,
                        hardware_ekf_est_4para_myrob_M->Sizes.checksums);
    rteiSetTPtr(hardware_ekf_est_4para_myrob_M->extModeInfo, rtmGetTPtr
                (hardware_ekf_est_4para_myrob_M));
  }

  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for S-Function (readEncDUEpin8_9): '<S4>/Encoder1' */

    /* S-Function Block: <S4>/Encoder1 */
    readEncDUEpin8_9_Start_wrapper
      (&hardware_ekf_est_4para_myrob_DW.Encoder1_DSTATE);

    /* Start for S-Function (readEncDUEpin10_11): '<S3>/Encoder3' */

    /* S-Function Block: <S3>/Encoder3 */
    readEncDUEpin10_11_Start_wrapper
      (&hardware_ekf_est_4para_myrob_DW.Encoder3_DSTATE);

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay3' */
    hardware_ekf_est_4para_myrob_DW.UnitDelay3_DSTATE[0] =
      hardware_ekf_est_4para_myrobo_P.UnitDelay3_InitialCondition[0];

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay2' */
    hardware_ekf_est_4para_myrob_DW.UnitDelay2_DSTATE[0] =
      hardware_ekf_est_4para_myrobo_P.UnitDelay2_InitialCondition[0];

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay3' */
    hardware_ekf_est_4para_myrob_DW.UnitDelay3_DSTATE[1] =
      hardware_ekf_est_4para_myrobo_P.UnitDelay3_InitialCondition[1];

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay2' */
    hardware_ekf_est_4para_myrob_DW.UnitDelay2_DSTATE[1] =
      hardware_ekf_est_4para_myrobo_P.UnitDelay2_InitialCondition[1];

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay3' */
    hardware_ekf_est_4para_myrob_DW.UnitDelay3_DSTATE[2] =
      hardware_ekf_est_4para_myrobo_P.UnitDelay3_InitialCondition[2];

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay2' */
    hardware_ekf_est_4para_myrob_DW.UnitDelay2_DSTATE[2] =
      hardware_ekf_est_4para_myrobo_P.UnitDelay2_InitialCondition[2];

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay3' */
    hardware_ekf_est_4para_myrob_DW.UnitDelay3_DSTATE[3] =
      hardware_ekf_est_4para_myrobo_P.UnitDelay3_InitialCondition[3];

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay2' */
    hardware_ekf_est_4para_myrob_DW.UnitDelay2_DSTATE[3] =
      hardware_ekf_est_4para_myrobo_P.UnitDelay2_InitialCondition[3];

    /* InitializeConditions for S-Function (readEncDUEpin8_9): '<S4>/Encoder1' */

    /* S-Function Block: <S4>/Encoder1 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          hardware_ekf_est_4para_myrob_DW.Encoder1_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for Derivative: '<Root>/Derivative2' */
    hardware_ekf_est_4para_myrob_DW.TimeStampA = (rtInf);
    hardware_ekf_est_4para_myrob_DW.TimeStampB = (rtInf);

    /* InitializeConditions for S-Function (readEncDUEpin10_11): '<S3>/Encoder3' */

    /* S-Function Block: <S3>/Encoder3 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          hardware_ekf_est_4para_myrob_DW.Encoder3_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for Derivative: '<Root>/Derivative3' */
    hardware_ekf_est_4para_myrob_DW.TimeStampA_g = (rtInf);
    hardware_ekf_est_4para_myrob_DW.TimeStampB_p = (rtInf);

    /* SystemInitialize for MATLAB Function: '<Root>/EKF2' */
    hardware_ekf_est_4par_EKF2_Init(&hardware_ekf_est_4para_myrob_DW.sf_EKF2);

    /* SystemInitialize for MATLAB Function: '<Root>/EKF3' */
    hardware_ekf_est_4par_EKF2_Init(&hardware_ekf_est_4para_myrob_DW.sf_EKF3);

    /* Start for MATLABSystem: '<S3>/Digital Output1' */
    hardware_ekf_est_4para_myrob_DW.obj_f.matlabCodegenIsDeleted = false;
    hardware_ekf_est_4para_myrob_DW.obj_f.isInitialized = 1;
    digitalIOSetup(4, 1);
    hardware_ekf_est_4para_myrob_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM3' */
    hardware_ekf_est_4para_myrob_DW.obj_h.matlabCodegenIsDeleted = true;
    hardware_ekf_est_4para_myrob_DW.obj_h.isInitialized = 0;
    hardware_ekf_est_4para_myrob_DW.obj_h.matlabCodegenIsDeleted = false;
    hardware_ekf_est_4para_myrob_DW.obj_h.PinPWM = 5U;
    obj = &hardware_ekf_est_4para_myrob_DW.obj_h;
    hardware_ekf_est_4para_myrob_DW.obj_h.isSetupComplete = false;
    hardware_ekf_est_4para_myrob_DW.obj_h.isInitialized = 1;
    obj->MW_PWM_HANDLE = MW_PWM_Open
      (hardware_ekf_est_4para_myrob_DW.obj_h.PinPWM, 0.0, 0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle
      (hardware_ekf_est_4para_myrob_DW.obj_h.PinPWM);
    MW_PWM_Start(hardware_ekf_est_4para_myrob_DW.obj_h.MW_PWM_HANDLE);
    hardware_ekf_est_4para_myrob_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Output' */
    hardware_ekf_est_4para_myrob_DW.obj.matlabCodegenIsDeleted = false;
    hardware_ekf_est_4para_myrob_DW.obj.isInitialized = 1;
    digitalIOSetup(7, 1);
    hardware_ekf_est_4para_myrob_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM' */
    hardware_ekf_est_4para_myrob_DW.obj_d.matlabCodegenIsDeleted = true;
    hardware_ekf_est_4para_myrob_DW.obj_d.isInitialized = 0;
    hardware_ekf_est_4para_myrob_DW.obj_d.matlabCodegenIsDeleted = false;
    hardware_ekf_est_4para_myrob_DW.obj_d.PinPWM = 6U;
    obj = &hardware_ekf_est_4para_myrob_DW.obj_d;
    hardware_ekf_est_4para_myrob_DW.obj_d.isSetupComplete = false;
    hardware_ekf_est_4para_myrob_DW.obj_d.isInitialized = 1;
    obj->MW_PWM_HANDLE = MW_PWM_Open
      (hardware_ekf_est_4para_myrob_DW.obj_d.PinPWM, 0.0, 0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle
      (hardware_ekf_est_4para_myrob_DW.obj_d.PinPWM);
    MW_PWM_Start(hardware_ekf_est_4para_myrob_DW.obj_d.MW_PWM_HANDLE);
    hardware_ekf_est_4para_myrob_DW.obj_d.isSetupComplete = true;
  }
}

/* Model terminate function */
void hardware_ekf_est_4para_myrobot_new_driver_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S3>/Digital Output1' */
  if (!hardware_ekf_est_4para_myrob_DW.obj_f.matlabCodegenIsDeleted) {
    hardware_ekf_est_4para_myrob_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S3>/PWM3' */
  obj = &hardware_ekf_est_4para_myrob_DW.obj_h;
  if (!hardware_ekf_est_4para_myrob_DW.obj_h.matlabCodegenIsDeleted) {
    hardware_ekf_est_4para_myrob_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((hardware_ekf_est_4para_myrob_DW.obj_h.isInitialized == 1) &&
        hardware_ekf_est_4para_myrob_DW.obj_h.isSetupComplete) {
      obj->MW_PWM_HANDLE = MW_PWM_GetHandle
        (hardware_ekf_est_4para_myrob_DW.obj_h.PinPWM);
      MW_PWM_SetDutyCycle(hardware_ekf_est_4para_myrob_DW.obj_h.MW_PWM_HANDLE,
                          0.0);
      obj->MW_PWM_HANDLE = MW_PWM_GetHandle
        (hardware_ekf_est_4para_myrob_DW.obj_h.PinPWM);
      MW_PWM_Close(hardware_ekf_est_4para_myrob_DW.obj_h.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM3' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output' */
  if (!hardware_ekf_est_4para_myrob_DW.obj.matlabCodegenIsDeleted) {
    hardware_ekf_est_4para_myrob_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output' */

  /* Terminate for MATLABSystem: '<S4>/PWM' */
  obj = &hardware_ekf_est_4para_myrob_DW.obj_d;
  if (!hardware_ekf_est_4para_myrob_DW.obj_d.matlabCodegenIsDeleted) {
    hardware_ekf_est_4para_myrob_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((hardware_ekf_est_4para_myrob_DW.obj_d.isInitialized == 1) &&
        hardware_ekf_est_4para_myrob_DW.obj_d.isSetupComplete) {
      obj->MW_PWM_HANDLE = MW_PWM_GetHandle
        (hardware_ekf_est_4para_myrob_DW.obj_d.PinPWM);
      MW_PWM_SetDutyCycle(hardware_ekf_est_4para_myrob_DW.obj_d.MW_PWM_HANDLE,
                          0.0);
      obj->MW_PWM_HANDLE = MW_PWM_GetHandle
        (hardware_ekf_est_4para_myrob_DW.obj_d.PinPWM);
      MW_PWM_Close(hardware_ekf_est_4para_myrob_DW.obj_d.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
