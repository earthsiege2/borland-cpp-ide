/*  utime.h

    Definitions for utime() function.

*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __UTIME_H
#define __UTIME_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#if defined(__FLAT__)
#if !defined(_RC_INVOKED)
#pragma option -a-
#endif
#endif

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

int    _RTLENTRY _EXPFUNC utime(const char _FAR * __path,
                                const struct utimbuf _FAR *__times);

#else
int    _Cdecl _FARFUNC utime(char _FAR *__path, struct utimbuf _FAR *__times);
#endif

#ifdef __cplusplus
}
#endif

#if defined(__FLAT__)
#if !defined(_RC_INVOKED)
#pragma option -a.  /* restore default packing */
#endif
#endif

#endif  /* __UTIME_H */

