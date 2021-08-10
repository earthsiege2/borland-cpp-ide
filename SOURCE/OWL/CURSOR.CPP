//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\cursor.cpp
//   Implementation of GDI Cursor object class
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\gdiobjec.h>

DIAG_DECLARE_GROUP(OwlGDI);        // General GDI diagnostic group

TCursor::TCursor(HCURSOR handle, TAutoDelete autoDelete)
  : TGdiObject(handle, autoDelete)
{
}

#if defined(__WIN32__)
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
  ShouldDelete = FALSE;
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

#if defined(__WIN32__)
TCursor::TCursor(const void* resBits, DWORD resSize)
{
  PRECONDITION(resBits && resSize);
  Handle = ::CreateIconFromResource((PBYTE)resBits, resSize, FALSE, 0x00030000);
  CheckValid();
}

TCursor::TCursor(const ICONINFO* iconInfo)
{
  PRECONDITION(iconInfo);
  //iconInfo->fIcon = FALSE;
  Handle = ::CreateIconIndirect((PICONINFO)iconInfo);
  CheckValid();
}
#endif

TCursor::~TCursor()
{
  if (ShouldDelete)
    if (!::DestroyCursor((HCURSOR)Handle))
      THROW( TXGdi(IDS_GDIDESTROYFAIL, Handle) );
}
