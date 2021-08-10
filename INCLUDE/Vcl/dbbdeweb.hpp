// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DBBdeWeb.pas' rev: 6.00

#ifndef DBBdeWebHPP
#define DBBdeWebHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <HTTPProd.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <DBWeb.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbbdeweb
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TQueryTableProducer;
class PASCALIMPLEMENTATION TQueryTableProducer : public Dbweb::TDSTableProducer 
{
	typedef Dbweb::TDSTableProducer inherited;
	
private:
	Dbtables::TQuery* FQuery;
	void __fastcall SetQuery(Dbtables::TQuery* AQuery);
	
protected:
	virtual Db::TDataSet* __fastcall GetDataSet(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetDataSet(Db::TDataSet* ADataSet);
	
public:
	virtual AnsiString __fastcall Content();
	
__published:
	__property Caption ;
	__property CaptionAlignment  = {default=0};
	__property Columns ;
	__property Footer ;
	__property Header ;
	__property MaxRows  = {default=20};
	__property Dbtables::TQuery* Query = {read=FQuery, write=SetQuery};
	__property RowAttributes ;
	__property TableAttributes ;
	__property OnCreateContent ;
	__property OnFormatCell ;
	__property OnGetTableCaption ;
public:
	#pragma option push -w-inl
	/* TDSTableProducer.Create */ inline __fastcall virtual TQueryTableProducer(Classes::TComponent* AOwner) : Dbweb::TDSTableProducer(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDSTableProducer.Destroy */ inline __fastcall virtual ~TQueryTableProducer(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Dbbdeweb */
using namespace Dbbdeweb;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DBBdeWeb
