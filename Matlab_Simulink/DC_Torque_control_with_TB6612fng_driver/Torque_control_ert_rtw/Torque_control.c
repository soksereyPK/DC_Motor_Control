/*
 * File: Torque_control.c
 *
 * Code generated for Simulink model 'Torque_control'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Aug 26 16:07:10 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Torque_control.h"
#include "rtwtypes.h"
#include "Torque_control_private.h"
#include "Torque_control_types.h"
#include <string.h>
#include <stddef.h>
#include <math.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_Torque_control_T Torque_control_B;

/* Block states (default storage) */
DW_Torque_control_T Torque_control_DW;

/* Real-time model */
static RT_MODEL_Torque_control_T Torque_control_M_;
RT_MODEL_Torque_control_T *const Torque_control_M = &Torque_control_M_;

/* System initialize for atomic system: */
void Torque_co_Calibrationwrite_Init(DW_Calibrationwrite_Torque_co_T *localDW)
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
void Torque_control_Calibrationwrite(int16_T rtu_0,
  DW_Calibrationwrite_Torque_co_T *localDW)
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
void Torque_co_Calibrationwrite_Term(DW_Calibrationwrite_Torque_co_T *localDW)
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
void Torque_control_step(void)
{
  /* local block i/o variables */
  int16_T rtb_DataTypeConversion;

  {
    codertarget_arduinobase_i_h3r_T *obj;
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

    /* Reset subsysRan breadcrumbs */
    srClearBC(Torque_control_DW.Subsystem1_SubsysRanBC);

    /* MATLABSystem: '<S5>/Encoder1' */
    if (Torque_control_DW.obj_j.SampleTime !=
        Torque_control_P.Encoder1_SampleTime) {
      Torque_control_DW.obj_j.SampleTime = Torque_control_P.Encoder1_SampleTime;
    }

    if (Torque_control_DW.obj_j.TunablePropsChanged) {
      Torque_control_DW.obj_j.TunablePropsChanged = false;
    }

    MW_EncoderRead(Torque_control_DW.obj_j.Index, &rtb_Encoder1_0);

    /* Gain: '<S5>/Gain2' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion1'
     *  MATLABSystem: '<S5>/Encoder1'
     */
    Torque_control_B.Gain2 = Torque_control_P.Gain2_Gain * (real_T)
      rtb_Encoder1_0;

    /* Derivative: '<Root>/Derivative' incorporates:
     *  Clock: '<Root>/Clock'
     */
    Torque_control_B.y_tmp_idx_0 = Torque_control_M->Timing.t[0];
    if ((Torque_control_DW.TimeStampA >= Torque_control_B.y_tmp_idx_0) &&
        (Torque_control_DW.TimeStampB >= Torque_control_B.y_tmp_idx_0)) {
      Torque_control_B.Derivative = 0.0;
    } else {
      Torque_control_B.Derivative = Torque_control_DW.TimeStampA;
      lastU = &Torque_control_DW.LastUAtTimeA;
      if (Torque_control_DW.TimeStampA < Torque_control_DW.TimeStampB) {
        if (Torque_control_DW.TimeStampB < Torque_control_B.y_tmp_idx_0) {
          Torque_control_B.Derivative = Torque_control_DW.TimeStampB;
          lastU = &Torque_control_DW.LastUAtTimeB;
        }
      } else if (Torque_control_DW.TimeStampA >= Torque_control_B.y_tmp_idx_0) {
        Torque_control_B.Derivative = Torque_control_DW.TimeStampB;
        lastU = &Torque_control_DW.LastUAtTimeB;
      }

      Torque_control_B.Derivative = (Torque_control_B.Gain2 - *lastU) /
        (Torque_control_B.y_tmp_idx_0 - Torque_control_B.Derivative);
    }

    /* End of Derivative: '<Root>/Derivative' */

    /* Sin: '<Root>/Sine Wave' */
    Torque_control_B.SineWave = sin(Torque_control_P.SineWave_Freq *
      Torque_control_M->Timing.t[0] + Torque_control_P.SineWave_Phase) *
      Torque_control_P.SineWave_Amp + Torque_control_P.SineWave_Bias;

    /* MATLAB Function: '<S7>/MATLAB Function3' incorporates:
     *  Delay: '<S7>/Delay'
     *  Delay: '<S7>/Delay1'
     *  MATLAB Function: '<S7>/MATLAB Function'
     */
    Torque_control_B.u = Torque_control_DW.Delay_DSTATE[0];
    if (!rtIsNaN(Torque_control_B.u)) {
      if (Torque_control_B.u < 0.0) {
        Torque_control_B.u = -1.0;
      } else {
        Torque_control_B.u = (Torque_control_B.u > 0.0);
      }
    }

    Torque_control_B.x[0] = ((-Torque_control_DW.Delay_DSTATE[1] *
      Torque_control_DW.Delay_DSTATE[0] + Torque_control_B.SineWave *
      Torque_control_DW.Delay_DSTATE[2]) - Torque_control_DW.Delay_DSTATE[3] *
      Torque_control_B.u) * 0.01 + Torque_control_DW.Delay_DSTATE[0];
    Torque_control_B.x[1] = Torque_control_DW.Delay_DSTATE[1];
    Torque_control_B.x[2] = Torque_control_DW.Delay_DSTATE[2];
    Torque_control_B.x[3] = Torque_control_DW.Delay_DSTATE[3];
    memset(&Torque_control_B.b_I[0], 0, sizeof(real_T) << 4U);
    Torque_control_B.u = Torque_control_DW.Delay_DSTATE[0];
    Torque_control_B.Ak[0] = 0.01 * -Torque_control_DW.Delay_DSTATE[1] + 1.0;
    Torque_control_B.Ak[1] = Torque_control_B.b_I[1];
    Torque_control_B.Ak[2] = Torque_control_B.b_I[2];
    Torque_control_B.Ak[3] = Torque_control_B.b_I[3];
    Torque_control_B.Ak[4] = 0.01 * -Torque_control_DW.Delay_DSTATE[0] +
      Torque_control_B.b_I[4];
    Torque_control_B.Ak[5] = 1.0;
    Torque_control_B.Ak[6] = Torque_control_B.b_I[6];
    Torque_control_B.Ak[7] = Torque_control_B.b_I[7];
    Torque_control_B.Ak[8] = 0.01 * Torque_control_B.SineWave +
      Torque_control_B.b_I[8];
    Torque_control_B.Ak[9] = Torque_control_B.b_I[9];
    Torque_control_B.Ak[10] = 1.0;
    Torque_control_B.Ak[11] = Torque_control_B.b_I[11];
    if (!rtIsNaN(Torque_control_B.u)) {
      if (Torque_control_B.u < 0.0) {
        Torque_control_B.u = -1.0;
      } else {
        Torque_control_B.u = (Torque_control_B.u > 0.0);
      }
    }

    Torque_control_B.Ak[12] = 0.01 * -Torque_control_B.u + Torque_control_B.b_I
      [12];
    Torque_control_B.Ak[13] = Torque_control_B.b_I[13];
    Torque_control_B.Ak[14] = Torque_control_B.b_I[14];
    Torque_control_B.Ak[15] = 1.0;
    for (rtb_IN2 = 0; rtb_IN2 < 4; rtb_IN2++) {
      for (rtb_IN1 = 0; rtb_IN1 < 4; rtb_IN1++) {
        Ak_tmp_tmp = rtb_IN1 << 2;
        Ak_tmp = rtb_IN2 + Ak_tmp_tmp;
        Torque_control_B.Ak_m[Ak_tmp] = 0.0;
        Torque_control_B.Ak_m[Ak_tmp] +=
          Torque_control_DW.Delay1_DSTATE[Ak_tmp_tmp] *
          Torque_control_B.Ak[rtb_IN2];
        Torque_control_B.Ak_m[Ak_tmp] +=
          Torque_control_DW.Delay1_DSTATE[Ak_tmp_tmp + 1] *
          Torque_control_B.Ak[rtb_IN2 + 4];
        Torque_control_B.Ak_m[Ak_tmp] +=
          Torque_control_DW.Delay1_DSTATE[Ak_tmp_tmp + 2] *
          Torque_control_B.Ak[rtb_IN2 + 8];
        Torque_control_B.Ak_m[Ak_tmp] +=
          Torque_control_DW.Delay1_DSTATE[Ak_tmp_tmp + 3] *
          Torque_control_B.Ak[rtb_IN2 + 12];
      }

      for (rtb_IN1 = 0; rtb_IN1 < 4; rtb_IN1++) {
        Ak_tmp_tmp = (rtb_IN1 << 2) + rtb_IN2;
        Torque_control_B.b_I[Ak_tmp_tmp] = (((Torque_control_B.Ak_m[rtb_IN2 + 4]
          * Torque_control_B.Ak[rtb_IN1 + 4] + Torque_control_B.Ak_m[rtb_IN2] *
          Torque_control_B.Ak[rtb_IN1]) + Torque_control_B.Ak_m[rtb_IN2 + 8] *
          Torque_control_B.Ak[rtb_IN1 + 8]) + Torque_control_B.Ak_m[rtb_IN2 + 12]
          * Torque_control_B.Ak[rtb_IN1 + 12]) + c[Ak_tmp_tmp];
      }

      y_tmp[rtb_IN2] = d[rtb_IN2];
      y_tmp_0[rtb_IN2] = d[rtb_IN2];
    }

    Torque_control_B.u = 0.0;
    for (rtb_IN1 = 0; rtb_IN1 < 4; rtb_IN1++) {
      rtb_IN2 = rtb_IN1 << 2;
      Torque_control_B.u += (((Torque_control_B.b_I[rtb_IN2 + 1] * (real_T)
        y_tmp_0[1] + Torque_control_B.b_I[rtb_IN2] * (real_T)y_tmp_0[0]) +
        Torque_control_B.b_I[rtb_IN2 + 2] * (real_T)y_tmp_0[2]) +
        Torque_control_B.b_I[rtb_IN2 + 3] * (real_T)y_tmp_0[3]) * (real_T)
        y_tmp[rtb_IN1];
    }

    Torque_control_B.y_tmp = 0.0;
    for (rtb_IN1 = 0; rtb_IN1 < 4; rtb_IN1++) {
      Torque_control_B.Wk[rtb_IN1] = (((Torque_control_B.b_I[rtb_IN1 + 4] *
        (real_T)y_tmp[1] + Torque_control_B.b_I[rtb_IN1] * (real_T)y_tmp[0]) +
        Torque_control_B.b_I[rtb_IN1 + 8] * (real_T)y_tmp[2]) +
        Torque_control_B.b_I[rtb_IN1 + 12] * (real_T)y_tmp[3]) /
        (Torque_control_B.u + 0.01);
      Torque_control_B.y_tmp += (real_T)y_tmp_0[rtb_IN1] *
        Torque_control_B.x[rtb_IN1];
    }

    Torque_control_B.u = Torque_control_B.Derivative - (0.0 *
      Torque_control_B.SineWave + Torque_control_B.y_tmp);
    for (rtb_IN1 = 0; rtb_IN1 < 4; rtb_IN1++) {
      y_tmp_1 = y_tmp_0[rtb_IN1];
      Torque_control_B.x[rtb_IN1] += Torque_control_B.Wk[rtb_IN1] *
        Torque_control_B.u;
      rtb_IN2 = rtb_IN1 << 2;
      Torque_control_B.Ak[rtb_IN2] = Torque_control_B.Wk[0] * (real_T)y_tmp_1;
      Torque_control_B.Ak[rtb_IN2 + 1] = Torque_control_B.Wk[1] * (real_T)
        y_tmp_1;
      Torque_control_B.Ak[rtb_IN2 + 2] = Torque_control_B.Wk[2] * (real_T)
        y_tmp_1;
      Torque_control_B.Ak[rtb_IN2 + 3] = Torque_control_B.Wk[3] * (real_T)
        y_tmp_1;
    }

    for (rtb_IN1 = 0; rtb_IN1 < 4; rtb_IN1++) {
      for (rtb_IN2 = 0; rtb_IN2 < 4; rtb_IN2++) {
        Ak_tmp_tmp = rtb_IN2 << 2;
        Ak_tmp = Ak_tmp_tmp + rtb_IN1;
        Torque_control_B.P[Ak_tmp] = Torque_control_B.b_I[Ak_tmp] -
          (((Torque_control_B.b_I[Ak_tmp_tmp + 1] * Torque_control_B.Ak[rtb_IN1
             + 4] + Torque_control_B.b_I[Ak_tmp_tmp] *
             Torque_control_B.Ak[rtb_IN1]) + Torque_control_B.b_I[Ak_tmp_tmp + 2]
            * Torque_control_B.Ak[rtb_IN1 + 8]) +
           Torque_control_B.b_I[Ak_tmp_tmp + 3] * Torque_control_B.Ak[rtb_IN1 +
           12]);
      }
    }

    /* End of MATLAB Function: '<S7>/MATLAB Function3' */

    /* DataTypeConversion: '<Root>/Data Type Conversion6' */
    Torque_control_B.DataTypeConversion6 = (real32_T)Torque_control_B.x[1];

    /* MATLABSystem: '<Root>/Current Reg read1' */
    if (Torque_control_DW.obj.SampleTime !=
        Torque_control_P.CurrentRegread1_SampleTime) {
      Torque_control_DW.obj.SampleTime =
        Torque_control_P.CurrentRegread1_SampleTime;
    }

    status = 4U;
    status = MW_I2C_MasterWrite(Torque_control_DW.obj.I2CDriverObj.MW_I2C_HANDLE,
      64UL, &status, 1UL, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(Torque_control_DW.obj.I2CDriverObj.MW_I2C_HANDLE, 64UL,
                        &output_raw[0], 2UL, false, true);
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

    /* Gain: '<Root>/Gain3' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion1'
     *  Gain: '<Root>/Gain2'
     *  MATLABSystem: '<Root>/Current Reg read1'
     */
    Torque_control_B.current_A = (real_T)((int32_T)Torque_control_P.Gain2_Gain_h
      * rtb_IN1) * 1.9073486328125E-6 * Torque_control_P.Gain3_Gain;

    /* Outputs for Enabled SubSystem: '<Root>/Subsystem1' incorporates:
     *  EnablePort: '<S6>/Enable'
     */
    /* RelationalOperator: '<S2>/Compare' incorporates:
     *  Constant: '<S2>/Constant'
     */
    Torque_control_DW.Subsystem1_MODE = (Torque_control_B.y_tmp_idx_0 >=
      Torque_control_P.CompareToConstant_const);
    if (Torque_control_DW.Subsystem1_MODE) {
      /* MATLAB Function: '<S6>/MATLAB Function1' incorporates:
       *  Delay: '<S6>/Delay2'
       *  Delay: '<S6>/Delay3'
       */
      Torque_control_B.y_tmp_idx_0_tmp = Torque_control_B.current_A *
        Torque_control_DW.Delay2_DSTATE[0];
      Torque_control_B.y_tmp_idx_0 = Torque_control_B.Derivative *
        Torque_control_DW.Delay2_DSTATE[1] + Torque_control_B.y_tmp_idx_0_tmp;
      y_tmp_idx_1_tmp = Torque_control_B.Derivative *
        Torque_control_DW.Delay2_DSTATE[3];
      Torque_control_B.y_tmp = Torque_control_B.current_A *
        Torque_control_DW.Delay2_DSTATE[2] + y_tmp_idx_1_tmp;
      Torque_control_B.u = Torque_control_B.y_tmp_idx_0 *
        Torque_control_B.current_A + Torque_control_B.y_tmp *
        Torque_control_B.Derivative;
      Torque_control_B.y_tmp_idx_0_tmp = (Torque_control_DW.Delay2_DSTATE[2] *
        Torque_control_B.Derivative + Torque_control_B.y_tmp_idx_0_tmp) /
        (Torque_control_B.u + 1.0);
      Torque_control_B.u = (Torque_control_DW.Delay2_DSTATE[1] *
                            Torque_control_B.current_A + y_tmp_idx_1_tmp) /
        (Torque_control_B.u + 1.0);
      Torque_control_B.P_n[0] = Torque_control_DW.Delay2_DSTATE[0] -
        Torque_control_B.y_tmp_idx_0_tmp * Torque_control_B.y_tmp_idx_0;
      Torque_control_B.P_n[1] = Torque_control_DW.Delay2_DSTATE[1] -
        Torque_control_B.u * Torque_control_B.y_tmp_idx_0;
      Torque_control_B.P_n[2] = Torque_control_DW.Delay2_DSTATE[2] -
        Torque_control_B.y_tmp_idx_0_tmp * Torque_control_B.y_tmp;
      Torque_control_B.P_n[3] = Torque_control_DW.Delay2_DSTATE[3] -
        Torque_control_B.u * Torque_control_B.y_tmp;
      Torque_control_B.u = Torque_control_B.SineWave -
        (Torque_control_B.current_A * Torque_control_DW.Delay3_DSTATE[0] +
         Torque_control_B.Derivative * Torque_control_DW.Delay3_DSTATE[1]);
      Torque_control_B.x_a[0] = (Torque_control_B.P_n[0] *
        Torque_control_B.current_A + Torque_control_B.P_n[2] *
        Torque_control_B.Derivative) * Torque_control_B.u +
        Torque_control_DW.Delay3_DSTATE[0];
      Torque_control_B.x_a[1] = (Torque_control_B.P_n[1] *
        Torque_control_B.current_A + Torque_control_B.P_n[3] *
        Torque_control_B.Derivative) * Torque_control_B.u +
        Torque_control_DW.Delay3_DSTATE[1];
      srUpdateBC(Torque_control_DW.Subsystem1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<Root>/Subsystem1' */

    /* DataTypeConversion: '<Root>/Data Type Conversion4' */
    Torque_control_B.DataTypeConversion4 = (real32_T)Torque_control_B.x_a[0];

    /* DataTypeConversion: '<Root>/Data Type Conversion5' */
    Torque_control_B.DataTypeConversion5 = (real32_T)Torque_control_B.x_a[1];

    /* DataTypeConversion: '<Root>/Data Type Conversion2' */
    Torque_control_B.DataTypeConversion2 = (real32_T)Torque_control_B.x[2];

    /* DataTypeConversion: '<Root>/Data Type Conversion3' */
    Torque_control_B.DataTypeConversion3 = (real32_T)Torque_control_B.x[3];

    /* MATLAB Function: '<Root>/MATLAB Function3' */
    Torque_control_B.Ra = Torque_control_B.DataTypeConversion4;
    Torque_control_B.kt = Torque_control_B.DataTypeConversion5;
    Torque_control_B.J = Torque_control_B.kt / (Torque_control_B.Ra *
      Torque_control_B.DataTypeConversion2);
    Torque_control_B.Tc = Torque_control_B.DataTypeConversion3 *
      Torque_control_B.J;
    Torque_control_B.D = (Torque_control_B.DataTypeConversion6 *
                          Torque_control_B.Ra * Torque_control_B.J -
                          Torque_control_B.kt * Torque_control_B.kt) /
      Torque_control_B.Ra;

    /* DataTypeConversion: '<Root>/Data Type Conversion7' */
    Torque_control_B.w = (real32_T)Torque_control_B.x[0];

    /* MATLAB Function: '<S5>/MATLAB Function4' */
    Torque_control_B.Derivative = Torque_control_B.SineWave * 254.0 / 12.0;
    if (Torque_control_B.Derivative > 0.0) {
      rtb_IN1 = 1;
      rtb_IN2 = 0;
    } else if (Torque_control_B.Derivative < 0.0) {
      Torque_control_B.Derivative = fabs(Torque_control_B.Derivative);
      rtb_IN1 = 0;
      rtb_IN2 = 1;
    } else {
      Torque_control_B.Derivative = 0.0;
      rtb_IN1 = 0;
      rtb_IN2 = 0;
    }

    /* End of MATLAB Function: '<S5>/MATLAB Function4' */

    /* MATLABSystem: '<S5>/Digital Output' */
    writeDigitalPin(5, (uint8_T)rtb_IN1);

    /* MATLABSystem: '<S5>/Digital Output1' */
    writeDigitalPin(7, (uint8_T)rtb_IN2);

    /* MATLABSystem: '<S5>/PWM' */
    obj = &Torque_control_DW.obj_f;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
    if (!(Torque_control_B.Derivative <= 255.0)) {
      Torque_control_B.Derivative = 255.0;
    }

    MW_PWM_SetDutyCycle(Torque_control_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE,
                        Torque_control_B.Derivative);

    /* End of MATLABSystem: '<S5>/PWM' */
    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  Constant: '<S1>/Constant2'
     */
    Torque_control_B.y_tmp_idx_0 = floor(Torque_control_P.Constant2_Value_a);
    if (rtIsNaN(Torque_control_B.y_tmp_idx_0) || rtIsInf
        (Torque_control_B.y_tmp_idx_0)) {
      Torque_control_B.y_tmp_idx_0 = 0.0;
    } else {
      Torque_control_B.y_tmp_idx_0 = fmod(Torque_control_B.y_tmp_idx_0, 65536.0);
    }

    /* DataTypeConversion: '<S1>/Data Type Conversion' */
    rtb_DataTypeConversion = Torque_control_B.y_tmp_idx_0 < 0.0 ? -(int16_T)
      (uint16_T)-Torque_control_B.y_tmp_idx_0 : (int16_T)(uint16_T)
      Torque_control_B.y_tmp_idx_0;
    Torque_control_Calibrationwrite(rtb_DataTypeConversion,
      &Torque_control_DW.Calibrationwrite);
  }

  {
    real_T *lastU;

    /* Update for Delay: '<S7>/Delay1' */
    memcpy(&Torque_control_DW.Delay1_DSTATE[0], &Torque_control_B.P[0], sizeof
           (real_T) << 4U);

    /* Update for Delay: '<S7>/Delay' */
    Torque_control_DW.Delay_DSTATE[0] = Torque_control_B.x[0];
    Torque_control_DW.Delay_DSTATE[1] = Torque_control_B.x[1];
    Torque_control_DW.Delay_DSTATE[2] = Torque_control_B.x[2];
    Torque_control_DW.Delay_DSTATE[3] = Torque_control_B.x[3];

    /* Update for Derivative: '<Root>/Derivative' */
    if (Torque_control_DW.TimeStampA == (rtInf)) {
      Torque_control_DW.TimeStampA = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeA;
    } else if (Torque_control_DW.TimeStampB == (rtInf)) {
      Torque_control_DW.TimeStampB = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeB;
    } else if (Torque_control_DW.TimeStampA < Torque_control_DW.TimeStampB) {
      Torque_control_DW.TimeStampA = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeA;
    } else {
      Torque_control_DW.TimeStampB = Torque_control_M->Timing.t[0];
      lastU = &Torque_control_DW.LastUAtTimeB;
    }

    *lastU = Torque_control_B.Gain2;

    /* End of Update for Derivative: '<Root>/Derivative' */

    /* Update for Enabled SubSystem: '<Root>/Subsystem1' incorporates:
     *  EnablePort: '<S6>/Enable'
     */
    if (Torque_control_DW.Subsystem1_MODE) {
      /* Update for Delay: '<S6>/Delay2' */
      Torque_control_DW.Delay2_DSTATE[0] = Torque_control_B.P_n[0];
      Torque_control_DW.Delay2_DSTATE[1] = Torque_control_B.P_n[1];
      Torque_control_DW.Delay2_DSTATE[2] = Torque_control_B.P_n[2];
      Torque_control_DW.Delay2_DSTATE[3] = Torque_control_B.P_n[3];

      /* Update for Delay: '<S6>/Delay3' */
      Torque_control_DW.Delay3_DSTATE[0] = Torque_control_B.x_a[0];
      Torque_control_DW.Delay3_DSTATE[1] = Torque_control_B.x_a[1];
    }

    /* End of Update for SubSystem: '<Root>/Subsystem1' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Torque_control_M->Timing.clockTick0 * 1) + 0)
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
      ((Torque_control_M->Timing.clockTick1 * 1) + 0)
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
  Torque_control_M->Timing.t[0] =
    ((time_T)(++Torque_control_M->Timing.clockTick0)) *
    Torque_control_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Torque_control_M->Timing.clockTick1++;
  }

  switch (Torque_control_M->Timing.rtmDbBufReadBuf2) {
   case 0:
    Torque_control_M->Timing.rtmDbBufWriteBuf2 = 1;
    break;

   case 1:
    Torque_control_M->Timing.rtmDbBufWriteBuf2 = 0;
    break;

   default:
    Torque_control_M->Timing.rtmDbBufWriteBuf2 =
      !Torque_control_M->Timing.rtmDbBufLastBufWr2;
    break;
  }

  Torque_control_M->Timing.rtmDbBufClockTick2
    [Torque_control_M->Timing.rtmDbBufWriteBuf2] =
    Torque_control_M->Timing.clockTick0;
  Torque_control_M->Timing.rtmDbBufLastBufWr2 =
    Torque_control_M->Timing.rtmDbBufWriteBuf2;
  Torque_control_M->Timing.rtmDbBufWriteBuf2 = 0xFF;
}

/* Model initialize function */
void Torque_control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Torque_control_M->solverInfo,
                          &Torque_control_M->Timing.simTimeStep);
    rtsiSetTPtr(&Torque_control_M->solverInfo, &rtmGetTPtr(Torque_control_M));
    rtsiSetStepSizePtr(&Torque_control_M->solverInfo,
                       &Torque_control_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Torque_control_M->solverInfo, (&rtmGetErrorStatus
      (Torque_control_M)));
    rtsiSetRTModelPtr(&Torque_control_M->solverInfo, Torque_control_M);
  }

  rtsiSetSimTimeStep(&Torque_control_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Torque_control_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Torque_control_M, &Torque_control_M->Timing.tArray[0]);
  rtmSetTFinal(Torque_control_M, 50.0);
  Torque_control_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Torque_control_M->Sizes.checksums[0] = (1066229772U);
  Torque_control_M->Sizes.checksums[1] = (2742355446U);
  Torque_control_M->Sizes.checksums[2] = (464244847U);
  Torque_control_M->Sizes.checksums[3] = (2326988256U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[16];
    Torque_control_M->extModeInfo = (&rt_ExtModeInfo);
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
    systemRan[12] = (sysRanDType *)&Torque_control_DW.Subsystem1_SubsysRanBC;
    systemRan[13] = (sysRanDType *)&Torque_control_DW.Subsystem1_SubsysRanBC;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Torque_control_M->extModeInfo,
      &Torque_control_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Torque_control_M->extModeInfo,
                        Torque_control_M->Sizes.checksums);
    rteiSetTPtr(Torque_control_M->extModeInfo, rtmGetTPtr(Torque_control_M));
  }

  {
    /* local block i/o variables */
    int16_T rtb_DataTypeConversion_o;
    codertarget_arduinobase_i_h3r_T *obj_0;
    codertarget_arduinobase_in_h3_T *obj;
    codertarget_arduinobase_inter_T *obj_1;
    int16_T i;
    uint8_T SwappedDataBytes[2];
    uint8_T b_x[2];
    Torque_control_M->Timing.rtmDbBufReadBuf2 = 0xFF;
    Torque_control_M->Timing.rtmDbBufWriteBuf2 = 0xFF;
    Torque_control_M->Timing.rtmDbBufLastBufWr2 = 0;

    /* InitializeConditions for Delay: '<S7>/Delay1' */
    memcpy(&Torque_control_DW.Delay1_DSTATE[0],
           &Torque_control_P.Delay1_InitialCondition[0], sizeof(real_T) << 4U);

    /* InitializeConditions for Derivative: '<Root>/Derivative' */
    Torque_control_DW.TimeStampA = (rtInf);
    Torque_control_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Delay: '<S7>/Delay' */
    Torque_control_DW.Delay_DSTATE[0] = Torque_control_P.Delay_InitialCondition
      [0];

    /* SystemInitialize for Enabled SubSystem: '<Root>/Subsystem1' */
    /* InitializeConditions for Delay: '<S6>/Delay2' */
    Torque_control_DW.Delay2_DSTATE[0] =
      Torque_control_P.Delay2_InitialCondition[0];

    /* End of SystemInitialize for SubSystem: '<Root>/Subsystem1' */

    /* InitializeConditions for Delay: '<S7>/Delay' */
    Torque_control_DW.Delay_DSTATE[1] = Torque_control_P.Delay_InitialCondition
      [1];

    /* SystemInitialize for Enabled SubSystem: '<Root>/Subsystem1' */
    /* InitializeConditions for Delay: '<S6>/Delay2' */
    Torque_control_DW.Delay2_DSTATE[1] =
      Torque_control_P.Delay2_InitialCondition[1];

    /* End of SystemInitialize for SubSystem: '<Root>/Subsystem1' */

    /* InitializeConditions for Delay: '<S7>/Delay' */
    Torque_control_DW.Delay_DSTATE[2] = Torque_control_P.Delay_InitialCondition
      [2];

    /* SystemInitialize for Enabled SubSystem: '<Root>/Subsystem1' */
    /* InitializeConditions for Delay: '<S6>/Delay2' */
    Torque_control_DW.Delay2_DSTATE[2] =
      Torque_control_P.Delay2_InitialCondition[2];

    /* End of SystemInitialize for SubSystem: '<Root>/Subsystem1' */

    /* InitializeConditions for Delay: '<S7>/Delay' */
    Torque_control_DW.Delay_DSTATE[3] = Torque_control_P.Delay_InitialCondition
      [3];

    /* SystemInitialize for Enabled SubSystem: '<Root>/Subsystem1' */
    /* InitializeConditions for Delay: '<S6>/Delay2' */
    Torque_control_DW.Delay2_DSTATE[3] =
      Torque_control_P.Delay2_InitialCondition[3];

    /* InitializeConditions for Delay: '<S6>/Delay3' */
    Torque_control_DW.Delay3_DSTATE[0] =
      Torque_control_P.Delay3_InitialCondition[0];

    /* SystemInitialize for Outport: '<S6>/x' */
    Torque_control_B.x_a[0] = Torque_control_P.x_Y0;

    /* InitializeConditions for Delay: '<S6>/Delay3' */
    Torque_control_DW.Delay3_DSTATE[1] =
      Torque_control_P.Delay3_InitialCondition[1];

    /* SystemInitialize for Outport: '<S6>/x' */
    Torque_control_B.x_a[1] = Torque_control_P.x_Y0;

    /* End of SystemInitialize for SubSystem: '<Root>/Subsystem1' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Initialize Function1' */
    /* Start for MATLABSystem: '<S8>/Configuration write' */
    Torque_control_DW.obj_c.matlabCodegenIsDeleted = true;
    Torque_control_DW.obj_c.DefaultMaximumBusSpeedInHz = 400000.0;
    Torque_control_DW.obj_c.isInitialized = 0L;
    Torque_control_DW.obj_c.I2CDriverObj.MW_I2C_HANDLE = NULL;
    Torque_control_DW.obj_c.matlabCodegenIsDeleted = false;
    obj_1 = &Torque_control_DW.obj_c;
    Torque_control_DW.obj_c.isSetupComplete = false;
    Torque_control_DW.obj_c.isInitialized = 1L;
    Torque_control_B.modename = MW_I2C_MASTER;
    Torque_control_B.i2cname = 0;
    obj_1->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(Torque_control_B.i2cname,
      Torque_control_B.modename);
    Torque_control_DW.obj_c.BusSpeed = 100000UL;
    Torque_control_B.varargin_1 = Torque_control_DW.obj_c.BusSpeed;
    MW_I2C_SetBusSpeed(Torque_control_DW.obj_c.I2CDriverObj.MW_I2C_HANDLE,
                       Torque_control_B.varargin_1);
    Torque_control_DW.obj_c.isSetupComplete = true;
    Torque_co_Calibrationwrite_Init(&Torque_control_DW.Calibrationwrite_p);

    /* End of SystemInitialize for SubSystem: '<Root>/Initialize Function1' */

    /* Start for MATLABSystem: '<S5>/Encoder1' */
    Torque_control_DW.obj_j.Index = 0U;
    Torque_control_DW.obj_j.matlabCodegenIsDeleted = false;
    Torque_control_DW.obj_j.SampleTime = Torque_control_P.Encoder1_SampleTime;
    Torque_control_DW.obj_j.isSetupComplete = false;
    Torque_control_DW.obj_j.isInitialized = 1L;
    MW_EncoderSetup(2UL, 3UL, &Torque_control_DW.obj_j.Index);
    Torque_control_DW.obj_j.isSetupComplete = true;
    Torque_control_DW.obj_j.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S5>/Encoder1' */
    MW_EncoderReset(Torque_control_DW.obj_j.Index);

    /* Start for MATLABSystem: '<Root>/Current Reg read1' */
    Torque_control_DW.obj.matlabCodegenIsDeleted = true;
    Torque_control_DW.obj.DefaultMaximumBusSpeedInHz = 400000.0;
    Torque_control_DW.obj.isInitialized = 0L;
    Torque_control_DW.obj.SampleTime = -1.0;
    Torque_control_DW.obj.I2CDriverObj.MW_I2C_HANDLE = NULL;
    Torque_control_DW.obj.matlabCodegenIsDeleted = false;
    Torque_control_DW.obj.SampleTime =
      Torque_control_P.CurrentRegread1_SampleTime;
    obj = &Torque_control_DW.obj;
    Torque_control_DW.obj.isSetupComplete = false;
    Torque_control_DW.obj.isInitialized = 1L;
    Torque_control_B.modename = MW_I2C_MASTER;
    Torque_control_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(Torque_control_B.i2cname,
      Torque_control_B.modename);
    Torque_control_DW.obj.BusSpeed = 100000UL;
    Torque_control_B.varargin_1 = Torque_control_DW.obj.BusSpeed;
    MW_I2C_SetBusSpeed(Torque_control_DW.obj.I2CDriverObj.MW_I2C_HANDLE,
                       Torque_control_B.varargin_1);
    Torque_control_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Output' */
    Torque_control_DW.obj_l.matlabCodegenIsDeleted = false;
    Torque_control_DW.obj_l.isInitialized = 1L;
    digitalIOSetup(5, 1);
    Torque_control_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Output1' */
    Torque_control_DW.obj_b.matlabCodegenIsDeleted = false;
    Torque_control_DW.obj_b.isInitialized = 1L;
    digitalIOSetup(7, 1);
    Torque_control_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/PWM' */
    Torque_control_DW.obj_f.matlabCodegenIsDeleted = true;
    Torque_control_DW.obj_f.isInitialized = 0L;
    Torque_control_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_0 = &Torque_control_DW.obj_f;
    Torque_control_DW.obj_f.isSetupComplete = false;
    Torque_control_DW.obj_f.isInitialized = 1L;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(4UL, 0.0, 0.0);
    Torque_control_DW.obj_f.isSetupComplete = true;
    Torque_co_Calibrationwrite_Init(&Torque_control_DW.Calibrationwrite);

    /* Outputs for Atomic SubSystem: '<Root>/Initialize Function1' */
    /* DataTypeConversion: '<S8>/Data Type Conversion' incorporates:
     *  Constant: '<S8>/Constant3'
     */
    Torque_control_B.d = floor(Torque_control_P.Constant3_Value);
    if (rtIsNaN(Torque_control_B.d) || rtIsInf(Torque_control_B.d)) {
      Torque_control_B.d = 0.0;
    } else {
      Torque_control_B.d = fmod(Torque_control_B.d, 65536.0);
    }

    i = Torque_control_B.d < 0.0 ? -(int16_T)(uint16_T)-Torque_control_B.d :
      (int16_T)(uint16_T)Torque_control_B.d;

    /* End of DataTypeConversion: '<S8>/Data Type Conversion' */

    /* MATLABSystem: '<S8>/Configuration write' */
    memcpy((void *)&SwappedDataBytes[0], (void *)&i, (uint16_T)((size_t)2 *
            sizeof(uint8_T)));
    b_x[0] = SwappedDataBytes[1];
    b_x[1] = SwappedDataBytes[0];
    memcpy((void *)&i, (void *)&b_x[0], (uint16_T)((size_t)1 * sizeof(int16_T)));
    memcpy((void *)&SwappedDataBytes[0], (void *)&i, (uint16_T)((size_t)2 *
            sizeof(uint8_T)));
    Torque_control_B.b_SwappedDataBytes[0] = 0U;
    Torque_control_B.b_SwappedDataBytes[1] = SwappedDataBytes[0];
    Torque_control_B.b_SwappedDataBytes[2] = SwappedDataBytes[1];
    MW_I2C_MasterWrite(Torque_control_DW.obj_c.I2CDriverObj.MW_I2C_HANDLE, 64UL,
                       &Torque_control_B.b_SwappedDataBytes[0], 3UL, false,
                       false);

    /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
     *  Constant: '<S9>/Constant2'
     */
    Torque_control_B.d = floor(Torque_control_P.Constant2_Value);
    if (rtIsNaN(Torque_control_B.d) || rtIsInf(Torque_control_B.d)) {
      Torque_control_B.d = 0.0;
    } else {
      Torque_control_B.d = fmod(Torque_control_B.d, 65536.0);
    }

    /* DataTypeConversion: '<S9>/Data Type Conversion' */
    rtb_DataTypeConversion_o = Torque_control_B.d < 0.0 ? -(int16_T)(uint16_T)
      -Torque_control_B.d : (int16_T)(uint16_T)Torque_control_B.d;
    Torque_control_Calibrationwrite(rtb_DataTypeConversion_o,
      &Torque_control_DW.Calibrationwrite_p);

    /* End of Outputs for SubSystem: '<Root>/Initialize Function1' */
  }
}

/* Model terminate function */
void Torque_control_terminate(void)
{
  codertarget_arduinobase_i_h3r_T *obj;

  /* Terminate for MATLABSystem: '<S5>/Encoder1' */
  if (!Torque_control_DW.obj_j.matlabCodegenIsDeleted) {
    Torque_control_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Torque_control_DW.obj_j.isInitialized == 1L) &&
        Torque_control_DW.obj_j.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Encoder1' */
  /* Terminate for MATLABSystem: '<Root>/Current Reg read1' */
  if (!Torque_control_DW.obj.matlabCodegenIsDeleted) {
    Torque_control_DW.obj.matlabCodegenIsDeleted = true;
    if ((Torque_control_DW.obj.isInitialized == 1L) &&
        Torque_control_DW.obj.isSetupComplete) {
      MW_I2C_Close(Torque_control_DW.obj.I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Current Reg read1' */
  /* Terminate for MATLABSystem: '<S5>/Digital Output' */
  if (!Torque_control_DW.obj_l.matlabCodegenIsDeleted) {
    Torque_control_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output' */

  /* Terminate for MATLABSystem: '<S5>/Digital Output1' */
  if (!Torque_control_DW.obj_b.matlabCodegenIsDeleted) {
    Torque_control_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S5>/PWM' */
  obj = &Torque_control_DW.obj_f;
  if (!Torque_control_DW.obj_f.matlabCodegenIsDeleted) {
    Torque_control_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((Torque_control_DW.obj_f.isInitialized == 1L) &&
        Torque_control_DW.obj_f.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_SetDutyCycle(Torque_control_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);
      MW_PWM_Close(Torque_control_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PWM' */
  Torque_co_Calibrationwrite_Term(&Torque_control_DW.Calibrationwrite);

  /* Terminate for Atomic SubSystem: '<Root>/Initialize Function1' */
  /* Terminate for MATLABSystem: '<S8>/Configuration write' */
  if (!Torque_control_DW.obj_c.matlabCodegenIsDeleted) {
    Torque_control_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((Torque_control_DW.obj_c.isInitialized == 1L) &&
        Torque_control_DW.obj_c.isSetupComplete) {
      MW_I2C_Close(Torque_control_DW.obj_c.I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/Configuration write' */
  Torque_co_Calibrationwrite_Term(&Torque_control_DW.Calibrationwrite_p);

  /* End of Terminate for SubSystem: '<Root>/Initialize Function1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
