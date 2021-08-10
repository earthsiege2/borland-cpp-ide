/*-----------------------------------------------------------------------*
 * filename - oshandle.c
 *
 * function(s)
 *      _get_osfhandle - return OS file handle
 *      _open_osfhandle - allocate a file handle table slot
 *----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1993, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <ntbc.h>

#include <_io.h>
#include <_thread.h>
#include <fcntl.h>
#include <errno.h>

/*---------------------------------------------------------------------*

Name            _get_osfhandle - return OS file handle

Usage           long _get_handle(int handle);

Prototype in    io.h

Description     This function returns the OS file handle that corresponds
                to given RTL handle.

Return value    If successful, the OS file handle; otherwise -1 and sets
                errno to EBADF

*---------------------------------------------------------------------*/

long _RTLENTRY _EXPFUNC _get_osfhandle(int handle)
{
    if ((unsigned) handle < _nfile)
        {
        if (_openfd[handle] != 0)
            return _handles[handle];
        }
    errno = EBADF;
    return -1;
}


/*---------------------------------------------------------------------*

Name            _open_osfhandle - allocate a file handle table slot

Usage           int _open_handle(long ofshandle, int oflag);

Prototype in    io.h

Description     This function allocates the first free slot in the
                file handle table _handles[].  The OS handle is stored
                in the _handles[], and the oflag (open file flags)
                word is stored in _openfd[].  The index of the table slot
                is returned.

                NOTE: this is a user callable _get_handle().

Return value    If successful, the handle table index; otherwise -1.

*---------------------------------------------------------------------*/

int  _RTLENTRY _EXPFUNC _open_osfhandle(long osfhandle, int oflag)
{
    long handle;

    /* Get the default translation mode from _fmode if not specified
     * by oflag.  Then, If O_BINARY is not specified, set O_TEXT
     * so that the flags will be non-zero when stored in _openfd[].
     */
    if ((oflag & (O_TEXT | O_BINARY)) == 0)
        oflag |= _FMODE & (O_TEXT | O_BINARY);
    if ((oflag & O_BINARY) == 0)
        oflag |= O_TEXT;

    oflag &= ~_O_RUNFLAGS;          /* clear bits used only at open time */

    _lock_all_handles();
    handle = _get_handle(osfhandle, oflag);
    _unlock_all_handles();

    return handle;
}
