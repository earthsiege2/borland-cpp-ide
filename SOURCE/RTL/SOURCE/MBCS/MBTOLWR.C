/*-----------------------------------------------------------------------*
 * filename - mbtolwr.c
 *
 * function(s)
 *        _mbctolower - Converts a code of uppercase letters to
 *                      lowercase letters.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1992, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

#include <ctype.h>
#include <mbctype.h>

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
        c = _ltolower(c);
    return c;
}
