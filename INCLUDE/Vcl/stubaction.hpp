// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'StubAction.pas' rev: 6.00

#ifndef StubActionHPP
#define StubActionHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Stubaction
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TStubActionModule;
class PASCALIMPLEMENTATION TStubActionModule : public Httpapp::TWebModule 
{
	typedef Httpapp::TWebModule inherited;
	
__published:
	void __fastcall WebModule2WebActionItem1Action(System::TObject* Sender, Httpapp::TWebRequest* Request, Httpapp::TWebResponse* Response, bool &Handled);
public:
	#pragma option push -w-inl
	/* TWebModule.Create */ inline __fastcall virtual TStubActionModule(Classes::TComponent* AOwner) : Httpapp::TWebModule(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomWebDispatcher.Destroy */ inline __fastcall virtual ~TStubActionModule(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TDataModule.CreateNew */ inline __fastcall virtual TStubActionModule(Classes::TComponent* AOwner, int Dummy) : Httpapp::TWebModule(AOwner, Dummy) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TStubActionModule* StubActionModule;

}	/* namespace Stubaction */
using namespace Stubaction;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// StubAction
