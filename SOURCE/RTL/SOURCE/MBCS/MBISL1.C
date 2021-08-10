/*-----------------------------------------------------------------------*
 * filename - mbisl1.c
 *
 * function(s)
 *        _ismbcl1 - Tests a character whether it is the first standard
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
    return (c >= 0x889F && c <= 0x9872 && _ismbbtrail((unsigned char)c) );
}
