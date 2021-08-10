/*------------------------------------------------------------------------
 * filename - _isnan.c
 *
 * function(s)
 *
 *   _isnan     - double version
 *
 * These functions return 1 if the value passed in is +-NAN, and 0 if not
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

int _RTLENTRY _EXPFUNC _isnan (double d)
{
  union u_double *p = (union u_double *)&d;

  if ((p->s.a & 0x7FF00000) == 0x7FF00000)
    if ( ((p->s.a & 0x000FFFFF) != 0) || (p->s.b))
        return 1;

  return 0;
}

#if 0  // Not used since float->double conversion will take place
int _RTLENTRY _EXPFUNC _isnanf (float f)
{
  union u_float *p = (union u_float *)&f;

  if ((p->a & 0x7F800000) == 0x7F800000)
    if ((p->a & 0x007FFFFF) != 0)
        return 1;

  return 0;
}
#endif
