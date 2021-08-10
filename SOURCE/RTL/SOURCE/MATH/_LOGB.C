/*------------------------------------------------------------------------
 * filename - _logb.c
 *
 * function(s)
 *
 *   _logb    - Double version
 *
 * These functions return the unbiased exponent of the value passed in.
 *
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1996, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <float.h>
#include <_float.h>

#pragma argsused
#pragma warn -rvl
double _RTLENTRY _EXPFUNC _logb(double __d)
{
  asm {
    fwait
    fld [__d]
    fxtract
    ffree st(0)
    fincstp
  }
  /* the exponent from __d is now in ST(0) in integral form. */
}

#pragma argsused
#pragma warn -rvl
long double _RTLENTRY _EXPFUNC _logbl(long double __ld)
{
  asm {
    fwait
    fld [__ld]
    fxtract
    ffree st(0)
    fincstp
  }
  /* the exponent from __ld is now in ST(0) in integral form. */
}
