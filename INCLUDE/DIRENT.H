/*  dirent.h

    Definitions for POSIX directory operations.

*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1991, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __DIRENT_H
#define __DIRENT_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#ifndef NULL
#include <_null.h>
#endif

#if defined(__WIN32__)
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
#if defined(__OS2__)
    char        d_name[256];
#elif defined(__WIN32__) || defined(__DPMI32__)
    char        d_name[260];
#else
    char        d_name[13];
#endif
};

#if !defined(__FLAT__)

/* _DIR type returned by _opendir().  The first two members cannot
 * be separated, because they make up the DOS DTA structure used
 * by _findfirst() and _findnext().
 */
typedef struct
{
    char           _d_reserved[30];      /* reserved part of DTA */
    struct dirent  _d_dirent;            /* filename part of DTA */
    char    _FAR  *_d_dirname;           /* directory name */
    char           _d_first;             /* first file flag */
    unsigned char  _d_magic;             /* magic cookie for verifying handle */
} DIR;

#else    /* defined __FLAT__ */


/* DIR type returned by opendir().  The members of this structure
 * must not be accessed by application programs.
 */
typedef struct
{
    unsigned long _d_hdir;              /* directory handle */
    char         *_d_dirname;           /* directory name */
    unsigned      _d_magic;             /* magic cookie for verifying handle */
    unsigned      _d_nfiles;            /* no. of files remaining in buf */
#if defined(__OS2__)
    char         *_d_bufp;              /* next entry in buffer */
    char          _d_buf[512];          /* buffer for found filenames */
#endif
#if defined(__WIN32__)
    char          _d_buf[sizeof(WIN32_FIND_DATA)];  /* buffer for a single file */
#endif
} DIR;

#endif  /* __FLAT__ */

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

