/*------------------------------------------------------------------------*/
/*                                                                        */
/*  STACKS.H                                                              */
/*                                                                        */
/*  Copyright (c) 1991, 1993 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __CLASSLIB_STACKS_H )
#define __CLASSLIB_STACKS_H

#if !defined( __CHECKS_H )
#include <checks.h>
#endif  // __CHECKS_H

#if !defined( __CLASSLIB_DEFS_H )
#include "classlib\defs.h"
#endif  // __CLASSLIB_DEFS_H

#if !defined( __CLASSLIB_SHDDEL_H )
#include "classlib\shddel.h"
#endif  // __CLASSLIB_SHDDEL_H

#if !defined( __CLASSLIB_VECTIMP_H )
#include "classlib\vectimp.h"
#endif  // __CLASSLIB_VECTIMP_H

#if !defined( __CLASSLIB_LISTIMP_H )
#include "classlib\listimp.h"
#endif  // __CLASSLIB_LISTIMP_H

#pragma option -Vo-
#if defined( BI_CLASSLIB_NO_po )
#pragma option -po-
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class Vect, class T> class TStackAsVectorImp                */
/*                                                                        */
/*  Implements the fundamental stack operations, using a vector           */
/*  as the underlying implementation.  The type Vect specifies the        */
/*  form of the vector, either a TVectorImp<T0> or a                      */
/*  TIVectorImp<T0>.  The type T specifies the type of the                */
/*  objects to be put on the stack.  When using TVectorImp<T0>,           */
/*  T should be the same as T0. When using TIVectorImp<T0>, T             */
/*  should be of type pointer to T0.  See TStackAsVector and              */
/*  TIStackAsVector for examples.                                         */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class Vect, class T> class TStackAsVectorImp
{

public:

    TStackAsVectorImp( unsigned max = DEFAULT_STACK_SIZE ) :
        Data(max),
        Current(0)
        {
        }

    int IsEmpty() const
        {
        return Current == 0;
        }

    int IsFull() const
        {
        return Current == Data.Limit();
        }

    int GetItemsInContainer() const
        {
        return Current;
        }

#if defined( BI_OLDNAMES )
    int isEmpty() const { return IsEmpty(); }
    int isFull() const { return IsFull(); }
    int getItemsInContainer() const { return GetItemsInContainer(); }
#endif  // BI_OLDNAMES

protected:

    Vect Data;
    unsigned Current;

};

#if defined( BI_OLDNAMES )
#define BI_StackAsVectorImp TStackAsVectorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMStackAsVector                  */
/*  template <class T,class Alloc> class TMStackAsVectorIterator          */
/*                                                                        */
/*  Implements a managed stack of objects of type T, using a vector as    */
/*  the underlying implementation.                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T, class Alloc> class TMStackAsVectorIterator;

template <class T,class Alloc> class TMStackAsVector :
    public TStackAsVectorImp<TMVectorImp<T,Alloc>,T>
{

    typedef TStackAsVectorImp<TMVectorImp<T,Alloc>,T> Parent;

public:

    friend class TMStackAsVectorIterator<T,Alloc>;

    typedef void (*IterFunc)(T&, void *);
    typedef int  (*CondFunc)(const T&, void *);

    TMStackAsVector( unsigned max = DEFAULT_STACK_SIZE ) :
        TStackAsVectorImp<TMVectorImp<T,Alloc>,T>( max )
        {
        }

    void Push( const T& t )
        {
        PRECONDITION( Current < Data.Limit() );
        Data[Current++] = t;
        }

    T Pop()
        {
        PRECONDITION( Current > 0 );
        return Data[--Current];
        }

    const T& Top() const
        {
        PRECONDITION( Current > 0 );
        return Data[Current-1];
        }

    void ForEach( IterFunc iter, void *args )
        {
        if( !IsEmpty() )
            Data.ForEach( iter, args, 0, Current );
        }

    T *FirstThat( CondFunc cond, void *args ) const
        {
        if( IsEmpty() )
            return 0;
        return Data.FirstThat( cond, args, 0, Current );
        }

    T *LastThat( CondFunc cond, void *args ) const
        {
        if( IsEmpty() )
            return 0;
        return Data.LastThat( cond, args, 0, Current );
        }

    void Flush()
        {
        Current = 0;
        }

#if defined( BI_OLDNAMES )
    void push( const T& t ) { Push(t); }
    T pop() { return Pop(); }
    const T& top() const { return Top(); }
    void forEach( IterFunc iter, void *args )
        { ForEach( iter, args ); }
    T *firstThat( CondFunc cond, void *args ) const
        { return FirstThat( cond, args ); }
    T *lastThat( CondFunc cond, void *args ) const
        { return LastThat( cond, args ); }
    void flush( TShouldDelete::DeleteType = TShouldDelete::DefDelete )
        {
        Flush();
        }

#endif  // BI_OLDNAMES

};

template <class T,class Alloc> class TMStackAsVectorIterator :
    public TMVectorIteratorImp<T,Alloc>
{

public:

    TMStackAsVectorIterator( const TMStackAsVector<T,Alloc>& s ) :
        TMVectorIteratorImp<T,Alloc>(s.Data,0,s.Current)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_MStackAsVector TMStackAsVector
#define BI_MStackAsVectorIterator TMStackAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TStackAsVector                               */
/*  template <class T> class TStackAsVectorIterator                       */
/*                                                                        */
/*  Implements a stack of objects of type T, using a vector as            */
/*  the underlying implementation and TStandardAllocator as its memory    */
/*  manager.                                                              */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TStackAsVector :
    public TMStackAsVector<T,TStandardAllocator>
{

public:

    TStackAsVector( unsigned max = DEFAULT_STACK_SIZE ) :
        TMStackAsVector<T,TStandardAllocator>( max )
        {
        }

};

template <class T> class TStackAsVectorIterator :
    public TMStackAsVectorIterator<T,TStandardAllocator>
{

public:

    TStackAsVectorIterator( const TStackAsVector<T>& s ) :
        TMStackAsVectorIterator<T,TStandardAllocator>(s)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_StackAsVector TStackAsVector
#define BI_StackAsVectorIterator TStackAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMIStackAsVector                 */
/*  template <class T,class Alloc> class TMIStackAsVectorIterator         */
/*                                                                        */
/*  Implements a managed stack of pointers to objects of type T,          */
/*  using a vector as the underlying implementation.                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMIStackAsVectorIterator;

template <class T,class Alloc> class TMIStackAsVector :
    public TStackAsVectorImp<TMIVectorImp<T,Alloc>, T * >,
    public TShouldDelete
{

    typedef TStackAsVectorImp<TMIVectorImp<T,Alloc>, T * > Parent;

public:

    friend class TMIStackAsVectorIterator<T,Alloc>;

    typedef void (*IterFunc)(T&, void *);
    typedef int  (*CondFunc)(const T&, void *);

    TMIStackAsVector( unsigned max = DEFAULT_STACK_SIZE ) :
        TStackAsVectorImp<TMIVectorImp<T,Alloc>,T *>( max )
        {
        }

    ~TMIStackAsVector()
        {
        Flush();
        }

    void Push( T *t )
        {
        PRECONDITION( Current < Data.Limit() );
        Data[Current++] = t;
        }

    T *Pop()
        {
        PRECONDITION( Current > 0 );
        return Data[--Current];
        }

    T *const& Top() const
        {
        PRECONDITION( Current > 0 );
        return Data[Current-1];
        }

    void Flush( DeleteType dt = DefDelete )
        {
        Data.Flush( DelObj(dt), Current );
        Current = 0;
        }

    void ForEach( IterFunc iter, void *args )
        {
        if( !IsEmpty() )
            Data.ForEach( iter, args, 0, Current );
        }

    T *FirstThat( CondFunc cond, void *args ) const
        {
        if( IsEmpty() )
            return 0;
        return Data.FirstThat( cond, args, 0, Current );
        }

    T *LastThat( CondFunc cond, void *args ) const
        {
        if( IsEmpty() )
            return 0;
        return Data.LastThat( cond, args, 0, Current );
        }

#if defined( BI_OLDNAMES )
    void push( T *t ) { Push(t); }
    T *pop() { return Pop(); }
    T *top() const { return Top(); }
    void flush( DeleteType dt = DefDelete ) { Flush(dt); }
    void forEach( IterFunc iter, void *args )
        { ForEach( iter, args ); }
    T *firstThat( CondFunc cond, void *args ) const
        { return FirstThat( cond, args ); }
    T *lastThat( CondFunc cond, void *args ) const
        { return LastThat( cond, args ); }
#endif  // BI_OLDNAMES

};

template <class T,class Alloc> class TMIStackAsVectorIterator :
    public TMIVectorIteratorImp<T,Alloc>
{

public:

    TMIStackAsVectorIterator( const TMIStackAsVector<T,Alloc>& s ) :
        TMIVectorIteratorImp<T,Alloc>(s.Data,0,s.Current)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_MIStackAsVector TMIStackAsVector
#define BI_MIStackAsVectorIterator TMIStackAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TIStackAsVector                              */
/*  template <class T> class TIStackAsVectorIterator                      */
/*                                                                        */
/*  Implements a stack of pointers to objects of type T,                  */
/*  using a vector as the underlying implementation and                   */
/*  TStandardAllocator as its memory manager.                             */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TIStackAsVector :
    public TMIStackAsVector<T,TStandardAllocator>
{

public:

    TIStackAsVector( unsigned max = DEFAULT_STACK_SIZE ) :
        TMIStackAsVector<T,TStandardAllocator>( max )
        {
        }

};

template <class T> class TIStackAsVectorIterator :
    public TMIStackAsVectorIterator<T,TStandardAllocator>
{

public:

    TIStackAsVectorIterator( const TIStackAsVector<T>& s ) :
        TMIStackAsVectorIterator<T,TStandardAllocator>(s)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_IStackAsVector TIStackAsVector
#define BI_IStackAsVectorIterator TIStackAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class Stk, class T> class TStackAsListImp                   */
/*                                                                        */
/*  Implements the fundamental stack operations, using a stack            */
/*  as the underlying implementation.  The type Stk specifies the         */
/*  form of the stack, either a TStackImp<T0> or a                        */
/*  TIStackImp<T0>.  The type T specifies the type of the                 */
/*  objects to be put on the stack.  When using TStackImp<T0>,            */
/*  T should be the same as T0. When using TIStackImp<T0>, T              */
/*  should be of type pointer to T0.  See TStackAsList and                */
/*  TIStackAsList for examples.                                           */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class Stk, class T> class TStackAsListImp
{

public:

    TStackAsListImp()
        {
        }

    int IsEmpty() const
        {
        return Data.IsEmpty();
        }

    int IsFull() const
        {
        return 0;
        }

    int GetItemsInContainer() const
        {
        return Data.GetItemsInContainer();
        }

#if defined( BI_OLDNAMES )
    int isEmpty() const { return IsEmpty(); }
    int isFull() const { return IsFull(); }
    int getItemsInContainer() const { return GetItemsInContainer(); }
#endif  // BI_OLDNAMES

protected:

    Stk Data;

};

#if defined( BI_OLDNAMES )
#define BI_StackAsListImp TStackAsListImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMStackAsList                    */
/*  template <class T,class Alloc> class TMStackAsListIterator            */
/*                                                                        */
/*  Implements a managed stack of objects of type T, using a list as      */
/*  the underlying implementation.                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T, class Alloc> class TMStackAsListIterator;

template <class T,class Alloc> class TMStackAsList :
    public TStackAsListImp<TMListImp<T,Alloc>,T>
{

    typedef TStackAsListImp<TMListImp<T,Alloc>,T> Parent;

public:

    friend class TMStackAsListIterator<T,Alloc>;

    typedef void (*IterFunc)(T&, void *);
    typedef int  (*CondFunc)(const T&, void *);

    void Push( const T& t )
        {
        Data.Add( t );
        }

    T Pop();

    const T& Top() const
        {
        PRECONDITION( !Data.IsEmpty() );
        return Data.PeekHead();
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
    void push( const T& t ) { Push(t); }
    T pop() { return Pop(); }
    const T& top() const { return Top(); }
    void forEach( IterFunc iter, void *args )
        { ForEach( iter, args ); }
    T *firstThat( CondFunc cond, void *args ) const
        { return FirstThat( cond, args ); }
    T *lastThat( CondFunc cond, void *args ) const
        { return LastThat( cond, args ); }
    void flush( TShouldDelete::DeleteType = TShouldDelete::DefDelete )
        {
        Flush();
        }

#endif  // BI_OLDNAMES
};

template <class T, class Alloc> T TMStackAsList<T,Alloc>::Pop()
{
    T t = Top();
    Data.Detach( t );
    return t;
}

template <class T,class Alloc> class TMStackAsListIterator :
    public TMListIteratorImp<T,Alloc>
{

public:

    TMStackAsListIterator( const TMStackAsList<T,Alloc>& s ) :
        TMListIteratorImp<T,Alloc>(s.Data)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_MStackAsList TMStackAsList
#define BI_MStackAsListIterator TMStackAsListIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TStackAsList                                 */
/*  template <class T> class TStackAsListIterator                         */
/*                                                                        */
/*  Implements a stack of objects of type T, using a list as              */
/*  the underlying implementation and TStandardAllocator as its memory    */
/*  manager.                                                              */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TStackAsList :
    public TMStackAsList<T,TStandardAllocator>
{
};

template <class T> class TStackAsListIterator :
    public TMStackAsListIterator<T,TStandardAllocator>
{

public:

    TStackAsListIterator( const TStackAsList<T>& s ) :
        TMStackAsListIterator<T,TStandardAllocator>(s)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_StackAsList TStackAsList
#define BI_StackAsListIterator TStackAsListIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMIStackAsList                   */
/*  template <class T,class Alloc> class TMIStackAsListIterator           */
/*                                                                        */
/*  Implements a managed stack of pointers to objects of type T,          */
/*  using a linked list as the underlying implementation.                 */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMIStackAsListIterator;

template <class T,class Alloc> class TMIStackAsList :
    public TStackAsListImp<TMIListImp<T,Alloc>,T *>,
    public TShouldDelete
{

    typedef TStackAsListImp<TMIListImp<T,Alloc>,T *> Parent;

public:

    friend class TMIStackAsListIterator<T,Alloc>;

    typedef void (*IterFunc)(T&, void *);
    typedef int  (*CondFunc)(const T&, void *);

    ~TMIStackAsList()
        {
        Flush();
        }

    void Push( T *t )
        {
        Data.Add( t );
        }

    T *Pop();

    T *Top() const
        {
        PRECONDITION( !Data.IsEmpty() );
        return Data.PeekHead();
        }

    void Flush( DeleteType dt = DefDelete )
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
    void push( T *t ) { Push(t); }
    T *pop() { return Pop(); }
    T *top() const { return Top(); }
    Parent::isEmpty;
    Parent::isFull;
    Parent::getItemsInContainer;
    void flush( DeleteType dt = DefDelete ) { Flush(dt); }
    void forEach( IterFunc iter, void *args )
        { ForEach( iter, args ); }
    T *firstThat( CondFunc cond, void *args ) const
        { return FirstThat( cond, args ); }
    T *lastThat( CondFunc cond, void *args ) const
        { return LastThat( cond, args ); }
#endif  // BI_OLDNAMES
};

template <class T, class Alloc> T *TMIStackAsList<T,Alloc>::Pop()
{
    T * t = Top();
    Data.Detach( t );
    return t;
}

template <class T,class Alloc> class TMIStackAsListIterator :
    public TMIListIteratorImp<T,Alloc>
{

public:

    TMIStackAsListIterator( const TMIStackAsList<T,Alloc>& s ) :
        TMIListIteratorImp<T,Alloc>(s.Data)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_MIStackAsList TMIStackAsList
#define BI_MIStackAsListIterator TMIStackAsListIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TIStackAsList                                */
/*  template <class T> class TIStackAsListIterator                        */
/*                                                                        */
/*  Implements a stack of pointers to objects of type T,                  */
/*  using a linked list as the underlying implementation and              */
/*  TStandardAllocator as its memory manager.                             */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TIStackAsList :
    public TMIStackAsList<T,TStandardAllocator>
{
};

template <class T> class TIStackAsListIterator :
    public TMIStackAsListIterator<T,TStandardAllocator>
{

public:

    TIStackAsListIterator( const TIStackAsList<T>& s ) :
        TMIStackAsListIterator<T,TStandardAllocator>(s)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_IStackAsList TIStackAsList
#define BI_IStackAsListIterator TIStackAsListIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TStack                                       */
/*  template <class T> class TStackIterator                               */
/*                                                                        */
/*  Easy names for TStackAsVector and TStackAsVectorIterator.             */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TStack :
    public TStackAsVector<T>
{

public:

    TStack( unsigned max = DEFAULT_STACK_SIZE ) :
        TStackAsVector<T>( max )
        {
        }

}

template <class T> class TStackIterator :
    public TStackAsVectorIterator<T>
{

public:


    TStackIterator( const TStack<T>& a ) :
        TStackAsVectorIterator<T>(a)
        {
        }

};

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#pragma option -Vo.

#endif  // __CLASSLIB_STACKS_H

