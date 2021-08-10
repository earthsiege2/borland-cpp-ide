/*---------------------------------------------------------------------------
 * filename - getdcwd.c
 *
 * function(s)
 *        getdcwd - gets current directory for specified drive
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>

#include <direct.h>
#include <dos.h>
#include <errno.h>
#include <_io.h>
#include <stdlib.h>
#include <string.h>

extern unsigned _ostype;  // Undocumented.  Look at changes to _osmode.

/*---------------------------------------------------------------------*

Name            _getdcwd - gets working directory for specific drive

Usage           char *_getdcwd(int drive, char *buf, int n);

Prototype in    dir.h

Description     _getdcwd gets the full path name of the working directory
                of the specified drive (including the drive name), up to n
                bytes long, and stores it in buf. If the full path name length
                (including the null-terminator) is longer than n, an
                error occurs.  The drive is 0 for the default drive, 1=A,
                2=B, etc.

                If buf is NULL, a buffer n bytes long will be allocated
                for you with malloc. You can later free the allocated buffer
                by passing the _getdcwd return value to the function free.

Return value    _getdcwd returns buf; on error, it returns NULL.

                In the event of an error return, the global variable errno is
                set to one of the following:

                        ENOMEM  Not enough core
                        ERANGE  Result out of range

*---------------------------------------------------------------------*/

char * _RTLENTRY _EXPFUNC _getdcwd(int drive, char *bufP, int bufL)
{
    int     size;
    char    bufI[_MAX_DIR + 3];
    char    envname[4];
    unsigned drivemask;

    /* If the default drive is specified, simply use GetCurrentDirectory.
     */
    if (drive == 0)
    {
        size = (int)GetCurrentDirectory(sizeof(bufI), bufI);
        if (size == 0 || size > bufL)
        {
            errno = ENOMEM;
            return((char *)NULL);
        }
    }
    else if (_ostype == 2)          /* MS-DOS */
    {
        /* Use DOS call 47H to get the specified directory.
         */
        bufI[0] = drive + 'A' - 1;
        bufI[1] = ':';
        bufI[2] = '\\';
        bufI[3] = '\0';
        _ESI = (long)bufI+3;
        _DL  = drive;
        _AH  = 0x47;
        geninterrupt(0x21);
        if (_FLAGS & 1)         /* carry indicates error */
            return NULL;
    }
    else                            /* WinNT */
    {
        drivemask = GetLogicalDrives();
        if (drivemask & (1 << (drive-1)))
        {
                
            /* Construct environment variable name for the specified drive.
             */
            envname[0] = '=';
            envname[1] = drive + 'A' - 1;
            envname[2] = ':';
            envname[3] = '\0';

            /* The environment variable =D:, where D is the drive, contains
             * the current directory for that drive.
             */
            if (GetEnvironmentVariable(envname, bufI, sizeof(bufI)) == 0)
            {
                /*  The environment variable was not found, assume the current
                 * directory is the root.
                 */
                bufI[0] = envname[1];
                bufI[1] = ':';
                bufI[2] = '\\';
                bufI[3] = '\0';
            }
        }
        else
            return NULL;
                
    }

    /* If the buffer length is too small to contain the directory name,
     * return an error.
     */
    if (strlen(bufI) >= bufL)
    {
        errno = ERANGE;
        return  NULL;
    }

    /* Allocate a buffer if bufP is NULL.
     */
    if (bufP == NULL)
    {
        if ((bufP = malloc(bufL)) == NULL)
        {
            errno = ENOMEM;
            return  NULL;
        }
    }
    strcpy(bufP, bufI);
    return  bufP;
}
