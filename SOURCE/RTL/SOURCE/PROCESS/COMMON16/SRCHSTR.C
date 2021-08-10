/*-----------------------------------------------------------------------*
 * filename - srchstr.c
 *
 * function(s)
 *        _searchstr   - search a list of directories for a file.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <io.h>
#include <direct.h>
#include <string.h>
#include <stdlib.h>
#include <_io.h>

/*-----------------------------------------------------------------------*

Name            _searchstr - searches for a file using a path string

Usage           void _searchstr(const char *filename, const char *varname,
                                char *pathname);

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

void _RTLENTRY _EXPFUNC _searchstr(const char *file, const char *ipath, char *pathname)
{
    char c;
    int len;
    char *temp;

    /* Try the current directory, then all directories in the
     * string ipath.
     */
    if (_getdcwd(0,pathname,_MAX_PATH) == NULL)
        len = 0;
    else
        len = strlen(pathname);
    for (;;)
    {
        /* The next directory to try is already in pathname, and its
         * length is in len.  If it doesn't end in a slash, and isn't
         * blank, append a slash.
         */
        pathname[len] = '\0';
        if (len != 0 && (c = pathname[len-1]) != '\\' && c != '/')
            strcat(pathname,"\\");

        /* Append the filename to the directory name, then return
         * if the file exists.
         */
        strcat(pathname,file);
        if (_access(pathname, 0) == 0)
            break;

        /* Try the next directory in the ipath string.
         */
        if (*ipath == '\0')             /* end of the variable */
        {
            pathname[0] = '\0';         /* return an empty path */
            return;
        }
        for (len = 0; *ipath != ';' && *ipath != '\0'; ipath++, len++)
            pathname[len] = *ipath;     /* copy next directory */
        if (*ipath != '\0')
            ipath++;                    /* skip over semicolon */
    }

    /* Pathname contains the relative path of the found file.  Convert
     * it to an absolute path.
     */
    if ((temp = _fullpath(NULL, pathname, _MAX_PATH)) == NULL)
        return;
    strcpy(pathname, temp);
    free(temp);
}
