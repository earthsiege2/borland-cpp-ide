//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.11  $
//
// Implementation of TDibDC encapsulation class, including the use of WinG when
// needed.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_DC_H)
# include <owl/dc.h>
#endif
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif
#if !defined(OWL_WING_H) && defined(BI_PLAT_WIN16)
# include <owl/wing.h>
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlGDI);        // General GDI diagnostic group

//
// Construct a DC that can be used with DI Bitmaps. Under Win32 bitmaps
// selected must be DIBSections, under Win16 they must be WinG bitmaps.
//
TDibDC::TDibDC()
:
#if defined(BI_PLAT_WIN16)
  TMemoryDC(TWinG::IsAvailable() ? TWinG::Dll()->CreateDC() : 0, AutoDelete)
#else
  TMemoryDC()
#endif
{
#if defined(BI_PLAT_WIN16)
  CheckValid(TWinG::IsAvailable() ? IDS_WINGFAILURE : IDS_WINGNOTAVAILABLE);
#else
  CheckValid();
#endif
}

//
// Construct a DC, same as above, then auto select the given bitmap in.
//
TDibDC::TDibDC(const TBitmap& bitmap)
:
#if defined(BI_PLAT_WIN16)
  TMemoryDC(TWinG::IsAvailable() ? TWinG::Dll()->CreateDC() : 0, AutoDelete)
#else
  TMemoryDC()
#endif
{
  CheckValid();
  SelectObject(bitmap);
}


//
// Get the color table of the currently selected bitmap.
//
uint
TDibDC::GetDIBColorTable(uint start, uint count, RGBQUAD far* colors)
{
#if defined(BI_PLAT_WIN16)
  if (TWinG::IsAvailable())
    return TWinG::Dll()->GetDIBColorTable(GetHDC(), start, count, colors);
  return 0;
#else
  return ::GetDIBColorTable(GetHDC(), start, count, colors);
#endif
}

//
// Set the color table of the currently selected bitmap.
//
uint
TDibDC::SetDIBColorTable(uint start, uint count, const RGBQUAD far* colors)
{
#if defined(BI_PLAT_WIN16)
  if (TWinG::IsAvailable())
    return TWinG::Dll()->SetDIBColorTable(GetHDC(), start, count, colors);
  return 0;
#else
  return ::SetDIBColorTable(GetHDC(), start, count, colors);
#endif
}


//
// Dib Screen Update BitBlt's. A screen DC must be the destination.
// BitBlts from this DIB onto the destination DC.
//
bool
TDibDC::BitBltToScreen(TDC& dstDC, const TRect& dst, const TPoint& src) const
{
#if defined(BI_PLAT_WIN32)
  return dstDC.BitBlt(dst, *this, src);
#else
  return TWinG::Dll()->BitBlt(dstDC, dst.left, dst.top, dst.Width(), dst.Height(),
                            GetHDC(), src.x, src.y);
#endif
}

//
// BitBlts from this DIB onto the destination DC.
//
bool
TDibDC::BitBltToScreen(TDC& dstDC, int dstX, int dstY, int dstW, int dstH,
                       int srcX, int srcY) const
{
#if defined(BI_PLAT_WIN32)
  return dstDC.BitBlt(dstX, dstY, dstW, dstH, *this, srcX, srcY);
#else
  return TWinG::Dll()->BitBlt(dstDC, dstX, dstY, dstW, dstH, GetHDC(), srcX, srcY);
#endif
}

//
// Stretches the DIB onto the destination DC.
//
bool
TDibDC::StretchBltToScreen(TDC& dstDC, const TRect& dst, const TRect& src) const
{
#if defined(BI_PLAT_WIN32)
  return dstDC.StretchBlt(dst, *this, src);
#else
  return TWinG::Dll()->StretchBlt(dstDC, dst.left, dst.top, dst.Width(), dst.Height(),
                                GetHDC(), src.left, src.top, src.Width(), src.Height());
#endif
}

//
// Stretches the DIB onto the destination DC.
//
bool
TDibDC::StretchBltToScreen(TDC& dstDC, int dstX, int dstY, int dstW, int dstH,
                           int srcX, int srcY, int srcW, int srcH) const
{
#if defined(BI_PLAT_WIN32)
  return dstDC.StretchBlt(dstX, dstY, dstW, dstH, *this, srcX, srcY, srcW, srcH);
#else
  return TWinG::Dll()->StretchBlt(dstDC, dstX, dstY, dstW, dstH,
                                GetHDC(), srcX, srcY, srcW, srcH);
#endif
}

