/*------------------------------------------------------------------------*/
/*                                                                        */
/*  HEAPSEL.H                                                             */
/*                                                                        */
/*  Copyright (c) 1993, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __HEAPSEL_H )
#define __HEAPSEL_H

#if !defined( __DOS_H )
#include <dos.h>
#endif

#if !defined( __STDLIB_H )
#include <stdlib.h>
#endif

#if !defined( CLASSLIB_DEFS_H )
#include <classlib/defs.h>
#endif

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po-
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  The class THeapSelector provides a mechanism for assuring that two    */
/*  objects will be allocated from the same heap. Any class that inherits */
/*  from THeapSelector can use the placement new operator provided by     */
/*  this class:                                                           */
/*                                                                        */
/*      class Derived : public THeapSelector                              */
/*      {                                                                 */
/*      public:                                                           */
/*          void CreateArray() { Data = new(*this)char[17]; }             */
/*      private:                                                          */
/*          char *Data;                                                   */
/*      };                                                                */
/*                                                                        */
/*  In this way, any call to CreateArray() on an object of type Derived   */
/*  will allocate the array from the heap that was used to allocate the   */
/*  object itself, regardless of which module actually makes the call to  */
/*  CreateArray(). This is especially useful when the allocation is done  */
/*  in a virtual function that may be overridden in a separate module.    */
/*  Allocating from the same heap as the object helps prevent the sort of */
/*  problems that arise when a DLL holds on to a pointer to an object in  */
/*  an EXE that is no longer executing.                                   */
/*                                                                        */
/*  Note that under Windows THeapSelector is a __huge class. Using it     */
/*  will force all derived classes to be __huge as well. Since exported   */
/*  classes are automatically __huge this won't impose a penalty when     */
/*  used as a base class for an exported class.                           */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _BIDSFARCLASS _RTTI THeapSelector
{

public:

    THeapSelector() {};

    friend void _BIDSFARDATA *operator new( size_t sz,
                                        const THeapSelector _BIDSFARDATA &heap );
    friend void _BIDSFARDATA *operator new [] ( size_t sz,
                                        const THeapSelector _BIDSFARDATA &heap );
    void operator delete( void _BIDSFARDATA *ptr );
    void operator delete [] ( void _BIDSFARDATA *ptr );

// protected:   // workaround

    THeapSelector( const THeapSelector _BIDSFARDATA & ) {};
    THeapSelector _BIDSFARDATA & operator = ( const THeapSelector _BIDSFARDATA & )
        { return *this; };

private:

#if !defined( __FLAT__ )

    void _BIDSFARDATA *Allocate( size_t ) const;
    static void Free( void _BIDSFARDATA * );

    class HeapSetup
    {
    public:
        HeapSetup( unsigned );
        ~HeapSetup();
    private:
        unsigned SavedDS;
    };

#endif

};

#if defined( __FLAT__ )

inline void *operator new( size_t sz,
                           const THeapSelector &heap )
{
    return ::operator new( sz );
}

inline void *operator new [] ( size_t sz,
                               const THeapSelector &heap )
{
    return ::operator new[]( sz );
}

inline void THeapSelector::operator delete( void *ptr )
{
    ::operator delete( ptr );
}

inline void THeapSelector::operator delete [] ( void *ptr )
{
    ::operator delete[]( ptr );
}

#else   // 16-bit

inline void _BIDSFARDATA *operator new( size_t sz,
                                    const THeapSelector _BIDSFARDATA &heap )
{
    return heap.Allocate( sz );
}

inline void _BIDSFARDATA *operator new [] ( size_t sz,
                                    const THeapSelector _BIDSFARDATA &heap )
{
    return heap.Allocate( sz );
}

inline void THeapSelector::operator delete( void _BIDSFARDATA *ptr )
{
    THeapSelector::Free( ptr );
}

inline void THeapSelector::operator delete [] ( void _BIDSFARDATA *ptr )
{
    THeapSelector::Free( ptr );
}

inline THeapSelector::HeapSetup::HeapSetup( unsigned seg )
{
    SavedDS = _DS;
    _DS = seg;
}

inline THeapSelector::HeapSetup::~HeapSetup()
{
    _DS = SavedDS;
}

#endif

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#endif  // __HEAPSEL_H

