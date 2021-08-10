// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBCustomDataSet.pas' rev: 6.00

#ifndef IBCustomDataSetHPP
#define IBCustomDataSetHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IBBlob.hpp>	// Pascal unit
#include <IBUtils.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <IBSQL.hpp>	// Pascal unit
#include <IBDatabase.hpp>	// Pascal unit
#include <IBHeader.hpp>	// Pascal unit
#include <IB.hpp>	// Pascal unit
#include <IBExternals.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibcustomdataset
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIBDataSetUpdateObject;
class DELPHICLASS TIBCustomDataSet;
class PASCALIMPLEMENTATION TIBDataSetUpdateObject : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Classes::TStrings* FRefreshSQL;
	void __fastcall SetRefreshSQL(Classes::TStrings* value);
	
protected:
	virtual TIBCustomDataSet* __fastcall GetDataSet(void) = 0 ;
	virtual void __fastcall SetDataSet(TIBCustomDataSet* ADataSet) = 0 ;
	virtual void __fastcall Apply(Db::TUpdateKind UpdateKind) = 0 ;
	virtual Classes::TStrings* __fastcall GetSQL(Db::TUpdateKind UpdateKind) = 0 ;
	__property TIBCustomDataSet* DataSet = {read=GetDataSet, write=SetDataSet};
	
public:
	__fastcall virtual TIBDataSetUpdateObject(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBDataSetUpdateObject(void);
	
__published:
	__property Classes::TStrings* RefreshSQL = {read=FRefreshSQL, write=SetRefreshSQL};
};


typedef System::TDateTime *PDateTime;

typedef Ibblob::TIBBlobStream* TBlobDataArray[1];

typedef Ibblob::TIBBlobStream* *PBlobDataArray;

#pragma pack(push, 4)
struct TFieldData
{
	short fdDataType;
	short fdDataScale;
	bool fdNullable;
	bool fdIsNull;
	short fdDataSize;
	short fdDataLength;
	int fdDataOfs;
} ;
#pragma pack(pop)

typedef TFieldData *PFieldData;

#pragma option push -b-
enum TCachedUpdateStatus { cusUnmodified, cusModified, cusInserted, cusDeleted, cusUninserted };
#pragma option pop

#pragma pack(push, 1)
struct TIBDBKey
{
	Byte DBKey[8];
} ;
#pragma pack(pop)

typedef TIBDBKey *PIBDBKey;

#pragma pack(push, 4)
struct TRecordData
{
	Db::TBookmarkFlag rdBookmarkFlag;
	short rdFieldCount;
	int rdRecordNumber;
	TCachedUpdateStatus rdCachedUpdateStatus;
	Db::TUpdateStatus rdUpdateStatus;
	unsigned rdSavedOffset;
	TIBDBKey rdDBKey;
	TFieldData rdFields[1];
} ;
#pragma pack(pop)

typedef TRecordData *PRecordData;

class DELPHICLASS TIBStringField;
class PASCALIMPLEMENTATION TIBStringField : public Db::TStringField 
{
	typedef Db::TStringField inherited;
	
public:
	__fastcall virtual TIBStringField(Classes::TComponent* AOwner);
	/* virtual class method */ virtual void __fastcall CheckTypeSize(TMetaClass* vmt, int Value);
	virtual AnsiString __fastcall GetAsString();
	virtual Variant __fastcall GetAsVariant();
	HIDESBASE bool __fastcall GetValue(AnsiString &Value);
	virtual void __fastcall SetAsString(const AnsiString Value);
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TIBStringField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIBBCDField;
class PASCALIMPLEMENTATION TIBBCDField : public Db::TBCDField 
{
	typedef Db::TBCDField inherited;
	
protected:
	/* virtual class method */ virtual void __fastcall CheckTypeSize(TMetaClass* vmt, int Value);
	virtual System::Currency __fastcall GetAsCurrency(void);
	virtual AnsiString __fastcall GetAsString();
	virtual Variant __fastcall GetAsVariant();
	virtual int __fastcall GetDataSize(void);
	
public:
	__fastcall virtual TIBBCDField(Classes::TComponent* AOwner);
	
__published:
	__property Size  = {default=8};
public:
	#pragma option push -w-inl
	/* TField.Destroy */ inline __fastcall virtual ~TIBBCDField(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIBDataLink;
class PASCALIMPLEMENTATION TIBDataLink : public Db::TDetailDataLink 
{
	typedef Db::TDetailDataLink inherited;
	
private:
	TIBCustomDataSet* FDataSet;
	
protected:
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall RecordChanged(Db::TField* Field);
	virtual Db::TDataSet* __fastcall GetDetailDataSet(void);
	virtual void __fastcall CheckBrowseMode(void);
	
public:
	__fastcall TIBDataLink(TIBCustomDataSet* ADataSet);
	__fastcall virtual ~TIBDataLink(void);
};


#pragma option push -b-
enum TIBGeneratorApplyEvent { gamOnNewRecord, gamOnPost, gamOnServer };
#pragma option pop

class DELPHICLASS TIBGeneratorField;
class PASCALIMPLEMENTATION TIBGeneratorField : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	AnsiString FField;
	AnsiString FGenerator;
	int FIncrementBy;
	TIBCustomDataSet* DataSet;
	TIBGeneratorApplyEvent FApplyEvent;
	bool __fastcall IsComplete(void);
	
public:
	__fastcall TIBGeneratorField(TIBCustomDataSet* ADataSet);
	AnsiString __fastcall ValueName();
	void __fastcall Apply(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property AnsiString Field = {read=FField, write=FField};
	__property AnsiString Generator = {read=FGenerator, write=FGenerator};
	__property int IncrementBy = {read=FIncrementBy, write=FIncrementBy, default=1};
	__property TIBGeneratorApplyEvent ApplyEvent = {read=FApplyEvent, write=FApplyEvent, default=0};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TIBGeneratorField(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TIBUpdateAction { uaFail, uaAbort, uaSkip, uaRetry, uaApply, uaApplied };
#pragma option pop

typedef void __fastcall (__closure *TIBUpdateErrorEvent)(Db::TDataSet* DataSet, Db::EDatabaseError* E, Db::TUpdateKind UpdateKind, TIBUpdateAction &UpdateAction);

typedef void __fastcall (__closure *TIBUpdateRecordEvent)(Db::TDataSet* DataSet, Db::TUpdateKind UpdateKind, TIBUpdateAction &UpdateAction);

typedef Set<TCachedUpdateStatus, cusUnmodified, cusUninserted>  TIBUpdateRecordTypes;

#pragma option push -b-
enum TLiveMode { lmInsert, lmModify, lmDelete, lmRefresh };
#pragma option pop

typedef Set<TLiveMode, lmInsert, lmRefresh>  TLiveModes;

typedef DynamicArray<int >  IBCustomDataSet__7;

class PASCALIMPLEMENTATION TIBCustomDataSet : public Db::TDataSet 
{
	typedef Db::TDataSet inherited;
	
private:
	bool FNeedsRefresh;
	bool FForcedRefresh;
	bool FIBLoaded;
	Ibdatabase::TIBBase* FBase;
	int FBlobCacheOffset;
	Classes::TList* FBlobStreamList;
	int FBufferChunks;
	char *FBufferCache;
	char *FOldBufferCache;
	int FBufferChunkSize;
	int FCacheSize;
	int FOldCacheSize;
	char *FFilterBuffer;
	unsigned FBPos;
	unsigned FOBPos;
	unsigned FBEnd;
	unsigned FOBEnd;
	bool FCachedUpdates;
	int FCalcFieldsOffset;
	int FCurrentRecord;
	int FDeletedRecords;
	char *FModelBuffer;
	char *FOldBuffer;
	bool FOpen;
	bool FInternalPrepared;
	Ibsql::TIBSQL* FQDelete;
	Ibsql::TIBSQL* FQInsert;
	Ibsql::TIBSQL* FQRefresh;
	Ibsql::TIBSQL* FQSelect;
	Ibsql::TIBSQL* FQModify;
	int FRecordBufferSize;
	int FRecordCount;
	int FRecordSize;
	bool FUniDirectional;
	Db::TUpdateMode FUpdateMode;
	TIBDataSetUpdateObject* FUpdateObject;
	bool FParamCheck;
	bool FUpdatesPending;
	TIBUpdateRecordTypes FUpdateRecordTypes;
	DynamicArray<int >  FMappedFieldPosition;
	TIBDataLink* FDataLink;
	bool FStreamedActive;
	TLiveModes FLiveMode;
	TIBGeneratorField* FGeneratorField;
	int FRowsAffected;
	Classes::TNotifyEvent FBeforeDatabaseDisconnect;
	Classes::TNotifyEvent FAfterDatabaseDisconnect;
	Classes::TNotifyEvent FDatabaseFree;
	TIBUpdateErrorEvent FOnUpdateError;
	TIBUpdateRecordEvent FOnUpdateRecord;
	Classes::TNotifyEvent FBeforeTransactionEnd;
	Classes::TNotifyEvent FAfterTransactionEnd;
	Classes::TNotifyEvent FTransactionFree;
	Ibexternals::PVoid __fastcall GetSelectStmtHandle(void);
	void __fastcall SetUpdateMode(const Db::TUpdateMode Value);
	void __fastcall SetUpdateObject(TIBDataSetUpdateObject* Value);
	Db::TGetResult __fastcall AdjustCurrentRecord(void * Buffer, Db::TGetMode GetMode);
	void __fastcall AdjustRecordOnInsert(void * Buffer);
	bool __fastcall CanEdit(void);
	bool __fastcall CanInsert(void);
	bool __fastcall CanDelete(void);
	bool __fastcall CanRefresh(void);
	void __fastcall CheckEditState(void);
	void __fastcall ClearBlobCache(void);
	void __fastcall CopyRecordBuffer(void * Source, void * Dest);
	void __fastcall DoBeforeDatabaseDisconnect(System::TObject* Sender);
	void __fastcall DoAfterDatabaseDisconnect(System::TObject* Sender);
	void __fastcall DoDatabaseFree(System::TObject* Sender);
	void __fastcall DoBeforeTransactionEnd(System::TObject* Sender);
	void __fastcall DoAfterTransactionEnd(System::TObject* Sender);
	void __fastcall DoTransactionFree(System::TObject* Sender);
	void __fastcall FetchCurrentRecordToBuffer(Ibsql::TIBSQL* Qry, int RecordNumber, char * Buffer);
	Ibdatabase::TIBDatabase* __fastcall GetDatabase(void);
	Ibheader::PISC_DB_HANDLE __fastcall GetDBHandle(void);
	Classes::TStrings* __fastcall GetDeleteSQL(void);
	Classes::TStrings* __fastcall GetInsertSQL(void);
	Ibsql::TIBXSQLDA* __fastcall GetSQLParams(void);
	Classes::TStrings* __fastcall GetRefreshSQL(void);
	Classes::TStrings* __fastcall GetSelectSQL(void);
	Ibsql::TIBSQLTypes __fastcall GetStatementType(void);
	Classes::TStrings* __fastcall GetModifySQL(void);
	Ibdatabase::TIBTransaction* __fastcall GetTransaction(void);
	Ibheader::PISC_TR_HANDLE __fastcall GetTRHandle(void);
	void __fastcall InternalDeleteRecord(Ibsql::TIBSQL* Qry, void * Buff);
	bool __fastcall InternalLocate(const AnsiString KeyFields, const Variant &KeyValues, Db::TLocateOptions Options);
	void __fastcall InternalPostRecord(Ibsql::TIBSQL* Qry, void * Buff);
	void __fastcall InternalRevertRecord(int RecordNumber);
	bool __fastcall IsVisible(char * Buffer);
	void __fastcall SaveOldBuffer(char * Buffer);
	void __fastcall SetBufferChunks(int Value);
	void __fastcall SetDatabase(Ibdatabase::TIBDatabase* Value);
	void __fastcall SetDeleteSQL(Classes::TStrings* Value);
	void __fastcall SetInsertSQL(Classes::TStrings* Value);
	void __fastcall SetInternalSQLParams(Ibsql::TIBSQL* Qry, void * Buffer);
	void __fastcall SetRefreshSQL(Classes::TStrings* Value);
	void __fastcall SetSelectSQL(Classes::TStrings* Value);
	void __fastcall SetModifySQL(Classes::TStrings* Value);
	void __fastcall SetTransaction(Ibdatabase::TIBTransaction* Value);
	void __fastcall SetUpdateRecordTypes(TIBUpdateRecordTypes Value);
	HIDESBASE void __fastcall SetUniDirectional(bool Value);
	void __fastcall RefreshParams(void);
	void __fastcall SQLChanging(System::TObject* Sender);
	int __fastcall AdjustPosition(char * FCache, unsigned Offset, int Origin);
	void __fastcall ReadCache(char * FCache, unsigned Offset, int Origin, char * Buffer);
	void __fastcall ReadRecordCache(int RecordNumber, char * Buffer, bool ReadOldBuffer);
	void __fastcall WriteCache(char * FCache, unsigned Offset, int Origin, char * Buffer);
	void __fastcall WriteRecordCache(int RecordNumber, char * Buffer);
	Db::TGetResult __fastcall InternalGetRecord(char * Buffer, Db::TGetMode GetMode, bool DoCheck);
	void __fastcall SetGeneratorField(const TIBGeneratorField* Value);
	bool __fastcall InternalGetFieldData(Db::TField* Field, void * Buffer);
	virtual void __fastcall InternalSetFieldData(Db::TField* Field, void * Buffer);
	AnsiString __fastcall GetPlan();
	
protected:
	void __fastcall ActivateConnection(void);
	bool __fastcall ActivateTransaction(void);
	void __fastcall DeactivateTransaction(void);
	void __fastcall CheckDatasetClosed(void);
	void __fastcall CheckDatasetOpen(void);
	char * __fastcall GetActiveBuf(void);
	virtual void __fastcall InternalBatchInput(Ibsql::TIBBatchInput* InputObject);
	virtual void __fastcall InternalBatchOutput(Ibsql::TIBBatchOutput* OutputObject);
	virtual void __fastcall InternalPrepare(void);
	virtual void __fastcall InternalUnPrepare(void);
	virtual void __fastcall InternalExecQuery(void);
	virtual void __fastcall InternalRefreshRow(void);
	virtual void __fastcall InternalSetParamsFromCursor(void);
	void __fastcall CheckNotUniDirectional(void);
	virtual void __fastcall SetActive(bool Value);
	virtual void __fastcall PSEndTransaction(bool Commit);
	virtual int __fastcall PSExecuteStatement(const AnsiString ASQL, Db::TParams* AParams, void * ResultSet = (void *)(0x0));
	virtual AnsiString __fastcall PsGetTableName();
	virtual AnsiString __fastcall PSGetQuoteChar();
	virtual Db::EUpdateError* __fastcall PSGetUpdateException(Sysutils::Exception* E, Db::EUpdateError* Prev);
	virtual bool __fastcall PSInTransaction(void);
	virtual bool __fastcall PSIsSQLBased(void);
	virtual bool __fastcall PSIsSQLSupported(void);
	virtual void __fastcall PSStartTransaction(void);
	virtual void __fastcall PSReset(void);
	virtual bool __fastcall PSUpdateRecord(Db::TUpdateKind UpdateKind, Db::TDataSet* Delta);
	virtual void __fastcall InternalInsert(void);
	virtual void __fastcall InitRecord(char * Buffer);
	virtual void __fastcall Disconnect(void);
	bool __fastcall ConstraintsStored(void);
	virtual void __fastcall ClearCalcFields(char * Buffer);
	virtual void __fastcall CreateFields(void);
	virtual char * __fastcall AllocRecordBuffer(void);
	virtual void __fastcall DoBeforeDelete(void);
	virtual void __fastcall DoBeforeEdit(void);
	virtual void __fastcall DoBeforeInsert(void);
	virtual void __fastcall FreeRecordBuffer(char * &Buffer);
	virtual void __fastcall GetBookmarkData(char * Buffer, void * Data);
	virtual Db::TBookmarkFlag __fastcall GetBookmarkFlag(char * Buffer);
	virtual bool __fastcall GetCanModify(void);
	virtual Db::TDataSource* __fastcall GetDataSource(void);
	virtual TMetaClass* __fastcall GetFieldClass(Db::TFieldType FieldType);
	virtual int __fastcall GetRecNo(void);
	virtual Db::TGetResult __fastcall GetRecord(char * Buffer, Db::TGetMode GetMode, bool DoCheck);
	virtual int __fastcall GetRecordCount(void);
	virtual Word __fastcall GetRecordSize(void);
	virtual void __fastcall InternalAddRecord(void * Buffer, bool Append);
	virtual void __fastcall InternalCancel(void);
	virtual void __fastcall InternalClose(void);
	virtual void __fastcall InternalDelete(void);
	virtual void __fastcall InternalFirst(void);
	virtual void __fastcall InternalGotoBookmark(void * Bookmark);
	virtual void __fastcall InternalHandleException(void);
	virtual void __fastcall InternalInitFieldDefs(void);
	virtual void __fastcall InternalInitRecord(char * Buffer);
	virtual void __fastcall InternalLast(void);
	virtual void __fastcall InternalOpen(void);
	virtual void __fastcall InternalPost(void);
	virtual void __fastcall InternalRefresh(void);
	virtual void __fastcall InternalSetToRecord(char * Buffer);
	virtual bool __fastcall IsCursorOpen(void);
	void __fastcall ReQuery(void);
	virtual void __fastcall SetBookmarkFlag(char * Buffer, Db::TBookmarkFlag Value);
	virtual void __fastcall SetBookmarkData(char * Buffer, void * Data);
	void __fastcall SetCachedUpdates(bool Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	virtual void __fastcall SetFieldData(Db::TField* Field, void * Buffer)/* overload */;
	virtual void __fastcall SetFieldData(Db::TField* Field, void * Buffer, bool NativeFormat)/* overload */;
	virtual void __fastcall SetRecNo(int Value);
	virtual void __fastcall DoOnNewRecord(void);
	virtual void __fastcall Loaded(void);
	__property Ibsql::TIBXSQLDA* SQLParams = {read=GetSQLParams};
	__property Ibsql::TIBXSQLDA* Params = {read=GetSQLParams};
	__property bool InternalPrepared = {read=FInternalPrepared, nodefault};
	__property Ibsql::TIBSQL* QDelete = {read=FQDelete};
	__property Ibsql::TIBSQL* QInsert = {read=FQInsert};
	__property Ibsql::TIBSQL* QRefresh = {read=FQRefresh};
	__property Ibsql::TIBSQL* QSelect = {read=FQSelect};
	__property Ibsql::TIBSQL* QModify = {read=FQModify};
	__property Ibsql::TIBSQLTypes StatementType = {read=GetStatementType, nodefault};
	__property Ibexternals::PVoid SelectStmtHandle = {read=GetSelectStmtHandle};
	__property TLiveModes LiveMode = {read=FLiveMode, nodefault};
	__property int BufferChunks = {read=FBufferChunks, write=SetBufferChunks, nodefault};
	__property bool CachedUpdates = {read=FCachedUpdates, write=SetCachedUpdates, nodefault};
	__property bool UniDirectional = {read=FUniDirectional, write=SetUniDirectional, default=0};
	__property Classes::TStrings* DeleteSQL = {read=GetDeleteSQL, write=SetDeleteSQL};
	__property Classes::TStrings* InsertSQL = {read=GetInsertSQL, write=SetInsertSQL};
	__property Classes::TStrings* RefreshSQL = {read=GetRefreshSQL, write=SetRefreshSQL};
	__property Classes::TStrings* SelectSQL = {read=GetSelectSQL, write=SetSelectSQL};
	__property Classes::TStrings* ModifySQL = {read=GetModifySQL, write=SetModifySQL};
	__property Db::TUpdateMode UpdateMode = {read=FUpdateMode, write=SetUpdateMode, default=0};
	__property bool ParamCheck = {read=FParamCheck, write=FParamCheck, default=1};
	__property TIBGeneratorField* GeneratorField = {read=FGeneratorField, write=SetGeneratorField};
	__property Classes::TNotifyEvent BeforeDatabaseDisconnect = {read=FBeforeDatabaseDisconnect, write=FBeforeDatabaseDisconnect};
	__property Classes::TNotifyEvent AfterDatabaseDisconnect = {read=FAfterDatabaseDisconnect, write=FAfterDatabaseDisconnect};
	__property Classes::TNotifyEvent DatabaseFree = {read=FDatabaseFree, write=FDatabaseFree};
	__property Classes::TNotifyEvent BeforeTransactionEnd = {read=FBeforeTransactionEnd, write=FBeforeTransactionEnd};
	__property Classes::TNotifyEvent AfterTransactionEnd = {read=FAfterTransactionEnd, write=FAfterTransactionEnd};
	__property Classes::TNotifyEvent TransactionFree = {read=FTransactionFree, write=FTransactionFree};
	
public:
	__fastcall virtual TIBCustomDataSet(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBCustomDataSet(void);
	void __fastcall ApplyUpdates(void);
	TCachedUpdateStatus __fastcall CachedUpdateStatus(void);
	void __fastcall CancelUpdates(void);
	void __fastcall FetchAll(void);
	bool __fastcall LocateNext(const AnsiString KeyFields, const Variant &KeyValues, Db::TLocateOptions Options);
	void __fastcall RecordModified(bool Value);
	void __fastcall RevertRecord(void);
	void __fastcall Undelete(void);
	virtual void __fastcall Post(void);
	Ibsql::TIBXSQLDA* __fastcall Current(void);
	Ibsql::TIBSQLTypes __fastcall SQLType(void);
	virtual bool __fastcall BookmarkValid(void * Bookmark);
	virtual int __fastcall CompareBookmarks(void * Bookmark1, void * Bookmark2);
	virtual Classes::TStream* __fastcall CreateBlobStream(Db::TField* Field, Db::TBlobStreamMode Mode);
	virtual bool __fastcall GetCurrentRecord(char * Buffer);
	virtual bool __fastcall GetFieldData(Db::TField* Field, void * Buffer)/* overload */;
	virtual bool __fastcall GetFieldData(Db::TField* Field, void * Buffer, bool NativeFormat)/* overload */;
	virtual bool __fastcall Locate(const AnsiString KeyFields, const Variant &KeyValues, Db::TLocateOptions Options);
	virtual Variant __fastcall Lookup(const AnsiString KeyFields, const Variant &KeyValues, const AnsiString ResultFields);
	virtual Db::TUpdateStatus __fastcall UpdateStatus(void);
	virtual bool __fastcall IsSequenced(void);
	__property Ibheader::PISC_DB_HANDLE DBHandle = {read=GetDBHandle};
	__property Ibheader::PISC_TR_HANDLE TRHandle = {read=GetTRHandle};
	__property TIBDataSetUpdateObject* UpdateObject = {read=FUpdateObject, write=SetUpdateObject};
	__property bool UpdatesPending = {read=FUpdatesPending, nodefault};
	__property TIBUpdateRecordTypes UpdateRecordTypes = {read=FUpdateRecordTypes, write=SetUpdateRecordTypes, nodefault};
	__property int RowsAffected = {read=FRowsAffected, nodefault};
	__property AnsiString Plan = {read=GetPlan};
	
__published:
	__property Ibdatabase::TIBDatabase* Database = {read=GetDatabase, write=SetDatabase};
	__property Ibdatabase::TIBTransaction* Transaction = {read=GetTransaction, write=SetTransaction};
	__property bool ForcedRefresh = {read=FForcedRefresh, write=FForcedRefresh, default=0};
	__property AutoCalcFields  = {default=1};
	__property ObjectView  = {default=0};
	__property AfterCancel ;
	__property AfterClose ;
	__property AfterDelete ;
	__property AfterEdit ;
	__property AfterInsert ;
	__property AfterOpen ;
	__property AfterPost ;
	__property AfterRefresh ;
	__property AfterScroll ;
	__property BeforeCancel ;
	__property BeforeClose ;
	__property BeforeDelete ;
	__property BeforeEdit ;
	__property BeforeInsert ;
	__property BeforeOpen ;
	__property BeforePost ;
	__property BeforeRefresh ;
	__property BeforeScroll ;
	__property OnCalcFields ;
	__property OnDeleteError ;
	__property OnEditError ;
	__property OnNewRecord ;
	__property OnPostError ;
	__property TIBUpdateErrorEvent OnUpdateError = {read=FOnUpdateError, write=FOnUpdateError};
	__property TIBUpdateRecordEvent OnUpdateRecord = {read=FOnUpdateRecord, write=FOnUpdateRecord};
	
/* Hoisted overloads: */
	
public:
	inline bool __fastcall  GetFieldData(int FieldNo, void * Buffer){ return TDataSet::GetFieldData(FieldNo, Buffer); }
	
};


class DELPHICLASS TIBDataSet;
class PASCALIMPLEMENTATION TIBDataSet : public TIBCustomDataSet 
{
	typedef TIBCustomDataSet inherited;
	
private:
	bool __fastcall GetPrepared(void);
	
protected:
	virtual void __fastcall PSSetCommandText(const AnsiString CommandText);
	virtual void __fastcall SetFiltered(bool Value);
	virtual void __fastcall InternalOpen(void);
	
public:
	void __fastcall Prepare(void);
	void __fastcall UnPrepare(void);
	void __fastcall BatchInput(Ibsql::TIBBatchInput* InputObject);
	void __fastcall BatchOutput(Ibsql::TIBBatchOutput* OutputObject);
	void __fastcall ExecSQL(void);
	Ibsql::TIBXSQLVAR* __fastcall ParamByName(AnsiString Idx);
	__property Params ;
	__property bool Prepared = {read=GetPrepared, nodefault};
	__property StatementType ;
	__property SelectStmtHandle ;
	__property LiveMode ;
	
__published:
	__property BufferChunks ;
	__property CachedUpdates ;
	__property DeleteSQL ;
	__property InsertSQL ;
	__property RefreshSQL ;
	__property SelectSQL ;
	__property ModifySQL ;
	__property ParamCheck  = {default=1};
	__property UniDirectional  = {default=0};
	__property Filtered  = {default=0};
	__property GeneratorField ;
	__property BeforeDatabaseDisconnect ;
	__property AfterDatabaseDisconnect ;
	__property DatabaseFree ;
	__property BeforeTransactionEnd ;
	__property AfterTransactionEnd ;
	__property TransactionFree ;
	__property UpdateObject ;
	__property Active  = {default=0};
	__property AutoCalcFields  = {default=1};
	__property DataSource  = {read=GetDataSource, write=SetDataSource};
	__property AfterCancel ;
	__property AfterClose ;
	__property AfterDelete ;
	__property AfterEdit ;
	__property AfterInsert ;
	__property AfterOpen ;
	__property AfterPost ;
	__property AfterScroll ;
	__property BeforeCancel ;
	__property BeforeClose ;
	__property BeforeDelete ;
	__property BeforeEdit ;
	__property BeforeInsert ;
	__property BeforeOpen ;
	__property BeforePost ;
	__property BeforeScroll ;
	__property OnCalcFields ;
	__property OnDeleteError ;
	__property OnEditError ;
	__property OnFilterRecord ;
	__property OnNewRecord ;
	__property OnPostError ;
public:
	#pragma option push -w-inl
	/* TIBCustomDataSet.Create */ inline __fastcall virtual TIBDataSet(Classes::TComponent* AOwner) : TIBCustomDataSet(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIBCustomDataSet.Destroy */ inline __fastcall virtual ~TIBDataSet(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIBDSBlobStream;
class PASCALIMPLEMENTATION TIBDSBlobStream : public Classes::TStream 
{
	typedef Classes::TStream inherited;
	
protected:
	Db::TField* FField;
	Ibblob::TIBBlobStream* FBlobStream;
	bool FModified;
	
public:
	__fastcall TIBDSBlobStream(Db::TField* AField, Ibblob::TIBBlobStream* ABlobStream, Db::TBlobStreamMode Mode);
	__fastcall virtual ~TIBDSBlobStream(void);
	virtual int __fastcall Read(void *Buffer, int Count);
	virtual int __fastcall Seek(int Offset, Word Origin)/* overload */;
	virtual void __fastcall SetSize(int NewSize)/* overload */;
	virtual int __fastcall Write(const void *Buffer, int Count);
	
/* Hoisted overloads: */
	
public:
	inline __int64 __fastcall  Seek(const __int64 Offset, Classes::TSeekOrigin Origin){ return TStream::Seek(Offset, Origin); }
	
protected:
	inline void __fastcall  SetSize(const __int64 NewSize){ TStream::SetSize(NewSize); }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word BufferCacheSize = 0x3e8;
static const Shortint UniCache = 0x2;
extern PACKAGE TMetaClass*DefaultFieldClasses[38];
extern PACKAGE Db::_di_IProviderSupport __fastcall (*CreateProviderProc)(TIBCustomDataSet* DataSet);

}	/* namespace Ibcustomdataset */
using namespace Ibcustomdataset;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBCustomDataSet
