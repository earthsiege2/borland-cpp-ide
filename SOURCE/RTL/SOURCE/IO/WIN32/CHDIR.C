/*---------------------------------------------------------------------------
 * filename - chdir.c
 *
 * function(s)
 *        chdir   - changes working directory
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1991, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>

#include <_io.h>
#include <stdlib.h>
#include <ctype.h>

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
    char buffer[_MAX_PATH];
    char envname[4];
    char drive;

    /* No drive was specified, so let's change the current
     * directory for the current drive.
     */

    if (SetCurrentDirectory((char *)pathP) != TRUE)
	return (__NTerror());

    if (GetCurrentDirectory(sizeof(buffer), buffer) == 0)
	return (__NTerror());

    /* If the path specifies a drive, set the current directory for
     * that drive.
     */
    drive = toupper(buffer[0]);
    if (drive >= 'A' && drive <= 'Z' && buffer[1] == ':')
    {
	/* On NT, you set the current directory for a given drive by
	 * setting the magic environment variable =N:, where N is the
	 * drive letter.
	 */
	envname[0] = '=';
	envname[1] = drive;
	envname[2] = ':';
	envname[3] = '\0';
	if (SetEnvironmentVariable(envname, buffer) != TRUE)
	    return (__NTerror());
    }
    return(0);
}
