/*-----------------------------------------------------------------------*
 * filename - mbtohira.c
 *
 * function(s)
 *        _mbctohira - Converts 2-bytes Katakana code to 2-bytes Hiragana.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */

#include <mbctype.h>

/*---------------------------------------------------------------------*

Name            _mbctohira - Converts 2-bytes Katakana code to 2-bytes
                             Hiragana

Usage           unsigned int _mbctohira(unsigned int c);

Prototype in    mbstring.h

Description     _mbctohira convers 2-bytes Katakana code in a Shift-JIS
                code system to 2-byte Hiragana.
                Other codes are not converted.

Return value    Returns a converted value. If the code is not convertible,
                _mbstohira returns a original value.

*---------------------------------------------------------------------*/

unsigned int _RTLENTRY _EXPFUNC _mbctohira(unsigned int c)
{
    if (c >= 0x8340 && c <= 0x8393 && c != 0x837F)
    {
        if (c < 0x837F)
            c -= 0x00A1;
        else
            c -= 0x00A2;
    }
    return c;
}
