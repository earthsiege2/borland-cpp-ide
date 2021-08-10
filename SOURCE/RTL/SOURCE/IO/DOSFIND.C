/*---------------------------------------------------------------------------
 * filename - dosfind.c
 *
 * function(s)
 *        _dos_findfirst - searches disk directory
 *        _dos_findnext  - fetches files which match _dos_findfirst
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1991, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.3 $        */

#include <dir.h>
#include <dos.h>

/*--------------------------------------------------------------------------*

Name            _dos_findfirst  - searches disk directory

Usage           unsigned _dos_findfirst(const char *pathname, unsigned attrib,
                              struct find_t *fileinfo);

Prototype in    dos.h

Description     begins a search of a disk directory similar to the
                MS-DOS system call 0x4E.

                pathname is a string with an optional drive specifier,
                path and file name of the file to be found.   If a
                matching file is found, the fileinfo structure is filled
                with the file-directory information.

                attrib is an MS-DOS file-attribute byte used in selecting
                eligible files for the search.  attrib can be one of the
                following constants defined in dos.h

                        _A_RDONLY  Read only
                        _A_HIDDEN  Hidden file
                        _A_SYSTEM  System file
                        _A_VOLID   Volume label
                        _A_SUBDIR  Directory
                        _A_ARCH    Archive

                For more detailed information about these attributes, refer
                to the MS-DOS Programmer's Reference Manual.

Return value    success : 0
                else : -1 and errno is set to
                        ENOENT  Path or file name not found
                        ENMFILE No more files

*---------------------------------------------------------------------------*/

unsigned _RTLENTRY _EXPFUNC
_dos_findfirst (const char *pathname, unsigned attrib, struct find_t *fileinfo)
{
  return (findfirst(pathname, (struct ffblk *)fileinfo, attrib)
          == 0 ? 0 : -1);
}

/*--------------------------------------------------------------------------*

Name            _dos_findnext  - fetches files which match _dos_findfirst

Usage           unsigned _dos_findnext(struct find_t *fileinfo);

Prototype in    dos.h

Description     _dos_findnext is used to fetch subsequent files which
                match the pathname given in _dos_findfirst.  fileinfo is the
                same block filled in by the _dos_findfirst call.  This
                block contains necessary information for continuing
                the search.  One file name for each call to _dos_findnext will
                be returned until no more files are found in the directory
                matching the pathname.

Return value    success : 0
                else : -1 and errno is set to
                        ENOENT  Path or file name not found
                        ENMFILE No more files

*---------------------------------------------------------------------------*/
unsigned _RTLENTRY _EXPFUNC _dos_findnext(struct find_t *fileinfo)
{
  return (findnext((struct ffblk *)fileinfo) == 0 ? 0 : -1);
}

