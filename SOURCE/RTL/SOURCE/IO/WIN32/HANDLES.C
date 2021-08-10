/*-----------------------------------------------------------------------*
 * filename - handles.c
 *
 * function(s)
 *        _lock_all_handles   - lock global file handle lock
 *        _unlock_all_handles - unlock the global file handle lock
 *        _lock_handle        - lock a file handle
 *        _unlock_handle      - unlock a file handle
 *        _get_handle         - allocate a file handle table slot
 *        _dup_handle         - duplicate a file handle table slot
 *        _free_handle        - free a file handle table slot
 *        cfinfo_get          - construct file information table
 *        _init_handles       - initialize file handle table and lock
 *        _cleanup_handle_locks - free the global file handle lock
 *----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <ntbc.h>

#include <_io.h>
#include <_thread.h>
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

/*----------------------------------------------------------------------
 * Flag bits for C file startup information
 *
 * These flags are used to construct the file information table, which
 * passes open file handle information to child processes. The values
 * were chosen for compatibility with the MSC implementation, and do
 * NOT correspond exactly to open() flags.
 */
#define _CF_OPEN    0x01        /* file is open */
#define _CF_APPEND  0x20        /* file was opened with O_APPEND */
#define _CF_TERM    0x40        /* file is a character device */
#define _CF_TEXT    0x80        /* file was not opened with O_BINARY */

#ifdef _MT

/*----------------------------------------------------------------------
 * Semaphores to lock access to the file handle table and the
 * file handles themeselves.
 */
static lock_t handle_lock;  /* global handle lock */
static lock_t *hlocks;      /* table of per-handle locks */
static int _selffree = 0;   /* used to determine whether _unlock_handle()
                               should free the lock or leave it allocated */
/*---------------------------------------------------------------------*

Name            _lock_all_handles - lock the global file handle lock

Usage           void _lock_all_handles(void);

Prototype in    _io.h

Related
functions usage void _unlock_all_handles(void);

Description     This function locks the global lock that governs
                access to the file handle table and the lock table
                in hlock.c

Return value    None.

*---------------------------------------------------------------------*/

void _lock_all_handles(void)
{
    _lock(handle_lock,"locking global handle lock");
}

/*---------------------------------------------------------------------*

Name            _cleanup_handle_locks - free the global file handle lock

Usage           void _cleanup_handle_locks(void);

Description     This function frees the global lock that governs
                access to the file handle table.

Notes           This function also sets the _selffree flag to 1.  This
                is in case a dll (like CG32) forces some cleanup calls
                back into the EXE's RTL, and the handle locks are
                needed again.  _lock_handle() will automatically re-
                allocate the lock blocks again, and with this flag set
                _unlock_handle() will also free it.

Return value    None.

*---------------------------------------------------------------------*/

void _cleanup_handle_locks(void)
{
    if (hlocks)
    {
        free (hlocks);
        hlocks = 0;
    }
    _selffree = 1;
}

/*---------------------------------------------------------------------*

Name            _unlock_all_handles - unlock the global file handle lock

Usage           void _unlock_all_handles(void);

Prototype in    _io.h

Related
functions usage void _unlock_all_handles(void);

Description     This function unlocks the global lock that governs
                access to the file handle table and the lock table
                in hlock.c

Return value    None.

*---------------------------------------------------------------------*/

void _unlock_all_handles(void)
{
    _unlock(handle_lock,"unlocking global handle lock");
}

/*---------------------------------------------------------------------*

Name            _lock_handle - lock a file handle

Usage           void _lock_handle(int handle);

Prototype in    _io.h

Related
functions usage void _unlock_handle(int handle);

Description     This function locks a file handle to prevent other
                threads from using that handle.  The handle must
                refer to a valid open file, and is not checked.
                A matching _unlock_handle call must be made to
                unlock the handle.  Nested locks can be be performed
                on a single handle, as long as they are matched
                by an equal number of unlock operations.

Return value    None.

*---------------------------------------------------------------------*/

void _lock_handle(int handle)
{
    /* If the lock for this handle has never been created, create it.
     */
    if (hlocks == NULL || hlocks[handle] == 0)
    {
        _lock_all_handles();

        /* Create the handle lock array.
         */
        if (hlocks == NULL)
        {
            size_t size;

            size = sizeof(lock_t) * _nfile;
            if ((hlocks = malloc(size)) == NULL)
                _lock_error("allocating handle lock table");
            memset(hlocks,0,size);
        }

        /* Create this particular handle lock.
         */
        if (hlocks[handle] == 0)
            _create_lock(&hlocks[handle],"creating handle lock");

        _unlock_all_handles();
    }

    _lock(hlocks[handle],"locking handle");
}

/*---------------------------------------------------------------------*

Name            _unlock_handle - lock a file handle

Usage           void _unlock_handle(int handle);

Prototype in    _io.h

Related
functions usage void _unlock_handle(int handle);

Description     This function locks a file handle to prevent other
                threads from using that handle.  The handle must
                refer to a valid open file, and is not checked.
                A matching _unlock_handle call must be made to
                unlock the handle.  Nested locks can be be performed
                on a single handle, as long as they are matched
                by an equal number of unlock operations.

Return value    None.

*---------------------------------------------------------------------*/

void _unlock_handle(int handle)
{
    _unlock(hlocks[handle],"unlocking handle");
    if (_selffree)
        _cleanup_handle_locks();
}



#endif  /* _MT */

/*---------------------------------------------------------------------*

Name            _get_handle - allocate a file handle table slot

Usage           int _get_handle(long handle, int oflag);

Prototype in    _io.h

Related
functions usage void _free_handle(int fd);

Description     This function allocates the first free slot in the
                file handle table _handles[].  The OS handle is stored
                in the _handles[], and the oflag (open file flags)
                word is stored in _openfd[].  The index of the table slot
                is returned.

                NOTE: the file handles are assumed to have been previously
                locked with _lock_all_handles!

Return value    If successful, the handle table index; otherwise -1.

*---------------------------------------------------------------------*/

int _get_handle(long handle, int oflag)
{
    int i;

    /* Free slots are those where _openfd[] is zero.
     */
    for (i = 0; i < (int)_nfile; i++)
        if (_openfd[i] == 0)        /* found a free slot? */
            break;
    if (i == (int)_nfile)           /* no free slots */
        return -1;

    _openfd [i] = oflag;            /* save the open flags */
    _handles[i] = handle;           /* save the OS handle */
    return i;                       /* return index (UNIX file handle) */
}

/*---------------------------------------------------------------------*

Name            _dup_handle - duplicate a file handle table slot

Usage           int _dup_handle(int oldfd, int newfd, long handle);

Prototype in    _io.h

Related
functions usage void _get_handle(long handle, int oflag);

Description     This function copies the handle flags indicated by oldfd
                to the slot indicated by newfd, and sets the handle for
                newfd to handle.  An error occurs if oldhandle does
                not refer to an open file, or if newhandle does not
                refer to a free slot.

                If newfd is -1, the first available handle slot is used;
                otherwise the slot specified by newfd is used.

                NOTE: the file handles are assumed to have been previously
                locked with _lock_all_handles!

Return value    If successful, newhandle is returned; otherwise -1.

*---------------------------------------------------------------------*/

int _dup_handle(int oldfd, int newfd, long handle)
{
    /* If newfd is -1, search for the first available slot.
     */
    if (newfd == -1)
        for (newfd = 0; newfd < (int)_nfile && _openfd[newfd] != 0; newfd++)
            ;

    /* Check that handles are within range and that they are in the
     * proper state.
     */
    if ((unsigned)oldfd >= _nfile || (unsigned)newfd >= _nfile)
        return -1;
    if (_openfd[oldfd] == 0 || _openfd[newfd] != 0)
        return -1;

    /* Copy the file flags and set the new handle.
     */
    _openfd [newfd] = _openfd[oldfd];   /* copy the open flags */
    _handles[newfd] = handle;           /* save the OS handle */
    return newfd;                       /* return index (UNIX file handle) */
}

/*---------------------------------------------------------------------*

Name            _free_handle - free a file handle table slot

Usage           void _free_handle(int fd);

Prototype in    _io.h

Related
functions usage void _free_handle(long handle, int oflag);

Description     This function frees the handle table slot whose index
                is fd.  This is done by setting _openfd[fd] to 0.

                NOTE: the file handles are assumed to have been previously
                locked with _lock_all_handles!

Return value    none

*---------------------------------------------------------------------*/

void _free_handle(int fd)
{
    if ((unsigned)fd < _nfile)
        _openfd[fd] = 0;
}

/*-----------------------------------------------------------------------*

Name            cfinfo_get - construct file information table

Usage           int cfinfo_get(char *buf);

Prototype in    local

Description     This function constructs the file information table
                based on the state of the current open files.
                The resulting table is copied to the buffer 'buf'.  No
                length checking is performed on the buffer.

                If the buffer is NULL, the function does not store
                the file information table, but calculates and returns
                the size of the buffer required to store the table.

                A pointer to this function is stored in the global
                variable _cfinfo_get.  If no file I/O is used,
                it points to a dummy function instead of this function.

Return value    If buffer is NULL, the length of the environment string;
                otherwise 0.

*------------------------------------------------------------------------*/

static int cfinfo_get(char *buf)
{
    int n, i, fdflags;
    char flags;

    /* Find the last open file.
     */
    for (n = _nfile; n != 0; n--)
        if (_openfd[n-1] != 0)
            break;

    /* If the buffer is NULL, return the length of the buffer required
     * to hold the file information.  The buffer is in the following
     * format:
     *      int         number of files (n)
     *      char[n]     file flags
     *      long[n]     file handles
     * The program loader will pass a pointer to this table in the
     * STARTUPINFO parameter to CreateProcess.
     */
    if (buf == NULL)
    {
        if (n == 0)
            return (0);
        else
            return (sizeof(int) + n*(sizeof(char)+sizeof(long)));
    }

    /* Construct the table, as described above.
     */
    *(int *)buf = n;
    buf+= sizeof(int);
    for (i = 0; i < n; i++)
    {
        flags = _CF_OPEN;                   /* this bit is always set */
        fdflags = _openfd[i];
        if (fdflags & O_APPEND)             /* convert O_APPEND bit */
            flags |= _CF_APPEND;
        if ((fdflags & O_BINARY) == 0)      /* convert O_BINARY bit */
            flags |= _CF_TEXT;
        if (fdflags & O_DEVICE)             /* convert O_DEVICE bit */
            flags |= _CF_TERM;
        *buf++ = flags;
    }
    memcpy(buf, _handles, n * sizeof(long)); /* copy handles */
    return (0);
}


/*---------------------------------------------------------------------*

Name            _init_handles - initialize file handle table and lock

Usage           void _init_handles(void);

Description     This function creates the the global lock that governs
                access to the file handle table and the lock table
                in hlock.c.  It also attempts to open the printer
                and assigns it to file handle 4 for use by strprn.

Return value    None.

*---------------------------------------------------------------------*/

void _RTLENTRY _init_handles(void)
{
    int     i, n, nhand, gotinfo;
    char    *p;
    char    flags;
    int     fdflags;
    STARTUPINFO s;

    /* Create the lock used to govern access to the lock table in hlock.c.
     */
    _create_lock(&handle_lock,"creating global handle lock");

    /* Set the maximum handle count to _nfile, then reset _nfile to
     * the actual number allowed if less than requested.
     */
    if ((i = SetHandleCount((DWORD)_nfile)) < _nfile)
        _nfile = i;

    /* Set the pointer to the function that constructs _C_FILE_INFO.
     */
    _cfinfo_get = cfinfo_get;

    /* If the STARTUPINFO contains a pointer to file handle information,
     * convert its value to open flags and file handles.
     */
    gotinfo = 0;
    GetStartupInfo(&s);
    n = s.cbReserved2;              /* no. of bytes of startup info */
    p = (char *)s.lpReserved2;      /* pointer to the info */
    if (n != 0)                     /* is the info is non-empty? */
    {
        /* First word is number of handles.  Verify that the number
         * matches the size of the information block.
         */
        nhand = *((int *) p);
        p += sizeof(int);
        if (n == sizeof(int) + nhand*(sizeof(char)+sizeof(long)))
        {
            /* Convert the file flags (MSC) to _openfd flags.
             */
            gotinfo = 1;
            for (i = 0; i < nhand; i++)
            {
                flags = *p++;
                fdflags = 0;

                if (flags & _CF_APPEND)
                    fdflags |= O_APPEND;

                if (flags & _CF_TERM)
                    fdflags |= O_DEVICE;

                if (flags & _CF_TEXT)
                    fdflags |= O_TEXT;
                else
                    fdflags |= O_BINARY;

                _openfd[i] = (_openfd[i] & O_ACCMODE) | fdflags;
            }
            for (i = nhand; i < _nfile; i++)
                _openfd[i] = 0;

            /* Copy the handle table.
             */
            memmove(_handles, p, nhand*sizeof(long));
        }
    }

    /* Get the standard I/O handles if the file information
     * wasn't passed from the parent.
     */
    if (!gotinfo)
    {
        _handles[0] = (long)GetStdHandle (STD_INPUT_HANDLE);
        _handles[1] = (long)GetStdHandle (STD_OUTPUT_HANDLE);
        _handles[2] = (long)GetStdHandle (STD_ERROR_HANDLE);

        /* Check to see if the standard files are character devices.
         */
        for (i = 0; i <= 2; i++)
            if (__isatty(i))
                _openfd[i] |= O_DEVICE;
            else
                _openfd[i] &= ~O_DEVICE;
    }
}
