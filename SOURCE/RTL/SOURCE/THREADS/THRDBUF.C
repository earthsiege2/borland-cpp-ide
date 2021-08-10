/*-----------------------------------------------------------------------*
 * filename - thrdbuf.c
 *
 * function(s)
 *      _thread_buf     - allocate buffer for a thread
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1991, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.5.2.1 $        */

#include <stdlib.h>
#include <_thread.h>
#include <_malloc.h>

/*---------------------------------------------------------------------*

Name            _thread_buf - allocate buffer for a thread

Usage           void * _thread_buf(int offset, int size);

Prototype in

Description     This function returns the address of a "static" buffer
                for the current thread.  The offset must be the offset
                in the THREAD_DATA structure of a buffer pointer member.
                If that particular buffer pointer is NULL, a buffer
                of the specified size is allocated.

Return value    If successful, the address of an allocated buffer.
                If unsuccessful, a NULL pointer.

*---------------------------------------------------------------------*/

void * _thread_buf(int offset, int size)
{
    THREAD_DATA *th;
    char        *buf;
    char        **memberp;

    /* First make sure this thread has a thread data structure.
     */
    if ((th = _thread_data()) == NULL)
        return (NULL);

    /* Calculate the address of the member of the thread data structure
     * given the offset.
     */
    memberp = (char **)(((char *)th) + offset);

    /* Allocate this buffer if the pointer to it is NULL.
     */
    if ((buf = *memberp) == NULL)
    {
        if ((buf = __org_malloc(size)) == NULL)
            return (NULL);
        *memberp = buf;
    }
    return ((void *)buf);
}
