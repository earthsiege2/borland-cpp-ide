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
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1991, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

#include <ntbc.h>
#include <_malloc.h>
#include <_ostype.h>


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

int __fastcall _virt_reserve (unsigned long size, void **ptr, unsigned long *actualsize)
{
    unsigned long vsize;
    static DWORD heap_size = 0;

    if (heap_size == 0)
    {
        if (_ostype == _WIN32S || _ostype == _DOS32)
        {
            heap_size = SHEAP_SIZE;     /* on DOS, use small heap size */
        }
        else
            heap_size = HEAP_SIZE;      /* on NT, use big heap size */
    }

    vsize = ROUND_UP(size,heap_size);   /* round up to 4 Meg (1 on DOS) */
    if ((*ptr = VirtualAlloc(NULL, vsize, MEM_RESERVE, PAGE_NOACCESS)) == NULL)
        return (0);         /* failure */

    *actualsize = vsize;
    return (1);                         /* success */
}

/*---------------------------------------------------------------------*

Name            _virt_alloc - allocate virtual memory

Usage           int _virt_alloc (void **ptr, unsigned long size);

Prototype in    _malloc.h

Description     This function allocates a section of virtual address
                space.  The starting address of the section to be
                allocated is *ptr, and its length is size.  If *ptr is
                0, then the starting address is unspecified.  Both the
                starting address and the size must be multiples of the
                machine's page size.

Return value    If _virt_alloc is successful, it returns 1 and stores
                the address of the allocated region in *ptr; otherwise
                it returns 0.

*---------------------------------------------------------------------*/
int __fastcall _virt_alloc(void **ptr, unsigned long size)
{
    *ptr = VirtualAlloc(*ptr, size, MEM_COMMIT, PAGE_READWRITE);
    return *ptr != NULL;
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

int __fastcall _virt_commit(void *base, unsigned long size)
{
    void *origbase = base;

    /* Do it a page at a time, because we may be crossing a
     * section boundary.
     */
    while (size != 0)
    {
        if (VirtualAlloc(base, PAGE_SIZE, MEM_COMMIT, PAGE_READWRITE) == NULL)
        {
            _virt_decommit(origbase, (char *)base - (char *)origbase);
            return (0);     /* failure */
        }
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

int __fastcall _virt_decommit(void *base, unsigned long size)
{
    if (VirtualFree(base, size, MEM_DECOMMIT) != TRUE)
        return (0); /* failure */

    return (1);     /* success */
}


/*---------------------------------------------------------------------*

Name            _virt_release - free virtual address space of heap

Usage           int _virt_release (void *base);

Prototype in    _malloc.h

Description     This function frees a section of virtual address
                space.

Return value    If _virt_release is successful, it returns 1; otherwise
                it returns 0.

*---------------------------------------------------------------------*/

int __fastcall _virt_release(void *base)
{
    if (VirtualFree(base, 0, MEM_RELEASE) != TRUE)
        return (0); /* failure */

    return (1);     /* success */
}

