/*------------------------------------------------------------------------
 * filename - _chgsgn.c
 *
 * function(s)
 *
 *   _chgsign    - double version
 *   _chgsignl   - long double version
 *
 * Returns a value of the same magnitude and exponent, but with the opposite
 * sign.
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1998, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <float.h>
#include <_float.h>

double _RTLENTRY _EXPFUNC _chgsign(double __d)
{
    ((_rtl_double_t *)&__d)->i64.s.high32.s.high16.s.high08.value ^= 0x80;
    return __d;
}

long double _RTLENTRY _EXPFUNC _chgsignl(long double __ld)
{
    ((_rtl_ldouble_t *)&__ld)->i16.s.high08.value ^= 0x80;
    return __ld;
}
