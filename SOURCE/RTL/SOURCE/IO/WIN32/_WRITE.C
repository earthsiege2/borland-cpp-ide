/*-----------------------------------------------------------------------*
 * filename - _rtl_write.c
 *
 * function(s)
 *    _rtl_write - write to a file (untranslated)
 *    _write - write to a file (untranslated)
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#define INCL_ERROR_H

#include <ntbc.h>

#include <io.h>
#include <_io.h>

/*-----------------------------------------------------------------------*

Name            _rtl_write - writes to a file

Usage           int _rtl_write(int handle, void *buf, unsigned nbyte);

Prototype in    io.h

Description     _rtl_write is a direct call to the NT WriteFile system call.
                See also __rtl_write in __rtl_write.C

                No translation of newlines is performed, even if
                the file was opened in text mode.  No locking of the
                file handle semaphore is performed in multi-thread
                environments, as __rtl_write does.

Return value    The number of bytes written are returned by both
                functions. In case of error, _rtl_write returns -1
                and sets the global variable errno to one of the following:

                    EACCES  Permission denied
                    EBADF   Bad file number

*------------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC _rtl_write(int fd, const void *buf, unsigned int len)
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

int _RTLENTRYF _EXPFUNC _write(int fd, const void *buf, unsigned int len)
{
    return _rtl_write(fd, buf, len);
}

