/*
 * ext_mode_types.h
 *
 * Code generation for model "hardware_ekf_est_4para_myrobot_new_driver".
 *
 * Model version              : 3.17
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Tue Jun 28 16:28:18 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef EXT_MODE_TYPES_H
#define EXT_MODE_TYPES_H
#include "rtwtypes.h"

/** External Mode Event ID */
typedef uint16_T extmodeEventId_T;

/** External Mode real time, measured using the target's clock */
typedef uint32_T extmodeRealTime_T;

/** External Mode simulation time */
typedef time_T extmodeSimulationTime_T;

/** External Mode double data type */
typedef real_T extmodeDouble_T;

/** External Mode classic trigger signal */
typedef real_T extmodeClassicTriggerSignal_T;

/** Run the simulation forever (infinite simulation end time) */
#define EXTMODE_SIMULATION_RUN_FOREVER ((extmodeSimulationTime_T) -1)

/** External Mode Base rate event id */
#define EXTMODE_BASE_RATE_EVENT_ID     1

/** External Mode Max Event Id */
#define EXTMODE_MAX_EVENT_ID           0xFF
#endif                                 /* EXT_MODE_TYPES_H */

/* [EOF] ext_mode_types.h */
