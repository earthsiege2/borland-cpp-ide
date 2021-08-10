/*-----------------------------------------------------------------------*
 * filename - mbisupr.c
 *
 * function(s)
 *        _ismbcupper - Tests a character whether it is a uppercase
 *                      letter or not.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */

#include <mbctype.h>

#if 0
extern int _mbascii;
#endif

/*---------------------------------------------------------------------*

Name            _ismbcupper - Tests a character whether it is a uppercase
                              lettter or not.

Usage           int _ismbcupper(unsigned int c);

Prototype in    mbstring.h

Description     _ismbcupper tests c whether it is a uppercase letter or not.

Return value    Returns the value excepting 0 if it is a uppercase,
		and returns 0 if it is not.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ismbcupper(unsigned int c)
{
    if (c > 0x00FF)
    {
#if 0
        if (_mbascii && c >= 0x8260 && c <= 0x8279)
            return 1;
#endif
        return 0;
    }
    else
        return isupper(c);
}
