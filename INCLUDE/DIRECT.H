/*  direct.h


    Defines structures, macros, and functions for dealing with
    directories and pathnames.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.3  $ */

#ifndef __DIRECT_H
#define __DIRECT_H


#if !defined(__DIR_H)
#include <dir.h>
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */


#ifdef __cplusplus
extern "C" {
#endif

/* Prototypes for MSC functions */

int    _RTLENTRY _EXPFUNC _chdrive(int __drive);
char * _RTLENTRY _EXPFUNC _getdcwd(int __drive, char * __buf, int __len);

wchar_t * _RTLENTRY _EXPFUNC _wgetdcwd(int __drive, wchar_t * __buf, int __len);

unsigned long _RTLENTRY _EXPFUNC _getdrives(void);



#ifdef __cplusplus
}
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif /* __DIRECT_H */
