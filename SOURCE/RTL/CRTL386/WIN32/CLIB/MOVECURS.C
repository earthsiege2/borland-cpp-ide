/*-----------------------------------------------------------------------*
 * filename - movecurs.c
 *
 * function(s)
 *        __movecursor - moves the text cursor to absolute position
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

/*------------------------------------------------------------------------

Name            __movecursor - moves the text cursor

Usage           void __movecursor(int column, int row)

Prototype in    _video.h

Description     Moves the text cursor to absolute, zero-based location
                (column, row) on the screen.

*------------------------------------------------------------------------*/

void _RTLENTRY __movecursor(int column, int row)
{
    COORD c;

    c.X = column;
    c.Y = row;
    SetConsoleCursorPosition(_hout, c);
}
