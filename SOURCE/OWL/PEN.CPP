//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\pen.cpp
//   Implementation for GDI Pen object
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\gdiobjec.h>

DIAG_DECLARE_GROUP(OwlGDI);        // General GDI diagnostic group
DIAG_DECLARE_GROUP(OwlGDIOrphan);  // Orphan control tracing group

//
// Constructors
//
TPen::TPen(HPEN handle, TAutoDelete autoDelete)
  : TGdiObject(handle, autoDelete)
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
    ShouldDelete = FALSE;
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
        hex << DWORD(LPVOID(logPen)));
  CheckValid();
  OBJ_REF_ADD(Handle, Pen);
}

TPen::TPen(const TPen& src)
{
  LOGPEN logPen;

  src.GetObject(logPen);
  Handle = ::CreatePenIndirect(&logPen);
  WARNX(OwlGDI, !Handle, 0, "Cannot create TPen from TPen @" <<
        hex << DWORD(LPVOID(&src)));
  CheckValid();
  OBJ_REF_ADD(Handle, Pen);
}

#if defined(__WIN32__)
TPen::TPen(DWORD penStyle, DWORD width, const TBrush& brush,
           DWORD styleCount, LPDWORD style)
{
  LOGBRUSH logBrush;
  brush.GetObject(logBrush);
  Handle = ::ExtCreatePen(penStyle, width, &logBrush, styleCount, style);
  WARNX(OwlGDI, !Handle, 0, "Cannot create TPen from brush " << hex << 
        UINT(HBRUSH(brush)));
  CheckValid();
  OBJ_REF_ADD(Handle, Pen);
}

TPen::TPen(DWORD penStyle, DWORD width, const LOGBRUSH& logBrush,
           DWORD styleCount, LPDWORD style)
{
  Handle = ::ExtCreatePen(penStyle, width, (LPLOGBRUSH)&logBrush, styleCount,
                          style);
  WARNX(OwlGDI, !Handle, 0, "Cannot create TPen from logBrush @" <<
        hex << DWORD(LPVOID(&logBrush)));
  CheckValid();
  OBJ_REF_ADD(Handle, Pen);
}
#endif
