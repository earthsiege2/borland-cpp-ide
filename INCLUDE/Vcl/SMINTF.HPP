// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SMIntf.pas' rev: 5.00

#ifndef SMIntfHPP
#define SMIntfHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Smintf
{
//-- type declarations -------------------------------------------------------
__interface ISMClient;
typedef System::DelphiInterface<ISMClient> _di_ISMClient;
__interface INTERFACE_UUID("{CB9879E1-4395-11D0-9FFC-00A0248E4B9A}") ISMClient  : public IUnknown 
{
	
public:
	virtual Word __stdcall RegisterClient(int ID, char * Name, void * Instance, void * SignalProc) = 0 
		;
	virtual Word __stdcall AddStatement(char * Statement, int Len) = 0 ;
};

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE GUID Class_SMClient;

}	/* namespace Smintf */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Smintf;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SMIntf
