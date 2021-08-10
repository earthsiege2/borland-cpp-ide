/*---------------------------------------------------------------------------
 * filename - flength.c
 *
 * function(s)
 *        filelength - gets file size in bytes
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1991, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#define INCL_ERROR_H

#include <ntbc.h>

#include <io.h>
#include <_io.h>

/*--------------------------------------------------------------------------*

Name            filelength - gets file size in bytes

Usage           long filelength(int handle);

Prototype in    io.h

Description     returns the length (in bytes) of the file associated
                with handle

Return value    success : length of the file
                failure : -1L and errno is set to

                        EBADF  Bad file number

*---------------------------------------------------------------------------*/

long _RTLENTRY _EXPFUNC filelength (int fd)
{
    long        rc;

    if ((unsigned)fd >= _nfile)
        return __IOerror(ERROR_INVALID_HANDLE);

    _lock_handle(fd);

    if ((rc = GetFileSize((HANDLE)_handles[fd],NULL)) == -1L)
        RETURN (__NTerror());
exit:
    _unlock_handle(fd);
    return (rc);
}
