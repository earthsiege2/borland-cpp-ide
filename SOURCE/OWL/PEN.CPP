//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Implementation of TPen, an encapsulation of the GDI Pen object
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlGDI);        // General GDI diagnostic group
DIAG_DECLARE_GROUP(OwlGDIOrphan);  // Orphan control tracing group

//
// Constructors
//

//
// Alias an existing pen handle. Assume ownership if autoDelete says so
//
TPen::TPen(HPEN handle, TAutoDelete autoDelete)
:
  TGdiObject(handle, autoDelete)
{
    if (ShouldDelete)
      RefAdd(Handle, Pen);
}

//
// Basic pen constructor.
// Detect constructions of stock pens & get stock objects instead
//
TPen::TPen(const TColor& color, int width, int style)
{
  if (width == 1 && style == PS_SOLID &&
     (color == TColor::Black || color == TColor::White)) {
    if (color == TColor::Black)
      Handle = ::GetStockObject(BLACK_PEN);
    else
      Handle = ::GetStockObject(WHITE_PEN);
    ShouldDelete = false;
    return;
  }
  Handle = ::CreatePen(style, width, color);
  WARNX(OwlGDI, !Handle, 0, "Cannot create TPen (" << color << " " << width <<
        " " << style << ")");
  CheckValid();
  RefAdd(Handle, Pen);
}

//
// Construct a TPen given a logical pen object
//
TPen::TPen(const LOGPEN far* logPen)
{
  PRECONDITION(logPen);
  Handle = ::CreatePenIndirect((LPLOGPEN)logPen);
  WARNX(OwlGDI, !Handle, 0, "Cannot create TPen from logPen @" <<
        hex << uint32(LPVOID(logPen)));
  CheckValid();
  RefAdd(Handle, Pen);
}

//
// Construct a copy of an existing pen. Contructed pen will share the handle
// unless NO_GDI_SHARE_HANDLES is defined, in which case a new handle is
// created
//
TPen::TPen(const TPen& src)
{
#if !defined(NO_GDI_SHARE_HANDLES)
  Handle = src.Handle;
  RefAdd(Handle, Pen);
#else
  LOGPEN logPen;

  src.GetObject(logPen);
  Handle = ::CreatePenIndirect(&logPen);
  WARNX(OwlGDI, !Handle, 0, "Cannot create TPen from TPen @" <<
        hex << uint32(LPVOID(&src)));
  CheckValid();
  RefAdd(Handle, Pen);
#endif
}

#if defined(BI_PLAT_WIN32)
//
// Construct a Win32 type pen
//
TPen::TPen(uint32 penStyle, uint32 width, const TBrush& brush,
           uint32 styleCount, uint32* style)
{
  LOGBRUSH logBrush;
  brush.GetObject(logBrush);
  Handle = ::ExtCreatePen(penStyle, width, &logBrush, styleCount, style);
  WARNX(OwlGDI, !Handle, 0, "Cannot create TPen from brush " << hex <<
        uint(HBRUSH(brush)));
  CheckValid();
  RefAdd(Handle, Pen);
}

//
// Construct a Win32 type pen
//
TPen::TPen(uint32 penStyle, uint32 width, const LOGBRUSH& logBrush,
           uint32 styleCount, uint32* style)
{
  Handle = ::ExtCreatePen(penStyle, width, (LPLOGBRUSH)&logBrush, styleCount,
                          style);
  WARNX(OwlGDI, !Handle, 0, "Cannot create TPen from logBrush @" <<
        hex << uint32(LPVOID(&logBrush)));
  CheckValid();
  RefAdd(Handle, Pen);
}
#endif
