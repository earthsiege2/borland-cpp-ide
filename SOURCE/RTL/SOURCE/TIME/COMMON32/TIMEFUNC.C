/*------------------------------------------------------------------------
 * filename - timefunc.c
 *
 * function(s)
 *        _isDst    - determines whether daylight savings is in effect
 *        _totalsec - converts a date to seconds since 1970
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.0  $        */

#if defined(__WIN32__)
#include <ntbc.h>
#endif
#include <time.h>
#include <_time.h>

#define Thursday        4
#define April           4
#define October         10

/*--------------------------------------------------------------------------*

Name            _isDST  -  determines whether daylight savings is in effect

Usage           int  _isDST (unsigned hour,  unsigned yday,
                     unsigned month, unsigned year);

Prototype in    _io.h

Description     Returns non-zero if daylight savings is in effect for
                the given date.

                If month is 0, yday is the day of the year; otherwise yday is
                the day of the month, where month is 1 for Jan, 2 for Feb, etc.
                In either case, yday is zero based.  year is the number of
                years since 1970.

                It is assumed that the caller has called tzset() to fill in
                the timezone info.

Return value    Non-zero if DST is in effect for the given date.

*---------------------------------------------------------------------------*/

int _isDST (unsigned hour, unsigned yday, unsigned month, unsigned year)
{
    unsigned  temp, sunday;

    if (month == 0)                 /* if only day of year given    */
    {
        temp = yday;
        if (yday >= 31+28 && ( ((year+70) & 3) == 0))
            temp--;
        for (month = 0; temp >= (unsigned)_YDays[month]; month++)
            ;
    }
    else                            /* if month+day of month given  */
    {
        yday += _YDays[month-1];
        if (month > 2 && ( ((year+70) & 3) == 0))   /* leap year, Mar-Dec */
            yday++;
    }

    /* Weed out months other than April or October.
     */
    if (month < April || month > October)
        return (0);
    if (month > April && month < October)
        return (1);

    /* Month is either April or October.  Up through 1986, the starting
     * day for DST is the last Sunday in April; after that it is
     * the first Sunday in April.  The last day of DST is the last Sunday
     * in October.
     */
    if (year > 16 && month == April)    /* if April and year > 1986 */
        sunday = _YDays[month-1] + 7;   /* day = 7th day in month */
    else
        sunday = _YDays[month];         /* day = last day in month */
    if ((year + 70) & 3)                /* leap year ? */
        sunday--;                       /* no --> adjust */

    /* Adjust the threshold day downward to the preceding Sunday.
     */
    temp = sunday + ((year + 1) >> 2)   /* add leap days since 1970 */
           + (year * 365)                 /* add years since 1970 */
           + Thursday;                    /* 01-01-70 was Thursday */
    sunday -= temp % 7;                 /* back up to Sunday */

    /* Check if the day falls within the limit.
     */
    if (month == April)
    {
        if (yday > sunday)
            return (1);
        if (yday < sunday)
            return (0);
        return (hour >= 2);         /* DST started at 2:00 AM */
    }
    else
    {
        if (yday < sunday)
            return (1);
        if (yday > sunday)
            return (0);
        return (hour <= 1);         /* DST ended at 2:00 AM */
    }
}

/*------------------------------------------------------------------------*
Name            _totalsec - convert a date to seconds since 1970

Usage           #include <_io.h>
                unsigned long _totalsec
                    (int year, int month, int day, int hour, int min, int sec);

Protype         _io.h

Description     Converts a broken-down date to the number of seconds elapsed
                since year 70 (1970) in calendar time.  All arguments are
                zero based, except for the year, which is the number of years
                since 1900.

Return value    The time in seconds since 1/1/1970 GMT.

*---------------------------------------------------------------------------*/

unsigned long _totalsec
(int year, int month, int day, int hour, int min, int sec)
{
    int leaps;
    time_t days, secs;

    if (year < 70 || year > 138)
        return ((time_t) -1);

    min += sec / 60;
    sec %= 60;              /* Seconds are normalized */
    hour += min / 60;
    min %= 60;              /* Minutes are normalized */
    day += hour / 24;
    hour %= 24;             /* Hours are normalized   */

    year += month / 12;     /* Normalize month (not necessarily final) */
    month %= 12;

    while (day >= _Days[month])
    {
        if (!(year & 3) && (month ==1))
        {
            if (day > 28)
            {
                day -= 29;
                month++;
            }
            else
                break;
        }
        else
        {
            day -= _Days[month];
            month++;
        }

        if (month >= 12)    /* Normalize month */
        {
            month -= 12;
            year++;
        }
    }

    year -= 70;
    leaps = (year + 2) / 4;

    if (!((year+70) & 3) && (month < 2))
        --leaps;

    days = year*365L + leaps + _YDays[month] + day;

    secs = days*86400L + hour*3600L + min*60L + sec + _timezone;

    if (_daylight && _isDST(hour, day, month+1, year))
        secs -= 3600;

    return(secs > 0 ? secs : (time_t) -1);
}

