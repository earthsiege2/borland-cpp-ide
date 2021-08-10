/*-----------------------------------------------------------------------*
 * filename - vdel.cpp
 * C++ vector_delete
 * Called internally by the compiler to deallocate arrays of classes
 * having destructors
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1990, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.3 $        */

#include <stddef.h>
#include <_io.h>

typedef void _cdecl    (* destCdecl)   (void *, int);
typedef void _pascal   (* destPascal)  (int, void *);
typedef void _fastcall (* destFastcall)(int, void *);
typedef void _stdcall  (* destStdcall) (void *, int);
#if defined(__OS2__)
typedef void _syscall  (* destSyscall) (void *, int);
#endif

#pragma argsused

void * _RTLENTRY _vector_delete_(
             void *ptr,                 // address of array (always needed)
             unsigned classdtorcnt,       
             size_t size,               // size of each object
             unsigned count,            // how many objects
             unsigned mode,             // How to call
             void * dest
            )
/*
   The interpretation of the low 3 bits of the mode parameter is:

        reserved        0x00
        _cdecl          0x01
        _pascal         0x02
        _fastcall       0x03
        _fortran        0x04    // Not used
        _stdcall        0x05
        _syscall        0x06
        reserved        0x07

   The remaining bits of mode are:

        deallocate      0x08
        stored count    0x10
*/
{
    unsigned temp;

    if (ptr == 0)
        return (void *) 0;

   if (mode & 0x10)       // if stored count
        temp = *((unsigned *)ptr - 1);
    else
        temp = count;

   _DestructorCount += temp * classdtorcnt;

   return _vector_delete_(ptr, size, count, mode, dest);
}
