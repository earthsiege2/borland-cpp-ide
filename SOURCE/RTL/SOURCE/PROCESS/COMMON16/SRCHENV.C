/*-----------------------------------------------------------------------*
 * filename - srchenv.c
 *
 * function(s)
 *        _searchenv   - search a path environment variable for a file.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdlib.h>

/*-----------------------------------------------------------------------*

Name            _searchenv - searches for a file using an enviroment path

Usage           void _searchenv(const char *filename, const char *varname,
                                char *pathname);

Prototype in    stdlib.h

Description     _searchenv searches for the file 'filename' in the
                current directory, and then in the directories specifed
                by the environment variable 'varname'.  If the file
                is found, the complete pathname of the file is copied
                to the user's buffer pathname.  If the file is not found,
                an empty string will be stored in pathname.  The pathname
                must be at least _MAX_PATH characters long; no error
                checking is performed on the length of the pathname.

Return value    None.

*------------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC _searchenv (const char *file, const char *varname,
                                char *pathname)
{
    char *env;

    /* If the environment variable isn't defined, at least try
     * the current directory.
     */
    if ((env = getenv(varname)) == NULL)
        env = "";
    _searchstr(file, env, pathname);
}
