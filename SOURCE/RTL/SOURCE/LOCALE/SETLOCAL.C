/*
*
*    SETLOCAL.C
*
*    module for ANSI C setlocale() function
*    handles the "C" locale only
*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1993, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

#undef __USELOCALES__
#define __SIMPLE_LOCALES__
#include <locale.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <tchar.h>

#pragma warn -par

_TCHAR * _RTLENTRY _EXPFUNC _tsetlocale( int category, const _TCHAR *locale )
  {
  if( locale == NULL )
    {
    return( _TEXT("C") );
    }
  else
    {
    return( *locale && _tcscmp( locale, _TEXT("C") ) ? NULL : (_TCHAR *) locale );
    }
  }
