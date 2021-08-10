//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Definition of base most abstract GDI object class
//----------------------------------------------------------------------------
#if !defined(OWL_GDIBASE_H)
#define OWL_GDIBASE_H

#if !defined(OWL_OWLDEFS_H)
# include <owl/owldefs.h>
#endif
#if !defined(OSL_GEOMETRY_H)
# include <osl/geometry.h>
#endif
#if !defined(OWL_COLOR_H)
# include <owl/color.h>
#endif
#if !defined(OWL_EXCEPT_H)
# include <owl/except.h>
#endif

//
// Flag for Handle ctors to control Handle deletion in dtor
//
enum TAutoDelete { NoAutoDelete, AutoDelete };

//
// class TGdiBase
// ----- --------
//
// Root and abstract class for Windows GDI object wrappers.  Provides basic
// notion of working with a GDI handle, and constructing a C++ object with
// an aliased handle.
//
class _OWLCLASS TGdiBase {
  public:
    class _OWLCLASS_RTL TXGdi : public TXOwl {
      public:
        TXGdi(unsigned resId = IDS_GDIFAILURE, HANDLE = 0);
        static string Msg(unsigned resId, HANDLE);
        TXOwl* Clone();
        void Throw();
    };

  protected:
    HANDLE      Handle;       // GDI handle of this object
    bool        ShouldDelete; // Should object delete GDI handle in dtor?

    // throws exception if object is bad
    void        CheckValid(uint resId = IDS_GDIFAILURE);
    static void CheckValid(HANDLE handle, uint resId = IDS_GDIFAILURE);

    // constructors for use by derived classes only
    TGdiBase();
    TGdiBase(HANDLE handle, TAutoDelete autoDelete = NoAutoDelete);
    
    friend class TXGdi;

  private:
    TGdiBase(const TGdiBase&); // Protect against copying & assignment
    TGdiBase& operator=(const TGdiBase&);
};

#endif  // OWL_GDIBASE_H
