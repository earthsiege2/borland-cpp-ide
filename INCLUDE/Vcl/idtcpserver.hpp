// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdTCPServer.pas' rev: 6.00

#ifndef IdTCPServerHPP
#define IdTCPServerHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdIntercept.hpp>	// Pascal unit
#include <IdThreadMgrDefault.hpp>	// Pascal unit
#include <IdThreadMgr.hpp>	// Pascal unit
#include <IdThread.hpp>	// Pascal unit
#include <IdTCPConnection.hpp>	// Pascal unit
#include <IdSocketHandle.hpp>	// Pascal unit
#include <IdException.hpp>	// Pascal unit
#include <IdComponent.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idtcpserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdListenerThread;
class DELPHICLASS TIdTCPServer;
class DELPHICLASS TIdPeerThread;
typedef void __fastcall (__closure *TIdServerThreadEvent)(TIdPeerThread* AThread);

class PASCALIMPLEMENTATION TIdTCPServer : public Idcomponent::TIdComponent 
{
	typedef Idcomponent::TIdComponent inherited;
	
protected:
	int FAcceptWait;
	bool FActive;
	bool FImplicitThreadMgrCreated;
	Idthreadmgr::TIdThreadMgr* FThreadMgr;
	Idsockethandle::TIdSocketHandles* FBindings;
	TIdListenerThread* FListenerThread;
	int FTerminateWaitTime;
	TMetaClass*FThreadClass;
	Classes::TThreadList* FThreads;
	TIdServerThreadEvent FOnExecute;
	TIdServerThreadEvent FOnConnect;
	TIdServerThreadEvent FOnDisconnect;
	Idintercept::TIdServerIntercept* FIntercept;
	virtual void __fastcall DoConnect(TIdPeerThread* axThread);
	virtual void __fastcall DoDisconnect(TIdPeerThread* axThread);
	virtual bool __fastcall DoExecute(TIdPeerThread* AThread);
	int __fastcall GetDefaultPort(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall SetAcceptWait(int AValue);
	virtual void __fastcall SetActive(bool AValue);
	void __fastcall SetBindings(const Idsockethandle::TIdSocketHandles* abValue);
	void __fastcall SetDefaultPort(const int AValue);
	void __fastcall SetIntercept(const Idintercept::TIdServerIntercept* Value);
	void __fastcall SetThreadMgr(const Idthreadmgr::TIdThreadMgr* Value);
	void __fastcall TerminateAllThreads(void);
	
public:
	__fastcall virtual TIdTCPServer(Classes::TComponent* AOwner);
	__fastcall virtual ~TIdTCPServer(void);
	virtual void __fastcall Loaded(void);
	__property int AcceptWait = {read=FAcceptWait, write=SetAcceptWait, nodefault};
	__property bool ImplicitThreadMgrCreated = {read=FImplicitThreadMgrCreated, nodefault};
	__property TMetaClass* ThreadClass = {read=FThreadClass, write=FThreadClass};
	__property Classes::TThreadList* Threads = {read=FThreads};
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property Idsockethandle::TIdSocketHandles* Bindings = {read=FBindings, write=SetBindings};
	__property int DefaultPort = {read=GetDefaultPort, write=SetDefaultPort, nodefault};
	__property Idintercept::TIdServerIntercept* Intercept = {read=FIntercept, write=SetIntercept};
	__property TIdServerThreadEvent OnConnect = {read=FOnConnect, write=FOnConnect};
	__property TIdServerThreadEvent OnExecute = {read=FOnExecute, write=FOnExecute};
	__property TIdServerThreadEvent OnDisconnect = {read=FOnDisconnect, write=FOnDisconnect};
	__property int TerminateWaitTime = {read=FTerminateWaitTime, write=FTerminateWaitTime, default=5000};
	__property Idthreadmgr::TIdThreadMgr* ThreadMgr = {read=FThreadMgr, write=SetThreadMgr};
};


class PASCALIMPLEMENTATION TIdListenerThread : public Idthread::TIdThread 
{
	typedef Idthread::TIdThread inherited;
	
protected:
	int FAcceptWait;
	Classes::TList* FBindingList;
	TIdTCPServer* FServer;
	
public:
	virtual void __fastcall AfterRun(void);
	__fastcall TIdListenerThread(TIdTCPServer* axServer);
	__fastcall virtual ~TIdListenerThread(void);
	virtual void __fastcall Run(void);
	__property int AcceptWait = {read=FAcceptWait, write=FAcceptWait, nodefault};
	__property TIdTCPServer* Server = {read=FServer};
};


class DELPHICLASS TIdTCPServerConnection;
class PASCALIMPLEMENTATION TIdTCPServerConnection : public Idtcpconnection::TIdTCPConnection 
{
	typedef Idtcpconnection::TIdTCPConnection inherited;
	
protected:
	TIdTCPServer* __fastcall GetServer(void);
	
__published:
	__property TIdTCPServer* Server = {read=GetServer};
public:
	#pragma option push -w-inl
	/* TIdTCPConnection.Create */ inline __fastcall virtual TIdTCPServerConnection(Classes::TComponent* AOwner) : Idtcpconnection::TIdTCPConnection(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIdTCPConnection.Destroy */ inline __fastcall virtual ~TIdTCPServerConnection(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TIdPeerThread : public Idthread::TIdThread 
{
	typedef Idthread::TIdThread inherited;
	
protected:
	TIdTCPServerConnection* FConnection;
	virtual void __fastcall AfterRun(void);
	virtual void __fastcall BeforeRun(void);
	
public:
	virtual void __fastcall Run(void);
	__property TIdTCPServerConnection* Connection = {read=FConnection};
public:
	#pragma option push -w-inl
	/* TIdThread.Create */ inline __fastcall virtual TIdPeerThread(bool ACreateSuspended) : Idthread::TIdThread(ACreateSuspended) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIdThread.Destroy */ inline __fastcall virtual ~TIdPeerThread(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdTCPServerError;
class PASCALIMPLEMENTATION EIdTCPServerError : public Idexception::EIdException 
{
	typedef Idexception::EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdTCPServerError(const AnsiString Msg) : Idexception::EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdTCPServerError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdTCPServerError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdTCPServerError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdTCPServerError(const AnsiString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTCPServerError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdTCPServerError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTCPServerError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdTCPServerError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdAcceptWaitCannotBeModifiedWhileServerIsActive;
class PASCALIMPLEMENTATION EIdAcceptWaitCannotBeModifiedWhileServerIsActive : public EIdTCPServerError 
{
	typedef EIdTCPServerError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdAcceptWaitCannotBeModifiedWhileServerIsActive(const AnsiString Msg) : EIdTCPServerError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdAcceptWaitCannotBeModifiedWhileServerIsActive(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdTCPServerError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdAcceptWaitCannotBeModifiedWhileServerIsActive(int Ident)/* overload */ : EIdTCPServerError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdAcceptWaitCannotBeModifiedWhileServerIsActive(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdTCPServerError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdAcceptWaitCannotBeModifiedWhileServerIsActive(const AnsiString Msg, int AHelpContext) : EIdTCPServerError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdAcceptWaitCannotBeModifiedWhileServerIsActive(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdTCPServerError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdAcceptWaitCannotBeModifiedWhileServerIsActive(int Ident, int AHelpContext)/* overload */ : EIdTCPServerError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdAcceptWaitCannotBeModifiedWhileServerIsActive(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTCPServerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdAcceptWaitCannotBeModifiedWhileServerIsActive(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdNoExecuteSpecified;
class PASCALIMPLEMENTATION EIdNoExecuteSpecified : public EIdTCPServerError 
{
	typedef EIdTCPServerError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdNoExecuteSpecified(const AnsiString Msg) : EIdTCPServerError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdNoExecuteSpecified(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdTCPServerError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdNoExecuteSpecified(int Ident)/* overload */ : EIdTCPServerError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdNoExecuteSpecified(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdTCPServerError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdNoExecuteSpecified(const AnsiString Msg, int AHelpContext) : EIdTCPServerError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNoExecuteSpecified(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdTCPServerError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdNoExecuteSpecified(int Ident, int AHelpContext)/* overload */ : EIdTCPServerError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNoExecuteSpecified(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTCPServerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdNoExecuteSpecified(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idtcpserver */
using namespace Idtcpserver;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdTCPServer
