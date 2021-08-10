/*  math.h

    Definitions for the math floating point package.

*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef  __MATH_H
#define  __MATH_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#pragma option -a-

#endif  /* !RC_INVOKED */


#if !defined(__STDC__) /* NON-ANSI */

#ifdef __cplusplus
    /* use class complex instead of _cabs in C++ */
#else
struct complex      /* as used by "_cabs" function */
{
    double  x, y;
};

struct _complexl    /* as used by "_cabsl" function */
{
    long double  x, y;
};

#define cabs(z)     (hypot  ((z).x, (z).y))
#define cabsl(z)    (hypotl ((z).x, (z).y))
#endif /* NON-ANSI */

#endif

typedef enum
{
    DOMAIN = 1,    /* argument domain error -- log (-1)        */
    SING,          /* argument singularity  -- pow (0,-2))     */
    OVERFLOW,      /* overflow range error  -- exp (1000)      */
    UNDERFLOW,     /* underflow range error -- exp (-1000)     */
    TLOSS,         /* total loss of significance -- sin(10e70) */
    PLOSS,         /* partial loss of signif. -- not used      */
    STACKFAULT     /* floating point unit stack overflow       */
}   _mexcep;

/* Constants rounded for 21 decimals. */
#define M_E         2.71828182845904523536
#define M_LOG2E     1.44269504088896340736
#define M_LOG10E    0.434294481903251827651
#define M_LN2       0.693147180559945309417
#define M_LN10      2.30258509299404568402
#define M_PI        3.14159265358979323846
#define M_PI_2      1.57079632679489661923
#define M_PI_4      0.785398163397448309616
#define M_1_PI      0.318309886183790671538
#define M_2_PI      0.636619772367581343076
#define M_1_SQRTPI  0.564189583547756286948
#define M_2_SQRTPI  1.12837916709551257390
#define M_SQRT2     1.41421356237309504880
#define M_SQRT_2    0.707106781186547524401

#define EDOM    33      /* Math argument */
#define ERANGE  34      /* Result too large */

struct  exception
{
    int type;
    char   _FAR *name;
    double  arg1, arg2, retval;
};

struct  _exceptionl
{
    int type;
    char   _FAR *name;
    long double  arg1, arg2, retval;
};

#if !defined(__FLAT__)

#define HUGE_VAL    _huge_dble
extern double _RTLENTRY _huge_dble;
#define _LHUGE_VAL   _huge_ldble
extern long double _RTLENTRY _huge_ldble;

#ifdef __cplusplus
extern "C" {
#endif
double      _RTLENTRY _EXPFUNC acos    (double __x);
double      _RTLENTRY _EXPFUNC asin    (double __x);
double      _RTLENTRY          atan    (double __x);
double      _RTLENTRY _EXPFUNC atan2   (double __y, double __x);
double      _RTLENTRY _EXPFUNC ceil    (double __x);
double      _RTLENTRY _EXPFUNC cos     (double __x);
double      _RTLENTRY _EXPFUNC cosh    (double __x);
double      _RTLENTRY _EXPFUNC exp     (double __x);
double      _RTLENTRY          fabs    (double __x);
double      _RTLENTRY          __fabs__(double __x); /* Intrinsic */
double      _RTLENTRY _EXPFUNC floor   (double __x);
double      _RTLENTRY _EXPFUNC fmod    (double __x, double __y);
double      _RTLENTRY _EXPFUNC frexp   (double __x, int _FAR *__exponent);
double      _RTLENTRY _EXPFUNC ldexp   (double __x, int __exponent);
double      _RTLENTRY _EXPFUNC log     (double __x);
double      _RTLENTRY _EXPFUNC log10   (double __x);
double      _RTLENTRY _EXPFUNC modf    (double __x, double _FAR *__ipart);
double      _RTLENTRY _EXPFUNC pow     (double __x, double __y);
double      _RTLENTRY _EXPFUNC sin     (double __x);
double      _RTLENTRY _EXPFUNC sinh    (double __x);
double      _RTLENTRY _EXPFUNC sqrt    (double __x);
double      _RTLENTRY _EXPFUNC tan     (double __x);
double      _RTLENTRY _EXPFUNC tanh    (double __x);

long double _RTLENTRY _EXPFUNC acosl  (long double __x);
long double _RTLENTRY _EXPFUNC asinl  (long double __x);
long double _RTLENTRY _EXPFUNC atan2l (long double __x, long double __y);
long double _RTLENTRY          atanl  (long double __x);
long double _RTLENTRY _EXPFUNC ceill  (long double __x);
long double _RTLENTRY _EXPFUNC coshl  (long double __x);
long double _RTLENTRY _EXPFUNC cosl   (long double __x);
long double _RTLENTRY _EXPFUNC expl   (long double __x);
long double _RTLENTRY          fabsl  (long double __x);
long double _RTLENTRY _EXPFUNC floorl (long double __x);
long double _RTLENTRY _EXPFUNC fmodl  (long double __x, long double __y);
long double _RTLENTRY _EXPFUNC frexpl (long double __x, int _FAR *__exponent);
long double _RTLENTRY _EXPFUNC ldexpl (long double __x, int __exponent);
long double _RTLENTRY _EXPFUNC log10l (long double __x);
long double _RTLENTRY _EXPFUNC logl   (long double __x);
long double _RTLENTRY _EXPFUNC modfl  (long double __x, long double _FAR *__ipart);
long double _RTLENTRY _EXPFUNC powl   (long double __x, long double __y);
long double _RTLENTRY _EXPFUNC sinhl  (long double __x);
long double _RTLENTRY _EXPFUNC sinl   (long double __x);
long double _RTLENTRY _EXPFUNC sqrtl  (long double __x);
long double _RTLENTRY _EXPFUNC tanhl  (long double __x);
long double _RTLENTRY _EXPFUNC tanl   (long double __x);

#ifdef __cplusplus
}
#endif


#if !__STDC__

#ifdef __cplusplus
extern "C" {
#endif

double      _RTLENTRY _EXPFUNC hypot (double __x, double __y);
int         _RTLENTRY _EXPFUNC _matherr (struct exception _FAR *__e);
double      _RTLENTRY _EXPFUNC poly  (double __x, int __degree, double _FAR *__coeffs);
double      _RTLENTRY _EXPFUNC pow10 (int __p);
long double _RTLENTRY _EXPFUNC hypotl (long double __x, long double __y);
long double _RTLENTRY _EXPFUNC polyl  (long double __x, int __degree, long double _FAR *__coeffs);
long double _RTLENTRY _EXPFUNC pow10l (int __p);

#if !defined(__ABS_DEFINED)
#define __ABS_DEFINED
int         _RTLENTRY __abs__(int);
#ifdef __cplusplus
inline int _RTLENTRY  abs(int __x) { return __abs__(__x); }
#else
int         _RTLENTRY abs(int __x);
#  define abs(x)   __abs__(x)
#endif

#endif /* __ABS_DEFINED */

double      _RTLENTRY          atof  (const char _FAR *__s);
long        _RTLENTRY          labs  (long __x);
int         _RTLENTRY _EXPFUNC _matherrl (struct _exceptionl _FAR *__e);

long double _RTLENTRY          _atold (const char _FAR *__s);

long double _RTLENTRY _EXPFUNC hypotl (long double __x, long double __y);
long double _RTLENTRY _EXPFUNC polyl  (long double __x, int __degree, long double _FAR *__coeffs);
long double _RTLENTRY _EXPFUNC pow10l (int __p);

#ifdef __cplusplus
}
#endif

#endif  /* !__STDC__ */

#else   /* defined __FLAT__ */

#define HUGE_VAL    _huge_dble
extern double _RTLENTRY _EXPDATA _huge_dble;
#define _LHUGE_VAL   _huge_ldble
extern long double _RTLENTRY _EXPDATA _huge_ldble;

#ifdef __cplusplus
extern "C" {
#endif
double      _RTLENTRY _EXPFUNC acos    (double __x);
double      _RTLENTRY _EXPFUNC asin    (double __x);
double      _RTLENTRY _EXPFUNC atan    (double __x);
double      _RTLENTRY _EXPFUNC atan2   (double __y, double __x);
double      _RTLENTRY _EXPFUNC ceil    (double __x);
double      _RTLENTRY _EXPFUNC cos     (double __x);
double      _RTLENTRY _EXPFUNC cosh    (double __x);
double      _RTLENTRY _EXPFUNC exp     (double __x);
double      _RTLENTRY _EXPFUNC fabs    (double __x);
double      _RTLENTRY _EXPFUNC floor   (double __x);
double      _RTLENTRY _EXPFUNC fmod    (double __x, double __y);
double      _RTLENTRY _EXPFUNC frexp   (double __x, int * __exponent);
double      _RTLENTRY _EXPFUNC ldexp   (double __x, int __exponent);
double      _RTLENTRY _EXPFUNC log     (double __x);
double      _RTLENTRY _EXPFUNC log10   (double __x);
double      _RTLENTRY _EXPFUNC modf    (double __x, double * __ipart);
double      _RTLENTRY _EXPFUNC pow     (double __x, double __y);
double      _RTLENTRY _EXPFUNC sin     (double __x);
double      _RTLENTRY _EXPFUNC sinh    (double __x);
double      _RTLENTRY _EXPFUNC sqrt    (double __x);
double      _RTLENTRY _EXPFUNC tan     (double __x);
double      _RTLENTRY _EXPFUNC tanh    (double __x);

long double _RTLENTRY _EXPFUNC acosl  (long double __x);
long double _RTLENTRY _EXPFUNC asinl  (long double __x);
long double _RTLENTRY _EXPFUNC atan2l (long double __x, long double __y);
long double _RTLENTRY _EXPFUNC atanl  (long double __x);
long double _RTLENTRY _EXPFUNC ceill  (long double __x);
long double _RTLENTRY _EXPFUNC coshl  (long double __x);
long double _RTLENTRY _EXPFUNC cosl   (long double __x);
long double _RTLENTRY _EXPFUNC expl   (long double __x);
long double _RTLENTRY _EXPFUNC fabsl  (long double __x);
long double _RTLENTRY _EXPFUNC floorl (long double __x);
long double _RTLENTRY _EXPFUNC fmodl  (long double __x, long double __y);
long double _RTLENTRY _EXPFUNC frexpl (long double __x, int * __exponent);
long double _RTLENTRY _EXPFUNC ldexpl (long double __x, int __exponent);
long double _RTLENTRY _EXPFUNC log10l (long double __x);
long double _RTLENTRY _EXPFUNC logl   (long double __x);
long double _RTLENTRY _EXPFUNC modfl  (long double __x, long double * __ipart);
long double _RTLENTRY _EXPFUNC powl   (long double __x, long double __y);
long double _RTLENTRY _EXPFUNC sinhl  (long double __x);
long double _RTLENTRY _EXPFUNC sinl   (long double __x);
long double _RTLENTRY _EXPFUNC sqrtl  (long double __x);
long double _RTLENTRY _EXPFUNC tanhl  (long double __x);
long double _RTLENTRY _EXPFUNC tanl   (long double __x);

/* Intrinsic functions */

double      _RTLENTRY _EXPFUNC __sin__ (double __x);
double      _RTLENTRY _EXPFUNC __cos__ (double __x);
long double _RTLENTRY _EXPFUNC __cosl__(long double __x);
long double _RTLENTRY _EXPFUNC __sinl__(long double __x);

#ifdef __cplusplus
}
#endif


#if !defined(__STDC__) /* NON_ANSI */

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(__ABS_DEFINED)
#define __ABS_DEFINED
int         _RTLENTRY __abs__(int);
#ifdef __cplusplus
inline int _RTLENTRY  abs(int __x) { return __abs__(__x); }
#else
int         _RTLENTRYF _EXPFUNC abs(int __x);
#  define abs(x)   __abs__(x)
#endif
#endif /* __ABS_DEFINED */

double      _RTLENTRY _EXPFUNC atof    (const char * __s);
long        _RTLENTRY _EXPFUNC labs    (long __x);
double      _RTLENTRY _EXPFUNC pow10   (int __p);

long double _RTLENTRY _EXPFUNC _atold  (const char * __s);

int         _RTLENTRY          _matherr(struct exception  *__e);
int         _RTLENTRY          _matherrl(struct _exceptionl *__e);

double      _RTLENTRY _EXPFUNC hypot   (double __x, double __y);
double      _RTLENTRY _EXPFUNC poly    (double __x, int __degree, double coeffs []);
long double _RTLENTRY _EXPFUNC hypotl  (long double __x, long double __y);
long double _RTLENTRY _EXPFUNC polyl   (long double __x, int __degree, long double coeffs []);
long double _RTLENTRY _EXPFUNC pow10l  (int __p);


#ifdef __cplusplus
}
#endif

#endif  /* !__STDC__ */

#endif  /* __FLAT__ */


#if !defined(RC_INVOKED)

#pragma option -a. /* restore default packing */

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif  /* __MATH_H */



