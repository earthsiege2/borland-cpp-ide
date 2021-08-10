//----------------------------------------------------------------------------
// Borland BIDS Container Library
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.4  $
//
//----------------------------------------------------------------------------
#if !defined( CLASSLIB_DICT_H )
#define CLASSLIB_DICT_H

#if !defined( CLASSLIB_DEFS_H )
#include <classlib/defs.h>
#endif

#if !defined( CLASSLIB_SHDDEL_H )
#include <classlib/shddel.h>
#endif

#if !defined( CLASSLIB_HASHIMP_H )
#include <classlib/hashimp.h>
#endif

#pragma option -Vo-
#if defined( BI_CLASSLIB_NO_po )
#pragma option -po-
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class A> class TMDictionaryAsHashTable              */
/*  template <class T,class A> class TMDictionaryAsHashTableIterator      */
/*                                                                        */
/*  Managed dictionary and iterator                                       */
/*                                                                        */
/*  Implements the dictionary container using a hash table.  Assumes      */
/*  that T is of class TAssociation.                                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class A> class TMDictionaryAsHashTableIterator;

template <class T,class A> class TMDictionaryAsHashTable :
    public TShouldDelete
{
public:

    friend class TMDictionaryAsHashTableIterator<T,A>;

    TMDictionaryAsHashTable( unsigned size = DEFAULT_HASH_TABLE_SIZE ) :
        HashTable(size)
        {
        }
        
    int Add( const T& t )
        {
        return Find( t ) ? 0 : HashTable.Add( t );
        }
        
    int Detach( const T& t, DeleteType dt = DefDelete );
        
    T *Find( const T& t )
        {
        return HashTable.Find( t );
        }

    void Flush( DeleteType dt = DefDelete );
        
    void ForEach( void (*func)(T&, void *),
                  void *args )
        {
        HashTable.ForEach( func, args );
        }
        
    unsigned GetItemsInContainer() const
        {
        return HashTable.GetItemsInContainer();
        }
        
    int IsEmpty() const
        {
        return HashTable.IsEmpty();
        }
        
protected:

    TMHashTableImp<T,A> HashTable;

private:

    static void DeleteElement( T& t, void * );
    
};

template <class T, class A>
int TMDictionaryAsHashTable<T,A>::Detach( const T& t,
                                          DeleteType dt = DefDelete )
{
    if( DelObj(dt) )
        {
        T *assoc = Find(t);
        if( assoc )
            assoc->DeleteElements();
        }
    return HashTable.Detach( t );
}
        
template <class T, class A>
void TMDictionaryAsHashTable<T,A>::Flush(DeleteType dt)
{
    if( DelObj(dt) )
        {
        HashTable.ForEach( DeleteElement, 0 );
        }
    HashTable.Flush();
}
        
template <class T, class A>
void TMDictionaryAsHashTable<T,A>::DeleteElement( T& t, void * )
{
    t.DeleteElements();
}

template <class T,class A>
class TMDictionaryAsHashTableIterator :
    public TMHashTableIteratorImp<T,A>
{
public:

    TMDictionaryAsHashTableIterator( const TMDictionaryAsHashTable<T,A>& t ) :
        TMHashTableIteratorImp<T,A>( t.HashTable )
        {
        }
        
};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TDictionaryAsHashTable                       */
/*  template <class T> class TDictionaryAsHashTableIterator               */
/*                                                                        */
/*  Standard dictionary and iterator                                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TDictionaryAsHashTable :
    public TMDictionaryAsHashTable<T,TStandardAllocator>
{

public:

    TDictionaryAsHashTable( unsigned size = DEFAULT_HASH_TABLE_SIZE ) :
        TMDictionaryAsHashTable<T,TStandardAllocator>(size)
        {
        }
        
};

template <class T>
class TDictionaryAsHashTableIterator :
    public TMDictionaryAsHashTableIterator<T,TStandardAllocator>
{
public:

    TDictionaryAsHashTableIterator( const TDictionaryAsHashTable<T>& t ) :
        TMDictionaryAsHashTableIterator<T,TStandardAllocator>( t )
        {
        }
        
};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class A> class TMIDictionaryAsHashTable             */
/*  template <class T,class A> class TMIDictionaryAsHashTableIterator     */
/*                                                                        */
/*  Managed indirect dictionary and iterator                              */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T,class A> class TMIDictionaryAsHashTableIterator;

template <class T,class A> class TMIDictionaryAsHashTable :
    public TShouldDelete
{

public:

    friend class TMIDictionaryAsHashTableIterator<T,A>;

    TMIDictionaryAsHashTable( unsigned size = DEFAULT_HASH_TABLE_SIZE ) :
        HashTable(size)
        {
        }
        
    int Add( T *t )
        {
        return Find( t ) ? 0 : HashTable.Add( t );
        }
        
    int Detach( T *t, DeleteType dt = DefDelete );
        
    T *Find( T *t )
        {
        return HashTable.Find( t );
        }

    void Flush( DeleteType dt = DefDelete );
        
    void ForEach( void (*func)(T&, void *),
                  void *args )
        {
        HashTable.ForEach( func, args );
        }
        
    unsigned GetItemsInContainer() const
        {
        return HashTable.GetItemsInContainer();
        }
        
    int IsEmpty() const
        {
        return HashTable.IsEmpty();
        }
        
protected:

    TMIHashTableImp<T,A> HashTable;
    
private:

    static void DeleteElement( T& t, void * );
    
};

template <class T, class A>
int TMIDictionaryAsHashTable<T,A>::Detach( T *t, DeleteType dt = DefDelete )
{
    if( DelObj(dt) )
        {
        T *assoc = Find(t);
        if( assoc )
            assoc->DeleteElements();
        }
    return HashTable.Detach( t, DelObj(dt) );
}
        
template <class T, class A>
void TMIDictionaryAsHashTable<T,A>::Flush( DeleteType dt = DefDelete )
{
    if( DelObj(dt) )
        {
        HashTable.ForEach( DeleteElement, 0 );
        }
    HashTable.Flush(DelObj(dt));
}
        
template <class T, class A>
void TMIDictionaryAsHashTable<T,A>::DeleteElement( T& t, void * )
{
    t.DeleteElements();
}

template <class T,class A>
class TMIDictionaryAsHashTableIterator :
    public TMIHashTableIteratorImp<T,A>
{
public:

    TMIDictionaryAsHashTableIterator( const TMIDictionaryAsHashTable<T,A>& t ) :
        TMIHashTableIteratorImp<T,A>( t.HashTable )
        {
        }
        
};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TIDictionaryAsHashTable                      */
/*  template <class T> class TIDictionaryAsHashTableIterator              */
/*                                                                        */
/*  Standard indirect dictionary and iterator                             */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TIDictionaryAsHashTableIterator;

template <class T> class TIDictionaryAsHashTable :
    public TMIDictionaryAsHashTable<T,TStandardAllocator>
{

public:

    friend class TIDictionaryAsHashTableIterator<T>;

    TIDictionaryAsHashTable( unsigned size = DEFAULT_HASH_TABLE_SIZE ) :
        TMIDictionaryAsHashTable<T,TStandardAllocator>(size)
        {
        }

};

template <class T> class TIDictionaryAsHashTableIterator :
    public TMIDictionaryAsHashTableIterator<T,TStandardAllocator>
{
public:

    TIDictionaryAsHashTableIterator( const TIDictionaryAsHashTable<T>& t ) :
        TMIDictionaryAsHashTableIterator<T,TStandardAllocator>( t )
        {
        }
        
};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TDictionary                                  */
/*  template <class T> class TDictionaryIterator                          */
/*                                                                        */
/*  Easy names for TDictionaryAsHashTable and                             */
/*  TDictionaryAsHashTableIterator                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TDictionary :
    public TDictionaryAsHashTable<T>
{

public:

    TDictionary( unsigned size = DEFAULT_HASH_TABLE_SIZE ) :
        TDictionaryAsHashTable<T>( size )
        {
        }

};

template <class T> class TDictionaryIterator :
    public TDictionaryAsHashTableIterator<T>
{

public:


    TDictionaryIterator( const TDictionary<T>& a ) :
        TDictionaryAsHashTableIterator<T>(a)
        {
        }

};

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#pragma option -Vo.

#endif  // CLASSLIB_DICT_H

