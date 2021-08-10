//----------------------------------------------------------------------------
// Borland Services Library
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.15  $
//
// Includes windowing system headers, with necessary macros defined
//----------------------------------------------------------------------------
#if !defined(SERVICES_WSYSINC_H)
#define SERVICES_WSYSINC_H

#if !defined(SERVICES_DEFS_H)
# include <services/defs.h>
#endif

//
// For MS Windows, get windows.h and other standard windows headers
//
#if defined(BI_PLAT_MSW)
# if defined(_INC_WINDOWS)
    //
    // WINDOWS.H has already been included - Ensure that
    // 1. STRICT is defined
    // 2. That the user did not request us to map BOOL to bool
    //
#   if !defined(STRICT)
#     error if windows.h is included before services/wsysinc.h, STRICT must be defined
#   endif
#   if defined(BI_REDEFINE_BOOL)
#     error windows.h must be included via services/wsysinc.h for BOOL redefinition
#   endif
# else
    //
    // We're going to pull in WINDOWS.H - define macros required for
    // framework libraries.
    //
#   define NOMINMAX
#   define STRICT

    //
    // Have WINDOWS.H use WBOOL as its 'int' alias instead of BOOL if
    // 'BOOL to bool' mapping has been requested.
    //
#   if defined(BI_UNIQUE_BOOL) && defined(BI_REDEFINE_BOOL)
#     undef  BOOL
#     define BOOL WBOOL
#   endif
#   include <windows.h>
# endif

//
// Retrieve other Windows headers (before we proceed with BOOL-remapping)
//

// VER.H is currently mucking with definitions of UINT if LIB is not
// defined.
//
# if defined(BI_PLAT_WIN16)
#   if !defined(LIB)
#     define LIB
#   endif
#   include <ver.h>
#   undef LIB
# endif

// Grab shell extension header
//
# if !defined(_INC_SHELLAPI) && !defined(BI_PLAT_WIN32)
#   include <shellapi.h>
# endif

//
// Get Windows OLE2 headers only if requested
//
# if defined(INC_OLE2)
#   include <services/ole2inc.h>
# endif

// Pre v5.0 tools, LPCWSTR is not defined in 16-bits
//
//
# if defined(__BORLANDC__) && (__BORLANDC__ < 0x0500)
#   if !defined(LPCWSTR) && defined(BI_PLAT_WIN16)
      typedef const wchar_t far* LPCWSTR;
      typedef       wchar_t far* LPWSTR;
#   endif
# endif


// Get WIN95-specific definitions if we're using an earlier version
// of WINDOWS.H
//
# if defined(BI_PLAT_WIN16)
#   if (WINVER < 0x0400)
#     if !defined(SERVICES_WIN95_16_H)
#       include <services/win95_16.h>
#     endif
#   endif
# endif

//
// Map BOOL, TRUE and FALSE to bool, true and false respectively.
//
# if defined(BI_UNIQUE_BOOL) && defined(BI_REDEFINE_BOOL)
#   undef  BOOL
#   define BOOL bool
#   undef  FALSE
#   define FALSE false
#   undef  TRUE
#   define TRUE true
# endif

//
// For compatibility only, the inline function versions in services/defs.h
// are recomended
//
# if defined(BI_PLAT_WIN16)
#   define MAKEWORD(a, b)      ((WORD)(((BYTE)(a)) | ((WORD)((BYTE)(b))) << 8))

#   if !defined(LOWORD)
#     define LOWORD(l)         ((uint16)(l))
#   endif
#   if !defined(HIWORD)
#     define HIWORD(l)         ((uint16)((uint32)(l) >> 16))
#   endif

# endif

//
// Current module instance in RTL
//
# if defined(BI_PLAT_WIN16)
    extern __cdecl HINSTANCE _hInstance;
# else  // BI_PLAT_WIN32
    extern HINSTANCE _hInstance;
# endif
//
// For OS/2, get os2.h
//
#elif defined(BI_PLAT_OS2)
# if !defined(__OS2_H)
#   define INCL_BASE
#   define INCL_PM 
#   include <os2.h>
# endif

#endif

#if defined(BI_PLAT_WIN32)
  union _ULARGE_INTEGER;
  union _LARGE_INTEGER;
#else
  class far _ULARGE_INTEGER;
  class far _LARGE_INTEGER;
#endif

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

//
// Large, 64bit integer classes
//
class uint64 {
  public:
    uint64(uint32 low, uint32 high) {LowPart = low; HighPart = high;}
    uint64() {LowPart = HighPart = 0;}
    uint64(_ULARGE_INTEGER uli) {*(_ULARGE_INTEGER*)this = uli;}
    operator _ULARGE_INTEGER() const {return *(_ULARGE_INTEGER*)this;}

    uint32 LowPart;
    uint32 HighPart;
};

class int64 {
  public:
    int64(uint32 low, long high) {LowPart = low; HighPart = high;}
    int64(long low) {LowPart = low; HighPart = low<0 ? -1 : 0;}
    int64() {LowPart = HighPart = 0;}
    int64(_LARGE_INTEGER li) {*(_LARGE_INTEGER*)this = li;}
    operator _LARGE_INTEGER() const {return *(_LARGE_INTEGER*)this;}

    uint32 LowPart;
    int32  HighPart;
};

#if defined(BI_NAMESPACE)
}       // namespace ClassLib
#endif

#endif  // CLASSLIB_WSYSINC_H
