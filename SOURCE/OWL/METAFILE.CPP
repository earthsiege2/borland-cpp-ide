//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.8  $
//
// Implementation of TMetaFilePict class
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_METAFILE_H)
# include <owl/metafile.h>
#endif
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif
#if !defined(OWL_CLIPBOAR_H)
# include <owl/clipboar.h>
#endif
#if !defined(OWL_EXCEPT_H)
# include <owl/except.h>
#endif
#if !defined(CLASSLIB_FILE_H)
# include <classlib/file.h>
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlGDI);        // General GDI diagnostic group

// Constant for checking validity of a METAFILEHEADER
//
const uint32 TMetaFilePict::MFHeaderKey = 0x9AC6CDD7L;

//
// Alias an existing meta file handle.
//
TMetaFilePict::TMetaFilePict(HMETAFILE handle, TAutoDelete autoDelete)
:
  TGdiBase(handle, autoDelete),
  Extent(0,0),
  Placeable(false)
{
  Mm = MM_ANISOTROPIC;
}

//
// Create a metafile object from an external file.
//
TMetaFilePict::TMetaFilePict(const char* filename)
:
  Extent(0,0),
  Placeable(false)
{
  TFile file;

  file.Open(filename, O_RDONLY, SH_DENYWR);
  file.Read(&MFHeader, sizeof(MFHeader));

  // Determine whether this file begins with a valid METAFILEHEADER
  // struct and load the file accordingly.
  //
  if ((MFHeader.key == MFHeaderKey)
      && (MFHeader.checksum == CalcHeaderChecksum(MFHeader)))
  {
    // Determine size of metafile data
    //
    TFileStatus status;
    file.GetStatus(status);
    long size = status.size - sizeof(METAFILEHEADER);

    // Convert the data to a metafile
    //
    HGLOBAL hMem = ::GlobalAlloc(GMEM_MOVEABLE, size);
    if (!hMem)
      TXOutOfMemory::Raise();
    unsigned char _huge* pMem = (unsigned char _huge*)GlobalLock(hMem);
    file.Read((void _huge*)pMem, size);

#if defined(BI_PLAT_WIN32)
    Handle = SetMetaFileBitsEx(size, pMem);
    GlobalUnlock(hMem);
#else
    Handle = SetMetaFileBits(hMem);
    GlobalUnlock(hMem);    
#endif

    // Remember that this metafile comes with a placeable header
    // (in other words, MFHeader holds valid data)
    //
    if (Handle)
      Placeable = true;

    // Placeable metafiles are meant to be played back in
    // the unconstrained mapping mode.  The header tells
    // the desired size and aspect ratio.
    //
    Mm = MM_ANISOTROPIC;

    // Set metafile dimensions according to info in header
    //
    Extent.cx = MFHeader.bbox.right - MFHeader.bbox.left;
    Extent.cy = MFHeader.bbox.bottom - MFHeader.bbox.top;

    // Convert dimensions to HIMETRIC units (.001 cm)
    //
    Extent.cx = MulDiv(Extent.cx, 2540, MFHeader.inch);
    Extent.cy = MulDiv(Extent.cy, 2540, MFHeader.inch);
  }  
  else {
    Mm = MM_ANISOTROPIC;
    Handle = ::GetMetaFile(filename);
  }
  ShouldDelete = true;
  file.Close();
  CheckValid();
}

//
// Construct a TMetaFilePict that represents the metafilepict on the clipboard.
// Should be copied if metafile needs to be kept.
//
TMetaFilePict::TMetaFilePict(const TClipboard&)
:
  Extent(0,0),
  Placeable(false)
{
  HGLOBAL hmfp = ::GetClipboardData(CF_METAFILEPICT);
  METAFILEPICT far* mfp = (METAFILEPICT far*)::GlobalLock(hmfp);

  if (mfp) {
    Mm = mfp->mm;
    Extent = TSize(mfp->xExt, mfp->yExt);
    Handle = mfp->hMF;
    ::GlobalUnlock(hmfp);
  }
  else
    Handle = 0;

  ShouldDelete = false;
  CheckValid();
}

#if defined(BI_PLAT_WIN32)

//
// Create an enhanced metafile from a memory buffer.
//
TMetaFilePict::TMetaFilePict(uint size, void* data)
:
  TGdiBase(::SetMetaFileBitsEx(size, (LPBYTE)data), NoAutoDelete),
  Extent(0,0),
  Placeable(false)
{
  CheckValid();
  Mm = MM_ANISOTROPIC;
}

#else

//
// Create a meta file from a memory buffer.
//
TMetaFilePict::TMetaFilePict(HGLOBAL data)
:
  TGdiBase(::SetMetaFileBitsBetter(data), NoAutoDelete),
  Extent(0,0),
  Placeable(false)
{
  CheckValid();
  Mm = MM_ANISOTROPIC;
}

#endif

//
// Copy the metafile.
//
TMetaFilePict::TMetaFilePict(const TMetaFilePict& src, const char far* fileName)
:
  TGdiBase(::CopyMetaFile(src, fileName), AutoDelete),
  Extent(src.Extent),
  Placeable(false)
{
  CheckValid();
  Mm = src.Mm;
}

//
// Delete the metafile.
//
TMetaFilePict::~TMetaFilePict()
{
  if (ShouldDelete && Handle)
    ::DeleteMetaFile(HMETAFILE(Handle));
}

//
// Read the fields in the file header structure of a placeable
// metafile and compute a checksum value for verifying the
// header's integrity.
//
uint16
TMetaFilePict::CalcHeaderChecksum(const METAFILEHEADER& header)
{
  LPWORD lpw;             // pointer to words in header 
  uint16 checksum = 0;

  for (lpw = (LPWORD)&header;
       lpw < (LPWORD)&header.checksum;
       ++lpw)
  {
    // XOR current checksum with next field 
    //
    checksum ^= *lpw;
  }

  return checksum;
}

#if defined(BI_PLAT_WIN32)

//
// Retrieve the bits of the metafile.
//
uint32
TMetaFilePict::GetMetaFileBitsEx(uint size, void* data)
{
  return ::GetMetaFileBitsEx(HMETAFILE(Handle), size, (LPBYTE)data);
}

#endif

//
// Calculates target play size based on info from the metafilepict (if any)
// and default target size as necessary
//
TSize
TMetaFilePict::CalcPlaySize(TDC& dc, const TSize& defSize) const
{
  // Given a fixed mapping mode, return precalculated extents
  //
  if (Mm != MM_ISOTROPIC && Mm != MM_ANISOTROPIC) {
    WARNX(OwlGDI, (Extent.X() == 0) || (Extent.Y() == 0), 0, "Constrained metafile extent == 0");
    return Extent;    // Assumes extents were calculated correctly.
  }

  //
  // Metafile uses partially constrained or unconstrained mapping mode
  //

  // If no extent info given, then use defaults
  //
  if (Extent.X() == 0) {
    WARNX(OwlGDI, (defSize.X() == 0) || (defSize.Y() == 0), 0, "Metafile using default extent == 0");
    return defSize;
  }

  // Use positive extents scaled to 0.01mm units
  //
  else if (Extent.cx > 0) {
    return TSize(
        int(long(Extent.cx)*dc.GetDeviceCaps(HORZRES)/dc.GetDeviceCaps(HORZSIZE)/100),
        int(long(Extent.cy)*dc.GetDeviceCaps(VERTRES)/dc.GetDeviceCaps(VERTSIZE)/100)
      );
  }
  // Use negative extents scaled to 0.01mm units w/ aspect ratio scaling
  //
  else {
    long xscale = 100L * defSize.cx *
      dc.GetDeviceCaps(HORZSIZE)/dc.GetDeviceCaps(HORZRES) / -Extent.cx;
    long yscale = 100L * defSize.cy *
      dc.GetDeviceCaps(VERTSIZE)/dc.GetDeviceCaps(VERTRES) / -Extent.cy;
    long scale = min(xscale, yscale);
    return TSize(
      int(long(-Extent.cx)*scale*dc.GetDeviceCaps(HORZRES)/dc.GetDeviceCaps(HORZSIZE) / 100),
      int(long(-Extent.cy)*scale*dc.GetDeviceCaps(VERTRES)/dc.GetDeviceCaps(VERTSIZE) / 100)
    );
  }
}

//
// Play this metafile onto a dc, possibly using a default size if this
// metafile doesn't have one. Does not save dc state.
//
bool
TMetaFilePict::PlayOnto(TDC& dc, const TSize& defSize) const
{
  // Set target dc's mapping mode to this metafile's if there is one
  //
  if (Mm)
    dc.SetMapMode(Mm);

  // Set the viewport extent to the area that the metafile will fill
  //
  if (Mm == MM_ISOTROPIC || Mm == MM_ANISOTROPIC)
    dc.SetViewportExt(CalcPlaySize(dc, defSize));

  return ::PlayMetaFile(dc, *this);
}

//
// Move this metafile to the clipboard inside of a metafilepict struct.
// Ownership of the metafilepict as well as the metafile is passed to the
// clipboard.
//
void
TMetaFilePict::ToClipboard(TClipboard& clipboard, unsigned mapMode,
                           const TSize& extent)
{

  HGLOBAL hmfp = ::GlobalAlloc(GMEM_MOVEABLE, sizeof(METAFILEPICT));
  if (!hmfp)
    TXOutOfMemory::Raise();
  METAFILEPICT far* mfp = (METAFILEPICT far*)::GlobalLock(hmfp);
  mfp->mm = mapMode;
  mfp->xExt = extent.cx;
  mfp->yExt = extent.cy;
  mfp->hMF = (HMETAFILE)Handle;
  ::GlobalUnlock(hmfp);

  clipboard.SetClipboardData(CF_METAFILEPICT, hmfp);
  ShouldDelete = false;
}

#if defined(BI_PLAT_WIN32)

//
// Alias an existing enhanced metafile handle.
//
TEnhMetaFilePict::TEnhMetaFilePict(HENHMETAFILE handle, TAutoDelete autoDelete)
:
  TGdiBase(handle, autoDelete)
{
}

//
// Create an enhanced metafile from an external file.
//
TEnhMetaFilePict::TEnhMetaFilePict(const char* filename)
:
  TGdiBase(::GetEnhMetaFile(filename), AutoDelete)
{
}

//
// Copy a metafile
//
TEnhMetaFilePict::TEnhMetaFilePict(const TEnhMetaFilePict& metafilepict,
                                   const char far* filename)
:
  TGdiBase(::CopyEnhMetaFile(metafilepict, filename), AutoDelete)
{
}

//
// Create metafile from buffer
//
TEnhMetaFilePict::TEnhMetaFilePict(uint bytes, const void* buffer)
:
  TGdiBase(::SetEnhMetaFileBits(bytes, (const BYTE*)buffer), AutoDelete)
{
}

//
// Destroy the enhanced metafile picture.
//
TEnhMetaFilePict::~TEnhMetaFilePict()
{
  if (ShouldDelete && Handle)
    ::DeleteEnhMetaFile(HENHMETAFILE(Handle));
}

//
// Plays the metafile onto a device context.
//
bool
TEnhMetaFilePict::PlayOnto(TDC& dc, const TRect* rect) const
{
  return ::PlayEnhMetaFile(dc, *this, rect);
}


#endif  // BI_PLAT_WIN32
