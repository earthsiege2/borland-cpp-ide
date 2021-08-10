/*-----------------------------------------------------------------------*
 * filename - _fputc.c
 *
 * function(s)
 *      _fputc   - puts a character on a stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>
#include <_stdio.h>
#include <_io.h>

/*---------------------------------------------------------------------*

Name            _fputc - puts a character on a stream

Usage           int _fputc(int ch, FILE *stream);

Prototype in    stdio.h

Description     this function is only called by the putc() macro. The
                only purpose for this is to decrement the level
                indicator before calling fputc().

Return value    On success it returns the character ch

                On error, it returns EOF.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _fputc( char ch,  FILE *fp )
{
    --fp->level;

    return( fputc( ch, fp ) );
}
