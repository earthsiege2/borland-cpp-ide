/*------------------------------------------------------------------------*/
/*                                                                        */
/*  STACK.H                                                               */
/*                                                                        */
/*  Copyright Borland International 1991, 1993                            */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __STACK_H )
#define __STACK_H

#define BI_OLDNAMES

#if !defined( TEMPLATES )

#if !defined( __CLSTYPES_H )
#include "classlib\obsolete\ClsTypes.h"
#endif  // __CLSTYPES_H

#if !defined( __CONTAIN_H )
#include "classlib\obsolete\Contain.h"
#endif  // __CONTAIN_H

#if !defined( __LIST_H )
#include "classlib\obsolete\List.h"
#endif  // __LIST_H

#pragma option -Vo-
#if defined( __BCOPT__ ) && !defined( __FLAT__ ) && !defined( _ALLOW_po )
#pragma option -po-
#endif

_CLASSDEF(Stack)

class _CLASSTYPE Stack : public Container
{

public:

    void push( Object _FAR & );
    Object _FAR & pop();
    Object _FAR & top() const
        {
        return list.peekHead();
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
        return stackClass;
        }

    virtual char _FAR *nameOf() const
        {
        return "Stack";
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

    virtual ContainerIterator _FAR & initIterator() const;

    int ownsElements()
        {
        return list.ownsElements();
        }

    void ownsElements( int del )
        { 
        list.ownsElements( del );
        }

private:

    List list;

};

#else   // TEMPLATES

#if !defined( __CONTAIN_H )
#include "classlib\obsolete\Contain.h"
#endif  // __CONTAIN_H

#if !defined( __STACKS_H )
#include "classlib\Stacks.h"
#endif  // __STACKS_H

#pragma option -Vo-
#if defined( __BCOPT__ ) && !defined( __FLAT__ ) && !defined( _ALLOW_po )
#pragma option -po-
#endif

#define Stack   BI_TCStackAsList
#define PStack  PBI_TCStackAsList
#define RStack  RBI_TCStackAsList
#define RPStack RPBI_TCStackAsList
#define PCStack PCBI_TCStackAsList
#define RCStack RCBI_TCStackAsList

_CLASSDEF( BI_TCStackAsList )

#define StackIterator   BI_TCStackAsListIterator
#define PStackIterator  PBI_TCStackAsListIterator
#define RStackIterator  RBI_TCStackAsListIterator
#define RPStackIterator RPBI_TCStackAsListIterator
#define PCStackIterator PCBI_TCStackAsListIterator
#define RCStackIterator RCBI_TCStackAsListIterator

_CLASSDEF( BI_TCStackAsListIterator )

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_OStackAsVector                                               */
/*                                                                        */
/*  Implements a stack of pointers to Object,                             */
/*  using a vector as the underlying implementation.                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_OStackAsVector : private BI_IStackAsVector<Object>
{

public:

    friend class _CLASSTYPE BI_OStackAsVectorIterator;

    BI_OStackAsVector( unsigned max = DEFAULT_STACK_SIZE ) :
        BI_IStackAsVector<Object>( max )
        {
        }


    void push( Object _FAR *t )
        {
        BI_IStackAsVector<Object>::push( t );
        }

    Object _FAR *pop()
        {
        return (Object _FAR *)(BI_IStackAsVector<Object>::pop());
        }

    Object _FAR *top() const
        {
        return (Object _FAR *)(BI_IStackAsVector<Object>::top());
        }

    int isEmpty() const
        {
        return BI_IStackAsVector<Object>::isEmpty();
        }

    int isFull() const
        {
        return BI_IStackAsVector<Object>::isFull();
        }

    void forEach( iterFuncType f, void _FAR*args )
        {
        BI_IStackAsVector<Object>::forEach( f, args );
        }

    Object _FAR *firstThat( condFuncType f, void _FAR *args ) const
        {
        return BI_IStackAsVector<Object>::firstThat( f, args );
        }

    Object _FAR *lastThat( condFuncType f, void _FAR *args ) const
        {
        return BI_IStackAsVector<Object>::lastThat( f, args );
        }

    void flush( TShouldDelete::DeleteType dt )
        {
        BI_IStackAsVector<Object>::flush( dt );
        }

    int getItemsInContainer() const
        {
        return BI_IStackAsVector<Object>::getItemsInContainer();
        }

};

class _CLASSTYPE BI_OStackAsVectorIterator :
    public BI_IStackAsVectorIterator<Object>
{

public:

    BI_OStackAsVectorIterator( const BI_OStackAsVector _FAR & s ) :
        BI_IStackAsVectorIterator<Object>((const BI_IStackAsVector<Object>&)s)
        {
        }

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_TCStackAsVector                                              */
/*                                                                        */
/*  Implements an Object stack, with the full semantics of                */
/*  the BC 2.0 style stack, using a vector as the underlying              */
/*  implementation.                                                       */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_TCStackAsVector : 
    public Container, 
    private BI_OStackAsVector
{

public:

    friend class _CLASSTYPE BI_TCStackAsVectorIterator;

    BI_TCStackAsVector( unsigned lim = DEFAULT_STACK_SIZE ) :
        BI_OStackAsVector(lim)
        {
        }

    void push( Object _FAR & o )
        {
        BI_OStackAsVector::push( &o );
        }

    Object _FAR & pop()
        {
        return ptrToRef(BI_OStackAsVector::pop());
        }

    Object _FAR & top() const
        {
        return ptrToRef(BI_OStackAsVector::top());
        }

    virtual int isEmpty() const
        {
        return BI_OStackAsVector::isEmpty();
        }

    virtual countType getItemsInContainer() const
        {
        return BI_OStackAsVector::getItemsInContainer();
        }

    virtual void flush( DeleteType dt = DefDelete )
        {
        BI_OStackAsVector::flush( dt );
        }

    virtual ContainerIterator _FAR & initIterator() const;

    virtual classType isA() const
        {
        return stackClass;
        }

    virtual char _FAR *nameOf() const
        {
        return "BI_TCStackAsVector";
        }

    virtual void forEach( iterFuncType f, void _FAR *args )
        {
        BI_OStackAsVector::forEach( f, args );
        }

    virtual Object _FAR & firstThat( condFuncType f, void _FAR *args ) const
        {
        return ptrToRef(BI_OStackAsVector::firstThat( f, args ));
        }

    virtual Object _FAR & lastThat( condFuncType f, void _FAR *args ) const
        {
        return ptrToRef(BI_OStackAsVector::lastThat( f, args ));
        }

};

class _CLASSTYPE BI_TCStackAsVectorIterator : public ContainerIterator
{

public:

    BI_TCStackAsVectorIterator( const BI_TCStackAsVector _FAR & s ) :
        iter((const BI_OStackAsVector&)s)
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

    BI_OStackAsVectorIterator iter;

};

inline ContainerIterator _FAR & BI_TCStackAsVector::initIterator() const
{
    return *new BI_TCStackAsVectorIterator( *this );
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_OStackAsList                                                 */
/*                                                                        */
/*  Implements a stack of pointers to Object,                             */
/*  using a list as the underlying implementation.                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_OStackAsList : private BI_IStackAsList<Object>
{

public:

    friend class _CLASSTYPE BI_OStackAsListIterator;

    void push( Object _FAR *t )
        {
        BI_IStackAsList<Object>::push( t );
        }

    Object _FAR *pop()
        {
        return (Object _FAR *)(BI_IStackAsList<Object>::pop());
        }

    Object _FAR *top() const
        {
        return (Object _FAR *)(BI_IStackAsList<Object>::top());
        }

    int isEmpty() const
        {
        return BI_IStackAsList<Object>::isEmpty();
        }

    int isFull() const
        {
        return BI_IStackAsList<Object>::isFull();
        }

    void forEach( iterFuncType f, void _FAR*args )
        {
        BI_IStackAsList<Object>::forEach( f, args );
        }

    Object _FAR *firstThat( condFuncType f, void _FAR *args ) const
        {
        return BI_IStackAsList<Object>::firstThat( f, args );
        }

    Object _FAR *lastThat( condFuncType f, void _FAR *args ) const
        {
        return BI_IStackAsList<Object>::lastThat( f, args );
        }

    void flush( TShouldDelete::DeleteType dt = TShouldDelete::DefDelete )
        {
        BI_IStackAsList<Object>::flush( dt );
        }

    int getItemsInContainer() const
        {
        return BI_IStackAsList<Object>::getItemsInContainer();
        }

};

class _CLASSTYPE BI_OStackAsListIterator :
    public BI_IStackAsListIterator<Object>
{

public:

    BI_OStackAsListIterator( const BI_OStackAsList _FAR & s ) :
        BI_IStackAsListIterator<Object>((const BI_IStackAsList<Object>&)s)
        {
        }

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_TCStackAsList                                                */
/*                                                                        */
/*  Implements an Object stack, with the full semantics of                */
/*  the BC 2.0 style stack, using a list as the underlying                */
/*  implementation.                                                       */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_TCStackAsList : public Container, private BI_OStackAsList
{

public:

    friend class _CLASSTYPE BI_TCStackAsListIterator;

    void push( Object _FAR & o )
        {
        BI_OStackAsList::push( &o );
        }

    Object _FAR & pop()
        {
        return ptrToRef(BI_OStackAsList::pop());
        }

    Object _FAR & top() const
        {
        return ptrToRef(BI_OStackAsList::top());
        }

    virtual int isEmpty() const
        {
        return BI_OStackAsList::isEmpty();
        }

    virtual countType getItemsInContainer() const
        {
        return BI_OStackAsList::getItemsInContainer();
        }

    virtual void flush( DeleteType dt = DefDelete )
        {
        BI_OStackAsList::flush( dt );
        }

    virtual ContainerIterator _FAR & initIterator() const;

    virtual classType isA() const
        {
        return stackClass;
        }

    virtual char _FAR * nameOf() const
        {
        return "BI_TCStackAsList";
        }

    virtual void forEach( iterFuncType f, void _FAR *args )
        {
        BI_OStackAsList::forEach( f, args );
        }

    virtual Object _FAR & firstThat( condFuncType f, void _FAR *args ) const
        {
        return ptrToRef(BI_OStackAsList::firstThat( f, args ));
        }

    virtual Object _FAR & lastThat( condFuncType f, void _FAR *args ) const
        {
        return ptrToRef(BI_OStackAsList::lastThat( f, args ));
        }

};

class _CLASSTYPE BI_TCStackAsListIterator : public ContainerIterator
{

public:

    BI_TCStackAsListIterator( const BI_TCStackAsList _FAR & s ) :
        iter((const BI_OStackAsList&)s)
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

    BI_OStackAsListIterator iter;

};

inline ContainerIterator _FAR & BI_TCStackAsList::initIterator() const
{
    return *new BI_TCStackAsListIterator( *this );
}

#endif  // TEMPLATES

#if defined( __BCOPT__ ) && !defined( __FLAT__ ) && !defined( _ALLOW_po )
#pragma option -po.
#endif
#pragma option -Vo.

#endif  // __STACK_H

