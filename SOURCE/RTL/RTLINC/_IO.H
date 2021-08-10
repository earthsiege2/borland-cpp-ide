/*------------------------------------------------------------------------
 * filename - _io.h
 *
 *  Definitions for low level I/O functions.
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.3  $ */

#if !defined(__STDDEF_H)
#include <stddef.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

void _ErrorMessage(const char *__message);
void _ErrorExit   (const char *__message);
int  __IOerror    (int  __doserror);   /* returns -1 */

int  __NTerror     (void);              /* returns -1 */
int  __DOSerror    (void);              /* returns _doserrno */

/* ANSI-safe entry points for low-level I/O functions.
 */
int      _RTLENTRY  __access (const char *__path, int __amode);
int      _RTLENTRYF __close  (int __handle);
int      _RTLENTRY  __dup    (int __handle);
int      _RTLENTRY  __dup2   (int __oldhandle, int __newhandle);
int      _RTLENTRY  __eof    (int __handle);
int      _RTLENTRY  __ftruncate(int __handle, long __size);
int      _RTLENTRY  __isatty (int __handle);
int      _RTLENTRY  __isatty_osfhandle(long __handle);
long     _RTLENTRYF __lseek  (int __handle, long __offset, int __fromwhere);
int      __cdecl    __open   (const char *__path, int __access,... /*unsigned mode*/);
int      _RTLENTRYF __read   (int __handle, void *__buf, unsigned __len);
int      _RTLENTRYF __unlink (const char *__path);
unsigned _RTLENTRY  _umask   (unsigned __cmask);
int      _RTLENTRYF __write  (int __handle, void *__buf, unsigned __len);
unsigned _RTLENTRY  _DosCreate(char *pathP, unsigned attr, int *handlep,
                               unsigned disp);

int      __cdecl    ___wopen (const wchar_t *__path, int __access,... /*unsigned mode*/);
int      _RTLENTRYF __wread  (int __handle, void *__buf, unsigned __len);
int      _RTLENTRYF _wunlink (const wchar_t *__path);
unsigned _RTLENTRY  _wDosCreate(wchar_t *pathP, unsigned attr, int *handlep,
                               unsigned disp);

/* Functions for locking and unlocking file handles.
 */
#ifdef _MT
void _lock_all_handles   (void);
void _unlock_all_handles (void);
void _lock_handle        (int __handle);
void _unlock_handle      (int __handle);
#else
#define _lock_all_handles()
#define _unlock_all_handles()
#define _lock_handle(handle)
#define _unlock_handle(handle)
#endif

/* Functions for allocated and freeing file handle table slots.
 */
int  _dup_handle  (int oldfd, int newfd, long handle);
void _free_handle (int fd);
int  _get_handle  (long handle, int oflag);

/* Functions and variables for handling _C_FILE_INFO env. variable
 */
extern int  (*_cfinfo_get)(char *); /* function to get file info */
extern char  *_cfinfo_value;        /* value of _C_FILE_INFO env. variable */
extern int _RTLENTRY _EXPDATA _fileinfo; /* true if file info passed to children */

#ifdef __cplusplus
}
#endif

extern unsigned _RTLENTRY _EXPDATA _nfile;

/* Array of open file flags.
 */
extern unsigned int _RTLENTRY  _openfd[];

/* Array of open file handles (not used on OS/2).
 */
extern long _RTLENTRY          _handles[];

/* Array of process IDs for _popen/_pclose.
 */
extern unsigned int _RTLENTRY  _pidtab[];

/* Pointer to EXE's _fmode variable.
 */
extern int *_fmodeptr;
#define _FMODE (*_fmodeptr)

/* Standard "one entry, one exit" macro for serialization of exits.
 */
#define RETURN(code)    {rc=(code); goto exit;}

#define O_PSEUDO 0x10000
