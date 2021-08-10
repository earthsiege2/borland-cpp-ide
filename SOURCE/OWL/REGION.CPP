//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.6  $
//
// Implementation of class TRegion, a GDI Region object encapsulation
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlGDI);        // General GDI diagnostic group

//
// Constructor to create an empty region.
//
TRegion::TRegion()
{
  Handle = ::CreateRectRgn(0, 0, 0, 0);
  WARNX(OwlGDI, !Handle, 0, "Cannot create empty rect region");
  CheckValid();
}

//
// Alias constructor for an existing region.
//
TRegion::TRegion(HRGN handle, TAutoDelete autoDelete)
:
  TGdiBase(handle, autoDelete)
{
}

//
// Copy an existing region.
//
TRegion::TRegion(const TRegion& source)
{
  Handle = ::CreateRectRgn(0, 0, 0, 0);
  WARNX(OwlGDI, !Handle, 0, "Cannot create copy of region " <<
        uint(HRGN(source)));
  CheckValid();
  ::CombineRgn((HRGN)Handle, source, 0, RGN_COPY);
}

//
// Create a rectangular region.
//
TRegion::TRegion(const TRect& rect)
{
  Handle = ::CreateRectRgnIndirect(&rect);
  WARNX(OwlGDI, !Handle, 0, "Cannot create rect region " << rect);
  CheckValid();
}

//
// Create an elliptic region.
//
TRegion::TRegion(const TRect& rect, TRegion::TEllipse)
{
  Handle = ::CreateEllipticRgnIndirect(&rect);
  WARNX(OwlGDI, !Handle, 0, "Cannot create elliptic region " << rect);
  CheckValid();
}

//
// Create a rounded rectangular region.
//
TRegion::TRegion(const TRect& rect, const TSize& corner)
{
  Handle = ::CreateRoundRectRgn(rect.left, rect.top, rect.right, rect.bottom,
                                corner.cx, corner.cy);
  WARNX(OwlGDI, !Handle, 0, "Cannot create roundrect region " << rect << corner);
  CheckValid();
}

//
// Create a region out of a polygon.
//
TRegion::TRegion(const TPoint* points, int count, int fillMode)
{
  Handle = ::CreatePolygonRgn(points, count, fillMode);
  WARNX(OwlGDI, !Handle, 0, "Cannot create poly region " << count <<
        "pts @" << hex << uint32(LPVOID(points)));
  CheckValid();
}

//
// Create a poly-polygon region.
//
TRegion::TRegion(const TPoint* points, const int* polyCounts, int count,
                 int fillMode)
{
  Handle = ::CreatePolyPolygonRgn(points, polyCounts, count, fillMode);
  WARNX(OwlGDI, !Handle, 0, "Cannot create polypoly region " << count <<
        "polies @" << hex << uint32(LPVOID(points)));
  CheckValid();
}

//
// No orphan control for regions since they are not selectable into DCs,
// just delete
//
TRegion::~TRegion()
{
  if (ShouldDelete)
    if (!::DeleteObject(Handle))
      TXGdi::Raise(IDS_GDIDELETEFAIL, Handle);
}

//
// Modify and return the intersection of two regions.
//
TRegion&
TRegion::operator &=(const TRect& source)
{
  ::CombineRgn((HRGN)Handle, (HRGN)Handle, TRegion(source), RGN_AND);
  return *this;
}

//
// Modify and return the union of two regions.
//
TRegion&
TRegion::operator |=(const TRect& source)
{
  ::CombineRgn((HRGN)Handle, (HRGN)Handle, TRegion(source), RGN_OR);
  return *this;
}

//
// Modify and return the exclusive or of two regions.
//
TRegion&
TRegion::operator ^=(const TRect& source)
{
  ::CombineRgn((HRGN)Handle, (HRGN)Handle, TRegion(source), RGN_XOR);
  return *this;
}
