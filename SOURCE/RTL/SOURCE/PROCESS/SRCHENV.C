/*-----------------------------------------------------------------------*
 * filename - srchenv.c
 *
 * function(s)
 *        _searchenv   - search a path environment variable for a file.
 *        _wsearchenv  - search a wide-character path environment variable
 *				for a file.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <stdlib.h>
#include <tchar.h>
/*-----------------------------------------------------------------------*

Name            _searchenv, _wsearchenv - searches for a file using an
		    enviroment path

Usage           void _searchenv(const char *filename, const char *varname,
                                char *pathname);
                void _swearchenv(const wchar_t *filename, const wchar_t *varname,
                                wchar_t *pathname);

Prototype in    stdlib.h

Description     _searchenv and _wsearchenv searche for the file 'filename'
		in the current directory, and then in the directories specifed
                by the environment variable 'varname'.  If the file
                is found, the complete pathname of the file is copied
                to the user's buffer pathname.  If the file is not found,
                an empty string will be stored in pathname.  The pathname
                must be at least _MAX_PATH characters long; no error
                checking is performed on the length of the pathname.

Return value    None.

*------------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC _tsearchenv (const _TCHAR *file, const _TCHAR *varname,
                                _TCHAR *pathname)
{
    _TCHAR *env;

    /* If the environment variable isn't defined, at least try
     * the current directory.
     */
    if ((env = _tgetenv(varname)) == NULL)
        env = _TEXT("");
    _tsearchstr(file, env, pathname);
}
