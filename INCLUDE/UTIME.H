/*  utime.h

    Definitions for utime() function.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1991, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.3  $ */

#ifndef __UTIME_H
#define __UTIME_H

#ifndef ___STDDEF_H
#include <_stddef.h>
#endif

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#pragma pack(push, 1)

#endif  /* !RC_INVOKED */


#ifndef  _TIME_T
#define  _TIME_T
typedef long time_t;
#endif

/* Structure passed to utime containing file times
 */
struct utimbuf
{
        time_t  actime;         /* access time (used on NTFS) */
        time_t  modtime;        /* modification time */
};

#ifdef __cplusplus
extern "C" {
#endif

int    _RTLENTRY _EXPFUNC _utime(const char * __path,
                                 const struct utimbuf *__times);
int    _RTLENTRY _EXPFUNC _wutime(const wchar_t * __path,
                                  const struct utimbuf *__times);

#if !defined(__STDC__)
int    _RTLENTRY _EXPFUNC utime(const char * __path,
                                const struct utimbuf *__times);
#endif

int _RTLENTRY _EXPFUNC _futime(int __fd, const struct utimbuf *__times);

#ifdef __cplusplus
}
#endif


#if !defined(RC_INVOKED)

#pragma pack(pop)       /* restore default packing */

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif  /* __UTIME_H */

