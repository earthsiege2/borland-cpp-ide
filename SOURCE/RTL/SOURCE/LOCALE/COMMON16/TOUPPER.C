/*-----------------------------------------------------------------------*
 * filename - toupper.c
 *
 * function(s)
 *        toupper - translates characters to upper-case
 *                  for the "C" locale only

 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
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
                For the "C" locale only

Return value    returns the converted value of c, on success, and
                nothing on failure.

*---------------------------------------------------------------------*/
#if defined(__FARFUNCS__)
#include <_farfunc.h>
#endif


int _CType toupper( int ch )
  {
   /* check for EOF */
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