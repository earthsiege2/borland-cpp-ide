//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Implementation of TGdiObject, abstract class for GDI objects that can be
// selected into TDCs
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif

DIAG_DEFINE_GROUP_INIT(OWL_INI, OwlGDI, 1, 0);
                                   // General GDI diagnostic group
DIAG_DEFINE_GROUP_INIT(OWL_INI, OwlGDIOrphan, 1, 0);
                                   // Orphan control tracing group

//
// TGdiObject's internal orphan control object, container and member functions
//
#include <classlib/bags.h>

struct TObjInfo {
  HANDLE            Handle;
  TGdiObject::TType Type : 8;
  int               RefCount : 8;

  TObjInfo() : Handle(0), Type(TGdiObject::None), RefCount(0) {}
  TObjInfo(HANDLE handle) : Handle(handle) {}
  TObjInfo(HANDLE handle, TGdiObject::TType type, int ref)
    : Handle(handle), Type(type), RefCount(ref) {}
  bool operator ==(const TObjInfo& other) const {
    return other.Handle == Handle;
  }
};

typedef TBagAsVector<TObjInfo> TObjInfoBag;
static TObjInfoBag* ObjInfoBag;

#if defined(__TRACE)
const static char* ObjTypeStr[] = {
  "?", "Pen", "Brush", "Font", "Palette", "Bitmap", "TextBrush", 0
};
#endif

//
// Find a reference to a given handle in the ObjInfoBag
//
TObjInfo*
TGdiObject::RefFind(HANDLE handle)
{
  if (!ObjInfoBag)
    return 0;

  return handle ?
           CONST_CAST(TObjInfo*,ObjInfoBag->Find(TObjInfo(handle))) : 0;
}

//
// Add an object reference entry into table, starting ref count at one
//
void
TGdiObject::RefAdd(HANDLE handle, TGdiObject::TType type)
{
  if (handle && !RefFind(handle)) {
    if (!ObjInfoBag)
      ObjInfoBag = new TObjInfoBag;
    ObjInfoBag->Add(TObjInfo(handle, type, 1));
  }
}

//
// Remove an object reference entry from table
//
void
TGdiObject::RefRemove(HANDLE handle)
{
  ObjInfoBag->Detach(TObjInfo(handle));
  if (ObjInfoBag->GetItemsInContainer() == 0) {
    delete ObjInfoBag;
    ObjInfoBag = 0;
  }
}

//
// Increment an object reference entry's ref count
//
void
TGdiObject::RefInc(HANDLE handle)
{
  TObjInfo* member = RefFind(handle);
  if (member)
    member->RefCount++;
}

//
// Decrement an object reference entry's ref count.  Delete object if
// refcount goes to zero.  Warn if deletion was/wasn't supposed to
// happen and it didn't/did. Detach info if object was deleted.
//
void
#if defined(__TRACE)
TGdiObject::RefDec(HANDLE handle, bool wantDelete)
#else
TGdiObject::RefDec(HANDLE handle, bool)
#endif
{
  TObjInfo* member = RefFind(handle);
  if (member) {
    bool needDelete = --(member->RefCount) == 0;
#if defined(__TRACE)
    if (needDelete != wantDelete) {
      if (needDelete)
        TRACEX(OwlGDIOrphan, 1, "Orphan" << ObjTypeStr[member->Type] <<
               (uint)member->Handle << "Deleted")
      else
        TRACEX(OwlGDIOrphan, 1, ObjTypeStr[member->Type] <<
               (uint)member->Handle << "Orphan")
    }
#endif
    if (needDelete) {
      if (!::DeleteObject(member->Handle))
        TXGdi::Raise(IDS_GDIDELETEFAIL, member->Handle);
      ObjInfoBag->Detach(*member);
      if (ObjInfoBag->GetItemsInContainer() == 0) {
        delete ObjInfoBag;
        ObjInfoBag = 0;
      }
    }
  }
}

//
// Return the reference count of a handle, -1 if not found
//
int
TGdiObject::RefCount(HANDLE handle)
{
  TObjInfo* member = RefFind(handle);
  if (member)
    return member->RefCount;
  return -1;
}

//----------------------------------------------------------------------------

//
//
//
#if defined(__TRACE) || defined(__WARN)
  ostream& operator <<(ostream& os, const TGdiObject& gdiObject)
  {
    os << "@" << (void*)&gdiObject << " ";
    os << '(';
# if !defined(BI_NO_RTTI)
      os << typeid(gdiObject).name() << ',';
# endif
    os << ')';
    return os;
  }
#endif

//
// TGdiObject constructors
//
TGdiObject::TGdiObject()
{
  // Handle must be set by derived class
  TRACEX(OwlGDI, 2, "TGdiObject constructed " << *this);
}

//
// Create a wrapper for a given GDI object.
//
TGdiObject::TGdiObject(HANDLE handle, TAutoDelete autoDelete)
:
  TGdiBase(handle, autoDelete)
{
  // CheckValid();  // cant do this here, as derived class may set handle later
  // Derived class must call RefAdd(Handle, type) if ShouldDelete
  TRACEX(OwlGDI, 2, "TGdiObject constructed " << *this);
}

//
// Decrement the reference count on this object.
//
TGdiObject::~TGdiObject()
{
  if (ShouldDelete)
    RefDec(Handle, true);
  TRACEX(OwlGDI, 2, "TGdiObject destructed " << *this);
}


