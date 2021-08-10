/*-----------------------------------------------------------------------*
 * filename - cursor.c
 *
 * function(s)
 *        setcursortype - sets the text cursor type.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1991, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.5.2.1 $        */

#define INCL_CON
#include <ntbc.h>

#include <_video.h>
#include <conio.h>

void _RTLENTRY _EXPFUNC _setcursortype( int cur_t )
{
    CONSOLE_CURSOR_INFO info;

    switch (cur_t)
    {
    case _NOCURSOR:
        info.dwSize = 1;
        info.bVisible = FALSE;
        break;
    case _SOLIDCURSOR:
        /* Win9x seems to have trouble setting the cursor size to 100%, even
           though NT does it correctly.  So we'll only go up to 99% which
           works everywhere.
        */
        info.dwSize = 99;
        info.bVisible = TRUE;
        break;
    case _NORMALCURSOR:
        info.dwSize = 25;
        info.bVisible = TRUE;
        break;
    }
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
