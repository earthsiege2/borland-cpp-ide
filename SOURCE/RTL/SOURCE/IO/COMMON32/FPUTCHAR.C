/*-----------------------------------------------------------------------*
 * filename - fputchar.c
 *
 * function(s)
 *      fputchar - puts a character to stdout
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.4  $        */

#include <stdio.h>
#include <_stdio.h>
#include <_tchar.h>

/*---------------------------------------------------------------------*

Name            _fputtchar used as _fputchar and _fputwchar
                _fputchar   - puts a character to stdout
                _fputwchar - puts a wide character to stdout


Usage           int _fputchar (register int c);
                wint_t _fputwchar (register wint_t c);

Prototype in    stdio.h

Description     _fputtchar simply calls _lputtc to output its argument to
                stdout.

Return value    see _fgettc.

*---------------------------------------------------------------------*/

_TINT _RTLENTRY _EXPFUNC _fputtchar (_TINT ch)
{
    _TINT ret;

    _lock_stream(stdout);
    ret = _lputtc(ch,stdout);
    _unlock_stream(stdout);
    return (ret);
}
