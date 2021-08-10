/*------------------------------------------------------------------------
 * filename - _process.h
 *
 *      definitions of internal routines for exec* and spawn*
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern  void    (*_exitbuf)(void);
extern  void    (*_exitfopen)(void);
extern  void    (*_exitopen)(void);

int _RTLENTRY _getpid     (void);

#ifdef _MT
void       _lock_env   (void);
void       _unlock_env (void);
#else
#define    _lock_env()
#define    _unlock_env()
#endif

#ifdef __WIN32__
int        _setenv     (const char *__string);
#endif

#ifdef __OS2__
int        _noinherit  (int __handle);
#endif

int        _LoadProg   (int __mode, const char *__path, const char * const * __argp,
                        const char * const * __envV, int __usepath);

int _RTLENTRY _cwait   (int *__term_stat, int __pid, int __action);

void       _abort      (void);

#ifdef __cplusplus
}
#endif
