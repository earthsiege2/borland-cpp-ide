/*------------------------------------------------------------------------
 * filename - _scanf.h
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __SCANF_H
#define __SCANF_H

#if !defined(__STDARG_H)
#include <stdarg.h>
#endif

typedef enum
{
    isSuppressed = 1,
    isHalf       = 2,
    isLong       = 4,
    isLongDouble = 8,
    isExclusive  = 16,
    isFarPtr     = 32
} flagBits;


#ifdef __cplusplus
extern "C" {
#endif
int _scanner     ( int   (*__Get)   (void *__srceP),
                   void  (*__UnGet) (int __ch, void *__srceP),
                   void       *__srceP,
                   const char *__formP,
                   va_list     __varPP );

void _RTLENTRY _scantod (
                   void    *__valueP,   /* actually long double *   */
                   int    (*__Get)   (void *__srceP),
                   void   (*__UnGet) (int __ch, void *__srceP),
                   void    *__srceP,
                   int      __width,
                   int     *__countP,
                   int     *__statusP );

long _scantol    ( int    (*__Get)   (void *__srceP),
                   void   (*__UnGet) (int __ch, void *__srceP),
                   void    *__srceP,
                   int      __radix,
                   int      __width,
                   int     *__countP,
                   int     *__statusP );

void _RTLENTRY _scanrslt (
                   void    *__valueP,
                   void    *__rsltP,
                   int      __rsltType);

/*
  Internal RTL function to perform double/float truncations.
*/
#define FLT 0
#define DBL 1
double __ldtrunc(int __flag, long double __x, double __xhuge);

#ifdef __cplusplus
}
#endif

#endif
