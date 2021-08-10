// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DBLocalS.pas' rev: 6.00

#ifndef DBLocalSHPP
#define DBLocalSHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SqlExpr.hpp>	// Pascal unit
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

namespace Dblocals
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSQLClientDataSet;
class PASCALIMPLEMENTATION TSQLClientDataSet : public Dblocal::TCustomCachedDataSet 
{
	typedef Dblocal::TCustomCachedDataSet inherited;
	
private:
	Db::TParams* FLocalParams;
	Sqlexpr::TSQLDataSet* FDataSet;
	AnsiString FLocalCommandText;
	Sqlexpr::TSQLConnection* FSQLConnection;
	Sqlexpr::TSQLCommandType FCommandType;
	bool FStreamedActive;
	Sqlexpr::TSQLCommandType __fastcall GetCommandType(void);
	Sqlexpr::TSQLConnection* __fastcall GetConnection(void);
	AnsiString __fastcall GetConnectionName();
	HIDESBASE AnsiString __fastcall GetMasterFields();
	bool __fastcall GetObjectView(void);
	void __fastcall SetCommandType(const Sqlexpr::TSQLCommandType Value);
	void __fastcall SetConnection(const Sqlexpr::TSQLConnection* Value);
	void __fastcall SetConnectionName(const AnsiString Value);
	void __fastcall SetInternalCommandText(AnsiString Value);
	void __fastcall SetLocalParams(void);
	HIDESBASE void __fastcall SetMasterFields(const AnsiString Value);
	HIDESBASE void __fastcall SetObjectView(const bool Value);
	Db::TDataSource* __fastcall GetMasterSource(void);
	HIDESBASE void __fastcall SetDataSource(Db::TDataSource* Value);
	
protected:
	virtual void __fastcall Loaded(void);
	virtual AnsiString __fastcall GetCommandText();
	virtual void __fastcall SetActive(bool Value);
	virtual void __fastcall SetCommandText(AnsiString Value);
	
public:
	__fastcall virtual TSQLClientDataSet(Classes::TComponent* AOwner);
	__fastcall virtual ~TSQLClientDataSet(void);
	virtual void __fastcall CloneCursor(Dbclient::TCustomClientDataSet* Source, bool Reset, bool KeepSettings = false);
	AnsiString __fastcall GetQuoteChar();
	
__published:
	__property AnsiString CommandText = {read=GetCommandText, write=SetCommandText};
	__property Sqlexpr::TSQLCommandType CommandType = {read=GetCommandType, write=SetCommandType, default=0};
	__property Sqlexpr::TSQLConnection* DBConnection = {read=GetConnection, write=SetConnection};
	__property AnsiString ConnectionName = {read=GetConnectionName, write=SetConnectionName};
	__property MasterFields  = {read=GetMasterFields, write=SetMasterFields};
	__property Db::TDataSource* MasterSource = {read=GetMasterSource, write=SetDataSource};
	__property ObjectView  = {read=GetObjectView, write=SetObjectView, default=0};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Dblocals */
using namespace Dblocals;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DBLocalS
