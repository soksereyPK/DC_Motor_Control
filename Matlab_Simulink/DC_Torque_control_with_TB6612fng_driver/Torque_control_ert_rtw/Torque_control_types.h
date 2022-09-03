/*
 * File: Torque_control_types.h
 *
 * Code generated for Simulink model 'Torque_control'.
 *
 * Model version                  : 1.39
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Sep  3 11:18:33 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Torque_control_types_h_
#define RTW_HEADER_Torque_control_types_h_
#include "MW_SVD.h"
#include "rtwtypes.h"

/* Model Code Variants */

/* Custom Type definition for MATLABSystem: '<S1>/Calibration write' */
#include "MW_SVD.h"
#ifndef struct_tag_jbIFaTBEZATkkvPSmnoPa
#define struct_tag_jbIFaTBEZATkkvPSmnoPa

struct tag_jbIFaTBEZATkkvPSmnoPa
{
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /* struct_tag_jbIFaTBEZATkkvPSmnoPa */

#ifndef typedef_c_arduinodriver_ArduinoI2C_To_T
#define typedef_c_arduinodriver_ArduinoI2C_To_T

typedef struct tag_jbIFaTBEZATkkvPSmnoPa c_arduinodriver_ArduinoI2C_To_T;

#endif                             /* typedef_c_arduinodriver_ArduinoI2C_To_T */

#ifndef struct_tag_3coDYKg8JwMUxQ16KBcXBE
#define struct_tag_3coDYKg8JwMUxQ16KBcXBE

struct tag_3coDYKg8JwMUxQ16KBcXBE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  c_arduinodriver_ArduinoI2C_To_T I2CDriverObj;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
};

#endif                                 /* struct_tag_3coDYKg8JwMUxQ16KBcXBE */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_3coDYKg8JwMUxQ16KBcXBE codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

#ifndef struct_tag_04b6x6tDldj9IrIH2gmbjG
#define struct_tag_04b6x6tDldj9IrIH2gmbjG

struct tag_04b6x6tDldj9IrIH2gmbjG
{
  int16_T __dummy;
};

#endif                                 /* struct_tag_04b6x6tDldj9IrIH2gmbjG */

#ifndef typedef_b_arduinodriver_ArduinoDigita_T
#define typedef_b_arduinodriver_ArduinoDigita_T

typedef struct tag_04b6x6tDldj9IrIH2gmbjG b_arduinodriver_ArduinoDigita_T;

#endif                             /* typedef_b_arduinodriver_ArduinoDigita_T */

#ifndef struct_tag_AYWgtFscQm3mLUJYb3A20C
#define struct_tag_AYWgtFscQm3mLUJYb3A20C

struct tag_AYWgtFscQm3mLUJYb3A20C
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
};

#endif                                 /* struct_tag_AYWgtFscQm3mLUJYb3A20C */

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_AYWgtFscQm3mLUJYb3A20C codertarget_arduinobase_block_T;

#endif                             /* typedef_codertarget_arduinobase_block_T */

#ifndef struct_tag_hiATgaifu8RfrjZ2yifYbH
#define struct_tag_hiATgaifu8RfrjZ2yifYbH

struct tag_hiATgaifu8RfrjZ2yifYbH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  real_T SampleTime;
  uint8_T Index;
};

#endif                                 /* struct_tag_hiATgaifu8RfrjZ2yifYbH */

#ifndef typedef_codertarget_arduinobase_int_h_T
#define typedef_codertarget_arduinobase_int_h_T

typedef struct tag_hiATgaifu8RfrjZ2yifYbH codertarget_arduinobase_int_h_T;

#endif                             /* typedef_codertarget_arduinobase_int_h_T */

#ifndef struct_tag_chY474Xs2EmAHQmJ9UhmtD
#define struct_tag_chY474Xs2EmAHQmJ9UhmtD

struct tag_chY474Xs2EmAHQmJ9UhmtD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  c_arduinodriver_ArduinoI2C_To_T I2CDriverObj;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
  real_T SampleTime;
};

#endif                                 /* struct_tag_chY474Xs2EmAHQmJ9UhmtD */

#ifndef typedef_codertarget_arduinobase_in_h3_T
#define typedef_codertarget_arduinobase_in_h3_T

typedef struct tag_chY474Xs2EmAHQmJ9UhmtD codertarget_arduinobase_in_h3_T;

#endif                             /* typedef_codertarget_arduinobase_in_h3_T */

#ifndef struct_tag_g1WX34VPn8QzVKQriB4HN
#define struct_tag_g1WX34VPn8QzVKQriB4HN

struct tag_g1WX34VPn8QzVKQriB4HN
{
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_g1WX34VPn8QzVKQriB4HN */

#ifndef typedef_g_matlabshared_ioclient_perip_T
#define typedef_g_matlabshared_ioclient_perip_T

typedef struct tag_g1WX34VPn8QzVKQriB4HN g_matlabshared_ioclient_perip_T;

#endif                             /* typedef_g_matlabshared_ioclient_perip_T */

#ifndef struct_tag_4eDVzK5FiryyCjvjjvrZGB
#define struct_tag_4eDVzK5FiryyCjvjjvrZGB

struct tag_4eDVzK5FiryyCjvjjvrZGB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  g_matlabshared_ioclient_perip_T PWMDriverObj;
};

#endif                                 /* struct_tag_4eDVzK5FiryyCjvjjvrZGB */

#ifndef typedef_codertarget_arduinobase_i_h3r_T
#define typedef_codertarget_arduinobase_i_h3r_T

typedef struct tag_4eDVzK5FiryyCjvjjvrZGB codertarget_arduinobase_i_h3r_T;

#endif                             /* typedef_codertarget_arduinobase_i_h3r_T */

/* Parameters (default storage) */
typedef struct P_Torque_control_T_ P_Torque_control_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Torque_control_T RT_MODEL_Torque_control_T;

#endif                                 /* RTW_HEADER_Torque_control_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
