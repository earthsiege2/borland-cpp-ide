// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SqlExpr.pas' rev: 6.00

#ifndef SqlExprHPP
#define SqlExprHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SqlTimSt.hpp>	// Pascal unit
#include <DBXpress.hpp>	// Pascal unit
#include <DBCommon.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Sqlexpr
{
//-- type declarations -------------------------------------------------------
typedef int TLocaleCode;

#pragma option push -b-
enum TSQLExceptionType { exceptConnection, exceptCommand, exceptCursor, exceptMetaData, exceptUseLast };
#pragma option pop

#pragma option push -b-
enum TSQLTraceFlag { traceQPREPARE, traceQEXECUTE, traceERROR, traceSTMT, traceCONNECT, traceTRANSACT, traceBLOB, traceMISC, traceVENDOR, traceDATAIN, traceDATAOUT };
#pragma option pop

typedef Set<TSQLTraceFlag, traceQPREPARE, traceDATAOUT>  TSQLTraceFlags;

class DELPHICLASS TSQLBlobStream;
class DELPHICLASS TCustomSQLDataSet;
class DELPHICLASS TSQLConnection;
#pragma option push -b-
enum TConnectionState { csStateClosed, csStateOpen, csStateConnecting, csStateExecuting, csStateFetching, csStateDisconnecting };
#pragma option pop

typedef void __fastcall (__closure *TSQLConnectionLoginEvent)(TSQLConnection* Database, Classes::TStrings* LoginParams);

#pragma option push -b-
enum TTableScope { tsSynonym, tsSysTable, tsTable, tsView };
#pragma option pop

typedef Set<TTableScope, tsSynonym, tsView>  TTableScopes;

#pragma option push -b-
enum TSchemaType { stNoSchema, stTables, stSysTables, stProcedures, stColumns, stProcedureParams, stIndexes };
#pragma option pop

#pragma option push -b-
enum EConnectFlag { eConnect, eReconnect, eDisconnect };
#pragma option pop

class PASCALIMPLEMENTATION TSQLConnection : public Db::TCustomConnection 
{
	typedef Db::TCustomConnection inherited;
	
private:
	unsigned FActiveStatements;
	bool FAutoClone;
	TSQLConnection* FCloneParent;
	TConnectionState FConnectionState;
	AnsiString FConnectionName;
	AnsiString FConnectionRegistryFile;
	AnsiString FDriverName;
	AnsiString FDriverRegistryFile;
	AnsiString FGetDriverFunc;
	int FTransactionCount;
	bool FIsCloned;
	Dbxpress::_di_ISQLConnection FISQLConnection;
	bool FKeepConnection;
	AnsiString FLastError;
	AnsiString FLibraryName;
	bool FLoadParamsOnConnect;
	Classes::TList* FMonitorUsers;
	TSQLConnectionLoginEvent FOnLogin;
	Classes::TStrings* FParams;
	bool FParamsLoaded;
	unsigned FMaxStmtsPerConn;
	AnsiString FQuoteChar;
	int FRefCount;
	unsigned FSQLDllHandle;
	Dbxpress::_di_ISQLDriver FSQLDriver;
	bool FSQLHourGlass;
	Dbxpress::_di_ISQLMetaData FSQLMetaData;
	BOOL FSupportsMultiTrans;
	TTableScopes FTableScope;
	Dbxpress::TSQLCallbackEvent FTraceCallbackEvent;
	int FTraceClientData;
	BOOL FTransactionsSupported;
	AnsiString FVendorLib;
	void __fastcall CheckActive(void);
	void __fastcall CheckInactive(void);
	void __fastcall CheckLoginParams(void);
	void __fastcall ClearConnectionUsers(void);
	void __fastcall ClearMonitors(void);
	void __fastcall FreeSchemaTable(TCustomSQLDataSet* DataSet);
	TSQLConnection* __fastcall GetConnectionForStatement(void);
	AnsiString __fastcall GetConnectionName();
	AnsiString __fastcall GetFDriverRegistryFile();
	int __fastcall GetLocaleCode(void);
	bool __fastcall GetInTransaction(void);
	AnsiString __fastcall GetLibraryName();
	void __fastcall GetLoginParams(Classes::TStrings* LoginParams);
	AnsiString __fastcall GetQuoteChar();
	AnsiString __fastcall GetVendorLib();
	void __fastcall Login(Classes::TStrings* LoginParams);
	TCustomSQLDataSet* __fastcall OpenSchemaTable(TSchemaType eKind, AnsiString SInfo, AnsiString SQualifier = "");
	void __fastcall RegisterTraceMonitor(System::TObject* Client);
	void __fastcall RegisterTraceCallback(bool Value);
	void __fastcall SetConnectionParams(void);
	void __fastcall SetConnectionName(AnsiString Value);
	void __fastcall SetDriverName(AnsiString Value);
	void __fastcall SetKeepConnection(bool Value);
	void __fastcall SetParams(Classes::TStrings* Value);
	void __fastcall SetCursor(int CursorType);
	void __fastcall SetLocaleCode(int Value);
	void __fastcall UnregisterTraceMonitor(System::TObject* Client);
	
protected:
	Word __fastcall Check(Word status);
	void __fastcall CheckConnection(EConnectFlag eFlag);
	virtual void __fastcall CheckDisconnect(void);
	virtual void __fastcall ConnectionOptions(void);
	virtual void __fastcall DoConnect(void);
	virtual void __fastcall DoDisconnect(void);
	virtual bool __fastcall GetConnected(void);
	HIDESBASE TCustomSQLDataSet* __fastcall GetDataSet(int Index);
	virtual void __fastcall Loaded(void);
	void __fastcall LoadSQLDll(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall OpenSchema(TSchemaType eKind, AnsiString sInfo, Classes::TStrings* List);
	void __fastcall SQLError(Word OpStatus, TSQLExceptionType eType, const Dbxpress::_di_ISQLCommand Command = (void *)(0x0));
	__property Dbxpress::_di_ISQLConnection Connection = {read=FISQLConnection};
	__property AnsiString ConnectionRegistryFile = {read=FConnectionRegistryFile};
	__property Dbxpress::_di_ISQLDriver Driver = {read=FSQLDriver};
	__property AnsiString DriverRegistryFile = {read=GetFDriverRegistryFile};
	__property AnsiString LastError = {read=FLastError, write=FLastError};
	__property AnsiString QuoteChar = {read=FQuoteChar};
	__property unsigned SQLDllHandle = {read=FSQLDllHandle, write=FSQLDllHandle, nodefault};
	
public:
	__fastcall virtual TSQLConnection(Classes::TComponent* AOwner);
	__fastcall virtual ~TSQLConnection(void);
	TSQLConnection* __fastcall CloneConnection(void);
	void __fastcall CloseDataSets(void);
	void __fastcall Commit(const Dbxpress::TTransactionDesc &TransDesc);
	int __fastcall Execute(const AnsiString SQL, Db::TParams* Params, void * ResultSet = (void *)(0x0));
	unsigned __fastcall ExecuteDirect(const AnsiString SQL);
	void __fastcall GetFieldNames(const AnsiString TableName, Classes::TStrings* List);
	void __fastcall GetIndexNames(const AnsiString TableName, Classes::TStrings* List);
	void __fastcall GetProcedureNames(Classes::TStrings* List);
	void __fastcall GetProcedureParams(AnsiString ProcedureName, Classes::TList* List);
	void __fastcall GetTableNames(Classes::TStrings* List, bool SystemTables = false);
	void __fastcall LoadParamsFromIniFile(AnsiString FFileName = "");
	void __fastcall Rollback(const Dbxpress::TTransactionDesc &TransDesc);
	void __fastcall SetTraceCallbackEvent(Dbxpress::TSQLCallbackEvent Event, int IClientInfo);
	void __fastcall StartTransaction(const Dbxpress::TTransactionDesc &TransDesc);
	__property unsigned ActiveStatements = {read=FActiveStatements, nodefault};
	__property bool AutoClone = {read=FAutoClone, write=FAutoClone, default=1};
	__property TConnectionState ConnectionState = {read=FConnectionState, write=FConnectionState, nodefault};
	__property TCustomSQLDataSet* DataSets[int Index] = {read=GetDataSet};
	__property bool InTransaction = {read=GetInTransaction, nodefault};
	__property int LocaleCode = {read=GetLocaleCode, write=SetLocaleCode, default=0};
	__property unsigned MaxStmtsPerConn = {read=FMaxStmtsPerConn, nodefault};
	__property Dbxpress::_di_ISQLMetaData MetaData = {read=FSQLMetaData};
	__property bool ParamsLoaded = {read=FParamsLoaded, write=FParamsLoaded, nodefault};
	__property Dbxpress::_di_ISQLConnection SQLConnection = {read=FISQLConnection, write=FISQLConnection};
	__property bool SQLHourGlass = {read=FSQLHourGlass, write=FSQLHourGlass, default=1};
	__property Dbxpress::TSQLCallbackEvent TraceCallbackEvent = {read=FTraceCallbackEvent};
	__property BOOL TransactionsSupported = {read=FTransactionsSupported, nodefault};
	
__published:
	__property Connected  = {default=0};
	__property AnsiString ConnectionName = {read=GetConnectionName, write=SetConnectionName};
	__property AnsiString DriverName = {read=FDriverName, write=SetDriverName};
	__property AnsiString GetDriverFunc = {read=FGetDriverFunc, write=FGetDriverFunc};
	__property bool KeepConnection = {read=FKeepConnection, write=SetKeepConnection, default=1};
	__property AnsiString LibraryName = {read=GetLibraryName, write=FLibraryName};
	__property bool LoadParamsOnConnect = {read=FLoadParamsOnConnect, write=FLoadParamsOnConnect, default=0};
	__property LoginPrompt  = {default=1};
	__property Classes::TStrings* Params = {read=FParams, write=SetParams};
	__property TTableScopes TableScope = {read=FTableScope, write=FTableScope, default=12};
	__property AnsiString VendorLib = {read=GetVendorLib, write=FVendorLib};
	__property AfterConnect ;
	__property AfterDisconnect ;
	__property BeforeConnect ;
	__property BeforeDisconnect ;
	__property TSQLConnectionLoginEvent OnLogin = {read=FOnLogin, write=FOnLogin};
};


#pragma option push -b-
enum TSQLCommandType { ctQuery, ctTable, ctStoredProc };
#pragma option pop

#pragma pack(push, 4)
struct TSQLSchemaInfo
{
	TSchemaType FType;
	AnsiString ObjectName;
	AnsiString Pattern;
} ;
#pragma pack(pop)

typedef DynamicArray<Dbxpress::FLDDesc >  TFieldDescList;

class PASCALIMPLEMENTATION TCustomSQLDataSet : public Db::TDataSet 
{
	typedef Db::TDataSet inherited;
	
private:
	DynamicArray<Byte >  FBlobBuffer;
	char *FCalcFieldsBuffer;
	bool FCheckRowsAffected;
	TSQLConnection* FClonedConnection;
	AnsiString FCommandText;
	TSQLCommandType FCommandType;
	unsigned FCurrentBlobSize;
	Db::TDataLink* FDataLink;
	AnsiString FDesignerData;
	char *FFieldBuffer;
	bool FGetNextRecordSet;
	Db::TIndexDefs* FIndexDefs;
	bool FIndexDefsLoaded;
	AnsiString FLastError;
	int FMaxBlobSize;
	unsigned FMaxColSize;
	AnsiString FNativeCommand;
	bool FNoMetadata;
	bool FParamCheck;
	int FParamCount;
	Db::TParams* FParams;
	bool FPrepared;
	Classes::TList* FProcParams;
	int FRecords;
	int FRowsAffected;
	TSQLSchemaInfo FSchemaInfo;
	AnsiString FSortFieldNames;
	Dbxpress::_di_ISQLCommand FSQLCommand;
	TSQLConnection* FSQLConnection;
	Dbxpress::_di_ISQLCursor FSQLCursor;
	bool FStatementOpen;
	short FTransactionLevel;
	bool __fastcall CheckFieldNames(const AnsiString FieldNames);
	void __fastcall CheckConnection(EConnectFlag eFlag);
	AnsiString __fastcall CheckDetail(AnsiString SQL);
	void __fastcall CheckStatement(bool ForSchema = false);
	bool __fastcall GetCalculatedField(Db::TField* Field, void * &Buffer);
	TCustomSQLDataSet* __fastcall GetDataSetFromSQL(AnsiString TableName);
	Classes::TList* __fastcall GetProcParams(void);
	TSQLConnection* __fastcall GetInternalConnection(void);
	virtual int __fastcall GetObjectProcParamCount(void);
	virtual int __fastcall GetParamCount(void);
	virtual AnsiString __fastcall GetQueryFromType();
	int __fastcall GetRowsAffected(void);
	void __fastcall InitBuffers(void);
	void __fastcall LoadFieldDef(Word FieldID, Dbxpress::FLDDesc &FldDesc);
	void __fastcall ReadDesignerData(Classes::TReader* Reader);
	void __fastcall RefreshParams(void);
	virtual void __fastcall SetConnection(const TSQLConnection* Value);
	void __fastcall SetCurrentBlobSize(unsigned Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetParameters(const Db::TParams* Value);
	void __fastcall SetParamsFromProcedure(void);
	void __fastcall SetParamsFromSQL(Db::TDataSet* DataSet, bool bFromFields);
	void __fastcall SetPrepared(bool Value);
	virtual void __fastcall SetCommandType(const TSQLCommandType Value);
	void __fastcall WriteDesignerData(Classes::TWriter* Writer);
	
protected:
	virtual void __fastcall PSEndTransaction(bool Commit);
	virtual void __fastcall PSExecute(void);
	virtual int __fastcall PSExecuteStatement(const AnsiString ASQL, Db::TParams* AParams, void * ResultSet = (void *)(0x0));
	virtual void __fastcall PSGetAttributes(Classes::TList* List);
	virtual Db::TIndexDef* __fastcall PSGetDefaultOrder(void);
	virtual AnsiString __fastcall PSGetKeyFields();
	virtual Db::TIndexDefs* __fastcall PSGetIndexDefs(Db::TIndexOptions IndexTypes);
	virtual Db::TParams* __fastcall PSGetParams(void);
	virtual AnsiString __fastcall PSGetQuoteChar();
	virtual AnsiString __fastcall PSGetTableName();
	virtual Db::EUpdateError* __fastcall PSGetUpdateException(Sysutils::Exception* E, Db::EUpdateError* Prev);
	virtual bool __fastcall PSInTransaction(void);
	virtual bool __fastcall PSIsSQLBased(void);
	virtual bool __fastcall PSIsSQLSupported(void);
	virtual void __fastcall PSReset(void);
	virtual void __fastcall PSSetCommandText(const AnsiString ACommandText);
	virtual void __fastcall PSSetParams(Db::TParams* AParams);
	virtual void __fastcall PSStartTransaction(void);
	virtual bool __fastcall PSUpdateRecord(Db::TUpdateKind UpdateKind, Db::TDataSet* Delta);
	virtual void __fastcall InternalClose(void);
	virtual void __fastcall InternalHandleException(void);
	virtual void __fastcall InternalInitFieldDefs(void);
	virtual void __fastcall InternalOpen(void);
	virtual bool __fastcall IsCursorOpen(void);
	void __fastcall AddFieldDesc(TFieldDescList FieldDescs, int DescNo, int &FieldID, Classes::TBits* RequiredFields, Db::TFieldDefs* FieldDefs);
	void __fastcall AddIndexDefs(TCustomSQLDataSet* SourceDS, AnsiString IndexName = "");
	Word __fastcall Check(Word status);
	void __fastcall CheckPrepareError(void);
	void __fastcall ClearIndexDefs(void);
	virtual void __fastcall CloseCursor(void);
	void __fastcall CloseStatement(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual int __fastcall ExecSQL(bool ExecDirect = false);
	void __fastcall ExecuteStatement(void);
	void __fastcall FreeCursor(void);
	void __fastcall FreeBuffers(void);
	void __fastcall FreeStatement(void);
	virtual bool __fastcall GetCanModify(void);
	virtual Db::TDataSource* __fastcall GetDataSource(void);
	void __fastcall GetObjectTypeNames(Db::TFields* Fields);
	void __fastcall GetOutputParams(Classes::TList* AProcParams);
	virtual Db::TGetResult __fastcall GetRecord(char * Buffer, Db::TGetMode GetMode, bool DoCheck);
	AnsiString __fastcall GetSortFieldNames();
	virtual void __fastcall InitRecord(char * Buffer);
	virtual void __fastcall InternalRefresh(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall OpenCursor(bool InfoQuery);
	virtual void __fastcall OpenSchema(void);
	virtual void __fastcall PrepareStatement(void);
	void __fastcall PropertyChanged(void);
	virtual void __fastcall SetBufListSize(int Value);
	virtual void __fastcall SetCommandText(const AnsiString Value);
	virtual void __fastcall SetFieldData(Db::TField* Field, void * Buffer)/* overload */;
	void __fastcall SetParamsFromCursor(void);
	void __fastcall SetSortFieldNames(AnsiString Value);
	void __fastcall SQLError(Word OpStatus, TSQLExceptionType eType);
	virtual void __fastcall UpdateIndexDefs(void);
	__property Db::TBlobByteData BlobBuffer = {read=FBlobBuffer, write=FBlobBuffer};
	__property unsigned CurrentBlobSize = {read=FCurrentBlobSize, write=SetCurrentBlobSize, nodefault};
	__property Db::TDataLink* DataLink = {read=FDataLink};
	__property TSQLConnection* InternalConnection = {read=GetInternalConnection};
	__property AnsiString LastError = {read=FLastError, write=FLastError};
	__property AnsiString NativeCommand = {read=FNativeCommand, write=FNativeCommand};
	__property Classes::TList* ProcParams = {read=GetProcParams, write=FProcParams};
	__property int RowsAffected = {read=GetRowsAffected, nodefault};
	void __fastcall SetMaxBlobSize(int MaxSize);
	void __fastcall SetFCommandText(const AnsiString Value);
	__property int ParamCount = {read=GetParamCount, nodefault};
	__property TSQLSchemaInfo SchemaInfo = {read=FSchemaInfo, write=FSchemaInfo};
	__property AnsiString CommandText = {read=FCommandText, write=SetCommandText};
	__property TSQLCommandType CommandType = {read=FCommandType, write=SetCommandType, default=0};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property int MaxBlobSize = {read=FMaxBlobSize, write=SetMaxBlobSize, default=-1};
	virtual int __fastcall GetRecordCount(void);
	__property Db::TParams* Params = {read=FParams, write=SetParameters};
	__property bool ParamCheck = {read=FParamCheck, write=FParamCheck, default=1};
	__property AnsiString SortFieldNames = {read=GetSortFieldNames, write=SetSortFieldNames};
	
public:
	__fastcall virtual TCustomSQLDataSet(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomSQLDataSet(void);
	virtual Classes::TStream* __fastcall CreateBlobStream(Db::TField* Field, Db::TBlobStreamMode Mode);
	virtual int __fastcall GetBlobFieldData(int FieldNo, Db::TBlobByteData &Buffer);
	virtual void __fastcall GetDetailLinkFields(Classes::TList* MasterFields, Classes::TList* DetailFields);
	virtual bool __fastcall GetFieldData(int FieldNo, void * Buffer)/* overload */;
	virtual bool __fastcall GetFieldData(Db::TField* Field, void * Buffer)/* overload */;
	int __fastcall GetKeyFieldNames(Classes::TStrings* List);
	virtual AnsiString __fastcall GetQuoteChar();
	Db::TParam* __fastcall ParamByName(const AnsiString Value);
	__property Db::TIndexDefs* IndexDefs = {read=FIndexDefs, write=FIndexDefs};
	virtual bool __fastcall IsSequenced(void);
	void __fastcall SetSchemaInfo(TSchemaType SchemaType, AnsiString SchemaObjectName, AnsiString SchemaPattern);
	__property bool Prepared = {read=FPrepared, write=SetPrepared, default=0};
	__property AnsiString DesignerData = {read=FDesignerData, write=FDesignerData};
	__property int RecordCount = {read=GetRecordCount, nodefault};
	__property short TransactionLevel = {read=FTransactionLevel, write=FTransactionLevel, default=0};
	
__published:
	__property Active  = {default=0};
	__property bool NoMetadata = {read=FNoMetadata, write=FNoMetadata, default=0};
	__property ObjectView  = {default=0};
	__property BeforeOpen ;
	__property AfterOpen ;
	__property BeforeClose ;
	__property AfterClose ;
	__property BeforeScroll ;
	__property AfterScroll ;
	__property BeforeRefresh ;
	__property AfterRefresh ;
	__property OnCalcFields ;
	__property TSQLConnection* SQLConnection = {read=FSQLConnection, write=SetConnection};
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetFieldData(Db::TField* Field, void * Buffer, bool NativeFormat){ TDataSet::SetFieldData(Field, Buffer, NativeFormat); }
	
public:
	inline bool __fastcall  GetFieldData(Db::TField* Field, void * Buffer, bool NativeFormat){ return TDataSet::GetFieldData(Field, Buffer, NativeFormat); }
	
};


class PASCALIMPLEMENTATION TSQLBlobStream : public Classes::TMemoryStream 
{
	typedef Classes::TMemoryStream inherited;
	
private:
	TCustomSQLDataSet* FDataSet;
	Db::TBlobField* FField;
	int FFieldNo;
	
public:
	__fastcall TSQLBlobStream(Db::TBlobField* Field, Db::TBlobStreamMode Mode);
	__fastcall virtual ~TSQLBlobStream(void);
	void __fastcall ReadBlobData(void);
};


#pragma option push -b-
enum TConnectionUserType { eUserMonitor, eUserDataSet };
#pragma option pop

struct SQLTRACEDesc;
typedef SQLTRACEDesc *pSQLTRACEDesc;

#pragma pack(push, 1)
struct SQLTRACEDesc
{
	char pszTrace[1024];
	int eTraceCat;
	int ClientData;
	Word uTotalMsgLen;
} ;
#pragma pack(pop)

typedef void __fastcall (__closure *TTraceEvent)(System::TObject* Sender, pSQLTRACEDesc CBInfo, bool &LogTrace);

typedef void __fastcall (__closure *TTraceLogEvent)(System::TObject* Sender, pSQLTRACEDesc CBInfo);

class DELPHICLASS TSQLMonitor;
class PASCALIMPLEMENTATION TSQLMonitor : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	bool FActive;
	bool FAutoSave;
	AnsiString FFileName;
	bool FKeepConnection;
	int FMaxTraceCount;
	TTraceEvent FOnTrace;
	TTraceLogEvent FOnLogTrace;
	TSQLConnection* FSQLConnection;
	bool FStreamedActive;
	TSQLTraceFlags FTraceFlags;
	Classes::TStrings* FTraceList;
	void __fastcall CheckInactive(void);
	int __fastcall GetTraceCount(void);
	
protected:
	Dbxpress::CBRType __stdcall InvokeCallBack(int CallType, void * CBInfo);
	void __fastcall SetActive(bool Value);
	void __fastcall SetSQLConnection(TSQLConnection* Value);
	void __fastcall SetStreamedActive(void);
	void __fastcall SetTraceList(Classes::TStrings* Value);
	void __fastcall SetFileName(const AnsiString Value);
	void __fastcall SwitchConnection(const TSQLConnection* Value);
	
public:
	__fastcall virtual TSQLMonitor(Classes::TComponent* AOwner);
	__fastcall virtual ~TSQLMonitor(void);
	void __fastcall LoadFromFile(AnsiString AFileName);
	void __fastcall SaveToFile(AnsiString AFileName);
	__property int MaxTraceCount = {read=FMaxTraceCount, write=FMaxTraceCount, nodefault};
	__property int TraceCount = {read=GetTraceCount, nodefault};
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property bool AutoSave = {read=FAutoSave, write=FAutoSave, default=0};
	__property AnsiString FileName = {read=FFileName, write=SetFileName};
	__property TTraceLogEvent OnLogTrace = {read=FOnLogTrace, write=FOnLogTrace};
	__property TTraceEvent OnTrace = {read=FOnTrace, write=FOnTrace};
	__property Classes::TStrings* TraceList = {read=FTraceList, write=SetTraceList, stored=false};
	__property TSQLConnection* SQLConnection = {read=FSQLConnection, write=SetSQLConnection};
};


typedef void *TLocale;

typedef void __fastcall (__closure *TLoginEvent)(System::TObject* Sender, AnsiString Username, AnsiString Password);

typedef void __fastcall (__closure *TConnectChangeEvent)(System::TObject* Sender, bool Connecting);

class DELPHICLASS TSQLDataLink;
class PASCALIMPLEMENTATION TSQLDataLink : public Db::TDetailDataLink 
{
	typedef Db::TDetailDataLink inherited;
	
private:
	TCustomSQLDataSet* FSQLDataSet;
	
protected:
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall CheckBrowseMode(void);
	virtual Db::TDataSet* __fastcall GetDetailDataSet(void);
	virtual void __fastcall RecordChanged(Db::TField* Field);
	
public:
	__fastcall TSQLDataLink(TCustomSQLDataSet* ADataSet);
public:
	#pragma option push -w-inl
	/* TDataLink.Destroy */ inline __fastcall virtual ~TSQLDataLink(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSQLDataSet;
class PASCALIMPLEMENTATION TSQLDataSet : public TCustomSQLDataSet 
{
	typedef TCustomSQLDataSet inherited;
	
public:
	__fastcall virtual TSQLDataSet(Classes::TComponent* AOwner);
	virtual int __fastcall ExecSQL(bool ExecDirect = false);
	
__published:
	__property CommandText ;
	__property CommandType  = {default=0};
	__property DataSource ;
	__property MaxBlobSize  = {default=-1};
	__property ParamCheck  = {default=1};
	__property Params ;
	__property SortFieldNames ;
public:
	#pragma option push -w-inl
	/* TCustomSQLDataSet.Destroy */ inline __fastcall virtual ~TSQLDataSet(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSQLQuery;
class PASCALIMPLEMENTATION TSQLQuery : public TCustomSQLDataSet 
{
	typedef TCustomSQLDataSet inherited;
	
private:
	Classes::TStrings* FSQL;
	AnsiString FText;
	void __fastcall QueryChanged(System::TObject* Sender);
	void __fastcall SetSQL(Classes::TStrings* Value);
	
public:
	__fastcall virtual TSQLQuery(Classes::TComponent* AOwner);
	__fastcall virtual ~TSQLQuery(void);
	virtual int __fastcall ExecSQL(bool ExecDirect = false);
	virtual void __fastcall PrepareStatement(void);
	__property RowsAffected ;
	__property AnsiString Text = {read=FText};
	
__published:
	__property DataSource ;
	__property MaxBlobSize  = {default=-1};
	__property ParamCheck  = {default=1};
	__property Params ;
	__property Classes::TStrings* SQL = {read=FSQL, write=SetSQL};
};


class DELPHICLASS TSQLStoredProc;
class PASCALIMPLEMENTATION TSQLStoredProc : public TCustomSQLDataSet 
{
	typedef TCustomSQLDataSet inherited;
	
private:
	AnsiString FStoredProcName;
	void __fastcall SetStoredProcName(AnsiString Value);
	
public:
	__fastcall virtual TSQLStoredProc(Classes::TComponent* AOwner);
	virtual int __fastcall ExecProc(void);
	TCustomSQLDataSet* __fastcall NextRecordSet(void);
	virtual void __fastcall PrepareStatement(void);
	
__published:
	__property MaxBlobSize  = {default=-1};
	__property ParamCheck  = {default=1};
	__property Params ;
	__property AnsiString StoredProcName = {read=FStoredProcName, write=SetStoredProcName};
public:
	#pragma option push -w-inl
	/* TCustomSQLDataSet.Destroy */ inline __fastcall virtual ~TSQLStoredProc(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSQLTable;
class PASCALIMPLEMENTATION TSQLTable : public TCustomSQLDataSet 
{
	typedef TCustomSQLDataSet inherited;
	
private:
	bool FIsDetail;
	Classes::TList* FIndexFields;
	AnsiString FIndexFieldNames;
	AnsiString FIndexName;
	Db::TMasterDataLink* FMasterLink;
	AnsiString FTableName;
	int FIndexFieldCount;
	void __fastcall AddParamsToQuery(void);
	AnsiString __fastcall GetMasterFields();
	Db::TField* __fastcall GetIndexField(int Index);
	int __fastcall GetIndexFieldCount(void);
	int __fastcall RefreshIndexFields(void);
	void __fastcall SetIndexFieldNames(AnsiString Value);
	void __fastcall SetIndexName(AnsiString Value);
	void __fastcall SetMasterFields(AnsiString Value);
	void __fastcall SetTableName(AnsiString Value);
	virtual AnsiString __fastcall GetQueryFromType();
	HIDESBASE void __fastcall SetDataSource(Db::TDataSource* Value);
	
protected:
	virtual void __fastcall OpenCursor(bool InfoQuery);
	void __fastcall SetIndexField(int Index, Db::TField* Value);
	__property Db::TMasterDataLink* MasterLink = {read=FMasterLink};
	
public:
	__fastcall virtual TSQLTable(Classes::TComponent* AOwner);
	__fastcall virtual ~TSQLTable(void);
	void __fastcall DeleteRecords(void);
	void __fastcall GetIndexNames(Classes::TStrings* List);
	virtual void __fastcall PrepareStatement(void);
	__property Db::TField* IndexFields[int Index] = {read=GetIndexField, write=SetIndexField};
	__property int IndexFieldCount = {read=GetIndexFieldCount, nodefault};
	
__published:
	__property Active  = {default=0};
	__property AnsiString IndexFieldNames = {read=FIndexFieldNames, write=SetIndexFieldNames};
	__property AnsiString IndexName = {read=FIndexName, write=SetIndexName};
	__property AnsiString MasterFields = {read=GetMasterFields, write=SetMasterFields};
	__property Db::TDataSource* MasterSource = {read=GetDataSource, write=SetDataSource};
	__property MaxBlobSize  = {default=-1};
	__property AnsiString TableName = {read=FTableName, write=SetTableName};
};


//-- var, const, procedure ---------------------------------------------------
#define SSelect "select"
#define SSelectStar " select * "
#define SSelectStarFrom " select * from "
#define SWhere " where "
#define SAnd " and "
#define SOrderBy " order by "
static const char SParam = '\x3f';
static const Shortint DefaultCursor = 0x0;
static const Shortint HourGlassCursor = 0xfffffff5;
static const Shortint DefaultMaxBlobSize = 0xffffffff;
static const Shortint DefaultRowsetSize = 0x14;
static const Word TErrorMessageSize = 0x800;
extern PACKAGE Byte FldTypeMap[38];
extern PACKAGE Word FldSubTypeMap[38];
extern PACKAGE Db::TFieldType DataTypeMap[26];
extern PACKAGE Db::TFieldType BlobTypeMap[15];
extern PACKAGE Word __stdcall (*GetDriver)(char * SVendorLib, char * SResourceFile, /* out */ void *Obj);
extern PACKAGE unsigned DllHandle;
extern PACKAGE HRESULT __stdcall (*DllGetClassObject)(const GUID &CLSID, const GUID &IID, void *Obj);
extern PACKAGE AnsiString __fastcall GetDriverRegistryFile(bool DesignMode = false);
extern PACKAGE AnsiString __fastcall GetConnectionRegistryFile(bool DesignMode = false);
extern PACKAGE void __fastcall GetDriverNames(Classes::TStrings* List, bool DesignMode = true);
extern PACKAGE void __fastcall GetConnectionNames(Classes::TStrings* List, AnsiString Driver = "", bool DesignMode = true);
extern PACKAGE void __fastcall FreeProcParams(Classes::TList* &ProcParams);
extern PACKAGE void __fastcall LoadParamListItems(Db::TParams* Params, Classes::TList* ProcParams);
extern PACKAGE void __fastcall RegisterDbXpressLib(void * GetClassProc);

}	/* namespace Sqlexpr */
using namespace Sqlexpr;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SqlExpr
