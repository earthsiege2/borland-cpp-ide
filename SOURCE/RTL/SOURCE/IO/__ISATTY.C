/*-----------------------------------------------------------------------*
 * filename - __isatty.c
 *
 * function(s)
 *        __isatty - checks for device type
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1991, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

#include <ntbc.h>

#include <_io.h>
#include <io.h>

/*-----------------------------------------------------------------------*

Name            __isatty - checks for device type

Usage           int __isatty(int handle);

Prototype in    _io.h

Description     __isatty is a function that determines whether handle
                represents any one of the following character devices:
                    - a terminal
                    - a console
                    - a printer
                    - a serial port

Return value    If  the  device is character device, __isatty returns a
                non-zero integer. If it is not such a device, __isatty
                returns 0.

*------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC __isatty(int handle)
{
    if ((unsigned)handle >= _nfile)
        return 0;

    return (GetFileType((HANDLE)_handles[handle]) == FILE_TYPE_CHAR);
}


/*-----------------------------------------------------------------------*

Name            __isatty_osfhandle - checks for device type (raw OS handle)

Usage           int __isatty(long handle);

Prototype in    _io.h

Description     see __isatty

Return value    If  the  device is character device, returns a non-zero
		integer. If it is not such a device, returns 0.

*------------------------------------------------------------------------*/
int _RTLENTRY _EXPFUNC __isatty_osfhandle(long handle)
{
    return (GetFileType((HANDLE)handle) == FILE_TYPE_CHAR);
}
