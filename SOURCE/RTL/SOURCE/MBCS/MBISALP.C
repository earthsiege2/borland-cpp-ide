/*-----------------------------------------------------------------------*
 * filename - mbisalp.c
 *
 * function(s)
 *        _ismbcalpha - Tests a character whether it is a alphabetical
 *                      charachter or not.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1992, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */


#include <ctype.h>
#include <mbctype.h>
#include <mbstring.h>

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
        return 0;
    else
        return _ismbbalpha(c);
}
