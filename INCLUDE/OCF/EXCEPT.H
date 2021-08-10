//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1997 by Borland International, All Rights Reserved
//
// $Revision:   2.4  $
//
// OCF Exception classes
//     NOTE: All OCF Exception classes are defined here except for TXAuto,
//           the exception used in automation failures. [See AUTODEFS.H
//           for TXAuto].
//----------------------------------------------------------------------------
#if !defined(OCF_EXCEPT_H)
#define OCF_EXCEPT_H

#if !defined(OCF_DEFS_H)
# include <ocf/defs.h>
#endif
#if !defined(SERVICES_CSTRING_H)
# include <services/cstring.h>
#endif
#if !defined(SERVICES_EXCEPT_H)
# include <services/except.h>
#endif
#if !defined(SERVICES_OLE2INC_H)
# include <services/ole2inc.h>
#endif

#if defined(BI_NAMESPACE)
namespace OCF {
#endif

//
// class TXOle
// ~~~~~ ~~~~~
// OLE API related exception object
//
class TXOle : public TXBase {
  public:
    TXOle(const string& msg, HRESULT stat);
    TXOle(const TXOle& src);
   ~TXOle();

    TXOle*      Clone();
    void        Throw();

    static void Check(HRESULT stat, const char far* msg);
    static void Check(HRESULT stat);
    static void Throw(HRESULT stat, const char far* msg);
    static void OleErrorFromCode(HRESULT stat, char far* buffer, int size);

    const long  Stat;
};

//
//
//
inline
TXOle::TXOle(const string& msg, HRESULT stat)
      : TXBase(msg), Stat((long)stat)
{}

//
//
//
inline TXOle::TXOle(const TXOle& src)
             : TXBase(src), Stat(src.Stat)
{}

//
// Macro to simply error checking of OLE calls
//
#if (__DEBUG > 0) || defined(__WARN)
# define OLECALL(func, msg) TXOle::Check(func, msg)
#else
# define OLECALL(func, msg) TXOle::Check(func)
#endif


//
// class TXObjComp
// ~~~~~ ~~~~~~~~~
// Base OC exception class
//
class TXObjComp : public TXOle {
  public:
    enum TError {

      // Application Errors
      //
      xNoError,
      xBOleLoadFail,
      xBOleVersFail,
      xBOleBindFail,
      xDocFactoryFail,

      // Doc & Part Errors
      //
      xMissingRootIStorage,
      xInternalPartError,
      xPartInitError,

      // Storage Errors
      //
      xRootStorageOpenError,
      xStorageOpenError,
      xStorageILockError,
      xStreamOpenError,
    };

    TXObjComp(TError err, const string& msg, HRESULT stat = HR_FAIL)
      : TXOle(msg, stat), ErrorCode(err) {}
    TXObjComp(const TXObjComp& src)
      : TXOle(src), ErrorCode(src.ErrorCode) {}
   ~TXObjComp();

    TXObjComp*  Clone();
    void        Throw();

    static void Check(HRESULT stat, TError err, const char far* msg = 0);
    static void Throw(TError err, HRESULT stat = HR_FAIL, const char far* msg = 0);

    const TError ErrorCode;
};

#if defined(BI_NAMESPACE)
} // namespace OCF
#endif

#endif  //  OCF_EXCEPT_H
