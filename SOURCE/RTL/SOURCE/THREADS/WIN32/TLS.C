/*-----------------------------------------------------------------------*
 * filename - tls.c
 *
 * function(s)
 *      _init_tls     - startup initialization for thread local storage
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1992, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>

#include <_defs.h>

/*----------------------------------------------------------------------
 * The following variable gives the index into the thread local storage
 * of the location where the RTL stores each thread's stack base.
 * It is used by alloca() to check for stack overflow.
 */
DWORD _stkindex;        /* thread local storage index of stack base */
DWORD _tlsindex;        /* thread local storage index for thread data */

/*---------------------------------------------------------------------*

Name            _init_tls - startup initialization for thread local storage

Usage           void _init_tls(void);

Description     This function is called at startup time if alloca()
                or threads are used (see _alloca.asm).  It sets up a
                thread local storage index that can be used to save
                the base of each thread's stack, and fetches the base
                of the main thread's stack.

                It also also sets up a tls index that is used by threads
                to save a pointer to a THRDDATA structure.

Return value    None.

*---------------------------------------------------------------------*/

void _RTLENTRY _init_tls(void)
{
#pragma startup _init_tls 1

    MEMORY_BASIC_INFORMATION info;

    /* Allocate a thread local storage index, to be used for saving each
     * thread's stack base.  This is used by alloca() to check for
     * stack overflow.
     */
    _stkindex = TlsAlloc();

    /* Store the main thread's stack base in the thread local storage.
     * The _beginthread function will do the same for each new thread.
     */
    VirtualQuery((void *)&info, &info, sizeof(info));
    TlsSetValue(_stkindex, (void *)info.AllocationBase);

    /* Allocate a thread local storage index, to be used for THRDDATA.
     */
    _tlsindex = TlsAlloc();
}


/*---------------------------------------------------------------------*

Name            _exit_tls - termination for thread local storage

Usage           void _exit_tls(void);

Description     This function is called at exit time if alloca()
                or threads are used (see _alloca.asm).  It frees up the
                thread local storage index that can is used to save
                the base of each thread's stack.

                It also also frees up the tls index that is used by threads
                to save a pointer to a THRDDATA structure.

Return value    None.

*---------------------------------------------------------------------*/

void _RTLENTRY _exit_tls(void)
{
#pragma exit _exit_tls 1

    TlsFree(_stkindex);
    TlsFree(_tlsindex);
}
