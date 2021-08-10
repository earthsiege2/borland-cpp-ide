/*------------------------------------------------------------------------*/
/*                                                                        */
/*  BAGS.H                                                                */
/*                                                                        */
/*  Copyright (c) 1991, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( CLASSLIB_BAGS_H )
#define CLASSLIB_BAGS_H

#if !defined( __CHECKS_H )
#include <checks.h>
#endif

#if !defined( CLASSLIB_DEFS_H )
#include <classlib/defs.h>
#endif

#if !defined( CLASSLIB_SHDDEL_H )
#include <classlib/shddel.h>
#endif

#if !defined( CLASSLIB_VECTIMP_H )
#include <classlib/vectimp.h>
#endif

#pragma option -Vo-
#if defined( BI_CLASSLIB_NO_po )
#pragma option -po-
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class Vect, class T> class TBagAsVectorImp                  */
/*                                                                        */
/*  Implements a bag, using a vector as the underlying implementation.    */
/*  The type Vect specifies the form of the vector, either a              */
/*  TCVectorImp<T0> or a TICVectorImp<T0>.  The type T specifies the      */
/*  type of the objects to be put in the bag.  When using                 */
/*  TVectorImp<T0>, T should be the same as T0. When using                */
/*  TIVectorImp<T0>, T should be of type pointer to T0.  See              */
/*  TBagAsVector and TIBagAsVector for examples.                          */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class Vect, class T> class TBagAsVectorImp
{

public:

    TBagAsVectorImp( unsigned sz = DEFAULT_BAG_SIZE ) :
        Data(sz,1)
        {
        }

    int IsEmpty() const
        {
        return Data.IsEmpty();
        }

    int IsFull() const
        { return 0;
        }

    int GetItemsInContainer() const
        {
        return Data.Top();
        }

#if defined( BI_OLDNAMES )
    int isEmpty() const { return IsEmpty(); }
    int isFull() const { return IsFull(); }
    int getItemsInContainer() const { return GetItemsInContainer(); }
#endif

protected:

    Vect Data;

};

#if defined( BI_OLDNAMES )
#define BI_BagAsVectorImp TBagAsVectorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMBagAsVector                    */
/*  template <class T,class Alloc> class TMBagAsVectorIterator            */
/*                                                                        */
/*  Implements a managed bag of objects of type T, using a vector as      */
/*  the underlying implementation.                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T, class Alloc> class TMBagAsVectorIterator;

template <class T,class Alloc> class TMBagAsVector :
    public TBagAsVectorImp<TMCVectorImp<T,Alloc>,T>
{

    typedef TBagAsVectorImp<TMCVectorImp<T,Alloc>,T> Parent;

public:

    friend class TMBagAsVectorIterator<T,Alloc>;

    typedef void (*IterFunc)(T&, void *);
    typedef int  (*CondFunc)(const T&, void *);

    TMBagAsVector( unsigned sz = DEFAULT_BAG_SIZE ) :
        TBagAsVectorImp<TMCVectorImp<T,Alloc>,T>( sz )
        {
        }

    int Add( const T& t )
        {
        return Data.Add( t );
        }

    int Detach( const T& t )
        {
        return Data.Detach( t );
        }

    int HasMember( const T& t ) const
        {
        return Data.Find(t) != UINT_MAX;
        }

    const T *Find( const T& t ) const
        {
        unsigned loc = Data.Find(t);
        return ( loc == UINT_MAX ? 0 : &Data[loc] );
        }

    void ForEach( IterFunc iter, void *args )
        {
        Data.ForEach( iter, args, 0, Data.Top() );
        }

    T *FirstThat( CondFunc cond, void *args ) const
        {
        return Data.FirstThat( cond, args, 0, Data.Top() );
        }

    T *LastThat( CondFunc cond, void *args ) const
        {
        return Data.LastThat( cond, args, 0, Data.Top() );
        }

    void Flush()
        {
        Data.Flush();
        }

#if defined( BI_OLDNAMES )
    void add( const T& t ) { Add(t); }
    void detach( const T& t,
                 TShouldDelete::DeleteType dt = TShouldDelete::NoDelete )
        { Detach( t ); }
    int hasMember( const T& t ) const { return HasMember(t); }
    T findMember( const T& t ) const 
    { 
    PRECONDITION( HasMember(t) );
    return *Find(t);
    }
    Parent::isEmpty;
    Parent::isFull;
    Parent::getItemsInContainer;
    void forEach( IterFunc iter, void *args )
        { ForEach( iter, args ); }
    T *firstThat( CondFunc cond, void *args ) const
        { return FirstThat( cond, args ); }
    T *lastThat( CondFunc cond, void *args ) const
        { return LastThat( cond, args ); }
    void flush( TShouldDelete::DeleteType dt = TShouldDelete::DefDelete )
        {
        Flush();
        }

#endif  // BI_OLDNAMES

};

template <class T,class Alloc> class TMBagAsVectorIterator :
    private TMVectorIteratorImp<T,Alloc>
{

    typedef TMVectorIteratorImp<T,Alloc> Parent;

public:

    TMBagAsVectorIterator( const TMBagAsVector<T,Alloc>& b ) :
        TMVectorIteratorImp<T,Alloc>(b.Data)
        {
        }

    void Restart()
        {
        Parent::Restart();
        }

    Parent::operator int;
    Parent::Current;
    Parent::operator ++;

#if defined( BI_OLDNAMES )
    Parent::restart;
    Parent::current;
#endif

};

#if defined( BI_OLDNAMES )
#define BI_MBagAsVector TMBagAsVector
#define BI_MBagAsVectorIterator TMBagAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TBagAsVector                                 */
/*  template <class T> class TBagAsVectorIterator                         */
/*                                                                        */
/*  Implements a bag of objects of type T, using a vector as the          */
/*  underlying implementation and TStandardAllocator as its memory        */
/*  manager.                                                              */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TBagAsVector :
    public TMBagAsVector<T,TStandardAllocator>
{

public:

    TBagAsVector( unsigned sz = DEFAULT_BAG_SIZE ) :
        TMBagAsVector<T,TStandardAllocator>( sz )
        {
        }

};

template <class T> class TBagAsVectorIterator :
    public TMBagAsVectorIterator<T,TStandardAllocator>
{

public:

    TBagAsVectorIterator( const TBagAsVector<T>& b ) :
        TMBagAsVectorIterator<T,TStandardAllocator>(b)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_BagAsVector TBagAsVector
#define BI_BagAsVectorIterator TBagAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMIBagAsVector                   */
/*  template <class T,class Alloc> class TMIBagAsVectorIterator           */
/*                                                                        */
/*  Implements a managed bag of pointers to objects of type T,            */
/*  using a vector as the underlying implementation.                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T, class Alloc> class TMIBagAsVectorIterator;

template <class T,class Alloc> class TMIBagAsVector :
    public TBagAsVectorImp<TMICVectorImp<T,Alloc>,T *>,
    public TShouldDelete
{

    typedef TBagAsVectorImp<TMICVectorImp<T,Alloc>,T *> Parent;

public:

    typedef void (*IterFunc)(T&, void *);
    typedef int  (*CondFunc)(const T&, void *);

    friend TMIBagAsVectorIterator<T,Alloc>;

    TMIBagAsVector( unsigned sz = DEFAULT_BAG_SIZE ) :
        TBagAsVectorImp<TMICVectorImp<T,Alloc>,T *>(sz)
        {
        }

    ~TMIBagAsVector()
        {
        Flush();
        }

    int Add( T *t )
        {
        return Data.Add( t );
        }

    int Detach( T *t, DeleteType dt = NoDelete )
        {
        return Data.Detach( t, dt );
        }

    int HasMember( const T *t ) const
        {
        return Data.Find(t) != UINT_MAX;
        }

    void Flush( TShouldDelete::DeleteType dt = TShouldDelete::DefDelete )
        {
        Data.Flush( DelObj(dt), Data.Top(), 0 );
        }

    T *Find( T *t ) const
        {
        unsigned loc = Data.Find(t);
        return ( loc == UINT_MAX ? 0 : STATIC_CAST(T *,Data[loc]) );
        }

    void ForEach( IterFunc iter, void *args )
        {
        Data.ForEach( iter, args, 0, Data.Top() );
        }

    T *FirstThat( CondFunc cond, void *args ) const
        {
        return Data.FirstThat( cond, args, 0, Data.Top() );
        }

    T *LastThat( CondFunc cond, void *args ) const
        {
        return Data.LastThat( cond, args, 0, Data.Top() );
        }

#if defined( BI_OLDNAMES )
    void add( T *t ) { Add(t); }
    void detach( T *t, DeleteType dt = NoDelete ) { Detach( t, dt ); }
    void flush( TShouldDelete::DeleteType dt = TShouldDelete::DefDelete )
        { Flush( dt ); }
    T *findMember( T *t ) const { return Find(t); }
    Parent::isEmpty;
    Parent::isFull;
    Parent::getItemsInContainer;
    void forEach( IterFunc iter, void *args )
        { ForEach( iter, args ); }
    T *firstThat( CondFunc cond, void *args ) const
        { return FirstThat( cond, args ); }
    T *lastThat( CondFunc cond, void *args ) const
        { return LastThat( cond, args ); }
#endif  // BI_OLDNAMES

};

template <class T,class Alloc> class TMIBagAsVectorIterator :
    public TMICVectorIteratorImp<T,Alloc>
{

public:

    TMIBagAsVectorIterator( const TMIBagAsVector<T,Alloc>& s ) :
        TMICVectorIteratorImp<T,Alloc>(s.Data,0,s.Data.Top()) {}

};

#if defined( BI_OLDNAMES )
#define BI_MIBagAsVector TMIBagAsVector
#define BI_MIBagAsVectorIterator TMIBagAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TIBagAsVector                                */
/*  template <class T> class TIBagAsVectorIterator                        */
/*                                                                        */
/*  Implements a bag of pointers to objects of type T, using a vector as  */
/*  the underlying implementation and TStandardAllocator as its memory    */
/*  manager.                                                              */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TIBagAsVector :
    public TMIBagAsVector<T,TStandardAllocator>
{

public:

    TIBagAsVector( unsigned sz = DEFAULT_BAG_SIZE ) :
        TMIBagAsVector<T,TStandardAllocator>(sz)
        {
        }

};

template <class T> class TIBagAsVectorIterator :
    private TMIBagAsVectorIterator<T,TStandardAllocator>
{

    typedef TMIBagAsVectorIterator<T,TStandardAllocator> Parent;

public:

    TIBagAsVectorIterator( const TIBagAsVector<T>& s ) :
        TMIBagAsVectorIterator<T,TStandardAllocator>(s)
        {
        }

    void Restart()
        {
        Parent::Restart();
        }

    Parent::operator int;
    Parent::Current;
    Parent::operator ++;

#if defined( BI_OLDNAMES )
    Parent::restart;
    Parent::current;
#endif

};

#if defined( BI_OLDNAMES )
#define BI_IBagAsVector TIBagAsVector
#define BI_IBagAsVectorIterator TIBagAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TBag                                         */
/*  template <class T> class TBagIterator                                 */
/*                                                                        */
/*  Easy names for TBagAsVector and TBagAsVectorIterator.                 */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TBag :
    public TBagAsVector<T>
{

public:

    TBag( unsigned sz = DEFAULT_BAG_SIZE ) :
        TBagAsVector<T>( sz )
        {
        }

}

template <class T> class TBagIterator :
    public TBagAsVectorIterator<T>
{

public:


    TBagIterator( const TBag<T>& a ) :
        TBagAsVectorIterator<T>(a)
        {
        }

};

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#pragma option -Vo.

#endif  // CLASSLIB_BAGS_H

