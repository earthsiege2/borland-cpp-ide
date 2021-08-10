/*  new.h

    Access to operator new() and newhandler()

*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1990, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined(__NEW_H)
#define __NEW_H

#ifndef __cplusplus
#error Must use C++ with new.h
#endif

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

class _EXPCLASS xalloc;

typedef void (* _RTLENTRY new_handler)() /* throw(xalloc) */;

new_handler _RTLENTRY set_new_handler(new_handler);

#ifdef __MSC  // Uses non-ANSI name
#define _set_new_handler(f) set_new_handler(f)
#endif

#endif  /* __NEW_H */

