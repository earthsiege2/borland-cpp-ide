/*-----------------------------------------------------------------------*
 * filename - getdate.c
 *
 * function(s)
 *        getdate - gets system date
 *        gettime - gets system time
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>

#include <dos.h>

/*---------------------------------------------------------------------*

Name            getdate - gets system date

Usage           #include <dos.h>
                void getdate(struct date *dateblk);

Prototype in    dos.h

Description     getdate fills in the date structure (pointed to by
                dateblk) with the system's current date.

                The date structure is defined as follows:

                struct date {
                        int da_year;    (* Current year *)
                        char da_day;    (* Day of the month *)
                        char da_mon;    (* Month (1 = Jan) *)
                };

Return value    nothing

*---------------------------------------------------------------------*/

void _RTLENTRYF _EXPFUNC getdate(struct date *datep)
{
    SYSTEMTIME d;

    GetLocalTime(&d);

    datep->da_day  = d.wDay;
    datep->da_mon  = d.wMonth;
    datep->da_year = d.wYear;
}

/*---------------------------------------------------------------------*

Name            gettime - gets system time

Usage           #include <dos.h>
                void gettime(struct time *timep);

Prototype in    dos.h

Description     gettime fills in the time structure pointed to by timep
                with the system's current local time.

                The time structure is defined as follows:

                struct time {
                        unsigned char ti_min;   (* Minutes *)
                        unsigned char ti_hour;  (* Hours *)
                        unsigned char ti_hund;  (* Hundredths of seconds *)
                        unsigned char ti_sec;   (* Seconds *)
                };

Return value    nothing

*---------------------------------------------------------------------*/

void _RTLENTRYF _EXPFUNC gettime(struct time *timep)
{
    SYSTEMTIME d;

    GetLocalTime(&d);

    timep->ti_hour = d.wHour;
    timep->ti_min  = d.wMinute;
    timep->ti_sec  = d.wSecond;
    timep->ti_hund = d.wMilliseconds/10;
}
