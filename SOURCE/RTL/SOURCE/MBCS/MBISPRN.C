/*-----------------------------------------------------------------------*
 * filename - mbisprn.c
 *
 * function(s)
 *        _ismbcprint - tests a character whether it is a printer font
 *                      or not.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ctype.h>
#include <mbctype.h>
#include <mbstring.h>

/*---------------------------------------------------------------------*

Name            _ismbcprint - Tests a character whether it is a printer
                              font or not.

Usage           int _ismbcprint(unsigned int c);

Prototype in    mbstring.h

Description     _ismbcprint tests whether c is a printer font
               (1-byte code that is a not control character, or legal
                2-bytes code) or not.

Return value    Returns the value excepting 0 if it is a printer font,
		and returns 0 if it is not.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ismbcprint(unsigned int c)
{
    if (c > 0x00FF)
        return (_ismbblead(c >> 8) && _ismbbtrail((unsigned char)c));
    else
        return (_ismbbprint(c));
}
