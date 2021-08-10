/*-----------------------------------------------------------------------*
 * filename - mbisdgt.c
 *
 * function(s)
 *        _ismbcdigit - Tests a character whether it is a numeric
 *                      character or not.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1992, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


#include <ctype.h>
#include <mbctype.h>
#include <mbstring.h>

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
        return 0;
    else
        return isdigit(c);
}
