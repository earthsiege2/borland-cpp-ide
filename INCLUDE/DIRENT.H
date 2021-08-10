/*  dirent.h

    Definitions for POSIX directory operations.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1991, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.2  $ */

#ifndef __DIRENT_H
#define __DIRENT_H

#ifndef ___STDDEF_H
#include <_stddef.h>
#endif

#ifndef _WINDOWS_
#include <windows.h>  /* For WIN32_FIND_DATA */
#endif

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#pragma pack(push, 1)

#endif  /* !RC_INVOKED */


#ifdef __cplusplus
extern "C" {
#endif


/* dirent structure returned by readdir().
 */
struct dirent
{
    char        d_name[260];
};

/* wdirent structure returned by wreaddir().
 */
struct wdirent
{
    wchar_t        d_name[260];
};

/* DIR type returned by opendir().  The members of this structure
 * must not be accessed by application programs.
 */
typedef struct
{
    unsigned long _d_hdir;              /* directory handle */
    char         *_d_dirname;           /* directory name */
    unsigned      _d_magic;             /* magic cookie for verifying handle */
    unsigned      _d_nfiles;            /* no. of files remaining in buf */
    char          _d_buf[sizeof(WIN32_FIND_DATA)];  /* buffer for a single file */
} DIR;

typedef struct
{
    unsigned long _d_hdir;              /* directory handle */
    wchar_t      *_d_dirname;           /* directory name */
    unsigned      _d_magic;             /* magic cookie for verifying handle */
    unsigned      _d_nfiles;            /* no. of files remaining in buf */
    char          _d_buf[sizeof(WIN32_FIND_DATA)];  /* buffer for a single file */
} wDIR;

wDIR           * _RTLENTRY _EXPFUNC wopendir  (const wchar_t *__dirname);
struct wdirent * _RTLENTRY _EXPFUNC wreaddir  (wDIR *__dir);
int              _RTLENTRY _EXPFUNC wclosedir (wDIR *__dir);
void             _RTLENTRY _EXPFUNC wrewinddir(wDIR *__dir);

/* Prototypes.
 */
DIR            _FAR * _RTLENTRY _EXPFUNC opendir  (const char _FAR *__dirname);
struct dirent  _FAR * _RTLENTRY _EXPFUNC readdir  (DIR _FAR *__dir);
int                   _RTLENTRY _EXPFUNC closedir (DIR _FAR *__dir);
void                  _RTLENTRY _EXPFUNC rewinddir(DIR _FAR *__dir);

#ifdef __cplusplus
}
#endif


#if !defined(RC_INVOKED)

/* restore default packing */
#pragma pack(pop)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif  /* __DIRENT_H */

