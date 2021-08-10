//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.10  $
//
// General definitions used by all ObjectWindows programs. Included directly
// by ObjectWindows source modules.
//----------------------------------------------------------------------------
#if !defined(OWL_DEFS_H)
#define OWL_DEFS_H
#define __OWL_OWLDEFS_H   // Old-style define for VbxGen compatibility

//----------------------------------------------------------------------------
// We must use all libraries in DLLs if we are using Owl in a DLL
//
// Define _OWLDLL with -WSE (-WE for 32bit) to use Owl, bids & RTL in dlls.
//
// Be sure _BUILDOWLDLL is defined when building an actual owl dll
//
#if defined(_OWLDLL) || defined(_BUILDOWLDLL)
# if !defined(_OWLDLL)
#   define _OWLDLL
# endif
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

//----------------------------------------------------------------------------
// Get core Classlib and Winsys header for supporting defines
//
#if !defined(CLASSLIB_DEFS_H)
# include <classlib/defs.h>      // Supporting defines for app classes
#endif
#if !defined(WINSYS_DEFS_H)
# include <winsys/defs.h>        // Supporting defines for win sys classes
#endif
#if !defined(WINSYS_SYSTEM_H)
# include <winsys/system.h>
#endif

//----------------------------------------------------------------------------
// Setup class, function and data modifier macros for OWL.
//
#if defined(_BUILDOWLDLL)
# define _OWLCLASS     __export _CALLCNVN
# define _OWLCLASS_RTL __export
# define _OWLDATA      __export
# define _OWLFUNC      __export
#elif defined(_OWLDLL)
# define _OWLCLASS     __import _CALLCNVN
# define _OWLCLASS_RTL __import
# if defined(BI_PTR_0_32)
#   define _OWLDATA    __import
#   define _OWLFUNC    __import
# else
#   define _OWLDATA    __far
#   define _OWLFUNC
# endif
#else
# if defined(_OWLFARVTABLE)
#   define _OWLCLASS   __huge _CALLCNVN
# else
#   define _OWLCLASS   _CALLCNVN
# endif
# define _OWLCLASS_RTL _EXPCLASS
# define _OWLDATA
# define _OWLFUNC
#endif
#define _OWLFAR

//
// Setup modifier for callback function
//
#if defined(BI_PLAT_WIN32)
# define OWL_EXPORT    __declspec(dllexport)
# define OWL_EXPORT16
#elif defined(BI_PLAT_WIN16)
# define OWL_EXPORT
# define OWL_EXPORT16  __export
#endif

//----------------------------------------------------------------------------
// Setup class modifier for user classes derived from Owl classes.
//  Force data segment load on method entry in case called back from Owl for
//  16bit windows DLLs using Owl in a DLL
//
#if defined(_OWLDLL) && defined(BI_APP_DLL) && defined(BI_PLAT_WIN16)
# define _USERCLASS __export _CALLCNVN
#else
# define _USERCLASS _CALLCNVN
#endif

//----------------------------------------------------------------------------
// Define macro for user code to force inclusion of stream registration
// objects when statically linking to OWL. Assumes that classlib/objstrm.h has
// been #included at the point where it is used.
//
#if defined(_OWLDLL)
# define _OWLLINK(s)
#else
# define _OWLLINK(s) __link(s)
#endif

//----------------------------------------------------------------------------
// Get Classlib, Winsys & Services headers common to all of Owl
//
#if !defined(WINSYS_WSYSINC_H)
# include <winsys/wsysinc.h>     // Windowing system headers
#endif
#if !defined(WINSYS_WSYSCLS_H)
# include <winsys/wsyscls.h>     // Windowing system wrapper classes
#endif
#if !defined(CLASSLIB_STDTEMPL_H)
# include <classlib/stdtempl.h>
#endif
#if !defined(SERVICES_MEMORY_H)
# include <services/memory.h>    // Common memory manipulation functions
#endif
#if !defined(SERVICES_CSTRING_H)
# include <services/cstring.h>   // Standard C++ string class
#endif
#if !defined(SERVICES_CHECKS_H)
# include <services/checks.h>    // Runtime diagnostic macros
#endif

//----------------------------------------------------------------------------
// Additional windows.h related defines & undefs for Owl compatibility
//
#if defined(BI_PLAT_WIN32)
# undef GetNextWindow
# undef GetWindowTask
# undef MessageBox
  inline WINAPI MessageBox(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, uint uType)
# if defined(UNICODE)
    {return MessageBoxExW(hWnd, lpText, lpCaption, uType, 0);}
# else
    {return MessageBoxExA(hWnd, lpText, lpCaption, uType, 0);}
# endif
# define WM_SYSTEMERROR      0x0017
# define WM_CTLCOLOR         0x0019
# define HTASK HANDLE    // allow users to use the same type in Win16 & Win32
#elif defined(BI_PLAT_WIN16)
# define WM_HOTKEY           0x0312
# define WM_PAINTICON        0x0026
#endif
#undef  SetWindowFont
#undef  GetWindowFont

//----------------------------------------------------------------------------
// Owl settings for runtime diagnostics in winsys.defs.h & classlib/checks.h
//
#define   OWL_INI     "OWL.INI"
#define   OWL_CDLEVEL  2
#if !defined(OWL_DIAGINFO)
# define OWL_DIAGINFO
#endif

//----------------------------------------------------------------------------
// Strict data makes all data members private. Accessors must then be used
// to access the data members.
//
#if defined(OWL_STRICT_DATA)
# define public_data    private
# define protected_data private
#else
# define public_data    public
# define protected_data protected
#endif

//----------------------------------------------------------------------------
// Default the OWLx_COMPAT macros to be true unless overriden by NO_OWLx_COMPAT
// macros. These macros turn on OWL 1.0 and 2.X compatibility features.
//
#if !defined(NO_OWL1_COMPAT)
# define OWL1_COMPAT
#endif
#if !defined(NO_OWL2_COMPAT)
# define OWL2_COMPAT
#endif
#if !defined(NO_WIN32S_SUPPORT)
# define WIN32S_SUPPORT
#endif

//----------------------------------------------------------------------------
// Common external Owl functions & data
//
#include <owl/version.h>             // OWL version # constants

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

uint16 far _OWLFUNC OWLGetVersion(); // Get version of OWL (dll) at runtime

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

#if defined(BI_NAMESPACE)
using namespace OWL;
#endif

#if defined(BI_NAMESPACE)
# define NS_OWL OWL
#else
# define NS_OWL
#endif

#endif  // OWL_DEFS_H
