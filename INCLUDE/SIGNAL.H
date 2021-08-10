/*  signal.h

    Definitions for ANSI defined signaling capability

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1988, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.5  $ */

#ifndef __SIGNAL_H
#define __SIGNAL_H

#ifndef ___STDDEF_H
#include <_stddef.h>
#endif

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */

/* _SIGCONTEXT contains exception info for WIN32 exceptions that were caught
   and turned into signals.  There will always be three 32-bit parameters
   passed to the user's signal handler.  Unused parameters will be 0.  The
   _PSIGCONTEXT parameter will always be the last (third) parameter.
 */

typedef struct
{
  struct _EXCEPTION_RECORD * _pexecptionrecord; /* defined in WINNT.H */
  struct _CONTEXT *          _pcontext;         /* defined in WINNT.H */
  unsigned long              _result;           /* return value for the SEH */
} _SIGCONTEXT, *_PSIGCONTEXT;

#ifdef __cplusplus
  namespace std {
#endif /* __cplusplus */

typedef int sig_atomic_t;   /* Atomic entity type (ANSI) */

#ifdef __cplusplus
typedef void _USERENTRY (_EXPFUNC * _CatcherPTR)(int);
#else
typedef void _USERENTRY (_EXPFUNC * _CatcherPTR)();
#endif

#define SIG_DFL ((_CatcherPTR)0)   /* Default action   */
#define SIG_IGN ((_CatcherPTR)1)   /* Ignore action    */
#define SIG_ERR ((_CatcherPTR)-1)  /* Error return     */

#define SIGABRT         22
#define SIGFPE           8              /* Floating point trap  */
#define SIGILL           4              /* Illegal instruction  */
#define SIGINT           2
#define SIGSEGV         11              /* Memory access violation */
#define SIGTERM         15
#define SIGUSR1         16              /* User-defined signal 1 */
#define SIGUSR2         17              /* User-defined signal 2 */
#define SIGUSR3         20              /* User-defined signal 3 */
#define SIGBREAK        21              /* Control-Break interrupt */

#ifdef __cplusplus
extern "C" {
#endif
int _RTLENTRY _EXPFUNC raise(int __sig);
#ifdef __cplusplus
void (_USERENTRY * _RTLENTRY _EXPFUNC32 signal(int __sig, void (_USERENTRY * __func)(int))) (int);
}
#else
void (_USERENTRY * _RTLENTRY _EXPFUNC32 signal(int __sig, void (_USERENTRY * __func)())) (int);
#endif

#if !defined(__STDC__)
#define NSIG   23      /* highest defined signal no. + 1 */
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */

#ifdef __cplusplus
} // std
#endif /* __cplusplus */


#endif  /* __SIGNAL_H */

#if defined(__cplusplus) && !defined(__USING_CNAME__) && !defined(__SIGNAL_H_USING_LIST)
#define __SIGNAL_H_USING_LIST
     using std::_CatcherPTR;
     using std::sig_atomic_t;
     using std::raise;
     using std::signal;
#endif /* __USING_CNAME__ */
