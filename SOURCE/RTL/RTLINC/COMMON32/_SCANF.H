/*------------------------------------------------------------------------
 * filename - _scanf.h
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.3  $ */

#ifndef __SCANF_H
#define __SCANF_H

#if !defined(__STDARG_H)
#include <stdarg.h>
#endif

#if !defined(__STDDEF_H)
#include <stddef.h>
#endif

#include <tchar.h>

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

int _scannerw    ( int   (*__Getw)   (void *__srceP),
                   void  (*__UnGetw) (int __ch, void *__srceP),
                   void       *__srceP,
                   const wchar_t *__formP,
                   va_list     __varPP );

void _RTLENTRY _scantod (
                   void    *__valueP,   /* actually long double *   */
                   int    (*__Get)   (void *__srceP),
                   void   (*__UnGet) (int __ch, void *__srceP),
                   void    *__srceP,
                   int      __width,
                   int     *__countP,
                   int     *__statusP );

void _RTLENTRY _scanwtod (
                   void    *__valueP,   /* actually long double *   */
                   int    (*__Getw)   (void *__srceP),
                   void   (*__UnGetw) (int __ch, void *__srceP),
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

long _scanwtol    ( int    (*__Getw)   (void *__srceP),
                   void   (*__UnGetw) (int __ch, void *__srceP),
                   void    *__srceP,
                   int      __radix,
                   int      __width,
                   int     *__countP,
                   int     *__statusP );


__int64 __scantoint64(
                   int  (*Get)   (void *srceP),
                   void (*UnGet) (int ch, void *srceP),
                   void *srceP,
                   int  radix,
                   int  width,
                   int  *countP,
                   int  *statusP );

__int64 __scanwtoint64(
                   int  (*Get)   (void *srceP),
                   void (*UnGet) (int ch, void *srceP),
                   void *srceP,
                   int  radix,
                   int  width,
                   int  *countP,
                   int  *statusP );

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
