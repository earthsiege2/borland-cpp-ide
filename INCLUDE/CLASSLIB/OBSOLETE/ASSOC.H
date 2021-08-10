/*------------------------------------------------------------------------*/
/*                                                                        */
/*  ASSOC.H                                                               */
/*                                                                        */
/*  Copyright Borland International 1991, 1993                            */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __ASSOC_H )
#define __ASSOC_H

#define BI_OLDNAMES

#if !defined( __CLSTYPES_H )
#include "classlib\obsolete\ClsTypes.h"
#endif  // __CLSTYPES_H

#if !defined( __OBJECT_H )
#include "classlib\obsolete\Object.h"
#endif  // __OBJECT_H

#if !defined( __SHDDEL_H )
#include "classlib\ShdDel.h"
#endif  // __SHDDEL_H

#pragma option -Vo-
#if defined( __BCOPT__ ) && !defined( __FLAT__ ) && !defined( _ALLOW_po )
#pragma option -po-
#endif

_CLASSDEF(ostream)
_CLASSDEF(Association)

class _CLASSTYPE Association :
    public Object,
    public virtual Object::TShouldDelete
{

public:

    Association( Object _FAR & k, Object _FAR & v ) :
        aKey( k ),
        aValue( v )
        {
        }

    Association( const Association _FAR & a ) :
        aKey(a.aKey),
        aValue(a.aValue)
        {
        }

    virtual ~Association();

    Object _FAR & key() const
        {
        return aKey;
        }

    Object _FAR & value() const
        {
        return aValue;
        }

    virtual classType isA() const
        {
        return associationClass;
        }

    virtual _TCHAR _FAR *nameOf() const
        {
        return "Association";
        }

    virtual hashValueType hashValue() const
        {
        return aKey.hashValue();
        }

    virtual int isEqual( const Object _FAR & ) const;
    virtual int isAssociation() const
        {
        return 1;
        }

    virtual void printOn( ostream _FAR & ) const;

private:

    Object _FAR & aKey;
    Object _FAR & aValue;

};

#if defined( __BCOPT__ ) && !defined( __FLAT__ ) && !defined( _ALLOW_po )
#pragma option -po.
#endif
#pragma option -Vo.

#endif
