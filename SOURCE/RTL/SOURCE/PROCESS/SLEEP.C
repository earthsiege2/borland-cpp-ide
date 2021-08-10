/*-----------------------------------------------------------------------*
 * filename - sleep.c
 *
 * function(s)
 *        _sleep - suspends execution for interval
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1991, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.5.2.1 $        */

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

/* This version is obsolete and shouldn't be used anymore */
void _RTLENTRY _EXPFUNC sleep(unsigned seconds)
{
    _sleep (seconds);
}
