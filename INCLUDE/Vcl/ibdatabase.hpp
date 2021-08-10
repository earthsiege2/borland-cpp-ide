// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBDatabase.pas' rev: 6.00

#ifndef IBDatabaseHPP
#define IBDatabaseHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IB.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <IBExternals.hpp>	// Pascal unit
#include <IBHeader.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibdatabase
{
//-- type declarations -------------------------------------------------------
typedef AnsiString IBDatabase__1[67];

typedef AnsiString IBDatabase__2[20];

class DELPHICLASS TIBDatabase;
typedef void __fastcall (__closure *TIBDatabaseLoginEvent)(TIBDatabase* Database, Classes::TStrings* LoginParams);

__interface IIBEventNotifier;
typedef System::DelphiInterface<IIBEventNotifier> _di_IIBEventNotifier;
__interface INTERFACE_UUID("{9427DE09-46F7-4E1D-8B92-C1F88B47BF6D}") IIBEventNotifier  : public IInterface 
{
	
public:
	virtual void __fastcall RegisterEvents(void) = 0 ;
	virtual void __fastcall UnRegisterEvents(void) = 0 ;
	virtual bool __fastcall GetAutoRegister(void) = 0 ;
};

class DELPHICLASS TIBSchema;
class PASCALIMPLEMENTATION TIBSchema : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual void __fastcall FreeNodes(void) = 0 ;
	virtual bool __fastcall Has_DEFAULT_VALUE(AnsiString Relation, AnsiString Field) = 0 ;
	virtual bool __fastcall Has_COMPUTED_BLR(AnsiString Relation, AnsiString Field) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TIBSchema(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIBSchema(void) { }
	#pragma option pop
	
};


typedef AnsiString TIBFileName;

class DELPHICLASS TIBTransaction;
class DELPHICLASS TIBTimer;
class PASCALIMPLEMENTATION TIBTimer : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	unsigned FInterval;
	HWND FWindowHandle;
	Classes::TNotifyEvent FOnTimer;
	bool FEnabled;
	void __fastcall UpdateTimer(void);
	void __fastcall SetEnabled(bool Value);
	void __fastcall SetInterval(unsigned Value);
	void __fastcall SetOnTimer(Classes::TNotifyEvent Value);
	void __fastcall WndProc(Messages::TMessage &Msg);
	
protected:
	DYNAMIC void __fastcall Timer(void);
	
public:
	__fastcall virtual TIBTimer(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBTimer(void);
	
__published:
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property unsigned Interval = {read=FInterval, write=SetInterval, default=1000};
	__property Classes::TNotifyEvent OnTimer = {read=FOnTimer, write=SetOnTimer};
};


#pragma option push -b-
enum TTransactionAction { TARollback, TACommit, TARollbackRetaining, TACommitRetaining };
#pragma option pop

#pragma option push -b-
enum TAutoStopAction { saNone, saRollback, saCommit, saRollbackRetaining, saCommitRetaining };
#pragma option pop

class DELPHICLASS TIBBase;
class PASCALIMPLEMENTATION TIBTransaction : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	bool FIBLoaded;
	bool FCanTimeout;
	Classes::TList* FDatabases;
	Classes::TList* FSQLObjects;
	TIBDatabase* FDefaultDatabase;
	void * *FHandle;
	bool FHandleIsShared;
	Classes::TNotifyEvent FOnIdleTimer;
	bool FStreamedActive;
	char *FTPB;
	short FTPBLength;
	TIBTimer* FTimer;
	TTransactionAction FDefaultAction;
	Classes::TStrings* FTRParams;
	bool FTRParamsChanged;
	TAutoStopAction FAutoStopAction;
	void __fastcall EnsureNotInTransaction(void);
	void __fastcall EndTransaction(TTransactionAction Action, bool Force);
	TIBDatabase* __fastcall GetDatabase(int Index);
	int __fastcall GetDatabaseCount(void);
	TIBBase* __fastcall GetSQLObject(int Index);
	int __fastcall GetSQLObjectCount(void);
	bool __fastcall GetInTransaction(void);
	int __fastcall GetIdleTimer(void);
	void __fastcall BeforeDatabaseDisconnect(TIBDatabase* DB);
	void __fastcall SetActive(bool Value);
	void __fastcall SetDefaultAction(TTransactionAction Value);
	void __fastcall SetDefaultDatabase(TIBDatabase* Value);
	void __fastcall SetIdleTimer(int Value);
	void __fastcall SetTRParams(Classes::TStrings* Value);
	void __fastcall TimeoutTransaction(System::TObject* Sender);
	void __fastcall TRParamsChange(System::TObject* Sender);
	void __fastcall TRParamsChanging(System::TObject* Sender);
	int __fastcall AddSQLObject(TIBBase* ds);
	void __fastcall RemoveSQLObject(int Idx);
	void __fastcall RemoveSQLObjects(void);
	
protected:
	virtual void __fastcall Loaded(void);
	void __fastcall SetHandle(Ibexternals::PVoid Value);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__fastcall virtual TIBTransaction(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBTransaction(void);
	int __fastcall Call(int ErrCode, bool RaiseError);
	void __fastcall Commit(void);
	void __fastcall CommitRetaining(void);
	void __fastcall Rollback(void);
	void __fastcall RollbackRetaining(void);
	void __fastcall StartTransaction(void);
	void __fastcall CheckInTransaction(void);
	void __fastcall CheckNotInTransaction(void);
	void __fastcall CheckAutoStop(void);
	int __fastcall AddDatabase(TIBDatabase* db);
	int __fastcall FindDatabase(TIBDatabase* db);
	TIBDatabase* __fastcall FindDefaultDatabase(void);
	void __fastcall RemoveDatabase(int Idx);
	void __fastcall RemoveDatabases(void);
	void __fastcall CheckDatabasesInList(void);
	__property int DatabaseCount = {read=GetDatabaseCount, nodefault};
	__property TIBDatabase* Databases[int Index] = {read=GetDatabase};
	__property int SQLObjectCount = {read=GetSQLObjectCount, nodefault};
	__property TIBBase* SQLObjects[int Index] = {read=GetSQLObject};
	__property Ibexternals::PVoid Handle = {read=FHandle};
	__property bool HandleIsShared = {read=FHandleIsShared, nodefault};
	__property bool InTransaction = {read=GetInTransaction, nodefault};
	__property char * TPB = {read=FTPB};
	__property short TPBLength = {read=FTPBLength, nodefault};
	
__published:
	__property bool Active = {read=GetInTransaction, write=SetActive, nodefault};
	__property TIBDatabase* DefaultDatabase = {read=FDefaultDatabase, write=SetDefaultDatabase};
	__property int IdleTimer = {read=GetIdleTimer, write=SetIdleTimer, default=0};
	__property TTransactionAction DefaultAction = {read=FDefaultAction, write=SetDefaultAction, default=1};
	__property Classes::TStrings* Params = {read=FTRParams, write=SetTRParams};
	__property TAutoStopAction AutoStopAction = {read=FAutoStopAction, write=FAutoStopAction, nodefault};
	__property Classes::TNotifyEvent OnIdleTimer = {read=FOnIdleTimer, write=FOnIdleTimer};
};


class PASCALIMPLEMENTATION TIBDatabase : public Db::TCustomConnection 
{
	typedef Db::TCustomConnection inherited;
	
private:
	AnsiString FHiddenPassword;
	bool FIBLoaded;
	TIBDatabaseLoginEvent FOnLogin;
	Ib::TTraceFlags FTraceFlags;
	int FDBSQLDialect;
	int FSQLDialect;
	Classes::TNotifyEvent FOnDialectDowngradeWarning;
	bool FCanTimeout;
	Classes::TList* FSQLObjects;
	Classes::TList* FTransactions;
	AnsiString FDBName;
	Classes::TStrings* FDBParams;
	bool FDBParamsChanged;
	char *FDPB;
	short FDPBLength;
	void * *FHandle;
	bool FHandleIsShared;
	Classes::TNotifyEvent FOnIdleTimer;
	TIBTransaction* FDefaultTransaction;
	TIBTransaction* FInternalTransaction;
	TIBTimer* FTimer;
	Classes::TStringList* FUserNames;
	Classes::TList* FEventNotifiers;
	bool FAllowStreamedConnected;
	TIBSchema* FSchema;
	void __fastcall EnsureInactive(void);
	int __fastcall GetDBSQLDialect(void);
	int __fastcall GetSQLDialect(void);
	void __fastcall SetSQLDialect(const int Value);
	void __fastcall ValidateClientSQLDialect(void);
	void __fastcall DBParamsChange(System::TObject* Sender);
	void __fastcall DBParamsChanging(System::TObject* Sender);
	TIBBase* __fastcall GetSQLObject(int Index);
	int __fastcall GetSQLObjectCount(void);
	AnsiString __fastcall GetDBParamByDPB(const int Idx);
	int __fastcall GetIdleTimer(void);
	TIBTransaction* __fastcall GetTransaction(int Index);
	int __fastcall GetTransactionCount(void);
	bool __fastcall Login(void);
	void __fastcall SetDatabaseName(const AnsiString Value);
	void __fastcall SetDBParamByDPB(const int Idx, AnsiString Value);
	void __fastcall SetDBParams(Classes::TStrings* Value);
	void __fastcall SetDefaultTransaction(TIBTransaction* Value);
	void __fastcall SetIdleTimer(int Value);
	void __fastcall TimeoutConnection(System::TObject* Sender);
	bool __fastcall GetIsReadOnly(void);
	int __fastcall AddSQLObject(TIBBase* ds);
	void __fastcall RemoveSQLObject(int Idx);
	void __fastcall RemoveSQLObjects(void);
	void __fastcall InternalClose(bool Force);
	
protected:
	virtual void __fastcall DoConnect(void);
	virtual void __fastcall DoDisconnect(void);
	virtual bool __fastcall GetConnected(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__fastcall virtual TIBDatabase(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBDatabase(void);
	void __fastcall AddEventNotifier(_di_IIBEventNotifier Notifier);
	void __fastcall RemoveEventNotifier(_di_IIBEventNotifier Notifier);
	void __fastcall ApplyUpdates(const Db::TDataSet* * DataSets, const int DataSets_Size);
	void __fastcall CloseDataSets(void);
	void __fastcall CheckActive(void);
	void __fastcall CheckInactive(void);
	void __fastcall CreateDatabase(void);
	void __fastcall DropDatabase(void);
	void __fastcall ForceClose(void);
	void __fastcall GetFieldNames(const AnsiString TableName, Classes::TStrings* List);
	void __fastcall GetTableNames(Classes::TStrings* List, bool SystemTables = false);
	int __fastcall IndexOfDBConst(AnsiString st);
	bool __fastcall TestConnected(void);
	void __fastcall CheckDatabaseName(void);
	int __fastcall Call(int ErrCode, bool RaiseError);
	int __fastcall AddTransaction(TIBTransaction* TR);
	int __fastcall FindTransaction(TIBTransaction* TR);
	TIBTransaction* __fastcall FindDefaultTransaction(void);
	void __fastcall RemoveTransaction(int Idx);
	void __fastcall RemoveTransactions(void);
	void __fastcall SetHandle(Ibexternals::PVoid Value);
	__property Ibexternals::PVoid Handle = {read=FHandle};
	__property bool IsReadOnly = {read=GetIsReadOnly, nodefault};
	__property AnsiString DBParamByDPB[int Idx] = {read=GetDBParamByDPB, write=SetDBParamByDPB};
	__property int SQLObjectCount = {read=GetSQLObjectCount, nodefault};
	__property TIBBase* SQLObjects[int Index] = {read=GetSQLObject};
	__property bool HandleIsShared = {read=FHandleIsShared, nodefault};
	__property int TransactionCount = {read=GetTransactionCount, nodefault};
	__property TIBTransaction* Transactions[int Index] = {read=GetTransaction};
	__property TIBTransaction* InternalTransaction = {read=FInternalTransaction};
	bool __fastcall Has_DEFAULT_VALUE(AnsiString Relation, AnsiString Field);
	bool __fastcall Has_COMPUTED_BLR(AnsiString Relation, AnsiString Field);
	void __fastcall FlushSchema(void);
	
__published:
	__property Connected  = {default=0};
	__property AnsiString DatabaseName = {read=FDBName, write=SetDatabaseName};
	__property Classes::TStrings* Params = {read=FDBParams, write=SetDBParams};
	__property LoginPrompt  = {default=1};
	__property TIBTransaction* DefaultTransaction = {read=FDefaultTransaction, write=SetDefaultTransaction};
	__property int IdleTimer = {read=GetIdleTimer, write=SetIdleTimer, nodefault};
	__property int SQLDialect = {read=GetSQLDialect, write=SetSQLDialect, nodefault};
	__property int DBSQLDialect = {read=FDBSQLDialect, nodefault};
	__property Ib::TTraceFlags TraceFlags = {read=FTraceFlags, write=FTraceFlags, nodefault};
	__property bool AllowStreamedConnected = {read=FAllowStreamedConnected, write=FAllowStreamedConnected, default=1};
	__property AfterConnect ;
	__property AfterDisconnect ;
	__property BeforeConnect ;
	__property BeforeDisconnect ;
	__property TIBDatabaseLoginEvent OnLogin = {read=FOnLogin, write=FOnLogin};
	__property Classes::TNotifyEvent OnIdleTimer = {read=FOnIdleTimer, write=FOnIdleTimer};
	__property Classes::TNotifyEvent OnDialectDowngradeWarning = {read=FOnDialectDowngradeWarning, write=FOnDialectDowngradeWarning};
};


class PASCALIMPLEMENTATION TIBBase : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	TIBDatabase* FDatabase;
	int FIndexInDatabase;
	TIBTransaction* FTransaction;
	int FIndexInTransaction;
	System::TObject* FOwner;
	Classes::TNotifyEvent FBeforeDatabaseDisconnect;
	Classes::TNotifyEvent FAfterDatabaseDisconnect;
	Classes::TNotifyEvent FOnDatabaseFree;
	Classes::TNotifyEvent FBeforeTransactionEnd;
	Classes::TNotifyEvent FAfterTransactionEnd;
	Classes::TNotifyEvent FOnTransactionFree;
	virtual void __fastcall DoBeforeDatabaseDisconnect(void);
	virtual void __fastcall DoAfterDatabaseDisconnect(void);
	virtual void __fastcall DoDatabaseFree(void);
	virtual void __fastcall DoBeforeTransactionEnd(void);
	virtual void __fastcall DoAfterTransactionEnd(void);
	virtual void __fastcall DoTransactionFree(void);
	virtual Ibheader::PISC_DB_HANDLE __fastcall GetDBHandle(void);
	virtual Ibheader::PISC_TR_HANDLE __fastcall GetTRHandle(void);
	virtual void __fastcall SetDatabase(TIBDatabase* Value);
	virtual void __fastcall SetTransaction(TIBTransaction* Value);
	
public:
	__fastcall TIBBase(System::TObject* AOwner);
	__fastcall virtual ~TIBBase(void);
	virtual void __fastcall CheckDatabase(void);
	virtual void __fastcall CheckTransaction(void);
	__property Classes::TNotifyEvent BeforeDatabaseDisconnect = {read=FBeforeDatabaseDisconnect, write=FBeforeDatabaseDisconnect};
	__property Classes::TNotifyEvent AfterDatabaseDisconnect = {read=FAfterDatabaseDisconnect, write=FAfterDatabaseDisconnect};
	__property Classes::TNotifyEvent OnDatabaseFree = {read=FOnDatabaseFree, write=FOnDatabaseFree};
	__property Classes::TNotifyEvent BeforeTransactionEnd = {read=FBeforeTransactionEnd, write=FBeforeTransactionEnd};
	__property Classes::TNotifyEvent AfterTransactionEnd = {read=FAfterTransactionEnd, write=FAfterTransactionEnd};
	__property Classes::TNotifyEvent OnTransactionFree = {read=FOnTransactionFree, write=FOnTransactionFree};
	__property TIBDatabase* Database = {read=FDatabase, write=SetDatabase};
	__property Ibheader::PISC_DB_HANDLE DBHandle = {read=GetDBHandle};
	__property System::TObject* Owner = {read=FOwner};
	__property Ibheader::PISC_TR_HANDLE TRHandle = {read=GetTRHandle};
	__property TIBTransaction* Transaction = {read=FTransaction, write=SetTransaction};
};


//-- var, const, procedure ---------------------------------------------------
#define DPBPrefix "isc_dpb_"
extern PACKAGE AnsiString DPBConstantNames[67];
#define TPBPrefix "isc_tpb_"
extern PACKAGE AnsiString TPBConstantNames[20];
extern PACKAGE void __fastcall GenerateDPB(Classes::TStrings* sl, AnsiString &DPB, short &DPBLength);
extern PACKAGE void __fastcall GenerateTPB(Classes::TStrings* sl, AnsiString &TPB, short &TPBLength);

}	/* namespace Ibdatabase */
using namespace Ibdatabase;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBDatabase
