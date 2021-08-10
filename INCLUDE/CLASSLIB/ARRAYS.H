//----------------------------------------------------------------------------
// Borland BIDS Container Library
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.8  $
//
//----------------------------------------------------------------------------
#if !defined( CLASSLIB_ARRAYS_H )
#define CLASSLIB_ARRAYS_H

//#define TEMPLATES

#if !defined( CLASSLIB_DEFS_H )
# include <classlib/defs.h>
#endif
#if !defined( CLASSLIB_SHDDEL_H )
# include <classlib/shddel.h>
#endif
#if !defined( CLASSLIB_ALLOCTR_H )
# include <classlib/alloctr.h>
#endif
#if !defined( CLASSLIB_VECTIMP_H )
# include <classlib/vectimp.h>
#endif

#pragma option -Vo-
#if defined( BI_CLASSLIB_NO_po )
# pragma option -po-
#endif

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  [INTERNAL USE ONLY]                                                   */
/*                                                                        */
/*  template <class Vect, class T> class TArrayAsVectorImp                */
/*                                                                        */
/*  Implements the type-independent array operations, using a vector      */
/*  as the underlying implementation.  The type Vect specifies the        */
/*  form of the vector, either a TCVectorImp<T0>, a TSVectorImp<T0>, a    */
/*  TICVectorImp<T0>, or a TISVectorImp<T0>.  The type T specifies the    */
/*  type of the objects to be put in the array.  When using               */
/*  TCVectorImp<T0> or a TSVectorImp<T0> T should be the same as T0. When */
/*  using TICVectorImp<T0> or TISVectorImp<T0> T should be of type        */
/*  pointer to T0.  See TArrayAsVector and                                */
/*  TIArrayAsVector for examples.                                         */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class Vect, class T> class TArrayAsVectorImp
{

public:

    TArrayAsVectorImp( int upper, int lower, int delta ) :
        Data( upper-lower+1,delta ),
        Lowerbound( lower )
        {
        }

    int LowerBound() const
        {
        return Lowerbound;
        }

    int UpperBound() const
        {
        return BoundBase( Data.Limit() )-1;
        }

    unsigned ArraySize() const
        {
        return Data.Limit();
        }

    int IsFull() const
        {
        return Data.GetDelta() == 0 && Data.Count() >= Data.Limit();
        }

    int IsEmpty() const
        {
        return Data.Count() == 0;
        }

    unsigned GetItemsInContainer() const
        {
        return Data.Count();
        }

#if defined( BI_OLDNAMES )
    int lowerBound() const { return LowerBound(); }
    int upperBound() const { return UpperBound(); }
    unsigned arraySize() const { return ArraySize(); }
    int isFull() const { return IsFull(); }
    int isEmpty() const { return IsEmpty(); }
    unsigned getItemsInContainer() const { return GetItemsInContainer(); }
#endif

    void Reallocate( unsigned sz, unsigned offset = 0 )
        {
        Data.Resize( sz, offset );
        }


    void SetData( int loc, const T& t )
        {
        PRECONDITION( loc >= Lowerbound && loc <= UpperBound() );
        Data[ ZeroBase(loc) ] = t;
        }

    void RemoveEntry( int loc )
        {
        SqueezeEntry( ZeroBase(loc) );
        }

    void SqueezeEntry( unsigned loc )
        {
        PRECONDITION( loc < Data.Count() );
        Data.Detach( loc );
        }

    unsigned ZeroBase( int loc ) const
        {
        return loc - Lowerbound;
        }

    int BoundBase( unsigned loc ) const
        {
        return loc == UINT_MAX ? INT_MAX : loc + Lowerbound;
        }

    void Grow( int loc )
        {
        if( loc < LowerBound() )
            Reallocate( ArraySize() + (loc - Lowerbound) );
        else if( loc >= BoundBase( Data.Limit()) )
            Reallocate( ZeroBase(loc) );
        }

    int Lowerbound;

    Vect Data;

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  [INTERNAL USE ONLY]                                                   */
/*                                                                        */
/*  template <class Vect, class T> class TDArrayAsVectorImp               */
/*                                                                        */
/*  Implements the fundamental array operations for direct arrays, using  */
/*  a vector as the underlying implementation.                            */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class Vect, class T> class TDArrayAsVectorImp :
    public TArrayAsVectorImp<Vect,T>
{

public:

    typedef void (*IterFunc)(T&, void *);
    typedef int  (*CondFunc)(const T&, void *);

    TDArrayAsVectorImp( int upper, int lower, int delta ) :
        TArrayAsVectorImp<Vect,T>( upper, lower, delta )
        {
        }

    int Add( const T& t )
        {
        return Data.Add(t);
        }

    int Detach( const T& t )
        {
        return Data.Detach(t);
        }

    int Detach( int loc )
        {
        return Data.Detach( ZeroBase(loc) );
        }

    int Destroy( const T& t )
        {
        return Detach(t);
        }

    int Destroy( int loc )
        {
        return Detach(loc);
        }

    int HasMember( const T& t ) const
        {
        return Data.Find(t) != UINT_MAX;
        }

    int Find( const T& t ) const
        {
        return BoundBase( Data.Find( t ) );
        }

    T& operator []( int loc )
        {
        Grow( loc+1 );
        return Data[ZeroBase(loc)];
        }

    T& operator []( int loc ) const
        {
        PRECONDITION( loc >= Lowerbound && ZeroBase(loc) < Data.Limit() );
        return Data[ZeroBase(loc)];
        }

    void ForEach( IterFunc iter, void *args )
        {
        if( !IsEmpty() )
            Data.ForEach( iter, args );
        }

    T *FirstThat( CondFunc cond, void *args ) const
        {
        if( IsEmpty() )
            return 0;
        return Data.FirstThat( cond, args );
        }

    T *LastThat( CondFunc cond, void *args ) const
        {
        if( IsEmpty() )
            return 0;
        return Data.LastThat( cond, args );
        }

    void Flush()
        {
        Data.Flush();
        }

#if defined( BI_OLDNAMES )
    int add( const T& t ) { return Add(t); }
    int detach( const T& t,TShouldDelete::DeleteType=TShouldDelete::NoDelete)
        { return Detach(t); }
    int detach( int loc,TShouldDelete::DeleteType=TShouldDelete::NoDelete)
        { return Detach(loc); }
    int destroy( const T& t ) { return Destroy(t); }
    int destroy( int loc,TShouldDelete::DeleteType ) { return Destroy(loc); }
    int hasMember( const T& t ) const { return HasMember(t); }
    void forEach( IterFunc iter, void *args )
        { ForEach( iter, args ); }
    T *firstThat( CondFunc cond, void *args ) const
        { return FirstThat( cond, args ); }
    T *lastThat( CondFunc cond, void *args ) const
        { return lastThat( cond, args ); }
    void flush( TShouldDelete::DeleteType = TShouldDelete::DefDelete )
        { Flush(); }
#endif

protected:

    const T& ItemAt( int i ) const
        {
        return Data[ ZeroBase(i) ];
        }

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  [INTERNAL USE ONLY]                                                   */
/*                                                                        */
/*  template <class Vect, class T> class TIArrayAsVectorImp               */
/*                                                                        */
/*  Implements the fundamental array operations for indirect arrays,      */
/*  using a vector as the underlying implementation.                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class Vect, class T> class TIArrayAsVectorImp :
    public TArrayAsVectorImp<Vect,T *>, public TShouldDelete
{

public:

    typedef void (*IterFunc)(T&, void *);
    typedef int  (*CondFunc)(const T&, void *);

    TIArrayAsVectorImp( int upper, int lower, int delta ) :
        TArrayAsVectorImp<Vect,T *>( upper, lower, delta )
        {
        }

    ~TIArrayAsVectorImp()
        {
        Flush();
        }

    int Add( T *t )
        {
        return Data.Add(t);
        }

    int Detach( T *t,
                TShouldDelete::DeleteType dt = TShouldDelete::NoDelete )
        {
        return Data.Detach(t,DelObj(dt));
        }

    int Detach( int loc,
                TShouldDelete::DeleteType dt = TShouldDelete::NoDelete )
        {
        return Data.Detach( ZeroBase(loc), DelObj(dt) );
        }

    int Destroy( T *t )
        {
        return Detach(t,TShouldDelete::Delete);
        }

    int Destroy( int loc )
        {
        return Detach(loc,TShouldDelete::Delete);
        }

    int HasMember( const T *t ) const
        {
        return Data.Find(t) != UINT_MAX;
        }

    int Find( const T *t ) const
        {
        return BoundBase( Data.Find( t ) );
        }

    T *& operator []( int loc )
        {
        Grow( loc+1 );
        return Data[ZeroBase(loc)];
        }

    T *& operator []( int loc ) const
        {
        PRECONDITION( loc >= Lowerbound && ZeroBase(loc) < Data.Limit() );
        return Data[ZeroBase(loc)];
        }

    void ForEach( IterFunc iter, void *args )
        {
        if( !IsEmpty() )
            Data.ForEach( iter, args );
        }

    T *FirstThat( CondFunc cond, void *args ) const
        {
        if( IsEmpty() )
            return 0;
        return Data.FirstThat( cond, args );
        }

    T *LastThat( CondFunc cond, void *args ) const
        {
        if( IsEmpty() )
            return 0;
        return Data.LastThat( cond, args );
        }

    void Flush( DeleteType dt = DefDelete )
        {
        Data.Flush(DelObj(dt));
        }

#if defined( BI_OLDNAMES )
    int add( T *t ) { return Add(t); }
    int detach( T *t,TShouldDelete::DeleteType dt =TShouldDelete::NoDelete)
        { return Detach(t,dt); }
    int detach( int loc,TShouldDelete::DeleteType dt =TShouldDelete::NoDelete)
        { return Detach(loc,dt); }
    int destroy( T *t ) { return Destroy(t); }
    int destroy( int loc,TShouldDelete::DeleteType ) { return Destroy(loc); }
    int find( const T *t ) const { return Find(t); }
    int hasMember( T *t ) const { return HasMember(t); }
    void forEach( IterFunc iter, void *args )
        { ForEach( iter, args ); }
    T *firstThat( CondFunc cond, void *args ) const
        { return FirstThat( cond, args ); }
    T *lastThat( CondFunc cond, void *args ) const
        { return lastThat( cond, args ); }
    void flush( TShouldDelete::DeleteType = TShouldDelete::DefDelete )
        { Flush(); }
#endif

protected:

    T *& ItemAt( int i ) const
        {
        return Data[ ZeroBase(i) ];
        }

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMArrayAsVector                  */
/*  template <class T,class Alloc> class TMArrayAsVectorIterator          */
/*                                                                        */
/*  Implements a managed array of objects of type T, using a vector as    */
/*  the underlying implementation.                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T, class Alloc> class TMArrayAsVectorIterator;

template <class T, class Alloc> class TMArrayAsVector :
    public TDArrayAsVectorImp<TMCVectorImp<T,Alloc>,T>
{

    friend TMArrayAsVectorIterator<T,Alloc>;

public:

    TMArrayAsVector( int upper, int lower = 0, int delta = 0 ) :
        TDArrayAsVectorImp<TMCVectorImp<T,Alloc>,T>( upper, lower, delta )
        {
        }

    int AddAt( const T& t, int loc )
        {
        return Data.AddAt( t, ZeroBase(loc) );
        }

#if defined( BI_OLDNAMES )
    int addAt( const T& t, int loc ) { return AddAt(t,loc); }
#endif

};

template <class T, class Alloc> class TMArrayAsVectorIterator :
    public TMCVectorIteratorImp<T,Alloc>
{

public:

    TMArrayAsVectorIterator( const TMArrayAsVector<T,Alloc>& a ) :
        TMCVectorIteratorImp<T,Alloc>( a.Data ) {}

};

#if defined( BI_OLDNAMES )
#define BI_MArrayAsVector TMArrayAsVector
#define BI_MArrayAsVectorIterator TMArrayAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TArrayAsVector                               */
/*  template <class T> class TArrayAsVectorIterator                       */
/*                                                                        */
/*  Implements an array of objects of type T, using a vector as the       */
/*  underlying implementation and TStandardAllocator as its memory        */
/*  manager.                                                              */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TArrayAsVector :
    public TMArrayAsVector<T,TStandardAllocator>
{

public:

    TArrayAsVector( int upper, int lower = 0, int delta = 0 ) :
        TMArrayAsVector<T,TStandardAllocator>( upper, lower, delta )
        {
        }

};

template <class T> class TArrayAsVectorIterator :
    public TMArrayAsVectorIterator<T,TStandardAllocator>
{

public:

    TArrayAsVectorIterator( const TArrayAsVector<T>& a ) :
        TMArrayAsVectorIterator<T,TStandardAllocator>(a)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_ArrayAsVector TArrayAsVector
#define BI_ArrayAsVectorIterator TArrayAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMSArrayAsVector                 */
/*  template <class T,class Alloc> class TMSArrayAsVectorIterator         */
/*                                                                        */
/*  Implements a managed, sorted array of objects of type T, using a      */
/*  vector as the underlying implementation.                              */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T, class Alloc> class TMSArrayAsVectorIterator;

template <class T, class Alloc> class TMSArrayAsVector :
    public TDArrayAsVectorImp<TMSVectorImp<T,Alloc>,T>
{

    friend TMSArrayAsVectorIterator<T,Alloc>;

public:

    TMSArrayAsVector( int upper, int lower = 0, int delta = 0 ) :
        TDArrayAsVectorImp<TMSVectorImp<T,Alloc>,T>( upper, lower, delta )
        {
        }

};

template <class T, class Alloc> class TMSArrayAsVectorIterator :
    public TMSVectorIteratorImp<T,Alloc>
{

public:

    TMSArrayAsVectorIterator( const TMSArrayAsVector<T,Alloc>& a ) :
        TMSVectorIteratorImp<T,Alloc>( a.Data ) {}

};

#if defined( BI_OLDNAMES )
#define BI_MSArrayAsVector TMSArrayAsVector
#define BI_MSArrayAsVectorIterator TMSArrayAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TSArrayAsVector                              */
/*  template <class T> class TSArrayAsVectorIterator                      */
/*                                                                        */
/*  Implements a sorted array of objects of type T, using a vector as     */
/*  the underlying implementation and TStandardAllocator as its memory    */
/*  manager.                                                              */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TSArrayAsVector :
    public TMSArrayAsVector<T,TStandardAllocator>
{

public:

    TSArrayAsVector( int upper, int lower = 0, int delta = 0 ) :
        TMSArrayAsVector<T,TStandardAllocator>( upper, lower, delta )
        {
        }

};

template <class T> class TSArrayAsVectorIterator :
    public TMSArrayAsVectorIterator<T,TStandardAllocator>
{

public:

    TSArrayAsVectorIterator( const TSArrayAsVector<T>& a ) :
        TMSArrayAsVectorIterator<T,TStandardAllocator>( a ) {}

};

#if defined( BI_OLDNAMES )
#define BI_SArrayAsVector TSArrayAsVector
#define BI_SArrayAsVectorIterator TSArrayAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMIArrayAsVector                 */
/*  template <class T,class Alloc> class TMIArrayAsVectorIterator         */
/*                                                                        */
/*  Implements a managed indirect array of objects of type T, using a     */
/*  vector as the underlying implementation.                              */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T, class Alloc> class TMIArrayAsVectorIterator;

template <class T, class Alloc> class TMIArrayAsVector :
    public TIArrayAsVectorImp<TMICVectorImp<T,Alloc>,T>
{

    friend TMIArrayAsVectorIterator<T,Alloc>;

public:

    TMIArrayAsVector( int upper, int lower = 0, int delta = 0 ) :
        TIArrayAsVectorImp<TMICVectorImp<T,Alloc>,T>( upper, lower, delta )
        {
        }

    int AddAt( T *t, int loc )
        {
        return Data.AddAt( t, ZeroBase(loc) );
        }

#if defined( BI_OLDNAMES )
    int addAt( T *t, int loc ) { return AddAt(t,loc); }
#endif

};

template <class T, class Alloc> class TMIArrayAsVectorIterator :
    public TMICVectorIteratorImp<T,Alloc>
{

public:

    TMIArrayAsVectorIterator( const TMIArrayAsVector<T,Alloc>& a ) :
        TMICVectorIteratorImp<T,Alloc>( a.Data ) {}

};

#if defined( BI_OLDNAMES )
#define BI_MIArrayAsVector TMIArrayAsVector
#define BI_MIArrayAsVectorIterator TMIArrayAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TIArrayAsVector                              */
/*  template <class T> class TIArrayAsVectorIterator                      */
/*                                                                        */
/*  Implements an indirect array of objects of type T, using a vector as  */
/*  the underlying implementation and TStandardAllocator as its memory    */
/*  manager.                                                              */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TIArrayAsVector :
    public TMIArrayAsVector<T,TStandardAllocator>
{

public:

    TIArrayAsVector( int upper, int lower = 0, int delta = 0 ) :
        TMIArrayAsVector<T,TStandardAllocator>( upper, lower, delta )
        {
        }

};

template <class T> class TIArrayAsVectorIterator :
    public TMIArrayAsVectorIterator<T,TStandardAllocator>
{

public:

    TIArrayAsVectorIterator( const TIArrayAsVector<T>& a ) :
        TMIArrayAsVectorIterator<T,TStandardAllocator>(a)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_IArrayAsVector TIArrayAsVector
#define BI_IArrayAsVectorIterator TIArrayAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMISArrayAsVector                */
/*  template <class T,class Alloc> class TMISArrayAsVectorIterator        */
/*                                                                        */
/*  Implements a managed, indirect sorted array of objects of type T,     */
/*  using a vector as the underlying implementation.                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T, class Alloc> class TMISArrayAsVectorIterator;

template <class T, class Alloc> class TMISArrayAsVector :
    public TIArrayAsVectorImp<TMISVectorImp<T,Alloc>,T>
{

    friend TMISArrayAsVectorIterator<T,Alloc>;

public:

    TMISArrayAsVector( int upper, int lower = 0, int delta = 0 ) :
        TIArrayAsVectorImp<TMISVectorImp<T,Alloc>,T>( upper, lower, delta )
        {
        }

};

template <class T, class Alloc> class TMISArrayAsVectorIterator :
    public TMISVectorIteratorImp<T,Alloc>
{

public:

    TMISArrayAsVectorIterator( const TMISArrayAsVector<T,Alloc>& a ) :
        TMISVectorIteratorImp<T,Alloc>( a.Data ) {}

};

#if defined( BI_OLDNAMES )
#define BI_MISArrayAsVector TMISArrayAsVector
#define BI_MIArrayAsVectorIterator TMIArrayAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TISArrayAsVector                             */
/*  template <class T> class TISArrayAsVectorIterator                     */
/*                                                                        */
/*  Implements an indirect sorted array of objects of type T, using a     */
/*  vector as the underlying implementation and TStandardAllocator as its */
/*  memory manager.                                                       */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TISArrayAsVector :
    public TMISArrayAsVector<T,TStandardAllocator>
{

public:

    TISArrayAsVector( int upper, int lower = 0, int delta = 0 ) :
        TMISArrayAsVector<T,TStandardAllocator>( upper, lower, delta )
        {
        }

};

template <class T> class TISArrayAsVectorIterator :
    public TMISArrayAsVectorIterator<T,TStandardAllocator>
{

public:

    TISArrayAsVectorIterator( const TISArrayAsVector<T>& a ) :
        TMISArrayAsVectorIterator<T,TStandardAllocator>(a)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_ISArrayAsVector TISArrayAsVector
#define BI_ISArrayAsVectorIterator TISArrayAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TArray                                       */
/*  template <class T> class TArrayIterator                               */
/*                                                                        */
/*  Easy names for TArrayAsVector and TArrayAsVectorIterator              */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TArray :
    public TArrayAsVector<T>
{

public:

    TArray( int upper, int lower = 0, int delta = 0 ) :
        TArrayAsVector<T>( upper, lower, delta )
        {
        }

};

template <class T> class TArrayIterator :
    public TArrayAsVectorIterator<T>
{

public:


    TArrayIterator( const TArray<T>& a ) :
        TArrayAsVectorIterator<T>(a)
        {
        }

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TSArray                                      */
/*  template <class T> class TSArrayIterator                              */
/*                                                                        */
/*  Easy names for TSArrayAsVector and TSArrayAsVectorIterator            */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TSArray :
    public TSArrayAsVector<T>
{

public:

    TSArray( int upper, int lower = 0, int delta = 0 ) :
        TSArrayAsVector<T>( upper, lower, delta )
        {
        }

};

template <class T> class TSArrayIterator :
    public TSArrayAsVectorIterator<T>
{

public:


    TSArrayIterator( const TSArray<T>& a ) :
        TSArrayAsVectorIterator<T>(a)
        {
        }

};

#if defined(BI_NAMESPACE)
}   // namespace ClassLib
#endif

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#pragma option -Vo.

#endif  // CLASSLIB_ARRAYS_H
