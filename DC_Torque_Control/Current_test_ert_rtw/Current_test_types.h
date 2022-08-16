/*
 * File: Current_test_types.h
 *
 * Code generated for Simulink model 'Current_test'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Aug 16 11:52:52 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Current_test_types_h_
#define RTW_HEADER_Current_test_types_h_
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

#ifndef typedef_c_arduinodriver_ArduinoI2C_Cu_T
#define typedef_c_arduinodriver_ArduinoI2C_Cu_T

typedef struct tag_jbIFaTBEZATkkvPSmnoPa c_arduinodriver_ArduinoI2C_Cu_T;

#endif                             /* typedef_c_arduinodriver_ArduinoI2C_Cu_T */

#ifndef struct_tag_3coDYKg8JwMUxQ16KBcXBE
#define struct_tag_3coDYKg8JwMUxQ16KBcXBE

struct tag_3coDYKg8JwMUxQ16KBcXBE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  c_arduinodriver_ArduinoI2C_Cu_T I2CDriverObj;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
};

#endif                                 /* struct_tag_3coDYKg8JwMUxQ16KBcXBE */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_3coDYKg8JwMUxQ16KBcXBE codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

#ifndef struct_tag_chY474Xs2EmAHQmJ9UhmtD
#define struct_tag_chY474Xs2EmAHQmJ9UhmtD

struct tag_chY474Xs2EmAHQmJ9UhmtD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  c_arduinodriver_ArduinoI2C_Cu_T I2CDriverObj;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
  real_T SampleTime;
};

#endif                                 /* struct_tag_chY474Xs2EmAHQmJ9UhmtD */

#ifndef typedef_codertarget_arduinobase_int_d_T
#define typedef_codertarget_arduinobase_int_d_T

typedef struct tag_chY474Xs2EmAHQmJ9UhmtD codertarget_arduinobase_int_d_T;

#endif                             /* typedef_codertarget_arduinobase_int_d_T */

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

#ifndef typedef_codertarget_arduinobase_in_dv_T
#define typedef_codertarget_arduinobase_in_dv_T

typedef struct tag_4eDVzK5FiryyCjvjjvrZGB codertarget_arduinobase_in_dv_T;

#endif                             /* typedef_codertarget_arduinobase_in_dv_T */

/* Parameters (default storage) */
typedef struct P_Current_test_T_ P_Current_test_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Current_test_T RT_MODEL_Current_test_T;

#endif                                 /* RTW_HEADER_Current_test_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
