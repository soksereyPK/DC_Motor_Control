/*
 * File: ReadEnc_SPI_types.h
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

#ifndef RTW_HEADER_ReadEnc_SPI_types_h_
#define RTW_HEADER_ReadEnc_SPI_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef struct_tag_HKgB5DiOrWaNRtJ1KSLpNC
#define struct_tag_HKgB5DiOrWaNRtJ1KSLpNC

struct tag_HKgB5DiOrWaNRtJ1KSLpNC
{
  int16_T __dummy;
};

#endif                                 /* struct_tag_HKgB5DiOrWaNRtJ1KSLpNC */

#ifndef typedef_c_arduinodriver_ArduinoSPI_Re_T
#define typedef_c_arduinodriver_ArduinoSPI_Re_T

typedef struct tag_HKgB5DiOrWaNRtJ1KSLpNC c_arduinodriver_ArduinoSPI_Re_T;

#endif                             /* typedef_c_arduinodriver_ArduinoSPI_Re_T */

#ifndef struct_tag_Ulz8DOF7t19vKg8OKWWaCD
#define struct_tag_Ulz8DOF7t19vKg8OKWWaCD

struct tag_Ulz8DOF7t19vKg8OKWWaCD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T slaveSelectPin_;
  c_arduinodriver_ArduinoSPI_Re_T SPIDriverObj;
};

#endif                                 /* struct_tag_Ulz8DOF7t19vKg8OKWWaCD */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_Ulz8DOF7t19vKg8OKWWaCD codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

/* Parameters (default storage) */
typedef struct P_ReadEnc_SPI_T_ P_ReadEnc_SPI_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_ReadEnc_SPI_T RT_MODEL_ReadEnc_SPI_T;

#endif                                 /* RTW_HEADER_ReadEnc_SPI_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
