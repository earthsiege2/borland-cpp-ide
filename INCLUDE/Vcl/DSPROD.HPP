// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DSProd.pas' rev: 5.00

#ifndef DSProdHPP
#define DSProdHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Db.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dsprod
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDataSetPageProducer;
class PASCALIMPLEMENTATION TDataSetPageProducer : public Httpapp::TPageProducer 
{
	typedef Httpapp::TPageProducer inherited;
	
private:
	Db::TDataSet* FDataSet;
	
protected:
	virtual Db::TDataSet* __fastcall GetDataSet(void);
	virtual void __fastcall SetDataSet(Db::TDataSet* ADataSet);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	DYNAMIC void __fastcall DoTagEvent(Httpapp::TTag Tag, const AnsiString TagString, Classes::TStrings* 
		TagParams, AnsiString &ReplaceText);
	
public:
	virtual AnsiString __fastcall Content();
	
__published:
	__property Db::TDataSet* DataSet = {read=GetDataSet, write=SetDataSet};
	__property OnHTMLTag ;
public:
	#pragma option push -w-inl
	/* TCustomPageProducer.Create */ inline __fastcall virtual TDataSetPageProducer(Classes::TComponent* 
		AOwner) : Httpapp::TPageProducer(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomPageProducer.Destroy */ inline __fastcall virtual ~TDataSetPageProducer(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Dsprod */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Dsprod;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DSProd
