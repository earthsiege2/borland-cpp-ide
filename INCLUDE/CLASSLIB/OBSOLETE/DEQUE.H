/*------------------------------------------------------------------------*/
/*                                                                        */
/*  DEQUE.H                                                               */
/*                                                                        */
/*  Copyright Borland International 1991, 1993                            */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __DEQUE_H )
#define __DEQUE_H

#define BI_OLDNAMES

#if !defined( TEMPLATES )

#if !defined( __CLSTYPES_H )
#include "classlib\obsolete\ClsTypes.h"
#endif  // __CLSTYPES_H

#if !defined( __CONTAIN_H )
#include "classlib\obsolete\Contain.h"
#endif  // __CONTAIN_H

#if !defined( __DBLLIST_H )
#include "classlib\obsolete\DblList.h"
#endif  // __DBLLIST_H

#pragma option -Vo-
#if defined( __BCOPT__ ) && !defined( __FLAT__ ) && !defined( _ALLOW_po )
#pragma option -po-
#endif

_CLASSDEF(Deque)

class _CLASSTYPE Deque : public Container
{

public:

    ~Deque()
        {
        flush();
        }

    Object& peekLeft() const
        {
        return list.peekAtHead();
        }

    Object& peekRight() const
        {
        return list.peekAtTail();
        }

    Object& getLeft();
    Object& getRight();

    void putLeft( Object& o )
        {
        list.addAtHead( o );
        itemsInContainer++;
        }

    void putRight( Object& o )
        {
        list.addAtTail( o );
        itemsInContainer++;
        }

    virtual void flush( DeleteType dt = DefDelete )
        {
        list.flush( dt );
        }

    virtual int isEmpty() const
        {
        return list.isEmpty();
        }

    virtual countType getItemsInContainer() const
        {
        return list.getItemsInContainer();
        }

    virtual void forEach( iterFuncType f, void _FAR *arg )
        {
        list.forEach( f, arg );
        }

    virtual Object _FAR & firstThat( condFuncType f, void _FAR *arg ) const
        {
        return list.firstThat( f, arg );
        }

    virtual Object _FAR & lastThat( condFuncType f, void _FAR *arg ) const
        {
        return list.lastThat( f, arg );
        }

    virtual classType isA() const
        {
        return dequeClass;
        }

    virtual char _FAR *nameOf() const
        {
        return "Deque";
        }

    virtual hashValueType hashValue() const
        {
        return list.hashValue();
        }

    virtual int isEqual( const Object& obj ) const
        {
        return list.isEqual( obj );
        }

    virtual int isSortable() const
        {
        return list.isSortable();
        }

    virtual int isAssociation() const
        {
        return list.isAssociation();
        }

    virtual void printOn( ostream& os ) const
        {
        list.printOn( os );
        }

    virtual void printHeader( ostream& os ) const
        {
        list.printHeader( os );
        }

    virtual void printSeparator( ostream& os ) const
        {
        list.printSeparator( os );
        }

    virtual void printTrailer( ostream& os ) const
        {
        list.printTrailer( os );
        }

    virtual ContainerIterator& initIterator() const;

    int ownsElements()
        {
        return list.ownsElements();
        }

    void ownsElements( int del )
        { 
        list.ownsElements( del );
        }

private:

    DoubleList list;

};

#else   // TEMPLATES

#if !defined( __CONTAIN_H )
#include "classlib\obsolete\Contain.h"
#endif  // __CONTAIN_H

#if !defined( __DEQUES_H )
#include "classlib\Deques.h"
#endif  // __DEQUES_H

#pragma option -Vo-
#if defined( __BCOPT__ ) && !defined( __FLAT__ ) && !defined( _ALLOW_po )
#pragma option -po-
#endif

#define Deque   BI_TCDequeAsDoubleList
#define PDeque  PBI_TCDequeAsDoubleList
#define RDeque  RBI_TCDequeAsDoubleList
#define RPDeque RPBI_TCDequeAsDoubleList
#define PCDeque PCBI_TCDequeAsDoubleList
#define RCDeque RCBI_TCDequeAsDoubleList

_CLASSDEF( BI_TCDequeAsDoubleList )

#define DequeIterator   BI_TCDequeAsDoubleListIterator
#define PDequeIterator  PBI_TCDequeAsDoubleListIterator
#define RDequeIterator  RBI_TCDequeAsDoubleListIterator
#define RPDequeIterator RPBI_TCDequeAsDoubleListIterator
#define PCDequeIterator PCBI_TCDequeAsDoubleListIterator
#define RCDequeIterator RCBI_TCDequeAsDoubleListIterator

_CLASSDEF( BI_TCDequeAsDoubleListIterator )

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_ODequeAsVector                                               */
/*                                                                        */
/*  Implements a dequeue of pointers to Object,                           */
/*  using a vector as the underlying implementation.                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_ODequeAsVector : public BI_IDequeAsVector<Object>
{

public:

    friend class _CLASSTYPE BI_ODequeAsVectorIterator;

    BI_ODequeAsVector( unsigned sz = DEFAULT_DEQUE_SIZE ) :
        BI_IDequeAsVector<Object>( sz )
        {
        }

    Object _FAR *peekLeft() const
        {
        return BI_IDequeAsVector<Object>::peekLeft();
        }

    Object _FAR *peekRight() const
        {
        return BI_IDequeAsVector<Object>::peekRight();
        }

    Object _FAR *getLeft()
        {
        return BI_IDequeAsVector<Object>::getLeft();
        }

    Object _FAR *getRight()
        {
        return BI_IDequeAsVector<Object>::getRight();
        }

    void putLeft( Object _FAR *o )
        {
        BI_IDequeAsVector<Object>::putLeft( o );
        }

    void putRight( Object _FAR *o )
        {
        BI_IDequeAsVector<Object>::putRight( o );
        }

    void flush( TShouldDelete::DeleteType dt = TShouldDelete::DefDelete )
        {
        BI_IDequeAsVector<Object>::flush( dt );
        }

    int isFull() const
        {
        return BI_IDequeAsVector<Object>::isFull();
        }

    int isEmpty() const
        {
        return BI_IDequeAsVector<Object>::isEmpty();
        }

    void forEach( iterFuncType f, void _FAR*), void _FAR*args )
        {
        BI_IDequeAsVector<Object>::forEach( f, args );
        }

    Object _FAR *firstThat( condFuncType f, void _FAR *args ) const
        {
        return BI_IDequeAsVector<Object>::firstThat( f, args );
        }

    Object _FAR *lastThat( condFuncType f, void _FAR *args ) const
        {
        return BI_IDequeAsVector<Object>::lastThat( f, args );
        }

    int getItemsInContainer() const
        {
        return BI_IDequeAsVector<Object>::getItemsInContainer();
        }

};

class _CLASSTYPE BI_ODequeAsVectorIterator :
    public BI_IDequeAsVectorIterator<Object>
{

public:

    BI_ODequeAsVectorIterator( const BI_ODequeAsVector _FAR &d ) :
        BI_IDequeAsVectorIterator<Object>((const BI_IDequeAsVector<Object>&)d)
        {
        }

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_TCDequeAsVector                                              */
/*                                                                        */
/*  Implements an Object dequeue, with the full semantics of              */
/*  the BC 2.0 style deque, using a vector as the underlying              */
/*  implementation.                                                       */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_TCDequeAsVector : 
    public Container, 
    protected BI_ODequeAsVector
{

public:

    friend class _CLASSTYPE BI_TCDequeAsVectorIterator;

    BI_TCDequeAsVector( int sz = DEFAULT_DEQUE_SIZE ) :
        BI_ODequeAsVector(sz)
        {
        }

    Object _FAR & peekLeft() const
        {
        return ptrToRef(BI_ODequeAsVector::peekLeft());
        }

    Object _FAR & peekRight() const
        {
        return ptrToRef(BI_ODequeAsVector::peekRight());
        }

    Object _FAR & getLeft()
        {
        return ptrToRef(BI_ODequeAsVector::getLeft());
        }

    Object _FAR & getRight()
        {
        return ptrToRef(BI_ODequeAsVector::getRight());
        }

    void putLeft( Object _FAR & o )
        {
        BI_ODequeAsVector::putLeft( &o );
        }

    void putRight( Object _FAR & o )
        {
        BI_ODequeAsVector::putRight( &o );
        }

    virtual void flush( DeleteType dt = DefDelete )
        {
        BI_ODequeAsVector::flush(dt);
        }

    virtual int isEmpty() const
        {
        return BI_ODequeAsVector::isEmpty();
        }

    virtual countType getItemsInContainer() const
        {
        return BI_ODequeAsVector::getItemsInContainer();
        }

    void forEach( iterFuncType f, void _FAR*args )
        {
        BI_ODequeAsVector::forEach( f, args );
        }

    Object _FAR & firstThat( condFuncType f, void _FAR *args ) const
        {
        return ptrToRef(BI_ODequeAsVector::firstThat( f, args ));
        }

    Object _FAR & lastThat( condFuncType f, void _FAR *args ) const
        {
        return ptrToRef(BI_ODequeAsVector::lastThat( f, args ));
        }

    virtual ContainerIterator _FAR & initIterator() const;

    virtual classType isA() const
        {
        return dequeClass;
        }

    virtual char _FAR *nameOf() const
        {
        return "BI_TCDequeAsVector";
        }

};

class _CLASSTYPE BI_TCDequeAsVectorIterator : public ContainerIterator
{

public:

    BI_TCDequeAsVectorIterator( const BI_TCDequeAsVector _FAR &d ) :
        iter((const BI_ODequeAsVector&)d)
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

    BI_ODequeAsVectorIterator iter;

};

inline ContainerIterator _FAR & BI_TCDequeAsVector::initIterator() const
{
    return *new BI_TCDequeAsVectorIterator( *this );
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_ODequeAsDoubleList                                           */
/*                                                                        */
/*  Implements a dequeue of pointers to Object,                           */
/*  using a double-linked list as the underlying implementation.          */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_ODequeAsDoubleList : 
    protected BI_IDequeAsDoubleList<Object>
{

public:

    friend class _CLASSTYPE BI_ODequeAsDoubleListIterator;

    ~BI_ODequeAsDoubleList()
        {
        flush();
        }

    Object _FAR *peekLeft() const
        {
        return BI_IDequeAsDoubleList<Object>::peekLeft();
        }

    Object _FAR *peekRight() const
        {
        return BI_IDequeAsDoubleList<Object>::peekRight();
        }

    Object _FAR *getLeft()
        {
        return BI_IDequeAsDoubleList<Object>::getLeft();
        }

    Object _FAR *getRight()
        {
        return BI_IDequeAsDoubleList<Object>::getRight();
        }

    void putLeft( Object _FAR *o )
        {
        BI_IDequeAsDoubleList<Object>::putLeft( o );
        }

    void putRight( Object _FAR *o )
        {
        BI_IDequeAsDoubleList<Object>::putRight( o );
        }

    void flush( TShouldDelete::DeleteType dt = TShouldDelete::DefDelete )
        {
        BI_IDequeAsDoubleList<Object>::flush( dt );
        }

    int isFull() const
        {
        return BI_IDequeAsDoubleList<Object>::isFull();
        }

    int isEmpty() const
        {
        return BI_IDequeAsDoubleList<Object>::isEmpty();
        }

    void forEach( iterFuncType f, void _FAR*args )
        {
        BI_IDequeAsDoubleList<Object>::forEach( f, args );
        }

    Object _FAR *firstThat( condFuncType f, void _FAR *args ) const
        {
        return BI_IDequeAsDoubleList<Object>::firstThat( f, args );
        }

    Object _FAR *lastThat( condFuncType f, void _FAR *args ) const
        {
        return BI_IDequeAsDoubleList<Object>::lastThat( f, args );
        }

    int getItemsInContainer() const { return BI_IDequeAsDoubleList<Object>::getItemsInContainer(); }

};

class _CLASSTYPE BI_ODequeAsDoubleListIterator :
    public BI_IDequeAsDoubleListIterator<Object>
{

public:

    BI_ODequeAsDoubleListIterator( const BI_ODequeAsDoubleList _FAR &d ) :
        BI_IDequeAsDoubleListIterator<Object>((const BI_IDequeAsDoubleList<Object>&)d)
        {
        }

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_TCDequeAsDoubleList                                          */
/*                                                                        */
/*  Implements an Object dequeue, with the full semantics of              */
/*  the BC 2.0 style stack, using a double-linked list as the underlying  */
/*  implementation.                                                       */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_TCDequeAsDoubleList : 
    public Container,
    protected BI_ODequeAsDoubleList
{

public:

    friend class _CLASSTYPE BI_TCDequeAsDoubleListIterator;

    Object _FAR & peekLeft() const
        {
        return ptrToRef(BI_ODequeAsDoubleList::peekLeft());
        }

    Object _FAR & peekRight() const
        {
        return ptrToRef(BI_ODequeAsDoubleList::peekRight());
        }

    Object _FAR & getLeft()
        {
        return ptrToRef(BI_ODequeAsDoubleList::getLeft());
        }

    Object _FAR & getRight()
        {
        return ptrToRef(BI_ODequeAsDoubleList::getRight());
        }

    void putLeft( Object _FAR & o )
        {
        BI_ODequeAsDoubleList::putLeft( &o );
        }

    void putRight( Object _FAR & o )
        {
        BI_ODequeAsDoubleList::putRight( &o );
        }

    virtual void flush( DeleteType dt = DefDelete )
        {
        BI_ODequeAsDoubleList::flush( dt );
        }

    virtual int isEmpty() const
        {
        return BI_ODequeAsDoubleList::isEmpty();
        }

    virtual countType getItemsInContainer() const
        {
        return BI_ODequeAsDoubleList::getItemsInContainer();
        }

    void forEach( iterFuncType f, void _FAR*args )
        {
        BI_ODequeAsDoubleList::forEach( f, args );
        }

    Object _FAR & firstThat( condFuncType f, void _FAR *args ) const
        {
        return ptrToRef(BI_ODequeAsDoubleList::firstThat( f, args ));
        }

    Object _FAR & lastThat( condFuncType f, void _FAR *args ) const
        {
        return ptrToRef(BI_ODequeAsDoubleList::lastThat( f, args ));
        }

    virtual ContainerIterator _FAR & initIterator() const;

    virtual classType isA() const
        {
        return dequeClass;
        }

    virtual char _FAR *nameOf() const
        {
        return "BI_DequeAsDoubleList";
        }

};

class _CLASSTYPE BI_TCDequeAsDoubleListIterator : public ContainerIterator
{

public:

    BI_TCDequeAsDoubleListIterator( const BI_TCDequeAsDoubleList _FAR &o ) :
        iter((const BI_ODequeAsDoubleList&)o)
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

    BI_ODequeAsDoubleListIterator iter;

};

inline ContainerIterator _FAR & BI_TCDequeAsDoubleList::initIterator() const
{
    return *new BI_TCDequeAsDoubleListIterator( *this );
}

#endif  // TEMPLATES

#if defined( __BCOPT__ ) && !defined( __FLAT__ ) && !defined( _ALLOW_po )
#pragma option -po.
#endif
#pragma option -Vo.

#endif  // __DEQUE_H

