/*-----------------------------------------------------------------------*
 * filename - strset.c
 *
 * function(s)
 *        strset, _wcsset - sets all (wide-)characters in a (wide-character)
 *			string to a given (wide-)character
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <string.h>
#include <_string.h>
#include <tchar.h>
#include <mem.h>

/*---------------------------------------------------------------------*

Name            strset, _wcsset - sets all wide-characters in a (wide-character)
			string to a given (wide-)character

Usage           char *strset(char *str, int ch);
                wchar_t *_wcsset(wchar_t *str, wchar_t ch);

Prototype in    string.h

Description     strset and _wcsset set all characters in the string str to the
                character ch.

Return value    pointer to str

*---------------------------------------------------------------------*/

#ifdef strset
#  undef strset
#  define INTRINSIC
#endif

#ifndef _UNICODE
_TCHAR * _RTLENTRY _EXPFUNC _tcsset(_TCHAR *s, int ch)
#else
_TCHAR * _RTLENTRY _EXPFUNC _tcsset(_TCHAR *s, _TCHAR ch)
#endif
{
#ifdef INTRINSIC
    return __strset__(s, ch);
#else
#ifndef _UNICODE
     memset(s, ch, _tcslen(s));
#else
     _wmemset(s, ch, _tcslen(s));
#endif
     return (s);
#endif
}
