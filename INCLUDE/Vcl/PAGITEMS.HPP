// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'PagItems.pas' rev: 6.00

#ifndef PagItemsHPP
#define PagItemsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <HTTPProd.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <CompProd.hpp>	// Pascal unit
#include <WebComp.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Pagitems
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TBasePageItemsProducer;
class PASCALIMPLEMENTATION TBasePageItemsProducer : public Compprod::TComponentsPageProducer 
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
	__fastcall virtual TBasePageItemsProducer(Classes::TComponent* AOwner);
	__fastcall virtual ~TBasePageItemsProducer(void);
	__property Webcomp::TWebComponentList* WebPageItems = {read=FWebPageItems};
private:
	void *__IGetWebComponentList;	/* Webcomp::IGetWebComponentList */
	void *__ITopLevelWebComponent;	/* Webcomp::ITopLevelWebComponent */
	
public:
	operator ITopLevelWebComponent*(void) { return (ITopLevelWebComponent*)&__ITopLevelWebComponent; }
	operator IGetWebComponentList*(void) { return (IGetWebComponentList*)&__IGetWebComponentList; }
	
};


class DELPHICLASS TPageItemsProducer;
class PASCALIMPLEMENTATION TPageItemsProducer : public TBasePageItemsProducer 
{
	typedef TBasePageItemsProducer inherited;
	
private:
	AnsiString FHTMLFile;
	Classes::TStrings* FHTMLDoc;
	void __fastcall SetHTMLFile(const AnsiString Value);
	void __fastcall SetHTMLDoc(Classes::TStrings* Value);
	
protected:
	virtual Classes::TStream* __fastcall GetTemplateStream(/* out */ bool &AOwned);
	
public:
	__fastcall virtual TPageItemsProducer(Classes::TComponent* AOwner);
	__fastcall virtual ~TPageItemsProducer(void);
	__property Classes::TStrings* HTMLDoc = {read=FHTMLDoc, write=SetHTMLDoc};
	__property AnsiString HTMLFile = {read=FHTMLFile, write=SetHTMLFile};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Pagitems */
using namespace Pagitems;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// PagItems
