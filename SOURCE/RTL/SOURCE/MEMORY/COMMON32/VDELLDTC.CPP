/*-----------------------------------------------------------------------*
 * filename - vdelltdc.cpp
 * C++ vector_delete
 * Called internally by the compiler to deallocate arrays of classes
 * having destructors.  Local destructor count version.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1996, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision         */

#include <stddef.h>
#include <_io.h>

typedef void _cdecl(*destCdecl) (void *, int);
typedef void _pascal(*destPascal) (int, void *);
typedef void _fastcall(*destFastcall) (void *, int);
typedef void _stdcall(*destStdcall) (void *, int);

#if defined(__OS2__)
typedef void _syscall(*destSyscall) (void *, int);

#endif

#pragma argsused

void *_RTLENTRY _vector_delete_ldtc_(
                       void *ptr,   // address of array (always needed)
                       size_t size,    // size of each object
                       unsigned count,     // how many objects
                       unsigned mode,  // How to call
                       void *dest
)
/* This routine is used to destroy an array of class type.  If mode is
   set, it deallocates the space for the array afterwards.

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
    int dealloc = mode & 0x08;
    int stored_count = mode & 0x10;

    try
    {
        if (ptr == 0)
            return (void *) 0;

        if (stored_count)   // if stored count

            count = *((unsigned *) ptr - 1);

        mode &= 0x07;   // strip out all flags except call type

        for (char *p = (char *)ptr + size * (count - 1); count-- > 0; p -= size)
        {
            switch (mode)
            {
            case 1: (*(destCdecl)    dest) ((void *) p, 2); break;
            case 2: (*(destPascal)   dest) (2, (void *) p); break;
            case 3: (*(destFastcall) dest) ((void *) p, 2); break;
            case 5: (*(destStdcall)  dest) ((void *) p, 2); break;
#if defined(__OS2__)
            case 6: (*(destSyscall)  dest) ((void *) p, 2); break;
#endif
            default:
                _ErrorExit("Illegal mode in _vector_delete_");
                break;
            }
        }

        if (stored_count)
            ptr = (char *) ptr - sizeof(count);

        if (dealloc)
            operator delete[] ((void *) ptr);

        else
            return (void *) ptr;
    }
    catch (...)
    {
        _vector_delete_ldtc_(ptr, size, count, mode, dest);
        throw;
    }

    return (void *) 0;
}

