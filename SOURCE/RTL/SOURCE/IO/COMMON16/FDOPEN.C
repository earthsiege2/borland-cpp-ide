/*-----------------------------------------------------------------------*
 * filename - fdopen.c
 *
 * function(s)
 *        fdopen        - associates a stream with a file handle
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#include <stdio.h>
#include <_stdio.h>

/*---------------------------------------------------------------------*

Name            fdopen -  associates a stream with a file handle

Usage           FILE *fdopen(int handle, char *type);

Prototype in    stdio.h

Description     see fopen

*---------------------------------------------------------------------*/
FILE * _FARFUNC fdopen (int handle, char *type)
{
        register FILE   *fp;

        if (handle < 0 || (fp = __getfp()) == NULL)
                return NULL;

        fp->fd = handle;
        return __openfp (fp, NULL, type, 0);
}
