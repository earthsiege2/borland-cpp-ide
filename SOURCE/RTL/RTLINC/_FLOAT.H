/*------------------------------------------------------------------------
 * filename - _float.h
 *
 *  Helper definitions for floating point routines
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1998, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $ */

#ifndef ___FLOAT_H
#define ___FLOAT_H

#include <_defs.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma option push -a1

typedef union _u08
{
  unsigned char value;
} _08;

typedef union _u16
{
  struct
  {
    _08 low08, high08;
  } s;
  unsigned short value;
} _16;

typedef union _u32
{
  struct
  {
    _16 low16, high16;
  } s;
  unsigned long value;
} _32;

typedef union _u64
{
  struct
  {
    _32 low32, high32;
  } s;
  unsigned __int64 value;
} _64;


typedef struct
{
  _32 i32;
} _rtl_float_t;

typedef struct
{
  _64 i64;
} _rtl_double_t;

typedef struct
{
  _64 i64;
  _16 i16;
} _rtl_ldouble_t;



extern double _RTLENTRY _EXPDATA __ieee_64_p_inf;
extern double _RTLENTRY _EXPDATA __ieee_64_n_inf;
extern double _RTLENTRY _EXPDATA __ieee_64_p_nanq;
extern double _RTLENTRY _EXPDATA __ieee_64_n_nanq;
extern double _RTLENTRY _EXPDATA __ieee_64_p_nans;
extern double _RTLENTRY _EXPDATA __ieee_64_n_nans;
extern double _RTLENTRY _EXPDATA __ieee_64_p_zero;
extern double _RTLENTRY _EXPDATA __ieee_64_n_zero;

#pragma option pop

#ifdef __cplusplus
} // "C"
#endif

#endif /* ___FLOAT_H */