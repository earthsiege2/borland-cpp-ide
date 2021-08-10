// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'PagItems.pas' rev: 5.00

#ifndef PagItemsHPP
#define PagItemsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <CompProd.hpp>	// Pascal unit
#include <WebComp.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <ImgList.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Pagitems
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TPageItemsProducer;
class PASCALIMPLEMENTATION TPageItemsProducer : public Compprod::TComponentsPageProducer 
{
	typedef Compprod::TComponentsPageProducer inherited;
	
private:
	Webcomp::TWebComponentList* FWebPageItems;
	
protected:
	System::TObject* __fastcall GetComponentList(void);
	System::TObject* __fastcall GetDefaultComponentList(void);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	DYNAMIC void __fastcall SetChildOrder(Classes::TComponent* Component, int Order);
	
public:
	__fastcall virtual TPageItemsProducer(Classes::TComponent* AOwner);
	__fastcall virtual ~TPageItemsProducer(void);
	__property Webcomp::TWebComponentList* WebPageItems = {read=FWebPageItems};
private:
	void *__IGetWebComponentList;	/* Webcomp::IGetWebComponentList */
	
public:
	operator IGetWebComponentList*(void) { return (IGetWebComponentList*)&__IGetWebComponentList; }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Pagitems */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Pagitems;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// PagItems
