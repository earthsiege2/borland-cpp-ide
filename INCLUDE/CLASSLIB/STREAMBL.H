/*------------------------------------------------------------------------*/
/*                                                                        */
/*  STREAMBL.H                                                            */
/*                                                                        */
/*  Copyright (c) 1992, 1993 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*  Class definitions for object streaming                                */
/*                                                                        */
/*                                                                        */
/*                 +----------------+  +-------------+                    */
/*                 |TStreamableTypes|  |ObjectBuilder|                    */
/*                 +--+----------+--+  +-------------+                    */
/*                    |class name|     |  BUILDER    |                    */
/*                    +----------+     |  delta      |                    */
/*                          |          +-------------+                    */
/*                          |                 |                           */
/*                          |                /\                           */
/*                          |         +--------                           */
/*                          |         |                                   */
/*                          |         |                                   */
/*                        +----------------+                              */
/*                        |TStreamableClass|                              */
/*                        +----------------+                              */
/*                        |  Module ID     |                              */
/*                        +----------------+                              */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __CLASSLIB_STREAMBL_H )
#define __CLASSLIB_STREAMBL_H

#if !defined( __STRING_H )
#include <string.h>
#endif  // __STRING_H

#if !defined( __CLASSLIB_DEFS_H )
#include "classlib\defs.h"
#endif  // __CLASSLIB_DEFS_H

#if defined(_FASTTHIS)
#  define _BIDSFASTTHIS __fastthis
#else
#  define _BIDSFASTTHIS
#endif

#if !defined( __CLASSLIB_VECTIMP_H )
#include "classlib\vectimp.h"
#endif  // __CLASSLIB_VECTIMP_H

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po-
#endif

#if defined( __WINDOWS__ ) && !defined( __WINDOWS_H )
#include <windows.h>
#endif  // __WINDOWS__ && __WINDOWS_H

#if defined( BI_NO_PER_INSTANCE_DATA ) && defined(_BIDSDLL)

extern HINSTANCE _hInstance;
typedef unsigned ModuleId;
inline ModuleId GetModuleId() { return (unsigned)_hInstance; }

#else

typedef unsigned ModuleId;
inline ModuleId GetModuleId() { return 1; }

#endif

class _BIDSCLASS _BIDSFASTTHIS _RTTI TStreamer;
class _BIDSCLASS _BIDSFASTTHIS _RTTI TStreamableBase;

typedef TStreamer *(* BUILDER)( TStreamableBase * );

struct _BIDSCLASS ObjectBuilder
{

    enum { NoDelta = -1 };

    ObjectBuilder( BUILDER b, int d ) : Builder( b ), Delta( d )
    {
    }

    BUILDER Builder;
    int Delta;

};

#define __DELTA( d ) (FP_OFF((TStreamable *)(d *)1)-1)

class _BIDSCLASS TStreamableClass : public ObjectBuilder
{

public:

    TStreamableClass( const char *n, 
                      BUILDER b, 
                      int d = NoDelta,
                      ModuleId mid = GetModuleId()
                    );

    ~TStreamableClass();

    int operator == ( const TStreamableClass& n ) const
        {
        if( strcmp( ObjectId, n.ObjectId ) != 0 )
            return 0;
        else
            return (ModId == 0 || n.ModId == 0 || ModId == n.ModId);
        }

    int operator < ( const TStreamableClass& n ) const
        {
        int res = strcmp( ObjectId, n.ObjectId );
        if( res < 0 )
            return 1;
        else if( res > 0 )
            return 0;
        else if( ModId == 0 || n.ModId == 0 || ModId == n.ModId )
            return 0;
        else
            return ModId < n.ModId;
        }

private:

    const char *ObjectId;
    ModuleId ModId;

};

class _BIDSCLASS TStreamableTypes
{

public:

    TStreamableTypes() : Types( 5, 5 ) {}

    void RegisterType( ModuleId id, TStreamableClass& );
    void UnRegisterType( ModuleId id, TStreamableClass& );
    const ObjectBuilder *Lookup( ModuleId id, const char *name ) const;

private:

    TISVectorImp< TStreamableClass > Types;

};

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#endif  // __CLASSLIB_STREAMBLE_H

