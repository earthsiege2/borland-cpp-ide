/*------------------------------------------------------------------------
 * filename - tzset.c
 *
 * function(s)
 *        tzset     - UNIX time compatibility
 *        _isDst    - determines whether daylight savings is in effect
 *        _totalsec - converts a date to seconds since 1970
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#if defined(__WIN32__)
#include <ntbc.h>
#endif

#include <time.h>
#include <_time.h>
#include <_ctype.h>
#define ISALPHA(c) iscalpha(c)
#include <stdlib.h>
#include <string.h>

#define YES 1
#define NO  0

#define Normal    0
#define Daylight  1
#define TZstrlen        3        /* Len of tz string(- null terminator) */
#define DefaultTimeZone 5L
#define DefaultDaylight YES
#define DefaultTZname   "EST"    /* Default normal time zone name */
#define DefaultDSTname  "EDT"    /* Default daylight savings zone name */

#define Thursday        4
#define April           4
#define October         10

/*----------------------------------------------------------------------
 * Public variables
 */
static char _DfltZone[ TZstrlen+1 ], _DfltLight[ TZstrlen+1 ];

char * const _RTLENTRY _EXPDATA _tzname[2] = {&_DfltZone[0], &_DfltLight[0]};

long  _RTLENTRY _EXPDATA _timezone = DefaultTimeZone * 60L * 60L; /* Set for EST */

int   _RTLENTRY _EXPDATA _daylight = DefaultDaylight;             /* Apply daylight savings */

/*---------------------------------------------------------------------*

Name            tzset

Usage           void tzset(void);

Prototype in    time.h

Description     sets local timezone info base on the "TZ" environment string

Return value    None

*---------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC tzset(void)
{
#pragma startup tzset 30

    register int  i;       /* A loop index */
    char *env;             /* Pointer to "TZ" environment string */

#define  issign(c)   (((c) == '-') || ((c) == '+'))

    if (
       /************************************************************
          1. Check for "TZ" string in the environment.
                env[0] - 1st char in time zone name
                env[1] - 2nd "    "   "    "
                env[2] - 3rd "    "   "    "
                env[3] - 1st char in time zone difference value
                env[4] - 2nd "    "   "    "       "        "
          2. Rule out short strings.
          3. Rule out non A-Z time zone characters.
          4. Rule out bad time zone difference numbers.
             a. Not a +/- or 0-9.
             b. Sign with no following digit(s).
       ************************************************************/
/* 1. */ ((env = getenv("TZ")) == 0)                                      ||
/* 2. */ (strlen(env) < (TZstrlen+1))                                     ||
/* 3. */ ((!ISALPHA(env[0])) || (!ISALPHA(env[1])) || (!ISALPHA(env[2]))) ||
/* 4a.*/ (!(issign(env[ TZstrlen ]) || isdigit(env[ TZstrlen ])))         ||
/* 4b.*/ ((!isdigit(env[ TZstrlen ])) && (!isdigit(env[ TZstrlen+1 ]))) )
    {
        /*----- Missing or bogus "TZ" string, set default values -----*/

#if defined(__WIN32__)        
        TIME_ZONE_INFORMATION tzi;

        _daylight = (GetTimeZoneInformation(&tzi) == TIME_ZONE_ID_DAYLIGHT);
        _timezone = (tzi.Bias + tzi.StandardBias) * 60;
        strcpy(_tzname[Normal], "");
        strcpy(_tzname[Daylight], "");
#else
        _daylight = DefaultDaylight;
        _timezone = DefaultTimeZone * 60L * 60L;
        strcpy(_tzname[Normal], DefaultTZname);
        strcpy(_tzname[Daylight], DefaultDSTname);
#endif
    }
    else    /*----- Parse the "TZ" string and set values from string -----*/
    {
        memset(_tzname[Daylight], 0, TZstrlen+1); /* Dlt daylight to NULL  */
        strncpy(_tzname[Normal], env, TZstrlen);  /* Set zime zone string  */
        _tzname[Normal][TZstrlen] = '\0';         /* Force NULL termination*/
        _timezone = atol(&env[TZstrlen]) * 3600L; /* Base timezone on "TZ" */

        /*----- Scan for optional daylight savings field -----*/

        /* Scan for string start  */
        for (_daylight=NO,i=TZstrlen; env[i]; i++)
        {
            if (ISALPHA(env[i]))        /* Found the string start */
                {
                if ((strlen(&env[i])<TZstrlen) ||
                                    (!ISALPHA(env[i+1]))       ||
                                    (!ISALPHA(env[i+2])) )
                    break;
                /* Copy and null-terminate dlt sav string */
                strncpy(_tzname[Daylight], &env[i], TZstrlen);
                _tzname[Daylight][TZstrlen] = '\0';
                _daylight = YES;
                break;
            }
        }
    }
}


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
        for (month = 0; temp >= _YDays[month]; month++)
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
        sunday = _YDays[month-1] + 7;/* day = 7th day in month */
    else
        sunday = _YDays[month];      /* day = last day in month */
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
