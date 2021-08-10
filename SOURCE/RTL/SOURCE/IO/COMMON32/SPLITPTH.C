/*------------------------------------------------------------------------
 * filename - spltpath.c
 *
 * function(s)
 *        CopyIt   - copies a string to another
 *        DotFound - checks for special directory names
 *        _fnsplit - splits a full path name into its components
 *        _splitpath - split a full path name (MSC compatible)
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.5  $        */

#include <dir.h>
#include <string.h>
#include <tchar.h>

/*---------------------------------------------------------------------*

Name            CopyIt - copies a (wide) string to another

Usage           void CopyIt (_TCHAR *dst, const _TCHAR *src, unsigned maxlen)

Prototype in    local to this module

Description     copies (wide) string scr to (wide) string dst.

Return value    nothing

*---------------------------------------------------------------------*/

static void CopyIt(_TCHAR *dst, const _TCHAR *src, unsigned maxlen)
{
        if (dst) {
                if(_tcslen(src) >= maxlen)
                {
                        _tcsncpy(dst, src, maxlen);
                        dst[maxlen] = 0;
                }
                else
                        _tcscpy(dst, src);
        }
}

/*---------------------------------------------------------------------*

Name            DotFound - checks for special dir name cases

Usage           int DotFound(_TCHAR *pB);

Prototype in    local to this module

Description     checks for special directory names

*---------------------------------------------------------------------*/

#if defined(_MBCS) && !defined(_UNICODE)
static  int DotFound(_TCHAR *baseP, _TCHAR *pB)
#else
static  int DotFound(_TCHAR *pB)
#endif
{
#if defined(_MBCS) && !defined(_UNICODE)
        if (*(pB-1) == _TEXT('.') && _mbsbtype(baseP, (pB-1)-baseP) == _MBC_SINGLE)
                pB--;
        if (_mbsbtype(baseP, (pB-1)-baseP) == _MBC_TRAIL)
                return 0;
#else
        if (*(pB-1) == _TEXT('.'))
                pB--;
#endif
        switch (*--pB) {
        case _TEXT(':')  :
                if (*(pB-2) != _TEXT('\0'))
                        break;
        case _TEXT('/')  :
        case _TEXT('\\') :
        case _TEXT('\0') :
                return 1;
        }
        return 0;
}

/*---------------------------------------------------------------------*

Name            _tfnsplit used as _fnsplit and _wfnsplit
                _fnsplit  - splits a full path name into its components
                _wfnsplit - splits a full (wide) path name into its components

                _tsplitpath used as _splitpath and _wsplitpath
                _splitpath  - splits a full path name into its components
                _wsplitpath - splits a full (wide) path name into its components

Usage           #include <dir.h>
                int _fnsplit (const char *path, char * drive, char * dir,
                              char * name, char * ext);
                int _wfnsplit(const wchar_t *path, wchar_t * drive, wchar_t * dir,
                              wchar_t * name, wchar_t * ext);

                void _splitpath (const char *path, char * drive, char * dir,
                                 char * name, char * ext);
                void _wsplitpath(const wchar_t *path, wchar_t * drive,
                                 wchar_t * dir, wchar_t * name, wchar_t * ext);

Related
functions usage void _makepath (char *path, const char *drive, const char *dir,
                                const char *name, const char *ext);
                void _wmakepath(wchar_t *path, const wchar_t *drive,
                                const wchar_t *dir, const wchar_t *name,
                                const wchar_t *ext);

Prototype in    dir.h

Description     Takes a file's full path name (path) as a string in the form

                        X:\DIR\SUBDIR\NAME.EXT

                and splits path into its four components. It then stores
                those components in the strings pointed to by drive, dir,
                name and ext. (Each component is required but can be a
                NULL, which means the corresponding component will be
                parsed but not stored.)

                The maximum sizes for these strings are given by the
                constants MAXDRIVE, MAXDIR, MAXPATH, MAXNAME and MAXEXT,
                (defined in dir.h) and each size includes space for the
                null-terminator.

                        Constant        (Max.)  String

                        MAXPATH         (80)    path
                        MAXDRIVE        (3)     drive; includes colon (:)
                        MAXDIR          (66)    dir; includes leading and
                                                trailing backslashes (\)
                        MAXFILE         (9)     name
                        MAXEXT          (5)     ext; includes leading dot (.)

                Assumes that there is enough space to store each
                non-NULL component. fnmerge assumes that there is enough
                space for the constructed path name. The maximum constructed
                length is MAXPATH.

                When these functions split a path, they treat the punctuation as
                follows:

                * drive keeps the colon attached (C:, A:, etc.)

                * dir keeps the leading and trailing backslashes
                  (\turboc\include\,\source\, etc.)

                * ext keeps the dot preceding the extension (.c, .exe, etc.)

                _splitpath/_wsplitpath are MSC-compatible functions that are
                identical to _fnsplit/_wfnsplit, except that they don't
                return a value.

                The _splitpath and _makepath functions are invertible; if you
                split a given path with a _splitpath function, then
                merge the resultant components with a _makepath function, you
                end up with path.

Return value    _fnsplit/_wfnsplit returns an integer (composed of five flags,
                defined in dir.h) indicating which of the full path name
                components were present in path; these flags and the components
                they represent are:

                        EXTENSION       an extension
                        FILENAME        a filename
                        DIRECTORY       a directory (and possibly
                                        sub-directories)
                        DRIVE           a drive specification (see dir.h)
                        WILDCARDS       wildcards (* or ? cards)

                _splitpath/_wsplitpath does not return a value.

*---------------------------------------------------------------------*/
#ifndef _UNICODE
#undef  _tfnsplit
#define _tfnsplit _fnsplit
#endif

int _RTLENTRY _EXPFUNC _tfnsplit(const _TCHAR *pathP, _TCHAR *driveP, _TCHAR *dirP,
                         _TCHAR *nameP, _TCHAR *extP)
{
        register _TCHAR   *pB;
        register int    Wrk;
        int     Ret;

        _TCHAR buf[ MAXPATH+2 ];

        /*
          Set all string to default value zero
        */
        Ret = 0;
        if (driveP)
                *driveP = 0;
        if (dirP)
                *dirP = 0;
        if (nameP)
                *nameP = 0;
        if (extP)
                *extP = 0;

        /*
          Copy filename into template up to MAXPATH characters
        */
        pB = buf;
        if ((Wrk = _tcslen(pathP)) > MAXPATH)
                Wrk = MAXPATH;
        *pB++ = 0;
        _tcsncpy(pB, pathP, Wrk);
        *(pB += Wrk) = 0;

        /*
          Split the filename and fill corresponding nonzero pointers
        */
        Wrk = 0;
        for (; ; ) {
#if defined(_MBCS) && !defined(_UNICODE)
                if (_mbsbtype(buf+1, (pB-1) - (buf+1)) == _MBC_TRAIL) {
                        pB -= 2;
                        continue;
                }
#endif
                switch (*--pB) {
                case _TEXT('.')  :
                        if (!Wrk && (*(pB+1) == _TEXT('\0')))
#if defined(_MBCS) && !defined(_UNICODE)
                                Wrk = DotFound(buf+1, pB);
#else
                                Wrk = DotFound(pB);
#endif
                        if ((!Wrk) && ((Ret & EXTENSION) == 0)) {
                                Ret |= EXTENSION;
                                CopyIt(extP, pB, MAXEXT - 1);
                                *pB = 0;
                        }
                        continue;
                case _TEXT(':')  :
                        if (pB != &buf[2])
                                continue;
                case _TEXT('\0') :
                        if (Wrk) {
                                if (*++pB)
                                        Ret |= DIRECTORY;
                                CopyIt(dirP, pB, MAXDIR - 1);
                                *pB-- = 0;
                                break;
                        }
                case _TEXT('/')  :
                case _TEXT('\\') :
                        if (!Wrk) {
                                Wrk++;
                                if (*++pB)
                                        Ret |= FILENAME;
                                CopyIt(nameP, pB, MAXFILE - 1);
                                *pB-- = 0;
                                if (*pB == 0 || (*pB == _TEXT(':') && pB == &buf[2]))
                                        break;
                        }
                        continue;
                case _TEXT('*')  :
                case _TEXT('?')  :
                        if (!Wrk)
                                Ret |= WILDCARDS;
                default :
                        continue;
                }
                break;
        }
        if (*pB == _TEXT(':')) {
                if (buf[1])
                        Ret |= DRIVE;
                CopyIt(driveP, &buf[1], MAXDRIVE - 1);
        }

        return (Ret);
}

void _RTLENTRY _EXPFUNC _tsplitpath(const _TCHAR *pathP, _TCHAR *driveP,
                                    _TCHAR *dirP, _TCHAR *nameP, _TCHAR *extP)
{
        (void)_tfnsplit(pathP,driveP,dirP,nameP,extP);
}
