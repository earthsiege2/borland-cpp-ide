/*---------------------------------------------------------------------------
 * filename - dosgdriv.c
 *
 * function(s)
 *        _dos_getdrive - gets current drive
 *        _dos_setdrive - sets current drive
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <ntbc.h>
#include <_io.h>
#include <dos.h>

/*--------------------------------------------------------------------------*

Name            _dos_getdrive - gets current drive

Usage           void _dos_getdrive(unsigned *drive);

Prototype in    dos.h

Description     gets the current drive, stores it at *drive (1=A, 2=B, etc.)

Return value    None.

*---------------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC _dos_getdrive(unsigned *drive)
{
    char    buf[MAX_PATH];

    /* Use GetCurrentDirectory to get the current directory path, then
     * parse the drive name.
     */
    GetCurrentDirectory(sizeof(buf), buf);    /* ignore errors */
    *drive = buf[0] >= 'a' ? buf[0] - 'a' + 1 : buf[0] - 'A' + 1;
}

/*--------------------------------------------------------------------------*

Name            _dos_setdrive - sets current drive

Usage           void _dos_setdrive(unsigned drive, unsigned *ndrives);

Prototype in    dir.h

Description     sets the current drive, where drive is:
                1 = A:, 2 = B:, 3 = C:; etc.  Stores the total
                number of drives in the system at *ndrives.

Return value    none

*---------------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC _dos_setdrive(unsigned drive, unsigned *ndrives)
{
    char envname[4];
    char dir[MAX_PATH];

    /* Set *ndrives to 0.  That way if an error occurs before we get
     * around to setting *ndrives to some reasonable value, the caller
     * will be able to detect it.
     */
    *ndrives = 0;

    /* See if a current directory has been specified for this drive.
     * NT stores the current directory for drive N in the magic environment
     * variable =N:.
     */
    envname[0] = '=';
    envname[1] = drive -1 + 'A';
    envname[2] = ':';
    envname[3] = '\0';
    if (GetEnvironmentVariable(envname, dir, sizeof(dir)) == 0)
    {
        /* The current directory for that drive hasn't been set yet.
         * Set it to the root.
         */
        dir[0] = envname[1];
        dir[1] = ':';
        dir[2] = '\\';
        dir[3] = '\0';
        if (SetEnvironmentVariable(envname, dir) != TRUE)
        {
            __NTerror();        /* set errno */
            return;
        }
    }

    /* Make the specfied drive the current drive by setting the current
     * directory to that drive's current directory.  This has to be done
     * because NT has no concept of "current drive."
     */
    if (SetCurrentDirectory(dir) != TRUE)
    {
        __NTerror();             /* set errno */
        return;
    }

    /* Figure out how many drives exist by trying to do a GetDriveType
     * on all possible drives, and counting those that don't give an error.
     */
    dir[1] = ':';
    dir[2] = '\\';
    dir[3] = '\0';
    for (dir[0] = 'A'; dir[0] <= 'Z'; dir[0]++)
    {
        DWORD type;

        if ((type = GetDriveType(dir)) != 0 && type != 1)
            (*ndrives)++;
    }
    return;
}
