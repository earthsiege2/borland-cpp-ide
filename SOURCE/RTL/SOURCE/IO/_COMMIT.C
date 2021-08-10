/*-----------------------------------------------------------------------*
 * filename - _commit.c
 *
 * function(s)
 *    _commit - forces the OS to commit written changes to a file.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1999, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

#define INCL_ERROR_H

#include <ntbc.h>

#include <io.h>
#include <_io.h>

/*-----------------------------------------------------------------------*

Name            _commit - forces the OS to commit written changes to a file

Usage           int _commit(int handle);

Prototype in    io.h

Description     _commit forces the OS to commit (phsycally write all
                internal buffers to the disk) any changes that have been
                written to it. This is done with the OS FlushFileBuffers()
                API.

                The OS WriteFile and WriteFileEx functions typically write
                data to an internal buffer that the operating system writes
                to disk on a regular basis. The FlushFileBuffers function
                writes all of the buffered information for the specified
                file to disk.

Return value    On success, it returns 0. In case of error, _commit returns
                -1 and sets the global variable errno to one of the following:

                    EACCES  Permission denied
                    EBADF   Bad file number

*------------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC _commit(int fd)
{

    /* if the file handle is out of range or not open, then error */

    if (((unsigned)fd >= _nfile) || (_openfd[fd] == 0))
    {
        return __IOerror(ERROR_INVALID_HANDLE);
    }

    _lock_handle(fd);

    if (FlushFileBuffers((HANDLE)_handles[fd]) != TRUE)
    {
        _unlock_handle(fd);
        return (__NTerror());
    }

    _unlock_handle(fd);
    return 0;
}
