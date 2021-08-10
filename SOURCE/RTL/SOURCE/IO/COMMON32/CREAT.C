/*---------------------------------------------------------------------------
 * filename - creat.c
 *
 * function(s)
 *        creat - creates a new file or rewrites an existing one
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <_io.h>
#include <fcntl.h>

/*--------------------------------------------------------------------------*

Name            creat - creates a new file or rewrites an existing one

Usage           int creat(const char *filename, int permiss);

Prototype in    io.h

Description     creates a new file or prepares to rewrite an existing
                file named by the string pointed to by filename. permiss
                only applies to newly created files.

Return value    success : the new file handle
                else : -1 and errno is set to one of the following:

                        ENOENT  Path or file name not found
                        EMFILE  Too many open files
                        EACCESS Permission denied

*---------------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC creat(const char *path, register int mode)
{
    /* NOTE: O_RDWR is required for compatibility with BC++ for DOS and MSC,
     * but is incompatible with POSIX (which requires O_WRONLY).
     */
    return __open(path, O_RDWR | O_CREAT | O_TRUNC, mode);
}
