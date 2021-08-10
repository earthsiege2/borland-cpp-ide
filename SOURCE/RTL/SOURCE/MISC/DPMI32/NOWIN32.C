/*---------------------------------------------------------------------------
 * filename - nowin32.c
 *
 * function(s)
 *    __disallowDPMI32onWin32 - disallows DPMI32 module execution on Win32.
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1994, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <_ostype.h>

extern void _ErrorExit(const char *msg);

void __disallowDPMI32onWin32(void)
{
#pragma startup __disallowDPMI32onWin32 2

    if  (_ostype != _DOS32) 
        _ErrorExit("This DPMI32 module cannot be run on Win32");
}

