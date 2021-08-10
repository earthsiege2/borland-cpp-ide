/*-----------------------------------------------------------------------*
 * filename - fgetc.c
 *
 * function(s)
 *    fgetc       - gets character from stream with locking
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.3 $        */

#include <stdio.h>
#include <_stdio.h>
#include <_tchar.h>

/*---------------------------------------------------------------------*

Name            _fgettc used as fgetc and fgetwc
                fgetc  - gets character from stream with locking
                fgetwc - gets (wide) character from stream with locking

Usage           int fgetc(FILE *stream);
                wint_t fgetwc(FILE *stream);

Prototype in    stdio.h

Description     behaves exactly like _gettc, except that it is a true
                function while _gettc is a macro.

Return value    the character read, after converting it to an int
                without sign extension.  On end-of-file or error,
                returns EOF

*---------------------------------------------------------------------*/

_TINT _RTLENTRY _EXPFUNC _fgettc (FILE  *fp)
{
    _TINT ret;

    _lock_stream(fp);
    ret = _lgettc(fp);
    _unlock_stream(fp);
    return (ret);
}
