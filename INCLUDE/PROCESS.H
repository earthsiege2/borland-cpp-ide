/*  process.h

    Symbols and structures for process management.

*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined(__PROCESS_H)
#define __PROCESS_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */


/*  Modes available as first argument to the spawnxx functions. */

#define P_WAIT    0 /* child runs separately, parent waits until exit */
#define P_NOWAIT  1 /* both concurrent -- not implemented */
#define P_OVERLAY 2 /* child replaces parent, parent no longer exists */

#define P_NOWAITO 3 /* ASYNCH,       toss RC    */
#define P_DETACH  4 /* DETACHED,     toss RC    */

#define WAIT_CHILD       0
#define WAIT_GRANDCHILD      1

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(__FLAT__)
extern  unsigned _Cdecl _psp;    /* provided unconditionally in dos.h */
#define  getpid()   (_psp)

void _Cdecl abort(void);
void _Cdecl _cexit(void);
void _Cdecl _c_exit(void);
void _Cdecl exit(int __status);
void _Cdecl _exit(int __status);

#if defined(__DPMI16__) || !defined(_Windows)

int  _Cdecl execl(char _FAR *__path, char _FAR *__arg0, ...);
int  _Cdecl execle(char _FAR *__path, char _FAR *__arg0, ...);
int  _Cdecl execlp(char _FAR *__path, char _FAR *__arg0, ...);
int  _Cdecl execlpe(char _FAR *__path, char _FAR *__arg0, ...);
int  _Cdecl execv(char _FAR *__path, char _FAR *__argv[]);
int  _Cdecl execve(char _FAR *__path, char _FAR *__argv[], char _FAR *_FAR *__env);
int  _Cdecl execvp(char _FAR *__path, char _FAR *__argv[]);
int  _Cdecl execvpe(char _FAR *__path, char _FAR *__argv[], char _FAR *_FAR *__env);
int  _Cdecl spawnl(int __mode, char _FAR *__path, char _FAR *__arg0, ...);
int  _Cdecl spawnle(int __mode, char _FAR *__path, char _FAR *__arg0, ...);
int  _Cdecl spawnlp(int __mode, char _FAR *__path, char _FAR *__arg0, ...);
int  _Cdecl spawnlpe(int __mode, char _FAR *__path, char _FAR *__arg0, ...);
int  _Cdecl spawnv(int __mode, char _FAR *__path, char _FAR *__argv[]);
int  _Cdecl spawnve(int __mode, char _FAR *__path, char _FAR *__argv[], char _FAR *_FAR *__env);
int  _Cdecl spawnvp(int __mode, char _FAR *__path, char _FAR *__argv[]);
int  _Cdecl spawnvpe(int __mode, char _FAR *__path, char _FAR *__argv[], char _FAR *_FAR *__env);
int  _Cdecl _FARFUNC system(const char _FAR *__command);

#endif /* __DPMI16__ || !_Windows */

#else  /* defined __FLAT__ */

int  _RTLENTRY _EXPFUNC getpid(void);
void _RTLENTRY _EXPFUNC abort(void);
void _RTLENTRY _EXPFUNC _cexit(void);
void _RTLENTRY _EXPFUNC _c_exit(void);
int  _RTLENTRY _EXPFUNC execl(const char * __path, const char * __arg0, ...);
int  _RTLENTRY _EXPFUNC execle(const char * __path, const char * __arg0, ...);
int  _RTLENTRY _EXPFUNC execlp(const char * __path, const char * __arg0, ...);
int  _RTLENTRY _EXPFUNC execlpe(const char * __path, const char * __arg0, ...);
int  _RTLENTRY _EXPFUNC execv(const char * __path, char * const * __argv);
int  _RTLENTRY _EXPFUNC execve(const char * __path, char * const * __argv,
                              char * const * __env);
int  _RTLENTRY _EXPFUNC execvp(const char * __path, char * const * __argv);
int  _RTLENTRY _EXPFUNC execvpe(const char * __path, char * const * __argv,
                                char * const * __env);
void _RTLENTRY _EXPFUNC exit(int __status);
void _RTLENTRY _EXPFUNC _exit(int __status);
int  _RTLENTRY _EXPFUNC spawnl(int __mode, const char * __path, const char * __arg0, ...);
int  _RTLENTRY _EXPFUNC spawnle(int __mode, const char * __path, const char * __arg0, ...);
int  _RTLENTRY _EXPFUNC spawnlp(int __mode, const char * __path, const char * __arg0, ...);
int  _RTLENTRY _EXPFUNC spawnlpe(int __mode, const char * __path, const char * __arg0, ...);
int  _RTLENTRY _EXPFUNC spawnv(int __mode, const char * __path, char * const * __argv);
int  _RTLENTRY _EXPFUNC spawnve(int __mode, const char * __path, char * const * __argv,
                               char * const * __env);
int  _RTLENTRY _EXPFUNC spawnvp(int __mode, const char * __path, char * const * __argv);
int  _RTLENTRY _EXPFUNC spawnvpe(int __mode, const char * __path, char * const * __argv,
                                char * const * __env);
int  _RTLENTRY _EXPFUNC system(const char * __command);

#if defined(__MT__)

#if defined(__OS2__)
int _RTLENTRY _EXPFUNC _beginthread(void (_USERENTRY *__start)(void *),
                                    unsigned __stksize, void *__arg);
#endif  /* __OS2__ */

#if defined(__WIN32__)
unsigned long _RTLENTRY _EXPFUNC _beginthread  (void (_USERENTRY *__start)(void *),
                                                unsigned __stksize, void *__arg);
unsigned long _RTLENTRY _EXPFUNC _beginthreadNT(void (_USERENTRY *__start)(void *),
                                                unsigned __stksize, void *__arg,
                                                void *__security_attr,
                                                unsigned long __create_flags,
                                                unsigned long *__thread_id);

#endif  /* __WIN32__ */

void _RTLENTRY _EXPFUNC _endthread     (void);

#if defined(__MFC_COMPAT__)
inline unsigned long _RTLENTRY _beginthreadex
(
    void *security,
    unsigned stksize,
    unsigned (__stdcall *start_address)(void *),
    void *arglist,
    unsigned initflag,
    unsigned *threadaddr
)
{
    return _beginthreadNT((void(_USERENTRY *)(void *))start_address, stksize,
                          arglist, security, (unsigned long)initflag,
                          (unsigned long *)threadaddr);
}
#pragma argsused
inline void _RTLENTRY _endthreadex(unsigned retval)
{
    _endthread();
}
#endif  /* __MFC_COMPAT__ */


#endif  /* __MT__ */

#if defined(__OS2__) || defined(__WIN32__)
int  _RTLENTRY _EXPFUNC cwait          (int *__term_stat, int __pid, int __action);
int  _RTLENTRY _EXPFUNC wait           (int *__term_stat);
#endif  /* __OS2__ || __WIN32__ */

#endif  /* __FLAT__ */

#ifdef __cplusplus
}
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif  /* __PROCESS_H */

