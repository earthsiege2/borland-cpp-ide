/*-----------------------------------------------------------------------*
 * filename - _lock.c
 *
 * function(s)
 *      _create_lock    - create a semaphore
 *      _lock_nt        - lock a semaphore
 *      _unlock_nt      - unlock a semahore
 *      _lock_error     - print semaphore error message and exit
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1991, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.5.2.1 $        */

/* The following line is required to define the CRITICAL_SECTION correctly
 * in WINNT.H for SDK3.  It apparently enables debugging fields, which
 * I assume will be removed for the final release of NT.
 * Remove when Microsoft fixes the problem.
 */
#define DEVL  1

#include <ntbc.h>

#include <_io.h>
#include <string.h>
#include <_thread.h>

#define MAX_LOCKS 512  /* This should be big enough for everyone */

/*----------------------------------------------------------------------
 * crit - array of critical sections
 */
static CRITICAL_SECTION crit[MAX_LOCKS];
static int nlocks;

/*---------------------------------------------------------------------*

Name            _create_lock - create a semaphore

Usage           void _create_lock(lock_t *lockp, char *mesg);

Prototype in    _thread.h

Description     This function creates a semaphore, storing its handle
                at the long word pointed to by lockp.  If an error occurs,
                an error message containing 'mesg' is printed, and
                the program is terminated abnormally.

Return value    None.

*---------------------------------------------------------------------*/

void _create_lock(lock_t *lockp, char *mesg)
{
    EnterCriticalSection(&crit[0]);     /* lock the lock table */
    if (nlocks >= MAX_LOCKS)            /* exceeded maximum no. */
        _lock_error(mesg);
    InitializeCriticalSection(&crit[nlocks]);
    *lockp = (long)&crit[nlocks++];     /* allocate the next free lock */
    LeaveCriticalSection(&crit[0]);
}

/*---------------------------------------------------------------------*

Name            _lock_nt - lock a semaphore

Usage           void _lock_nt(lock_t lock);

Prototype in    _thread.h

Related
functions usage void _unlock(lock_t lock);

Description     This function locks a semaphore.  No error can occur.

Return value    None.

*---------------------------------------------------------------------*/

void _lock_nt(lock_t lock)
{
    EnterCriticalSection((CRITICAL_SECTION *)lock);
}

/*---------------------------------------------------------------------*

Name            _unlock_nt - unlock a semaphore

Usage           void _unlock_nt(lock_t lock, char *mesg);

Prototype in    _thread.h

Related
functions usage void _lock_nt(lock_t lock, char *mesg);

Description     This function unlocks a semaphore.  No error can occur.

Return value    None.

*---------------------------------------------------------------------*/

void _unlock_nt(lock_t lock)
{
    LeaveCriticalSection((CRITICAL_SECTION *)lock);
}

/*---------------------------------------------------------------------*

Name            _lock_error - print semaphore error message and exit

Usage           void _lock_error(char *mesg);

Prototype in    _thread.h

Description     This function prints an error message to standard error,
                then terminates all threads in the current process.
                This function is called when a file handle semaphore
                operation fails.

Return value    None.

*---------------------------------------------------------------------*/

void _lock_error(char *mesg)
{
    char buf[80];

    strcpy(buf,"Semaphore error ");
    strcat(buf,mesg);
    _ErrorExit(buf);
}

/*---------------------------------------------------------------------*

Name            _init_lock - initialize lock table

Usage           void _init_lock(void);

Description     This function creates the global lock that governs
                access to the lock table.

Return value    None.

*---------------------------------------------------------------------*/


static void _init_lock(void)
{
#pragma startup _init_lock 0 /* Initialization of the master MT lock for all other locks */

    /* Create the critical section used to govern access to the
     * table of other critical sections.  We use crit[0] for this.
     */
    InitializeCriticalSection(&crit[0]);
    nlocks = 1;
}
