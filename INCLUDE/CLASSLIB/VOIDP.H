/*------------------------------------------------------------------------*/
/*                                                                        */
/*  VOIDP.H                                                               */
/*                                                                        */
/*  Copyright (c) 1993, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( CLASSLIB_VOIDP_H )
#define CLASSLIB_VOIDP_H

#if !defined( CLASSLIB_DEFS_H )
#include <classlib/defs.h>
#endif

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po-
#endif

class TVoidPointer
{

public:

    TVoidPointer( const void *p = 0 ) : Ptr(p) {}
    TVoidPointer( const TVoidPointer& rp ) : Ptr(rp.Ptr) {}

    const TVoidPointer& operator = ( const TVoidPointer& vp )
        { Ptr = vp.Ptr; return *this; }
    const TVoidPointer& operator = ( const void *p )
        { Ptr = p; return *this; }
    operator void *() const { return CONST_CAST(void *,Ptr); }

private:

    const void *Ptr;

};

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#endif  // CLASSLIB_VOIDP_H

