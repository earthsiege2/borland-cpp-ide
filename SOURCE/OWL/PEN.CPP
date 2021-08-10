//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation for GDI Pen object
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/gdiobjec.h>

DIAG_DECLARE_GROUP(OwlGDI);        // General GDI diagnostic group
DIAG_DECLARE_GROUP(OwlGDIOrphan);  // Orphan control tracing group

//
// Constructors
//
TPen::TPen(HPEN handle, TAutoDelete autoDelete)
:
  TGdiObject(handle, autoDelete)
{
  #if !defined(NO_GDI_ORPHAN_CONTROL)
    if (ShouldDelete)
      OBJ_REF_ADD(Handle, Pen);
  #endif
}

//
// detect constructions of stock pens & get stock objects instead
//
TPen::TPen(TColor color, int width, int style)
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
  OBJ_REF_ADD(Handle, Pen);
}

TPen::TPen(const LOGPEN far* logPen)
{
  PRECONDITION(logPen);
  Handle = ::CreatePenIndirect((LPLOGPEN)logPen);
  WARNX(OwlGDI, !Handle, 0, "Cannot create TPen from logPen @" <<
        hex << uint32(LPVOID(logPen)));
  CheckValid();
  OBJ_REF_ADD(Handle, Pen);
}

TPen::TPen(const TPen& src)
{
  LOGPEN logPen;

  src.GetObject(logPen);
  Handle = ::CreatePenIndirect(&logPen);
  WARNX(OwlGDI, !Handle, 0, "Cannot create TPen from TPen @" <<
        hex << uint32(LPVOID(&src)));
  CheckValid();
  OBJ_REF_ADD(Handle, Pen);
}

#if defined(BI_PLAT_WIN32)
TPen::TPen(uint32 penStyle, uint32 width, const TBrush& brush,
           uint32 styleCount, uint32* style)
{
  LOGBRUSH logBrush;
  brush.GetObject(logBrush);
  Handle = ::ExtCreatePen(penStyle, width, &logBrush, styleCount, style);
  WARNX(OwlGDI, !Handle, 0, "Cannot create TPen from brush " << hex << 
        uint(HBRUSH(brush)));
  CheckValid();
  OBJ_REF_ADD(Handle, Pen);
}

TPen::TPen(uint32 penStyle, uint32 width, const LOGBRUSH& logBrush,
           uint32 styleCount, uint32* style)
{
  Handle = ::ExtCreatePen(penStyle, width, (LPLOGBRUSH)&logBrush, styleCount,
                          style);
  WARNX(OwlGDI, !Handle, 0, "Cannot create TPen from logBrush @" <<
        hex << uint32(LPVOID(&logBrush)));
  CheckValid();
  OBJ_REF_ADD(Handle, Pen);
}
#endif
