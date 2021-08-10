//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.10  $
//
//----------------------------------------------------------------------------
#if !defined(CLASSLIB_DEFS_H)
#define CLASSLIB_DEFS_H

#if !defined(__cplusplus)
# error Must compile Borland Class Library as C++
#endif

//----------------------------------------------------------------------------
// We must use all libraries in DLLs if we are using BIDS in a DLL
//
// Define _BIDSDLL with -WSE (-WE for 32bit) to use BIDS & RTL in dlls.
//
// Be sure _BUILDBIDSDLL is defined when building an actual BIDS dll
//
#if defined(_BIDSDLL) || defined(_CLASSDLL) || defined(_BUILDBIDSDLL) || defined(_RTLDLL)
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
//
//  To restore the old BIDS naming convention of data and function names
//  beginning with lowercase letters, in addition to the new convention of
//  uppercase letters, remove the // from the #define below or define on the
//  cmd line. The libraries do not need to be rebuilt.
//

//#define BI_OLDNAMES         // add names with initial lowercase

//----------------------------------------------------------------------------
//
//  Common definitions for pointer size and calling conventions.
//
//  Calling conventions:
//
//  _BIDSENTRY      Specifies the calling convention used by BIDS.
//
//
//  Export (and size for DOS) information:
//
//  _BIDSCLASS      Exports class if building DLL version of library.
//                  For DOS16 also provides size information.
//
//  _BIDSDATA       Exports data if building DLL version of library.
//
//  _BIDSFUNC       Exports function if building DLL version of library.
//                  For DOS16 also provides size information
//
//  _BIDSFAR        Promotes data pointers to far in DLLs (DOS16 only).
//
//  _BIDSFARDATA    Forces data pointer to be far.
//
//  _BIDSFARFUNC    Forces function to be far.
//
//  _BIDSFARCLASS   Forces class to be far.
//
//  _BIDSNEARDATA   Forces data to be near.
//
//  _BIDSNEARFUNC   Forces function to be near.
//
//  _BIDSNEARCLASS  Forces class to be near.
//
//----------------------------------------------------------------------------

#define _BIDSENTRY _CALLCNVN
#if defined(BI_COMP_MSC)
# define _BIDSCTOR
#else
# define _BIDSCTOR _BIDSENTRY
#endif

#if defined(BI_PTR_0_32)
# define _BIDSFARDATA
# define _BIDSFARFUNC
# define _BIDSFARCLASS
# define _BIDSNEARDATA
# define _BIDSNEARFUNC
# define _BIDSNEARCLASS
# if defined(_BUILDBIDSDLL)
#   define _BIDSCLASS     __export _CALLCNVN
#   define _BIDSCLASS_RTL __export _CALLCNVN
#   define _BIDSTEMPL     __export
#   define _BIDSDATA      __export
#   define _BIDSFUNC      __export
# elif defined(_BIDSDLL) && !defined(BI_PLAT_OS2)
#   define _BIDSCLASS     __import _CALLCNVN
#   define _BIDSCLASS_RTL __import _CALLCNVN
#   define _BIDSTEMPL     __import
#   define _BIDSDATA      __import
#   define _BIDSFUNC      __import
# else
#   define _BIDSCLASS     _CALLCNVN
#   define _BIDSCLASS_RTL _CALLCNVN
#   define _BIDSTEMPL
#   define _BIDSDATA
#   define _BIDSFUNC
# endif
#else  // 16bit
# if defined(_BIDSDLL)
#   define _BIDSCLASS     __export _CALLCNVN
#   define _BIDSTEMPL     __export
# elif defined(_BIDSFARVTABLE) || defined(BI_DATA_HUGE)
#   define _BIDSCLASS     __huge _CALLCNVN
#   define _BIDSTEMPL     __huge
# elif defined(BI_DATA_FAR)
#   define _BIDSCLASS     __far _CALLCNVN
#   define _BIDSTEMPL     __far
# else
#   define _BIDSCLASS     __near _CALLCNVN
#   define _BIDSTEMPL     __near
# endif
# define _BIDSFARDATA     __far
# define _BIDSFARFUNC     __far
# define _BIDSFARCLASS    __far _CALLCNVN
# define _BIDSNEARDATA    __near
# define _BIDSNEARFUNC    __near
# define _BIDSNEARCLASS   __near _CALLCNVN
# if defined(_BUILDBIDSDLL)
#   define _BIDSFUNC      __export
# else
#   if defined(_BIDSDLL)
#     define _BIDSFUNC    __far
#   else
#     define _BIDSFUNC
#   endif
# endif
# define _BIDSDATA
# if defined(_BIDSFARVTABLE)
#   define _BIDSCLASS_RTL _EXPCLASS
# else
#   define _BIDSCLASS_RTL _BIDSCLASS
# endif
#endif
#define _BIDSFAR

#if defined(BI_NAMESPACE)

# if defined(BI_NO_NAMESPACE)
#   error Compiler lacks support for namespaces.
# endif

#endif

#endif  // CLASSLIB_DEFS_H
