/*------------------------------------------------------------------------
 * filename - clearerr.c
 *
 * function(s)
 *        clearerr - resets error indication
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>

/*---------------------------------------------------------------------------*

Name            clearerr - resets error indication

Usage           #include <stdio.h>
                void clearerr(FILE *stream);

Prototype in    stdio.h

Description     clearerr sets the stream's error and end-of-file indicators
                to 0.

Return value    nothing

*---------------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC clearerr (FILE *fp)
{
    fp->flags &= ~(_F_ERR | _F_EOF);
}

