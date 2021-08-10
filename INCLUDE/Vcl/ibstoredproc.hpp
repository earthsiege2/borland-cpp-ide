// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBStoredProc.pas' rev: 5.00

#ifndef IBStoredProcHPP
#define IBStoredProcHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IBUtils.hpp>	// Pascal unit
#include <IBSQL.hpp>	// Pascal unit
#include <IBHeader.hpp>	// Pascal unit
#include <IBCustomDataSet.hpp>	// Pascal unit
#include <IBDatabase.hpp>	// Pascal unit
#include <IB.hpp>	// Pascal unit
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

namespace Ibstoredproc
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIBStoredProc;
class PASCALIMPLEMENTATION TIBStoredProc : public Ibcustomdataset::TIBCustomDataSet 
{
	typedef Ibcustomdataset::TIBCustomDataSet inherited;
	
private:
	bool FIBLoaded;
	void * *FStmtHandle;
	AnsiString FProcName;
	Db::TParams* FParams;
	bool FPrepared;
	Classes::TStrings* FNameList;
	void __fastcall SetParamsList(Db::TParams* Value);
	void __fastcall FreeStatement(void);
	Classes::TStrings* __fastcall GetStoredProcedureNames(void);
	void __fastcall GetStoredProcedureNamesFromServer(void);
	void __fastcall CreateParamDesc(void);
	void __fastcall SetParams(void);
	void __fastcall SetParamsFromCursor(void);
	void __fastcall GenerateSQL(void);
	void __fastcall FetchDataIntoOutputParams(void);
	void __fastcall ReadParamData(Classes::TReader* Reader);
	void __fastcall WriteParamData(Classes::TWriter* Writer);
	
protected:
	virtual void __fastcall PSExecute(void);
	virtual AnsiString __fastcall PSGetTableName();
	virtual Db::TParams* __fastcall PSGetParams(void);
	virtual void __fastcall PSSetCommandText(const AnsiString CommandText);
	virtual void __fastcall PSSetParams(Db::TParams* AParams);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall SetFiltered(bool Value);
	Word __fastcall GetParamsCount(void);
	void __fastcall SetPrepared(bool Value);
	void __fastcall SetPrepare(bool Value);
	void __fastcall SetProcName(AnsiString Value);
	virtual void __fastcall Disconnect(void);
	virtual void __fastcall InternalOpen(void);
	
public:
	__fastcall virtual TIBStoredProc(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBStoredProc(void);
	void __fastcall CopyParams(Db::TParams* Value);
	void __fastcall ExecProc(void);
	Db::TParam* __fastcall ParamByName(const AnsiString Value);
	void __fastcall Prepare(void);
	void __fastcall UnPrepare(void);
	__property Word ParamCount = {read=GetParamsCount, nodefault};
	__property Ibexternals::PVoid StmtHandle = {read=FStmtHandle};
	__property bool Prepared = {read=FPrepared, write=SetPrepare, nodefault};
	__property Classes::TStrings* StoredProcedureNames = {read=GetStoredProcedureNames};
	
__published:
	__property AnsiString StoredProcName = {read=FProcName, write=SetProcName};
	__property Db::TParams* Params = {read=FParams, write=SetParamsList};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Ibstoredproc */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ibstoredproc;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBStoredProc
