/*------------------------------------------------------------------------
 * filename - systime.c
 *
 * function(s)
 *    _getsystime    - MSC compatible time routines
 *    _setsystime    - MSC compatible time routines
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1999, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#define INCL_USER
#include <ntbc.h>
#include <time.h>

/* MSC compatible get/set time/date functions. */

unsigned int _RTLENTRY _EXPFUNC _getsystime(struct tm *__timeptr)
{
    SYSTEMTIME st;

    /* First, get the current local time */

    GetLocalTime (&st);

    /* Then fill up the user's struct tm */

    __timeptr->tm_wday  = st.wDayOfWeek;
    __timeptr->tm_year  = st.wYear-1900;
    __timeptr->tm_mon   = st.wMonth-1;
    __timeptr->tm_mday  = st.wDay;
    __timeptr->tm_hour  = st.wHour;
    __timeptr->tm_min   = st.wMinute;
    __timeptr->tm_sec   = st.wSecond;
    __timeptr->tm_isdst = -1;  /* mktime() will fill this in for us */

    /* Let mktime() adjust any incorrect fields */

    mktime (__timeptr);

    return st.wMilliseconds;
}


unsigned int _RTLENTRY _EXPFUNC _setsystime(struct tm *__timeptr, unsigned int __ms)
{
    SYSTEMTIME st;

    /* First, let mktime() adjust any incorrect fields */

    mktime (__timeptr);

    /* Then build up the SYSTEMTIME instance */

    st.wYear         = (WORD)(__timeptr->tm_year+1900);
    st.wMonth        = (WORD)(__timeptr->tm_mon+1);
    st.wDay          = (WORD) __timeptr->tm_mday;
    st.wHour         = (WORD)(__timeptr->tm_hour);
    st.wMinute       = (WORD) __timeptr->tm_min;
    st.wSecond       = (WORD) __timeptr->tm_sec;
    st.wMilliseconds = (WORD) __ms;

    /* Finally, set the system time */

    if (SetLocalTime (&st) == FALSE)
    {
        return GetLastError ();
    }

    return 0;
}
