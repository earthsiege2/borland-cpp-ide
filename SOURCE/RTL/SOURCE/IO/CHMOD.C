/*---------------------------------------------------------------------------
 * filename - chmod.c
 *
 * function(s)
 *        chmod - changes access mode of file
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1991, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <ntbc.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <io.h>
#include <_io.h>
#include <tchar.h>

/*-------------------------------------------------------------------------*

Name            _tchmod used as _wchmod and chmod
                chmod   - changes access mode of file
                _wchmod - changes access mode of file

Usage           #include <sys/types.h>
                #include <sys/stat.h>
                int chmod(const char *filename, int permiss);
                int _wchmod(const wchar_t *filename, int permiss);

Prototype in    io.h

Description     Sets   the  file access  permissions  of   the  file
                according to the mask given by permiss.

                filename points to a (wide) string naming the file.

                permiss can contain  one or both of the  symbolic constants
                S_IWRITE and S_IREAD:

                    Value of permiss   Access Permission
                    S_IWRITE            Permission to write
                    S_IREAD             Permission to read
                    S_IREAD | S_IWRITE  Permission to read and write

Return value    Upon  successfully  changing  the  file access  mode, chmod
                returns 0 otherwise, it returns a  value of -1 and errno is
                set to one of the following:
                  ENOENT  Path or file name not found
                  EACCES  Permission denied

*---------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _tchmod( const _TCHAR *pathname, int attrib )
{
    DWORD fattr;

    /* Get the current file attributes.
     */
    if ((fattr = GetFileAttributes(pathname)) == (DWORD)-1)
        return (__NTerror());

    /* Set or clear the read-only attribute depending on whether
     * S_IWRITE is set in attrib.  Ignore S_IREAD because a file
     * is always readable on NT.
     */
    if ((attrib & S_IWRITE) == 0)               /* writing not allowed? */
        fattr |= FILE_ATTRIBUTE_READONLY;       /* turn on read-only */
    else                                        /* writing allowed */
        fattr &= ~FILE_ATTRIBUTE_READONLY;      /* turn off read-only */

    /* Set the new file attributes.
     */
    if (SetFileAttributes(pathname, fattr) != TRUE)
        return (__NTerror());
    else
        return (0);
}
