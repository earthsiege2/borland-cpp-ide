/*------------------------------------------------------------------------
 * filename - _process.h
 *
 *      definitions of internal routines for exec* and spawn*
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $ */

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#if !defined( __TCHAR_H )
#include <_tchar.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern  void    (*_exitbuf)(void);
extern  void    (*_exitfopen)(void);
extern  void    (*_exitopen)(void);

int _RTLENTRY _getpid     (void);

#ifdef _MT
#ifndef _UNICODE
void       _lock_env   (void);
void       _unlock_env (void);
#else
void       _wlock_env   (void);
void       _wunlock_env (void);
#endif
#else
#ifndef _UNICODE
#define    _lock_env()
#define    _unlock_env()
#else
#define    _wlock_env()
#define    _wunlock_env()
#endif
#endif

#ifndef _UNICODE
int        _setenv     (const char *__string);
int        _LoadProg   (int __mode, const char *__path, const char * const * __argp,
                        const char * const * __envV, int __usepath);
#else
int        _wsetenv    (const wchar_t *__string);
int        _wLoadProg  (int __mode, const wchar_t *__path, const wchar_t * const * __argp,
                        const wchar_t * const * __envV, int __usepath);
#endif

#ifdef __OS2__
int        _noinherit  (int __handle);
#endif


int _RTLENTRY _cwait   (int *__term_stat, int __pid, int __action);

void       _abort      (void);

#ifdef __cplusplus
}
#endif
