/*-----------------------------------------------------------------------*
 * filename - toupper.c
 *
 * function(s)
 *        toupper - translates characters to upper-case
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ctype.h>

/*---------------------------------------------------------------------*

Name            toupper - translates characters to upper-case

Usage           int toupper(int c);

Prototype in    toupper is a function that converts an integer c (in the range
                EOF to 255) to its upper-case value (if it was lower-case): all
                others are left unchanged.

Return value    returns the converted value of c, on success, and
                nothing on failure.

*---------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC toupper( int ch )
  {
  if( ch == -1 )  return( -1 );

  if( islower((unsigned char)ch) )
    {
    return( _toupper((unsigned char)ch) );
    }
  else
    {
    return( (unsigned char)ch );
    }
  }
