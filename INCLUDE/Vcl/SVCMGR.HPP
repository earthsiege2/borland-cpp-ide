// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SvcMgr.pas' rev: 6.00

#ifndef SvcMgrHPP
#define SvcMgrHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <WinSvc.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Svcmgr
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TEventLogger;
class PASCALIMPLEMENTATION TEventLogger : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	AnsiString FName;
	int FEventLog;
	
public:
	__fastcall TEventLogger(AnsiString Name);
	__fastcall virtual ~TEventLogger(void);
	void __fastcall LogMessage(AnsiString Message, unsigned EventType = (unsigned)(0x1), Word Category = (Word)(0x0), unsigned ID = (unsigned)(0x0));
};


class DELPHICLASS TDependency;
class PASCALIMPLEMENTATION TDependency : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	AnsiString FName;
	bool FIsGroup;
	
protected:
	virtual AnsiString __fastcall GetDisplayName();
	
__published:
	__property AnsiString Name = {read=FName, write=FName};
	__property bool IsGroup = {read=FIsGroup, write=FIsGroup, nodefault};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Create */ inline __fastcall virtual TDependency(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TDependency(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDependencies;
class PASCALIMPLEMENTATION TDependencies : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
public:
	TDependency* operator[](int Index) { return Items[Index]; }
	
private:
	Classes::TPersistent* FOwner;
	HIDESBASE TDependency* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TDependency* Value);
	
protected:
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall TDependencies(Classes::TPersistent* Owner);
	__property TDependency* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TDependencies(void) { }
	#pragma option pop
	
};


class DELPHICLASS TServiceThread;
class DELPHICLASS TService;
#pragma option push -b-
enum TErrorSeverity { esIgnore, esNormal, esSevere, esCritical };
#pragma option pop

#pragma option push -b-
enum TServiceType { stWin32, stDevice, stFileSystem };
#pragma option pop

#pragma option push -b-
enum TStartType { stBoot, stSystem, stAuto, stManual, stDisabled };
#pragma option pop

#pragma option push -b-
enum TCurrentStatus { csStopped, csStartPending, csStopPending, csRunning, csContinuePending, csPausePending, csPaused };
#pragma option pop

typedef void __fastcall (__closure *TServiceEvent)(TService* Sender);

typedef void __fastcall (__closure *TContinueEvent)(TService* Sender, bool &Continued);

typedef void __fastcall (__closure *TPauseEvent)(TService* Sender, bool &Paused);

typedef void __fastcall (__closure *TStartEvent)(TService* Sender, bool &Started);

typedef void __fastcall (__closure *TStopEvent)(TService* Sender, bool &Stopped);

typedef void __stdcall (*TServiceController)(unsigned CtrlCode);

class PASCALIMPLEMENTATION TService : public Classes::TDataModule 
{
	typedef Classes::TDataModule inherited;
	
private:
	bool FAllowStop;
	bool FAllowPause;
	TDependencies* FDependencies;
	AnsiString FDisplayName;
	unsigned FErrCode;
	TErrorSeverity FErrorSeverity;
	TEventLogger* FEventLogger;
	bool FInteractive;
	AnsiString FLoadGroup;
	Classes::TStringList* FParams;
	AnsiString FPassword;
	AnsiString FServiceStartName;
	TServiceThread* FServiceThread;
	TServiceType FServiceType;
	TStartType FStartType;
	TCurrentStatus FStatus;
	unsigned FStatusHandle;
	unsigned FTagID;
	int FWaitHint;
	unsigned FWin32ErrorCode;
	TServiceEvent FBeforeInstall;
	TServiceEvent FAfterInstall;
	TServiceEvent FBeforeUninstall;
	TServiceEvent FAfterUninstall;
	TContinueEvent FOnContinue;
	TServiceEvent FOnExecute;
	TPauseEvent FOnPause;
	TServiceEvent FOnShutdown;
	TStartEvent FOnStart;
	TStopEvent FOnStop;
	AnsiString __fastcall GetDisplayName();
	int __fastcall GetParamCount(void);
	AnsiString __fastcall GetParam(int Index);
	void __fastcall SetStatus(TCurrentStatus Value);
	void __fastcall SetDependencies(TDependencies* Value);
	AnsiString __fastcall GetNTDependencies();
	int __fastcall GetNTServiceType(void);
	int __fastcall GetNTStartType(void);
	int __fastcall GetNTErrorSeverity(void);
	int __fastcall GetNTControlsAccepted(void);
	void __fastcall SetOnContinue(TContinueEvent Value);
	void __fastcall SetOnPause(TPauseEvent Value);
	void __fastcall SetOnStop(TStopEvent Value);
	bool __fastcall GetTerminated(void);
	bool __fastcall AreDependenciesStored(void);
	void __fastcall SetInteractive(bool Value);
	void __fastcall SetPassword(const AnsiString Value);
	void __fastcall SetServiceStartName(const AnsiString Value);
	
protected:
	void __fastcall Main(unsigned Argc, Winsvc::PLPSTRA Argv);
	void __fastcall Controller(unsigned CtrlCode);
	virtual void __fastcall DoStart(void);
	virtual bool __fastcall DoStop(void);
	virtual bool __fastcall DoPause(void);
	virtual bool __fastcall DoContinue(void);
	virtual void __fastcall DoInterrogate(void);
	virtual void __fastcall DoShutdown(void);
	virtual bool __fastcall DoCustomControl(unsigned CtrlCode);
	
public:
	__fastcall virtual TService(Classes::TComponent* AOwner);
	__fastcall virtual TService(Classes::TComponent* AOwner, int Dummy);
	__fastcall virtual ~TService(void);
	virtual TServiceController __fastcall GetServiceController(void) = 0 ;
	void __fastcall ReportStatus(void);
	void __fastcall LogMessage(AnsiString Message, unsigned EventType = (unsigned)(0x1), int Category = 0x0, int ID = 0x0);
	__property unsigned ErrCode = {read=FErrCode, write=FErrCode, nodefault};
	__property int ParamCount = {read=GetParamCount, nodefault};
	__property AnsiString Param[int Index] = {read=GetParam};
	__property TServiceThread* ServiceThread = {read=FServiceThread};
	__property TCurrentStatus Status = {read=FStatus, write=SetStatus, nodefault};
	__property bool Terminated = {read=GetTerminated, nodefault};
	__property unsigned Win32ErrCode = {read=FWin32ErrorCode, write=FWin32ErrorCode, nodefault};
	
__published:
	__property bool AllowStop = {read=FAllowStop, write=FAllowStop, default=1};
	__property bool AllowPause = {read=FAllowPause, write=FAllowPause, default=1};
	__property TDependencies* Dependencies = {read=FDependencies, write=SetDependencies, stored=AreDependenciesStored};
	__property AnsiString DisplayName = {read=GetDisplayName, write=FDisplayName};
	__property TErrorSeverity ErrorSeverity = {read=FErrorSeverity, write=FErrorSeverity, default=1};
	__property bool Interactive = {read=FInteractive, write=SetInteractive, default=0};
	__property AnsiString LoadGroup = {read=FLoadGroup, write=FLoadGroup};
	__property AnsiString Password = {read=FPassword, write=SetPassword};
	__property AnsiString ServiceStartName = {read=FServiceStartName, write=SetServiceStartName};
	__property TServiceType ServiceType = {read=FServiceType, write=FServiceType, default=0};
	__property TStartType StartType = {read=FStartType, write=FStartType, default=2};
	__property unsigned TagID = {read=FTagID, write=FTagID, default=0};
	__property int WaitHint = {read=FWaitHint, write=FWaitHint, default=5000};
	__property TServiceEvent BeforeInstall = {read=FBeforeInstall, write=FBeforeInstall};
	__property TServiceEvent AfterInstall = {read=FAfterInstall, write=FAfterInstall};
	__property TServiceEvent BeforeUninstall = {read=FBeforeUninstall, write=FBeforeUninstall};
	__property TServiceEvent AfterUninstall = {read=FAfterUninstall, write=FAfterUninstall};
	__property TContinueEvent OnContinue = {read=FOnContinue, write=SetOnContinue};
	__property TServiceEvent OnExecute = {read=FOnExecute, write=FOnExecute};
	__property TPauseEvent OnPause = {read=FOnPause, write=SetOnPause};
	__property TServiceEvent OnShutdown = {read=FOnShutdown, write=FOnShutdown};
	__property TStartEvent OnStart = {read=FOnStart, write=FOnStart};
	__property TStopEvent OnStop = {read=FOnStop, write=SetOnStop};
public:
	#pragma option push -w-inl
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TServiceThread : public Classes::TThread 
{
	typedef Classes::TThread inherited;
	
private:
	TService* FService;
	
protected:
	virtual void __fastcall Execute(void);
	
public:
	__fastcall TServiceThread(TService* Service);
	void __fastcall ProcessRequests(bool WaitForMessage);
public:
	#pragma option push -w-inl
	/* TThread.Destroy */ inline __fastcall virtual ~TServiceThread(void) { }
	#pragma option pop
	
};


class DELPHICLASS TServiceApplication;
class PASCALIMPLEMENTATION TServiceApplication : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TEventLogger* FEventLogger;
	AnsiString FTitle;
	void __fastcall OnExceptionHandler(System::TObject* Sender, Sysutils::Exception* E);
	int __fastcall GetServiceCount(void);
	
protected:
	DYNAMIC void __fastcall DoHandleException(Sysutils::Exception* E);
	void __fastcall RegisterServices(bool Install, bool Silent);
	void __fastcall DispatchServiceMain(unsigned Argc, Winsvc::PLPSTRA Argv);
	bool __fastcall Hook(Messages::TMessage &Message);
	
public:
	__fastcall virtual TServiceApplication(Classes::TComponent* AOwner);
	__fastcall virtual ~TServiceApplication(void);
	__property int ServiceCount = {read=GetServiceCount, nodefault};
	virtual void __fastcall CreateForm(TMetaClass* InstanceClass, void *Reference);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall Run(void);
	__property AnsiString Title = {read=FTitle, write=FTitle};
};


//-- var, const, procedure ---------------------------------------------------
static const Word CM_SERVICE_CONTROL_CODE = 0x401;
extern PACKAGE TServiceApplication* Application;

}	/* namespace Svcmgr */
using namespace Svcmgr;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SvcMgr
