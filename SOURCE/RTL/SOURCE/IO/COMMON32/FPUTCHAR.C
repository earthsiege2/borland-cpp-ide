/*-----------------------------------------------------------------------*
 * filename - fputchar.c
 *
 * function(s)
 *      fputchar - puts a character to stdout
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>
#include <_stdio.h>

/*---------------------------------------------------------------------*

Name            fputchar - puts a character to stdout


Usage           int fputchar (register int c);

Prototype in    stdio.h

Description     fputchar simply calls fputc to output its argument to
                stdout.

Return value    see fgetc.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC fputchar (int ch)
{
    int ret;

    _lock_stream(stdout);
    ret = _lputc(ch,stdout);
    _unlock_stream(stdout);
    return (ret);
}
