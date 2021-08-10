//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
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

//
// Alias an existing meta file handle.
//
TMetaFilePict::TMetaFilePict(HMETAFILE handle, TAutoDelete autoDelete)
:
  TGdiBase(handle, autoDelete),
  Extent(0,0)
{
  Mm = MM_ANISOTROPIC;
}

//
// Create a metafile object from an external file.
//
TMetaFilePict::TMetaFilePict(const char* filename)
:
  TGdiBase(::GetMetaFile(filename), AutoDelete),
  Extent(0,0)
{
  Mm = MM_ANISOTROPIC;
}

//
// Construct a TMetaFilePict that represents the metafilepict on the clipboard.
// Should be copied if metafile needs to be kept.
//
TMetaFilePict::TMetaFilePict(const TClipboard&)
:
  Extent(0,0)
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
  Extent(0,0)
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
  Extent(0,0)
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
  Extent(src.Extent)
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
  if (Mm != MM_ISOTROPIC && Mm != MM_ANISOTROPIC)
    return Extent;    // Assumes extents were calculated correctly.

  // If no extent info given, then use defaults
  //
  if (!Extent.cx) {
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

  // Set the viewport extent to the size that the metafile wil play to
  //
  if ((Mm == MM_ISOTROPIC || Mm == MM_ANISOTROPIC) && Extent.cx && Extent.cy)
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
