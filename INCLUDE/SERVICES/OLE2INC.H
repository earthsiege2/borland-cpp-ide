//----------------------------------------------------------------------------
// Borland Services Library
// Copyright (c) 1994, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.6  $
//
// Includes OLE2 headers in the right order with necessary macros defined
//----------------------------------------------------------------------------
#if !defined(SERVICES_OLE2INC_H)
#define SERVICES_OLE2INC_H

#if !defined(SERVICES_DEFS_H)
# include <services/defs.h>
#endif

//
// If wsysinc.h hasn't been included yet, then let it pull in OLE2 if it can
//
#if !defined(SERVICES_WSYSINC_H)
# if !defined(INC_OLE2)
#   define INC_OLE2
# endif
# include <services/wsysinc.h>
#endif

//
// Well, if wsysinc.h already was included, or it didn't get OLE2 for us, then
// try to get the headers now.
// NOTE: If 'BOOL to bool' remapping was requested, OLE2 headers *must* be
//       included via 'services/wsysinc.h'; i.e. define 'INC_OLE2' before
//       including <services/wsysinc.h>
//
//
#if !defined(__OLE2_H) && !defined(_OLE2_H_)
# if defined(BI_REDEFINE_BOOL) && !defined(SERVICES_WSYSINC_H)
#   error OLE headers must be included via services/wsysinc.h when redefining BOOL
# endif
# if defined(BI_PLAT_WIN16)
#   if !defined(__OLE2_H) && !defined(_OLE2_H_)
#     include <ole2.h>
#   endif
#   if !defined(__DISPATCH_H) && !defined(_DISPATCH_H_)
#     include <dispatch.h>
#   endif
#   if !defined(__OLENLS_H) && !defined(_OLENLS_)
#     include <olenls.h>
#   endif
# elif defined(BI_PLAT_WIN32)
#   error Win32 Ole2 headers cannot be included after Windows.h, define INC_OLE2 first
# else
    // No OLE2 on non-MSW platforms currently
# endif
#endif

//
// OLECHAR & BSTR is char under Win16, and wchar_t under Win32
//
#if !defined(BI_PLAT_WIN16)
# define BI_OLECHAR_WIDE    // OLECHAR is wide (wchar_t)
# define BI_HAS_WCHAR       // platform has wide char functions available
#endif

#endif  // SERVICES_OLE2INC_H
