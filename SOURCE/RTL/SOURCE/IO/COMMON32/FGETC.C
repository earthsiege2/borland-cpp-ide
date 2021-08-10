/*-----------------------------------------------------------------------*
 * filename - fgetc.c
 *
 * function(s)
 *    fgetc       - gets character from stream with locking 
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

/*---------------------------------------------------------------------*

Name            fgetc - gets character from stream with locking

Usage           int getc(FILE *stream);

Prototype in    stdio.h

Description     behaves exactly like getc, except that it is a true
                function while getc is a macro.

Return value    the character read, after converting it to an int
                without sign extension.  On end-of-file or error,
                returns EOF

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC fgetc (FILE  *fp)
{
    int ret;

    _lock_stream(fp);
    ret = _lgetc(fp);
    _unlock_stream(fp);
    return (ret);
}
