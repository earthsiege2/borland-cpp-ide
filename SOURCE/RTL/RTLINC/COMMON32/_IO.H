/*------------------------------------------------------------------------
 * filename - _io.h
 *
 *  Definitions for low level I/O functions.
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

void _ErrorMessage(const char *__message);
void _ErrorExit   (const char *__message);
int  __IOerror    (int  __doserror);   /* returns -1 */

#ifdef __WIN32__
int  __NTerror     (void);              /* returns -1 */
int  __DOSerror    (void);              /* returns _doserrno */
#else
int  __DOSerror    (int  __doserror);   /* returns _doserrno */
#endif

/* ANSI-safe entry points for low-level I/O functions.
 */
int      _RTLENTRY  __access (const char *__path, int __amode);
int      _RTLENTRYF __close  (int __handle);
int      _RTLENTRY  __dup    (int __handle);
int      _RTLENTRY  __dup2   (int __oldhandle, int __newhandle);
int      _RTLENTRY  __eof    (int __handle);
int      _RTLENTRY  __ftruncate(int __handle, long __size);
int      _RTLENTRY  __isatty (int __handle);
long     _RTLENTRYF __lseek  (int __handle, long __offset, int __fromwhere);
int      __cdecl    __open   (const char *__path, int __access,... /*unsigned mode*/);
int      _RTLENTRYF __read   (int __handle, void *__buf, unsigned __len);
int      _RTLENTRYF __unlink (const char *__path);
unsigned _RTLENTRY  _umask   (unsigned __cmask);
int      _RTLENTRYF __write  (int __handle, void *__buf, unsigned __len);

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
#ifdef __WIN32__
int  _dup_handle  (int oldfd, int newfd, long handle);
void _free_handle (int fd);
int  _get_handle  (long handle, int oflag);
#endif

/* Functions and variables for handling _C_FILE_INFO environment variable.
 */
extern int  (*_cfinfo_get)(char *); /* function to get file info */
extern char  *_cfinfo_value;        /* value of _C_FILE_INFO env. variable */
#ifdef __OS2__
extern char   _cfinfo_name[];       /* name of env. variable */
#endif
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
#ifdef __WIN32__
extern long _RTLENTRY          _handles[];
#endif

/* Array of process IDs for _popen/_pclose.
 */
extern unsigned int _RTLENTRY  _pidtab[];

/* Pointer to EXE's _fmode variable.
 */
extern int *_fmodeptr;
#define _FMODE (*_fmodeptr)

/* Standard "one entry, one exit" macro for serialization exits.
 */
#define RETURN(code)    {rc=(code); goto exit;}
