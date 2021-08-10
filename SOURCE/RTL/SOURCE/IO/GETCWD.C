/*-----------------------------------------------------------------------*
 * filename - getcwd.c
 *
 * function(s)
 *        getcwd - gets current working directory
 *        _wgetcwd - gets current working directory (wide-character)
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <direct.h>
#include <errno.h>
#include <stdlib.h>
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            getcwd, _wgetcwd - gets current working directory

Usage           char *getcwd(char *buf, int n);
                wchar_t *_wgetcwd(wchar_t *buf, int n);

Prototype in    dir.h

Description     getcwd gets the full path name of the cwd (current
                working directory, including the drive), up to n bytes
                long, and stores it in buf. If the full path name length
                (including the null-terminator) is longer than n, an
                error occurs.

                If buf is NULL, a buffer n bytes long will be allocated
                for you with malloc. You can later free the allocated buffer
                by passing the getcwd return value to the function free.

Return value    getcwd returns buf; on error, it returns NULL.

                In the event of an error return, the global variable errno is
                set to one of the following:

                        ENODEV  No such device
                        ENOMEM  Not enough core
                        ERANGE  Result out of range

*---------------------------------------------------------------------*/

_TCHAR * _RTLENTRY _EXPFUNC _tgetcwd(_TCHAR *bufP, int bufL)
{
    return (_tgetdcwd(0, bufP, bufL));
}
