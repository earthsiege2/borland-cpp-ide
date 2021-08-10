/*------------------------------------------------------------------------
 * filename - tzset.c
 *
 * function(s)
 *        tzset     - UNIX time compatibility
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.8  $        */

#if defined(__WIN32__)
#include <ntbc.h>
#endif

#include <time.h>
#include <_time.h>
#include <_ctype.h>
#include <stdlib.h>
#include <string.h>
#include <_tchar.h>

#define Normal          0
#define Daylight        1
#define TZstrlen        3               /* Len of tz string(- null terminator) */
#define DefaultTZname   _TEXT("EST")    /* Default normal time zone name */
#define DefaultDSTname  _TEXT("EDT")    /* Default daylight savings zone name */

#define  issign(c)   (((c) == _TEXT('-')) || ((c) == _TEXT('+')))

/*----------------------------------------------------------------------
 * Public variables
 */
static _TCHAR _tDfltZone[ TZstrlen+1 ], _tDfltLight[ TZstrlen+1 ];

_TCHAR * const _RTLENTRY _EXPDATA _ttzname[2] = {&_tDfltZone[0], &_tDfltLight[0]};

/*---------------------------------------------------------------------*

Name            _ttzset used as _tzset and _wtzset

Usage           void tzset(void);
                void _wtzset(void);

Prototype in    time.h

Description     sets local timezone info base on the "TZ" environment string

Return value    None

*---------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC _ttzset(void)
{
#ifndef _UNICODE
#pragma startup tzset 30
#else
#pragma startup _wtzset 30
#endif

    register int  i;       /* A loop index */
    _TCHAR *env;           /* Pointer to "TZ" environment string */

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
/* 1. */ ((env = _tgetenv(_TEXT("TZ"))) == 0)                                       ||
/* 2. */ (_tcslen(env) < (TZstrlen+1))                                              ||
/* 3. */ ((!_istalpha(env[0])) || (!_istalpha(env[1])) || (!_istalpha(env[2])))     ||
/* 4a.*/ (!(issign(env[ TZstrlen ]) || _istdigit(env[ TZstrlen ])))                 ||
/* 4b.*/ ((!_istdigit(env[ TZstrlen ])) && (!_istdigit(env[ TZstrlen+1 ]))) )
    {
        /*----- Missing or bogus "TZ" string, set default values -----*/

#if defined(__WIN32__)
        TIME_ZONE_INFORMATION tzi;

        GetTimeZoneInformation(&tzi);
        _daylight = (tzi.DaylightBias !=0);
        _timezone = (tzi.Bias + tzi.StandardBias) * 60;
        _tcscpy(_ttzname[Normal], _TEXT(""));
        _tcscpy(_ttzname[Daylight], _TEXT(""));
#else
        _daylight = DefaultDaylight;
        _timezone = DefaultTimeZone * 60L * 60L;
        _tcscpy(_ttzname[Normal], DefaultTZname);
        _tcscpy(_ttzname[Daylight], DefaultDSTname);
#endif
    }
    else    /*----- Parse the "TZ" string and set values from string -----*/
    {
        memset(_ttzname[Daylight], 0, (TZstrlen+1)*sizeof(_TCHAR)); /* Dlt daylight to NULL  */
        _tcsncpy(_ttzname[Normal], env, TZstrlen);  /* Set zime zone string  */
        _ttzname[Normal][TZstrlen] = _TEXT('\0');   /* Force NULL termination*/

        _timezone = _ttol(&env[TZstrlen]) * 3600L; /* Base timezone on "TZ" */

        /*----- Scan for optional daylight savings field -----*/

        /* Scan for string start  */
        for (_daylight=0,i=TZstrlen; env[i]; i++)
        {
            if (_istalpha(env[i]))        /* Found the string start */
            {
                if ((_tcslen(&env[i]) < TZstrlen) ||
                    (!_istalpha(env[i+1]))        ||
                    (!_istalpha(env[i+2])) )
                    break;
                /* Copy and null-terminate dlt sav string */
                _tcsncpy(_ttzname[Daylight], &env[i], TZstrlen);
                _ttzname[Daylight][TZstrlen] = _TEXT('\0');
                _daylight = 1;
                break;
            }
        }
    }
}

