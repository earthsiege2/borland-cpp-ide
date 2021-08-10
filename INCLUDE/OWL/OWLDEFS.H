//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   include\owl\owldefs.h
//   General definitions used by all ObjectWindows programs. Included
//   directly by ObjectWindows source modules.
//----------------------------------------------------------------------------
#if !defined(__OWL_OWLDEFS_H)
#define __OWL_OWLDEFS_H

//
// We must use all libraries as DLLs if we are building or using any DLL
//
// __DLL__ is defined by the compiler if -WD is used. Define _OWLDLL with -WS
// (-WE for 32bit) to use Owl, bids & RTL in dlls.
//
// Be sure _BUILDOWLDLL is defined when building an actual owl dll
//
#if defined(__DLL__) || defined(_OWLDLL)
#  if !defined(_OWLDLL)
#    define _OWLDLL
#  endif
#  if !defined(_BIDSDLL)
#    define _BIDSDLL
#  endif
#  if !defined(_RTLDLL)
#    define _RTLDLL
#  endif
#endif

//
// Define macros for Owl class, data & functions modifiers
//
#if defined(_FASTTHIS) && !defined(__FLAT__)
#  define _OWLFASTTHIS __fastthis
#else
#  define _OWLFASTTHIS
#endif
#if defined(_BUILDOWLDLL)
#  define _OWLCLASS     _OWLFASTTHIS  __export
#  define _OWLCLASS_RTL __export
#  define _OWLDATA      __export
#  define _OWLFUNC      __export
#elif defined(_OWLDLL)
#  define _OWLCLASS     _OWLFASTTHIS  __import
#  define _OWLCLASS_RTL __import
#  if defined(__FLAT__)
#    define _OWLDATA      __import
#    define _OWLFUNC      __import
#  else
#    define _OWLDATA
#    define _OWLFUNC
#  endif
#else
#  define _OWLCLASS     _OWLFASTTHIS
#  define _OWLCLASS_RTL _EXPCLASS
#  define _OWLDATA
#  define _OWLFUNC
#endif
#define _OWLFAR

//
// Define macro for user code to force inclusion of stream 
// registration objects when statically linking to OWL.
// Assumes that objstrm.h has been #included at the point
// where it is used.
//
#if defined(_OWLDLL)
#  define _OWLLINK(s)
#else
#  define _OWLLINK(s) __link(s)
#endif

//
// Include windows.h, if necessary, with necessary macros defined
//
#if defined(__WINDOWS_H)
#  if !defined(STRICT)
#    error if windows.h is included before owl\owldefs.h, STRICT must be defined
#  endif
#else
#  define STRICT
#  include <windows.h>
#endif

//
// Additional windows.h related defines & undefs
//
#if defined(__WIN32__)
#  undef GetNextWindow
#  undef GetWindowTask
#  undef MessageBox
   inline WINAPI MessageBox(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
#  if defined(UNICODE)
     {return MessageBoxExW(hWnd, lpText, lpCaption, uType, 0);}
#  else
     {return MessageBoxExA(hWnd, lpText, lpCaption, uType, 0);}
#  endif
#  define HUGE
#  define WM_SYSTEMERROR      0x0017
#  define WM_CTLCOLOR         0x0019
#  define HTASK HANDLE    // allow users to use the same type in win16 & win32
#else
  // Things that don't exist in WIN16
#  define HUGE huge
#  define WM_HOTKEY             0x0312
#  define WM_PAINTICON          0x0026
#
#endif
#undef  SetWindowFont
#undef  GetWindowFont

#define COUNTOF(s)   (sizeof(s) / sizeof((s)[0]))
#if !defined(__SHELLAPI_H) && !defined(__WIN32__)
#  include <shellapi.h>
#endif

//
// Include RTL & other owl headers
//
#if !defined(__SYSTYPES_H)
#  include <systypes.h>
#endif
#include <cstring.h>
#include <checks.h>
#if !defined(__OWL_EXCEPT_H)
#  include <owl\except.h>
#endif

//
// Other common types defined
//
typedef const void far* LPCVOID;

//
// Owl diagnostics
//
uint8 _OWLFUNC GetDiagEnabled(char* file, char* name, uint8 e);
uint8 _OWLFUNC GetDiagLevel(char* file, char* name, uint8 l);

#define OWL_INI "OWL.INI"

#define DIAG_DEFINE_GROUP_INIT(f,g,e,l)\
  DIAG_DEFINE_GROUP(g, GetDiagEnabled(f,#g,e), GetDiagLevel(f,#g,l));

//
// Common external functions & data
//
unsigned short far _OWLFUNC OWLGetVersion();
const unsigned short OWLVersion = 0x0200; // Version 2.00
#if !defined(__WIN32__)
  extern __cdecl HINSTANCE _hInstance;
#endif

#endif  // __OWL_OWLDEFS_H
