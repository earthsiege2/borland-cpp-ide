/*-----------------------------------------------------------------------*
 * filename - _read.c
 *
 * function(s)
 *        _rtl_read - reads binary data from a file
 *        _read - reads binary data from a file ( MS_COMPAT )
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

/* _read() is an MS-COMPAT function.  It is identical to our read() function
   which goes straight to __read().
*/

int _RTLENTRYF _EXPFUNC _read( int fd, void *buf, unsigned len )
{
   return(__read(fd, buf, len));
}
