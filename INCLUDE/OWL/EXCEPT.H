//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.8  $
//
// ObjectWindows exception class & function definitions
//----------------------------------------------------------------------------
#if !defined(OWL_EXCEPT_H)
#define OWL_EXCEPT_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(SERVICES_EXCEPT_H)
# include <services/except.h>
#endif
#if !defined(WINSYS_EXBASE_H)
# include <winsys/exbase.h>
#endif
#include <owl/except.rh>

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the
// definition of classes
#include <services/preclass.h>

class _OWLCLASS TModule;
extern TModule* Module;  // Global Module ptr in each DLL/EXE

//
// Global function to handle exceptions in OWL as a last resort
//
int _OWLFUNC HandleGlobalException(xmsg& x, char* caption, char* canResume=0);

//
// class TXOwl
// ~~~~~ ~~~~~
// TXOwl is root class of the ObjectWindows exception hierarchy.
//
class _OWLCLASS_RTL TXOwl : public TXBase {
  public:
    TXOwl(const string& msg, uint resId = 0);
    TXOwl(uint resId, TModule* module = ::Module);
   ~TXOwl();

    // Override TXBase's virtuals
    //
#if defined(BI_NO_COVAR_RET)
    TXBase* Clone();
#else
    TXOwl* Clone();
#endif
    void Throw();

    // Per-exception class unhandled-handler, will default to the per-module
    // unhandled-handler
    //
    virtual int Unhandled(TModule* appModule, uint promptResId);

    uint GetErrorCode() const;

    static string ResourceIdToString(bool* found, uint resId,
                                     TModule* module = ::Module);
    static string MakeMessage(uint resId, const char far* infoStr, TModule* module = ::Module);
    static string MakeMessage(uint resId, uint infoNum, TModule* module = ::Module);

    static void Raise(const string& msg, uint resId = 0);
    static void Raise(uint resId, TModule* module = ::Module);

  public:
    uint ResId;
};

//
// class TXOutOfMemory
// ~~~~~ ~~~~~~~~~~~~~
class _OWLCLASS_RTL TXOutOfMemory : public TXOwl {
  public:
    TXOutOfMemory();

#if defined(BI_NO_COVAR_RET)
    TXBase* Clone();
#else
    TXOutOfMemory* Clone();
#endif
    void   Throw();

    static void Raise();
};


// Generic definitions/compiler options (eg. alignment) following the
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} //namespace OWL
#endif

#if defined(OWL1_COMPAT)

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

//----------------------------------------------------------------------------
// Owl 1.0 compatibility exception classes
//

//
// class TXCompatibility
// ~~~~~ ~~~~~~~~~~~~~~~
class _OWLCLASS_RTL TXCompatibility : public TXOwl {
  public:
    TXCompatibility(int statusCode);
    TXCompatibility(const TXCompatibility& src);

#if defined(BI_NO_COVAR_RET)
    TXBase* Clone();
#else
    TXCompatibility* Clone();
#endif
    void             Throw();
    int              Unhandled(TModule* app, uint promptResId);

    static string MapStatusCodeToString(int statusCode);

    // Member containing an OWL-1 compatible status code representing
    // an error condition.
    //
    int Status;
};

//
// class TStatus
// ~~~~~ ~~~~~~~
class _OWLCLASS TStatus {
  public:
    TStatus();
    TStatus& operator =(int statusCode);
    operator int() const;

  private:
    void Set(int statusCode);
    int  StatusCode;
};

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline implementations
//

//
inline TStatus::TStatus() {
  StatusCode = 0;
}

//
inline TStatus& TStatus::operator =(int statusCode) {
  Set(statusCode);
  return *this;
}

//
inline TStatus::operator int() const {
  return StatusCode;
}

#endif  // if defined(OWL1_COMPAT)

//
inline uint TXOwl::GetErrorCode() const {
  return ResId;
}

#endif  // OWL_EXCEPT_H
