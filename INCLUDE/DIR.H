/*  dir.h

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

/* $Revision:   9.8  $ */

#if !defined(__DIR_H)
#define __DIR_H

#ifndef ___STDDEF_H
#include <_stddef.h>
#endif

#if !defined(___TCHAR_H)
#include <tchar.h>
#endif

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */

#ifdef __cplusplus
namespace std {
#endif /* __cplusplus */

#define WILDCARDS 0x01
#define EXTENSION 0x02
#define FILENAME  0x04
#define DIRECTORY 0x08
#define DRIVE     0x10


#if !defined(RC_INVOKED)
#pragma pack(push, 1)
#endif

#ifndef MAXPATH
#define MAXPATH   260
#define MAXDIR    256
#define MAXFILE   256
#define MAXEXT    256
#define MAXDRIVE    3
#endif

#ifndef _FFBLK_DEF
#define _FFBLK_DEF
struct  ffblk   {
    long            ff_reserved;
    long            ff_fsize;
    unsigned long   ff_attrib;
    unsigned short  ff_ftime;
    unsigned short  ff_fdate;
    char            ff_name[MAXPATH];
};
struct  _wffblk   {
    long            ff_reserved;
    long            ff_fsize;
    unsigned long   ff_attrib;
    unsigned short  ff_ftime;
    unsigned short  ff_fdate;
    wchar_t         ff_name[MAXPATH];
};
#endif

#ifndef FA_NORMAL
#define FA_NORMAL   0x00        /* Normal file, no attributes */
#define FA_RDONLY   0x01        /* Read only attribute */
#define FA_HIDDEN   0x02        /* Hidden file */
#define FA_SYSTEM   0x04        /* System file */
#define FA_LABEL    0x08        /* Volume label */
#define FA_DIREC    0x10        /* Directory */
#define FA_ARCH     0x20        /* Archive */
#endif /* FA_NORMAL */

#ifndef _A_NORMAL
/* MSC names for file attributes */
#define _A_NORMAL   0x00        /* Normal file, no attributes */
#define _A_RDONLY   0x01        /* Read only attribute */
#define _A_HIDDEN   0x02        /* Hidden file */
#define _A_SYSTEM   0x04        /* System file */
#define _A_VOLID    0x08        /* Volume label */
#define _A_SUBDIR   0x10        /* Directory */
#define _A_ARCH     0x20        /* Archive */
#endif /* _A_NORMAL */

#define _getcwd(a,b)            getcwd(a,b)

#if !defined(RC_INVOKED)
#pragma pack(pop)       /* restore default packing */
#endif

#ifdef __cplusplus
extern "C" {
#endif

int         _RTLENTRYF _EXPFUNC32   chdir( const char _FAR *__path );
int         _RTLENTRYF _EXPFUNC     findfirst( const char _FAR *__path,
                                    struct ffblk _FAR *__ffblk,
                                    int __attrib );
int         _RTLENTRYF _EXPFUNC     findnext( struct ffblk _FAR *__ffblk );
int         _RTLENTRYF _EXPFUNC     findclose( struct ffblk _FAR *__ffblk );

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

int         _RTLENTRY  _EXPFUNC32   _wchdir( const wchar_t *__path );
int         _RTLENTRY  _EXPFUNC32   _wmkdir( const wchar_t *__path );
int         _RTLENTRY  _EXPFUNC32   _wrmdir( const wchar_t *__path );
wchar_t   * _RTLENTRY  _EXPFUNC32   wsearchpath( const wchar_t *__file );
wchar_t   * _RTLENTRY  _EXPFUNC     _wmktemp( wchar_t *__template );
int         _RTLENTRY  _EXPFUNC     _wfindfirst( const wchar_t *__path,
                                    struct _wffblk *__ffblk,
                                    int __attrib );
int         _RTLENTRY  _EXPFUNC     _wfindnext( struct _wffblk *__ffblk );
int         _RTLENTRY  _EXPFUNC     _wfindclose( struct _wffblk *__ffblk );
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

#ifdef __cplusplus
}
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */

#ifdef __cplusplus
} // std
#endif /* __cplusplus */

#endif  /* __DIR_H */

#if defined(__cplusplus) && !defined(__USING_CNAME__) && !defined(__DIR_H_USING_LIST)
#define __DIR_H_USING_LIST
    using std::ffblk;
    using std::_wffblk;
    using std::chdir;
    using std::findfirst;
    using std::findnext;
    using std::findclose;
    using std::fnmerge;
    using std::fnsplit;
    using std::getcurdir;
    using std::getcwd;
    using std::getdisk;
    using std::_mkdir;
    using std::_mktemp;
    using std::_rmdir;
    using std::searchpath;
    using std::setdisk;
#if !defined(__STDC__)
    using std::mkdir;
    using std::mktemp;
    using std::rmdir;
#endif
    using std::_wchdir;
    using std::_wmkdir;
    using std::_wrmdir;
    using std::wsearchpath;
    using std::_wmktemp;
    using std::_wfindfirst;
    using std::_wfindnext;
    using std::_wfindclose;
    using std::_wfnsplit;
    using std::_wfnmerge;
    using std::_wgetcwd;
    using std::_wgetcurdir;
#endif /* __USING_CNAME__ */

