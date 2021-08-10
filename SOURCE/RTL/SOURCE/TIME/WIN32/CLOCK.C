/*-----------------------------------------------------------------------*
 * filename - clock.c
 *
 * function(s)
 *      clock       - ANSI standard; returns number of timer ticks
 *                    that have elapsed since this program started.
 *      _init_clock - get starting millisecond counter
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

#include <time.h>

/*----------------------------------------------------------------------
 * Value of NT millisecond counter at program startup.
 */
static DWORD _StartTime = 0;

/*---------------------------------------------------------------------*

Name            clock - determines processor time

Usage           clock_t clock(void);

Related
functions usage time_t time(time_t *tp);

Prototype in    time.h

Description     clock can be used to determine the time interval
                between two events.

                To determine the time in seconds, the value returned
                by clock should be divided by the value of the macro
                CLK_TCK.

Return value    The clock function returns the processor time elapsed
                since the beginning of the program invocation.  If the
                processor time is not available, or its value cannot
                be represented, the function returns the value -1.

*---------------------------------------------------------------------*/

clock_t _RTLENTRY _EXPFUNC  clock(void)
{
    return ((clock_t)(GetTickCount() - _StartTime));
}

/*---------------------------------------------------------------------*

Name            _init_clock - get starting millisecond counter

Usage           void _init_clock(void);

Prototype in

Description     Set _StartTime to the current value of the NT
                millsecond timer.  This function is called
                at startup time if the program uses clock().

Return value    None.

*---------------------------------------------------------------------*/

static void _RTLENTRY _init_clock()
{
#pragma startup _init_clock 0

    /* Initialize the starting millisecond counter.
     */
    _StartTime = clock();
}
