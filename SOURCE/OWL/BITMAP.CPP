//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.7  $
//
// Implementation of GDI Bitmap object class
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif
#if !defined(OWL_METAFILE_H)
# include <owl/metafile.h>
#endif
#if !defined(OWL_CLIPBOAR_H)
# include <owl/clipboar.h>
#endif


OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlGDI);        // General GDI diagnostic group
DIAG_DECLARE_GROUP(OwlGDIOrphan);  // Orphan control tracing group

//
// Construct an alias TBitmap for an existing bitmap handle
//
TBitmap::TBitmap(HBITMAP handle, TAutoDelete autoDelete)
:
  TGdiObject(handle, autoDelete)
{
  if (ShouldDelete)
    RefAdd(Handle, Bitmap);
  TRACEX(OwlGDI, OWL_CDLEVEL, "TBitmap constructed @" << (void*)this);
}

//
// Create an empty bitmap.
//
TBitmap::TBitmap()
:
  TGdiObject()
{
  TRACEX(OwlGDI, OWL_CDLEVEL, "Default TBitmap constructed @" << (void*)this);
}

//
// Create a copy of the bitmap found on the clipboard.
//
TBitmap::TBitmap(const TClipboard& clipboard)
:
  TGdiObject(clipboard.GetClipboardData(CF_BITMAP))
{
  RefAdd(Handle, Bitmap);
  RefInc(Handle);
  TRACEX(OwlGDI, OWL_CDLEVEL, "TBitmap constructed @" << (void*)this << " from clipboard.");
}

//
// Convenient constructor to create a bitmap with specified parameters.
//
TBitmap::TBitmap(int width, int height, uint8 planes, uint8 bitCount, const void far* bits)
{
  Handle = ::CreateBitmap(width, height, planes, bitCount, bits);
  WARNX(OwlGDI, !Handle, 0, "Cannot create bitmap (" << width << "x" <<
        height << "x" << planes << ")");
  CheckValid();
  RefAdd(Handle, Bitmap);
  TRACEX(OwlGDI, OWL_CDLEVEL, "TBitmap constructed @" << (void*)this << " using parameters (" <<
         dec << width << "x" << height << "x" << planes << ")." << hex);
}

//
// Create via an indirect pointer to a BITMAP structure.
//
TBitmap::TBitmap(const BITMAP far* bitmap)
{
  PRECONDITION(bitmap);
  Handle = ::CreateBitmapIndirect((LPBITMAP)bitmap);  // API cast
  WARNX(OwlGDI, !Handle, 0, "Cannot create bitmap from BITMAP @" <<
        hex << (void*)bitmap);
  CheckValid();
  RefAdd(Handle, Bitmap);
  TRACEX(OwlGDI, OWL_CDLEVEL, "TBitmap constructed @" << (void*)this << " from BITMAP @" <<
         (void*)bitmap << ".");
}

//
// Create a discardable bitmap from the DC.
//
TBitmap::TBitmap(const TDC& dc, int width, int height, bool discardable)
{
  if (discardable) {
    Handle = ::CreateDiscardableBitmap(dc, width, height);
    WARNX(OwlGDI, !Handle, 0, "Cannot create discardable bitmap (" << width <<
          "x" << height << ") for " << hex << (uint)(HDC)dc);
  }
  else {
    Handle = ::CreateCompatibleBitmap(dc, width, height);
    WARNX(OwlGDI, !Handle, 0, "Cannot create compatible bitmap (" << width <<
          "x" << height << ") for " << hex << (uint)(HDC)dc);
  }
  CheckValid();
  RefAdd(Handle, Bitmap);

  if (discardable) {
    TRACEX(OwlGDI, OWL_CDLEVEL, "Discardable TBitmap constructed @" << (void*)this << " (" <<
           dec << width << "x" << height << ") for " << hex << (uint)(HDC)dc << ".");
  }
  else  {
    TRACEX(OwlGDI, OWL_CDLEVEL, "Compatible TBitmap constructed @" << (void*)this << " (" <<
           dec << width << "x" << height << ") for " << hex << (uint)(HDC)dc << ".");
  }
}

//
// Create a bitmap from the device independent bitmap.
//
TBitmap::TBitmap(const TDC& dc, const TDib& dib, uint32 usage)
{
  Handle = ::CreateDIBitmap(dc,
                            (BITMAPINFOHEADER far*)dib.GetInfoHeader(),
                            usage, (const uint8 FAR*)dib.GetBits(),
                            (BITMAPINFO far*)dib.GetInfo(),
                            dib.Usage());
                            // API casts
  WARNX(OwlGDI, !Handle, 0, "Cannot create bitmap from DIB " << hex <<
        (uint)(HANDLE)dib << " for " << (uint)(HDC)dc);
  CheckValid();
  RefAdd(Handle, Bitmap);
  TRACEX(OwlGDI, OWL_CDLEVEL, "TBitmap constructed @" << (void*)this <<
         " from DIB for " << (uint)(HDC)dc << ".");
}

//
// Load bitmap from resource.
//
TBitmap::TBitmap(HINSTANCE instance, TResId resId)
{
  Handle = ::LoadBitmap(instance, resId);
  WARNX(OwlGDI, !Handle, 0, "Cannot load bitmap " << resId << " from " <<
        hex << (uint)instance);
  CheckValid();
  RefAdd(Handle, Bitmap);
  TRACEX(OwlGDI, OWL_CDLEVEL, "TBitmap constructed from resource @" << (void*)this << ".");
}

//
// Copy constructor, duplicates a bitmap, bits and all
//
TBitmap::TBitmap(const TBitmap& src)
{
  Handle = 0;
  Create(src);
  TRACEX(OwlGDI, OWL_CDLEVEL, "TBitmap duplicated @" << (void*)this << " from @" << (void*)&src << ".");
}

//
// Construct a bitmap by playing a metafile into it
//
TBitmap::TBitmap(const TMetaFilePict& metaFile, TPalette& palette, const TSize& defSize)
{
  // Adjust size to final metafile size as needed
  //
  TMemoryDC memDC;
  TSize size = metaFile.CalcPlaySize(memDC, defSize);

  // Create bitmap, either mono or screen compatible
  //
  uint16  nColors;
  palette.GetObject(nColors);
  if (nColors > 2) {
    TScreenDC dc;
    Handle = ::CreateCompatibleBitmap(dc, size.cx, size.cy);
  }
  else
    Handle = ::CreateBitmap(size.cx, size.cy, 1, 1, 0);

  CheckValid();
  RefAdd(Handle, Bitmap);

  // clear bitmap, then play metafile onto it
  //
  memDC.SelectObject(*this);

  memDC.SelectStockObject(WHITE_BRUSH);
  memDC.PatBlt(0, 0, size.cx, size.cy);
  memDC.SelectObject(palette, false);

  metaFile.PlayOnto(memDC, size);

  TRACEX(OwlGDI, OWL_CDLEVEL, "TBitmap constructed @" << (void*)this <<
         " from metafile @" << (void*)&metaFile << ".");
}

//
// Construct a Bitmap given a handle to a TDib, and a pointer to a TPalette.
// If the palette is not supplied, a temp one is created and destroyed.
//
TBitmap::TBitmap(const TDib& dib, const TPalette* palette)
{
  if (palette)
    Create(dib, *palette);
  else
    Create(dib, TPalette(dib));
  TRACEX(OwlGDI, OWL_CDLEVEL, "TBitmap constructed @" << (void*)this << " from DIB @" <<
         (void*)&dib << " and palette @" << (void*)palette << ".");
}

//
// Destroy the C++ object.
//
TBitmap::~TBitmap()
{
  TRACEX(OwlGDI, OWL_CDLEVEL, "TBitmap destructed @" << (void*)this << ".");
}


//
// Get and return specific information about the bitmap using GDI's GetObject
//
int
TBitmap::Width() const
{
  BITMAP bm;
  GetObject(bm);
  return bm.bmWidth;
}

//
// Return the height of the bitmap.
//
int
TBitmap::Height() const
{
  BITMAP bm;
  GetObject(bm);
  return bm.bmHeight;
}

//
// Return the dimension the bitmap.
//
TSize
TBitmap::Size() const
{
  BITMAP bm;
  GetObject(bm);
  return TSize(bm.bmWidth, bm.bmHeight);
}

//
// Return the number of planes in this bitmap.
//
int
TBitmap::Planes() const
{
  BITMAP bm;
  GetObject(bm);
  return bm.bmPlanes;
}

//
// Return the bits per pixel in this bitmap.
//
int
TBitmap::BitsPixel() const
{
  BITMAP bm;
  GetObject(bm);
  return bm.bmBitsPixel;
}

//
// Put a device-dependent bitmap on the clipboard as a (DD)BITMAP. Clipboard
// assumes ownership of the actual bitmap handle & this TBitmap will not delete
// the handle
//
void
TBitmap::ToClipboard(TClipboard& clipboard)
{
  clipboard.SetClipboardData(CF_BITMAP, Handle);
  ShouldDelete = false;
  RefRemove(Handle);
}

//
// Create a bitmap & get its handle, given a dib and a palette
// Used by ctors here and in derived classes. Assumes Handle member can be
// over written, & adds handle to reference container.
//
void
TBitmap::Create(const TDib& dib, const TPalette& palette)
{
  TScreenDC  dc;
  dc.SelectObject(palette, false);
  dc.RealizePalette();

  Handle = ::CreateDIBitmap(
               dc,
               (LPBITMAPINFOHEADER)dib.GetInfoHeader(),
               CBM_INIT,
               (const uint8 far*)dib.GetBits(),
               (LPBITMAPINFO)dib.GetInfo(),
               dib.Usage()
            );             // API type casts

  CheckValid();
  RefAdd(Handle, Bitmap);
}

//
// Create a bitmap & get its handle, given an other bitmap
// Used by ctors here and in derived classes. Assumes Handle can be
// written over, & adds handle to reference container.
//
void
TBitmap::Create(const TBitmap& src)
{
  TMemoryDC memDC1;
  TMemoryDC memDC2;

  BITMAP  bm;
  src.GetObject(bm);
  if (bm.bmPlanes != 1 || bm.bmBitsPixel != 1) {
    // create a color bitmap (Assume screen compatible)
    TScreenDC dc;
    Handle = ::CreateCompatibleBitmap(dc, bm.bmWidth, bm.bmHeight);
  }
  else
    // create a mono bitmap
    Handle = ::CreateBitmap(bm.bmWidth, bm.bmHeight, 1, 1, 0);

  CheckValid();
  RefAdd(Handle, Bitmap);

  memDC1.SelectObject(src);
  memDC2.SelectObject(*this);
  memDC2.BitBlt(TRect(TPoint(0, 0), TSize(bm.bmWidth, bm.bmHeight)),
                memDC1, TPoint(0, 0), SRCCOPY);
}
