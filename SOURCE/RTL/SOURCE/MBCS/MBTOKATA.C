/*-----------------------------------------------------------------------*
 * filename - mbtokata.c
 *
 * function(s)
 *        _mbctokata - Converts 2-byte Hiragana code to 2-byte Katakana.
  *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1992, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


#include <mbctype.h>

/*---------------------------------------------------------------------*

Name            _mbctokata - Converts 2-byte Hiragana code to 2-byte
                             Katakana.

Usage           unsigned int _mbctokata(unsigned int c);

Prototype in    mbstring.h

Description     _mbctokata convers 2-bytes Hiragana code in a Shift-JIS
                code system to 2-byte Katakana.
                Other codes are not converted.

Return value    Returns a converted value. If the code is not convertible,
                _mbstokata returns a original value.

*---------------------------------------------------------------------*/

unsigned int _RTLENTRY _EXPFUNC _mbctokata(unsigned int c)
{
    if (_ismbchira(c))
    {
        c += 0x00A1;
        if (c >= 0x837F)
            c++;
    }
    return c;
}
