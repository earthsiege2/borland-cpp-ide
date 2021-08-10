/*-----------------------------------------------------------------------*
 * filename - mbishira.c
 *
 * function(s)
 *        _ismbchira - Tests a character whehter it is a 2-bytes
 *                     Hiragana or not.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1992, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


#include <mbstring.h>

extern int _mbcsCodePage;

/*---------------------------------------------------------------------*

Name            _ismbchira - Tests a character whehter it is a
                             2-bytes Hiragana or not.

Usage           int _ismbchira(unsigned int c);

Prototype in    mbstring.h

Description     _ismbchira judges whether c is a 2-bytes Hiragana char
                or not.

Return value    Returns the value excepting 0 if it is a 2-bytes Hiragana,
                and returns 0 if it is not. (0x829F <= c <= 0x82F1)

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ismbchira(unsigned int c)
{
    return (_mbcsCodePage == _KANJI_CP && c >= 0x829F && c <= 0x82F1);
}
