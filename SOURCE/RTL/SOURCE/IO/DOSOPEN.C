/*-----------------------------------------------------------------------*
 * filename - _dos_open.c
 *
 * function(s)
 *        _dos_open - opens a file for reading or writing
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1991, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.3 $        */


#include <errno.h>
#include <fcntl.h>
#include <_io.h>

#define BAD_FLAGS (O_BINARY | O_TEXT | O_APPEND | O_CREAT)

/*-----------------------------------------------------------------------*

Name            _dos_open - opens a file for reading or writing

Usage           #include <fcntl.h>
                unsigned _dos_open(const char *pathname, unsigned oflag,
                                int *handle);

Prototype in    dos.h

Description     _dos_open opens the file pathname with the access mode
                specified by oflag.  See _open for information on
                oflag.  If the open is successful, the file handle
                is stored at *handle.

Return value    success : 0
                else    : the DOS error code, and errno is set.

Note            Compatible with Microsoft C.  Not the same as _open().

*------------------------------------------------------------------------*/

unsigned _RTLENTRY _EXPFUNC
_dos_open (const char *pathP, unsigned oflag, int *handle )
{
    int fd;

    if ((fd = __open(pathP, (oflag & ~BAD_FLAGS) | O_BINARY)) == -1)
        return (_doserrno);         /* error */
    else
    {
        *handle = fd;
        return 0;                   /* success */
    }
}
