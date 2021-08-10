/*------------------------------------------------------------------------
 * filename - __access.c
 *
 * function(s)
 *        __access - determines accessibility of a file
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.4  $        */

#include <ntbc.h>

#include <_io.h>
#include <tchar.h>
#include <errno.h>

/*--------------------------------------------------------------------------*

Name            _taccess used as __access and _waccess
                __access - determines accessibility of a file
                _waccess - determines accessibility of a file

Usage           int __access(const char *filename, int amode);
                int _waccess(const wchar_t *filename, int amode);

Prototype in    _io.h

Description     Checks  a named file  to determine if  it exists and
                whether it can be read, written or executed.

                filename points to a (wide) string naming the file.

                amode  contains a  bit pattern  constructed as  follows:
                        06      Check for read and write permission
                        04      Check for read  permission
                        02      Check for  write permission
                        01      Check for execute permission
                        00      Check for existence of file


Return value    If  the   requested  access  is  allowed,   0  is  returned
                otherwise, a  value of -1 is  returned and errno is  set to
                one of  the following:
                        ENOENT  Path or file  name not found
                        EACCES  Permission denied

*----------------------------------------------------------------------------*/

#ifdef _UNICODE
int _RTLENTRY _EXPFUNC _waccess(const wchar_t *filename, int amode)
#else
int _RTLENTRY _EXPFUNC __access(const char *filename, int amode)
#endif
{
    DWORD attr;         /* file attributes */

    if ((attr = GetFileAttributes(filename)) == (DWORD)-1)
        return (__NTerror());

    if ((amode & 0x0002) != 0 && (attr & FILE_ATTRIBUTE_READONLY) != 0)
    {
        errno = EACCES;
        return(-1);
    }
    else
        return(0);
}
