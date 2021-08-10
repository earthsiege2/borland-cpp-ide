//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\icon.cpp
//   Implementation of GDI Icon object class
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\gdiobjec.h>

DIAG_DECLARE_GROUP(OwlGDI);        // General GDI diagnostic group

TIcon::TIcon(HICON handle, TAutoDelete autoDelete)
  : TGdiBase(handle, autoDelete)
{
}

#if defined(__WIN32__)
TIcon::TIcon(HINSTANCE, const TIcon& icon)
{
  Handle = ::CopyIcon(icon);
  CheckValid();
}
#else
TIcon::TIcon(HINSTANCE instance, const TIcon& icon)
{
  Handle = ::CopyIcon(instance, icon);
  CheckValid();
}
#endif

TIcon::TIcon(HINSTANCE instance, TResId resId)
{
  Handle = ::LoadIcon(instance, resId);
  ShouldDelete = FALSE;
  CheckValid();
}

TIcon::TIcon(HINSTANCE instance, const char far* fileName, int index)
{
  Handle = ::ExtractIcon(instance, (LPSTR)fileName, index);
  if ((int)Handle == 1)
    Handle = 0;
  CheckValid();
}

TIcon::TIcon(HINSTANCE instance, const TSize& size, int planes, int bitsPixel,
             const void far* andBits, const void far* xorBits)
{
  Handle = ::CreateIcon(instance, size.cx, size.cy,
                        BYTE(planes), BYTE(bitsPixel),
                        (const BYTE far*)andBits, (const BYTE far*)xorBits);
  CheckValid();
}

#if defined(__WIN32__)
TIcon::TIcon(const void* resBits, DWORD resSize)
{
  Handle = CreateIconFromResource((PBYTE)resBits, resSize, TRUE, 0x00030000);
  CheckValid();
}

TIcon::TIcon(const ICONINFO* iconInfo)
{
  //IconInfo->fIcon = TRUE;
  Handle = CreateIconIndirect((PICONINFO)iconInfo);
  CheckValid();
}
#endif

TIcon::~TIcon()
{
  if (ShouldDelete)
    if (!::DestroyIcon((HICON)Handle))
      THROW( TXGdi(IDS_GDIDESTROYFAIL, Handle) );
}
