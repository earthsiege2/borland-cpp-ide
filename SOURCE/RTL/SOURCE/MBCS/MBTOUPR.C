/*-----------------------------------------------------------------------*
 * filename - mbtoupr.c
 *
 * function(s)
 *        _mbctoupper - Converts a code of lowercase letters to
 *                      uppercase letters.
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
        c = _ltoupper(c);
    return c;
}
