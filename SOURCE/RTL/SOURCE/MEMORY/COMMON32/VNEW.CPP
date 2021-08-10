/*-----------------------------------------------------------------------*
 * filename - vnew.cpp
 * C++ VECTOR_NEW
 * Called internally by the compiler to allocate arrays of classes
 * having constructors
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1990, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stddef.h>
#include <_io.h>

typedef void _cdecl    (* constCdecl)   (void *);
typedef void _pascal   (* constPascal)  (void *);
typedef void _fastcall (* constFastcall)(void *);
// typedef void _fortran  (* constFortran) (void *);
typedef void _stdcall  (* constStdcall) (void *);
#if defined(__OS2__)
typedef void _syscall  (* constSyscall) (void *);
#endif

#pragma argsused

void * _RTLENTRY _vector_new_(
	void *ptr,              // address of array, 0 means allocate
	size_t size,            // size of each object
	unsigned count,         // how many objects
	unsigned mode,          // actual type of constructor
	void * cons
	)
/* This routine is used to initialize an array of class type.  If ptr is
   NULL, it allocates the space for the array first.

   The interpretation of the low 3 bits of the mode parameter is:

	reserved        0x00
	_cdecl          0x01
	_pascal         0x02
	_fastcall       0x03
	_fortran        0x04
	_stdcall        0x05
	_syscall        0x06
	reserved        0x07

   The remaining bits of mode are:

	deallocate      0x08
	stored count    0x10
	save dtorcnt    0x200 
*/
{
    unsigned DtorCnt = _DestructorCount;
	
    if( ptr == 0 )
	{
	// if stored count flag then allocate extra space for count
	ptr = operator new[]((size * count)+((mode & 0x10) ? sizeof(count): 0));

	if (ptr == 0)
	    return 0;
	}

    if (mode & 0x10)        // if stored count
	{
	*(unsigned *)ptr = count;
	ptr = ((char *)ptr + sizeof(count));
	}

    if(!cons)
       return(ptr);

    for( char *p = (char *) ptr;  count-- > 0;  p += size )
	    {
		unsigned callmode = mode & 0x07; // strip out all flags except call type

	switch (callmode)
	    {
	    case 1: (*(constCdecl)    cons)((void *) p); break;
	    case 2: (*(constPascal)   cons)((void *) p); break;
	    case 3: (*(constFastcall) cons)((void *) p); break;
//          case 4: (*(constFortran)  cons)((void *) p); break;
	    case 5: (*(constStdcall)  cons)((void *) p); break;
#if defined(__OS2__)
	    case 6: (*(constSyscall)  cons)((void *) p); break;
#endif
	    default:
		    _ErrorExit("Illegal mode in _vector_new_");
		    break;
	    }
		}
	if (mode & 0x200)
		_DestructorCount = DtorCnt;

    return ptr;
}
