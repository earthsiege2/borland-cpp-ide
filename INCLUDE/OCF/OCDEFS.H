//
//----------------------------------------------------------------------------
// ObjectComponents
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//   ObjectComponents fundamental definitions
//----------------------------------------------------------------------------
#if !defined(OCF_OCDEFS_H)
#define OCF_OCDEFS_H

//
// We must use all libraries as DLLs if we are using OCF as a DLL
//
// Define _OCFDLL with -WSE (-WE for 32bit) to use BIDS & RTL in dlls.
//
// Be sure _BUILDOCFDLL is defined when building an actual OCF dll
//
#if defined(_OCFDLL) || defined(_BUILDOCFDLL)
#  if !defined(_OCFDLL)
#    define _OCFDLL
#  endif
#  if !defined(_BIDSDLL)
#    define _BIDSDLL
#  endif
#  if !defined(_RTLDLL)
#    define _RTLDLL
#  endif
#endif

//
// Define macros for OCF class, data & functions modifiers
//
#if defined(_FASTTHIS) && !defined(__FLAT__)
#  define _OCFFASTTHIS __fastthis
#else
#  define _OCFFASTTHIS
#endif
#if defined(_BUILDOCFDLL)
#  define _OCFCLASS     _OCFFASTTHIS  __export
#  define _OCFDATA      __export
#  define _OCFFUNC      __export
#elif defined(_OCFDLL)
#  define _OCFCLASS     _OCFFASTTHIS  __import
#  if defined(__FLAT__)
#    define _OCFDATA      __import
#    define _OCFFUNC      __import
#  else
#    define _OCFDATA
#    define _OCFFUNC
#  endif
#else
#  if defined(__FLAT__)
#    define _OCFCLASS
#  else
#    define _OCFCLASS     _OCFFASTTHIS __huge  // _ICLASS
#  endif
#  define _OCFDATA
#  define _OCFFUNC
#endif

#define INC_OLE2  // make sure windows.h (via defs.h) gets ole2, not ole1

#if !defined(OSL_DEFS_H)
# include <osl/defs.h>
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
#if !defined(OSL_EXCEPT_H)
# include <osl/except.h>
#endif
#if !defined(OCF_OLEUTIL_H)
# include <ocf/oleutil.h>
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

//
// Base OC exception class
//
class TXObjComp : public TXOle {
  public:
    enum TError {
      xNoError,             // App errors
      xBOleLoadFail,
      xBOleVersFail,
      xBOleBindFail,
      xDocFactoryFail,
      xMissingRootIStorage, // doc and part errors
      xInternalPartError,
      xPartInitError,
      xRootStorageOpenError,// storage errors
      xStorageOpenError,
      xStorageILockError,
      xStreamOpenError,
    };
    TXObjComp(TError err, const string& msg, HRESULT stat = HR_FAIL)
      : TXOle(msg, stat), ErrorCode(err) {}
    TXObjComp(const TXObjComp& src)
      : TXOle(src), ErrorCode(src.ErrorCode) {}
   ~TXObjComp();

    TXObjComp* Clone();
    void       Throw();

    static void Check(HRESULT stat, TError err, const char far* msg = 0);
    static void Throw(TError err, HRESULT stat = HR_FAIL, const char far* msg = 0);

    const TError ErrorCode;
};

#endif  // OCF_OCDEFS_H

