/*------------------------------------------------------------------------*/
/*                                                                        */
/*  SET.H                                                                 */
/*                                                                        */
/*  Copyright Borland International 1991, 1993                            */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __SET_H )
#define __SET_H

#define BI_OLDNAMES

#if !defined( TEMPLATES )

#if !defined( __RESOURCE_H )
#include "classlib\Resource.h"
#endif  // __RESOURCE_H

#if !defined( __CLSTYPES_H )
#include "classlib\obsolete\ClsTypes.h"
#endif  // __CLSTYPES_H

#if !defined( __BAG_H )
#include "classlib\obsolete\Bag.h"
#endif  // __BAG_H

_CLASSDEF(Set)

class _CLASSTYPE Set : public Bag
{

public:

    Set( sizeType setSize = DEFAULT_SET_SIZE ) :
        Bag( setSize )
        {
        }

    virtual void add( Object _FAR & toAdd )
        {
        if( !(Bag::hasMember( toAdd )) )
            {
            Bag::add( toAdd );
            }
        }
    virtual classType isA() const
        {
        return setClass;
        }

    virtual char _FAR *nameOf() const
        {
        return "Set";
        }

};

#else   // TEMPLATES

#if !defined( __COLLECT_H )
#include "classlib\obsolete\Collect.h"
#endif  // __COLLECT_H

#if !defined( __BAG_H )
#include "classlib\obsolete\Bag.h"
#endif  // __BAG_H

#if !defined( __SETS_H )
#include "classlib\Sets.h"
#endif  // __SETS_H


#pragma option -Vo-
#if defined( __BCOPT__ ) && !defined( __FLAT__ ) && !defined( _ALLOW_po )
#pragma option -po-
#endif

#define Set   BI_TCSetAsVector
#define PSet  PBI_TCSetAsVector
#define RSet  RBI_TCSetAsVector
#define RPSet RPBI_TCSetAsVector
#define PCSet PCBI_TCSetAsVector
#define RCSet RCBI_TCSetAsVector

_CLASSDEF( BI_TCSetAsVector )

#define SetIterator   BI_TCSetAsVectorIterator
#define PSetIterator  PBI_TCSetAsVectorIterator
#define RSetIterator  RBI_TCSetAsVectorIterator
#define RPSetIterator RPBI_TCSetAsVectorIterator
#define PCSetIterator PCBI_TCSetAsVectorIterator
#define RCSetIterator RCBI_TCSetAsVectorIterator

_CLASSDEF( BI_TCSetAsVectorIterator )

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_OSetAsVector                                                 */
/*                                                                        */
/*  Implements a set of pointers to Object,                               */
/*  using a vector as the underlying implementation.                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_OSetAsVector : public BI_OBagAsVector
{

public:

    BI_OSetAsVector( unsigned sz = DEFAULT_SET_SIZE ) :
        BI_OBagAsVector(sz)
        {
        }

    void add( Object _FAR *o )
        {
        if( !hasMember(o) )
            BI_OBagAsVector::add(o);
        }


};

class BI_OSetAsVectorIterator : public BI_OBagAsVectorIterator
{

public:

    BI_OSetAsVectorIterator( const BI_OSetAsVector _FAR &s ) :
        BI_OBagAsVectorIterator(s) {}

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_TCSetAsVector                                                */
/*                                                                        */
/*  Implements an Object set, with the full semantics of                  */
/*  the BC 2.0 style Set, using a vector as the underlying                */
/*  implementation.                                                       */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_TCSetAsVector : public BI_TCBagAsVector
{

public:

    BI_TCSetAsVector( unsigned sz = DEFAULT_SET_SIZE ) :
        BI_TCBagAsVector(sz)
        {
        }

    virtual void add( Object _FAR &o )
        {
        if( !hasMember(o) )
            BI_TCBagAsVector::add(o);
        }

    virtual classType isA() const
        {
        return setClass;
        }

    virtual char _FAR *nameOf() const
        {
        return "BI_TCSetAsVector";
        }

    virtual ContainerIterator _FAR & BI_TCSetAsVector::initIterator() const;

};

class BI_TCSetAsVectorIterator : public BI_TCBagAsVectorIterator
{

public:

    BI_TCSetAsVectorIterator( const BI_TCSetAsVector _FAR &s ) :
        BI_TCBagAsVectorIterator(s)
        {
        }

};

inline ContainerIterator _FAR & BI_TCSetAsVector::initIterator() const
{
    return *new BI_TCSetAsVectorIterator( *this );
}

#endif  // TEMPLATES

#if defined( __BCOPT__ ) && !defined( __FLAT__ ) && !defined( _ALLOW_po )
#pragma option -po.
#endif
#pragma option -Vo.

#endif  // __SET_H

