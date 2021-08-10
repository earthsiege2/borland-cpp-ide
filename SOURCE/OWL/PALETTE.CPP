//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Implementation of TPalette, an encapsulation of the GDI Palette object
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif
#if !defined(OWL_CLIPBOAR_H)
# include <owl/clipboar.h>
#endif
#include <memory.h>

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlGDI);        // General GDI diagnostic group
DIAG_DECLARE_GROUP(OwlGDIOrphan);  // Orphan control tracing group

//
// Constructors
//

//
// Alias an existing palette handle. Assume ownership if autoDelete says so
//
TPalette::TPalette(HPALETTE handle, TAutoDelete autoDelete)
:
  TGdiObject(handle, autoDelete)
{
  if (ShouldDelete)
    RefAdd(Handle, Palette);
}

//
// Construct a TPalette by pulling a palette handle from the clipboard
//
TPalette::TPalette(const TClipboard& clipboard)
:
  TGdiObject(clipboard.GetClipboardData(CF_PALETTE))
{
  WARNX(OwlGDI, !Handle, 0, "Cannot create TPalette from the clipboard");
  CheckValid();
  RefAdd(Handle, Palette);
  RefInc(Handle);
}

//
// Construct a copy of an existing palette. Always performs full, deep object
// copy
//
TPalette::TPalette(const TPalette& src)
{
  uint16  nColors;
  src.GetObject(nColors);
  if (nColors) {
    LOGPALETTE* logPal = (LOGPALETTE*) new
      uint8[sizeof(LOGPALETTE)+(nColors-1)*sizeof(PALETTEENTRY)];

    logPal->palVersion = 0x300;  
    logPal->palNumEntries = nColors;
    src.GetPaletteEntries(0, nColors, logPal->palPalEntry);
    Handle = ::CreatePalette(logPal);
    delete[] logPal;
  }
  else
    Handle = 0;  // Force a failure

  WARNX(OwlGDI, !Handle, 0, "Cannot create palette from palette " <<
        uint(HPALETTE(src)));
  CheckValid();
  RefAdd(Handle, Palette);
}

//
// Construct a TPalette given a logical palette object
//
TPalette::TPalette(const LOGPALETTE far* logPalette)
{
  PRECONDITION(logPalette);
  Handle = ::CreatePalette(logPalette);
  WARNX(OwlGDI, !Handle, 0, "Cannot create palette from logPalette @" <<
        hex << uint32(LPVOID(logPalette)));
  CheckValid();
  RefAdd(Handle, Palette);
}

//
// Construct a TPalette given a palette entry array
//
TPalette::TPalette(const PALETTEENTRY far* entries, int count)
{
  LOGPALETTE* logPal = (LOGPALETTE*)new uint8[
     sizeof(LOGPALETTE)+(count-1)*sizeof(PALETTEENTRY) ];

  logPal->palVersion  = 0x300;
  logPal->palNumEntries = (uint16)count;
  memcpy(logPal->palPalEntry, entries, count*sizeof(PALETTEENTRY));
  Handle = ::CreatePalette(logPal);
  delete[] logPal;

  WARNX(OwlGDI, !Handle, 0, "Cannot create palette from " << count <<
        "palette entries @" << hex << uint32(LPVOID(entries)));
  CheckValid();
  RefAdd(Handle, Palette);
}

//
// Construct a TPalette from the bitmap info from a DIB
//
TPalette::TPalette(const BITMAPINFO far* info, uint flags)
{
  Create(info, flags);
}

//
// Construct a TPalette from a TDib
//
TPalette::TPalette(const TDib& dib, uint flags)
{
  Create(dib.GetInfo(), flags);
}

//
// Accept a pointer to a BITMAPINFO structure and create a GDI logical
// palette from the color table which follows it, for 2, 16 and 256 color
// bitmaps. Fail for all others, including 24-bit DIB's
//
void
TPalette::Create(const BITMAPINFO far* info, uint flags)
{
  const RGBQUAD far* rgb = info->bmiColors;

  // if the ClrUsed field of the header is non-zero,
  // it means that we could have have a short color table.
  //
  uint16 nColors = uint16(info->bmiHeader.biClrUsed ?
           info->bmiHeader.biClrUsed :
           NColors(info->bmiHeader.biBitCount));

  if (nColors) {
    LOGPALETTE* logPal = (LOGPALETTE*)
       new uint8[sizeof(LOGPALETTE) + (nColors-1)*sizeof(PALETTEENTRY)];

    logPal->palVersion  = 0x300;      // Windows 3.0 version
    logPal->palNumEntries = nColors;
    for (uint16 n = 0; n < nColors; n++) {
      logPal->palPalEntry[n].peRed   = rgb[n].rgbRed;
      logPal->palPalEntry[n].peGreen = rgb[n].rgbGreen;
      logPal->palPalEntry[n].peBlue  = rgb[n].rgbBlue;
      logPal->palPalEntry[n].peFlags = (uint8)flags;
    }
    Handle = ::CreatePalette(logPal);
    delete[] logPal;
  }
  else
    Handle = 0;

  WARNX(OwlGDI, !Handle, 0, "Cannot create palette from bitmapinfo @" <<
        hex << uint32(LPVOID(info)));
  CheckValid();
  RefAdd(Handle, Palette);
}

//
// Move this palette handle to the clipboard.  Clipboard assumes ownership,
// this TPalette will not delete the handle
//
void
TPalette::ToClipboard(TClipboard& clipboard)
{
  if (Handle) {
    clipboard.SetClipboardData(CF_PALETTE, Handle);
    ShouldDelete = false; // GDI object now owned by Clipboard
    RefRemove(Handle);
  }
}

//
// Obsolete PM core info based palette construction. TDib now always converts
// PM DIBs to Windows DIBs when reading.
//
#if defined(OWL2_COMPAT)
//
//
//
TPalette::TPalette(const BITMAPCOREINFO far* core, uint flags)
{
  Create(core, flags);
}

//
// Accept a pointer to a BITMAPCORE structure and create a GDI logical
// palette from the color table which follows it, for 2, 16 and 256 color
// bitmaps. Fail for all others, including 24-bit DIB's
//
// It differs from the windows DIB routine in two respects:
//
//   1) The PM 1.x DIB must have complete color tables, since there is no
//      ClrUsed field in the header
//
//   2) The size of the color table entries is 3 bytes, not 4 bytes.
//
void
TPalette::Create(const BITMAPCOREINFO far* coreInfo, uint flags)
{
  const RGBTRIPLE far* rgb = coreInfo->bmciColors;

  uint16 nColors = (uint16)NColors(coreInfo->bmciHeader.bcBitCount);
  if (nColors) {
    LOGPALETTE* logPal = (LOGPALETTE*)
       new uint8[sizeof(LOGPALETTE) + (nColors-1)*sizeof(PALETTEENTRY)];

    logPal->palVersion  = 0x300; // Windows 3.0 version
    logPal->palNumEntries = nColors;
    for (short n = 0; n < nColors; n++) {
      logPal->palPalEntry[n].peRed   = rgb[n].rgbtRed;
      logPal->palPalEntry[n].peGreen = rgb[n].rgbtGreen;
      logPal->palPalEntry[n].peBlue  = rgb[n].rgbtBlue;
      logPal->palPalEntry[n].peFlags = (uint8)flags;
    }
    Handle = ::CreatePalette(logPal);
    delete[] logPal;
  }
  else
    Handle = 0;

  WARNX(OwlGDI, !Handle, 0, "Cannot create palette from coreinfo @" <<
        hex << uint32(LPVOID(coreInfo)));
  CheckValid();
  RefAdd(Handle, Palette);
}
#endif
