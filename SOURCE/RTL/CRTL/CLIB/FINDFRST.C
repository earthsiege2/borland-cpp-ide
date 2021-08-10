/*---------------------------------------------------------------------------
 * filename - findfrst.c
 *
 * function(s)
 *        findfirst - searches disk directory
 *        findnext  - fetches files which match findfirst
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */


#include <dir.h>
#include <dos.h>

/*--------------------------------------------------------------------------*

Name            findfirst - searches disk directory

Usage           int findfirst(const char *pathname, struct ffblk *ffblk,
                              int attrib);

Prototype in    dir.h

Description     begins a search of a disk directory by using the
                MS-DOS system call 0x4E.

                pathname is a string with an optional drive specifier,
                path and file name of the file to be found.   If a
                matching file is found, the ffblk structure is filled
                with the file-directory information.

                attrib is an MS-DOS file-attribute byte used in selecting
                eligible files for the search.  attrib can be one of the
                following constants defined in dos.h

                        FA_RDONLY  Read only
                        FA_HIDDEN  Hidden file
                        FA_SYSTEM  System file
                        FA_LABEL   Volume label
                        FA_DIREC   Directory
                        FA_ARCH    Archive

                For more detailed information about these attributes, refer
                to the MS-DOS Programmer's Reference Manual.

Return value    success : 0
                else : -1 and errno is set to
                        ENOENT  Path or file name not found
                        ENMFILE No more files

*---------------------------------------------------------------------------*/

int _CType findfirst(const char *pathname, struct ffblk *ffblk, int attrib)
{
    return (_dos_findfirst(pathname,attrib,(struct find_t *)ffblk)
            == 0 ? 0 : -1);
}


/*--------------------------------------------------------------------------*

Name            findnext - fetches files which match findfirst

Usage           int findnext(struct ffblk *ffblk);

Prototype in    dir.h

Description     findnext is used to fetch subsequent files which
                match the pathname given in findfirst.  ffblk is the
                same block filled in by the findfirst call.  This
                block contains necessary information for continuing
                the search.  One file name for each call to findnext will
                be returned until no more files are found in the directory
                matching the pathname.

Return value    success : 0
                else : -1 and errno is set to
                        ENOENT  Path or file name not found
                        ENMFILE No more files

*---------------------------------------------------------------------------*/
int _CType findnext(struct ffblk *ffblk)
{
    return (_dos_findnext((struct find_t *)ffblk) == 0 ? 0 : -1);
}
