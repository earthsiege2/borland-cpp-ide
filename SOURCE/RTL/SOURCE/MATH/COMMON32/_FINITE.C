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
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1996, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.0  $        */

#pragma inline
#include <float.h>

union u_float
{
  unsigned long a;
};

union u_double
{
  struct _sd
  {
    unsigned long b,a;
  } s;
};

int _RTLENTRY _EXPFUNC _finite (double d)
{
  union u_double *p = (union u_double *)&d;

  if ((p->s.a & 0x7FF00000) == 0x7FF00000)
        return 0;

  return 1;
}

#if 0  // Not used since float->double conversion will take place
int _RTLENTRY _EXPFUNC _finitef (float f)
{
  union u_float *p = (union u_float *)&f;

  if ((p->a & 0x7F800000) == 0x7F800000)
        return 0;

  return 1;
}
#endif
