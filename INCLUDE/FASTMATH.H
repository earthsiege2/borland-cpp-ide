/*
   fastmath.h - header file for the FastMath routines.  These are high
                performance math routines that don't bother checking for
                most error conditions and never call matherr.  They are
                coded for maximum speed and most are written in assembly.

                These functions are never exported from the RTLDLL, which
                means that they always get linked directly into the PE file
                which is being created.

*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1999, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.9.2.1 $ */

#ifndef __FASTMATH_H
#define __FASTMATH_H

#include <_defs.h>
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

#define _FMAPI _RTLENTRY /* FastMath API */

/* _FMAPI functions are never exported from the RTLDLL, they always get linked
   into the PE file directly.
*/

/* double routines: */

double      _FMAPI _fm_acos    (double __x);
double      _FMAPI _fm_asin    (double __x);
double      _FMAPI _fm_atan    (double __x);
double      _FMAPI _fm_atan2   (double __y, double __x);
double      _FMAPI _fm_cos     (double __x);
double      _FMAPI _fm_cosh    (double __x);
double      _FMAPI _fm_exp     (double __x);
double      _FMAPI _fm_fabs    (double __x);
double      _FMAPI _fm_frexp   (double __x, int * __exponent);
double      _FMAPI _fm_hypot   (double __x, double __y);
double      _FMAPI _fm_ldexp   (double __x, int __exponent);
double      _FMAPI _fm_log     (double __x);
double      _FMAPI _fm_log10   (double __x);
double      _FMAPI _fm_sin     (double __x);
double      _FMAPI _fm_sinh    (double __x);
double      _FMAPI _fm_sqrt    (double __x);
double      _FMAPI _fm_tan     (double __x);
double      _FMAPI _fm_tanh    (double __x);

/* long double routines: */

long double _FMAPI _fm_acosl  (long double __x);
long double _FMAPI _fm_asinl  (long double __x);
long double _FMAPI _fm_atan2l (long double __x, long double __y);
long double _FMAPI _fm_atanl  (long double __x);
long double _FMAPI _fm_coshl  (long double __x);
long double _FMAPI _fm_cosl   (long double __x);
long double _FMAPI _fm_expl   (long double __x);
long double _FMAPI _fm_fabsl  (long double __x);
long double _FMAPI _fm_frexpl (long double __x, int * __exponent);
long double _FMAPI _fm_hypotl (long double __x, long double __y);
long double _FMAPI _fm_ldexpl (long double __x, int __exponent);
long double _FMAPI _fm_log10l (long double __x);
long double _FMAPI _fm_logl   (long double __x);
long double _FMAPI _fm_sinhl  (long double __x);
long double _FMAPI _fm_sinl   (long double __x);
long double _FMAPI _fm_sqrtl  (long double __x);
long double _FMAPI _fm_tanhl  (long double __x);
long double _FMAPI _fm_tanl   (long double __x);

/* Additional fast functions, not directly supported in the regular RTL: */

/* double routines: */
void _FMAPI _fm_sincos(double __a, double *__x, double *__y);

/* long double routines: */
void _FMAPI _fm_sincosl(long double __a, long double *__x, long double *__y);
long double _FMAPI              _fm_atanhl (long double __x);
long double _FMAPI              _fm_acoshl (long double __x);
long double _FMAPI              _fm_asinhl (long double __x);


/* Special inline function that performs an intrinsic FWAIT instruction */
__inline void _fm_fwait(void)
{
    __emit__(0x9B);  /* asm FWAIT */
}

/* _fm_init can be called to mask all fpu exceptions prior to using the
  FastMath routines.
*/
unsigned int _FMAPI _fm_init(void);


/* If you don't want the standard C function names re-mapped to the FastMath
   versions, then define _FM_NO_REMAP.  The FastMath routines can still be
   called with their _fm_xxx names.
*/
#ifndef _FM_NO_REMAP

/* Undefine the standard functions names in preparation for re-mapping */

#undef acos
#undef asin
#undef atan
#undef atan2
#undef cos
#undef cosh
#undef exp
#undef fabs
#undef frexp
#undef hypot
#undef ldexp
#undef log
#undef log10
#undef sin
#undef sinh
#undef sqrt
#undef tan
#undef tanh
#undef sincos

#undef acosl
#undef asinl
#undef atan2l
#undef atanl
#undef coshl
#undef cosl
#undef expl
#undef fabsl
#undef frexpl
#undef hypotl
#undef ldexpl
#undef log10l
#undef logl
#undef sinhl
#undef sinl
#undef sqrtl
#undef tanhl
#undef tanl
#undef sincosl

#undef atanhl
#undef acoshl
#undef asinhl

/* now re-map the standard names to their FastMath equivalents */

#define acos      _fm_acos
#define asin      _fm_asin
#define atan      _fm_atan
#define atan2     _fm_atan2
#define cos       _fm_cos
#define cosh      _fm_cosh
#define exp       _fm_exp
#define fabs      _fm_fabs
#define frexp     _fm_frexp
#define hypot     _fm_hypot
#define ldexp     _fm_ldexp
#define log       _fm_log
#define log10     _fm_log10
#define sin       _fm_sin
#define sinh      _fm_sinh
#define sqrt      _fm_sqrt
#define tan       _fm_tan
#define tanh      _fm_tanh
#define sincos    _fm_sincos

#define acosl     _fm_acosl
#define asinl     _fm_asinl
#define atan2l    _fm_atan2l
#define atanl     _fm_atanl
#define coshl     _fm_coshl
#define cosl      _fm_cosl
#define expl      _fm_expl
#define fabsl     _fm_fabsl
#define frexpl    _fm_frexpl
#define hypotl    _fm_hypotl
#define ldexpl    _fm_ldexpl
#define log10l    _fm_log10l
#define logl      _fm_logl
#define sinhl     _fm_sinhl
#define sinl      _fm_sinl
#define sqrtl     _fm_sqrtl
#define tanhl     _fm_tanhl
#define tanl      _fm_tanl
#define sincosl   _fm_sincosl

#define atanhl    _fm_atanhl
#define acoshl    _fm_acoshl
#define asinhl    _fm_asinhl

#endif /* _FM_NO_REMAP */

#ifdef __cplusplus
} // "C"
#endif

#endif /* __FASTMATH_H */