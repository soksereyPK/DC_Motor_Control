/*
 * File: Torque_control_types.h
 *
 * Code generated for Simulink model 'Torque_control'.
 *
 * Model version                  : 2.7
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Apr 27 10:18:12 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Torque_control_types_h_
#define RTW_HEADER_Torque_control_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"
#ifndef struct_tag_9aqKbsbsI7JI0RwgnVwU0C
#define struct_tag_9aqKbsbsI7JI0RwgnVwU0C

struct tag_9aqKbsbsI7JI0RwgnVwU0C
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_9aqKbsbsI7JI0RwgnVwU0C */

#ifndef typedef_b_arduinodriver_ArduinoDigita_T
#define typedef_b_arduinodriver_ArduinoDigita_T

typedef struct tag_9aqKbsbsI7JI0RwgnVwU0C b_arduinodriver_ArduinoDigita_T;

#endif                             /* typedef_b_arduinodriver_ArduinoDigita_T */

#ifndef struct_tag_qrLkTWTW64zZK0sqwALTyG
#define struct_tag_qrLkTWTW64zZK0sqwALTyG

struct tag_qrLkTWTW64zZK0sqwALTyG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
};

#endif                                 /* struct_tag_qrLkTWTW64zZK0sqwALTyG */

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_qrLkTWTW64zZK0sqwALTyG codertarget_arduinobase_block_T;

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

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_hiATgaifu8RfrjZ2yifYbH codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

/* Custom Type definition for MATLABSystem: '<S1>/PWM' */
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

#ifndef typedef_codertarget_arduinobase_int_h_T
#define typedef_codertarget_arduinobase_int_h_T

typedef struct tag_4eDVzK5FiryyCjvjjvrZGB codertarget_arduinobase_int_h_T;

#endif                             /* typedef_codertarget_arduinobase_int_h_T */

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
