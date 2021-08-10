//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.11  $
//
// Implementation of TWinGDll, a WinG dll wrapper
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_WING_H)
# include <owl/wing.h>
#endif

OWL_DIAGINFO;

#if defined(BI_PLAT_WIN32)
  static char WinGDllName[] = "WinG32.DLL";
#else
  static char WinGDllName[] = "WinG.DLL";
#endif


HDC      
TWinGDll::CreateDC()
{
  static TModuleProc0<HDC> createDC(WinGModule(), "WinGCreateDC");
  return createDC();
}

BOOL     
TWinGDll::RecommendDIBFormat(BITMAPINFO* p1)
{
  static TModuleProc1<BOOL, BITMAPINFO*> 
  recommendDIBFormat(WinGModule(), "WinGRecommendDIBFormat");
  return recommendDIBFormat(p1);
}

HBITMAP  
TWinGDll::CreateBitmap(HDC p1, BITMAPINFO const* p2, void** p3)
{
  static TModuleProc3<HBITMAP,HDC,BITMAPINFO const*,void**>
  createBitmap(WinGModule(), "WinGCreateBitmap");
  return createBitmap(p1, p2, p3);
}

void*    
TWinGDll::GetDIBPointer(HBITMAP p1, BITMAPINFO* p2)
{
  static TModuleProc2<void*,HBITMAP,BITMAPINFO*> 
  getDIBPointer(WinGModule(), "WinGGetDIBPointer");
  return getDIBPointer(p1, p2);
}

uint     
TWinGDll::GetDIBColorTable(HDC p1, uint p2, uint p3, RGBQUAD* p4)
{
  static TModuleProc4<uint,HDC,uint,uint,RGBQUAD*> 
  getDIBColorTable(WinGModule(), "WinGGetDIBColorTable");
  return getDIBColorTable(p1, p2, p3, p4);
}

uint     
TWinGDll::SetDIBColorTable(HDC p1, uint p2, uint p3, RGBQUAD const* p4)
{
  static TModuleProc4<uint,HDC,uint,uint,RGBQUAD const far*> 
  setDIBColorTable(WinGModule(), "WinGSetDIBColorTable");
  return setDIBColorTable(p1, p2, p3, p4);
}

HPALETTE 
TWinGDll::CreateHalftonePalette()
{
  static TModuleProc0<HPALETTE> 
  createHalftonePalette(WinGModule(), "WinGCreateHalftonePalette");
  return createHalftonePalette();
}

HBRUSH   
TWinGDll::CreateHalfToneBrush(HDC p1, COLORREF p2, WING_DITHER_TYPE p3)
{
  static TModuleProc3<HBRUSH,HDC,COLORREF,WING_DITHER_TYPE> 
  createHalftoneBrush(WinGModule(), "WinGCreateHalftoneBrush");
  return createHalftoneBrush(p1, p2, p3);
}

BOOL     
TWinGDll::BitBlt(HDC p1, int p2, int p3, int p4, int p5, HDC p6, int p7, int p8)
{
  static TModuleProc8<BOOL,HDC,int,int,int,int,HDC,int,int> 
  bitBlt(WinGModule(), "WinGBitBlt");
  return bitBlt(p1, p2, p3, p4, p5, p6, p7, p8);
}

BOOL     
TWinGDll::StretchBlt(HDC p1, int p2, int p3, int p4, int p5, HDC p6, int p7, int p8, int p9, int p10)
{
  static TModuleProc10<BOOL,HDC,int,int,int,int,HDC,int,int,int,int> 
  stretchBlt(WinGModule(), "WinGStretchBlt");
  return stretchBlt(p1, p2 , p3, p4, p5, p6, p7, p8, p9, p10);
}

TModule& 
TWinGDll::WinGModule()
{
  static TModule wingModule(WinGDllName, true, true);
  return wingModule;
}

bool     
TWinGDll::IsAvailable()
{
  return WinGModule().IsLoaded();
}

bool       
TWinG::IsAvailable()
{
  return TWinGDll::IsAvailable();
}

TWinGDll*  
TWinG::Dll()
{
  static TWinGDll wingDLL;
  return &wingDLL;
}

