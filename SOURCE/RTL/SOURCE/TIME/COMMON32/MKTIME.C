/*------------------------------------------------------------------------
 * filename - mktime.c
 *
 * function(s)
 *    mktime    - normalizes the date and time structure
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <time.h>
#include <_time.h>

time_t _RTLENTRY _EXPFUNC mktime(struct tm *t)
{
    time_t secs;

    secs = _totalsec(t->tm_year, t->tm_mon, t->tm_mday-1, t->tm_hour,
                     t->tm_min, t->tm_sec);

    if (secs != (time_t) -1)
        *t = *localtime(&secs);

    return(secs);
}
