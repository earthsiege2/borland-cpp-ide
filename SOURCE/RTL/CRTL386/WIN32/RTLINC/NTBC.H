/*------------------------------------------------------------------------
 * filename - ntbc.h
 *
 *  NT API functions and definitions
 *
 *-----------------------------------------------------------------------*/

/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*| Borland C++ 386 Run Time Library - Version 1.0               |*/
/*|                                                              |*/
/*|                                                              |*/
/*| Copyright (c) 1987, 1993 by Borland International            |*/
/*| All Rights Reserved.                                         |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

#ifndef _NTBC_H
#define _NTBC_H

#pragma pack(4)

#ifndef INCL_ERROR_H
#define _WINERROR_      /* prevent including winerror.h */
#endif

#define i386
#define WIN32

#include <excpt.h>
#include <windef.h>
#include <winbase.h>
#include <dosexcpt.h>       /* OS-2 compatible exception definitions */

#ifdef INCL_USER
#include <winuser.h>
#endif

#ifdef INCL_CON
#include <wincon.h>
#endif

#pragma pack()

#endif  /* _NTBC_H */

