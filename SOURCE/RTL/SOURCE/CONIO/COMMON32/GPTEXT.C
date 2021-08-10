/*-----------------------------------------------------------------------*
 * filename - gptext.c
 *
 * function(s)
 *        gettext  - gets a character block from screen
 *        puttext  - puts a character block on the screen
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <_video.h>
#include <conio.h>

/*---------------------------------------------------------------------*

Name            gettext  - gets a character block from screen

Usage           int gettext(int left, int top, int right, int bottom,
                            void *buffer)

Prototype in    conio.h

Description     Reads the contents of the rectangle defined by its screen
                coordinate arguments and stores the characters and attribute
                bytes in the memory referenced by buffer.

Return value    On success, one is returned;  zero on failure.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC gettext(int left, int top, int right, int bottom, void *buffer)
{
        int y, size;

        if (!__validatexy(left, top, right, bottom))
                return 0;

        size = right-left+1;
        for (y = top; y <= bottom; y++)
        {
                __getline(buffer, left, y, size);
                buffer = (void *)((char *)buffer + size*2);
        }
        return 1;
}

/*---------------------------------------------------------------------*

Name            puttext  - places a character block on screen

Usage           int puttext(int left, int top, int right, int bottom,
                            void *buffer)

Prototype in    conio.h

Description     Places the contents of memory pointed to by buffer into
                the rectangle defined by its screen coordinate arguments.

Return value    On success, one is returned;  zero on failure.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC puttext(int left, int top, int right, int bottom, void *buffer)
{
        int y, size;

        if (!__validatexy(left, top, right, bottom))
                return 0;

        size = right-left+1;
        for (y = top; y <= bottom; y++)
        {
                __putline(left, y, buffer, size);
                buffer = (void *)((char *)buffer + size*2);
        }
        return 1;
}
