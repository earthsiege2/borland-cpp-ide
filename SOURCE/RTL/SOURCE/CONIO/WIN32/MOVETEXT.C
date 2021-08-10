/*-----------------------------------------------------------------------*
 * filename - movetext.c
 *
 * function(s)
 *        movetext - copies text from one rectangle to another.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#define INCL_CON
#include <ntbc.h>

#include <_video.h>
#include <conio.h>

/*---------------------------------------------------------------------*

Name            movetext - copies text from one rectangle to another.

Usage           int movetext(int sx1, int sy1, int sx2, int sy2, int dx1,
                             int dy1);

Prototype in    conio.h

Description     movetext copies the contents of the on screen rectangle
                {sx1, sy1, sx2, sy2} to a source rectangle of the same
                dimensions which has its upper left hand corner at dx1, dy1.

Return value    on success, one is returned; zero is returned on failure.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC movetext(int sx1, int sy1, int sx2, int sy2, int dx1, int dy1)
{
    SMALL_RECT sr;      /* scroll rectangle */
    SMALL_RECT cr;      /* clip rectangle */
    COORD      d;       /* destination origin */
    CHAR_INFO  fill;    /* not actually used */

    if (!__validatexy(sx1,sy1,sx2,sy2) ||
        !__validatexy(dx1,dy1,dx1+(sx2-sx1),dy1+(sy2-sy1)))
        return 0;

    /* The scroll region is the source rectangle.
     */
    sr.Left   = sx1 - 1;
    sr.Top    = sy1 - 1;
    sr.Right  = sx2 - 1;
    sr.Bottom = sy2 - 1;

    /* The destination origin is simply (dx1, dy1).
     */
    d.X = dx1 - 1;
    d.Y = dy1 - 1;

    /* The clip region is the destination rectangle.  This prevents
     * the scroll region from being filled.
     */
    cr.Left   = dx1 - 1;
    cr.Top    = dy1 - 1;
    cr.Right  = cr.Left + (sx2 - sx1);
    cr.Bottom = cr.Top  + (sy2 - sy1);

    ScrollConsoleScreenBuffer(_hout, &sr, &cr, d, &fill);

#if 0   /* old code */
    int first, last, direction, y;

    first = sy1;
    last = sy2;
    direction = 1;

    if (sy1 < dy1)
    {
        first = sy2;
        last = sy1;
        direction = -1;
    }

    for (y = first; y != last + direction; y += direction)
        __moveline(dx1, dy1+(y-sy1), sx1, y, sx2-sx1+1);
#endif

    return 1;
}
