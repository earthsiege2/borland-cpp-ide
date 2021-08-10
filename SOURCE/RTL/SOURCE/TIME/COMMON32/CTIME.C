/*------------------------------------------------------------------------
 * filename - ctime.c
 *
 * function(s)
 *    _atime    - converts date and time to ASCII without trailing '\n'
 *    asctime   - converts date and time to ASCII
 *    ctime     - converts date and time to a string
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#ifdef _MT
#include <_thread.h>
#endif
#include <time.h>
#include <_time.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef _MT

#define ascbuf ((THREAD_TIME *)THREAD_BUF(time,sizeof(THREAD_TIME)))->thread_asctime

#else

static char ascbuf[26];

#endif

/*------------------------------------------------------------------------*

Name            _atime - converts date and time to ASCII without trailing '\n'

Usage           #include <_time.h>
                int _atime( char *dest, const struct tm *tmPtr, char *term );

Prototype       _time.h

Description     Provides the basic formatting capabilities for asctime() and
                strftime( "%c" ).  These two functions both provide an ASCII
                version of the date and time in the struct tm, but asctime()
                adds a newline to the end.  The term parameter contains
                the string to be appended to the end of the time string:
                typically either a newline (asctime) or an empty string
                (strftime).

Return value    none

*---------------------------------------------------------------------------*/

void _atime( char *dest, const struct tm *tmPtr, char *term )
{
    sprintf( dest, "%s %s %02d %02d:%02d:%02d %4d%s",
        _SWeekday[tmPtr->tm_wday],
        _SMonth[tmPtr->tm_mon],
        tmPtr->tm_mday,
        tmPtr->tm_hour,
        tmPtr->tm_min,
        tmPtr->tm_sec,
        tmPtr->tm_year + 1900,
        term
        );

}

/*------------------------------------------------------------------------*

Name            asctime   - converts date and time to ASCII
                ctime     - converts date and time to a string

Usage           #include <time.h>
                char *asctime(struct tm *tmX);
                char *ctime(long *clock);

Prototype in    time.h

Description     asctime  converts  a  time  stored  as  a  structure  to  a
                26-character string in the following form:

                Mon Nov 21 11:31:54 1983\n\0

                All the fields have a constant width.

                ctime converts a time pointed to by clock (such as returned
                by the function time) to  a 26-character string of the form
                described above.

Return value    asctime and ctime return a  pointer to the character string
                containing the date and time. This string is a static which
                is overwritten with each call.

*---------------------------------------------------------------------------*/

char * _RTLENTRY _EXPFUNC asctime(const struct tm *tmPtr)
{
    char *a;

    a = ascbuf;
    _atime(a, tmPtr, "\n");  /* ASCII time + terminating newline */
    return(a);
}

char * _RTLENTRY _EXPFUNC ctime(const time_t *clock)
{
    return(asctime(localtime(clock)));
}
