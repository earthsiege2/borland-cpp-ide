/*  direct.h


    Defines structures, macros, and functions for dealing with
    directories and pathnames.

*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __DIRECT_H
#define __DIRECT_H

#pragma warn -nak   /* Ignore non-ansi keywords */

#if !defined(__DIR_H)
#include <dir.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Prototypes for MSC functions */

#if !defined(__FLAT__)

int    _Cdecl _chdrive(int __drive);
char _FAR * _Cdecl _FARFUNC _getdcwd(int __drive, char _FAR *__buf, int __len);
int    _Cdecl _getdrive(void);

#else   /* defined __FLAT__ */

int    _RTLENTRY _EXPFUNC _chdrive(int __drive);
char * _RTLENTRY _EXPFUNC _getdcwd(int __drive, char * __buf, int __len);
int    _RTLENTRY _EXPFUNC _getdrive(void);

#endif /* __FLAT__ */

#ifdef __cplusplus
}
#endif

#pragma warn .nak   /* Ignore non-ansi keywords */

#endif /* __DIRECT_H */
