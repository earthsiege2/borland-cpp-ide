/*-----------------------------------------------------------------------*
 * filename - wild.c
 *
 * function(s)
 *        _expand_wild - expand a wild card filename argument
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <dir.h>
#include <stdlib.h>
#include <string.h>

/*----------------------------------------------------------------------
 * Variables and functions from setargv.c
 */
extern void _addarg(char _FAR *, int);   /* function to add one argument to argv */

/*----------------------------------------------------------------------
 * expand - expand a wild-card argument into its matching filenames.
 */
void _RTLENTRY _EXPFUNC _expand_wild(char _FAR *arg)
{
    static char fullname[_MAX_PATH];
    struct ffblk ff;
    char *endpath;
    int nfound;

    /* Copy the path prefix to fullname.  Set endpath to point
     * to the end of the prefix.
     */
    strcpy(fullname,arg);
    for (endpath = fullname + strlen(fullname); endpath != fullname; endpath--)
        if (*(endpath-1) == ':' || *(endpath-1) == '\\' || *(endpath-1) == '/')
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
            if (findfirst(arg, &ff, 0) == -1)
                break;
        }
        else
            if (findnext(&ff) != 0)
                break;

        /* Append the filename to the path prefix, and add the
         * resulting full pathname to the argument list.
         */
        strcpy(endpath,ff.ff_name);
        _addarg(fullname, 1);
        nfound++;
    }

    /* If no matching files are found, use the argument unmodified.
     */
    if (nfound == 0)
        _addarg(arg, 0);
}
