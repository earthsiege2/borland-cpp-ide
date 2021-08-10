/*-----------------------------------------------------------------------*
 * filename - _write.c
 *
 * function(s)
 *    _write - write to a file (untranslated)
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#define INCL_ERROR_H

#include <ntbc.h>

#include <io.h>
#include <_io.h>

/*-----------------------------------------------------------------------*

Name            _write - writes to a file

Usage           int _write(int handle, void *buf, unsigned nbyte);

Prototype in    io.h

Description     _write is a direct call to the NT WriteFile system call.
                See also __write in __WRITE.C

                No translation of newlines is performed, even if
                the file was opened in text mode.  No locking of the
                file handle semaphore is performed in multi-thread
                environments, as __write does.

Return value    The number of bytes written are returned by both
                functions. In case of error, _write returns -1
                and sets the global variable errno to one of the following:

                    EACCES  Permission denied
                    EBADF   Bad file number

*------------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC _write(int fd, const void *buf, unsigned int len)
{
    DWORD   written;

    if ((unsigned)fd >= _nfile)
        return __IOerror(ERROR_INVALID_HANDLE);

    if (WriteFile((HANDLE)_handles[fd], (PVOID)buf, (DWORD)len, &written,
                  NULL) != TRUE)
        return (__NTerror());
    else
        return ((int)written);
}
