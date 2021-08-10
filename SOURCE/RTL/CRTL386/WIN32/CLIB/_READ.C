/*-----------------------------------------------------------------------*
 * filename - _read.c
 *
 * function(s)
 *        _rtl_read - reads binary data from a file
 *        _read - reads binary data from a file ( obsolete )
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

Name            _rtl_read - reads from file

Usage           int _rtl_read(int handle, void *buf, unsigned nbyte);

Prototype in    io.h

Description     _rtl_read is a direct call to the NT ReadFile system call.
                see also __read in __READ.C

                No translation of newlines is performed, even if
                the file was opened in text mode.  No locking of the
                file handle semaphore is performed in multi-thread
                environments, as __read does.

Return value    Upon successful completion, a positive integer is
                returned indicating the number of bytes placed in the buffer.

                On end-of-file, _rtl_read return zero. On error, _rtl_read
                returns -1 and errno is set to one of the following:

                        EACCES  Permission denied
                        EBADF   Bad file number

*------------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC _rtl_read( int fd, void *buf, unsigned len )
{
    DWORD   nread;

    if ((unsigned)fd >= _nfile)
        return __IOerror(ERROR_INVALID_HANDLE);

    if (ReadFile((HANDLE)_handles[fd], buf, (DWORD)len, &nread, NULL) != TRUE)
        return (__NTerror());
    else
        return ((int)nread);
}

/*------------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC _read( int fd, void *buf, unsigned len )
{
   return(_rtl_read(fd, buf, len) );
}
