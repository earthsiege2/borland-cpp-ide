/*-----------------------------------------------------------------------*
 * filename - mbisupr.c
 *
 * function(s)
 *        _ismbcupper - Tests a character whether it is a uppercase
 *                      letter or not.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1992, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

#include <mbctype.h>

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
        return 0;
    else
        return (isupper)(c);
}
