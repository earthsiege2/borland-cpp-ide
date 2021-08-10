/*-----------------------------------------------------------------------*
 * filename - __lseek.c
 *
 * function(s)
 *        __lseek - moves read/write file pointer
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1991, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

#define INCL_ERROR_H

#include <ntbc.h>

#include <_io.h>
#include <io.h>
#include <fcntl.h>

/*-----------------------------------------------------------------------*

Name            __lseek - moves read/write file pointer

Usage           #include <io.h>
                long __lseek(int handle, long offset, int fromwhere);

Related
functions usage long tell(int handle);

Prototype in    io.h

Description     __lseek sets the file pointer associated with handle
                to a new position that is offset bytes beyond the file
                location given by fromwhere. fromwhere must be one of the
                values 0, 1 or 2, which represent three symbolic constants
                (defined in stdio.h) as follows:

                fromwhere       File Location
                SEEK_SET (0)    file beginning
                SEEK_CUR (1)    current file pointer position
                SEEK_END (2)    end-of-file

                tell gets the current position of the file pointer associated
                with handle and expresses it as the number of bytes from the
                beginning of the file.

Return value    __lseek returns the offset of the pointer's new
                position, measured in bytes from the file beginning. __lseek
                returns -1L on error, and errno is set to one of the following:

                    EBADF   Bad file number
                    EINVAL  Invalid argument

                On devices incapable of seeking (such as terminals and
                printers), the return value is undefined.

                tell returns the current file pointer position. A return of -1
                (long) indicates an error, and errno is set to:

                    EBADF   Bad file number

*------------------------------------------------------------------------*/

long _RTLENTRY _EXPFUNC __lseek(int fd, long offset, int kind)
{
    LONG   NewPtr;
    DWORD  method;

    if ((unsigned)fd >= _nfile)
        return __IOerror(ERROR_INVALID_HANDLE);

    /* Translate the POSIX seek type to the NT method.
     */
    switch (kind)
    {
    case SEEK_SET:
        method = FILE_BEGIN;
        break;
    case SEEK_CUR:
        method = FILE_CURRENT;
        break;
    case SEEK_END:
        method = FILE_END;
        break;
    default:
        return ((long)__IOerror(ERROR_INVALID_FUNCTION));
    }

    _lock_handle(fd);

    _openfd[fd] &= ~_O_EOF;      /* forget about ^Z      */

    if ((NewPtr = SetFilePointer((HANDLE)_handles[fd], offset, NULL, method))
                == -1)
        __NTerror();        /* set errno */

    _unlock_handle(fd);

    return NewPtr;
}
