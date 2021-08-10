/*-----------------------------------------------------------------------*
 * filename - thrddata.c
 *
 * function(s)
 *      _thread_data     - return address of current thread's "static" data
 *      _thread_data_new - allocate new per-thread data structure
 *      _thread_data_del - deallocate per-thread data structure
 *      _thread_init     - initialize data structures for threads
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>

#include <_thread.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

/*----------------------------------------------------------------------
 * External variables
 */
extern DWORD  _tlsindex;           /* thread local storage index (tls.c) */
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
    if ((p = (THREAD_DATA *)TlsGetValue(_tlsindex)) == NULL)
    {
        p = _thread_data_new();
        TlsSetValue(_tlsindex, (void *)p);
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
    else if ((t = malloc(sizeof(THREAD_DATA))) != NULL)
        memset(t, 0, sizeof(THREAD_DATA));

    if (t != NULL)
        {
        /* Set the rand() seed to 1.
         */
        t->thread_seed = 1;

        /* Allocate space dor exception variables.
         */
        if ((t->thread_exceptvars = malloc(_ExceptVarsSize)) == NULL)
            {
            free(t);
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
#pragma startup _thread_init 1

    /* Create the lock used to guard access to the thread data
     * structures.
     */
    _create_lock(&thread_lock,"creating thread data lock");
}
