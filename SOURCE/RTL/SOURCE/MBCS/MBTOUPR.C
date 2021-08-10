/*-----------------------------------------------------------------------*
 * filename - mbtoupr.c
 *
 * function(s)
 *        _mbctoupper - Converts a code of lowercase letters to
 *                      uppercase letters.
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

Name            _mbctoupper - Converts a code of lowercase letters to
                              uppercase letters.

Usage           unsigned int _mbctoupper(unsigned int c);

Prototype in    mbstring.h

Description     _mbctoupper convers a code of uppercase letters to
                lowercase letters. _mbctoupper does not convert
                any other codes.

Return value    Returns a converted value. If the code is not convertible,
                _mbstolower returns a original value.

*---------------------------------------------------------------------*/

unsigned int _RTLENTRY _EXPFUNC _mbctoupper(unsigned int c)
{
    if (c <= 0x00FF)
    {
        if (islower(c))
            c -= 0x20;
    }
#if 0
    else
    {
        if (_mbascii && c >= 0x8281 && c <= 0x829A)
            c -= 0x0021;
    }
#endif
    return c;
}
