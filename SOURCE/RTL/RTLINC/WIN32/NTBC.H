/*------------------------------------------------------------------------
 * filename - ntbc.h
 *
 *  NT API functions and definitions
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1993, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef _NTBC_H
#define _NTBC_H

#pragma pack(4)

#define _X86_
#define i386
#define WIN32
#define _M_IX86 300
#define NONAMELESSUNION
#define NO_ANONYMOUS_STRUCT

#if defined(__cplusplus)
    #define _WCHAR_T_DEFINED
#endif

#if defined(NONAMELESSUNION) && !defined(_UNION_NAME)
# define _UNION_NAME(X) X
#else
# define _UNION_NAME(X)
#endif

#ifndef INCL_ERROR_H
#define _WINERROR_      /* prevent including winerror.h */
#endif

#define i386
#define WIN32

#include <stdarg.h>
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

