/*
 * File: Yaw_Axis_Control.c
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
     *  ActionPort: '<S5>/Action Port'
     */
    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<Root>/Constant7'
     *  SignalConversion generated from: '<S5>/In1'
     */
    Yaw_Axis_Control_B.Merge = Yaw_Axis_Control_P.Constant7_Value;

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem2' */

    /* Update for IfAction SubSystem: '<Root>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Update for SwitchCase: '<Root>/Switch Case' */
    srUpdateBC(Yaw_Axis_Control_DW.IfActionSubsystem2_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/If Action Subsystem2' */
    break;

   case 2L:
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<Root>/Constant3'
     *  SignalConversion generated from: '<S3>/In1'
     */
    Yaw_Axis_Control_B.Merge = Yaw_Axis_Control_P.Constant3_Value;

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Update for SwitchCase: '<Root>/Switch Case' */
    srUpdateBC(Yaw_Axis_Control_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/If Action Subsystem' */
    break;

   case 3L:
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<Root>/Constant4'
     *  SignalConversion generated from: '<S4>/In1'
     */
    Yaw_Axis_Control_B.Merge = Yaw_Axis_Control_P.Constant4_Value;

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Update for SwitchCase: '<Root>/Switch Case' */
    srUpdateBC(Yaw_Axis_Control_DW.IfActionSubsystem1_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/If Action Subsystem1' */
    break;
  }

  /* End of SwitchCase: '<Root>/Switch Case' */

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem2' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  /* RelationalOperator: '<S1>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S1>/Delay Input1'
   *
   * Block description for '<S1>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (Yaw_Axis_Control_B.Merge != Yaw_Axis_Control_DW.DelayInput1_DSTATE) {
    /* MATLABSystem: '<S2>/Serial Transmit2' */
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

    /* End of MATLABSystem: '<S2>/Serial Transmit2' */
    srUpdateBC(Yaw_Axis_Control_DW.EnabledSubsystem2_SubsysRanBC);
  }

  /* End of RelationalOperator: '<S1>/FixPt Relational Operator' */
  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem2' */

  /* S-Function (readEncDUEpin8_9): '<Root>/Encoder1' */
  readEncDUEpin8_9_Outputs_wrapper(&Yaw_Axis_Control_B.Encoder1,
    &Yaw_Axis_Control_DW.Encoder1_DSTATE);

  /* Update for UnitDelay: '<S1>/Delay Input1'
   *
   * Block description for '<S1>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Yaw_Axis_Control_DW.DelayInput1_DSTATE = Yaw_Axis_Control_B.Merge;

  /* Update for S-Function (readEncDUEpin8_9): '<Root>/Encoder1' */

  /* S-Function "readEncDUEpin8_9_wrapper" Block: <Root>/Encoder1 */
  readEncDUEpin8_9_Update_wrapper(&Yaw_Axis_Control_B.Encoder1,
    &Yaw_Axis_Control_DW.Encoder1_DSTATE);

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
  Yaw_Axis_Control_M->Sizes.checksums[0] = (1196176380U);
  Yaw_Axis_Control_M->Sizes.checksums[1] = (701489920U);
  Yaw_Axis_Control_M->Sizes.checksums[2] = (1462621305U);
  Yaw_Axis_Control_M->Sizes.checksums[3] = (2616574265U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    Yaw_Axis_Control_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &Yaw_Axis_Control_DW.EnabledSubsystem2_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &Yaw_Axis_Control_DW.EnabledSubsystem2_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &Yaw_Axis_Control_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &Yaw_Axis_Control_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
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

    /* Start for S-Function (readEncDUEpin8_9): '<Root>/Encoder1' */

    /* S-Function Block: <Root>/Encoder1 */
    readEncDUEpin8_9_Start_wrapper(&Yaw_Axis_Control_DW.Encoder1_DSTATE);

    /* InitializeConditions for UnitDelay: '<S1>/Delay Input1'
     *
     * Block description for '<S1>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Yaw_Axis_Control_DW.DelayInput1_DSTATE =
      Yaw_Axis_Control_P.DetectChange2_vinit;

    /* InitializeConditions for S-Function (readEncDUEpin8_9): '<Root>/Encoder1' */

    /* S-Function Block: <Root>/Encoder1 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          Yaw_Axis_Control_DW.Encoder1_DSTATE = initVector[0];
        }
      }
    }

    /* SystemInitialize for Merge: '<Root>/Merge' */
    Yaw_Axis_Control_B.Merge = Yaw_Axis_Control_P.Merge_InitialOutput;

    /* Start for MATLABSystem: '<S2>/Serial Transmit2' */
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

    /* End of Start for MATLABSystem: '<S2>/Serial Transmit2' */
    /* End of SystemInitialize for SubSystem: '<Root>/Enabled Subsystem2' */
  }
}

/* Model terminate function */
void Yaw_Axis_Control_terminate(void)
{
  /* Terminate for Enabled SubSystem: '<Root>/Enabled Subsystem2' */
  /* Terminate for MATLABSystem: '<S2>/Serial Transmit2' */
  if (!Yaw_Axis_Control_DW.obj.matlabCodegenIsDeleted) {
    Yaw_Axis_Control_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Serial Transmit2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
