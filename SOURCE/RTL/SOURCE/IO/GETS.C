/*------------------------------------------------------------------------
 * filename - gets.c
 *
 * function(s)
 *        gets - gets a string from a stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.3 $        */

#include <stdio.h>
#include <_stdio.h>
#include <_tchar.h>

/*---------------------------------------------------------------------*

Name            _getts used as gets and _getws
                gets   - gets a string from a stream
                _getws - gets a wide string from a stream

Usage           char *gets(char *string);
                wchar_t *_getws(wchar_t *string);

Prototype in    stdio.h

Description     _getts reads a string into string from the
                standard input stream stdin. The string is terminated by a
                newline character, which is replaced in @i{string} by a null
                character (\0).

Return value    on success, returns the string argument string;
                else returns NULL on end-of-file or error.

*---------------------------------------------------------------------*/

_TCHAR * _RTLENTRY _EXPFUNC _getts(_TCHAR *s)
{
    register _TINT   c;
    register _TCHAR *P;

    _lock_stream(stdin);

    P = s;

    while ((c = _gettc (stdin)) != _TEOF && c != _TEXT('\n'))
        *P++ = c;

    if (_TEOF == c && P == s)
        P = NULL;
    else
    {
        *P = 0;
        P = ferror (stdin) ? NULL : s;
    }

    _unlock_stream(stdin);
    return (P);
}
