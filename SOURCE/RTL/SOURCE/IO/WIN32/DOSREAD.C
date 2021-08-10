/*-----------------------------------------------------------------------*
 * filename - dosread.c
 *
 * function(s)
 *        _dos_read - reads from file
 *-----------------------------------------------------------------------*/

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

/*-----------------------------------------------------------------------*

Name            _dos_read - reads from file

Usage           unsigned _dos_read(int handle, void *buf, unsigned nbyte,
                                unsigned *nread);

Prototype in    dos.h

Description     _dos_read is a direct call to the NT ReadFile system call.
                The number of bytes requested is nbyte.

                If the read is successful, the number of bytes actually
                read is stored at *nread.  If *nread is 0, an attempt
                was made to read at the end of file.
                No text file translation is performed on the data read.

Return value    success : 0, and *nread is set to no. of bytes read
                else    : the DOS error code, and errno is set to
                          one of the following:

                        EACCESS  Permission denied
                        EBADF    Bad file number

Note            Compatible with Microsoft C.  Not the same as _rtl_read().

*------------------------------------------------------------------------*/

unsigned _RTLENTRY _EXPFUNC
_dos_read (int fd, void *buf, unsigned len, unsigned *nread)
{
    DWORD   actual;

    if ((unsigned)fd >= _nfile)
    {
        __IOerror(ERROR_INVALID_HANDLE);    /* set errno */
        return (ERROR_INVALID_HANDLE);      /* return fake NT error code */
    }

    if (ReadFile((HANDLE)_handles[fd], buf, (DWORD)len, &actual, NULL) != TRUE)
        return (__DOSerror());
    else
    {
        *nread = (unsigned)actual;
        return (0);
    }
}
