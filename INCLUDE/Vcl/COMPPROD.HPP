// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'CompProd.pas' rev: 6.00

#ifndef CompProdHPP
#define CompProdHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <WebComp.hpp>	// Pascal unit
#include <HTTPProd.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Compprod
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TComponentsPageProducer;
class PASCALIMPLEMENTATION TComponentsPageProducer : public Httpprod::TBasePageProducer 
{
	typedef Httpprod::TBasePageProducer inherited;
	
protected:
	HIDESBASE virtual Classes::TComponent* __fastcall FindComponent(Classes::TStrings* TagParams);
	AnsiString __fastcall FindComponentName(Classes::TStrings* TagParams);
	virtual AnsiString __fastcall GetComponentContent(Classes::TStrings* TagParams);
	DYNAMIC void __fastcall DoTagEvent(Httpprod::TTag Tag, const AnsiString TagString, Classes::TStrings* TagParams, AnsiString &ReplaceText);
	virtual Webcomp::TWebContentOptions* __fastcall GetContentOptions(bool &Owned);
	virtual AnsiString __fastcall HandleTag(const AnsiString TagString, Classes::TStrings* TagParams);
	
__published:
	__property OnHTMLTag ;
public:
	#pragma option push -w-inl
	/* TBasePageProducer.Create */ inline __fastcall virtual TComponentsPageProducer(Classes::TComponent* AOwner) : Httpprod::TBasePageProducer(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TComponentsPageProducer(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Compprod */
using namespace Compprod;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CompProd
