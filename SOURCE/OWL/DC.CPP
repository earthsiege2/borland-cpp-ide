//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of TDC
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/dc.h>

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

TDC::TDC(HDC handle)
:
  TGdiBase(handle, NoAutoDelete)
{
  Init();
}

//
// Following two ctors are for use by derived classes only
//
TDC::TDC()
{
  Init();
}

TDC::TDC(HDC handle, TAutoDelete autoDelete)
:
  TGdiBase(handle, autoDelete)
{
  Init();
}

//
// Default dtor does not delete Handle
//
TDC::~TDC()
{
  RestoreObjects();
}

HDC
TDC::GetAttributeHDC() const
{
  return HDC(Handle);
}

void
TDC::SelectObject(const TPen& pen)
{
  HPEN oldPen = (HPEN)::SelectObject(GetHDC(), pen);
  if (oldPen) {
    OBJ_REF_INC(pen);
    if ((bool)oldPen > 1)
      if (!OrgPen)
        OrgPen = oldPen;
      else
        OBJ_REF_DEC(oldPen, false);
  }
}

void
TDC::SelectObject(const TBrush& brush)
{
  HBRUSH oldBrush = (HBRUSH)::SelectObject(GetHDC(), brush);
  if (oldBrush) {
    OBJ_REF_INC(brush);
    if ((bool)oldBrush > 1)
      if (!OrgBrush)
        OrgBrush = oldBrush;
      else
        OBJ_REF_DEC(oldBrush, false);
  }
}

void
TDC::SelectObject(const TFont& font)
{
  HFONT oldFont = (HFONT)::SelectObject(GetHDC(), font);
  if (oldFont) {
    OBJ_REF_INC(font);
    if ((bool)oldFont > 1)
      if (!OrgFont)
        OrgFont = oldFont;
      else
        OBJ_REF_DEC(oldFont, false);
  }
}

void
TDC::SelectObject(const TPalette& palette, bool forceBackground)
{
  HPALETTE oldPalette = ::SelectPalette(GetHDC(), palette, forceBackground);
  if (oldPalette) {
    OBJ_REF_INC(palette);
    if ((bool)oldPalette > 1)
      if (!OrgPalette)
        OrgPalette = oldPalette;
      else
        OBJ_REF_DEC(oldPalette, false);
  }
}

void
TDC::SelectStockObject(int index)
{
  PRECONDITION(::GetStockObject(index));
  HANDLE oldObj = ::SelectObject(GetHDC(), ::GetStockObject(index));
  if ((bool)oldObj > 1)
      OBJ_REF_DEC(oldObj, false);
}

void
TDC::RestorePen()
{
  if (OrgPen) {
    OBJ_REF_DEC(::SelectObject(GetHDC(), OrgPen), false);
    OrgPen = 0;
  }
}

void
TDC::RestoreBrush()
{
  if (OrgBrush) {
    OBJ_REF_DEC(::SelectObject(GetHDC(), OrgBrush), false);
    OrgBrush = 0;
  }
}

void
TDC::RestoreFont()
{
  if (OrgFont) {
    OBJ_REF_DEC(::SelectObject(GetHDC(), OrgFont), false);
    OrgFont = 0;
  }
}

void
TDC::RestorePalette()
{
  if (OrgPalette) {
    OBJ_REF_DEC(::SelectPalette(GetHDC(), OrgPalette, false), false);
    OrgPalette = 0;
  }
}

#if defined(BI_PLAT_WIN32)
void
TDC::RestoreTextBrush()
{
  if (OrgTextBrush) {
    OBJ_REF_DEC(::SelectObject(GetHDC(), OrgTextBrush), false);
    OrgTextBrush = 0;
  }
}
#endif

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
// implement subset of Win32 GetCurrentObject for Win16 (& Win32s!)
//
HANDLE
TDC::GetCurrentObject(uint objectType) const
{
  HGDIOBJ curObj;

#if defined(BI_PLAT_WIN32)
  static bool notImplemented = false;

  //
  // Try the Win32 GetCurrentObject() function, will fail under Win32s
  //
  if (!notImplemented) {
    curObj = ::GetCurrentObject(GetHDC(), objectType);
    if (GetLastError() != ERROR_CALL_NOT_IMPLEMENTED)
      return curObj;
    notImplemented = true;
  }
#endif

  curObj = 0;
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

    default:     // throw an exception for unsupported objtypes
      CHECK(curObj);
  }

  if (curObj)
    ::SelectObject(GetHDC(), curObj);
  return curObj;
}

//
// Compile this in to get this function for 16bit
//
#if !defined(BI_PLAT_WIN32)

//
// Use undocumented GDI GetClipRgn(HDC) to get the actual handle, and
// make a copy of it. Note that the Win32 GetClipRgn(HDC) does the copying
// itself, while this win16 version requires us to do it.
//
extern "C" HRGN FAR PASCAL ::GetClipRgn(HDC);  // GDI.173

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

void
TDC::OWLFastWindowFrame(TBrush& brush, TRect& r, int xWidth, int yWidth)
{
  SelectObject(brush);

#if !defined(BI_PLAT_WIN32)
  if (!FastWindowFrame(GetHDC(), &r, xWidth, yWidth, PATCOPY))
#endif
  {
    int  width = r.Width() - xWidth;
    int  height = r.Height() - yWidth;

    PatBlt(r.left, r.top, xWidth, height, PATCOPY);  // left
    PatBlt(xWidth, r.top, width, yWidth, PATCOPY);   // top
    PatBlt(r.left, height, width, yWidth, PATCOPY);  // bottom
    PatBlt(width, yWidth, xWidth, height, PATCOPY);  // right
  }
  RestoreBrush();
}

int
TDC::SaveDC() const
{
  return ::SaveDC(GetHDC());
}

bool
TDC::RestoreDC(int savedIndex)
{
  return ::RestoreDC(GetHDC(), savedIndex);
}

int
TDC::GetDeviceCaps(int index) const
{
  return ::GetDeviceCaps(GetAttributeHDC(), index);
}

bool
TDC::ResetDC(DEVMODE far& devMode)
{
  return ::ResetDC(GetHDC(), &devMode) != 0;
}

TColor
TDC::SetBkColor(TColor color)
{
  if (GetHDC() != GetAttributeHDC())
    ::SetBkColor(GetHDC(), color);
  return ::SetBkColor(GetAttributeHDC(), color);
}

TColor
TDC::SetTextColor(TColor color)
{
  if (GetHDC() != GetAttributeHDC())
    ::SetTextColor(GetHDC(), color);
  return ::SetTextColor(GetAttributeHDC(), color);
}

int
TDC::SetMapMode(int mode)
{
  if (GetHDC() != GetAttributeHDC())
    ::SetMapMode(GetHDC(), mode);
  return ::SetMapMode(GetAttributeHDC(), mode);
}

bool
TDC::SetViewportOrg(const TPoint& point, TPoint far* oldOrg)
{
  if (GetHDC() != GetAttributeHDC())
    ::SetViewportOrgEx(GetHDC(), point.x, point.y, oldOrg);
  return ::SetViewportOrgEx(GetAttributeHDC(), point.x, point.y, oldOrg);
}

bool
TDC::OffsetViewportOrg(const TPoint& delta, TPoint far* oldOrg)
{
  if (GetHDC() != GetAttributeHDC())
    ::OffsetViewportOrgEx(GetHDC(), delta.x, delta.y, oldOrg);
  return ::OffsetViewportOrgEx(GetAttributeHDC(), delta.x, delta.y, oldOrg);
}

bool
TDC::SetViewportExt(const TSize& extent, TSize far* oldExtent)
{
  if (GetHDC() != GetAttributeHDC())
    ::SetViewportExtEx(GetHDC(), extent.cx, extent.cy, oldExtent);
  return ::SetViewportExtEx(GetAttributeHDC(), extent.cx, extent.cy, oldExtent);
}

bool
TDC::ScaleViewportExt(int xNum, int xDenom, int yNum, int yDenom,
                      TSize far* oldExtent)
{
  if (GetHDC() != GetAttributeHDC())
    ::ScaleViewportExtEx(GetHDC(), xNum, xDenom, yNum, yDenom, oldExtent);
  return ::ScaleViewportExtEx(GetAttributeHDC(), xNum, xDenom, yNum, yDenom, oldExtent);
}

bool
TDC::SetWindowOrg(const TPoint& point, TPoint far* oldOrg)
{
  if (GetHDC() != GetAttributeHDC())
    ::SetWindowOrgEx(GetHDC(), point.x, point.y, oldOrg);
  return ::SetWindowOrgEx(GetAttributeHDC(), point.x, point.y, oldOrg);
}

bool
TDC::OffsetWindowOrg(const TPoint& delta, TPoint far* oldOrg)
{
  if (GetHDC() != GetAttributeHDC())
    ::OffsetWindowOrgEx(GetHDC(), delta.x, delta.y, oldOrg);
  return ::OffsetWindowOrgEx(GetAttributeHDC(), delta.x, delta.y, oldOrg);
}

bool
TDC::SetWindowExt(const TSize& extent, TSize far* oldExtent)
{
  if (GetHDC() != GetAttributeHDC())
    ::SetWindowExtEx(GetHDC(), extent.cx, extent.cy, oldExtent);
  return ::SetWindowExtEx(GetAttributeHDC(), extent.cx, extent.cy, oldExtent);
}

bool
TDC::ScaleWindowExt(int xNum, int xDenom, int yNum, int yDenom, TSize far* oldExtent)
{
  if (GetHDC() != GetAttributeHDC())
    ::ScaleWindowExtEx(GetHDC(), xNum, xDenom, yNum, yDenom, oldExtent);
  return ::ScaleWindowExtEx(GetAttributeHDC(), xNum, xDenom, yNum, yDenom, oldExtent);
}

bool
TDC::TextOut(int x, int y, const char far* str, int count)
{
  return ::TextOut(GetHDC(), x, y, str, count>=0 ? count : strlen(str));
}

bool
TDC::ExtTextOut(int x, int y, uint16 options, const TRect* rect,
                const char far* str, int count, const int far* dx)
{
  return ::ExtTextOut(GetHDC(), x, y, options, rect, str,
                      count>=0 ? count : strlen(str), (int far*)dx);
                                                      // API typecast
}

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

int
TDC::DrawText(const char far* str, int count, const TRect& rect, uint16 format)
{
  return ::DrawText(GetHDC(), str, count,  // uses -1 to signify autocount
                    (RECT*)&rect, format);
                    // API typecast
}

bool
TDC::GrayString(const TBrush& brush, GRAYSTRINGPROC outputFunc,
                const char far* str, int count, const TRect& rect)
{
  return ::GrayString(GetHDC(), brush, outputFunc, (uint32)str,
                      count>=0 ? count : 0,  // uses 0 to signify autocount
                      rect.left, rect.top, rect.Width(), rect.Height());
}
