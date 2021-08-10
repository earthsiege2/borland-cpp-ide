/*-----------------------------------------------------------------------*
 * filename - getpsp.c
 *
 * function(s)
 *        getpsp - gets the program segment prefix
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#include <dos.h>

/* Don't allow DPMI32 modules on Win32 */
void _RTLENTRY __disallowDPMI32onWin32(void);
#pragma extref __disallowDPMI32onWin32

/*---------------------------------------------------------------------*

Name            getpsp - gets the program segment prefix

Usage           unsigned getpsp(void);

Prototype in    dos.h

Description     getpsp gets the segment address of the program
                segment prefix (the PSP) using DOS call 0x62.

                This call only exists in DOS 3.x. For versions of MS-DOS 2.x
                and 3.x, the global variable _psp  set by the start-up code may
                be used instead.

Return value    getpsp returns the segment value of the PSP.

*---------------------------------------------------------------------*/
unsigned _RTLENTRY getpsp(void)           /* DOS 3.0 */
{
        _AH = 0x62;
        geninterrupt(0x21);
        return(_BX);
}
