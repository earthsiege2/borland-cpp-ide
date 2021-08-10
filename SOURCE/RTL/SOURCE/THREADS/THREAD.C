/*-----------------------------------------------------------------------*
 * filename - thread.c
 *
 * function(s)
 *
 *      _adopt_thread   - Hooks our RTL 'stuff' up to a CreatThread thread
 *      _unadopt_thread - Releases that RTL 'stuff'
 *      _beginthread    - create and start a thread
 *      _beginthreadNT  - create and start a thread
 *      _beginthreadex  - create and start a thread
 *      _endthread      - terminate a thread
 *      _endthreadex    - terminate a thread
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1991, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.5  $        */

#define INCL_ERROR_H
#include <ntbc.h>

#include <stdlib.h>
#include <errno.h>
#include <_io.h>
#include <_thread.h>
#include <string.h>
#include <process.h>

extern DWORD __thread _tlsindex;                        /* in tls.c */
extern DWORD __thread _stkindex;                        /* in tls.c */

extern void _setexc(PEXCEPTIONREGISTRATIONRECORD p);    /* in startup.c */
extern void _unsetexc(PEXCEPTIONREGISTRATIONRECORD p);  /* in startup.c */

extern void _ExceptInit(void *);

/*---------------------------------------------------------------------*

Name            new_thread - thread startup function

Usage           static DWORD new_thread(void *arglist, PFN endfunc);

Prototype in    local

Description     This function is the first code that is run by a
                new thread created with _beginthread.  The function
                first checks that a thread data area has been
                allocated, and terminates if not.  It then retrieves
                the thread start address from the thread data area,
                and calls that function, passing it arglist as
                its single parameter.

Return value    None.

*---------------------------------------------------------------------*/

static DWORD _RTLENTRY new_thread(THREAD_DATA *t, void (_RTLENTRY *endfunc) (unsigned __retval))
{
    EXCEPTIONREGISTRATIONRECORD hand;
    MEMORY_BASIC_INFORMATION info;
    DWORD extra = 0;
    OSVERSIONINFO ov;
    unsigned retval;

    ov.dwOSVersionInfoSize = sizeof (ov);
    GetVersionEx (&ov);

    if (ov.dwPlatformId == 1) /*  If under Win95 we cannot go below
                               *  64K above what the system says is
                               *  the bottom of the stack
                               */
        extra = 0x10000;

    /* Save a pointer to the thread data structure in NT's thread
     * local storage.
     */

    _tlsindex = (DWORD)t;

    /* Store the thread's stack base in the thread local storage.
     */
    VirtualQuery((void *)&info, &info, sizeof(info));
    _stkindex = ((DWORD)info.AllocationBase + extra);

    _ExceptInit(t->thread_exceptvars);

    /* Set up the RTL exception handler.  Save a pointer to
     * its registration record in the thread data, so that
     * _endthread() can remove it.
     */
    _setexc(&hand);
    t->thread_excep = &hand;

    /* Call the thread starting address.  If the function returns a value,
       we hold it in retval, and pass it along to the endfunc.  This allows
       us to have both _beginthreadex & _beginthread routines come through
       here and pass the proper values to _endthread & _endthreadex.
     */
    if (t->thread_ex_mode)
        retval = (*((unsigned __stdcall (*) (void *))t->thread_func))(t->thread_arglist);
    else
        retval = (*((unsigned _USERENTRY (*) (void *))t->thread_func))(t->thread_arglist);

    if (endfunc)
        endfunc(retval);

    return 0;   /* may never get here */
}

/* -------------------------------------------------------------------- */

static DWORD __stdcall new_thread_helper(THREAD_DATA *t)
{
    if (t->thread_ex_mode)
        return new_thread (t, _endthreadex);
    else
        return new_thread (t, (void (_RTLENTRY *) (unsigned))_endthread);
}

/*---------------------------------------------------------------------*

Name            _adopt_thread
                _unadopt_thread

Prototype in    process.h

Description     The _adopt_thread function is designed to hook up the
                needed internal data (exceptions, stack info, ...)
                into a thread that was created from CreateThread.  Normally
                a user will call _beginthread to creat a thread and that
                will hook up the internal data automatically.  If a user is
                called from a thread that came from an outside source (ie
                ISAPI) then this needed internal data is not present.  This
                function will handle that, call the user function (passing
                in the arglist param), then unhook the exception stuff and
                return a handle to the thread context.  This is so that the
                same function can be used again (without re-allocation all
                that data).  Then, at some known end of this cycle, the
                _unadopt_thread function can be called to finally free up
                the rest of this data.

                Alternatively, the last parameter free_flag can be set to
                non-zero and the thread data structures will be freed before
                _adopt_thread returns.  In this case the returned thread
                context will be NULL since it has already been freed.

Return value    The thread context or NULL if free_flag is true or if an
                error occured in which case errno is set to:

                  ENOMEM  Not enough memory

*---------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC _unadopt_thread (_PTHREAD_ADOPTION_DATA thd)
{
    if (thd)
        _thread_data_del((THREAD_DATA*)thd);
}

_PTHREAD_ADOPTION_DATA _RTLENTRY _EXPFUNC _adopt_thread (void (_USERENTRY *start_address)(void *),
                                                         void *arglist, int free_flag)
{
    THREAD_DATA *t;
    t = _thread_data();
    if (!t)
    {
        errno = ENOMEM;
        return NULL;
    }

    t->thread_func = start_address;
    t->thread_arglist = arglist;

    new_thread (t, NULL);  // NULL means don't call _endthread at the end
    _unsetexc(t->thread_excep);
    if (free_flag)
    {
        _thread_data_del(t);
        errno = 0;  // reset errno so this NULL doesn't look like an error.
        t = NULL;

    }
    return (_PTHREAD_ADOPTION_DATA)t;
}


/* -------------------------------------------------------------------- */


static unsigned long _RTLENTRY __beginthreadNT(void (_USERENTRY *start_address)(void *),
                                                      unsigned  stack_size,
                                                      void *arglist,
                                                      void *security_attr,
                                                      unsigned long create_flags,
                                                      unsigned long *thread_id,
                                                      int ex_mode)
{
    DWORD tid;
    THREAD_DATA *t;
    HANDLE h;

    /* Check to see that the requested stack size is valid (zero is
     * legal and means the same size as primary thread)
     */
    if (((signed)stack_size) < 16 && stack_size != 0)
    {
        errno = EINVAL;
        return -1;
    }

    /* Allocate a per-thread data structure for the new thread.
     * Save a pointer to the argument list and the starting address.
     */
    if ((t = _thread_data_new()) == NULL)
    {
        errno = ENOMEM;
        return -1;
    }
    t->thread_arglist = arglist;
    t->thread_func = start_address;

    /* Save the ex_mode state for use later
     */
    t->thread_ex_mode = ex_mode;

    /* Create the thread and start it running.
     */
    h = CreateThread((LPSECURITY_ATTRIBUTES)security_attr, stack_size,
                     (LPTHREAD_START_ROUTINE) (new_thread_helper),
                     t, create_flags, &tid);
    if (h == NULL)
    {
        if (GetLastError() == ERROR_NOT_ENOUGH_QUOTA)
            return (__IOerror(ERROR_NO_PROC_SLOTS));
        else
            return (__NTerror());
    }
    t->thread_handle = h;
    if (thread_id)
        *thread_id = tid;
    return ((int)h);
}

/*---------------------------------------------------------------------*

Name            _beginthreadNT - create and start a thread (advanced)

Prototype in    process.h

Description     This function creates a thread and allows specifying the
                other parameters of the OS API CreateThread (ie security and
                thread creation flags).  Otherwise it's the same as
                _beghtthread.


Return value    If successful, the thread ID number.
                If unsuccessful, -1 is returned, and errno is set as
                follows:
                    EAGAIN  Too many threads
                    ENOMEM  Not enough memory
            EINVAL  Bad stack value (for stack less than 16 bytes)

*---------------------------------------------------------------------*/
unsigned long _RTLENTRY _EXPFUNC _beginthreadNT(void (_USERENTRY *start_address)(void *),
                                                      unsigned  stack_size,
                                                      void *arglist,
                                                      void *security_attr,
                                                      unsigned long create_flags,
                                                      unsigned long *thread_id)
{
    return __beginthreadNT (start_address, stack_size, arglist,
                            security_attr, create_flags, thread_id, 0);
}


/*---------------------------------------------------------------------*

Name            _beginthread - create and start a thread

Usage           unsigned long _beginthread(void (*start_address)(void *),
                    unsigned stack_size, void *arglist);

Prototype in    process.h

Description     This function creates a thread.  The thread starts
                execution at start_address.  The size of its stack
                is stack_size; the stack is allocated by they system
                after the stack size is rounded up to the next multiple
                of 4096.  The thread is a passed arglist as its only parameter;
                it may be NULL, but must be present.  The thread
                terminates by simply returning, or by calling _endthread.

Return value    If successful, the thread ID number.
                If unsuccessful, -1 is returned, and errno is set as
                follows:
                    EAGAIN  Too many threads
                    ENOMEM  Not enough memory
            EINVAL  Bad stack value (for stack less than 16 bytes)

*---------------------------------------------------------------------*/

unsigned long _RTLENTRY _EXPFUNC _beginthread(void (_USERENTRY *start_address)(void *),
                                              unsigned stack_size, void *arglist)
{
    return _beginthreadNT(start_address, stack_size, arglist, 0, 0, 0);
}



/*---------------------------------------------------------------------*

Name            _beginthreadex - create and start a thread (advanced, MSC compat)

Prototype in    process.h

Description     This function creates a thread and allows specifying the
                other parameters of the OS API CreateThread (ie security and
                thread creation flags).  When the thread finnishes its
                execution, _endthreadex is called (as opposed to _endthread)
                which does NOT close the thread handle.

                NOTE: the start address needs to be defined to return an
                unsigned which is the thread exit code.


Return value    If successful, the thread ID number.
                If unsuccessful, -1 is returned, and errno is set as
                follows:
                    EAGAIN  Too many threads
                    ENOMEM  Not enough memory
            EINVAL  Bad stack value (for stack less than 16 bytes)

*---------------------------------------------------------------------*/

unsigned long _RTLENTRY _EXPFUNC _beginthreadex(void *__security,
                                                unsigned __stksize,
                                                unsigned (__stdcall *__startaddr)(void *),
                                                void *__arglist,
                                                unsigned __initflag,
                                                unsigned *__threadaddr)
{
    return __beginthreadNT((void (_USERENTRY *)(void *))__startaddr, __stksize,
                          __arglist, __security,
                          (unsigned long)__initflag,
                          (unsigned long *)__threadaddr,
                          1 /* the 1 here indicates ex-mode */);
}




/*---------------------------------------------------------------------*

Name            _endthread - terminate current thread

Usage           void _endthread(void);

Prototype in

Description     This function terminates the current thread.  The thread
                must have been created by an earlier call to _beginthread.

Return value    None.

*---------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC _endthread(void)
{
    THREAD_DATA *t;
    HANDLE h;

    if ((t = _thread_data()) != NULL)
    {
        _unsetexc(t->thread_excep);
        h = t->thread_handle;
        _thread_data_del(t);
        CloseHandle(h);
    }
    ExitThread(0);
}

/*---------------------------------------------------------------------*

Name            _endthreadex - terminate current thread (without closing handle)

Usage           void _endthreadex(unsigned __retval);

Prototype in

Description     This function terminates the current thread.  The thread
                must have been created by an earlier call to _beginthreadex.
                The parameter __retval will be the exit code passed to the OS
                API ExitThread.
                This function will not close the thread handle.

Return value    None.

*---------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC _endthreadex(unsigned __retval)
{
    THREAD_DATA *t;

    if ((t = _thread_data()) != NULL)
    {
        _unsetexc(t->thread_excep);
        _thread_data_del(t);
    }
    ExitThread(__retval);
}
