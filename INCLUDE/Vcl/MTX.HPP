// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Mtx.pas' rev: 6.00

#ifndef MtxHPP
#define MtxHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <comsvcs.h>
DECLARE_DINTERFACE_TYPE(ITransactionContext);
DECLARE_DINTERFACE_TYPE(ITransactionContextEx);
DECLARE_DINTERFACE_TYPE(ISharedPropertyGroupManager);
DECLARE_DINTERFACE_TYPE(ISharedPropertyGroup);

namespace Mtx
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE _di_ITransactionContext __fastcall CreateTransactionContext();
extern PACKAGE _di_ITransactionContextEx __fastcall CreateTransactionContextEx();
extern PACKAGE _di_ISharedPropertyGroupManager __fastcall CreateSharedPropertyGroupManager();
extern PACKAGE _di_ISharedPropertyGroup __fastcall CreateSharedPropertyGroup(const WideString Name);

}	/* namespace Mtx */
using namespace Mtx;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Mtx
