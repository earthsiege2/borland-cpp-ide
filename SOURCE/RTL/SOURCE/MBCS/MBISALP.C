/*-----------------------------------------------------------------------*
 * filename - mbisalp.c
 *
 * function(s)
 *        _ismbcalpha - Tests a character whether it is a alphabetical
 *                      charachter or not.
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

#if 0
extern int _mbascii;
#endif

/*---------------------------------------------------------------------*

Name            _ismbcalpha - Tests a character whether it is a
                              alphabetical charachter or not.

Usage           int _ismbcalpha(unsigned int c);

Prototype in    mbstring.h

Description     _ismbcalpha tests whether c is a alphabetical character
		or not.

Return value    Returns the value excepting 0 if it's a alphabetical
		character,and returns 0 if it is not.   

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ismbcalpha(unsigned int c)
{
    if (c > 0x00FF)
    {
#if 0
        if (_mbascii &&
            (c >= 0x8281 && c <= 0x829A || c >= 0x8260 && c <= 0x8279))
            return 1;
#endif
        return 0;
    }
    else
        return _ismbbalpha(c);
}
