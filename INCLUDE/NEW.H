/*  new.h

    Access to operator new() and newhandler()

*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1990, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.1  $ */

#if !defined(__NEW_H)
#define __NEW_H

#ifndef __cplusplus
#error Must use C++ with new.h
#endif

#if !defined(___DEFS_H)
#include <_defs.h>
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */


#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

class _EXPCLASS xalloc;

typedef void (* _RTLENTRY new_handler)() /* throw(xalloc) */;
new_handler _RTLENTRY set_new_handler(new_handler);

#if defined(__MFC_COMPAT__)
typedef int (* _RTLENTRY _PNH)(size_t);
inline _PNH _RTLENTRY set_new_handler(_PNH p)
                      { return (_PNH) set_new_handler ((new_handler)p); }
#endif

#ifdef __MSC  // Uses non-ANSI name
#define _set_new_handler(f) set_new_handler(f)
#endif

void * _RTLENTRY _EXPFUNC32 operator new(size_t size);
void * _RTLENTRY _EXPFUNC32 operator new(size_t size, void *ptr);

void * _RTLENTRY _EXPFUNC32 operator new[](size_t size);
void * _RTLENTRY _EXPFUNC32 operator new[](size_t size, void *ptr);

void   _RTLENTRY _EXPFUNC32 operator delete  (void *);
void   _RTLENTRY _EXPFUNC32 operator delete[](void *);

#if !defined(__FLAT__) && (defined(__COMPACT__) || defined(__LARGE__) || defined(__HUGE__))
    void __far * _RTLENTRY operator new(unsigned long size);
    void __far * _RTLENTRY operator new(unsigned long size, void __far *ptr);

    void __far * _RTLENTRY operator new[](unsigned long size);
    void __far * _RTLENTRY operator new[](unsigned long size, void __far *ptr);

    void         _RTLENTRY operator delete  (void __far *ptr);
    void         _RTLENTRY operator delete[](void __far *ptr);
#endif

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif  /* __NEW_H */

