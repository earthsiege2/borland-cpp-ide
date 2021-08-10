/*-----------------------------------------------------------------------*
 * filename - strxfrm.c
 *
 * function(s)
 *        strxfrm - copies one string into another
 *        wcsxfrm - copies one wide-character string into another
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.2  $        */

#undef __USELOCALES__
#define __SIMPLE_LOCALES__
#include <string.h>
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            strxfrm, wcsxfrm - transforms a portion of a string

Usage           size_t strxfrm( char *dest, const char *src, size_t n )
                size_t wcsxfrm( wchar_t *dest, const wchar_t *src, size_t n )

Prototype in    string.h

Description     strxfrm transforms the string pointed to by src into the
                string dest for no more than n characters (including the
                null terminator).

Return value    Number of characters needed to represent src (not including
                the null char).

*---------------------------------------------------------------------*/

size_t _RTLENTRY _EXPFUNC _tcsxfrm( _TCHAR *dest, const _TCHAR *src, size_t n )

{
    size_t l = _tcslen( src );

    if (n && dest)
    {
        _tcsncpy(dest, src, n);

        if (n > l)
            dest[l] = _T('\0');  /* terminate the string if there's
                                    enough room
                                 */
    }

    return l;
}

