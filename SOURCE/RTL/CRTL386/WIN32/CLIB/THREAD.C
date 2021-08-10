/*-----------------------------------------------------------------------*
 * filename - thread.c
 *
 * function(s)
 *      _beginthread - create and start a thread
 *      _endthread   - terminate a thread
 *-----------------------------------------------------------------------*/

/* $Copyright: 1991$ */

#include <ntbc.h>

#include <stdlib.h>
#include <errno.h>
#include <_io.h>
#include <_thread.h>
#include <string.h>
#include <process.h>

extern DWORD _tlsindex;                         /* in tls.c */
extern DWORD _stkindex;                         /* in tls.c */

extern void _setexc(PEXCEPTIONREGISTRATIONRECORD p);    /* in startup.c */
extern void _unsetexc(PEXCEPTIONREGISTRATIONRECORD p);  /* in startup.c */

extern void _ExceptInit(void *);

/*---------------------------------------------------------------------*

Name            new_thread - thread startup function

Usage           static void new_thread(void *arglist);

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

DWORD new_thread(THREAD_DATA *t)
{
    EXCEPTIONREGISTRATIONRECORD hand;
    MEMORY_BASIC_INFORMATION info;

    /* Save a pointer to the thread data structure in NT's thread
     * local storage.
     */
    TlsSetValue(_tlsindex, (void *)t);

    /* Store the thread's stack base in the thread local storage.
     */
    VirtualQuery((void *)&info, &info, sizeof(info));
    TlsSetValue(_stkindex, (void *)info.AllocationBase);

    _ExceptInit(t->thread_exceptvars);

    /* Set up the RTL exception handler.  Save a pointer to
     * its registration record in the thread data, so that
     * _endthread() can remove it.
     */
    _setexc(&hand);
    t->thread_excep = &hand;

    /* Call the thread starting address
     */
    (*(t->thread_func))(t->thread_arglist);
    _endthread();
    return 0;   /* never gets here */
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

*---------------------------------------------------------------------*/

unsigned long _RTLENTRY _EXPFUNC _beginthreadNT(void (_USERENTRY *start_address)(void *),
                                                      unsigned  stack_size,
                                                      void *arglist,
                                                      void *security_attr,
                                                      unsigned long create_flags,
                                                      unsigned long *thread_id)
{
    DWORD tid;
    THREAD_DATA *t;
    HANDLE h;

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

    /* Create the thread and start it running.
     */
    h = CreateThread((LPSECURITY_ATTRIBUTES)security_attr, stack_size, (LPTHREAD_START_ROUTINE)new_thread,
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

unsigned long _RTLENTRY _EXPFUNC _beginthread(void (_USERENTRY *start_address)(void *),
                                              unsigned stack_size, void *arglist)
{
    return _beginthreadNT(start_address, stack_size, arglist, 0, 0, 0);
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
