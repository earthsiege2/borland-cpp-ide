/*------------------------------------------------------------------------
 * filename - wcsftime.c
 *
 * function(s)
 *      wcsftime - converts data and time structure to a wide-character string
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1996, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.3  $        */


#include <_io.h>
#include <_printf.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <_locale.h>

size_t _RTLENTRY _EXPFUNC
wcsftime( wchar_t *s, size_t maxsize, const wchar_t *fmt, const struct tm *t )
{
    wchar_t buf[ 255 ];
    wchar_t format[ 255 ];
    char tempbuf[ 255];

    wchar_t *p = buf;
    wchar_t *fp = format;
    char *tp;

    wchar_t pad;
    size_t  i, len;

    for ( len = 1; len < maxsize && *fmt; ++fmt, p = buf )
    {

        if ( *fmt != L'%' )
        {
            ++len;
            *s++ = *fmt;
        }

        else
        {
            wcscpy( buf, L"00" );
            strcpy( tempbuf, "00" );
            tp = 0;
the_switch:
            switch( *++fmt )
            {

            /* abbreviated day */
            case L'a':
                if (t->tm_wday == 0)
                    tp = (char *) _getLocaleTimeInfo(LOCALE_SABBREVDAYNAME7);
                else
                    tp = (char *) _getLocaleTimeInfo(LOCALE_SABBREVDAYNAME1 + t->tm_wday - 1);
                break;

            /* full day */
            case L'A':
                if (t->tm_wday == 0)
                    tp = (char *) _getLocaleTimeInfo(LOCALE_SDAYNAME7);
                else
                    tp = (char *) _getLocaleTimeInfo(LOCALE_SDAYNAME1 + t->tm_wday - 1);
                break;

            /* abbreviated month */
            case L'b':
            case L'h':   /* POSIX  */
                tp = (char *) _getLocaleTimeInfo(LOCALE_SABBREVMONTHNAME1 + t->tm_mon);
                break;

            /* full month */
            case L'B':
                tp = (char *) _getLocaleTimeInfo(LOCALE_SMONTHNAME1 + t->tm_mon);
                break;

            /* date and time */
            case L'c':
                /* set p to current s position */
                p = s;

                /* recurse */
                wcsftime( p, maxsize, L"%x %X", t );
                break;

            /* month date */
            case L'd':
                __utow( t->tm_mday, p + (t->tm_mday < 10));
                break;

            case L'g':
                tp = tempbuf;
                strcpy(tp, "");
                _getLocaleEra(tp, sizeof(tempbuf), t);
                break;

            /* hour (24) */
            case L'H':
                __utow( t->tm_hour, p + (t->tm_hour < 10));
                break;

            /* hour (12) */
            case L'I':
                i = t->tm_hour % 12;

                if (i == 0)
                    i = 12;

                __utow( i, p + (i < 10) );
                break;

            /* year day */
            case L'j':
                i = t->tm_yday + 1;

                __utow( i, p + (i < 10) + (i < 100) );
                break;

            /* month */
            case L'm':
                i = t->tm_mon + 1;

                __utow( i, p + (i < 10) );
                break;

            /* minute */
            case L'M':
                __utow( t->tm_min, p + (t->tm_min < 10) );
                break;

            /* am/pm */
            case L'p':
                if (t->tm_hour / 12 > 0)
                    tp = (char *) _getLocaleTimeInfo(LOCALE_S2359);
                else
                    tp = (char *) _getLocaleTimeInfo(LOCALE_S1159);

                break;

            /* seconds */
            case L'S':
                __utow( t->tm_sec, p + (t->tm_sec < 10) );
                break;

            /* week of year (Sunday) */
            case L'U':
                // Adjust weekday to be positive (first week) Sunday
                // based
                i = (t->tm_wday + 7) % 7;

                // Adjust week to be positive (first week)
                i = (t->tm_yday - i + 7) / 7;

                __utow( i, p + (i < 10) );
                break;

            /* day of week */
            case L'w':
                __utow( t->tm_wday, p );

                break;

            /* week of year (Monday) */
            case L'W':
                // Adjust weekday to be positive (first week) Monday
                // based
                i = (t->tm_wday + 6) % 7;

                // Adjust week to be positive (first week)
                i = (t->tm_yday - i + 6) / 7;

                __utow( i, p + (i < 10) );
                break;

            /* date */
            case L'x':
            case L'D':       /* POSIX */
                /* set p to current s position */
                p = s;

                /* recurse */
                tp = (char *) _getLocaleTimeInfo(LOCALE_SSHORTDATE);
                mbstowcs(fp, tp, sizeof(format));
                tp = 0;
                wcsftime( p, maxsize, fp, t );
                break;

            /* time */
            case L'X':
                /* set p to current s position */
                p = s;

                /* recurse */
                tp = (char *) _getLocaleTimeInfo(LOCALE_STIMEFORMAT);
                mbstowcs(fp, tp, sizeof(format));
                tp = 0;
                wcsftime( p, maxsize, fp, t );
                break;

            /* year (no century) */
            case L'y':
                i = t->tm_year % 100;

                __utow( i, p + (i < 10) );
                break;

            /* year (with century) */
            case L'Y':
                __utow( 1900 + t->tm_year, p );
                break;

            /* century */
            case L'C':       /* POSIX */
                __utow( 19, p );
                break;

            case L'+' :
                pad = *++fmt;
                buf[0] = pad;
                buf[1] = pad;
                goto the_switch;


           /* time zone */
            case L'Z':
               p = _wtzname[ t->tm_isdst ];
               break;

            /* literally "%" */
            case L'%':
                p = L"%";
                break;

            case L'#':
            	switch( *++fmt )
                {

                case  L'c' :
                    tp = (char *) _getLocaleTimeInfo(LOCALE_SLONGDATE);
                    mbstowcs(fp, tp, sizeof(format));
                    tp = 0;
                    wcscat ( fp, L" %X");
                    wcsftime( p, maxsize, fp, t );
                    break;

                case L'x' :
                    tp = (char *) _getLocaleTimeInfo(LOCALE_SLONGDATE);
                    mbstowcs(fp, tp, sizeof(format));
                    tp = 0;
                    wcsftime( p, maxsize, fp, t );
                    break;

                default :
                	break;

                }
                break;
            }

            if (tp)
                mbstowcs(p, tp, maxsize);


            i = min( wcslen( p ), maxsize - len );
            wcsncpy( s, p, i );
            len += i;
            s += i;

        } /* if-else */

    } /* for */

    *s = L'\0';

    if( *fmt )
        return( 0 );
    else
        return( len - 1 );
}
