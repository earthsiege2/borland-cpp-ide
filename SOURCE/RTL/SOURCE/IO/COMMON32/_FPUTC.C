/*-----------------------------------------------------------------------*
 * filename - _fputc.c
 *
 * function(s)
 *      _fputc   - puts a character on a stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.3  $        */

#include <stdio.h>
#include <_stdio.h>
#include <_io.h>
#include <_tchar.h>

/*---------------------------------------------------------------------*

Name            __fputtc used as _fputc and _fputwc
                _fputc  - puts a character on a stream
                _fputwc - puts a wide character on a stream
                                                   
Usage           int _fputc(char ch, FILE *stream);
                wint_t _fputwc(wchar_t ch, FILE *stream);

Prototype in    stdio.h

Description     this function is only called by the putc() macro. The
                only purpose for this is to decrement the level
                indicator before calling fputc().

Return value    On success it returns the character ch

                On error, it returns EOF.

*---------------------------------------------------------------------*/

_TINT _RTLENTRY _EXPFUNC __fputtc( _TCHAR ch,  FILE *fp )
{    
    fp->level -= sizeof(_TCHAR);

    return( _fputtc( ch, fp ) );
}
