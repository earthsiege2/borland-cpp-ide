/*-----------------------------------------------------------------------*
 * filename - stime.c
 *
 * function(s)
 *        stime - sets time of day
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1991, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <ntbc.h>
#include <_io.h>
#include <time.h>

/*---------------------------------------------------------------------*

Name            stime - sets time

Usage           int stime(long *tp);

Related
functions usage long time(long *tloc);

Prototype in    time.h

Description     see time

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC stime(time_t *tp)
{
    SYSTEMTIME d;
    struct tm *t;

    /* Convert the time_t value to a tm structure.
     */
    t = localtime(tp);

    /* Convert the tm structure to an NT SYSTEMTIME and set the time.
     */
    d.wHour         = t->tm_hour;
    d.wMinute       = t->tm_min;
    d.wSecond       = t->tm_sec;
    d.wMilliseconds = 0;
    d.wDay          = t->tm_mday;
    d.wMonth        = t->tm_mon + 1;
    d.wYear         = t->tm_year + 1900;
    d.wDayOfWeek    = t->tm_wday;
    if (SetLocalTime(&d) == 0)
        return (__NTerror());
    else
        return (0);
}
