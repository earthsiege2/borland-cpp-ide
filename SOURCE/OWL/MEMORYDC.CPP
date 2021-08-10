//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of TMemoryDC and TDibDC encapsulation classes
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/dc.h>

DIAG_DECLARE_GROUP(OwlGDI);        // General GDI diagnostic group

const int MemDCCacheSize = 2;      // Number of mem DCs allocated in the cache

//
// Cache of screen-compatible memory HDCs used automatically by TMemoryDC when
// the default ctor is called. Reduces the amount of HDC creations & allows
// centralized sharing of these memory HDCs
//
class TMemDCCache {
  public:
    struct TEntry {
      HDC   Handle;
      bool  Busy;
    };
    
    TMemDCCache(int numEntries);
   ~TMemDCCache();
    HDC  Get();
    void Release(HDC hDC);

  private:
    TEntry*  Entries;
    int      NumEntries;
};

TMemDCCache::TMemDCCache(int numEntries)
{
  NumEntries = numEntries;
  Entries = new TEntry[NumEntries];

  for (int i = 0; i < NumEntries; i++) {
    Entries[i].Handle = ::CreateCompatibleDC(0);
    Entries[i].Busy = false;
  }
}

TMemDCCache::~TMemDCCache()
{
  for (int i = 0; i < NumEntries; i++) {
    WARNX(OwlGDI, Entries[i].Busy, 0, "Unreleased DC " << 
          hex << uint(Entries[i].Handle) << " in MemDCCache");
    if (Entries[i].Handle)
      ::DeleteDC(Entries[i].Handle);
  }
  delete [] Entries;
}

HDC
TMemDCCache::Get()
{
  for (int i = 0; i < NumEntries; i++)
    if (!Entries[i].Busy) {
      Entries[i].Busy = true;
      return Entries[i].Handle;
    }
  return 0;
}

void
TMemDCCache::Release(HDC hDC)
{
  for (int i = 0; i < NumEntries; i++)
    if (Entries[i].Handle == hDC) {
      WARNX(OwlGDI, !Entries[i].Busy, 0, "Releasing non-busy DC " << 
            hex << uint(Entries[i].Handle) << " in MemDCCache");
      Entries[i].Busy = false;
      return;
    }
}

static TMemDCCache MemDCCache(MemDCCacheSize);

//
// construct a screen-compatible memory DC. Try to get one from the cache first
//
TMemoryDC::TMemoryDC()
:
  TCreatedDC()
{
  Handle = MemDCCache.Get();
  if (Handle)
    ShouldDelete = false;

  else {
    Handle = ::CreateCompatibleDC(0);
    CheckValid();
  }
  OrgBitmap = 0;
}

TMemoryDC::TMemoryDC(const TDC& dc) : TCreatedDC()
{
  Handle = ::CreateCompatibleDC(dc);
  CheckValid();
  OrgBitmap = 0;
}

//
// Use an existing HDC. Delete it on destruction as requested. Allow bitmap
// selection
//
TMemoryDC::TMemoryDC(HDC handle, TAutoDelete autoDelete)
:
  TCreatedDC(handle, autoDelete)
{
}

void
TMemoryDC::SelectObject(const TBitmap& bitmap)
{
  HBITMAP oldBitmap = (HBITMAP)::SelectObject(HDC(Handle), bitmap);
  if (oldBitmap) {
    OBJ_REF_INC(bitmap);
    if ((bool)oldBitmap > 1)
      if (!OrgBitmap)
        OrgBitmap = oldBitmap;
      else
        OBJ_REF_DEC(oldBitmap, false);
  }
}

void
TMemoryDC::RestoreBitmap()
{
  if (OrgBitmap) {
    OBJ_REF_DEC(::SelectObject(HDC(Handle), OrgBitmap), false);
    OrgBitmap = 0;
  }
}

TMemoryDC::~TMemoryDC()
{
  RestoreBitmap();
  RestoreObjects();
  MemDCCache.Release(HDC(Handle));
}
