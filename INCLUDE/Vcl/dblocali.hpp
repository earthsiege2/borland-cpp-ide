// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DBLocalI.pas' rev: 6.00

#ifndef DBLocalIHPP
#define DBLocalIHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IBCustomDataSet.hpp>	// Pascal unit
#include <Provider.hpp>	// Pascal unit
#include <DBLocal.hpp>	// Pascal unit
#include <DBClient.hpp>	// Pascal unit
#include <IB.hpp>	// Pascal unit
#include <IBDatabase.hpp>	// Pascal unit
#include <IBQuery.hpp>	// Pascal unit
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

namespace Dblocali
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIBCDSQuery;
class PASCALIMPLEMENTATION TIBCDSQuery : public Ibquery::TIBQuery 
{
	typedef Ibquery::TIBQuery inherited;
	
private:
	AnsiString FKeyFields;
	
protected:
	virtual Db::TIndexDef* __fastcall PSGetDefaultOrder(void);
public:
	#pragma option push -w-inl
	/* TIBQuery.Create */ inline __fastcall virtual TIBCDSQuery(Classes::TComponent* AOwner) : Ibquery::TIBQuery(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIBQuery.Destroy */ inline __fastcall virtual ~TIBCDSQuery(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIBClientDataSet;
class PASCALIMPLEMENTATION TIBClientDataSet : public Dblocal::TCustomCachedDataSet 
{
	typedef Dblocal::TCustomCachedDataSet inherited;
	
private:
	AnsiString FCommandText;
	TIBCDSQuery* FDataSet;
	Db::TParams* FLocalParams;
	bool FStreamedActive;
	void __fastcall CheckMasterSourceActive(Db::TDataSource* MasterSource);
	void __fastcall SetDetailsActive(bool Value);
	Ibdatabase::TIBDatabase* __fastcall GetConnection(void);
	HIDESBASE AnsiString __fastcall GetMasterFields();
	Db::TDataSource* __fastcall GetMasterSource(void);
	Ibdatabase::TIBTransaction* __fastcall GetTransaction(void);
	void __fastcall SetConnection(Ibdatabase::TIBDatabase* Value);
	HIDESBASE void __fastcall SetDataSource(const Db::TDataSource* Value);
	void __fastcall SetInternalCommandText(AnsiString Value);
	void __fastcall SetLocalParams(void);
	HIDESBASE void __fastcall SetMasterFields(const AnsiString Value);
	void __fastcall SetParamsFromSQL(const AnsiString Value);
	void __fastcall SetTransaction(const Ibdatabase::TIBTransaction* Value);
	
protected:
	virtual AnsiString __fastcall GetCommandText();
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetActive(bool Value);
	virtual void __fastcall SetCommandText(AnsiString Value);
	
public:
	__fastcall virtual TIBClientDataSet(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBClientDataSet(void);
	virtual void __fastcall CloneCursor(Dbclient::TCustomClientDataSet* Source, bool Reset, bool KeepSettings = false);
	AnsiString __fastcall GetQuoteChar();
	
__published:
	__property Active  = {default=0};
	__property AnsiString CommandText = {read=GetCommandText, write=SetCommandText};
	__property Ibdatabase::TIBDatabase* DBConnection = {read=GetConnection, write=SetConnection};
	__property Ibdatabase::TIBTransaction* DBTransaction = {read=GetTransaction, write=SetTransaction};
	__property AnsiString MasterFields = {read=GetMasterFields, write=SetMasterFields};
	__property Db::TDataSource* MasterSource = {read=GetMasterSource, write=SetDataSource};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Dblocali */
using namespace Dblocali;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DBLocalI
