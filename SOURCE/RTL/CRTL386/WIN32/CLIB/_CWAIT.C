/*------------------------------------------------------------------------
 * filename - cwait.c
 *
 * function(s)
 *        cwait - cwait for termination of a particular child process.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>

#include <process.h>
#include <errno.h>
#include <_thread.h>
#include <_io.h>
#include <string.h>

#define MAXPIDS MAXIMUM_WAIT_OBJECTS

/*-----------------------------------------------------------------------
 * _add_pid_ptr - pointer to function to add process to table
 *
 * This pointer is defined in loadprog.c.  Initially it points to a dummy
 * function, but if cwait() is used, it is set to point to _add_pid()
 * below, which actually adds the process to a table that maps process
 * IDs to process handles.
 */
extern int (*_add_pid_ptr)(DWORD, HANDLE);

/*----------------------------------------------------------------------
 * Table to map process IDs to process handles.  The tables are
 * stored as two separate arrays, one for process IDs, and one for
 * process handles.  This is done so that WaitForMultipleObjects
 * can be used on the handle array.  Whenever a process ID is deleted,
 * the resulting gap is closed by moving down successive entries.
 */
static int npids = 0;               /* no. of entries in table */
static DWORD pids[MAXPIDS];         /* process IDs */
static HANDLE phandles[MAXPIDS];    /* process handles */

/*----------------------------------------------------------------------
 * Semaphore to lock access to the process ID table.
 */
#ifdef _MT

static lock_t pid_lock;

static void lockpid(void)
{
    _lock(pid_lock,"locking PID table");
}

static void unlockpid(void)
{
    _unlock(pid_lock,"unlocking PID table");
}

#else

#define lockpid()
#define unlockpid()

#endif

/*------------------------------------------------------------------------*

Name            add_pid - add a new process to table

Usage           int add_pid(DWORD pid, HANDLE handle)

Prototype in    none

Description     This function adds a new process to the process ID table.


Returns         If successful, the process ID is returned; otherwise
                -1 is returned and errno is set to

                    EAGAIN  Too many outstanding processes

*--------------------------------------------------------------------------*/

int add_pid(DWORD pid, HANDLE handle)
{
    int rc;

    lockpid();
    if (npids == MAXPIDS)
    {
        errno = EAGAIN;
        RETURN (-1);
    }
    pids[npids] = pid;
    phandles[npids] = handle;
    npids++;
    rc = (int)pid;
exit:
    unlockpid();
    return rc;
}

/*------------------------------------------------------------------------*

Name            cwait -  Halt calling thread until a particular child dies.

Usage           int cwait(int *term_stat, int pid, int action);

Prototype in    process.h

Description     This function waits for a child process to terminate.
                The process of the child to wait for is pid.  If term_stat
                is not null, it points to location where cwait will
                store the termination status. Action specifies whether
                to wait for the process alone, or for the process
                and all of its children.

                If 'term_stat' is not NULL then it points to a word whose
                high and low order bytes are defined as follows:

                - For NORMAL child termination(ie. via DosExit())
                        Low  order byte - will be zero (0)
                        High order byte - The low order byte of the return
                                code from the child process.  This is the
                                value that is passed to a DosExit() call, or
                                is returned from main() or passed to exit()
                                or passed to _exit().  If the child process
                                didn't exit via one of the above methods but
                                just "fell through" main() then this value
                                will be unpredictable.

                - For ABNORMAL child termination(killed/trap/harderr abend)
                        Low  order byte - Termination info about the child
                                1 - Critical error abort
                                2 - Execution fault, protection exception
                                3 - DosKillProcess signal
                        High order byte - will be zero (0)

                If pid is 0, cwait waits for any child process to terminate.
                Otherwise, pid specifies the process ID of the process to wait
                for; this value must have been obtained by an earlier call
                call to a spawn function.

                The acceptable values for 'action' are :

                WAIT_CHILD      - waits for the specified child only
                WAIT_GRANDCHILD - waits for the specified child *and* all of
                                  its children

                These two values are defined in PROCESS.H.

Returns
                When cwait() returns after a normal child process termination
                it returns the PID of the child to the parent.

                When cwait() returns after an abnormal child termination it
                returns -1 to the parent and sets 'errno' to EINTR.

                If cwait() returns without a child process completion it
                returns a-1 value and sets 'errno' as follows:

                EINVAL - A bad 'action' value was specified.
                ECHILD - No child exists or the 'pid' value is bad.
*--------------------------------------------------------------------------*/

int _RTLENTRY _cwait(int *term_stat, int pid, int action)
{
    DWORD   ret, exitcode;
    int     index, rc;
    HANDLE  handle;

    if (action != WAIT_CHILD && action != WAIT_GRANDCHILD)
    {
        errno = EINVAL;
        return -1;
    }

    if (pid == 0)
    {
        /* Wait for any child to terminate.
         */
        ret = WaitForMultipleObjects(npids, phandles, FALSE, -1);

        if (ret >= WAIT_ABANDONED_0 && ret < WAIT_ABANDONED_0 + npids)
            index = ret - WAIT_ABANDONED_0;
        else if (ret < npids)
            index = ret;
        else
        {
echild:
            errno = ECHILD;
            return -1;
        }
    }
    else
    {
        /* Wait for the specified process to terminate.  Search
         * for it in the table.
         */
        lockpid();
        for (index = 0; index < npids && pids[index] != (DWORD)pid; index++)
            ;
        if (index == npids)
        {
            unlockpid();
            goto echild;
        }
        unlockpid();

        ret = WaitForSingleObject(phandles[index], -1);
        if (ret != 0 && ret != WAIT_ABANDONED)
            goto echild;
    }

    /* Get the return code of the terminated process.
     */
    handle = phandles[index];
    if (GetExitCodeProcess(handle, &exitcode) != TRUE)
        rc = __NTerror();
    else
        rc = pids[index];
    CloseHandle(handle);

    /* Remove the process from the table.
     */
    lockpid();
    memcpy(&pids[index], &pids[index+1], sizeof(DWORD) * (npids - index - 1));
    memcpy(&phandles[index], &phandles[index+1], sizeof(HANDLE) * (npids - index - 1));
    npids--;
    unlockpid();

    /* Return the termination code to *term_stat.  NOTE: is there any
     * way to detect abnormal termination on NT?
     */
    if (term_stat != NULL && rc != -1)
        *term_stat = (int)((exitcode & 0xff) << 8);
    return (rc);
}

/*---------------------------------------------------------------------*

Name            _init_cwait - initialize process ID table and lock

Usage           void _init_cwait(void);

Description     This function creates the global lock that governs
                access to the process ID table.  It also sets the
                _add_pid_ptr pointer (in loadprog.c) to point to
                the _add_pid() function.

Return value    None.

*---------------------------------------------------------------------*/

static void _init_cwait(void)
{
#pragma startup _init_cwait 1

    /* Create the lock used to govern access to the process ID table.
     */
    _create_lock(&pid_lock,"creating process ID table lock");

    /* Set the pointer to the _add_pid() function.
     */
    _add_pid_ptr = add_pid;
}
