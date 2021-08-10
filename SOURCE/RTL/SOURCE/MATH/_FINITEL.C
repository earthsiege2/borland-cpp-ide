/*------------------------------------------------------------------------
 * filename - _finitel.c
 *
 * function(s)
 *
 *   _finitel   - long double version
 *
 * These functions return 1 if the value passed in is finite, and 0 if not
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1996, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.5.2.1 $        */

#include <float.h>
#include <_float.h>

int _RTLENTRY _EXPFUNC _finitel (long double ld)
{
  if (((((_rtl_ldouble_t *)&ld)->i16.value & 0x7FFFU) == 0x7FFFU) &&
      (((_rtl_ldouble_t *)&ld)->i64.value == 0x8000000000000000Ui64))
          return 0;

  return 1;
}
