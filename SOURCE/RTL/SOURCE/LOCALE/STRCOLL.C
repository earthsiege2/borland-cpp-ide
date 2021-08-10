/*-----------------------------------------------------------------------*
 * filename - strcoll.c
 *
 * function(s)
 *        strcoll - compares two strings
 *        wcscoll - compares two wide-character strings
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.5.2.1 $        */

#undef __USELOCALES__
#define __SIMPLE_LOCALES__
#include <string.h>
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            strcoll, wcscoll - compares two strings

Usage           int strcoll(const char *s1, const char *s2);
                int wcscoll(const wchar_t *s1, const wchar_t *s2);

Prototype in    string.h

Description     strcoll compares the string pointed to by s1 to the
                string pointed to by s2, according to the collating
                sequence set by setlocale.

Return value    returns a value that is
                   < 0 if s1 is less than s2
                   == 0 if s1 is same as s2
                   > 0 if si is greater than s2

*---------------------------------------------------------------------*/


int _RTLENTRY _EXPFUNC _tcscoll( const _TCHAR *s1, const _TCHAR *s2 )

{
    return( _tcscmp( s1, s2 ) );
}

