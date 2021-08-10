/*  process.h

    Symbols and structures for process management.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.8  $ */

#if !defined(__PROCESS_H)
#define __PROCESS_H

#ifndef ___STDDEF_H
#include <_stddef.h>
#endif

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */

#ifdef __cplusplus
namespace std {
#endif /* __cplusplus */

/*  Modes available as first argument to the spawnxx functions. */
#define P_WAIT           0  /* child runs separately, parent waits until exit */
#define P_NOWAIT         1  /* both child & parent run concurrently */
#define P_OVERLAY        2  /* child replaces parent, parent no longer exists */
#define P_NOWAITO        3  /* ASYNCH,       toss RC    */
#define P_DETACH         4  /* DETACHED,     toss RC    */

/* MSC versions of the spawnxx modes */
#define _P_WAIT          0
#define _P_NOWAIT        1
#define _P_OVERLAY       2
#define _P_NOWAITO       3
/*      _P_DETACH           // This one conflicts with the Flag version below */

/* Flags that can be or'ed into the base spawnxx mode parameter */
#define _P_MASK         (0x07)  /* used to mask off the P_xxx values */

#define _P_DETACH       (0x0010) /* Run child as a detached process (or'able version of P_DETACH) */
#define _P_NEWCONSOLE   (0x0020) /* Run child in a new console window */
#define _P_NEWPROCGROUP (0x0040) /* Child is the root of a new Process Group */
#define _P_SUSPENDED    (0x0080) /* Child's main thread is created suspended */
#define _P_NOCLOSE      (0x0100) /* Prevents the child's hProcess or hThread from being closed */
#define _P_NEWWIN16     (0x0200) /* Run Win16 apps in a private WOW VDM */
#define _P_SHAREDWIN16  (0x0400) /* Run all Win16 apps the same WOW VDM */
#define _P_DEFERRORMODE (0x0800) /* Child does not inherit error mode of parent */
#define _P_PRIO_IDLE    (0x1000) /* Run in IDLE priority class */
#define _P_PRIO_NORM    (0x2000) /* Run in NORMAL priority class */
#define _P_PRIO_HIGH    (0x4000) /* Run in HIGH priority class */
#define _P_PRIO_REAL    (0x8000) /* Run in REALTIME priority class */

#define WAIT_CHILD      (0)
#define WAIT_GRANDCHILD (1)

#ifdef __cplusplus
extern "C" {
#endif

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


int  _RTLENTRY _EXPFUNC _wexecl(const wchar_t * __path, const wchar_t * __arg0, ...);
int  _RTLENTRY _EXPFUNC _wexecle(const wchar_t * __path, const wchar_t * __arg0, ...);
int  _RTLENTRY _EXPFUNC _wexeclp(const wchar_t * __path, const wchar_t * __arg0, ...);
int  _RTLENTRY _EXPFUNC _wexeclpe(const wchar_t * __path, const wchar_t * __arg0, ...);
int  _RTLENTRY _EXPFUNC _wexecv(const wchar_t * __path, wchar_t * const * __argv);
int  _RTLENTRY _EXPFUNC _wexecve(const wchar_t * __path, wchar_t * const * __argv,
                              wchar_t * const * __env);
int  _RTLENTRY _EXPFUNC _wexecvp(const wchar_t * __path, wchar_t * const * __argv);
int  _RTLENTRY _EXPFUNC _wexecvpe(const wchar_t * __path, wchar_t * const * __argv,
                                wchar_t * const * __env);
int  _RTLENTRY _EXPFUNC _wspawnl(int __mode, const wchar_t * __path, const wchar_t * __arg0, ...);
int  _RTLENTRY _EXPFUNC _wspawnle(int __mode, const wchar_t * __path, const wchar_t * __arg0, ...);
int  _RTLENTRY _EXPFUNC _wspawnlp(int __mode, const wchar_t * __path, const wchar_t * __arg0, ...);
int  _RTLENTRY _EXPFUNC _wspawnlpe(int __mode, const wchar_t * __path, const wchar_t * __arg0, ...);
int  _RTLENTRY _EXPFUNC _wspawnv(int __mode, const wchar_t * __path, wchar_t * const * __argv);
int  _RTLENTRY _EXPFUNC _wspawnve(int __mode, const wchar_t * __path, wchar_t * const * __argv,
                               wchar_t * const * __env);
int  _RTLENTRY _EXPFUNC _wspawnvp(int __mode, const wchar_t * __path, wchar_t * const * __argv);
int  _RTLENTRY _EXPFUNC _wspawnvpe(int __mode, const wchar_t * __path, wchar_t * const * __argv,
                                wchar_t * const * __env);
int  _RTLENTRY _EXPFUNC _wsystem(const wchar_t * __command);


#if defined(__MT__)

struct _thread_adoption_data_s { char __dummy; };
typedef struct _thread_adoption_data_s* _PTHREAD_ADOPTION_DATA;

void                    _RTLENTRY _EXPFUNC     _unadopt_thread(_PTHREAD_ADOPTION_DATA __thd);
_PTHREAD_ADOPTION_DATA  _RTLENTRY _EXPFUNC     _adopt_thread(void (_USERENTRY *__start_address)(void *),
                                                             void *__arglist,
                                                              int __free_flag);

unsigned long _RTLENTRY _EXPFUNC _beginthread  (void (_USERENTRY *__start)(void *),
                                                unsigned __stksize, void *__arg);
unsigned long _RTLENTRY _EXPFUNC _beginthreadNT(void (_USERENTRY *__start)(void *),
                                                unsigned __stksize, void *__arg,
                                                void *__security_attr,
                                                unsigned long __create_flags,
                                                unsigned long *__thread_id);

unsigned long _RTLENTRY _EXPFUNC _beginthreadex(void *__security_attr,
                                                unsigned __stksize,
                                                unsigned (__stdcall *__start)(void *),
                                                void *__arg,
                                                unsigned __create_flags,
                                                unsigned *__thread_id);

void          _RTLENTRY _EXPFUNC _endthread    (void);
void          _RTLENTRY _EXPFUNC _endthreadex  (unsigned __thread_retval);

#endif  /* __MT__ */

int  _RTLENTRY _EXPFUNC cwait          (int *__term_stat, int __pid, int __action);
int  _RTLENTRY _EXPFUNC wait           (int *__term_stat);

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

#endif  /* __PROCESS_H */

#if defined(__cplusplus) && !defined(__USING_CNAME__) && !defined(__PROCESS_H_USING_LIST)
#define __PROCESS_H_USING_LIST
    using std::getpid;
    using std::abort;
    using std::_cexit;
    using std::_c_exit;
    using std::execl;
    using std::execle;
    using std::execlp;
    using std::execlpe;
    using std::execv;
    using std::execve;
    using std::execvp;
    using std::execvpe;
    using std::exit;
    using std::_exit;
    using std::spawnl;
    using std::spawnle;
    using std::spawnlp;
    using std::spawnlpe;
    using std::spawnv;
    using std::spawnve;
    using std::spawnvp;
    using std::spawnvpe;
    using std::system;
    using std::_wexecl;
    using std::_wexecle;
    using std::_wexeclp;
    using std::_wexeclpe;
    using std::_wexecv;
    using std::_wexecve;
    using std::_wexecvp;
    using std::_wexecvpe;
    using std::_wspawnl;
    using std::_wspawnle;
    using std::_wspawnlp;
    using std::_wspawnlpe;
    using std::_wspawnv;
    using std::_wspawnve;
    using std::_wspawnvp;
    using std::_wspawnvpe;
    using std::_wsystem;
#if defined(__MT__)
    using std::_PTHREAD_ADOPTION_DATA;
    using std::_adopt_thread;
    using std::_unadopt_thread;
    using std::_beginthread;
    using std::_beginthreadNT;
    using std::_beginthreadex;
    using std::_endthread;
    using std::_endthreadex;
#endif // __MT__
    using std::cwait;
    using std::wait;
#endif /* __USING_CNAME__ */


