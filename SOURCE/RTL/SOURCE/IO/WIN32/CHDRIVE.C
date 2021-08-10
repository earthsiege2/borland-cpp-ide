/*---------------------------------------------------------------------------
 * filename - _chdrive.c
 *
 * function(s)
 *        _chdrive   - change the current working drive
 *        _getrive   - get the current working drive
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1991, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>

#include <stdlib.h>
#include <errno.h>
#include <_io.h>

/*--------------------------------------------------------------------------*

Name            _chdrive - sets current drive

Usage           int _chdrive(int drive);

Prototype in    dir.h

Description     sets the current drive.
                1 = A:, 2 = B:, 3 = C:; etc.

Return value    0 if drive changed successfully, -1 if error.

Note            Compatible with MSC. Not the same as setdisk().

*---------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _chdrive(int drive)
{
    int     rc;
    char    envname[4];
    char    *buf;

    /* Allocate a buffer big enough to hold the value of a "drive"
     * environment variable.
     */
    if ((buf = malloc(MAX_PATH)) == NULL)
    {
enomem:
        errno = ENOMEM;
        return -1;
    }

    /* Construct environment variable name for the specified drive.
     */
    envname[0] = '=';
    envname[1] = drive + 'A' - 1;
    envname[2] = ':';
    envname[3] = '\0';

    /* The value of the environment variable =D:, where D is the drive,
     * is the current directory for that drive.
     */
    if (GetEnvironmentVariable(envname, buf, MAX_PATH) == 0)
    {
        /* An environment variable for this drive has not been defined.
         * Create one with the root directory as its value.
         */
        buf[0] = envname[1];
        buf[1] = ':';
        buf[2] = '\\';
        buf[3] = '\0';
        if (SetEnvironmentVariable(envname, buf) != TRUE)
        {
            free(buf);
            return (__NTerror());
        }
    }

    /* Set the current drive by setting the current directory.
     */
    if (SetCurrentDirectory(buf) != TRUE)
        rc = __NTerror();
    else
        rc = 0;
    free(buf);
    return (rc);
}

/*--------------------------------------------------------------------------*

Name            _getdrive - sets current drive

Usage           int _getdrive(int drive);

Prototype in    dir.h

Description     gets the current drive.
                1 = A:, 2 = B:, 3 = C:; etc.

Return value    If successful, the drive number; -1 if error.

Note            Compatible with MSC. Not the same as getdisk().

*---------------------------------------------------------------------------*/

int _getdrive()
{
    char *buf;
    int   drive;
    int   size;

    /* Allocate a buffer big enough to hold the current directory path.
     * Then get the current directory.
     */
    if ((buf = malloc(MAX_PATH)) == NULL)
    {
enomem:
        errno = ENOMEM;
        return -1;
    }
    size = (int)GetCurrentDirectory(MAX_PATH, buf);
    if (size == 0 || size > MAX_PATH)
        goto enomem;

    /* Parse the drive name to get the drive number.
     */
    drive = buf[0];
    if (buf[1] == ':')
    {
        if (drive >= 'A' && drive <= 'Z')
            drive = drive - 'A' + 1;
        else if (drive >= 'a' && drive <= 'z')
            drive = drive - 'a' + 1;
        else
            drive = 0;      /* something strange about the drive name */
    }
    free(buf);
    return (drive);
}
