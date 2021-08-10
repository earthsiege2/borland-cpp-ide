// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Cpl.pas' rev: 6.00

#ifndef CplHPP
#define CplHPP

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
using namespace Cpl;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Cpl
