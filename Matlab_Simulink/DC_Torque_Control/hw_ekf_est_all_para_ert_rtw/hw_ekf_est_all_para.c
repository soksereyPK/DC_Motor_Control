/*
 * File: hw_ekf_est_all_para.c
 *
 * Code generated for Simulink model 'hw_ekf_est_all_para'.
 *
 * Model version                  : 4.4
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Aug 26 10:32:21 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "hw_ekf_est_all_para.h"
#include "rtwtypes.h"
#include "hw_ekf_est_all_para_private.h"
#include "hw_ekf_est_all_para_types.h"
#include <string.h>
#include <stddef.h>
#include <math.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_hw_ekf_est_all_para_T hw_ekf_est_all_para_B;

/* Block states (default storage) */
DW_hw_ekf_est_all_para_T hw_ekf_est_all_para_DW;

/* Real-time model */
static RT_MODEL_hw_ekf_est_all_para_T hw_ekf_est_all_para_M_;
RT_MODEL_hw_ekf_est_all_para_T *const hw_ekf_est_all_para_M =
  &hw_ekf_est_all_para_M_;

/* System initialize for atomic system: */
void hw_ekf_es_Calibrationwrite_Init(DW_Calibrationwrite_hw_ekf_es_T *localDW)
{
  MW_I2C_Mode_Type modename;
  uint32_T i2cname;
  codertarget_arduinobase_inter_T *obj;
  uint32_T varargin_1;

  /* Start for MATLABSystem: '<S1>/Calibration write' */
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.DefaultMaximumBusSpeedInHz = 400000.0;
  localDW->obj.isInitialized = 0L;
  localDW->obj.I2CDriverObj.MW_I2C_HANDLE = NULL;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  obj = &localDW->obj;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1L;
  modename = MW_I2C_MASTER;
  i2cname = 0;
  obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, modename);
  localDW->obj.BusSpeed = 100000UL;
  varargin_1 = localDW->obj.BusSpeed;
  MW_I2C_SetBusSpeed(localDW->obj.I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void hw_ekf_est_all_Calibrationwrite(int16_T rtu_0,
  DW_Calibrationwrite_hw_ekf_es_T *localDW)
{
  int16_T b_x;
  uint8_T b_SwappedDataBytes[3];
  uint8_T SwappedDataBytes[2];
  uint8_T b_x_0[2];

  /* MATLABSystem: '<S1>/Calibration write' */
  memcpy((void *)&SwappedDataBytes[0], (void *)&rtu_0, (uint16_T)((size_t)2 *
          sizeof(uint8_T)));
  b_x_0[0] = SwappedDataBytes[1];
  b_x_0[1] = SwappedDataBytes[0];
  memcpy((void *)&b_x, (void *)&b_x_0[0], (uint16_T)((size_t)1 * sizeof(int16_T)));
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_x, (uint16_T)((size_t)2 *
          sizeof(uint8_T)));
  b_SwappedDataBytes[0] = 5U;
  b_SwappedDataBytes[1] = SwappedDataBytes[0];
  b_SwappedDataBytes[2] = SwappedDataBytes[1];
  MW_I2C_MasterWrite(localDW->obj.I2CDriverObj.MW_I2C_HANDLE, 64UL,
                     &b_SwappedDataBytes[0], 3UL, false, false);
}

/* Termination for atomic system: */
void hw_ekf_es_Calibrationwrite_Term(DW_Calibrationwrite_hw_ekf_es_T *localDW)
{
  /* Terminate for MATLABSystem: '<S1>/Calibration write' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1L) && localDW->obj.isSetupComplete) {
      MW_I2C_Close(localDW->obj.I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Calibration write' */
}

/* Model step function */
void hw_ekf_est_all_para_step(void)
{
  /* local block i/o variables */
  int16_T rtb_DataTypeConversion;

  {
    codertarget_arduinobase_i_lsc_T *obj;
    real_T y_tmp_idx_1_tmp;
    real_T *lastU;
    int32_T rtb_Encoder1_0;
    int16_T Ak_tmp;
    int16_T Ak_tmp_tmp;
    int16_T rtb_IN1;
    int16_T rtb_IN2;
    int8_T y_tmp[4];
    int8_T y_tmp_0[4];
    int8_T y_tmp_1;
    uint8_T b_x[2];
    uint8_T output_raw[2];
    uint8_T status;
    static const int8_T d[4] = { 1, 0, 0, 0 };

    static const real_T c[16] = { 1.0000000000000002E-6, 0.0, 0.0, 0.0, 0.0,
      1.0E-5, 0.0, 0.0, 0.0, 0.0, 0.0001, 0.0, 0.0, 0.0, 0.0, 1.0E-5 };

    /* MATLABSystem: '<S4>/Encoder1' */
    if (hw_ekf_est_all_para_DW.obj_g.SampleTime !=
        hw_ekf_est_all_para_P.Encoder1_SampleTime) {
      hw_ekf_est_all_para_DW.obj_g.SampleTime =
        hw_ekf_est_all_para_P.Encoder1_SampleTime;
    }

    if (hw_ekf_est_all_para_DW.obj_g.TunablePropsChanged) {
      hw_ekf_est_all_para_DW.obj_g.TunablePropsChanged = false;
    }

    MW_EncoderRead(hw_ekf_est_all_para_DW.obj_g.Index, &rtb_Encoder1_0);

    /* Gain: '<S10>/Gain' incorporates:
     *  DataTypeConversion: '<S4>/Data Type Conversion1'
     *  Gain: '<S4>/Gain2'
     *  MATLABSystem: '<S4>/Encoder1'
     */
    hw_ekf_est_all_para_B.Gain = hw_ekf_est_all_para_P.Gain2_Gain * (real_T)
      rtb_Encoder1_0 * hw_ekf_est_all_para_P.Gain_Gain;

    /* Derivative: '<Root>/Derivative' */
    hw_ekf_est_all_para_B.SineWave = hw_ekf_est_all_para_M->Timing.t[0];
    if ((hw_ekf_est_all_para_DW.TimeStampA >= hw_ekf_est_all_para_B.SineWave) &&
        (hw_ekf_est_all_para_DW.TimeStampB >= hw_ekf_est_all_para_B.SineWave)) {
      hw_ekf_est_all_para_B.Derivative = 0.0;
    } else {
      hw_ekf_est_all_para_B.lastTime = hw_ekf_est_all_para_DW.TimeStampA;
      lastU = &hw_ekf_est_all_para_DW.LastUAtTimeA;
      if (hw_ekf_est_all_para_DW.TimeStampA < hw_ekf_est_all_para_DW.TimeStampB)
      {
        if (hw_ekf_est_all_para_DW.TimeStampB < hw_ekf_est_all_para_B.SineWave)
        {
          hw_ekf_est_all_para_B.lastTime = hw_ekf_est_all_para_DW.TimeStampB;
          lastU = &hw_ekf_est_all_para_DW.LastUAtTimeB;
        }
      } else if (hw_ekf_est_all_para_DW.TimeStampA >=
                 hw_ekf_est_all_para_B.SineWave) {
        hw_ekf_est_all_para_B.lastTime = hw_ekf_est_all_para_DW.TimeStampB;
        lastU = &hw_ekf_est_all_para_DW.LastUAtTimeB;
      }

      hw_ekf_est_all_para_B.Derivative = (hw_ekf_est_all_para_B.Gain - *lastU) /
        (hw_ekf_est_all_para_B.SineWave - hw_ekf_est_all_para_B.lastTime);
    }

    /* End of Derivative: '<Root>/Derivative' */

    /* Sin: '<Root>/Sine Wave' */
    hw_ekf_est_all_para_B.SineWave = sin(hw_ekf_est_all_para_P.SineWave_Freq *
      hw_ekf_est_all_para_M->Timing.t[0] + hw_ekf_est_all_para_P.SineWave_Phase)
      * hw_ekf_est_all_para_P.SineWave_Amp + hw_ekf_est_all_para_P.SineWave_Bias;

    /* MATLAB Function: '<S6>/MATLAB Function3' incorporates:
     *  Delay: '<S6>/Delay'
     *  Delay: '<S6>/Delay1'
     *  MATLAB Function: '<S6>/MATLAB Function'
     */
    hw_ekf_est_all_para_B.lastTime = hw_ekf_est_all_para_DW.Delay_DSTATE[0];
    if (!rtIsNaN(hw_ekf_est_all_para_B.lastTime)) {
      if (hw_ekf_est_all_para_B.lastTime < 0.0) {
        hw_ekf_est_all_para_B.lastTime = -1.0;
      } else {
        hw_ekf_est_all_para_B.lastTime = (hw_ekf_est_all_para_B.lastTime > 0.0);
      }
    }

    hw_ekf_est_all_para_B.x[0] = ((-hw_ekf_est_all_para_DW.Delay_DSTATE[1] *
      hw_ekf_est_all_para_DW.Delay_DSTATE[0] + hw_ekf_est_all_para_B.SineWave *
      hw_ekf_est_all_para_DW.Delay_DSTATE[2]) -
      hw_ekf_est_all_para_DW.Delay_DSTATE[3] * hw_ekf_est_all_para_B.lastTime) *
      0.01 + hw_ekf_est_all_para_DW.Delay_DSTATE[0];
    hw_ekf_est_all_para_B.x[1] = hw_ekf_est_all_para_DW.Delay_DSTATE[1];
    hw_ekf_est_all_para_B.x[2] = hw_ekf_est_all_para_DW.Delay_DSTATE[2];
    hw_ekf_est_all_para_B.x[3] = hw_ekf_est_all_para_DW.Delay_DSTATE[3];
    memset(&hw_ekf_est_all_para_B.b_I[0], 0, sizeof(real_T) << 4U);
    hw_ekf_est_all_para_B.lastTime = hw_ekf_est_all_para_DW.Delay_DSTATE[0];
    hw_ekf_est_all_para_B.Ak[0] = 0.01 * -hw_ekf_est_all_para_DW.Delay_DSTATE[1]
      + 1.0;
    hw_ekf_est_all_para_B.Ak[1] = hw_ekf_est_all_para_B.b_I[1];
    hw_ekf_est_all_para_B.Ak[2] = hw_ekf_est_all_para_B.b_I[2];
    hw_ekf_est_all_para_B.Ak[3] = hw_ekf_est_all_para_B.b_I[3];
    hw_ekf_est_all_para_B.Ak[4] = 0.01 * -hw_ekf_est_all_para_DW.Delay_DSTATE[0]
      + hw_ekf_est_all_para_B.b_I[4];
    hw_ekf_est_all_para_B.Ak[5] = 1.0;
    hw_ekf_est_all_para_B.Ak[6] = hw_ekf_est_all_para_B.b_I[6];
    hw_ekf_est_all_para_B.Ak[7] = hw_ekf_est_all_para_B.b_I[7];
    hw_ekf_est_all_para_B.Ak[8] = 0.01 * hw_ekf_est_all_para_B.SineWave +
      hw_ekf_est_all_para_B.b_I[8];
    hw_ekf_est_all_para_B.Ak[9] = hw_ekf_est_all_para_B.b_I[9];
    hw_ekf_est_all_para_B.Ak[10] = 1.0;
    hw_ekf_est_all_para_B.Ak[11] = hw_ekf_est_all_para_B.b_I[11];
    if (!rtIsNaN(hw_ekf_est_all_para_B.lastTime)) {
      if (hw_ekf_est_all_para_B.lastTime < 0.0) {
        hw_ekf_est_all_para_B.lastTime = -1.0;
      } else {
        hw_ekf_est_all_para_B.lastTime = (hw_ekf_est_all_para_B.lastTime > 0.0);
      }
    }

    hw_ekf_est_all_para_B.Ak[12] = 0.01 * -hw_ekf_est_all_para_B.lastTime +
      hw_ekf_est_all_para_B.b_I[12];
    hw_ekf_est_all_para_B.Ak[13] = hw_ekf_est_all_para_B.b_I[13];
    hw_ekf_est_all_para_B.Ak[14] = hw_ekf_est_all_para_B.b_I[14];
    hw_ekf_est_all_para_B.Ak[15] = 1.0;
    for (rtb_IN2 = 0; rtb_IN2 < 4; rtb_IN2++) {
      for (rtb_IN1 = 0; rtb_IN1 < 4; rtb_IN1++) {
        Ak_tmp_tmp = rtb_IN1 << 2;
        Ak_tmp = rtb_IN2 + Ak_tmp_tmp;
        hw_ekf_est_all_para_B.Ak_m[Ak_tmp] = 0.0;
        hw_ekf_est_all_para_B.Ak_m[Ak_tmp] +=
          hw_ekf_est_all_para_DW.Delay1_DSTATE[Ak_tmp_tmp] *
          hw_ekf_est_all_para_B.Ak[rtb_IN2];
        hw_ekf_est_all_para_B.Ak_m[Ak_tmp] +=
          hw_ekf_est_all_para_DW.Delay1_DSTATE[Ak_tmp_tmp + 1] *
          hw_ekf_est_all_para_B.Ak[rtb_IN2 + 4];
        hw_ekf_est_all_para_B.Ak_m[Ak_tmp] +=
          hw_ekf_est_all_para_DW.Delay1_DSTATE[Ak_tmp_tmp + 2] *
          hw_ekf_est_all_para_B.Ak[rtb_IN2 + 8];
        hw_ekf_est_all_para_B.Ak_m[Ak_tmp] +=
          hw_ekf_est_all_para_DW.Delay1_DSTATE[Ak_tmp_tmp + 3] *
          hw_ekf_est_all_para_B.Ak[rtb_IN2 + 12];
      }

      for (rtb_IN1 = 0; rtb_IN1 < 4; rtb_IN1++) {
        Ak_tmp_tmp = (rtb_IN1 << 2) + rtb_IN2;
        hw_ekf_est_all_para_B.b_I[Ak_tmp_tmp] =
          (((hw_ekf_est_all_para_B.Ak_m[rtb_IN2 + 4] *
             hw_ekf_est_all_para_B.Ak[rtb_IN1 + 4] +
             hw_ekf_est_all_para_B.Ak_m[rtb_IN2] *
             hw_ekf_est_all_para_B.Ak[rtb_IN1]) +
            hw_ekf_est_all_para_B.Ak_m[rtb_IN2 + 8] *
            hw_ekf_est_all_para_B.Ak[rtb_IN1 + 8]) +
           hw_ekf_est_all_para_B.Ak_m[rtb_IN2 + 12] *
           hw_ekf_est_all_para_B.Ak[rtb_IN1 + 12]) + c[Ak_tmp_tmp];
      }

      y_tmp[rtb_IN2] = d[rtb_IN2];
      y_tmp_0[rtb_IN2] = d[rtb_IN2];
    }

    hw_ekf_est_all_para_B.lastTime = 0.0;
    for (rtb_IN1 = 0; rtb_IN1 < 4; rtb_IN1++) {
      rtb_IN2 = rtb_IN1 << 2;
      hw_ekf_est_all_para_B.lastTime += (((hw_ekf_est_all_para_B.b_I[rtb_IN2 + 1]
        * (real_T)y_tmp_0[1] + hw_ekf_est_all_para_B.b_I[rtb_IN2] * (real_T)
        y_tmp_0[0]) + hw_ekf_est_all_para_B.b_I[rtb_IN2 + 2] * (real_T)y_tmp_0[2])
        + hw_ekf_est_all_para_B.b_I[rtb_IN2 + 3] * (real_T)y_tmp_0[3]) * (real_T)
        y_tmp[rtb_IN1];
    }

    hw_ekf_est_all_para_B.y_tmp = 0.0;
    for (rtb_IN1 = 0; rtb_IN1 < 4; rtb_IN1++) {
      hw_ekf_est_all_para_B.Wk[rtb_IN1] = (((hw_ekf_est_all_para_B.b_I[rtb_IN1 +
        4] * (real_T)y_tmp[1] + hw_ekf_est_all_para_B.b_I[rtb_IN1] * (real_T)
        y_tmp[0]) + hw_ekf_est_all_para_B.b_I[rtb_IN1 + 8] * (real_T)y_tmp[2]) +
        hw_ekf_est_all_para_B.b_I[rtb_IN1 + 12] * (real_T)y_tmp[3]) /
        (hw_ekf_est_all_para_B.lastTime + 0.01);
      hw_ekf_est_all_para_B.y_tmp += (real_T)y_tmp_0[rtb_IN1] *
        hw_ekf_est_all_para_B.x[rtb_IN1];
    }

    hw_ekf_est_all_para_B.lastTime = hw_ekf_est_all_para_B.Derivative - (0.0 *
      hw_ekf_est_all_para_B.SineWave + hw_ekf_est_all_para_B.y_tmp);
    for (rtb_IN1 = 0; rtb_IN1 < 4; rtb_IN1++) {
      y_tmp_1 = y_tmp_0[rtb_IN1];
      hw_ekf_est_all_para_B.x[rtb_IN1] += hw_ekf_est_all_para_B.Wk[rtb_IN1] *
        hw_ekf_est_all_para_B.lastTime;
      rtb_IN2 = rtb_IN1 << 2;
      hw_ekf_est_all_para_B.Ak[rtb_IN2] = hw_ekf_est_all_para_B.Wk[0] * (real_T)
        y_tmp_1;
      hw_ekf_est_all_para_B.Ak[rtb_IN2 + 1] = hw_ekf_est_all_para_B.Wk[1] *
        (real_T)y_tmp_1;
      hw_ekf_est_all_para_B.Ak[rtb_IN2 + 2] = hw_ekf_est_all_para_B.Wk[2] *
        (real_T)y_tmp_1;
      hw_ekf_est_all_para_B.Ak[rtb_IN2 + 3] = hw_ekf_est_all_para_B.Wk[3] *
        (real_T)y_tmp_1;
    }

    for (rtb_IN1 = 0; rtb_IN1 < 4; rtb_IN1++) {
      for (rtb_IN2 = 0; rtb_IN2 < 4; rtb_IN2++) {
        Ak_tmp_tmp = rtb_IN2 << 2;
        Ak_tmp = Ak_tmp_tmp + rtb_IN1;
        hw_ekf_est_all_para_B.P[Ak_tmp] = hw_ekf_est_all_para_B.b_I[Ak_tmp] -
          (((hw_ekf_est_all_para_B.b_I[Ak_tmp_tmp + 1] *
             hw_ekf_est_all_para_B.Ak[rtb_IN1 + 4] +
             hw_ekf_est_all_para_B.b_I[Ak_tmp_tmp] *
             hw_ekf_est_all_para_B.Ak[rtb_IN1]) +
            hw_ekf_est_all_para_B.b_I[Ak_tmp_tmp + 2] *
            hw_ekf_est_all_para_B.Ak[rtb_IN1 + 8]) +
           hw_ekf_est_all_para_B.b_I[Ak_tmp_tmp + 3] *
           hw_ekf_est_all_para_B.Ak[rtb_IN1 + 12]);
      }
    }

    /* End of MATLAB Function: '<S6>/MATLAB Function3' */

    /* MATLABSystem: '<Root>/Current Reg read' */
    if (hw_ekf_est_all_para_DW.obj.SampleTime !=
        hw_ekf_est_all_para_P.CurrentRegread_SampleTime) {
      hw_ekf_est_all_para_DW.obj.SampleTime =
        hw_ekf_est_all_para_P.CurrentRegread_SampleTime;
    }

    status = 4U;
    status = MW_I2C_MasterWrite
      (hw_ekf_est_all_para_DW.obj.I2CDriverObj.MW_I2C_HANDLE, 64UL, &status, 1UL,
       true, false);
    if (status == 0) {
      MW_I2C_MasterRead(hw_ekf_est_all_para_DW.obj.I2CDriverObj.MW_I2C_HANDLE,
                        64UL, &output_raw[0], 2UL, false, true);
      memcpy((void *)&rtb_IN2, (void *)&output_raw[0], (uint16_T)((size_t)1 *
              sizeof(int16_T)));
      memcpy((void *)&output_raw[0], (void *)&rtb_IN2, (uint16_T)((size_t)2 *
              sizeof(uint8_T)));
      b_x[0] = output_raw[1];
      b_x[1] = output_raw[0];
      memcpy((void *)&rtb_IN1, (void *)&b_x[0], (uint16_T)((size_t)1 * sizeof
              (int16_T)));
    } else {
      rtb_IN1 = 0;
    }

    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Gain: '<Root>/Gain'
     *  MATLABSystem: '<Root>/Current Reg read'
     */
    hw_ekf_est_all_para_B.current_mA = (real_T)((int32_T)
      hw_ekf_est_all_para_P.Gain_Gain_e * rtb_IN1) * 1.9073486328125E-6;

    /* Gain: '<Root>/Gain1' */
    hw_ekf_est_all_para_B.current_A = hw_ekf_est_all_para_P.Gain1_Gain *
      hw_ekf_est_all_para_B.current_mA;

    /* MATLAB Function: '<S5>/MATLAB Function1' incorporates:
     *  Delay: '<S5>/Delay2'
     *  Delay: '<S5>/Delay3'
     */
    hw_ekf_est_all_para_B.Derivative /= hw_ekf_est_all_para_B.current_A;
    hw_ekf_est_all_para_B.y_tmp = hw_ekf_est_all_para_B.Derivative *
      hw_ekf_est_all_para_DW.Delay2_DSTATE[1] +
      hw_ekf_est_all_para_DW.Delay2_DSTATE[0];
    y_tmp_idx_1_tmp = hw_ekf_est_all_para_B.Derivative *
      hw_ekf_est_all_para_DW.Delay2_DSTATE[3];
    hw_ekf_est_all_para_B.y_tmp_idx_1 = y_tmp_idx_1_tmp +
      hw_ekf_est_all_para_DW.Delay2_DSTATE[2];
    hw_ekf_est_all_para_B.lastTime = hw_ekf_est_all_para_B.y_tmp_idx_1 *
      hw_ekf_est_all_para_B.Derivative + hw_ekf_est_all_para_B.y_tmp;
    hw_ekf_est_all_para_B.unnamed_idx_0 = (hw_ekf_est_all_para_DW.Delay2_DSTATE
      [2] * hw_ekf_est_all_para_B.Derivative +
      hw_ekf_est_all_para_DW.Delay2_DSTATE[0]) / (hw_ekf_est_all_para_B.lastTime
      + 1.0);
    hw_ekf_est_all_para_B.lastTime = (y_tmp_idx_1_tmp +
      hw_ekf_est_all_para_DW.Delay2_DSTATE[1]) / (hw_ekf_est_all_para_B.lastTime
      + 1.0);
    hw_ekf_est_all_para_B.P_h[0] = hw_ekf_est_all_para_DW.Delay2_DSTATE[0] -
      hw_ekf_est_all_para_B.unnamed_idx_0 * hw_ekf_est_all_para_B.y_tmp;
    hw_ekf_est_all_para_B.P_h[1] = hw_ekf_est_all_para_DW.Delay2_DSTATE[1] -
      hw_ekf_est_all_para_B.lastTime * hw_ekf_est_all_para_B.y_tmp;
    hw_ekf_est_all_para_B.P_h[2] = hw_ekf_est_all_para_DW.Delay2_DSTATE[2] -
      hw_ekf_est_all_para_B.unnamed_idx_0 * hw_ekf_est_all_para_B.y_tmp_idx_1;
    hw_ekf_est_all_para_B.P_h[3] = hw_ekf_est_all_para_DW.Delay2_DSTATE[3] -
      hw_ekf_est_all_para_B.lastTime * hw_ekf_est_all_para_B.y_tmp_idx_1;
    hw_ekf_est_all_para_B.lastTime = hw_ekf_est_all_para_B.SineWave /
      hw_ekf_est_all_para_B.current_A - (hw_ekf_est_all_para_B.Derivative *
      hw_ekf_est_all_para_DW.Delay3_DSTATE[1] +
      hw_ekf_est_all_para_DW.Delay3_DSTATE[0]);
    hw_ekf_est_all_para_B.x_n[0] = (hw_ekf_est_all_para_B.P_h[2] *
      hw_ekf_est_all_para_B.Derivative + hw_ekf_est_all_para_B.P_h[0]) *
      hw_ekf_est_all_para_B.lastTime + hw_ekf_est_all_para_DW.Delay3_DSTATE[0];
    hw_ekf_est_all_para_B.x_n[1] = (hw_ekf_est_all_para_B.P_h[3] *
      hw_ekf_est_all_para_B.Derivative + hw_ekf_est_all_para_B.P_h[1]) *
      hw_ekf_est_all_para_B.lastTime + hw_ekf_est_all_para_DW.Delay3_DSTATE[1];

    /* DataTypeConversion: '<Root>/Data Type Conversion3' */
    hw_ekf_est_all_para_B.DataTypeConversion3 = (real32_T)
      hw_ekf_est_all_para_B.x_n[0];

    /* DataTypeConversion: '<Root>/Data Type Conversion4' */
    hw_ekf_est_all_para_B.DataTypeConversion4 = (real32_T)
      hw_ekf_est_all_para_B.x_n[1];

    /* DataTypeConversion: '<Root>/Data Type Conversion5' */
    hw_ekf_est_all_para_B.DataTypeConversion5 = (real32_T)
      hw_ekf_est_all_para_B.x[1];

    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    hw_ekf_est_all_para_B.DataTypeConversion1 = (real32_T)
      hw_ekf_est_all_para_B.x[2];

    /* DataTypeConversion: '<Root>/Data Type Conversion2' */
    hw_ekf_est_all_para_B.DataTypeConversion2 = (real32_T)
      hw_ekf_est_all_para_B.x[3];

    /* MATLAB Function: '<Root>/MATLAB Function3' */
    hw_ekf_est_all_para_B.Ra = hw_ekf_est_all_para_B.DataTypeConversion3;
    hw_ekf_est_all_para_B.kt = hw_ekf_est_all_para_B.DataTypeConversion4;
    hw_ekf_est_all_para_B.J = hw_ekf_est_all_para_B.kt /
      (hw_ekf_est_all_para_B.Ra * hw_ekf_est_all_para_B.DataTypeConversion1);
    hw_ekf_est_all_para_B.Tc = hw_ekf_est_all_para_B.DataTypeConversion2 *
      hw_ekf_est_all_para_B.J;
    hw_ekf_est_all_para_B.D = (hw_ekf_est_all_para_B.DataTypeConversion5 *
      hw_ekf_est_all_para_B.Ra * hw_ekf_est_all_para_B.J -
      hw_ekf_est_all_para_B.kt * hw_ekf_est_all_para_B.kt) /
      hw_ekf_est_all_para_B.Ra;

    /* DataTypeConversion: '<Root>/Data Type Conversion6' */
    hw_ekf_est_all_para_B.w = (real32_T)hw_ekf_est_all_para_B.x[0];

    /* MATLAB Function: '<S4>/MATLAB Function4' */
    hw_ekf_est_all_para_B.SineWave = hw_ekf_est_all_para_B.SineWave * 254.0 /
      12.0;
    if (hw_ekf_est_all_para_B.SineWave > 0.0) {
      rtb_IN1 = 1;
      rtb_IN2 = 0;
    } else if (hw_ekf_est_all_para_B.SineWave < 0.0) {
      hw_ekf_est_all_para_B.SineWave = fabs(hw_ekf_est_all_para_B.SineWave);
      rtb_IN1 = 0;
      rtb_IN2 = 1;
    } else {
      hw_ekf_est_all_para_B.SineWave = 0.0;
      rtb_IN1 = 0;
      rtb_IN2 = 0;
    }

    /* End of MATLAB Function: '<S4>/MATLAB Function4' */

    /* MATLABSystem: '<S4>/Digital Output' */
    writeDigitalPin(5, (uint8_T)rtb_IN1);

    /* MATLABSystem: '<S4>/Digital Output1' */
    writeDigitalPin(7, (uint8_T)rtb_IN2);

    /* MATLABSystem: '<S4>/PWM' */
    obj = &hw_ekf_est_all_para_DW.obj_i;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
    if (!(hw_ekf_est_all_para_B.SineWave <= 255.0)) {
      hw_ekf_est_all_para_B.SineWave = 255.0;
    }

    MW_PWM_SetDutyCycle(hw_ekf_est_all_para_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE,
                        hw_ekf_est_all_para_B.SineWave);

    /* End of MATLABSystem: '<S4>/PWM' */
    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  Constant: '<S1>/Constant2'
     */
    hw_ekf_est_all_para_B.SineWave = floor
      (hw_ekf_est_all_para_P.Constant2_Value_g);
    if (rtIsNaN(hw_ekf_est_all_para_B.SineWave) || rtIsInf
        (hw_ekf_est_all_para_B.SineWave)) {
      hw_ekf_est_all_para_B.SineWave = 0.0;
    } else {
      hw_ekf_est_all_para_B.SineWave = fmod(hw_ekf_est_all_para_B.SineWave,
        65536.0);
    }

    /* DataTypeConversion: '<S1>/Data Type Conversion' */
    rtb_DataTypeConversion = hw_ekf_est_all_para_B.SineWave < 0.0 ? -(int16_T)
      (uint16_T)-hw_ekf_est_all_para_B.SineWave : (int16_T)(uint16_T)
      hw_ekf_est_all_para_B.SineWave;
    hw_ekf_est_all_Calibrationwrite(rtb_DataTypeConversion,
      &hw_ekf_est_all_para_DW.Calibrationwrite);
  }

  {
    real_T *lastU;

    /* Update for Delay: '<S6>/Delay1' */
    memcpy(&hw_ekf_est_all_para_DW.Delay1_DSTATE[0], &hw_ekf_est_all_para_B.P[0],
           sizeof(real_T) << 4U);

    /* Update for Delay: '<S6>/Delay' */
    hw_ekf_est_all_para_DW.Delay_DSTATE[0] = hw_ekf_est_all_para_B.x[0];
    hw_ekf_est_all_para_DW.Delay_DSTATE[1] = hw_ekf_est_all_para_B.x[1];
    hw_ekf_est_all_para_DW.Delay_DSTATE[2] = hw_ekf_est_all_para_B.x[2];
    hw_ekf_est_all_para_DW.Delay_DSTATE[3] = hw_ekf_est_all_para_B.x[3];

    /* Update for Derivative: '<Root>/Derivative' */
    if (hw_ekf_est_all_para_DW.TimeStampA == (rtInf)) {
      hw_ekf_est_all_para_DW.TimeStampA = hw_ekf_est_all_para_M->Timing.t[0];
      lastU = &hw_ekf_est_all_para_DW.LastUAtTimeA;
    } else if (hw_ekf_est_all_para_DW.TimeStampB == (rtInf)) {
      hw_ekf_est_all_para_DW.TimeStampB = hw_ekf_est_all_para_M->Timing.t[0];
      lastU = &hw_ekf_est_all_para_DW.LastUAtTimeB;
    } else if (hw_ekf_est_all_para_DW.TimeStampA <
               hw_ekf_est_all_para_DW.TimeStampB) {
      hw_ekf_est_all_para_DW.TimeStampA = hw_ekf_est_all_para_M->Timing.t[0];
      lastU = &hw_ekf_est_all_para_DW.LastUAtTimeA;
    } else {
      hw_ekf_est_all_para_DW.TimeStampB = hw_ekf_est_all_para_M->Timing.t[0];
      lastU = &hw_ekf_est_all_para_DW.LastUAtTimeB;
    }

    *lastU = hw_ekf_est_all_para_B.Gain;

    /* End of Update for Derivative: '<Root>/Derivative' */

    /* Update for Delay: '<S5>/Delay3' */
    hw_ekf_est_all_para_DW.Delay3_DSTATE[0] = hw_ekf_est_all_para_B.x_n[0];
    hw_ekf_est_all_para_DW.Delay3_DSTATE[1] = hw_ekf_est_all_para_B.x_n[1];

    /* Update for Delay: '<S5>/Delay2' */
    hw_ekf_est_all_para_DW.Delay2_DSTATE[0] = hw_ekf_est_all_para_B.P_h[0];
    hw_ekf_est_all_para_DW.Delay2_DSTATE[1] = hw_ekf_est_all_para_B.P_h[1];
    hw_ekf_est_all_para_DW.Delay2_DSTATE[2] = hw_ekf_est_all_para_B.P_h[2];
    hw_ekf_est_all_para_DW.Delay2_DSTATE[3] = hw_ekf_est_all_para_B.P_h[3];
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((hw_ekf_est_all_para_M->Timing.clockTick0 * 1) + 0)
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
      ((hw_ekf_est_all_para_M->Timing.clockTick1 * 1) + 0)
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
  hw_ekf_est_all_para_M->Timing.t[0] =
    ((time_T)(++hw_ekf_est_all_para_M->Timing.clockTick0)) *
    hw_ekf_est_all_para_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    hw_ekf_est_all_para_M->Timing.clockTick1++;
  }

  switch (hw_ekf_est_all_para_M->Timing.rtmDbBufReadBuf2) {
   case 0:
    hw_ekf_est_all_para_M->Timing.rtmDbBufWriteBuf2 = 1;
    break;

   case 1:
    hw_ekf_est_all_para_M->Timing.rtmDbBufWriteBuf2 = 0;
    break;

   default:
    hw_ekf_est_all_para_M->Timing.rtmDbBufWriteBuf2 =
      !hw_ekf_est_all_para_M->Timing.rtmDbBufLastBufWr2;
    break;
  }

  hw_ekf_est_all_para_M->Timing.rtmDbBufClockTick2
    [hw_ekf_est_all_para_M->Timing.rtmDbBufWriteBuf2] =
    hw_ekf_est_all_para_M->Timing.clockTick0;
  hw_ekf_est_all_para_M->Timing.rtmDbBufLastBufWr2 =
    hw_ekf_est_all_para_M->Timing.rtmDbBufWriteBuf2;
  hw_ekf_est_all_para_M->Timing.rtmDbBufWriteBuf2 = 0xFF;
}

/* Model initialize function */
void hw_ekf_est_all_para_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&hw_ekf_est_all_para_M->solverInfo,
                          &hw_ekf_est_all_para_M->Timing.simTimeStep);
    rtsiSetTPtr(&hw_ekf_est_all_para_M->solverInfo, &rtmGetTPtr
                (hw_ekf_est_all_para_M));
    rtsiSetStepSizePtr(&hw_ekf_est_all_para_M->solverInfo,
                       &hw_ekf_est_all_para_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&hw_ekf_est_all_para_M->solverInfo,
                          (&rtmGetErrorStatus(hw_ekf_est_all_para_M)));
    rtsiSetRTModelPtr(&hw_ekf_est_all_para_M->solverInfo, hw_ekf_est_all_para_M);
  }

  rtsiSetSimTimeStep(&hw_ekf_est_all_para_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&hw_ekf_est_all_para_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(hw_ekf_est_all_para_M, &hw_ekf_est_all_para_M->Timing.tArray[0]);
  rtmSetTFinal(hw_ekf_est_all_para_M, 120.0);
  hw_ekf_est_all_para_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  hw_ekf_est_all_para_M->Sizes.checksums[0] = (4189070465U);
  hw_ekf_est_all_para_M->Sizes.checksums[1] = (38709715U);
  hw_ekf_est_all_para_M->Sizes.checksums[2] = (2406688859U);
  hw_ekf_est_all_para_M->Sizes.checksums[3] = (1190283627U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[15];
    hw_ekf_est_all_para_M->extModeInfo = (&rt_ExtModeInfo);
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
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(hw_ekf_est_all_para_M->extModeInfo,
      &hw_ekf_est_all_para_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(hw_ekf_est_all_para_M->extModeInfo,
                        hw_ekf_est_all_para_M->Sizes.checksums);
    rteiSetTPtr(hw_ekf_est_all_para_M->extModeInfo, rtmGetTPtr
                (hw_ekf_est_all_para_M));
  }

  {
    /* local block i/o variables */
    int16_T rtb_DataTypeConversion_l;
    codertarget_arduinobase_i_lsc_T *obj_0;
    codertarget_arduinobase_in_ls_T *obj;
    codertarget_arduinobase_inter_T *obj_1;
    int16_T i;
    uint8_T SwappedDataBytes[2];
    uint8_T b_x[2];
    hw_ekf_est_all_para_M->Timing.rtmDbBufReadBuf2 = 0xFF;
    hw_ekf_est_all_para_M->Timing.rtmDbBufWriteBuf2 = 0xFF;
    hw_ekf_est_all_para_M->Timing.rtmDbBufLastBufWr2 = 0;

    /* InitializeConditions for Delay: '<S6>/Delay1' */
    memcpy(&hw_ekf_est_all_para_DW.Delay1_DSTATE[0],
           &hw_ekf_est_all_para_P.Delay1_InitialCondition[0], sizeof(real_T) <<
           4U);

    /* InitializeConditions for Delay: '<S6>/Delay' */
    hw_ekf_est_all_para_DW.Delay_DSTATE[0] =
      hw_ekf_est_all_para_P.Delay_InitialCondition[0];
    hw_ekf_est_all_para_DW.Delay_DSTATE[1] =
      hw_ekf_est_all_para_P.Delay_InitialCondition[1];
    hw_ekf_est_all_para_DW.Delay_DSTATE[2] =
      hw_ekf_est_all_para_P.Delay_InitialCondition[2];
    hw_ekf_est_all_para_DW.Delay_DSTATE[3] =
      hw_ekf_est_all_para_P.Delay_InitialCondition[3];

    /* InitializeConditions for Derivative: '<Root>/Derivative' */
    hw_ekf_est_all_para_DW.TimeStampA = (rtInf);
    hw_ekf_est_all_para_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Delay: '<S5>/Delay3' */
    hw_ekf_est_all_para_DW.Delay3_DSTATE[0] =
      hw_ekf_est_all_para_P.Delay3_InitialCondition[0];
    hw_ekf_est_all_para_DW.Delay3_DSTATE[1] =
      hw_ekf_est_all_para_P.Delay3_InitialCondition[1];

    /* InitializeConditions for Delay: '<S5>/Delay2' */
    hw_ekf_est_all_para_DW.Delay2_DSTATE[0] =
      hw_ekf_est_all_para_P.Delay2_InitialCondition[0];
    hw_ekf_est_all_para_DW.Delay2_DSTATE[1] =
      hw_ekf_est_all_para_P.Delay2_InitialCondition[1];
    hw_ekf_est_all_para_DW.Delay2_DSTATE[2] =
      hw_ekf_est_all_para_P.Delay2_InitialCondition[2];
    hw_ekf_est_all_para_DW.Delay2_DSTATE[3] =
      hw_ekf_est_all_para_P.Delay2_InitialCondition[3];

    /* SystemInitialize for Atomic SubSystem: '<Root>/Initialize Function' */
    /* Start for MATLABSystem: '<S7>/Configuration write' */
    hw_ekf_est_all_para_DW.obj_o.matlabCodegenIsDeleted = true;
    hw_ekf_est_all_para_DW.obj_o.DefaultMaximumBusSpeedInHz = 400000.0;
    hw_ekf_est_all_para_DW.obj_o.isInitialized = 0L;
    hw_ekf_est_all_para_DW.obj_o.I2CDriverObj.MW_I2C_HANDLE = NULL;
    hw_ekf_est_all_para_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_1 = &hw_ekf_est_all_para_DW.obj_o;
    hw_ekf_est_all_para_DW.obj_o.isSetupComplete = false;
    hw_ekf_est_all_para_DW.obj_o.isInitialized = 1L;
    hw_ekf_est_all_para_B.modename = MW_I2C_MASTER;
    hw_ekf_est_all_para_B.i2cname = 0;
    obj_1->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open
      (hw_ekf_est_all_para_B.i2cname, hw_ekf_est_all_para_B.modename);
    hw_ekf_est_all_para_DW.obj_o.BusSpeed = 100000UL;
    hw_ekf_est_all_para_B.varargin_1 = hw_ekf_est_all_para_DW.obj_o.BusSpeed;
    MW_I2C_SetBusSpeed(hw_ekf_est_all_para_DW.obj_o.I2CDriverObj.MW_I2C_HANDLE,
                       hw_ekf_est_all_para_B.varargin_1);
    hw_ekf_est_all_para_DW.obj_o.isSetupComplete = true;
    hw_ekf_es_Calibrationwrite_Init(&hw_ekf_est_all_para_DW.Calibrationwrite_p);

    /* End of SystemInitialize for SubSystem: '<Root>/Initialize Function' */

    /* Start for MATLABSystem: '<S4>/Encoder1' */
    hw_ekf_est_all_para_DW.obj_g.Index = 0U;
    hw_ekf_est_all_para_DW.obj_g.matlabCodegenIsDeleted = false;
    hw_ekf_est_all_para_DW.obj_g.SampleTime =
      hw_ekf_est_all_para_P.Encoder1_SampleTime;
    hw_ekf_est_all_para_DW.obj_g.isSetupComplete = false;
    hw_ekf_est_all_para_DW.obj_g.isInitialized = 1L;
    MW_EncoderSetup(2UL, 3UL, &hw_ekf_est_all_para_DW.obj_g.Index);
    hw_ekf_est_all_para_DW.obj_g.isSetupComplete = true;
    hw_ekf_est_all_para_DW.obj_g.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S4>/Encoder1' */
    MW_EncoderReset(hw_ekf_est_all_para_DW.obj_g.Index);

    /* Start for MATLABSystem: '<Root>/Current Reg read' */
    hw_ekf_est_all_para_DW.obj.matlabCodegenIsDeleted = true;
    hw_ekf_est_all_para_DW.obj.DefaultMaximumBusSpeedInHz = 400000.0;
    hw_ekf_est_all_para_DW.obj.isInitialized = 0L;
    hw_ekf_est_all_para_DW.obj.SampleTime = -1.0;
    hw_ekf_est_all_para_DW.obj.I2CDriverObj.MW_I2C_HANDLE = NULL;
    hw_ekf_est_all_para_DW.obj.matlabCodegenIsDeleted = false;
    hw_ekf_est_all_para_DW.obj.SampleTime =
      hw_ekf_est_all_para_P.CurrentRegread_SampleTime;
    obj = &hw_ekf_est_all_para_DW.obj;
    hw_ekf_est_all_para_DW.obj.isSetupComplete = false;
    hw_ekf_est_all_para_DW.obj.isInitialized = 1L;
    hw_ekf_est_all_para_B.modename = MW_I2C_MASTER;
    hw_ekf_est_all_para_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(hw_ekf_est_all_para_B.i2cname,
      hw_ekf_est_all_para_B.modename);
    hw_ekf_est_all_para_DW.obj.BusSpeed = 100000UL;
    hw_ekf_est_all_para_B.varargin_1 = hw_ekf_est_all_para_DW.obj.BusSpeed;
    MW_I2C_SetBusSpeed(hw_ekf_est_all_para_DW.obj.I2CDriverObj.MW_I2C_HANDLE,
                       hw_ekf_est_all_para_B.varargin_1);
    hw_ekf_est_all_para_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Output' */
    hw_ekf_est_all_para_DW.obj_d.matlabCodegenIsDeleted = false;
    hw_ekf_est_all_para_DW.obj_d.isInitialized = 1L;
    digitalIOSetup(5, 1);
    hw_ekf_est_all_para_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Output1' */
    hw_ekf_est_all_para_DW.obj_c.matlabCodegenIsDeleted = false;
    hw_ekf_est_all_para_DW.obj_c.isInitialized = 1L;
    digitalIOSetup(7, 1);
    hw_ekf_est_all_para_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM' */
    hw_ekf_est_all_para_DW.obj_i.matlabCodegenIsDeleted = true;
    hw_ekf_est_all_para_DW.obj_i.isInitialized = 0L;
    hw_ekf_est_all_para_DW.obj_i.matlabCodegenIsDeleted = false;
    obj_0 = &hw_ekf_est_all_para_DW.obj_i;
    hw_ekf_est_all_para_DW.obj_i.isSetupComplete = false;
    hw_ekf_est_all_para_DW.obj_i.isInitialized = 1L;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(4UL, 0.0, 0.0);
    hw_ekf_est_all_para_DW.obj_i.isSetupComplete = true;
    hw_ekf_es_Calibrationwrite_Init(&hw_ekf_est_all_para_DW.Calibrationwrite);

    /* Outputs for Atomic SubSystem: '<Root>/Initialize Function' */
    /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
     *  Constant: '<S7>/Constant3'
     */
    hw_ekf_est_all_para_B.d = floor(hw_ekf_est_all_para_P.Constant3_Value);
    if (rtIsNaN(hw_ekf_est_all_para_B.d) || rtIsInf(hw_ekf_est_all_para_B.d)) {
      hw_ekf_est_all_para_B.d = 0.0;
    } else {
      hw_ekf_est_all_para_B.d = fmod(hw_ekf_est_all_para_B.d, 65536.0);
    }

    i = hw_ekf_est_all_para_B.d < 0.0 ? -(int16_T)(uint16_T)
      -hw_ekf_est_all_para_B.d : (int16_T)(uint16_T)hw_ekf_est_all_para_B.d;

    /* End of DataTypeConversion: '<S7>/Data Type Conversion' */

    /* MATLABSystem: '<S7>/Configuration write' */
    memcpy((void *)&SwappedDataBytes[0], (void *)&i, (uint16_T)((size_t)2 *
            sizeof(uint8_T)));
    b_x[0] = SwappedDataBytes[1];
    b_x[1] = SwappedDataBytes[0];
    memcpy((void *)&i, (void *)&b_x[0], (uint16_T)((size_t)1 * sizeof(int16_T)));
    memcpy((void *)&SwappedDataBytes[0], (void *)&i, (uint16_T)((size_t)2 *
            sizeof(uint8_T)));
    hw_ekf_est_all_para_B.b_SwappedDataBytes[0] = 0U;
    hw_ekf_est_all_para_B.b_SwappedDataBytes[1] = SwappedDataBytes[0];
    hw_ekf_est_all_para_B.b_SwappedDataBytes[2] = SwappedDataBytes[1];
    MW_I2C_MasterWrite(hw_ekf_est_all_para_DW.obj_o.I2CDriverObj.MW_I2C_HANDLE,
                       64UL, &hw_ekf_est_all_para_B.b_SwappedDataBytes[0], 3UL,
                       false, false);

    /* DataTypeConversion: '<S8>/Data Type Conversion' incorporates:
     *  Constant: '<S8>/Constant2'
     */
    hw_ekf_est_all_para_B.d = floor(hw_ekf_est_all_para_P.Constant2_Value);
    if (rtIsNaN(hw_ekf_est_all_para_B.d) || rtIsInf(hw_ekf_est_all_para_B.d)) {
      hw_ekf_est_all_para_B.d = 0.0;
    } else {
      hw_ekf_est_all_para_B.d = fmod(hw_ekf_est_all_para_B.d, 65536.0);
    }

    /* DataTypeConversion: '<S8>/Data Type Conversion' */
    rtb_DataTypeConversion_l = hw_ekf_est_all_para_B.d < 0.0 ? -(int16_T)
      (uint16_T)-hw_ekf_est_all_para_B.d : (int16_T)(uint16_T)
      hw_ekf_est_all_para_B.d;
    hw_ekf_est_all_Calibrationwrite(rtb_DataTypeConversion_l,
      &hw_ekf_est_all_para_DW.Calibrationwrite_p);

    /* End of Outputs for SubSystem: '<Root>/Initialize Function' */
  }
}

/* Model terminate function */
void hw_ekf_est_all_para_terminate(void)
{
  codertarget_arduinobase_i_lsc_T *obj;

  /* Terminate for MATLABSystem: '<S4>/Encoder1' */
  if (!hw_ekf_est_all_para_DW.obj_g.matlabCodegenIsDeleted) {
    hw_ekf_est_all_para_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((hw_ekf_est_all_para_DW.obj_g.isInitialized == 1L) &&
        hw_ekf_est_all_para_DW.obj_g.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Encoder1' */

  /* Terminate for MATLABSystem: '<Root>/Current Reg read' */
  if (!hw_ekf_est_all_para_DW.obj.matlabCodegenIsDeleted) {
    hw_ekf_est_all_para_DW.obj.matlabCodegenIsDeleted = true;
    if ((hw_ekf_est_all_para_DW.obj.isInitialized == 1L) &&
        hw_ekf_est_all_para_DW.obj.isSetupComplete) {
      MW_I2C_Close(hw_ekf_est_all_para_DW.obj.I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Current Reg read' */
  /* Terminate for MATLABSystem: '<S4>/Digital Output' */
  if (!hw_ekf_est_all_para_DW.obj_d.matlabCodegenIsDeleted) {
    hw_ekf_est_all_para_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output1' */
  if (!hw_ekf_est_all_para_DW.obj_c.matlabCodegenIsDeleted) {
    hw_ekf_est_all_para_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S4>/PWM' */
  obj = &hw_ekf_est_all_para_DW.obj_i;
  if (!hw_ekf_est_all_para_DW.obj_i.matlabCodegenIsDeleted) {
    hw_ekf_est_all_para_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((hw_ekf_est_all_para_DW.obj_i.isInitialized == 1L) &&
        hw_ekf_est_all_para_DW.obj_i.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_SetDutyCycle
        (hw_ekf_est_all_para_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_Close(hw_ekf_est_all_para_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM' */
  hw_ekf_es_Calibrationwrite_Term(&hw_ekf_est_all_para_DW.Calibrationwrite);

  /* Terminate for Atomic SubSystem: '<Root>/Initialize Function' */
  /* Terminate for MATLABSystem: '<S7>/Configuration write' */
  if (!hw_ekf_est_all_para_DW.obj_o.matlabCodegenIsDeleted) {
    hw_ekf_est_all_para_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((hw_ekf_est_all_para_DW.obj_o.isInitialized == 1L) &&
        hw_ekf_est_all_para_DW.obj_o.isSetupComplete) {
      MW_I2C_Close(hw_ekf_est_all_para_DW.obj_o.I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Configuration write' */
  hw_ekf_es_Calibrationwrite_Term(&hw_ekf_est_all_para_DW.Calibrationwrite_p);

  /* End of Terminate for SubSystem: '<Root>/Initialize Function' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
