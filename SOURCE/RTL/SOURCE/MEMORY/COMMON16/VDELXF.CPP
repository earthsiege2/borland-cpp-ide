/*-----------------------------------------------------------------------*
 * filename - vdelxf.cpp
 * C++ vector_delete
 * Called internally by the compiler to deallocate arrays of classes
 * having destructors
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1990, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#include <stdlib.h>
#include <stdarg.h>
#include <dos.h>
#include <_vector.h>

void far * _vector_delete_(void far *, size_t, unsigned long, unsigned, ...);

void far * _vector_delete_(void far *ptr,   // address of array (always needed)
                           unsigned classdtorcnt,
                           size_t size,                   // size of each object
                           unsigned long count,           // how many objects
                           unsigned mode,                 // How to call
                           ...
                           )
{
    va_list ap;         // for access to parameters
    destNNC np;         // near call version
    destFNC fp;         // far call version
    unsigned long temp;
    
    if (!ptr)
        return (void far *) 0;

    va_start(ap, mode);

	if (mode & VFARCALL)
		fp = va_arg(ap, destFNC);
	else
		np = va_arg(ap, destNNC);

    if (mode & VSTORECNT)       // if stored count
        temp = *((unsigned long far *) ((char far *)ptr - sizeof(count)));
    else
        temp = count;
    
    _DestructorCount += temp * classdtorcnt;

    if (mode & VFARCALL)
        return _vector_delete_(ptr, size, count, mode, (void far *)fp);
    else
        return _vector_delete_(ptr, size, count, mode, (void near *)np);
}
