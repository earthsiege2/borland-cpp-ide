//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\brush.cpp
//   Implementation for GDI Brush object
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\gdiobjec.h>

DIAG_DECLARE_GROUP(OwlGDI);        // General GDI diagnostic group

//
// internal brush cache to keep most common brushes around cached by color
//

class TBrushCache {
  public:
    struct TEntry {
      HBRUSH  Handle;
      TColor  Color;
      
      TEntry(HANDLE handle) {Handle = (HBRUSH)handle;}
    };
    
    TBrushCache(TEntry* entries, int numEntries);
    HBRUSH Lookup(TColor color);

  private:
    TEntry*  Entries;
    int      NumEntries;
};

TBrushCache::TBrushCache(TEntry* entries, int numEntries)
{
  Entries = entries;
  NumEntries = numEntries;

  for (int i = 0; i < NumEntries; i++) {
    LOGBRUSH logBrush;
    if (GetObject(Entries[i].Handle, sizeof(LOGBRUSH), &logBrush))
      Entries[i].Color = logBrush.lbColor;
  }
}

HBRUSH
TBrushCache::Lookup(TColor color)
{
  for (int i = 0; i < NumEntries; i++)
    if (color == Entries[i].Color)
      return Entries[i].Handle;
  return 0;
}

//
// Static instance of a brush cache table & the cache itself
//
static TBrushCache::TEntry BrushCacheEntries[] = {
  {::GetStockObject(BLACK_BRUSH)},
  {::GetStockObject(DKGRAY_BRUSH)},
  {::GetStockObject(GRAY_BRUSH)},
  {::GetStockObject(LTGRAY_BRUSH)},
  {::GetStockObject(WHITE_BRUSH)}
};
static TBrushCache BrushCache(BrushCacheEntries, COUNTOF(BrushCacheEntries));

//
// Constructors
//
TBrush::TBrush(HBRUSH handle, TAutoDelete autoDelete)
  : TGdiObject(handle, autoDelete)
{
  #if !defined(NO_GDI_ORPHAN_CONTROL)
    if (ShouldDelete)
      OBJ_REF_ADD(Handle, Brush);
  #endif
}

TBrush::TBrush(TColor color)
{
  if ((Handle = BrushCache.Lookup(color)) != 0) {
    ShouldDelete = FALSE;
    return;
  }
  Handle = ::CreateSolidBrush(color);
  WARNX(OwlGDI, !Handle, 0, "Cannot create solid TBrush " << hex << color);
  CheckValid();
  OBJ_REF_ADD(Handle, Brush);
}

TBrush::TBrush(TColor color, int style)
{
  Handle = ::CreateHatchBrush(style, color);
  WARNX(OwlGDI, !Handle, 0, "Cannot create hatch TBrush " << hex << color <<
        " " << style);
  CheckValid();
  OBJ_REF_ADD(Handle, Brush);
}

TBrush::TBrush(const TBitmap& pattern)
{
  Handle = ::CreatePatternBrush(pattern);
  WARNX(OwlGDI, !Handle, 0, "Cannot create pattern TBrush from bitmap " <<
        hex << (UINT)(HBITMAP)pattern);
  CheckValid();
  OBJ_REF_ADD(Handle, Brush);
}

TBrush::TBrush(const TDib& pattern)
{
  #if defined(__WIN32__)
    Handle = ::CreateDIBPatternBrushPt((LPVOID)(const BITMAPINFO far*)pattern,
                                       pattern.Usage());
  #else
    Handle = ::CreateDIBPatternBrush(pattern, pattern.Usage());
  #endif
  WARNX(OwlGDI, !Handle, 0, "Cannot create pattern TBrush from DIB " <<
        hex << (UINT)(HANDLE)pattern);
  CheckValid();
  OBJ_REF_ADD(Handle, Brush);
}

TBrush::TBrush(const LOGBRUSH far* logBrush)
{
  PRECONDITION(logBrush);
  Handle = ::CreateBrushIndirect((LPLOGBRUSH)logBrush);  // API cast
  WARNX(OwlGDI, !Handle, 0, "Cannot create TBrush from logBrush @" <<
        hex << DWORD(LPVOID(logBrush)));
  CheckValid();
  OBJ_REF_ADD(Handle, Brush);
}

TBrush::TBrush(const TBrush& src)
{
  LOGBRUSH logBrush;
  src.GetObject(logBrush);
  Handle = ::CreateBrushIndirect(&logBrush);
  WARNX(OwlGDI, !Handle, 0, "Cannot create TBrush from TBrush @" <<
        hex << DWORD(LPVOID(&src)));
  CheckValid();
  OBJ_REF_ADD(Handle, Brush);
}
