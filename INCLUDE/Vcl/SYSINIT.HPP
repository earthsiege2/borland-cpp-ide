// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SysInit.pas' rev: 6.00

#ifndef SysInitHPP
#define SysInitHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
namespace Sysinit
{
extern PACKAGE HINSTANCE HInstance;
} /* namespace Sysinit */

namespace Sysinit
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool ModuleIsLib;
extern PACKAGE bool ModuleIsPackage;
extern PACKAGE bool ModuleIsCpp;
extern PACKAGE int TlsIndex;
extern PACKAGE Byte TlsLast;
extern PACKAGE System::TDLLProc DllProc;
#pragma error Unsupported symbol type (4, DllProcEx)
extern PACKAGE int DataMark;
extern PACKAGE void __cdecl VclInit(bool isDLL, bool isPkg, int hInst, bool isGui);
extern PACKAGE void __cdecl VclExit(void);

}	/* namespace Sysinit */
using namespace Sysinit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SysInit
