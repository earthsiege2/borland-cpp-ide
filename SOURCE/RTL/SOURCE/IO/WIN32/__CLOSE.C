/*------------------------------------------------------------------------
 * filename - __close.c
 *
 * function(s)
 *        __close - close a file handle
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1991, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#define INCL_ERROR_H

#include <ntbc.h>

#include <_io.h>
#include <io.h>

/*-------------------------------------------------------------------------*

Name            __close - close a file handle

Usage           int __close(int handle);

Prototype in    io.h

Description     __close closes the  file handle indicated by handle  which is
                obtained  from a  _creat, creat,  creatnew, creattemp, dup,
                dup2, _rtl_open or open call.

Return value    Upon  successful completion,  __close returns  0 otherwise,  a
                value of  -1 is returned, and errno is  set to
                    EBADF Bad file number

*---------------------------------------------------------------------------*/

int _RTLENTRYF __close (int handle)
{
    if ((unsigned)handle >= _nfile)
        return __IOerror(ERROR_INVALID_HANDLE);

    _lock_handle(handle);

    if (CloseHandle((HANDLE)_handles[handle]) == TRUE)  /* success */
    {
        _openfd [handle] = 0;
	_handles[handle] = (unsigned long) INVALID_HANDLE_VALUE;
        _unlock_handle(handle);
        return (0);
    }
    else        /* failure */
    {
        _unlock_handle(handle);
        return __NTerror();
    }
}
