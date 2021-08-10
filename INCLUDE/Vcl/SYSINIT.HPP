// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SysInit.pas' rev: 5.00

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
extern PACKAGE void *DllProc;
extern PACKAGE int DataMark;
extern PACKAGE void __cdecl VclInit(bool isDLL, bool isPkg, int hInst, bool isGui);
extern PACKAGE void __cdecl VclExit(void);

}	/* namespace Sysinit */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Sysinit;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SysInit
