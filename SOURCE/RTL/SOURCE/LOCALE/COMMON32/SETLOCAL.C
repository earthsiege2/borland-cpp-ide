/*
*
*    SETLOCAL.C
*
*    module for ANSI C setlocale() function
*    handles the "C" locale only
*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1993, 1994 by Borland International
 *      All Rights Reserved.
 *
 */


#include <locale.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>

#pragma warn -par

char * _RTLENTRY _EXPFUNC setlocale( int category, const char *locale )
  {
  if( locale == NULL )
    {
    return( "C" );
    }
  else
    {
    return( *locale && strcmp( locale, "C" ) ? NULL : (char *) locale );
    }
  }
