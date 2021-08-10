/*-----------------------------------------------------------------------*
 * filename - fgetchar.c
 *
 * function(s)
 *      fgetchar - gets character from standard input stream
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

Name            fgetchar - gets character from standard intput stream

Usage           int fgetchar  (void);

Prototype in    stdio.h

Description     the same as fgetc(stdin).

return value    the character read, after converting it to an int
                without sign extension.  On end-of-file or error,
                fgetchar returns EOF

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC fgetchar( void )
{
    int ret;

    _lock_stream(stdin);
    ret = _lgetc(stdin);
    _unlock_stream(stdin);
    return (ret);
}
