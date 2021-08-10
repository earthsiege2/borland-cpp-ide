/*------------------------------------------------------------------------*/
/*                                                                        */
/*  QUEUE.H                                                               */
/*                                                                        */
/*  Copyright Borland International 1991, 1993                            */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __QUEUE_H )
#define __QUEUE_H

#define BI_OLDNAMES

#if !defined( TEMPLATES )

#if !defined( __CLSTYPES_H )
#include "classlib\obsolete\ClsTypes.h"
#endif  // __CLSTYPES_H

#if !defined( __DEQUE_H )
#include "classlib\obsolete\Deque.h"
#endif  // __DEQUE_H

#pragma option -Vo-
#if defined( __BCOPT__ ) && !defined( _ALLOW_po )
#pragma option -po-
#endif

_CLASSDEF(Queue)

class _CLASSTYPE Queue : public Deque
{

public:

    Object _FAR & get()
        {
        return Deque::getRight();
        }

    void put( Object _FAR & o )
        {
        Deque::putLeft( o );
        }

    virtual classType isA() const
        {
        return queueClass;
        }

    virtual char _FAR *nameOf() const
        {
        return "Queue";
        }

private:

    Object _FAR & getLeft();
    Object _FAR & getRight();

    void putLeft( Object _FAR & );
    void putRight( Object _FAR & );

};

#else   // TEMPLATES

#if !defined( __QUEUES_H )
#include "classlib\Queues.h"
#endif  // __QUEUES_H

#pragma option -Vo-
#if defined( __BCOPT__ ) && !defined( _ALLOW_po )
#pragma option -po-
#endif

#define Queue   BI_TCQueueAsDoubleList
#define PQueue  PBI_TCQueueAsDoubleList
#define RQueue  RBI_TCQueueAsDoubleList
#define RPQueue RPBI_TCQueueAsDoubleList
#define PCQueue PCBI_TCQueueAsDoubleList
#define RCQueue RCBI_TCQueueAsDoubleList

_CLASSDEF( BI_TCQueueAsDoubleList )

#define QueueIterator   BI_TCQueueAsDoubleListIterator
#define PQueueIterator  PBI_TCQueueAsDoubleListIterator
#define RQueueIterator  RBI_TCQueueAsDoubleListIterator
#define RPQueueIterator RPBI_TCQueueAsDoubleListIterator
#define PCQueueIterator PCBI_TCQueueAsDoubleListIterator
#define RCQueueIterator RCBI_TCQueueAsDoubleListIterator

_CLASSDEF( BI_TCQueueAsDoubleListIterator )

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_OQueueAsVector                                               */
/*                                                                        */
/*  Implements a queue of pointers to Object,                             */
/*  using a vector as the underlying implementation.                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_OQueueAsVector : public BI_ODequeAsVector
{

public:

    BI_OQueueAsVector( unsigned sz = DEFAULT_QUEUE_SIZE ) :
        BI_ODequeAsVector(sz)
        {
        }

    Object _FAR *get()
        {
        return BI_ODequeAsVector::getRight();
        }

    void put( Object _FAR *t )
        {
        BI_ODequeAsVector::putLeft( t );
        }

private:

    Object _FAR *getLeft();
    Object _FAR *getRight();

    void putLeft( Object _FAR * );
    void putRight( Object _FAR * );

};

class _CLASSTYPE BI_OQueueAsVectorIterator :
    public BI_ODequeAsVectorIterator
{

public:

    BI_OQueueAsVectorIterator( const BI_ODequeAsVector _FAR &q ) :
        BI_ODequeAsVectorIterator(q) {}

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_TCQueueAsVector                                              */
/*                                                                        */
/*  Implements an Object queue, with the full semantics of                */
/*  the BC 2.0 style queue, using a vector as the underlying              */
/*  implementation.                                                       */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_TCQueueAsVector : public BI_TCDequeAsVector
{

public:

    BI_TCQueueAsVector( unsigned sz = DEFAULT_QUEUE_SIZE ) :
        BI_TCDequeAsVector(sz)
        {
        }

    Object _FAR & get()
        {
        return BI_TCDequeAsVector::getRight();
        }

    void put( Object _FAR & t )
        { BI_TCDequeAsVector::putLeft( t );
        }

    virtual classType isA() const
        {
        return queueClass;
        }

    virtual char _FAR *nameOf() const
        {
        return "BI_TCQueueAsDoubleList";
        }

    virtual ContainerIterator _FAR & initIterator() const;

private:

    Object _FAR & getLeft();
    Object _FAR & getRight();

    void putLeft( Object _FAR & );
    void putRight( Object _FAR & );

};

class _CLASSTYPE BI_TCQueueAsVectorIterator :
    public BI_TCDequeAsVectorIterator
{

public:

    BI_TCQueueAsVectorIterator( const BI_TCQueueAsVector _FAR &q ) :
        BI_TCDequeAsVectorIterator(q)
        {
        }

};

inline ContainerIterator _FAR & BI_TCQueueAsVector::initIterator() const
{
    return *new BI_TCQueueAsVectorIterator( *this );
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_OQueueAsDoubleList                                           */
/*                                                                        */
/*  Implements a queue of pointers to Object,                             */
/*  using a double linked list as the underlying implementation.          */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_OQueueAsDoubleList : public BI_ODequeAsDoubleList
{

public:

    Object _FAR *get()
        {
        return BI_ODequeAsDoubleList::getRight();
        }

    void put( Object _FAR *t )
        {
        BI_ODequeAsDoubleList::putLeft( t );
        }

private:

    Object _FAR *getLeft();
    Object _FAR *getRight();

    void putLeft( Object _FAR * );
    void putRight( Object _FAR * );

};

class _CLASSTYPE BI_OQueueAsDoubleListIterator :
    public BI_ODequeAsDoubleListIterator
{

public:

    BI_OQueueAsDoubleListIterator( const BI_OQueueAsDoubleList _FAR & q ) :
        BI_ODequeAsDoubleListIterator(q) {}

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_TCQueueAsDoubleList                                          */
/*                                                                        */
/*  Implements an Object queue, with the full semantics of                */
/*  the BC 2.0 style queue, using a double linked list as the underlying  */
/*  implementation.                                                       */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_TCQueueAsDoubleList : public BI_TCDequeAsDoubleList
{

public:

    Object _FAR & get()
        {
        return BI_TCDequeAsDoubleList::getRight();
        }

    void put( Object _FAR & t )
        {
        BI_TCDequeAsDoubleList::putLeft( t );
        }

    virtual classType isA() const
        {
        return queueClass;
        }

    virtual char _FAR *nameOf() const
        {
        return "BI_TCQueueAsDoubleList";
        }

    virtual ContainerIterator _FAR & initIterator() const;

private:

    Object _FAR & getLeft();
    Object _FAR & getRight();

    void putLeft( Object _FAR & );
    void putRight( Object _FAR & );

};

class _CLASSTYPE BI_TCQueueAsDoubleListIterator :
    public BI_TCDequeAsDoubleListIterator
{

public:

    BI_TCQueueAsDoubleListIterator( const BI_TCQueueAsDoubleList _FAR &q ) :
        BI_TCDequeAsDoubleListIterator(q) {}

};

inline ContainerIterator _FAR & BI_TCQueueAsDoubleList::initIterator() const
{
    return *new BI_TCQueueAsDoubleListIterator( *this );
}

#endif  // TEMPLATES

#if defined( __BCOPT__ ) && !defined( _ALLOW_po )
#pragma option -po.
#endif
#pragma option -Vo.

#endif  // __QUEUE_H

