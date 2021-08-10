/*------------------------------------------------------------------------*/
/*                                                                        */
/*  HASHIMP.H                                                             */
/*                                                                        */
/*  Copyright (c) 1991, 1993 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*  Note: Hash tables can determine the hash value of an object by        */
/*  calling a member function or global function named HashValue().       */
/*                                                                        */
/*  For member functions, the following prototype should be used:         */
/*                                                                        */
/*      unsigned HashValue() const;                                       */
/*                                                                        */
/*  For global functions, then following prototype should be used:        */
/*                                                                        */
/*      unsigned HashValue( const T& t );                                 */
/*                                                                        */
/*  If the global function is used, the member function does not need to  */
/*  be defined.                                                           */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __CLASSLIB_HASHIMP_H )
#define __CLASSLIB_HASHIMP_H

#if !defined( __CHECKS_H )
#include <checks.h>
#endif  // __CHECKS_H

#if !defined( __CLASSLIB_DEFS_H )
#include "classlib\defs.h"
#endif  // __CLASSLIB_DEFS_H

#if !defined( __CLASSLIB_LISTIMP_H )
#include "classlib\listimp.h"
#endif  // __CLASSLIB_LISTIMP_H

#if !defined( __CLASSLIB_VECTIMP_H )
#include "classlib\vectimp.h"
#endif  // __CLASSLIB_VECTIMP_H

#pragma option -Vo-
#if defined( BI_CLASSLIB_NO_po )
#pragma option -po-
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> unsigned HashValue( T & t )                        */
/*                     unsigned HashValue( void *& )                      */
/*                                                                        */
/*  Template function which calls the HashValue() member function for     */
/*  an object of type T.  The (void *) non-template function is           */
/*  defined so that indirect container templates will compile. It         */
/*  should never be called.                                               */
/*                                                                        */
/*------------------------------------------------------------------------*/

inline unsigned HashValue( void *& t )
{
    return unsigned(t);
}

inline unsigned HashValue( const TVoidPointer& t )
{
    return unsigned(STATIC_CAST(void *,t));
}

template <class T> inline unsigned HashValue( const T& t )
{
    return t.HashValue();
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc,class List> class TMInternalHashImp     */
/*                                                                        */
/*  Used internally.                                                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc,class List>
    class TMInternalHashTableIteratorImp;

template <class T,class Alloc,class List> class TMInternalHashImp :
    public Alloc
{

public:

    friend TMInternalHashTableIteratorImp<T,Alloc,List>;

    TMInternalHashImp( unsigned size ) :
        Table(size),
        Size(size),
        ItemsInContainer(0)
        {
        }

    unsigned GetItemsInContainer() const
        {
        return ItemsInContainer;
        }

    int IsEmpty() const
        {
        return ItemsInContainer == 0;
        }

protected:

    unsigned TableSize() const
        {
        return Size;
        }

    unsigned ItemsInContainer;
    TMIVectorImp<List,Alloc> Table;

private:

    virtual unsigned GetHashValue( const T& t ) const = 0;

    unsigned Size;

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc,class List>                             */
/*      class TMInternalHashTableIteratorImp                              */
/*                                                                        */
/*  Used internally.                                                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc,class List>
class TMInternalHashTableIteratorImp :
    public Alloc
{

public:

    TMInternalHashTableIteratorImp( const TMInternalHashImp<T,Alloc,List>& h ) :
        HashIter(h.Table),
        ListIter(0)
        {
        Restart();
        }
        
    ~TMInternalHashTableIteratorImp()
        {
        delete ListIter;
        }
        
    operator int()
        {
        return HashIter;
        }
        
    const T& Current()
        {
        PRECONDITION( ListIter != 0 );
        return ListIter->Current();
        }
        
    const T& operator ++ ( int )
        {
        PRECONDITION( ListIter != 0 );
        const T& t = ListIter->Current();
        Scan();
        return t;
        }
        
    T operator ++ ()
        {
        PRECONDITION( ListIter != 0 );
        Scan();
        PRECONDITION( ListIter != 0 );
        return ListIter->Current();
        }
        
    void Restart();
        
private:

    TMIVectorIteratorImp<List,Alloc> HashIter;
    TMListIteratorImp<T,Alloc> *ListIter;
    
    void Scan();
};

template <class T,class Alloc,class List>
void TMInternalHashTableIteratorImp<T,Alloc,List>::Restart()
{
    HashIter.Restart();
        
    delete ListIter;
    while( HashIter && HashIter.Current() == 0 )
        HashIter++;
    ListIter = HashIter ?
        new(*this)TMListIteratorImp<T,Alloc>( *HashIter.Current() ) : 0;
}

template <class T,class Alloc,class List>
void TMInternalHashTableIteratorImp<T,Alloc,List>::Scan()
{
    // if not at end of list, then iterate to the next item
    if( *ListIter )
        (*ListIter)++;

    // if now at end of list, then iterate to the next list (if any)
    if( ! *ListIter )
        {
        HashIter++;
        delete ListIter;

        while( HashIter != 0 && HashIter.Current() == 0 )
            HashIter++;
        if( HashIter == 0 )
            ListIter = 0;
        else
            ListIter =
                new(*this)TMListIteratorImp<T,Alloc>( *HashIter.Current() );
        }
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMHashTableImp                   */
/*  template <class T,class Alloc> class TMHashTableIteratorImp           */
/*                                                                        */
/*  Implements a managed hash table of objects of type T, using storage   */
/*  storage allocator A.  Assumes that T has meaningful copy and ==       */
/*  semantics as well as a default constructor.                           */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMHashTableIteratorImp;

template <class T,class Alloc> class TMHashTableImp :
    private TMInternalHashImp< T,Alloc,TMListImp<T,Alloc> >
{

    typedef TMInternalHashImp< T,Alloc,TMListImp<T,Alloc> > Parent;

public:

    friend TMHashTableIteratorImp<T,Alloc>;

    typedef void (*IterFunc)(T&, void *);

    int Add( const T& t );
    int Detach( const T& t );

    TMHashTableImp( unsigned size = DEFAULT_HASH_TABLE_SIZE ) :
        TMInternalHashImp< T,Alloc,TMListImp<T,Alloc> >(size)
        {
        }
        
    void ForEach( IterFunc iter, void *args );
    T *Find( const T& t ) const;
    void Flush();

    Parent::GetItemsInContainer;
    Parent::IsEmpty;
    Parent::operator delete;
    Parent::operator delete [];

private:

    unsigned GetHashValue( const T& t ) const
        {
        return HashValue(t) % TableSize();
        }

};

template <class T,class Alloc> class TMHashTableIteratorImp :
    public TMInternalHashTableIteratorImp<T,Alloc,TMListImp<T,Alloc> >
{

public:
    TMHashTableIteratorImp( const TMHashTableImp<T,Alloc>& h ) :
        TMInternalHashTableIteratorImp<T,Alloc,TMListImp<T,Alloc> >(h) {}
    
};

template <class T,class Alloc>
int TMHashTableImp<T,Alloc>::Add( const T& t )
{
    unsigned index = GetHashValue(t);
    TMListImp<T,Alloc> *list = Table[index];
    if( list == 0 )
        {
        list = Table[index] = new(*this)TMListImp<T,Alloc>;
        }
    if( list == 0 )
        return 0;
    else 
        {
        list->Add(t);
        ItemsInContainer++;
        return 1;
        }
}

template <class T,class Alloc>
int TMHashTableImp<T,Alloc>::Detach( const T& t )
{
    unsigned index = GetHashValue(t);
    TMListImp<T,Alloc> *list = Table[index];
    if( list == 0 || ! list->Detach(t) )
        return 0;
    else
        {
        if( list->IsEmpty() )
            {
            delete Table[index];
            Table[index] = 0;
            }
        ItemsInContainer--;
        return 1;
        }
}

template <class T,class Alloc>
void TMHashTableImp<T,Alloc>::ForEach( IterFunc iter, void *args )
{
    TMIVectorIteratorImp<TMListImp<T,Alloc>,Alloc> iterator(Table);
    while( iterator )
        {
        TMListImp<T,Alloc> *list = iterator++;
        if( list != 0 )
            list->ForEach(iter,args);
        }
}

template <class T,class Alloc>
T *TMHashTableImp<T,Alloc>::Find( const T& t ) const
{
    TMListImp<T,Alloc> *list = Table[GetHashValue(t)];
    return list ? list->Find(t) : 0;
}

template <class T,class Alloc> void TMHashTableImp<T,Alloc>::Flush()
{
    for( unsigned i = 0; i < TableSize(); i++ )
        {
        if( Table[i] != 0 )
            {
            Table[i]->Flush();
            delete Table[i];
            Table[i] = 0;
            }
        }
    ItemsInContainer = 0;
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class THashTableImp                                */
/*  template <class T> class THashTableIteratorImp                        */
/*                                                                        */
/*  Implements a hash table of objects of type T.                         */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class THashTableIteratorImp;

template <class T> class THashTableImp :
    public TMHashTableImp<T,TStandardAllocator>
{
public:

    friend THashTableIteratorImp<T>;

    THashTableImp( unsigned aPrime = DEFAULT_HASH_TABLE_SIZE ) :
        TMHashTableImp<T,TStandardAllocator>(aPrime)
        {
        }
};

template <class T> class THashTableIteratorImp :
    public TMHashTableIteratorImp<T,TStandardAllocator>
{
public:

    THashTableIteratorImp( const THashTableImp<T>& h ) :
        TMHashTableIteratorImp<T,TStandardAllocator>(h)
        {
        }
};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMIHashTableImp                  */
/*  template <class T,class Alloc> class TMIHashTableIteratorImp          */
/*                                                                        */
/*  Implements a managed hash table of pointers to objects of type T,     */
/*  using the storage storage allocator A.                                */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class Alloc> class TMIHashTableIteratorImp;

template <class T,class Alloc> class TMIHashTableImp :
    private TMInternalHashImp<TVoidPointer,Alloc,TMIListImp<T,Alloc> >
{

    typedef TMInternalHashImp<TVoidPointer,Alloc,TMIListImp<T,Alloc> > Parent;

public:

    friend TMIHashTableIteratorImp<T,Alloc>;

    typedef void (*IterFunc)(T&, void *);

    TMIHashTableImp( unsigned size = DEFAULT_HASH_TABLE_SIZE ) :
        TMInternalHashImp<TVoidPointer,Alloc,TMIListImp<T,Alloc> >(size)
        {
        }

    int Add( T *t );
    int Detach( T *t, int del = 0 );

    void ForEach( IterFunc iter, void *args );
    T *Find( const T *t ) const;

    void Flush( int del = 0 );

    Parent::GetItemsInContainer;
    Parent::IsEmpty;
    Parent::operator delete;

private:

    unsigned GetHashValue( const TVoidPointer& t ) const
        {
        return HashValue(*STATIC_CAST(T *,STATIC_CAST(void *,t)))%TableSize();
        }

};

template <class T,class Alloc>
class TMIHashTableIteratorImp :
    private TMInternalHashTableIteratorImp<TVoidPointer,Alloc,TMIListImp<T,Alloc> >
{

    typedef TMInternalHashTableIteratorImp<TVoidPointer,Alloc,TMIListImp<T,Alloc> > Parent;

public:

    TMIHashTableIteratorImp( const TMIHashTableImp<T,Alloc>& h ) :
        TMInternalHashTableIteratorImp<TVoidPointer,Alloc,TMIListImp<T,Alloc> >(h)
        {
        }

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

};

template <class T,class Alloc>
void TMIHashTableImp<T,Alloc>::ForEach( IterFunc iter, void *args )
{
    TMIVectorIteratorImp<TMIListImp<T,Alloc>,Alloc> iterator(Table);
    while( iterator )
        {
        if( iterator.Current() != 0 )
            iterator.Current()->ForEach(iter,args);
        iterator++;
        }
}

template <class T,class Alloc>
T *TMIHashTableImp<T,Alloc>::Find( const T *t ) const
{
    TMIListImp<T,Alloc> *list = Table[GetHashValue(t)];
    return list ? list->Find(t) : 0;
}

template <class T,class Alloc> int TMIHashTableImp<T,Alloc>::Add( T *t )
{
    unsigned index = GetHashValue(t);
    TMIListImp<T,Alloc> *list = Table[GetHashValue(t)];
    if( list == 0 )
        {
        list = Table[index] = new(*this)TMIListImp<T,Alloc>;
        }
    if( list == 0 )
        return 0;
    else 
        {
        list->Add(t);
        ItemsInContainer++;
        return 1;
        }
}

template <class T,class Alloc>
int TMIHashTableImp<T,Alloc>::Detach( T *t, int del )
{
    unsigned index = GetHashValue(t);
    TMIListImp<T,Alloc> *list = Table[GetHashValue(t)];
    if( list == 0 || ! list->Detach( t, del ) )
        return 0;
    else
        {
        if( list->IsEmpty() )
            {
            delete Table[index];
            Table[index] = 0;
            }
        ItemsInContainer--;
        return 1;
        }
}

template <class T,class Alloc>
void TMIHashTableImp<T,Alloc>::Flush( int del )
{
    for( unsigned i = 0; i < TableSize(); i++ )
        {
        if( Table[i] != 0 )
            {
            Table[i]->Flush(del);
            delete Table[i];
            Table[i] = 0;
            }
        }
    ItemsInContainer = 0;
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TIHashTableImp                               */
/*  template <class T> class TIHashTableIteratorImp                       */
/*                                                                        */
/*  Implements a hash table of pointers to objects of type T              */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TIHashTableIteratorImp;

template <class T> class TIHashTableImp :
    public TMIHashTableImp<T,TStandardAllocator>
{
public:

    friend TIHashTableIteratorImp<T>;

    TIHashTableImp( unsigned aPrime = DEFAULT_HASH_TABLE_SIZE ) :
        TMIHashTableImp<T,TStandardAllocator>( aPrime)
        {
        }
};

template <class T> class TIHashTableIteratorImp :
    public TMIHashTableIteratorImp<T,TStandardAllocator>
{
public:

    TIHashTableIteratorImp( const TIHashTableImp<T>& h ) :
        TMIHashTableIteratorImp<T,TStandardAllocator>(h)
        {
        }
};

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#pragma option -Vo.

#endif  // __CLASSLIB_HASHIMP_H

