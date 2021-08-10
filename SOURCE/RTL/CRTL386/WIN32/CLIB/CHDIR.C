/*---------------------------------------------------------------------------
 * filename - chdir.c
 *
 * function(s)
 *        chdir   - changes working directory
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>

#include <_io.h>
#include <dir.h>

/*--------------------------------------------------------------------------*

Name            chdir - changes working directory

Usage           int chdir(const char *path);

Prototype in    dir.h

Description     causes the directory specified by path to become the
                current working directory.

Return value    success : 0
                failure : -1 and errno is set to ENOENT (Path or file
                name not found)

*---------------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC chdir(const char *pathP)
{
#if 0
    char buf[4];
    char drive;

    /* If the path specifies a drive, set the current directory for
     * that drive, but don't change the current directory.
     */
    drive = pathP[0];
    if (drive >= 'a' && drive <= 'z')
        drive = drive - 'a' + 'A';
    if (drive >= 'A' && drive <= 'Z' && pathP[1] == ':')
    {
        /* On NT, you set the current directory for a given drive by
         * setting the magic environment variable =N:, where N is the
         * drive letter.
         */
        buf[0] = '=';
        buf[1] = drive;
        buf[2] = ':';
        buf[3] = '\0';
        if (SetEnvironmentVariable(buf, (char *)pathP) != TRUE)
            return (__NTerror());
    }
    else
#endif
    {
        /* No drive was specified, so let's change the current
         * directory for the current drive.
         */
        if (SetCurrentDirectory((char *)pathP) != TRUE)
            return (__NTerror());
    }
    return(0);
}
