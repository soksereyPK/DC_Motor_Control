/*
 * File: multiword_types.h
 *
 * Code generated for Simulink model 'position_control'.
 *
 * Model version                  : 2.47
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Apr 26 12:52:06 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef MULTIWORD_TYPES_H
#define MULTIWORD_TYPES_H
#include "rtwtypes.h"

/*
 * Definitions supporting external data access
 */
typedef int32_T chunk_T;
typedef uint32_T uchunk_T;

/*
 * MultiWord supporting definitions
 */
typedef long int long_T;

/*
 * MultiWord types
 */
typedef struct {
  uint32_T chunks[2];
} int64m_T;

typedef struct {
  int64m_T re;
  int64m_T im;
} cint64m_T;

typedef struct {
  uint32_T chunks[2];
} uint64m_T;

typedef struct {
  uint64m_T re;
  uint64m_T im;
} cuint64m_T;

typedef struct {
  uint32_T chunks[3];
} int96m_T;

typedef struct {
  int96m_T re;
  int96m_T im;
} cint96m_T;

typedef struct {
  uint32_T chunks[3];
} uint96m_T;

typedef struct {
  uint96m_T re;
  uint96m_T im;
} cuint96m_T;

typedef struct {
  uint32_T chunks[4];
} int128m_T;

typedef struct {
  int128m_T re;
  int128m_T im;
} cint128m_T;

typedef struct {
  uint32_T chunks[4];
} uint128m_T;

typedef struct {
  uint128m_T re;
  uint128m_T im;
} cuint128m_T;

typedef struct {
  uint32_T chunks[5];
} int160m_T;

typedef struct {
  int160m_T re;
  int160m_T im;
} cint160m_T;

typedef struct {
  uint32_T chunks[5];
} uint160m_T;

typedef struct {
  uint160m_T re;
  uint160m_T im;
} cuint160m_T;

typedef struct {
  uint32_T chunks[6];
} int192m_T;

typedef struct {
  int192m_T re;
  int192m_T im;
} cint192m_T;

typedef struct {
  uint32_T chunks[6];
} uint192m_T;

typedef struct {
  uint192m_T re;
  uint192m_T im;
} cuint192m_T;

typedef struct {
  uint32_T chunks[7];
} int224m_T;

typedef struct {
  int224m_T re;
  int224m_T im;
} cint224m_T;

typedef struct {
  uint32_T chunks[7];
} uint224m_T;

typedef struct {
  uint224m_T re;
  uint224m_T im;
} cuint224m_T;

typedef struct {
  uint32_T chunks[8];
} int256m_T;

typedef struct {
  int256m_T re;
  int256m_T im;
} cint256m_T;

typedef struct {
  uint32_T chunks[8];
} uint256m_T;

typedef struct {
  uint256m_T re;
  uint256m_T im;
} cuint256m_T;

#endif                                 /* MULTIWORD_TYPES_H */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
