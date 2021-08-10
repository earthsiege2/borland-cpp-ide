/*------------------------------------------------------------------------*/
/*                                                                        */
/*  BAG.H                                                                 */
/*                                                                        */
/*  Copyright Borland International 1991, 1993                            */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __BAG_H )
#define __BAG_H

#define BI_OLDNAMES

#if !defined( TEMPLATES )

#if !defined( __RESOURCE_H )
#include "classlib\Resource.h"
#endif  // __RESOURCE_H

#if !defined( __CLSTYPES_H )
#include "classlib\obsolete\ClsTypes.h"
#endif  // __CLSTYPES_H

#if !defined( __HASHTBL_H )
#include "classlib\obsolete\HashTbl.h"
#endif  // __HASHTBL_H

#pragma option -Vo-
#if defined( __BCOPT__ ) && !defined( __FLAT__ ) && !defined( _ALLOW_po )
#pragma option -po-
#endif

_CLASSDEF(Bag)

class _CLASSTYPE Bag : public Collection
{

public:

    Bag( sizeType bagSize = DEFAULT_BAG_SIZE ) :
        table( bagSize )
        {
        }

    virtual void add( Object _FAR & o )
        {
        table.add( o );
        }

    virtual void detach( Object _FAR & o, DeleteType dt = NoDelete )
        {
        table.detach( o, dt );
        }

    virtual void flush( DeleteType dt = DefDelete )
        {
        table.flush( dt );
        }

    virtual int isEmpty() const
        {
        return table.isEmpty();
        }

    virtual countType getItemsInContainer() const
        {
        return table.getItemsInContainer();
        }

    void forEach( iterFuncType f, void _FAR *args )
        {
        table.forEach( f, args );
        }

    Object _FAR& firstThat( condFuncType f, void _FAR *args ) const
        {
        return table.firstThat( f, args );
        }

    Object _FAR& lastThat( condFuncType f, void _FAR *args ) const
        {
        return table.lastThat( f, args );
        }

    virtual int hasMember( Object _FAR & o ) const
        {
        return table.hasMember( o );
        }

    virtual Object _FAR & findMember( Object _FAR & o ) const
        {
        return table.findMember(o);
        }

    virtual ContainerIterator _FAR & initIterator() const
        {
        return table.initIterator();
        }

    virtual classType isA() const
        {
        return bagClass;
        }

    virtual _TCHAR _FAR *nameOf() const
        {
        return "Bag";
        }

    int ownsElements()
        {
        return table.ownsElements();
        }

    void ownsElements( int del )
        { 
        table.ownsElements( del );
        }

private:

    HashTable table;

};

#else   // TEMPLATES

#if !defined( __RESOURCE_H )
#include "classlib\Resource.h"
#endif  // __RESOURCE_H

#if !defined( __COLLECT_H )
#include "classlib\obsolete\Collect.h"
#endif  // __COLLECT_H

#if !defined( __BAGS_H )
#include "classlib\Bags.h"
#endif  // __BAGS_H

#pragma option -Vo-
#if defined( __BCOPT__ ) && !defined( __FLAT__ ) && !defined( _ALLOW_po )
#pragma option -po-
#endif

#define Bag   BI_TCBagAsVector
#define PBag  PBI_TCBagAsVector
#define RBag  RBI_TCBagAsVector
#define RPBag RPBI_TCBagAsVector
#define PCBag PCBI_TCBagAsVector
#define RCBag RCBI_TCBagAsVector

_CLASSDEF( BI_TCBagAsVector )

#define BagIterator   BI_TCBagAsVectorIterator
#define PBagIterator  PBI_TCBagAsVectorIterator
#define RBagIterator  RBI_TCBagAsVectorIterator
#define RPBagIterator RPBI_TCBagAsVectorIterator
#define PCBagIterator PCBI_TCBagAsVectorIterator
#define RCBagIterator RCBI_TCBagAsVectorIterator

_CLASSDEF( BI_TCBagAsVectorIterator )

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_OBagAsVector                                                 */
/*                                                                        */
/*  Implements a bag of pointers to Object,                               */
/*  using a vector as the underlying implementation.                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_OBagAsVector
{

public:

    friend class _CLASSTYPE BI_OBagAsVectorIterator;

    BI_OBagAsVector( unsigned sz = DEFAULT_BAG_SIZE ) :
        obag( sz )
        {
        }

    void add( Object _FAR *o )
        {
        obag.add(o);
        }

    void detach( Object _FAR *o,
                 TShouldDelete::DeleteType dt = TShouldDelete::NoDelete
               )
        {
        obag.detach( o, dt );
        }

    void flush( TShouldDelete::DeleteType dt = TShouldDelete::DefDelete )
        {
        obag.flush( dt );
        }

    int hasMember( Object _FAR *o ) const
        {
        return obag.hasMember(o);
        }

    Object _FAR *findMember( Object _FAR *o ) const
        {
        Object _FAR *obj = obag.findMember( o );
        return obj != 0 ? obj : 0;
        }

    int isEmpty() const
        {
        return obag.isEmpty();
        }

    int isFull() const
        {
        return obag.isFull();
        }

    void forEach( iterFuncType f, void _FAR*args )
        {
        obag.forEach( f, args );
        }

    Object _FAR *firstThat( condFuncType f, void _FAR *args ) const
        {
        return obag.firstThat( f, args );
        }

    Object _FAR *lastThat( condFuncType f, void _FAR *args ) const
        {
        return obag.lastThat( f, args );
        }

    int getItemsInContainer() const
        {
        return obag.getItemsInContainer();
        }

    int ownsElements()
        {
        return obag.ownsElements();
        }

    void ownsElements( int del )
        {
        obag.ownsElements( del );
        }

protected:

    BI_IBagAsVector<Object> obag;

};

class _CLASSTYPE BI_OBagAsVectorIterator :
    public BI_IBagAsVectorIterator<Object>
{

public:

    BI_OBagAsVectorIterator( const BI_OBagAsVector _FAR & b ) :
        BI_IBagAsVectorIterator<Object>(b.obag)
        {
        }

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_TCBagAsVector                                                */
/*                                                                        */
/*  Implements an Object bag, with the full semantics of                  */
/*  the BC 2.0 style Bag, using a vector as the underlying                */
/*  implementation.                                                       */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_TCBagAsVector : public Collection
{

public:

    friend class _CLASSTYPE BI_TCBagAsVectorIterator;

    BI_TCBagAsVector( int sz = DEFAULT_BAG_SIZE ) :
        bag(sz)
        {
        }

    virtual void add( Object _FAR & o )
        {
        bag.add( &o );
        }

    virtual void detach( Object _FAR & o,
                    TShouldDelete::DeleteType dt = TShouldDelete::NoDelete )
        {
        bag.detach( &o, dt );
        }

    virtual void flush(TShouldDelete::DeleteType dt=TShouldDelete::DefDelete )
        {
        bag.flush( dt );
        }

    virtual int isEmpty() const
        {
        return bag.isEmpty();
        }

    virtual countType getItemsInContainer() const
        {
        return bag.getItemsInContainer();
        }

    void forEach( iterFuncType f, void _FAR*args )
        {
        bag.forEach( f, args );
        }

    Object _FAR & firstThat( condFuncType f, void _FAR *args ) const
        {
        return ptrToRef(bag.firstThat( f, args ));
        }

    Object _FAR & lastThat( condFuncType f, void _FAR *args ) const
        {
        return ptrToRef(bag.lastThat( f, args ));
        }

    virtual int hasMember( Object _FAR & o ) const
        {
        return bag.hasMember( &o );
        }

    virtual Object _FAR & findMember( Object _FAR & o ) const
        {
        return ptrToRef(bag.findMember(&o));
        }

    virtual ContainerIterator _FAR & initIterator() const;

    virtual classType isA() const
        {
        return bagClass;
        }

    virtual _TCHAR _FAR *nameOf() const
        {
        return "BI_TCBagAsVector";
        }

    int ownsElements()
        {
        return bag.ownsElements();
        }

    void ownsElements( int del )
        {
        bag.ownsElements( del );
        }

protected:

    BI_OBagAsVector bag;

};

class _CLASSTYPE BI_TCBagAsVectorIterator : public ContainerIterator
{

public:

    BI_TCBagAsVectorIterator( const BI_TCBagAsVector _FAR &b ) :
        iter(b.bag)
        {
        }

    virtual operator int()
        {
        return int(iter);
        }

    virtual Object _FAR & current()
        {
        return Object::ptrToRef(iter.current());
        }

    virtual Object _FAR & operator ++ ( int )
        {
        return Object::ptrToRef(iter++);
        }

    virtual Object _FAR & operator ++ ()
        {
        return Object::ptrToRef(++iter);
        }

    virtual void restart()
        {
        iter.restart();
        }

private:

    BI_OBagAsVectorIterator iter;

};

inline ContainerIterator _FAR & BI_TCBagAsVector::initIterator() const
{
    return *new BI_TCBagAsVectorIterator( *this );
}

#endif  // TEMPLATES

#if defined( __BCOPT__ ) && !defined( __FLAT__ ) && !defined( _ALLOW_po )
#pragma option -po.
#endif
#pragma option -Vo.

#endif  // __BAG_H

