/*---------------------------------------------------------------------------
 * filename - fstat.c
 *
 * function(s)
 *        fstat      - gets open file information
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1991, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.3 $        */

#define INCL_ERROR_H

#include <ntbc.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <io.h>
#include <_io.h>
#include <string.h>
#include <fcntl.h>

/* The following helper function is in statcvt.c.
 */
extern void _statcvt(
    struct stat *bufP,      /* stat structure to be filled in */
    DWORD attr,             /* NT file attributes */
    FILETIME *ctime,        /* NT time of file creation */
    FILETIME *atime,        /* NT time of last access */
    FILETIME *wtime,        /* NT time of last write */
    DWORD fsize);           /* NT low word of file size */

/*--------------------------------------------------------------------------*

Name            fstat - gets open file information

Usage           #include <sys/stat.h>
                int fstat(int handle, struct stat *buff)

Prototype in    sys/stat.h

Description     Gather statistics about the nominated file and place
                them in the buffer *bufP.

                Not all of the fields are relevant to NT.
                The fields are set thus:

                    st_dev      set to fildes if device, else set to
                                drive holding the file.
                    st_ino      0
                    st_mode     Unix-style flag bits for file access rights
                    st_nlink    1
                    st_uid      0
                    st_gid      0
                    st_rdev     same as st_dev
                    st_size     file size (0 if device).
                    st_atime    time file last changed (seconds since 1970)
                    st_mtime    same as st_atime
                    st_ctime    same as st_atime

                The file access rights flags may contain S_IFCHR or S_IFREG.
                S_IREAD is always set and S_IWRITE is set only for devices,
                since there is no method in PCDOS of inspecting the file
                attributes without knowing the file name.  Programs which
                need this information should use stat().

                The file time fields are not available on MSDOS versions
                prior to 2.0, or if the file is a character stream (S_IFCHR),
                and will be set to zero in such cases.

Return value    The return value is 0 if the call was successful, otherwise
                -1 is returned and errno contains the reason.

*---------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC fstat (int fd, struct stat *bufP)
{
    int         rc;
    HANDLE      h;
    FILETIME atime;     /* time of last access */
    FILETIME ctime;     /* time of creation */
    FILETIME wtime;     /* time of last write */

    if ((unsigned)fd >= _nfile)
        return __IOerror(ERROR_INVALID_HANDLE);

    _lock_handle(fd);
    h = (HANDLE)_handles[fd];

    memset(bufP, 0, sizeof(struct stat));   /* Zero the structure   */

    /* Convert NT file type to POSIX file type.
     */
    switch (GetFileType(h))
    {
    case FILE_TYPE_CHAR:
        bufP->st_mode = S_IFCHR;
        break;

    case FILE_TYPE_DISK:
        /* Get the NT file times.
         */
        if (GetFileTime(h, &ctime, &atime, &wtime) != TRUE)
            RETURN (__NTerror());

        /* Convert the file attributes, times, and size to a struct stat.
         */
        _statcvt(bufP,
                 _openfd[fd] & _O_WRITABLE ? 0 : FILE_ATTRIBUTE_READONLY,
                 &ctime, &atime, &wtime,
                 GetFileSize(h, NULL));
        break;

    case FILE_TYPE_PIPE:
        bufP->st_mode = S_IFIFO;
        break;
    }

    rc = 0;

exit:
    _unlock_handle(fd);
    return (rc);
}
