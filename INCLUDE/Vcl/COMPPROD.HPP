// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'CompProd.pas' rev: 5.00

#ifndef CompProdHPP
#define CompProdHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <WebComp.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Compprod
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TComponentsPageProducer;
class PASCALIMPLEMENTATION TComponentsPageProducer : public Httpapp::TPageProducer 
{
	typedef Httpapp::TPageProducer inherited;
	
protected:
	HIDESBASE virtual Classes::TComponent* __fastcall FindComponent(Classes::TStrings* TagParams);
	AnsiString __fastcall FindComponentName(Classes::TStrings* TagParams);
	virtual AnsiString __fastcall GetComponentContent(Classes::TStrings* TagParams);
	DYNAMIC void __fastcall DoTagEvent(Httpapp::TTag Tag, const AnsiString TagString, Classes::TStrings* 
		TagParams, AnsiString &ReplaceText);
	virtual Webcomp::TWebContentOptions* __fastcall GetContentOptions(bool &Owned);
	
__published:
	__property OnHTMLTag ;
public:
	#pragma option push -w-inl
	/* TCustomPageProducer.Create */ inline __fastcall virtual TComponentsPageProducer(Classes::TComponent* 
		AOwner) : Httpapp::TPageProducer(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomPageProducer.Destroy */ inline __fastcall virtual ~TComponentsPageProducer(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Compprod */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Compprod;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CompProd
