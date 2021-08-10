/*-----------------------------------------------------------------------*
 * filename - _fdopen.c
 *
 * function(s)
 *        _fdopen        - associates a stream with a file handle
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
#include <_io.h>

/*---------------------------------------------------------------------*

Name            _fdopen -  associates a stream with a file handle

Usage           FILE *_fdopen(int handle, char *type);

Prototype in    _stdio.h (fdopen declared in stdio.h)

Description     This is the internal entry point for fdopen.
                See fopen for details.

*---------------------------------------------------------------------*/

FILE * _RTLENTRY _fdopen (int handle, char *type)
{
    register FILE   *fp;

    _lock_all_streams();

    if (handle < 0)
        fp = NULL;
    else if ((fp = __getfp()) != NULL)
    {
        fp->fd = handle;
        fp = __openfp (fp, NULL, type, 0);
    }

    _unlock_all_streams();
    return (fp);
}
