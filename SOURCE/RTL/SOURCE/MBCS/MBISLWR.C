/*-----------------------------------------------------------------------*
 * filename - mbislwr.c
 *
 * function(s)
 *        _ismbclower - Tests a character whether it is a lowercase letter
 *                      or not.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1992, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

#include <mbctype.h>
#include <mbstring.h>

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
        return 0;
    else
        return (islower)(c);
}

