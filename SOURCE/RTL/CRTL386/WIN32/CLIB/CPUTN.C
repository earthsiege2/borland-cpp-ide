/*------------------------------------------------------------------------
 * filename - cputn.c
 *
 * function(s)
 *    __cputn - character output function
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

#include <conio.h>
#include <stdio.h>
#include <_printf.h>
#include <_video.h>

#define BELL        '\a'
#define BACKSPACE   '\b'
#define LINEFEED    '\n'
#define CR          '\r'


/*---------------------------------------------------------------------*

Name            __cputn - character output function

Description     prints a string of n chars on the screen

Return value    returns last character printed

Note            template must match putnF typedef from _printf.h

*------------------------------------------------------------------------*/

#pragma warn -par

unsigned __cputn (const void *s, unsigned n, void *dontCare)
{
    int col, row;
    unsigned char c = 0;
    CHAR_INFO aCell;
    COORD size, coord;
    SMALL_RECT region;

    col = _wherex();
    row = _wherey();

    while (n--)
    {
        switch (c = *(((char*)s)++))
        {

        case BELL :
            Beep(3000, 100);
            break;

        case BACKSPACE :
            if (col > _video.windowx1)
                col--;
            break;

        case CR :
            col = _video.windowx1;
            break;

        case LINEFEED :
            ++row;
            break;

        default :
            aCell.Char.AsciiChar = c;
            aCell.Attributes = _video.attribute;
            size.X = 1;
            size.Y = 1;
            coord.X = 0;
            coord.Y = 0;
            region.Left = region.Right = col;
            region.Top = region.Bottom = row;
            WriteConsoleOutput(_hout, &aCell, size, coord, &region);
            col++;
            break;
        } /* end switch */

        if (col > _video.windowx2)      /* line wrap? */
        {
            col = _video.windowx1;
            row += _wscroll;
        }

        if (row > _video.windowy2)      /* screen wrap? */
        {
            __scroll(UP, _video.windowx1, _video.windowy1,
            _video.windowx2, _video.windowy2, 1);
            row--;
        }
    } /* end while */

    /* Set final cursor position.
     */
    coord.X = col;
    coord.Y = row;
    SetConsoleCursorPosition(_hout, coord);

    return c;       /* return no. of characters output */
}

#pragma warn .par
