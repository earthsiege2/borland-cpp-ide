//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
// $Revision:   10.7  $
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

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TWinGDll
// ~~~~~ ~~~~~~~~
// Wrapper for the WinG dll itself
//
class _OWLCLASS TWinGDll {
  public:
    static HDC      CreateDC();
    static BOOL     RecommendDIBFormat(BITMAPINFO*);
    static HBITMAP  CreateBitmap(HDC, BITMAPINFO const*, void**);
    static void*    GetDIBPointer(HBITMAP, BITMAPINFO*);
    static uint     GetDIBColorTable(HDC, uint, uint, RGBQUAD*);
    static uint     SetDIBColorTable(HDC, uint, uint, RGBQUAD const*);
    static HPALETTE CreateHalftonePalette();
    static HBRUSH   CreateHalfToneBrush(HDC, COLORREF, WING_DITHER_TYPE);
    static BOOL     BitBlt(HDC, int, int, int, int, HDC, int, int);
    static BOOL     StretchBlt(HDC, int, int, int, int, HDC, int, int, int, int);

    static TModule& WinGModule();
    static bool     IsAvailable();
};

//
//
//
class _OWLCLASS TWinG {
  public:
    static bool       IsAvailable();
    static TWinGDll*  Dll();
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

#endif // OWL_WING_H
