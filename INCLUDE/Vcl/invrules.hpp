// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'InvRules.pas' rev: 6.00

#ifndef InvRulesHPP
#define InvRulesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IntfInfo.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Invrules
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall IsParamByRef(Typinfo::TParamFlags Flags, Typinfo::PTypeInfo ParamInfo, Intfinfo::TCallConv CC);
extern PACKAGE int __fastcall GetTypeSize(Typinfo::PTypeInfo P);
extern PACKAGE bool __fastcall IsRetInAXDX(Typinfo::PTypeInfo Info);
extern PACKAGE bool __fastcall RetOnStack(Typinfo::PTypeInfo Info);
extern PACKAGE bool __fastcall RetInFPU(Typinfo::PTypeInfo Info);
extern PACKAGE int __fastcall GetStackTypeSize(Typinfo::PTypeInfo P, Intfinfo::TCallConv CC);

}	/* namespace Invrules */
using namespace Invrules;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// InvRules
