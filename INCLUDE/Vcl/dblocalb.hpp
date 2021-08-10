// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DBLocalB.pas' rev: 6.00

#ifndef DBLocalBHPP
#define DBLocalBHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DBTables.hpp>	// Pascal unit
#include <Provider.hpp>	// Pascal unit
#include <DBLocal.hpp>	// Pascal unit
#include <DBClient.hpp>	// Pascal unit
#include <SqlTimSt.hpp>	// Pascal unit
#include <Midas.hpp>	// Pascal unit
#include <DBCommon.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dblocalb
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TBDEQuery;
class PASCALIMPLEMENTATION TBDEQuery : public Dbtables::TQuery 
{
	typedef Dbtables::TQuery inherited;
	
private:
	AnsiString FKeyFields;
	
protected:
	virtual Db::TIndexDef* __fastcall PSGetDefaultOrder(void);
public:
	#pragma option push -w-inl
	/* TQuery.Create */ inline __fastcall virtual TBDEQuery(Classes::TComponent* AOwner) : Dbtables::TQuery(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TQuery.Destroy */ inline __fastcall virtual ~TBDEQuery(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBDEClientDataSet;
class PASCALIMPLEMENTATION TBDEClientDataSet : public Dblocal::TCustomCachedDataSet 
{
	typedef Dblocal::TCustomCachedDataSet inherited;
	
private:
	AnsiString FCommandText;
	AnsiString FCurrentCommand;
	TBDEQuery* FDataSet;
	Dbtables::TDatabase* FDatabase;
	Db::TParams* FLocalParams;
	bool FStreamedActive;
	void __fastcall CheckMasterSourceActive(Db::TDataSource* MasterSource);
	void __fastcall SetDetailsActive(bool Value);
	Dbtables::TDatabase* __fastcall GetConnection(void);
	Db::TDataSource* __fastcall GetMasterSource(void);
	HIDESBASE AnsiString __fastcall GetMasterFields();
	void __fastcall SetConnection(Dbtables::TDatabase* Value);
	HIDESBASE void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetLocalParams(void);
	HIDESBASE void __fastcall SetMasterFields(const AnsiString Value);
	void __fastcall SetParamsFromSQL(const AnsiString Value);
	void __fastcall SetSQL(const AnsiString Value);
	
protected:
	virtual AnsiString __fastcall GetCommandText();
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetActive(bool Value);
	virtual void __fastcall SetCommandText(AnsiString Value);
	
public:
	__fastcall virtual TBDEClientDataSet(Classes::TComponent* AOwner);
	__fastcall virtual ~TBDEClientDataSet(void);
	virtual void __fastcall CloneCursor(Dbclient::TCustomClientDataSet* Source, bool Reset, bool KeepSettings = false);
	AnsiString __fastcall GetQuoteChar();
	
__published:
	__property Active  = {default=0};
	__property AnsiString CommandText = {read=GetCommandText, write=SetCommandText};
	__property Dbtables::TDatabase* DBConnection = {read=GetConnection, write=SetConnection};
	__property MasterFields  = {read=GetMasterFields, write=SetMasterFields};
	__property Db::TDataSource* MasterSource = {read=GetMasterSource, write=SetDataSource};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Dblocalb */
using namespace Dblocalb;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DBLocalB
