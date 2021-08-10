// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SvrInfoModule.pas' rev: 6.00

#ifndef SvrInfoModuleHPP
#define SvrInfoModuleHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <HTTPProd.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Svrinfomodule
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TWebModule2;
class PASCALIMPLEMENTATION TWebModule2 : public Httpapp::TWebModule 
{
	typedef Httpapp::TWebModule inherited;
	
__published:
	Httpprod::TPageProducer* PageProducerSelect;
	Httpprod::TPageProducer* PageProducerDetails;
	void __fastcall CleanAction(System::TObject* Sender, Httpapp::TWebRequest* Request, Httpapp::TWebResponse* Response, bool &Handled);
	void __fastcall ServerListPageHTMLTag(System::TObject* Sender, Httpprod::TTag Tag, const AnsiString TagString, Classes::TStrings* TagParams, AnsiString &ReplaceText);
public:
	#pragma option push -w-inl
	/* TWebModule.Create */ inline __fastcall virtual TWebModule2(Classes::TComponent* AOwner) : Httpapp::TWebModule(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomWebDispatcher.Destroy */ inline __fastcall virtual ~TWebModule2(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TDataModule.CreateNew */ inline __fastcall virtual TWebModule2(Classes::TComponent* AOwner, int Dummy) : Httpapp::TWebModule(AOwner, Dummy) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TWebModule2* WebModule2;

}	/* namespace Svrinfomodule */
using namespace Svrinfomodule;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SvrInfoModule
