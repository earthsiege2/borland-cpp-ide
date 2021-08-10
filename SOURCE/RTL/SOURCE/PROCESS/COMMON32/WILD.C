/*-----------------------------------------------------------------------*
 * filename - wild.c
 *
 * function(s)
 *        _expand_wild -  expand a wild card filename argument
 *        _wexpand_wild - expand a wide-character wild card filename argument
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.5  $        */

#ifdef __OS2__
#include <os2bc.h>
#else
#include <ntbc.h>
#endif
#include <string.h>
#include <tchar.h>
#include <_tchar.h>

/*----------------------------------------------------------------------
 * Variables and functions from setargv.c
 */
extern void _taddarg(_TCHAR *, int);   /* function to add one argument to argv */

/*----------------------------------------------------------------------
 * _expand_wild - expand a wild-card argument into its matching filenames.
 */
void _RTLENTRY _EXPFUNC _texpand_wild(_TCHAR *arg)
{
#ifdef __OS2__
    static _TCHAR fullname[CCHMAXPATH];
    FILEFINDBUF3 *ff;
    HDIR hdir;
    ULONG nfiles;
    APIRET ret;
    static _TCHAR buf[1024];
#else   /* not OS2 */
    static _TCHAR fullname[MAX_PATH];
    WIN32_FIND_DATA ff;
    HANDLE hdir;
#endif  /* OS2 */
    _TCHAR *endpath;
    int nfound;

    /* Copy the path prefix to fullname.  Set endpath to point
     * to the end of the prefix.
     */
    _tcscpy(fullname,arg);
    for (endpath = fullname + _tcslen(fullname); endpath != fullname; endpath--)
#if defined(_MBCS) && !defined(_UNICODE)
        if ( (*(endpath-1) == _TEXT(':') || *(endpath-1) == _TEXT('\\') || *(endpath-1) == _TEXT('/') ) && _mbsbtype(fullname, (endpath-1)-fullname) == _MBC_SINGLE)
#else
        if (*(endpath-1) == _TEXT(':') || *(endpath-1) == _TEXT('\\') || *(endpath-1) == _TEXT('/'))
#endif
            break;

    /* Add each matching file to the argument list.
     */
#ifdef __OS2__
    nfound = 0;
    for (;;)
    {
        /* Get as many matching files as will fit into buf.
         */
        hdir = HDIR_SYSTEM;
        nfiles = 1024;
        if (nfound == 0)
            ret = DosFindFirst((PSZ)arg,&hdir,FILE_NORMAL,(PFILEFINDBUF)buf,
                 sizeof(buf),&nfiles,FIL_STANDARD);
        else
            ret = DosFindNext(hdir,(PFILEFINDBUF)buf,
                 sizeof(buf),&nfiles);
        if (ret != 0)
            break;

        /* Append each filename to the path prefix, and add the
         * resulting full pathname to the argument list.
         */
        for (ff = (FILEFINDBUF3 *)buf;
             nfiles--;
             ff = (FILEFINDBUF3 *)((_TCHAR *)ff + (int)ff->oNextEntryOffset))
        {
            strcpy(endpath,ff->achName);
            _addarg(fullname, 1);
        }
        nfound++;
    }
#else   /* not OS2 */
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
            if ((hdir = FindFirstFile(arg, &ff)) == (HANDLE)-1)
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
        _taddarg(fullname, 1);
        nfound++;
    }
#endif  /* OS2 */

    /* If no matching files are found, use the argument unmodified.
     */
    if (nfound == 0)
        _taddarg(arg, 0);
}
