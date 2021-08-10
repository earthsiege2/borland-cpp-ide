/*------------------------------------------------------------------------
 * filename - cputn.c
 *
 * function(s)
 *    __cputn - character output function
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1991, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#ifdef __OS2__
#  define INCL_VIO
#  include <os2bc.h>
#else
#  define INCL_CON
#  include <ntbc.h>
#endif

#include <conio.h>
#include <stdio.h>
#include <_printf.h>
#include <_video.h>

#define BELL        '\a'
#define BACKSPACE   '\b'
#define LINEFEED    '\n'
#define CR          '\r'

#ifdef __WIN32__
#  define MAXCELLBUF 32
#endif

/* Structure used to pass information about a string to be written
 * to the screen.
 */
typedef struct
{
    int col, row;               /* cursor column and row */
    uchar *start, *end;         /* pointer to start and end of string */
} STRINGINFO;

/*---------------------------------------------------------------------*

Name            flush - flush a string of characters to video screen

Description     Writes the string of characters from s->start to s->end
                to the screen at coordinates s->row and (s->col - length
                of string).  The characters are assumed to lie in a
                single row, and on WIN32, there must not be more than
                MAXCELLBUF characters.  After the string is written,
                s->start is updated to be equal to s->end.

Return value    none

*------------------------------------------------------------------------*/

static void flush(STRINGINFO *s)
{
    int len;
#ifdef __OS2__
    BYTE attr;
#else
    CHAR_INFO aCell[MAXCELLBUF];
    COORD size, coord;
    SMALL_RECT region;
    int i;
#endif

    if ((len = s->end - s->start) == 0)     /* no characters to flush? */
        return;
#ifdef __OS2__
    attr = (BYTE)_video.attribute;
    VioWrtCharStrAtt((PCHAR16) s->start, (USHORT) len,
                     (USHORT) s->row, (USHORT) s->col - len,
                     (PBYTE16) &attr, (HVIO) 0);
#else
    for (i = 0; i < len; i++)
    {
        aCell[i].Char.AsciiChar = s->start[i];
        aCell[i].Attributes = _video.attribute;
    }
    size.X = len;
    size.Y = 1;
    coord.X = 0;
    coord.Y = 0;
    region.Left = s->col - len;
    region.Right = s->col - 1;
    region.Top = region.Bottom = s->row;
    WriteConsoleOutput(_hout, &aCell[0], size, coord, &region);
#endif
    s->start = s->end;
}

/*---------------------------------------------------------------------*

Name            __cputn - character output function

Description     prints a string of n chars on the screen

Return value    returns last character printed

Note            template must match putnF typedef from _printf.h

*------------------------------------------------------------------------*/

#pragma warn -par

unsigned __cputn (const void *str, unsigned n, void *dontCare)
{
    STRINGINFO s;
    unsigned char c = 0;
    int special;

    s.col = _wherex();
    s.row = _wherey();
    s.start = s.end = (unsigned char *)str;

    while (n--)
    {
        special = 1;        /* assume special character */
        switch (c = *s.end)
        {
        case BELL:
            flush(&s);
            {
#ifdef __OS2__
                DosBeep(3000, 100);
#else
                Beep(3000, 100);
#endif
            }
            break;

        case BACKSPACE :
            flush(&s);
            if (s.col > _video.windowx1)
                s.col--;
            break;

        case CR :
            flush(&s);
            s.col = _video.windowx1;
            break;

        case LINEFEED :
            flush(&s);
            ++s.row;
            break;

        default :
            special = 0;
            s.col++;
            break;
        } /* end switch */

        s.end++;
        if (special)
            s.start = s.end;        /* skip over the special character */

#ifdef __WIN32__
        if (s.end - s.start >= MAXCELLBUF)
            flush(&s);
#endif

        if (s.col > _video.windowx2)      /* line wrap? */
        {
            flush(&s);
            s.col = _video.windowx1;
            s.row += _wscroll;
        }

        if (s.row > _video.windowy2)      /* screen wrap? */
        {
            flush(&s);
            __scroll(UP, _video.windowx1, _video.windowy1,
                    _video.windowx2, _video.windowy2, 1);
            s.row--;
        }
    } /* end while */

    flush(&s);
    __movecursor(s.col, s.row);

    return c;
}

#pragma warn .par
