/*-----------------------------------------------------------------------*
 * filename - mbisspc.c
 *
 * function(s)
 *        _ismbcspace - Tests a character whether it is a space or not.
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

#if 0
extern int _mbascii;
#endif

/*---------------------------------------------------------------------*

Name            _ismbcspace - Tests a character whether it is a space
                              or not.

Usage           int _ismbcspace(unsigned int c);

Prototype in    mbstring.h

Description     _ismbcspace tests c whether it is a space or not.

Return value    Returns the value excepting 0 if it is a space,
		and returns 0 if it is not.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ismbcspace(unsigned int c)
{
    if (c > 0x00FF)
    {
#if 0
        if (_mbascii && c == 0x8140)
            return 1;
#endif
        return 0;
    }
    else
        return isspace(c);
}
