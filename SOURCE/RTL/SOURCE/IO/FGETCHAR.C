/*-----------------------------------------------------------------------*
 * filename - _fgetchar.c
 *
 * function(s)
 *      _fgetchar - gets character from standard input stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <stdio.h>
#include <_stdio.h>
#include <_tchar.h>

/*---------------------------------------------------------------------*

Name            _fgettchar used as _fgetchar and _fgetwchar
                _fgetchar   - gets character from standard intput stream
                _fgetwchar - gets wide character from standard intput stream

Usage           int _fgetchar  (void);
                wint_t _fgetwchar  (void);

Prototype in    stdio.h

Description     the same as fgetc(stdin).

return value    the character read, after converting it to an _TINT
                without sign extension.  On end-of-file or error,
                _fgetchar returns EOF

*---------------------------------------------------------------------*/

_TINT _RTLENTRY _EXPFUNC _fgettchar( void )
{
    _TINT ret;

    _lock_stream(stdin);
    ret = _lgettc(stdin);
    _unlock_stream(stdin);
    return (ret);
}
