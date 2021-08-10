/*-----------------------------------------------------------------------*
 * filename - sleep.c
 *
 * function(s)
 *        _sleep - suspends execution for interval
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <ntbc.h>

#include <_defs.h>

/*---------------------------------------------------------------------*

Name            _sleep - suspends execution for interval

Usage           unsigned _sleep(unsigned seconds);

Prototype in    dos.h

Description     With a call to _sleep, the current thread is
                suspended from execution for the number of seconds specified
                by the argument seconds. The interval is only accurate to
                the nearest NT clock tick.

Return value    None

*---------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC _sleep(unsigned seconds)
{
    Sleep((DWORD)seconds * 1000L);
}

