//----------------------------------------------------------------------------
// ObjectSupport
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
//
//----------------------------------------------------------------------------
#if !defined(OSL_DEFS_H)
#define OSL_DEFS_H

#if !defined(CLASSLIB_DEFS_H)
# include <classlib/defs.h>
#endif


//----------------------------------------------------------------------------
//
// Include windows.h, if indicated, with necessary macros defined
//

#if defined(BI_PLAT_WIN32) && !defined(_OLEAUTO_H_)
//
// NOTE: 'tagCY' seems to undergo several changes [from struct to union,
//       then to union containing a struct] making it hard to properly
//       choose between inheritance and containment.
//       The following approach ensures the it can be used as a base class.
//
#ifndef _tagCY_DEFINED
#define _tagCY_DEFINED
#define _CY_DEFINED
                        /* size is 8 */
typedef struct  tagCY
    {
    unsigned long Lo;
    long Hi;
    }   CY;

#endif
#endif

#if defined(BI_PLAT_MSW)
# if defined(__WINDOWS_H) && !defined(INC_WINDOWS)
#   if !defined(STRICT)
#     error if windows.h is included before osl/defs.h, STRICT must be defined
#   endif
# else
#   define STRICT
#   if defined(BI_NO_BOOL) && defined(EMULATE_BOOL)
#     define BOOL WBOOL
#     include <windows.h>
#     undef BOOL           // redefine Windows BOOL in terms of the bool type
#     define BOOL bool
#     undef FALSE
#     define FALSE false
#     undef TRUE
#     define TRUE true
#   else
#     include <windows.h>
#   endif
# endif
# if !defined(__SHELLAPI_H) && !defined(_INC_SHELLAPI) && !defined(BI_PLAT_WIN32)
#   include <shellapi.h>
# endif
# if defined(BI_PLAT_WIN16) && defined(INC_OLE2)
#   if !defined(__OLE2_H) && !defined(_OLE2_H_)
#     include <ole2.h>
#   endif
#   if !defined(__DISPATCH_H)
#     include <dispatch.h>
#   endif
#   if !defined(__OLENLS_H) && !defined(_OLENLS_)
#     include <olenls.h>
#   endif
# endif
#endif

//
// Some nonfixed-size types defined similar to the fixedsize in systypes.h
//
typedef unsigned long  ulong;
typedef unsigned int   uint;
typedef unsigned short ushort;

//
// Shorthand 'far' keyword evaluates to __far when needed & supported, else
// nothing
//
#if !defined(far)
# if defined(BI_PTR_0_32)
#   define far
# else
#   define far __far
# endif
#endif
#if defined(BI_NO_BOOL) && defined(EMULATE_BOOL)
  template<class T> inline bool ToBool(const T& t) {
    return static_cast<bool>(t != 0);
  }
#else
  template<class T> inline bool ToBool(const T& t) {
    return static_cast<bool>(t);
  }
#endif

//
// Current module instance in RTL (PLAT_WIN16) or OSL (PLAT_WIN32)
//
extern __cdecl HINSTANCE _hInstance;

//
// Class encapsulations for 64 bit signed and unsigned integers compatible
// with Ole2 and Win32 structs
//
#if !defined(__SYSTYPES_H)
# include <systypes.h>    // int8, int16, etc.
#endif

#if defined(BI_PLAT_WIN32)
  union _ULARGE_INTEGER;
  union _LARGE_INTEGER;
#else
  class far _ULARGE_INTEGER;
  class far _LARGE_INTEGER;
#endif

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

#endif  // OSL_DEFS_H
