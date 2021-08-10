/*------------------------------------------------------------------------
 * filename - _cpysgn.c
 *
 * function(s)
 *
 *   _cpysign    - double version
 *   _cpysignl   - long double version
 *
 * Returns the first value with the same magnitude and exponent, but with
 * the sign of the second value
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1998, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <float.h>
#include <_float.h>

double _RTLENTRY _EXPFUNC _copysign(double __da, double __db)
{
    ((_rtl_double_t *)&__da)->i64.s.high32.s.high16.s.high08.value =
    (((_rtl_double_t *)&__da)->i64.s.high32.s.high16.s.high08.value & ~0x80) |
     (((_rtl_double_t *)&__db)->i64.s.high32.s.high16.s.high08.value & 0x80);
    return __da;
}

long double _RTLENTRY _EXPFUNC _copysignl(long double __lda, long double __ldb)
{
    ((_rtl_ldouble_t *)&__lda)->i16.s.high08.value =
    (((_rtl_ldouble_t *)&__lda)->i16.s.high08.value & ~0x80) |
     (((_rtl_ldouble_t *)&__ldb)->i16.s.high08.value & 0x80);
    return __lda;
}
