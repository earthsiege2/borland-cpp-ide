//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Definition of WinG dynamic library wrapper classes, TWinGDll & TWinG
//----------------------------------------------------------------------------
#if !defined(OWL_WING_H)
#define OWL_WING_H

#if !defined(OWL_MODULE_H)
# include <owl/module.h>
#endif
#if !defined (_INC_WING)
# include <wing.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TWinGDll
// ~~~~~ ~~~~~~~~
// Wrapper for the WinG dll itself
//
class _OWLCLASS TWinGDll : public TModule {
  public:
    TWinGDll();

    TModuleProc0<HDC> CreateDC;
    TModuleProc1<BOOL, BITMAPINFO far*> RecommendDIBFormat;
    TModuleProc3<HBITMAP,HDC,BITMAPINFO const far*,void far* far*> CreateBitmap;
    TModuleProc2<void far*,HBITMAP,BITMAPINFO far*> GetDIBPointer;
    TModuleProc4<uint,HDC,uint,uint,RGBQUAD far*> GetDIBColorTable;
    TModuleProc4<uint,HDC,uint,uint,RGBQUAD const far*> SetDIBColorTable;
    TModuleProc0<HPALETTE> CreateHalftonePalette;
    TModuleProc3<HBRUSH,HDC,COLORREF,WING_DITHER_TYPE> CreateHalftoneBrush;
    TModuleProc8<BOOL,HDC,int,int,int,int,HDC,int,int> BitBlt;
    TModuleProc10<BOOL,HDC,int,int,int,int,HDC,int,int,int,int> StretchBlt;
};


//
// class TWinG
// ~~~~~ ~~~~~
// Loader for the WinG dll
//
typedef TDllLoader<TWinGDll> TWinG;

#if defined(BI_COMP_BORLANDC)
# if defined(_OWLDLL) || defined(BI_APP_DLL)
  //
  // Export template of TDllLoader<TWinGDll> when building ObjectWindows DLL 
  // and provide import declaration of DLL instance for users of the class.
  //
  template class _OWLCLASS TDllLoader<TWinGDll>;
# endif 
#endif  

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#endif // OWL_WING_H
