// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DBLocal.pas' rev: 6.00

#ifndef DBLocalHPP
#define DBLocalHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Provider.hpp>	// Pascal unit
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

namespace Dblocal
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TSqlDBType { typeDBX, typeBDE, typeADO, typeIBX };
#pragma option pop

class DELPHICLASS TCustomCachedDataSet;
class PASCALIMPLEMENTATION TCustomCachedDataSet : public Dbclient::TCustomClientDataSet 
{
	typedef Dbclient::TCustomClientDataSet inherited;
	
private:
	Provider::TDataSetProvider* FProvider;
	TSqlDBType FSqlDBType;
	Provider::TBeforeUpdateRecordEvent __fastcall GetBeforeUpdateRecord();
	void __fastcall SetBeforeUpdateRecord(Provider::TBeforeUpdateRecordEvent Value);
	Provider::TAfterUpdateRecordEvent __fastcall GetAfterUpdateRecord();
	void __fastcall SetAfterUpdateRecord(Provider::TAfterUpdateRecordEvent Value);
	Provider::TGetTableNameEvent __fastcall GetOnGetTableName();
	void __fastcall SetOnGetTableName(Provider::TGetTableNameEvent Value);
	Provider::TProviderDataEvent __fastcall GetOnUpdateData();
	void __fastcall SetOnUpdateData(Provider::TProviderDataEvent Value);
	Provider::TResolverErrorEvent __fastcall GetOnUpdateError();
	void __fastcall SetOnUpdateError(Provider::TResolverErrorEvent Value);
	
protected:
	virtual void __fastcall CloseCursor(void);
	virtual AnsiString __fastcall GetCommandText();
	Provider::TProviderOptions __fastcall GetOptions(void);
	Db::TUpdateMode __fastcall GetUpdateMode(void);
	virtual void __fastcall SetActive(bool Value);
	virtual void __fastcall SetAggregates(Dbclient::TAggregates* Value);
	virtual void __fastcall SetCommandText(AnsiString Value);
	void __fastcall SetOptions(Provider::TProviderOptions Value);
	void __fastcall SetUpdateMode(Db::TUpdateMode Value);
	__property Provider::TDataSetProvider* Provider = {read=FProvider, write=FProvider};
	__property TSqlDBType SqlDBType = {read=FSqlDBType, write=FSqlDBType, nodefault};
	
public:
	__fastcall virtual TCustomCachedDataSet(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomCachedDataSet(void);
	HIDESBASE void __fastcall LoadFromFile(const AnsiString AFileName = "");
	
__published:
	__property Active  = {default=0};
	__property CommandText ;
	__property Aggregates ;
	__property AggregatesActive  = {default=0};
	__property AutoCalcFields  = {default=1};
	__property Constraints  = {stored=ConstraintsStored};
	__property DisableStringTrim  = {default=0};
	__property FetchOnDemand  = {default=1};
	__property FieldDefs ;
	__property FileName ;
	__property Filter ;
	__property Filtered  = {default=0};
	__property FilterOptions  = {default=0};
	__property IndexDefs ;
	__property IndexFieldNames ;
	__property IndexName ;
	__property MasterFields ;
	__property MasterSource ;
	__property Provider::TProviderOptions Options = {read=GetOptions, write=SetOptions, default=0};
	__property ObjectView  = {default=1};
	__property PacketRecords  = {default=-1};
	__property Params ;
	__property ReadOnly  = {default=0};
	__property Db::TUpdateMode UpdateMode = {read=GetUpdateMode, write=SetUpdateMode, default=0};
	__property BeforeOpen ;
	__property AfterOpen ;
	__property BeforeClose ;
	__property AfterClose ;
	__property BeforeInsert ;
	__property AfterInsert ;
	__property BeforeEdit ;
	__property AfterEdit ;
	__property BeforePost ;
	__property AfterPost ;
	__property BeforeCancel ;
	__property AfterCancel ;
	__property BeforeDelete ;
	__property AfterDelete ;
	__property BeforeScroll ;
	__property AfterScroll ;
	__property BeforeRefresh ;
	__property AfterRefresh ;
	__property OnCalcFields ;
	__property OnDeleteError ;
	__property OnEditError ;
	__property OnFilterRecord ;
	__property OnNewRecord ;
	__property OnPostError ;
	__property OnReconcileError ;
	__property BeforeApplyUpdates ;
	__property AfterApplyUpdates ;
	__property BeforeGetRecords ;
	__property AfterGetRecords ;
	__property BeforeRowRequest ;
	__property AfterRowRequest ;
	__property BeforeExecute ;
	__property AfterExecute ;
	__property BeforeGetParams ;
	__property AfterGetParams ;
	__property Provider::TBeforeUpdateRecordEvent BeforeUpdateRecord = {read=GetBeforeUpdateRecord, write=SetBeforeUpdateRecord};
	__property Provider::TAfterUpdateRecordEvent AfterUpdateRecord = {read=GetAfterUpdateRecord, write=SetAfterUpdateRecord};
	__property Provider::TGetTableNameEvent OnGetTableName = {read=GetOnGetTableName, write=SetOnGetTableName};
	__property Provider::TProviderDataEvent OnUpdateData = {read=GetOnUpdateData, write=SetOnUpdateData};
	__property Provider::TResolverErrorEvent OnUpdateError = {read=GetOnUpdateError, write=SetOnUpdateError};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Dblocal */
using namespace Dblocal;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DBLocal
