/*-----------------------------------------------------------------------*
 * filename - strdate.c
 *
 * function(s)
 *        _strdate - gets system date string
 *        _strtime - gets system time string
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>

#include <time.h>

/*---------------------------------------------------------------------*

Name         makedate - make a date or time string

Usage        char *makedate(char *str,int one,int two,int three,
                           char sep);

Description  Makes a date or time string in the form xxsyysz,
             where xx, yy, and zz are two digit decimal representations
             of the parameters one, two, and three, respectively,
             and s is the separator character sep.  The string
             is terminated by a null

Return value The value of str.

*---------------------------------------------------------------------*/

static char *makedate(char *str, int one, int two, int three, char sep)
{
    str[2] = str[5] = sep;
    str[8] = '\0';
    str[0] = (char)(((one / 10) % 10) + '0');
    str[1] = (char)((one % 10) + '0');
    str[3] = (char)(((two / 10) % 10) + '0');
    str[4] = (char)((two % 10) + '0');
    str[6] = (char)(((three / 10) % 10) + '0');
    str[7] = (char)((three % 10) + '0');
    return (str);
}

/*---------------------------------------------------------------------*

Name          _strdate - copies system date to a string buffer

Usage         #include <time.h>
              char *_strdate(char *datestr);

Prototype in  time.h

Description   _strdate copies the current system date to a buffer
              pointed to by datestr, in the following format:

              mm/dd/yy

              where mm is two digits representing the month, dd is two
              digits representing the day, and yy is two digits
              representing the year. The string thus formed is
              terminated by a null character.
              The buffer must be at least 9 bytes long.

Return value  The value of datestr.

              Note  Compatible with Microsoft C.

*---------------------------------------------------------------------*/

char * _RTLENTRY _EXPFUNC _strdate(char *datestr)
{
    SYSTEMTIME dt;

    GetSystemTime(&dt);
    return (makedate(datestr,(int)dt.wMonth,(int)dt.wDay, 
                             (int)dt.wYear-1900, '/'));
}

/*---------------------------------------------------------------------*

Name          _strtime - copies system time to a string buffer

Usage         #include <time.h>
              char *_strtime(char *timestr);

Prototype in  time.h

Description   _strtime copies the current system time to a buffer
              pointed to by timestr, in the following format:

              hh/mm/ss

              where hh is two digits representing the hour, mm is two
              digits representing the minutes, and yy is two digits
              representing the seconds. The string thus formed is
              terminated by a null character.
              The buffer must be at least 9 bytes long.

Return value  The value of timestr.

              Note  Compatible with Microsoft C.

*---------------------------------------------------------------------*/

char * _RTLENTRY _EXPFUNC _strtime(char *timestr)
{
    SYSTEMTIME dt;

    GetSystemTime(&dt);
    return (makedate(timestr, (int)dt.wHour, (int)dt.wMinute, 
                              (int)dt.wSecond, ':'));
}
