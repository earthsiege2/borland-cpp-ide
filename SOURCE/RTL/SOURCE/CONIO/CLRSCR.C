/*------------------------------------------------------------------------
 * filename - clrscr.c
 *
 * function(s)
 *        clrscr - clears text mode window
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#define INCL_CON
#include <ntbc.h>

#include <_video.h>
#include <conio.h>

/*------------------------------------------------------------------------*

Name            clrscr - clears text mode window

Usage           void clrscr(void);

Prototype in    conio.h

Description     clrscr clears the current text window and places the cursor
                in the upper left-hand corner(at position 1,1).

Return value    None

*--------------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC clrscr(void)
{
    COORD c;
    DWORD len, wr;

    if (_video.windowx1 == 0 && _video.windowy1 == 0 &&
        _video.windowx2 == _video.screenwidth - 1 &&
        _video.windowy2 == _video.screenheight - 1)
    {
        /* Window is full-screen, so we can clear it in two calls.
         */
        len = _video.screenwidth * _video.screenheight;
        c.X = c.Y = 0;
        FillConsoleOutputCharacter(_hout, ' ', len, c, &wr);
        FillConsoleOutputAttribute(_hout, _video.attribute, len, c, &wr);
    }
    else
    {
        /* Window is not full-screen, so clear it a line at a time.
         */
        len = _video.windowx2 - _video.windowx1 + 1;
        c.X = _video.windowx1;
        for (c.Y = _video.windowy1; c.Y <= _video.windowy2; c.Y++)
        {
            FillConsoleOutputCharacter(_hout, ' ', len, c, &wr);
            FillConsoleOutputAttribute(_hout, _video.attribute, len, c, &wr);
        }
    }

    gotoxy(1, 1);
}
