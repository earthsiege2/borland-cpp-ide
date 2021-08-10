// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBQuery.pas' rev: 5.00

#ifndef IBQueryHPP
#define IBQueryHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IBSQL.hpp>	// Pascal unit
#include <IBCustomDataSet.hpp>	// Pascal unit
#include <IB.hpp>	// Pascal unit
#include <IBHeader.hpp>	// Pascal unit
#include <StdVCL.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibquery
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIBQuery;
class PASCALIMPLEMENTATION TIBQuery : public Ibcustomdataset::TIBCustomDataSet 
{
	typedef Ibcustomdataset::TIBCustomDataSet inherited;
	
private:
	Classes::TStrings* FSQL;
	bool FPrepared;
	Db::TParams* FParams;
	AnsiString FText;
	int FRowsAffected;
	bool FCheckRowsAffected;
	bool FGenerateParamNames;
	int __fastcall GetRowsAffected(void);
	void __fastcall PrepareSQL(char * Value);
	void __fastcall QueryChanged(System::TObject* Sender);
	void __fastcall ReadParamData(Classes::TReader* Reader);
	void __fastcall SetQuery(Classes::TStrings* Value);
	void __fastcall SetParamsList(Db::TParams* Value);
	void __fastcall SetParams(void);
	void __fastcall SetParamsFromCursor(void);
	void __fastcall SetPrepared(bool Value);
	void __fastcall SetPrepare(bool Value);
	void __fastcall WriteParamData(Classes::TWriter* Writer);
	Ibexternals::PVoid __fastcall GetStmtHandle(void);
	
protected:
	virtual void __fastcall PSExecute(void);
	virtual Db::TParams* __fastcall PSGetParams(void);
	virtual AnsiString __fastcall PSGetTableName();
	virtual void __fastcall PSSetCommandText(const AnsiString CommandText);
	virtual void __fastcall PSSetParams(Db::TParams* AParams);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall InitFieldDefs(void);
	virtual void __fastcall InternalOpen(void);
	virtual void __fastcall Disconnect(void);
	Word __fastcall GetParamsCount(void);
	bool __fastcall GenerateQueryForLiveUpdate(void);
	virtual void __fastcall SetFiltered(bool Value);
	
public:
	__fastcall virtual TIBQuery(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBQuery(void);
	void __fastcall BatchInput(Ibsql::TIBBatchInput* InputObject);
	void __fastcall BatchOutput(Ibsql::TIBBatchOutput* OutputObject);
	void __fastcall ExecSQL(void);
	virtual void __fastcall GetDetailLinkFields(Classes::TList* MasterFields, Classes::TList* DetailFields
		);
	Db::TParam* __fastcall ParamByName(const AnsiString Value);
	void __fastcall Prepare(void);
	void __fastcall UnPrepare(void);
	__property bool Prepared = {read=FPrepared, write=SetPrepare, nodefault};
	__property Word ParamCount = {read=GetParamsCount, nodefault};
	__property Ibexternals::PVoid StmtHandle = {read=GetStmtHandle};
	__property AnsiString Text = {read=FText};
	__property int RowsAffected = {read=GetRowsAffected, nodefault};
	__property bool GenerateParamNames = {read=FGenerateParamNames, write=FGenerateParamNames, nodefault
		};
	
__published:
	__property CachedUpdates ;
	__property DataSource  = {read=GetDataSource, write=SetDataSource};
	__property Constraints  = {stored=ConstraintsStored};
	__property ParamCheck ;
	__property Classes::TStrings* SQL = {read=FSQL, write=SetQuery};
	__property Db::TParams* Params = {read=FParams, write=SetParamsList, stored=false};
	__property UniDirectional ;
	__property UpdateObject ;
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Ibquery */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ibquery;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBQuery
