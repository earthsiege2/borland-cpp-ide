/*-----------------------------------------------------------------------*
 * filename - dosgdate.c
 *
 * function(s)
 *        _dos_getdate - gets system date
 *        _dos_gettime - gets system time
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1991, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>
#include <dos.h>

/*---------------------------------------------------------------------*

Name            _dos_getdate - gets system date

Usage           #include <dos.h>
                void _dos_getdate(struct dosdate_t *dateblk);

Prototype in    dos.h

Description     _dos_getdate fills in the dosdate_t structure (pointed to by
                dateblk) with the system's current date.

                The dosdate_t structure is defined as follows:

                struct dosdate_t {
                        unsigned char day;      (* 1-31 *)
                        unsigned char month;    (* 1-12 *)
                        unsigned int  year;     (* 1980 - 2099 *)
                        unsigned char dayofweek;(* 0 - 6 (0=Sunday) *)
                };

Return value    nothing

Note            Compatible with Microsoft C.  Not the same as getdate().

*---------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC _dos_getdate(struct dosdate_t *datep)
{
    SYSTEMTIME d;

    GetLocalTime(&d);
    datep->dayofweek = d.wDayOfWeek;
    datep->day = d.wDay;
    datep->month = d.wMonth;
    datep->year = d.wYear;
}

/*---------------------------------------------------------------------*

Name            _dos_gettime - gets system time

Usage           #include <dos.h>
                void _dos_gettime(struct dostime_t *timep);

Prototype in    dos.h

Description     _dos_gettime fills in the dostime_t structure pointed to
                by timep with the system's current time.

                The dostime_t structure is defined as follows:

                struct dostime_t {
                        unsigned char hour;     (* Hours *)
                        unsigned char minute;   (* Minutes *)
                        unsigned char second;   (* Seconds *)
                        unsigned char hsecond;  (* Hundredths of seconds *)
                };

Return value    nothing

Note            Compatible with Microsoft C.  Not the same as gettime().

*---------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC _dos_gettime(struct dostime_t *timep)
{
    SYSTEMTIME d;

    GetLocalTime(&d);
    timep->hour = d.wHour;
    timep->minute = d.wMinute;
    timep->second = d.wSecond;
    timep->hsecond = d.wMilliseconds / 10;
}
