/*-----------------------------------------------------------------------*
 * filename - vdelxn.cpp
 * C++ vector_delete
 * Called internally by the compiler to deallocate arrays of classes
 * having destructors
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1990, 1994 by Borland International
 *      All Rights Reserved.
 *
 */


#include <stdlib.h>
#include <stdarg.h>
#include <dos.h>
#include <_vector.h>

void near * _vector_delete_(void near *, size_t, unsigned, unsigned, ...);

#if defined(__LARGE__) || defined(__HUGE__) || defined(__COMPACT__)
#pragma argsused
#endif
void near * _vector_delete_(void near *ptr,   // address of array (always needed)
                           unsigned classdtorcnt,
                           size_t size,                   // size of each object
                           unsigned count,                // how many objects
                           unsigned mode,                 // How to call
                           ...
                           )
{
#if defined(__LARGE__) || defined(__HUGE__) || defined(__COMPACT__)
    abort();
    return 0;
#else
    va_list ap;         // for access to parameters
    destNNC np;         // near call version
    destFNC fp;         // far call version
    unsigned temp;
    
    if (!ptr)
        return (void near *) 0;

    va_start(ap, mode);

    if (mode & VFARCALL)
        fp = va_arg(ap, destFNC);
    else
        np = va_arg(ap, destNNC);

    if (mode & VSTORECNT)   // if stored count
        count = *((unsigned *) ((char *)ptr - sizeof(count)));
    else
        temp = count;
    
    _DestructorCount += temp * classdtorcnt;

    if (mode & VFARCALL)
        return _vector_delete_(ptr, size, count, mode, (void far *)fp);
    else
        return _vector_delete_(ptr, size, count, mode, (void near *)np);
#endif
}
