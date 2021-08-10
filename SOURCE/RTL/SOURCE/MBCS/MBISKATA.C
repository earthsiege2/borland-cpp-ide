/*-----------------------------------------------------------------------*
 * filename - mbiskata.c
 *
 * function(s)
 *        _ismbckata - Tests a character whehter it is a 2-bytes
 *                     Katakana or not.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1992, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */


#include <mbstring.h>

extern int _mbcsCodePage;

/*---------------------------------------------------------------------*

Name            _ismbckata - Tests a character whehter it is a 2-bytes
                             Katakana or not.

Usage           int _ismbckata(unsigned int c);

Prototype in    mbstring.h

Description     _ismbckata tests whether c is a 2-bytes Katakana char
                or not.

Return value    Returns the value excepting 0 if it is a 2-bytes Katakana,
                and returns 0 if it is not.
                (0x8340 <= c <= 0x837E or 0x8380 <= c <= 0x8396)

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ismbckata(unsigned int c)
{
    return (_mbcsCodePage == _KANJI_CP &&
            c >= 0x8340 && c <= 0x8396 && c != 0x837F);
}
