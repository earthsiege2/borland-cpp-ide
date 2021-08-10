/*-----------------------------------------------------------------------*
 * filename - makepath.c
 *
 * function(s)
 *        _makepath - make new filename
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.5  $        */

#include <string.h>
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            _tmakepath used as _makepath and _wmakepath
                _makepath  - makes new file name
                _wmakepath - makes new (wide ) file name

Usage           #include <stdlib.h>
                void _makepath (char *path, const char * drive,
                                const char * dir, const char * name,
                                const char * ext);
                void _wmakepath(wchar_t *path, const wchar_t * drive,
                                const wchar_t * dir, const wchar_t * name,
                                const wchar_t * ext);

Related
functions usage void _splitpath (const char *path, char *drive, char *dir,
                                 char *name, char *ext);
                void _wsplitpath(const wchar_t *path, wchar_t *drive,
                                 wchar_t *dir, wchar_t *name, wchar_t *ext);

Prototype in    stdlib.h

Description     Makes a (wide) file name from its components. The
                new file's full path name is

                        X:\DIR\SUBDIR\NAME.EXT

                where

                        X is given by drive
                        \DIR\SUBDIR\ is given by dir
                        NAME.EXT is given by name and ext

                If the drive, dir, name, or ext parameters are null or empty,
                they are not inserted in the path string.  Otherwise, if the
                drive doesn't end with a colon, one is inserted in the path.
                If the dir doesn't end in a slash, one is inserted in the
                path.  If the ext doesn't start with a dot, one is inserted
                in the path.

                The maximum sizes for the path string is given by the
                constant _MAX_PATH (defined in stdlib.h), which includes space
                for the null-terminator.

                _splitpath/_wsplitpath and _makepath/_wmakepath are
                invertible; if you split a given path with
                _splitpath/_wsplitpath, then merge the resultant components
                with _makepath/_wmakepath, you end up with path.

Return value    None

*---------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC _tmakepath(register _TCHAR *pathP,
                                   const    _TCHAR *driveP,
                                   const    _TCHAR *dirP,
                                   const    _TCHAR *nameP,
                                   const    _TCHAR *extP)
{
        if (driveP && *driveP)
        {
                *pathP++ = *driveP;
                *pathP++ = _TEXT(':');
        }
        if (dirP && *dirP)
        {
                pathP = _tcspcpy(pathP,dirP);
#if defined(_MBCS) && !defined(_UNICODE)
                if ((*(pathP-1) != _TEXT('\\') &&
                     *(pathP-1) != _TEXT('/')) ||
                     _mbsbtype(dirP, strlen(dirP)-1) == _MBC_TRAIL)
#else
                if (*(pathP-1) != _TEXT('\\') &&
                    *(pathP-1) != _TEXT('/'))
#endif
                        *pathP++ = _TEXT('\\');
        }
        if (nameP) pathP = _tcspcpy(pathP,nameP);
        if (extP && *extP)
        {
                if (*extP != _TEXT('.')) *pathP++ = _TEXT('.');
                pathP = _tcspcpy(pathP,extP);
        }
        *pathP = 0;
}
