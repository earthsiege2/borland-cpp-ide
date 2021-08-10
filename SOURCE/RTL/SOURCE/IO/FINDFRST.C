/*---------------------------------------------------------------------------
 * filename - findfrst.c
 *
 * function(s)
 *        findfirst - searches disk directory
 *        findnext  - fetches files which match findfirst
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.4  $        */

#define INCL_ERROR_H
#include <ntbc.h>

#include <_io.h>
#include <_thread.h>
#include <dos.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <dir.h>
#include <_tchar.h>
#define SPECIAL_BITS (_A_SUBDIR|_A_HIDDEN|_A_SYSTEM)

/*----------------------------------------------------------------------
 * Semaphore used to govern access to the directory handle list.
 */
#ifdef _MT
#ifndef _UNICODE
lock_t hdir_lock;              /* heap semaphore */
#else
extern lock_t hdir_lock;       /* heap semaphore */
#endif
#endif

/*----------------------------------------------------------------------
 * __ffblk_handle_list is a list kept of all outstanding find_t blocks,
 * so that directory handles can be recycled.
 */
typedef struct handle_rec
{
    struct ffblk      *finfo;
    HANDLE             handle;
    DWORD              attr;
    char              *name;
    struct handle_rec *next, *prev;  /* Need a prev so we can remove items */
} HANDLE_REC;

#ifndef _UNICODE
HANDLE_REC *__ffblk_handle_list;
#else
extern HANDLE_REC *__ffblk_handle_list;
#endif

/*---------------------------------------------------------------------*

Name            _handle_done - Cleans up the handle list

Usage           void _handle_done(void);

Prototype in

Description     This helper function is called from the exit code to
                clean up the list of directory handles.

Return value    None.

*---------------------------------------------------------------------*/

#ifndef _UNICODE
static void _handle_done (void)
{
#pragma exit _handle_done 1 /* Finalizes the ffblk handle list */
#else
static void _whandle_done (void)
{
#pragma exit _whandle_done 1 /* Finalizes the  wide ffblk handle list */

#endif
    HANDLE_REC * r;
    while (__ffblk_handle_list)
    {
        r = __ffblk_handle_list->next;
        free (__ffblk_handle_list);
        __ffblk_handle_list = r;
    }

}

/*---------------------------------------------------------------------*

Name            _init_hdir - set up the directory handle lock

Usage           void _init_hdir(void);

Prototype in

Description     Create the semaphore locks used to govern access to
                the list of directory handles.

Return value    None.

*---------------------------------------------------------------------*/

#ifdef _MT
#ifndef _UNICODE
static void _init_hdir()
{
#pragma startup _init_hdir 1 /* Initializes the lock which governs access to */
                             /* the directory handle list */
#else
static void _winit_hdir()
{
#pragma startup _winit_hdir 1 /* Initializes the lock which governs access to */
                              /* the wide directory handle list */
#endif
    /* Create the lock used to govern access to the directory handle list.
     */
    if( !hdir_lock )
      _create_lock(&hdir_lock,"creating directory lock");
}
#endif


/*--------------------------------------------------------------------------*

Name            __get_handle - get a directory handle

Usage           HANDLE_REC *__get_handle (struct ffblk *fileinfo, int allocate);

Prototype in    local

Description     __get_handle searches the list of outstanding ffblk blocks
                kept in __ffblk_handle_list for the specified block.  If it is
                found, the address of the HANDLE_REC corresponding
                to the block is returned.  If it is not found, a new
                handle record is allocated with the handle set to
                HDIR_CREATE and its address is returned.

                This scheme allows us to recycle directory handles used by
                earlier findfirst calls, since findclose need not be called.
                The new findclose call will also close these handles.

                The allocate param should be 1 to allocate space for a new one
                if not found, or 0 to simply check for it.

Return value    If successful, the address of a HANDLE_REC structure;
                otherwise NULL is returned.

*---------------------------------------------------------------------------*/

#ifdef _UNICODE
extern HANDLE_REC *__get_handle (struct ffblk *fileinfo, int allocate);
#else
HANDLE_REC *__get_handle (struct ffblk *fileinfo, int allocate)
{
    HANDLE_REC *r;

    _lock(hdir_lock,"locking directory handles");

    /* Search for a matching handle record using the
     * the address of the fileinfo block as the key.
     */
    for (r = __ffblk_handle_list; r != NULL && r->finfo != fileinfo; r = r->next)
        ;

    if (allocate)
    {
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
            r->next = __ffblk_handle_list;          /* insert at head of handle list */
            r->prev = NULL;
            if (__ffblk_handle_list)                /* hook up reverse gear */
                __ffblk_handle_list->prev = r;

            __ffblk_handle_list = r;
        }
        fileinfo->ff_reserved = (long)r;    /* save pointer to handle record */
    }
    _unlock(hdir_lock,"unlocking directory handles");
    return r;
}
#endif   // _UNICODE


/*--------------------------------------------------------------------------*

Name            _tfindfirst used as findfirst and _wfindfirst
                findfirst   - searches disk directory
                _wfindfirst - searches disk directory

Usage           int findfirst(const char *pathname, struct ffblk *ffblk,
                              int attrib);
                int _wfindfirst(const wchar_t *pathname, struct _wffblk *ffblk,
                              int attrib);

Prototype in    dir.h

Description     begins a search of a disk directory similar to the
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

int _RTLENTRYF _EXPFUNC _tfindfirst(const _TCHAR *pathname, struct _tffblk *fileinfo, int attrib)
{
  HANDLE_REC *hr;

  /* Get a handle record.
   */
  if ((hr = __get_handle((struct ffblk*)fileinfo, 1)) == NULL)
  {
      __IOerror(ERROR_NOT_ENOUGH_MEMORY);
      return (ERROR_NOT_ENOUGH_MEMORY);
  }

  hr->handle = (HANDLE)-1;        /* force FindFirst to be called */
  hr->attr   = attrib;            /* save search attributes */
  hr->name   = (char *)pathname;
  return (_tfindnext(fileinfo));
}


/*--------------------------------------------------------------------------*

Name            _tGetVol used as GetVol and _wGetVol
                GetVol   - Gets the drive volume from the specified path
                _wGetVol - Gets the drive volume from the specified path

Usage           char *GetVol (char *path)
                wchar_t *GetVol (wchar_t *path)

Return value    ASCIIZ volume string
                or
                NULL if an error occured
*---------------------------------------------------------------------------*/

static _TCHAR *_tGetVol (_TCHAR *s)
{
    static _TCHAR buf[256];
           _TCHAR drive[7];

    _tfullpath (buf, s, 255);
    _tfnsplit (buf, drive, NULL, NULL, NULL);
    _tcscat (drive,_TEXT("\\"));
    buf[0] = 0;
    if (GetVolumeInformation (drive, buf, 255, NULL, NULL, NULL, NULL, 0))
        return buf;

  return NULL;
}

/*--------------------------------------------------------------------------*

Name            _tfindclose used as findclose and _wfindclose
                findclose   - closes handles associated with a previous
                              findfirst/findnext call
                _wfindclose - same

Usage           int findclose(struct ffblk *ffblk);
                int _wfindclose(struct _wffblk *ffblk);

Prototype in    dir.h

Description     findclose closes any handles and frees up any dynamic
                memory associated with previous calles to findfirst/findnext.

Return value    success : 0
                else : -1 and errno is set to
                        EINVDAT Invalid data

*---------------------------------------------------------------------------*/
int _RTLENTRYF _EXPFUNC _tfindclose(struct _tffblk *fileinfo)
{
    HANDLE_REC * hr;

    if (!fileinfo)
    {
        errno = EINVDAT;
        return -1;
    }

    /* Look to see if this ffblk is in our list of open blocks */
    if ((hr = __get_handle((struct ffblk*)fileinfo, 0)) == NULL)
    {
        /* Not in our list, so don't attempt to free it */
        errno = EINVDAT;
        return -1;
    }

    _lock(hdir_lock,"locking directory handles (findclose)");

    /* It is in our list, so free all resources pertaining to this ffblk */
    if (hr->handle)
        FindClose(hr->handle);

    hr->handle = 0;
    hr->finfo = 0;

    /* unlink the node from the list */

    if (!hr->prev)  /* If the node is the first in the list */
    {
        __ffblk_handle_list = hr->next;
        if (hr->next)
          hr->next->prev = NULL;
    }
    else
    {
        if (hr->next)
          hr->next->prev = hr->prev;
        if (hr->prev)
          hr->prev->next = hr->next;
    }
    free (hr);

    _unlock(hdir_lock,"unlocking directory handles (findclose)");

    return 0;
}

/*--------------------------------------------------------------------------*

Name            _tfindnext used as findnext and _wfindnext
                findnext   - fetches files which match findfirst
                _wfindnext - fetches files which match _wfindfirst

Usage           int findnext(struct ffblk *ffblk);
                int _wfindnext(struct _wffblk *ffblk);

Prototype in    dir.h

Description     _tfindnext is used to fetch subsequent files which
                match the pathname given in _tfindfirst.  ffblk is the
                same block filled in by the _tfindfirst call.  This
                block contains necessary information for continuing
                the search.  One file name for each call to _tfindnext will
                be returned until no more files are found in the directory
                matching the pathname.

Return value    success : 0
                else : -1 and errno is set to
                        ENOENT  Path or file name not found
                        ENMFILE No more files

*---------------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC _tfindnext(struct _tffblk *fileinfo)
{
  WIN32_FIND_DATA ff;
  HANDLE_REC *hr;
  FILETIME local;
  BOOL found;
  _TCHAR *ptr;

  hr = (HANDLE_REC *)fileinfo->ff_reserved;

  /* If requested attributes word has the Volume ID bit set,
   * and if the volume label entry has already been returned
   * return "done".
   */
  if ((hr->attr & _A_VOLID) && hr->handle == (HANDLE)-2)
      return(-1);

  /* If requested attributes word has the Volume ID bit set,
   * get and return the volume label entry (only on first call).
   */
  if ((hr->attr & _A_VOLID) && hr->handle == (HANDLE)-1)
  {
      fileinfo->ff_attrib = _A_VOLID;
      ptr = _tGetVol ((_TCHAR*)(hr->name));
      if (ptr)
      {
          _tcscpy(fileinfo->ff_name, ptr);
          hr->handle = (HANDLE)-2;      /* note that the volume has been
                                         * returned
                                         */
          return 0;
      }
      else
          return (__DOSerror() == 0 ? 0 : -1);
  }

  for (;;)
  {
      if ((hr->handle == (HANDLE)-1) || (hr->handle == (HANDLE)-2))
      {
          hr->handle = (HANDLE)-1;      /* in case it's -2
                                         */
          hr->handle = FindFirstFile((_TCHAR*)(hr->name), &ff);
          found = hr->handle != (HANDLE)-1;
      }
      else
          found = FindNextFile(hr->handle, &ff);
      if (!found)
          return (__DOSerror() == 0 ? 0 : -1);

      /* If requested attribute word includes hidden, system, or
       * subdirectory bits, return normal files AND files with
       * any of the requested attributes.
       */
      else if ((ff.dwFileAttributes & SPECIAL_BITS) == 0 ||
               (hr->attr & ff.dwFileAttributes & SPECIAL_BITS) != 0)
          break;
  }

  /* Fill in the find_t structure from the NT structure.
   */
  fileinfo->ff_attrib = ff.dwFileAttributes;

  /* Convert times from GM to Local
   */
  FileTimeToLocalFileTime(&ff.ftLastWriteTime, &local);

  FileTimeToDosDateTime(&local, &fileinfo->ff_fdate, &fileinfo->ff_ftime);
  fileinfo->ff_fsize = ff.nFileSizeLow;
  _tcscpy(fileinfo->ff_name, ff.cFileName);
  return (0);
}
