/*------------------------------------------------------------------------
 * filename - ftime.c
 *
 * function(s)
 *        ftime - Get current time and store it in 'timeb' structure
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1991, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>

#include <time.h>
#include <_time.h>
#include <sys\timeb.h>

/*---------------------------------------------------------------------*

Name            ftime - Get current time and store it in 'timeb' structure

Usage           void ftime(struct timeb *TimeStructPtr);

Prototype in    sys\timeb.h

Description     ftime determines the current time and fills in the fields
                in the timeb structure pointed to by TimeStructPtr.

*---------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC ftime(struct timeb *TimeStructPtr)
{
    SYSTEMTIME date;

    GetLocalTime(&date);

    /* Convert extern 'timezone's seconds to structure 'timezone's minutes.
     * Set daylight savings indicator.
     * Convert NT date and time to UNIX style time and store in structure.
     */
    TimeStructPtr->timezone = (short)(_timezone / 60L);
    TimeStructPtr->dstflag  = _daylight && _isDST( date.wHour, date.wDay,
                                 date.wMonth, date.wYear-1970);

    TimeStructPtr->time = (long)_totalsec((date.wYear - 1900), date.wMonth-1,
                                        date.wDay-1, date.wHour, date.wMinute,
                                        date.wSecond);
    TimeStructPtr->millitm  = date.wMilliseconds;
}
