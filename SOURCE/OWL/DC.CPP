//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Implementation of class TDC
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_DC_H)
# include <owl/dc.h>
#endif

DIAG_DECLARE_GROUP(OwlGDI);        // General GDI diagnostic group

//
//
//
void
TDC::Init()
{
  OrgBrush = 0;
  OrgPen = 0;
  OrgFont = 0;
  OrgPalette = 0;
#if defined(BI_PLAT_WIN32)
  OrgTextBrush = 0;
#endif
}

//
//
//
TDC::TDC(HDC handle)
:
  TGdiBase(handle, NoAutoDelete)
{
  Init();
  TRACEX(OwlGDI, OWL_CDLEVEL, "TDC constructed @" << (void*)this <<
    " from handle" << uint(handle));
}

//
// Following two ctors are for use by derived classes only
//
TDC::TDC()
{
  Init();
  TRACEX(OwlGDI, OWL_CDLEVEL, "TDC constructed @" << (void*)this);
}

//
//
//
TDC::TDC(HDC handle, TAutoDelete autoDelete)
:
  TGdiBase(handle, autoDelete)
{
  Init();
  TRACEX(OwlGDI, OWL_CDLEVEL, "TDC constructed @" << (void*)this <<
    " from handle" << uint(handle));
}

//
// Default dtor does not delete Handle
//
TDC::~TDC()
{
  RestoreObjects();
  TRACEX(OwlGDI, OWL_CDLEVEL, "TDC destructed @" << (void*)this);
}

//
//
//
HDC
TDC::GetAttributeHDC() const
{
  return HDC(Handle);
}

//
//
//
void
TDC::SelectObject(const TPen& pen)
{
  TRACEX(OwlGDI, 1, "TDC::SelectPen @" << (void*)this <<
    " pen @" << (void*)&pen);
  HPEN oldPen = (HPEN)::SelectObject(GetHDC(), pen);
  if (oldPen) {
    TGdiObject::RefInc(pen);
    if (uint(oldPen) > 1)
      if (!OrgPen)
        OrgPen = oldPen;
      else
        TGdiObject::RefDec(oldPen, false);
  }
}

//
//
//
void
TDC::SelectObject(const TBrush& brush)
{
  TRACEX(OwlGDI, 1, "TDC::SelectBrush @" << (void*)this <<
    " brush @" << (void*)&brush);
  HBRUSH oldBrush = (HBRUSH)::SelectObject(GetHDC(), brush);
  if (oldBrush) {
    TGdiObject::RefInc(brush);
    if (uint(oldBrush) > 1)
      if (!OrgBrush)
        OrgBrush = oldBrush;
      else
        TGdiObject::RefDec(oldBrush, false);
  }
}

//
//
//
void
TDC::SelectObject(const TFont& font)
{
  TRACEX(OwlGDI, 1, "TDC::SelectFont @" << (void*)this <<
    " font @" << (void*)&font);
  HFONT oldFont = (HFONT)::SelectObject(GetHDC(), font);
  if (oldFont) {
    TGdiObject::RefInc(font);
    if (uint(oldFont) > 1)
      if (!OrgFont)
        OrgFont = oldFont;
      else
        TGdiObject::RefDec(oldFont, false);
  }
}

//
//
//
void
TDC::SelectObject(const TPalette& palette, bool forceBackground)
{
  TRACEX(OwlGDI, 1, "TDC::SelectPalette @" << (void*)this <<
    " palette @" << (void*)&palette);
  HPALETTE oldPalette = ::SelectPalette(GetHDC(), palette, forceBackground);
  if (oldPalette) {
    TGdiObject::RefInc(palette);
    if (uint(oldPalette) > 1)
      if (!OrgPalette)
        OrgPalette = oldPalette;
      else
        TGdiObject::RefDec(oldPalette, false);
  }
}

//
//
//
void
TDC::SelectStockObject(int index)
{
  PRECONDITION(::GetStockObject(index));
  TRACEX(OwlGDI, 1, "TDC::SelectStockObject @" << (void*)this <<
    " index " << index);
  HANDLE oldObj = ::SelectObject(GetHDC(), ::GetStockObject(index));
  if (uint(oldObj) > 1)
    TGdiObject::RefDec(oldObj, false);
}

//
//
//
void
TDC::RestorePen()
{
  TRACEX(OwlGDI, 1, "TDC::RestorePen @" << (void*)this);
  if (OrgPen) {
    TGdiObject::RefDec(::SelectObject(GetHDC(), OrgPen), false);
    OrgPen = 0;
  }
}

//
//
//
void
TDC::RestoreBrush()
{
  TRACEX(OwlGDI, 1, "TDC::RestoreBrush @" << (void*)this);
  if (OrgBrush) {
    TGdiObject::RefDec(::SelectObject(GetHDC(), OrgBrush), false);
    OrgBrush = 0;
  }
}

//
//
//
void
TDC::RestoreFont()
{
  TRACEX(OwlGDI, 1, "TDC::RestoreFont @" << (void*)this);
  if (OrgFont) {
    TGdiObject::RefDec(::SelectObject(GetHDC(), OrgFont), false);
    OrgFont = 0;
  }
}

//
//
//
void
TDC::RestorePalette()
{
  TRACEX(OwlGDI, 1, "TDC::RestorePalette @" << (void*)this);
  if (OrgPalette) {
    TGdiObject::RefDec(::SelectPalette(GetHDC(), OrgPalette, false), false);
    OrgPalette = 0;
  }
}

#if defined(BI_PLAT_WIN32)
//
//
//
void
TDC::RestoreTextBrush()
{
  TRACEX(OwlGDI, 1, "TDC::RestoreTextBrush @" << (void*)this);
  if (OrgTextBrush) {
    TGdiObject::RefDec(::SelectObject(GetHDC(), OrgTextBrush), false);
    OrgTextBrush = 0;
  }
}
#endif

//
//
//
void
TDC::RestoreObjects()
{
  if (Handle) {
    RestorePen();
    RestoreBrush();
    RestoreFont();
    RestorePalette();
#if defined(BI_PLAT_WIN32)
    RestoreTextBrush();
#endif
  }
}

//
// Subset of Win32 GetCurrentObject for Win16 (& Win32s!), or just a straight
// call for normal win32
//
HANDLE
TDC::GetCurrentObject(uint objectType) const
{
#if defined(BI_PLAT_WIN32) && !defined(WIN32S_SUPPORT)
    return ::GetCurrentObject(GetHDC(), objectType);
#else

# if defined(BI_PLAT_WIN32)
  static bool notImplemented = false;

  // Try the Win32 GetCurrentObject() function, will fail under Win32s
  //
  if (!notImplemented) {
    HGDIOBJ curObj = ::GetCurrentObject(GetHDC(), objectType);
    if (::GetLastError() != ERROR_CALL_NOT_IMPLEMENTED)
      return curObj;
    notImplemented = true;
  }
# endif

  // Get the currently selected tool object of a given type by shoving a stock
  // object into it slot and catching it when it pops out. Then restore it.
  //
  HGDIOBJ curObj;
  switch (objectType) {
    case OBJ_PEN:
      curObj = ::SelectObject(GetHDC(), ::GetStockObject(BLACK_PEN));
      break;

    case OBJ_BRUSH:
      curObj = ::SelectObject(GetHDC(), ::GetStockObject(BLACK_BRUSH));
      break;

    case OBJ_PAL:
      curObj = ::SelectObject(GetHDC(), ::GetStockObject(DEFAULT_PALETTE));
      break;

    case OBJ_FONT:
      curObj = ::SelectObject(GetHDC(), ::GetStockObject(DEVICE_DEFAULT_FONT));
      break;

    default:
      curObj = 0;           // In non-diagnostic versions, will return 0
      PRECONDITION(curObj); // In diagnostic version will fail a precondition
  }
  if (curObj)
    ::SelectObject(GetHDC(), curObj);  // Restore the object we poped out

  return curObj;
#endif
}

//
// Compile this in to get this function for 16bit
//
#if defined(BI_PLAT_WIN16)

//
// Use undocumented GDI GetClipRgn(HDC) to get the actual handle, and
// make a copy of it. Note that the Win32 GetClipRgn(HDC) does the copying
// itself, while this win16 version requires us to do it.
//
extern "C" HRGN FAR PASCAL GetClipRgn(HDC);  // GDI.173

//
//
//
bool
TDC::GetClipRgn(TRegion& region) const
{
  HRGN hRgn = ::GetClipRgn(GetHDC());
  if (!hRgn)
    return false;
  region = TRegion(hRgn);   // make a copy of the region using assignment
  return true;
}
#endif

extern "C" bool FAR PASCAL FastWindowFrame(HDC, LPRECT, int xWidth, int yWidth, long rop);


//
//
//
void
TDC::OWLFastWindowFrame(TBrush& brush, TRect& r, int xThick, int yThick)
{
  SelectObject(brush);

#if !defined(BI_PLAT_WIN32)
  if (!FastWindowFrame(GetHDC(), &r, xThick, yThick, PATCOPY))
#endif
  {
    int  width = r.Width() - xThick;
    int  height = r.Height() - yThick;

    PatBlt(r.left,        r.top, xThick, height, PATCOPY);  // left
    PatBlt(r.left+xThick, r.top, width, yThick, PATCOPY);   // top
    PatBlt(r.left, r.top+height, width, yThick, PATCOPY);  // bottom
    PatBlt(r.left+width,  r.top+yThick, xThick, height, PATCOPY);  // right
  }
  RestoreBrush();
}

//
//
//
int
TDC::SaveDC() const
{
  return ::SaveDC(GetHDC());
}

//
//
//
bool
TDC::RestoreDC(int savedIndex)
{
  return ::RestoreDC(GetHDC(), savedIndex);
}

//
//
//
int
TDC::GetDeviceCaps(int index) const
{
  return ::GetDeviceCaps(GetAttributeHDC(), index);
}

//
//
//
bool
TDC::ResetDC(DEVMODE far& devMode)
{
  return ::ResetDC(GetHDC(), &devMode) != 0;
}

//
//
//
TColor
TDC::SetBkColor(const TColor& color)
{
  if (GetHDC() != GetAttributeHDC())
    ::SetBkColor(GetHDC(), color);
  return ::SetBkColor(GetAttributeHDC(), color);
}

//
//
//
TColor
TDC::SetTextColor(const TColor& color)
{
  if (GetHDC() != GetAttributeHDC())
    ::SetTextColor(GetHDC(), color);
  return ::SetTextColor(GetAttributeHDC(), color);
}

//
//
//
int
TDC::SetMapMode(int mode)
{
  if (GetHDC() != GetAttributeHDC())
    ::SetMapMode(GetHDC(), mode);
  return ::SetMapMode(GetAttributeHDC(), mode);
}

//
//
//
bool
TDC::SetViewportOrg(const TPoint& point, TPoint far* oldOrg)
{
  if (GetHDC() != GetAttributeHDC())
    ::SetViewportOrgEx(GetHDC(), point.x, point.y, oldOrg);
  return ::SetViewportOrgEx(GetAttributeHDC(), point.x, point.y, oldOrg);
}

//
//
//
bool
TDC::OffsetViewportOrg(const TPoint& delta, TPoint far* oldOrg)
{
  if (GetHDC() != GetAttributeHDC())
    ::OffsetViewportOrgEx(GetHDC(), delta.x, delta.y, oldOrg);
  return ::OffsetViewportOrgEx(GetAttributeHDC(), delta.x, delta.y, oldOrg);
}

//
//
//
bool
TDC::SetViewportExt(const TSize& extent, TSize far* oldExtent)
{
  if (GetHDC() != GetAttributeHDC())
    ::SetViewportExtEx(GetHDC(), extent.cx, extent.cy, oldExtent);
  return ::SetViewportExtEx(GetAttributeHDC(), extent.cx, extent.cy, oldExtent);
}

//
//
//
bool
TDC::ScaleViewportExt(int xNum, int xDenom, int yNum, int yDenom,
                      TSize far* oldExtent)
{
  if (GetHDC() != GetAttributeHDC())
    ::ScaleViewportExtEx(GetHDC(), xNum, xDenom, yNum, yDenom, oldExtent);
  return ::ScaleViewportExtEx(GetAttributeHDC(), xNum, xDenom, yNum, yDenom, oldExtent);
}

//
//
//
bool
TDC::SetWindowOrg(const TPoint& point, TPoint far* oldOrg)
{
  if (GetHDC() != GetAttributeHDC())
    ::SetWindowOrgEx(GetHDC(), point.x, point.y, oldOrg);
  return ::SetWindowOrgEx(GetAttributeHDC(), point.x, point.y, oldOrg);
}

//
//
//
bool
TDC::OffsetWindowOrg(const TPoint& delta, TPoint far* oldOrg)
{
  if (GetHDC() != GetAttributeHDC())
    ::OffsetWindowOrgEx(GetHDC(), delta.x, delta.y, oldOrg);
  return ::OffsetWindowOrgEx(GetAttributeHDC(), delta.x, delta.y, oldOrg);
}

//
//
//
bool
TDC::SetWindowExt(const TSize& extent, TSize far* oldExtent)
{
  if (GetHDC() != GetAttributeHDC())
    ::SetWindowExtEx(GetHDC(), extent.cx, extent.cy, oldExtent);
  return ::SetWindowExtEx(GetAttributeHDC(), extent.cx, extent.cy, oldExtent);
}

//
//
//
bool
TDC::ScaleWindowExt(int xNum, int xDenom, int yNum, int yDenom, TSize far* oldExtent)
{
  if (GetHDC() != GetAttributeHDC())
    ::ScaleWindowExtEx(GetHDC(), xNum, xDenom, yNum, yDenom, oldExtent);
  return ::ScaleWindowExtEx(GetAttributeHDC(), xNum, xDenom, yNum, yDenom, oldExtent);
}

//
//
//
bool
TDC::TextOut(int x, int y, const char far* str, int count)
{
  return ::TextOut(GetHDC(), x, y, str, count>=0 ? count : strlen(str));
}

//
//
//
bool
TDC::ExtTextOut(int x, int y, uint16 options, const TRect* rect,
                const char far* str, int count, const int far* dx)
{
  PRECONDITION(count == 0 || str != 0);
  return ::ExtTextOut(GetHDC(), x, y, options, rect, str,
                      count>=0 ? count : strlen(str), (int far*)dx);
                                                      // API typecast
}

//
//
//
bool
TDC::TabbedTextOut(const TPoint& p, const char far* str, int count,
                   int numPositions, const int far* positions,
                   int tabOrigin, TSize& size) {
  size = (uint32)::TabbedTextOut(GetHDC(), p.x, p.y, str,
                                 count>=0 ? count : strlen(str),
                                 numPositions, (int far*)positions,
                                 tabOrigin);
                                                // API typecast
  return true;
}

//
//
//
int
TDC::DrawText(const char far* str, int count, const TRect& rect, uint16 format)
{
  return ::DrawText(GetHDC(), str, count,  // uses -1 to signify autocount
                    (RECT*)&rect, format);
                    // API typecast
}

//
//
//
bool
TDC::GrayString(const TBrush& brush, GRAYSTRINGPROC outputFunc,
                const char far* str, int count, const TRect& rect)
{
  return ::GrayString(GetHDC(), brush, outputFunc, (uint32)str,
                      count>=0 ? count : 0,  // uses 0 to signify autocount
                      rect.left, rect.top, rect.Width(), rect.Height());
}
