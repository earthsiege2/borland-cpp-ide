/*-----------------------------------------------------------------------*
 * filename - _wherexy.c
 *
 * function(s)
 *        _wherex - gives absolute horizontal cursor position
 *        _wherey - gives absolute vertical cursor position
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#define INCL_CON
#include <ntbc.h>

#include <_video.h>
#include <conio.h>

/*---------------------------------------------------------------------*

Name            _wherex - returns the horizontal cursor position

Usage           unsigned _wherexy(void);

Prototype in    _video.h

Return value    an unsigned integer holding the horizontal coordinate
                (0 is the leftmost position).

*---------------------------------------------------------------------*/

unsigned _wherex(void)
{
    CONSOLE_SCREEN_BUFFER_INFO info;

    if (GetConsoleScreenBufferInfo(_hout, &info) == TRUE)
        return info.dwCursorPosition.X;
    else
        return 0;
}

/*---------------------------------------------------------------------*

Name            _wherey - returns the vertical cursor position

Usage           unsigned _wherey(void);

Prototype in    _video.h

Return value    an unsigned integer holding the vertical coordinate
                (0 is the topmost position).

*---------------------------------------------------------------------*/

unsigned _wherey(void)
{
    CONSOLE_SCREEN_BUFFER_INFO info;

    if (GetConsoleScreenBufferInfo(_hout, &info) == TRUE)
        return info.dwCursorPosition.Y;
    else
        return 0;
}
