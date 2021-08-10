//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.16  $
//
// Implementation for TBrush GDI Brush object. Includes cache for solid brushes
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlGDI);        // General GDI diagnostic group

#define CACHE_SIZE 8

#if !defined(SECTION) || SECTION == 1

//
// Internal MRU brush cache to keep most recent solid brushes around cached by
// color
//
class TBrushCache {
  public:
    struct TEntry {
      HANDLE   Handle;
      COLORREF Color;
    };

    TBrushCache();
   ~TBrushCache();

    static HANDLE Lookup(COLORREF color);
    static void   Float(int i);
    static void   Add(HANDLE handle, COLORREF color);

  private:
    static TEntry Entries[CACHE_SIZE];
    static int Size;
};

//
// Static data members
//
int TBrushCache::Size = CACHE_SIZE;

//
// Initialize all entries to 0.
//
TBrushCache::TEntry TBrushCache::Entries[CACHE_SIZE] = {{0, 0}};


//
//
//
TBrushCache::TBrushCache()
{
}


//
//
//
TBrushCache::~TBrushCache()
{
  for (int i = 0; i < Size; i++)
    if (Entries[i].Handle) {
      TGdiObject::RefDec(Entries[i].Handle, false);
      Entries[i].Handle = 0;
    }
}

//
// Move an entry to the front, shifting in between ones down
//
void
TBrushCache::Float(int i)
{
  HANDLE handle = Entries[i].Handle;
  COLORREF color = Entries[i].Color;

  TRACEX(OwlGDI, 2, "TBrushCache::Float(" << i << ") (" <<
    hex << uint(handle) << ", " << hex << color << ")");

  memmove(Entries+1, Entries, sizeof(TEntry)*i);
  Entries[0].Handle = handle;
  Entries[0].Color = color;
}

//
// Add a new entry to the front, pushing the last old one off the end.
//
void
TBrushCache::Add(HANDLE handle, COLORREF color)
{
  TRACEX(OwlGDI, 2, "TBrushCache::Add(" << hex << uint(handle) <<
    ", " << hex << color << ")");
  CHECK(Size > 1);

  if (Entries[Size-1].Handle)
    TGdiObject::RefDec(Entries[Size-1].Handle, false);  

  memmove(Entries+1, Entries, sizeof(TEntry)*(Size-1));
  Entries[0].Handle = handle;
  Entries[0].Color = color;
  TGdiObject::RefAdd(handle, TGdiObject::Brush);
}

//
// Lookup a color in the cache, returning the handle if found
//
HANDLE
TBrushCache::Lookup(COLORREF color)
{
  for (int i = 0; i < Size && Entries[i].Handle; i++)
    if (color == Entries[i].Color) {
      TRACEX(OwlGDI, 2, "TBrushCache::Lookup(" << hex << color <<
        "): found " << hex << uint(Entries[i].Handle) << " @" << i);
      Float(i);
      return Entries[0].Handle;  // After Float() our entry is at 0!
    }
  TRACEX(OwlGDI, 2, "TBrushCache::Lookup(" << hex << color << "): not found");
  return 0;
}

//
// Static instance of the brush cache used by TBrush
//
static TBrushCache& GetBrushCache() 
{
  static TBrushCache BrushCache;
  return BrushCache;
};

//
// Constructors
//

//
// Alias an existing brush handle. Assume ownership if autoDelete says so
//
TBrush::TBrush(HBRUSH handle, TAutoDelete autoDelete)
:
  TGdiObject(handle, autoDelete)
{
  if (ShouldDelete)
    RefAdd(Handle, Brush);
  TRACEX(OwlGDI, OWL_CDLEVEL, "TBrush constructed @" << (void*)this <<
                              " with handle " << uint(handle));
}

//
// Construct a brush from a solid color. Gets handle from the cache if found,
// otherwise create the brush and add it to the cache
//
TBrush::TBrush(const TColor& color)
{
  ShouldDelete = false;

#if 0  
  if (color.IsSysColor())
    Handle = ::GetSysColorBrush(color.Index());
  else
#endif
  {
    COLORREF cr = color;
    if ((Handle = GetBrushCache().Lookup(cr)) != 0)
      return;
    Handle = ::CreateSolidBrush(cr);
  }
  WARNX(OwlGDI, !Handle, 0, "Cannot create solid TBrush " << hex << color);
  CheckValid();

  GetBrushCache().Add(Handle, color);

  TRACEX(OwlGDI, OWL_CDLEVEL, "TBrush constructed @" << (void*)this <<
                              " with color " << (COLORREF)color);
}

//
// Construct a hatch brush of a given color and hatch style
//
TBrush::TBrush(const TColor& color, int style)
{
  Handle = ::CreateHatchBrush(style, color);
  WARNX(OwlGDI, !Handle, 0, "Cannot create hatch TBrush " << hex << color <<
                            " " << style);
  CheckValid();
  RefAdd(Handle, Brush);
  TRACEX(OwlGDI, OWL_CDLEVEL, "TBrush constructed @" << (void*)this <<
                              " with color " << (COLORREF)color <<
                              ", style 0x" << style);
}

//
// Construct a pattern brush given a TBitmap
//
TBrush::TBrush(const TBitmap& pattern)
{
  Handle = ::CreatePatternBrush(pattern);
  WARNX(OwlGDI, !Handle, 0, "Cannot create pattern TBrush from bitmap " <<
        hex << (uint)(HBITMAP)pattern);
  CheckValid();
  RefAdd(Handle, Brush);
  TRACEX(OwlGDI, OWL_CDLEVEL, "TBrush constructed @" << (void*)this <<
                              " from bitmap @" << (void*)&pattern);
}

//
// Construct a brush from a logical brush definition
//
TBrush::TBrush(const LOGBRUSH far* logBrush)
{
  PRECONDITION(logBrush);
  Handle = ::CreateBrushIndirect((LPLOGBRUSH)logBrush);  // API cast
  WARNX(OwlGDI, !Handle, 0, "Cannot create TBrush from logBrush @" <<
        hex << uint32(LPVOID(logBrush)));
  CheckValid();
  RefAdd(Handle, Brush);
  TRACEX(OwlGDI, OWL_CDLEVEL, "TBrush constructed @" << (void*)this <<
                              " from logBrush @" << (void*)logBrush);
}

//
// Construct a copy of an existing brush. Contructed brush will share the
// handle unless NO_GDI_SHARE_HANDLES is defined, in which case a new handle is
// created
//
TBrush::TBrush(const TBrush& src)
{
#if !defined(NO_GDI_SHARE_HANDLES)
  Handle = src.Handle;
  RefAdd(Handle, Brush);
#else
  LOGBRUSH logBrush;
  src.GetObject(logBrush);
  Handle = ::CreateBrushIndirect(&logBrush);
  WARNX(OwlGDI, !Handle, 0, "Cannot create TBrush from TBrush @" <<
        hex << uint32(LPVOID(&src)));
  CheckValid();
  RefAdd(Handle, Brush);
#endif
  TRACEX(OwlGDI, OWL_CDLEVEL, "Copy constructed TBrush @" << (void*)this <<
                              " from TBrush @" << (void*)&src);
}

//
// Destroy the C++ object.
//
TBrush::~TBrush()
{
  TRACEX(OwlGDI, OWL_CDLEVEL, "TBrush destructed @" << (void*)this);
}
#endif

#if !defined(SECTION) || SECTION == 2

//
// Construct a pattern brush given a TDib
//
TBrush::TBrush(const TDib& pattern)
{
  Handle = ::CreateDIBPatternBrush(pattern, pattern.Usage());
  WARNX(OwlGDI, !Handle, 0, "Cannot create pattern TBrush from DIB " <<
        hex << (uint)(HANDLE)pattern);
  CheckValid();
  RefAdd(Handle, Brush);
  TRACEX(OwlGDI, OWL_CDLEVEL, "TBrush constructed @" << (void*)this <<
                              " from DIB @" << (void*)&pattern);
}

//----------------------------------------------------------------------------

//
// Create a hatch brush.
//
THatch8x8Brush::THatch8x8Brush(const uint8 hatch[], const TColor& fgColor, const TColor& bgColor)
:
  TBrush(Create(hatch, fgColor, bgColor), AutoDelete)
{
}

//
// Reconstructs the brush with a new pattern or colors
//
void
THatch8x8Brush::Reconstruct(const uint8 hatch[], const TColor& fgColor, const TColor& bgColor)
{
  if (Handle)
    RefDec(Handle, true);

  Handle = Create(hatch, fgColor, bgColor);
  RefAdd(Handle, Brush);
}

//
// Private static create member to create or re-create the handle
//
HBRUSH
THatch8x8Brush::Create(const uint8 hatch[], const TColor& fgColor, const TColor& bgColor)
{
  TDib dib(8, 8, 2, DIB_RGB_COLORS);
  uchar HUGE* bits = (uchar HUGE*)dib.GetBits();
  memset(bits, 0, 8*sizeof(uint32));
  for (int i = 0; i < 8; i++)
    bits[(7-i) * sizeof(uint32)] = hatch[i];  // Dib is upside down
  dib.SetColor(0, bgColor);
  dib.SetColor(1, fgColor);

#if 0  // Extra step using hbitmap required for some old Win32 versions
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

#endif
