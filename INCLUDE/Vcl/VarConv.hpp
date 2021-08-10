// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'VarConv.pas' rev: 6.00

#ifndef VarConvHPP
#define VarConvHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ConvUtils.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Varconv
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Variant __fastcall VarConvertCreate(const double AValue, const Convutils::TConvType AType)/* overload */;
extern PACKAGE Variant __fastcall VarConvertCreate(const AnsiString AValue)/* overload */;
extern PACKAGE Word __fastcall VarConvert(void);
extern PACKAGE bool __fastcall VarIsConvert(const Variant &AValue);
extern PACKAGE Variant __fastcall VarAsConvert(const Variant &AValue)/* overload */;
extern PACKAGE Variant __fastcall VarAsConvert(const Variant &AValue, const Convutils::TConvType AType)/* overload */;

}	/* namespace Varconv */
using namespace Varconv;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// VarConv
