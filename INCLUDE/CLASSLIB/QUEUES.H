/*------------------------------------------------------------------------*/
/*                                                                        */
/*  QUEUES.H                                                              */
/*                                                                        */
/*  Copyright (c) 1991, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( CLASSLIB_QUEUES_H )
#define CLASSLIB_QUEUES_H

#if !defined( CLASSLIB_DEFS_H )
#include <classlib/defs.h>
#endif

#if !defined( CLASSLIB_DEQUES_H )
#include <classlib/deques.h>
#endif

#pragma option -Vo-
#if defined( BI_CLASSLIB_NO_po )
#pragma option -po-
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMQueueAsVector                  */
/*  template <class T,class Alloc> class TMQueueAsVectorIterator          */
/*                                                                        */
/*  Implements a managed queue of objects of type T, using a vector as    */
/*  the underlying implementation.                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMQueueAsVectorIterator;

template <class T,class Alloc> class TMQueueAsVector :
    private TMDequeAsVector<T,Alloc>
{

    typedef TMDequeAsVector<T,Alloc> Parent;

public:

    friend class TMQueueAsVectorIterator<T,Alloc>;

    TMQueueAsVector( unsigned sz = DEFAULT_QUEUE_SIZE ) :
        TMDequeAsVector<T,Alloc>(sz)
        {
        }

    const T& Peek() const
        {
        return Parent::PeekRight();
        }

    T Get()
        {
        return Parent::GetRight();
        }

    void Put( const T& t )
        {
        Parent::PutLeft( t );
        }

    Parent::IterFunc;
    Parent::CondFunc;
    Parent::ForEach;
    Parent::FirstThat;
    Parent::LastThat;
    Parent::Flush;
    Parent::IsFull;
    Parent::IsEmpty;
    Parent::GetItemsInContainer;

#if defined( BI_OLDNAMES )
    T get() { return Get(); }
    void put( const T& t ) { Put(t); }
    Parent::forEach;
    Parent::firstThat;
    Parent::lastThat;
    Parent::flush;
    Parent::isFull;
    Parent::isEmpty;
    Parent::getItemsInContainer;
#endif  // BI_OLDNAMES

};

template <class T,class Alloc> class TMQueueAsVectorIterator :
    public TMDequeAsVectorIterator<T,Alloc>
{

public:

    TMQueueAsVectorIterator( const TMQueueAsVector<T,Alloc>& q ) :
        TMDequeAsVectorIterator<T,Alloc>(q)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_MQueueAsVector TMQueueAsVector
#define BI_MQueueAsVectorIterator TMQueueAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TQueueAsVector                               */
/*  template <class T> class TQueueAsVectorIterator                       */
/*                                                                        */
/*  Implements a queue of objects of type T, using a vector as            */
/*  the underlying implementation and TStandardAllocator as its memory    */
/*  manager.                                                              */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TQueueAsVector :
    public TMQueueAsVector<T,TStandardAllocator>
{

public:

    TQueueAsVector( unsigned sz = DEFAULT_QUEUE_SIZE ) :
        TMQueueAsVector<T,TStandardAllocator>(sz)
        {
        }

};

template <class T> class TQueueAsVectorIterator :
    public TMQueueAsVectorIterator<T,TStandardAllocator>
{

public:

    TQueueAsVectorIterator( const TQueueAsVector<T>& q ) :
        TMQueueAsVectorIterator<T,TStandardAllocator>(q)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_QueueAsVector TQueueAsVector
#define BI_QueueAsVectorIterator TQueueAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMIQueueAsVector                 */
/*  template <class T,class Alloc> class TMIQueueAsVectorIterator         */
/*                                                                        */
/*  Implements a managed queue of pointers to objects of type T,          */
/*  using a vector as the underlying implementation.                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMIQueueAsVectorIterator;

template <class T,class Alloc> class TMIQueueAsVector :
    private TMIDequeAsVector<T,Alloc>
{

    typedef TMIDequeAsVector<T,Alloc> Parent;

public:

    friend class TMIQueueAsVectorIterator<T,Alloc>;

    TMIQueueAsVector( unsigned sz = DEFAULT_QUEUE_SIZE ) :
        TMIDequeAsVector<T,Alloc>(sz)
        {
        }

    T *Peek() const
        {
        return Parent::PeekRight();
        }

    T *Get()
        {
        return Parent::GetRight();
        }

    void Put( T *t )
        {
        Parent::PutLeft( t );
        }

    Parent::IterFunc;
    Parent::CondFunc;
    Parent::IsFull;
    Parent::IsEmpty;
    Parent::GetItemsInContainer;
    Parent::Flush;
    Parent::ForEach;
    Parent::FirstThat;
    Parent::LastThat;
    Parent::OwnsElements;

#if defined( BI_OLDNAMES )
    T *peek() const { return Peek(); }
    T *get() { return Get(); }
    void put( T *t ) { Put(t); }
    Parent::isFull;
    Parent::isEmpty;
    Parent::getItemsInContainer;
    Parent::flush;
    Parent::forEach;
    Parent::firstThat;
    Parent::lastThat;
    Parent::ownsElements;
#endif  // BI_OLDNAMES

};

template <class T,class Alloc> class TMIQueueAsVectorIterator :
    public TMIDequeAsVectorIterator<T,Alloc>
{

public:

    TMIQueueAsVectorIterator( const TMIQueueAsVector<T,Alloc>& q ) :
        TMIDequeAsVectorIterator<T,Alloc>(q) {}

};

#if defined( BI_OLDNAMES )
#define BI_MIQueueAsVector TMIQueueAsVector
#define BI_MIQueueAsVectorIterator TMIQueueAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TIQueueAsVector                              */
/*  template <class T> class TIQueueAsVectorIterator                      */
/*                                                                        */
/*  Implements a queue of pointers to objects of type T,                  */
/*  using a vector as the underlying implementation and                   */
/*  TStandardAllocator as its memory manager.                             */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TIQueueAsVector :
    public TMIQueueAsVector<T,TStandardAllocator>
{

public:

    TIQueueAsVector( unsigned sz = DEFAULT_QUEUE_SIZE ) :
        TMIQueueAsVector<T,TStandardAllocator>(sz)
        {
        }

};

template <class T> class TIQueueAsVectorIterator :
    public TMIQueueAsVectorIterator<T,TStandardAllocator>
{

public:

    TIQueueAsVectorIterator( const TIQueueAsVector<T>& q ) :
        TMIQueueAsVectorIterator<T,TStandardAllocator>(q)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_IQueueAsVector TIQueueAsVector
#define BI_IQueueAsVectorIterator TIQueueAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMQueueAsDoubleList              */
/*  template <class T,class Alloc> class TMQueueAsDoubleListIterator      */
/*                                                                        */
/*  Implements a managed queue of objects of type T, using a double       */
/*  linked list as the underlying implementation.                         */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMQueueAsDoubleListIterator;

template <class T,class Alloc> class TMQueueAsDoubleList :
    private TMDequeAsDoubleList<T,Alloc>
{

    typedef TMDequeAsDoubleList<T,Alloc> Parent;

public:

    friend class TMQueueAsDoubleListIterator<T,Alloc>;

    const T& Peek() const
        {
        return Parent::PeekRight();
        }

    T Get()
        {
        return Parent::GetRight();
        }

    void Put( const T& t )
        {
        Parent::PutLeft( t );
        }

    Parent::IterFunc;
    Parent::CondFunc;
    Parent::IsFull;
    Parent::IsEmpty;
    Parent::GetItemsInContainer;
    Parent::Flush;
    Parent::ForEach;
    Parent::FirstThat;
    Parent::LastThat;

#if defined( BI_OLDNAMES )
    T peek() const { return Peek(); }
    T get() { return Get(); }
    void put( const T& t ) { Put(t); }
    Parent::isFull;
    Parent::isEmpty;
    Parent::getItemsInContainer;
    Parent::flush;
    Parent::forEach;
    Parent::firstThat;
    Parent::lastThat;
#endif  // BI_OLDNAMES

};

template <class T,class Alloc> class TMQueueAsDoubleListIterator :
    public TMDequeAsDoubleListIterator<T,Alloc>
{

public:

    TMQueueAsDoubleListIterator( const TMQueueAsDoubleList<T,Alloc>& q ) :
        TMDequeAsDoubleListIterator<T,Alloc>(q)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_QueueAsDoubleList TQueueAsDoubleList
#define BI_QueueAsDoubleListIterator TQueueAsDoubleListIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TQueueAsDoubleList                           */
/*  template <class T> class TQueueAsDoubleListIterator                   */
/*                                                                        */
/*  Implements a queue of objects of type T, using a double linked list   */
/*  as the underlying implementation and TStandardAllocator as its        */
/*  memory manager.                                                       */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TQueueAsDoubleList :
    public TMQueueAsDoubleList<T,TStandardAllocator>
{
};

template <class T> class TQueueAsDoubleListIterator :
    public TMQueueAsDoubleListIterator<T,TStandardAllocator>
{

public:

    TQueueAsDoubleListIterator( const TQueueAsDoubleList<T>& q ) :
        TMQueueAsDoubleListIterator<T,TStandardAllocator>(q)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_QueueAsDoubleList TQueueAsDoubleList
#define BI_QueueAsDoubleListIterator TQueueAsDoubleListIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMIQueueAsDoubleList             */
/*  template <class T,class Alloc> class TMIQueueAsDoubleListIterator     */
/*                                                                        */
/*  Implements a managed queue of pointers to objects of type T,          */
/*  using a double linked list as the underlying implementation.          */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMIQueueAsDoubleListIterator;

template <class T,class Alloc> class TMIQueueAsDoubleList :
    private TMIDequeAsDoubleList<T,Alloc>
{

    typedef TMIDequeAsDoubleList<T,Alloc> Parent;

public:

    friend class TMIQueueAsDoubleListIterator<T,Alloc>;

    T *Peek() const
        {
        return Parent::PeekRight();
        }

    T *Get()
        {
        return Parent::GetRight();
        }

    void Put( T *t )
        {
        Parent::PutLeft( t );
        }

    Parent::IterFunc;
    Parent::CondFunc;
    Parent::IsFull;
    Parent::IsEmpty;
    Parent::GetItemsInContainer;
    Parent::Flush;
    Parent::ForEach;
    Parent::FirstThat;
    Parent::LastThat;
    Parent::OwnsElements;

#if defined( BI_OLDNAMES )
    T *peek() const { return Peek(); }
    T *get() { return Get(); }
    void put( T *t ) { Put(t); }
    Parent::isFull;
    Parent::isEmpty;
    Parent::getItemsInContainer;
    Parent::flush;
    Parent::forEach;
    Parent::firstThat;
    Parent::lastThat;
    Parent::ownsElements;
#endif  // BI_OLDNAMES

};

template <class T,class Alloc> class TMIQueueAsDoubleListIterator :
    public TMIDequeAsDoubleListIterator<T,Alloc>
{

public:

    TMIQueueAsDoubleListIterator( const TMIQueueAsDoubleList<T,Alloc>& q ) :
        TMIDequeAsDoubleListIterator<T,Alloc>(q) {}

};

#if defined( BI_OLDNAMES )
#define BI_MIQueueAsDoubleList TMIQueueAsDoubleList
#define BI_MIQueueAsDoubleListIterator TMIQueueAsDoubleListIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TIQueueAsDoubleList                          */
/*  template <class T> class TIQueueAsDoubleListIterator                  */
/*                                                                        */
/*  Implements a queue of pointers to objects of type T, using a double   */
/*  linked list as the underlying implementation and TStandardAllocator   */
/*  as its memory manager.                                                */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TIQueueAsDoubleList :
    public TMIQueueAsDoubleList<T,TStandardAllocator>
{
};

template <class T> class TIQueueAsDoubleListIterator :
    public TMIQueueAsDoubleListIterator<T,TStandardAllocator>
{

public:

    TIQueueAsDoubleListIterator( const TIQueueAsDoubleList<T>& q ) :
        TMIQueueAsDoubleListIterator<T,TStandardAllocator>(q) {}

};

#if defined( BI_OLDNAMES )
#define BI_IQueueAsDoubleList TIQueueAsDoubleList
#define BI_IQueueAsDoubleListIterator TIQueueAsDoubleListIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TQueue                                       */
/*  template <class T> class TQueueIterator                               */
/*                                                                        */
/*  Easy names for TQueueAsVector and TQueueAsVectorIterator              */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TQueue :
    public TQueueAsVector<T>
{

public:

    TQueue( unsigned max = DEFAULT_QUEUE_SIZE ) :
        TQueueAsVector<T>( max )
        {
        }

}

template <class T> class TQueueIterator :
    public TQueueAsVectorIterator<T>
{

public:


    TQueueIterator( const TQueue<T>& a ) :
        TQueueAsVectorIterator<T>(a)
        {
        }

};

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#pragma option -Vo.

#endif  // CLASSLIB_QUEUES_H

