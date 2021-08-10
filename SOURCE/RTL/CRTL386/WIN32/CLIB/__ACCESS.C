/*------------------------------------------------------------------------
 * filename - __access.c
 *
 * function(s)
 *        __access - determines accessibility of a file
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>

#include <_io.h>
#include <errno.h>

/*--------------------------------------------------------------------------*

Name            __access - determines accessibility of a file

Usage           int __access(const char *filename, int amode);

Prototype in    _io.h

Description     __access checks  a named file  to determine if  it exists and
                whether it can be read, written or executed.

                filename points to a string naming the file.

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

int _RTLENTRY __access(const char *filename, int amode)
{
    DWORD attr;         /* file attributes */

    if ((attr = GetFileAttributes((char *)filename)) == -1)
        return (__NTerror());

    if ((amode & 0x0002) != 0 && (attr & FILE_ATTRIBUTE_READONLY) != 0)
    {
        errno = EACCES;
        return(-1);
    }
    else
        return(0);
}
