/*-----------------------------------------------------------------------*
 * filename - tell.c
 *
 * function(s)
 *        tell - gets current position of file pointer
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <io.h>
#include <_io.h>

/*---------------------------------------------------------------------*

Name            tell - gets current position of file pointer

Usage           long tell(int handle);

Prototype in    io.h

Description     gets the current position of the file pointer associated
                with handle and expresses it as the number of bytes from
                the beginning of the file.

Return value    the current file pointer position.  A return of -1L
                indicates an error, and errno is set to:

                        EBADF   Bad file number

*---------------------------------------------------------------------*/

long _RTLENTRY _EXPFUNC tell(int handle)
{
        return (__lseek (handle, 0L, SEEK_CUR));
}
