/*-----------------------------------------------------------------------*
 * filename - mbisl2.c
 *
 * function(s)
 *        _ismbcl2 - Tests a character whether it is the second standard
 *                   level of Kanji in JIS code.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */

#include <mbctype.h>
#include <mbstring.h>

/*---------------------------------------------------------------------*

Name            _ismbcl2 - Tests a character whether it is the second 
                           standard level of Kanji in JIS code. 

Usage           int _ismbcl2(unsigned int c);

Prototype in    mbstring.h

Description     _ismbcl2 tests whether c is the second standard level of
                Kanji.

Return value    Returns the value excepting 0 if is the second standard
                level of Kanji, and return 0 if it is not.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ismbcl2(unsigned int c)
{
    return ((c >= 0x989F && c <= 0xEA9E) &&
            (c <= 0x9FFC || c >= 0xE040) &&
            _ismbbtrail((unsigned char)c));
}
