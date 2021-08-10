/*-----------------------------------------------------------------------*
 * filename - wild.c
 *
 * function(s)
 *        _expand_wild -  expand a wild card filename argument
 *        _wexpand_wild - expand a wide-character wild card filename argument
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1991, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

#include <ntbc.h>
#include <string.h>
#include <_setargv.h>

/*----------------------------------------------------------------------
 * _expand_wild - expand a wild-card argument into its matching filenames.
 */
void _RTLENTRY _EXPFUNC _texpand_wild(_TCHAR *_arg, _PFN_ADDARG _pfn_addarg)
{
    static _TCHAR fullname[MAX_PATH];
    WIN32_FIND_DATA ff;
    HANDLE hdir;
    _TCHAR *endpath;
    int nfound;

    /* Copy the path prefix to fullname.  Set endpath to point
     * to the end of the prefix.
     */
    _tcscpy(fullname,_arg);
    for (endpath = fullname + _tcslen(fullname); endpath != fullname; endpath--)
#if defined(_MBCS) && !defined(_UNICODE)
        if ( (*(endpath-1) == _TEXT(':') || *(endpath-1) == _TEXT('\\') || *(endpath-1) == _TEXT('/') ) && _mbsbtype(fullname, (endpath-1)-fullname) == _MBC_SINGLE)
#else
        if (*(endpath-1) == _TEXT(':') || *(endpath-1) == _TEXT('\\') || *(endpath-1) == _TEXT('/'))
#endif
            break;

    /* Add each matching file to the argument list.
     */
    nfound = -1;
    for (;;)
    {
        /* If this is the first time through the loop, open a directory
         * stream and get the first file.  Otherwise get the next file
         * on the existing stream.
         */
        if (nfound == -1)
        {
            nfound = 0;
            if ((hdir = FindFirstFile(_arg, &ff)) == (HANDLE)-1)
                break;
        }
        else
        {
            if (FindNextFile(hdir, &ff) != TRUE)
            {
                FindClose(hdir);
                break;
            }
        }

        /* Filter out directories, and hidden and system files.
         */
        if (ff.dwFileAttributes & ( FILE_ATTRIBUTE_DIRECTORY
                                  | FILE_ATTRIBUTE_HIDDEN
                                  | FILE_ATTRIBUTE_SYSTEM))
            continue;

        /* Append the filename to the path prefix, and add the
         * resulting full pathname to the argument list.
         */
        _tcscpy(endpath,ff.cFileName);
        _pfn_addarg(fullname, 1);
        nfound++;
    }

    /* If no matching files are found, use the argument unmodified.
     */
    if (nfound == 0)
        _pfn_addarg(_arg, 0);
}
