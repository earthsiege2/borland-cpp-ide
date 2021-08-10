/*---------------------------------------------------------------------------
 * filename - dosclose.c
 *
 * function(s)
 *        _dos_close - close a file handle
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <_io.h>
#include <errno.h>

/*--------------------------------------------------------------------------*

Name            _dos_close - close a file handle

Usage           unsigned _dos_close(int handle);

Prototype in    io.h

Description     _dos_close closes the  file handle indicated by handle which is
                obtained  from a  _dos_creat, _dos_creatnew, or _dos_open call.

Return value    Upon successful completion, _dos_close returns 0.
                Otherwise, the DOS error code is returned, and errno is set to
                        EBADF   Bad file number

*---------------------------------------------------------------------------*/

unsigned _RTLENTRY _EXPFUNC _dos_close( int fd )
{
    if (__close(fd) != 0)
        return (_doserrno);
    else
        return 0;
}
