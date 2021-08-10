/*---------------------------------------------------------------------------
 * filename - getdcwd.c
 *
 * function(s)
 *        getdcwd - gets current directory for specified drive
 *        _wgetdcwd - gets current directory for specified drive (wide-character)
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1991, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <ntbc.h>

#include <winbase.h>
#include <direct.h>
#include <dos.h>
#include <errno.h>
#include <_io.h>
#include <stdlib.h>
#include <string.h>
#include <_ostype.h>
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            _getdcwd, _wgetdcwd - gets working directory for specific drive

Usage           char *_getdcwd(int drive, char *buf, int n);
                wchar_t *_wgetdcwd(int drive, wchar_t *buf, int n);

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

_TCHAR * _RTLENTRY _EXPFUNC _tgetdcwd(int drive, _TCHAR *bufP, int bufL)
{
    int     size;
    _TCHAR    bufI[_MAX_DIR + 3];
    _TCHAR    envname[4];
    _TCHAR   *filename;
    unsigned drivemask;

    /* If the default drive is specified, simply use GetCurrentDirectory.
     */
    if (drive == 0)
    {
        size = (int)GetCurrentDirectory(sizeof(bufI)/sizeof(_TCHAR), bufI);
        if (size == 0 || size > bufL)
        {
            errno = ENOMEM;
            return((_TCHAR *)NULL);
        }
    }
    else if (_ostype == _DOS32)          /* MS-DOS */
    {
        /* Use DOS call 47H to get the specified directory.
         */
        bufI[0] = drive + _TEXT('A') - 1;
        bufI[1] = _TEXT(':');
        bufI[2] = _TEXT('\\');
        bufI[3] = _TEXT('\0');
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
	    /* Use envname to store drive spec */
            envname[0] = drive + _TEXT('A') - 1;
            envname[1] = _TEXT(':');
            envname[2] = _TEXT('.');
            envname[3] = _TEXT('\0');
	    GetFullPathName(envname, sizeof(bufI)/sizeof(_TCHAR), bufI, &filename);
        }
        else
            return NULL;

    }

    /* If the buffer length is too small to contain the directory name,
     * return an error.
     */
    if ((int)_tcslen(bufI) >= bufL)
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
    _tcscpy(bufP, bufI);
    return  bufP;
}
