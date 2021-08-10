/*------------------------------------------------------------------------
 * filename - clreol.c
 *
 * function(s)
 *        clreol - Clears to the end of the line in the text window
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#define INCL_CON
#include <ntbc.h>

#include <_video.h>
#include <conio.h>

/*------------------------------------------------------------------------*

Name            clreol - Clears to the end of the line in text window

Usage           void clreol(void)

Prototype in    conio.h

Description     clreol clears all characters from the cursor position to
                the end of the line within the current text window without
                moving the cursor.

Return value    None

*--------------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC clreol(void)
{
    COORD c;
    DWORD len, wr;

    c.X = _wherex();
    c.Y = _wherey();
    len = _video.windowx2 - c.X + 1;
    FillConsoleOutputCharacter(_hout, ' ', len, c, &wr);
    FillConsoleOutputAttribute(_hout, _video.attribute, len, c, &wr);
}
