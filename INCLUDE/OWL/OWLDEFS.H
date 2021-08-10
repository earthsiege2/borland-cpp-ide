//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   General definitions used by all ObjectWindows programs. Included
//   directly by ObjectWindows source modules.
//----------------------------------------------------------------------------
#if !defined(OWL_OWLDEFS_H)
#define OWL_OWLDEFS_H
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
# if !defined(_BIDSDLL)
#   define _BIDSDLL
# endif
# if !defined(_RTLDLL)
#   define _RTLDLL
# endif
#endif

//
// Setup class, function and data modifier macros for Owl.
//
#if defined(_FASTTHIS) && !defined(__FLAT__)
# define _OWLFASTTHIS __fastthis
#else
# define _OWLFASTTHIS
#endif
#if defined(_BUILDOWLDLL)
# define _OWLCLASS     __export  _OWLFASTTHIS
# define _OWLCLASS_RTL __export
# define _OWLDATA      __export
# define _OWLFUNC      __export
#elif defined(_OWLDLL)
# define _OWLCLASS     __import  _OWLFASTTHIS
# define _OWLCLASS_RTL __import
# if defined(__FLAT__)
#   define _OWLDATA __import
#   define _OWLFUNC __import
# else
#   define _OWLDATA __far
#   define _OWLFUNC
# endif
#else
# if defined(_OWLFARVTABLE)
#   define _OWLCLASS __huge _OWLFASTTHIS
# else
#   define _OWLCLASS _OWLFASTTHIS
# endif
# define _OWLCLASS_RTL _EXPCLASS
# define _OWLDATA
# define _OWLFUNC
#endif
#define _OWLFAR

//
// Setup class modifier for user classes derived from Owl classes.
//
#if defined(_OWLDLL) && defined(__DLL__) && !defined(__WIN32__)
  // force data segment load on method entry in case called back from Owl
# define _USERCLASS  __export _OWLFASTTHIS
#else
# define _USERCLASS           _OWLFASTTHIS
#endif 

//----------------------------------------------------------------------------
// Get RTL, OSL & other owl headers common to all of Owl
//
#if !defined(OSL_DEFS_H)
# include <osl/defs.h>
# include <osl/inlines.h>
#endif
#if !defined(__SYSTYPES_H)
# include <systypes.h>    // int8, int16, etc.
#endif
#if !defined(__CSTRING_H)
# include <cstring.h>     // string class
#endif
#if !defined(__CHECKS_H)
# include <checks.h>      // diag macros (PRECONDITION, CHECK, WARN, TRACE)
#endif
#if !defined(OWL_EXCEPT_H)
# include <owl/except.h>  // Owl exception classes
#endif

//----------------------------------------------------------------------------
// Define macro for user code to force inclusion of stream
// registration objects when statically linking to OWL.
// Assumes that objstrm.h has been #included at the point
// where it is used.
//
#if defined(_OWLDLL)
# define _OWLLINK(s)
#else
# define _OWLLINK(s) __link(s)
#endif

//----------------------------------------------------------------------------
// Additional windows.h related defines & undefs for owl compatibility
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
# define HUGE
# define WM_SYSTEMERROR      0x0017
# define WM_CTLCOLOR         0x0019
# define HTASK HANDLE    // allow users to use the same type in Win16 & Win32
#else
# define HUGE                __huge
# define WM_HOTKEY           0x0312
# define WM_PAINTICON        0x0026
#endif
#undef  SetWindowFont
#undef  GetWindowFont

//----------------------------------------------------------------------------
// Owl diagnostics extensions
//
uint8 _OWLFUNC GetDiagEnabled(char* file, char* name, uint8 e);
uint8 _OWLFUNC GetDiagLevel(char* file, char* name, uint8 l);

#define OWL_INI "OWL.INI"

#define DIAG_DEFINE_GROUP_INIT(f,g,e,l)\
  DIAG_DEFINE_GROUP(g, GetDiagEnabled(f,#g,e), GetDiagLevel(f,#g,l));

//----------------------------------------------------------------------------
// Common external Owl functions & data
//
uint16 far _OWLFUNC OWLGetVersion(); // Get running version
const uint16 OWLVersion = 0x0250;    // Version building with: XX.XX

#endif  // OWL_OWLDEFS_H
