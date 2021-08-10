// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'VcsIntf.pas' rev: 6.00

#ifndef VcsIntfHPP
#define VcsIntfHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ToolIntf.hpp>	// Pascal unit
#include <VirtIntf.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Vcsintf
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIVCSClient;
class PASCALIMPLEMENTATION TIVCSClient : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual AnsiString __stdcall GetIDString(void) = 0 ;
	virtual void __stdcall ExecuteVerb(int Index) = 0 ;
	virtual AnsiString __stdcall GetMenuName(void) = 0 ;
	virtual AnsiString __stdcall GetVerb(int Index) = 0 ;
	virtual int __stdcall GetVerbCount(void) = 0 ;
	virtual Word __stdcall GetVerbState(int Index) = 0 ;
	virtual void __stdcall ProjectChange(void) = 0 ;
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIVCSClient(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIVCSClient(void) { }
	#pragma option pop
	
};


typedef TIVCSClient* __stdcall (*TVCSManagerInitProc)(Toolintf::TIToolServices* VCSInterface);

//-- var, const, procedure ---------------------------------------------------
#define isVersionControl "Version Control"
#define ivVCSManager "VCSManager"
#define VCSManagerEntryPoint "INITVCS0014"
static const Shortint vsEnabled = 0x1;
static const Shortint vsChecked = 0x2;

}	/* namespace Vcsintf */
using namespace Vcsintf;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// VcsIntf
