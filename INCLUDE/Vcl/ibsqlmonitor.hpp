// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBSQLMonitor.pas' rev: 5.00

#ifndef IBSQLMonitorHPP
#define IBSQLMonitorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IBServices.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <IBDatabase.hpp>	// Pascal unit
#include <IBCustomDataSet.hpp>	// Pascal unit
#include <IBSQL.hpp>	// Pascal unit
#include <IBUtils.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibsqlmonitor
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TSQLEvent)(AnsiString EventText);

class DELPHICLASS TIBCustomSQLMonitor;
class PASCALIMPLEMENTATION TIBCustomSQLMonitor : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Word FAtom;
	HWND FHWnd;
	unsigned FThread;
	TSQLEvent FOnSQLEvent;
	Ibdatabase::TTraceFlags FTraceFlags;
	
protected:
	virtual void __fastcall MonitorHandler(Messages::TMessage &Msg);
	__property TSQLEvent OnSQL = {read=FOnSQLEvent, write=FOnSQLEvent};
	__property Ibdatabase::TTraceFlags TraceFlags = {read=FTraceFlags, write=FTraceFlags, nodefault};
	
public:
	__fastcall virtual TIBCustomSQLMonitor(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBCustomSQLMonitor(void);
};


class DELPHICLASS TIBSQLMonitor;
class PASCALIMPLEMENTATION TIBSQLMonitor : public TIBCustomSQLMonitor 
{
	typedef TIBCustomSQLMonitor inherited;
	
__published:
	__property OnSQL ;
public:
	#pragma option push -w-inl
	/* TIBCustomSQLMonitor.Create */ inline __fastcall virtual TIBSQLMonitor(Classes::TComponent* AOwner
		) : TIBCustomSQLMonitor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIBCustomSQLMonitor.Destroy */ inline __fastcall virtual ~TIBSQLMonitor(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIBSQLMonitorHook;
class PASCALIMPLEMENTATION TIBSQLMonitorHook : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	unsigned FSharedBuffer;
	unsigned FWriteLock;
	unsigned FWriteEvent;
	unsigned FWriteFinishedEvent;
	unsigned FReadEvent;
	unsigned FReadFinishedEvent;
	char *FBuffer;
	int *FMonitorCount;
	int *FReaderCount;
	int *FTraceDataType;
	int *FBufferSize;
	Ibdatabase::TTraceFlags FTraceFlags;
	
protected:
	void __fastcall ResetStates(void);
	void __fastcall Lock(void);
	void __fastcall Unlock(void);
	void __fastcall BeginWrite(void);
	void __fastcall EndWrite(void);
	void __fastcall BeginRead(void);
	void __fastcall EndRead(void);
	void __fastcall WriteSQLData(AnsiString Text, Ibdatabase::TTraceFlag DataType);
	
public:
	__fastcall TIBSQLMonitorHook(void);
	__fastcall virtual ~TIBSQLMonitorHook(void);
	int __fastcall MonitorCount(void);
	void __fastcall RegisterMonitor(void);
	void __fastcall UnregisterMonitor(void);
	AnsiString __fastcall ReadSQLData(TIBCustomSQLMonitor* Arg);
	virtual void __fastcall SQLPrepare(Ibsql::TIBSQL* qry);
	virtual void __fastcall SQLExecute(Ibsql::TIBSQL* qry);
	virtual void __fastcall SQLFetch(Ibsql::TIBSQL* qry);
	virtual void __fastcall DBConnect(Ibdatabase::TIBDatabase* db);
	virtual void __fastcall DBDisconnect(Ibdatabase::TIBDatabase* db);
	virtual void __fastcall TRStart(Ibdatabase::TIBTransaction* tr);
	virtual void __fastcall TRCommit(Ibdatabase::TIBTransaction* tr);
	virtual void __fastcall TRCommitRetaining(Ibdatabase::TIBTransaction* tr);
	virtual void __fastcall TRRollback(Ibdatabase::TIBTransaction* tr);
	virtual void __fastcall TRRollbackRetaining(Ibdatabase::TIBTransaction* tr);
	virtual void __fastcall ServiceAttach(Ibservices::TIBCustomService* service);
	virtual void __fastcall ServiceDetach(Ibservices::TIBCustomService* service);
	virtual void __fastcall ServiceQuery(Ibservices::TIBCustomService* service);
	virtual void __fastcall ServiceStart(Ibservices::TIBCustomService* service);
	__property Ibdatabase::TTraceFlags TraceFlags = {read=FTraceFlags, write=FTraceFlags, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::ResourceString _SCantPrintValue;
#define Ibsqlmonitor_SCantPrintValue System::LoadResourceString(&Ibsqlmonitor::_SCantPrintValue)
extern PACKAGE System::ResourceString _SEOFReached;
#define Ibsqlmonitor_SEOFReached System::LoadResourceString(&Ibsqlmonitor::_SEOFReached)
static const Word WM_MIN_IBSQL_MONITOR = 0x400;
static const Word WM_MAX_IBSQL_MONITOR = 0x600;
static const Word WM_IBSQL_SQL_EVENT = 0x401;
extern PACKAGE void __fastcall EnableMonitoring(void);
extern PACKAGE void __fastcall DisableMonitoring(void);
extern PACKAGE bool __fastcall MonitoringEnabled(void);
extern PACKAGE TIBSQLMonitorHook* __fastcall MonitorHook(void);

}	/* namespace Ibsqlmonitor */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ibsqlmonitor;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBSQLMonitor
