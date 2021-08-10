/*-----------------------------------------------------------------------*
 * filename - stati64.c
 *
 * function(s)
 *        stati64 - gets information about open file
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.0  $        */

#include <ntbc.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <_io.h>
#include <stdlib.h>
#include <string.h>
#include <_tchar.h>

/* The following helper function is in statcvt.c.
 */
extern void _statcvt_i64 (
    struct stati64 *bufP,   /* stati64 structure to be filled in */
    DWORD attr,             /* NT file attributes */
    FILETIME *ctime,        /* NT time of file creation */
    FILETIME *atime,        /* NT time of last access */
    FILETIME *wtime,        /* NT time of last write */
    DWORD    fsize_high,    /* NT high word file size */
    DWORD    fsize_low);    /* NT low word file size */

/*-----------------------------------------------------------------------*

Name            _tstati64 used as stati64 and _wstati64
                stati64   - gets information about open file
                _wstati64 - gets information about open file

Usage           #include <sys\stat.h>
                int stati64(const char *pathname, struct stati64 *buff)
                int _wstati64(const wchar_t *pathname, struct stati64 *buff)

Prototype in    sys\stat.h

Description     Gather statistics about the file named by *pathP and place them
                in the buffer *bufP.

                It should be noted that on MSDOS this call can return more
                information about a file than is possible with the fstat()
                call.  In particular it is possible to get statistics for
                directories and the time of the file is accessible for DOS
                versions prior to 3.0.

                Not all of the fields are relevant to MSDOS.  The statistics
                fields are set thus:

                st_dev          set to -1 if S_IFCHR, else set to drive
                                holding the file.
                st_ino          0
                st_mode         Unix-style bit-set for file access rights
                st_nlink        1
                st_uid          0
                st_gid          0
                st_rdev         same as st_dev
                st_size         file size (0 if S_IFDIR or S_IFCHR)
                st_atime        time file last changed (seconds since 1970)
                st_mtime        same as st_atime
                st_ctime        same as st_atime

                The file access rights bit-set may contain S_IFCHR, S_IFDIR,
                S_IFREG, S_IREAD, S_IWRITE, or S_IEXEC.

                If the name is for a device, the time fields will be zero
                and the size field is undefined.

Return value    The return value is 0 if the call was successful, otherwise
                -1 is returned and errno contains the reason.  The buffer
                is not touched unless the call is successful.

*------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC _tstati64 (const _TCHAR *pathP, struct stati64 *bufP)
{
    WIN32_FIND_DATA ff;
    HANDLE      hfile;              /* file handle */
    _TCHAR      curdir[MAX_PATH];   /* current directory */
    _TCHAR      DriveChar;
    _TCHAR     *full = 0;

    /* Assume it is a disk file and try to get the FindFirst info.
     */
    memset(bufP, 0, sizeof(struct stati64));   /* Zero the structure   */
    bufP->st_nlink = 1;

    if ((hfile = FindFirstFile(pathP, &ff)) == (HANDLE)-1)
    {
        /* Check for special case of ROOT directory
         */
        if ((_tcspbrk(pathP, _TEXT("\\/.")) != NULL) &&
           ((full = _tfullpath(NULL, pathP, 0)) != NULL) &&
           (_tcslen(full) == 3))
        {
            if (GetDriveType(full) < 2)
                return (__NTerror());

            bufP->st_mode = S_IFDIR;
            bufP->st_dev = bufP->st_rdev = _totupper(full[0]) - _TEXT('A') + 1;

            free(full);
            return 0;
        }
        else
            if (full)
                free (full);

        /* It may not be a disk file.  Try to open the file for reading
         * so we can find out the type of the file.
         */
        if ((hfile = CreateFile(pathP, GENERIC_READ,
                      FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
                      OPEN_EXISTING, 0, NULL)) == (HANDLE)-1)
            return (__NTerror());

        /* Get the handle type to see if it is a character device or pipe.
         */
        bufP->st_mode = GetFileType(hfile) == FILE_TYPE_PIPE ? S_IFIFO : S_IFCHR;
        CloseHandle(hfile);
        return (0);
    }

    /* It it a disk file, convert the NT file info to a stat structure.
     */
    FindClose(hfile);
    _statcvt_i64(bufP, ff.dwFileAttributes, &ff.ftCreationTime,
             &ff.ftLastAccessTime, &ff.ftLastWriteTime, ff.nFileSizeHigh,
             ff.nFileSizeLow);

    /* Determine the disk device by parsing the drive name.
     * If no drive name, assume current drive.
     */
    if (pathP[1] == _TEXT(':'))
        DriveChar = pathP[0];
    else
    {
        if (GetCurrentDirectory(sizeof(curdir), curdir) == 0)
            DriveChar = _TEXT('A');        /* reasonable default if failure */
        else
            DriveChar = curdir[0];
    }
    if (DriveChar >= 'a' && DriveChar <= 'z')
        bufP->st_dev = DriveChar - 'a';
    else if (DriveChar >= 'A' && DriveChar <= 'Z')
        bufP->st_dev = DriveChar - 'A';
    bufP->st_rdev = bufP->st_dev;
    return (0);
}
