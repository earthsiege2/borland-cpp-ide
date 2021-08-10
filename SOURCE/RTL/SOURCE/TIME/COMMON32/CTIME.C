/*------------------------------------------------------------------------
 * filename - ctime.c
 *
 * function(s)
 *    _atime    - converts date and time to ASCII without trailing '\n'
 *    asctime   - converts date and time to ASCII
 *    ctime     - converts date and time to a string
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.5  $        */

#ifdef _MT
#include <_thread.h>
#endif
#include <ctype.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <_tchar.h>
#include <_time.h>

#ifdef _MT

#define ascbuf ((THREAD_TIME *)THREAD_BUF(time,sizeof(THREAD_TIME)))->thread_asctime

#else

static _TCHAR ascbuf[26];

#endif

/*------------------------------------------------------------------------*

Name            _tatime used as:
                _atime
                _watime   - converts date and time to (wide) character
                            without trailing '\n'.

Usage           #include <_time.h>
                int  _atime( char *dest, const struct tm *tmPtr,
                             char *term );
                int _watime( wchar_t *dest, const struct tm *tmPtr,
                             wchar_t *term );

Prototype       _time.h

Description     Provides the basic formatting capabilities for asctime(),
                _wasctime(), strftime( "%c" ) and wcsftime( "%c ).
                These functions provide a (wide) character version of the
                date and time in the struct tm, but asctime() and
                _wasctime() add a newline to the end.  The term parameter
                contains the string to be appended to the end of the time
                string: typically either a newline (asctime, _wasctime) or
                an empty string (strftime, wcsftime).

Return value    none

*---------------------------------------------------------------------------*/
#ifdef _UNICODE
#undef _stprintf
#define _stprintf wsprintfW
#endif

void _tatime( _TCHAR *dest, const struct tm *tmPtr, _TCHAR *term )
{
     _stprintf( dest, _TEXT("%s %s %02d %02d:%02d:%02d %4d%s"),
        _tSWeekday[tmPtr->tm_wday],
        _tSMonth[tmPtr->tm_mon],
        tmPtr->tm_mday,
        tmPtr->tm_hour,
        tmPtr->tm_min,
        tmPtr->tm_sec,
        tmPtr->tm_year + 1900,
        term
        );

}

/*------------------------------------------------------------------------*

Name            _tasctime and _tctime, used as:
                  asctime - converts date and time to ASCII
                _wasctime - converts date and time to wide character
                  ctime   - converts date and time to a string
                _wctime   - converts date and time to a wide char string

Usage           #include <time.h>
                char    *   asctime(struct tm *tmX);
                wchar_t * _wasctime(struct tm *tmX);
                char    *   ctime(long *clock);
                wchar_t * _wctime(long *clock);

Prototype in    time.h

Description     asctime and _wasctime convert a time stored as a structure
                to a 26 (wide) character string in the following form:

                Mon Nov 21 11:31:54 1983\n\0

                All the fields have a constant width.

                ctime and _wctime convert a time pointed to by clock (such
                as returned by the function time) to a 26 (wide) character
                string of the form described above.

Return value    asctime, _wasctime, ctime and _wctime return a pointer to
                the (wide) character string containing the date and time.
                This string is a static which is overwritten with each call.

*---------------------------------------------------------------------------*/

_TCHAR * _RTLENTRY _EXPFUNC _tasctime(const struct tm *tmPtr)
{
    _TCHAR *a;

    a = (_TCHAR*)ascbuf;
    _tatime(a, tmPtr, _TEXT("\n"));  /* ASCII time + terminating newline */
    return(a);
}

_TCHAR * _RTLENTRY _EXPFUNC _tctime(const time_t *clock)
{
    return(_tasctime(localtime(clock)));
}

