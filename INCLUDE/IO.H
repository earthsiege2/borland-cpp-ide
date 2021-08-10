/*  io.h

    Definitions for low level I/O functions.

*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.12  $ */

#ifndef __IO_H
#define __IO_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#if !defined(___NFILE_H)
#include <_nfile.h>
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#pragma pack(push, 1)

#endif  /* !RC_INVOKED */


#ifndef __cplusplus
#if !defined(_WCHAR_T) && !defined(_WCHAR_T_DEFINED)
#define _WCHAR_T
#define _WCHAR_T_DEFINED  /* For WINDOWS.H */
typedef unsigned short wchar_t;
#endif
#endif

extern  unsigned    _RTLENTRY _EXPDATA _nfile;

#define HANDLE_MAX   (_NFILE_)
struct  ftime   {
    unsigned    ft_tsec  : 5;   /* Two second interval */
    unsigned    ft_min   : 6;   /* Minutes */
    unsigned    ft_hour  : 5;   /* Hours */
    unsigned    ft_day   : 5;   /* Days */
    unsigned    ft_month : 4;   /* Months */
    unsigned    ft_year  : 7;   /* Year */
};

#define SEEK_CUR    1
#define SEEK_END    2
#define SEEK_SET    0

#ifdef __cplusplus
extern "C" {
#endif
int  _RTLENTRYF _EXPFUNC access  (const char _FAR *path, int amode);
#ifdef __IN_CHMOD
int  _RTLENTRY  _EXPFUNC _rtl_chmod  ();
int  _RTLENTRY  _EXPFUNC _chmod  ();
#else
int  _RTLENTRY  _EXPFUNC _rtl_chmod (const char _FAR *__pathname, int __func, ... );
int  _RTLENTRY  _EXPFUNC _chmod     (const char _FAR *__pathname, int __func, ... );
#endif
int  _RTLENTRY  _EXPFUNC chmod   (const char _FAR *__path, int __amode);
int  _RTLENTRY  _EXPFUNC chsize  (int __handle, long __size);
int  _RTLENTRYF _EXPFUNC _rtl_close  (int __handle);
int  _RTLENTRYF _EXPFUNC _close  (int __handle);
int  _RTLENTRYF _EXPFUNC close   (int __handle);
int  _RTLENTRYF _EXPFUNC _rtl_creat  (const char _FAR *__path, int __attribute);
int  _RTLENTRYF _EXPFUNC _creat  (const char _FAR *__path, int __attribute);
int  _RTLENTRYF _EXPFUNC creat   (const char _FAR *__path, int __amode);
int  _RTLENTRY  _EXPFUNC creatnew(const char _FAR *__path, int __mode); /* DOS 3.0 or later */
int  _RTLENTRY  _EXPFUNC creattemp(char _FAR *__path, int __amode); /* DOS 3.0 or later */
int  _RTLENTRY  _EXPFUNC32 dup   (int __handle);
int  _RTLENTRY  _EXPFUNC32 dup2  (int __oldhandle, int __newhandle);
int  _RTLENTRYF _EXPFUNC eof     (int __handle);
long _RTLENTRYF _EXPFUNC filelength(int __handle);
int  _RTLENTRY  _EXPFUNC32 getftime(int __handle, struct ftime _FAR *__ftimep);

#if defined(__FLAT__)
int  _RTLENTRY _EXPFUNC _waccess   (const wchar_t *__path, int __amode);
int  _RTLENTRY _EXPFUNC _wchmod    (const wchar_t *__path, int __amode);
int  _RTLENTRY _EXPFUNC _wrtl_chmod(const wchar_t *__pathname, int __func, ... );
int  _RTLENTRY _EXPFUNC _wcreat    (const wchar_t *__path, int __amode);
int  _RTLENTRY _EXPFUNC _wrtl_creat(const wchar_t *__path, int __attribute);
int  _RTLENTRY _EXPFUNC _wunlink   (const wchar_t *__path);
int  _RTLENTRY _EXPFUNC _wremove   (const wchar_t * __path);
int  _RTLENTRY _EXPFUNC _wrename   (const wchar_t *__oldname,const wchar_t *__newname);
int  _RTLENTRY _EXPFUNC _wrtl_open (const wchar_t *__path, int __oflags);
wchar_t   * _RTLENTRY  _EXPFUNC     _wmktemp(wchar_t *__template);
#endif

#if defined(__OS2__)
int  _RTLENTRY  _EXPFUNC _truncate(const char *__path, long __size);
int  _RTLENTRYF _EXPFUNC _ftruncate(int __handle, long __size);
#endif  /* __OS2__ */

#if defined(__WIN32__)
long _RTLENTRY  _EXPFUNC _get_osfhandle(int __handle);
int  _RTLENTRY  _EXPFUNC _open_osfhandle(long __osfhandle, int __oflag);
#endif  /* __FLAT__ */

#ifdef __IN_IOCTL
int  _RTLENTRY           ioctl   ();
#else
int  _RTLENTRY  _EXPFUNC ioctl   (int __handle, int __func, ...);
        /* optional 3rd and 4th args are: void _FAR * __argdx, int argcx */
#endif

int  _RTLENTRY  _EXPFUNC32 isatty (int __handle);
int  _RTLENTRY  _EXPFUNC   lock   (int __handle, long __offset, long __length);
int  _RTLENTRY  _EXPFUNC   locking(int __handle, int __mode, long __length);
long _RTLENTRY  _EXPFUNC32 lseek  (int __handle, long __offset, int __fromwhere);
char * _RTLENTRY  _EXPFUNC   _mktemp(char *__template );

#ifdef __IN_OPEN
int  _RTLENTRY  _EXPFUNC   open  ();
#ifdef __FLAT__
int  _RTLENTRY  _EXPFUNC   _wopen  ();
#endif
#else
int  _RTLENTRY  _EXPFUNC   open  (const char _FAR *__path, int __access,... /*unsigned mode*/);
#endif
#ifdef __FLAT__
int  _RTLENTRY  _EXPFUNC   _wopen(const wchar_t *__path, int __access,... /*unsigned mode*/);
#endif
int  _RTLENTRYF _EXPFUNC   _rtl_open (const char _FAR *__path, int __oflags);
int  _RTLENTRYF _EXPFUNC   _open (const char _FAR *__path, int __oflags);
int  _RTLENTRYF _EXPFUNC   read  (int __handle, void _FAR *__buf, unsigned __len);
int  _RTLENTRYF _EXPFUNC32 _rtl_read (int __handle, void _FAR *__buf, unsigned __len);
int  _RTLENTRYF _EXPFUNC32 _read (int __handle, void _FAR *__buf, unsigned __len);
int  _RTLENTRYF _EXPFUNC32 remove(const char _FAR *__path);
int  _RTLENTRYF _EXPFUNC   rename(const char _FAR *__oldname,const char _FAR *__newname);
int  _RTLENTRY  _EXPFUNC32 setftime(int __handle, struct ftime _FAR *__ftimep);
int  _RTLENTRY  _EXPFUNC   setmode(int __handle, int __amode);

#ifdef __IN_SOPEN
int  _RTLENTRY  _EXPFUNC32 _sopen ();
int  _RTLENTRY  _EXPFUNC32 _wsopen ();
#else
int  _RTLENTRY  _EXPFUNC32 _sopen (const char *__path, int __access, int __shflag,
                      ... /* unsigned mode */);
#if defined(__FLAT__)
int  _RTLENTRY  _EXPFUNC32 _wsopen (const wchar_t *__path, int __access, int __shflag,
                      ... /* unsigned mode */);
#endif
#endif
long _RTLENTRY  _EXPFUNC32 tell  (int __handle);
unsigned _RTLENTRY         umask (unsigned __cmask);
int  _RTLENTRYF _EXPFUNC32 unlink(const char _FAR *__path);
int  _RTLENTRY  _EXPFUNC   unlock(int __handle, long __offset, long __length);
int  _RTLENTRYF _EXPFUNC   _rtl_write(int __handle, const void _FAR *__buf, unsigned __len);
int  _RTLENTRYF _EXPFUNC   _write(int __handle, const void _FAR *__buf, unsigned __len);
int  _RTLENTRYF _EXPFUNC   write (int __handle, const void _FAR *__buf, unsigned __len);
#if !defined(__STDC__)
char  * _RTLENTRY _EXPFUNC mktemp( char *__template );
#ifdef __IN_SOPEN
int  _RTLENTRY _EXPFUNC32 sopen ();
#else
int  _RTLENTRY _EXPFUNC32 sopen (const char *__path, int __access, int __shflag,
                      ... /* unsigned mode */);
#endif
#endif

#if !defined(__FLAT__)
 /* Initialization call for Easy Windows */
void _RTLENTRY             _InitEasyWin(void);
#endif

#if defined(__MSC)
#define _lseek(__handle, __offset, __fromwhere) lseek(__handle, __offset, __fromwhere)
#define _dup(h) dup(h)
#endif

#ifdef __cplusplus
}
#endif


#if !defined(RC_INVOKED)

/* Obsolete functions */
#pragma obsolete _chmod
#pragma obsolete _close
#pragma obsolete _creat
#pragma obsolete _open
#pragma obsolete _read
#pragma obsolete _write

/* restore default packing */
#pragma pack(pop)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif  /* __IO_H */

