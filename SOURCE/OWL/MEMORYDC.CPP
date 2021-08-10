//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.8  $
//
// Implementation of TMemoryDC and TDibDC encapsulation classes
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_DC_H)
# include <owl/dc.h>
#endif
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlGDI);        // General GDI diagnostic group

//
// class TMemDCCache
// ~~~~~ ~~~~~~~~~~~
// Cache of screen-compatible memory HDCs used automatically by TMemoryDC when
// the default ctor is called. Reduces the amount of HDC creations & allows
// centralized sharing of these memory HDCs. The cache grows on demand.
//
class TMemDCCache {
  public:
    enum {MaxEntries = 8};          // Max # of mem DCs allowed in the cache

    struct TEntry {
      HDC   Handle;
      bool  Busy;
    };

    TMemDCCache();
   ~TMemDCCache();
    HDC  Get();
    void Release(HDC hDC);

  private:
    TEntry  Entries[MaxEntries];
};

//
//
//
TMemDCCache::TMemDCCache()
{
  for (int i = 0; i < MaxEntries; i++) {
    Entries[i].Handle = 0;
    Entries[i].Busy = false;
  }
}

//
//
//
TMemDCCache::~TMemDCCache()
{
  for (int i = 0; i < MaxEntries && Entries[i].Handle; i++) {
    WARNX(OwlGDI, Entries[i].Busy, 0, "Unreleased DC " <<
          hex << uint(Entries[i].Handle) << " in MemDCCache at destruction");
    ::DeleteDC(Entries[i].Handle);
  }
}

//
// Get a screen compatible memory HDC from the cache, creating one if needed
// and there is room.
//
HDC
TMemDCCache::Get()
{
  for (int i = 0; i < MaxEntries; i++) {
    if (!Entries[i].Handle) {
      // Use a screen dc as reference when constructing the compatible DC
      // since in some rare situations CreateCompatibleDC(0) fails.
      //
      HDC sdc = ::GetWindowDC(0);  
      Entries[i].Handle = ::CreateCompatibleDC(sdc);
      ::ReleaseDC(0, sdc);
    }
    if (!Entries[i].Busy) {
      Entries[i].Busy = true;
      return Entries[i].Handle;
    }
  }
  return 0;  // Cache is full
}

//
//
//
void
TMemDCCache::Release(HDC hDC)
{
  for (int i = 0; i < MaxEntries && Entries[i].Handle; i++) {
    if (Entries[i].Handle == hDC) {
      WARNX(OwlGDI, !Entries[i].Busy, 0, "Releasing non-busy DC " <<
            hex << uint(Entries[i].Handle) << " in MemDCCache");
      Entries[i].Busy = false;
      return;
    }
  }
}

//
//
//
static TMemDCCache&
GetMemDCCache()
{
  static TMemDCCache MemDCCache;
  return MemDCCache;
}

//
// Construct a screen-compatible memory DC. Try to get one from the cache first
//
TMemoryDC::TMemoryDC()
:
  TCreatedDC()
{
  Init();
}

//
// Construct a memory DC compatible with a non-screen DC
//
TMemoryDC::TMemoryDC(const TDC& dc)
:
  TCreatedDC()
{
  Handle = ::CreateCompatibleDC(dc);
  CheckValid();
  OrgBitmap = 0;
}

//
// Construct a TDC using an existing HDC. Delete it on destruction as
// requested.
//
TMemoryDC::TMemoryDC(HDC handle, TAutoDelete autoDelete)
:
  TCreatedDC(handle, autoDelete)
{
}

//
// Construct a screen compatible memory dc & select a bitmap right away
//
TMemoryDC::TMemoryDC(TBitmap& bitmap)
:
  TCreatedDC()
{
  Init();
  SelectObject(bitmap);
}

//
// A protected pass-thru constructor for use by derived classes
//
TMemoryDC::TMemoryDC(const char far* driver, const char far* device,
                     const char far* output, const DEVMODE far* initData)
:
  TCreatedDC(driver, device, output, initData)
{
}

//
// Initialization for screen compatible DC construction
//
void
TMemoryDC::Init()
{
  Handle = GetMemDCCache().Get();
  if (Handle) {
    ShouldDelete = false;              // Found, let the cache own the handle
  }
  else {
    Handle = ::CreateCompatibleDC(0);  // Cache is full, we own the handle
    CheckValid();
  }
  OrgBitmap = 0;
}

//
// Select a bitmap object into this memory DC. This is a new type of object
// selection added on to what TDC can do.
//
void
TMemoryDC::SelectObject(const TBitmap& bitmap)
{
  HBITMAP oldBitmap = (HBITMAP)::SelectObject(HDC(Handle), bitmap);
  if (oldBitmap) {
    TGdiObject::RefInc(bitmap);
    if (uint(oldBitmap) > 1)
      if (!OrgBitmap)
        OrgBitmap = oldBitmap;
      else
        TGdiObject::RefDec(oldBitmap, false);
  }
}

//
// Restore the original bitmap object into this memory DC
//
void
TMemoryDC::RestoreBitmap()
{
  if (OrgBitmap) {
    TGdiObject::RefDec(::SelectObject(HDC(Handle), OrgBitmap), false);
    OrgBitmap = 0;
  }
}

//
// Destruct this memory DC, restoring all originally selected objects &
// releasing our handle if it may have been from the cache
//
TMemoryDC::~TMemoryDC()
{
  RestoreBitmap();
  RestoreObjects();
  if (!ShouldDelete)  // The HDC is never from the cache if ShouldDelete
    GetMemDCCache().Release(HDC(Handle));
}
