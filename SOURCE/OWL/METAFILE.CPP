//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of TMetaFilePict class
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/metafile.h>
#include <owl/gdiobjec.h>
#include <owl/clipboar.h>
#include <owl/except.h>


TMetaFilePict::TMetaFilePict(HMETAFILE handle, TAutoDelete autoDelete)
:
  TGdiBase(handle, autoDelete),
  Extent(0,0)
{
  Mm = MM_ANISOTROPIC;
}

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

TMetaFilePict::TMetaFilePict(uint size, void* data)
:
  TGdiBase(::SetMetaFileBitsEx(size, (LPBYTE)data), NoAutoDelete),
  Extent(0,0)
{
  CheckValid();
  Mm = MM_ANISOTROPIC;
}

#else

TMetaFilePict::TMetaFilePict(HGLOBAL data)
:
  TGdiBase(::SetMetaFileBitsBetter(data), NoAutoDelete),
  Extent(0,0)
{
  CheckValid();
  Mm = MM_ANISOTROPIC;
}

#endif

TMetaFilePict::TMetaFilePict(const TMetaFilePict& src, const char far* fileName)
:
  TGdiBase(::CopyMetaFile(src, fileName), AutoDelete),
  Extent(src.Extent)
{
  CheckValid();
  Mm = src.Mm;
}

TMetaFilePict::~TMetaFilePict()
{
  if (ShouldDelete && Handle)
    ::DeleteMetaFile(HMETAFILE(Handle));
}

#if defined(BI_PLAT_WIN32)

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
    THROW( TXOutOfMemory() );
  METAFILEPICT far* mfp = (METAFILEPICT far*)::GlobalLock(hmfp);
  mfp->mm = mapMode;
  mfp->xExt = extent.cx;
  mfp->yExt = extent.cy;
  mfp->hMF = (HMETAFILE)Handle;
  ::GlobalUnlock(hmfp);
  
  clipboard.SetClipboardData(CF_METAFILEPICT, hmfp);
  ShouldDelete = false;
}
