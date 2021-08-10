//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of TDib class
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/gdiobjec.h>
#include <owl/metafile.h>
#include <owl/clipboar.h>
#include <owl/except.h>
#include <classlib/file.h>

//
// size of scan in bytes =
//   Pixel Width * bits per pixel rounded up to a uint32 boundary
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
    IsCore = true;
  else if (Info->bmiHeader.biSize == sizeof(BITMAPINFOHEADER))
    IsCore = false;
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
  }
  else {
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
:
  TGdiBase(handle, autoDelete),
  Info(0), Bits(0), NumClrs(0),
  W(0), H(0),
  IsCore(false), IsResHandle(false)
{
  InfoFromHandle();
}

//
// Construct a TDib borrowed from a clipboard handle
//
TDib::TDib(const TClipboard& clipboard)
:
  TGdiBase(clipboard.GetClipboardData(CF_DIB)),
  Info(0), Bits(0), NumClrs(0),
  W(0), H(0),
  IsCore(false), IsResHandle(false)
{
  InfoFromHandle();
}

//
// Construct a TDib that is a copy of an existing one
//
TDib::TDib(const TDib& dib)
:
  Info(0), Bits(0), NumClrs(0),
  W(0), H(0),
  IsCore(false), IsResHandle(false)
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

//
// Destruct a dib by unlocking & freeing its global memory handle as required
//
TDib::~TDib()
{
  if (Handle)
    if (IsResHandle) {
#if defined(BI_PLAT_WIN16)
      ::UnlockResource(Handle);
      if (ShouldDelete)
        ::FreeResource(Handle);
#endif
    }
    else {
      ::GlobalUnlock(Handle);
      if (ShouldDelete)
        ::GlobalFree(Handle);
    }
}

//
// Convert an absolute RGB color table to a palette relative color table
// Makes sure that color table is RGB
//
bool
TDib::ChangeModeToPal(const TPalette& pal)
{
  if (Mode != DIB_RGB_COLORS)
    return false;

  uint16 nEntries = pal.GetNumEntries();
  
  for (int c = 0; c < NumClrs; c++) {
    uint16 index = uint16(c);
    for (uint16 i = 0; i < nEntries; i++) {
      PALETTEENTRY pe; //getting all entries one time up front would be faster
      pal.GetPaletteEntry(i, pe);
      if (pe.peRed == Info->bmiColors[c].rgbRed &&
          pe.peGreen == Info->bmiColors[c].rgbGreen &&
          pe.peBlue == Info->bmiColors[c].rgbBlue) {
        index = i;
        break;
      }
    }
    ((uint16*)Info->bmiColors)[c] = index;
  }
  Mode = DIB_PAL_COLORS;
  return true;
}

//
// Convert a palette relative color table to an absolute RGB color table
// Makes sure that color table is pal relative & that there is enough space
//
bool
TDib::ChangeModeToRGB(const TPalette& pal)
{
  if (Mode != DIB_PAL_COLORS ||
      (int)((char*)Bits - (char*)Info) < NumClrs*sizeof(RGBQUAD))
    return false;
  
  uint16 nEntries = pal.GetNumEntries();

  for (int c = (int)NumClrs-1; c >= 0; c--) {
    uint16 i = ((uint16*)Info->bmiColors)[c];
    if (i >= nEntries)
      i = 0;
    PALETTEENTRY pe;
    pal.GetPaletteEntry(i, pe);
    Info->bmiColors[c].rgbRed = pe.peRed;
    Info->bmiColors[c].rgbGreen = pe.peGreen;
    Info->bmiColors[c].rgbBlue = pe.peBlue;
  }
  Mode = DIB_RGB_COLORS;
  return true;
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
TDib::MapColor(TColor fromColor, TColor toColor, bool doAll)
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
uint16
TDib::GetIndex(int entry) const
{
  if (entry >= 0 && entry < NumClrs)
    if (Mode == DIB_PAL_COLORS)
      return ((uint16*)GetColors())[entry];

  return 0;
}

void
TDib::SetIndex(int entry, uint16 index)
{
  if (entry >= 0 && entry < NumClrs)
    if (Mode == DIB_PAL_COLORS)
      ((uint16*)GetColors())[entry] = index;
}

int
TDib::FindIndex(uint16 index)
{
  for (int entry = 0; entry < NumClrs; entry++)
    if (GetIndices()[entry] == index)
      return entry;
  return -1;
}

int
TDib::MapIndex(uint16 fromIndex, uint16 toIndex, bool doAll)
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
TDib::MapUIColors(uint mapColors, TColor* bkColor)
{
  if (mapColors & TDib::MapFace)
    MapColor(TColor::LtGray, ::GetSysColor(COLOR_BTNFACE));
  if (mapColors & TDib::MapText)
    MapColor(TColor::Black, ::GetSysColor(COLOR_BTNTEXT));
  if (mapColors & TDib::MapShadow)
    MapColor(TColor::Gray, ::GetSysColor(COLOR_BTNSHADOW));
  if (mapColors & TDib::MapHighlight)
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
#if defined(BI_PLAT_WIN16)
      ::UnlockResource(Handle);
#endif
    }
    else {
      ::GlobalUnlock(Handle);
    }
    clipboard.SetClipboardData(CF_DIB, Handle);
    ShouldDelete = false;
    Info = 0;
    Bits = 0;
    Handle = 0;
  }
}

#endif
#if !defined(SECTION) || SECTION == 2  // Constructing & reading .BMP files

//
// Construct a Dib given a .BMP file name
//
TDib::TDib(const char* name)
:
  Info(0), Bits(0), NumClrs(0),
  W(0), H(0),
  IsCore(false), IsResHandle(false)
{
  if (!ReadFile(name))
    THROW( TXGdi(IDS_GDIFILEREADFAIL) );
}

#if !defined(BI_DATA_NEAR)

TDib::TDib(istream& is, bool readFileHeader)
:
  Info(0), Bits(0), NumClrs(0),
  W(0), H(0),
  IsCore(false), IsResHandle(false)
{
  if (!Read(is, readFileHeader))
    THROW( TXGdi(IDS_GDIFILEREADFAIL) );
}
#endif
  
//
// Construct an empty Dib for use by derived classes
//
TDib::TDib()
:
  Info(0), Bits(0), NumClrs(0),
  W(0), H(0),
  IsCore(false), IsResHandle(false)
{
  // Handle must be set by derived class
  // InfoFromHandle() or equivalent must then be called
}

//
// Test if the passed file is a Windows 3.0 (or PM 1.x) DI bitmap and if so
// read it. Return false if unable to do so.
//
bool
TDib::ReadFile(const char* name)
{
  TFile file(name, TFile::ReadOnly);
  if (!file.IsOpen()) {
    TRACEX(OwlGDI, 0, "Cannot open bitmap file '" << name << "' to read");
    return false;
  }

  // Read the bitmap in, file header & all
  //
  bool ok = Read(file, true);

  file.Close();
  return ok;
}

//
// Read a Windows 3.0 or PM 1.X device independent bitmap. (.BMP)
//  Check header, read Info, palette and bitmap.  PM Dibs can be converted to
//  Win 3.0 Dibs on the fly.
// Return true iff Dib was read OK
//
bool
TDib::Read(TFile& file, bool readFileHeader)
{
  long offBits = 0;

  // Read file header and verify the signature. Grab bfOffBits if it is != 0
  // We ignore all other information in the file header since some applications
  // do not put correct information in the fields...
  //
  if (readFileHeader) {
    BITMAPFILEHEADER bmf;
    if (file.Read(&bmf, sizeof(bmf)) != sizeof(bmf) || bmf.bfType != 'BM') {
      TRACEX(OwlGDI, 0, "Not a Windows 3.x or PM 1.x bitmap file");
      return false;
    }
    if (bmf.bfOffBits)
      offBits = bmf.bfOffBits - sizeof(BITMAPFILEHEADER);
  }

  // Read bitmap header & check size
  //
  uint32 headerSize;
  if (file.Read(&headerSize, sizeof(headerSize)) != sizeof(headerSize)
      || headerSize != sizeof(BITMAPCOREHEADER)
      && headerSize != sizeof(BITMAPINFOHEADER)) {
    TRACEX(OwlGDI, 0, "Not a Windows 3.x or PM 1.x bitmap file");
    return false;
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
  if (file.Read(&infoHeader.biWidth, (int)headerSize-sizeof(uint32)) !=
      (int)headerSize-sizeof(uint32)) {
    TRACEX(OwlGDI, 0, "Invalid DIB Header");
    return false;
  }

  // Type dependent fields kept independently
  //
  uint16 bitCount;
  int    colorAlloc;
  int    colorRead;
  uint32 bitsAlloc;

  // If this is a PM 1.X Dib, expand header and fill out reamining fields
  // for win3 dib info
  // Calculate size of color table in memory using RGBQUADs if converting.
  // For PM Dibs, this is NOT the size on disk.
  //
  if (headerSize == sizeof(BITMAPCOREHEADER)) {
    // check number of planes. Windows 3.x supports only 1 plane DIBs
    if (coreHeader.bcPlanes != 1) {
      TRACEX(OwlGDI, 0, "Invalid number of planes in PM 1.X bitmap");
      return false;
    }
    bitCount = coreHeader.bcBitCount;
    NumClrs = NColors(bitCount);
    colorRead = (int)NumClrs * sizeof(RGBTRIPLE); // Color tables on disk
    W = coreHeader.bcWidth;
    H = coreHeader.bcHeight;
    #if defined(CVT_CORE_TO_INFO)
      IsCore = false;
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
      IsCore = true;
      colorAlloc = colorRead;
    #endif
    bitsAlloc = 0;      // Calculate below
  }
  else {
    // check number of planes. Windows 3.x supports only 1 plane DIBs
    if (infoHeader.biPlanes != 1) {
      TRACEX(OwlGDI, 0, "Invalid number of planes in Win 3.X bitmap");
      return false;
    }
    IsCore = false;
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
      return false;
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

  // Locate & Read Bits, skipping Pad if any. Ignore offBits if it is zero.
  // Ignore offBits if less than the current position (it's probably bad)
  //
  Bits = (char far*)Info + ((int)infoHeader.biSize + colorAlloc);
  if (offBits && offBits - (long)(headerSize+colorRead) > 0)
    file.Seek(offBits - (headerSize+colorRead), TFile::cur);
  if (file.Read(Bits, bitsAlloc) != bitsAlloc) {
    TRACEX(OwlGDI, 0, "Could not read DIB bits");
    return false;
  }
  return true;
}


#if !defined(BI_DATA_NEAR)

#if defined(BI_PLAT_WIN16)  

static bool
bigRead(istream& is, char HUGE* p, long len)
{
  const int PtrIncSize = 0x4000;

  long bytesLeft = len;
  int  passBytes = 0;

  // Bring pointer offset to right multiple
  //
  if (OFFSETOF(p) != 0  && bytesLeft > 0) {
    passBytes = (int)min(long(PtrIncSize - (OFFSETOF(p) % PtrIncSize)), 
                         bytesLeft);
    if (!is.read((char*)p, passBytes)) 
      return false;
    p += passBytes;
    bytesLeft -= passBytes;
  } 

  // Cycle through a chunk at a time
  //
  while (bytesLeft >  0) {
    passBytes = (int)min(long(PtrIncSize), bytesLeft);
    if (!is.read((char*)p, passBytes))
      return false;
    p += passBytes;
    bytesLeft -= passBytes;
  }
  return true;
}

#endif  //  BI_PLAT_WIN16   


//
// Read a Windows 3.0 or PM 1.X device independent bitmap. (.BMP)
//  Check header, read Info, palette and bitmap.  PM Dibs can be converted to
//  Win 3.0 Dibs on the fly.
// Return true iff Dib was read OK
//
bool
TDib::Read(istream& is, bool readFileHeader)
{
  long offBits = 0;

  // Read file header and verify the signature. Grab bfOffBits if it is != 0
  // We ignore all other information in the file header since some applications
  // do not put correct information in the fields...
  //
  if (readFileHeader) {
    BITMAPFILEHEADER bmf;
    if (!is.read((char*)&bmf, sizeof(bmf)) || bmf.bfType != 'BM') {
      TRACEX(OwlGDI, 0, "Not a Windows 3.x or PM 1.x bitmap file");
      return false;
    }
    if (bmf.bfOffBits)
      offBits = bmf.bfOffBits - sizeof(BITMAPFILEHEADER);
  }

  uint32 headerSize;
  if (!is.read((char*)&headerSize, sizeof(headerSize))
      || headerSize != sizeof(BITMAPCOREHEADER)
      && headerSize != sizeof(BITMAPINFOHEADER)) {
    TRACEX(OwlGDI, 0, "Not a Windows 3.x or PM 1.x bitmap file");
    return false;
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
  if (!is.read((char*)&infoHeader.biWidth, (int)headerSize-sizeof(uint32))) {
    TRACEX(OwlGDI, 0, "Invalid DIB Header");
    return false;
  }

  // Type dependent fields kept independently
  //
  uint16 bitCount;
  int    colorAlloc;
  int    colorRead;
  uint32 bitsAlloc;

  // If this is a PM 1.X Dib, expand header and fill out reamining fields
  // for win3 dib info
  // Calculate size of color table in memory using RGBQUADs if converting.
  // For PM Dibs, this is NOT the size on disk.
  //
  if (headerSize == sizeof(BITMAPCOREHEADER)) {
    // check number of planes. Windows 3.x supports only 1 plane DIBs
    if (coreHeader.bcPlanes != 1) {
      TRACEX(OwlGDI, 0, "Invalid number of planes in PM 1.X bitmap");
      return false;
    }
    bitCount = coreHeader.bcBitCount;
    NumClrs = NColors(bitCount);
    colorRead = (int)NumClrs * sizeof(RGBTRIPLE); // Color tables on disk
    W = coreHeader.bcWidth;
    H = coreHeader.bcHeight;
    #if defined(CVT_CORE_TO_INFO)
      IsCore = false;
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
      IsCore = true;
      colorAlloc = colorRead;
    #endif
    bitsAlloc = 0;      // Calculate below
  }
  else {
    // check number of planes. Windows 3.x supports only 1 plane DIBs
    if (infoHeader.biPlanes != 1) {
      TRACEX(OwlGDI, 0, "Invalid number of planes in Win 3.X bitmap");
      return false;
    }
    IsCore = false;
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
    if (!is.read((char*)Info+(int)infoHeader.biSize, colorRead)) {
      TRACEX(OwlGDI, 0, "Could not read color table");
      ::GlobalUnlock(Handle);
      return false;
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

  // Locate & Read Bits, skipping Pad if any. Ignore offBits if it is zero.
  // Ignore offBits if less than the current position (it's probably bad)
  //
  Bits = (char far*)Info + ((int)infoHeader.biSize + colorAlloc);
  if (offBits && offBits - (long)(headerSize+colorRead) > 0)
    is.seekg(offBits - (headerSize+colorRead), ios::cur);

#if defined(BI_PLAT_WIN16)
  if (!bigRead(is, (char*)Bits, bitsAlloc)) {
    TRACEX(OwlGDI, 0, "Could not read DIB bits");
    return false;
  }
#else
  if (!is.read((char*)Bits, bitsAlloc)) {
    TRACEX(OwlGDI, 0, "Could not read DIB bits");
    return false;
  }
#endif  
  return true;
}
#endif  // !defined(BI_DATA_NEAR)

#endif
#if !defined(SECTION) || SECTION == 3 // constructing & reading DIB resources

//
// Construct a Dib given a module instance and a resource name or int Id
//
TDib::TDib(HINSTANCE instance, TResId resId)
:
  Info(0), Bits(0), NumClrs(0),
  W(0), H(0),
  IsCore(false), IsResHandle(false)
{
  if (!LoadResource(instance, resId))
    THROW( TXGdi(IDS_GDIRESLOADFAIL) );
}

//
// Load a dib resource into an empty dib.
//
bool
TDib::LoadResource(HINSTANCE instance, TResId resId)
{
  // First, load the resource into a global memory block.
  //
  HRSRC  resHandle = ::FindResource(instance, resId, RT_BITMAP);
  if (resHandle)
    Handle = ::LoadResource(instance, resHandle);
  else
    Handle = 0;
  if (!Handle) {
    TRACEX(OwlGDI, 0, "Cannot access bitmap resource");
    return false;
  }
  IsResHandle = true;

  // Then update our pointers & other info.
  //
  InfoFromHandle();

  // Under Win32, resources are read-only. So, to allow for later modification
  // of the Dib, a copy must be made. Could postpone this until dib needed
  // to be written on...
  //
#if defined(BI_PLAT_WIN32)
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
  IsResHandle = false;
  InfoFromHandle();
#endif

  return true;
}

#endif
#if !defined(SECTION) || SECTION == 4  // Writing BMP files

//
// 
//
bool
TDib::WriteFile(const char* name)
{
  TFile file(name, TFile::WriteOnly|TFile::Create|TFile::DenyRdWr, TFile::PermRdWr);

  if (!file.IsOpen()) {
    TRACEX(OwlGDI, 0, "Cannot open bitmap file '" << name << "' to write");
    return false;
  }

  bool ok = Write(file, true);

  file.Close();
  if (!ok) {
    TRACEX(OwlGDI, 0, "Disk error writing file '" << name << "'");
    return false;
  }
  return true;
}

//
// 
//
bool
TDib::Write(TFile& file, bool writeFileHeader)
{
  long size = ::GlobalSize(Handle);

  // write file header
  //
  if (writeFileHeader) {
    BITMAPFILEHEADER bmf;
    bmf.bfType = 'BM';
    bmf.bfSize = sizeof(bmf) + size;
    bmf.bfReserved1 = 0;
    bmf.bfReserved2 = 0;
    bmf.bfOffBits = sizeof(bmf) + (char far*)Bits - (char far*)Info;
    if (file.Write(&bmf, sizeof(bmf)) != sizeof(bmf))
      return false;
  }

  // Write rest of dib, including dib header, color table & bits
  //
  if (file.Write((void HUGE*)Info, size) != size)
    return false;

  return true;
}

#if !defined(BI_DATA_NEAR)

#if defined(BI_PLAT_WIN16)

static bool
bigWrite(ostream& os, char HUGE* p, long len)
{
  const int PtrIncSize = 0x4000;

  long bytesLeft = len;
  int  passBytes = 0;

  // Bring pointer offset to proper multiple
  //
  if (OFFSETOF(p) != 0  && bytesLeft > 0) {
    passBytes = (int)min(long(PtrIncSize - (OFFSETOF(p) % PtrIncSize)), 
                         bytesLeft);
    if (!os.write((char*)p, passBytes)) 
      return false;
    p += passBytes;
    bytesLeft -= passBytes;
  } 

  // Cycle through a chunk at a time
  //
  while (bytesLeft >  0) {
    passBytes = (int)min(long(PtrIncSize), bytesLeft);
    if (!os.write((char*)p, passBytes))
      return false;
    p += passBytes;
    bytesLeft -= passBytes;
  }
  return true;
}

#endif  //  BI_PLAT_WIN16


//
// 
//
bool
TDib::Write(ostream& os, bool writeFileHeader)
{
  long size = ::GlobalSize(Handle);

  // write file header
  //
  if (writeFileHeader) {
    BITMAPFILEHEADER bmf;
    bmf.bfType = 'BM';
    bmf.bfSize = sizeof(bmf) + size;
    bmf.bfReserved1 = 0;
    bmf.bfReserved2 = 0;
    bmf.bfOffBits = sizeof(bmf) + (char far*)Bits - (char far*)Info;
    if (!os.write((char*)&bmf, sizeof(bmf)))
      return false;
  }

  // Write rest of dib, including dib header, color table & bits
  //
#if defined(BI_PLAT_WIN16)
  if (!bigWrite(os, (char*)Info, size))
    return false;
#else
  if (!os.write((char*)Info, size))
    return false;
#endif

  return true;
}
#endif  // !defined(BI_DATA_NEAR)

#endif
#if !defined(SECTION) || SECTION == 5

//
// Construct a Dib given dimensions and color depth
//
TDib::TDib(int width, int height, int nColors, uint16 mode)
:
  Info(0), Bits(0), NumClrs(0),
  W(0), H(0),
  IsCore(false), IsResHandle(false)
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
  InfoHeader.biClrImportant  = 0;   // nColors ?;
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
    for (uint16 i = 0; i < nColors; i++)
      ((uint16*)Info->bmiColors)[i] = i;
  }
  else {
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

#endif
#if !defined(SECTION) || SECTION == 6

//
// Construct a TDib given a TBitmap and a TPalette
// If no palette is give, uses the one in the focus window.
//
TDib::TDib(const TBitmap& bitmap, const TPalette* palette)
:
  Info(0), Bits(0), NumClrs(0),
  W(0), H(0),
  IsCore(false), IsResHandle(false)
{
  BITMAP  bm;
  bitmap.GetObject(bm);

  uint16            bitCount;
  BITMAPINFOHEADER  infoHeader;

  IsCore = false;
  infoHeader.biSize       = sizeof(BITMAPINFOHEADER);
  infoHeader.biWidth      = W = bm.bmWidth;
  infoHeader.biHeight     = H = bm.bmHeight;
  if (palette) {
    uint16 nColors;
    palette->GetObject(nColors);
    infoHeader.biBitCount    = bitCount = NBits(nColors);
  }
  else
    infoHeader.biBitCount    = bitCount = uint16(bm.bmBitsPixel*bm.bmPlanes);
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
    dc.SelectObject(*palette, false);
  Bits = (char far*)Info + ((int)infoHeader.biSize + colorAlloc);
  Mode = DIB_RGB_COLORS;
  dc.GetDIBits(bitmap, StartScan(), NumScans(), Bits, *Info, Usage());
}

#endif
