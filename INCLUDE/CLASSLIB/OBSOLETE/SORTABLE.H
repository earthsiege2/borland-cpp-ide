/*------------------------------------------------------------------------*/
/*                                                                        */
/*  SORTABLE.H                                                            */
/*                                                                        */
/*  Copyright Borland International 1991, 1993                            */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( _SORTABLE_H )
#define _SORTABLE_H

#define BI_OLDNAMES

#if !defined( __CLSDEFS_H )
#include "classlib\obsolete\ClsDefs.h"
#endif  // __CLSDEFS_H

#if !defined( __OBJECT_H )
#include "classlib\obsolete\Object.h"
#endif  // __OBJECT_H

#if !defined( __CHECKS_H )
#include <checks.h>
#endif  // __CHECKS_H

#pragma option -Vo-
#if defined( __BCOPT__ ) && !defined( __FLAT__ ) && !defined( _ALLOW_po )
#pragma option -po-
#endif

_CLASSDEF(ostream)
_CLASSDEF(Sortable)

class _CLASSTYPE Sortable : public Object
{

public:

    virtual int isEqual( const Object _FAR & ) const = 0;
    virtual int isLessThan( const Object _FAR & ) const = 0;
    virtual int isSortable() const
        {
        return 1;
        }

    virtual classType isA() const = 0;
    virtual char _FAR *nameOf() const = 0;
    virtual hashValueType hashValue() const = 0;
    virtual void printOn( ostream& ) const = 0;

};

inline
int operator < ( const Object _FAR & test1, const Object _FAR & test2 )
{
    CHECK( test1.isSortable() && test2.isSortable() );
    return ((Sortable&)test1) < ((Sortable&)test2);
}

inline
int operator > ( const Object _FAR & test1, const Object _FAR & test2 )
{
    CHECK( test1.isSortable() && test2.isSortable() );
    return ((Sortable&)test1) > ((Sortable&)test2);
}

inline
int operator >= ( const Object _FAR & test1, const Object _FAR & test2 )
{
    CHECK( test1.isSortable() && test2.isSortable() );
    return ((Sortable&)test1) >= ((Sortable&)test2);
}

inline
int operator <= ( const Object _FAR & test1, const Object _FAR & test2 )
{
    CHECK( test1.isSortable() && test2.isSortable() );
    return ((Sortable&)test1) <= ((Sortable&)test2);
}

inline
int operator < ( const Sortable _FAR & test1, const Sortable _FAR & test2 )
{
    return ( (test1.isA() == test2.isA()) && test1.isLessThan( test2 ) );
}

inline
int operator > ( const Sortable _FAR & test1, const Sortable _FAR & test2 )
{
    return !( test1 < test2 ) && test1 != test2;
}

inline
int operator >=( const Sortable _FAR & test1, const Sortable _FAR & test2 )
{
    return ( !( test1 <( test2 ) ) );
}

inline
int operator <=( const Sortable _FAR & test1, const Sortable _FAR & test2 )
{
    return ( test1 < test2 || test1 == test2 );
}

#if defined( __BCOPT__ ) && !defined( __FLAT__ ) && !defined( _ALLOW_po )
#pragma option -po.
#endif
#pragma option -Vo.

#endif
