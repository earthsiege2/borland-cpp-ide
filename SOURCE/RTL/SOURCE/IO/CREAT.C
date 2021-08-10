/*---------------------------------------------------------------------------
 * filename - creat.c
 *
 * function(s)
 *        creat - creates a new file or rewrites an existing one
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.6 $        */

#include <_io.h>
#include <fcntl.h>
#include <_tchar.h>
#include <sys\stat.h>
#include <errno.h>

/*--------------------------------------------------------------------------*

Name            _tcreat used as creat and _wcreat
                creat   - creates a new file or rewrites an existing one
                _wcreat - creates a new file or rewrites an existing one

Usage           int creat(const char *filename, int permiss);
                int _wcreat(const wchar_t *filename, int permiss);

Prototype in    io.h

Description     creates a new file or prepares to rewrite an existing
                file named by the string pointed to by filename. permiss
                only applies to newly created files.

Return value    success : the new file handle
                else : -1 and errno is set to one of the following:

                        ENOENT  Path or file name not found
                        EMFILE  Too many open files
                        EACCES  Permission denied

*---------------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC _tcreat(const _TCHAR *path, register int mode)
{
    /* Test that mode is valid or zero */
    if ( (mode != 0)             &&
        ((mode & S_IFDIR ) == 0) &&
        ((mode & S_IFIFO ) == 0) &&
        ((mode & S_IFCHR ) == 0) &&
        ((mode & S_IFREG ) == 0) &&
        ((mode & S_IREAD ) == 0) &&
        ((mode & S_IWRITE) == 0) &&
        ((mode & S_IEXEC ) == 0))
    {
        errno = EACCES;
        return -1;
    }

    /* NOTE: O_RDWR is required for compatibility with BC++ for DOS and MSC,
     * but is incompatible with POSIX (which requires O_WRONLY).
     */
    return ___topen(path, O_RDWR | O_CREAT | O_TRUNC, mode);
}
