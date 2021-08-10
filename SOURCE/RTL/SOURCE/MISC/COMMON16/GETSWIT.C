/*-----------------------------------------------------------------------*
 * filename - getswit.c
 *
 * function(s)
 *        _getswitchar - gets the MS-DOS switch character
 *        _setswitchar - sets the MS-DOS switch character
 * note : these functions are undocumented in the Reference Guide
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */


#include <dos.h>

/*---------------------------------------------------------------------*

Name            _getswitchar - gets the MS-DOS switch character

Usage           char _getswitchar(void);

Prototype in    dos.h

Description     _getswitchar returns the current MS-DOS switch character
                value.

Return value    the current MS-DOS switch character value.

*---------------------------------------------------------------------*/
int _getswitchar(void)
{
    _AX = 0x3700;
    geninterrupt(0x21);
    return(_DL);
}

/*---------------------------------------------------------------------*

Name            _setswitchar - sets the MS-DOS switch character

Usage           void _setswitch(char byte);

Prototype in    dos.h

Description     _setswitchar set the current MS-DOS switch character
                value to the value of byte.  This call uses the
                undocumented MS-DOS system call 0x37, and works for
                MS-DOS versions 2.0 to 3.0 (Future versions of MS-DOS
                may alter or discontinue this call.)

Return value    Nothing

*---------------------------------------------------------------------*/
void _setswitchar(char ch)
{
    _AX = 0x3701;
    _DL = ch;
    geninterrupt(0x21);
}
