/*-----------------------------------------------------------------------*
 * filename - virtmem.c
 *
 * function(s)
 *      _virt_release  - free virtual address space
 *      _virt_reserve  - allocate virtual address space for heap
 *      _virt_commit   - commit pages of heap
 *      _virt_decommit - decommit pages of heap
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>
#include <_malloc.h>


/* The following definition must be 1 if the RTL is to work on broken
 * versions of Win32S that don't allow VirtualAlloc() to have a protection
 * parameter of PAGE_NOACCESS.  Set it to 0 when VirtualAlloc() works again.
 */
static int WIN32S_BUG;

/*---------------------------------------------------------------------*

Name            _virt_reserve - allocate virtual address space for heap

Usage           int _virt_reserve (unsigned long size, void **ptr,
                    unsigned long *actualsize);

Prototype in    _malloc.h

Description     This function allocates a section of virtual address
                space.  The size is specified in bytes, and is rounded
                up to the next multiple of HEAPSIZE (4 megabytes on
                OS/2 and NT, 1 megabyte on Win32/DOS).  The pages in
                the allocated area are initially decommitted, and must
                be committed with _virt_commit before they can be used.
                The base virtual address of the newly allocated area is
                returned to *ptr, and its actual size is returned to
                *actualsize.

Return value    If _virt_reserve is successful, it returns 1 and returns
                the base and size of the allocate area to *ptr and
                *actualsize, respectively.  If the function is not
                successful, it returns 0, and the values of *ptr and
                *actualsize are undefined.

*---------------------------------------------------------------------*/

int _virt_reserve (unsigned long size, void **ptr, unsigned long *actualsize)
{
    unsigned long vsize;
    static DWORD heap_size = 0;
    DWORD oldprot;

    /* Determine if we are running on a system that supports uncommited
     * memory.  Do this by calling GetVersion(), which will return the
     * high bit set on NT and some other 32bit DPMI servers but not on WIN32S.
     * We use this information to determine the size of the virtual
     * address allocated for a heap section: 1 meg for commited,
     *                                       4 meg for uncommited.
     */
    if (heap_size == 0)
    {
        if (GetVersion() & 0x80000000L)
            {
            WIN32S_BUG = 0;
            heap_size = SHEAP_SIZE;     /* on DOS, use small heap size */
            }
        else
            heap_size = HEAP_SIZE;      /* on NT, use big heap size */
    }

    vsize = ROUND_UP(size,heap_size);       /* round up to 4 Meg (1 on DOS) */
    if (WIN32S_BUG)
        {
        if ((*ptr = VirtualAlloc(NULL, vsize, MEM_COMMIT, PAGE_READWRITE)) == NULL)
            return (0);         /* failure */
        }
    else
        {
        if ((*ptr = VirtualAlloc(NULL, vsize, MEM_RESERVE, PAGE_NOACCESS)) == NULL)
            return (0);         /* failure */
        }

    *actualsize = vsize;
    return (1);                 /* success */
}

/*---------------------------------------------------------------------*

Name            _virt_commit - commit pages of heap

Usage           int _virt_commit (void *base, unsigned long size);

Prototype in    _malloc.h

Description     This function commits a section of virtual address
                space.  The starting address of the section to be committed
                is base, and its length is size.  Both the base and the
                size must be multiples of the machine's page size.

Return value    If _virt_commit is successful, it returns 1; otherwise
                it returns 0.

*---------------------------------------------------------------------*/

int _virt_commit(void *base, unsigned long size)
{
    /* Do it a page at a time, because we may be crossing a
     * section boundary.
     */
    if (!WIN32S_BUG)
        while (size != 0)
        {
            if (VirtualAlloc(base, PAGE_SIZE, MEM_COMMIT, PAGE_READWRITE) == NULL)
                return (0);     /* failure */
            base = (void *)((char *)base + PAGE_SIZE);
            size -= PAGE_SIZE;
        }
    return (1);             /* success */
}

/*---------------------------------------------------------------------*

Name            _virt_decommit - decommit pages of heap

Usage           int _virt_decommit (void *base, unsigned long size);

Prototype in    _malloc.h

Description     This function decommits a section of virtual address
                space.  The starting address of the section to be decommitted
                is base, and its length is size, which must be a multiple
                of the machine's page size.  The pages must have been
                previously committed; after this call, they are no
                longer accessible.

Return value    If _virt_commit is successful, it returns 1; otherwise
                it returns 0.

*---------------------------------------------------------------------*/

int _virt_decommit(void *base, unsigned long size)
{
    /* Do it a page at a time, because we may be crossing a
     * section boundary.
     */
    if (!WIN32S_BUG)
        while (size != 0)
        {
            if (VirtualFree(base, PAGE_SIZE, MEM_DECOMMIT) != TRUE)
                return (0);     /* failure */
            base = (void *)((char *)base + PAGE_SIZE);
            size -= PAGE_SIZE;
        }
    return (1);             /* success */
}


/*---------------------------------------------------------------------*

Name            _virt_release - free virtual address space of heap

Usage           int _virt_release (void *base);

Prototype in    _malloc.h

Description     This function frees a section of virtual address
                space.  The pages must have been previously
                decommitted

Return value    If _virt_release is successful, it returns 1; otherwise
                it returns 0.

*---------------------------------------------------------------------*/

int _virt_release(void *base)
{
    if (VirtualFree(base, 0, MEM_RELEASE) != TRUE)
        return (0);     /* failure */
    return (1);         /* success */
}

