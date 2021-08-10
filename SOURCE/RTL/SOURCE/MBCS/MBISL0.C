/*-----------------------------------------------------------------------*
 * filename - mbisl0.c
 *
 * function(s)
 *        _ismbcl0 - Tests a character whether it is the character
 *                   in Shift-JIS code excepting Kanji character.
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

Name            _ismbcl0 - Tests a character whether it is the character
                           in Shift-JIS code, excepting Kanji character.
		           
Usage           int _ismbcl0(unsigned int c);

Prototype in    mbstring.h

Description	_isbmcl0 judges whether c is a 2-bytes char excepting Kanji
		in Shift-JIS code or not.      

Return value    Returns the value excepting 0 if is a 2-byte code in Shift-JIS
		excepting Kanji char,and returns 0 if it is not.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ismbcl0(unsigned int c)
{
    return (c >= 0x8140 && c <= 0x889E && _ismbbtrail((unsigned char)c) );
}
