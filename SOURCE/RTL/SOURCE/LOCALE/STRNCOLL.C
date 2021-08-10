/*-----------------------------------------------------------------------*
 * filename - strncoll.c
 *
 * function(s)
 *        _strncoll - compares two strings without case sensitivity
 *        _wcsncoll - compares two wide-character strings without case
 *                  sensitivity
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1996, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.5.2.1 $        */

#undef __USELOCALES__
#define __SIMPLE_LOCALES__
#include <string.h>
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            _strncoll, _wcsncoll - compares two strings

Usage           int _strncoll(const char *s1, const char *s2, size_t maxlen);
                int _wcsncoll(const wchar_t *s1, const wchar_t *s2, size_t maxlen);

Prototype in    string.h

Description     _strncoll compares the string pointed to by s1 to the
                string pointed to by s2, according to the collating
                sequence set by setlocale.

                At most "maxlen" characters will be compared. A "maxlen" of zero
                results in an equal compare, i.e. returns a zero.

Return value    returns a value that is
                   < 0 if s1 is less than s2
                   == 0 if s1 is same as s2
                   > 0 if si is greater than s2

*---------------------------------------------------------------------*/


int _RTLENTRY _EXPFUNC _tcsncoll( const _TCHAR *s1, const _TCHAR *s2, size_t n )

{
    return( _tcsncmp( s1, s2, n ) );
}

