//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\dib.cpp
//   Implementation of TDib class
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\gdiobjec.h>
#include <owl\metafile.h>
#include <owl\clipboar.h>
#include <owl\except.h>
#include <classlib\file.h>

//
// size of scan in bytes =
//   Pixel Width * bits per pixel rounded up to a DWORD boundary
//
inline long ScanBytes(int pixWidth, int bitsPixel) {
  return (((long)pixWidth*bitsPixel+31) / 32) * 4;
}

DIAG_DECLARE_GROUP(OwlGDI);        // General GDI diagnostic group


#if !defined(SECTION) || SECTION == 1

// defining this will cause old core BMs to be converted to 3.0 format
// undefine this to leave old core bms as is, or not worry about them at all
//
//#define CVT_CORE_TO_INFO


//
// Lock the global/res handle if needed & extract the pointers and cached info
// maintained as member variables.
//
void
TDib::InfoFromHandle()
{
  if (!Info)
    if (IsResHandle)
      Info = (LPBITMAPINFO)::LockResource(Handle);
    else
      Info = (LPBITMAPINFO)::GlobalLock(Handle);
  if (Info->bmiHeader.biSize == sizeof(BITMAPCOREHEADER))
    IsCore = TRUE;
  else if (Info->bmiHeader.biSize == sizeof(BITMAPINFOHEADER))
    IsCore = FALSE;
  else {
    ::GlobalUnlock(Handle);
    THROW( TXGdi(IDS_INVALIDDIBHANDLE) );
  }
  int colorAlloc;
  if (IsCore) {
    NumClrs = NColors(((LPBITMAPCOREINFO)Info)->bmciHeader.bcBitCount);
    colorAlloc = (int)NumClrs * sizeof(RGBTRIPLE);
    W = ((LPBITMAPCOREINFO)Info)->bmciHeader.bcWidth;
    H = ((LPBITMAPCOREINFO)Info)->bmciHeader.bcHeight;
  } else {
    NumClrs = NColors(Info->bmiHeader.biBitCount);
    colorAlloc = (int)NumClrs * sizeof(RGBQUAD);
    W = (int)Info->bmiHeader.biWidth;
    H = (int)Info->bmiHeader.biHeight;
  }
  Bits = (char far*)Info + ((int)Info->bmiHeader.biSize + colorAlloc);
  Mode = DIB_RGB_COLORS;
}

//
// Construct a TDib from a borrowed handle
//
TDib::TDib(HGLOBAL handle, TAutoDelete autoDelete)
  : TGdiBase(handle, autoDelete), Info(0), Bits(0), NumClrs(0), W(0), H(0),
    IsCore(FALSE), IsResHandle(FALSE)
{
  InfoFromHandle();
}

//
// Construct a TDib borrowed from a clipboard handle
//
TDib::TDib(const TClipboard& clipboard)
  : TGdiBase(clipboard.GetClipboardData(CF_DIB)), Info(0), Bits(0),
    NumClrs(0), W(0), H(0), IsCore(FALSE), IsResHandle(FALSE)
{
  InfoFromHandle();
}

//
// Construct a TDib that is a copy of an existing one
//
TDib::TDib(const TDib& dib)
  : Info(0), Bits(0), NumClrs(0), W(0), H(0), IsCore(FALSE), IsResHandle(FALSE)
{
  PRECONDITION(dib.IsOK());

  long size = ::GlobalSize(dib.Handle);
  Handle = ::GlobalAlloc(GMEM_MOVEABLE, size);
  if (!Handle)
    THROW( TXOutOfMemory() );

  Info = (LPBITMAPINFO)::GlobalLock(Handle);
  hmemcpy(Info, dib.Info, size);
  IsCore = dib.IsCore;
  NumClrs = dib.NumClrs;
  W = dib.W;
  H = dib.H;
  Mode = dib.Mode;
  int colorAlloc = (int)NumClrs *
                   (IsCore ? sizeof(RGBTRIPLE) : sizeof(RGBQUAD));
  Bits = (char far*)Info + ((int)Info->bmiHeader.biSize + colorAlloc);
}


TDib::~TDib()
{
  if (Handle)
    if (IsResHandle) {
      #if !defined(__WIN32__)
        ::UnlockResource(Handle);
        if (ShouldDelete)
          ::FreeResource(Handle);
      #endif

    } else {
      ::GlobalUnlock(Handle);
      if (ShouldDelete)
        ::GlobalFree(Handle);
    }
}

//
// Convert an absolute RGB color table to a palette relative color table
// Makes sure that color table is RGB
//
BOOL
TDib::ChangeModeToPal(const TPalette& pal)
{
  if (Mode != DIB_RGB_COLORS)
    return FALSE;

  WORD nEntries = pal.GetNumEntries();
  
  for (int c = 0; c < NumClrs; c++) {
    WORD index = WORD(c);
    for (WORD i = 0; i < nEntries; i++) {
      PALETTEENTRY pe; //getting all entries one time up front would be faster
      pal.GetPaletteEntry(i, pe);
      if (pe.peRed == Info->bmiColors[c].rgbRed &&
          pe.peGreen == Info->bmiColors[c].rgbGreen &&
          pe.peBlue == Info->bmiColors[c].rgbBlue) {
        index = i;
        break;
      }
    }
    ((WORD*)Info->bmiColors)[c] = index;
  }
  Mode = DIB_PAL_COLORS;
  return TRUE;
}

//
// Convert a palette relative color table to an absolute RGB color table
// Makes sure that color table is pal relative & that there is enough space
//
BOOL
TDib::ChangeModeToRGB(const TPalette& pal)
{
  if (Mode != DIB_PAL_COLORS ||
      (int)((char*)Bits - (char*)Info) < NumClrs*sizeof(RGBQUAD))
    return FALSE;
  
  WORD nEntries = pal.GetNumEntries();

  for (int c = (int)NumClrs-1; c >= 0; c--) {
    WORD i = ((WORD*)Info->bmiColors)[c];
    if (i >= nEntries)
      i = 0;
    PALETTEENTRY pe;
    pal.GetPaletteEntry(i, pe);
    Info->bmiColors[c].rgbRed = pe.peRed;
    Info->bmiColors[c].rgbGreen = pe.peGreen;
    Info->bmiColors[c].rgbBlue = pe.peBlue;
  }
  Mode = DIB_RGB_COLORS;
  return TRUE;
}

//
// Get, set, find and map the color table entries as colors(RGBQUADs)
//
TColor
TDib::GetColor(int entry) const
{
  if (entry >= 0 && entry < NumClrs)
    if (Mode == DIB_RGB_COLORS)
      return GetColors()[entry];

  return 0;
}

void
TDib::SetColor(int entry, TColor color)
{
  if (entry >= 0 && entry < NumClrs)
    if (Mode == DIB_RGB_COLORS)
      GetColors()[entry] = color;
}

int
TDib::FindColor(TColor color)
{
  for (int entry = 0; entry < NumClrs; entry++)
    if (color == GetColors()[entry])
      return entry;
  return -1;
}

int
TDib::MapColor(TColor fromColor, TColor toColor, BOOL doAll)
{
  for (int entry = 0, count = 0; entry < NumClrs; entry++)
    if (fromColor == GetColors()[entry]) {
      GetColors()[entry] = toColor;
      count++;
      if (!doAll)
        break;
    }
  return count;
}

//
// Get, set, find and map the color table entries as palette indices
//
WORD
TDib::GetIndex(int entry) const
{
  if (entry >= 0 && entry < NumClrs)
    if (Mode == DIB_PAL_COLORS)
      return ((WORD*)GetColors())[entry];

  return 0;
}

void
TDib::SetIndex(int entry, WORD index)
{
  if (entry >= 0 && entry < NumClrs)
    if (Mode == DIB_PAL_COLORS)
      ((WORD*)GetColors())[entry] = index;
}

int
TDib::FindIndex(WORD index)
{
  for (int entry = 0; entry < NumClrs; entry++)
    if (GetIndices()[entry] == index)
      return entry;
  return -1;
}

int
TDib::MapIndex(WORD fromIndex, WORD toIndex, BOOL doAll)
{
  for (int entry = 0, count = 0; entry < NumClrs; entry++)
    if (GetIndices()[entry] == fromIndex) {
      GetIndices()[entry] = toIndex;
      count++;
      if (!doAll)
        break;
    }
  return count;
}

void
TDib::MapUIColors(UINT mapColors, TColor* bkColor)
{
  if (mapColors & TDib::MapText)
    MapColor(TColor::Black, ::GetSysColor(COLOR_BTNTEXT));
  if (mapColors & TDib::MapFace)
    MapColor(TColor::LtGray, ::GetSysColor(COLOR_BTNFACE));
  if (mapColors & TDib::MapFace)
    MapColor(TColor::Gray, ::GetSysColor(COLOR_BTNSHADOW));
  if (mapColors & TDib::MapFace)
    MapColor(TColor::White, ::GetSysColor(COLOR_BTNHIGHLIGHT));
  if (mapColors & TDib::MapFrame)
    MapColor(TColor::LtMagenta, ::GetSysColor(COLOR_WINDOWFRAME));
  if (bkColor)
    MapColor(TColor::LtYellow, *bkColor);
}

//
// Move this dib to the clipboard. Ownership of the DIB is passed to the
// clipboard.
//
void
TDib::ToClipboard(TClipboard& clipboard)
{
  if (Handle) {
    if (IsResHandle) {
      #if !defined(__WIN32__)
        ::UnlockResource(Handle);
      #endif
    } else {
      ::GlobalUnlock(Handle);
    }
    clipboard.SetClipboardData(CF_DIB, Handle);
    ShouldDelete = FALSE;
    Info = 0;
    Bits = 0;
    Handle = 0;
  }
}

#endif  //section 1
#if !defined(SECTION) || SECTION == 2

//
// Construct a Dib given a .BMP file name
//
TDib::TDib(const char* name)
  : Info(0), Bits(0), NumClrs(0), W(0), H(0), IsCore(FALSE), IsResHandle(FALSE)
{
  if (!LoadFile(name))
    THROW( TXGdi(IDS_GDIFILEREADFAIL) );
}

//
// Test if the passed file is a Windows 3.0 DI(or PM 1.x) bitmap
//  and if so read it.
//  Report errors if unable to do so. Adjust the Scroller to the new
//  bitmap dimensions.
//
BOOL
TDib::LoadFile(const char* name)
{
  TFile file(name, TFile::ReadOnly);
  if (!file.IsOpen()) {
    TRACEX(OwlGDI, 0, "Cannot open bitmap file '" << name << "' to read");
    return FALSE;
  }

  // read file header and verify the signature
  BITMAPFILEHEADER bmf;
  if (file.Read(&bmf, sizeof(bmf)) != sizeof(bmf) || bmf.bfType != 'BM') {
    TRACEX(OwlGDI, 0, "Not a Windows 3.x or OS/2 1.x bitmap file '" << name << "'");
    file.Close();
    return FALSE;
  }

  // we ignore all other information in the file header
  // since some applications do not put correct information in
  // the fields...
  //
  if (!Read(file,bmf.bfOffBits ? bmf.bfOffBits-sizeof(BITMAPFILEHEADER) : 0)) {
    file.Close();
    return FALSE;
  }
  file.Close();
  return TRUE;
}


#endif
#if !defined(SECTION) || SECTION == 3

//
// Construct a Dib given a module instance and a resource name or int Id
//
TDib::TDib(HINSTANCE instance, TResId resId)
  : Info(0), Bits(0), NumClrs(0), W(0), H(0), IsCore(FALSE), IsResHandle(FALSE)
{
  if (!LoadResource(instance, resId))
    THROW( TXGdi(IDS_GDIRESLOADFAIL) );
}

//
// Load a dib resource into a dib.  Either use ::LoadResource, or use
// ::AccessResource get to the file handle and read it like a BMP file.
//
BOOL
TDib::LoadResource(HINSTANCE instance, TResId resId)
{
#if TRUE || defined(__WIN32__)  // This version works in all cases

  // First, load the resource into a global memory block.
  //
  HRSRC  resHandle = ::FindResource(instance, resId, RT_BITMAP);
  if (resHandle)
    Handle = ::LoadResource(instance, resHandle);
  else
    Handle = 0;
  if (!Handle) {
    TRACEX(OwlGDI, 0, "Cannot access bitmap resource");
    return FALSE;
  }
  IsResHandle = TRUE;

  // Then update our pointers & other info.
  //
  InfoFromHandle();

  // Under Win32, resources are read-only. So, to allow for later modification
  // of the Dib, a copy must be made. Could postpone this until dib needed
  // to be written on...
  //
  #if defined(__WIN32__)
    long size = ::SizeofResource(instance, resHandle);
    HANDLE tempHandle = ::GlobalAlloc(GMEM_MOVEABLE, size);
    if (!tempHandle)
      THROW( TXOutOfMemory() );

    void* tempInfo = ::GlobalLock(tempHandle);
    hmemcpy(tempInfo, Info, size);

    // Handle will now be a memory handle, & no longer a res handle
    // Update Bits pointer & other members that may have moved.
    //
    Handle = tempHandle;
    Info = (LPBITMAPINFO)tempInfo;
    IsResHandle = FALSE;
    InfoFromHandle();
  #endif

  return TRUE;

#else   // This version will work for win16

  // We use the low-level resource functions here so that
  // the same routines can be used to read DIB's from files
  // and resources
  //
  TFile  file(::AccessResource(instance, ::FindResource(instance, resId, RT_BITMAP)));
  if (!file.IsOpen()) {
    TRACEX(OwlGDI, 0, "Cannot access bitmap resource");
    return FALSE;
  }
  // a bitmap resource is just like a bitmap file without
  // the BITMAPFILEHEADER structure
  //
  if (!Read(file)) {
    file.Close();
    return FALSE;
  }
  file.Close();
  return TRUE;

#endif
}

//
// Read a Windows 3.0 or PM 1.X device independent bitmap. (.BMP)
//  Check header, read Info, palette and bitmap.  PM Dibs can be converted to
//  Win 3.0 Dibs on the fly.
// Return true iff Dib was read OK
//
BOOL
TDib::Read(TFile& file, long offBits)
{
  DWORD headerSize;
  if (file.Read(&headerSize, sizeof(headerSize)) != sizeof(headerSize)
    || headerSize != sizeof(BITMAPCOREHEADER)
    && headerSize != sizeof(BITMAPINFOHEADER)) {
    TRACEX(OwlGDI, 0, "Not a Windows 3.x or PM 1.x bitmap file");
    return FALSE;
  }

  // Prepare to accept a header that is either Core(PM) or Info(Win) type
  // Note thet the biSize and the bcSize fields are the same(the only ones).
  //
  union {
    BITMAPINFOHEADER infoHeader;
    BITMAPCOREHEADER coreHeader;
  };
  #if defined(CVT_CORE_TO_INFO)
    infoHeader.biSize = sizeof(BITMAPINFOHEADER);
  #else
    infoHeader.biSize = headerSize;
  #endif
  if (file.Read(&infoHeader.biWidth, (int)headerSize-sizeof(DWORD)) !=
      (int)headerSize-sizeof(DWORD)) {
    TRACEX(OwlGDI, 0, "Invalid DIB Header");
    return FALSE;
  }

  // Type dependent fields kept independently
  //
  WORD  bitCount;
  int   colorAlloc;
  int   colorRead;
  DWORD bitsAlloc;

  // If this is a PM 1.X Dib, expand header and fill out reamining fields
  // for win3 dib info
  // Calculate size of color table in memory using RGBQUADs if converting.
  // For PM Dibs, this is NOT the size on disk.
  //
  if (headerSize == sizeof(BITMAPCOREHEADER)) {
    // check number of planes. Windows 3.x supports only 1 plane DIBs
    if (coreHeader.bcPlanes != 1) {
      TRACEX(OwlGDI, 0, "Invalid number of planes in PM 1.X bitmap");
      return FALSE;
    }
    bitCount = coreHeader.bcBitCount;
    NumClrs = NColors(bitCount);
    colorRead = (int)NumClrs * sizeof(RGBTRIPLE); // Color tables on disk
    W = coreHeader.bcWidth;
    H = coreHeader.bcHeight;
    #if defined(CVT_CORE_TO_INFO)
      IsCore = FALSE;
      // Note reverse field order for copying in place
      infoHeader.biBitCount = coreHeader.bcBitCount;
      infoHeader.biPlanes = 1;
      infoHeader.biWidth = W;
      infoHeader.biHeight = H;
      infoHeader.biCompression = BI_RGB;
      infoHeader.biSizeImage = 0; // calculate this below
      infoHeader.biXPelsPerMeter = 0;
      infoHeader.biYPelsPerMeter = 0;
      infoHeader.biClrUsed = NumClrs;
      infoHeader.biClrImportant = 0;
      colorAlloc = NumClrs * sizeof(RGBQUAD); // size of color tables in mem
    #else
      IsCore = TRUE;
      colorAlloc = colorRead;
    #endif
    bitsAlloc = 0;      // Calculate below
  } else {
    // check number of planes. Windows 3.x supports only 1 plane DIBs
    if (infoHeader.biPlanes != 1) {
      TRACEX(OwlGDI, 0, "Invalid number of planes in Win 3.X bitmap");
      return FALSE;
    }
    IsCore = FALSE;
    bitCount = infoHeader.biBitCount;
    if (!infoHeader.biClrUsed)
      infoHeader.biClrUsed = NColors(bitCount);
    NumClrs = (int)infoHeader.biClrUsed;
    colorAlloc = (int)NumClrs * sizeof(RGBQUAD); // size of color tables
    colorRead = colorAlloc;
    W = (int)infoHeader.biWidth;
    H = (int)infoHeader.biHeight;
    bitsAlloc = infoHeader.biSizeImage;
  }

  // Some applications do not fill in the SizeImage field in the header.
  // (Actually the truth is more likely that some drivers do not fill the
  // field in and the apps do not compensate for these buggy drivers.)
  // Or it is a PM 1.X Dib.
  // Therefore, if compression was not used, we will(re)compute the size,
  // but if compression is used, we have no choice but to trust the size.
  //
  if (IsCore || infoHeader.biCompression == BI_RGB) {
    bitsAlloc = ScanBytes(W, bitCount) * H;
    if (!IsCore)
      infoHeader.biSizeImage = bitsAlloc;
  }

  Handle = ::GlobalAlloc(GMEM_MOVEABLE, infoHeader.biSize + colorAlloc + bitsAlloc);
  if (!Handle)
    THROW( TXOutOfMemory() );

  Info = (LPBITMAPINFO)::GlobalLock(Handle);
  Info->bmiHeader = infoHeader;

  // Read color table.  Expand to RGBQUADs if it is a PM Dib & we are converting
  //
  if (colorAlloc) {
    if (file.Read((char far*)Info+(int)infoHeader.biSize, colorRead) != colorRead) {
      TRACEX(OwlGDI, 0, "Could not read color table");
      ::GlobalUnlock(Handle);
      return FALSE;
    }
    #if defined(CVT_CORE_TO_INFO)
    if (IsCore) {
      for (int i = NumClrs-1; i >= 0; i--) {
        Info->bmiColors[i].rgbRed = ((RGBTRIPLE*)Info->bmiColors)[i].rgbtRed;
        Info->bmiColors[i].rgbGreen = ((RGBTRIPLE*)Info->bmiColors)[i].rgbtGreen;
        Info->bmiColors[i].rgbBlue = ((RGBTRIPLE*)Info->bmiColors)[i].rgbtBlue;
        Info->bmiColors[i].rgbReserved = 0;
      }
    }
    #endif
  }
  Mode = DIB_RGB_COLORS;

  // Locate & Read Bits, skipping Pad if any.  Ignore OffBits if it is zero.
  // Ignore OffBits if less than the current position(its probably bad)
  //
  Bits = (char far*)Info +((int)infoHeader.biSize + colorAlloc);
  if (offBits && offBits - (long)(headerSize+colorRead) > 0)
    file.Seek(offBits- (headerSize+colorRead), TFile::cur);
  if (file.Read(Bits, bitsAlloc) != bitsAlloc) {
    TRACEX(OwlGDI, 0, "Could not read DIB bits");
    return FALSE;
  }
  return TRUE;
}

#endif //section 3
#if !defined(SECTION) || SECTION == 4

BOOL
TDib::WriteFile(const char* name)
{
  TFile file(name, TFile::WriteOnly|TFile::Create|TFile::DenyRdWr, TFile::PermRdWr);

  if (!file.IsOpen()) {
    TRACEX(OwlGDI, 0, "Cannot open bitmap file '" << name << "' to write");
    return FALSE;
  }

  long size = ::GlobalSize(Handle);

  // write file header
  BITMAPFILEHEADER bmf;
  bmf.bfType = 'BM';
  bmf.bfSize = sizeof(bmf) + size;
  bmf.bfReserved1 = 0;
  bmf.bfReserved2 = 0;
  bmf.bfOffBits = sizeof(bmf) +(char far*)Bits - (char far*)Info;
  if (file.Write(&bmf, sizeof(bmf)) != sizeof(bmf) ||
      file.Write((void HUGE*)Info, size) != size) {
    TRACEX(OwlGDI, 0, "Disk error writing file '" << name << "'");
    file.Close();
    return FALSE;
  }
  file.Close();
  return TRUE;
}

#endif //section 4
#if !defined(SECTION) || SECTION == 5

//
// Construct a Dib given dimensions and color depth
//
TDib::TDib(int width, int height, int nColors, WORD mode)
  : Info(0), Bits(0), NumClrs(0), W(0), H(0), IsCore(FALSE), IsResHandle(FALSE)
{
  PRECONDITION(width && height && nColors);

  BITMAPINFOHEADER      InfoHeader;
  InfoHeader.biSize       = sizeof(BITMAPINFOHEADER);
  InfoHeader.biWidth      = width;
  InfoHeader.biHeight     = height;
  InfoHeader.biBitCount   = NBits(nColors);
  InfoHeader.biPlanes     = 1;
  InfoHeader.biXPelsPerMeter = 0;
  InfoHeader.biYPelsPerMeter = 0;
  InfoHeader.biClrUsed       = nColors;
  InfoHeader.biClrImportant  = 0;  // nColors;
  InfoHeader.biCompression   = BI_RGB;
  InfoHeader.biSizeImage = ScanBytes(width, InfoHeader.biBitCount) * height;

  int  colorAlloc = nColors * sizeof(RGBQUAD); // size of color tables
  long bitsAlloc = InfoHeader.biSize + colorAlloc + InfoHeader.biSizeImage;

  Handle = ::GlobalAlloc(GMEM_MOVEABLE, bitsAlloc);
  if (!Handle)
    THROW( TXOutOfMemory() );

  Info = (LPBITMAPINFO)::GlobalLock(Handle);
  Info->bmiHeader = InfoHeader;
  InfoFromHandle();

  Mode = mode;
  if (Mode == DIB_PAL_COLORS) {
    // Generate a 1:1 palette relative color table- it can later be translated
    // to RGB given a palette.
    //
    for (WORD i = 0; i < nColors; i++)
     ((WORD*)Info->bmiColors)[i] = i;

  } else {
  
    // Get the system palette and convert to RGB quad format.
    //
    TScreenDC dc;
    ::GetSystemPaletteEntries(dc, 0, nColors, (LPPALETTEENTRY)Info->bmiColors);
    for (int i = 0; i < nColors; i++) {
      Swap(Info->bmiColors[i].rgbRed, Info->bmiColors[i].rgbBlue);
      Info->bmiColors[i].rgbReserved = 0;
    }
  }
}
#endif //Section 5
#if !defined(SECTION) || SECTION == 6

//
// Construct a TDib given a TBitmap and a TPalette
// If no palette is give, uses the one in the focus window.
//
TDib::TDib(const TBitmap& bitmap, const TPalette* palette)
  : Info(0), Bits(0), NumClrs(0), W(0), H(0), IsCore(FALSE), IsResHandle(FALSE)
{
  BITMAP  bm;
  bitmap.GetObject(bm);

  WORD              bitCount;
  BITMAPINFOHEADER  infoHeader;

  IsCore = FALSE;
  infoHeader.biSize       = sizeof(BITMAPINFOHEADER);
  infoHeader.biWidth      = W = bm.bmWidth;
  infoHeader.biHeight     = H = bm.bmHeight;
  if (palette) {
    WORD nColors;
    palette->GetObject(nColors);
    infoHeader.biBitCount    = bitCount = NBits(nColors);
  } else
    infoHeader.biBitCount    = bitCount = WORD(bm.bmBitsPixel*bm.bmPlanes);
  infoHeader.biPlanes        = 1;
  infoHeader.biXPelsPerMeter = 0;
  infoHeader.biYPelsPerMeter = 0;
  infoHeader.biClrUsed       = NumClrs = NColors(bitCount);
  infoHeader.biClrImportant  = 0;
  infoHeader.biCompression   = BI_RGB;
  infoHeader.biSizeImage     = ScanBytes(W, bitCount) * H;

  int  colorAlloc = (int)NumClrs * sizeof(RGBQUAD); // size of color tables
  long bitsAlloc = infoHeader.biSize + colorAlloc + infoHeader.biSizeImage;

  Handle = ::GlobalAlloc(GMEM_MOVEABLE, bitsAlloc);
  if (!Handle)
    THROW( TXOutOfMemory() );

  Info = (LPBITMAPINFO)::GlobalLock(Handle);
  Info->bmiHeader = infoHeader;

  TScreenDC dc;
  if (palette)
    dc.SelectObject(*palette, FALSE);
  Bits = (char far*)Info + ((int)infoHeader.biSize + colorAlloc);
  Mode = DIB_RGB_COLORS;
  dc.GetDIBits(bitmap, StartScan(), NumScans(), Bits, *Info, Usage());
}

#endif //Section 6
