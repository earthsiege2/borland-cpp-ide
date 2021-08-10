/*-----------------------------------------------------------------------*
 * filename - tolower.c
 *
 * function(s)
 *        tolower - translates characters to lower-case
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

#undef __USELOCALES__
#define __SIMPLE_LOCALES__

#include <stdio.h>
#include <ctype.h>

/*---------------------------------------------------------------------*

Name            tolower - translates characters to lower-case

Usage           int tolower(int c);

Prototype in    ctype.h

Description     tolower is a function that converts an integer c (in the range
                EOF to 255) to its lower-case value (if it was upper-case): all
                others are left unchanged.

Return value    returns the converted value of c, on success, and nothing
                on failure.

*---------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC tolower( int ch )
{
    if( ch == EOF )
        return( EOF );

    if( isupper( (unsigned char)ch) )
    {
        return( _tolower((unsigned char)ch) );
    }
    else
    {
        return( (unsigned char)ch );
    }
}
