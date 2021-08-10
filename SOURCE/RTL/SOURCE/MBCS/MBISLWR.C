/*-----------------------------------------------------------------------*
 * filename - mbislwr.c
 *
 * function(s)
 *        _ismbclower - Tests a character whether it is a lowercase letter
 *                      or not.
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

#if 0
extern int _mbascii;
#endif

/*---------------------------------------------------------------------*

Name            _ismbclower - Tests a character whether it is a
                              lowercase letter or not

Usage           int _ismbclower(unsigned int c);

Prototype in    mbstring.h

Description     _ismbclower tests whether c is a lowercase letter or not.

Return value    Returns the value excepting 0 if it is a lowercase,
		and returns 0 if it is not.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ismbclower(unsigned int c)
{
    if (c > 0x00FF)
    {
#if 0
        if (_mbascii && c >= 0x8281 && c <= 0x829A)
            return 1;
#endif
        return 0;
    }
    else
        return islower(c);
}

