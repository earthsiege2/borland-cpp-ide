//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1997 by Borland International, All Rights Reserved
//
// $Revision:   2.9  $
//
// ObjectComponents fundamental definitions
//----------------------------------------------------------------------------
#if !defined(OCF_DEFS_H)
#define OCF_DEFS_H

#if defined(BI_NAMESPACE)
namespace OCF {
#endif

//
// We must use all libraries as DLLs if we are using OCF as a DLL
//
// Define _OCFDLL with -WSE (-WE for 32bit) to use BIDS & RTL in dlls.
//
// Be sure _BUILDOCFDLL is defined when building an actual OCF dll
//
#if defined(_OCFDLL) || defined(_BUILDOCFDLL)
# if !defined(_OCFDLL)
#   define _OCFDLL
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

#if defined(BI_NAMESPACE)
} // namespace OCF
using namespace OCF;
#endif

//----------------------------------------------------------------------------
// Get core Classlib and Winsys header for supporting defines
//

#define INC_OLE2  // make sure windows.h (via defs.h) gets ole2, not ole1

#if !defined(WINSYS_DEFS_H)
# include <winsys/defs.h>
#endif
#if !defined(WINSYS_WSYSINC_H)
# include <winsys/wsysinc.h>
#endif
#if !defined(SERVICES_CSTRING_H)
# include <services/cstring.h>     // string class
#endif
#if !defined(SERVICES_CHECKS_H)
# include <services/checks.h> // diag macros (PRECONDITION, CHECK, WARN, TRACE)
#endif
#if !defined(WINSYS_EXBASE_H)
# include <winsys/exbase.h>
#endif

//----------------------------------------------------------------------------
// Setup class, function and data modifier macros for OCF
//

#if defined(BI_NAMESPACE)
namespace OCF {
#endif

#if defined(BI_COMP_MSC)
# define __export      __declspec(dllexport)
# define __import      __declspec(dllimport)
#endif
#if defined(_FASTTHIS) && !defined(BI_PTR_0_32)
# define _OCFFASTTHIS  __fastthis
#else
# define _OCFFASTTHIS
#endif
#if defined(_BUILDOCFDLL)
# define _OCFCLASS     __export _OCFFASTTHIS
# define _OCFDATA      __export
# define _OCFFUNC      __export
#elif defined(_OCFDLL)
# define _OCFCLASS     __import _OCFFASTTHIS
# if defined(BI_PTR_0_32)
#   define _OCFDATA    __import
#   define _OCFFUNC    __import
# else
#   define _OCFDATA
#   define _OCFFUNC
# endif
#else
# if defined(BI_PTR_0_32)
#   define _OCFCLASS
# else
#   define _OCFCLASS   __huge _OCFFASTTHIS  // _ICLASS
# endif
# define _OCFDATA
# define _OCFFUNC
#endif

//
// Useful HRESULT constants and test functions
//
#define HR_NOERROR             NOERROR
#define HR_OK                  ResultFromScode(S_OK)  // same as NOERROR
#define HR_FALSE               ResultFromScode(S_FALSE)
#define HR_NOTIMPL             ResultFromScode(E_NOTIMPL)
#define HR_OUTOFMEMORY         ResultFromScode(E_OUTOFMEMORY)
#define HR_INVALIDARG          ResultFromScode(E_INVALIDARG)
#define HR_NOINTERFACE         ResultFromScode(E_NOINTERFACE)
#define HR_POINTER             ResultFromScode(E_POINTER)
#define HR_HANDLE              ResultFromScode(E_HANDLE)
#define HR_ABORT               ResultFromScode(E_ABORT)
#define HR_FAIL                ResultFromScode(E_FAIL)

#define HR_CLASS_NOAGGREGATION ResultFromScode(CLASS_E_NOAGGREGATION)
#define HR_CLASS_CLASSNOTAVAILABLE ResultFromScode(CLASS_E_CLASSNOTAVAILABLE)

#define HR_DISP_MEMBERNOTFOUND ResultFromScode(DISP_E_MEMBERNOTFOUND)
#define HR_DISP_BADPARAMCOUNT  ResultFromScode(DISP_E_BADPARAMCOUNT)
#define HR_DISP_BADVARTYPE     ResultFromScode(DISP_E_BADVARTYPE)
#define HR_DISP_OVERFLOW       ResultFromScode(DISP_E_OVERFLOW)
#define HR_DISP_TYPEMISMATCH   ResultFromScode(DISP_E_TYPEMISMATCH)
#define HR_DISP_PARAMNOTFOUND  ResultFromScode(DISP_E_PARAMNOTFOUND)
#define HR_DISP_PARAMNOTOPTIONAL ResultFromScode(DISP_E_PARAMNOTOPTIONAL)
#define HR_DISP_EXCEPTION      ResultFromScode(DISP_E_EXCEPTION)
#define HR_DISP_OVERFLOW       ResultFromScode(DISP_E_OVERFLOW)
#define HR_DISP_UNKNOWNINTERFACE ResultFromScode(DISP_E_UNKNOWNINTERFACE)
#define HR_DISP_UNKNOWNNAME    ResultFromScode(DISP_E_UNKNOWNNAME)

#define HR_TYPE_INVALIDSTATE   ResultFromScode(TYPE_E_INVALIDSTATE)
#define HR_TYPE_WRONGTYPEKIND  ResultFromScode(TYPE_E_WRONGTYPEKIND)
#define HR_TYPE_LIBNOTREGISTERED ResultFromScode(TYPE_E_LIBNOTREGISTERED)
#define HR_TYPE_ELEMENTNOTFOUND ResultFromScode(TYPE_E_ELEMENTNOTFOUND)
#define HR_TYPE_UNSUPFORMAT    ResultFromScode(TYPE_E_UNSUPFORMAT)

#define HR_DATA_FORMATETC      ResultFromScode(DATA_E_FORMATETC)
#define HR_DV_FORMATETC        ResultFromScode(DV_E_FORMATETC)
#define HR_DATA_SAMEFORMATETC  ResultFromScode(DATA_S_SAMEFORMATETC)

#define HR_MK_NOOBJECT         ResultFromScode(MK_E_NOOBJECT)
#define HR_MK_NOSTORAGE        ResultFromScode(MK_E_NOSTORAGE)
#define HR_MK_UNAVAILABLE      ResultFromScode(MK_E_UNAVAILABLE)

#define HR_OLE_STATIC          ResultFromScode(OLE_E_STATIC)
#define HR_OLE_NOT_INPLACEACTIVE ResultFromScode(OLE_E_NOT_INPLACEACTIVE)
#define HR_OLEOBJ_INVALIDVERB  ResultFromScode(OLEOBJ_S_INVALIDVERB)
#define HR_OLE_USEREG          ResultFromScode(OLE_S_USEREG)

#define HR_RPC_CALL_REJECTED   ResultFromScode(RPC_E_CALL_REJECTED)
#define HR_STG_CANTSAVE        ResultFromScode(STG_E_CANTSAVE)

// Return result codes based on bool expression
//
inline HRESULT HRFailIfZero(int bexpr) {return bexpr ? HR_NOERROR : HR_FAIL;}
inline HRESULT HRFalseIfZero(int bexpr) {return bexpr ? HR_OK : HR_FALSE;}

// Return bool based on hresult test
//
inline bool HRSucceeded(HRESULT hr) {return static_cast<bool>((SCODE)hr >= 0);}
inline bool HRIsOK(HRESULT hr) {return static_cast<bool>(hr == HR_OK);}

#if defined(BI_NAMESPACE)
} // namespace OCF
using namespace OCF;
#endif

#if defined(BI_NAMESPACE)
# define NS_CLASSLIB ClassLib
# define NS_OCF OCF
#else
# define NS_CLASSLIB
# define NS_OCF
#endif

#endif  // OCF_DEFS_H
