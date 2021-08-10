/*------------------------------------------------------------------------*/
/*                                                                        */
/*  ASSOC.H                                                               */
/*                                                                        */
/*  Copyright (c) 1993, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( CLASSLIB_ASSOC_H )
#define CLASSLIB_ASSOC_H

#if !defined( CLASSLIB_DEFS_H )
#include <classlib/defs.h>
#endif

#if !defined( CLASSLIB_ALLOCTR_H )
#include <classlib/alloctr.h>
#endif

#if !defined( CLASSLIB_VOIDP_H )
#include <classlib/voidp.h>
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
/*  template <class K,class V,class A> class TMDDAssociation              */
/*                                                                        */
/*  Managed association (direct key, direct value)                        */
/*                                                                        */
/*  Implements a binding of a key (K) and value (V).  Assumes that        */
/*  K has a HashValue() member function or a global function with         */
/*  the following prototype exists:                                       */
/*                                                                        */
/*      unsigned HashValue( K& );                                         */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class K,class V,class A> class TMDDAssociation
{
public:

    TMDDAssociation()
        {
        }
        
    TMDDAssociation( const K& k, const V& v ) :
        KeyData(k),
        ValueData(v)
        {
        }
        
    unsigned HashValue() const
        {
        return ::HashValue( KeyData );
        }
        
    const K& Key() const
        {
        return KeyData;
        }
        
    const V& Value() const
        {
        return ValueData;
        }
        
    int operator == (const TMDDAssociation<K,V,A> & a) const
        {
        return KeyData == a.KeyData;
        }

    void DeleteElements()
        {
        }
        
protected:

    K KeyData;
    V ValueData;
};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class K,class V> class TDDAssociation                       */
/*                                                                        */
/*  Standard association (direct key, direct value)                       */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class K,class V> class TDDAssociation :
    public TMDDAssociation<K,V,TStandardAllocator>
{
public:

    TDDAssociation() :
        TMDDAssociation<K,V,TStandardAllocator>()
        {
        }
        
    TDDAssociation( const K& k, const V& v ) :
        TMDDAssociation<K,V,TStandardAllocator>( k, v )
        {
        }
};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class K,class V,class A> class TMDIAssociation              */
/*                                                                        */
/*  Managed association (direct key, indirect value)                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class K,class V,class A> class TMDIAssociation :
    private TMDDAssociation<K,TVoidPointer,A>
{

    typedef TMDDAssociation<K,TVoidPointer,A> Parent;

public:

    TMDIAssociation() :
        TMDDAssociation<K,TVoidPointer,A>()
        {
        }
        
    TMDIAssociation( const K& k, V *v ) : 
        TMDDAssociation<K,TVoidPointer,A>( k, v )
        {
        }

    const V *Value() const
        {
        return STATIC_CAST(V *,STATIC_CAST(void *,(TMDDAssociation<K,TVoidPointer,A>::Value())));
        }

    int operator == (const TMDIAssociation<K,V,A> & a) const
        {
        return Parent::operator ==(a);
        }

    Parent::HashValue;
    Parent::Key;

    void DeleteElements()
        {
        delete CONST_CAST(V *,Value());
        }
        
};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class K,class V> class TDIAssociation                       */
/*                                                                        */
/*  Standard association (direct key, indirect value)                     */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class K,class V> class TDIAssociation :
    public TMDIAssociation<K,V,TStandardAllocator>
{
public:

    TDIAssociation() :
        TMDIAssociation<K,V,TStandardAllocator>()
        {
        }
        
    TDIAssociation( const K& k, V *v ) :
        TMDIAssociation<K,V,TStandardAllocator>( k, v )
        {
        }
};


/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class K,class V,class A> class TMIDAssociation              */
/*                                                                        */
/*  Managed association (indirect key, direct value)                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class K,class V,class A> class TMIDAssociation :
    private TMDDAssociation<TVoidPointer,V,A>
{

    typedef TMDDAssociation<TVoidPointer,V,A> Parent;

public:

    TMIDAssociation() :
        TMDDAssociation<TVoidPointer,V,A>()
        {
        }
        
    TMIDAssociation( K *k, const V& v ) : 
        TMDDAssociation<TVoidPointer,V,A>( k, v )
        {
        }
        
    const K *Key() const
        {
        return STATIC_CAST(K *, STATIC_CAST(void *, Parent::Key()));
        }

    int operator == (const TMIDAssociation<K,V,A>& a) const
        {
        return *Key() == *a.Key();
        }

    unsigned HashValue() const
        {
        return ::HashValue( *Key() );
        }
        
    Parent::Value;

    void DeleteElements()
        {
        delete CONST_CAST(K *,Key());
        }
        
};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class K,class V> class TIDAssociation                       */
/*                                                                        */
/*  Standard association (indirect key, direct value)                     */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class K,class V> class TIDAssociation :
    public TMIDAssociation<K,V,TStandardAllocator>
{
public:

    TIDAssociation() :
        TMIDAssociation<K,V,TStandardAllocator>()
        {
        }
        
    TIDAssociation( K *k, const V& v ) :
        TMIDAssociation<K,V,TStandardAllocator>( k, v )
        {
        }
};


/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class K,class V,class A> class TMIIAssociation              */
/*                                                                        */
/*  Managed association (indirect key, indirect value)                    */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class K,class V,class A> class TMIIAssociation :
    private TMDDAssociation<TVoidPointer,TVoidPointer,A>
{

    typedef TMDDAssociation<TVoidPointer,TVoidPointer,A> Parent;

public:

    TMIIAssociation() :
        TMDDAssociation<TVoidPointer,TVoidPointer,A>()
        {
        }
        
    TMIIAssociation( K *k, V *v ) : 
        TMDDAssociation<TVoidPointer,TVoidPointer,A>
            ( k, v )
        {
        }
        
    const K *Key() const
        {
        return STATIC_CAST(K *, STATIC_CAST(void *, Parent::Key()));
        }
        
    const V *Value() const
        {
        return STATIC_CAST(V *, STATIC_CAST(void *, Parent::Value()));
        }
        
    int operator == (const TMIIAssociation<K,V,A>& a) const
        {
        return *Key() == *a.Key();
        }

    unsigned HashValue() const
        {
        return ::HashValue( *Key() );
        }
        
    void DeleteElements()
        {
        delete CONST_CAST(K *,Key());
        delete CONST_CAST(V *,Value());
        }
        
};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class K,class V> class TIIAssociation                       */
/*                                                                        */
/*  Standard association (indirect key, indirect value)                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class K,class V> class TIIAssociation :
    public TMIIAssociation<K,V,TStandardAllocator>
{
public:

    TIIAssociation() :
        TMIIAssociation<K,V,TStandardAllocator>()
        {
        }
        
    TIIAssociation( K *k, V *v ) :
        TMIIAssociation<K,V,TStandardAllocator>( k, v )
        {
        }
};


#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#pragma option -Vo.

#endif  // CLASSLIB_ASSOC_H
