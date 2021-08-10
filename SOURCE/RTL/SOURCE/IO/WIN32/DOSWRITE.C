/*-----------------------------------------------------------------------*
 * filename - doswrite.c
 *
 * function(s)
 *        _dos_write - writes data to file (MSC compatible)
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

Name            _dos_write - writes data to file

Usage           unsigned _dos_write(int handle, void far *buf, unsigned nbyte,
                                unsigned *nwrite);

Prototype in    dos.h

Description     _dos_write is a direct call to the NT WriteFile system call.
                The number of bytes requested is nbyte.

                If the write is successful, the number of bytes actually
                written is stored at *nwrite, which may be less than
                the number of bytes requested.
                No text file translation is performed on the data.

Return value    success : 0, and *nwrite is set to no. of bytes written
                else    : the DOS error code, and errno is set to
                          one of the following:

                        EACCESS  Permission denied
                        EBADF    Bad file number

Note            Compatible with Microsoft C.  Not the same as _write().

*------------------------------------------------------------------------*/

unsigned _RTLENTRY _EXPFUNC
_dos_write( int fd, void *buf, unsigned len, unsigned *nwrite )
{
    DWORD   written;

    if ((unsigned)fd >= _nfile)
    {
        __IOerror(ERROR_INVALID_HANDLE);    /* set errno */
        return (ERROR_INVALID_HANDLE);      /* return fake NT error code */
    }

    if (WriteFile((HANDLE)_handles[fd], (PVOID)buf, (DWORD)len, &written,
                  NULL) != TRUE)
        return (__DOSerror());
    else
    {
        *nwrite = (unsigned)written;
        return (0);
    }
}
