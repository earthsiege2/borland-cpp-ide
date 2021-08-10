/*  stat.h

    Definitions used for file status functions
*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.10  $ */

#if !defined(__STAT_H)
#define __STAT_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#if !defined(__TYPES_H)
#include <sys/types.h>
#endif

#if defined  __FLAT__
#ifndef _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif
#endif /* __FLAT__ */

/* Traditional names for bits in st_mode.
 */
#define S_IFMT   0xF000  /* file type mask */
#define S_IFDIR  0x4000  /* directory */
#define S_IFIFO  0x1000  /* FIFO special */
#define S_IFCHR  0x2000  /* character special */
#define S_IFBLK  0x3000  /* block special */
#define S_IFREG  0x8000  /* or just 0x0000, regular */
#define S_IREAD  0x0100  /* owner may read */
#define S_IWRITE 0x0080 /* owner may write */
#define S_IEXEC  0x0040  /* owner may execute <directory search> */

#if defined(__FLAT__)
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
#pragma pack(1)
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
    time_t  st_atime;
    time_t  st_mtime;
    time_t  st_ctime;
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
    time_t  st_atime;
    time_t  st_mtime;
    time_t  st_ctime;
};
#endif

#if !defined(_RC_INVOKED)
#pragma pack()
#endif

#else  /* __FLAT__ */
struct  stat
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

#endif  /* __FLAT__ */

#ifdef __cplusplus
extern "C" {
#endif
int  _RTLENTRY _EXPFUNC fstat(int __handle, struct stat _FAR *__statbuf);
#if defined(__FLAT__)
int  _RTLENTRY _EXPFUNC _wstat(const wchar_t *__path, struct stat *__statbuf);
int  _RTLENTRY _EXPFUNC _stati64(const char *__path, struct stati64 *__statbuf);
int  _RTLENTRY _EXPFUNC _wstati64(const wchar_t *__path, struct stati64 *__statbuf);
int  _RTLENTRY _EXPFUNC _stat(const char _FAR *__path, struct stat _FAR *__statbuf);
#if !defined(__STDC__) && (__BORLANDC__  >= 0x0520)
int  _RTLENTRY _EXPFUNC stat(const char *__path, struct stat _FAR *__statbuf);
#endif  /* __STDC__ && __BORLANDC__ */
#else   /* __FLAT__ */
int  _RTLENTRY _EXPFUNC stat(const char *__path, struct stat _FAR *__statbuf);
#endif  /* __FLAT__ */

#ifdef __MSC

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

#define _fstat(h,b) fstat(h,(struct stat *)b)
#define _stat(p,b)   stat(p,(struct stat *)b)
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
#endif

#ifdef __cplusplus
}
#endif

#endif  /* __STAT_H */
