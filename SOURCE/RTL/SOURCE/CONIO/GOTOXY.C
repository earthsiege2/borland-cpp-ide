/*-----------------------------------------------------------------------*
 * filename - gotoxy.c
 *
 * function(s)
 *        gotoxy - moves the text cursor.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <_video.h>
#include <conio.h>

/*------------------------------------------------------------------------

Name            gotoxy - moves the text cursor

Usage           void gotoxy(int column, int row)

Prototype in    conio.h

Description     Moves the text cursor to location (x, y) in the current window.

*------------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC gotoxy(int column, int row)
{
    int r, c;

    /* Translate row and column to physical coordinates,
     * then perform a sanity check.
     */
    r = row    - 1 + _video.windowy1;
    c = column - 1 + _video.windowx1;

    if ((r < _video.windowy1) || (r > _video.windowy2) || ( c < _video.windowx1) || (c > _video.windowx2))
        return;

    __movecursor(c, r);
}
