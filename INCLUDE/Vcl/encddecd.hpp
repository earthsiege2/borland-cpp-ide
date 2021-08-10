// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'EncdDecd.pas' rev: 6.00

#ifndef EncdDecdHPP
#define EncdDecdHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Encddecd
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall EncodeStream(Classes::TStream* Input, Classes::TStream* Output);
extern PACKAGE void __fastcall DecodeStream(Classes::TStream* Input, Classes::TStream* Output);
extern PACKAGE AnsiString __fastcall EncodeString(const AnsiString Input);
extern PACKAGE AnsiString __fastcall DecodeString(const AnsiString Input);

}	/* namespace Encddecd */
using namespace Encddecd;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// EncdDecd
