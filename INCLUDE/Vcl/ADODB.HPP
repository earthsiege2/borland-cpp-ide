// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ADODB.pas' rev: 6.00

#ifndef ADODBHPP
#define ADODBHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ADOInt.hpp>	// Pascal unit
#include <OleDB.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Adodb
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EADOError;
class PASCALIMPLEMENTATION EADOError : public Db::EDatabaseError 
{
	typedef Db::EDatabaseError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EADOError(const AnsiString Msg) : Db::EDatabaseError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EADOError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Db::EDatabaseError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EADOError(int Ident)/* overload */ : Db::EDatabaseError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EADOError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Db::EDatabaseError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EADOError(const AnsiString Msg, int AHelpContext) : Db::EDatabaseError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EADOError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Db::EDatabaseError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EADOError(int Ident, int AHelpContext)/* overload */ : Db::EDatabaseError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EADOError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Db::EDatabaseError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EADOError(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TConnectMode { cmUnknown, cmRead, cmWrite, cmReadWrite, cmShareDenyRead, cmShareDenyWrite, cmShareExclusive, cmShareDenyNone };
#pragma option pop

#pragma option push -b-
enum TConnectOption { coConnectUnspecified, coAsyncConnect };
#pragma option pop

#pragma option push -b-
enum TCursorLocation { clUseServer, clUseClient };
#pragma option pop

#pragma option push -b-
enum TCursorType { ctUnspecified, ctOpenForwardOnly, ctKeyset, ctDynamic, ctStatic };
#pragma option pop

#pragma option push -b-
enum TEventStatus { esOK, esErrorsOccured, esCantDeny, esCancel, esUnwantedEvent };
#pragma option pop

#pragma option push -b-
enum TExecuteOption { eoAsyncExecute, eoAsyncFetch, eoAsyncFetchNonBlocking, eoExecuteNoRecords };
#pragma option pop

typedef Set<TExecuteOption, eoAsyncExecute, eoExecuteNoRecords>  TExecuteOptions;

#pragma option push -b-
enum TIsolationLevel { ilUnspecified, ilChaos, ilReadUncommitted, ilBrowse, ilCursorStability, ilReadCommitted, ilRepeatableRead, ilSerializable, ilIsolated };
#pragma option pop

#pragma option push -b-
enum TADOLockType { ltUnspecified, ltReadOnly, ltPessimistic, ltOptimistic, ltBatchOptimistic };
#pragma option pop

#pragma option push -b-
enum TObjectState { stClosed, stOpen, stConnecting, stExecuting, stFetching };
#pragma option pop

typedef Set<TObjectState, stClosed, stFetching>  TObjectStates;

#pragma option push -b-
enum TSchemaInfo { siAsserts, siCatalogs, siCharacterSets, siCollations, siColumns, siCheckConstraints, siConstraintColumnUsage, siConstraintTableUsage, siKeyColumnUsage, siReferentialConstraints, siTableConstraints, siColumnsDomainUsage, siIndexes, siColumnPrivileges, siTablePrivileges, siUsagePrivileges, siProcedures, siSchemata, siSQLLanguages, siStatistics, siTables, siTranslations, siProviderTypes, siViews, siViewColumnUsage, siViewTableUsage, siProcedureParameters, siForeignKeys, siPrimaryKeys, siProcedureColumns, siDBInfoKeywords, siDBInfoLiterals, siCubes, siDimensions, siHierarchies, siLevels, siMeasures, siProperties, siMembers, siProviderSpecific };
#pragma option pop

#pragma option push -b-
enum TXactAttribute { xaCommitRetaining, xaAbortRetaining };
#pragma option pop

typedef Set<TXactAttribute, xaCommitRetaining, xaAbortRetaining>  TXactAttributes;

class DELPHICLASS TADOConnection;
typedef void __fastcall (__closure *TBeginTransCompleteEvent)(TADOConnection* Connection, int TransactionLevel, const Adoint::_di_Error Error, TEventStatus &EventStatus);

#pragma option push -b-
enum TCommandType { cmdUnknown, cmdText, cmdTable, cmdStoredProc, cmdFile, cmdTableDirect };
#pragma option pop

typedef void __fastcall (__closure *TConnectErrorEvent)(TADOConnection* Connection, const Adoint::_di_Error Error, TEventStatus &EventStatus);

typedef void __fastcall (__closure *TDisconnectEvent)(TADOConnection* Connection, TEventStatus &EventStatus);

typedef void __fastcall (__closure *TExecuteCompleteEvent)(TADOConnection* Connection, int RecordsAffected, const Adoint::_di_Error Error, TEventStatus &EventStatus, const Adoint::_di__Command Command, const Adoint::_di__Recordset Recordset);

typedef void __fastcall (__closure *TWillConnectEvent)(TADOConnection* Connection, WideString &ConnectionString, WideString &UserID, WideString &Password, TConnectOption &ConnectOptions, TEventStatus &EventStatus);

typedef void __fastcall (__closure *TWillExecuteEvent)(TADOConnection* Connection, WideString &CommandText, TCursorType &CursorType, TADOLockType &LockType, TCommandType &CommandType, TExecuteOptions &ExecuteOptions, TEventStatus &EventStatus, const Adoint::_di__Command Command, const Adoint::_di__Recordset Recordset);

typedef void __fastcall (__closure *TInfoMessageEvent)(TADOConnection* Connection, const Adoint::_di_Error Error, TEventStatus &EventStatus);

class DELPHICLASS TCustomADODataSet;
class DELPHICLASS TADOCommand;
class DELPHICLASS TADODataSet;
class PASCALIMPLEMENTATION TADOConnection : public Db::TCustomConnection 
{
	typedef Db::TCustomConnection inherited;
	
private:
	Classes::TList* FCommands;
	Adoint::_di__Connection FConnectionObject;
	int FConnEventsID;
	WideString FConnectionString;
	WideString FDefaultDatabase;
	WideString FUserID;
	WideString FPassword;
	TConnectOption FConnectOptions;
	TIsolationLevel FIsolationLevel;
	int FTransactionLevel;
	bool FKeepConnection;
	TBeginTransCompleteEvent FOnBeginTransComplete;
	TConnectErrorEvent FOnConnectComplete;
	TConnectErrorEvent FOnCommitTransComplete;
	TConnectErrorEvent FOnRollbackTransComplete;
	TDisconnectEvent FOnDisconnect;
	TInfoMessageEvent FOnInfoMessage;
	TWillConnectEvent FOnWillConnect;
	TExecuteCompleteEvent FOnExecuteComplete;
	TWillExecuteEvent FOnWillExecute;
	void __fastcall ClearRefs(void);
	bool __fastcall IsProviderStored(void);
	bool __fastcall IsDefaultDatabaseStored(void);
	TCustomADODataSet* __fastcall GetADODataSet(int Index);
	TXactAttributes __fastcall GetAttributes(void);
	TADOCommand* __fastcall GetCommand(int Index);
	int __fastcall GetCommandCount(void);
	int __fastcall GetCommandTimeout(void);
	WideString __fastcall GetConnectionString();
	int __fastcall GetConnectionTimeout(void);
	TCursorLocation __fastcall GetCursorLocation(void);
	WideString __fastcall GetDefaultDatabase();
	TIsolationLevel __fastcall GetIsolationLevel(void);
	TConnectMode __fastcall GetMode(void);
	Adoint::_di_Properties __fastcall GetProperties();
	WideString __fastcall GetProvider();
	TObjectStates __fastcall GetState(void);
	WideString __fastcall GetVersion();
	void __fastcall SetAttributes(const TXactAttributes Value);
	void __fastcall SetCommandTimeout(const int Value);
	void __fastcall SetConnectionString(const WideString Value);
	void __fastcall SetConnectionTimeout(const int Value);
	void __fastcall SetCursorLocation(const TCursorLocation Value);
	void __fastcall SetDefaultDatabase(const WideString Value);
	void __fastcall SetIsolationLevel(const TIsolationLevel Value);
	void __fastcall SetMode(const TConnectMode Value);
	void __fastcall SetProvider(const WideString Value);
	void __fastcall SetConnectOptions(const TConnectOption Value);
	bool __fastcall GetInTransaction(void);
	void __fastcall SetConnectionObject(const Adoint::_di__Connection Value);
	void __fastcall SetKeepConnection(const bool Value);
	
protected:
	_di_IConnectionPoint __fastcall ConnectionPoint();
	HRESULT __safecall InfoMessage(const Adoint::_di_Error pError, Activex::TOleEnum &adStatus, const Adoint::_di__Connection pConnection);
	HRESULT __safecall BeginTransComplete(int TransactionLevel, const Adoint::_di_Error pError, Activex::TOleEnum &adStatus, const Adoint::_di__Connection pConnection);
	HRESULT __safecall CommitTransComplete(const Adoint::_di_Error pError, Activex::TOleEnum &adStatus, const Adoint::_di__Connection pConnection);
	HRESULT __safecall RollbackTransComplete(const Adoint::_di_Error pError, Activex::TOleEnum &adStatus, const Adoint::_di__Connection pConnection);
	HRESULT __safecall WillExecute(WideString &Source, Activex::TOleEnum &CursorType, Activex::TOleEnum &LockType, int &Options, Activex::TOleEnum &adStatus, const Adoint::_di__Command pCommand, const Adoint::_di__Recordset pRecordset, const Adoint::_di__Connection pConnection);
	HRESULT __safecall ExecuteComplete(int RecordsAffected, const Adoint::_di_Error pError, Activex::TOleEnum &adStatus, const Adoint::_di__Command pCommand, const Adoint::_di__Recordset pRecordset, const Adoint::_di__Connection pConnection);
	HRESULT __safecall WillConnect(WideString &ConnectionString, WideString &UserID, WideString &Password, int &Options, Activex::TOleEnum &adStatus, const Adoint::_di__Connection pConnection);
	HRESULT __safecall ConnectComplete(const Adoint::_di_Error pError, Activex::TOleEnum &adStatus, const Adoint::_di__Connection pConnection);
	HRESULT __safecall Disconnect(Activex::TOleEnum &adStatus, const Adoint::_di__Connection pConnection);
	void __fastcall CheckActive(void);
	virtual void __fastcall CheckDisconnect(void);
	void __fastcall CheckInactive(void);
	virtual void __fastcall DoConnect(void);
	virtual void __fastcall DoDisconnect(void);
	virtual bool __fastcall GetConnected(void);
	Adoint::_di_Errors __fastcall GetErrors();
	virtual void __fastcall Loaded(void);
	virtual void __fastcall RegisterClient(System::TObject* Client, Db::TConnectChangeEvent Event = 0x0);
	virtual void __fastcall UnRegisterClient(System::TObject* Client);
	virtual void __fastcall WaitForConnectComplete(void);
	
public:
	__fastcall virtual TADOConnection(Classes::TComponent* AOwner);
	__fastcall virtual ~TADOConnection(void);
	int __fastcall BeginTrans(void);
	void __fastcall Cancel(void);
	void __fastcall CommitTrans(void);
	void __fastcall Execute(const WideString CommandText, int &RecordsAffected, const TExecuteOptions ExecuteOptions = (System::Set<TExecuteOption, eoAsyncExecute, eoExecuteNoRecords> () << TExecuteOption(3) ))/* overload */;
	Adoint::_di__Recordset __fastcall Execute(const WideString CommandText, const TCommandType CommandType = (TCommandType)(0x1), const TExecuteOptions ExecuteOptions = System::Set<TExecuteOption, eoAsyncExecute, eoExecuteNoRecords> () )/* overload */;
	void __fastcall GetProcedureNames(Classes::TStrings* List);
	void __fastcall GetFieldNames(const AnsiString TableName, Classes::TStrings* List);
	void __fastcall GetTableNames(Classes::TStrings* List, bool SystemTables = false);
	HIDESBASE void __fastcall Open(const WideString UserID, const WideString Password)/* overload */;
	void __fastcall OpenSchema(const TSchemaInfo Schema, const OleVariant &Restrictions, const OleVariant &SchemaID, TADODataSet* DataSet);
	void __fastcall RollbackTrans(void);
	__property Adoint::_di__Connection ConnectionObject = {read=FConnectionObject, write=SetConnectionObject};
	__property int CommandCount = {read=GetCommandCount, nodefault};
	__property TADOCommand* Commands[int Index] = {read=GetCommand};
	__property TCustomADODataSet* DataSets[int Index] = {read=GetADODataSet};
	__property Adoint::_di_Errors Errors = {read=GetErrors};
	__property bool InTransaction = {read=GetInTransaction, nodefault};
	__property Adoint::_di_Properties Properties = {read=GetProperties};
	__property TObjectStates State = {read=GetState, nodefault};
	__property WideString Version = {read=GetVersion};
	
__published:
	__property TXactAttributes Attributes = {read=GetAttributes, write=SetAttributes, default=0};
	__property int CommandTimeout = {read=GetCommandTimeout, write=SetCommandTimeout, default=30};
	__property Connected  = {default=0};
	__property WideString ConnectionString = {read=GetConnectionString, write=SetConnectionString};
	__property int ConnectionTimeout = {read=GetConnectionTimeout, write=SetConnectionTimeout, default=15};
	__property TConnectOption ConnectOptions = {read=FConnectOptions, write=SetConnectOptions, default=0};
	__property TCursorLocation CursorLocation = {read=GetCursorLocation, write=SetCursorLocation, default=1};
	__property WideString DefaultDatabase = {read=GetDefaultDatabase, write=SetDefaultDatabase, stored=IsDefaultDatabaseStored};
	__property TIsolationLevel IsolationLevel = {read=GetIsolationLevel, write=SetIsolationLevel, default=4};
	__property bool KeepConnection = {read=FKeepConnection, write=SetKeepConnection, default=1};
	__property LoginPrompt  = {default=1};
	__property TConnectMode Mode = {read=GetMode, write=SetMode, default=0};
	__property WideString Provider = {read=GetProvider, write=SetProvider, stored=IsProviderStored};
	__property AfterConnect ;
	__property BeforeConnect ;
	__property AfterDisconnect ;
	__property BeforeDisconnect ;
	__property TDisconnectEvent OnDisconnect = {read=FOnDisconnect, write=FOnDisconnect};
	__property TInfoMessageEvent OnInfoMessage = {read=FOnInfoMessage, write=FOnInfoMessage};
	__property TBeginTransCompleteEvent OnBeginTransComplete = {read=FOnBeginTransComplete, write=FOnBeginTransComplete};
	__property TConnectErrorEvent OnCommitTransComplete = {read=FOnCommitTransComplete, write=FOnCommitTransComplete};
	__property TConnectErrorEvent OnRollbackTransComplete = {read=FOnRollbackTransComplete, write=FOnRollbackTransComplete};
	__property TConnectErrorEvent OnConnectComplete = {read=FOnConnectComplete, write=FOnConnectComplete};
	__property TWillConnectEvent OnWillConnect = {read=FOnWillConnect, write=FOnWillConnect};
	__property TExecuteCompleteEvent OnExecuteComplete = {read=FOnExecuteComplete, write=FOnExecuteComplete};
	__property TWillExecuteEvent OnWillExecute = {read=FOnWillExecute, write=FOnWillExecute};
	__property OnLogin ;
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Open(void){ TCustomConnection::Open(); }
	
private:
	void *__ConnectionEventsVt;	/* Adoint::ConnectionEventsVt */
	
public:
	operator ConnectionEventsVt*(void) { return (ConnectionEventsVt*)&__ConnectionEventsVt; }
	operator IInterface*(void) { return (IInterface*)&__ConnectionEventsVt; }
	
};


class DELPHICLASS TRDSConnection;
class PASCALIMPLEMENTATION TRDSConnection : public Db::TCustomConnection 
{
	typedef Db::TCustomConnection inherited;
	
private:
	Adoint::_di_IDataspace FDataSpace;
	WideString FComputerName;
	WideString FServerName;
	OleVariant FAppServer;
	int FInternetTimeout;
	bool FIsAppServer;
	void __fastcall CheckInactive(void);
	void __fastcall ClearRefs(void);
	void __fastcall SetServerName(const WideString Value);
	void __fastcall SetComputerName(const WideString Value);
	
protected:
	virtual void __fastcall DoConnect(void);
	virtual void __fastcall DoDisconnect(void);
	virtual bool __fastcall GetConnected(void);
	
public:
	__fastcall virtual TRDSConnection(Classes::TComponent* AOwner);
	__fastcall virtual ~TRDSConnection(void);
	Adoint::_di__Recordset __fastcall GetRecordset(const WideString CommandText, WideString ConnectionString = L"");
	__property OleVariant AppServer = {read=FAppServer};
	__property Adoint::_di_IDataspace DataSpaceObject = {read=FDataSpace};
	
__published:
	__property WideString ComputerName = {read=FComputerName, write=SetComputerName};
	__property Connected  = {default=0};
	__property int InternetTimeout = {read=FInternetTimeout, write=FInternetTimeout, default=0};
	__property WideString ServerName = {read=FServerName, write=SetServerName, stored=FIsAppServer};
	__property AfterConnect ;
	__property AfterDisconnect ;
	__property BeforeConnect ;
	__property BeforeDisconnect ;
};


typedef Db::TFieldType TDataType;

#pragma option push -b-
enum TParameterAttribute { paSigned, paNullable, paLong };
#pragma option pop

typedef Set<TParameterAttribute, paSigned, paLong>  TParameterAttributes;

#pragma option push -b-
enum TParameterDirection { pdUnknown, pdInput, pdOutput, pdInputOutput, pdReturnValue };
#pragma option pop

class DELPHICLASS TParameter;
class DELPHICLASS TParameters;
class PASCALIMPLEMENTATION TParameter : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	Adoint::_di__Parameter FParameter;
	TParameterAttributes __fastcall GetAttributes(void);
	Db::TFieldType __fastcall GetDataType(void);
	WideString __fastcall GetName();
	Byte __fastcall GetNumericScale(void);
	Adoint::_di__Parameter __fastcall GetParameter();
	TParameterDirection __fastcall GetParameterDirection(void);
	Byte __fastcall GetPrecision(void);
	Adoint::_di_Properties __fastcall GetProperties();
	int __fastcall GetSize(void);
	Variant __fastcall GetValue();
	void __fastcall SetAttributes(const TParameterAttributes Value);
	void __fastcall SetDataType(const Db::TFieldType Value);
	void __fastcall SetName(const WideString Value);
	void __fastcall SetNumericScale(const Byte Value);
	void __fastcall SetParameterDirection(const TParameterDirection Value);
	void __fastcall SetPrecision(const Byte Value);
	void __fastcall SetSize(const int Value);
	void __fastcall SetValue(const Variant &Value);
	TParameters* __fastcall GetParameters(void);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	virtual AnsiString __fastcall GetDisplayName();
	bool __fastcall IsEqual(TParameter* Value);
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall AppendChunk(const OleVariant &Val);
	void __fastcall LoadFromFile(const AnsiString FileName, Db::TFieldType DataType);
	void __fastcall LoadFromStream(Classes::TStream* Stream, Db::TFieldType DataType);
	__property Adoint::_di__Parameter ParameterObject = {read=GetParameter};
	__property TParameters* Parameters = {read=GetParameters};
	__property Adoint::_di_Properties Properties = {read=GetProperties};
	
__published:
	__property WideString Name = {read=GetName, write=SetName};
	__property TParameterAttributes Attributes = {read=GetAttributes, write=SetAttributes, default=0};
	__property Db::TFieldType DataType = {read=GetDataType, write=SetDataType, default=0};
	__property TParameterDirection Direction = {read=GetParameterDirection, write=SetParameterDirection, default=1};
	__property Byte NumericScale = {read=GetNumericScale, write=SetNumericScale, default=0};
	__property Byte Precision = {read=GetPrecision, write=SetPrecision, default=0};
	__property int Size = {read=GetSize, write=SetSize, default=0};
	__property Variant Value = {read=GetValue, write=SetValue};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Create */ inline __fastcall virtual TParameter(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TParameter(void) { }
	#pragma option pop
	
};


typedef DynamicArray<Typinfo::PPropInfo >  TPropList;

class PASCALIMPLEMENTATION TParameters : public Classes::TOwnedCollection 
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TParameter* operator[](int Index) { return Items[Index]; }
	
private:
	bool FModified;
	TADOCommand* __fastcall GetCommand(void);
	HIDESBASE TParameter* __fastcall GetItem(int Index);
	Adoint::_di_Parameters __fastcall GetParamCollection();
	Variant __fastcall GetParamValue(const WideString ParamName);
	HIDESBASE void __fastcall SetItem(int Index, const TParameter* Value);
	void __fastcall SetParamValue(const WideString ParamName, const Variant &Value);
	
protected:
	Adoint::_di__Parameter __fastcall Create_Parameter(const WideString Name, Db::TFieldType DataType, TParameterDirection Direction = (TParameterDirection)(0x1), int Size = 0x0);
	DYNAMIC int __fastcall GetAttrCount(void);
	DYNAMIC AnsiString __fastcall GetAttr(int Index);
	DYNAMIC AnsiString __fastcall GetItemAttr(int Index, int ItemIndex);
	bool __fastcall InternalRefresh(void);
	void __fastcall AppendParameters(void);
	virtual void __fastcall Update(Classes::TCollectionItem* Item);
	__property bool Modified = {read=FModified, nodefault};
	
public:
	TParameter* __fastcall AddParameter(void);
	void __fastcall AssignValues(TParameters* Value);
	TParameter* __fastcall CreateParameter(const WideString Name, Db::TFieldType DataType, TParameterDirection Direction, int Size, const OleVariant &Value);
	TParameter* __fastcall FindParam(const WideString Value);
	void __fastcall GetParamList(Classes::TList* List, const WideString ParamNames);
	bool __fastcall IsEqual(TParameters* Value);
	TParameter* __fastcall ParamByName(const WideString Value);
	AnsiString __fastcall ParseSQL(AnsiString SQL, bool DoCreate);
	bool __fastcall Refresh(void);
	__property Variant ParamValues[WideString ParamName] = {read=GetParamValue, write=SetParamValue};
	__property TADOCommand* Command = {read=GetCommand};
	__property TParameter* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property Adoint::_di_Parameters ParameterCollection = {read=GetParamCollection};
public:
	#pragma option push -w-inl
	/* TOwnedCollection.Create */ inline __fastcall TParameters(Classes::TPersistent* AOwner, TMetaClass* ItemClass) : Classes::TOwnedCollection(AOwner, ItemClass) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TParameters(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TADOCommand : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Adoint::_di__Command FCommandObject;
	TADOConnection* FConnection;
	WideString FConnectionString;
	WideString FCommandText;
	AnsiString FCommandTextAlias;
	Classes::TComponent* FComponentRef;
	TExecuteOptions FExecuteOptions;
	TParameters* FParameters;
	System::Set<Shortint, 1, 8>  FConnectionFlags;
	bool FParamCheck;
	int __fastcall GetCommandTimeOut(void);
	TCommandType __fastcall GetCommandType(void);
	Word __fastcall GetPrepared(void);
	Adoint::_di_Properties __fastcall GetProperties();
	TObjectStates __fastcall GetState(void);
	void __fastcall SetCommandTimeOut(const int Value);
	void __fastcall SetComandType(const TCommandType Value);
	void __fastcall SetConnection(const TADOConnection* Value);
	void __fastcall SetConnectionString(const WideString Value);
	void __fastcall SetParameters(const TParameters* Value);
	void __fastcall SetPrepared(const Word Value);
	Adoint::_di__Connection __fastcall GetActiveConnection();
	
protected:
	void __fastcall AssignCommandText(const WideString Value, bool Loading = false);
	void __fastcall CheckCommandText(void);
	void __fastcall ClearActiveConnection(void);
	bool __fastcall ComponentLoading(void);
	void __fastcall ConnectionStateChange(System::TObject* Sender, bool Connecting);
	virtual void __fastcall Initialize(bool DoAppend = true);
	virtual void __fastcall OpenConnection(void);
	virtual void __fastcall SetCommandText(const WideString Value);
	virtual bool __fastcall SetConnectionFlag(int Flag, bool Value);
	__property Adoint::_di__Connection ActiveConnection = {read=GetActiveConnection};
	__property AnsiString CommandTextAlias = {read=FCommandTextAlias, write=FCommandTextAlias};
	__property Classes::TComponent* ComponentRef = {read=FComponentRef, write=FComponentRef};
	
public:
	__fastcall virtual TADOCommand(Classes::TComponent* AOwner);
	__fastcall virtual ~TADOCommand(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall Cancel(void);
	Adoint::_di__Recordset __fastcall Execute()/* overload */;
	Adoint::_di__Recordset __fastcall Execute(const OleVariant &Parameters)/* overload */;
	Adoint::_di__Recordset __fastcall Execute(int &RecordsAffected, const OleVariant &Parameters)/* overload */;
	__property Adoint::_di__Command CommandObject = {read=FCommandObject};
	__property Adoint::_di_Properties Properties = {read=GetProperties};
	__property TObjectStates States = {read=GetState, nodefault};
	
__published:
	__property WideString CommandText = {read=FCommandText, write=SetCommandText};
	__property int CommandTimeout = {read=GetCommandTimeOut, write=SetCommandTimeOut, default=30};
	__property TCommandType CommandType = {read=GetCommandType, write=SetComandType, default=1};
	__property TADOConnection* Connection = {read=FConnection, write=SetConnection};
	__property WideString ConnectionString = {read=FConnectionString, write=SetConnectionString};
	__property TExecuteOptions ExecuteOptions = {read=FExecuteOptions, write=FExecuteOptions, default=0};
	__property Word Prepared = {read=GetPrepared, write=SetPrepared, default=0};
	__property TParameters* Parameters = {read=FParameters, write=SetParameters};
	__property bool ParamCheck = {read=FParamCheck, write=FParamCheck, default=1};
};


#pragma option push -b-
enum TCursorOption { coHoldRecords, coMovePrevious, coAddNew, coDelete, coUpdate, coBookmark, coApproxPosition, coUpdateBatch, coResync, coNotify, coFind, coSeek, coIndex };
#pragma option pop

typedef Set<TCursorOption, coHoldRecords, coIndex>  TCursorOptions;

#pragma option push -b-
enum TEventReason { erAddNew, erDelete, erUpdate, erUndoUpdate, erUndoAddNew, erUndoDelete, erRequery, erResynch, erClose, erMove, erFirstChange, erMoveFirst, erMoveNext, erMovePrevious, erMoveLast };
#pragma option pop

#pragma option push -b-
enum TFilterGroup { fgUnassigned, fgNone, fgPendingRecords, fgAffectedRecords, fgFetchedRecords, fgPredicate, fgConflictingRecords };
#pragma option pop

#pragma option push -b-
enum TMarshalOption { moMarshalAll, moMarshalModifiedOnly };
#pragma option pop

#pragma option push -b-
enum TRecordStatus { rsOK, rsNew, rsModified, rsDeleted, rsUnmodified, rsInvalid, rsMultipleChanges, rsPendingChanges, rsCanceled, rsCantRelease, rsConcurrencyViolation, rsIntegrityViolation, rsMaxChangesExceeded, rsObjectOpen, rsOutOfMemory, rsPermissionDenied, rsSchemaViolation, rsDBDeleted };
#pragma option pop

typedef Set<TRecordStatus, rsOK, rsDBDeleted>  TRecordStatusSet;

#pragma option push -b-
enum TAffectRecords { arCurrent, arFiltered, arAll, arAllChapters };
#pragma option pop

#pragma option push -b-
enum TPersistFormat { pfADTG, pfXML };
#pragma option pop

#pragma option push -b-
enum TSeekOption { soFirstEQ, soLastEQ, soAfterEQ, soAfter, soBeforeEQ, soBefore };
#pragma option pop

typedef OleVariant TVariantList[1];

typedef OleVariant *PVariantList;

typedef void __fastcall (__closure *TWillChangeFieldEvent)(TCustomADODataSet* DataSet, const int FieldCount, const OleVariant &Fields, TEventStatus &EventStatus);

typedef void __fastcall (__closure *TFieldChangeCompleteEvent)(TCustomADODataSet* DataSet, const int FieldCount, const OleVariant &Fields, const Adoint::_di_Error Error, TEventStatus &EventStatus);

typedef void __fastcall (__closure *TWillChangeRecordEvent)(TCustomADODataSet* DataSet, const TEventReason Reason, const int RecordCount, TEventStatus &EventStatus);

typedef void __fastcall (__closure *TRecordChangeCompleteEvent)(TCustomADODataSet* DataSet, const TEventReason Reason, const int RecordCount, const Adoint::_di_Error Error, TEventStatus &EventStatus);

typedef void __fastcall (__closure *TEndOfRecordsetEvent)(TCustomADODataSet* DataSet, Word &MoreData, TEventStatus &EventStatus);

typedef void __fastcall (__closure *TFetchProgressEvent)(TCustomADODataSet* DataSet, int Progress, int MaxProgress, TEventStatus &EventStatus);

typedef void __fastcall (__closure *TRecordsetErrorEvent)(TCustomADODataSet* DataSet, const TEventReason Reason, const Adoint::_di_Error Error, TEventStatus &EventStatus);

typedef void __fastcall (__closure *TRecordsetReasonEvent)(TCustomADODataSet* DataSet, const TEventReason Reason, TEventStatus &EventStatus);

typedef void __fastcall (__closure *TRecordsetEvent)(TCustomADODataSet* DataSet, const Adoint::_di_Error Error, TEventStatus &EventStatus);

typedef void __fastcall (__closure *TRecordsetCreate)(TCustomADODataSet* DataSet, const Adoint::_di__Recordset Recordset);

class PASCALIMPLEMENTATION TCustomADODataSet : public Db::TDataSet 
{
	friend class TADOTable;
	friend class TADOStoredProc;
	typedef Db::TDataSet inherited;
	
private:
	Adoint::_di__Recordset FRecordsetObject;
	Adoint::_di__Recordset FFindCursor;
	Adoint::_di__Recordset FLookupCursor;
	Adoint::_di__Recordset FLockCursor;
	Oledb::_di_IRowset FRowset;
	Oledb::_di_IAccessor FAccessor;
	Oledb::_di_IRowsetFind FRowsetFind;
	unsigned FHAccessor;
	int FOleRecBufSize;
	int FEventsID;
	TADOCommand* FCommand;
	char *FFilterBuffer;
	int FRecBufSize;
	int FCacheSize;
	AnsiString FDetailFilter;
	AnsiString FIndexFieldNames;
	int FMaxRecords;
	Classes::TList* FModifiedFields;
	int FParentRecNo;
	Classes::TList* FIndexFields;
	Db::TIndexDefs* FIndexDefs;
	Db::TParams* FParams;
	AnsiString FIndexName;
	AnsiString FDesignerData;
	Db::TMasterDataLink* FMasterDataLink;
	TFilterGroup FFilterGroup;
	TCursorLocation FCursorLocation;
	TCursorType FCursorType;
	TADOLockType FLockType;
	TMarshalOption FMarshalOptions;
	TCommandType FRSCommandType;
	TCustomADODataSet* FParentDataSet;
	void *FBlockReadInfo;
	bool FStoreDefs;
	bool FEnableBCD;
	bool FConnectionChanged;
	TWillChangeFieldEvent FOnWillChangeField;
	TFieldChangeCompleteEvent FOnFieldChangeComplete;
	TWillChangeRecordEvent FOnWillChangeRecord;
	TRecordChangeCompleteEvent FOnRecordChangeComplete;
	TRecordsetReasonEvent FOnWillChangeRecordset;
	TRecordsetErrorEvent FOnRecordsetChangeComplete;
	TRecordsetReasonEvent FOnWillMove;
	TRecordsetErrorEvent FOnMoveComplete;
	TEndOfRecordsetEvent FOnEndOfRecordset;
	TRecordsetEvent FOnFetchComplete;
	TFetchProgressEvent FOnFetchProgress;
	TRecordsetCreate FOnRecordsetCreate;
	int __fastcall GetCacheSize(void);
	int __fastcall GetCommandTimeout(void);
	TCommandType __fastcall GetCommandType(void);
	TADOConnection* __fastcall GetConnection(void);
	WideString __fastcall GetConnectionString();
	TCursorLocation __fastcall GetCursorLocation(void);
	TCursorType __fastcall GetCursorType(void);
	TExecuteOptions __fastcall GetExecuteOptions(void);
	TFilterGroup __fastcall GetFilterGroup(void);
	Db::TField* __fastcall GetIndexField(int Index);
	int __fastcall GetIndexFieldCount(void);
	AnsiString __fastcall GetIndexFieldNames();
	AnsiString __fastcall GetIndexName();
	TADOLockType __fastcall GetLockType(void);
	TMarshalOption __fastcall GetMarshalOptions(void);
	AnsiString __fastcall GetMasterFields();
	int __fastcall GetMaxRecords(void);
	bool __fastcall GetParamCheck(void);
	TParameters* __fastcall GetParameters(void);
	bool __fastcall GetPrepared(void);
	Adoint::_di_Properties __fastcall GetProperties();
	TObjectStates __fastcall GetRecordsetState(void);
	TRecordStatusSet __fastcall GetRecordStatus(void);
	WideString __fastcall GetSort();
	void __fastcall PropertyChanged(void);
	void __fastcall ReadDesignerData(Classes::TReader* Reader);
	void __fastcall RefreshIndexFields(void);
	void __fastcall SetCacheSize(const int Value);
	void __fastcall SetCommandTimeout(const int Value);
	void __fastcall SetCommandType(const TCommandType Value);
	void __fastcall SetConnectionString(const WideString Value);
	void __fastcall SetCursorLocation(const TCursorLocation Value);
	void __fastcall SetCursorType(const TCursorType Value);
	void __fastcall SetExecuteOptions(const TExecuteOptions Value);
	void __fastcall SetFilterGroup(const TFilterGroup Value);
	void __fastcall SetIndexField(int Index, const Db::TField* Value);
	void __fastcall SetIndexFieldNames(const AnsiString Value);
	void __fastcall SetIndexName(const AnsiString Value);
	void __fastcall SetLockType(const TADOLockType Value);
	void __fastcall SetMarshalOptions(const TMarshalOption Value);
	void __fastcall SetMasterFields(const AnsiString Value);
	void __fastcall SetMaxRecords(const int Value);
	void __fastcall SetParamCheck(const bool Value);
	void __fastcall SetParameters(const TParameters* Value);
	void __fastcall SetRecordset(const Adoint::_di__Recordset Value);
	void __fastcall SetPrepared(const bool Value);
	void __fastcall SetSort(const WideString Value);
	void __fastcall WriteDesignerData(Classes::TWriter* Writer);
	
protected:
	virtual void __fastcall PSEndTransaction(bool Commit);
	virtual void __fastcall PSExecute(void);
	virtual int __fastcall PSExecuteStatement(const AnsiString ASQL, Db::TParams* AParams, void * ResultSet = (void *)(0x0));
	virtual void __fastcall PSGetAttributes(Classes::TList* List);
	virtual Db::TIndexDef* __fastcall PSGetDefaultOrder(void);
	virtual AnsiString __fastcall PSGetKeyFields();
	virtual Db::TParams* __fastcall PSGetParams(void);
	virtual AnsiString __fastcall PSGetQuoteChar();
	virtual AnsiString __fastcall PSGetTableName();
	virtual Db::TIndexDefs* __fastcall PSGetIndexDefs(Db::TIndexOptions IndexTypes = (System::Set<Db::TIndexOption, ixPrimary, ixNonMaintained> () << Db::TIndexOption(0) << Db::TIndexOption(1) << Db::TIndexOption(2) << Db::TIndexOption(3) << Db::TIndexOption(4) << Db::TIndexOption(5) ));
	virtual Db::EUpdateError* __fastcall PSGetUpdateException(Sysutils::Exception* E, Db::EUpdateError* Prev);
	virtual bool __fastcall PSInTransaction(void);
	virtual bool __fastcall PSIsSQLBased(void);
	virtual bool __fastcall PSIsSQLSupported(void);
	virtual void __fastcall PSReset(void);
	virtual void __fastcall PSSetParams(Db::TParams* AParams);
	virtual void __fastcall PSSetCommandText(const AnsiString CommandText);
	virtual void __fastcall PSStartTransaction(void);
	virtual bool __fastcall PSUpdateRecord(Db::TUpdateKind UpdateKind, Db::TDataSet* Delta);
	void __fastcall ActivateTextFilter(const AnsiString FilterText);
	virtual char * __fastcall AllocRecordBuffer(void);
	virtual void __fastcall CheckActive(void);
	virtual void __fastcall CheckFieldCompatibility(Db::TField* Field, Db::TFieldDef* FieldDef);
	virtual void __fastcall ClearCalcFields(char * Buffer);
	virtual void __fastcall DataEvent(Db::TDataEvent Event, int Info);
	void __fastcall DeactivateFilters(void);
	virtual void __fastcall DefChanged(System::TObject* Sender);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall DestroyLookupCursor(void);
	virtual void __fastcall DoOnNewRecord(void);
	void __fastcall EnableEvents(void);
	virtual bool __fastcall FindRecord(bool Restart, bool GoForward);
	virtual void __fastcall FreeRecordBuffer(char * &Buffer);
	bool __fastcall GetActiveRecBuf(char * &RecBuf);
	virtual void __fastcall GetBookmarkData(char * Buffer, void * Data);
	virtual Db::TBookmarkFlag __fastcall GetBookmarkFlag(char * Buffer);
	virtual bool __fastcall GetCanModify(void);
	WideString __fastcall GetCommandText();
	virtual Db::TDataSource* __fastcall GetDataSource(void);
	virtual int __fastcall GetRecNo(void);
	virtual Db::TGetResult __fastcall GetRecord(char * Buffer, Db::TGetMode GetMode, bool DoCheck);
	virtual int __fastcall GetRecordCount(void);
	virtual Word __fastcall GetRecordSize(void);
	virtual Variant __fastcall GetStateFieldValue(Db::TDataSetState State, Db::TField* Field);
	void __fastcall InitOleDBAccess(bool Initializing);
	virtual void __fastcall InternalAddRecord(void * Buffer, bool Append);
	virtual void __fastcall InternalCancel(void);
	virtual void __fastcall InternalClose(void);
	virtual void __fastcall InternalDelete(void);
	virtual void __fastcall InternalEdit(void);
	virtual void __fastcall InternalFirst(void);
	Db::TGetResult __fastcall InternalGetRecord(char * Buffer, Db::TGetMode GetMode, bool DoCheck);
	virtual void __fastcall InternalGotoBookmark(void * Bookmark);
	virtual void __fastcall InternalHandleException(void);
	virtual void __fastcall InternalInitFieldDefs(void);
	virtual void __fastcall InternalInitRecord(char * Buffer);
	virtual void __fastcall InternalInsert(void);
	virtual void __fastcall InternalLast(void);
	virtual void __fastcall InternalOpen(void);
	virtual void __fastcall InternalPost(void);
	virtual void __fastcall InternalRefresh(void);
	void __fastcall InternalRequery(TExecuteOptions Options = System::Set<TExecuteOption, eoAsyncExecute, eoExecuteNoRecords> () );
	void __fastcall InternalSetSort(WideString Value);
	virtual void __fastcall InternalSetToRecord(char * Buffer);
	virtual bool __fastcall IsCursorOpen(void);
	virtual void __fastcall Loaded(void);
	bool __fastcall LocateRecord(const AnsiString KeyFields, const OleVariant &KeyValues, Db::TLocateOptions Options, bool SyncCursor);
	virtual void __fastcall MasterChanged(System::TObject* Sender);
	virtual void __fastcall MasterDisabled(System::TObject* Sender);
	virtual void __fastcall OpenCursor(bool InfoQuery);
	virtual void __fastcall PrepareCursor(void);
	void __fastcall RefreshParams(void);
	void __fastcall ReleaseLock(void);
	virtual void __fastcall SetBlockReadSize(int Value);
	virtual void __fastcall SetBookmarkFlag(char * Buffer, Db::TBookmarkFlag Value);
	virtual void __fastcall SetBookmarkData(char * Buffer, void * Data);
	void __fastcall SetCommandText(const WideString Value);
	virtual void __fastcall SetConnection(const TADOConnection* Value);
	virtual bool __fastcall SetConnectionFlag(int Flag, bool Value);
	virtual void __fastcall SetDataSource(const Db::TDataSource* Value);
	bool __fastcall SetDetailFilter(void);
	virtual void __fastcall SetFieldData(Db::TField* Field, void * Buffer)/* overload */;
	virtual void __fastcall SetFieldData(Db::TField* Field, void * Buffer, bool NativeFormat)/* overload */;
	virtual void __fastcall SetFiltered(bool Value);
	virtual void __fastcall SetFilterOptions(Db::TFilterOptions Value);
	virtual void __fastcall SetFilterText(const AnsiString Value);
	void __fastcall SetParamsFromCursor(void);
	virtual void __fastcall SetRecNo(int Value);
	virtual void __fastcall UpdateIndexDefs(void);
	void __fastcall UpdateRecordSetPosition(char * Buffer);
	__property Db::TMasterDataLink* MasterDataLink = {read=FMasterDataLink};
	__property TADOCommand* Command = {read=FCommand};
	__property WideString CommandText = {read=GetCommandText, write=SetCommandText};
	__property int CommandTimeout = {read=GetCommandTimeout, write=SetCommandTimeout, default=30};
	__property TCommandType CommandType = {read=GetCommandType, write=SetCommandType, default=1};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property FieldDefs  = {stored=FStoreDefs};
	__property Db::TIndexDefs* IndexDefs = {read=FIndexDefs, write=FIndexDefs};
	__property AnsiString IndexFieldNames = {read=GetIndexFieldNames, write=SetIndexFieldNames};
	__property AnsiString MasterFields = {read=GetMasterFields, write=SetMasterFields};
	__property bool ParamCheck = {read=GetParamCheck, write=SetParamCheck, default=1};
	__property TParameters* Parameters = {read=GetParameters, write=SetParameters};
	__property bool Prepared = {read=GetPrepared, write=SetPrepared, default=0};
	__property bool StoreDefs = {read=FStoreDefs, write=FStoreDefs, default=0};
	_di_IConnectionPoint __fastcall ConnectionPoint();
	HRESULT __safecall WillChangeField(int cFields, const OleVariant Fields, Activex::TOleEnum &adStatus, const Adoint::_di__Recordset pRecordset);
	HRESULT __safecall FieldChangeComplete(int cFields, const OleVariant Fields, const Adoint::_di_Error pError, Activex::TOleEnum &adStatus, const Adoint::_di__Recordset pRecordset);
	HRESULT __safecall WillChangeRecord(Activex::TOleEnum adReason, int cRecords, Activex::TOleEnum &adStatus, const Adoint::_di__Recordset pRecordset);
	HRESULT __safecall RecordChangeComplete(Activex::TOleEnum adReason, int cRecords, const Adoint::_di_Error pError, Activex::TOleEnum &adStatus, const Adoint::_di__Recordset pRecordset);
	HRESULT __safecall WillChangeRecordset(Activex::TOleEnum adReason, Activex::TOleEnum &adStatus, const Adoint::_di__Recordset pRecordset);
	HRESULT __safecall RecordsetChangeComplete(Activex::TOleEnum adReason, const Adoint::_di_Error pError, Activex::TOleEnum &adStatus, const Adoint::_di__Recordset pRecordset);
	HRESULT __safecall WillMove(Activex::TOleEnum adReason, Activex::TOleEnum &adStatus, const Adoint::_di__Recordset pRecordset);
	HRESULT __safecall MoveComplete(Activex::TOleEnum adReason, const Adoint::_di_Error pError, Activex::TOleEnum &adStatus, const Adoint::_di__Recordset pRecordset);
	HRESULT __safecall EndOfRecordset(Word &fMoreData, Activex::TOleEnum &adStatus, const Adoint::_di__Recordset pRecordset);
	HRESULT __safecall FetchProgress(int Progress, int MaxProgress, Activex::TOleEnum &adStatus, const Adoint::_di__Recordset pRecordset);
	HRESULT __safecall FetchComplete(const Adoint::_di_Error pError, Activex::TOleEnum &adStatus, const Adoint::_di__Recordset pRecordset);
	
public:
	__fastcall virtual TCustomADODataSet(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomADODataSet(void);
	virtual bool __fastcall BookmarkValid(void * Bookmark);
	void __fastcall CancelBatch(TAffectRecords AffectRecords = (TAffectRecords)(0x2));
	void __fastcall CancelUpdates(void);
	void __fastcall Clone(TCustomADODataSet* Source, TADOLockType LockType = (TADOLockType)(0x0));
	virtual int __fastcall CompareBookmarks(void * Bookmark1, void * Bookmark2);
	virtual Classes::TStream* __fastcall CreateBlobStream(Db::TField* Field, Db::TBlobStreamMode Mode);
	void __fastcall DeleteRecords(TAffectRecords AffectRecords = (TAffectRecords)(0x2));
	__property bool EnableBCD = {read=FEnableBCD, write=FEnableBCD, default=1};
	void __fastcall FilterOnBookmarks(const System::TVarRec * Bookmarks, const int Bookmarks_Size);
	virtual int __fastcall GetBlobFieldData(int FieldNo, Db::TBlobByteData &Buffer);
	virtual void __fastcall GetDetailLinkFields(Classes::TList* MasterFields, Classes::TList* DetailFields);
	virtual bool __fastcall GetFieldData(Db::TField* Field, void * Buffer)/* overload */;
	virtual bool __fastcall GetFieldData(Db::TField* Field, void * Buffer, bool NativeFormat)/* overload */;
	virtual bool __fastcall GetFieldData(int FieldNo, void * Buffer)/* overload */;
	virtual bool __fastcall IsSequenced(void);
	void __fastcall LoadFromFile(const WideString FileName);
	virtual bool __fastcall Locate(const AnsiString KeyFields, const Variant &KeyValues, Db::TLocateOptions Options);
	virtual Variant __fastcall Lookup(const AnsiString KeyFields, const Variant &KeyValues, const AnsiString ResultFields);
	Adoint::_di__Recordset __fastcall NextRecordset(int &RecordsAffected);
	void __fastcall Requery(TExecuteOptions Options = System::Set<TExecuteOption, eoAsyncExecute, eoExecuteNoRecords> () );
	void __fastcall SaveToFile(const WideString FileName = L"", TPersistFormat Format = (TPersistFormat)(0x0));
	bool __fastcall Seek(const Variant &KeyValues, TSeekOption SeekOption = (TSeekOption)(0x0));
	bool __fastcall Supports(TCursorOptions CursorOptions);
	void __fastcall UpdateBatch(TAffectRecords AffectRecords = (TAffectRecords)(0x2));
	virtual Db::TUpdateStatus __fastcall UpdateStatus(void);
	__property AnsiString DesignerData = {read=FDesignerData, write=FDesignerData};
	__property AnsiString IndexName = {read=GetIndexName, write=SetIndexName};
	__property int IndexFieldCount = {read=GetIndexFieldCount, nodefault};
	__property Db::TField* IndexFields[int Index] = {read=GetIndexField, write=SetIndexField};
	__property TFilterGroup FilterGroup = {read=GetFilterGroup, write=SetFilterGroup, nodefault};
	__property Adoint::_di_Properties Properties = {read=GetProperties};
	__property Adoint::_di__Recordset Recordset = {read=FRecordsetObject, write=SetRecordset};
	__property TObjectStates RecordsetState = {read=GetRecordsetState, nodefault};
	__property TRecordStatusSet RecordStatus = {read=GetRecordStatus, nodefault};
	__property WideString Sort = {read=GetSort, write=SetSort};
	
__published:
	__property Active  = {default=0};
	__property AutoCalcFields  = {default=1};
	__property int CacheSize = {read=GetCacheSize, write=SetCacheSize, default=1};
	__property TADOConnection* Connection = {read=GetConnection, write=SetConnection};
	__property WideString ConnectionString = {read=GetConnectionString, write=SetConnectionString};
	__property TCursorLocation CursorLocation = {read=GetCursorLocation, write=SetCursorLocation, default=1};
	__property TCursorType CursorType = {read=GetCursorType, write=SetCursorType, default=2};
	__property TExecuteOptions ExecuteOptions = {read=GetExecuteOptions, write=SetExecuteOptions, default=0};
	__property Filter ;
	__property Filtered  = {default=0};
	__property TADOLockType LockType = {read=GetLockType, write=SetLockType, default=3};
	__property TMarshalOption MarshalOptions = {read=GetMarshalOptions, write=SetMarshalOptions, default=0};
	__property int MaxRecords = {read=GetMaxRecords, write=SetMaxRecords, default=0};
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
	__property TWillChangeFieldEvent OnWillChangeField = {read=FOnWillChangeField, write=FOnWillChangeField};
	__property TFieldChangeCompleteEvent OnFieldChangeComplete = {read=FOnFieldChangeComplete, write=FOnFieldChangeComplete};
	__property TWillChangeRecordEvent OnWillChangeRecord = {read=FOnWillChangeRecord, write=FOnWillChangeRecord};
	__property TRecordChangeCompleteEvent OnRecordChangeComplete = {read=FOnRecordChangeComplete, write=FOnRecordChangeComplete};
	__property TRecordsetReasonEvent OnWillChangeRecordset = {read=FOnWillChangeRecordset, write=FOnWillChangeRecordset};
	__property TRecordsetErrorEvent OnRecordsetChangeComplete = {read=FOnRecordsetChangeComplete, write=FOnRecordsetChangeComplete};
	__property TRecordsetReasonEvent OnWillMove = {read=FOnWillMove, write=FOnWillMove};
	__property TRecordsetErrorEvent OnMoveComplete = {read=FOnMoveComplete, write=FOnMoveComplete};
	__property TEndOfRecordsetEvent OnEndOfRecordset = {read=FOnEndOfRecordset, write=FOnEndOfRecordset};
	__property TRecordsetEvent OnFetchComplete = {read=FOnFetchComplete, write=FOnFetchComplete};
	__property TFetchProgressEvent OnFetchProgress = {read=FOnFetchProgress, write=FOnFetchProgress};
	__property TRecordsetCreate OnRecordsetCreate = {read=FOnRecordsetCreate, write=FOnRecordsetCreate};
private:
	void *__RecordsetEventsVt;	/* Adoint::RecordsetEventsVt */
	
public:
	operator RecordsetEventsVt*(void) { return (RecordsetEventsVt*)&__RecordsetEventsVt; }
	operator IInterface*(void) { return (IInterface*)&__RecordsetEventsVt; }
	
};


class PASCALIMPLEMENTATION TADODataSet : public TCustomADODataSet 
{
	typedef TCustomADODataSet inherited;
	
private:
	TRDSConnection* FRDSConnection;
	void __fastcall SetRDSConnection(TRDSConnection* Value);
	
protected:
	virtual void __fastcall DataEvent(Db::TDataEvent Event, int Info);
	virtual void __fastcall OpenCursor(bool InfoQuery);
	virtual void __fastcall SetConnection(const TADOConnection* Value);
	virtual void __fastcall SetDataSetField(const Db::TDataSetField* Value);
	
public:
	void __fastcall CreateDataSet(void);
	void __fastcall GetIndexNames(Classes::TStrings* List);
	__property IndexDefs ;
	
__published:
	__property CommandText ;
	__property CommandTimeout  = {default=30};
	__property CommandType  = {default=1};
	__property DataSetField ;
	__property DataSource ;
	__property EnableBCD  = {default=1};
	__property FieldDefs ;
	__property IndexName ;
	__property IndexFieldNames ;
	__property MasterFields ;
	__property ParamCheck  = {default=1};
	__property Parameters ;
	__property Prepared  = {default=0};
	__property TRDSConnection* RDSConnection = {read=FRDSConnection, write=SetRDSConnection};
	__property StoreDefs  = {default=0};
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
	__property OnCalcFields ;
	__property OnDeleteError ;
	__property OnEditError ;
	__property OnNewRecord ;
	__property OnPostError ;
public:
	#pragma option push -w-inl
	/* TCustomADODataSet.Create */ inline __fastcall virtual TADODataSet(Classes::TComponent* AOwner) : TCustomADODataSet(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomADODataSet.Destroy */ inline __fastcall virtual ~TADODataSet(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADOTable;
class PASCALIMPLEMENTATION TADOTable : public TCustomADODataSet 
{
	typedef TCustomADODataSet inherited;
	
private:
	bool __fastcall GetTableDirect(void);
	void __fastcall SetTableDirect(const bool Value);
	bool __fastcall GetReadOnly(void);
	void __fastcall SetReadOnly(const bool Value);
	
public:
	__fastcall virtual TADOTable(Classes::TComponent* AOwner);
	void __fastcall GetIndexNames(Classes::TStrings* List);
	__property IndexDefs ;
	
__published:
	__property CommandTimeout  = {default=30};
	__property EnableBCD  = {default=1};
	__property IndexFieldNames ;
	__property IndexName ;
	__property MasterFields ;
	__property Db::TDataSource* MasterSource = {read=GetDataSource, write=SetDataSource};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, stored=false, nodefault};
	__property bool TableDirect = {read=GetTableDirect, write=SetTableDirect, default=0};
	__property WideString TableName = {read=GetCommandText, write=SetCommandText};
public:
	#pragma option push -w-inl
	/* TCustomADODataSet.Destroy */ inline __fastcall virtual ~TADOTable(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADOQuery;
class PASCALIMPLEMENTATION TADOQuery : public TCustomADODataSet 
{
	typedef TCustomADODataSet inherited;
	
private:
	Classes::TStrings* FSQL;
	int FRowsAffected;
	Classes::TStrings* __fastcall GetSQL(void);
	void __fastcall SetSQL(const Classes::TStrings* Value);
	
protected:
	void __fastcall QueryChanged(System::TObject* Sender);
	
public:
	__fastcall virtual TADOQuery(Classes::TComponent* AOwner);
	__fastcall virtual ~TADOQuery(void);
	int __fastcall ExecSQL(void);
	__property int RowsAffected = {read=FRowsAffected, nodefault};
	
__published:
	__property CommandTimeout  = {default=30};
	__property DataSource ;
	__property EnableBCD  = {default=1};
	__property ParamCheck  = {default=1};
	__property Parameters ;
	__property Prepared  = {default=0};
	__property Classes::TStrings* SQL = {read=GetSQL, write=SetSQL};
};


class DELPHICLASS TADOStoredProc;
class PASCALIMPLEMENTATION TADOStoredProc : public TCustomADODataSet 
{
	typedef TCustomADODataSet inherited;
	
public:
	__fastcall virtual TADOStoredProc(Classes::TComponent* AOwner);
	void __fastcall ExecProc(void);
	
__published:
	__property CommandTimeout  = {default=30};
	__property DataSource ;
	__property EnableBCD  = {default=1};
	__property WideString ProcedureName = {read=GetCommandText, write=SetCommandText};
	__property Parameters ;
	__property Prepared  = {default=0};
public:
	#pragma option push -w-inl
	/* TCustomADODataSet.Destroy */ inline __fastcall virtual ~TADOStoredProc(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADOBlobStream;
class PASCALIMPLEMENTATION TADOBlobStream : public Classes::TMemoryStream 
{
	typedef Classes::TMemoryStream inherited;
	
private:
	Db::TBlobField* FField;
	TCustomADODataSet* FDataSet;
	char *FBuffer;
	int FFieldNo;
	bool FModified;
	Variant FData;
	Variant FFieldData;
	
protected:
	void __fastcall ReadBlobData(void);
	virtual void * __fastcall Realloc(int &NewCapacity);
	
public:
	__fastcall TADOBlobStream(Db::TBlobField* Field, Db::TBlobStreamMode Mode);
	__fastcall virtual ~TADOBlobStream(void);
	virtual int __fastcall Write(const void *Buffer, int Count);
	void __fastcall Truncate(void);
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall CreateUDLFile(const WideString FileName, const WideString ProviderName, const WideString DataSourceName);
extern PACKAGE void __fastcall GetProviderNames(Classes::TStrings* Names);
extern PACKAGE WideString __fastcall PromptDataSource(unsigned ParentHandle, WideString InitialString);
extern PACKAGE WideString __fastcall PromptDataLinkFile(unsigned ParentHandle, WideString InitialFile);
extern PACKAGE AnsiString __fastcall DataLinkDir();
extern PACKAGE int __fastcall GetDataLinkFiles(Classes::TStrings* FileNames, AnsiString Directory = "");

}	/* namespace Adodb */
using namespace Adodb;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ADODB
