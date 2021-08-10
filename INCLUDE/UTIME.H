/*  utime.h

    Definitions for utime() function.

*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.4  $ */

#ifndef __UTIME_H
#define __UTIME_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#ifndef __cplusplus
#if !defined(_WCHAR_T) && !defined(_WCHAR_T_DEFINED)
#define _WCHAR_T
#define _WCHAR_T_DEFINED  /* For WINDOWS.H */
typedef unsigned short wchar_t;
#endif
#endif

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#if defined(__FLAT__)
#pragma pack(push, 1)
#endif

#endif  /* !RC_INVOKED */


#ifndef  _TIME_T
#define  _TIME_T
typedef long time_t;
#endif

/* Structure passed to utime containing file times
 */
struct utimbuf
{
        time_t  actime;         /* access time (not used on DOS) */
        time_t  modtime;        /* modification time */
};

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__FLAT__)

int    _RTLENTRY _EXPFUNC _utime(const char * __path,
                                 const struct utimbuf *__times);
int    _RTLENTRY _EXPFUNC _wutime(const wchar_t * __path,
                                  const struct utimbuf *__times);

#if !defined(__STDC__)
int    _RTLENTRY _EXPFUNC utime(const char * __path,
                                const struct utimbuf *__times);
#endif

#else  /* __FLAT__  */
int    _Cdecl _FARFUNC utime(const char _FAR *__path,
                             const struct utimbuf _FAR *__times);
#endif

#ifdef __cplusplus
}
#endif


#if !defined(RC_INVOKED)

#if defined(__FLAT__)
#pragma pack(pop)       /* restore default packing */
#endif

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif  /* __UTIME_H */

