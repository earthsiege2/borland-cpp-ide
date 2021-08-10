/*  dir.h

    Defines structures, macros, and functions for dealing with
    directories and pathnames.

*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.11  $ */

#if !defined(__DIR_H)
#define __DIR_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#if !defined(___TCHAR_H)
#include <tchar.h>
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */


#ifndef __cplusplus
#if !defined(_WCHAR_T) && !defined(_WCHAR_T_DEFINED)
#define _WCHAR_T
#define _WCHAR_T_DEFINED  /* For WINDOWS.H */
typedef unsigned short wchar_t;
#endif
#endif

#define WILDCARDS 0x01
#define EXTENSION 0x02
#define FILENAME  0x04
#define DIRECTORY 0x08
#define DRIVE     0x10

#define MAXDRIVE  3

#if !defined(__FLAT__)

#ifndef _FFBLK_DEF
#define _FFBLK_DEF
struct  ffblk   {
    char        ff_reserved[21];
    char        ff_attrib;
    unsigned    ff_ftime;
    unsigned    ff_fdate;
    long        ff_fsize;
    char        ff_name[13];
};
#endif

#define MAXPATH   80
#define MAXDIR    66
#define MAXFILE   9
#define MAXEXT    5

#else  /* defined __FLAT__ */

#if !defined(RC_INVOKED)
#pragma pack(push, 1)
#endif

#ifndef _FFBLK_DEF
#define _FFBLK_DEF
struct  ffblk   {
    long            ff_reserved;
    long            ff_fsize;
    unsigned long   ff_attrib;
    unsigned short  ff_ftime;
    unsigned short  ff_fdate;
    char            ff_name[256];
};
struct  _wffblk   {
    long            ff_reserved;
    long            ff_fsize;
    unsigned long   ff_attrib;
    unsigned short  ff_ftime;
    unsigned short  ff_fdate;
    wchar_t         ff_name[256];
};
#endif

#define MAXPATH   260
#define MAXDIR    256
#define MAXFILE   256
#define MAXEXT    256

#if !defined(RC_INVOKED)
#pragma pack(pop)       /* restore default packing */
#endif

#endif  /* __FLAT__  */

#ifdef __cplusplus
extern "C" {
#endif

int         _RTLENTRYF _EXPFUNC32   chdir( const char _FAR *__path );
int         _RTLENTRYF _EXPFUNC     findfirst( const char _FAR *__path,
                                    struct ffblk _FAR *__ffblk,
                                    int __attrib );
int         _RTLENTRYF _EXPFUNC     findnext( struct ffblk _FAR *__ffblk );

void        _RTLENTRYF _EXPFUNC     fnmerge( char _FAR *__path,
                                    const char _FAR *__drive,
                                    const char _FAR *__dir,
                                    const char _FAR *__name,
                                    const char _FAR *__ext );
int         _RTLENTRYF _EXPFUNC     fnsplit(const char _FAR *__path,
                                    char _FAR *__drive,
                                    char _FAR *__dir,
                                    char _FAR *__name,
                                    char _FAR *__ext );
int         _RTLENTRY  _EXPFUNC32   getcurdir( int __drive, char _FAR *__directory );
char _FAR * _RTLENTRY  _EXPFUNC     getcwd( char _FAR *__buf, int __buflen );
int         _RTLENTRY  _EXPFUNC32   getdisk( void );
int         _RTLENTRY  _EXPFUNC32   _mkdir( const char *__path );
char      * _RTLENTRY  _EXPFUNC     _mktemp( char *__template );
int         _RTLENTRY  _EXPFUNC32   _rmdir( const char _FAR *__path );
char _FAR * _RTLENTRYF _EXPFUNC32   searchpath( const char _FAR *__file );
int         _RTLENTRY  _EXPFUNC32   setdisk( int __drive );

#if !defined(__STDC__)
int    _RTLENTRY _EXPFUNC32 mkdir( const char *__path );
char * _RTLENTRY _EXPFUNC   mktemp( char *__template );
int    _RTLENTRY _EXPFUNC32 rmdir( const char *__path );
#endif

#ifdef __FLAT__
int         _RTLENTRY  _EXPFUNC32   _wchdir( const wchar_t *__path );
int         _RTLENTRY  _EXPFUNC32   _wmkdir( const wchar_t *__path );
int         _RTLENTRY  _EXPFUNC32   _wrmdir( const wchar_t *__path );
wchar_t   * _RTLENTRY  _EXPFUNC32   wsearchpath( const wchar_t *__file );
wchar_t   * _RTLENTRY  _EXPFUNC     _wmktemp( wchar_t *__template );
int         _RTLENTRY  _EXPFUNC     _wfindfirst( const wchar_t *__path,
                                    struct _wffblk *__ffblk,
                                    int __attrib );
int         _RTLENTRY  _EXPFUNC     _wfindnext( struct _wffblk *__ffblk );
int         _RTLENTRY  _EXPFUNC     _wfnsplit(const wchar_t *__path,
                                    wchar_t *__drive,
                                    wchar_t *__dir,
                                    wchar_t *__name,
                                    wchar_t *__ext );
void        _RTLENTRY  _EXPFUNC     _wfnmerge( wchar_t *__path,
                                    const wchar_t *__drive,
                                    const wchar_t *__dir,
                                    const wchar_t *__name,
                                    const wchar_t *__ext );
wchar_t   * _RTLENTRY  _EXPFUNC     _wgetcwd( wchar_t *__buf, int __buflen );
int         _RTLENTRY  _EXPFUNC     _wgetcurdir( int __drive, wchar_t *__directory );
#endif

#ifdef __cplusplus
}
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif  /* __DIR_H */


