/*------------------------------------------------------------------------*/
/*                                                                        */
/*  REF.H                                                                 */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.5.2.1 $ */

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

#endif  /* !RC_INVOKED */

#endif  // __REF_H
