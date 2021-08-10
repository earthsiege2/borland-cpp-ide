/*-----------------------------------------------------------------------*
 * filename - fputc.c
 *
 * function(s)
 *      fputc    - puts a character on a stream with locking
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

Name            _fputtc used as fputc and fputwc
                fputc  - puts a character on a stream with locking
                fputwc - puts a wide character on a stream with locking

Usage           #include <stdio.h>
                int fputc (int ch, FILE *stream);
                int fputwc(wint_t ch, FILE *stream);

Related
functions usage _TINT _lputtc(_TINT ch, FILE *stream);

Prototype in    stdio.h

Description     see _lputtc in lputc.c

Return value    see _lputtc.

*---------------------------------------------------------------------*/

_TINT _RTLENTRY _EXPFUNC _fputtc (_TINT ch, FILE *fp)
{
    _TINT ret;

    _lock_stream(fp);
    ret = _lputtc(ch,fp);
    _unlock_stream(fp);
    return (ret);
}
