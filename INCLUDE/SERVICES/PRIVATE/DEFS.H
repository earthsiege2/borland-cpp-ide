//----------------------------------------------------------------------------
// Borland Class Library
// (C) Copyright 1993, 1997 by Borland International, All Rights Reserved
//
//----------------------------------------------------------------------------
#if !defined(SERVICES_PRIVATE_DEFS_H)
#define SERVICES_PRIVATE_DEFS_H

//
//    Common definitions for pointer size and calling conventions.
//
//    Calling conventions:
//    _RTLENTRY       Specifies the calling convention used by the RTL
//
//    _USERENTRY      Specifies the calling convention the RTL expects user
//                    compiled functions to use (for callbacks)
//
//    Export (and size for DOS) information:
//    _EXPCLASS       Exports class if building DLL version of library
//                    For DOS16 also provides size information
//
//    _EXPDATA        Exports data if building DLL version of library
//
//    _EXPFUNC        Exports function if building DLL version of library
//                    For DOS16 also provides size information
//
//    _FAR            Promotes data pointers to far in DLLs (DOS16 only)
//
//    Obsolete versions:
//    _Cdecl          Use _RTLENTRY
//    _CLASSTYPE      Use _EXPCLASS
//    _FARFUNC        Use _EXPFUNC
//    _FARCALL        Use _EXPFUNC and declare function explicity __far
//

#if defined(BI_COMP_MSC)
# if defined(_BUILDBIDSDLL)           // Building BIDS DLL
#   define _RTLENTRY
#   define _USERENTRY
#   define _EXPCLASS    __declspec(dllexport)
#   define _EXPDATA     __declspec(dllexport)

#   define _EXPFUNC
#   define _EXPFUNC32

#   define _FAR
#   define _FARFUNC
#   define _FARCALL
#   define _CLASSTYPE   __declspec(dllexport)
# elif defined(_BIDSDLL)              // Using BIDS DLL
#   define _RTLENTRY
#   define _USERENTRY
#   define _EXPCLASS    __declspec(dllimport)
#   define _EXPDATA     __declspec(dllimport)

#   define _EXPFUNC
#   define _EXPFUNC32

#   define _FAR
#   define _FARFUNC
#   define _FARCALL
#   define _CLASSTYPE   __declspec(dllimport)
# else                                // Using static version of BIDS
#   define _RTLENTRY
#   define _USERENTRY
#   define _EXPCLASS
#   define _EXPDATA

#   define _EXPFUNC
#   define _EXPFUNC32

#   define _FAR
#   define _FARFUNC
#   define _FARCALL
#   define _CLASSTYPE
# endif

# define _RTTI
# define _Cdecl
#endif  // #if BI_COMP_MSC

#endif  // SERVICES_PRIVATE_DEFS_H
