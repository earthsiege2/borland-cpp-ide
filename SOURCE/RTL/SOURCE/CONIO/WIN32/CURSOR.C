/*-----------------------------------------------------------------------*
 * filename - cursor.c
 *
 * function(s)
 *        setcursortype - sets the text cursor type.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1991, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

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
        info.dwSize = 100;
        info.bVisible = TRUE;
        break;
    case _NORMALCURSOR:
        info.dwSize = 25;
        info.bVisible = TRUE;
        break;
    }
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
