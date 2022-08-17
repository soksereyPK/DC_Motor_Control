/*
 * File: position_control_PD_with_Due_types.h
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

#ifndef RTW_HEADER_position_control_PD_with_Due_types_h_
#define RTW_HEADER_position_control_PD_with_Due_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Model Code Variants */
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

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_hiATgaifu8RfrjZ2yifYbH codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

/* Custom Type definition for MATLABSystem: '<S1>/PWM1' */
#include "MW_SVD.h"
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

#ifndef typedef_codertarget_arduinobase_int_i_T
#define typedef_codertarget_arduinobase_int_i_T

typedef struct tag_4eDVzK5FiryyCjvjjvrZGB codertarget_arduinobase_int_i_T;

#endif                             /* typedef_codertarget_arduinobase_int_i_T */

/* Parameters (default storage) */
typedef struct P_position_control_PD_with_Du_T_ P_position_control_PD_with_Du_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_position_control_PD_w_T RT_MODEL_position_control_PD__T;

#endif                    /* RTW_HEADER_position_control_PD_with_Due_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */