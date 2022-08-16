/*
 * File: LP_filter_types.h
 *
 * Code generated for Simulink model 'LP_filter'.
 *
 * Model version                  : 2.1
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Aug 16 14:15:09 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LP_filter_types_h_
#define RTW_HEADER_LP_filter_types_h_
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

#ifndef typedef_c_arduinodriver_ArduinoI2C_LP_T
#define typedef_c_arduinodriver_ArduinoI2C_LP_T

typedef struct tag_jbIFaTBEZATkkvPSmnoPa c_arduinodriver_ArduinoI2C_LP_T;

#endif                             /* typedef_c_arduinodriver_ArduinoI2C_LP_T */

#ifndef struct_tag_3coDYKg8JwMUxQ16KBcXBE
#define struct_tag_3coDYKg8JwMUxQ16KBcXBE

struct tag_3coDYKg8JwMUxQ16KBcXBE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  c_arduinodriver_ArduinoI2C_LP_T I2CDriverObj;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
};

#endif                                 /* struct_tag_3coDYKg8JwMUxQ16KBcXBE */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_3coDYKg8JwMUxQ16KBcXBE codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

#ifndef struct_tag_jZFcpf4zU37NGg00vsZjlD
#define struct_tag_jZFcpf4zU37NGg00vsZjlD

struct tag_jZFcpf4zU37NGg00vsZjlD
{
  int16_T S0_isInitialized;
  real_T W0_states[38];
  real_T P0_InitialStates;
  real_T P1_Coefficients[39];
};

#endif                                 /* struct_tag_jZFcpf4zU37NGg00vsZjlD */

#ifndef typedef_b_dsp_FIRFilter_0_LP_filter_T
#define typedef_b_dsp_FIRFilter_0_LP_filter_T

typedef struct tag_jZFcpf4zU37NGg00vsZjlD b_dsp_FIRFilter_0_LP_filter_T;

#endif                               /* typedef_b_dsp_FIRFilter_0_LP_filter_T */

#ifndef struct_tag_xKx7C8V0xFtQzG38QF761F
#define struct_tag_xKx7C8V0xFtQzG38QF761F

struct tag_xKx7C8V0xFtQzG38QF761F
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRFilter_0_LP_filter_T cSFunObject;
};

#endif                                 /* struct_tag_xKx7C8V0xFtQzG38QF761F */

#ifndef typedef_b_dspcodegen_FIRFilter_LP_fil_T
#define typedef_b_dspcodegen_FIRFilter_LP_fil_T

typedef struct tag_xKx7C8V0xFtQzG38QF761F b_dspcodegen_FIRFilter_LP_fil_T;

#endif                             /* typedef_b_dspcodegen_FIRFilter_LP_fil_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_LP_filter_T
#define typedef_cell_wrap_LP_filter_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_LP_filter_T;

#endif                                 /* typedef_cell_wrap_LP_filter_T */

#ifndef struct_tag_cksQiuuyuezeibpnKRNZ1E
#define struct_tag_cksQiuuyuezeibpnKRNZ1E

struct tag_cksQiuuyuezeibpnKRNZ1E
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_LP_filter_T inputVarSize;
  int32_T NumChannels;
  b_dspcodegen_FIRFilter_LP_fil_T *FilterObj;
  b_dspcodegen_FIRFilter_LP_fil_T _pobj0;
};

#endif                                 /* struct_tag_cksQiuuyuezeibpnKRNZ1E */

#ifndef typedef_dsp_simulink_LowpassFilter_LP_T
#define typedef_dsp_simulink_LowpassFilter_LP_T

typedef struct tag_cksQiuuyuezeibpnKRNZ1E dsp_simulink_LowpassFilter_LP_T;

#endif                             /* typedef_dsp_simulink_LowpassFilter_LP_T */

#ifndef struct_tag_chY474Xs2EmAHQmJ9UhmtD
#define struct_tag_chY474Xs2EmAHQmJ9UhmtD

struct tag_chY474Xs2EmAHQmJ9UhmtD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  c_arduinodriver_ArduinoI2C_LP_T I2CDriverObj;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
  real_T SampleTime;
};

#endif                                 /* struct_tag_chY474Xs2EmAHQmJ9UhmtD */

#ifndef typedef_codertarget_arduinobase_int_f_T
#define typedef_codertarget_arduinobase_int_f_T

typedef struct tag_chY474Xs2EmAHQmJ9UhmtD codertarget_arduinobase_int_f_T;

#endif                             /* typedef_codertarget_arduinobase_int_f_T */

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

#ifndef typedef_codertarget_arduinobase_in_f2_T
#define typedef_codertarget_arduinobase_in_f2_T

typedef struct tag_4eDVzK5FiryyCjvjjvrZGB codertarget_arduinobase_in_f2_T;

#endif                             /* typedef_codertarget_arduinobase_in_f2_T */

/* Parameters (default storage) */
typedef struct P_LP_filter_T_ P_LP_filter_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_LP_filter_T RT_MODEL_LP_filter_T;

#endif                                 /* RTW_HEADER_LP_filter_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
