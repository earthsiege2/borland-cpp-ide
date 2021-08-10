/*----------------------------------------------------------------------*
 * filename - signal.c                                                  *
 *                                                                      *
 * function(s) signal(), raise()                                        *
 * usage                                                                *
 *              Function prototypes are in SIGNAL.H                     *
 *                                                                      *
 *      oldcatcher = signal(sig, newcatcher);                           *
 *              void (*oldcatcher)(int) Ptr to previous signal catcher  *
 *              int  sig                Signal # to install catcher for *
 *      void (*newcatcher)(int) Address of new signal catcher           *
 *                                                                      *
 *      rc = raise(sig);                                                *
 *      int  rc                 Return code, success=0, error=!0        *
 *      int  sig                Signal number to raise                  *
 *----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1991, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#define INCL_CON
#include <ntbc.h>

#include <process.h>    /* _exit() */
#include <errno.h>
#include <float.h>      /* FPE_nn SEGV_nn ILL_nn types */
#include <signal.h>
#include <stdlib.h>
#include <_thread.h>
#include <_process.h>

#undef ANSI_CONFORMING
#define ANSI_CONFORMING

/*----------------------------- NOTE ! ---------------------------------

Normal ANSI operation resets ALL signals,  Microsoft(R) doesn't reset SIGFPE.
Remove ANSI_CONFORMING define for MS style SIGFPE operation.
Default configuration is ANSI conforming SIGFPE operation.

  ----------------------------- NOTE ! -------------------------------*/

typedef void  (_USERENTRY *CatcherPTR)(int);
typedef void  (_USERENTRY *CatcherPTR2)(int,int);

static int GetIndex(int);

extern  ERR  _HandlerPtr;		/* in STARTUP.C */
static  char  HandlerPtrSet=0;

#define BogusSignal     -1		/* Flags a bogus signal type    */

/*+----------------------------------------------------------------------+
  |       Signal Dispatch, Index Generator & Signal Default Tables       |
  | *** Note : Ordering of constants in these tables MUST match          |
  +----------------------------------------------------------------------+*/

#define SIGINT_INDEX    0
#define SIGILL_INDEX    1
#define SIGFPE_INDEX    2
#define SIGSEGV_INDEX   3
#define SIGTERM_INDEX   4
#define SIGUSR1_INDEX   5
#define SIGUSR2_INDEX   6
#define SIGUSR3_INDEX   7
#define SIGBREAK_INDEX  8
#define SIGABRT_INDEX   9
#define SIGMAX_INDEX    10

#ifndef _MT
static CatcherPTR Dispatch[SIGMAX_INDEX] =
{
    SIG_DFL,
    SIG_DFL,
    SIG_DFL,
    SIG_DFL,
    SIG_DFL,
    SIG_DFL,
    SIG_DFL,
    SIG_DFL,
    SIG_DFL,
    SIG_DFL
};
#endif  /* not _MT */

static const int IxGen[SIGMAX_INDEX] =
{
/* NEVER! change the ordering of these */

        SIGINT,
        SIGILL,
        SIGFPE,
        SIGSEGV,
        SIGTERM,
        SIGUSR1,
        SIGUSR2,
        SIGUSR3,
        SIGBREAK,
        SIGABRT
};

/*+----------------------------------------------------------------------+
  |            Table of values for EXPLICITLY raised signals             |
  |  For SIGILL, SIGFPE & SIGSEGV explicit generation may have special   |
  |  meaning to applications.  For the others use dummy 0's.             |
  +----------------------------------------------------------------------+*/

static const UCHAR ExplicitVal[SIGMAX_INDEX] =
{
        0,                      /* SIGINT  */
        ILL_EXPLICITGEN,        /* SIGILL  */
        FPE_EXPLICITGEN,        /* SIGFPE  */
        SEGV_EXPLICITGEN,       /* SIGSEGV */
        0,                      /* SIGTERM */
        0,                      /* SIGUSR1 (OS/2) */
        0,                      /* SIGUSR2 (OS/2) */
        0,                      /* SIGUSR3 (OS/2) */
        0,                      /* SIGBREAK(OS/2) */
        0                       /* SIGABRT */
};


/*+----------------------------------------------------------------------+
  |   GetIndex()  Get a DispatchTable index for specified signal type    |
  +----------------------------------------------------------------------+*/

static int GetIndex(int SigType)
{
    register int i;

    for (i = 0; i < SIGMAX_INDEX; i++)
        if (IxGen[i] == SigType)
            return i;
    return -1;
}

/*---------------------------------------------------------------------*

Name            ExcHandler - Exception handler for signal

Usage           static DWORD __cdecl ExcHandler(
                             PEXCEPTIONREPORTRECORD p,
                             PEXCEPTIONREGISTRATIONRECORD q,
                             PCONTEXTRECORD r,
                             PVOID s);

Description     This function is called indirectly by the RTL's internal
                exception handler.  It translates the NT exception
                number into a signal number, then performs the action
                for that signal, as defined by the current thread.
                If the action is SIG_IGN, the signal is ignored.
                If the action is SIG_DFL, the default action is performed
                (either terminating the current process with exit code 3,
                or ignoring the signal).  Otherwise, the signal-catching
                function associated with the signal is called.

Return value    The function returns XCPT_CONTINUE_SEARCH if the signal
                was not recognized or not handled.  The function
                returns XCPT_CONTINUE_EXECUTION if the signal was
                handled or ignored.

*---------------------------------------------------------------------*/

#pragma warn -par       /* unused parameters */

static DWORD __EHCC ExcHandler(PEXCEPTIONREPORTRECORD p,
                               PEXCEPTIONREGISTRATIONRECORD q,
                               PCONTEXT r,
                               PVOID s)
{
#ifdef _MT
    THREAD_DATA *t;
    CatcherPTR  *Dispatch;
#endif
    CatcherPTR  Action;
    int         Index;
    int         FpeCode;
    DWORD       SwMask;

    /* If there is no thread data structure, or no signal dispatch table
     * has been allocated for this thread, don't handle the exception.
     */
#ifdef _MT
    if ((t = _thread_data()) == NULL || (Dispatch = t->thread_sig) == NULL)
        return (XCPT_CONTINUE_SEARCH);
#endif

    /* Map the NT exception number to a signal dispatch table index.
     * If the signal is one that provides a second argument to the
     * signal argument, put that argument in FpeCode.  If the exception
     * is one that can't be handled by signal(), tell NT that we
     * can't handle it.
     */
    SwMask = 0;
    switch(p->ExceptionNum)
    {
        case XCPT_FLOAT_DIVIDE_BY_ZERO:
            Index = SIGFPE_INDEX;
            FpeCode = FPE_ZERODIVIDE;
            SwMask = SW_ZERODIVIDE;
            break;

        case XCPT_FLOAT_OVERFLOW:
            Index = SIGFPE_INDEX;
            FpeCode = FPE_OVERFLOW;
            SwMask = SW_OVERFLOW;
            break;

        case XCPT_FLOAT_UNDERFLOW:
            Index = SIGFPE_INDEX;
            FpeCode = FPE_UNDERFLOW;
            SwMask = SW_UNDERFLOW;
            break;

        case XCPT_FLOAT_INVALID_OPERATION:
            Index = SIGFPE_INDEX;
            FpeCode = FPE_INVALID;
            SwMask = SW_INVALID;
            break;

        case XCPT_FLOAT_STACK_CHECK:
            Index = SIGFPE_INDEX;
            FpeCode = FPE_STACKFAULT;
            SwMask = SW_INVALID | SW_OVERFLOW | SW_STACKFAULT;
            break;

        case XCPT_INTEGER_DIVIDE_BY_ZERO:
            Index = SIGFPE_INDEX;
            FpeCode = FPE_INTDIV0;
            break;

        case XCPT_ACCESS_VIOLATION:
            Index = SIGSEGV_INDEX;
            FpeCode = SEGV_ACCESS;
            break;

        case XCPT_ILLEGAL_INSTRUCTION:
            Index = SIGILL_INDEX;
            FpeCode = ILL_EXECUTION;
            break;

        case XCPT_PRIVILEGED_INSTRUCTION:
            Index = SIGILL_INDEX;
            FpeCode = ILL_PRIVILEGED;
            break;

        default:
            return (XCPT_CONTINUE_SEARCH);      /* can't handle it ourselves */
    }

    /* If the action for this signal is SIG_IGN, ignore the exception.
     */
    if ((Action = Dispatch[Index]) == SIG_IGN)
        return ((ULONG)XCPT_CONTINUE_EXECUTION);

    /* If the action for this signal is SIG_DFL, let NT handle it.
     * This usually results in a panic screen and program termination.
     */
    if (Action == SIG_DFL)
        return (XCPT_CONTINUE_SEARCH);      /* can't handle it ourselves */

    /* Reset the signal function to SIG_DFL.
     */
#ifdef ANSI_CONFORMING
    Dispatch[Index] = SIG_DFL;              /* Always default (ANSI) */
#else
    if (Index != SIGFPE_INDEX)              /* Maybe default (MS) */
        Dispatch[Index] = SIG_DFL;
#endif

    /* Call the signal handler.
     */
    if (Index == SIGILL_INDEX || Index == SIGSEGV_INDEX ||
        Index == SIGFPE_INDEX)
    {
        /* Clear pending exception then disable precision, denormal, and
	 * underflow floating point exceptions, enable all others.
	 * Then clear all exceptions.  This is necessary because at this point
	 * the OS has masked all exceptions.  If the signal handler longjmps
	 * out and never returns, no more exceptions could be processed.
         */
        _clear87();
        _control87(CW_DEFAULT, MCW_EM | MCW_IC | MCW_RC | MCW_PC);

        (*(CatcherPTR2)Action)(IxGen[Index],FpeCode);   /* call handler */
        r->FloatSave.StatusWord &= ~SwMask;  /* clear exception bit */
    }
    else
        (*Action)(IxGen[Index]);
    return (XCPT_CONTINUE_EXECUTION);
}

/*---------------------------------------------------------------------*

Name            controlc - control-C and control-Break handler

Usage           static DWORD WINAPI controlc(ULONG ctrltype);

Description     This function is called by NT when a control-C or
                control-Break is entered.  It translates the type of
                event into a signal number, then performs the action
                for that signal, as defined by the current thread.
                If the action is SIG_IGN, the signal is ignored.
                If the action is SIG_DFL, the default action is performed
                (either terminating the current process with exit code 3,
                or ignoring the signal).  Otherwise, the signal-catching
                function associated with the signal is called.

Return value    The function returns TRUE, but the NT documents do
                not say what happens if FALSE is returned.  To
                be investigated.

*---------------------------------------------------------------------*/

static BOOL WINAPI controlc(ULONG ctrltype)
{
    raise(ctrltype == CTRL_C_EVENT ? SIGINT : SIGBREAK);
    return (TRUE);
}

#pragma warn .par

/*+----------------------------------------------------------------------+
  |                Signal() - Install new signal catchers                |
  +----------------------------------------------------------------------+*/
/*
void (_USERENTRY * _RTLENTRY signal(sig, New))(int)
int sig;
CatcherPTR New;
*/

CatcherPTR _RTLENTRY _EXPFUNC signal(int sig, CatcherPTR New)
{
    int    Index;
    CatcherPTR      OldVal;
#ifdef _MT
    CatcherPTR      *Dispatch;
    THREAD_DATA     *t;
#endif

    /* Let the startup code know where our exception handler is.
     * Enable receipt of signal-type exceptions.
     */
    if (!HandlerPtrSet)
    {
        _HandlerPtr = ExcHandler;
        SetConsoleCtrlHandler(controlc, TRUE);
        HandlerPtrSet = 1;
    }

    /* Get an index for the signal type, exit if it's bad.
     */
    if ((Index = GetIndex(sig)) == BogusSignal)
    {
        errno = EINVAL;
        return (SIG_ERR);
    }

    /* Get a pointer to the dispatch table for this thread.  If it
     * hasn't been allocated yet, allocate and set it up with default
     * values.
     */
#ifdef _MT
    if ((t = _thread_data()) == NULL)
        return (SIG_ERR);   /* can't set erro, which also needs thread data */
    if ((Dispatch = t->thread_sig) == NULL)
    {
        int i;

        if ((Dispatch = (CatcherPTR *)malloc(sizeof(void *)*SIGMAX_INDEX)) == NULL)
        {
            errno = ENOMEM;
            return (SIG_ERR);
        }
        for (i = 0; i < SIGMAX_INDEX; i++)
            Dispatch[i] = SIG_DFL;
        t->thread_sig = Dispatch;
    }
#endif

    /* Install the handler
     */
    OldVal = Dispatch[Index];       /* Save the OLD handler */
    Dispatch[Index] = New;          /* Set the NEW handler  */

    return (OldVal);
}

/*+----------------------------------------------------------------------+
  |                raise() - generate a software 'event'                 |
  +----------------------------------------------------------------------+*/

int _RTLENTRY _EXPFUNC raise(int SigType)
{
#ifdef _MT
    THREAD_DATA *t;
    CatcherPTR  *Dispatch;
#endif
    CatcherPTR  Action;
    int         FpeCode;
    int         Index;

    /* If there is no thread data structure, or no signal dispatch table
     * has been allocated for this thread, don't handle the exception.
     */
#ifdef _MT
    if ((t = _thread_data()) == NULL || (Dispatch = t->thread_sig) == NULL)
        return (1);
#endif

    if ((Index = GetIndex(SigType)) == BogusSignal)
        return (1);

    if ((Action = Dispatch[Index]) != SIG_IGN)
    {
        if (Action == SIG_DFL)
        {
            switch (SigType)
            {
            case SIGUSR1:
            case SIGUSR2:
            case SIGUSR3:
                break;
            case SIGABRT:
                _abort();
                break;
            default :
                _exit(3);
            }
        }
        else
        {
            /* Call user routine. Add optional parameter
             * specifing that the signal was raised explicitly
             * rather than asynchronously.
             */
#ifdef ANSI_CONFORMING
            Dispatch[Index] = SIG_DFL; /* Always default (ANSI) */
#else
            if (SigType != SIGFPE)     /* Maybe default (MS) */
                Dispatch[Index] = SIG_DFL;
#endif
            if ((FpeCode = ExplicitVal[Index]) != 0)
                (*(CatcherPTR2)Action)(SigType, FpeCode);
            else
                (*Action)(SigType);
        }
    }
    return 0;
}
