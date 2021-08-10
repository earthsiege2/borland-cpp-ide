/*------------------------------------------------------------------------
 * filename - cputn.c
 *
 * function(s)
 *    __cputn - character output function
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1991, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.2  $        */

#ifdef __OS2__
#  define INCL_VIO
#  include <os2bc.h>
#else
#  define INCL_CON
#  include <ntbc.h>
#endif

#include <conio.h>
#include <stdio.h>
#if defined(_MBCS)
#include <mbctype.h>
#endif
#include <_printf.h>
#include <_video.h>
#if !defined(__OS2__) && defined(_MBCS)
#include <_thread.h>
#endif

#define BELL        '\a'
#define BACKSPACE   '\b'
#define LINEFEED    '\n'
#define CR          '\r'

#if defined(_MBCS)
#define MAXCELLBUF 80
#else
#ifdef __WIN32__
#  define MAXCELLBUF 32
#endif
#endif

/* Structure used to pass information about a string to be written
 * to the screen.
 */
typedef struct
{
    int col, row;               /* cursor column and row */
#if defined(_MBCS)
    int len;
    int *pending_lead_byte;
#ifdef __OS2__
    uchar str[MAXCELLBUF];
#else
    CHAR_INFO aCell[MAXCELLBUF];
#endif
#else
    uchar *start, *end;         /* pointer to start and end of string */
#endif
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
#if defined(_MBCS)

#ifdef __OS2__
    BYTE attr;
#else
    COORD size, coord;
    SMALL_RECT region;
#endif

    if (s->len == 0)    /* no characters to flush? */
        return;
#ifdef __OS2__
    attr = (BYTE)_video.attribute;
    VioWrtCharStrAtt((PCHAR16) s->aStr, (USHORT) s->len,
                     (USHORT) s->row, (USHORT) s->col - s->len,
                     (PBYTE16) &attr, (HVIO) 0);
#else
    size.X = s->len;
    size.Y = 1;
    coord.X = 0;
    coord.Y = 0;
    region.Left = s->col - s->len;
    region.Right = s->col - 1;
    region.Top = region.Bottom = s->row;
    WriteConsoleOutput(_hout, &s->aCell[0], size, coord, &region);
#endif
    s->len = 0;

#else /* _MBCS */
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
#endif
}

/*---------------------------------------------------------------------*

Name            __cputn - character output function

Description     prints a string of n chars on the screen

Return value    returns last character printed

Note            template must match putnF typedef from _printf.h
                Note: the last param: eos_flag is not used.

*------------------------------------------------------------------------*/

#pragma warn -par

unsigned __cputn (const void *str, unsigned n, void *dontCare /*, int eos_flag */)
{
    STRINGINFO s;
    unsigned char c = 0;
#if defined(_MBCS)
#ifndef _MT
    static int pending_lead_byte_data = 0;
#endif
#else
    int special;
#endif

    s.col = _wherex();
    s.row = _wherey();
#if defined(_MBCS)
    s.len = 0;
#ifdef _MT
    s.pending_lead_byte = &_thread_data()->thread_lead_byte;
#else
    s.pending_lead_byte = &pending_lead_byte_data;
#endif
#else
    s.start = s.end = (unsigned char *)str;
#endif

    while (n--)
    {
#if defined(_MBCS)
        switch (c = *((unsigned char *)str)++)
#else
        special = 1;        /* assume special character */
        switch (c = *s.end)
#endif
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
#if defined(_MBCS)
            if (*s.pending_lead_byte)
            {
                /* couldn't output DBCS character on 1-column window */
                if (_video.windowx2 - _video.windowx1 >= 1)
                {
                    if (s.len+2 > MAXCELLBUF)
                        flush(&s);
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
                    if (s.col == _video.windowx2)
                    {
#ifdef __OS2__
                        s.aStr[s.len] = ' ';
#else
                        s.aCell[s.len].Char.AsciiChar = ' ';
                        s.aCell[s.len].Attributes = _video.attribute;
#endif
                        s.len++;
                        s.col++;
                    }
                    else
                    {
#ifdef __OS2__
                        s.aStr[s.len] = *s.pending_lead_byte;
                        s.aStr[s.len+1] = c;
#else
                        s.aCell[s.len].Char.AsciiChar = *s.pending_lead_byte;
                        s.aCell[s.len].Attributes = _video.attribute;
                        s.aCell[s.len+1].Char.AsciiChar = c;
                        s.aCell[s.len+1].Attributes = _video.attribute;
#endif
                        s.len += 2;
                        s.col += 2;
                    }
                }
                *s.pending_lead_byte = 0;
            }
            else if (_ismbblead(c))
                *s.pending_lead_byte = c;
            else
            {
#ifdef __OS2__
                s.aStr[s.len] = c;
#else
                s.aCell[s.len].Char.AsciiChar = c;
                s.aCell[s.len].Attributes = _video.attribute;
#endif
                s.len++;
                s.col++;
            }
#else /* _MBCS */
            special = 0;
            s.col++;
#endif
            break;
        } /* end switch */

#if defined(_MBCS)
        if (s.len >= MAXCELLBUF)
            flush(&s);
#else
        s.end++;
        if (special)
            s.start = s.end;        /* skip over the special character */

#ifdef __WIN32__
        if (s.end - s.start >= MAXCELLBUF)
            flush(&s);
#endif
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
