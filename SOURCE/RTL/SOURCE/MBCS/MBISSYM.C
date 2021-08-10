/*-----------------------------------------------------------------------*
 * filename - mbissym.c
 *
 * function(s)
 *        _ismbcsymbol - Tests a character whether it is a 2-bytes comma,
 *                       period or symbol.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */

#include <mbstring.h>

/*---------------------------------------------------------------------*

Name            _ismbcsymbol - Tests a character whether it is a 2-bytes
                               comma,period or symbol.

Usage           int _ismbcsymbol(unsigned int c);

Prototype in    mbstring.h

Description     _ismbcsymbol tests whether c is a 2 bytes comma, period
                or symbol, or not.

Return value    Returns a value excepting 0 if it is a 2-bytes comma,
                period or symbol, and returns 0 if it is not.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _ismbcsymbol(unsigned int c)
{
    return (c >= 0x8141 && c <= 0x81AC && c != 0x817F);
}
