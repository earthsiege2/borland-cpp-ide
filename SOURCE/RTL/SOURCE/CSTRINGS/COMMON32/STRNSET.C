/*-----------------------------------------------------------------------*
 * filename - strnset.c
 *
 * function(s)
 *        strnset, _wcsnset - sets all wide-characters in a string to a given
 *              wide-character
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.3  $        */

#include <string.h>
#include <_string.h>
#include <tchar.h>
#include <mem.h>

/*---------------------------------------------------------------------*

Name            strnset, _wcsnset - sets all (wide-)characters in a string
		to a given (wide-)character

Usage           char *strnset(char *str, int ch, size_t n);
		wchar_t *_wcsnset(wchar_t *str, wchar_t ch, size_t n);

Prototype in    string.h

Description     strnset and _wcsnset initializes the first n bytes of the
		ASCII/wide-character string str to the (wide-)character ch.
		If n > strlen(str), then strlen(str) replaces n.

Return value    pointer to str

*---------------------------------------------------------------------*/

#ifdef strnset
#  undef strnset
#  define INTRINSIC
#endif

#ifndef _UNICODE
_TCHAR * _RTLENTRY _EXPFUNC _tcsnset(_TCHAR *s, int ch, size_t n)
#else
_TCHAR * _RTLENTRY _EXPFUNC _tcsnset(_TCHAR *s, _TCHAR ch, size_t n)
#endif
{
#ifdef INTRINSIC
    return __strnset__(s, ch, n);
#else
    unsigned len;

    len = _tcslen(s);
    if (len < n)
        n = len;
#ifndef _UNICODE
    memset(s, ch, n);
#else
    _wmemset(s, ch, n);
#endif
    return (s);
#endif
}
