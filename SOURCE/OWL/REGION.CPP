//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of GDI Region object class
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/gdiobjec.h>

DIAG_DECLARE_GROUP(OwlGDI);        // General GDI diagnostic group

TRegion::TRegion()
{
  Handle = ::CreateRectRgn(0, 0, 0, 0);
  WARNX(OwlGDI, !Handle, 0, "Cannot create empty rect region");
  CheckValid();
}

TRegion::TRegion(HRGN handle, TAutoDelete autoDelete)
:
  TGdiBase(handle, autoDelete)
{
}

TRegion::TRegion(const TRegion& source)
{
  Handle = ::CreateRectRgn(0, 0, 0, 0);
  WARNX(OwlGDI, !Handle, 0, "Cannot create copy of region " << 
        uint(HRGN(source)));
  CheckValid();
  ::CombineRgn((HRGN)Handle, source, 0, RGN_COPY);
}

TRegion::TRegion(const TRect& rect)
{
  Handle = ::CreateRectRgnIndirect(&rect);
  WARNX(OwlGDI, !Handle, 0, "Cannot create rect region " << rect);
  CheckValid();
}

TRegion::TRegion(const TRect& rect, TRegion::TEllipse)
{
  Handle = ::CreateEllipticRgnIndirect(&rect);
  WARNX(OwlGDI, !Handle, 0, "Cannot create elliptic region " << rect);
  CheckValid();
}

TRegion::TRegion(const TRect& rect, const TSize& corner)
{
  Handle = ::CreateRoundRectRgn(rect.left, rect.top, rect.right, rect.bottom,
                                corner.cx, corner.cy);
  WARNX(OwlGDI, !Handle, 0, "Cannot create roundrect region " << rect << corner);
  CheckValid();
}

TRegion::TRegion(const TPoint* points, int count, int fillMode)
{
  Handle = ::CreatePolygonRgn(points, count, fillMode);
  WARNX(OwlGDI, !Handle, 0, "Cannot create poly region " << count << 
        "pts @" << hex << uint32(LPVOID(points)));
  CheckValid();
}

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
      THROW( TGdiObject::TXGdi(IDS_GDIDELETEFAIL, Handle) );
}

TRegion&
TRegion::operator &=(const TRect& source)
{
  ::CombineRgn((HRGN)Handle, (HRGN)Handle, TRegion(source), RGN_AND);
  return *this;
}

TRegion&
TRegion::operator |=(const TRect& source)
{
  ::CombineRgn((HRGN)Handle, (HRGN)Handle, TRegion(source), RGN_OR);
  return *this;
}

TRegion&
TRegion::operator ^=(const TRect& source)
{
  ::CombineRgn((HRGN)Handle, (HRGN)Handle, TRegion(source), RGN_XOR);
  return *this;
}
