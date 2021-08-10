/*-----------------------------------------------------------------------*
 * filename - mbisspc.c
 *
 * function(s)
 *        _ismbcspace - Tests a character whether it is a space or not.
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
        return 0;
    else
        return isspace(c);
}
