// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GraphUtil.pas' rev: 6.00

#ifndef GraphUtilHPP
#define GraphUtilHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Graphics.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Graphutil
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TScrollDirection { sdLeft, sdRight, sdUp, sdDown };
#pragma option pop

#pragma option push -b-
enum TArrowType { atSolid, atArrows };
#pragma option pop

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ColorRGBToHLS(unsigned clrRGB, Word &Hue, Word &Luminance, Word &Saturation);
extern PACKAGE unsigned __fastcall ColorHLSToRGB(Word Hue, Word Luminance, Word Saturation);
extern PACKAGE unsigned __fastcall ColorAdjustLuma(unsigned clrRGB, int n, BOOL fScale);
extern PACKAGE Graphics::TColor __fastcall GetHighLightColor(const Graphics::TColor Color);
extern PACKAGE Graphics::TColor __fastcall GetShadowColor(const Graphics::TColor Color);
extern PACKAGE void __fastcall DrawArrow(Graphics::TCanvas* ACanvas, TScrollDirection Direction, const Types::TPoint &Location, int Size);
extern PACKAGE void __fastcall DrawChevron(Graphics::TCanvas* ACanvas, TScrollDirection Direction, const Types::TPoint &Location, int Size);
extern PACKAGE void __fastcall DrawCheck(Graphics::TCanvas* ACanvas, const Types::TPoint &Location, int Size, bool Shadow = true);

}	/* namespace Graphutil */
using namespace Graphutil;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GraphUtil
