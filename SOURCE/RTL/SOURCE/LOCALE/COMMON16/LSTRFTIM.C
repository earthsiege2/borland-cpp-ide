/*------------------------------------------------------------------------
 * filename - lstrftim.c
 *
 * function(s)
 *  _lstrftime  - converts date and time structure to a string according
 *                to the current locale.
 *  _getordinal - convert value into ordinal string representation
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */


#include <_io.h>
#include <_printf.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <RtlData.h>

#define __POSIX__

#ifdef __POSIX__

int _getordinal( unsigned int value, char *dest );

#endif

size_t _FARFUNC _lstrftime( char *s, size_t maxsize, const char *fmt, const struct tm *t )

{
   char buf[ 25 ];

   char *p = buf;
   int i, len;
   int ordinal = 0;
    _QRTLDataBlock;

    for ( len = 1; len < maxsize && *fmt; ++fmt, p = buf )

    {

    if ( *fmt != '%' )
    {
        ++len;
         *s++ = *fmt;
    }

    else
    {

        strcpy( buf, "00" );

the_switch:

        switch( *++fmt )
        {

        /* abbreviated day */
        case 'a':

            p = (char *) &_QRTLInstanceData(_pLocale)->TimeCat.TimeDateInfo.abday[ t->tm_wday ];

            break;

        /* full day */
        case 'A':

            p = (char *) &_QRTLInstanceData(_pLocale)->TimeCat.TimeDateInfo.day[ t->tm_wday ];

            break;

#ifdef __POSIX__

        /* POSIX: abbreviated month */
        case 'h':
#endif

        /* abbreviated month */
        case 'b':

            p = (char *) &_QRTLInstanceData(_pLocale)->TimeCat.TimeDateInfo.abmon[ t->tm_mon ];

            break;

        /* full month */
        case 'B':

            p = (char *) &_QRTLInstanceData(_pLocale)->TimeCat.TimeDateInfo.mon[ t->tm_mon ];

            break;

        /* date and time */
        case 'c':

            /* set p to current s position */
            p = s;

            /* recurse */
            _lstrftime( p, maxsize, (char *) &_QRTLInstanceData(_pLocale)->TimeCat.TimeDateInfo.d_t_fmt, t );

            break;

#ifdef __POSIX__

        /* POSIX: century divided by 100 */
        case 'C':

            i = ( t->tm_year + 1900 ) / 100;

            __utoa( i, buf + (i < 10) );

            break;
#endif

        /* month date */
        case 'd':

            if ( ordinal )
            {
                if ( _getordinal( t->tm_mday, buf ) == 1 )
                    break;
            }

             /* if not ordinal or _getordinal() failed */
             __utoa( t->tm_mday, buf + (t->tm_mday < 10) );

             break;


#ifdef __POSIX__

        /* POSIX: mm/dd/yy */
        case 'D':

            /* set p to current s position */
            p = s;

            /* recurse */
            _lstrftime( p, maxsize, "%m/%d/%y", t );

            break;

        /* POSIX: day of month */
        case 'e':

            i = t->tm_mday;

            if ( i < 10 )
                buf[ 0 ] = ' ';

            if ( ordinal )
            {
                if ( _getordinal( i, buf ) == 1 )
                    break;
            }

             __utoa( i, buf + (i < 10) );

             break;

#endif

        /* hour (24) */
        case 'H':

            if ( ordinal )
            {
                if ( _getordinal( t->tm_hour, buf ) == 1 )
                break;
            }

            /* if not ordinal or _getordinal() failed */
            __utoa( t->tm_hour, buf + (t->tm_hour < 10) );

            break;

        /* hour (12) */
        case 'I':

            i = t->tm_hour % 12;

            if (i == 0)
                i = 12;

            if ( ordinal )
            {
                if ( _getordinal( i, buf ) == 1 )
                    break;
            }

            /* if not ordinal or _getordinal() failed */
            __utoa( i, buf + (i < 10) );

            break;

        /* year day */
        case 'j':

            i = t->tm_yday + 1;

            if ( ordinal )
            {
                if ( _getordinal( i, buf ) == 1 )
                    break;
            }

            /* if not ordinal or _getordinal() failed */
            __utoa( i, buf + (i < 10) + (i < 100) );

            break;

        /* month */
        case 'm':

            i = t->tm_mon + 1;

            if ( ordinal )
            {
                if ( _getordinal( i, buf ) == 1 )
                    break;
            }

            /* if not ordinal or _getordinal() failed */
            __utoa( i, buf + (i < 10) );

            break;

        /* minute */
        case 'M':

            if ( ordinal )
            {
                if ( _getordinal( t->tm_min, buf ) == 1 )
                    break;
            }

            /* if not ordinal or _getordinal() failed */
            __utoa( t->tm_min, buf + (t->tm_min < 10) );

            break;

#ifdef __POSIX__

        /* POSIX: newline character */
        case 'n':
            buf[ 0 ] = '\n';
            buf[ 1 ] = '\0';
            break;

        /* POSIX: ordinal modifier */
        case 'O':

            ordinal = 1;
            goto the_switch;

#endif

        /* am/pm */
        case 'p':

            p = (char *) &_QRTLInstanceData(_pLocale)->TimeCat.TimeDateInfo.am_pm[ t->tm_hour / 12 ];

            break;

#ifdef __POSIX__

        /* POSIX: 12 hour am/pm time format */
        case 'r':

            /* set p to current s position */
            p = s;

            /* recurse */
            _lstrftime( p, maxsize, (char *) &_QRTLInstanceData(_pLocale)->TimeCat.TimeDateInfo.t_fmt_ampm, t );

            break;
#endif
        /* seconds */
        case 'S':

            if ( ordinal )
            {
                if ( _getordinal( t->tm_sec, buf ) == 1 )
                    break;
            }

            /* if not ordinal or _getordinal() failed */
            __utoa( t->tm_sec, buf + (t->tm_sec < 10) );

            break;

#ifdef __POSIX__

        /* POSIX: tab character */
        case 't':
            buf[ 0 ] = '\t';
            buf[ 1 ] = '\0';
            break;

        /* POSIX: 24 hour clock HH:MM:SS */
        case 'T':

            /* set p to current s position */
            p = s;

            /* recurse */
            _lstrftime( p, maxsize, "%H:%M:%S", t );

            break;
#endif

        /* week of year (Sunday) */
        case 'U':

            // Adjust weekday to be positive (first week) Sunday based
            i = (t->tm_wday + 7) % 7;
            
            // Adjust week to be positive (first week)
            i = (t->tm_yday - i + 6) / 7;

            if ( ordinal )
            {
                if ( _getordinal( i, buf ) == 1 )
                    break;
            }

            /* if not ordinal or _getordinal() failed */
            __utoa( i, buf + (i < 10) );

            break;

#ifdef __POSIX__

        /* POSIX: week of year (ISO 8601 {4}) */
        case 'V':

            /* not implemented */
            break;

        /* POSIX: day of week mon - sun (1 - 7) */
        case 'u':

            i = t->tm_wday ? t->tm_wday : 7;

            if ( ordinal )
            {
                if ( _getordinal( i, buf ) == 1 )
                    break;
            }

            /* if not ordinal or _getordinal() failed */
            __utoa( i, buf );

            break;
#endif

        /* day of week sun - sat (0 - 6) */
        case 'w':

            if ( ordinal )
            {
                if ( _getordinal( t->tm_wday, buf ) == 1 )
                    break;
            }

            /* if not ordinal or _getordinal() failed */
            __utoa( t->tm_wday, buf );

            break;

        /* week of year (Monday) */
        case 'W':

            // Adjust weekday to be positive (first week) Monday based
            i = (t->tm_wday + 6) % 7;

            // Adjust week to be positive (first week)
            i = (t->tm_yday - i + 6) / 7;

            if ( ordinal )
            {
                if ( _getordinal( i, buf ) == 1 )
                    break;
            }

            /* if not ordinal or _getordinal() failed */
            __utoa( i, buf + (i < 10) );

            break;

        /* date */
        case 'x':

            /* set p to current s position */
            p = s;

            /* recurse */
            _lstrftime( p, maxsize, (char *) &_QRTLInstanceData(_pLocale)->TimeCat.TimeDateInfo.d_fmt, t );

            break;

        /* time */
        case 'X':

            /* set p to current s position */
            p = s;

            /* recurse */
            _lstrftime( p, maxsize, (char *) &_QRTLInstanceData(_pLocale)->TimeCat.TimeDateInfo.t_fmt, t );

            break;

        /* year (no century) */
        case 'y':

           i = ( 1900 + t->tm_year ) % 100;

           if ( ordinal )
           {
               if ( _getordinal( i, buf ) == 1 )
                   break;
           }

           /* if not ordinal or _getordinal() failed */
           __utoa( i, buf + (i < 10) );

           break;

        /* year (with century) */
        case 'Y':

           __utoa( 1900 + t->tm_year, buf );
           break;

        /* time zone */
        case 'Z':
            p = _tzname[ t->tm_isdst ];

            break;

        /* literally "%" */
        case '%':
            p = "%";

        }

        i = min( strlen( p ), maxsize - len );
        strncpy( s, p, i );
        len += i;
        s += i;

        /* reset */
        ordinal = 0;

    } /* if-else */

    } /* for */

    *s = '\0';

   if( *fmt )  return( 0 );
   else        return( len - 1 );

}

#ifdef __POSIX__

/*---------------------------------------------------------------------*

Name            _getordinal

Usage           int _getordinal( unsigned int value, char *dest )

Prototype in    local to this module

Description     transforms 'value' into a ordinal string (dest), if possible,
                by using formats defined in the current locale

Return value    1 == successful transform and 0 == could not transform

*---------------------------------------------------------------------*/

int _getordinal( unsigned int value, char *dest )

{
    int i = 0;
    char *ptr;
    _QRTLDataBlock;

    if ( value > MAX_ALT_DIGITS - 1 )
        return( 0 );

   ptr = (char *) &_QRTLInstanceData(_pLocale)->TimeCat.TimeDateInfo.alt_digits;

    while( i++ != value )
        while( *ptr++ != '\0' )
            ;

    /* valid string? */
    if( *ptr != '\0' )
    {
        strcpy( dest, ptr );
        return( 1 );
    }

    else
    {
        return( 0 );
    }
}

#endif /* POSIX */

