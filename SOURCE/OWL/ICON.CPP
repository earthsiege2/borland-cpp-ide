//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.7  $
//
// Implementation of class TIcon, a GDI Icon object encapsulation
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
TIcon::TIcon(HICON handle, TAutoDelete autoDelete)
:
  TGdiBase(handle, autoDelete)
{
}

#if defined(BI_PLAT_WIN32)
//
//
//
TIcon::TIcon(HINSTANCE, const TIcon& icon)
{
  Handle = ::CopyIcon(icon);
  CheckValid();
}
#else
//
//
//
TIcon::TIcon(HINSTANCE instance, const TIcon& icon)
{
  Handle = ::CopyIcon(instance, icon);
  CheckValid();
}
#endif

//
//
//
TIcon::TIcon(HINSTANCE instance, TResId resId)
{
  Handle = ::LoadIcon(instance, resId);
  ShouldDelete = (instance != 0);
  CheckValid();
}

//
//
//
TIcon::TIcon(HINSTANCE instance, const char far* fileName, int index)
{
  Handle = ::ExtractIcon(instance, (LPSTR)fileName, index);
  if ((int)Handle == 1)
    Handle = 0;
  CheckValid();
}

//
//
//
TIcon::TIcon(HINSTANCE instance, const TSize& size, int planes, int bitsPixel,
             const void far* andBits, const void far* xorBits)
{
  Handle = ::CreateIcon(instance, size.cx, size.cy,
                        uint8(planes), uint8(bitsPixel),
                        (const uint8 far*)andBits, (const uint8 far*)xorBits);
  CheckValid();
}

#if defined(BI_PLAT_WIN32)
//
//
//
TIcon::TIcon(const void* resBits, uint32 resSize)
{
  Handle = CreateIconFromResource((PBYTE)resBits, resSize, true, 0x00030000);
  CheckValid();
}

//
//
//
TIcon::TIcon(const ICONINFO* iconInfo)
{
  //IconInfo->fIcon = true;  // assume the user setup the struct OK
  Handle = CreateIconIndirect((PICONINFO)iconInfo);
  CheckValid();
}
#endif

//
//
//
TIcon::~TIcon()
{
  if (ShouldDelete && Handle)
    ::DestroyIcon((HICON)Handle);
}
