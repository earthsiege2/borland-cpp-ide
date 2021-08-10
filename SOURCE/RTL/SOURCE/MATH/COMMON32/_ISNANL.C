/*------------------------------------------------------------------------
 * filename - _isnanl.c
 *
 * function(s)
 *
 *   _isnanl    - long double version
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

union u_ldouble
{
  struct _sld
  {
    unsigned short c;
    unsigned long b,a;
  } s;
};

int _RTLENTRY _EXPFUNC _isnanl (long double ld)
{
  union u_ldouble *p = (union u_ldouble *)&ld;

  if ((p->s.a & 0x7FFF8000) == 0x7FFF8000)
    if ( ((p->s.a & 0x00007FFF) != 0) || (p->s.b) || (p->s.c))
        return 1;

  return 0;
}

