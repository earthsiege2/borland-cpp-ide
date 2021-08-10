//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\palette.cpp
//   Implementation of GDI Palette object class
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\gdiobjec.h>
#include <owl\clipboar.h>
#include <memory.h>

DIAG_DECLARE_GROUP(OwlGDI);        // General GDI diagnostic group
DIAG_DECLARE_GROUP(OwlGDIOrphan);  // Orphan control tracing group

//
// Constructors
//
TPalette::TPalette(HPALETTE handle, TAutoDelete autoDelete)
  : TGdiObject(handle, autoDelete)
{
  #if !defined(NO_GDI_ORPHAN_CONTROL)
    if (ShouldDelete)
      OBJ_REF_ADD(Handle, Palette);
  #endif
}

TPalette::TPalette(const TClipboard& clipboard)
  : TGdiObject(clipboard.GetClipboardData(CF_PALETTE))
{
  OBJ_REF_ADD(Handle, Palette);
  OBJ_REF_INC(Handle);
}

TPalette::TPalette(const LOGPALETTE far* logPalette)
{
  PRECONDITION(logPalette);
  Handle = ::CreatePalette(logPalette);
  WARNX(OwlGDI, !Handle, 0, "Cannot create palette from logPalette @" << 
        hex << DWORD(LPVOID(logPalette)));
  CheckValid();
  OBJ_REF_ADD(Handle, Palette);
}

TPalette::TPalette(const TPalette& palette)
{
  WORD  nColors;
  palette.GetObject(nColors);
  if (nColors) {
    LOGPALETTE* logPal = (LOGPALETTE*) new
      BYTE[sizeof(LOGPALETTE)+(nColors-1)*sizeof(PALETTEENTRY)];

    logPal->palVersion = 0x300;
    logPal->palNumEntries = nColors;
    palette.GetPaletteEntries(0, nColors, logPal->palPalEntry);
    Handle = ::CreatePalette(logPal);
    delete logPal;
  } else
    Handle = 0;

  WARNX(OwlGDI, !Handle, 0, "Cannot create palette from palette " << 
        UINT(HPALETTE(palette)));
  CheckValid();
  OBJ_REF_ADD(Handle, Palette);
}

TPalette::TPalette(const BITMAPINFO far* info, UINT flags)
{
  Create(info, flags);
}

TPalette::TPalette(const BITMAPCOREINFO far* core, UINT flags)
{
  Create(core, flags);
}

TPalette::TPalette(const TDib& dib, UINT flags)
{
  if (dib.IsPM())
    Create((const BITMAPCOREINFO far*)dib.GetInfo(), flags);
  else
    Create(dib.GetInfo(), flags);
}

TPalette::TPalette(const PALETTEENTRY far* entries, int count)
{
  LOGPALETTE* logPal = (LOGPALETTE*)new BYTE[
     sizeof(LOGPALETTE)+(count-1)*sizeof(PALETTEENTRY) ];

  logPal->palVersion  = 0x300;
  logPal->palNumEntries = (WORD)count;
  memcpy(logPal->palPalEntry, entries, count*sizeof(PALETTEENTRY));
  Handle = ::CreatePalette(logPal);
  delete logPal;

  WARNX(OwlGDI, !Handle, 0, "Cannot create palette from " << count <<
        "palette entries @" << hex << DWORD(LPVOID(entries)));
  CheckValid();
  OBJ_REF_ADD(Handle, Palette);
}

//
// Accept a pointer to a BITMAPINFO structure and create a GDI logical
// palette from the color table which follows it, for 2, 16 and 256 color
// bitmaps. Fail for all others, including 24-bit DIB's
//
void
TPalette::Create(const BITMAPINFO far* info, UINT flags)
{
  const RGBQUAD far* rgb = info->bmiColors;

  // if the ClrUsed field of the header is non-zero,
  // it means that we could have have a short color table.
  //
  WORD  nColors = info->bmiHeader.biClrUsed ?
           (WORD)info->bmiHeader.biClrUsed :
           (WORD)NColors(info->bmiHeader.biBitCount);

  if (nColors) {
    LOGPALETTE* logPal = (LOGPALETTE*)
       new BYTE[sizeof(LOGPALETTE) + (nColors-1)*sizeof(PALETTEENTRY)];

    logPal->palVersion  = 0x300;      // Windows 3.0 version
    logPal->palNumEntries = nColors;
    for (WORD n = 0; n < nColors; n++) {
      logPal->palPalEntry[n].peRed   = rgb[n].rgbRed;
      logPal->palPalEntry[n].peGreen = rgb[n].rgbGreen;
      logPal->palPalEntry[n].peBlue  = rgb[n].rgbBlue;
      logPal->palPalEntry[n].peFlags = (BYTE)flags;
    }
    Handle = ::CreatePalette(logPal);
    delete logPal;
  } else
    Handle = 0;

  WARNX(OwlGDI, !Handle, 0, "Cannot create palette from bitmapinfo @" << 
        hex << DWORD(LPVOID(info)));
  CheckValid();
  OBJ_REF_ADD(Handle, Palette);
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
TPalette::Create(const BITMAPCOREINFO far* coreInfo, UINT flags)
{
  const RGBTRIPLE far* rgb = coreInfo->bmciColors;

  WORD nColors = (WORD)NColors(coreInfo->bmciHeader.bcBitCount);
  if (nColors) {
    LOGPALETTE* logPal = (LOGPALETTE*)
       new BYTE[sizeof(LOGPALETTE) + (nColors-1)*sizeof(PALETTEENTRY)];

    logPal->palVersion  = 0x300; // Windows 3.0 version
    logPal->palNumEntries = nColors;
    for (short n = 0; n < nColors; n++) {
      logPal->palPalEntry[n].peRed   = rgb[n].rgbtRed;
      logPal->palPalEntry[n].peGreen = rgb[n].rgbtGreen;
      logPal->palPalEntry[n].peBlue  = rgb[n].rgbtBlue;
      logPal->palPalEntry[n].peFlags = (BYTE)flags;
    }
    Handle = ::CreatePalette(logPal);
    delete logPal;
  } else
    Handle = 0;

  WARNX(OwlGDI, !Handle, 0, "Cannot create palette from coreinfo @" << 
        hex << DWORD(LPVOID(coreInfo)));
  CheckValid();
  OBJ_REF_ADD(Handle, Palette);
}

//
// Move this logical palette to the clipboard.  Clipboard assumes ownership
//
void
TPalette::ToClipboard(TClipboard& clipboard)
{
  if (Handle) {
    clipboard.SetClipboardData(CF_PALETTE, Handle);
    ShouldDelete = FALSE; // GDI object now owned by Clipboard
    OBJ_REF_REMOVE(Handle);
  }
}
