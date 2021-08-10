/*------------------------------------------------------------------------*/
/*                                                                        */
/*  REF.H                                                                 */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __cplusplus
#error Must use C++ for REF.H
#endif

#ifndef __REF_H
#define __REF_H

/*
 *
 * Base class for reference counting
 *
 */

#if !defined(___DEFS_H)
#include <_defs.h>
#endif


#if !defined(RC_INVOKED)

#if defined(__BCOPT__)
#if !defined(_RTL_ALLOW_po) && !defined(__FLAT__)
#pragma option -po-     // disable Object data calling convention
#endif
#endif

#pragma option -Vo-

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */


/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TReference                                                      */
/*                                                                        */
/*  Base class for reference counting                                     */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _EXPCLASS TReference
{

public:

    _RTLENTRY TReference(unsigned short initRef = 0) : Refs(initRef) { }
    void _RTLENTRY AddReference() { Refs++; }
    unsigned short _RTLENTRY References() { return Refs; }
    unsigned short _RTLENTRY RemoveReference() { return --Refs; }

private:

    unsigned short Refs;    // Number of references to this block

};

#if defined( BI_OLDNAMES )
#define BI_Reference TReference
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#if defined(__BCOPT__)
#if !defined(_RTL_ALLOW_po) && !defined(__FLAT__)
#pragma option -po.     // restore Object data calling convention
#endif
#endif

#pragma option -Vo.

#endif  /* !RC_INVOKED */


#endif  // __REF_H
