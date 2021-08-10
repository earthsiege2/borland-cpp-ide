/*-----------------------------------------------------------------------*
 * filename - __isatty.c
 *
 * function(s)
 *        __isatty - checks for device type
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

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

int _RTLENTRY __isatty(int handle)
{
    if ((unsigned)handle >= _nfile)
        return 0;

    return (GetFileType((HANDLE)_handles[handle]) == FILE_TYPE_CHAR);
}
