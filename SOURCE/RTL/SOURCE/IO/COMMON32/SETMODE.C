/*-----------------------------------------------------------------------*
 * filename - setmode.c
 *
 * function(s)
 *        setmode - sets mode of open file
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <errno.h>
#include <io.h>
#include <_io.h>
#include <fcntl.h>

/*--------------------------------------------------------------------------*

Name            setmode - sets mode of open file

Usage           int setmode(int handle, int mode);

Prototype in    io.h

Description     setmode  sets the  mode of  the open  file associated  with
                handle  to either  binary or  text. The  argument mode must
                have a value of either O_BINARY or O_TEXT, never both.

Return value    setmode returns 0 if successful; on error it returns -1 and
                sets errno to
                        EINVAL  Invalid argument

*---------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC setmode (int fildes, int mode)
{
    int newmode;

    if ((unsigned)fildes >= _nfile)
        return(__IOerror (-EBADF));
    if ((newmode = mode & (O_TEXT | O_BINARY)) == mode &&
        newmode != (int)(O_TEXT | O_BINARY))
    {
        mode = _openfd [fildes];
        _openfd [fildes] = (mode & ~(O_TEXT | O_BINARY)) | newmode;

        return((mode & (O_TEXT | O_BINARY)));
    }
    else
        return(__IOerror (-EINVAL));
}
