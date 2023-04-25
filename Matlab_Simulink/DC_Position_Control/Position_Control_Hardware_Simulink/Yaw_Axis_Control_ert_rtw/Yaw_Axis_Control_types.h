/*
 * File: Yaw_Axis_Control_types.h
 *
 * Code generated for Simulink model 'Yaw_Axis_Control'.
 *
 * Model version                  : 1.360
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Apr  4 17:00:41 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Yaw_Axis_Control_types_h_
#define RTW_HEADER_Yaw_Axis_Control_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef struct_tag_qbUFhX6Bp3RsgYGeqgZpEH
#define struct_tag_qbUFhX6Bp3RsgYGeqgZpEH

struct tag_qbUFhX6Bp3RsgYGeqgZpEH
{
  int16_T __dummy;
};

#endif                                 /* struct_tag_qbUFhX6Bp3RsgYGeqgZpEH */

#ifndef typedef_c_arduinodriver_ArduinoSerial_T
#define typedef_c_arduinodriver_ArduinoSerial_T

typedef struct tag_qbUFhX6Bp3RsgYGeqgZpEH c_arduinodriver_ArduinoSerial_T;

#endif                             /* typedef_c_arduinodriver_ArduinoSerial_T */

#ifndef struct_tag_ghK8YWVQwtwpThnQHmUfd
#define struct_tag_ghK8YWVQwtwpThnQHmUfd

struct tag_ghK8YWVQwtwpThnQHmUfd
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T Protocol;
  real_T port;
  real_T dataSizeInBytes;
  real_T dataType;
  real_T sendModeEnum;
  real_T sendFormatEnum;
  c_arduinodriver_ArduinoSerial_T SerialDriverObj;
};

#endif                                 /* struct_tag_ghK8YWVQwtwpThnQHmUfd */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_ghK8YWVQwtwpThnQHmUfd codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

/* Parameters (default storage) */
typedef struct P_Yaw_Axis_Control_T_ P_Yaw_Axis_Control_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Yaw_Axis_Control_T RT_MODEL_Yaw_Axis_Control_T;

#endif                                /* RTW_HEADER_Yaw_Axis_Control_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
