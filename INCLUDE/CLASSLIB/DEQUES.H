//----------------------------------------------------------------------------
// Borland BIDS Container Library
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.4  $
//
//----------------------------------------------------------------------------
#if !defined( CLASSLIB_DEQUES_H )
#define CLASSLIB_DEQUES_H

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

#if !defined( CLASSLIB_DLISTIMP_H )
#include <classlib/dlistimp.h>
#endif

#pragma option -Vo-
#if defined( BI_CLASSLIB_NO_po )
#pragma option -po-
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class Vect, class T> class TDequeAsVectorImp                */
/*                                                                        */
/*  Implements the fundamental dequeue operations, using a vector         */
/*  as the underlying implementation.  The type Vect specifies the        */
/*  form of the vector, either a TVectorImp<T0> or a                      */
/*  TIVectorImp<T0>.  The type T specifies the type of the                */
/*  objects to be put in the dequeue.  When using TVectorImp<T0>,         */
/*  T should be the same as T0. When using TIVectorImp<T0>, T             */
/*  should be of type pointer to T0.  See TQueueAsVector and              */
/*  TIQueueAsVector for examples.                                         */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class Vect, class T> class TDequeAsVectorImp
{

public:

    TDequeAsVectorImp( unsigned max = DEFAULT_DEQUE_SIZE ) :
        Data(max+1),
        Left(0),
        Right(0)
        {
        }

    int IsFull() const
        {
        return Right == Prev( Left );
        }

    int IsEmpty() const
        {
        return Right == Left;
        }

    int GetItemsInContainer() const
        {
        return (Right>=Left) ? Right - Left : Data.Limit()-(Left-Right);
        }

#if defined( BI_OLDNAMES )
    int isFull() const { return IsFull(); }
    int isEmpty() const { return IsEmpty(); }
    int getItemsInContainer() const { return GetItemsInContainer(); }
#endif  // BI_OLDNAMES

protected:

    Vect Data;
    unsigned Left;
    unsigned Right;

    unsigned Prev( unsigned index ) const
        {
        if( index == 0 )
            index = Data.Limit();
        return --index;
        }

    unsigned Next( unsigned index ) const
        {
        index++;
        if( index == Data.Limit() )
            index = 0;
        return index;
        }

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMDequeAsVector                  */
/*                                                                        */
/*  Implements a managed dequeue of objects of type T, using a vector as  */
/*  the underlying implementation.                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T, class Alloc> class TMDequeAsVectorIterator;

template <class T,class Alloc> class TMDequeAsVector :
    public TDequeAsVectorImp<TMVectorImp<T,Alloc>,T>
{

    typedef TDequeAsVectorImp<TMVectorImp<T,Alloc>,T> Parent;

public:

    friend TMDequeAsVectorIterator<T,Alloc>;

    typedef void (*IterFunc)(T&, void *);
    typedef int  (*CondFunc)(const T&, void *);

    TMDequeAsVector( unsigned max = DEFAULT_DEQUE_SIZE ) :
        TDequeAsVectorImp<TMVectorImp<T,Alloc>,T>( max )
        {
        }

    const T& PeekLeft() const
        {
        PRECONDITION( !IsEmpty() );
        return Data[Left];
        }

    const T& PeekRight() const
        {
        PRECONDITION( !IsEmpty() );
        return Data[Prev(Right)];
        }

    T GetLeft();
    T GetRight();

    void PutLeft( const T& );
    void PutRight( const T& );

    void ForEach( IterFunc iter, void *args );

    T *FirstThat( CondFunc cond, void *args ) const;

    T *LastThat( CondFunc cond, void *args ) const;

    void Flush()
        {
        Left = Right = 0;
        }

#if defined( BI_OLDNAMES )
    const T& peekLeft() const { return PeekLeft(); }
    const T& peekRight() const { return PeekRight(); }
    T getLeft() { return GetLeft(); }
    T getRight() { return GetRight(); }
    void putLeft( const T& t ) { PutLeft(t); }
    void putRight( const T& t ) { PutRight(t); }
    void forEach( IterFunc iter, void *args )
        { ForEach( iter, args ); }
    T *firstThat( CondFunc cond, void *args ) const
        { return FirstThat( cond, args ); }
    T *lastThat( CondFunc cond, void *args ) const
        { return LastThat( cond, args ); }
    void flush( TShouldDelete::DeleteType = TShouldDelete::DefDelete )
        { Flush(); }
#endif  // BI_OLDNAMES

};

template <class T, class Alloc> T TMDequeAsVector<T,Alloc>::GetRight()
{
    PRECONDITION( !IsEmpty() );
    Right = Prev(Right);
    T t = Data[Right];
    Data[Right] = T();
    return t;
}

template <class T, class Alloc>
void TMDequeAsVector<T,Alloc>::PutRight( const T& t )
{
    PRECONDITION( !IsFull() );
    Data[Right] = t;
    Right = Next(Right);
}

template <class T, class Alloc> T TMDequeAsVector<T,Alloc>::GetLeft()
{
    PRECONDITION( !IsEmpty() );
    T t = Data[Left];
    Data[Left] = T();
    Left = Next(Left);
    return t;
}

template <class T, class Alloc>
void TMDequeAsVector<T,Alloc>::PutLeft( const T& t )
{
    PRECONDITION( !IsFull() );
    Left = Prev(Left);
    Data[Left] = t;
}

template <class T,class Alloc>
void TMDequeAsVector<T,Alloc>::ForEach( IterFunc iter, void *args )
{
    for( unsigned index = Left; index != Right; index=Next(index) )
        iter( Data[index], args );
}

template <class T,class Alloc>
T *TMDequeAsVector<T,Alloc>::FirstThat( CondFunc cond, void *args ) const
{
    for( unsigned index = Left; index != Right; index=Next(index) )
        if( cond( Data[index], args ) )
            return &Data[index];
    return 0;
}

template <class T,class Alloc>
T *TMDequeAsVector<T,Alloc>::LastThat( CondFunc cond, void *args ) const
{
    T *res = 0;
    for( unsigned index = Left; index != Right; index=Next(index) )
        if( cond( Data[index], args ) )
            res = &Data[index];
    return res;
}

#if defined( BI_OLDNAMES )
#define BI_MDequeAsVector TMDequeAsVector
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMDequeAsVectorIterator          */
/*                                                                        */
/*  Implements an iterator for the family of Deques as Vectors.           */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMDequeAsVectorIterator
{

public:

    TMDequeAsVectorIterator( const TMDequeAsVector<T,Alloc>& );

    operator int();
    const T& Current();
    const T& operator ++ ( int );
    const T& operator ++ ();
    void Restart();

#if defined( BI_OLDNAMES )
    const T& current() { return Current(); }
    void restart() { Restart(); }
#endif  // BI_OLDNAMES

private:

    unsigned Left;
    unsigned Right;
    const TMVectorImp<T,Alloc> *Vect;
    TMVectorIteratorImp<T,Alloc> Iter;
    int Second;

    void NextBlock();

};

template <class T,class Alloc>
TMDequeAsVectorIterator<T,Alloc>::TMDequeAsVectorIterator( const TMDequeAsVector<T,Alloc>& v ) :
    Iter( v.Data )
{
    Vect = &v.Data;
    Left = v.Left;
    Right = v.Right;
    Restart();
}

template <class T,class Alloc>
TMDequeAsVectorIterator<T,Alloc>::operator int()
{
    return int(Iter);
}

template <class T,class Alloc>
const T& TMDequeAsVectorIterator<T,Alloc>::Current()
{
    return Iter.Current();
}

template <class T,class Alloc>
const T& TMDequeAsVectorIterator<T,Alloc>::operator ++ ( int )
{
    const T& temp = Iter++;
    NextBlock();
    return temp;
}

template <class T,class Alloc>
const T& TMDequeAsVectorIterator<T,Alloc>::operator ++ ()
{
    Iter++;
    NextBlock();
    return Current();
}

template <class T,class Alloc>
void TMDequeAsVectorIterator<T,Alloc>::Restart()
{
    if( Left <= Right )
        Iter.Restart( Left, Right );
    else
        Iter.Restart( Left, Vect->Limit() );
    Second = 0;
}

template <class T,class Alloc>
void TMDequeAsVectorIterator<T,Alloc>::NextBlock()
{
    if( int(Iter) == 0 && !Second && Left > Right )
        {
        Iter.Restart( 0, Right );
        Second = 1;
        }
}

#if defined( BI_OLDNAMES )
#define BI_MDequeAsVectorIterator TMDequeAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TDequeAsVector                               */
/*  template <class T> class TDequeAsVectorIterator                       */
/*                                                                        */
/*  Implements a dequeue of objects of type T, using a vector as the      */
/*  underlying implementation and TStandardAllocator as its memory        */
/*  manager.                                                              */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TDequeAsVector :
    public TMDequeAsVector<T,TStandardAllocator>
{

public:

    TDequeAsVector( unsigned max = DEFAULT_DEQUE_SIZE ) :
        TMDequeAsVector<T,TStandardAllocator>( max )
        {
        }

};

template <class T> class TDequeAsVectorIterator :
    public TMDequeAsVectorIterator<T,TStandardAllocator>
{

public:

    TDequeAsVectorIterator( const TDequeAsVector<T>& d ) :
        TMDequeAsVectorIterator<T,TStandardAllocator>( d )
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_DequeAsVector TDequeAsVector
#define BI_DequeAsVectorIterator TDequeAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMIDequeAsVector                 */
/*                                                                        */
/*  Implements a managed dequeue of pointers to objects of type T,        */
/*  using a vector as the underlying implementation.                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMIDequeAsVectorIterator;

template <class T,class Alloc> class TMIDequeAsVector :
    public TDequeAsVectorImp<TMIVectorImp<T,Alloc>,T *>,
    public TShouldDelete
{

    typedef TDequeAsVectorImp<TMIVectorImp<T,Alloc>,T *> Parent;

public:

    friend TMIDequeAsVectorIterator<T,Alloc>;

    typedef void (*IterFunc)(T&, void *);
    typedef int  (*CondFunc)(const T &, void *);

    TMIDequeAsVector( unsigned sz = DEFAULT_DEQUE_SIZE ) :
        TDequeAsVectorImp<TMIVectorImp<T,Alloc>,T *>(sz)
        {
        }

    ~TMIDequeAsVector()
        {
        Flush();
        }

    T *PeekLeft() const
        {
        PRECONDITION( !IsEmpty() );
        return Data[Left];
        }

    T *PeekRight() const
        {
        PRECONDITION( !IsEmpty() );
        return Data[Prev(Right)];
        }

    T *GetLeft();
    T *GetRight();
    void PutLeft( T *t );
    void PutRight( T *t );
    void Flush( TShouldDelete::DeleteType = TShouldDelete::DefDelete );

    void ForEach( IterFunc iter, void *args );

    T *FirstThat( CondFunc cond, void *args ) const;

    T *LastThat( CondFunc cond, void *args ) const;

#if defined( BI_OLDNAMES )
    T *peekLeft() const { return PeekLeft(); }
    T *peekRight() const { return PeekRight(); }
    T *getLeft() { return GetLeft(); }
    T *getRight() { return GetRight(); }
    void putLeft( T *t ) { PutLeft(t); }
    void putRight( T *t ) { PutRight(t); }
    void flush( TShouldDelete::DeleteType dt = TShouldDelete::DefDelete )
        { Flush( dt ); }
    void forEach( IterFunc iter, void *args )
        { ForEach( iter, args ); }
    T *firstThat( CondFunc cond, void *args ) const
        { return FirstThat( cond, args ); }
    T *lastThat( CondFunc cond, void *args ) const
        { return LastThat( cond, args ); }
#endif  // BI_OLDNAMES

};

template <class T, class Alloc>
T *TMIDequeAsVector<T,Alloc>::GetRight()
{
    PRECONDITION( !IsEmpty() );
    Right = Prev(Right);
    T *t = Data[Right];
    Data[Right] = 0;
    return t;
}

template <class T, class Alloc>
void TMIDequeAsVector<T,Alloc>::PutRight( T *t )
{
    PRECONDITION( !IsFull() );
    Data[Right] = t;
    Right = Next(Right);
}

template <class T, class Alloc>
T *TMIDequeAsVector<T,Alloc>::GetLeft()
{
    PRECONDITION( !IsEmpty() );
    T *t = Data[Left];
    Data[Left] = 0;
    Left = Next(Left);
    return t;
}

template <class T, class Alloc>
void TMIDequeAsVector<T,Alloc>::PutLeft( T *t )
{
    PRECONDITION( !IsFull() );
    Left = Prev(Left);
    Data[Left] = t;
}

template <class T,class Alloc>
void TMIDequeAsVector<T,Alloc>::Flush( TShouldDelete::DeleteType dt )
{
    if( DelObj(dt) != 0 )
        {
        if( Left <= Right )
            Data.Flush( 1, Right, Left );
        else
            {
            Data.Flush( 1, Data.Limit(), Left );
            Data.Flush( 1, Right, 0 );
            }
        }
    Left = Right = 0;
}

template <class T,class Alloc>
void TMIDequeAsVector<T,Alloc>::ForEach( IterFunc iter, void *args )
{
    for( unsigned index = Left; index != Right; index=Next(index) )
        iter( *(Data[index]), args );
}

template <class T,class Alloc>
T *TMIDequeAsVector<T,Alloc>::FirstThat( CondFunc cond, void *args ) const
{
    for( unsigned index = Left; index != Right; index=Next(index) )
        if( cond( *(Data[index]), args ) )
            return Data[index];
    return 0;
}

template <class T,class Alloc>
T *TMIDequeAsVector<T,Alloc>::LastThat( CondFunc cond, void *args ) const
{
    T *res = 0;
    for( unsigned index = Left; index != Right; index=Next(index) )
        if( cond( *(Data[index]), args ) )
            res = Data[index];
    return res;
}

#if defined( BI_OLDNAMES )
#define BI_MIDequeAsVector TMIDequeAsVector
#define BI_MIDequeAsVectorIterator TMIDequeAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TMIDequeAsVectorIterator                     */
/*                                                                        */
/*  Implements an iterator for the family of indirect Deques as Vectors.  */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMIDequeAsVectorIterator
{

public:

    TMIDequeAsVectorIterator( const TMIDequeAsVector<T,Alloc>& );

    operator int();
    T *Current();
    T *operator ++ ( int );
    T *operator ++ ();
    void Restart();

#if defined( BI_OLDNAMES )
    T *current() { return Current(); }
    void restart() { Restart(); }
#endif  // BI_OLDNAMES

private:

    unsigned Left;
    unsigned Right;
    const TMIVectorImp<T,Alloc> *Vect;
    TMIVectorIteratorImp<T,Alloc> Iter;
    int Second;

    void NextBlock();

};

template <class T,class Alloc>
TMIDequeAsVectorIterator<T,Alloc>::TMIDequeAsVectorIterator( const TMIDequeAsVector<T,Alloc>& v ) :
    Iter( v.Data )
{
    Vect = &v.Data;
    Left = v.Left;
    Right = v.Right;
    Restart();
}

template <class T,class Alloc>
TMIDequeAsVectorIterator<T,Alloc>::operator int()
{
    return int(Iter);
}

template <class T,class Alloc>
T *TMIDequeAsVectorIterator<T,Alloc>::Current()
{
    return Iter.Current();
}

template <class T,class Alloc>
T *TMIDequeAsVectorIterator<T,Alloc>::operator ++ ( int )
{
    T *temp = Iter++;
    NextBlock();
    return temp;
}

template <class T,class Alloc>
T *TMIDequeAsVectorIterator<T,Alloc>::operator ++ ()
{
    Iter++;
    NextBlock();
    return Iter.Current();
}

template <class T,class Alloc>
void TMIDequeAsVectorIterator<T,Alloc>::Restart()
{
    if( Left <= Right )
        Iter.Restart( Left, Right );
    else
        Iter.Restart( Left, Vect->Limit() );
    Second = 0;
}

template <class T,class Alloc>
void TMIDequeAsVectorIterator<T,Alloc>::NextBlock()
{
    if( int(Iter) == 0 && !Second && Left > Right )
        {
        Iter.Restart( 0, Right );
        Second = 1;
        }
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TIDequeAsVector                              */
/*  template <class T> class TIDequeAsVectorIterator                      */
/*                                                                        */
/*  Implements a dequeue of pointers to objects of type T, using a vector */
/*  as the underlying implementation and TStandardAllocator as its        */
/*  memory manager.                                                       */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TIDequeAsVector :
    public TMIDequeAsVector<T,TStandardAllocator>
{

public:

    TIDequeAsVector( unsigned sz = DEFAULT_DEQUE_SIZE ) :
        TMIDequeAsVector<T,TStandardAllocator>(sz)
        {
        }

};

template <class T> class TIDequeAsVectorIterator :
    public TMIDequeAsVectorIterator<T,TStandardAllocator>
{

public:

    TIDequeAsVectorIterator( const TIDequeAsVector<T>& d ) :
        TMIDequeAsVectorIterator<T,TStandardAllocator>(d)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_IDequeAsVector TIDequeAsVector
#define BI_IDequeAsVectorIterator TIDequeAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class Lst, class T> class TDequeAsDoubleListImp             */
/*                                                                        */
/*  Implements the fundamental dequeue operations, using a list           */
/*  as the underlying implementation.  The type Lst specifies the         */
/*  form of the list, either a TDoubleListImp<T0> or a                    */
/*  TIDoubleListImp<T0>.  The type T specifies the type of the            */
/*  objects to be put in the deque.  When using TDoubleListImp<T0>,       */
/*  T should be the same as T0. When using TIDoubleListImp<T0>, T         */
/*  should be of type pointer to T0.  See TDequeAsDoubleList and          */
/*  TIDequeAsDoubleList for examples.                                     */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class Lst, class T> class TDequeAsDoubleListImp
{

public:

    TDequeAsDoubleListImp()
        {
        }

    int IsFull() const
        {
        return 0;
        }

    int IsEmpty() const
        {
        return GetItemsInContainer() == 0;
        }

    int GetItemsInContainer() const
        {
        return Data.GetItemsInContainer();
        }

#if defined( BI_OLDNAMES )
    int isFull() const { return IsFull(); }
    int isEmpty() const { return IsEmpty(); }
    int getItemsInContainer() const { return GetItemsInContainer(); }
#endif  // BI_OLDNAMES

protected:

    Lst Data;

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMDequeAsDoubleList              */
/*  template <class T,class Alloc> class TMDequeAsDoubleListIterator      */
/*                                                                        */
/*  Implements a managed dequeue of objects of type T, using a            */
/*  double-linked list as the underlying implementation.                  */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMDequeAsDoubleListIterator;

template <class T,class Alloc> class TMDequeAsDoubleList :
    public TDequeAsDoubleListImp<TMDoubleListImp<T,Alloc>,T>
{

    typedef TDequeAsDoubleListImp<TMDoubleListImp<T,Alloc>,T> Parent;

public:

    friend TMDequeAsDoubleListIterator<T,Alloc>;

    typedef void (*IterFunc)(T &, void *);
    typedef int  (*CondFunc)(const T&, void *);

    T GetLeft();
    T GetRight();

    void PutLeft( const T& t )
        {
        Data.Add( t );
        }

    void PutRight( const T& t )
        {
        Data.AddAtTail( t );
        }

    const T& PeekLeft() const
        {
        PRECONDITION( !IsEmpty() );
        return Data.PeekHead();
        }

    const T& PeekRight() const
        {
        PRECONDITION( !IsEmpty() );
        return Data.PeekTail();
        }

    void ForEach( IterFunc iter, void *args )
        {
        Data.ForEach( iter, args );
        }

    T *FirstThat( CondFunc cond, void *args ) const
        {
        return Data.FirstThat( cond, args );
        }

    T *LastThat( CondFunc cond, void *args ) const
        {
        return Data.LastThat( cond, args );
        }

    void Flush()
        {
        Data.Flush();
        }

#if defined( BI_OLDNAMES )
    T peekLeft() const { return PeekLeft(); }
    T peekRight() const { return PeekRight(); }
    T getLeft() { return GetLeft(); }
    T getRight() { return GetRight(); }
    void putLeft( const T& t ) { PutLeft(t); }
    void putRight( const T& t ) { PutRight(t); }
    void flush( TShouldDelete::DeleteType = TShouldDelete::DefDelete )
        { Flush(); }
    void forEach( IterFunc iter, void *args )
        { ForEach( iter, args ); }
    T *firstThat( CondFunc cond, void *args ) const
        { return FirstThat( cond, args ); }
    T *lastThat( CondFunc cond, void *args ) const
        { return LastThat( cond, args ); }
    void flush( int ) { Flush(); }
#endif  // BI_OLDNAMES

};

template <class T, class Alloc> T TMDequeAsDoubleList<T,Alloc>::GetLeft()
{
    PRECONDITION( !IsEmpty() );
    T t = Data.PeekHead();
    Data.DetachAtHead();
    return t;
}

template <class T, class Alloc> T TMDequeAsDoubleList<T,Alloc>::GetRight()
{
    PRECONDITION( !IsEmpty() );
    T t = Data.PeekTail();
    Data.DetachAtTail();
    return t;
}

template <class T,class Alloc> class TMDequeAsDoubleListIterator :
    public TMDoubleListIteratorImp<T,Alloc>
{

public:

    TMDequeAsDoubleListIterator( const TMDequeAsDoubleList<T,Alloc>& s ) :
        TMDoubleListIteratorImp<T,Alloc>(s.Data)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_MDequeAsDoubleList TMDequeAsDoubleList
#define BI_MDequeAsDoubleListIterator TMDequeAsDoubleListIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TDequeAsDoubleList                           */
/*  template <class T> class TDequeAsDoubleListIterator                   */
/*                                                                        */
/*  Implements a dequeue of objects of type T, using a double-linked list */
/*  as the underlying implementation and TStandardAllocator as its        */
/*  memory manager.                                                       */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TDequeAsDoubleList :
    public TMDequeAsDoubleList<T,TStandardAllocator>
{
};

#if defined( BI_OLDNAMES )
#define BI_DequeAsDoubleList TDequeAsDoubleList
#endif

template <class T> class TDequeAsDoubleListIterator :
    public TMDequeAsDoubleListIterator<T,TStandardAllocator>
{

public:

    TDequeAsDoubleListIterator( const TDequeAsDoubleList<T>& s ) :
        TMDequeAsDoubleListIterator<T,TStandardAllocator>(s) {}

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMIDequeAsDoubleList             */
/*  template <class T,class Alloc> class TMIDequeAsDoubleListIterator     */
/*                                                                        */
/*  Implements a managed dequeue of pointers to objects of type T,        */
/*  using a double-linked list as the underlying implementation.          */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMIDequeAsDoubleListIterator;

template <class T,class Alloc> class TMIDequeAsDoubleList :
    public TDequeAsDoubleListImp<TMIDoubleListImp<T,Alloc>,T *>,
    public TShouldDelete
{

    typedef TDequeAsDoubleListImp<TMIDoubleListImp<T,Alloc>,T *> Parent;

public:


    friend TMIDequeAsDoubleListIterator<T,Alloc>;

    typedef void (*IterFunc)(T&, void *);
    typedef int  (*CondFunc)(const T&, void *);

    T *GetLeft();
    T *GetRight();

    void PutLeft( T *t )
        {
        Data.Add( t );
        }

    void PutRight( T *t )
        {
        Data.AddAtTail( t );
        }

    T *PeekLeft() const
        {
        PRECONDITION( !IsEmpty() );
        return STATIC_CAST(T *,Data.PeekHead());
        }

    T *PeekRight() const
        {
        PRECONDITION( !IsEmpty() );
        return STATIC_CAST(T *,Data.PeekTail());
        }

    void Flush( TShouldDelete::DeleteType dt = TShouldDelete::DefDelete )
        {
        Data.Flush( DelObj(dt) );
        }

    void ForEach( IterFunc iter, void *args )
        {
        Data.ForEach( iter, args );
        }

    T *FirstThat( CondFunc cond, void *args ) const
        {
        return Data.FirstThat( cond, args );
        }

    T *LastThat( CondFunc cond, void *args ) const
        {
        return Data.LastThat( cond, args );
        }

#if defined( BI_OLDNAMES )
    T *peekLeft() const { return PeekLeft(); }
    T *peekRight() const { return PeekRight(); }
    T *getLeft() { return GetLeft(); }
    T *getRight() { return GetRight(); }
    void putLeft( T *t ) { PutLeft(t); }
    void putRight( T *t ) { PutRight(t); }
    void flush( TShouldDelete::DeleteType dt = TShouldDelete::DefDelete )
        { Flush(dt); }
    void forEach( IterFunc iter, void *args )
        { ForEach( iter, args ); }
    T *firstThat( CondFunc cond, void *args ) const
        { return FirstThat( cond, args ); }
    T *lastThat( CondFunc cond, void *args ) const
        { return LastThat( cond, args ); }
#endif  // BI_OLDNAMES

};

template <class T,class Alloc> class TMIDequeAsDoubleListIterator :
    public TMIDoubleListIteratorImp<T,Alloc>
{

public:

    TMIDequeAsDoubleListIterator( const TMIDequeAsDoubleList<T,Alloc>& s ) :
        TMIDoubleListIteratorImp<T,Alloc>(s.Data)
        {
        }

};

template <class T, class Alloc>
T *TMIDequeAsDoubleList<T,Alloc>::GetLeft()
{
    PRECONDITION( !IsEmpty() );
    T *t = Data.PeekHead();
    Data.Detach( t, 0 );
    return t;
}

template <class T, class Alloc>
T *TMIDequeAsDoubleList<T,Alloc>::GetRight()
{
    PRECONDITION( !IsEmpty() );
    T *t = Data.PeekTail();
    Data.Detach( t, 0 );
    return t;
}

#if defined( BI_OLDNAMES )
#define BI_MIDequeAsDoubleList TMIDequeAsDoubleList
#define BI_MIDequeAsDoubleListIterator TMIDequeAsDoubleListIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TIDequeAsDoubleList                          */
/*  template <class T> class TIDequeAsDoubleListIterator                  */
/*                                                                        */
/*  Implements a dequeue of pointers to objects of type T, using a        */
/*  double-linked list as the underlying implementation and               */
/*  TStandardAllocator as its memory manager.                             */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TIDequeAsDoubleList :
    public TMIDequeAsDoubleList<T,TStandardAllocator>
{
};

template <class T> class TIDequeAsDoubleListIterator :
    public TMIDequeAsDoubleListIterator<T,TStandardAllocator>
{

public:

    TIDequeAsDoubleListIterator( const TIDequeAsDoubleList<T>& s ) :
        TMIDequeAsDoubleListIterator<T,TStandardAllocator>(s) {}

};

#if defined( BI_OLDNAMES )
#define BI_IDequeAsDoubleList TIDequeAsDoubleList
#define BI_IDequeAsDoubleListIterator TIDequeAsDoubleListIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TDeque                                       */
/*  template <class T> class TDequeIterator                               */
/*                                                                        */
/*  Easy names for TDequeAsVector and TDequeAsVectorIterator.             */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TDeque :
    public TDequeAsVector<T>
{

public:

    TDeque( unsigned max = DEFAULT_QUEUE_SIZE ) :
        TDequeAsVector<T>( max )
        {
        }

};

template <class T> class TDequeIterator :
    public TDequeAsVectorIterator<T>
{

public:


    TDequeIterator( const TDeque<T>& a ) :
        TDequeAsVectorIterator<T>(a)
        {
        }

};

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#pragma option -Vo.

#endif  // CLASSLIB_DEQUES_H

