/*------------------------------------------------------------------------
 * filename - ntbc.h
 *
 *  NT API functions and definitions
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1993, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.4  $ */

#ifndef _NTBC_H
#define _NTBC_H

#pragma pack(4)
#define _X86_
#define i386
#define WIN32
#define _M_IX86 300
#define NONAMELESSUNION
#define NO_ANONYMOUS_STRUCT
#ifdef __cplusplus
  #define __inline inline
#else
  #define __inline
#endif


#ifdef _UNICODE
#define UNICODE
#endif

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

#if !defined(__cplusplus)
#include <windef.h>
#include <winbase.h>
#include <dosexcpt.h>       /* OS-2 compatible exception definitions */

#ifdef INCL_USER
#include <wingdi.h>
#include <winuser.h>
#endif

#ifdef INCL_CON
#include <wincon.h>
#endif

#else
#include <windows.hpp>
#endif

#pragma pack()

#endif  /* _NTBC_H */

