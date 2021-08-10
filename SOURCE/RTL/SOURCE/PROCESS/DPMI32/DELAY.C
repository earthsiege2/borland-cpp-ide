/*---------------------------------------------------------------------------
 * filename - delay.c
 *
 * function(s)
 *        delay - wait for specified period.
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

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
