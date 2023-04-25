/*
 * File: Yaw_Axis_Control.c
 *
 * Code generated for Simulink model 'Yaw_Axis_Control'.
 *
 * Model version                  : 1.325
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Apr  4 15:11:38 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Yaw_Axis_Control.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "Yaw_Axis_Control_private.h"

/* Block signals (default storage) */
B_Yaw_Axis_Control_T Yaw_Axis_Control_B;

/* Block states (default storage) */
DW_Yaw_Axis_Control_T Yaw_Axis_Control_DW;

/* Real-time model */
static RT_MODEL_Yaw_Axis_Control_T Yaw_Axis_Control_M_;
RT_MODEL_Yaw_Axis_Control_T *const Yaw_Axis_Control_M = &Yaw_Axis_Control_M_;
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
void Yaw_Axis_Control_step(void)
{
  real_T dataIn;
  char_T labelTerminated[2];

  /* Reset subsysRan breadcrumbs */
  srClearBC(Yaw_Axis_Control_DW.EnabledSubsystem2_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Yaw_Axis_Control_DW.IfActionSubsystem2_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Yaw_Axis_Control_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Yaw_Axis_Control_DW.IfActionSubsystem1_SubsysRanBC);

  /* SwitchCase: '<Root>/Switch Case' incorporates:
   *  Constant: '<Root>/Constant6'
   */
  if (Yaw_Axis_Control_P.Constant6_Value < 0.0) {
    dataIn = ceil(Yaw_Axis_Control_P.Constant6_Value);
  } else {
    dataIn = floor(Yaw_Axis_Control_P.Constant6_Value);
  }

  if (rtIsNaN(dataIn) || rtIsInf(dataIn)) {
    dataIn = 0.0;
  } else {
    dataIn = fmod(dataIn, 4.294967296E+9);
  }

  switch (dataIn < 0.0 ? -(int32_T)(uint32_T)-dataIn : (int32_T)(uint32_T)dataIn)
  {
   case 1L:
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<Root>/Constant7'
     *  SignalConversion generated from: '<S6>/In1'
     */
    Yaw_Axis_Control_B.Merge = Yaw_Axis_Control_P.Constant7_Value;

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem2' */

    /* Update for IfAction SubSystem: '<Root>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Update for SwitchCase: '<Root>/Switch Case' */
    srUpdateBC(Yaw_Axis_Control_DW.IfActionSubsystem2_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/If Action Subsystem2' */
    break;

   case 2L:
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<Root>/Constant3'
     *  SignalConversion generated from: '<S4>/In1'
     */
    Yaw_Axis_Control_B.Merge = Yaw_Axis_Control_P.Constant3_Value;

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Update for SwitchCase: '<Root>/Switch Case' */
    srUpdateBC(Yaw_Axis_Control_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/If Action Subsystem' */
    break;

   case 3L:
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<Root>/Constant4'
     *  SignalConversion generated from: '<S5>/In1'
     */
    Yaw_Axis_Control_B.Merge = Yaw_Axis_Control_P.Constant4_Value;

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Update for SwitchCase: '<Root>/Switch Case' */
    srUpdateBC(Yaw_Axis_Control_DW.IfActionSubsystem1_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/If Action Subsystem1' */
    break;
  }

  /* End of SwitchCase: '<Root>/Switch Case' */

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem2' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  /* RelationalOperator: '<S1>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S1>/Delay Input1'
   *
   * Block description for '<S1>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (Yaw_Axis_Control_B.Merge != Yaw_Axis_Control_DW.DelayInput1_DSTATE) {
    /* MATLABSystem: '<S3>/Serial Transmit2' */
    if (Yaw_Axis_Control_DW.obj.Protocol !=
        Yaw_Axis_Control_P.SerialTransmit2_Protocol) {
      Yaw_Axis_Control_DW.obj.Protocol =
        Yaw_Axis_Control_P.SerialTransmit2_Protocol;
    }

    dataIn = Yaw_Axis_Control_B.Merge;
    labelTerminated[0] = 'Q';
    labelTerminated[1] = '\x00';
    MW_Serial_write(Yaw_Axis_Control_DW.obj.port, &dataIn, 1.0,
                    Yaw_Axis_Control_DW.obj.dataSizeInBytes,
                    Yaw_Axis_Control_DW.obj.sendModeEnum,
                    Yaw_Axis_Control_DW.obj.dataType,
                    Yaw_Axis_Control_DW.obj.sendFormatEnum, 1.0,
                    &labelTerminated[0]);

    /* End of MATLABSystem: '<S3>/Serial Transmit2' */
    srUpdateBC(Yaw_Axis_Control_DW.EnabledSubsystem2_SubsysRanBC);
  }

  /* End of RelationalOperator: '<S1>/FixPt Relational Operator' */
  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem2' */

  /* MATLABSystem: '<Root>/Encoder' */
  if (Yaw_Axis_Control_DW.obj_p.SampleTime !=
      Yaw_Axis_Control_P.Encoder_SampleTime) {
    Yaw_Axis_Control_DW.obj_p.SampleTime = Yaw_Axis_Control_P.Encoder_SampleTime;
  }

  if (Yaw_Axis_Control_DW.obj_p.TunablePropsChanged) {
    Yaw_Axis_Control_DW.obj_p.TunablePropsChanged = false;
  }

  /* MATLABSystem: '<Root>/Encoder' */
  MW_EncoderRead(Yaw_Axis_Control_DW.obj_p.Index, &Yaw_Axis_Control_B.Encoder);

  /* Gain: '<Root>/Gain1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  Yaw_Axis_Control_B.Gain1 = Yaw_Axis_Control_P.Gain1_Gain * (real_T)
    Yaw_Axis_Control_B.Encoder;

  /* SampleTimeMath: '<S2>/TSamp'
   *
   * About '<S2>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  dataIn = Yaw_Axis_Control_B.Gain1 * Yaw_Axis_Control_P.TSamp_WtEt;

  /* Sum: '<S2>/Diff' incorporates:
   *  UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  Yaw_Axis_Control_B.Diff = dataIn - Yaw_Axis_Control_DW.UD_DSTATE;

  /* Update for UnitDelay: '<S1>/Delay Input1'
   *
   * Block description for '<S1>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Yaw_Axis_Control_DW.DelayInput1_DSTATE = Yaw_Axis_Control_B.Merge;

  /* Update for UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  Yaw_Axis_Control_DW.UD_DSTATE = dataIn;

  {                                    /* Sample time: [0.01s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Yaw_Axis_Control_M->Timing.taskTime0 =
    ((time_T)(++Yaw_Axis_Control_M->Timing.clockTick0)) *
    Yaw_Axis_Control_M->Timing.stepSize0;
}

/* Model initialize function */
void Yaw_Axis_Control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(Yaw_Axis_Control_M, -1);
  Yaw_Axis_Control_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Yaw_Axis_Control_M->Sizes.checksums[0] = (1866385176U);
  Yaw_Axis_Control_M->Sizes.checksums[1] = (2757430588U);
  Yaw_Axis_Control_M->Sizes.checksums[2] = (433030377U);
  Yaw_Axis_Control_M->Sizes.checksums[3] = (418656124U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    Yaw_Axis_Control_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &Yaw_Axis_Control_DW.EnabledSubsystem2_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &Yaw_Axis_Control_DW.EnabledSubsystem2_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)
      &Yaw_Axis_Control_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &Yaw_Axis_Control_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &Yaw_Axis_Control_DW.IfActionSubsystem2_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Yaw_Axis_Control_M->extModeInfo,
      &Yaw_Axis_Control_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Yaw_Axis_Control_M->extModeInfo,
                        Yaw_Axis_Control_M->Sizes.checksums);
    rteiSetTPtr(Yaw_Axis_Control_M->extModeInfo, rtmGetTPtr(Yaw_Axis_Control_M));
  }

  {
    real_T tmp;
    uint8_T tmp_0;

    /* InitializeConditions for UnitDelay: '<S1>/Delay Input1'
     *
     * Block description for '<S1>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Yaw_Axis_Control_DW.DelayInput1_DSTATE =
      Yaw_Axis_Control_P.DetectChange2_vinit;

    /* InitializeConditions for UnitDelay: '<S2>/UD'
     *
     * Block description for '<S2>/UD':
     *
     *  Store in Global RAM
     */
    Yaw_Axis_Control_DW.UD_DSTATE =
      Yaw_Axis_Control_P.DiscreteDerivative_ICPrevScaled;

    /* SystemInitialize for Merge: '<Root>/Merge' */
    Yaw_Axis_Control_B.Merge = Yaw_Axis_Control_P.Merge_InitialOutput;

    /* Start for MATLABSystem: '<S3>/Serial Transmit2' */
    Yaw_Axis_Control_DW.obj.matlabCodegenIsDeleted = false;
    Yaw_Axis_Control_DW.obj.Protocol =
      Yaw_Axis_Control_P.SerialTransmit2_Protocol;
    Yaw_Axis_Control_DW.obj.isInitialized = 1L;
    Yaw_Axis_Control_DW.obj.port = 1.0;
    Yaw_Axis_Control_DW.obj.dataSizeInBytes = 8.0;
    Yaw_Axis_Control_DW.obj.dataType = 6.0;
    Yaw_Axis_Control_DW.obj.sendModeEnum = 2.0;
    Yaw_Axis_Control_DW.obj.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(Yaw_Axis_Control_DW.obj.port);
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint8_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    MW_SCI_Open(tmp_0);
    Yaw_Axis_Control_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S3>/Serial Transmit2' */
    /* End of SystemInitialize for SubSystem: '<Root>/Enabled Subsystem2' */

    /* Start for MATLABSystem: '<Root>/Encoder' */
    Yaw_Axis_Control_DW.obj_p.Index = 0U;
    Yaw_Axis_Control_DW.obj_p.matlabCodegenIsDeleted = false;
    Yaw_Axis_Control_DW.obj_p.SampleTime = Yaw_Axis_Control_P.Encoder_SampleTime;
    Yaw_Axis_Control_DW.obj_p.isSetupComplete = false;
    Yaw_Axis_Control_DW.obj_p.isInitialized = 1L;
    MW_EncoderSetup(2UL, 3UL, &Yaw_Axis_Control_DW.obj_p.Index);
    Yaw_Axis_Control_DW.obj_p.isSetupComplete = true;
    Yaw_Axis_Control_DW.obj_p.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<Root>/Encoder' */
    MW_EncoderReset(Yaw_Axis_Control_DW.obj_p.Index);
  }
}

/* Model terminate function */
void Yaw_Axis_Control_terminate(void)
{
  /* Terminate for Enabled SubSystem: '<Root>/Enabled Subsystem2' */
  /* Terminate for MATLABSystem: '<S3>/Serial Transmit2' */
  if (!Yaw_Axis_Control_DW.obj.matlabCodegenIsDeleted) {
    Yaw_Axis_Control_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/Serial Transmit2' */
  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!Yaw_Axis_Control_DW.obj_p.matlabCodegenIsDeleted) {
    Yaw_Axis_Control_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Yaw_Axis_Control_DW.obj_p.isInitialized == 1L) &&
        Yaw_Axis_Control_DW.obj_p.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
