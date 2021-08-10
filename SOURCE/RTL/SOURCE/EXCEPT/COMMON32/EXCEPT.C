/*-----------------------------------------------------------------------*
 * filename - except.c
 *
 * function(s)
 *      _setexc         - install RTL exception handler
 *      _unsetexc       - remove RTL exception handler
 *      _SetUserHandler - install user exception handler
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1991, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#ifdef __OS2__
#include <os2bc.h>
#else
#define INCL_USER
#include <ntbc.h>
#endif

#include <_defs.h>
#include <_io.h>

/*----------------------------------------------------------------------
 * _ExcRegPtr contains the address of an exception registration
 * record in the startup code's local stack area.
 */
extern PEXCEPTIONREGISTRATIONRECORD  _ExcRegPtr;

/*----------------------------------------------------------------------
 * The following flag is set to 1 by initstk.c if stack checking
 * is enabled.
 */
int _EXPDATA _stkchk = 0;

/*----------------------------------------------------------------------
 * A pointer to the current exception handler.  If signal() is not
 * used, it points to a handler that always returns XCPT_CONTINUE_SEARCH.
 * If signal() is called, signal() sets it to point to its own exception
 * handler.
 */                             
ERR _HandlerPtr, _UserHandlerPtr;

#define CPP_EXCEPT_CODE 0x0EEFFACE
extern void __call_terminate(void);
extern void __doGlobalUnwind(void);

ULONG __EHCC __DefHandler(PEXCEPTIONREPORTRECORD p,
                          PEXCEPTIONREGISTRATIONRECORD q,
                          PCONTEXTRECORD r,
                          PVOID s);

/*---------------------------------------------------------------------*

Name            ExcHandler - RTL internal exception handler

Usage           static ULONG __EHCC ExcHandler(
                             PEXCEPTIONREPORTRECORD p,
                             PEXCEPTIONREGISTRATIONRECORD q,
                             PCONTEXTRECORD r,
                             PVOID s);

Description     This function is the sole exception handler for the RTL.
                If the exception is not special cased, it calls the
                exception handler pointed to by _UserHandlerPtr.  If
                _UserHandlerPtr cannot handle the exception, the exception
                handler pointed by _HandlerPtr is called.  Normally, both
                _UserHandler and _HandlerPtr point to __DefHandler, the
                default handler.  The user program can modify
                _UserHandlerPtr by calling _SetUserHandler.
                If signal() is used, _HandlerPtr will be modified to
                point to signal()'s own exception handler.

Return value    This function returns the value returned
                by the function pointed to by _UserHandlerPtr or _HandlerPtr
                if either returns XCPT_CONTINUE_EXCECUTION.  Otherwise,
                XCPT_CONTINUE_SEARCH is returned for OS/2 and the value of
                UnhandledExceptionFilter (for Just-in-Time debugging) is
                returned for Win32.

*---------------------------------------------------------------------*/

#pragma warn -cln       /* XCPT_ constants are long */

static ULONG __EHCC ExcHandler(PEXCEPTIONREPORTRECORD p,
                               PEXCEPTIONREGISTRATIONRECORD q,
                               PCONTEXTRECORD r,
                               PVOID s)
{
    if  (p->ExceptionNum == CPP_EXCEPT_CODE)
    {
        _EAX = (unsigned)q;
        _EDX = (unsigned)p;
        __doGlobalUnwind();
        __call_terminate();
    
    }
    
    if (p->ExceptionNum == XCPT_UNABLE_TO_GROW_STACK && _stkchk != 0)
        _ErrorExit("Stack Overflow!");
    
    if (_UserHandlerPtr)
        if ((*_UserHandlerPtr)(p, q, r, s) == XCPT_CONTINUE_EXECUTION)
            return (XCPT_CONTINUE_EXECUTION);
    
    if (_HandlerPtr)
        if ((*_HandlerPtr)(p, q, r, s) == XCPT_CONTINUE_EXECUTION)
            return (XCPT_CONTINUE_EXECUTION);
    
#if defined(__WIN32__)
    {
        EXCEPTION_POINTERS exceptPointers;
            
        exceptPointers.ExceptionRecord = (PEXCEPTION_RECORD)p,
        exceptPointers.ContextRecord   = (PCONTEXT)r;           
        return UnhandledExceptionFilter(&exceptPointers);
    }
#else    
    return (XCPT_CONTINUE_SEARCH);
#endif
}

#pragma warn .cln


/*---------------------------------------------------------------------*

Name            _setexc - install RTL exception handler

Usage           void _setexc(PEXCEPTIONREGISTRATIONRECORD p);

Prototype in    none

Related
functions usage void _unsetexc(PEXCEPTIONREGISTRATIONRECORD p);

Description     This function installs the current thread's exception
                handler.  This must be done before starting the
                thread's main code.  The exception registration
                record is filled in by this function, and must
                be passed to _unsetexc before the thread terminates.
                The record must be located in the caller's local
                stack area, and the caller must be the outermost
                function of the thread; this ensures that the
                record will not disappear while the thread is
                running.

Return value    None.

*---------------------------------------------------------------------*/

void _setexc(PEXCEPTIONREGISTRATIONRECORD p)
{
    p->prev_structure = NULL;
    p->ExceptionHandler = ExcHandler;
    _SetExceptionHandler(p);
}

/*---------------------------------------------------------------------*

Name            _unsetexc - remove RTL exception handler

Usage           void _unsetexc(PEXCEPTIONREGISTRATIONRECORD p);

Prototype in    none

Related
functions usage void _setexc(PEXCEPTIONREGISTRATIONRECORD p);

Description     This function removes the current thread's exception
                handler.  This must be done prior to terminating
                the thread.  The exception registration record must
                have been filled in by an earlier call to _setexc.

Return value    None.

*---------------------------------------------------------------------*/

void _unsetexc(PEXCEPTIONREGISTRATIONRECORD p)
{
    _UnsetExceptionHandler(p);    /* un-set exception handler */
}


/*---------------------------------------------------------------------*

Name            _SetUserHandler - install user exception handler

Usage           void _SetUserHandler(ERR handler);

Prototype in    none

Related
functions usage void _unsetuserhandler(void);

Description     This function installs a user's exception handler.
                It does this by simply setting the global variable
                _UserHandlerPtr to point to the function specified
                by handler.

                When an exception occurs, the RTL's exception
                handler will call the user's handler. If the
                user's handler returns XCPT_CONTINUE_SEARCH,
                the RTL will attempt to handle the exception itself,
                possibly by generating a signal.  Otherwise the RTL
                will assume that the user's handler took care of the
                exception and will perform no other processing.

                This function returns the address of the previous
                exception handler.  If you wish to "chain" exceptions,
                you should save this address.  When your exception
                handler encounters an exception it cannot handle,
                it should call the previous handler and return the
                previous handler's return value.

                If you do not need to chain exceptions, you can ignore
                the return value of _SetUserHandler.  In this case,
                when your exception handler encounters an exception it
                cannot handle, it should return XCPT_CONTINUE_SEARCH.

                There are two ways to remove an exception handler. You
                can call _SetUserHandler with the address of the previous
                handler; this will allow correct exception chaining.
                Or you can call _unsethandler, which will remove
                all exception handlers, thereby "breaking" the chain.

Return value    The address of the previous exception handling function.

*---------------------------------------------------------------------*/

ERR _RTLENTRY _EXPFUNC _SetUserHandler(ERR handler)
{
    ERR oldhandler;

    oldhandler = _UserHandlerPtr;
    _UserHandlerPtr = handler;
    return oldhandler;
}

/*---------------------------------------------------------------------*

Name            _unsetuserhandler - remove user exception handler

Usage           void _unsetuserhandler(void);

Prototype in    none

Related
functions usage void _SetUserHandler(ERR handler);

Description     This function removes a user's exception handler
                that had been previously installed with _SetUserHandler.
                This is done by simply setting the global variable
                _UserHandlerPtr to point to a default exception
                handler that does nothing.

Return value    None.

*---------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC _unsetuserhandler(void)
{
    _UserHandlerPtr = __DefHandler;   /* use default handler again */
}

void _init_except(void)
{
#pragma startup _init_except 0

    _HandlerPtr = __DefHandler;       /* point to default signal handler */
    _UserHandlerPtr = __DefHandler;   /* point to default user handler */
}


void _exit_except(void)
{
#pragma exit _exit_except 0

    if (_ExcRegPtr)
        _unsetexc(_ExcRegPtr);          /* un-set exception handler */
}

/* Called in startup to supply default handler */
void _InitDefaultHander(void)
{
    /* Register the exception handler using an exception registration
     * record that is in the local stack area of the startup code.
     * If a function like signal() were to set up its own exception handler,
     * the record would get corrupted as soon as the function returned,
     * because it would be in a stack frame that was no longer valid.
     */
    if (_ExcRegPtr)
        _setexc(_ExcRegPtr);
}
