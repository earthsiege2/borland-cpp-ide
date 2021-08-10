//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation for GDI Brush object
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/gdiobjec.h>

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
    ShouldDelete = false;
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
        hex << (uint)(HBITMAP)pattern);
  CheckValid();
  OBJ_REF_ADD(Handle, Brush);
}

TBrush::TBrush(const TDib& pattern)
{
  // This calls is 16/32 independent (& avoids Win32s not-implemented problem)
  //
#if (0)  // Extra step using hbitmap required for some Win32 versions
  TBitmap bm(pattern);
  LOGBRUSH lb = { BS_PATTERN, 0, (int)HANDLE(bm) };
  Handle = ::CreateBrushIndirect(&lb);
#else
  Handle = ::CreateDIBPatternBrush(pattern, pattern.Usage());
#endif

  WARNX(OwlGDI, !Handle, 0, "Cannot create pattern TBrush from DIB " <<
        hex << (uint)(HANDLE)pattern);
  CheckValid();
  OBJ_REF_ADD(Handle, Brush);
}

TBrush::TBrush(const LOGBRUSH far* logBrush)
{
  PRECONDITION(logBrush);
  Handle = ::CreateBrushIndirect((LPLOGBRUSH)logBrush);  // API cast
  WARNX(OwlGDI, !Handle, 0, "Cannot create TBrush from logBrush @" <<
        hex << uint32(LPVOID(logBrush)));
  CheckValid();
  OBJ_REF_ADD(Handle, Brush);
}

TBrush::TBrush(const TBrush& src)
{
  LOGBRUSH logBrush;
  src.GetObject(logBrush);
  Handle = ::CreateBrushIndirect(&logBrush);
  WARNX(OwlGDI, !Handle, 0, "Cannot create TBrush from TBrush @" <<
        hex << uint32(LPVOID(&src)));
  CheckValid();
  OBJ_REF_ADD(Handle, Brush);
}

//----------------------------------------------------------------------------

THatch8x8Brush::THatch8x8Brush(const uint8 hatch[], TColor fgColor, TColor bgColor)
  : TBrush(Create(hatch, fgColor, bgColor), AutoDelete)
{
}

//
// reconstructs the brush with a new pattern or colors
//
void
THatch8x8Brush::Reconstruct(const uint8 hatch[], TColor fgColor, TColor bgColor)
{
  if (Handle) {
#if !defined(NO_GDI_ORPHAN_CONTROL)
    OBJ_REF_DEC(Handle, true);
#else
    if (!::DeleteObject(Handle))
      THROW( TXGdi(IDS_GDIDELETEFAIL, Handle) );
#endif
  }
  Handle = Create(hatch, fgColor, bgColor);
  OBJ_REF_ADD(Handle, Brush);
}

//
// private static create member to create or re-create the handle
//
HBRUSH
THatch8x8Brush::Create(const uint8 hatch[], TColor fgColor, TColor bgColor)
{
  TDib dib(8, 8, 2, DIB_RGB_COLORS);
  unsigned char HUGE* bits = (unsigned char HUGE*)dib.GetBits();
  memset(bits, 0, 8*sizeof(uint32));
  for (int i = 0; i < 8; i++)
    bits[(7-i) * sizeof(uint32)] = hatch[i];  // Dib is upside down
  dib.SetColor(0, bgColor);
  dib.SetColor(1, fgColor);

#if (0)  // Extra step using hbitmap required for some Win32 versions
  TBitmap bm(dib);
  LOGBRUSH lb = { BS_PATTERN, DIB_RGB_COLORS, (int)HANDLE(bm) };
  HBRUSH handle = ::CreateBrushIndirect(&lb);
#else
  HBRUSH handle = ::CreateDIBPatternBrush(dib, DIB_RGB_COLORS);
#endif

  CheckValid(handle);
  return handle;
}

//
// Predefined 8x8 hatch patterns
//
const uint8 THatch8x8Brush::Hatch22F1[8] = {
  0x99, 0x33, 0x66, 0xCC, 0x99, 0x33, 0x66, 0xCC
};
const uint8 THatch8x8Brush::Hatch13F1[8] = {
  0x88, 0x11, 0x22, 0x44, 0x88, 0x11, 0x22, 0x44
};
const uint8 THatch8x8Brush::Hatch11F1[8] = {
  0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55
};
const uint8 THatch8x8Brush::Hatch22B1[8] = {
  0xCC, 0x66, 0x33, 0x99, 0xCC, 0x66, 0x33, 0x99
};
const uint8 THatch8x8Brush::Hatch13B1[8] = {
  0x44, 0x22, 0x11, 0x88, 0x44, 0x22, 0x11, 0x88
};

