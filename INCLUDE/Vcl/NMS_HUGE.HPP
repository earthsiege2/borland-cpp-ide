// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NMS_Huge.pas' rev: 6.00

#ifndef NMS_HugeHPP
#define NMS_HugeHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Nms_huge
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall HugeInc(void * &HugePtr, int Amount);
extern PACKAGE void __fastcall HugeDec(void * &HugePtr, int Amount);
extern PACKAGE void * __fastcall HugeOffset(void * HugePtr, int Amount);
extern PACKAGE void __fastcall HMemCpy(void * DstPtr, void * SrcPtr, int Amount);

}	/* namespace Nms_huge */
using namespace Nms_huge;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NMS_Huge
