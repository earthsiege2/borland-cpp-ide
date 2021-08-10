/*-----------------------------------------------------------------------*
 * filename - mbisdgt.c
 *
 * function(s)
 *        _ismbcdigit - Tests a character whether it is a numeric
 *                      character or not.
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

Name            _ismbcdigit - Tests a character whether it is a
                              numeric character or not.

Usage           int _ismbcdigit(unsigned int c);

Prototype in    mbstring.h

Description     _ismbcdigit tests whether c is a numeric character or not.

Return value    Returns the value excepting 0 if it is a numeric cars,
                and returns 0 if it is not.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ismbcdigit(unsigned int c)
{
    if (c > 0x00FF)
    {
#if 0
        if (_mbascii && c >= 0x824F && c <= 0x8258)
            return 1;
#endif
        return 0;
    }
    else
        return isdigit(c);
}
