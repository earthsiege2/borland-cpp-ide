// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBTable.pas' rev: 6.00

#ifndef IBTableHPP
#define IBTableHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IBUtils.hpp>	// Pascal unit
#include <IBSQL.hpp>	// Pascal unit
#include <IBHeader.hpp>	// Pascal unit
#include <IBCustomDataSet.hpp>	// Pascal unit
#include <IBDatabase.hpp>	// Pascal unit
#include <IB.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibtable
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIBTableType { ttSystem, ttView };
#pragma option pop

typedef Set<TIBTableType, ttSystem, ttView>  TIBTableTypes;

typedef AnsiString TIndexName;

class DELPHICLASS TIBTable;
class PASCALIMPLEMENTATION TIBTable : public Ibcustomdataset::TIBCustomDataSet 
{
	typedef Ibcustomdataset::TIBCustomDataSet inherited;
	
private:
	bool FSystemTable;
	bool FMultiTableView;
	Db::TMasterDataLink* FMasterLink;
	Classes::TStringList* FMasterFieldsList;
	Classes::TStringList* FDetailFieldsList;
	bool FStoreDefs;
	Db::TIndexDefs* FIndexDefs;
	bool FDefaultIndex;
	bool FReadOnly;
	bool FFieldsIndex;
	AnsiString FTableName;
	AnsiString FIndexName;
	bool FRegenerateSQL;
	Classes::TStrings* FNameList;
	bool FSwitchingIndex;
	AnsiString FPrimaryIndexFields;
	TIBTableTypes FTableTypes;
	Classes::TStrings* WhereAllRefreshSQL;
	Classes::TStrings* WhereDBKeyRefreshSQL;
	Classes::TStrings* WherePrimaryRefreshSQL;
	int __fastcall GetIndexFieldCount(void);
	Db::TField* __fastcall GetIndexField(int Index);
	void __fastcall MasterChanged(System::TObject* Sender);
	void __fastcall MasterDisabled(System::TObject* Sender);
	HIDESBASE void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetIndexField(int Index, Db::TField* Value);
	void __fastcall SetIndexFieldNames(const AnsiString Value);
	void __fastcall GenerateSQL(void);
	void __fastcall GenerateUpdateSQL(void);
	void __fastcall SwitchToIndex(void);
	void __fastcall InternalTableRefresh(void);
	Classes::TStrings* __fastcall GetTableNames(void);
	void __fastcall GetTableNamesFromServer(void);
	void __fastcall SetTableTypes(const TIBTableTypes Value);
	bool __fastcall InternalGotoDBKey(const Ibcustomdataset::TIBDBKey &DBKey);
	AnsiString __fastcall FormatFieldsList(AnsiString Value);
	Ibcustomdataset::TIBDBKey __fastcall GetCurrentDBKey();
	bool __fastcall InternalGetUpdatable(void);
	bool __fastcall GetExists(void);
	void __fastcall SetIndexDefs(Db::TIndexDefs* Value);
	void __fastcall ExtractLinkFields(void);
	bool __fastcall FieldDefsStored(void);
	bool __fastcall IndexDefsStored(void);
	AnsiString __fastcall GetMasterFields();
	void __fastcall SetMasterFields(const AnsiString Value);
	AnsiString __fastcall GetIndexFieldNames();
	AnsiString __fastcall GetIndexName();
	void __fastcall SetIndexName(const AnsiString Value);
	void __fastcall SetParams(void);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall SetTableName(AnsiString Value);
	void __fastcall SetIndex(const AnsiString Value, bool FieldsIndex);
	void __fastcall ResetSQLStatements(void);
	void __fastcall Reopen(void);
	HIDESBASE bool __fastcall InternalLocate(const AnsiString KeyFields, const Variant &KeyValues, Db::TLocateOptions Options);
	
protected:
	virtual Db::TIndexDef* __fastcall PSGetDefaultOrder(void);
	virtual AnsiString __fastcall PSGetKeyFields();
	virtual AnsiString __fastcall PSGetTableName();
	virtual Db::TIndexDefs* __fastcall PSGetIndexDefs(Db::TIndexOptions IndexTypes);
	virtual void __fastcall PSSetCommandText(const AnsiString CommandText);
	virtual void __fastcall PSSetParams(Db::TParams* AParams);
	virtual void __fastcall DoOnNewRecord(void);
	void __fastcall GetIndexParams(const AnsiString IndexName, bool FieldsIndex, AnsiString &IndexedName);
	virtual bool __fastcall GetCanModify(void);
	virtual void __fastcall UpdateIndexDefs(void);
	virtual void __fastcall DataEvent(Db::TDataEvent Event, int Info);
	virtual void __fastcall DefChanged(System::TObject* Sender);
	virtual Db::TDataSource* __fastcall GetDataSource(void);
	virtual void __fastcall InitFieldDefs(void);
	virtual void __fastcall InternalClose(void);
	virtual void __fastcall InternalOpen(void);
	virtual void __fastcall InternalRefresh(void);
	virtual void __fastcall SetFiltered(bool Value);
	virtual void __fastcall SetFilterText(const AnsiString Value);
	virtual void __fastcall SetFilterOptions(Db::TFilterOptions Value);
	virtual void __fastcall InternalRefreshRow(void);
	
public:
	__fastcall virtual TIBTable(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBTable(void);
	void __fastcall AddIndex(const AnsiString Name, const AnsiString Fields, Db::TIndexOptions Options, const AnsiString DescFields = "");
	void __fastcall CreateTable(void);
	void __fastcall DeleteIndex(const AnsiString Name);
	void __fastcall DeleteTable(void);
	void __fastcall EmptyTable(void);
	virtual void __fastcall GetDetailLinkFields(Classes::TList* MasterFields, Classes::TList* DetailFields);
	void __fastcall GetIndexNames(Classes::TStrings* List);
	void __fastcall GotoCurrent(TIBTable* Table);
	virtual bool __fastcall Locate(const AnsiString KeyFields, const Variant &KeyValues, Db::TLocateOptions Options);
	__property LiveMode ;
	__property Ibcustomdataset::TIBDBKey CurrentDBKey = {read=GetCurrentDBKey};
	__property bool Exists = {read=GetExists, nodefault};
	__property int IndexFieldCount = {read=GetIndexFieldCount, nodefault};
	__property Db::TField* IndexFields[int Index] = {read=GetIndexField, write=SetIndexField};
	__property Classes::TStrings* TableNames = {read=GetTableNames};
	
__published:
	__property Active  = {default=0};
	__property BufferChunks ;
	__property CachedUpdates ;
	__property Constraints  = {stored=ConstraintsStored};
	__property bool DefaultIndex = {read=FDefaultIndex, write=FDefaultIndex, default=1};
	__property FieldDefs  = {stored=FieldDefsStored};
	__property Filter ;
	__property Filtered  = {default=0};
	__property Db::TIndexDefs* IndexDefs = {read=FIndexDefs, write=SetIndexDefs, stored=IndexDefsStored};
	__property AnsiString IndexFieldNames = {read=GetIndexFieldNames, write=SetIndexFieldNames};
	__property AnsiString IndexName = {read=GetIndexName, write=SetIndexName};
	__property AnsiString MasterFields = {read=GetMasterFields, write=SetMasterFields};
	__property Db::TDataSource* MasterSource = {read=GetDataSource, write=SetDataSource};
	__property bool ReadOnly = {read=FReadOnly, write=SetReadOnly, default=0};
	__property bool StoreDefs = {read=FStoreDefs, write=FStoreDefs, default=0};
	__property AnsiString TableName = {read=FTableName, write=SetTableName};
	__property TIBTableTypes TableTypes = {read=FTableTypes, write=SetTableTypes, default=0};
	__property UpdateObject ;
	__property UniDirectional  = {default=0};
	__property BeforeDatabaseDisconnect ;
	__property AfterDatabaseDisconnect ;
	__property DatabaseFree ;
	__property BeforeTransactionEnd ;
	__property AfterTransactionEnd ;
	__property TransactionFree ;
	__property OnFilterRecord ;
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Ibtable */
using namespace Ibtable;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBTable
