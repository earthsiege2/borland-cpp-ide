/*-----------------------------------------------------------------------*
 * filename - strdate.c
 *
 * function(s)
 *        _strdate - gets system date string
 *        _strtime - gets system time string
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.3  $        */

#include <ctype.h>
#include <tchar.h>
#include <ntbc.h>

#include <time.h>

/*---------------------------------------------------------------------*

Name         makedate - make a date or time string

Usage        _TCHAR *makedate(_TCHAR *str,int one,int two,int three,
                              _TCHAR sep);

Description  Makes a date or time string in the form xxsyysz,
             where xx, yy, and zz are two digit decimal representations
             of the parameters one, two, and three, respectively,
             and s is the separator character sep.  The string
             is terminated by a null

Return value The value of str.

*---------------------------------------------------------------------*/

static _TCHAR *makedate(_TCHAR *str, int one, int two, int three, _TCHAR sep)
{
    str[2] = str[5] = sep;
    str[8] = _TEXT('\0');
    str[0] = (_TCHAR)(((one / 10) % 10) + _TEXT('0'));
    str[1] = (_TCHAR)((one % 10) + _TEXT('0'));
    str[3] = (_TCHAR)(((two / 10) % 10) + _TEXT('0'));
    str[4] = (_TCHAR)((two % 10) + _TEXT('0'));
    str[6] = (_TCHAR)(((three / 10) % 10) + _TEXT('0'));
    str[7] = (_TCHAR)((three % 10) + _TEXT('0'));
    return (str);
}

/*---------------------------------------------------------------------*

Name          _tstrdate used as:
              _strdate 
              _wstrdate - copies system date to a string buffer

Usage         #include <time.h>
              char    *_strdate(char *datestr);
              wchar_t *_wstrdate(wchar_t *datestr);

Prototype in  time.h

Description   Copies the current system date to a buffer
              pointed to by datestr, in the following format:

              mm/dd/yy

              where mm is two digits representing the month, dd is two
              digits representing the day, and yy is two digits
              representing the year. The string thus formed is
              terminated by a null character.
              The buffer must be at least 9 (wide) chars long.

Return value  The value of datestr.

              Note  Compatible with Microsoft C.

*---------------------------------------------------------------------*/

_TCHAR * _RTLENTRY _EXPFUNC _tstrdate(_TCHAR *datestr)
{
    SYSTEMTIME dt;

    GetLocalTime(&dt);
    return (makedate(datestr,(int)dt.wMonth,(int)dt.wDay, 
                             (int)dt.wYear-1900, _TEXT('/')));
}

/*---------------------------------------------------------------------*

Name          _tstrtime used as:
              _strtime
              _wstrtime - copies system time to a string buffer

Usage         #include <time.h>
              char    *_strtime(char *timestr);
              wchar_t *_wstrtime(wchar_t *timestr);

Prototype in  time.h

Description   Copies the current system time to a buffer
              pointed to by timestr, in the following format:

              hh/mm/ss

              where hh is two digits representing the hour, mm is two
              digits representing the minutes, and yy is two digits
              representing the seconds. The string thus formed is
              terminated by a null character.
              The buffer must be at least 9 (wide) chars long.

Return value  The value of timestr.

              Note  Compatible with Microsoft C.

*---------------------------------------------------------------------*/

_TCHAR * _RTLENTRY _EXPFUNC _tstrtime(_TCHAR *timestr)
{
    SYSTEMTIME dt;

    GetLocalTime(&dt);
    return (makedate(timestr, (int)dt.wHour, (int)dt.wMinute, 
                              (int)dt.wSecond, _TEXT(':')));
}
