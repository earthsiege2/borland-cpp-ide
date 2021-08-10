/*-----------------------------------------------------------------------*
 * filename - direct.c
 *
 * functions:
 *        opendir        - opens a directory stream
 *        wopendir       - opens a directory stream (wide-character)
 *        readdir        - read entry from directory stream
 *        wreaddir       - read entry from directory stream (wide-character)
 *        rewinddir      - position directory stream at first entry
 *        wrewinddir     - position directory stream at first entry (wide-character)
 *        closedir       - close directory stream
 *        wclosedir      - close directory stream (wide-character)
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1991, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <ntbc.h>

#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <_io.h>
#include <tchar.h>

#define DIRMAGIC 0xddaa

#if defined (_UNICODE)
#define LPSTR   LPWSTR
#else
#define LPSTR   LPCSTR
#endif

/*----------------------------------------------------------------------
Name            opendir, wopendir - open a directory stream

Usage           #include <dirent.h>
                DIR *opendir(const char *dirname);
                wDIR *opendir(const wchar_t *dirname);

Related
functions usage struct dirent *readdir(DIR *dirp);
                void rewinddir(DIR *dirp);
                int closedir(DIR *dirp);

Prototype in    dirent.h

Description     The opendir() and wopendir() functions open a directory
                stream for reading. The name of the directory to read
                is dirname.  The stream is set to read the first entry
                in the directory.

Return value    On a successful open, opendir() returns a pointer to
                an object of type DIR.  On an error, opendir() returns
                NULL and sets errno as follows:

                ENOENT  The directory does not exist.
                ENOMEM  Not enough memory to allocate a DIR object.

*---------------------------------------------------------------------*/

_tDIR * _RTLENTRY _EXPFUNC _topendir(const _TCHAR *dirname)
{
    _TCHAR *name;
    int len;
    _tDIR *dir;
    HANDLE h;

    /* Allocate space for a copy of the directory name, plus
     * room for the "*.*" we will concatenate to the end.
     */
    len = _tcslen(dirname);
    if ((name = malloc((len+5) * sizeof(_TCHAR))) == NULL)
    {
        errno = ENOMEM;
        return (NULL);
    }
    _tcscpy(name,dirname);
    if (len-- && name[len] != _TEXT(':') && name[len] != _TEXT('\\') && name[len] != _TEXT('/'))
        _tcscat(name,_TEXT("\\*.*"));
    else
        _tcscat(name,_TEXT("*.*"));

    /* Allocate space for a DIR structure.
     */
    if ((dir = malloc(sizeof(_tDIR))) == NULL)
    {
        errno = ENOMEM;
        free(name);
        return (NULL);
    }

    /* Search for the first file to see if the directory exists,
     * and to obtain directory handle for future FindNextFile() calls.
     */
    if ((h = FindFirstFile((LPSTR)name,
            (LPWIN32_FIND_DATA)&dir->_d_buf[0])) == (HANDLE)-1)
    {
        free(name);
        free(dir);
        __NTerror();     /* set errno */
        return (NULL);
    }

    /* Everything is OK.  Save information in the DIR structure, return it.
     */
    dir->_d_nfiles  = 1;
    dir->_d_hdir    = (unsigned long)h;
    dir->_d_dirname = name;
    dir->_d_magic   = DIRMAGIC;
    return dir;
}

/*----------------------------------------------------------------------
Name            rewinddir, wrewinddir - rewind a directory stream

Usage           #include <dirent.h>
                void rewinddir(DIR *dirp);
                void wrewinddir(wDIR *dirp);

Related
functions usage struct dirent *readdir(DIR *dirp);
                DIR *opendir(const char *dirname);
                int closedir(DIR *dirp);

Prototype in    dirent.h

Description     The rewinddir() and wrewinddir()  functions reset the
                directory stream dirp to the first entry in the directory.

Return value    The rewinddir() function does not return a value.

*---------------------------------------------------------------------*/

void _trewinddir(_tDIR *dir)
{
    HANDLE h;

    /* Verify the handle.
     */
    if (dir->_d_magic != DIRMAGIC)
            return;

    /* Close the handle, start searching at the beginning with a new
     * handle
     */
    FindClose((HANDLE)dir->_d_hdir);

    if ((h = FindFirstFile((LPSTR)dir->_d_dirname,
            (LPWIN32_FIND_DATA)&dir->_d_buf[0])) != (HANDLE)-1)
    {
        dir->_d_hdir   = (unsigned long)h;
        dir->_d_nfiles = 1;
    }
}


/*----------------------------------------------------------------------
Name            readdir, wreaddir - read directory entry from a directory stream

Usage           #include <dirent.h>
                struct dirent *readdir(DIR *dirp);
                struct dirent *wreaddir(wDIR *dirp);
Related
functions usage void rewinddir(DIR *dirp);
                DIR *opendir(const char *dirname);
                int closedir(DIR *dirp);

Prototype in    dirent.h

Description     The readdir() and wreaddir functions read the directory
                entry at the current position in the directory stream dirp,
                and advances the directory stream position to the next entry.
                The directory entry is an object of type 'struct dirent'
                that contains the member
                        char d_name[]
                which is an array of characters containing the null-terminated
                filename.

                The readdir() function reads directory entries for all files,
                including directories.  On DOS, it also reads directory
                entries for system and hidden files.  It does not read
                volume labels or unused directory entries.

Return value    On a successful read, readdir() returns a pointer
                to an object of type 'struct direct'.  This structure
                will be overwritten by subsequent operations on the
                same directory stream.  It will not be overwritten
                by operations on other directory streams.

                When the end of the directory is reached, readdir()
                returns NULL but does not set errno.

                On an error, readdir() returns NULL and sets errno:

                EBADF   The dirp parameter does not point to a valid
                        open directory stream.

*---------------------------------------------------------------------*/

struct _tdirent * _treaddir(_tDIR *dir)
{
    WIN32_FIND_DATA *ff;

    /* Verify the handle.
     */
    if (dir->_d_magic != DIRMAGIC)
    {
        errno = EBADF;
        return (NULL);
    }

    /* If all files in the buffer have been returned, find some more files.
     */
    if (dir->_d_nfiles == 0)
    {
        if (FindNextFile((HANDLE)dir->_d_hdir,
                (LPWIN32_FIND_DATA)&dir->_d_buf[0]) != TRUE)
            return (NULL);
    }
    else
        dir->_d_nfiles = 0;

    /* Return the filename of the current file in the buffer.
     */
    ff = (WIN32_FIND_DATA *)(dir->_d_buf);
    return ((struct _tdirent *)&ff->cFileName[0]);
}

/*----------------------------------------------------------------------
Name            closedir, wclosedir - close directory stream

Usage           #include <dirent.h>
                int closedir(DIR *dirp);
                int wclosedir(wDIR *dirp);

Related
functions usage void rewinddir(DIR *dirp);
                struct dirent *readdir(DIR *dirp);
                DIR *opendir(const char *dirname);

Prototype in    dirent.h

Description     The closedir() and wclosedir() functions close the
                directory stream dirp. Subsequently, dirp will not
                refer to a valid directory stream.

Return value    On a successful close, closedir() returns 0.
                On an error, closedir() returns -1 and sets errno:

                EBADF   The dirp parameter does not point to a valid
                        open directory stream.

*---------------------------------------------------------------------*/

int _tclosedir(_tDIR *dir)
{
    /* Verify the handle.
     */
    if (dir == NULL || dir->_d_magic != DIRMAGIC)
    {
        errno = EBADF;
        return (-1);
    }

    dir->_d_magic = 0;              /* prevent accidental use after closing */
    FindClose((HANDLE)dir->_d_hdir);/* close directory handle */
    free(dir->_d_dirname);          /* free directory name */
    free(dir);                      /* free directory structure */
    return 0;
}
