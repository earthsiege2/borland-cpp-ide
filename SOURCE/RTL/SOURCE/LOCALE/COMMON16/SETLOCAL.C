/*
*
*    SETLOCAL.C
*
*    module for ANSI C setlocale() function
*    handles the "C" locale only
*
*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1993, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <locale.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>

#pragma warn -par

char * _CType _FARFUNC setlocale( int category, const char *locale )
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

