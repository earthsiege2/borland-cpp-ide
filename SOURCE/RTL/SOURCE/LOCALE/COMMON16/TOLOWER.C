/*-----------------------------------------------------------------------*
 * filename - tolower.c
 *
 * function(s)
 *        tolower - translates characters to lower-case
 *                  for the "C" locale only
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#include <ctype.h>

/*---------------------------------------------------------------------*

Name            tolower - translates characters to lower-case

Usage           int tolower(int c);

Prototype in    ctype.h

Description     tolower is a function that converts an integer c (in the range
                EOF to 255) to its lower-case value (if it was upper-case): all
                others are left unchanged.
                For the "C" locale only

Return value    returns the converted value of c, on success, and nothing
                on failure.

*---------------------------------------------------------------------*/
#if defined(__FARFUNCS__)
#include <_farfunc.h>
#endif

int _CType tolower( int ch )
  {
   /* check for EOF */
  if( ch == -1 )  return( -1 );

  if( isupper((unsigned char)ch) )
    {
    return( _tolower((unsigned char)ch) );
    }
  else
    {
    return( (unsigned char)ch );
    }
  }
