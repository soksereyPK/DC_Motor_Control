/*
 * File: ReadEnc_SPI.c
 *
 * Code generated for Simulink model 'ReadEnc_SPI'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Sep 14 14:26:25 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ReadEnc_SPI.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "ReadEnc_SPI_private.h"

/* Block signals (default storage) */
B_ReadEnc_SPI_T ReadEnc_SPI_B;

/* Block states (default storage) */
DW_ReadEnc_SPI_T ReadEnc_SPI_DW;

/* Real-time model */
static RT_MODEL_ReadEnc_SPI_T ReadEnc_SPI_M_;
RT_MODEL_ReadEnc_SPI_T *const ReadEnc_SPI_M = &ReadEnc_SPI_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void ReadEnc_SPI_step(void)
{
  real_T tmp;
  uint8_T rtb_DataTypeConversion;
  uint8_T tmp_0;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant'
   */
  tmp = floor(ReadEnc_SPI_P.Constant_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  rtb_DataTypeConversion = (uint8_T)(tmp < 0.0 ? (int16_T)(uint8_T)-(int8_T)
    (uint8_T)-tmp : (int16_T)(uint8_T)tmp);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* MATLABSystem: '<Root>/SPI WriteRead' */
  if (ReadEnc_SPI_DW.obj.slaveSelectPin_ !=
      ReadEnc_SPI_P.SPIWriteRead_slaveSelectPin_) {
    ReadEnc_SPI_DW.obj.slaveSelectPin_ =
      ReadEnc_SPI_P.SPIWriteRead_slaveSelectPin_;
  }

  tmp = rt_roundd_snf(ReadEnc_SPI_DW.obj.slaveSelectPin_);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  /* MATLABSystem: '<Root>/SPI WriteRead' */
  MW_SPIwriteReadLoop(tmp_0, &rtb_DataTypeConversion, 1.0, 1.0,
                      &ReadEnc_SPI_B.SPIWriteRead);

  {                                    /* Sample time: [0.01s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ReadEnc_SPI_M->Timing.taskTime0 =
    ((time_T)(++ReadEnc_SPI_M->Timing.clockTick0)) *
    ReadEnc_SPI_M->Timing.stepSize0;
}

/* Model initialize function */
void ReadEnc_SPI_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(ReadEnc_SPI_M, -1);
  ReadEnc_SPI_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  ReadEnc_SPI_M->Sizes.checksums[0] = (1443961092U);
  ReadEnc_SPI_M->Sizes.checksums[1] = (1584398497U);
  ReadEnc_SPI_M->Sizes.checksums[2] = (2133890438U);
  ReadEnc_SPI_M->Sizes.checksums[3] = (3756663402U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    ReadEnc_SPI_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ReadEnc_SPI_M->extModeInfo,
      &ReadEnc_SPI_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ReadEnc_SPI_M->extModeInfo,
                        ReadEnc_SPI_M->Sizes.checksums);
    rteiSetTPtr(ReadEnc_SPI_M->extModeInfo, rtmGetTPtr(ReadEnc_SPI_M));
  }

  {
    real_T tmp;
    uint8_T tmp_0;

    /* Start for MATLABSystem: '<Root>/SPI WriteRead' */
    ReadEnc_SPI_DW.obj.matlabCodegenIsDeleted = false;
    ReadEnc_SPI_DW.obj.slaveSelectPin_ =
      ReadEnc_SPI_P.SPIWriteRead_slaveSelectPin_;
    ReadEnc_SPI_DW.obj.isInitialized = 1L;
    tmp = rt_roundd_snf(ReadEnc_SPI_DW.obj.slaveSelectPin_);
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint8_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    MW_SSpinSetup(tmp_0);
    ReadEnc_SPI_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/SPI WriteRead' */
  }
}

/* Model terminate function */
void ReadEnc_SPI_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/SPI WriteRead' */
  if (!ReadEnc_SPI_DW.obj.matlabCodegenIsDeleted) {
    ReadEnc_SPI_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/SPI WriteRead' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
