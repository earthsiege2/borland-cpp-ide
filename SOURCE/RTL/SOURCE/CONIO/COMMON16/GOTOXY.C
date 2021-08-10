/*-----------------------------------------------------------------------*
 * filename - gotoxy.c
 *
 * function(s)
 *        gotoxy - moves the text cursor.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#include <_video.h>
#include <conio.h>

/*------------------------------------------------------------------------

Name            gotoxy - moves the text cursor

Usage           void gotoxy(int column, int row)

Prototype in    conio.h

Description     Moves the text cursor to location (x, y) in the current window.

*------------------------------------------------------------------------*/

void gotoxy(int column, int row)
{
        uchar r,c;

        /* translate to physical coord */
        r = row-1; r += _video.windowy1;
        c = column-1; c += _video.windowx1;

        if ((r < _video.windowy1) || (r > _video.windowy2) || ( c < _video.windowx1) || (c > _video.windowx2))
                return;

        _DL = c;
        _DH = r;
        _AH = V_SET_CURSOR_POS;
        _BH = 0;
        _VideoInt();
} /* gotoxy */
