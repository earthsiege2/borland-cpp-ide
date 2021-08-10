/*-----------------------------------------------------------------------*
 * filename - vappv.cpp
 * C++ VECTOR APPLY for virtual base classes
 * This is called internally by the compiler to copy
 * arrays of classes having assignment operators or ref constructors
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1990, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <stddef.h>
#include <_io.h>

typedef void _cdecl    (* appCdecl)   (void *, int, void *);
typedef void _pascal   (* appPascal)  (int, void *, void *);
typedef void _fastcall (* appFastcall)(void *, int, void *);
typedef void _stdcall  (* appStdcall) (void *, int, void *);
#if defined(__OS2__)
typedef void _syscall  (* appSyscall) (void *, int, void *);
#endif

void _RTLENTRY _EXPFUNC _vector_vapply_(
                      void * dest,      // address of destination array
                      void * src,       // address of source array
                      size_t size,      // size of each object
                      unsigned count,   // number of objects
                      unsigned mode,    // type of function to call
                      void * app
                     )

/* This routine is used to copy an array of class type.

   The interpretation of the low 3 bits of the mode parameter is:

        reserved        0x00
        _cdecl          0x01
        _pascal         0x02
        _fastcall       0x03
        _fortran        0x04    // Not used
        _stdcall        0x05
        _syscall        0x06
        reserved        0x07

*/
{
    mode &= 7;
    do
    {
        switch (mode)
            {
            case 1: (*(appCdecl)    app)((void *) dest, 0, (void *) src); break;
            case 2: (*(appPascal)   app)(0, (void *) src, (void *) dest); break;
            case 3: (*(appFastcall) app)((void *) dest, 0, (void *) src); break;
            case 5: (*(appStdcall)  app)((void *) dest, 0, (void *) src); break;
#if defined(__OS2__)
            case 6: (*(appSyscall)  app)((void *) dest, 0, (void *) src); break;
#endif
            default:
                    _ErrorExit("Illegal mode in _vector_applyv_");
                    break;
            }
        (char *) dest += size;
        (char *) src += size;
    } while (--count > 0);
}
