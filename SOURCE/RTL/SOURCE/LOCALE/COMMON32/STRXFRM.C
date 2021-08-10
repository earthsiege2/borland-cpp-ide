/*-----------------------------------------------------------------------*
 * filename - strxfrm.c
 *
 * function(s)
 *        strxfrm - copies one string into another
 *        wcsxfrm - copies one wide-character string into another
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
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            strxfrm, wcsxfrm - transforms a portion of a string

Usage           size_t strxfrm( char *dest, const char *src, size_t n )
                size_t wcsxfrm( wchar_t *dest, const wchar_t *src, size_t n )

Prototype in    string.h

Description     strxfrm transforms the string pointed to by src into the
                string dest for no more than n characters.

Return value    Number of characters copied

*---------------------------------------------------------------------*/

size_t _RTLENTRY _EXPFUNC _tcsxfrm( _TCHAR *dest, const _TCHAR *src, size_t n )

{
    size_t l = _tcslen( src );

    if (n > l)
        _tmemcpy(dest, src, l+1);

    return l;
}

