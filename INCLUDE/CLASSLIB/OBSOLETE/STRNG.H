/*------------------------------------------------------------------------*/
/*                                                                        */
/*  STRNG.H                                                               */
/*                                                                        */
/*  Copyright Borland International 1991, 1993                            */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( _STRNG_H )
#define _STRNG_H

#define BI_OLDNAMES

#if !defined( __STRING_H )
#include <string.h>
#endif  // __STRING_H

#if !defined( __CLSTYPES_H )
#include "classlib\obsolete\ClsTypes.h"
#endif  // __CLSTYPES_H

#if !defined( __SORTABLE_H )
#include "classlib\obsolete\Sortable.h"
#endif  // __SORTABLE_H

#if !defined( __CHECKS_H )
#include <checks.h>
#endif  // __CHECKS_H

#if !defined( __CSTRING_H )
#include <cstring.h>
#endif

#pragma option -Vo-
#if defined( __BCOPT__ ) && !defined( __FLAT__ ) && !defined( _ALLOW_po )
#pragma option -po-
#endif

_CLASSDEF(ostream)
_CLASSDEF(String)

class _CLASSTYPE String : public Sortable
{

public:

    String() {}
    String( const _TCHAR _FAR *str ) : strng(str) {}
    String( const _TCHAR _FAR *str, unsigned N ) : strng(str,N) {}
    String( unsigned n, _TCHAR c = ' ' ) : strng( c, n ) {}
    String( const String _FAR &str ) : strng(str.strng) {}
    virtual ~String() {}

    String& operator = ( const String _FAR &str )
        { strng = str.strng; return *this; }
    operator const _TCHAR _FAR *() const
        { return strng.c_str(); }

    virtual int isEqual( const Object _FAR &o ) const
        { return strng == ((const String _FAR &)o).strng; }
    virtual int isLessThan( const Object _FAR &o ) const
        { return strng < ((const String _FAR &)o).strng; }

    virtual classType isA() const
        {
        return stringClass;
        }

    virtual _TCHAR _FAR *nameOf() const
        {
        return "String";
        }

    virtual hashValueType hashValue() const
        { return strng.hash(); }
    virtual void printOn( ostream _FAR &os ) const
        { os << strng; }

private:

    BI_String strng;

};

#if defined( __BCOPT__ ) && !defined( __FLAT__ ) && !defined( _ALLOW_po )
#pragma option -po.
#endif
#pragma option -Vo.

#endif
