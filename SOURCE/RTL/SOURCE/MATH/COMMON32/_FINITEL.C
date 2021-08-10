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

int _RTLENTRY _EXPFUNC _finitel (long double ld)
{
  union u_ldouble *p = (union u_ldouble *)&ld;

  if ((p->s.a & 0x7FFF8000) == 0x7FFF8000)
        return 0;

  return 1;
}
