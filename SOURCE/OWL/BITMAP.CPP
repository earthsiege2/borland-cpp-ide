//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of GDI Bitmap object class
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/gdiobjec.h>
#include <owl/metafile.h>
#include <owl/clipboar.h>

DIAG_DECLARE_GROUP(OwlGDI);        // General GDI diagnostic group
DIAG_DECLARE_GROUP(OwlGDIOrphan);  // Orphan control tracing group

//
// Construct an alias TBitmap for an existing bitmap handle
//
TBitmap::TBitmap(HBITMAP handle, TAutoDelete autoDelete)
:
  TGdiObject(handle, autoDelete)
{
#if !defined(NO_GDI_ORPHAN_CONTROL)
  if (ShouldDelete)
    OBJ_REF_ADD(Handle, Bitmap);
#endif
}

TBitmap::TBitmap()
:
  TGdiObject()
{
}

TBitmap::TBitmap(const TClipboard& clipboard)
:
  TGdiObject(clipboard.GetClipboardData(CF_BITMAP))
{
  OBJ_REF_ADD(Handle, Bitmap);
  OBJ_REF_INC(Handle);
}

TBitmap::TBitmap(int width, int height, uint8 planes, uint8 bitCount, const void far* bits)
{
  Handle = ::CreateBitmap(width, height, planes, bitCount, bits);
  WARNX(OwlGDI, !Handle, 0, "Cannot create bitmap (" << width << "x" <<
        height << "x" << planes << ")");
  CheckValid();
  OBJ_REF_ADD(Handle, Bitmap);
}

TBitmap::TBitmap(const BITMAP far* bitmap)
{
  PRECONDITION(bitmap);
  Handle = ::CreateBitmapIndirect((LPBITMAP)bitmap);  // API cast
  WARNX(OwlGDI, !Handle, 0, "Cannot create bitmap from BITMAP @" <<
        hex << uint32(LPVOID(bitmap)));
  CheckValid();
  OBJ_REF_ADD(Handle, Bitmap);
}

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
  OBJ_REF_ADD(Handle, Bitmap);
}

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
  OBJ_REF_ADD(Handle, Bitmap);
}

TBitmap::TBitmap(HINSTANCE instance, TResId resId)
{
  Handle = ::LoadBitmap(instance, resId);
  WARNX(OwlGDI, !Handle, 0, "Cannot load bitmap " << resId << " from " <<
        hex << (uint)instance);
  CheckValid();
  OBJ_REF_ADD(Handle, Bitmap);
}

//
// Copy constructor, duplicates a bitmap, bits and all
//
TBitmap::TBitmap(const TBitmap& src)
{
  Handle = 0;
  Create(src);
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
  OBJ_REF_ADD(Handle, Bitmap);

  // clear bitmap, then play metafile onto it
  //
  memDC.SelectObject(*this);

  memDC.SelectStockObject(WHITE_BRUSH);
  memDC.PatBlt(0, 0, size.cx, size.cy);
  memDC.SelectObject(palette, false);

  metaFile.PlayOnto(memDC, size);
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

int
TBitmap::Height() const
{
  BITMAP bm;
  GetObject(bm);
  return bm.bmHeight;
}

uint8
TBitmap::Planes() const
{
  BITMAP bm;
  GetObject(bm);
  return bm.bmPlanes;
}

uint8
TBitmap::BitsPixel() const
{
  BITMAP bm;
  GetObject(bm);
  return bm.bmBitsPixel;
}

//
// Put a device-dependent bitmap on the clipboard as a (DD)BITMAP. Clipboard
// assumes ownership of the actual bitmap.
//
void
TBitmap::ToClipboard(TClipboard& clipboard)
{
  clipboard.SetClipboardData(CF_BITMAP, Handle);
  ShouldDelete = false;
  OBJ_REF_REMOVE(Handle);
}

//
// Create a bitmap & get its handle, given a dib and a palette
// Used by ctors here and in derived classes. Assumes Handle can be
// written over, & adds handle to reference container.
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
  OBJ_REF_ADD(Handle, Bitmap);
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
  OBJ_REF_ADD(Handle, Bitmap);

  memDC1.SelectObject(src);
  memDC2.SelectObject(*this);
  memDC2.BitBlt(TRect(TPoint(0, 0), TSize(bm.bmWidth, bm.bmHeight)),
                memDC1, TPoint(0, 0), SRCCOPY);
}
