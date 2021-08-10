//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.8  $
//
// Implementation of TWinGDll, a WinG dll wrapper
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_WING_H)
# include <owl/wing.h>
#endif

#if defined(BI_PLAT_WIN32)
  static char WinGDllName[] = "WinG32.DLL";
#else
  static char WinGDllName[] = "WinG.DLL";
#endif

//
//
//
TWinGDll::TWinGDll()
:
  TModule(WinGDllName, true, true),

  CreateDC(*this, "WinGCreateDC"),
  RecommendDIBFormat(*this, "WinGRecommendDIBFormat"),
  CreateBitmap(*this, "WinGCreateBitmap"),
  GetDIBPointer(*this, "WinGGetDIBPointer"),
  GetDIBColorTable(*this, "WinGGetDIBColorTable"),
  SetDIBColorTable(*this, "WinGSetDIBColorTable"),
  CreateHalftonePalette(*this, "WinGCreateHalftonePalette"),
  CreateHalftoneBrush(*this, "WinGCreateHalftoneBrush"),
  BitBlt(*this, "WinGBitBlt"),
  StretchBlt(*this, "WinGStretchBlt")
{
}

#if defined(__BORLANDC__) && (__BORLANDC__ >= 0x500)
//
// Cool new C++ technique to instantiate the template
//
template class /*_OWLCLASS*/ TDllLoader<TWinGDll>;
#endif
