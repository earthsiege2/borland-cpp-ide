/*------------------------------------------------------------------------
 * filename - strftime.c
 *
 * function(s)
 *    strftime  - converts date and time structure to a string according
 *                to the C locale.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#include <_io.h>
#include <_printf.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <RtlData.h>

extern char *SWeekday[7];
extern char *LWeekday[7];
extern char *SMonth[12];
extern char *LMonth[12];
extern char *AmPm[2];

extern int _FARFUNC atime( char *dest, const struct tm *tmPtr );

size_t _FARFUNC strftime( char *s, size_t maxsize, const char *fmt, const struct tm *t )

{
    char buf[ 25 ];

    char *p = buf;
    int i, len;

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

            p = SWeekday[t->tm_wday];

            break;

        /* full day */
        case 'A':

            p = LWeekday[t->tm_wday];

            break;

        /* abbreviated month */
        case 'b':

            p = SMonth[t->tm_mon];

            break;

        /* full month */
        case 'B':

            p = LMonth[t->tm_mon];

            break;

        /* date and time */
        case 'c':

            atime( p, t );

            break;

        /* month date */
        case 'd':

             __utoa( t->tm_mday, buf + (t->tm_mday < 10) );

             break;


        /* hour (24) */
        case 'H':

            __utoa( t->tm_hour, buf + (t->tm_hour < 10) );

            break;

        /* hour (12) */
        case 'I':

            i = t->tm_hour % 12;

            if (i == 0)
                i = 12;

            __utoa( i, buf + (i < 10) );

            break;

        /* year day */
        case 'j':

            i = t->tm_yday + 1;

            __utoa( i, buf + (i < 10) + (i < 100) );

            break;

        /* month */
        case 'm':

            i = t->tm_mon + 1;

            __utoa( i, buf + (i < 10) );

            break;

        /* minute */
        case 'M':

            __utoa( t->tm_min, buf + (t->tm_min < 10) );

            break;

        /* am/pm */
        case 'p':

            p = AmPm[ t->tm_hour / 12 ];

            break;

        /* seconds */
        case 'S':

            __utoa( t->tm_sec, buf + (t->tm_sec < 10) );

            break;

        /* week of year (Sunday) */
        case 'U':

            // Adjust weekday to be positive (first week) Sunday based
            i = (t->tm_wday + 7) % 7;
            
            // Adjust week to be positive (first week)
            i = (t->tm_yday - i + 6) / 7;

            __utoa( i, buf + (i < 10) );

            break;

        /* day of week sun - sat (0 - 6) */
        case 'w':

            __utoa( t->tm_wday, buf );

            break;

        /* week of year (Monday) */
        case 'W':

            // Adjust weekday to be positive (first week) Monday based
            i = (t->tm_wday + 6) % 7;

            // Adjust week to be positive (first week)
            i = (t->tm_yday - i + 6) / 7;

            __utoa( i, buf + (i < 10) );

            break;

        /* date */
        case 'x':

            strcpy( buf, SWeekday[t->tm_wday] );
            strcat( buf, " " );
            strcat( buf, SMonth[t->tm_mon] );
            strcat( buf, " " );
            __utoa( t->tm_mday, buf + strlen( buf ) );
            strcat( buf, ", " );
            __utoa( t->tm_year + 1900, buf + strlen( buf ) );

            break;

        /* time */
        case 'X':

            __utoa( t->tm_hour, buf + (t->tm_hour < 10) );
            strcat( buf, ":0" );
            __utoa( t->tm_min, buf + strlen( buf ) - (t->tm_min > 9) );
            strcat( buf, ":0" );
            __utoa( t->tm_sec, buf + strlen( buf ) - (t->tm_sec > 9) );

            break;

        /* year (no century) */
        case 'y':

           i = ( 1900 + t->tm_year ) % 100;

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

    } /* if-else */

    } /* for */

    *s = '\0';

   if( *fmt )  return( 0 );
   else        return( len - 1 );

}
