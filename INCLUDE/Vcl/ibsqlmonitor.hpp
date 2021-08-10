// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBSQLMonitor.pas' rev: 6.00

#ifndef IBSQLMonitorHPP
#define IBSQLMonitorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IBXConst.hpp>	// Pascal unit
#include <IBServices.hpp>	// Pascal unit
#include <IBDatabase.hpp>	// Pascal unit
#include <IBCustomDataSet.hpp>	// Pascal unit
#include <IBSQL.hpp>	// Pascal unit
#include <IBUtils.hpp>	// Pascal unit
#include <IB.hpp>	// Pascal unit
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
typedef void __fastcall (__closure *TSQLEvent)(AnsiString EventText, System::TDateTime EventTime);

class DELPHICLASS TIBCustomSQLMonitor;
class PASCALIMPLEMENTATION TIBCustomSQLMonitor : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	HWND FHWnd;
	TSQLEvent FOnSQLEvent;
	Ib::TTraceFlags FTraceFlags;
	bool FEnabled;
	void __fastcall MonitorWndProc(Messages::TMessage &Message);
	void __fastcall SetEnabled(const bool Value);
	
protected:
	__property TSQLEvent OnSQL = {read=FOnSQLEvent, write=FOnSQLEvent};
	__property Ib::TTraceFlags TraceFlags = {read=FTraceFlags, write=FTraceFlags, nodefault};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	
public:
	__fastcall virtual TIBCustomSQLMonitor(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBCustomSQLMonitor(void);
	void __fastcall Release(void);
	__property HWND Handle = {read=FHWnd, nodefault};
};


class DELPHICLASS TIBSQLMonitor;
class PASCALIMPLEMENTATION TIBSQLMonitor : public TIBCustomSQLMonitor 
{
	typedef TIBCustomSQLMonitor inherited;
	
__published:
	__property OnSQL ;
	__property TraceFlags ;
	__property Enabled  = {default=1};
public:
	#pragma option push -w-inl
	/* TIBCustomSQLMonitor.Create */ inline __fastcall virtual TIBSQLMonitor(Classes::TComponent* AOwner) : TIBCustomSQLMonitor(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIBCustomSQLMonitor.Destroy */ inline __fastcall virtual ~TIBSQLMonitor(void) { }
	#pragma option pop
	
};


__interface IIBSQLMonitorHook;
typedef System::DelphiInterface<IIBSQLMonitorHook> _di_IIBSQLMonitorHook;
__interface INTERFACE_UUID("{CF65434C-9B75-4298-BA7E-E6B85B3C769D}") IIBSQLMonitorHook  : public IInterface 
{
	
public:
	virtual void __fastcall RegisterMonitor(TIBCustomSQLMonitor* SQLMonitor) = 0 ;
	virtual void __fastcall UnregisterMonitor(TIBCustomSQLMonitor* SQLMonitor) = 0 ;
	virtual void __fastcall ReleaseMonitor(TIBCustomSQLMonitor* Arg) = 0 ;
	virtual void __fastcall SQLPrepare(Ibsql::TIBSQL* qry) = 0 ;
	virtual void __fastcall SQLExecute(Ibsql::TIBSQL* qry) = 0 ;
	virtual void __fastcall SQLFetch(Ibsql::TIBSQL* qry) = 0 ;
	virtual void __fastcall DBConnect(Ibdatabase::TIBDatabase* db) = 0 ;
	virtual void __fastcall DBDisconnect(Ibdatabase::TIBDatabase* db) = 0 ;
	virtual void __fastcall TRStart(Ibdatabase::TIBTransaction* tr) = 0 ;
	virtual void __fastcall TRCommit(Ibdatabase::TIBTransaction* tr) = 0 ;
	virtual void __fastcall TRCommitRetaining(Ibdatabase::TIBTransaction* tr) = 0 ;
	virtual void __fastcall TRRollback(Ibdatabase::TIBTransaction* tr) = 0 ;
	virtual void __fastcall TRRollbackRetaining(Ibdatabase::TIBTransaction* tr) = 0 ;
	virtual void __fastcall ServiceAttach(Ibservices::TIBCustomService* service) = 0 ;
	virtual void __fastcall ServiceDetach(Ibservices::TIBCustomService* service) = 0 ;
	virtual void __fastcall ServiceQuery(Ibservices::TIBCustomService* service) = 0 ;
	virtual void __fastcall ServiceStart(Ibservices::TIBCustomService* service) = 0 ;
	virtual void __fastcall SendMisc(AnsiString Msg) = 0 ;
	virtual Ib::TTraceFlags __fastcall GetTraceFlags(void) = 0 ;
	virtual int __fastcall GetMonitorCount(void) = 0 ;
	virtual void __fastcall SetTraceFlags(const Ib::TTraceFlags Value) = 0 ;
	virtual bool __fastcall GetEnabled(void) = 0 ;
	virtual void __fastcall SetEnabled(const bool Value) = 0 ;
	__property Ib::TTraceFlags TraceFlags = {read=GetTraceFlags, write=SetTraceFlags};
	__property bool Enabled = {read=GetEnabled, write=SetEnabled};
};

//-- var, const, procedure ---------------------------------------------------
static const Word WM_MIN_IBSQL_MONITOR = 0x400;
static const Word WM_MAX_IBSQL_MONITOR = 0x600;
static const Word WM_IBSQL_SQL_EVENT = 0x401;
extern PACKAGE _di_IIBSQLMonitorHook __fastcall MonitorHook();
extern PACKAGE void __fastcall EnableMonitoring(void);
extern PACKAGE void __fastcall DisableMonitoring(void);
extern PACKAGE bool __fastcall MonitoringEnabled(void);

}	/* namespace Ibsqlmonitor */
using namespace Ibsqlmonitor;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBSQLMonitor
