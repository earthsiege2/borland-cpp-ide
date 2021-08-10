/*-----------------------------------------------------------------------*
 * filename - fnmerge.c
 *
 * function(s)
 *        fnmerge - make new filename
 *        _wfnmerge - make new wide-character filename
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.3  $        */

#include <stdlib.h>
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            fnmerge, _wfnmerge - makes new (wide-character) file name

Usage           #include <dir.h>
                void fnmerge(char *path, const char * drive, const char * dir,
                             const char * name, const char * ext);
                void wfnmerge(wchar_t *path, const wchar_t * drive, const wchar_t * dir,
                             const wchar_t * name, const wchar_t * ext);

Related
functions usage int fnsplit(const char *path, char *drive, char *dir,
                            char *name, char *ext);

Prototype in    dir.h

Description     fnmerge makes a file name from its components. The
                new file's full path name is

                        X:\DIR\SUBDIR\NAME.EXT

                where

                        X is given by drive
                        \DIR\SUBDIR\ is given by dir
                        NAME.EXT is given by name and ext

                If the drive, dir, name, or ext parameters are null or empty,
                they are not inserted in the path string.  Otherwise, if
                the drive doesn't end a colon, one is inserted in the path.
                If the dir doesn't end in a slash, one is inserted in the
                path.  If the ext doesn't start with a dot, one is inserted
                in the path.

                The maximum sizes for the path string is given by the
                constant MAXPATH (defined in dir.h), which includes space
                for the null-terminator.

                fnsplit and fnmerge are invertible; if you split a given path
                with fnsplit, then merge the resultant components with fnmerge,
                you end up with path.

Return value    None

*---------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC _tfnmerge(register _TCHAR *pathP, const _TCHAR *driveP,
const _TCHAR *dirP, const _TCHAR *nameP, const _TCHAR *extP)
{
    _tmakepath(pathP,driveP,dirP,nameP,extP);
}
