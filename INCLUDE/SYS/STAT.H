/*  stat.h

    Definitions used for file status functions
*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined(__STAT_H)
#define __STAT_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#if !defined(__TYPES_H)
#include <sys/types.h>
#endif

/* Traditional names for bits in st_mode.
 */
#define S_IFMT  0xF000  /* file type mask */
#define S_IFDIR 0x4000  /* directory */
#define S_IFIFO 0x1000  /* FIFO special */
#define S_IFCHR 0x2000  /* character special */
#define S_IFBLK 0x3000  /* block special */
#define S_IFREG 0x8000  /* or just 0x0000, regular */
#define S_IREAD 0x0100  /* owner may read */
#define S_IWRITE 0x0080 /* owner may write */
#define S_IEXEC 0x0040  /* owner may execute <directory search> */

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

#if !defined(_RC_INVOKED)
#pragma pack()
#endif

#else
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
int  _RTLENTRY _EXPFUNC stat(const char _FAR *__path, struct stat _FAR *__statbuf);

#ifdef __MSC
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

