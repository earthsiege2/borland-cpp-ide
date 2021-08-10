/*---------------------------------------------------------------------------
 * filename - delay.c
 *
 * function(s)
 *        delay - wait for specified period.
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>

/*--------------------------------------------------------------------------*

Name            delay - wait for specified period.

Usage           void delay(unsigned milliseconds);

Prototype in    dos.h

Description     The current thread of execution is suspended for the specified
                number of milliseconds.

Return value    None
*---------------------------------------------------------------------------*/

void _RTLENTRYF delay( unsigned milliseconds )
{
    Sleep(milliseconds);
}
