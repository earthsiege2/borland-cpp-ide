/*---------------------------------------------------------------------------
 * filename - doscommit.c
 *
 * function(s)
 *        _dos_commit - commit a file handle
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1991, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>
#include <_io.h>

/*--------------------------------------------------------------------------*

Name            _dos_commit - commit a file handle

Usage           unsigned _dos_commit(int handle);

Prototype in    io.h

Description     _dos_commit commits the  file handle indicated by handle which is
                obtained  from a  _dos_creat, _dos_creatnew, or _dos_open call.

Return value    Upon successful completion, _dos_commit returns 0.
                Otherwise, the DOS error code is returned, and errno is set to
                        EBADF   Bad file number

*---------------------------------------------------------------------------*/
unsigned _RTLENTRY _dos_commit( int fd )
{
    return FlushFileBuffers((HANDLE)_handles[fd]) ? 0 : __NTerror();
}
