/*------------------------------------------------------------------------
 * filename - _thread.h
 *
 * Definitions for semaphore locking functions and other thread-related
 * functions.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $ */

#if !defined(__OS2__) && !defined(__WIN32__)
#error Locks and threads can only be used on OS/2 and NT
#endif

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#if defined(__WIN32__)
#include <ntbc.h>
#endif

#if !defined(_SEED_T)
#define _SEED_T
typedef struct
{
	unsigned lo;
	unsigned hi;
} __seed_t;
#endif

/* Thread Data structure used to hold "static" data for each thread.
 */
typedef struct _thread_data
{
#ifdef __WIN32__
    struct _thread_data *thread_link; /* next struct on free list */
    void    *thread_arglist;        /* argument list to pass to thread_func */
    HANDLE  thread_handle;          /* handle of thread object */
#endif
    int     thread_errno;           /* errno */
    int     thread_doserrno;        /* _doserrno */
    void    (_USERENTRY *thread_func)(void *); /* thread starting address */
    char    *thread_token;          /* pointer to next strtok() token */
    char    *thread_template;       /* pointer to temp filename template */
    int     thread_mbshift;         /* shift state for mbtowc() */
    int     thread_wcshift;         /* shift state for wctomb() */
    void    (_USERENTRY **thread_sig)();/* pointer to signal table */
    void    *thread_excep;          /* exception registration pointer */
    void    *thread_time;           /* data used by time functions */
    void    *thread_cvt;            /* array used by fcvt() and ecvt() */
    void    *thread_strbuf;         /* array used by strerror() */
    void    *thread_passbuf;        /* array used by getpass() */
    void    *thread_pathbuf;        /* array used by searchpath() */
    __seed_t   thread_seed;         /* random number seed */
#ifdef __WIN32__
    void    *thread_exceptvars;
#endif
#if defined(_MBCS)
    int     thread_lead_byte;       /* pending leadbyte data used by putch() */
#endif
} THREAD_DATA;

/* On OS/2, a lock_t is the same as an HMTX. On WIN32, it is a pointer
 * to a CRITICAL_SECTION structure.
 */
typedef unsigned long lock_t;

#ifdef _MT

#ifdef __cplusplus
extern "C" {
#endif

void            _create_lock        (lock_t *__lockp, char *__mesg);
void            _lock_error         (char *__mesg);

#ifdef __OS2__
void            _lock               (lock_t __lock, char *__mesg);
void            _unlock             (lock_t __lock, char *__mesg);
#endif  /* __OS2__ */

#ifdef __WIN32__
void            _lock_nt            (lock_t __lock);
void            _unlock_nt          (lock_t __lock);
#define _lock(lock, mesg)           _lock_nt(lock)
#define _unlock(lock,mesg)          _unlock_nt(lock)

#endif  /* __WIN32__ */

void *          _thread_buf         (int offset, int size);

THREAD_DATA *   _thread_data        (void);
#ifdef __OS2__
THREAD_DATA *   _thread_data_tid    (int __tid);
#endif
#ifdef __WIN32__
THREAD_DATA *   _thread_data_new    (void);
void            _thread_data_del    (THREAD_DATA *);
#endif

#define THREAD_BUF(member,size) _thread_buf((int)&(((THREAD_DATA *)0)->thread_##member),size)

#ifdef __cplusplus
}
#endif

#else   /* not _MT */

#define _create_lock(lockp, mesg)
#define _lock(lock, mesg)
#define _unlock(lock,mesg)
#define _lock_error(mesg)

#endif  /* _MT */
