/*  stat.h

    Definitions used for file status functions
*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.6  $ */

#if !defined(__STAT_H)
#define __STAT_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#if !defined(__TYPES_H)
#include <sys/types.h>
#endif

#ifndef _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif

/* Traditional names for bits in st_mode.
 */
#define S_IFMT   0xF000  /* file type mask */
#define S_IFDIR  0x4000  /* directory */
#define S_IFIFO  0x1000  /* FIFO special */
#define S_IFCHR  0x2000  /* character special */
#define S_IFBLK  0x3000  /* block special */
#define S_IFREG  0x8000  /* or just 0x0000, regular */
#define S_IREAD  0x0100  /* owner may read */
#define S_IWRITE 0x0080  /* owner may write */
#define S_IEXEC  0x0040  /* owner may execute <directory search> */

/* POSIX file type test macros.  The parameter is an st_mode value.
 */
#define S_ISDIR(m)  ((m) & S_IFDIR)
#define S_ISCHR(m)  ((m) & S_IFCHR)
#define S_ISBLK(m)  ((m) & S_IFBLK)
#define S_ISREG(m)  ((m) & S_IFREG)
#define S_ISFIFO(m) ((m) & S_IFIFO)

/* POSIX names for bits in st_mode.
 */
#define S_IRWXU  0x01c0 /* RWE permissions mask for owner */
#define S_IRUSR  0x0100 /* owner may read */
#define S_IWUSR  0x0080 /* owner may write */
#define S_IXUSR  0x0040 /* owner may execute <directory search> */

#if !defined(_RC_INVOKED)
#pragma option push -a1
#endif

struct  stat
{
    dev_t   st_dev;
    ino_t   st_ino;
    mode_t  st_mode;
    nlink_t st_nlink;
    uid_t   st_uid;
    gid_t   st_gid;
    dev_t   st_rdev;
    off_t   st_size;
    _TIME_T  st_atime;
    _TIME_T  st_mtime;
    _TIME_T  st_ctime;
};

#if !defined(__STDC__) && (__BORLANDC__  >= 0x0520)
struct  stati64
{
    dev_t   st_dev;
    ino_t   st_ino;
    mode_t  st_mode;
    nlink_t st_nlink;
    uid_t   st_uid;
    gid_t   st_gid;
    dev_t   st_rdev;
    __int64 st_size;
    _TIME_T  st_atime;
    _TIME_T  st_mtime;
    _TIME_T  st_ctime;
};
#endif

#if !defined(_RC_INVOKED)
#pragma option pop
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Define MS compatible names
*/
#define _S_IFMT   S_IFMT
#define _S_IFDIR  S_IFDIR
#define _S_IFIFO  S_IFIFO
#define _S_IFCHR  S_IFCHR
#define _S_IFBLK  S_IFBLK
#define _S_IFREG  S_IFREG
#define _S_IREAD  S_IREAD
#define _S_IWRITE S_IWRITE
#define _S_IEXEC  S_IEXEC

struct  _stat
{
    short st_dev;
    short st_ino;
    short st_mode;
    short st_nlink;
    int   st_uid;
    int   st_gid;
    short st_rdev;
    long  st_size;
    long  st_atime;
    long  st_mtime;
    long  st_ctime;
};


int  _RTLENTRY _EXPFUNC _fstat(int __handle, struct _stat  *__statbuf);
int  _RTLENTRY _EXPFUNC fstat(int __handle, struct stat  *__statbuf);
int  _RTLENTRY _EXPFUNC _wstat(const wchar_t *__path, struct _stat *__statbuf);
int  _RTLENTRY _EXPFUNC _stati64(const char *__path, struct stati64 *__statbuf);
int  _RTLENTRY _EXPFUNC _wstati64(const wchar_t *__path, struct stati64 *__statbuf);
int  _RTLENTRY _EXPFUNC _stat(const char  *__path, struct _stat  *__statbuf);
#if !defined(__STDC__) && (__BORLANDC__  >= 0x0520)
int  _RTLENTRY _EXPFUNC stat(const char *__path, struct stat  *__statbuf);
#endif  /* __STDC__ && __BORLANDC__ */


#ifdef __cplusplus
}
#endif

#endif  /* __STAT_H */
