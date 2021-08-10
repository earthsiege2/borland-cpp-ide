/*-----------------------------------------------------------------------*
 * filename - mbisl1.c
 *
 * function(s)
 *        _ismbcl1 - Tests a character whether it is the first standard
 *                   level of Kanji in JIS code.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1992, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */


#include <mbctype.h>
#include <mbstring.h>

extern int _mbcsCodePage;

/*---------------------------------------------------------------------*

Name            _ismbcl1 - Tests a character whether it is the first
                           standard level of Kanji in JIS code.

Usage           int _ismbcl1(unsigned int c);

Prototype in    mbstring.h

Description     _ismbcl1 tests whether c is the first standard level
                of Kanji in JIS.

Return value    Returns the value excepting 0 if is the first standard
                level of Kanji, and return 0 if it is not.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ismbcl1(unsigned int c)
{
    return (_mbcsCodePage == _KANJI_CP &&
            c >= 0x889F && c <= 0x9872 && _ismbbtrail((unsigned char)c) );
}
