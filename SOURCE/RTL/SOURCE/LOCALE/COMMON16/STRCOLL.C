/*-----------------------------------------------------------------------*
 * filename - strcoll.c
 *
 *	functions(s)
 *			strcoll - collates two strings
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <string.h>
#include <locale.h>

/*---------------------------------------------------------------------*

Name            strcoll - collates two strings

Usage           int strcoll(const char *s1, const char *s2);

Prototype in    string.h

Description     strcoll collates the string pointed to by s1 to the
                string pointed to by s2, according to the '"C" locale.

Return value    returns a value that is
                   < 0 if s1 is less than s2
                   == 0 if s1 is same as s2
                   > 0 if si is greater than s2

*---------------------------------------------------------------------*/

int _CType (strcoll)(const char _FAR *s1, const char _FAR *s2)

{
	return( strcmp( s1, s2 ) );
}



