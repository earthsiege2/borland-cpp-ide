/*------------------------------------------------------------------------
 * filename - strftime.c
 *
 * function(s)
 *      strftime - converts data and time structure to a string
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#ifdef __OS2__

#include <_printf.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <_time.h>

size_t _RTLENTRY _EXPFUNC strftime (char *s, size_t maxsize, const char *fmt,
                                const struct tm *t )
{
    char buf[ 25 ];

    char *p = buf;
    int i, len;

    for( len = 1; len < maxsize && *fmt; ++fmt, p = buf )
    {
        if( *fmt != '%' )
        {
            ++len;
            *s++ = *fmt;
        }
        else
        {
            strcpy( buf, "00" );

            switch( *++fmt )
            {
            case 'a':
                p = _SWeekday[t->tm_wday];
                break;

            case 'A':
                p = _LWeekday[t->tm_wday];
                break;

            case 'b':
                p = _SMonth[t->tm_mon];
                break;

            case 'B':
                p = _LMonth[t->tm_mon];
                break;

            case 'c':
                _atime( p, t, "" );
                break;

            case 'd':
                __utoa( t->tm_mday, buf + (t->tm_mday < 10) );
                break;

            case 'H':
                __utoa( t->tm_hour, buf + (t->tm_hour < 10) );
                break;

            case 'I':
                i = t->tm_hour % 12;
                if (i == 0)
                    i = 12;
                __utoa( i, buf + (i < 10) );
                break;

            case 'j':
                i = t->tm_yday + 1;
                __utoa( i, buf + (i < 10) + (i < 100) );
                break;

            case 'm':
                i = t->tm_mon + 1;
                __utoa( i, buf + (i < 10) );
                break;

            case 'M':
                __utoa( t->tm_min, buf + (t->tm_min < 10) );
                break;

            case 'p':
                p = _AmPm[ t->tm_hour / 12 ];
                break;

            case 'S':
                __utoa( t->tm_sec, buf + (t->tm_sec < 10) );
                break;

            case 'U':
                i = t->tm_wday - (t->tm_yday % 7);
                if( i < 0 )
                    i += 7;
                i = (t->tm_yday + i) / 7;
                __utoa( i, buf + (i < 10) );
                break;

            case 'w':
                __utoa( t->tm_wday, buf );
                break;

            case 'W':
                i = t->tm_wday - (t->tm_yday % 7);
                if( i < 0 )
                    i += 7;
                i = (t->tm_yday + i - 1) / 7;
                __utoa( i, buf + (i < 10) );
                break;

            case 'x':
                strcpy( buf, _SWeekday[t->tm_wday] );
                strcat( buf, " " );
                strcat( buf, _SMonth[t->tm_mon] );
                strcat( buf, " " );
                __utoa( t->tm_mday, buf + strlen( buf ) );
                strcat( buf, ", " );
                __utoa( t->tm_year + 1900, buf + strlen( buf ) );
                break;

            case 'X':
                __utoa( t->tm_hour, buf + (t->tm_hour < 10) );
                strcat( buf, ":0" );
                __utoa( t->tm_min, buf + strlen( buf ) - (t->tm_min > 9) );
                strcat( buf, ":0" );
                __utoa( t->tm_sec, buf + strlen( buf ) - (t->tm_sec > 9) );
                break;

            case 'y':
                i = t->tm_year % 100;
                __utoa( i, buf + (i < 10) );
                break;

            case 'Y':
                __utoa( 1900 + t->tm_year, buf );
                break;

            case 'Z':
                p = tzname[ t->tm_isdst ];
                break;

            case '%':
                p = "%";
            }

            i = min( strlen( p ), maxsize - len );
            strncpy( s, p, i );
            len += i;
            s += i;
        }
    }

    *s = '\0';

    if( *fmt )  return( 0 );
    else        return( len - 1 );
}

#else

#include <_io.h>
#include <_printf.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <_locale.h>

size_t _RTLENTRY _EXPFUNC
strftime( char *s, size_t maxsize, const char *fmt, const struct tm *t )


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

            p = (char *) &_pLocale->TimeCat.TimeDateInfo.abday[ t->tm_wday ];

            break;

         /* full day */
         case 'A':

            p = (char *) &_pLocale->TimeCat.TimeDateInfo.day[ t->tm_wday ];

            break;

         /* abbreviated month */
         case 'b':

            p = (char *) &_pLocale->TimeCat.TimeDateInfo.abmon[ t->tm_mon ];

            break;
   
         /* full month */
         case 'B':

            p = (char *) &_pLocale->TimeCat.TimeDateInfo.mon[ t->tm_mon ];

            break;
   
         /* date and time */
         case 'c':

            /* set p to current s position */
             p = s; 

             /* recurse */
             strftime( p, maxsize, (char *) &_pLocale->TimeCat.TimeDateInfo.d_t_fmt, t );

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

            p = (char *) &_pLocale->TimeCat.TimeDateInfo.am_pm[ t->tm_hour / 12 ];

            break;

         /* seconds */
         case 'S':

            __utoa( t->tm_sec, buf + (t->tm_sec < 10) );

            break;

         /* week of year (Sunday) */
         case 'U':

            i = t->tm_wday - (t->tm_yday % 7);

            if( i < 0 )
                i += 7;

            i = (t->tm_yday + i) / 7;

            __utoa( i, buf + (i < 10) );

            break;

         /* day of week */
         case 'w':

            __utoa( t->tm_wday, buf );

            break;

         /* week of year (Monday) */
         case 'W':

            i = t->tm_wday - (t->tm_yday % 7);

            if( i < 0 )
                i += 7;

            i = (t->tm_yday + i - 1) / 7;

            __utoa( i, buf + (i < 10) );

            break;

         /* date */
         case 'x':

            /* set p to current s position */
            p = s;

				/* recurse */
            strftime( p, maxsize, (char *) &_pLocale->TimeCat.TimeDateInfo.d_fmt, t );

            break;

         /* time */
         case 'X':

            /* set p to current s position */
            p = s;

				/* recurse */
            strftime( p, maxsize, (char *) &_pLocale->TimeCat.TimeDateInfo.t_fmt, t );

            break;

         /* year (no century) */
         case 'y':

            i = t->tm_year % 100;

            __utoa( i, buf + (i < 10) );

            break;

         /* year (with century) */
         case 'Y':

            __utoa( 1900 + t->tm_year, buf );

            break;

         /* time zone */
         case 'Z':
            p = tzname[ t->tm_isdst ];

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


#endif
