/*-----------------------------------------------------------------------*
 * filename - vnwvldtc.cpp
 * C++ VECTOR_NEW for virtual base classes.
 * Called internally by the compiler to allocate arrays of classes
 * having constructors.  Local destructor count version.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1996, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision         */

#include <stddef.h>
#include <_io.h>

typedef void _cdecl    (* constCdecl)   (void *, unsigned);
typedef void _pascal   (* constPascal)  (void *, unsigned);
typedef void _fastcall (* constFastcall)(void *, unsigned);
typedef void _stdcall  (* constStdcall) (void *, unsigned);
#if defined(__OS2__)
typedef void _syscall  (* constSyscall) (void *, unsigned);
#endif

typedef void _cdecl    (* consvCdecl)   (void *, int);
typedef void _pascal   (* consvPascal)  (int, void *);
typedef void _fastcall (* consvFastcall)(void *, int);
typedef void _stdcall  (* consvStdcall) (void *, int);
#if defined(__OS2__)
typedef void _syscall  (* consvSyscall) (void *, int);
#endif

#pragma argsused

void * _RTLENTRY _vector_vnew_ldtc_(
                 void *ptr,               // address of array, 0 means allocate
                 size_t size,             // size of each object
                 unsigned count,          // how many objects
                 unsigned mode,           // actual type of constructor
                 void * cons,
                 unsigned dtorMode,       // actual type of destructor
                 void * dtor              // addr of the destructor
                 )
/* This routine is used to initialize an array of class type.  If ptr is
   NULL, it allocates the space for the array first.

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
        save dtorcnt    0x200
*/
{
    int eltCount;
    int allocatedHere;

    try
    {
        if (ptr == 0)
        {
            // if stored count flag then allocate extra space for count
            ptr = operator new[]((size * count)+((mode & 0x10) ? sizeof(count): 0));

            if (ptr == 0)
                return 0;

            allocatedHere = 1;
        }
        else
            allocatedHere = 0;

        if (mode & 0x10)        // if stored count
        {
            *(unsigned *)ptr = count;
            ptr = ((char *)ptr + sizeof(count));
        }

        if (!cons)
            return(ptr);

        eltCount = count;
        for (char *p = (char *) ptr;  eltCount-- > 0; p += size)
        {
            unsigned callmode = mode & 0x07; // strip out all flags except call type

            switch (callmode)
            {
            case 1: (*(consvCdecl)    cons)((void *) p, 0); break;
            case 2: (*(consvPascal)   cons)(0, (void *) p); break;
            case 3: (*(consvFastcall) cons)((void *) p, 0); break;
            case 5: (*(consvStdcall)  cons)((void *) p, 0); break;
#if defined(__OS2__)
            case 6: (*(consvSyscall)  cons)((void *) p, 0); break;
#endif
            default:
                _ErrorExit("Illegal mode in _vector_newv_");
                break;
            }
        }
    }
    catch   (...)
    {
        int i;
        unsigned callmode = dtorMode & 0x07; // strip out all flags except call type

        /*
            Oops.  Took an exception when constructing the array.
            Have to clean up the mess.
        */

        i = count - eltCount - 1;
        for (char *p = (char *) ptr + (size * (i - 1));  i-- > 0;  p -= size)
        {

            switch (callmode)
            {
            case 0:                                         break;
            case 1: (*(constCdecl)    dtor)((void *) p, 0); break;
            case 2: (*(constPascal)   dtor)((void *) p, 0); break;
            case 3: (*(constFastcall) dtor)((void *) p, 0); break;
            case 5: (*(constStdcall)  dtor)((void *) p, 0); break;
#if defined(__OS2__)
            case 6: (*(constSyscall)  dtor)((void *) p, 0); break;
#endif
            default:
                _ErrorExit("Illegal dtorMode in _vector_new_");
                break;
            }

        }
        if (allocatedHere)
            operator delete [](ptr);
        throw;
    }

    return ptr;
}
