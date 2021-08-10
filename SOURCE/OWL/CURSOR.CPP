//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.7  $
//
// Implementation of TCursor, a GDI Cursor object class
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlGDI);        // General GDI diagnostic group

//
//
//
TCursor::TCursor(HCURSOR handle, TAutoDelete autoDelete)
:
  TGdiBase(handle, autoDelete)
{
  TRACEX(OwlGDI, OWL_CDLEVEL, "TCursor constructed @" << (void*)this <<
    " from handle " << uint(handle));
}

#if defined(BI_PLAT_WIN32)
//
//
//
TCursor::TCursor(HINSTANCE, const TCursor& cursor)
{
  Handle = (HCURSOR)::CopyIcon((HICON)(HCURSOR)cursor);
  CheckValid();
  TRACEX(OwlGDI, OWL_CDLEVEL, "TCursor @" << (void*)this <<
    " copied from TCursor " << (void*)&cursor);
}
#else
//
//
//
TCursor::TCursor(HINSTANCE instance, const TCursor& cursor)
{
  Handle = ::CopyCursor(instance, cursor);
  CheckValid();
  TRACEX(OwlGDI, OWL_CDLEVEL, "TCursor @" << (void*)this <<
    " copied from TCursor " << (void*)&cursor);
}
#endif

//
//
//
TCursor::TCursor(HINSTANCE instance, TResId resId)
{
  PRECONDITION(resId);
  Handle = ::LoadCursor(instance, resId);
  ShouldDelete = (instance != 0);
  CheckValid();
  TRACEX(OwlGDI, OWL_CDLEVEL, "TCursor @" << (void*)this <<
    " loaded from resource " << resId);
}

//
//
//
TCursor::TCursor(HINSTANCE instance, const TPoint& hotSpot, const TSize& size,
                 void far* andBits, void far* xorBits)
{
  PRECONDITION(andBits && xorBits);
  Handle = ::CreateCursor(instance, hotSpot.x, hotSpot.y, size.cx, size.cy,
                          andBits, xorBits);
  CheckValid();
  TRACEX(OwlGDI, OWL_CDLEVEL, "TCursor @" << (void*)this << " created from bits ");
}

#if defined(BI_PLAT_WIN32)
//
//
//
TCursor::TCursor(const void* resBits, uint32 resSize)
{
  PRECONDITION(resBits && resSize);
  Handle = ::CreateIconFromResource((PBYTE)resBits, resSize, false, 0x00030000);
  CheckValid();
  TRACEX(OwlGDI, OWL_CDLEVEL, "TCursor @" << (void*)this <<
    " created from bits (32)");
}

//
//
//
TCursor::TCursor(const ICONINFO* iconInfo)
{
  PRECONDITION(iconInfo);
  //iconInfo->fIcon = false;
  Handle = ::CreateIconIndirect((PICONINFO)iconInfo);
  CheckValid();
  TRACEX(OwlGDI, OWL_CDLEVEL, "TCursor constructed indirectly @" << (void*)this);
}

#endif

//
//
//
TCursor::~TCursor()
{
  if (ShouldDelete && Handle)
    ::DestroyCursor((HCURSOR)Handle);
  TRACEX(OwlGDI, OWL_CDLEVEL, "TCursor destructed @" << (void*)this);
}
