/*-----------------------------------------------------------------------*
 * filename - initexit.c
 *
 * function(s)
 *      _init_exit_proc - return address of next _INIT_ proc
 *      _cleanup        - call _EXIT_ routines
 *      _terminate      - terminate the program
 *      _lock_exit      - lock the atexit lock
 *      _unlock_exit    - unlock the atexit lock
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1996, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.8 $        */

#define INCL_USER
#include <ntbc.h>
#include <_defs.h>
#include <_io.h>
#include <_thread.h>
#include <_process.h>   /* _getpid() */
#include <_startup.h>
#include <stdlib.h>     /* exit() */
#include <string.h>     /* strchr() */
#ifdef _BUILDRTLDLL
#include <dos.h>        /* __emit__() */
#endif
#include <tchar.h>

/*----------------------------------------------------------------------
 * The following tables each contain a pointer to the module table
 * for this program (either an EXE or DLL).  See _startup.h and c02.asm
 * for the table layout.
 */
extern  MULTI_INIT _dll_table;       /* DLL's init table */
extern  MULTI_INIT _exe_table;       /* EXE's init table */

/*----------------------------------------------------------------------
 * Mutex Semaphore to lock access to the atexit table.
 */
#ifdef _MT
extern lock_t __exit_lock;
#endif

/*---------------------------------------------------------------------*

Name            _terminate - terminate the program

Usage           void _terminate(int code);

Description     This function is called by exit() to terminate the
                current process and return an error code to the
                parent process.  All threads are terminated as well.

Return value    None.

*---------------------------------------------------------------------*/

void _terminate(int code)
{
    ExitProcess(code);              /* terminate all threads */
}

/*---------------------------------------------------------------------*

Name            _create_shmem - create shared memory region

Usage           static MULTI_INIT *_create_shmem(void);

Description     This function creates or opens the shared memory region
                used to store the addresses of _INIT_ and
                _EXIT_ segments for each DLL.  If the region already
                exists, it is not created.

Return value    The address of the shared memory region, or NULL if
                it cannot be created.

*---------------------------------------------------------------------*/
MULTI_INIT *_create_shmem(void)
{
    return NULL;
}
/*---------------------------------------------------------------------*

Name            open_shmem - return address of shared memory region

Usage           static MULTI_INIT *open_shmem(void);

Description     This function returns the address of the shared memory
                region used to store the addresses of _INIT_ and
                _EXIT_ segments for each DLL.

Return value    The address of the shared memory region, or NULL if
                it does not exist.

*---------------------------------------------------------------------*/

static MULTI_INIT *open_shmem(void)
{
    return NULL;
}
/*---------------------------------------------------------------------*

Name            _init_exit_proc - return address of next _INIT_ function

Usage           VOIDFUNC _init_exit_proc(MULTI_INIT *init_table, int is_exit);

Description     This function returns the address of the next function
                to call in the _INIT_ segments listed in the MULTI_INIT
                table pointed to by init_table.

                The is_exit flag is zero if this a startup table, and 1
                if this is an exit table. this affects whether the _INIT_
                functions are to be called in high-to-low or
                low-to-high priority order.

Return value    The address of the next function to call, or NULL if
                all INIT functions have been called.

*---------------------------------------------------------------------*/
void _init_exit_proc(MULTI_INIT *init_table, int is_exit)
{
    /* This function iterates through all the #pragma startup/exit entries
       that have been registered in the system and calls them in the correct
       priority order.  The compiler will generate an instance of an INIT
       structure for each #pragma startup/exit statement in each module that
       it compiles.  All the entries marked as startup are generated into
       the _INIT_ segment and all the entries marked as exit are generated
       into the _EXIT_ segment.  The startup code then calculates the
       beginning and ending of each of these segments and eventually passes
       them into here as elements of the MULTI_INIT and MODULE_DATA
       structures.
    */

    INIT *table_start, *table_end, *ip;
    MODULE_DATA *modtable;
    int prior, i, start, end, incr;

    if (is_exit) /* EXIT table: process priorities from 255 -> 0 */
    {
        start = 0xff;   /* Start at 255     */
        end   = -1;     /* end prior to -1  */
        incr  = -1;     /* decrement        */
    }
    else         /* INIT table: process priorities from 0 -> 255 */
    {
        start = 0;      /* start at 0       */
        end   = 0x100;  /* end prior to 256 */
        incr  = 1;      /* increment        */
    }

    for (prior = start; prior != end; prior += incr)
    {
        for (i = 0; i < init_table->ntables; i++) /* for each _INIT_ table */
        {
            modtable = init_table->table[i];
            table_start = is_exit ? modtable->exit_start : modtable->init_start;
            table_end   = is_exit ? modtable->exit_end   : modtable->init_end;

            /* Scan through each table, looking, in priority order, for the
               next entry that needs to be called.  Priority 0 is highest.
               If this is an INIT table, start with the highest priority
               entries. If this is an EXIT table, start with the lowest
               priority entries.  In the case of duplicate priorities, we
               want the first one to be used for INIT entries and the last
               one to be used for EXIT entries.  We do this by making the
               loop take the first one it finds, but we run the EXIT loop
               from back to front so that the first one it finds is really
               the last one in the table.
            */

            if (is_exit == 0)  /* INIT: run the table front to back */
            {
                for (ip = table_start; ip < table_end; ip++)
                {
                    if ((unsigned char)prior == ip->priority)
                    {
                        ip->func();   /* call the INIT function */
                    }
                }
            }
            else /* EXIT: run the table back to front */
            {
                for (ip = table_end-1; ip >= table_start; ip--)
                {
                    if ((unsigned char)prior == ip->priority)
                    {
                        ip->func();   /* call the EXIT function */
                    }
                }
            }
        }
    }
}

/*---------------------------------------------------------------------*

Name            _cleanup - call _EXIT_ routines

Usage           void _cleanup(void);

Description     This function is called by exit() to  call all routines
                that have 'init' records in the _EXIT_ segment.  If
                this is the DLL version of the RTL, call the _EXIT_
                routines for the DLL as well.

Return value    None.

*---------------------------------------------------------------------*/

void _cleanup(void)
{
    MULTI_INIT *share_dll_table;
    int i;
    static int called = 0;

    /* Make sure that we're only called once.  Normally we are only called
       once, either by the user calling exit() or by falling through
       main/WinMain and the startup code calling exit().  However we must
       support this one eccentric MS compatible routine called _c_exit()
       which performs all shutdown operations but doesn't actually exit the
       process and instead returns to the caller.  In this situation
       _cleanup will get called from within _c_exit() and then again
       eventually when main/WinMain returns.  So to prevent the exit
       procedures from getting called twice (something they cannot handle),
       we will set a state flag and only call them the first time _cleanup
       is called.
     */

    if (called)
        return;

    called = 1;  /* set flag that prevents multiple _cleanup()'s */


    /* Run all the EXE's exit procedures.
     */
    _init_exit_proc(&_exe_table, 1);

    /* The following call runs the DLL's exit procedures.
     * This is also done in _startupd, if the DLL is marked as
     * "terminstance".  But if the user forgets to mark the DLL as
     * terminstance, we must call the exit procs here.
     */
    _init_exit_proc(&_dll_table, 1);

    /* Call exit functions for any other DLLs that might have
     * been loaded.  Then call each DLL's pseudo-entry point,
     * which simply calls that DLL's _dllmain().
     */
    if ((share_dll_table = open_shmem()) != NULL)
    {
        /* Call the exit functions for each DLL.
         */
        _init_exit_proc(share_dll_table, 1);

        /* Call _dllmain for each DLL.
         */
        for (i = 0; i < share_dll_table->ntables; i++)
#pragma warn -pro
            share_dll_table->table[i]->main(1, share_dll_table->table[i]->hmod);
#pragma warn .pro

    }
}
/*---------------------------------------------------------------------*

Name            _lock_exit - lock the atexit lock

Usage           void _lock_exit(void);

Prototype in    _stdio.h

Related
functions usage void _unlock_exit(void);

Description     This function locks the global lock that governs
                access to the atexit table.

Return value    None.

*---------------------------------------------------------------------*/

#ifdef _MT
void _lock_exit(void)
{
    _lock(__exit_lock,"locking atexit table");
}
#endif

/*---------------------------------------------------------------------*

Name            _unlock_exit - unlock the atexit lock

Usage           void _unlock_exit(void);

Prototype in    _stdio.h

Related
functions usage void _lock_exit(void);

Description     This function unlocks the global lock that governs
                access to the atexit table.

Return value    None.

*---------------------------------------------------------------------*/

#ifdef _MT
void _unlock_exit(void)
{
    _unlock(__exit_lock,"unlocking atexit lock");
}
#endif


#ifdef _MT
static void _RTLENTRY _init_exit()
{
#pragma startup _init_exit 6 /* Initialization of the atexit table MT lock */

    /* Create the lock used to govern access to the atexit table.
     */
    _create_lock(&__exit_lock,"creating atexit lock");
}
#endif

