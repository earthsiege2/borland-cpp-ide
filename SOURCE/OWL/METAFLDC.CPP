//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Implementation of class TMetaFileDC, a Metafile DC encapsulation
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_DC_H)
# include <owl/dc.h>
#endif

//
// Create a regular metafile DC.
//
TMetaFileDC::TMetaFileDC(const char far* filename)
:
  TDC(),
  Enhanced(false)
{
  Handle = ::CreateMetaFile(filename);
  CheckValid();
}

//
// Destroy the metafile.
//
TMetaFileDC::~TMetaFileDC()
{
  if (Handle) {
    if (ShouldDelete)
      // Do not restore objects, Metafiles cleanup after themselves
      //
#if defined(BI_PLAT_WIN32)
      if (IsEnhanced())
        ::DeleteEnhMetaFile(CloseEnh());
      else
#endif
        ::DeleteMetaFile(Close());
    Handle = 0;
  }
}

#if defined(BI_PLAT_WIN32)
//
// Create an enhanced metafile dc.
//
TMetaFileDC::TMetaFileDC(const TDC& dc, const char far* filename, TRect* rect,
                         const char far* description)
:
  TDC(),
  Enhanced(true)
{
  Handle = ::CreateEnhMetaFile(dc, filename, rect, description);
  CheckValid();
}
#endif  // BI_PLAT_WIN32
