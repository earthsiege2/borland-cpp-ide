/*---------------------------------------------------------------------------
 * filename - dosfind.c
 *
 * function(s)
 *        _dos_findfirst - searches disk directory
 *        _dos_findnext  - fetches files which match _dos_findfirst
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1991, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#define INCL_ERROR_H
#include <ntbc.h>

#include <_io.h>
#include <_thread.h>
#include <dos.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define SPECIAL_BITS (_A_SUBDIR|_A_HIDDEN|_A_SYSTEM)

/*----------------------------------------------------------------------
 * Semaphore used to govern access to the directory handle list.
 */
#ifdef _MT
lock_t hdir_lock;       /* heap semaphore */
#endif

/*----------------------------------------------------------------------
 * handle_list is a list is kept of all outstanding find_t blocks,
 * so that directory handles can be recycled.
 */
typedef struct handle_rec
{
    struct find_t     *finfo;
    HANDLE             handle;
    DWORD              attr;
    char              *name;
    struct handle_rec *next;
} HANDLE_REC;

static HANDLE_REC *handle_list;

/*---------------------------------------------------------------------*

Name            _init_hdir - set up the directory handle lock

Usage           void _init_hdir(void);

Prototype in

Description     Create the semaphore locks used to govern access to
                the list of directory handles.

Return value    None.

*---------------------------------------------------------------------*/

#ifdef _MT
static void _init_hdir()
{
#pragma startup _init_hdir 1

    /* Create the lock used to govern access to the directory handle list.
     */
    _create_lock(&hdir_lock,"creating directory lock");
}
#endif


/*--------------------------------------------------------------------------*

Name            get_handle - get a directory handle

Usage           HANDLE_REC *get_handle (struct find_t *fileinfo);

Prototype in    local

Description     get_handle searches the list of outstanding find_t blocks
                kept in handle_list for the specified block.  If it is
                found, the address of the HANDLE_REC corresponding
                to the block is returned.  If it is not found, a new
                handle record is allocated with the handle set to
                HDIR_CREATE and its address is returned.

                This scheme allows us to recycle directory used by
                earlier findfirst calls, since there is no findclose
                call on DOS.

Return value    If successful, the address of a HANDLE_REC structure;
                otherwise NULL is returned.

*---------------------------------------------------------------------------*/

static HANDLE_REC *get_handle (struct find_t *fileinfo)
{
    HANDLE_REC *r;

    _lock(hdir_lock,"locking directory handles");

    /* Search for a matching handle record using the
     * the address of the fileinfo block as the key.
     */
    for (r = handle_list; r != NULL && r->finfo != fileinfo; r = r->next)
        ;
    if (r != NULL)
    {
        /* This handle has been used before, so close it.
         */
        FindClose(r->handle);
    }
    else if ((r = malloc(sizeof(HANDLE_REC))) != NULL)
    {
        /* This is a find_t structure that hasn't been seen before, so
         * allocate a new one.
         */
        r->finfo = fileinfo;            /* save pointer to find_t struct */
        r->next = handle_list;          /* insert at head of handle list */
        handle_list = r;
    }
    fileinfo->reserved = (long)r;       /* save pointer to handle record */

    _unlock(hdir_lock,"unlocking directory handles");
    return r;
}


/*--------------------------------------------------------------------------*

Name            _dos_findfirst - searches disk directory

Usage           unsigned _dos_findfirst(const char *pathname, unsigned attrib,
                              struct find_t *fileinfo);

Prototype in    dir.h

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
    HANDLE_REC *hr;

    /* Get a handle record.
     */
    if ((hr = get_handle(fileinfo)) == NULL)
    {
        __IOerror(ERROR_NOT_ENOUGH_MEMORY);
        return (ERROR_NOT_ENOUGH_MEMORY);
    }

    hr->handle = (HANDLE)-1;        /* force FindFirst to be called */
    hr->attr   = attrib;            /* save search attributes */
    hr->name   = (char *)pathname;
    return (_dos_findnext(fileinfo));
}


/*--------------------------------------------------------------------------*

Name            _dos_findnext - fetches files which match _dos_findfirst

Usage           unsigned _dos_findnext(struct find_t *fileinfo);

Prototype in    dir.h

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
    WIN32_FIND_DATA ff;
    HANDLE_REC *hr;
    FILETIME local;
    BOOL found;

    hr = (HANDLE_REC *)fileinfo->reserved;
    for (;;)
    {
        if (hr->handle == (HANDLE)-1)
        {
            hr->handle = FindFirstFile(hr->name, &ff);
            found = hr->handle != (HANDLE)-1;
        }
        else
            found = FindNextFile(hr->handle, &ff);
        if (!found)
            return (__DOSerror());

        /* If requested attributes word has the Volume ID bit set,
         * include only volume label entries.
         */
        if ((hr->attr & _A_VOLID) && (ff.dwFileAttributes & _A_VOLID))
            break;

        /* If requested attribute word includes hidden, system, or
         * subdirectory bits, return normal files AND those with
         * any of the requested attributes.
         */
        else if ((ff.dwFileAttributes & SPECIAL_BITS) == 0 ||
                 (hr->attr & ff.dwFileAttributes & SPECIAL_BITS) != 0)
            break;
    }

    /* Fill in the find_t structure from the NT structure.
     */
    fileinfo->attrib = ff.dwFileAttributes;

    /* Convert times from GM to Local
     */
    FileTimeToLocalFileTime(&ff.ftLastWriteTime, &local);

    FileTimeToDosDateTime(&local, &fileinfo->wr_date, &fileinfo->wr_time);
    fileinfo->size = ff.nFileSizeLow;
    strcpy(fileinfo->name, ff.cFileName);
    return (0);
}

