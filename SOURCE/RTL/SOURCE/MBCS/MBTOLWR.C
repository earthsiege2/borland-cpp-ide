/*-----------------------------------------------------------------------*
 * filename - mbtolwr.c
 *
 * function(s)
 *        _mbctolower - Converts a code of uppercase letters to
 *                      lowercase letters.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ctype.h>
#include <mbctype.h>

#if 0
extern int _mbascii;
#endif

/*---------------------------------------------------------------------*

Name            _mbctolower - Converts a code of uppercase letters to
                              lowercase letters.

Usage           unsigned int _mbctolower(unsigned int c);

Prototype in    mbstring.h

Description     _mbctolower convers a code of uppercase letters to
                lowercase letters. _mbctolower does not convert
                any other codes.

Return value    Returns a converted value. If the code is not convertible,
                _mbstolower returns a original value.

*---------------------------------------------------------------------*/

unsigned int _RTLENTRY _EXPFUNC _mbctolower(unsigned int c)
{
    if (c <= 0x00FF)
    {
        if (isupper(c))
            c += 0x20;
    }
#if 0
    else
    {
        if (_mbascii && c >= 0x8260 && c <= 0x8279)
            c += 0x0021;
    }
#endif
    return c;
}
