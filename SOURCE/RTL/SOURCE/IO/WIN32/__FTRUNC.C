/*-----------------------------------------------------------------------*
 * filename - _ftrunc.c
 *
 * function(s)
 *        __ftruncate - truncate an open file
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#define INCL_ERROR_H

#include <ntbc.h>

#include <sys/types.h>
#include <io.h>
#include <_io.h>
#include <string.h>

/*---------------------------------------------------------------------*

Name            __ftruncate - truncate an open file

Usage           #include <sys/types.h>
                #include <sys/io.h>
                int ftruncate(int handle, off_t size);

Prototype in    _io.h (ftruncate is in io.h)

Description     This function truncates the open file 'handle' to the
                length specified by 'size'.  If the file is currently
                shorter than 'size', it is extended with zeroes; otherwise
                it is shortened to the new length.  The file must be
                opened for writing.

                This is the internal entry point for ftruncate() and
                chsize().

Return value    If successful, 0 is returned.  Otherwise -1 is returned
                and errno is set as follows:

                EBADF       Bad file handle
                EACCESS     Permission denied
                EINVAL      Size is negative

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC __ftruncate(int handle, off_t size)
{
    DWORD  newptr;
    DWORD  chunk;
    DWORD  written;
    DWORD  filepos;
    DWORD  filesize;
    HANDLE hfile;
    int    rc;
    char zerobuf[128];

    /* Verify and lock the file handle, get the NT handle.
     */
    if ((unsigned)handle >= _nfile)
        return __IOerror(ERROR_INVALID_HANDLE);
    _lock_handle(handle);
    hfile = (HANDLE)_handles[handle];

    /* Get the current file size (in filesize).
     */
    if ((filesize = GetFileSize(hfile,NULL)) == (DWORD)-1)
        RETURN (__NTerror());

    /* Get the current file position (in filepos).
     */
    if ((filepos = SetFilePointer(hfile, 0L, NULL, FILE_CURRENT)) == (DWORD)-1)
        RETURN (__NTerror());

    /* Set the new file size.
     */
    if (SetFilePointer(hfile, (DWORD)size, NULL, FILE_BEGIN) == (DWORD)-1)
        RETURN (__NTerror());
    if (SetEndOfFile(hfile) != TRUE)
        RETURN (__NTerror());

    /* If the file is being extended, fill the file from the old file size
     * to the new size with zeroes.
     */
    if ((DWORD)size > filesize)
    {
        /* Seek to old end of file.
         */
        if ((newptr = SetFilePointer(hfile, filesize, NULL, FILE_BEGIN)) == (DWORD)-1)
            RETURN (__NTerror());

        /* Fill with zeroes.
         */
        memset(zerobuf,0,sizeof(zerobuf));
        while (newptr < (DWORD)size)
        {
            if ((chunk = size - newptr) > sizeof(zerobuf))
                chunk = sizeof(zerobuf);
            if (WriteFile(hfile, (PVOID)zerobuf, chunk, &written, NULL) != TRUE)
                RETURN (__NTerror());
            newptr += chunk;
        }
    }

    /* Seek back to the original file position.
     */
    if (SetFilePointer(hfile, filepos, NULL, FILE_BEGIN) == (DWORD)-1)
        RETURN (__NTerror());
    rc = 0;

exit:
    _unlock_handle(handle);
    return rc;
}
