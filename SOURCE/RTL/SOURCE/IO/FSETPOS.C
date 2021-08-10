/*-----------------------------------------------------------------------*
 * filename - fsetpos.c
 *
 * function(s)
 *        fsetpos - positions the file pointer on a stream
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

/*-----------------------------------------------------------------------*

Name            fsetpos - positions the file pointer on a stream

Usage           #include <stdio.h>
                int fsetpos(FILE *stream, const fpos_t *pos);

Prototype in    stdio.h

Description     sets the file pointer using fseek

Return value    success : 0
                failure : non-zero

*------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC fsetpos(FILE *stream, const fpos_t *pos)
{
    return fseek(stream, *pos, SEEK_SET);
}
