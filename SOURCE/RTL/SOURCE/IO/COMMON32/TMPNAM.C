/*-----------------------------------------------------------------------*
 * filename - tmpnam.c
 *
 * function(s)
 *        tmpnam   - builds a unique file name
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

Name            tmpnam - builds a unique file name

Usage           char *tmpnam(char *s);

Prototype in    stdio.h

Return value    a unique temporary file name

*---------------------------------------------------------------------*/

char * _RTLENTRY _EXPFUNC tmpnam(char *s)
{
    _lock_all_streams();

    s = __tmpnam(s, &_tmpnum);

    _unlock_all_streams();
    return (s);
}
