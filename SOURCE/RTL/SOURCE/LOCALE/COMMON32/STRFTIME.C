/*------------------------------------------------------------------------
 * filename - strftime.c
 *
 * function(s)
 *      strftime - converts data and time structure to a string
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */


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

            // Adjust weekday to be positive (first week) Sunday based
            i = (t->tm_wday + 7) % 7;
            
            // Adjust week to be positive (first week)
            i = (t->tm_yday - i + 6) / 7;

            __utoa( i, buf + (i < 10) );

            break;

         /* day of week */
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
