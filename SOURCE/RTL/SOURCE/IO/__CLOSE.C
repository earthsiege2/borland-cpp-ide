/*------------------------------------------------------------------------
 * filename - __close.c
 *
 * function(s)
 *        __close - close a file handle
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1991, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.8.2.1 $        */

#define INCL_ERROR_H

#include <ntbc.h>

#include <_io.h>
#include <io.h>

extern int _isWindows; /* from startup/globals.c */

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
int _RTLENTRY _EXPFUNC __close (int handle)
{
    int is_pseudo = 0;

    if ((unsigned)handle >= _nfile)
        return __IOerror(ERROR_INVALID_HANDLE);

    _lock_handle(handle);


    /*
       O_PSEUDO is a special flag that is or'ed into the three system
       handles at startup time in GUI mode apps.
    */

    if (_openfd [handle] & O_PSEUDO)
        is_pseudo = 1;


    /* In gui mode apps the OS HANDLEs for, stdin, stdout, & stderr are
       pseudo HANDLEs and cannot successfully be closed.  So to allow them
       to be closed and possibly re-opened later we special case their
       handles' indices here. In console mode (or gui mode with handles
       other than stdin, stdout & stderr), the OS HANDLES are real, and the
       CloseHandle() API call won't fail.
    */
    if (
         is_pseudo ||
         ((CloseHandle((HANDLE)_handles[handle]) == TRUE))
       )
    {
        /* success */
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
