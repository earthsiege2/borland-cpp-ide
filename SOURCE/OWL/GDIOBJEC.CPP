//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of TGdiObject, abstract GDI object base class
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/gdiobjec.h>

DIAG_DEFINE_GROUP_INIT(OWL_INI, OwlGDI, 1, 0);
                                   // General GDI diagnostic group
DIAG_DEFINE_GROUP_INIT(OWL_INI, OwlGDIOrphan, 1, 0);
                                   // Orphan control tracing group

//
// TGdiObject's internal orphan control object, container and member functions
//
#if !defined(NO_GDI_ORPHAN_CONTROL)

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
  if (!ObjInfoBag)                  // Allocate bag on the first access of it
    ObjInfoBag = new TObjInfoBag;

  return handle ?
           CONST_CAST(TObjInfo*,ObjInfoBag->Find(TObjInfo(handle))) : 0;
}

//
// Add an object reference entry into table, starting ref count at one
//
void
TGdiObject::RefAdd(HANDLE handle, TGdiObject::TType type)
{
  if (handle && !RefFind(handle))
    ObjInfoBag->Add(TObjInfo(handle, type, 1));
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
  TGdiObject::RefDec(HANDLE handle)
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
        THROW( TXGdi(IDS_GDIDELETEFAIL, member->Handle) );
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

#endif  // !defined(NO_GDI_ORPHAN_CONTROL)


//----------------------------------------------------------------------------

//
// TGdiObject constructors
//
TGdiObject::TGdiObject()
{
  // Handle must be set by derived class
}

TGdiObject::TGdiObject(HANDLE handle, TAutoDelete autoDelete)
:
  TGdiBase(handle, autoDelete)
{
  // CheckValid();  // cant do this here, as derived class may set handle later
  // Derived class must call OBJ_REF_ADD(Handle, type) if ShouldDelete
}

TGdiObject::~TGdiObject()
{
  if (ShouldDelete) {
    #if !defined(NO_GDI_ORPHAN_CONTROL)
      OBJ_REF_DEC(Handle, true);
    #else
      if (!::DeleteObject(Handle))
        THROW( TXGdi(IDS_GDIDELETEFAIL, Handle) );
    #endif
  }
}
