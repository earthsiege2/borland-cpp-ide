/*---------------------------------------------------------------------------
 * filename - __dup2.c
 *
 * function(s)
 *        __dup2 - duplicate a file handle
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1991, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#define INCL_ERROR_H

#include <ntbc.h>

#include <io.h>
#include <_io.h>

/*--------------------------------------------------------------------------*

Name            __dup2 - duplicate a file handle

Usage           int   __dup2(int oldhandle, int newhandle);

Prototype in    io.h

Description     __dup2 sets the file handle newhandle to have the
                following in common with the original file handle:

                    . same open file or device
                    . same file pointer(that is, changing the file pointer of
                      one changes th other
                    . same access mode(read,write,read/write)

                If the file associated with newhandle is open when
                __dup2 is called, it is closed.

Return value    __dup2 returns 0 on successful completion, -1 otherwise.
                This is incompatible with UNIX/POSIX usage, but compatible
                with Microsoft C.

                In the event of an error, errno is set to one of the
                following:
                    EMFILE  Too many open files
                    EBADF   Bad file number

*---------------------------------------------------------------------------*/

static DWORD stdhandle[3] =
                { STD_INPUT_HANDLE, STD_OUTPUT_HANDLE, STD_ERROR_HANDLE };

int _RTLENTRY __dup2 (int oldfd, int newfd)
{
    int     rc = 0;
    int     orgfd = newfd;
    HANDLE  newhandle;      /* new file handle */
    HANDLE  prochandle;     /* handle of current process */
    
    if ((unsigned)oldfd >= _nfile)          /* validate the old file handle */
        return __IOerror(ERROR_INVALID_HANDLE);

    prochandle = GetCurrentProcess();       /* get current process handle */

    if (newfd != -1)                        /* close new handle if open */
        if (__close(newfd) == -1)
            return -1;

    _lock_all_handles();

    if (DuplicateHandle(prochandle, (HANDLE)_handles[oldfd], prochandle,
                        &newhandle, 0, TRUE, DUPLICATE_SAME_ACCESS) != TRUE)
        RETURN(__NTerror());

    if ((newfd = _dup_handle(oldfd, newfd, (long)newhandle)) == -1)
    {
        CloseHandle(newhandle);
        RETURN(__IOerror(ERROR_TOO_MANY_OPEN_FILES));
    }

    if (newfd < 3)
        if (SetStdHandle(stdhandle[newfd], newhandle) != TRUE)
            RETURN(__NTerror());

exit:
    _unlock_all_handles();

    return (orgfd == -1) ? newfd : rc;
}
