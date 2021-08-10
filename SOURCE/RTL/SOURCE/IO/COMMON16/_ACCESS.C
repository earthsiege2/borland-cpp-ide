/*------------------------------------------------------------------------
 * filename - _access.c
 *
 * function(s)
 *        _access - determines accessibility of a file
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1993, 1996 by Borland International
 *      All Rights Reserved.
 *
 */


#include <io.h>
#include <dos.h>
#include <errno.h>

/*--------------------------------------------------------------------------*

Name            _access - determines accessibility of a file

Usage           int _access(const char *filename, int amode);

Prototype in    io.h

Description     _access checks  a named file  to determine if  it exists and
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
int _CType _FARFUNC _access(const char *filename, int amode)
{
        register int    attrib;

        attrib = _rtl_chmod(filename, 0);
        if (attrib == -1)
                return(attrib);
	/*
	 * If not checking for write permission or file is not read-only
	 * then return success.
	 */
        if ((amode & 0x0002) == 0 || (attrib & FA_RDONLY) == 0)
                return(0);
	/* File exists but permission is denied */
        errno = EACCES;
        return(-1);
}
