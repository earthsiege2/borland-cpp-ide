//----------------------------------------------------------------------------
// Borland BIDS Container Library
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.7  $
//
//----------------------------------------------------------------------------
#if !defined( CLASSLIB_LISTIMP_H )
#define CLASSLIB_LISTIMP_H

#if !defined(CLASSLIB_DEFS_H)
# include <classlib/defs.h>
#endif
#if !defined(CLASSLIB_MEMMGR_H)
# include <classlib/memmgr.h>
#endif
#if !defined(CLASSLIB_ALLOCTR_H)
# include <classlib/alloctr.h>
#endif
#if !defined(CLASSLIB_VOIDP_H)
# include <classlib/voidp.h>
#endif
#if !defined(SERVICES_CHECKS_H)
# include <services/checks.h>
#endif
#if !defined(CLASSLIB_RESOURCE_H)
# include <classlib/resource.h>
#endif

#if !defined(__LIMITS_H) && !defined(_INC_LIMITS)
# include <limits.h>
#endif

#pragma option -Vo-
#if defined( BI_CLASSLIB_NO_po )
# pragma option -po-
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TMListElement                                */
/*                                                                        */
/*  Node for templates TMListImp<T,Alloc> and TMIListImp<T,Alloc>         */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMListImp;
template <class T,class Alloc> class TMSListImp;
template <class T,class Alloc> class TMListElement;
template <class T,class Alloc> class TMIListIteratorImp;
template <class T,class Alloc> class TMISListIteratorImp;

template <class T,class Alloc> class TMListBlockInitializer :
    public Alloc
{

protected:

    TMListBlockInitializer();
    ~TMListBlockInitializer();

    static unsigned Count;

};

#if defined( BI_OLDNAMES )
#define BI_MListBlockInitializer TMListBlockInitializer
#endif

template <class T,class Alloc>
TMListBlockInitializer<T,Alloc>::TMListBlockInitializer()
{
    PRECONDITION( Count != UINT_MAX );
    if( Count++ == 0 )
        TMListElement<T,Alloc>::Mgr =
            new(*this)TMMemBlocks<Alloc>( sizeof(TMListElement<T,Alloc>), 20 );
}

template <class T,class Alloc>
TMListBlockInitializer<T,Alloc>::~TMListBlockInitializer()
{
    PRECONDITION( Count != 0 );
    if( --Count == 0 )
        {
        delete TMListElement<T,Alloc>::Mgr;
        TMListElement<T,Alloc>::Mgr = 0;
        }
}

template <class T,class Alloc>
unsigned TMListBlockInitializer<T,Alloc>::Count = 0;

template <class T,class Alloc> class TMListElement
{

public:

    TMListElement( const T& t, TMListElement<T,Alloc> *p ) :
        Data(t)
        {
        Next = p->Next;
        p->Next = this;
        }

    TMListElement();

    TMListElement<T,Alloc> *Next;
    T Data;

    void *operator new( size_t sz );
    void operator delete( void * );

private:

    friend TMListBlockInitializer<T,Alloc>;

    static TMMemBlocks<Alloc> *Mgr;

};

#if defined( BI_OLDNAMES )
#define BI_MListElement TMListElement
#endif

template <class T,class Alloc> TMMemBlocks<Alloc> *TMListElement<T,Alloc>::Mgr = 0;

template <class T,class Alloc>
inline TMListElement<T,Alloc>::TMListElement()
{
    Next = 0;
}

template <class T,class Alloc>
void *TMListElement<T,Alloc>::operator new( size_t sz )
{
    PRECONDITION( Mgr != 0 );
    return Mgr->Allocate( sz );
}

template <class T,class Alloc>
void TMListElement<T,Alloc>::operator delete( void *b )
{
    PRECONDITION( Mgr != 0 );
    Mgr->Free( b );
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMListImp                        */
/*                                                                        */
/*  Implements a managed list of objects of type T.  Assumes that         */
/*  T has meaningful copy semantics and a default constructor.            */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMListIteratorImp;
template <class T,class Alloc> class TMSListIteratorImp;

template <class T,class Alloc> class TMListImp :
    private TMListBlockInitializer<T,Alloc>
{

    typedef TMListBlockInitializer<T,Alloc> Parent;

public:

    typedef void (*IterFunc)(T &, void *);
    typedef int  (*CondFunc)(const T &, void *);

    friend TMListIteratorImp<T,Alloc>;

    TMListImp()
        {
        InitList();
        }

    ~TMListImp()
        {
        Flush();
        }

    const T& PeekHead() const
        {
        return Head.Next->Data;
        }

    int Add( const T& t );

    int Detach( const T& t )
        {
        return DoDetach( t, 0 );
        }

    int DetachAtHead()
        {
        return DoDetachAtHead(0);
        }

    T *Find( const T& t );

    void Flush()
        {
        DoFlush();
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
#if !defined(BI_NO_ARRAYNEW)
    Parent::operator delete [];
#endif

#if defined( BI_OLDNAMES )
    const T& peekHead() const { return PeekHead(); }
    void add( const T& t ) { Add(t); }
    void detach( const T& t, int del = 0 ) { DoDetach( t, del ); }
    void flush( int = 0 ) { Flush(); }
    int isEmpty() const { return IsEmpty(); }
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

    void DoFlush( int del = 0 );

    TMListElement<T,Alloc> Head, Tail;

    virtual TMListElement<T,Alloc> *FindDetach( const T& t )
        {
        return FindPred(t);
        }

    virtual TMListElement<T,Alloc> *FindPred( const T& );

    int ItemsInContainer;

private:

    virtual void RemoveData( TMListElement<T,Alloc> * )
        {
        }

    void InitList();

    int DetachElement( TMListElement<T,Alloc> *pred, int del = 0 );

};

#if defined( BI_OLDNAMES )
#define BI_MListImp TMListImp
#endif

template <class T,class Alloc> void TMListImp<T,Alloc>::InitList()
{
    Head.Next = &Tail;
    Tail.Next = &Tail;
    ItemsInContainer = 0;
}

template <class T,class Alloc> int TMListImp<T,Alloc>::Add( const T& toAdd )
{
    new TMListElement<T,Alloc>( toAdd, &Head );
    ItemsInContainer++;
    return 1;
}

template <class T,class Alloc>
TMListElement<T,Alloc> *TMListImp<T,Alloc>::FindPred( const T& t )
{
    Tail.Data = t;
    TMListElement<T,Alloc> *cursor = &Head;
    while( !(t == cursor->Next->Data) )
        cursor = cursor->Next;
    Tail.Data = T();
    return cursor;
}

template <class T,class Alloc>
int TMListImp<T,Alloc>::DetachElement( TMListElement<T,Alloc> *pred,
                                       int del )
{
    TMListElement<T,Alloc> *item = pred->Next;
    if( item == &Tail )
        return 0;
    else
        {
        pred->Next = pred->Next->Next;
        if( del != 0 )
            RemoveData( item );
        delete item;
        ItemsInContainer--;
        return 1;
        }
}

template <class T,class Alloc> T *TMListImp<T,Alloc>::Find( const T& t )
{
    TMListElement<T,Alloc> *cursor = FindPred(t)->Next;
    if( cursor == &Tail )
        return 0;
    else
        return &cursor->Data;
}

template <class T,class Alloc> void TMListImp<T,Alloc>::DoFlush( int del )
{
    TMListElement<T,Alloc> *current = Head.Next;
    while( current != &Tail )
        {
        TMListElement<T,Alloc> *temp = current;
        current = current->Next;
        if( del != 0 )
            RemoveData( temp );
        delete temp;
        }
    InitList();
}

template <class T,class Alloc>
void TMListImp<T,Alloc>::ForEach( IterFunc iter, void *args )
{
    TMListElement<T,Alloc> *cur = Head.Next;
    while( cur->Next != cur )
        {
        iter( cur->Data, args );
        cur = cur->Next;
        }
}

template <class T,class Alloc>
T *TMListImp<T,Alloc>::FirstThat( CondFunc cond, void *args ) const
{
    TMListElement<T,Alloc> *cur = Head.Next;
    while( cur->Next != cur )
        if( cond( cur->Data, args ) != 0 )
            return &(cur->Data);
        else
            cur = cur->Next;
    return 0;
}

template <class T,class Alloc>
T *TMListImp<T,Alloc>::LastThat( CondFunc cond, void *args ) const
{
    T *res = 0;
    TMListElement<T,Alloc> *cur = Head.Next;
    while( cur->Next != cur )
        {
        if( cond( cur->Data, args ) != 0 )
            res = &(cur->Data);
        cur = cur->Next;
        }
    return res;
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMListIteratorImp                */
/*                                                                        */
/*  Implements a list iterator.  This iterator works with any direct      */
/*  managed list.  For indirect lists, see TMIListIteratorImp.            */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMListIteratorImp
{

public:

    TMListIteratorImp( const TMListImp<T,Alloc>& l )
        {
        List = &l;
        Cur = List->Head.Next;
        }

    operator int()
        {
        return Cur != &(List->Tail);
        }

    const T& Current()
        {
        PRECONDITION( int(*this) != 0 );
        return Cur->Data;
        }

    const T& operator ++ ( int )
        {
        PRECONDITION( Cur != &(List->Tail) );
        TMListElement<T,Alloc> *temp = Cur;
        Cur = Cur->Next;
        return temp->Data;
        }

    const T& operator ++ ()
        {
        PRECONDITION( Cur->Next != &(List->Tail) );
        Cur = Cur->Next;
        return Cur->Data;
        }

    void Restart()
        {
        Cur = List->Head.Next;
        }

#if defined( BI_OLDNAMES )
    const T& current() { return Current(); }
    void restart() { Restart(); }
#endif  // BI_OLDNAMES

private:

    const TMListImp<T,Alloc> *List;
    TMListElement<T,Alloc> *Cur;

};

#if defined( BI_OLDNAMES )
#define BI_MListIteratorImp TMListIteratorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TListImp                                     */
/*  template <class T> class TListIteratorImp                             */
/*                                                                        */
/*  Implements a list of objects of type T using TStandardAllocator as    */
/*  its memory manager.  Assumes that T has meaningful copy semantics     */
/*  and a default constructor.                                            */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TListImp :
    public TMListImp<T,TStandardAllocator>
{
};

template <class T> class TListIteratorImp :
    public TMListIteratorImp<T,TStandardAllocator>
{

public:

    TListIteratorImp( const TMListImp<T,TStandardAllocator>& l ) :
        TMListIteratorImp<T,TStandardAllocator>( l ) {}

};

#if defined( BI_OLDNAMES )
#define BI_ListImp TListImp
#define BI_ListIteratorImp TListIteratorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMSListImp                       */
/*                                                                        */
/*  Implements a managed, sorted list of objects of type T.  Assumes that */
/*  T has meaningful copy semantics, a meaningful < operator, and a       */
/*  default constructor.                                                  */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMSListImp :
    public TMListImp<T,Alloc>
{

    typedef TMListImp<T,Alloc> Parent;

public:

    friend TMListIteratorImp<T,Alloc>;

    int Add( const T& t );

#if !defined(BI_COMP_MSC)
    Parent::IterFunc;
    Parent::CondFunc;
#endif
    Parent::PeekHead;
    Parent::Detach;
    Parent::DetachAtHead;
    Parent::Find;
    Parent::Flush;
    Parent::IsEmpty;
    Parent::GetItemsInContainer;
    Parent::ForEach;
    Parent::FirstThat;
    Parent::LastThat;
    Parent::operator delete;
#if !defined(BI_NO_ARRAYNEW)
    Parent::operator delete [];
#endif

#if defined( BI_OLDNAMES )
    void add( const T& t ) { Add(t); }
#endif  // BI_OLDNAMES

protected:

    Parent::Head;
    Parent::Tail;
    Parent::ItemsInContainer;
    Parent::DoDetach;
    Parent::DoDetachAtHead;
    Parent::DoFlush;

    virtual TMListElement<T,Alloc> *FindDetach( const T& t );
    virtual TMListElement<T,Alloc> *FindPred( const T& );

};

template <class T,class Alloc> class TMSListIteratorImp :
    public TMListIteratorImp<T,Alloc>
{

public:

    TMSListIteratorImp( const TMSListImp<T,Alloc>& l ) :
        TMListIteratorImp<T,Alloc>( l ) {}

};

#if defined( BI_OLDNAMES )
#define BI_MSListImp TMSListImp
#define BI_MSListIteratorImp TMSListIteratorImp
#endif

template <class T,class Alloc> int TMSListImp<T,Alloc>::Add( const T& t )
{
    new TMListElement<T,Alloc>( t, FindPred(t) );
    ItemsInContainer++;
    return 1;
}

template <class T,class Alloc>
TMListElement<T,Alloc> *TMSListImp<T,Alloc>::FindDetach( const T& t )
{
    TMListElement<T,Alloc> *res = FindPred(t);
    if( res != 0 &&
        res->Next->Data == t )
        return res;
    else
        return &Tail;
}

template <class T,class Alloc>
TMListElement<T,Alloc> *TMSListImp<T,Alloc>::FindPred( const T& t )
{
    Tail.Data = t;
    TMListElement<T,Alloc> *cursor = &Head;
    while( cursor->Next->Data < t )
        cursor = cursor->Next;
    return cursor;
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TSListImp                                    */
/*  template <class T> class TSListIteratorImp                            */
/*                                                                        */
/*  Implements a sorted list of objects of type T using                   */
/*  TStandardAllocator as its memory manager.  Assumes that               */
/*  T has meaningful copy semantics, a meaningful < operator, and a       */
/*  default constructor.                                                  */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TSListImp :
    public TMSListImp<T,TStandardAllocator>
{
};

template <class T> class TSListIteratorImp :
    public TMSListIteratorImp<T,TStandardAllocator>
{

public:

    TSListIteratorImp( const TSListImp<T>& l ) :
        TMSListIteratorImp<T,TStandardAllocator>( l ) {}

};

#if defined( BI_OLDNAMES )
#define BI_SListImp TSListImp
#define BI_SListIteratorImp TSListIteratorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class List,class Alloc> class TMInternalIListImp    */
/*                                                                        */
/*  Implements a managed list of pointers to objects of type T.           */
/*  This is implemented through the form of TMListImp specified by List.  */
/*  Since pointers always have meaningful copy semantics, this class      */
/*  can handle any type of object.                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class List,class Alloc> class TMInternalIListImp :
    public List
{

    typedef List Parent;

public:

    typedef void (*IterFunc)(T&, void *);
    typedef int  (*CondFunc)(const T&, void *);

    T *PeekHead() const
        {
        return STATIC_CAST(T *,STATIC_CAST(void *,Parent::PeekHead()));
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

    void Flush( int del = 0 )
        {
        Parent::DoFlush(del);
        }

    T *Find( const T *t );

    void ForEach( IterFunc iter, void * );
    T *FirstThat( CondFunc cond, void * ) const;
    T *LastThat( CondFunc cond, void * ) const;

#if defined( BI_OLDNAMES )
    T *peekHead() const { return PeekHead(); }
    void add( T *t ) { Add(t); }
    void detach( T *t, int del = 0 ) { Detach( t, del ); }
    void forEach( IterFunc iter, void *args )
        { ForEach( iter, args ); }
    T *firstThat( CondFunc cond, void *args ) const
        { return FirstThat( cond, args ); }
    T *lastThat( CondFunc cond, void *args ) const
        { return LastThat( cond, args ); }
#endif  // BI_OLDNAMES

protected:

    virtual TMListElement<TVoidPointer,Alloc> *
                          FindPred( const TVoidPointer& ) = 0;

private:

    virtual void RemoveData( TMListElement<TVoidPointer,Alloc> *block )
        {
        delete STATIC_CAST(T *,STATIC_CAST(void *,block->Data));
        }
};

#if defined( BI_OLDNAMES )
#define BI_MInternalIListImp TMInternalIListImp
#endif

template <class T,class List,class Alloc>
T *TMInternalIListImp<T,List,Alloc>::Find( const T *t )
{
    TMListElement<TVoidPointer,Alloc> *cur = Head.Next;
    Tail.Data = t;
    while( !(*STATIC_CAST(T *,STATIC_CAST(void *,cur->Data)) == *t) )
        cur = cur->Next;
    Tail.Data = TVoidPointer();
    if( cur == &Tail )
        return 0;
    else
        return STATIC_CAST(T *,STATIC_CAST(void *,cur->Data));
}

template <class T,class List,class Alloc>
void TMInternalIListImp<T,List,Alloc>::ForEach( IterFunc iter,
                                                void *args )
{
    TMListElement<TVoidPointer,Alloc> *cur = Head.Next;
    while( cur->Next != cur )
        {
        iter( *STATIC_CAST(T *,STATIC_CAST(void *,cur->Data)), args );
        cur = cur->Next;
        }
}

template <class T,class List,class Alloc>
T *TMInternalIListImp<T,List,Alloc>::FirstThat( CondFunc cond,
                                                void *args ) const
{
    TMListElement<TVoidPointer,Alloc> *cur = Head.Next;
    while( cur->Next != cur )
        if( cond( *STATIC_CAST(T *,STATIC_CAST(void *,cur->Data)), args ) != 0 )
            return STATIC_CAST(T *,STATIC_CAST(void *,cur->Data));
        else
            cur = cur->Next;
    return 0;
}

template <class T,class List,class Alloc>
T *TMInternalIListImp<T,List,Alloc>::LastThat( CondFunc cond,
                                               void *args ) const
{
    T *res = 0;
    TMListElement<TVoidPointer,Alloc> *cur = Head.Next;
    while( cur->Next != cur )
        {
        if( cond( *STATIC_CAST(T *,STATIC_CAST(void *,cur->Data)), args ) != 0 )
            res = STATIC_CAST(T *,STATIC_CAST(void *,cur->Data));
        cur = cur->Next;
        }
    return res;
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMIListImp                       */
/*  template <class T,class Alloc> class TMIListIteratorImp               */
/*                                                                        */
/*  Implements a managed list of pointers to objects of type T.           */
/*  This is implemented through the template TMInternalIListImp.  Since   */
/*  pointers always have meaningful copy semantics, this class            */
/*  can handle any type of object.                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMIListImp :
    public TMInternalIListImp<T, TMListImp<TVoidPointer,Alloc>, Alloc >
{

    typedef TMInternalIListImp<T, TMListImp<TVoidPointer,Alloc>, Alloc > Parent;

public:

    void Flush( int del = 0 )
        {
        Parent::DoFlush(del);
        }

#if !defined(BI_COMP_MSC)
    Parent::IterFunc;
    Parent::CondFunc;
#endif
    Parent::PeekHead;
    Parent::Add;
    Parent::Detach;
    Parent::DetachAtHead;
    Parent::Find;
    Parent::IsEmpty;
    Parent::GetItemsInContainer;
    Parent::ForEach;
    Parent::FirstThat;
    Parent::LastThat;
    Parent::operator delete;
#if !defined(BI_NO_ARRAYNEW)
    Parent::operator delete [];
#endif

protected:

    Parent::Head;
    Parent::Tail;
    Parent::ItemsInContainer;

    virtual TMListElement<TVoidPointer,Alloc> *FindPred( const TVoidPointer& );

};

template <class T,class Alloc> class TMIListIteratorImp :
    public TMListIteratorImp<TVoidPointer,Alloc>
{

    typedef TMListIteratorImp<TVoidPointer,Alloc> Parent;
    typedef TMInternalIListImp<T,TMListImp<TVoidPointer,Alloc>,Alloc> ListBase;

public:

    TMIListIteratorImp( const TMIListImp<T,Alloc>& l ) :
        TMListIteratorImp<TVoidPointer,Alloc>(
            STATIC_CAST(const ListBase&,l) ) {}

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

    Parent::Restart;
    Parent::operator int;

#if defined( BI_OLDNAMES )
    T *current() { return Current(); }
    void restart() { Restart(); }
#endif  // BI_OLDNAMES

};

template <class T,class Alloc>
TMListElement<TVoidPointer,Alloc> *
    TMIListImp<T,Alloc>::FindPred( const TVoidPointer& t )
{
    Tail.Data = t;
    TMListElement<TVoidPointer,Alloc> *cursor = &Head;
    while( !(*STATIC_CAST(T *,STATIC_CAST(void *,t)) ==
             *STATIC_CAST(T *,STATIC_CAST(void *,cursor->Next->Data)) ))
        cursor = cursor->Next;
    Tail.Data = TVoidPointer();
    return cursor;
}

#if defined( BI_OLDNAMES )
#define BI_MIListImp TMIListImp
#define BI_MIListIteratorImp TMIListIteratorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TIListImp                                    */
/*  template <class T> class TIListIteratorImp                            */
/*                                                                        */
/*  Implements a list of pointers to objects of type T using              */
/*  TStandardAllocator as its memory manager. This is implemented         */
/*  through the template TMInternalIListImp.  Since                       */
/*  pointers always have meaningful copy semantics, this class            */
/*  can handle any type of object.                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TIListImp :
    public TMIListImp<T,TStandardAllocator>
{
};

template <class T> class TIListIteratorImp :
    public TMIListIteratorImp<T,TStandardAllocator>
{

public:

    TIListIteratorImp( const TIListImp<T>& l ) :
        TMIListIteratorImp<T,TStandardAllocator>( l ) {}

};

#if defined( BI_OLDNAMES )
#define BI_IListImp TIListImp
#define BI_IListIteratorImp TIListIteratorImp
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMISListImp                      */
/*  template <class T,class Alloc> class TMISListIteratorImp              */
/*                                                                        */
/*  Implements a managed sorted list of pointers to objects of type T.    */
/*  This is implemented through the template TInternalIListImp.  Since    */
/*  pointers always have meaningful copy semantics, this class            */
/*  can handle any type of object.                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMISListImp :
    public TMInternalIListImp<T, TMSListImp<TVoidPointer,Alloc>, Alloc >
{

    typedef TMInternalIListImp<T, TMSListImp<TVoidPointer,Alloc>, Alloc > Parent;

public:

    Parent::IterFunc;
    Parent::CondFunc;
    Parent::PeekHead;
    Parent::Add;
    Parent::Detach;
    Parent::DetachAtHead;
    Parent::Find;
    Parent::Flush;
    Parent::IsEmpty;
    Parent::GetItemsInContainer;
    Parent::ForEach;
    Parent::FirstThat;
    Parent::LastThat;
    Parent::operator delete;
#if !defined(BI_NO_ARRAYNEW)
    Parent::operator delete [];
#endif

protected:

    Parent::Head;
    Parent::Tail;
    Parent::ItemsInContainer;

    virtual TMListElement<TVoidPointer,Alloc> *FindDetach( const TVoidPointer& );
    virtual TMListElement<TVoidPointer,Alloc> *FindPred( const TVoidPointer& );

};

template <class T,class Alloc> class TMISListIteratorImp :
    public TMListIteratorImp<TVoidPointer,Alloc>
{

    typedef TMListIteratorImp<TVoidPointer,Alloc> Parent;
    typedef TMInternalIListImp<T,TMSListImp<TVoidPointer,Alloc>,Alloc> ListBase1;
    typedef TMSListImp<TVoidPointer,Alloc> ListBase2;

public:

    TMISListIteratorImp( const TMISListImp<T,Alloc>& l ) :
        TMListIteratorImp<TVoidPointer,Alloc>(
            STATIC_CAST(const ListBase2&, STATIC_CAST(const ListBase1&,l)) ) {}

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

    Parent::Restart;
    Parent::operator int;

#if defined( BI_OLDNAMES )
    T *current() { return Current(); }
#endif  // BI_OLDNAMES

};

#if defined( BI_OLDNAMES )
#define BI_MISListImp TMISListImp
#define BI_MISListIteratorImp TMISListIteratorImp
#endif

template <class T,class Alloc>
TMListElement<TVoidPointer,Alloc> *
    TMISListImp<T,Alloc>::FindDetach( const TVoidPointer& t )
{
    TMListElement<TVoidPointer,Alloc> *res = FindPred(t);
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
TMListElement<TVoidPointer,Alloc> *
    TMISListImp<T,Alloc>::FindPred( const TVoidPointer& t )
{
    Tail.Data = t;
    TMListElement<TVoidPointer,Alloc> *cursor = &Head;
    while( *STATIC_CAST(T *,STATIC_CAST(void *,cursor->Next->Data)) <
           *STATIC_CAST(T *,STATIC_CAST(void *,t)) )
        cursor = cursor->Next;
    Tail.Data = TVoidPointer();
    return cursor;
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TISListImp                                   */
/*  template <class T> class TISListIteratorImp                           */
/*                                                                        */
/*  Implements a sorted list of pointers to objects of type T using       */
/*  TStandardAllocator as its memory manager.                             */
/*  This is implemented through the template TInternalIListImp.  Since    */
/*  pointers always have meaningful copy semantics, this class            */
/*  can handle any type of object.                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TISListImp :
    public TMISListImp<T,TStandardAllocator>
{
};

template <class T> class TISListIteratorImp :
    public TMISListIteratorImp<T,TStandardAllocator>
{

public:

    TISListIteratorImp( const TISListImp<T>& l ) :
        TMISListIteratorImp<T,TStandardAllocator>( l ) {}

};

#if defined( BI_OLDNAMES )
# define BI_ISListImp TISListImp
#endif

#if defined( BI_CLASSLIB_NO_po )
# pragma option -po.
#endif

#pragma option -Vo.

#endif  // CLASSLIB_LISTIMP_H
