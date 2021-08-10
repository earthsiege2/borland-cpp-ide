/*------------------------------------------------------------------------*/
/*                                                                        */
/*  ARRAY.H                                                               */
/*                                                                        */
/*  Copyright Borland International 1991, 1993                            */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __ARRAY_H )
#define __ARRAY_H

#define BI_OLDNAMES

#if !defined( TEMPLATES )

#if !defined( __CLSTYPES_H )
#include "classlib\obsolete\ClsTypes.h"
#endif  // __CLSTYPES_H

#if !defined( __OBJECT_H )
#include "classlib\obsolete\Object.h"
#endif  // __OBJECT_H

#if !defined( __ABSTARRY_H )
#include "classlib\obsolete\AbstArry.h"
#endif  // __ABSTARRY_H

#pragma option -Vo-
#if defined( __BCOPT__ ) && !defined( _ALLOW_po )
#pragma option -po-
#endif

_CLASSDEF(Array)

class _CLASSTYPE Array : public AbstractArray

{

public:

    Array( int upper, int lower = 0, sizeType aDelta = 0 ) :
        AbstractArray( upper, lower, aDelta )
        {
        }

    virtual void add( Object _FAR & );
    void addAt( Object _FAR &, int );

    virtual classType isA() const
        {
        return arrayClass;
        }

    virtual char _FAR *nameOf() const
        {
        return "Array";
        }

};

#else   // TEMPLATES

#if !defined( __ARRAYS_H )
#include "classlib\Arrays.h"
#endif  // __ARRAYS_H

#pragma option -Vo-
#if defined( __BCOPT__ ) && !defined( _ALLOW_po )
#pragma option -po-
#endif

#define Array   BI_TCArrayAsVector
#define PArray  PBI_TCArrayAsVector
#define RArray  RBI_TCArrayAsVector
#define RPArray RPBI_TCArrayAsVector
#define PCArray PCBI_TCArrayAsVector
#define RCArray RCBI_TCArrayAsVector

_CLASSDEF( BI_TCArrayAsVector )

#define ArrayIterator   BI_TCArrayAsVectorIterator
#define PArrayIterator  PBI_TCArrayAsVectorIterator
#define RArrayIterator  RBI_TCArrayAsVectorIterator
#define RPArrayIterator RPBI_TCArrayAsVectorIterator
#define PCArrayIterator PCBI_TCArrayAsVectorIterator
#define RCArrayIterator RCBI_TCArrayAsVectorIterator

_CLASSDEF( BI_TCArrayAsVectorIterator )

#if !defined( __RESOURCE_H )
#include "classlib\Resource.h"
#endif  // __RESOURCE_H

#if !defined( __COLLECT_H )
#include "classlib\obsolete\Collect.h"
#endif  // __COLLECT_H

#if !defined( __SORTABLE_H )
#include "classlib\obsolete\Sortable.h"
#endif  // __SORTABLE_H

#if !defined( __ABSTARRY_H )
#include "classlib\obsolete\AbstArry.h"
#endif  // __ABSTARRY_H

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_OArrayAsVector                                               */
/*                                                                        */
/*  Implements an array of pointers to Object,                            */
/*  using a vector as the underlying implementation.                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_OArrayAsVector
{

public:

    friend class _CLASSTYPE BI_OArrayAsVectorIterator;

    BI_OArrayAsVector() : oarray( DEFAULT_ARRAY_SIZE )
        {
        }

    BI_OArrayAsVector( int upr, int lwr = 0, unsigned delta = 0 ) :
        oarray( upr, lwr, delta )
        {
        }

    Object *operator [] (int loc)
        {
        return oarray[loc];
        }

    Object *operator [] (int loc) const
        {
        return oarray[loc];
        }

    int lowerBound() const
        {
        return oarray.lowerBound();
        }

    int upperBound() const
        {
        return oarray.upperBound();
        }

    sizeType arraySize() const
        {
        return oarray.arraySize();
        }

    void add( Object _FAR *o )
        {
        oarray.add(o);
        }

    void addAt( Object _FAR *o, int loc )
        {
        oarray.addAt(o,loc);
        }

    void detach( int loc,
                 TShouldDelete::DeleteType dt = TShouldDelete::NoDelete
               )
        {
        oarray.detach( loc, dt );
        }

    void detach( Object _FAR *o,
                 TShouldDelete::DeleteType dt = TShouldDelete::NoDelete
               )
        {
        oarray.detach( o, dt );
        }

    void destroy( int i )
        {
        oarray.destroy( i );
        }

    void flush( TShouldDelete::DeleteType dt = TShouldDelete::DefDelete )
        {
        oarray.flush( dt );
        }

    int hasMember( Object _FAR *o ) const
        {
        return oarray.hasMember(o);
        }

    Object _FAR *findMember( Object _FAR *o ) const
        {
        int loc = oarray.find(o);
        return loc != INT_MAX ? oarray[loc] : 0;
        }

    int isEmpty() const
        {
        return oarray.isEmpty();
        }

    int isFull() const
        {
        return oarray.isFull();
        }

    void forEach( iterFuncType f, void _FAR *args )
        {
        oarray.forEach( f, args );
        }

    Object _FAR *firstThat( condFuncType f, void _FAR *args ) const
        {
        return oarray.firstThat( f, args );
        }

    Object _FAR *lastThat( condFuncType f, void _FAR *args ) const
        {
        return oarray.lastThat( f, args );
        }

    int getItemsInContainer() const
        {
        return oarray.getItemsInContainer();
        }

    int ownsElements()
        {
        return oarray.ownsElements();
        }

    void ownsElements( int del )
        {
        oarray.ownsElements( del );
        }

protected:

    BI_IArrayAsVector<Object> oarray;

};

class _CLASSTYPE BI_OArrayAsVectorIterator :
    public BI_IArrayAsVectorIterator<Object>
{

public:

    BI_OArrayAsVectorIterator( const BI_OArrayAsVector _FAR &a ) :
        BI_IArrayAsVectorIterator<Object>(a.oarray)
        {
        restart();
        }

    void restart()
        {
        BI_IArrayAsVectorIterator<Object>::restart();
        if( current() == 0 )
            (*this)++;
        }

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_TCArrayAsVector                                              */
/*                                                                        */
/*  Implements an Object array, with the full semantics of                */
/*  the BC 2.0 style array, using a vector as the underlying              */
/*  implementation.                                                       */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_TCArrayAsVector : public AbstractArray
{

public:

    friend class _CLASSTYPE BI_TCArrayAsVectorIterator;

    BI_TCArrayAsVector( int upper, int lower = 0, sizeType delta = 0 ) :
        array( upper, lower, delta )
        {
        }

    virtual Object& operator []( int loc )
        {
        return ptrToRef(array[loc]);
        }

    virtual Object& operator []( int loc ) const
        {
        return ptrToRef(array[loc]);
        }

    virtual int lowerBound() const
        {
        return array.lowerBound();
        }

    virtual int upperBound() const
        {
        return array.upperBound();
        }

    virtual sizeType arraySize() const
        {
        return array.arraySize();
        }

    void add( Object _FAR &o )
        {
        array.add(&o);
        }

    void addAt( Object _FAR &o, int loc )
        {
        array.addAt(&o,loc);
        }

    virtual void detach( int loc, DeleteType dt = NoDelete )
        {
        array.detach( loc, dt );
        }

    void detach( Object _FAR &o,
                 TShouldDelete::DeleteType dt = TShouldDelete::NoDelete
               )
        {
        array.detach( &o, dt );
        }

    void flush( TShouldDelete::DeleteType dt = TShouldDelete::DefDelete )
        {
        array.flush( dt );
        }

    int hasMember( Object _FAR &o ) const
        {
        return array.hasMember(&o);
        }

    Object _FAR &findMember( Object _FAR &o ) const
        {
        return ptrToRef(array.findMember(&o));
        }

    int isEmpty() const
        {
        return array.isEmpty();
        }

    int isFull() const
        {
        return array.isFull();
        }

    void forEach( iterFuncType f, void _FAR*args )
        {
        array.forEach( f, args );
        }

    Object _FAR &firstThat( condFuncType f, void _FAR *args ) const
        {
        return ptrToRef(array.firstThat( f, args ));
        }

    Object _FAR &lastThat( condFuncType f, void _FAR *args ) const
        {
        return ptrToRef(array.lastThat( f, args ));
        }

    int getItemsInContainer() const
        {
        return array.getItemsInContainer();
        }

    virtual classType isA() const
        {
        return arrayClass;
        }

    virtual char _FAR *nameOf() const
        {
        return "BI_TCArrayAsVector";
        }

    int ownsElements()
        {
        return array.ownsElements();
        }

    void ownsElements( int del )
        {
        array.ownsElements( del );
        }

    ContainerIterator _FAR &initIterator() const;

private:

    BI_OArrayAsVector array;

};

class _CLASSTYPE BI_TCArrayAsVectorIterator : public ContainerIterator
{

public:

    BI_TCArrayAsVectorIterator( const BI_TCArrayAsVector _FAR &a ) :
        iter(a.array)
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

    BI_OArrayAsVectorIterator iter;

};

inline ContainerIterator _FAR & BI_TCArrayAsVector::initIterator() const
        { return *new BI_TCArrayAsVectorIterator( *this ); }

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_OSArrayAsVector                                              */
/*                                                                        */
/*  Implements a sorted array of pointers to Object,                      */
/*  using a vector as the underlying implementation.                      */
/*                                                                        */
/*  Although the interface is written to take pointers to Object, in      */
/*  fact, pointers to Sortable are required.                              */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_OSArrayAsVector
{

public:

    friend class _CLASSTYPE BI_OSArrayAsVectorIterator;

    BI_OSArrayAsVector() : oarray( DEFAULT_ARRAY_SIZE, 0, 0 )
        {
        }

    BI_OSArrayAsVector( int upr, int lwr = 0, unsigned delta = 0 ) :
        oarray( upr, lwr, delta )
        {
        }

    Object *operator [] (int loc)
        {
        return oarray[loc];
        }

    Object *operator [] (int loc) const
        {
        return oarray[loc];
        }

    int lowerBound() const
        {
        return oarray.lowerBound();
        }

    int upperBound() const
        {
        return oarray.upperBound();
        }

    sizeType arraySize() const
        {
        return oarray.arraySize();
        }

    void add( Object _FAR *o )
        {
        PRECONDITION( o->isSortable() );
        oarray.add(o);
        }

    void detach( int loc,
                 TShouldDelete::DeleteType dt = TShouldDelete::NoDelete
               )
        {
        oarray.detach( loc, dt );
        }

    void detach( Object _FAR *o,
                 TShouldDelete::DeleteType dt = TShouldDelete::NoDelete
               )
        {
        PRECONDITION( o->isSortable() );
        oarray.detach( o, dt );
        }

    void flush( TShouldDelete::DeleteType dt = TShouldDelete::DefDelete )
        {
        oarray.flush( dt );
        }

    int hasMember( Object _FAR *o ) const
        {
        PRECONDITION( o->isSortable() );
        return oarray.hasMember(o);
        }

    Object _FAR *findMember( Object _FAR *o ) const
        {
        PRECONDITION( o->isSortable() );
        int loc = oarray.find(o);
        return loc != INT_MAX ? oarray[loc] : 0;
        }

    int isEmpty() const
        {
        return oarray.isEmpty();
        }

    int isFull() const
        {
        return oarray.isFull();
        }

    void forEach( iterFuncType f, void _FAR*args )
        {
        oarray.forEach( f, args );
        }

    Object _FAR *firstThat( condFuncType f, void _FAR *args ) const
        {
        return oarray.firstThat( f, args );
        }

    Object _FAR *lastThat( condFuncType f, void _FAR *args ) const
        {
        return oarray.lastThat( f, args );
        }

    int getItemsInContainer() const
        {
        return oarray.getItemsInContainer();
        }

    int ownsElements()
        {
        return oarray.ownsElements();
        }

    void ownsElements( int del )
        {
        oarray.ownsElements( del );
        }

protected:

    BI_ISArrayAsVector<Object> oarray;

};

class _CLASSTYPE BI_OSArrayAsVectorIterator :
    public BI_ISArrayAsVectorIterator<Object>
{

public:

    BI_OSArrayAsVectorIterator( const BI_OSArrayAsVector _FAR &a ) :
        BI_ISArrayAsVectorIterator<Object>(a.oarray)
        {
        }

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_TCSArrayAsVector                                             */
/*                                                                        */
/*  Implements a sorted Object array, with the full semantics of          */
/*  the BC 2.0 style sorted array, using a vector as the underlying       */
/*  implementation.                                                       */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_TCSArrayAsVector : public AbstractArray
{

public:

    friend class _CLASSTYPE BI_TCSArrayAsVectorIterator;

    BI_TCSArrayAsVector( int upper = DEFAULT_ARRAY_SIZE,
                         int lower = 0,
                         sizeType delta = 0
                       ) :
        array( upper, lower, delta )
        {
        }

    virtual Object& operator []( int loc )
        {
        return ptrToRef(array[loc]);
        }

    virtual Object& operator []( int loc ) const
        {
        return ptrToRef(array[loc]);
        }

    virtual int lowerBound() const
        {
        return array.lowerBound();
        }

    virtual int upperBound() const
        {
        return array.upperBound();
        }

    virtual sizeType arraySize() const
        {
        return array.arraySize();
        }

    void add( Object _FAR &o )
        {
        array.add(&o);
        }

    virtual void detach( int loc, DeleteType dt = NoDelete )
        {
        array.detach( loc, dt );
        }

    void detach( Object _FAR &o, DeleteType dt = NoDelete )
        {
        array.detach( &o, dt );
        }

    void flush( TShouldDelete::DeleteType dt = DefDelete )
        {
        array.flush( dt );
        }

    int hasMember( Object _FAR &o ) const
        {
        return array.hasMember(&o);
        }

    Object _FAR &findMember( Object _FAR &o ) const
        {
        return ptrToRef(array.findMember(&o));
        }

    int isEmpty() const
        {
        return array.isEmpty();
        }

    int isFull() const
        {
        return array.isFull();
        }

    void forEach( iterFuncType f, void _FAR*args )
        {
        array.forEach( f, args );
        }

    Object _FAR &firstThat( condFuncType f, void _FAR *args ) const
        {
        return ptrToRef(array.firstThat( f, args ));
        }

    Object _FAR &lastThat( condFuncType f, void _FAR *args ) const
        {
        return ptrToRef(array.lastThat( f, args ));
        }

    int getItemsInContainer() const
        {
        return array.getItemsInContainer();
        }

    virtual classType isA() const
        {
        return sortedArrayClass;
        }

    virtual char _FAR *nameOf() const
        {
        return "BI_TCSArrayAsVector";
        }

    int ownsElements()
        {
        return array.ownsElements();
        }

    void ownsElements( int del )
        {
        array.ownsElements( del );
        }

    ContainerIterator _FAR & initIterator() const;

private:

    BI_OSArrayAsVector array;

};

class _CLASSTYPE BI_TCSArrayAsVectorIterator : public ContainerIterator
{

public:

    BI_TCSArrayAsVectorIterator( const BI_TCSArrayAsVector _FAR &a ) :
        iter(a.array)
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

    BI_OSArrayAsVectorIterator iter;

};

inline ContainerIterator _FAR & BI_TCSArrayAsVector::initIterator() const
        {
        return *new BI_TCSArrayAsVectorIterator( *this );
        }

#endif  // TEMPLATES

#if defined( __BCOPT__ ) && !defined( _ALLOW_po )
#pragma option -po.
#endif
#pragma option -Vo.

#endif  // __ARRAY_H

