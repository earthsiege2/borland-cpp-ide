/*-----------------------------------------------------------------------*
 * filename - validxy.c
 *
 * function(s)
 *        __validatexy - checks the validity of the window coordinates
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <_video.h>

/*---------------------------------------------------------------------*

Name            __validatexy - checks the validity of the screen coordinates

Usage           int __validatexy(int x1, int y1, int x2, int y2);

Return value    __validatexy returns zero if the coordinates are invalid

*---------------------------------------------------------------------*/

int __validatexy(int x1, int y1, int x2, int y2)
{
    int wid, ht;

    wid = _video.screenwidth;
    ht = _video.screenheight;
    return !(x1 > wid || x2 > wid || x1 > x2 ||
             y1 > ht  || y2 > ht  || y1 > y2 ||
             x1 <= 0  || x2 <= 0  || y1 <= 0 || y2 <= 0);
}
