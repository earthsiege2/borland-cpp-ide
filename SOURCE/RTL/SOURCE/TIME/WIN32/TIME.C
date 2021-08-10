/*-----------------------------------------------------------------------*
 * filename - time.c
 *
 * function(s)
 *        time  - gets time of day
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

/*---------------------------------------------------------------------*

Name            time - gets time of day

Usage           long time(long *tloc);

Related
functions usage int stime(long *tp);

Prototype in    time.h

Description     time retrieves the current time (in seconds, elapsed
                since 00:00:00 GMT, January 1, 1970) and stores that
                value in the location pointed to by tloc.

                stime sets the system time and date.

Return value    time returns the elapsed time, stime returns 0.

*---------------------------------------------------------------------*/

time_t _RTLENTRY _EXPFUNC time(time_t *tloc)
{
    time_t          x;
    SYSTEMTIME st;

    GetLocalTime(&st);
    x = _totalsec(st.wYear-1900, st.wMonth-1, st.wDay-1,
                  st.wHour, st.wMinute, st.wSecond);
    if (tloc)
            *tloc = x;
    return (x);
}
