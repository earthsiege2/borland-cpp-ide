//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.6  $
//
//----------------------------------------------------------------------------
#if !defined(WINSYS_DEFS_H)
#define WINSYS_DEFS_H

#if !defined(__cplusplus)
# error Must compile Borland WinSys Library as C++
#endif

//----------------------------------------------------------------------------
// We must use all libraries in DLLs if we are using WinSys in a DLL
//
// Define _WSYSDLL with -WSE (-WE for 32bit) to use WSYS & RTL in dlls.
//
// Be sure _BUILDWSYSDLL is defined when building an actual WSYS dll
//
#if defined(_BIDSDLL) || defined(_WSYSDLL) || defined(_SVCSDLL) || defined(_BUILDWSYSDLL)
# if !defined(_WSYSDLL)
#   define _WSYSDLL
# endif
# if !defined(_BIDSDLL)
#   define _BIDSDLL
# endif
# if !defined(_SVCSDLL)
#   define _SVCSDLL
# endif
# if !defined(_RTLDLL)
#   define _RTLDLL
# endif
#endif

//
// Get core services definitions and the windowing system headers
//
#if !defined(SERVICES_DEFS_H)
# include <services/defs.h>
#endif

//----------------------------------------------------------------------------
// Setup class, function and data modifier macros for WinSys
//

#if defined(_BUILDWSYSDLL)
# define _WSYSCLASS     __export _CALLCNVN
# define _WSYSCLASS_RTL __export
# define _WSYSDATA      __export
# define _WSYSFUNC      __export
#elif defined(_WSYSDLL) && !defined(BI_PLAT_OS2)
# define _WSYSCLASS     __import _CALLCNVN
# define _WSYSCLASS_RTL __import
# if defined(BI_PTR_0_32)
#   define _WSYSDATA    __import
#   define _WSYSFUNC    __import
# else
#   define _WSYSDATA    __far
#   define _WSYSFUNC
# endif
#else
# if defined(_WSYSFARVTABLE)
#   define _WSYSCLASS   __huge _CALLCNVN
# else
#   define _WSYSCLASS   _CALLCNVN
# endif
# define _WSYSCLASS_RTL _EXPCLASS
# define _WSYSDATA
# define _WSYSFUNC
#endif

//
// The number of entries in an array, available at compile time
//
#define COUNTOF(s)   (sizeof(s) / sizeof((s)[0]))

//----------------------------------------------------------------------------
// WinSys extensions to the runtime diagnostics in classlib/checks.h
//
uint8 _WSYSFUNC GetDiagEnabled(char* file, char* name, uint8 e);
uint8 _WSYSFUNC GetDiagLevel(char* file, char* name, uint8 l);

#define WSYS_INI "OWL.INI"

#define DIAG_DEFINE_GROUP_INIT(f,g,e,l)\
  DIAG_DEFINE_GROUP(g, GetDiagEnabled(f,#g,e), GetDiagLevel(f,#g,l));

#endif  // WINSYS_DEFS_H
