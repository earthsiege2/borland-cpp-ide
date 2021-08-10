// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DBTables.pas' rev: 5.00

#ifndef DBTablesHPP
#define DBTablesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SMIntf.hpp>	// Pascal unit
#include <Bde.hpp>	// Pascal unit
#include <DBCommon.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#ifdef GetObjectContext
#undef GetObjectContext
#endif

namespace Dbtables
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EDBEngineError;
class DELPHICLASS TDBError;
class PASCALIMPLEMENTATION EDBEngineError : public Db::EDatabaseError 
{
	typedef Db::EDatabaseError inherited;
	
private:
	Classes::TList* FErrors;
	TDBError* __fastcall GetError(int Index);
	int __fastcall GetErrorCount(void);
	
public:
	__fastcall EDBEngineError(Word ErrorCode);
	__fastcall virtual ~EDBEngineError(void);
	__property int ErrorCount = {read=GetErrorCount, nodefault};
	__property TDBError* Errors[int Index] = {read=GetError};
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EDBEngineError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Db::EDatabaseError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EDBEngineError(int Ident)/* overload */ : Db::EDatabaseError(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EDBEngineError(int Ident, const System::TVarRec * Args
		, const int Args_Size)/* overload */ : Db::EDatabaseError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EDBEngineError(const AnsiString Msg, int AHelpContext)
		 : Db::EDatabaseError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EDBEngineError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Db::EDatabaseError(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EDBEngineError(int Ident, int AHelpContext)/* overload */
		 : Db::EDatabaseError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EDBEngineError(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Db::EDatabaseError(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
};


class DELPHICLASS ENoResultSet;
class PASCALIMPLEMENTATION ENoResultSet : public Db::EDatabaseError 
{
	typedef Db::EDatabaseError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ENoResultSet(const AnsiString Msg) : Db::EDatabaseError(Msg
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ENoResultSet(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Db::EDatabaseError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ENoResultSet(int Ident)/* overload */ : Db::EDatabaseError(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ENoResultSet(int Ident, const System::TVarRec * Args
		, const int Args_Size)/* overload */ : Db::EDatabaseError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ENoResultSet(const AnsiString Msg, int AHelpContext) : 
		Db::EDatabaseError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ENoResultSet(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Db::EDatabaseError(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ENoResultSet(int Ident, int AHelpContext)/* overload */
		 : Db::EDatabaseError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ENoResultSet(System::PResStringRec ResStringRec, 
		const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Db::EDatabaseError(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ENoResultSet(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TDBError : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Word FErrorCode;
	int FNativeError;
	AnsiString FMessage;
	Byte __fastcall GetCategory(void);
	Byte __fastcall GetSubCode(void);
	
public:
	__fastcall TDBError(EDBEngineError* Owner, Word ErrorCode, int NativeError, char * Message);
	__property Byte Category = {read=GetCategory, nodefault};
	__property Word ErrorCode = {read=FErrorCode, nodefault};
	__property Byte SubCode = {read=GetSubCode, nodefault};
	__property AnsiString Message = {read=FMessage};
	__property int NativeError = {read=FNativeError, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TDBError(void) { }
	#pragma option pop
	
};


typedef void *TLocale;

typedef Bde::CBRType __fastcall (__closure *TBDECallbackEvent)(void * CBInfo);

class DELPHICLASS TBDECallback;
class PASCALIMPLEMENTATION TBDECallback : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Bde::_hDBIObj *FHandle;
	System::TObject* FOwner;
	Bde::CBType FCBType;
	int FOldCBData;
	void *FOldCBBuf;
	Word FOldCBBufLen;
	Bde::pfDBICallBack FOldCBFunc;
	bool FInstalled;
	TBDECallbackEvent FCallbackEvent;
	
protected:
	Bde::CBRType __fastcall Invoke(Bde::CBType CallType, void * CBInfo);
	
public:
	__fastcall TBDECallback(System::TObject* AOwner, Bde::hDBICur Handle, Bde::CBType CBType, void * CBBuf
		, int CBBufSize, TBDECallbackEvent CallbackEvent, bool Chain);
	__fastcall virtual ~TBDECallback(void);
};


class DELPHICLASS TSessionList;
class DELPHICLASS TSession;
class PASCALIMPLEMENTATION TSessionList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TThreadList* FSessions;
	Classes::TBits* FSessionNumbers;
	void __fastcall AddSession(TSession* ASession);
	void __fastcall CloseAll(void);
	int __fastcall GetCount(void);
	TSession* __fastcall GetSession(int Index);
	TSession* __fastcall GetCurrentSession(void);
	TSession* __fastcall GetSessionByName(const AnsiString SessionName);
	void __fastcall SetCurrentSession(TSession* Value);
	
public:
	__fastcall TSessionList(void);
	__fastcall virtual ~TSessionList(void);
	__property TSession* CurrentSession = {read=GetCurrentSession, write=SetCurrentSession};
	TSession* __fastcall FindSession(const AnsiString SessionName);
	void __fastcall GetSessionNames(Classes::TStrings* List);
	TSession* __fastcall OpenSession(const AnsiString SessionName);
	__property int Count = {read=GetCount, nodefault};
	__property TSession* Sessions[int Index] = {read=GetSession/*, default*/};
	__property TSession* List[AnsiString SessionName] = {read=GetSessionByName};
};


#pragma option push -b-
enum TConfigModes { cfmVirtual, cfmPersistent, cfmSession };
#pragma option pop

typedef Set<TConfigModes, cfmVirtual, cfmSession>  TConfigMode;

typedef void __fastcall (__closure *TPasswordEvent)(System::TObject* Sender, bool &Continue);

#pragma option push -b-
enum TDatabaseEvent { dbOpen, dbClose, dbAdd, dbRemove, dbAddAlias, dbDeleteAlias, dbAddDriver, dbDeleteDriver 
	};
#pragma option pop

typedef void __fastcall (__closure *TDatabaseNotifyEvent)(TDatabaseEvent DBEvent, const void *Param)
	;

typedef void __fastcall (*TBDEInitProc)(TSession* Session);

#pragma option push -b-
enum TTraceFlag { tfQPrepare, tfQExecute, tfError, tfStmt, tfConnect, tfTransact, tfBlob, tfMisc, tfVendor, 
	tfDataIn, tfDataOut };
#pragma option pop

typedef Set<TTraceFlag, tfQPrepare, tfDataOut>  TTraceFlags;

class DELPHICLASS TDatabase;
class PASCALIMPLEMENTATION TSession : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Bde::_hDBIObj *FHandle;
	Classes::TList* FDatabases;
	Classes::TList* FCallbacks;
	void *FLocale;
	Smintf::_di_ISMClient FSMClient;
	Bde::TRACEDesc *FSMBuffer;
	TTraceFlags FTraceFlags;
	bool FSMLoadFailed;
	bool FStreamedActive;
	bool FKeepConnections;
	bool FDefault;
	bool FSQLHourGlass;
	bool FAutoSessionName;
	bool FUpdatingAutoSessionName;
	bool FDLLDetach;
	bool FBDEOwnsLoginCbDb;
	AnsiString FSessionName;
	int FSessionNumber;
	AnsiString FNetFileDir;
	AnsiString FPrivateDir;
	Bde::CBSCType FCBSCType;
	int FLockCount;
	int FReserved;
	#pragma pack(push, 1)
	Bde::TCBDBLogin FCBDBLogin;
	#pragma pack(pop)
	
	TPasswordEvent FOnPassword;
	Classes::TNotifyEvent FOnStartup;
	TDatabaseNotifyEvent FOnDBNotify;
	void __fastcall AddDatabase(TDatabase* Value);
	void __fastcall CallBDEInitProcs(void);
	void __fastcall CheckInactive(void);
	void __fastcall CheckConfigMode(TConfigMode CfgMode);
	void __fastcall CloseDatabaseHandle(TDatabase* Database);
	Bde::CBRType __fastcall DBLoginCallback(void * CBInfo);
	void __fastcall DBNotification(TDatabaseEvent DBEvent, const void *Param);
	void __fastcall DeleteConfigPath(const AnsiString Path, const AnsiString Node);
	TDatabase* __fastcall DoFindDatabase(const AnsiString DatabaseName, Classes::TComponent* AOwner);
	TDatabase* __fastcall DoOpenDatabase(const AnsiString DatabaseName, Classes::TComponent* AOwner);
	Bde::hDBIDb __fastcall FindDatabaseHandle(const AnsiString DatabaseName);
	bool __fastcall GetActive(void);
	TConfigMode __fastcall GetConfigMode(void);
	TDatabase* __fastcall GetDatabase(int Index);
	int __fastcall GetDatabaseCount(void);
	Bde::hDBISes __fastcall GetHandle(void);
	AnsiString __fastcall GetNetFileDir();
	AnsiString __fastcall GetPrivateDir();
	void __fastcall InitializeBDE(void);
	void __fastcall InternalAddAlias(const AnsiString Name, const AnsiString Driver, Classes::TStrings* 
		List, TConfigMode CfgMode, bool RestoreMode);
	void __fastcall InternalDeleteAlias(const AnsiString Name, TConfigMode CfgMode, bool RestoreMode);
	bool __fastcall SessionNameStored(void);
	void __fastcall LoadSMClient(bool DesignTime);
	void __fastcall LockSession(void);
	void __fastcall MakeCurrent(void);
	void __fastcall RegisterCallbacks(bool Value);
	void __fastcall RemoveDatabase(TDatabase* Value);
	Bde::CBRType __fastcall ServerCallback(void * CBInfo);
	void __fastcall SetActive(bool Value);
	void __fastcall SetAutoSessionName(bool Value);
	void __fastcall SetConfigMode(TConfigMode Value);
	void __fastcall SetConfigParams(const AnsiString Path, const AnsiString Node, Classes::TStrings* List
		);
	void __fastcall SetNetFileDir(const AnsiString Value);
	void __fastcall SetPrivateDir(const AnsiString Value);
	void __fastcall SetSessionName(const AnsiString Value);
	void __fastcall SetSessionNames(void);
	void __fastcall SetTraceFlags(TTraceFlags Value);
	void __fastcall SMClientSignal(System::TObject* Sender, int Data);
	Bde::CBRType __fastcall SqlTraceCallback(void * CBInfo);
	void __fastcall StartSession(bool Value);
	void __fastcall UnlockSession(void);
	void __fastcall UpdateAutoSessionName(void);
	void __fastcall ValidateAutoSession(Classes::TComponent* AOwner, bool AllSessions);
	
protected:
	virtual void __fastcall Loaded(void);
	void __fastcall ModifyConfigParams(const AnsiString Path, const AnsiString Node, Classes::TStrings* 
		List);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	__property TDatabaseNotifyEvent OnDBNotify = {read=FOnDBNotify, write=FOnDBNotify};
	__property bool BDEOwnsLoginCbDb = {read=FBDEOwnsLoginCbDb, write=FBDEOwnsLoginCbDb, nodefault};
	virtual void __fastcall SetName(const AnsiString NewName);
	
public:
	__fastcall virtual TSession(Classes::TComponent* AOwner);
	__fastcall virtual ~TSession(void);
	void __fastcall AddAlias(const AnsiString Name, const AnsiString Driver, Classes::TStrings* List);
	void __fastcall AddDriver(const AnsiString Name, Classes::TStrings* List);
	void __fastcall AddStandardAlias(const AnsiString Name, const AnsiString Path, const AnsiString DefaultDriver
		);
	__property TConfigMode ConfigMode = {read=GetConfigMode, write=SetConfigMode, nodefault};
	void __fastcall AddPassword(const AnsiString Password);
	void __fastcall Close(void);
	void __fastcall CloseDatabase(TDatabase* Database);
	void __fastcall DeleteAlias(const AnsiString Name);
	void __fastcall DeleteDriver(const AnsiString Name);
	void __fastcall DropConnections(void);
	TDatabase* __fastcall FindDatabase(const AnsiString DatabaseName);
	void __fastcall GetAliasNames(Classes::TStrings* List);
	void __fastcall GetAliasParams(const AnsiString AliasName, Classes::TStrings* List);
	AnsiString __fastcall GetAliasDriverName(const AnsiString AliasName);
	void __fastcall GetConfigParams(const AnsiString Path, const AnsiString Section, Classes::TStrings* 
		List);
	void __fastcall GetDatabaseNames(Classes::TStrings* List);
	void __fastcall GetDriverNames(Classes::TStrings* List);
	void __fastcall GetDriverParams(const AnsiString DriverName, Classes::TStrings* List);
	bool __fastcall GetPassword(void);
	void __fastcall GetTableNames(const AnsiString DatabaseName, const AnsiString Pattern, bool Extensions
		, bool SystemTables, Classes::TStrings* List);
	void __fastcall GetStoredProcNames(const AnsiString DatabaseName, Classes::TStrings* List);
	bool __fastcall IsAlias(const AnsiString Name);
	void __fastcall ModifyAlias(AnsiString Name, Classes::TStrings* List);
	void __fastcall ModifyDriver(AnsiString Name, Classes::TStrings* List);
	void __fastcall Open(void);
	TDatabase* __fastcall OpenDatabase(const AnsiString DatabaseName);
	void __fastcall RemoveAllPasswords(void);
	void __fastcall RemovePassword(const AnsiString Password);
	void __fastcall SaveConfigFile(void);
	__property int DatabaseCount = {read=GetDatabaseCount, nodefault};
	__property TDatabase* Databases[int Index] = {read=GetDatabase};
	__property Bde::hDBISes Handle = {read=GetHandle};
	__property void * Locale = {read=FLocale};
	__property TTraceFlags TraceFlags = {read=FTraceFlags, write=SetTraceFlags, nodefault};
	
__published:
	__property bool Active = {read=GetActive, write=SetActive, default=0};
	__property bool AutoSessionName = {read=FAutoSessionName, write=SetAutoSessionName, default=0};
	__property bool KeepConnections = {read=FKeepConnections, write=FKeepConnections, default=1};
	__property AnsiString NetFileDir = {read=GetNetFileDir, write=SetNetFileDir};
	__property AnsiString PrivateDir = {read=GetPrivateDir, write=SetPrivateDir};
	__property AnsiString SessionName = {read=FSessionName, write=SetSessionName, stored=SessionNameStored
		};
	__property bool SQLHourGlass = {read=FSQLHourGlass, write=FSQLHourGlass, default=1};
	__property TPasswordEvent OnPassword = {read=FOnPassword, write=FOnPassword};
	__property Classes::TNotifyEvent OnStartup = {read=FOnStartup, write=FOnStartup};
};


typedef DynamicArray<Bde::FLDDesc >  TFieldDescList;

class DELPHICLASS TParamList;
class PASCALIMPLEMENTATION TParamList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int FFieldCount;
	DynamicArray<Bde::FLDDesc >  FFieldDescs;
	char *FBuffer;
	Word FBufSize;
	
public:
	__fastcall TParamList(Classes::TStrings* Params);
	__fastcall virtual ~TParamList(void);
	__property char * Buffer = {read=FBuffer};
	__property int FieldCount = {read=FFieldCount, nodefault};
	__property TFieldDescList FieldDescs = {read=FFieldDescs};
};


#pragma option push -b-
enum TTransIsolation { tiDirtyRead, tiReadCommitted, tiRepeatableRead };
#pragma option pop

typedef void __fastcall (__closure *TDatabaseLoginEvent)(TDatabase* Database, Classes::TStrings* LoginParams
	);

class DELPHICLASS TDBDataSet;
class PASCALIMPLEMENTATION TDatabase : public Db::TCustomConnection 
{
	typedef Db::TCustomConnection inherited;
	
private:
	TTransIsolation FTransIsolation;
	bool FKeepConnection;
	bool FTemporary;
	bool FSessionAlias;
	bool FLocaleLoaded;
	bool FAliased;
	bool FSQLBased;
	bool FAcquiredHandle;
	bool FPseudoIndexes;
	bool FHandleShared;
	bool FExclusive;
	bool FReadOnly;
	int FRefCount;
	Bde::_hDBIObj *FHandle;
	void *FLocale;
	TSession* FSession;
	Classes::TStrings* FParams;
	Classes::TList* FStmtList;
	AnsiString FSessionName;
	AnsiString FDatabaseName;
	AnsiString FDatabaseType;
	TDatabaseLoginEvent FOnLogin;
	void __fastcall CheckActive(void);
	void __fastcall CheckInactive(void);
	void __fastcall CheckDatabaseName(void);
	void __fastcall CheckDatabaseAlias(AnsiString &Password);
	void __fastcall CheckSessionName(bool Required);
	void __fastcall ClearStatements(void);
	void __fastcall EndTransaction(Bde::eXEnd TransEnd);
	AnsiString __fastcall GetAliasName();
	AnsiString __fastcall GetDirectory();
	AnsiString __fastcall GetDriverName();
	bool __fastcall GetInTransaction(void);
	_di_IUnknown __fastcall GetObjectContext();
	TTraceFlags __fastcall GetTraceFlags(void);
	void __fastcall LoadLocale(void);
	void __fastcall Login(Classes::TStrings* LoginParams);
	bool __fastcall OpenFromExistingDB(void);
	void __fastcall ParamsChanging(System::TObject* Sender);
	void __fastcall SetAliasName(const AnsiString Value);
	void __fastcall SetDatabaseFlags(void);
	void __fastcall SetDatabaseName(const AnsiString Value);
	void __fastcall SetDatabaseType(const AnsiString Value, bool Aliased);
	void __fastcall SetDirectory(const AnsiString Value);
	void __fastcall SetDriverName(const AnsiString Value);
	void __fastcall SetExclusive(bool Value);
	void __fastcall SetHandle(Bde::hDBIDb Value);
	void __fastcall SetKeepConnection(bool Value);
	void __fastcall SetParams(Classes::TStrings* Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall SetTraceFlags(TTraceFlags Value);
	void __fastcall SetSessionName(const AnsiString Value);
	
protected:
	virtual void __fastcall DoConnect(void);
	virtual void __fastcall DoDisconnect(void);
	virtual bool __fastcall GetConnected(void);
	HIDESBASE TDBDataSet* __fastcall GetDataSet(int Index);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	
public:
	__fastcall virtual TDatabase(Classes::TComponent* AOwner);
	__fastcall virtual ~TDatabase(void);
	void __fastcall ApplyUpdates(TDBDataSet* const * DataSets, const int DataSets_Size);
	void __fastcall CloseDataSets(void);
	void __fastcall Commit(void);
	int __fastcall Execute(const AnsiString SQL, Db::TParams* Params, bool Cache, Bde::phDBICur Cursor)
		;
	void __fastcall FlushSchemaCache(const AnsiString TableName);
	void __fastcall Rollback(void);
	void __fastcall StartTransaction(void);
	void __fastcall ValidateName(const AnsiString Name);
	__property TDBDataSet* DataSets[int Index] = {read=GetDataSet};
	__property AnsiString Directory = {read=GetDirectory, write=SetDirectory};
	__property Bde::hDBIDb Handle = {read=FHandle, write=SetHandle};
	__property bool IsSQLBased = {read=FSQLBased, nodefault};
	__property bool InTransaction = {read=GetInTransaction, nodefault};
	__property void * Locale = {read=FLocale};
	__property TSession* Session = {read=FSession};
	__property bool Temporary = {read=FTemporary, write=FTemporary, nodefault};
	__property bool SessionAlias = {read=FSessionAlias, nodefault};
	__property TTraceFlags TraceFlags = {read=GetTraceFlags, write=SetTraceFlags, nodefault};
	
__published:
	__property AnsiString AliasName = {read=GetAliasName, write=SetAliasName};
	__property Connected ;
	__property AnsiString DatabaseName = {read=FDatabaseName, write=SetDatabaseName};
	__property AnsiString DriverName = {read=GetDriverName, write=SetDriverName};
	__property bool Exclusive = {read=FExclusive, write=SetExclusive, default=0};
	__property bool HandleShared = {read=FHandleShared, write=FHandleShared, default=0};
	__property bool KeepConnection = {read=FKeepConnection, write=SetKeepConnection, default=1};
	__property LoginPrompt ;
	__property Classes::TStrings* Params = {read=FParams, write=SetParams};
	__property bool ReadOnly = {read=FReadOnly, write=SetReadOnly, default=0};
	__property AnsiString SessionName = {read=FSessionName, write=SetSessionName};
	__property TTransIsolation TransIsolation = {read=FTransIsolation, write=FTransIsolation, default=1
		};
	__property AfterConnect ;
	__property AfterDisconnect ;
	__property BeforeConnect ;
	__property BeforeDisconnect ;
	__property TDatabaseLoginEvent OnLogin = {read=FOnLogin, write=FOnLogin};
};


#pragma option push -b-
enum TRecNoStatus { rnDbase, rnParadox, rnNotSupported };
#pragma option pop

class DELPHICLASS TDataSetUpdateObject;
class DELPHICLASS TBDEDataSet;
class PASCALIMPLEMENTATION TDataSetUpdateObject : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
protected:
	virtual TBDEDataSet* __fastcall GetDataSet(void) = 0 ;
	virtual void __fastcall SetDataSet(TBDEDataSet* ADataSet) = 0 ;
	virtual void __fastcall Apply(Db::TUpdateKind UpdateKind) = 0 ;
	__property TBDEDataSet* DataSet = {read=GetDataSet, write=SetDataSet};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TDataSetUpdateObject(Classes::TComponent* AOwner)
		 : Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TDataSetUpdateObject(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSQLUpdateObject;
class PASCALIMPLEMENTATION TSQLUpdateObject : public TDataSetUpdateObject 
{
	typedef TDataSetUpdateObject inherited;
	
protected:
	virtual Classes::TStrings* __fastcall GetSQL(Db::TUpdateKind UpdateKind) = 0 ;
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TSQLUpdateObject(Classes::TComponent* AOwner) : TDataSetUpdateObject(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TSQLUpdateObject(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TKeyIndex { kiLookup, kiRangeStart, kiRangeEnd, kiCurRangeStart, kiCurRangeEnd, kiSave };
#pragma option pop

struct TKeyBuffer;
typedef TKeyBuffer *PKeyBuffer;

#pragma pack(push, 1)
struct TKeyBuffer
{
	bool Modified;
	bool Exclusive;
	int FieldCount;
} ;
#pragma pack(pop)

struct TRecInfo;
typedef TRecInfo *PRecInfo;

#pragma pack(push, 1)
struct TRecInfo
{
	int RecordNumber;
	Db::TUpdateStatus UpdateStatus;
	Db::TBookmarkFlag BookmarkFlag;
} ;
#pragma pack(pop)

typedef DynamicArray<AnsiString >  TBlobDataArray;

class PASCALIMPLEMENTATION TBDEDataSet : public Db::TDataSet 
{
	typedef Db::TDataSet inherited;
	
/*private:*/protected:
	Bde::_hDBIObj *FHandle;
	Bde::_hDBIObj *FStmtHandle;
	#pragma pack(push, 1)
	Bde::RECProps FRecProps;
	#pragma pack(pop)
	
	void *FLocale;
	Bde::_hDBIObj *FExprFilter;
	Bde::_hDBIObj *FFuncFilter;
	char *FFilterBuffer;
	Word FIndexFieldMap[16];
	bool FExpIndex;
	bool FCaseInsIndex;
	bool FCachedUpdates;
	bool FInUpdateCallback;
	bool FCanModify;
	bool FCacheBlobs;
	Word FKeySize;
	Bde::DELAYUPDCbDesc *FUpdateCBBuf;
	TBDECallback* FUpdateCallback;
	TKeyBuffer *FKeyBuffers[6];
	TKeyBuffer *FKeyBuffer;
	TRecNoStatus FRecNoStatus;
	int FIndexFieldCount;
	int FConstDisableCount;
	Word FRecordSize;
	Word FBookmarkOfs;
	Word FRecInfoOfs;
	Word FBlobCacheOfs;
	Word FRecBufSize;
	bool FConstraintLayer;
	int FBlockBufSize;
	int FBlockBufOfs;
	int FBlockBufCount;
	int FBlockReadCount;
	int FLastParentPos;
	char *FBlockReadBuf;
	TBDEDataSet* FParentDataSet;
	TDataSetUpdateObject* FUpdateObject;
	Db::TUpdateErrorEvent FOnUpdateError;
	Db::TUpdateRecordEvent FOnUpdateRecord;
	void __fastcall ClearBlobCache(char * Buffer);
	bool __fastcall GetActiveRecBuf(char * &RecBuf);
	AnsiString __fastcall GetBlobData(Db::TField* Field, char * Buffer);
	char * __fastcall GetOldRecord(void);
	void __fastcall InitBufferPointers(bool GetProps);
	short __stdcall RecordFilter(void * RecBuf, int RecNo);
	void __fastcall SetBlobData(Db::TField* Field, char * Buffer, AnsiString Value);
	bool __fastcall HasConstraints(void);
	
protected:
	virtual Db::EUpdateError* __fastcall PSGetUpdateException(Sysutils::Exception* E, Db::EUpdateError* 
		Prev);
	virtual bool __fastcall PSIsSQLSupported(void);
	virtual void __fastcall PSReset(void);
	virtual bool __fastcall PSUpdateRecord(Db::TUpdateKind UpdateKind, Db::TDataSet* Delta);
	void __fastcall ActivateFilters(void);
	void __fastcall AddFieldDesc(TFieldDescList FieldDescs, int &DescNo, int &FieldID, Classes::TBits* 
		RequiredFields, Db::TFieldDefs* FieldDefs);
	void __fastcall AllocCachedUpdateBuffers(bool Allocate);
	void __fastcall AllocKeyBuffers(void);
	virtual char * __fastcall AllocRecordBuffer(void);
	Bde::CBRType __fastcall CachedUpdateCallBack(void * CBInfo);
	void __fastcall CheckCachedUpdateMode(void);
	void __fastcall CheckSetKeyMode(void);
	virtual void __fastcall ClearCalcFields(char * Buffer);
	virtual void __fastcall CloseCursor(void);
	virtual void __fastcall CloseBlob(Db::TField* Field);
	Bde::hDBIFilter __fastcall CreateExprFilter(const AnsiString Expr, Db::TFilterOptions Options, int 
		Priority);
	Bde::hDBIFilter __fastcall CreateFuncFilter(void * FilterFunc, int Priority);
	virtual Bde::hDBICur __fastcall CreateHandle(void);
	Bde::hDBIFilter __fastcall CreateLookupFilter(Classes::TList* Fields, const Variant &Values, Db::TLocateOptions 
		Options, int Priority);
	virtual void __fastcall DataEvent(Db::TDataEvent Event, int Info);
	void __fastcall DeactivateFilters(void);
	virtual void __fastcall DestroyHandle(void);
	virtual void __fastcall DestroyLookupCursor(void);
	virtual bool __fastcall FindRecord(bool Restart, bool GoForward);
	bool __fastcall ForceUpdateCallback(void);
	void __fastcall FreeKeyBuffers(void);
	virtual void __fastcall FreeRecordBuffer(char * &Buffer);
	virtual void __fastcall GetBookmarkData(char * Buffer, void * Data);
	virtual Db::TBookmarkFlag __fastcall GetBookmarkFlag(char * Buffer);
	virtual bool __fastcall GetCanModify(void);
	virtual AnsiString __fastcall GetFieldFullName(Db::TField* Field);
	Db::TField* __fastcall GetIndexField(int Index);
	int __fastcall GetIndexFieldCount(void);
	virtual bool __fastcall GetIsIndexField(Db::TField* Field);
	PKeyBuffer __fastcall GetKeyBuffer(TKeyIndex KeyIndex);
	bool __fastcall GetKeyExclusive(void);
	int __fastcall GetKeyFieldCount(void);
	virtual Bde::hDBICur __fastcall GetLookupCursor(const AnsiString KeyFields, bool CaseInsensitive);
	virtual Db::TGetResult __fastcall GetRecord(char * Buffer, Db::TGetMode GetMode, bool DoCheck);
	virtual int __fastcall GetRecordCount(void);
	virtual int __fastcall GetRecNo(void);
	virtual Word __fastcall GetRecordSize(void);
	virtual Variant __fastcall GetStateFieldValue(Db::TDataSetState State, Db::TField* Field);
	void __fastcall GetObjectTypeNames(Db::TFields* Fields);
	bool __fastcall GetUpdatesPending(void);
	Db::TUpdateRecordTypes __fastcall GetUpdateRecordSet(void);
	PKeyBuffer __fastcall InitKeyBuffer(PKeyBuffer Buffer);
	virtual void __fastcall InitRecord(char * Buffer);
	virtual void __fastcall InternalAddRecord(void * Buffer, bool Append);
	virtual void __fastcall InternalCancel(void);
	virtual void __fastcall InternalClose(void);
	virtual void __fastcall InternalDelete(void);
	virtual void __fastcall InternalEdit(void);
	virtual void __fastcall InternalFirst(void);
	virtual void __fastcall InternalGotoBookmark(void * Bookmark);
	virtual void __fastcall InternalHandleException(void);
	virtual void __fastcall InternalInitFieldDefs(void);
	virtual void __fastcall InternalInitRecord(char * Buffer);
	virtual void __fastcall InternalInsert(void);
	virtual void __fastcall InternalLast(void);
	virtual void __fastcall InternalOpen(void);
	virtual void __fastcall InternalPost(void);
	virtual void __fastcall InternalRefresh(void);
	virtual void __fastcall InternalSetToRecord(char * Buffer);
	virtual bool __fastcall IsCursorOpen(void);
	bool __fastcall LocateRecord(const AnsiString KeyFields, const Variant &KeyValues, Db::TLocateOptions 
		Options, bool SyncCursor);
	bool __fastcall MapsToIndex(Classes::TList* Fields, bool CaseInsensitive);
	virtual void __fastcall OpenCursor(bool InfoQuery);
	void __fastcall PostKeyBuffer(bool Commit);
	virtual void __fastcall PrepareCursor(void);
	Word __fastcall ProcessUpdates(Bde::DBIDelayedUpdCmd UpdCmd);
	bool __fastcall ResetCursorRange(void);
	virtual void __fastcall BlockReadNext(void);
	virtual void __fastcall SetBookmarkData(char * Buffer, void * Data);
	virtual void __fastcall SetBookmarkFlag(char * Buffer, Db::TBookmarkFlag Value);
	void __fastcall SetCachedUpdates(bool Value);
	bool __fastcall SetCursorRange(void);
	virtual void __fastcall SetBlockReadSize(int Value);
	virtual void __fastcall SetFieldData(Db::TField* Field, void * Buffer)/* overload */;
	void __fastcall SetFilterData(const AnsiString Text, Db::TFilterOptions Options);
	void __fastcall SetFilterHandle(Bde::hDBIFilter &Filter, Bde::hDBIFilter Value);
	virtual void __fastcall SetFiltered(bool Value);
	virtual void __fastcall SetFilterOptions(Db::TFilterOptions Value);
	virtual void __fastcall SetFilterText(const AnsiString Value);
	void __fastcall SetIndexField(int Index, Db::TField* Value);
	void __fastcall SetKeyBuffer(TKeyIndex KeyIndex, bool Clear);
	void __fastcall SetKeyExclusive(bool Value);
	void __fastcall SetKeyFieldCount(int Value);
	void __fastcall SetKeyFields(TKeyIndex KeyIndex, const System::TVarRec * Values, const int Values_Size
		);
	void __fastcall SetLinkRanges(Classes::TList* MasterFields);
	void __fastcall SetLocale(void * Value);
	virtual void __fastcall SetStateFieldValue(Db::TDataSetState State, Db::TField* Field, const Variant 
		&Value);
	virtual void __fastcall SetOnFilterRecord(const Db::TFilterRecordEvent Value);
	void __fastcall SetOnUpdateError(Db::TUpdateErrorEvent UpdateEvent);
	virtual void __fastcall SetRecNo(int Value);
	void __fastcall SetupCallBack(bool Value);
	void __fastcall SetUpdateRecordSet(Db::TUpdateRecordTypes RecordTypes);
	void __fastcall SetUpdateObject(TDataSetUpdateObject* Value);
	void __fastcall SwitchToIndex(const AnsiString IndexName, const AnsiString TagName);
	bool __fastcall UpdateCallbackRequired(void);
	__property Bde::hDBIStmt StmtHandle = {read=FStmtHandle, write=FStmtHandle};
	
public:
	__fastcall virtual TBDEDataSet(Classes::TComponent* AOwner);
	__fastcall virtual ~TBDEDataSet(void);
	void __fastcall ApplyUpdates(void);
	virtual bool __fastcall BookmarkValid(void * Bookmark);
	virtual void __fastcall Cancel(void);
	void __fastcall CancelUpdates(void);
	__property bool CacheBlobs = {read=FCacheBlobs, write=FCacheBlobs, default=1};
	virtual int __fastcall CompareBookmarks(void * Bookmark1, void * Bookmark2);
	void __fastcall CommitUpdates(void);
	Word __stdcall ConstraintCallBack(Bde::DsInfoReq Req, Bde::DataSources &ADataSources);
	bool __fastcall ConstraintsDisabled(void);
	virtual Classes::TStream* __fastcall CreateBlobStream(Db::TField* Field, Db::TBlobStreamMode Mode);
		
	void __fastcall DisableConstraints(void);
	void __fastcall EnableConstraints(void);
	void __fastcall FetchAll(void);
	void __fastcall FlushBuffers(void);
	virtual bool __fastcall GetCurrentRecord(char * Buffer);
	virtual int __fastcall GetBlobFieldData(int FieldNo, Db::TBlobByteData &Buffer);
	virtual bool __fastcall GetFieldData(Db::TField* Field, void * Buffer)/* overload */;
	virtual bool __fastcall GetFieldData(int FieldNo, void * Buffer)/* overload */;
	void __fastcall GetIndexInfo(void);
	virtual bool __fastcall Locate(const AnsiString KeyFields, const Variant &KeyValues, Db::TLocateOptions 
		Options);
	virtual Variant __fastcall Lookup(const AnsiString KeyFields, const Variant &KeyValues, const AnsiString 
		ResultFields);
	virtual bool __fastcall IsSequenced(void);
	virtual void __fastcall Post(void);
	void __fastcall RevertRecord(void);
	virtual Db::TUpdateStatus __fastcall UpdateStatus(void);
	virtual int __fastcall Translate(char * Src, char * Dest, bool ToOem);
	__property bool ExpIndex = {read=FExpIndex, nodefault};
	__property Bde::hDBICur Handle = {read=FHandle};
	__property Word KeySize = {read=FKeySize, nodefault};
	__property void * Locale = {read=FLocale};
	__property TDataSetUpdateObject* UpdateObject = {read=FUpdateObject, write=SetUpdateObject};
	__property bool UpdatesPending = {read=GetUpdatesPending, nodefault};
	__property Db::TUpdateRecordTypes UpdateRecordTypes = {read=GetUpdateRecordSet, write=SetUpdateRecordSet
		, nodefault};
	
__published:
	__property Active ;
	__property AutoCalcFields ;
	__property bool CachedUpdates = {read=FCachedUpdates, write=SetCachedUpdates, default=0};
	__property ObjectView ;
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
	__property OnNewRecord ;
	__property OnPostError ;
	__property Db::TUpdateErrorEvent OnUpdateError = {read=FOnUpdateError, write=SetOnUpdateError};
	__property Db::TUpdateRecordEvent OnUpdateRecord = {read=FOnUpdateRecord, write=FOnUpdateRecord};
};


class DELPHICLASS TNestedTable;
class PASCALIMPLEMENTATION TNestedTable : public TBDEDataSet 
{
	typedef TBDEDataSet inherited;
	
protected:
	virtual Bde::hDBICur __fastcall CreateHandle(void);
	virtual void __fastcall DoAfterPost(void);
	virtual void __fastcall DoBeforeInsert(void);
	virtual void __fastcall InternalPost(void);
	
public:
	__fastcall virtual TNestedTable(Classes::TComponent* AOwner);
	
__published:
	__property DataSetField ;
	__property ObjectView ;
public:
	#pragma option push -w-inl
	/* TBDEDataSet.Destroy */ inline __fastcall virtual ~TNestedTable(void) { }
	#pragma option pop
	
};


typedef Set<Shortint, 0, 15>  TDBFlags;

class PASCALIMPLEMENTATION TDBDataSet : public TBDEDataSet 
{
	typedef TBDEDataSet inherited;
	
/*private:*/protected:
	bool FAutoRefresh;
	TDBFlags FDBFlags;
	Db::TUpdateMode FUpdateMode;
	TDatabase* FDatabase;
	AnsiString FDatabaseName;
	AnsiString FSessionName;
	void __fastcall CheckDBSessionName(void);
	Bde::hDBIDb __fastcall GetDBHandle(void);
	void * __fastcall GetDBLocale(void);
	TSession* __fastcall GetDBSession(void);
	void __fastcall SetDatabaseName(const AnsiString Value);
	void __fastcall SetSessionName(const AnsiString Value);
	void __fastcall SetUpdateMode(const Db::TUpdateMode Value);
	void __fastcall SetAutoRefresh(const bool Value);
	void __fastcall SetupAutoRefresh(void);
	
protected:
	virtual void __fastcall PSEndTransaction(bool Commit);
	virtual int __fastcall PSExecuteStatement(const AnsiString ASQL, Db::TParams* AParams, void * ResultSet
		);
	virtual void __fastcall PSGetAttributes(Classes::TList* List);
	virtual AnsiString __fastcall PSGetQuoteChar();
	virtual bool __fastcall PSInTransaction(void);
	virtual bool __fastcall PSIsSQLBased(void);
	virtual void __fastcall PSStartTransaction(void);
	virtual bool __fastcall PSUpdateRecord(Db::TUpdateKind UpdateKind, Db::TDataSet* Delta);
	virtual void __fastcall CloseCursor(void);
	bool __fastcall ConstraintsStored(void);
	virtual void __fastcall Disconnect(void);
	virtual void __fastcall OpenCursor(bool InfoQuery);
	virtual bool __fastcall SetDBFlag(int Flag, bool Value);
	void __fastcall SetHandle(Bde::hDBICur Value);
	__property TDBFlags DBFlags = {read=FDBFlags, nodefault};
	__property Db::TUpdateMode UpdateMode = {read=FUpdateMode, write=SetUpdateMode, default=0};
	
public:
	__fastcall virtual TDBDataSet(Classes::TComponent* AOwner);
	bool __fastcall CheckOpen(Word Status);
	void __fastcall CloseDatabase(TDatabase* Database);
	TDatabase* __fastcall OpenDatabase(void);
	__property TDatabase* Database = {read=FDatabase};
	__property Bde::hDBIDb DBHandle = {read=GetDBHandle};
	__property void * DBLocale = {read=GetDBLocale};
	__property TSession* DBSession = {read=GetDBSession};
	__property Bde::hDBICur Handle = {read=FHandle, write=SetHandle};
	
__published:
	__property bool AutoRefresh = {read=FAutoRefresh, write=SetAutoRefresh, default=0};
	__property AnsiString DatabaseName = {read=FDatabaseName, write=SetDatabaseName};
	__property Filter ;
	__property Filtered ;
	__property FilterOptions ;
	__property AnsiString SessionName = {read=FSessionName, write=SetSessionName};
	__property OnFilterRecord ;
public:
	#pragma option push -w-inl
	/* TBDEDataSet.Destroy */ inline __fastcall virtual ~TDBDataSet(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TBatchMode { batAppend, batUpdate, batAppendUpdate, batDelete, batCopy };
#pragma option pop

#pragma option push -b-
enum TTableType { ttDefault, ttParadox, ttDBase, ttFoxPro, ttASCII };
#pragma option pop

#pragma option push -b-
enum TLockType { ltReadLock, ltWriteLock };
#pragma option pop

typedef AnsiString TIndexName;

typedef DynamicArray<Bde::IDXDesc >  TIndexDescList;

typedef DynamicArray<Bde::VCHKDesc >  TValCheckList;

class DELPHICLASS TIndexFiles;
class DELPHICLASS TTable;
class PASCALIMPLEMENTATION TTable : public TDBDataSet 
{
	typedef TDBDataSet inherited;
	
private:
	bool FStoreDefs;
	Db::TIndexDefs* FIndexDefs;
	Db::TMasterDataLink* FMasterLink;
	bool FDefaultIndex;
	bool FExclusive;
	bool FReadOnly;
	TTableType FTableType;
	bool FFieldsIndex;
	AnsiString FTableName;
	AnsiString FIndexName;
	Classes::TStrings* FIndexFiles;
	Bde::_hDBIObj *FLookupHandle;
	AnsiString FLookupKeyFields;
	int FTableLevel;
	bool FLookupCaseIns;
	char FNativeTableName[261];
	void __fastcall CheckMasterRange(void);
	void __fastcall DecodeIndexDesc(const Bde::IDXDesc &IndexDesc, AnsiString &Source, AnsiString &Name
		, AnsiString &FieldExpression, AnsiString &DescFields, Db::TIndexOptions &Options);
	bool __fastcall FieldDefsStored(void);
	char * __fastcall GetDriverTypeName(char * Buffer);
	bool __fastcall GetExists(void);
	AnsiString __fastcall GetIndexFieldNames();
	AnsiString __fastcall GetIndexName();
	void __fastcall GetIndexParams(const AnsiString IndexName, bool FieldsIndex, AnsiString &IndexedName
		, AnsiString &IndexTag);
	AnsiString __fastcall GetMasterFields();
	char * __fastcall GetTableTypeName(void);
	int __fastcall GetTableLevel(void);
	bool __fastcall IndexDefsStored(void);
	bool __fastcall IsXBaseTable(void);
	void __fastcall MasterChanged(System::TObject* Sender);
	void __fastcall MasterDisabled(System::TObject* Sender);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetExclusive(bool Value);
	void __fastcall SetIndexDefs(Db::TIndexDefs* Value);
	void __fastcall SetIndex(const AnsiString Value, bool FieldsIndex);
	void __fastcall SetIndexFieldNames(const AnsiString Value);
	void __fastcall SetIndexFiles(Classes::TStrings* Value);
	void __fastcall SetIndexName(const AnsiString Value);
	void __fastcall SetMasterFields(const AnsiString Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall SetTableLock(TLockType LockType, bool Lock);
	void __fastcall SetTableName(const AnsiString Value);
	void __fastcall SetTableType(TTableType Value);
	void * __fastcall SetTempLocale(bool ActiveCheck);
	void __fastcall RestoreLocale(void * LocaleSave);
	void __fastcall UpdateRange(void);
	
protected:
	virtual Db::TIndexDef* __fastcall PSGetDefaultOrder(void);
	virtual AnsiString __fastcall PSGetKeyFields();
	virtual AnsiString __fastcall PSGetTableName();
	virtual Db::TIndexDefs* __fastcall PSGetIndexDefs(Db::TIndexOptions IndexTypes);
	virtual void __fastcall PSSetCommandText(const AnsiString CommandText);
	virtual void __fastcall PSSetParams(Db::TParams* AParams);
	virtual Bde::hDBICur __fastcall CreateHandle(void);
	virtual void __fastcall DataEvent(Db::TDataEvent Event, int Info);
	virtual void __fastcall DefChanged(System::TObject* Sender);
	virtual void __fastcall DestroyHandle(void);
	virtual void __fastcall DestroyLookupCursor(void);
	virtual void __fastcall DoOnNewRecord(void);
	void __fastcall EncodeFieldDesc(Bde::FLDDesc &FieldDesc, const AnsiString Name, Db::TFieldType DataType
		, int Size, int Precision);
	void __fastcall EncodeIndexDesc(Bde::IDXDesc &IndexDesc, const AnsiString Name, const AnsiString FieldExpression
		, Db::TIndexOptions Options, const AnsiString DescFields);
	virtual bool __fastcall GetCanModify(void);
	virtual Db::TDataSource* __fastcall GetDataSource(void);
	Bde::hDBICur __fastcall GetHandle(const AnsiString IndexName, const AnsiString IndexTag);
	AnsiString __fastcall GetLanguageDriverName();
	virtual Bde::hDBICur __fastcall GetLookupCursor(const AnsiString KeyFields, bool CaseInsensitive);
	virtual void __fastcall InitFieldDefs(void);
	AnsiString __fastcall GetFileName();
	TTableType __fastcall GetTableType(void);
	bool __fastcall IsProductionIndex(const AnsiString IndexName);
	char * __fastcall NativeTableName(void);
	virtual void __fastcall PrepareCursor(void);
	virtual void __fastcall UpdateIndexDefs(void);
	__property Db::TMasterDataLink* MasterLink = {read=FMasterLink};
	
public:
	__fastcall virtual TTable(Classes::TComponent* AOwner);
	__fastcall virtual ~TTable(void);
	int __fastcall BatchMove(TBDEDataSet* ASource, TBatchMode AMode);
	void __fastcall AddIndex(const AnsiString Name, const AnsiString Fields, Db::TIndexOptions Options, 
		const AnsiString DescFields);
	void __fastcall ApplyRange(void);
	void __fastcall CancelRange(void);
	void __fastcall CloseIndexFile(const AnsiString IndexFileName);
	void __fastcall CreateTable(void);
	void __fastcall DeleteIndex(const AnsiString Name);
	void __fastcall DeleteTable(void);
	void __fastcall EditKey(void);
	void __fastcall EditRangeEnd(void);
	void __fastcall EditRangeStart(void);
	void __fastcall EmptyTable(void);
	bool __fastcall FindKey(const System::TVarRec * KeyValues, const int KeyValues_Size);
	void __fastcall FindNearest(const System::TVarRec * KeyValues, const int KeyValues_Size);
	virtual void __fastcall GetDetailLinkFields(Classes::TList* MasterFields, Classes::TList* DetailFields
		);
	void __fastcall GetIndexNames(Classes::TStrings* List);
	void __fastcall GotoCurrent(TTable* Table);
	bool __fastcall GotoKey(void);
	void __fastcall GotoNearest(void);
	void __fastcall LockTable(TLockType LockType);
	void __fastcall OpenIndexFile(const AnsiString IndexName);
	void __fastcall RenameTable(const AnsiString NewTableName);
	void __fastcall SetKey(void);
	void __fastcall SetRange(const System::TVarRec * StartValues, const int StartValues_Size, const System::TVarRec 
		* EndValues, const int EndValues_Size);
	void __fastcall SetRangeEnd(void);
	void __fastcall SetRangeStart(void);
	void __fastcall UnlockTable(TLockType LockType);
	__property bool Exists = {read=GetExists, nodefault};
	__property Bde::hDBICur Handle = {read=FHandle};
	__property int IndexFieldCount = {read=GetIndexFieldCount, nodefault};
	__property Db::TField* IndexFields[int Index] = {read=GetIndexField, write=SetIndexField};
	__property bool KeyExclusive = {read=GetKeyExclusive, write=SetKeyExclusive, nodefault};
	__property int KeyFieldCount = {read=GetKeyFieldCount, write=SetKeyFieldCount, nodefault};
	__property int TableLevel = {read=GetTableLevel, write=FTableLevel, nodefault};
	
__published:
	__property Constraints  = {stored=ConstraintsStored};
	__property bool DefaultIndex = {read=FDefaultIndex, write=FDefaultIndex, default=1};
	__property bool Exclusive = {read=FExclusive, write=SetExclusive, default=0};
	__property FieldDefs  = {stored=FieldDefsStored};
	__property Db::TIndexDefs* IndexDefs = {read=FIndexDefs, write=SetIndexDefs, stored=IndexDefsStored
		};
	__property AnsiString IndexFieldNames = {read=GetIndexFieldNames, write=SetIndexFieldNames};
	__property Classes::TStrings* IndexFiles = {read=FIndexFiles, write=SetIndexFiles};
	__property AnsiString IndexName = {read=GetIndexName, write=SetIndexName};
	__property AnsiString MasterFields = {read=GetMasterFields, write=SetMasterFields};
	__property Db::TDataSource* MasterSource = {read=GetDataSource, write=SetDataSource};
	__property bool ReadOnly = {read=FReadOnly, write=SetReadOnly, default=0};
	__property bool StoreDefs = {read=FStoreDefs, write=FStoreDefs, default=0};
	__property AnsiString TableName = {read=FTableName, write=SetTableName};
	__property TTableType TableType = {read=FTableType, write=SetTableType, default=0};
	__property UpdateMode ;
	__property UpdateObject ;
};


class PASCALIMPLEMENTATION TIndexFiles : public Classes::TStringList 
{
	typedef Classes::TStringList inherited;
	
private:
	TTable* FOwner;
	
public:
	__fastcall TIndexFiles(TTable* AOwner);
	virtual int __fastcall Add(const AnsiString S);
	virtual void __fastcall Clear(void);
	virtual void __fastcall Delete(int Index);
	virtual void __fastcall Insert(int Index, const AnsiString S);
public:
	#pragma option push -w-inl
	/* TStringList.Destroy */ inline __fastcall virtual ~TIndexFiles(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBatchMove;
class PASCALIMPLEMENTATION TBatchMove : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TTable* FDestination;
	TBDEDataSet* FSource;
	TBatchMode FMode;
	bool FAbortOnKeyViol;
	bool FAbortOnProblem;
	bool FTransliterate;
	int FRecordCount;
	int FMovedCount;
	int FKeyViolCount;
	int FProblemCount;
	int FChangedCount;
	Classes::TStrings* FMappings;
	AnsiString FKeyViolTableName;
	AnsiString FProblemTableName;
	AnsiString FChangedTableName;
	int FCommitCount;
	char * __fastcall ConvertName(const AnsiString Name, char * Buffer);
	void __fastcall SetMappings(Classes::TStrings* Value);
	void __fastcall SetSource(TBDEDataSet* Value);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	
public:
	__fastcall virtual TBatchMove(Classes::TComponent* AOwner);
	__fastcall virtual ~TBatchMove(void);
	void __fastcall Execute(void);
	__property int ChangedCount = {read=FChangedCount, nodefault};
	__property int KeyViolCount = {read=FKeyViolCount, nodefault};
	__property int MovedCount = {read=FMovedCount, nodefault};
	__property int ProblemCount = {read=FProblemCount, nodefault};
	
__published:
	__property bool AbortOnKeyViol = {read=FAbortOnKeyViol, write=FAbortOnKeyViol, default=1};
	__property bool AbortOnProblem = {read=FAbortOnProblem, write=FAbortOnProblem, default=1};
	__property int CommitCount = {read=FCommitCount, write=FCommitCount, default=0};
	__property AnsiString ChangedTableName = {read=FChangedTableName, write=FChangedTableName};
	__property TTable* Destination = {read=FDestination, write=FDestination};
	__property AnsiString KeyViolTableName = {read=FKeyViolTableName, write=FKeyViolTableName};
	__property Classes::TStrings* Mappings = {read=FMappings, write=SetMappings};
	__property TBatchMode Mode = {read=FMode, write=FMode, default=0};
	__property AnsiString ProblemTableName = {read=FProblemTableName, write=FProblemTableName};
	__property int RecordCount = {read=FRecordCount, write=FRecordCount, default=0};
	__property TBDEDataSet* Source = {read=FSource, write=SetSource};
	__property bool Transliterate = {read=FTransliterate, write=FTransliterate, default=1};
};


#pragma option push -b-
enum TParamBindMode { pbByName, pbByNumber };
#pragma option pop

#pragma pack(push, 1)
struct TServerDesc
{
	System::SmallString<64>  ParamName;
	Db::TFieldType BindType;
} ;
#pragma pack(pop)

typedef DynamicArray<TServerDesc >  TServerDescList;

typedef DynamicArray<Bde::SPParamDesc >  TSPParamDescList;

typedef DynamicArray<char >  DBTables__81;

class DELPHICLASS TStoredProc;
class PASCALIMPLEMENTATION TStoredProc : public TDBDataSet 
{
	typedef TDBDataSet inherited;
	
private:
	AnsiString FProcName;
	Db::TParams* FParams;
	DynamicArray<Bde::SPParamDesc >  FParamDescs;
	DynamicArray<TServerDesc >  FServerDescs;
	DynamicArray<char >  FRecordBuffer;
	Word FOverLoad;
	bool FPrepared;
	bool FQueryMode;
	TParamBindMode FBindMode;
	void __fastcall BindParams(void);
	bool __fastcall CheckServerParams(void);
	Bde::hDBICur __fastcall CreateCursor(bool GenHandle);
	void __fastcall CreateParamDesc(void);
	void __fastcall FreeStatement(void);
	Bde::hDBICur __fastcall GetCursor(bool GenHandle);
	void __fastcall PrepareProc(void);
	void __fastcall ReadParamData(Classes::TReader* Reader);
	void __fastcall SetParamsList(Db::TParams* Value);
	void __fastcall SetServerParams(void);
	void __fastcall WriteParamData(Classes::TWriter* Writer);
	
protected:
	virtual void __fastcall PSExecute(void);
	virtual AnsiString __fastcall PSGetTableName();
	virtual Db::TParams* __fastcall PSGetParams(void);
	virtual void __fastcall PSSetCommandText(const AnsiString CommandText);
	virtual void __fastcall PSSetParams(Db::TParams* AParams);
	virtual Bde::hDBICur __fastcall CreateHandle(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall Disconnect(void);
	Word __fastcall GetParamsCount(void);
	virtual bool __fastcall SetDBFlag(int Flag, bool Value);
	void __fastcall SetOverLoad(Word Value);
	void __fastcall SetProcName(const AnsiString Value);
	void __fastcall SetPrepared(bool Value);
	void __fastcall SetPrepare(bool Value);
	
public:
	__fastcall virtual TStoredProc(Classes::TComponent* AOwner);
	__fastcall virtual ~TStoredProc(void);
	void __fastcall CopyParams(Db::TParams* Value);
	bool __fastcall DescriptionsAvailable(void);
	void __fastcall ExecProc(void);
	Db::TParam* __fastcall ParamByName(const AnsiString Value);
	void __fastcall Prepare(void);
	void __fastcall GetResults(void);
	void __fastcall UnPrepare(void);
	__property Bde::hDBICur Handle = {read=FHandle};
	__property Word ParamCount = {read=GetParamsCount, nodefault};
	__property StmtHandle ;
	__property bool Prepared = {read=FPrepared, write=SetPrepare, nodefault};
	
__published:
	__property AnsiString StoredProcName = {read=FProcName, write=SetProcName};
	__property Word Overload = {read=FOverLoad, write=SetOverLoad, default=0};
	__property Db::TParams* Params = {read=FParams, write=SetParamsList, stored=false};
	__property TParamBindMode ParamBindMode = {read=FBindMode, write=FBindMode, default=0};
	__property UpdateObject ;
};


class DELPHICLASS TQuery;
class PASCALIMPLEMENTATION TQuery : public TDBDataSet 
{
	typedef TDBDataSet inherited;
	
private:
	Classes::TStrings* FSQL;
	bool FPrepared;
	Db::TParams* FParams;
	AnsiString FText;
	Db::TDataLink* FDataLink;
	bool FLocal;
	int FRowsAffected;
	bool FUniDirectional;
	bool FRequestLive;
	char *FSQLBinary;
	bool FConstrained;
	bool FParamCheck;
	bool FExecSQL;
	bool FCheckRowsAffected;
	Bde::hDBICur __fastcall CreateCursor(bool GenHandle);
	Bde::hDBICur __fastcall GetQueryCursor(bool GenHandle);
	int __fastcall GetRowsAffected(void);
	void __fastcall PrepareSQL(char * Value);
	void __fastcall QueryChanged(System::TObject* Sender);
	void __fastcall ReadBinaryData(Classes::TStream* Stream);
	void __fastcall ReadParamData(Classes::TReader* Reader);
	void __fastcall RefreshParams(void);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetQuery(Classes::TStrings* Value);
	void __fastcall SetParamsList(Db::TParams* Value);
	void __fastcall SetParamsFromCursor(void);
	void __fastcall SetPrepared(bool Value);
	void __fastcall SetPrepare(bool Value);
	void __fastcall WriteBinaryData(Classes::TStream* Stream);
	void __fastcall WriteParamData(Classes::TWriter* Writer);
	
protected:
	virtual void __fastcall PSExecute(void);
	virtual Db::TIndexDef* __fastcall PSGetDefaultOrder(void);
	virtual Db::TParams* __fastcall PSGetParams(void);
	virtual AnsiString __fastcall PSGetTableName();
	virtual void __fastcall PSSetCommandText(const AnsiString CommandText);
	virtual void __fastcall PSSetParams(Db::TParams* AParams);
	virtual Bde::hDBICur __fastcall CreateHandle(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall Disconnect(void);
	virtual void __fastcall FreeStatement(void);
	virtual Db::TDataSource* __fastcall GetDataSource(void);
	Word __fastcall GetParamsCount(void);
	virtual bool __fastcall SetDBFlag(int Flag, bool Value);
	virtual void __fastcall GetStatementHandle(char * SQLText);
	__property Db::TDataLink* DataLink = {read=FDataLink};
	
public:
	__fastcall virtual TQuery(Classes::TComponent* AOwner);
	__fastcall virtual ~TQuery(void);
	void __fastcall ExecSQL(void);
	virtual void __fastcall GetDetailLinkFields(Classes::TList* MasterFields, Classes::TList* DetailFields
		);
	Db::TParam* __fastcall ParamByName(const AnsiString Value);
	void __fastcall Prepare(void);
	void __fastcall UnPrepare(void);
	__property Bde::hDBICur Handle = {read=FHandle};
	__property bool Prepared = {read=FPrepared, write=SetPrepare, nodefault};
	__property Word ParamCount = {read=GetParamsCount, nodefault};
	__property bool Local = {read=FLocal, nodefault};
	__property StmtHandle ;
	__property AnsiString Text = {read=FText};
	__property int RowsAffected = {read=GetRowsAffected, nodefault};
	__property char * SQLBinary = {read=FSQLBinary, write=FSQLBinary};
	
__published:
	__property bool Constrained = {read=FConstrained, write=FConstrained, default=0};
	__property Constraints  = {stored=ConstraintsStored};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property bool ParamCheck = {read=FParamCheck, write=FParamCheck, default=1};
	__property bool RequestLive = {read=FRequestLive, write=FRequestLive, default=0};
	__property Classes::TStrings* SQL = {read=FSQL, write=SetQuery};
	__property Db::TParams* Params = {read=FParams, write=SetParamsList, stored=false};
	__property bool UniDirectional = {read=FUniDirectional, write=FUniDirectional, default=0};
	__property UpdateMode ;
	__property UpdateObject ;
};


class DELPHICLASS TUpdateSQL;
class PASCALIMPLEMENTATION TUpdateSQL : public TSQLUpdateObject 
{
	typedef TSQLUpdateObject inherited;
	
private:
	TBDEDataSet* FDataSet;
	TQuery* FQueries[3];
	Classes::TStrings* FSQLText[3];
	TQuery* __fastcall GetQuery(Db::TUpdateKind UpdateKind);
	Classes::TStrings* __fastcall GetSQLIndex(int Index);
	void __fastcall SetSQL(Db::TUpdateKind UpdateKind, Classes::TStrings* Value);
	void __fastcall SetSQLIndex(int Index, Classes::TStrings* Value);
	
protected:
	virtual Classes::TStrings* __fastcall GetSQL(Db::TUpdateKind UpdateKind);
	virtual TBDEDataSet* __fastcall GetDataSet(void);
	virtual void __fastcall SetDataSet(TBDEDataSet* ADataSet);
	void __fastcall SQLChanged(System::TObject* Sender);
	
public:
	__fastcall virtual TUpdateSQL(Classes::TComponent* AOwner);
	__fastcall virtual ~TUpdateSQL(void);
	virtual void __fastcall Apply(Db::TUpdateKind UpdateKind);
	void __fastcall ExecSQL(Db::TUpdateKind UpdateKind);
	void __fastcall SetParams(Db::TUpdateKind UpdateKind);
	__property DataSet ;
	__property TQuery* Query[Db::TUpdateKind UpdateKind] = {read=GetQuery};
	__property Classes::TStrings* SQL[Db::TUpdateKind UpdateKind] = {read=GetSQL, write=SetSQL};
	
__published:
	__property Classes::TStrings* ModifySQL = {read=GetSQLIndex, write=SetSQLIndex, index=0};
	__property Classes::TStrings* InsertSQL = {read=GetSQLIndex, write=SetSQLIndex, index=1};
	__property Classes::TStrings* DeleteSQL = {read=GetSQLIndex, write=SetSQLIndex, index=2};
};


class DELPHICLASS TBlobStream;
class PASCALIMPLEMENTATION TBlobStream : public Classes::TStream 
{
	typedef Classes::TStream inherited;
	
private:
	Db::TBlobField* FField;
	TBDEDataSet* FDataSet;
	char *FBuffer;
	Db::TBlobStreamMode FMode;
	int FFieldNo;
	bool FOpened;
	bool FModified;
	int FPosition;
	AnsiString FBlobData;
	bool FCached;
	int FCacheSize;
	int __fastcall GetBlobSize(void);
	
public:
	__fastcall TBlobStream(Db::TBlobField* Field, Db::TBlobStreamMode Mode);
	__fastcall virtual ~TBlobStream(void);
	virtual int __fastcall Read(void *Buffer, int Count);
	virtual int __fastcall Write(const void *Buffer, int Count);
	virtual int __fastcall Seek(int Offset, Word Origin);
	void __fastcall Truncate(void);
};


//-- var, const, procedure ---------------------------------------------------
static const Word smTraceBufSize = 0x8006;
static const Shortint dbfOpened = 0x0;
static const Shortint dbfPrepared = 0x1;
static const Shortint dbfExecSQL = 0x2;
static const Shortint dbfTable = 0x3;
static const Shortint dbfFieldList = 0x4;
static const Shortint dbfIndexList = 0x5;
static const Shortint dbfStoredProc = 0x6;
static const Shortint dbfExecProc = 0x7;
static const Shortint dbfProcDesc = 0x8;
static const Shortint dbfDatabase = 0x9;
static const Shortint dbfProvider = 0xa;
extern PACKAGE Byte FldTypeMap[36];
extern PACKAGE Word FldSubTypeMap[36];
extern PACKAGE Db::TFieldType DataTypeMap[24];
extern PACKAGE Db::TFieldType BlobTypeMap[15];
#define cmVirtual (System::Set<TConfigModes, cfmVirtual, cfmSession> () )
#define cmPersistent (System::Set<TConfigModes, cfmVirtual, cfmSession> () )
#define cmSession (System::Set<TConfigModes, cfmVirtual, cfmSession> () )
#define cmAll (System::Set<TConfigModes, cfmVirtual, cfmSession> () )
extern PACKAGE TSession* Session;
extern PACKAGE TSessionList* Sessions;
extern PACKAGE _di_IUnknown __fastcall (*GetObjectContextProc)(void);
extern PACKAGE void __fastcall RegisterBDEInitProc(const TBDEInitProc InitProc);
extern PACKAGE bool __fastcall GetFieldSource(Db::TDataSet* ADataSet, Bde::DataSources &ADataSources
	);
extern PACKAGE char * __fastcall AnsiToNative(void * Locale, const AnsiString AnsiStr, char * NativeStr
	, int MaxLen);
extern PACKAGE void __fastcall NativeToAnsi(void * Locale, char * NativeStr, AnsiString &AnsiStr);
extern PACKAGE void __fastcall AnsiToNativeBuf(void * Locale, char * Source, char * Dest, int Len);
extern PACKAGE void __fastcall NativeToAnsiBuf(void * Locale, char * Source, char * Dest, int Len);
extern PACKAGE int __fastcall NativeCompareStr(void * Locale, const AnsiString S1, const AnsiString 
	S2, int Len);
extern PACKAGE int __fastcall NativeCompareStrBuf(void * Locale, const char * S1, const char * S2, int 
	Len);
extern PACKAGE int __fastcall NativeCompareText(void * Locale, const AnsiString S1, const AnsiString 
	S2, int Len);
extern PACKAGE int __fastcall NativeCompareTextBuf(void * Locale, const char * S1, const char * S2, 
	int Len);
extern PACKAGE void __fastcall DbiError(Word ErrorCode);
extern PACKAGE void __fastcall Check(Word Status);

}	/* namespace Dbtables */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Dbtables;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DBTables
