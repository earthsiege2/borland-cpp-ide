// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'CPL.pas' rev: 5.00

#ifndef CPLHPP
#define CPLHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <cpl.h>

namespace Cpl
{
//-- type declarations -------------------------------------------------------
typedef int __stdcall (*TCPLApplet)(unsigned hwndCPl, unsigned uMsg, int lParam1, int lParam2);

typedef tagCPLINFO *PCPLInfo;

typedef tagCPLINFO  TCPLInfo;

typedef tagNEWCPLINFOA *PNewCPLInfoA;

typedef tagNEWCPLINFOW *PNewCPLInfoW;

typedef tagNEWCPLINFOA *PNewCPLInfo;

typedef tagNEWCPLINFOA  TNewCPLInfoA;

typedef tagNEWCPLINFOW  TNewCPLInfoW;

typedef tagNEWCPLINFOA  TNewCPLInfo;

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Cpl */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Cpl;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CPL
