/*------------------------------------------------------------------------
 * filename - getinfo3.c
 *
 * function(s)
 *      _getLocaleEra - return the current era for the date specified
 *
 *
 *
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1998, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <ntbc.h>
#include <winnls.h>
#include <locale.h>
#include <_locale.h>

/*
  Get the current era for the date specified
  return 0 if success or the number of needed chars if failed.
*/
int _getLocaleEra(char* buf, int bufsize, const struct tm *t )
{
    SYSTEMTIME st;
    int result;

    st.wYear      = (WORD) t->tm_year + 1900;
    st.wMonth     = (WORD) t->tm_mon;
    st.wDayOfWeek = (WORD) t->tm_wday;
    st.wDay       = (WORD) t->tm_mday;
    st.wHour      = (WORD) t->tm_hour;
    st.wMinute    = (WORD) t->tm_min;
    st.wSecond    = (WORD) t->tm_sec;
    st.wMilliseconds = 0;

    if ((result = GetDateFormat(__locale->handle, DATE_USE_ALT_CALENDAR, &st, "gg", &buf[0], 0)) > bufsize)
        return result;
    else
    {
        GetDateFormat(__locale->handle, DATE_USE_ALT_CALENDAR, &st, "gg", &buf[0], bufsize);
        return 0;
    }
}
