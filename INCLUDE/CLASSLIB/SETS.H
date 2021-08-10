//----------------------------------------------------------------------------
// Borland BIDS Container Library
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.3  $
//
//----------------------------------------------------------------------------
#if !defined(CLASSLIB_SETS_H)
#define CLASSLIB_SETS_H

#if !defined(CLASSLIB_DEFS_H)
# include <classlib/defs.h>
#endif
#if !defined(CLASSLIB_BAGS_H)
# include <classlib/bags.h>
#endif
#if !defined(SERVICES_CHECKS_H)
# include <services/checks.h>
#endif

#pragma option -Vo-
#if defined( BI_CLASSLIB_NO_po )
# pragma option -po-
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMSetAsVector                    */
/*  template <class T,class Alloc> class TMSetAsVectorIterator            */
/*                                                                        */
/*  Implements a managed set of objects of type T, using a vector as      */
/*  the underlying implementation.                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T, class Alloc> class TMSetAsVectorIterator;

template <class T,class Alloc> class TMSetAsVector :
    private TMBagAsVector<T,Alloc>
{

    typedef TMBagAsVector<T,Alloc> Parent;

public:

    friend TMSetAsVectorIterator<T,Alloc>;

    TMSetAsVector( unsigned sz = DEFAULT_SET_SIZE ) :
        TMBagAsVector<T,Alloc>(sz)
        {
        }

    int Add( const T& );

    Parent::IterFunc;
    Parent::CondFunc;
    Parent::Detach;
    Parent::HasMember;
    Parent::Find;
    Parent::IsEmpty;
    Parent::IsFull;
    Parent::GetItemsInContainer;
    Parent::ForEach;
    Parent::FirstThat;
    Parent::LastThat;
    Parent::Flush;

#if defined( BI_OLDNAMES )
    void add( const T& t ) { Add(t); }
    Parent::detach;
    Parent::hasMember;
    Parent::findMember;
    Parent::isEmpty;
    Parent::isFull;
    Parent::getItemsInContainer;
    Parent::forEach;
    Parent::firstThat;
    Parent::lastThat;
    Parent::flush;
#endif  // BI_OLDNAMES

};

template <class T,class Alloc> class TMSetAsVectorIterator :
    public TMBagAsVectorIterator<T,Alloc>
{

public:

    TMSetAsVectorIterator( const TMSetAsVector<T,Alloc>& s ) :
        TMBagAsVectorIterator<T,Alloc>(s)
        {
        }

};

template <class T,class Alloc> int TMSetAsVector<T,Alloc>::Add( const T& t )
{
    if( HasMember(t) )
        return 0;
    else
        return TMBagAsVector<T,Alloc>::Add(t);
}

#if defined( BI_OLDNAMES )
#define BI_MSetAsVector TMSetAsVector
#define BI_MSetAsVectorIterator TMSetAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TSetAsVector                                 */
/*  template <class T> class TSetAsVectorIterator                         */
/*                                                                        */
/*  Implements a set of objects of type T, using a vector as              */
/*  the underlying implementation and TStandardAllocator as its           */
/*  memory manager.                                                       */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TSetAsVector :
    public TMSetAsVector<T,TStandardAllocator>
{

public:

    TSetAsVector( unsigned sz = DEFAULT_SET_SIZE ) :
        TMSetAsVector<T,TStandardAllocator>(sz)
        {
        }

};

template <class T> class TSetAsVectorIterator :
    public TMSetAsVectorIterator<T,TStandardAllocator>
{

public:

    TSetAsVectorIterator( const TSetAsVector<T>& s ) :
        TMSetAsVectorIterator<T,TStandardAllocator>(s)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_SetAsVector TSetAsVector
#define BI_SetAsVectorIterator TSetAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T,class Alloc> class TMISetAsVector                   */
/*  template <class T,class Alloc> class TMISetAsVectorIterator           */
/*                                                                        */
/*  Implements a managed set of pointers to objects of type T,            */
/*  using a vector as the underlying implementation.                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T, class Alloc> class TMISetAsVectorIterator;

template <class T,class Alloc> class TMISetAsVector :
    private TMIBagAsVector<T,Alloc>
{

    typedef TMIBagAsVector<T,Alloc> Parent;

public:

    friend TMISetAsVectorIterator<T,Alloc>;

    TMISetAsVector( unsigned sz = DEFAULT_SET_SIZE ) :
        TMIBagAsVector<T,Alloc>(sz)
        {
        }

    int Add( T * );

    Parent::IterFunc;
    Parent::CondFunc;
    Parent::Detach;
    Parent::HasMember;
    Parent::Find;
    Parent::IsEmpty;
    Parent::IsFull;
    Parent::GetItemsInContainer;
    Parent::ForEach;
    Parent::FirstThat;
    Parent::LastThat;
    Parent::Flush;
    Parent::OwnsElements;

#if defined( BI_OLDNAMES )
    void add( T *t ) { Add(t); }
    Parent::detach;
    Parent::findMember;
    Parent::isEmpty;
    Parent::isFull;
    Parent::getItemsInContainer;
    Parent::forEach;
    Parent::firstThat;
    Parent::lastThat;
    Parent::flush;
    Parent::ownsElements;
#endif

};

#if defined( BI_OLDNAMES )
#define BI_MISetAsVector TMISetAsVector
#endif

template <class T,class Alloc>
int TMISetAsVector<T,Alloc>::Add( T *t )
{
    if( HasMember(t) )
        return 0;
    else
        return TMIBagAsVector<T,Alloc>::Add(t);
}

template <class T,class Alloc> class TMISetAsVectorIterator :
    public TMIBagAsVectorIterator<T,Alloc>
{

public:

    TMISetAsVectorIterator( const TMISetAsVector<T,Alloc>& s ) :
        TMIBagAsVectorIterator<T,Alloc>(s) {}

};

#if defined( BI_OLDNAMES )
#define BI_MISetAsVectorIterator TMISetAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TISetAsVector                                */
/*  template <class T> class TISetAsVectorIterator                        */
/*                                                                        */
/*  Implements a set of pointers to objects of type T,                    */
/*  using a vector as the underlying implementation and                   */
/*  TStandardAllocator as its memory manager.                             */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TISetAsVector :
    public TMISetAsVector<T,TStandardAllocator>
{

public:

    TISetAsVector( unsigned sz = DEFAULT_SET_SIZE ) :
        TMISetAsVector<T,TStandardAllocator>(sz)
        {
        }

};

template <class T> class TISetAsVectorIterator :
    public TMISetAsVectorIterator<T,TStandardAllocator>
{

public:

    TISetAsVectorIterator( const TISetAsVector<T>& s ) :
        TMISetAsVectorIterator<T,TStandardAllocator>(s)
        {
        }

};

#if defined( BI_OLDNAMES )
#define BI_ISetAsVector TISetAsVector
#define BI_ISetAsVectorIterator TISetAsVectorIterator
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TSet                                         */
/*  template <class T> class TSetIterator                                 */
/*                                                                        */
/*  Easy names for TSetAsVector and TSetAsVectorIterator.                 */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TSet :
    public TSetAsVector<T>
{

public:

    TSet( unsigned sz = DEFAULT_SET_SIZE ) :
        TSetAsVector<T>( sz )
        {
        }

};

template <class T> class TSetIterator :
    public TSetAsVectorIterator<T>
{

public:


    TSetIterator( const TSet<T>& a ) :
        TSetAsVectorIterator<T>(a)
        {
        }

};

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#pragma option -Vo.

#endif  // CLASSLIB_SETS_H

