//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Definition of base most abstract GDI object class, and associated exception
// class
//----------------------------------------------------------------------------
#if !defined(OWL_GDIBASE_H)
#define OWL_GDIBASE_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(WINSYS_COLOR_H)
# include <winsys/color.h>
#endif
#if !defined(OWL_EXCEPT_H)
# include <owl/except.h>
#endif
#if !defined(CLASSLIB_POINTER_H)
# include <classlib/pointer.h>   // get this header for backward compatibility
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TXGdi
// ~~~~~ ~~~~~
// Base GDI exception class. Handles all GDI related exceptions
//
class _OWLCLASS_RTL TXGdi : public TXOwl {
  public:
    TXGdi(uint resId = IDS_GDIFAILURE, HANDLE handle = 0);

    static string Msg(uint resId, HANDLE);

#if defined(BI_NO_COVAR_RET)
    TXBase* Clone();
#else
    TXGdi* Clone();
#endif
    void Throw();

    static void Raise(uint resId = IDS_GDIFAILURE, HANDLE handle = 0);
};

//
// Flag for Handle ctors to control Handle deletion in dtor
//
enum TAutoDelete { NoAutoDelete, AutoDelete };

//
// class TGdiBase
// ~~~~~ ~~~~~~~~
// Root and abstract class for Windows object wrappers. Provides basic
// notion of working with a handle, and constructing a C++ object with
// an aliased handle.
//
class _OWLCLASS TGdiBase {
  protected:
    HANDLE      Handle;       // GDI handle of this object
    bool        ShouldDelete; // Should object delete GDI handle in dtor?

    // Throws exception if object is bad
    //
    void        CheckValid(uint resId = IDS_GDIFAILURE);
    static void CheckValid(HANDLE handle, uint resId = IDS_GDIFAILURE);

    // Constructors for use by derived classes only
    //
    TGdiBase();
    TGdiBase(HANDLE handle, TAutoDelete autoDelete = NoAutoDelete);

  private:
    TGdiBase(const TGdiBase&); // Protect against copying & assignment
    TGdiBase& operator =(const TGdiBase&);

#if defined(OWL2_COMPAT)
  public:
    typedef ::TXGdi TXGdi;  // Exceptions moved to global scope
#endif
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

#endif  // OWL_GDIBASE_H
