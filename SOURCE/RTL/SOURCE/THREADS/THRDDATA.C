/*-----------------------------------------------------------------------*
 * filename - thrddata.c
 *
 * function(s)
 *      _thread_data     - return address of current thread's "static" data
 *      _thread_data_new - allocate new per-thread data structure
 *      _thread_data_del - deallocate per-thread data structure
 *      _thread_init     - initialize data structures for threads
 *      _thread_done     - clean up data structures for threads
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1991, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.8.2.1 $        */

#include <ntbc.h>

#include <_thread.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <_malloc.h>

/*----------------------------------------------------------------------
 * External variables
 */
extern DWORD __thread _tlsindex; /* thread local storage index (tls.c) */
extern unsigned _ExceptVarsSize;

/*----------------------------------------------------------------------
 * Private variables
 */
static THREAD_DATA *free_list;      /* list of unused thread data structures */
static lock_t       thread_lock;    /* semaphore for THREAD_DATA pointer */

/*---------------------------------------------------------------------*

Name            _thread_data - return address of "static" thread data
                                    for the current thread

Usage           THREAD_DATA * _thread_data(void);

Prototype in

Description     This function returns the address of the thread data
                structure for the current thread.  This data structure
                contains data that is ordinarily static in non-threading
                libraries.

Return value    If successful, the address of a THREAD_DATA structure.
                If unsuccessful, a NULL pointer.

*---------------------------------------------------------------------*/

THREAD_DATA * _thread_data(void)
{
    THREAD_DATA *p;

    /* If no thread data has been allocated for this thread, allocate
     * it and save a pointer to it in the thread local storage block.
     */
    if ((p = (THREAD_DATA *)_tlsindex) == NULL)
    {
        p = _thread_data_new();
        _tlsindex = (DWORD)p;
    }
    return p;
}

/*---------------------------------------------------------------------*

Name            _thread_data_new - allocate new per-thread data structure

Usage           THREAD_DATA * _thread_data_new(void);

Prototype in

Description     This function allocates a new per-thread data structure.
                This data structure contains data that is ordinarily
                static in non-threading libraries.  The caller is responsible
                for saving the returned pointer in the thread local storage.

Return value    If successful, the address of a THREAD_DATA structure.
                If unsuccessful, a NULL pointer.

*---------------------------------------------------------------------*/

THREAD_DATA * _thread_data_new(void)
{
    THREAD_DATA *t;

    _lock(thread_lock,"locking thread data (new)");

    /* First check the free list of thread structures.  Unlink the first
     * structure on the list.
     */
    if ((t = free_list) != NULL)
        free_list = t->thread_link;

    /* Nothing on the free list.  Allocate a new structure and zero it out.
     */
    else if ((t = __org_malloc(sizeof(THREAD_DATA))) != NULL)
        memset(t, 0, sizeof(THREAD_DATA));

    if (t != NULL)
        {
        /* Set the rand() seed to 1.
         */
        t->thread_seed.lo = 1;
        t->thread_seed.hi = 0;

        /* Initialize the other fields that must be 0
         */
        t->thread_ex_mode = 0;
        t->thread_excep   = 0;
        t->thread_xtra    = 0;

        /* Allocate space for exception variables if needed.  NOTE:
           we reuse this block of memory from previously terminated
           threads.
         */
        if ((t->thread_exceptvars == NULL) &&
            ((t->thread_exceptvars = __org_malloc(_ExceptVarsSize)) == NULL))
            {
            __org_free(t);
            t = NULL;
            }
        else
            memset(t->thread_exceptvars, 0, _ExceptVarsSize);
        }

    _unlock(thread_lock,"unlocking thread data (new)");
    return t;
}

/*---------------------------------------------------------------------*

Name            _thread_data_del - deallocate per-thread data structure

Usage           void _thread_data_del(THREAD_DATA * t);

Prototype in

Description     This function deallocates a per-thread data structure
                by placing it on the linked list of such structures.

Return value    none

*---------------------------------------------------------------------*/

void _thread_data_del(THREAD_DATA *t)
{
    _lock(thread_lock,"locking thread data (del)");

    /* Place the block on the free list for re-use later */
    t->thread_link = free_list;
    free_list = t;

    _unlock(thread_lock,"unlocking thread data (del)");
}

/*---------------------------------------------------------------------*

Name            _thread_init - initialize data structures for threads

Usage           void _thread_init(void);

Prototype in

Description     This function is called by the startup code to initialize
                all data structures needed by thread handling internal
                library functions.

Return value    None.

*---------------------------------------------------------------------*/

static void _thread_init(void)
{
#pragma startup _thread_init 1 /* Initialize the thread data struct's MT lock */

    /* Create the lock used to guard access to the thread data
     * structures.
     */
    _create_lock(&thread_lock,"creating thread data lock");
}

/*---------------------------------------------------------------------*

Name            _thread_done - clean up data structures for threads

Usage           void _thread_done(void);

Prototype in

Description     This function is called by the exit code to clean up
                all data structures used by thread handling internal
                library functions.

Return value    None.

*---------------------------------------------------------------------*/
static void _thread_done(void)
{
#pragma exit _thread_done 2 /* Finalization of all remaining thread data blocks */

    THREAD_DATA *p;

    /* Free the main thread's data if needed */
    if ((p = (THREAD_DATA *)_tlsindex) != NULL)
        _thread_data_del(p);

    while (free_list)
    {
        p = free_list;
        if (p->thread_strbuf)
            __org_free (p->thread_strbuf);
        if (p->thread_template)
            __org_free (p->thread_template);
        if (p->thread_cvt)
            __org_free (p->thread_cvt);
        if (p->thread_pathbuf)
            __org_free (p->thread_pathbuf);
        if (p->thread_time)
            __org_free (p->thread_time);
        if (p->thread_passbuf)
            __org_free (p->thread_passbuf);
        if (p->thread_exceptvars)
            __org_free (p->thread_exceptvars);
        if (p->thread_sig)
            __org_free (p->thread_sig);

        p = free_list->thread_link;
        __org_free (free_list);
        free_list = p;
    }
}