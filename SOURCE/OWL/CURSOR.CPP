//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of GDI Cursor object class
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/gdiobjec.h>

DIAG_DECLARE_GROUP(OwlGDI);        // General GDI diagnostic group

TCursor::TCursor(HCURSOR handle, TAutoDelete autoDelete)
:
  TGdiBase(handle, autoDelete)
{
}

#if defined(BI_PLAT_WIN32)
TCursor::TCursor(HINSTANCE, const TCursor& cursor)
{
  Handle = (HCURSOR)::CopyIcon((HICON)(HCURSOR)cursor);
  CheckValid();
}
#else
TCursor::TCursor(HINSTANCE instance, const TCursor& cursor)
{
  Handle = ::CopyCursor(instance, cursor);
  CheckValid();
}
#endif

TCursor::TCursor(HINSTANCE instance, TResId resId)
{
  PRECONDITION(resId);
  Handle = ::LoadCursor(instance, resId);
  ShouldDelete = (instance != 0);
  CheckValid();
}

TCursor::TCursor(HINSTANCE instance, const TPoint& hotSpot, const TSize& size,
                 void far* andBits, void far* xorBits)
{
  PRECONDITION(andBits && xorBits);
  Handle = ::CreateCursor(instance, hotSpot.x, hotSpot.y, size.cx, size.cy,
                          andBits, xorBits);
  CheckValid();
}

#if defined(BI_PLAT_WIN32)
TCursor::TCursor(const void* resBits, uint32 resSize)
{
  PRECONDITION(resBits && resSize);
  Handle = ::CreateIconFromResource((PBYTE)resBits, resSize, false, 0x00030000);
  CheckValid();
}

TCursor::TCursor(const ICONINFO* iconInfo)
{
  PRECONDITION(iconInfo);
  //iconInfo->fIcon = false;
  Handle = ::CreateIconIndirect((PICONINFO)iconInfo);
  CheckValid();
}
#endif

TCursor::~TCursor()
{
  if (ShouldDelete)
    ::DestroyCursor((HCURSOR)Handle);
}
