/*-----------------------------------------------------------------------*
 * filename - towlower.c
 *
 * function(s)
 *        tolower - translates wide-characters to lower-case
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1996, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

#undef __USELOCALES__
#define __SIMPLE_LOCALES__
#define _UNICODE
#include <stdio.h>
#include <windows.h>
#include <ctype.h>

/*---------------------------------------------------------------------*

Name            towlower - translates wide-characters to lower-case

Usage           wchar_t towlower(wchar_t);

Prototype in    ctype.h

Description     towlower is a function that converts a wide-character c
		to its lower-case value (if it was upper-case): all
                others are left unchanged.

Return value    returns the converted/unchanged value of c.

*---------------------------------------------------------------------*/

wchar_t _RTLENTRY _EXPFUNC towlower( wchar_t ch )
{
    unsigned int c;

    if( ch == WEOF )
	return( WEOF );
    c = ch;
    return ((wchar_t) CharLower((LPTSTR)c));
}
