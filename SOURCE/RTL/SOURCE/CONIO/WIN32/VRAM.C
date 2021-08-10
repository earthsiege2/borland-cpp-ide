/*-----------------------------------------------------------------------*
 * filename - vram.c
 *
 * function(s)
 *        __putline  - moves bytes to video RAM
 *        __getline  - fetches bytes from video RAM
 *        __moveline - moves bytes from one video RAM line to another
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
#include <string.h>

#define BUF_SIZE    80      /* size of CHAR_INFO buffer */

/*-----------------------------------------------------------------------*

Name            __putline - moves bytes to video RAM

Usage           void __putline (int dx, int dy, void *buffer, int __len);

Prototype in    _video.h

Description     Moves len character-attribute pairs from user buffer
                to video RAM at row dx and column dy.  The bytes must be
                located on a single screen line.

*------------------------------------------------------------------------*/

void __putline (int dx, int dy, void *buffer, int len)
{
    CHAR_INFO ch[BUF_SIZE]; /* character info buffer */
    CHAR_INFO *chp;
    COORD bs;               /* buffer size */
    COORD bc;               /* buffer coordinate */
    SMALL_RECT wr;          /* write region */
    int chunk, i;
    char  *bufp;

    bufp = (char *)buffer;
    while (len != 0)
    {
        /* Output the data in buffer-sized chunks.
         */
        chunk = len > BUF_SIZE ? BUF_SIZE : len;

        /* Convert the buffer, which is in IBM PC screen format,
         * to NT CHAR_INFO format.
         */
        for (i = 0, chp = ch; i < chunk; i++, chp++)
        {
            chp->Char.AsciiChar = *bufp++;
            chp->Attributes     = *bufp++;
        }

        /* Copy the converted data to the screen.
         */
        bs.X = chunk;
        bs.Y = 1;
        bc.X = 0;
        bc.Y = 0;
        wr.Left   = dx - 1;
        wr.Top    = wr.Bottom = dy - 1;
        wr.Right  = dx + chunk;
        if (WriteConsoleOutput(_hout, ch, bs, bc, &wr) != TRUE)
            return;

        /* Advance to the next chunk of data.
         */
        bufp += chunk;
        len -= chunk;
        dx += chunk;
    }
}

/*-----------------------------------------------------------------------*

Name            __getline - fetches bytes from video RAM

Usage           void __getline (void *buffer, int sx, int sy, int __len);

Prototype in    _video.h

Description     Moves len character-attribute pairs to user buffer
                from video RAM at row sx and column sy.  The bytes must be
                located on a single screen line.

*------------------------------------------------------------------------*/

void __getline (void *buffer, int sx, int sy, int len)
{
    CHAR_INFO ch[BUF_SIZE]; /* character info buffer */
    CHAR_INFO *chp;
    COORD bs;               /* buffer size */
    COORD bc;               /* buffer coordinate */
    SMALL_RECT rr;          /* read region */
    int chunk, i;
    char  *bufp;

    bufp = (char *)buffer;
    while (len != 0)
    {
        /* Read the data from the screen in buffer-sized chunks.
         */
        chunk = len > BUF_SIZE ? BUF_SIZE : len;

        /* Copy the converted data from the screen to our local buffer.
         */
        bs.X = chunk;
        bs.Y = 1;
        bc.X = 0;
        bc.Y = 0;
        rr.Left   = sx - 1;
        rr.Top    = rr.Bottom = sy - 1;
        rr.Right  = sx + chunk;

        if (ReadConsoleOutput(_hout, ch, bs, bc, &rr) != TRUE)
            return;

        /* Convert the buffer, which is in NT CHAR_INFO format, to
         * IBM PC screen format.
         */
        for (i = 0, chp = ch; i < chunk; i++, chp++)
        {
            *bufp++ = chp->Char.AsciiChar;
            *bufp++ = chp->Attributes;
        }

        /* Advance to the next chunk of data.
         */
        bufp += chunk;
        len -= chunk;
        sx += chunk;
    }
}

/*-----------------------------------------------------------------------*

Name            __moveline - moves bytes from one video RAM line to another

Usage           void __moveline (int dx, int dy, int sx, int sy, int __len);

Prototype in    _video.h

Description     Moves len character-attribute pairs from one line in
                the video RAM at row sy and column sx to another line at
                row dy and column dx.  The bytes must be located on a
                single screen line.

*------------------------------------------------------------------------*/

void __moveline (int dx, int dy, int sx, int sy, int len)
{
    SMALL_RECT sr;      /* scroll rectangle */
    SMALL_RECT cr;      /* clip rectangle */
    COORD      d;       /* destination origin */
    CHAR_INFO  fill;    /* not actually used */

    /* The scroll region is the source rectangle.
     */
    sr.Left  = sx - 1;
    sr.Top   = sr.Bottom = sy - 1;
    sr.Right = sx + len;

    /* The destination origin is simply (dx, dy).
     */
    d.X = dx - 1;
    d.Y = dy - 1;

    /* The clip region is the destination rectangle.  This prevents
     * the scroll region from being filled.
     */
    cr.Left  = dx - 1;
    cr.Top   = cr.Bottom = dy - 1;
    cr.Right = dx + len;

    ScrollConsoleScreenBuffer(_hout, &sr, &cr, d, &fill);
}
