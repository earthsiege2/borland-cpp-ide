/*------------------------------------------------------------------------
 * filename - _finite.c
 *
 * function(s)
 *
 *   _finite    - double version
 *
 * These functions return 1 if the value passed in is finite, and 0 if not
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1996, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

#include <float.h>
#include <_float.h>

int _RTLENTRY _EXPFUNC _finite (double d)
{
  if ((((_rtl_double_t *)&d)->i64.s.high32.value & 0x7FF00000) == 0x7FF00000)
        return 0;

  return 1;
}
