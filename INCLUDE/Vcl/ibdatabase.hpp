// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBDatabase.pas' rev: 5.00

#ifndef IBDatabaseHPP
#define IBDatabaseHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DBLogDlg.hpp>	// Pascal unit
#include <IB.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <IBExternals.hpp>	// Pascal unit
#include <IBHeader.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibdatabase
{
//-- type declarations -------------------------------------------------------
typedef AnsiString IBDatabase__1[67];

typedef AnsiString IBDatabase__2[20];

#pragma option push -b-
enum TTraceFlag { tfQPrepare, tfQExecute, tfQFetch, tfError, tfStmt, tfConnect, tfTransact, tfBlob, 
	tfService, tfMisc };
#pragma option pop

typedef Set<TTraceFlag, tfQPrepare, tfMisc>  TTraceFlags;

class DELPHICLASS TIBDatabase;
typedef void __fastcall (__closure *TIBDatabaseLoginEvent)(TIBDatabase* Database, Classes::TStrings* 
	LoginParams);

typedef AnsiString TIBFileName;

class DELPHICLASS TIBTransaction;
#pragma option push -b-
enum TTransactionAction { TARollback, TACommit, TARollbackRetaining, TACommitRetaining };
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
	Extctrls::TTimer* FTimer;
	TTransactionAction FDefaultAction;
	Classes::TStrings* FTRParams;
	bool FTRParamsChanged;
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
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	
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
	__property TTransactionAction DefaultAction = {read=FDefaultAction, write=SetDefaultAction, default=1
		};
	__property Classes::TStrings* Params = {read=FTRParams, write=SetTRParams};
	__property Classes::TNotifyEvent OnIdleTimer = {read=FOnIdleTimer, write=FOnIdleTimer};
};


class PASCALIMPLEMENTATION TIBDatabase : public Db::TCustomConnection 
{
	typedef Db::TCustomConnection inherited;
	
private:
	AnsiString FHiddenPassword;
	bool FIBLoaded;
	TIBDatabaseLoginEvent FOnLogin;
	TTraceFlags FTraceFlags;
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
	bool FStreamedConnected;
	Extctrls::TTimer* FTimer;
	Classes::TStringList* FUserNames;
	void __fastcall EnsureInactive(void);
	int __fastcall GetDBSQLDialect(void);
	int __fastcall GetSQLDialect(void);
	void __fastcall SetSQLDialect(const int Value);
	void __fastcall SetTraceFlags(const TTraceFlags Value);
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
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	
public:
	__fastcall virtual TIBDatabase(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBDatabase(void);
	void __fastcall ApplyUpdates(Db::TDataSet* const * DataSets, const int DataSets_Size);
	void __fastcall CloseDataSets(void);
	void __fastcall CheckActive(void);
	void __fastcall CheckInactive(void);
	void __fastcall CreateDatabase(void);
	void __fastcall DropDatabase(void);
	void __fastcall ForceClose(void);
	void __fastcall GetFieldNames(const AnsiString TableName, Classes::TStrings* List);
	void __fastcall GetTableNames(Classes::TStrings* List, bool SystemTables);
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
	
__published:
	__property Connected ;
	__property AnsiString DatabaseName = {read=FDBName, write=SetDatabaseName};
	__property Classes::TStrings* Params = {read=FDBParams, write=SetDBParams};
	__property LoginPrompt ;
	__property TIBTransaction* DefaultTransaction = {read=FDefaultTransaction, write=SetDefaultTransaction
		};
	__property int IdleTimer = {read=GetIdleTimer, write=SetIdleTimer, nodefault};
	__property int SQLDialect = {read=GetSQLDialect, write=SetSQLDialect, nodefault};
	__property int DBSQLDialect = {read=FDBSQLDialect, nodefault};
	__property TTraceFlags TraceFlags = {read=FTraceFlags, write=SetTraceFlags, nodefault};
	__property AfterConnect ;
	__property AfterDisconnect ;
	__property BeforeConnect ;
	__property BeforeDisconnect ;
	__property TIBDatabaseLoginEvent OnLogin = {read=FOnLogin, write=FOnLogin};
	__property Classes::TNotifyEvent OnIdleTimer = {read=FOnIdleTimer, write=FOnIdleTimer};
	__property Classes::TNotifyEvent OnDialectDowngradeWarning = {read=FOnDialectDowngradeWarning, write=
		FOnDialectDowngradeWarning};
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
	__property Classes::TNotifyEvent BeforeDatabaseDisconnect = {read=FBeforeDatabaseDisconnect, write=
		FBeforeDatabaseDisconnect};
	__property Classes::TNotifyEvent AfterDatabaseDisconnect = {read=FAfterDatabaseDisconnect, write=FAfterDatabaseDisconnect
		};
	__property Classes::TNotifyEvent OnDatabaseFree = {read=FOnDatabaseFree, write=FOnDatabaseFree};
	__property Classes::TNotifyEvent BeforeTransactionEnd = {read=FBeforeTransactionEnd, write=FBeforeTransactionEnd
		};
	__property Classes::TNotifyEvent AfterTransactionEnd = {read=FAfterTransactionEnd, write=FAfterTransactionEnd
		};
	__property Classes::TNotifyEvent OnTransactionFree = {read=FOnTransactionFree, write=FOnTransactionFree
		};
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
extern PACKAGE void __fastcall GenerateDPB(Classes::TStrings* sl, AnsiString &DPB, short &DPBLength)
	;
extern PACKAGE void __fastcall GenerateTPB(Classes::TStrings* sl, AnsiString &TPB, short &TPBLength)
	;

}	/* namespace Ibdatabase */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ibdatabase;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBDatabase
