/*-----------------------------------------------------------------------*
 * filename - lstrxfrm.c
 *
 * function(s)
 *        _lstrxfrm - transforms a string according to the current locale's
 *                  collation rules.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <string.h>
#include <rtldata.h>
#include <_locale.h>

/*---------------------------------------------------------------------*

Name            _lstrxfrm - transforms a portion of a string

Usage           size_t strxfrm( char *dest, const char *src, size_t n )

Prototype in    string.h

Description     _lstrxfrm transforms the string pointed to by src into the
                string dest for no more than n characters.

Return value    Number of characters copied

*---------------------------------------------------------------------*/

size_t _CType _lstrxfrm(char _FAR *s1, const char _FAR *s2, size_t n )
{
    _QRTLDataBlock;

    return( _QRTLInstanceData(_pLocale)->ptransform( s1, s2, n ) );
}

