/*------------------------------------------------------------------------*/
/*                                                                        */
/*  MEMMGR.H                                                              */
/*                                                                        */
/*  Copyright (c) 1991, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( CLASSLIB_MEMMGR_H )
#define CLASSLIB_MEMMGR_H

#if !defined( __STDLIB_H )
#include <stdlib.h>
#endif

#if !defined( __DOS_H )
#include <dos.h>
#endif

#if !defined( __CHECKS_H )
#include <checks.h>
#endif

#if !defined( CLASSLIB_DEFS_H )
#include <classlib/defs.h>
#endif

#if !defined( CLASSLIB_STDTEMPL_H )
#include <classlib/stdtempl.h>
#endif

#if !defined( CLASSLIB_ALLOCTR_H )
#include <classlib/alloctr.h>
#endif

#pragma option -Vo-
#if defined( BI_CLASSLIB_NO_po )
#pragma option -po-
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class Alloc> class TMBlockList                              */
/*                                                                        */
/*  Used internally.                                                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class Alloc> class TMBaseMemBlocks;

template <class Alloc> class TMBlockList
{

public:

    TMBlockList( TMBlockList * );

private:

    void *operator new( size_t, size_t, const Alloc& );
    void *operator new [] ( size_t, size_t, const Alloc& );
    void operator delete( void * );
    void operator delete [] ( void * );

    TMBlockList *Next;

    friend TMBaseMemBlocks<Alloc>;

};

template <class Alloc>
inline TMBlockList<Alloc>::TMBlockList( TMBlockList<Alloc> *nxt ) :
    Next( nxt )
{
}

template <class Alloc>
inline void *TMBlockList<Alloc>::operator new ( size_t sz,
                                            size_t extra,
                                            const Alloc& a )
{
    return new(a)char[sz+extra];
}

template <class Alloc>
inline void TMBlockList<Alloc>::operator delete ( void *ptr )
{
    Alloc::operator delete(ptr);
}

template <class Alloc>
inline void TMBlockList<Alloc>::operator delete [] ( void _BIDSFAR * ptr )
{
    Alloc::operator delete [] (ptr);
}

#if defined( BI_OLDNAMES )
#define MBlockList TMBlockList
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TBlockList                                                      */
/*                                                                        */
/*  Used internally.                                                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

class TBlockList : public TMBlockList<TStandardAllocator>
{

public:

    TBlockList( TBlockList *blk ) :
        TMBlockList<TStandardAllocator>( blk ) {}

};

#if defined( BI_OLDNAMES )
#define BlockList TBlockList
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class Alloc> class TMBaseMemBlocks                          */
/*                                                                        */
/*  Used internally.                                                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class Alloc> class TMBaseMemBlocks :
    public Alloc
{

public:

    TMBaseMemBlocks( size_t = 8192 );
    ~TMBaseMemBlocks();

    char *Block() const { return REINTERPRET_CAST(char *,CurBlock); }
    unsigned Count() const { return BlockCount; }
    AllocBlock( size_t );
    void FreeTo( unsigned );
    size_t GetBlockSize() const { return BlockSize; }

private:

    TMBlockList<Alloc> *CurBlock;
    const size_t BlockSize;
    unsigned BlockCount;

};

template <class Alloc>
inline TMBaseMemBlocks<Alloc>::TMBaseMemBlocks( size_t sz ) :
    CurBlock(0),
    BlockCount(0),
    BlockSize(sz)
{
    CHECK( sz != 0 );
}

template <class Alloc>
inline TMBaseMemBlocks<Alloc>::~TMBaseMemBlocks()
{
#if !defined( BI_WINDOWS_WEP_BUG )
    FreeTo( 0 );
#endif
}

template <class Alloc> int TMBaseMemBlocks<Alloc>::AllocBlock( size_t sz )
{
    TMBlockList<Alloc> *temp = 
        new( max(sz,BlockSize), *this ) TMBlockList<Alloc>( CurBlock-1 );
    if( temp == 0 )
        return 0;
    CurBlock = temp+1;
    BlockCount++;
    return 1;
}

template <class Alloc> void TMBaseMemBlocks<Alloc>::FreeTo( unsigned term )
{
    PRECONDITION( BlockCount >= term );
    while( BlockCount > term )
        {
        TMBlockList<Alloc> *temp = CurBlock-1;
        CurBlock = (temp->Next)+1;
        delete temp;
        BlockCount--;
        }
}

#if defined( BI_OLDNAMES )
#define MBaseMemBlocks TMBaseMemBlocks
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TBaseMemBlocks                                                  */
/*                                                                        */
/*  Used internally.                                                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

class TBaseMemBlocks : public TMBaseMemBlocks<TStandardAllocator>
{

public:

    TBaseMemBlocks( size_t sz = 8192 ) :
        TMBaseMemBlocks<TStandardAllocator>(sz) {}

};

#if defined( BI_OLDNAMES )
#define BaseMemBlocks TBaseMemBlocks
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class Alloc> class TMMemStack                               */
/*                                                                        */
/*  Managed memory stack.  Implements mark and release style memory       */
/*  management, using the allocator Alloc.                                */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class Alloc> class TMMarker;

template <class Alloc> class TMMemStack
{

public:

    friend TMMarker<Alloc>;

    TMMemStack( size_t = 8192 );

    void *Allocate( size_t );

#if defined( BI_OLDNAMES )
    void *allocate( size_t sz ) { return Allocate( sz ); }
#endif  // BI_OLDNAMES

private:

    TMBaseMemBlocks<Alloc> Data;
    size_t CurLoc;

};

#if defined( BI_OLDNAMES )
#define MMemStack TMMemStack
#endif

template <class Alloc>
inline void *operator new( size_t sz, TMMemStack<Alloc>& m )
{
    return m.Allocate( sz );
}

template <class Alloc>
inline void *operator new [] ( size_t sz, TMMemStack<Alloc>& m )
{
    return m.Allocate( sz );
}

template <class Alloc> inline TMMemStack<Alloc>::TMMemStack( size_t sz ) :
    Data( sz ),
    CurLoc(sz)
{
    CHECK( sz != 0 );
}

template <class Alloc> void *TMMemStack<Alloc>::Allocate( size_t sz )
{
    sz = max( 1U, sz );
    if( sz > Data.GetBlockSize() - CurLoc )
        if( Data.AllocBlock( sz ) == 0 )
            return 0;
        else
            CurLoc = 0;
    void *temp = Data.Block() + CurLoc;
    CurLoc += sz;
    return temp;
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class Alloc> class TMMarker                                 */
/*                                                                        */
/*  Provides the mark for TMMemStack.                                     */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class Alloc> class TMMarker
{

public:

    TMMarker( TMMemStack<Alloc>& ms ) :
        Memstk(ms),
        Blk(ms.Data.Count()),
        CurLoc(ms.CurLoc)
        {
        }

    ~TMMarker()
        {
        PRECONDITION( Blk < Memstk.Data.Count() ||
              (Blk == Memstk.Data.Count() && CurLoc <= Memstk.CurLoc )
            );
        Memstk.Data.FreeTo( Blk );
        Memstk.CurLoc = CurLoc;
        }


private:

    TMMemStack<Alloc>& Memstk;
    const unsigned Blk;
    const size_t CurLoc;

};

#if defined( BI_OLDNAMES )
#define MMarker TMMarker
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TMemStack                                                       */
/*                                                                        */
/*  Implements mark and release style memory management using the         */
/*  standard allocator.                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

class TMemStack : public TMMemStack<TStandardAllocator>
{
public:

    TMemStack( size_t sz = 8192 ) : TMMemStack<TStandardAllocator>(sz) {}

};

#if defined( BI_OLDNAMES )
#define MemStack TMemStack
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class Alloc> class TMarker                                  */
/*                                                                        */
/*  Provides the mark for TMemStack.                                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

class TMarker : public TMMarker<TStandardAllocator>
{

public:

    TMarker( TMMemStack<TStandardAllocator>& ms ) :
        TMMarker<TStandardAllocator>(ms) {}
};


/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class Alloc> class TMMemBlocks                              */
/*                                                                        */
/*  Managed single-size block allocator.  Allocates blocks                */
/*  of the size specified in the constructor, using the memory            */
/*  manager specified by Alloc.                                           */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class Alloc> class TMMemBlocks
{

public:

    TMMemBlocks( size_t, unsigned = 100 );

    void *Allocate( size_t );
    void Free( void * );

#if defined( BI_OLDNAMES )
    void *allocate( size_t sz ) { return Allocate(sz); }
    void free( void *ptr ) { Free(ptr); }
#endif  // BI_OLDNAMES

private:

    void *FreeList;
    TMMemStack<Alloc> Mem;
    size_t Size;

};

#if defined( BI_OLDNAMES )
#define MMemBlocks TMemBlocks
#endif

template <class Alloc>
inline TMMemBlocks<Alloc>::TMMemBlocks( size_t sz, unsigned count ) :
    Mem( sz*count ),
    FreeList(0),
    Size( max(sz,sizeof(void *)) )
{
    CHECK( sz != 0 && count != 0 );
}

#pragma argsused
template <class Alloc>
inline void *TMMemBlocks<Alloc>::Allocate( size_t sz )
{
    PRECONDITION( Size == max(sz,sizeof(void *)) );
    if( FreeList == 0 )
        return Mem.Allocate( Size );
    else
        {
        void *temp = FreeList;
        FreeList = *(void **)temp;
        return temp;
        }
}

template <class Alloc>
inline void TMMemBlocks<Alloc>::Free( void *block )
{
    *(void **)block = FreeList;
    FreeList = block;
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TMemBlocks                                                      */
/*                                                                        */
/*  Single-size block allocator.  Allocates blocks of the size            */
/*  specified in the constructor, using the global operator new           */
/*  and operator delete.                                                  */
/*                                                                        */
/*------------------------------------------------------------------------*/

class TMemBlocks : public TMMemBlocks<TStandardAllocator>
{

public:

    TMemBlocks( size_t sz, unsigned n = 100 ) :
        TMMemBlocks<TStandardAllocator>( sz, n ) {}

};

#if defined( BI_OLDNAMES )
#define MemBlocks TMemBlocks
#endif

typedef TMMemBlocks<TStandardAllocator> TStandardBlocks;

#if defined( BI_PLAT_WIN16 ) && defined( BI_DATA_FAR )
typedef TMMemBlocks<TSharedAllocator> TSharedBlocks;
#endif

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#pragma option -Vo.

#endif  // CLASSLIB_MEMMGR_H

