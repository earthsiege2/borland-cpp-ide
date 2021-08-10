/*-----------------------------------------------------------------------*
 * filename - srchstr.c
 *
 * function(s)
 *        _searchstr   - search a list of directories for a file.
 *        _wsearchstr  - search a wide-character list of directories for a file.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.5.2.1 $        */

#include <io.h>
#include <_io.h>
#include <tchar.h>
#include <direct.h>
#include <string.h>
#include <stdlib.h>

/*-----------------------------------------------------------------------*

Name            _searchstr, _wsearchstr - searches for a file using a path string

Usage           void _searchstr(const char *filename, const char *varname,
                                char *pathname);
                void _searchstr(const wchar_t *filename, const wchar_t *varname,
                                wchar_t *pathname);

Prototype in    stdlib.h

Description     _searchstr searches for the file 'filename' in the
                current directory, and then in the list of semicolon-
                separated directories specifed by ipath.  If the file
                is found, the complete pathname of the file is copied
                to the user's buffer pathname.  If the file is not found,
                an empty string will be stored in pathname.  The pathname
                must be at least _MAX_PATH characters long; no error
                checking is performed on the length of the pathname.

Return value    None.

*------------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC _tsearchstr(const _TCHAR *file, const _TCHAR *ipath, _TCHAR *pathname)
{
    _TCHAR c;
    int len;
    _TCHAR *temp;

    /* Try the current directory, then all directories in the
     * string ipath.
     */
    if (_tgetdcwd(0,pathname,_MAX_PATH) == NULL)
        len = 0;
    else
        len = _tcslen(pathname);
    for (;;)
    {
        /* The next directory to try is already in pathname, and its
         * length is in len.  If it doesn't end in a slash, and isn't
         * blank, append a slash.
         */
        pathname[len] = _TEXT('\0');

#if defined(_MBCS)
        if (len != 0 && (c = *_tcsdec(pathname, pathname+len)) != _TEXT('\\') && c != _TEXT('/'))
#else
        if (len != 0 && (c = pathname[len-1]) != _TEXT('\\') && c != _TEXT('/'))
#endif
            _tcscat(pathname,_TEXT("\\"));

        /* Append the filename to the directory name, then return
         * if the file exists.
         */
        _tcscat(pathname,file);
        if (_taccess(pathname, 0) == 0)
            break;

        /* Try the next directory in the ipath string.
         */
        if (*ipath == _TEXT('\0'))             /* end of the variable */
        {
            pathname[0] = _TEXT('\0');         /* return an empty path */
            return;
        }
        for (len = 0; *ipath != _TEXT(';') && *ipath != _TEXT('\0'); ipath++)
        {
            /* Strip off any quotes around this individual path dir */
            if (*ipath != _TEXT('\"'))
                pathname[len++] = *ipath;     /* copy next directory */
        }
        if (*ipath != _TEXT('\0'))
            ipath++;                    /* skip over semicolon */
    }

    /* Pathname contains the relative path of the found file.  Convert
     * it to an absolute path.
     */
    if ((temp = _tfullpath(NULL, pathname, _MAX_PATH)) == NULL)
        return;
    _tcscpy(pathname, temp);
    free(temp);
}
