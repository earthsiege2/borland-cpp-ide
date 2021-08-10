/*------------------------------------------------------------------------*/
/*                                                                        */
/*  VECTIMP.H                                                             */
/*                                                                        */
/*  Copyright (c) 1991, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( CLASSLIB_VECTIMP_H )
#define CLASSLIB_VECTIMP_H

#if !defined( __LIMITS_H )
#include <limits.h>
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

#if !defined( CLASSLIB_MEMMGR_H )
#include <classlib/memmgr.h>
#endif

#if !defined( CLASSLIB_VOIDP_H )
#include <classlib/voidp.h>
#endif

#pragma option -Vo-
#if defined( BI_CLASSLIB_NO_po )
#pragma option -po-
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T, class Alloc> class TVectorImpBase                  */
/*                                                                        */
/*  Implements the base functionality for a managed vector of objects of  */
/*  type T.  Assumes that T has meaningful copy semantics and a default   */
/*  constructor.                                                          */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T, class Alloc> class TVectorImpBase :
    public Alloc
{

public:

    TVectorImpBase() : Data(0), Lim(0) {}

    TVectorImpBase( unsigned sz, unsigned d ) :
        Data( new(*this)T[sz] ),
        Lim(sz)
        {
        }

    TVectorImpBase( const TVectorImpBase<T,Alloc>& );

    const TVectorImpBase<T,Alloc>& operator = (
                const TVectorImpBase<T,Alloc>& );

    ~TVectorImpBase()
        {
        delete [] Data;
        }

    unsigned Limit() const
        {
        return Lim;
        }

    virtual unsigned Top() const
        {
        return Lim;
        }

    virtual unsigned Count() const
        {
        return Lim;
        }

    int Resize( unsigned, unsigned = 0 );

    virtual unsigned GetDelta() const
        {
        return 0;
        }

#if defined( BI_OLDNAMES )
    unsigned limit() const { return Limit(); }
    int resize( unsigned sz, unsigned off = 0 ) { return Resize(sz,off); }
#endif

protected:

    T * Data;
    unsigned Lim;

    virtual void Zero( unsigned, unsigned )
        {
        }

};

template <class T, class Alloc>
TVectorImpBase<T,Alloc>::TVectorImpBase(
        const TVectorImpBase<T,Alloc>& v ) :
    Data( new(*this)T[v.Lim] ),
    Lim(v.Lim)
{
    PRECONDITION( Lim == 0 || (Data != 0 && v.Data != 0) );
    for( unsigned i = 0; i < Lim; i++ )
        Data[i] = v.Data[i];
}

template <class T, class Alloc>
const TVectorImpBase<T,Alloc>& TVectorImpBase<T,Alloc>::operator = ( const TVectorImpBase<T,Alloc>& v )
{
    if( Data != v.Data )
        {
        delete [] Data;
        Data = new(*this)T[v.Lim];
        CHECK( Data != 0 );
        Lim = v.Lim;
        for( unsigned i = 0; i < Lim; i++ )
            Data[i] = v.Data[i];
        }
    return *this;
}

inline unsigned NextDelta( unsigned sz, unsigned delta )
{
    return (sz%delta) ? ((sz+delta)/delta)*delta : sz;
}

template <class T, class Alloc>
int TVectorImpBase<T,Alloc>::Resize( unsigned newSz, unsigned offset )
{
    if( newSz <= Lim || GetDelta() == 0 )
        return 0;
    unsigned sz = Lim + NextDelta( newSz - Lim, GetDelta() );
    T *temp = new(*this)T[sz];
    unsigned last = min( sz-offset, Lim );
    for( unsigned i = 0; i < last; i++ )
        temp[i+offset] = Data[i];
    delete [] Data;
    Data = temp;
    Lim = sz;
    Zero( last+offset, sz );
    return 1;
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T, class Alloc> class TMVectorImp                     */
/*                                                                        */
/*  Implements a managed vector of objects of type T.  Assumes that       */
/*  T has meaningful copy semantics and a default constructor.            */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMVectorIteratorImp;

template <class T,class Alloc> class TMVectorImp :
    public TVectorImpBase<T,Alloc>
{

public:

    typedef void (*IterFunc)(T&, void *);
    typedef int  (*CondFunc)(const T&, void *);

    friend TMVectorIteratorImp<T,Alloc>;

    TMVectorImp() : TVectorImpBase<T,Alloc>() {}
    TMVectorImp( unsigned sz, unsigned d = 0 ) : TVectorImpBase<T,Alloc>(sz,d) {}

    T& operator [] ( unsigned index )
        {
        PRECONDITION( Lim == 0 || Data != 0 && index < Lim );
        return Data[index];
        }

    T& operator [] ( unsigned index ) const
        {
        PRECONDITION( Lim > 0 && Data != 0 && index < Lim );
        return Data[index];
        }

    void Flush( unsigned = UINT_MAX, unsigned = 0 ) {}

    void ForEach( IterFunc iter, void *args )
        {
        ForEach( iter, args, 0, Count() );
        }

    void ForEach( IterFunc iter, void *args,
                  unsigned start, unsigned stop );

    T *FirstThat( CondFunc cond, void *args,
                           unsigned start, unsigned ) const;

    T *FirstThat( CondFunc cond, void *args ) const
        {
        return FirstThat( cond, args, 0, Count() );
        }

    T *LastThat( CondFunc cond, void *args,
                          unsigned start, unsigned stop ) const;

    T *LastThat( CondFunc cond, void *args ) const
        {
        return LastThat( cond, args, 0, Count() );
        }

#if defined( BI_OLDNAMES )
    void flush( unsigned = 0, unsigned = UINT_MAX, unsigned = 0 ) {}
    void forEach( IterFunc iter, void *args )
        { ForEach( iter, args ); }
    void forEach( IterFunc iter, void *args,
                  unsigned start, unsigned stop )
        { ForEach( iter, args, start, stop ); }
    T *firstThat( CondFunc cond, void *args,
                           unsigned start, unsigned stop ) const
        { return FirstThat( cond, args, start, stop ); }
    T *firstThat( CondFunc cond, void *args ) const
        { return FirstThat( cond, args ); }
    T *lastThat( CondFunc cond, void *args,
                          unsigned start, unsigned stop ) const
        { return LastThat( cond, args, start, stop ); }
    T *lastThat( CondFunc cond, void *args ) const
        { return LastThat( cond, args ); }
#endif  // BI_OLDNAMES

};

template <class T, class Alloc>
void TMVectorImp<T,Alloc>::ForEach( IterFunc iter, void *args,
                                    unsigned start, unsigned stop )
{
    for( unsigned cur = start; cur < stop; cur++ )
        iter( Data[cur], args );
}

template <class T, class Alloc>
T *TMVectorImp<T,Alloc>::FirstThat( CondFunc cond, void *args,
                                    unsigned start, unsigned stop ) const
{
    for( unsigned cur = start; cur < stop; cur++ )
        if( cond( Data[cur], args ) != 0 )
            return &(T&)Data[cur];
    return 0;
}

template <class T, class Alloc>
T *TMVectorImp<T,Alloc>::LastThat( CondFunc cond, void *args,
                                   unsigned start, unsigned stop ) const
{
    T *res = 0;
    for( unsigned cur = start; cur < stop; cur++ )
        if( cond( Data[cur], args ) != 0 )
            res = &(T&)Data[cur];
    return res;
}

#if defined( BI_OLDNAMES )
#define BI_MVectorImp TMVectorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T, class Alloc> class TMVectorIteratorImp             */
/*                                                                        */
/*  Implements a vector iterator.  This iterator works with any direct,   */
/*  managed vector.  For indirect vectors, see TMIVectorIteratorImp.      */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T, class Alloc> class TMVectorIteratorImp
{

public:

    TMVectorIteratorImp( const TMVectorImp<T,Alloc>&v )
        {
        Vect = &v;
        Restart(0,v.Top());
        }

    TMVectorIteratorImp( const TMVectorImp<T,Alloc>&v,
                         unsigned start,
                         unsigned stop
                         )
        {
        Vect = &v;
        Restart( start, stop );
        }

    operator int() const
        {
        return Cur < Upper;
        }

    const T& Current() const
        {
        PRECONDITION( Cur < Upper );
        return (*Vect)[Cur];
        }

    const T& operator ++ ( int )
        {
        const T& temp = Current();
        Cur++;
        return temp;
        }

    const T& operator ++ ()
        {
        PRECONDITION( Cur < Upper );
        Cur++;
        return Current();
        }

    void Restart()
        {
        Restart(Lower,Upper);
        }

    void Restart( unsigned start, unsigned stop )
        {
        Cur = Lower = start;
        Upper = stop;
        }

#if defined( BI_OLDNAMES )
    const T& current() { return Current(); }
    void restart() { Restart(); }
    void restart( unsigned start, unsigned stop ) { Restart( start, stop ); }
#endif  // BI_OLDNAMES

private:

    const TMVectorImp<T,Alloc> *Vect;
    unsigned Cur;
    unsigned Lower, Upper;

};

#if defined( BI_OLDNAMES )
#define BI_MVectorIteratorImp TMVectorIteratorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TVectorImp                                   */
/*  template <class T> class TVectorIteratorImp                           */
/*                                                                        */
/*  Implements a vector of objects of type T using TStandardAllocator as  */
/*  its memory manager. Assumes that T has meaningful copy semantics and  */
/*  a default constructor.                                                */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TVectorImp :
    public TMVectorImp<T,TStandardAllocator>
{

public:

    TVectorImp()
        {
        }

    TVectorImp( unsigned sz, unsigned = 0 ) :
        TMVectorImp<T,TStandardAllocator>( sz )
        {
        }

    TVectorImp( const TVectorImp<T>& v ) :
        TMVectorImp<T,TStandardAllocator>( v )
        {
        }

};

template <class T> class TVectorIteratorImp :
    public TMVectorIteratorImp<T,TStandardAllocator>
{

public:

    TVectorIteratorImp( const TVectorImp<T>& v ) :
        TMVectorIteratorImp<T,TStandardAllocator>(v)
        {
        }

    TVectorIteratorImp( const TVectorImp<T>& v,
                        unsigned start,
                        unsigned stop
                        ) :
        TMVectorIteratorImp<T,TStandardAllocator>(v,start,stop)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_VectorImp TVectorImp
#define BI_VectorIteratorImp TVectorIteratorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T, class Alloc> class TMCVectorImp                    */
/*  template <class T, class Alloc> class TMCVectorIteratorImp            */
/*                                                                        */
/*  Implements a managed, counted vector of objects of type T.  Assumes   */
/*  that T has meaningful copy semantics and a default constructor.       */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T, class Alloc> class TMCVectorImp :
    public TMVectorImp<T,Alloc>
{

public:

    TMCVectorImp() :
        Count_(0),
        Delta(0)
        {
        }

    TMCVectorImp( unsigned sz, unsigned d = 0 ) :
        TMVectorImp<T,Alloc>( sz ),
        Count_(0),
        Delta(d)
        {
        }

    int Add( const T& );
    int AddAt( const T&, unsigned );
    int Detach( const T& t )
        {
        return Detach( Find(t) );
        }

    int Detach( unsigned loc );

    int IsEmpty() const
        {
        return Count_ == 0;
        }

    void Flush( unsigned stop = UINT_MAX,
                unsigned start = 0 )
        {
        TMVectorImp<T,Alloc>::Flush( stop, start );
        Count_ = 0;
        }

    virtual unsigned Find( const T& ) const;

    virtual unsigned Top() const
        {
        return Count_;
        }

    virtual unsigned Count() const
        {
        return Count_;
        }

    virtual unsigned GetDelta() const
        {
        return Delta;
        }

#if defined( BI_OLDNAMES )
    void add( const T& t ) { Add(t); }
    void addAt( const T& t, unsigned loc ) { AddAt( t, loc ); }
    void detach( const T& t, int del = 0 ) { Detach( t ); }
    void detach( unsigned loc, int del = 0 ) { Detach( loc ); }
    int isEmpty() const { return IsEmpty(); }
    void flush( unsigned del = 0,
                unsigned stop = UINT_MAX,
                unsigned start = 0 )
        { Flush( stop, start ); }
    unsigned count() const { return Count(); }
#endif  // BI_OLDNAMES

protected:

    unsigned Count_;
    unsigned Delta;

};

template <class T,class Alloc> class TMCVectorIteratorImp :
    public TMVectorIteratorImp<T,Alloc>
{

public:

    TMCVectorIteratorImp( const TMCVectorImp<T,Alloc>& v ) :
        TMVectorIteratorImp<T,Alloc>(v)
        {
        }

    TMCVectorIteratorImp( const TMCVectorImp<T,Alloc>& v,
                          unsigned start,
                          unsigned stop
                        ) :
        TMVectorIteratorImp<T,Alloc>(v,start,stop)
        {
        }

};

template <class T, class Alloc> int TMCVectorImp<T,Alloc>::Add( const T& t )
{
    if( Count_ >= Lim && !Resize( Count_+1 ) )
        return 0;
    Data[Count_++] = t;
    return 1;
}

template <class T, class Alloc> 
int TMCVectorImp<T,Alloc>::AddAt( const T& t, unsigned loc )
{
    if( loc >= Lim && !Resize(loc+1) )
        return 0;
    if( Count_ == Lim && !Resize(Lim+1) )
        return 0;
    if( loc > Count_ )
        Count_ = loc;
    for( unsigned cur = Count_; cur > loc; cur-- )
        Data[cur] = Data[cur-1];
    Data[loc] = t;
    Count_++;
    return 1;
}

template <class T, class Alloc>
int TMCVectorImp<T,Alloc>::Detach( unsigned loc )
{
    if( loc >= Lim )
        return 0;
    if( loc >= Count_ )
        {
        Zero( loc, loc+1 ); // removing an element that's not
        return 1;           // in the counted portion
        }
    Count_--;
    for( unsigned cur = loc; cur < Count_; cur++ )
        Data[cur] = Data[cur+1];
    return 1;
}

template <class T, class Alloc>
unsigned TMCVectorImp<T,Alloc>::Find( const T& t ) const
{
    for( unsigned loc = 0; loc < Count_; loc++ )
        if( Data[loc] == t )
            return loc;
    return UINT_MAX;
}

#if defined( BI_OLDNAMES )
#define BI_MCVectorImp TMCVectorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TCVectorImp                                  */
/*  template <class T> class TCVectorIteratorImp                          */
/*                                                                        */
/*  Implements a counted vector of objects of type T using                */
/*  TStandardAllocator as its memory manager.  Assumes                    */
/*  that T has meaningful copy semantics and a default constructor.       */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TCVectorImp :
    public TMCVectorImp<T,TStandardAllocator>
{

public:

    TCVectorImp()
        {
        }

    TCVectorImp( unsigned sz, unsigned d = 0 ) :
        TMCVectorImp<T,TStandardAllocator>( sz, d )
        {
        }

};

template <class T> class TCVectorIteratorImp :
    public TMCVectorIteratorImp<T,TStandardAllocator>
{

public:

    TCVectorIteratorImp( const TCVectorImp<T>& v ) :
        TMCVectorIteratorImp<T,TStandardAllocator>(v)
        {
        }

    TCVectorIteratorImp( const TCVectorImp<T>& v,
                         unsigned start,
                         unsigned stop
                        ) :
        TMCVectorIteratorImp<T,TStandardAllocator>(v,start,stop)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_CVectorImp TCVectorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T, class Alloc> class TMSVectorImp                    */
/*  template <class T, class Alloc> class TMSVectorIteratorImp            */
/*                                                                        */
/*  Implements a managed, sorted vector of objects of type T.  Assumes    */
/*  that T has meaningful copy semantics, a meaningful < operator,        */
/*  and a default constructor.                                            */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T, class Alloc> class TMSVectorImp :
    public TMCVectorImp<T,Alloc>
{

public:

    TMSVectorImp()
        {
        }

    TMSVectorImp( unsigned sz, unsigned d = 0 ) :
        TMCVectorImp<T,Alloc>( sz, d )
        {
        }

    int Add( const T& );

    virtual unsigned Find( const T& ) const;

};

template <class T,class Alloc> class TMSVectorIteratorImp :
    public TMCVectorIteratorImp<T,Alloc>
{

public:

    TMSVectorIteratorImp( const TMSVectorImp<T,Alloc>& v ) :
        TMCVectorIteratorImp<T,Alloc>(v)
        {
        }

    TMSVectorIteratorImp( const TMSVectorImp<T,Alloc>& v,
                          unsigned start,
                          unsigned stop
                        ) :
        TMCVectorIteratorImp<T,Alloc>(v,start,stop)
        {
        }

};

template <class T, class Alloc> int TMSVectorImp<T,Alloc>::Add( const T& t )
{
    unsigned loc = Count_++;
    if( Count_ > Lim )
        if( !Resize( Count_ ) )
            {
            --Count_;
            return 0;
            }
    while( loc > 0 && t < Data[loc-1] )
        {
        Data[loc] = Data[loc-1];
        loc--;
        }
    Data[loc] = t;
    return 1;
}

template <class T, class Alloc>
unsigned TMSVectorImp<T,Alloc>::Find( const T& t ) const
{
    if( Count_ == 0 )
        return UINT_MAX;

    unsigned lower = 0;
    unsigned upper = Count_-1;

    while( lower < upper && upper != UINT_MAX )
        {
        unsigned middle = (lower+upper)/2;
        if( (T&)Data[middle] == (T&)t )
            return middle;
        if( (T&)Data[middle] < (T&)t )
            lower = middle+1;
        else
            upper = middle-1;
        }

    if( lower == upper && (T&)Data[lower] == (T&)t )
        return lower;
    else
        return UINT_MAX;
}

#if defined( BI_OLDNAMES )
#define BI_MSVectorImp TMSVectorImp
#define BI_MSVectorIteratorImp TMSVectorIteratorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TSVectorImp                                  */
/*  template <class T> class TSVectorIteratorImp                          */
/*                                                                        */
/*  Implements a sorted vector of objects of type T using                 */
/*  TStandardAllocator as its memory manager.  Assumes                    */
/*  that T has meaningful copy semantics, a meaningful < operator,        */
/*  and a default constructor.                                            */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TSVectorImp :
    public TMSVectorImp<T,TStandardAllocator>
{

public:

    TSVectorImp()
        {
        }

    TSVectorImp( unsigned sz, unsigned d = 0 ) :
        TMSVectorImp<T,TStandardAllocator>( sz, d )
        {
        }

};

template <class T> class TSVectorIteratorImp :
    public TMSVectorIteratorImp<T,TStandardAllocator>
{

public:

    TSVectorIteratorImp( const TSVectorImp<T>& v ) :
        TMSVectorIteratorImp<T,TStandardAllocator>(v)
        {
        }

    TSVectorIteratorImp( const TSVectorImp<T>& v,
                         unsigned start,
                         unsigned stop
                        ) :
        TMSVectorIteratorImp<T,TStandardAllocator>(v,start,stop)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_SVectorImp TSVectorImp
#define BI_SVectorIteratorImp TSVectorIteratorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMIVectorImp                     */
/*                                                                        */
/*  Implements a managed vector of pointers to objects of type T.         */
/*  Since pointers always have meaningful copy semantics, this class      */
/*  can handle any type of object.                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMIVectorImp :
    public TVectorImpBase<TVoidPointer,Alloc>
{

public:

    typedef void (*IterFunc)(T&, void *);
    typedef int  (*CondFunc)(const T&, void *);

    TMIVectorImp( unsigned sz, unsigned d = 0 ) :
        TVectorImpBase<TVoidPointer,Alloc>(sz,d) {}

    T *& operator [] ( unsigned index )
        {
        PRECONDITION( Lim == 0 || Data != 0 && index < Lim );
        return *STATIC_CAST(T **,STATIC_CAST(void *,&Data[index]));
        }

    T *& operator [] ( unsigned index ) const
        {
        PRECONDITION( Lim > 0 && Data != 0 && index < Lim );
        return *STATIC_CAST(T **,STATIC_CAST(void *,&Data[index]));
        }

    void Flush( unsigned del = 0,
                unsigned stop = UINT_MAX,
                unsigned start = 0 );

    void ForEach( IterFunc iter, void *args )
        {
        ForEach( iter, args, 0, Count() );
        }

    void ForEach( IterFunc iter, void *args,
                  unsigned start, unsigned stop );

    T *FirstThat( CondFunc cond, void *args ) const
        {
        return FirstThat( cond, args, 0, Count() );
        }

    T *FirstThat( CondFunc cond, void *args,
                           unsigned start, unsigned stop ) const;

    T *LastThat( CondFunc cond, void *args ) const
        {
        return LastThat( cond, args, 0, Count() );
        }

    T *LastThat( CondFunc cond, void *args,
                          unsigned start, unsigned stop ) const;

#if defined( BI_OLDNAMES )
    void flush( unsigned del = 0, unsigned upr = UINT_MAX, unsigned lwr = 0 )
        { Flush( del, upr, lwr ); }
    void forEach( IterFunc iter, void *args )
        { ForEach( iter, args ); }
    void forEach( IterFunc cond, void *args,
                  unsigned start, unsigned stop)
        { ForEach( cond, args, start, stop ); }
    T *firstThat( CondFunc cond, void *args ) const
        { return FirstThat( cond, args ); }
    T *firstThat( CondFunc cond, void *args,
                           unsigned start, unsigned stop ) const
        { return FirstThat( cond, args, start, stop ); }
    T *lastThat( CondFunc cond, void *args ) const
        { return LastThat( cond, args ); }
    T *lastThat( CondFunc cond, void *args,
                          unsigned start, unsigned stop ) const
        { return LastThat( cond, args, start, stop ); }
#endif  // BI_OLDNAMES

protected:

    void Zero( unsigned, unsigned );

private:

    static void DelObj( T&, void * );

};

template <class T, class Alloc>
void TMIVectorImp<T,Alloc>::DelObj( T& tRef, void * )
{
    delete &tRef;
}

template <class T, class Alloc>
void TMIVectorImp<T,Alloc>::Flush( unsigned del,
                                   unsigned upr,
                                   unsigned lwr )
{
    upr = min( upr, Limit() );
    if( del )
        ForEach( DelObj, 0, lwr, upr );
    Zero( lwr, upr );
}

template <class T, class Alloc>
void TMIVectorImp<T,Alloc>::ForEach( IterFunc iter, void *args,
                                    unsigned start, unsigned stop )
{
    for( unsigned cur = start; cur < stop; cur++ )
        if( Data[cur] != 0 )
            iter( *STATIC_CAST(T *,STATIC_CAST(void *,Data[cur])), args );
}

template <class T, class Alloc>
T *TMIVectorImp<T,Alloc>::FirstThat( CondFunc cond,
                                     void *args,
                                     unsigned start,
                                     unsigned stop ) const
{
    for( unsigned cur = start; cur < stop; cur++ )
        if( Data[cur] != 0 &&
            cond( *STATIC_CAST(T *,STATIC_CAST(void *,Data[cur])), args ) != 0 )
            return STATIC_CAST(T *,STATIC_CAST(void *,Data[cur]));
    return 0;
}

template <class T, class Alloc>
T *TMIVectorImp<T,Alloc>::LastThat( CondFunc cond,
                                    void *args,
                                    unsigned start,
                                    unsigned stop ) const
{
    T *res = 0;
    for( unsigned cur = start; cur < stop; cur++ )
        if( Data[cur] != 0 &&
            cond( *STATIC_CAST(T *,STATIC_CAST(void *,Data[cur])), args ) != 0 )
            res = STATIC_CAST(T *,STATIC_CAST(void *,Data[cur]));
    return res;
}

template <class T, class Alloc>
void TMIVectorImp<T,Alloc>::Zero( unsigned lwr, unsigned upr )
{
    for( unsigned i = lwr; i < min( Limit(), upr ); i++ )
        Data[i] = 0;
}

#if defined( BI_OLDNAMES )
#define BI_MIVectorImp TMIVectorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMIVectorIteratorImp             */
/*                                                                        */
/*  Implements an iterator for a managed indirect vector of pointers to   */
/*  objects of type T.                                                    */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T, class Alloc> class TMIVectorIteratorImp
{

public:

    TMIVectorIteratorImp( const TMIVectorImp<T,Alloc>& v )
        {
        Vect = &v;
        Restart(0,v.Top());
        }

    TMIVectorIteratorImp( const TMIVectorImp<T,Alloc>& v,
                          unsigned start,
                          unsigned stop )
        {
        Vect = &v;
        Restart( start, stop );
        }

    operator int() const
        {
        return Cur < Upper;
        }

    T *Current() const
        {
        PRECONDITION( Cur < Upper );
        return STATIC_CAST(T *,STATIC_CAST(void *,(*Vect)[Cur]));
        }

    T *operator ++ ( int )
        {
        T *temp = Current();
        Cur++;
        return temp;
        }

    T *operator ++ ()
        {
        PRECONDITION( Cur < Upper );
        Cur++;
        return Current();
        }

    void Restart()
        {
        Restart(Lower,Upper);
        }

    void Restart( unsigned start, unsigned stop )
        {
        Cur = Lower = start;
        Upper = stop;
        }

#if defined( BI_OLDNAMES )
    const T *current() { return Current(); }
    void restart() { Restart(); }
    void restart( unsigned start, unsigned stop ) { Restart( start, stop ); }
#endif  // BI_OLDNAMES

private:

    const TMIVectorImp<T,Alloc> *Vect;
    unsigned Cur;
    unsigned Lower, Upper;

};

#if defined( BI_OLDNAMES )
#define BI_MIVectorIteratorImp TMIVectorIteratorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TIVectorImp                                  */
/*  template <class T> class TIVectorIteratorImp                          */
/*                                                                        */
/*  Implements a vector of pointers to objects of type T using            */
/*  TStandardAllocator as its memory manager.                             */
/*  Since pointers always have meaningful copy semantics, this class      */
/*  can handle any type of object.                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TIVectorImp :
    public TMIVectorImp<T,TStandardAllocator>
{

public:

    TIVectorImp( unsigned sz, unsigned d = 0 ) :
        TMIVectorImp<T,TStandardAllocator>(sz,d)
        {
        }

};

template <class T> class TIVectorIteratorImp :
    public TMIVectorIteratorImp<T,TStandardAllocator>
{

public:

    TIVectorIteratorImp( const TIVectorImp<T>& v ) :
        TMIVectorIteratorImp<T,TStandardAllocator>(v)
        {
        }

    TIVectorIteratorImp( const TIVectorImp<T>& v,
                         unsigned l, unsigned u ) :
        TMIVectorIteratorImp<T,TStandardAllocator>(v,l,u)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_IVectorImp TIVectorImp
#define BI_IVectorIteratorImp TIVectorIteratorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMICVectorImp                    */
/*  template <class T,class Alloc> class TMICVectorIteratorImp            */
/*                                                                        */
/*  Implements a managed, counted vector of pointers to objects of type T.*/
/*  Since pointers always have meaningful copy semantics, this class      */
/*  can handle any type of object.                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMICVectorImp :
    public TMIVectorImp<T,Alloc>
{

public:

    TMICVectorImp( unsigned sz, unsigned d = 0 ) :
        TMIVectorImp<T,Alloc>(sz), Delta(d), Count_(0) {}

    int Add( T *t );
    int AddAt( T *, unsigned );
    int Detach( const T *t, int del = 0 )
        {
        return Detach( Find(t), del );
        }

    int Detach( unsigned loc, int del = 0 );

    int IsEmpty() const
        {
        return Count_ == 0;
        }

    void Flush( int del = 0,
                unsigned stop = UINT_MAX,
                unsigned start = 0 )
        {
        TMIVectorImp<T,Alloc>::Flush( del, stop, start );
        Count_ = 0;
        }

    unsigned Find( const T *t ) const;

    virtual unsigned Top() const
        {
        return Count_;
        }

    virtual unsigned Count() const
        {
        return Count_;
        }

    virtual unsigned GetDelta() const
        {
        return Delta;
        }

#if defined( BI_OLDNAMES )
    unsigned find( T *t ) const { return Find(t); }
    void add( T *t ) { Add(t); }
#endif  // BI_OLDNAMES

protected:

    unsigned Count_;
    unsigned Delta;

};

template <class T,class Alloc> class TMICVectorIteratorImp :
    public TMIVectorIteratorImp<T,Alloc>
{

public:

    TMICVectorIteratorImp( const TMICVectorImp<T,Alloc>& v ) :
        TMIVectorIteratorImp<T,Alloc>(v)
        {
        }

    TMICVectorIteratorImp( const TMICVectorImp<T,Alloc>& v,
                           unsigned start,
                           unsigned stop ) :
        TMIVectorIteratorImp<T,Alloc>(v,start,stop)
        {
        }

};

template <class T, class Alloc> 
int TMICVectorImp<T,Alloc>::AddAt( T *t, unsigned loc )
{
    if( loc >= Lim && !Resize(loc+1) )
        return 0;
    if( Count_ == Lim && !Resize(Lim+1) )
        return 0;
    if( loc > Count_ )
        Count_ = loc;
    for( unsigned cur = Count_; cur > loc; cur-- )
        Data[cur] = Data[cur-1];
    Data[loc] = t;
    Count_++;
    return 1;
}

template <class T, class Alloc>
int TMICVectorImp<T,Alloc>::Detach( unsigned loc, int del )
{
    if( loc >= Lim )
        return 0;
    if( del )
        delete STATIC_CAST(T *,STATIC_CAST(void *,Data[loc]));
    if( loc >= Count_ )
        {
        Zero( loc, loc+1 ); // removing an element that's not
        return 1;           // in the counted portion
        }
    Count_--;
    for( unsigned cur = loc; cur < Count_; cur++ )
        Data[cur] = Data[cur+1];
    Zero( Count_, Count_+1 );
    return 1;
}

template <class T,class Alloc>
unsigned TMICVectorImp<T,Alloc>::Find( const T *t ) const
{
    if( Top() != 0 )
        {
        for( unsigned loc = 0; loc < Top(); loc++ )
            if( Data[loc] &&
              *STATIC_CAST(T *,STATIC_CAST(void *,Data[loc])) == *t )
                return loc;
        }
    return UINT_MAX;
}

template <class T,class Alloc> int TMICVectorImp<T,Alloc>::Add( T *t )
{
    while( Count_ < Limit() && (*this)[Count_] != 0 )
        Count_++;
    if( Count_ >= Lim && !Resize( Count_+1 ) )
        return 0;
    Data[Count_++] = t;
    return 1;
}

#if defined( BI_OLDNAMES )
#define BI_MICVectorImp TMICVectorImp
#define BI_MICVectorIteratorImp TMICVectorIteratorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TICVectorImp                                 */
/*  template <class T> class TICVectorIteratorImp                         */
/*                                                                        */
/*  Implements a counted vector of pointers to objects of type T using    */
/*  TStandardAllocator as its memory manager.                             */
/*  Since pointers always have meaningful copy semantics, this class      */
/*  can handle any type of object.                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TICVectorImp :
    public TMICVectorImp<T,TStandardAllocator>
{

public:

    TICVectorImp( unsigned sz, unsigned d = 0 ) :
        TMICVectorImp<T,TStandardAllocator>( sz, d )
        {
        }

};

template <class T> class TICVectorIteratorImp :
    public TMICVectorIteratorImp<T,TStandardAllocator>
{

public:

    TICVectorIteratorImp( const TICVectorImp<T>& v ) :
        TMICVectorIteratorImp<T,TStandardAllocator>(v)
        {
        }

    TICVectorIteratorImp( const TICVectorImp<T>& v,
                          unsigned l, unsigned u ) :
        TMICVectorIteratorImp<T,TStandardAllocator>(v,l,u)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_ICVectorImp TICVectorImp
#define BI_ICVectorVectorImp TICVectorIteratorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMISVectorImp                    */
/*  template <class T,class Alloc> class TMISVectorIteratorImp            */
/*                                                                        */
/*  Implements a managed, sorted vector of pointers to objects of type T. */
/*  This is implemented through the template TInternalIVectorImp.         */
/*  Since pointers always have meaningful copy semantics, this class      */
/*  can handle any type of object.                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMISVectorImp :
    public TMICVectorImp<T,Alloc>
{

public:

    TMISVectorImp( unsigned sz, unsigned d = 0 ) :
        TMICVectorImp<T,Alloc>(sz)
        {
        Delta = d;
        }

    unsigned Find( const T *t ) const;
    int Add( T *t );

#if defined( BI_OLDNAMES )
    unsigned find( T *t ) const { return Find(t); }
    void add( T *t ) { Add(t); }
#endif  // BI_OLDNAMES

};

template <class T,class Alloc> class TMISVectorIteratorImp :
    public TMICVectorIteratorImp<T,Alloc>
{

public:

    TMISVectorIteratorImp( const TMISVectorImp<T,Alloc>& v ) :
        TMICVectorIteratorImp<T,Alloc>(v)
        {
        }

    TMISVectorIteratorImp( const TMISVectorImp<T,Alloc>& v,
                           unsigned start,
                           unsigned stop ) :
        TMICVectorIteratorImp<T,Alloc>(v,start,stop)
        {
        }

};

template <class T,class Alloc>
unsigned TMISVectorImp<T,Alloc>::Find( const T *t ) const
{
    if( Count_ == 0 )
        return UINT_MAX;

    unsigned lower = 0;
    unsigned upper = Count_-1;

    while( lower < upper && upper != UINT_MAX )
        {
        unsigned middle = (lower+upper)/2;
        if( *STATIC_CAST(T *,STATIC_CAST(void *,Data[middle])) == *t )
            return middle;
        if( *STATIC_CAST(T *,STATIC_CAST(void *,Data[middle])) < *t )
            lower = middle+1;
        else
            upper = middle-1;
        }

    if( lower == upper &&
        *STATIC_CAST(T *,STATIC_CAST(void *,Data[lower])) == *t )
        return lower;
    else
        return UINT_MAX;
}

template <class T,class Alloc> int TMISVectorImp<T,Alloc>::Add( T *t )
{
    unsigned loc = Count_++;
    if( Count_ > Lim )
        if( !Resize( Count_ ) )
            {
            --Count_;
            return 0;
            }
    while( loc > 0 &&
           *t < *STATIC_CAST(T *,STATIC_CAST(void *,(*this)[loc-1])) )
        {
        Data[loc] = Data[loc-1];
        loc--;
        }
    Data[loc] = t;
    return 1;
}

#if defined( BI_OLDNAMES )
#define BI_MISVectorImp TMISVectorImp
#define BI_MISVectorVectorImp TMISVectorIteratorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TISVectorImp                                 */
/*  template <class T> class TISVectorIteratorImp                         */
/*                                                                        */
/*  Implements a sorted vector of pointers to objects of type T using     */
/*  TStandardAllocator as its memory manager.                             */
/*  This is implemented through the template TInternalIVectorImp.         */
/*  Since pointers always have meaningful copy semantics, this class      */
/*  can handle any type of object.                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TISVectorImp :
    public TMISVectorImp<T,TStandardAllocator>
{

public:

    TISVectorImp( unsigned sz, unsigned d = 0 ) :
        TMISVectorImp<T,TStandardAllocator>( sz, d )
        {
        }

};

template <class T> class TISVectorIteratorImp :
    public TMISVectorIteratorImp<T,TStandardAllocator>
{

public:

    TISVectorIteratorImp( const TISVectorImp<T>& v ) :
        TMISVectorIteratorImp<T,TStandardAllocator>(v)
        {
        }

    TISVectorIteratorImp( const TISVectorImp<T>& v,
                          unsigned l, unsigned u
                         ) :
        TMISVectorIteratorImp<T,TStandardAllocator>(v,l,u)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_ISVectorImp TISVectorImp
#define BI_ISVectorIteratorImp TISVectorIteratorImp
#endif

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#pragma option -Vo.

#endif  // CLASSLIB_VECTIMP_H

