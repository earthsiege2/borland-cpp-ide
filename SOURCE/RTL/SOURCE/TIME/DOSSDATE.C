/*-----------------------------------------------------------------------*
 * filename - dossdate.c
 *
 * function(s)
 *        _dos_setdate - sets system date
 *        _dos_settime - sets system time
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
#include <_io.h>
#include <dos.h>
#include <errno.h>


/*---------------------------------------------------------------------*

Name            _dos_setdate - sets system date

Usage           #include <dos.h>
                unsigned _dos_setdate(struct dosdate_t *dateblk);

Prototype in    dos.h

Description     _dos_setdate the system's current date using the values
                in the dosdate_t structure (pointed to by dateblk).

                The dosdate_t structure is defined as follows:

                struct dosdate_t {
                        unsigned char day;      (* 1-31 *)
                        unsigned char month;    (* 1-12 *)
                        unsigned int  year;     (* 1980 - 2099 *)
                        unsigned char dayofweek;(* 0 - 6 (0=Sunday) *)
                };

Return value    If sucess, returns 0.  Otherwise, returns non-zero
                and sets errrno:

                        EINVAL  Invalid date

Note            Compatible with Microsoft C.  Not the same as setdate().

*---------------------------------------------------------------------*/

unsigned _RTLENTRY _EXPFUNC _dos_setdate(struct dosdate_t *datep)
{
    SYSTEMTIME d;

    /* Check for boundaries that Win32 doesn't do for us
     */
    if (((int)datep->dayofweek > 6) || ((int)datep->dayofweek < 0))
        return (__IOerror(-EINVAL));

    if (datep->year > 2099)
        return (__IOerror(-EINVAL));

    /* Get current time so that the time will be preserved.
     */
    GetLocalTime(&d);

    /* Convert the dosdate_t structure to SYSTEMTIME and set the date.
     */
    d.wDayOfWeek = datep->dayofweek;
    d.wDay       = datep->day;
    d.wMonth     = datep->month;
    d.wYear      = datep->year;

    if (SetLocalTime(&d) == 0)
        return (__NTerror());

    return 0;
}

/*---------------------------------------------------------------------*

Name            _dos_settime - sets system time

Usage           #include <dos.h>
                unsigned _dos_settime(struct dostime_t *timep);

Prototype in    dos.h

Description     _dos_settime sets the system's current time to the values
                in the dostime_t structure pointed to by timep.

                The dostime_t structure is defined as follows:

                struct dostime_t {
                        unsigned char hour;     (* Hours *)
                        unsigned char minute;   (* Minutes *)
                        unsigned char second;   (* Seconds *)
                        unsigned char hsecond;  (* Hundredths of seconds *)
                };

Return value    If sucess, returns 0.  Otherwise, returns non-zero
                and sets errrno:

                        EINVAL  Invalid time

Note            Compatible with Microsoft C.  Not the same as settime().

*---------------------------------------------------------------------*/

unsigned _dos_settime(struct dostime_t *timep)
{
    SYSTEMTIME d;

    /* Get current time so that the date will be preserved.
     */
    GetLocalTime(&d);

    /* Convert the dostime_t structure to SYSTEMTIME and set the time.
     */
    d.wHour         = timep->hour;
    d.wMinute       = timep->minute;
    d.wSecond       = timep->second;
    d.wMilliseconds = timep->hsecond;

    if (SetLocalTime(&d) == 0)
        return (__NTerror());
    else
        return 0;
}
