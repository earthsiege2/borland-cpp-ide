/*-----------------------------------------------------------------------*
 * filename - setdate.c
 *
 * function(s)
 *        setdate - sets system date
 *        settime - sets system time
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.3  $        */

#include <ntbc.h>
#include <errno.h>
#include <_io.h>
#include <dos.h>

/*-----------------------------------------------------------------------*

Name            setdate - sets system date

Usage           #include <dos.h>
                void setdate(struct date *dateblk);

Prototype in    dos.h

Description     see getdate

*------------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC setdate(struct date *datep)
{
    SYSTEMTIME d;

    /* Get current date/time so that the time will be preserved.
     */
    GetLocalTime(&d);

    /* Convert the date structure to a system SYSTEMTIME and set the date.
     */
    d.wDay = datep->da_day;
    d.wMonth = datep->da_mon;
    d.wYear = datep->da_year;
    if (SetLocalTime(&d) == 0)
        __NTerror();
}

/*-----------------------------------------------------------------------*

Name            settime - sets system time

Usage           #include <dos.h>
                void settime(struct time *timeblk);

Prototype in    dos.h

Description     see gettime

*------------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC settime(struct time *timep)
{
    SYSTEMTIME d;

    /* Get current time so that the date and year will be preserved.
     */
    GetLocalTime(&d);

    /* Convert the dostime_t structure to an system SYSTEMTIME and set the time.
     */
    d.wHour = timep->ti_hour;
    d.wMinute = timep->ti_min;
    d.wSecond = timep->ti_sec;
    d.wMilliseconds = timep->ti_hund * 10;
    if (SetLocalTime(&d) == 0)
        __NTerror();
}

