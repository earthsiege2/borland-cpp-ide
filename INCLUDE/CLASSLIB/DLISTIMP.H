/*------------------------------------------------------------------------*/
/*                                                                        */
/*  DLISTIMP.H                                                            */
/*                                                                        */
/*  Copyright (c) 1991, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( CLASSLIB_DLISTIMP_H )
#define CLASSLIB_DLISTIMP_H

#if !defined( __LIMITS_H )
#include <limits.h>
#endif

#if !defined( __CHECKS_H )
#include <checks.h>
#endif

#if !defined( CLASSLIB_DEFS_H )
#include <classlib/defs.h>
#endif

#if !defined( CLASSLIB_MEMMGR_H )
#include <classlib/memmgr.h>
#endif

#if !defined( CLASSLIB_ALLOCTR_H )
#include <classlib/alloctr.h>
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
/*  template <class T,class Alloc> class TMDoubleListElement              */
/*                                                                        */
/*  Node for templates TMDoubleListImp<T,Alloc> and                       */
/*  TMIDoubleListImp<T,Alloc>                                             */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMDoubleListImp;

template <class T,class Alloc> class TMDoubleListBlockInitializer :
    public Alloc
{

protected:

    TMDoubleListBlockInitializer();
    ~TMDoubleListBlockInitializer();

    static unsigned Count;

};

#if defined( BI_OLDNAMES )
#define BI_DoubleListBlockInitializer TDoubleListBlockInitializer
#endif

template <class T,class Alloc>
TMDoubleListBlockInitializer<T,Alloc>::TMDoubleListBlockInitializer()
{
    PRECONDITION( Count != UINT_MAX );
    if( Count++ == 0 )
        TMDoubleListElement<T,Alloc>::Mgr = 
            new(*this)TMMemBlocks<Alloc>( sizeof(TMDoubleListElement<T,Alloc>), 20 );
}

template <class T,class Alloc>
TMDoubleListBlockInitializer<T,Alloc>::~TMDoubleListBlockInitializer()
{
    PRECONDITION( Count != 0 );
    if( --Count == 0 )
        {
        delete TMDoubleListElement<T,Alloc>::Mgr;
        TMDoubleListElement<T,Alloc>::Mgr = 0;
        }
}

template <class T,class Alloc>
unsigned TMDoubleListBlockInitializer<T,Alloc>::Count = 0;

template <class T,class Alloc> class TMDoubleListElement
{

public:

    TMDoubleListElement( const T& t, TMDoubleListElement<T,Alloc> *p ) :
        Data(t)
        {
        Next = p->Next;
        Prev = p;
        p->Next = this;
        Next->Prev = this;
        }

    TMDoubleListElement();

    TMDoubleListElement<T,Alloc> *Next;
    TMDoubleListElement<T,Alloc> *Prev;
    T Data;

    void *operator new( size_t sz );
    void operator delete( void * );

private:

    friend TMDoubleListBlockInitializer<T,Alloc>;

    static TMMemBlocks<Alloc> *Mgr;

};

#if defined( BI_OLDNAMES )
#define BI_MDoubleListElement TMDoubleListElement
#endif

template <class T,class Alloc>
TMMemBlocks<Alloc> *TMDoubleListElement<T,Alloc>::Mgr = 0;

template <class T,class Alloc>
inline TMDoubleListElement<T,Alloc>::TMDoubleListElement()
{
    Next = Prev = 0;
}

template <class T,class Alloc>
void *TMDoubleListElement<T,Alloc>::operator new( size_t sz )
{
    PRECONDITION( Mgr != 0 );
    return Mgr->Allocate( sz );
}

template <class T,class Alloc>
void TMDoubleListElement<T,Alloc>::operator delete( void *b )
{
    PRECONDITION( Mgr != 0 );
    Mgr->Free( b );
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMDoubleListImp                  */
/*                                                                        */
/*  Implements a managed double-linked list of objects of type T.         */
/*  Assumes that T has meaningful copy semantics and a default            */
/*  constructor.                                                          */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMDoubleListIteratorImp;

template <class T,class Alloc> class TMDoubleListImp :
    private TMDoubleListBlockInitializer<T,Alloc>
{

    typedef TMDoubleListBlockInitializer<T,Alloc> Parent;

public:

    typedef void (*IterFunc)(T&, void *);
    typedef int  (*CondFunc)(const T&, void *);

    friend TMDoubleListIteratorImp<T,Alloc>;

    TMDoubleListImp()
        {
        InitList();
        }

    ~TMDoubleListImp()
        {
        Flush();
        }

    const T& PeekHead() const
        {
        return Head.Next->Data;
        }

    const T& PeekTail() const
        {
        return Tail.Prev->Data;
        }

    int Add( const T& t )
        {
        return AddElement(t,&Head);
        }

    int AddAtHead( const T& t )
        {
        return AddElement(t,&Head);
        }

    int AddAtTail( const T& t )
        {
        return AddElement(t,Tail.Prev);
        }

    int Detach( const T& t )
        {
        return DoDetach(t,0);
        }

    int DetachAtHead()
        {
        return DoDetachAtHead(0);
        }

    int DetachAtTail()
        {
        return DoDetachAtTail(0);
        }

    T *Find( const T& t );

    void Flush()
        {
        DoFlush(0);
        }

    int IsEmpty() const
        {
        return ItemsInContainer == 0;
        }

    int GetItemsInContainer() const
        {
        return ItemsInContainer;
        }

    void ForEach( IterFunc iter, void *args );
    T *FirstThat( CondFunc cond, void *args ) const;
    T *LastThat( CondFunc cond, void *args ) const;

    Parent::operator delete;
    Parent::operator delete [];

#if defined( BI_OLDNAMES )
    const T& peekHead() const { return PeekHead(); }
    const T& peekTail() const { return PeekTail(); }
    void add( const T& t ) { Add(t); }
    void addAtTail( const T& t ) { AddAtTail(t); }
    void detach( const T& t, int del = 0 ) { Detach(t); }
    void flush( int = 0 ) { Flush(); }
    int isEmpty() const { return IsEmpty(); }
    int getItemsInContainer() const { return GetItemsInContainer(); }
    void forEach( IterFunc iter, void *args )
        { ForEach( iter, args ); }
    T *firstThat( CondFunc cond, void *args ) const
        { return FirstThat( cond, args ); }
    T *lastThat( CondFunc cond, void *args ) const
        { return LastThat( cond, args ); }
#endif  // BI_OLDNAMES

protected:

    int DoDetach( const T& t, int del = 0 )
        {
        return DetachElement(FindDetach(t),del);
        }

    int DoDetachAtHead( int del = 0 )
        {
        return DetachElement(&Head,del);
        }

    int DoDetachAtTail( int del = 0 )
        {
        return DetachElement(Tail.Prev->Prev,del);
        }

    void DoFlush( int del = 0 );

    TMDoubleListElement<T,Alloc> Head, Tail;

    virtual TMDoubleListElement<T,Alloc> *FindDetach( const T& t )
        {
        return FindPred(t);
        }

    virtual TMDoubleListElement<T,Alloc> *FindPred( const T& );

    int ItemsInContainer;

private:

    virtual void RemoveData( TMDoubleListElement<T,Alloc> * )
        {
        }

    void InitList();

    int DetachElement( TMDoubleListElement<T,Alloc> *element, int del = 0 );
    int AddElement( const T& t, TMDoubleListElement<T,Alloc> *element );

};

template <class T,class Alloc> void TMDoubleListImp<T,Alloc>::InitList()
{
    Head.Next = &Tail;
    Head.Prev = &Head;
    Tail.Prev = &Head;
    Tail.Next = &Tail;
    ItemsInContainer = 0;
}

template <class T,class Alloc>
int TMDoubleListImp<T,Alloc>::AddElement( const T& toAdd,
                              TMDoubleListElement<T,Alloc> *Pos )
{
    new TMDoubleListElement<T,Alloc>( toAdd, Pos );
    ItemsInContainer++;
    return 1;
}

template <class T,class Alloc>
TMDoubleListElement<T,Alloc> *TMDoubleListImp<T,Alloc>::FindPred( const T&t )
{
    Tail.Data = t;
    TMDoubleListElement<T,Alloc> *cursor = &Head;
    while( !(t == cursor->Next->Data) )
        cursor = cursor->Next;
    Tail.Data = T();
    return cursor;
}

template <class T,class Alloc>
int TMDoubleListImp<T,Alloc>::DetachElement(
        TMDoubleListElement<T,Alloc> *pred, int del )
{
    TMDoubleListElement<T,Alloc> *item = pred->Next;
    if( item == &Tail )
        return 0;
    else
        {
        pred->Next = pred->Next->Next;
        pred->Next->Prev = pred;
        if( del != 0 )
            RemoveData( item );
        delete item;
        ItemsInContainer--;
        return 1;
        }
}

template <class T,class Alloc>
T *TMDoubleListImp<T,Alloc>::Find( const T& t )
{
    TMDoubleListElement<T,Alloc> *pred = FindPred(t);
    if( pred->Next == &Tail )
        return 0;
    else
        return &pred->Next->Data;
}

template <class T,class Alloc>
void TMDoubleListImp<T,Alloc>::DoFlush( int del )
{
    TMDoubleListElement<T,Alloc> *current = Head.Next;
    while( current != &Tail )
        {
        TMDoubleListElement<T,Alloc> *temp = current;
        current = current->Next;
        if( del != 0 )
            RemoveData( temp );
        delete temp;
        }
    InitList();
}

template <class T,class Alloc>
void TMDoubleListImp<T,Alloc>::ForEach( IterFunc f, void *args
                                 )
{
    TMDoubleListElement<T,Alloc> *cur = Head.Next;
    while( cur->Next != cur )
        {
        f( cur->Data, args );
        cur = cur->Next;
        }
}

template <class T,class Alloc>
T *TMDoubleListImp<T,Alloc>::FirstThat( CondFunc cond, void *args ) const
{
    TMDoubleListElement<T,Alloc> *cur = Head.Next;
    while( cur->Next != cur )
        if( cond( cur->Data, args ) != 0 )
            return &(cur->Data);
        else
            cur = cur->Next;
    return 0;
}

template <class T,class Alloc>
T *TMDoubleListImp<T,Alloc>::LastThat( CondFunc cond, void *args ) const
{
    T *res = 0;
    TMDoubleListElement<T,Alloc> *cur = Head.Next;
    while( cur->Next != cur )
        {
        if( cond( cur->Data, args ) != 0 )
            res = &(cur->Data);
        cur = cur->Next;
        }
    return res;
}

#if defined( BI_OLDNAMES )
#define BI_MDoubleListImp TMDoubleListImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMDoubleListIteratorImp          */
/*                                                                        */
/*  Implements a double list iterator.  This iterator works with any      */
/*  direct double list.  For indirect lists, see                          */
/*  TMIDoubleListIteratorImp.                                             */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMDoubleListIteratorImp
{

public:

    TMDoubleListIteratorImp( const TMDoubleListImp<T,Alloc>& l )
        {
        List = &l;
        Cur = List->Head.Next;
        }

    TMDoubleListIteratorImp( const TMSDoubleListImp<T,Alloc>& l );

    operator int()
        {
        return Cur != &(List->Head) && Cur != &(List->Tail);
        }

    const T& Current()
        {
        PRECONDITION( int(*this) != 0 );
        return Cur->Data;
        }

    const T& operator ++ ( int )
        {
        PRECONDITION( Cur != &(List->Tail) );
        TMDoubleListElement<T,Alloc> *temp = Cur;
        Cur = Cur->Next;
        return temp->Data;
        }

    const T& operator ++ ()
        {
        PRECONDITION( Cur->Next != &(List->Tail) );
        Cur = Cur->Next;
        return Cur->Data;
        }

    const T& operator -- ( int )
        {
        PRECONDITION( Cur != &(List->Head) );
        TMDoubleListElement<T,Alloc> *temp = Cur;
        Cur = Cur->Prev;
        return temp->Data;
        }

    const T& operator -- ()
        {
        PRECONDITION( Cur->Prev != &(List->Head) );
        Cur = Cur->Prev;
        return Cur->Data;
        }

    void Restart()
        {
        Cur = List->Head.Next;
        }

    void RestartAtTail()
        {
        Cur = List->Tail.Prev;
        }

#if defined( BI_OLDNAMES )
    T current() { return Current(); }
    void restart() { Restart(); }
#endif


private:

    const TMDoubleListImp<T,Alloc> *List;
    TMDoubleListElement<T,Alloc> *Cur;

};

#if defined( BI_OLDNAMES )
#define BI_MDoubleListIteratorImp TMDoubleListIteratorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TDoubleListImp                               */
/*  template <class T> class TDoubleListIteratorImp                       */
/*                                                                        */
/*  Implements a double-linked list of objects of type T using            */
/*  TStandardAllocator as its memory manager. Assumes that T has          */
/*  meaningful copy semantics and a default constructor.                  */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TDoubleListImp :
    public TMDoubleListImp<T,TStandardAllocator>
{
};

template <class T> class TDoubleListIteratorImp :
    public TMDoubleListIteratorImp<T,TStandardAllocator>
{

public:

    TDoubleListIteratorImp( const TDoubleListImp<T>& l ) :
        TMDoubleListIteratorImp<T,TStandardAllocator>(l) {}

    TDoubleListIteratorImp( const TSDoubleListImp<T>& l ) :
        TMDoubleListIteratorImp<T,TStandardAllocator>(l) {}

};

#if defined( BI_OLDNAMES )
#define BI_DoubleListImp TDoubleListImp
#define BI_DoubleListIteratorImp TDoubleListIteratorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMSDoubleListImp                 */
/*  template <class T,class Alloc> class TMSDoubleListIteratorImp         */
/*                                                                        */
/*  Implements a managed sorted double-linked list of objects of type T.  */
/*  Assumes that T has meaningful copy semantics, a meaningful            */
/*  < operator, and a default constructor.                                */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMSDoubleListImp :
    private TMDoubleListImp<T,Alloc>
{
    typedef TMDoubleListImp<T,Alloc> Parent;

public:

    friend TMDoubleListIteratorImp<T,Alloc>;

    int Add( const T& t );

    Parent::IterFunc;
    Parent::CondFunc;
    Parent::PeekHead;
    Parent::PeekTail;
    Parent::Detach;
    Parent::Find;
    Parent::Flush;
    Parent::IsEmpty;
    Parent::GetItemsInContainer;
    Parent::ForEach;
    Parent::FirstThat;
    Parent::LastThat;
    Parent::operator delete;
    Parent::operator delete [];

#if defined( BI_OLDNAMES )
    void add( const T& t ) { Add(t); }
    Parent::peekHead;
    Parent::peekTail;
    Parent::detach;
    Parent::flush;
    Parent::isEmpty;
    Parent::getItemsInContainer;
    Parent::forEach;
    Parent::firstThat;
    Parent::lastThat;
#endif  // BI_OLDNAMES

protected:

    Parent::Head;
    Parent::Tail;
    Parent::ItemsInContainer;
    Parent::DoDetach;
    Parent::DoDetachAtHead;
    Parent::DoDetachAtTail;
    Parent::DoFlush;

    virtual TMDoubleListElement<T,Alloc> *FindDetach( const T& );
    virtual TMDoubleListElement<T,Alloc> *FindPred( const T& );

};

template <class T,class Alloc> class TMSDoubleListIteratorImp :
    public TMDoubleListIteratorImp<T,Alloc>
{

public:

    TMSDoubleListIteratorImp( const TMSDoubleListImp<T,Alloc>& l ) :
        TMDoubleListIteratorImp<T,Alloc>(l) {}

};

template <class T,class Alloc>
int TMSDoubleListImp<T,Alloc>::Add( const T& t )
{
    new TMDoubleListElement<T,Alloc>( t, FindPred(t) );
    ItemsInContainer++;
    return 1;
}

template <class T,class Alloc>
TMDoubleListElement<T,Alloc>*TMSDoubleListImp<T,Alloc>::FindDetach(const T&t)
{
    TMDoubleListElement<T,Alloc> *res = FindPred(t);
    if( res != 0 &&
        res->Next->Data == t )
        return res;
    else
        return &Tail;
}

template <class T,class Alloc>
TMDoubleListElement<T,Alloc>*TMSDoubleListImp<T,Alloc>::FindPred(const T& t)
{
    Tail.Data = t;
    TMDoubleListElement<T,Alloc> *cursor = &Head;
    while( cursor->Next->Data < t )
        cursor = cursor->Next;
    Tail.Data = T();
    return cursor;
}

// constructor for TMDoubleListIteratorImp
template <class T,class Alloc>
TMDoubleListIteratorImp<T,Alloc>::TMDoubleListIteratorImp(
    const TMSDoubleListImp<T,Alloc>& l )
{
    List = &l;
    Cur = List->Head.Next;
}

#if defined( BI_OLDNAMES )
#define BI_MSDoubleListImp TMSDoubleListImp
#define BI_MSDoubleListIteratorImp TMSDoubleListIteratorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TSDoubleListImp                              */
/*  template <class T> class TSDoubleListIteratorImp                      */
/*                                                                        */
/*  Implements a sorted double-linked list of objects of type T, using    */
/*  TStandardAllocator as its memory manager. Assumes that T has          */
/*  meaningful copy semantics, a meaningful < operator, and a default     */
/*  constructor.                                                          */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TSDoubleListImp :
    public TMSDoubleListImp<T,TStandardAllocator>
{
};

template <class T> class TSDoubleListIteratorImp :
    public TMSDoubleListIteratorImp<T,TStandardAllocator>
{

public:

    TSDoubleListIteratorImp( const TSDoubleListImp<T>& l ) :
        TMSDoubleListIteratorImp<T,TStandardAllocator>(l) {}

};

#if defined( BI_OLDNAMES )
#define BI_SDoubleListImp TSDoubleListImp
#define BI_SDoubleListIteratorImp TSDoubleListIteratorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class List,class Alloc>                             */
/*  class TMInternalIDoubleListImp                                        */
/*                                                                        */
/*  Implements a managed double-linked list of pointers to objects of     */
/*  type T. This is implemented through the form of TMDoubleListImp       */
/*  specified by List.  Since pointers always have meaningful copy        */
/*  semantics, this class can handle any type of object.                  */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class List,class Alloc> class TMInternalIDoubleListImp :
    public List
{

    typedef List Parent;

public:

    typedef void (*IterFunc)(T&, void *);
    typedef int  (*CondFunc)(const T&, void *);

    T *PeekHead() const
        {
        return STATIC_CAST(T *, STATIC_CAST(void *, Parent::PeekHead()));
        }

    T *PeekTail() const
        {
        return STATIC_CAST(T *, STATIC_CAST(void *, Parent::PeekTail()));
        }

    int Add( T *t )
        { 
        return Parent::Add( t ); 
        }

    int Detach( T *t, int del = 0 ) 
        { 
        return Parent::DoDetach( t, del ); 
        }

    int DetachAtHead( int del = 0 ) 
        { 
        return Parent::DoDetachAtHead( del ); 
        }

    int DetachAtTail( int del = 0 ) 
        { 
        return Parent::DoDetachAtTail( del ); 
        }

    T *Find( const T *t );

    void Flush( int del = 0 )
        {
        DoFlush( del );
        }

    void ForEach( IterFunc iter, void * );
    T *FirstThat( CondFunc cond, void * ) const;
    T *LastThat( CondFunc cond, void * ) const;

#if defined( BI_OLDNAMES )
    T *peekHead() const { return PeekHead(); }
    T *peekTail() const { return PeekTail(); }

    void add( T *t ) { Add(t); }
    void detach( T *t, int del = 0 ) { Detach( t, del ); }
    void forEach( IterFunc iter, void *args )
        { ForEach( iter, args ); }
    T *firstThat(  CondFunc cond, void *args ) const
        { return FirstThat( cond, args ); }
    T *lastThat( CondFunc cond, void *args ) const
        { return LastThat( cond, args ); }
#endif  // BI_OLDNAMES

protected:

    virtual TMDoubleListElement<TVoidPointer,Alloc> *FindPred( const TVoidPointer& ) = 0;

private:

    virtual void RemoveData( TMDoubleListElement<TVoidPointer,Alloc> *block )
        {
        delete STATIC_CAST(T *,STATIC_CAST(void *,block->Data));
        }

};

template <class T, class List, class Alloc>
T *TMInternalIDoubleListImp<T,List,Alloc>::Find( const T *t )
{
    TMDoubleListElement<TVoidPointer,Alloc> *pred = FindPred(t);
    if( pred->Next == &Tail )
        return 0;
    else
        return STATIC_CAST(T *,STATIC_CAST(void *,pred->Next->Data));
}

template <class T, class List, class Alloc>
void TMInternalIDoubleListImp<T,List,Alloc>::ForEach( IterFunc iter,
                                                      void *args )
{
    TMDoubleListElement<TVoidPointer,Alloc> *cur = Head.Next;
    while( cur->Next != cur )
        {
        iter( *STATIC_CAST(T *,STATIC_CAST(void *,cur->Data)), args );
        cur = cur->Next;
        }
}

template <class T, class List,class Alloc> T *
TMInternalIDoubleListImp<T,List,Alloc>::FirstThat( CondFunc cond,
                                                   void *args ) const
{
    TMDoubleListElement<TVoidPointer,Alloc> *cur = Head.Next;
    while( cur->Next != cur )
        if( cond( *STATIC_CAST(T *,STATIC_CAST(void *,cur->Data)), args ) != 0 )
            return STATIC_CAST(T *,STATIC_CAST(void *,cur->Data));
        else
            cur = cur->Next;
    return 0;
}

template <class T, class List, class Alloc> T *
TMInternalIDoubleListImp<T,List,Alloc>::LastThat( CondFunc cond,
                                                  void *args ) const
{
    T *res = 0;
    TMDoubleListElement<TVoidPointer,Alloc> *cur = Head.Next;
    while( cur->Next != cur )
        {
        if( cond( *STATIC_CAST(T *,STATIC_CAST(void *,cur->Data)), args ) != 0 )
            res = STATIC_CAST(T *,STATIC_CAST(void *,cur->Data));
        cur = cur->Next;
        }
    return res;
}

template <class T,class List,class Alloc>
class TMInternalIDoubleListIteratorImp :
    public TMDoubleListIteratorImp<TVoidPointer,Alloc>
{

    typedef TMDoubleListIteratorImp<TVoidPointer,Alloc> Parent;

public:

    TMInternalIDoubleListIteratorImp( const TMInternalIDoubleListImp<T,List,Alloc>& l ) :
        TMDoubleListIteratorImp<TVoidPointer,Alloc>(l) {}

    T *Current()
        {
        return STATIC_CAST(T *,STATIC_CAST(void *,Parent::Current()));
        }

    T *operator ++ (int)
        {
        return STATIC_CAST(T *,STATIC_CAST(void *,Parent::operator++(1)));
        }

    T *operator ++ ()
        {
        return STATIC_CAST(T *,STATIC_CAST(void *,Parent::operator++()));
        }

    T *operator -- (int)
        {
        return STATIC_CAST(T *,STATIC_CAST(void *,Parent::operator--(1)));
        }

    T *operator -- ()
        {
        return STATIC_CAST(T *,STATIC_CAST(void *,Parent::operator--()));
        }

#if defined( BI_OLDNAMES )
    T *current() { return Current(); }
#endif  // BI_OLDNAMES

};

#if defined( BI_OLDNAMES )
#define BI_MInternalIDoubleListImp TMInternalIDoubleListImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMIDoubleListImp                 */
/*  template <class T,class Alloc> class TMIDoubleListIteratorImp         */
/*                                                                        */
/*  Implements a double-linked list of pointers to objects of             */
/*  type T.  This is implemented through the template                     */
/*  TMInternalIDoubleListImp. Since pointers always have meaningful       */
/*  copy semantics, this class can handle any type of object.             */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMIDoubleListIteratorImp;

template <class T,class Alloc> class TMIDoubleListImp :
    private TMInternalIDoubleListImp<T,TMDoubleListImp<TVoidPointer,Alloc>,Alloc >
{

    typedef TMInternalIDoubleListImp<T,TMDoubleListImp<TVoidPointer,Alloc>,Alloc > Parent;

public:

    friend TMIDoubleListIteratorImp<T,Alloc>;

    Parent::IterFunc;
    Parent::CondFunc;
    Parent::PeekHead;
    Parent::PeekTail;
    Parent::Add;
    Parent::AddAtHead;
    Parent::AddAtTail;
    Parent::Detach;
    Parent::DetachAtHead;
    Parent::DetachAtTail;
    Parent::Find;
    Parent::Flush;
    Parent::IsEmpty;
    Parent::GetItemsInContainer;
    Parent::ForEach;
    Parent::FirstThat;
    Parent::LastThat;
    Parent::operator delete;
    Parent::operator delete [];

#if defined( BI_OLDNAMES )
    Parent::peekHead;
    Parent::peekTail;
    Parent::add;
    Parent::addAtTail;
    Parent::detach;
    Parent::flush;
    Parent::isEmpty;
    Parent::forEach;
    Parent::firstThat;
    Parent::lastThat;
#endif  // BI_OLDNAMES

protected:

    Parent::Head;
    Parent::Tail;
    Parent::ItemsInContainer;

    virtual TMDoubleListElement<TVoidPointer,Alloc> *FindPred(const TVoidPointer&);

};

template <class T,class Alloc> class TMIDoubleListIteratorImp :
    public TMInternalIDoubleListIteratorImp<T,TMDoubleListImp<TVoidPointer,Alloc>,Alloc>
{

public:

    TMIDoubleListIteratorImp( const TMIDoubleListImp<T,Alloc>& l ) :
        TMInternalIDoubleListIteratorImp<T,TMDoubleListImp<TVoidPointer,Alloc>,Alloc>( l ) {}

};

template <class T,class Alloc>
TMDoubleListElement<TVoidPointer,Alloc>
*TMIDoubleListImp<T,Alloc>::FindPred( const TVoidPointer& t )
{
    Tail.Data = t;
    TMDoubleListElement<TVoidPointer,Alloc> *cursor = &Head;
    while( !(*STATIC_CAST(T *,STATIC_CAST(void *,t)) ==
             *STATIC_CAST(T *,STATIC_CAST(void *,cursor->Next->Data))) )
        cursor = cursor->Next;
    Tail.Data = TVoidPointer();
    return cursor;
}

#if defined( BI_OLDNAMES )
#define BI_MIDoubleListImp TMIDoubleListImp
#define BI_MIDoubleListIteratorImp TMIDoubleListIteratorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TIDoubleListImp                              */
/*  template <class T> class TIDoubleListIteratorImp                      */
/*                                                                        */
/*  Implements a double-linked list of pointers to objects of             */
/*  type T using TStandardAllocator as its memory manager.                */
/*  This is implemented through the template                              */
/*  TMInternalIDoubleListImp. Since pointers always have meaningful       */
/*  copy semantics, this class can handle any type of object.             */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TIDoubleListImp :
    public TMIDoubleListImp<T,TStandardAllocator>
{
};

template <class T> class TIDoubleListIteratorImp :
    public TMIDoubleListIteratorImp<T,TStandardAllocator>
{

public:

    TIDoubleListIteratorImp( const TIDoubleListImp<T>& l ) :
        TMIDoubleListIteratorImp<T,TStandardAllocator>( l ) {}

};

#if defined( BI_OLDNAMES )
#define BI_IDoubleListImp TIDoubleListImp
#define BI_IDoubleListIteratorImp TIDoubleListIteratorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMISDoubleListImp                */
/*  template <class T,class Alloc> class TMISDoubleListIteratorImp        */
/*                                                                        */
/*  Implements a managed sorted double-linked list of pointers to         */
/*  objects of type T.  This is implemented through the template          */
/*  TMInternalIDoubleListImp. Since pointers always have meaningful       */
/*  copy semantics, this class can handle any type of object.             */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMISDoubleListIteratorImp;

template <class T,class Alloc> class TMISDoubleListImp :
    private TMInternalIDoubleListImp<T,TMSDoubleListImp<TVoidPointer,Alloc>,Alloc>
{

    typedef TMInternalIDoubleListImp<T, TMSDoubleListImp<TVoidPointer,Alloc>, Alloc > Parent;

public:

    friend TMISDoubleListIteratorImp<T,Alloc>;

    Parent::IterFunc;
    Parent::CondFunc;
    Parent::PeekHead;
    Parent::PeekTail;
    Parent::Add;
    Parent::Detach;
    Parent::DetachAtHead;
    Parent::DetachAtTail;
    Parent::Find;
    Parent::Flush;
    Parent::IsEmpty;
    Parent::GetItemsInContainer;
    Parent::ForEach;
    Parent::FirstThat;
    Parent::LastThat;
    Parent::operator delete;
    Parent::operator delete [];

protected:

    Parent::Head;
    Parent::Tail;
    Parent::ItemsInContainer;

    virtual TMDoubleListElement<TVoidPointer,Alloc> *FindDetach(const TVoidPointer&);
    virtual TMDoubleListElement<TVoidPointer,Alloc> *FindPred(const TVoidPointer&);

};

template <class T,class Alloc> class TMISDoubleListIteratorImp :
    public TMInternalIDoubleListIteratorImp<T,TMSDoubleListImp<TVoidPointer,Alloc>,Alloc>
{

public:

    TMISDoubleListIteratorImp( const TMISDoubleListImp<T,Alloc>& l ) :
        TMInternalIDoubleListIteratorImp<T,TMSDoubleListImp<TVoidPointer,Alloc>,Alloc>( l ) {}

};

template <class T,class Alloc>
TMDoubleListElement<TVoidPointer,Alloc>
*TMISDoubleListImp<T,Alloc>::FindDetach( const TVoidPointer& t )
{
    TMDoubleListElement<TVoidPointer,Alloc> *res = FindPred(t);
    if( res == 0 || res->Next == &Tail )
        return &Tail;
    else if(
        *STATIC_CAST(T *,STATIC_CAST(void *,res->Next->Data)) ==
        *STATIC_CAST(T *,STATIC_CAST(void *,t)) )
            return res;
    else
        return &Tail;
}

template <class T,class Alloc>
TMDoubleListElement<TVoidPointer,Alloc>
*TMISDoubleListImp<T,Alloc>::FindPred( const TVoidPointer& t )
{
    Tail.Data = t;
    TMDoubleListElement<TVoidPointer,Alloc> *cursor = &Head;
    while( *STATIC_CAST(T *,STATIC_CAST(void *,cursor->Next->Data)) <
           *STATIC_CAST(T *,STATIC_CAST(void *,t)) )
        cursor = cursor->Next;
    Tail.Data = TVoidPointer();
    return cursor;
}

#if defined( BI_OLDNAMES )
#define BI_MISDoubleListImp TMISDoubleListImp
#define BI_MISDoubleListIteratorImp TMISDoubleListIteratorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TISDoubleListImp                             */
/*  template <class T> class TISDoubleListIteratorImp                     */
/*                                                                        */
/*  Implements a managed sorted double-linked list of pointers to         */
/*  objects of type T using TStandardAllocator as its memory manager.     */
/*  This is implemented through the template                              */
/*  TMInternalIDoubleListImp. Since pointers always have meaningful       */
/*  copy semantics, this class can handle any type of object.             */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TISDoubleListImp :
    public TMISDoubleListImp<T,TStandardAllocator>
{
};

template <class T> class TISDoubleListIteratorImp :
    public TMISDoubleListIteratorImp<T,TStandardAllocator>
{

public:

    TISDoubleListIteratorImp( const TISDoubleListImp<T>& l ) :
        TMISDoubleListIteratorImp<T,TStandardAllocator>( l ) {}

};

#if defined( BI_OLDNAMES )
#define BI_ISDoubleListImp TISDoubleListImp
#define BI_ISDoubleListIteratorImp TISDoubleListIteratorImp
#endif

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#pragma option -Vo.

#endif  // CLASSLIB_DLISTIMP_H

