// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DSProd.pas' rev: 6.00

#ifndef DSProdHPP
#define DSProdHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <HTTPProd.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dsprod
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomDataSetPageProducer;
class PASCALIMPLEMENTATION TCustomDataSetPageProducer : public Httpprod::TCustomPageProducer 
{
	typedef Httpprod::TCustomPageProducer inherited;
	
private:
	Db::TDataSet* FDataSet;
	
protected:
	virtual Db::TDataSet* __fastcall GetDataSet(void);
	virtual void __fastcall SetDataSet(Db::TDataSet* ADataSet);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	DYNAMIC void __fastcall DoTagEvent(Httpprod::TTag Tag, const AnsiString TagString, Classes::TStrings* TagParams, AnsiString &ReplaceText);
	
public:
	virtual AnsiString __fastcall Content();
	__property Db::TDataSet* DataSet = {read=GetDataSet, write=SetDataSet};
public:
	#pragma option push -w-inl
	/* TCustomPageProducer.Create */ inline __fastcall virtual TCustomDataSetPageProducer(Classes::TComponent* AOwner) : Httpprod::TCustomPageProducer(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomPageProducer.Destroy */ inline __fastcall virtual ~TCustomDataSetPageProducer(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetPageProducer;
class PASCALIMPLEMENTATION TDataSetPageProducer : public TCustomDataSetPageProducer 
{
	typedef TCustomDataSetPageProducer inherited;
	
__published:
	__property HTMLDoc ;
	__property HTMLFile ;
	__property DataSet ;
	__property OnHTMLTag ;
	__property ScriptEngine ;
public:
	#pragma option push -w-inl
	/* TCustomPageProducer.Create */ inline __fastcall virtual TDataSetPageProducer(Classes::TComponent* AOwner) : TCustomDataSetPageProducer(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomPageProducer.Destroy */ inline __fastcall virtual ~TDataSetPageProducer(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Dsprod */
using namespace Dsprod;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DSProd
