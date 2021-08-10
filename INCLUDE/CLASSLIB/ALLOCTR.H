/*--------------------------------------------------------------------*/
/*                                                                    */
/*  ALLOCTR.H                                                         */
/*                                                                    */
/*  Copyright (c) 1992, 1993 Borland International                    */
/*  All Rights Reserved                                               */
/*                                                                    */
/*--------------------------------------------------------------------*/

#if !defined( __CLASSLIB_ALLOCTR_H )
#define __CLASSLIB_ALLOCTR_H

#if !defined( __STDLIB_H )
#include <stdlib.h>
#endif  // __STDLIB_H

#if !defined( __CLASSLIB_DEFS_H )
#include "classlib\defs.h"
#endif  // __CLASSLIB_DEFS_H

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po-
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TStandardAllocator                                              */
/*                                                                        */
/*  Provides class-specific operator new and operator delete that         */
/*  simply call the global operator new and operator delete.  That        */
/*  is, TStandardAllocator does not provide any specialized behavior.     */
/*  It is used in the non-managed versions of the parametrized            */
/*  containers.                                                           */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _BIDSCLASS TStandardAllocator
{
public:
    friend void _BIDSFAR *operator new( size_t sz, const TStandardAllocator& )
        { return ::operator new( sz ); }
    friend void _BIDSFAR *operator new [] ( size_t sz, const TStandardAllocator& )
        { return ::operator new [] ( sz ); }
    friend void *operator new( unsigned, void *ptr )
        { return ptr; }
    friend void *operator new [] ( unsigned, void *ptr )
        { return ptr; }
    void operator delete( void _BIDSFAR *ptr )
        { ::operator delete( ptr ); }
    void operator delete [] ( void _BIDSFAR *ptr )
        { ::operator delete [] ( ptr ); }
};

#if defined( BI_OLDNAMES )
#define BI_StandardAllocator TStandardAllocator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TSharedAllocator                                                */
/*                                                                        */
/*  Provides class-specific operator new and operator delete that         */
/*  allocate from shared memory.                                          */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _BIDSCLASS TSharedAllocator
{
public:
    friend void _BIDSFAR *operator new( size_t sz, const TSharedAllocator& );
    friend void _BIDSFAR *operator new [] ( size_t sz, const TSharedAllocator& );
    void operator delete( void _BIDSFAR *ptr );
    void operator delete [] ( void _BIDSFAR *ptr );
};

#if defined( BI_OLDNAMES )
#define BI_SharedAllocator TSharedAllocator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T, class Alloc> class TManaged_T                      */
/*                                                                        */
/*  Provides a parametrized wrapper for type T which uses a               */
/*  class-specific operator new and operator delete supplied              */
/*  by Alloc.                                                             */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T, class Alloc> class TManaged_T : private Alloc
{

public:

    Alloc::operator delete;
    Alloc::operator delete [];

    TManaged_T() {}
    TManaged_T( const T& t ) : data(t)
        {
        }

    const TManaged_T& operator = ( const TManaged_T& t )
        {
        data = t.data;
        return *this;
        }

    operator T&()
        {
        return data;
        }

private:

    T data;

};

#if defined( BI_OLDNAMES )
#define BI_Managed_T TManaged_T
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  TSharedAllocator::operator new                                        */
/*  TSharedAllocator::operator delete                                     */
/*                                                                        */
/*  When compiling for WINDOWS, allocates memory as GMEM_DDESHARE.        */
/*  When compiling for DOS, uses the global operator new and              */
/*  operator delete.                                                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if defined( __WINDOWS__ )

#include <windows.h>

inline void _BIDSFAR *operator new( size_t sz,
                                const TSharedAllocator& )
{
    return GlobalLock( GlobalAlloc( GPTR | GMEM_DDESHARE, sz ) );
}

inline void _BIDSFAR *::operator new [] ( size_t sz,
                                      const TSharedAllocator& )
{
    return GlobalLock( GlobalAlloc( GPTR | GMEM_DDESHARE, sz ) );
}

inline void TSharedAllocator::operator delete( void _BIDSFAR *ptr )
{
    HGLOBAL hMem = (HGLOBAL)GlobalHandle(FP_SEG(ptr));
    if (GlobalUnlock(hMem))
        GlobalFree(hMem);
}

inline void TSharedAllocator::operator delete [] ( void _BIDSFAR *ptr )
{
    HGLOBAL hMem = (HGLOBAL)GlobalHandle(FP_SEG(ptr));
    if (GlobalUnlock(hMem))
        GlobalFree(hMem);
}

#else

inline void _BIDSFAR *operator new( size_t sz,
                                    const TSharedAllocator& )
{
    return ::operator new( sz );
}

inline void _BIDSFAR *operator new [] ( size_t sz,
                                    const TSharedAllocator& )
{
    return ::operator new [] ( sz );
}

inline void TSharedAllocator::operator delete( void _BIDSFAR *ptr )
{
    ::operator delete( ptr );
}

inline void TSharedAllocator::operator delete [] ( void _BIDSFAR *ptr )
{
    ::operator delete [] ( ptr );
}

#endif  // __WINDOWS__

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#endif  // __CLASSLIB_ALLOCTR_H

