/*-----------------------------------------------------------------------*
 * filename - __unlink.c
 *
 * function(s)
 *        __unlink    - delete a file
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1991, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>

#include <_io.h>

/*-----------------------------------------------------------------------*

Name            __unlink - deletes a file

Usage           int __unlink(const char *filename);

Related
functions usage int remove(const char *filename);

Prototype in    _io.h

Description     __unlink deletes a file specified by filename. Any
                drive, path, and file name may be used as a filename.
                Wildcards are not allowed.

                Read-only files cannot be deleted by this call. To remove
                read-only files, first use chmod or _chmod to change the
                read-only attribute.

                remove is a macro that simply translates the call to a call
                to __unlink.

Return value    On successful completion, a 0 is returned. On
                error, a -1 is returned, and errno is set to one of the
                following values:

                        ENOENT  Path or file name not found
                        EACCES  Permission denied

*------------------------------------------------------------------------*/

int _RTLENTRYF __unlink(const char *filename)
{
    return (DeleteFile((char *)filename) == TRUE ? 0 : __NTerror());
}
