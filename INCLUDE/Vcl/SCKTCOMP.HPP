// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ScktComp.pas' rev: 6.00

#ifndef ScktCompHPP
#define ScktCompHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SyncObjs.hpp>	// Pascal unit
#include <WinSock.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Scktcomp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS ESocketError;
class PASCALIMPLEMENTATION ESocketError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ESocketError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ESocketError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ESocketError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ESocketError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ESocketError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ESocketError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ESocketError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ESocketError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ESocketError(void) { }
	#pragma option pop
	
};


#pragma pack(push, 4)
struct TCMSocketMessage
{
	unsigned Msg;
	int Socket;
	Word SelectEvent;
	Word SelectError;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TCMLookupComplete
{
	unsigned Msg;
	unsigned LookupHandle;
	Word AsyncBufLen;
	Word AsyncError;
	int Result;
} ;
#pragma pack(pop)

#pragma option push -b-
enum TServerType { stNonBlocking, stThreadBlocking };
#pragma option pop

#pragma option push -b-
enum TClientType { ctNonBlocking, ctBlocking };
#pragma option pop

#pragma option push -b-
enum TAsyncStyle { asRead, asWrite, asOOB, asAccept, asConnect, asClose };
#pragma option pop

typedef Set<TAsyncStyle, asRead, asClose>  TAsyncStyles;

#pragma option push -b-
enum TSocketEvent { seLookup, seConnecting, seConnect, seDisconnect, seListen, seAccept, seWrite, seRead };
#pragma option pop

#pragma option push -b-
enum TLookupState { lsIdle, lsLookupAddress, lsLookupService };
#pragma option pop

#pragma option push -b-
enum TErrorEvent { eeGeneral, eeSend, eeReceive, eeConnect, eeDisconnect, eeAccept, eeLookup };
#pragma option pop

class DELPHICLASS TCustomWinSocket;
typedef void __fastcall (__closure *TSocketEventEvent)(System::TObject* Sender, TCustomWinSocket* Socket, TSocketEvent SocketEvent);

typedef void __fastcall (__closure *TSocketErrorEvent)(System::TObject* Sender, TCustomWinSocket* Socket, TErrorEvent ErrorEvent, int &ErrorCode);

class DELPHICLASS TServerClientWinSocket;
typedef void __fastcall (__closure *TGetSocketEvent)(System::TObject* Sender, int Socket, TServerClientWinSocket* &ClientSocket);

class DELPHICLASS TServerClientThread;
typedef void __fastcall (__closure *TGetThreadEvent)(System::TObject* Sender, TServerClientWinSocket* ClientSocket, TServerClientThread* &SocketThread);

typedef void __fastcall (__closure *TSocketNotifyEvent)(System::TObject* Sender, TCustomWinSocket* Socket);

class PASCALIMPLEMENTATION TCustomWinSocket : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int FSocket;
	bool FConnected;
	Classes::TStream* FSendStream;
	bool FDropAfterSend;
	HWND FHandle;
	sockaddr_in FAddr;
	TAsyncStyles FAsyncStyles;
	TLookupState FLookupState;
	unsigned FLookupHandle;
	TSocketEventEvent FOnSocketEvent;
	TSocketErrorEvent FOnErrorEvent;
	Syncobjs::TCriticalSection* FSocketLock;
	void *FGetHostData;
	void *FData;
	AnsiString FService;
	Word FPort;
	bool FClient;
	int FQueueSize;
	bool __fastcall SendStreamPiece(void);
	void __fastcall WndProc(Messages::TMessage &Message);
	MESSAGE void __fastcall CMLookupComplete(TCMLookupComplete &Message);
	MESSAGE void __fastcall CMSocketMessage(TCMSocketMessage &Message);
	MESSAGE void __fastcall CMDeferFree(void *Message);
	void __fastcall DeferFree(void);
	void __fastcall DoSetAsyncStyles(void);
	HWND __fastcall GetHandle(void);
	AnsiString __fastcall GetLocalHost();
	AnsiString __fastcall GetLocalAddress();
	int __fastcall GetLocalPort(void);
	AnsiString __fastcall GetRemoteHost();
	AnsiString __fastcall GetRemoteAddress();
	int __fastcall GetRemotePort(void);
	sockaddr_in __fastcall GetRemoteAddr();
	
protected:
	void __fastcall AsyncInitSocket(const AnsiString Name, const AnsiString Address, const AnsiString Service, Word Port, int QueueSize, bool Client);
	void __fastcall DoOpen(void);
	void __fastcall DoListen(int QueueSize);
	sockaddr_in __fastcall InitSocket(const AnsiString Name, const AnsiString Address, const AnsiString Service, Word Port, bool Client);
	DYNAMIC void __fastcall Event(TCustomWinSocket* Socket, TSocketEvent SocketEvent);
	DYNAMIC void __fastcall Error(TCustomWinSocket* Socket, TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall SetAsyncStyles(TAsyncStyles Value);
	
public:
	__fastcall TCustomWinSocket(int ASocket);
	__fastcall virtual ~TCustomWinSocket(void);
	void __fastcall Close(void);
	virtual void __fastcall DefaultHandler(void *Message);
	void __fastcall Lock(void);
	void __fastcall Unlock(void);
	void __fastcall Listen(const AnsiString Name, const AnsiString Address, const AnsiString Service, Word Port, int QueueSize, bool Block = true);
	void __fastcall Open(const AnsiString Name, const AnsiString Address, const AnsiString Service, Word Port, bool Block = true);
	virtual void __fastcall Accept(int Socket);
	virtual void __fastcall Connect(int Socket);
	virtual void __fastcall Disconnect(int Socket);
	virtual void __fastcall Read(int Socket);
	virtual void __fastcall Write(int Socket);
	in_addr __fastcall LookupName(const AnsiString name);
	int __fastcall LookupService(const AnsiString service);
	int __fastcall ReceiveLength(void);
	int __fastcall ReceiveBuf(void *Buf, int Count);
	AnsiString __fastcall ReceiveText();
	int __fastcall SendBuf(void *Buf, int Count);
	bool __fastcall SendStream(Classes::TStream* AStream);
	bool __fastcall SendStreamThenDrop(Classes::TStream* AStream);
	int __fastcall SendText(const AnsiString S);
	__property AnsiString LocalHost = {read=GetLocalHost};
	__property AnsiString LocalAddress = {read=GetLocalAddress};
	__property int LocalPort = {read=GetLocalPort, nodefault};
	__property AnsiString RemoteHost = {read=GetRemoteHost};
	__property AnsiString RemoteAddress = {read=GetRemoteAddress};
	__property int RemotePort = {read=GetRemotePort, nodefault};
	__property sockaddr_in RemoteAddr = {read=GetRemoteAddr};
	__property bool Connected = {read=FConnected, nodefault};
	__property sockaddr_in Addr = {read=FAddr};
	__property TAsyncStyles ASyncStyles = {read=FAsyncStyles, write=SetAsyncStyles, nodefault};
	__property HWND Handle = {read=GetHandle, nodefault};
	__property int SocketHandle = {read=FSocket, nodefault};
	__property TLookupState LookupState = {read=FLookupState, nodefault};
	__property TSocketEventEvent OnSocketEvent = {read=FOnSocketEvent, write=FOnSocketEvent};
	__property TSocketErrorEvent OnErrorEvent = {read=FOnErrorEvent, write=FOnErrorEvent};
	__property void * Data = {read=FData, write=FData};
};


class DELPHICLASS TClientWinSocket;
class PASCALIMPLEMENTATION TClientWinSocket : public TCustomWinSocket 
{
	typedef TCustomWinSocket inherited;
	
private:
	TClientType FClientType;
	
protected:
	void __fastcall SetClientType(TClientType Value);
	
public:
	virtual void __fastcall Connect(int Socket);
	__property TClientType ClientType = {read=FClientType, write=SetClientType, nodefault};
public:
	#pragma option push -w-inl
	/* TCustomWinSocket.Create */ inline __fastcall TClientWinSocket(int ASocket) : TCustomWinSocket(ASocket) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomWinSocket.Destroy */ inline __fastcall virtual ~TClientWinSocket(void) { }
	#pragma option pop
	
};


class DELPHICLASS TServerWinSocket;
class DELPHICLASS TServerAcceptThread;
class PASCALIMPLEMENTATION TServerAcceptThread : public Classes::TThread 
{
	typedef Classes::TThread inherited;
	
private:
	TServerWinSocket* FServerSocket;
	
public:
	__fastcall TServerAcceptThread(bool CreateSuspended, TServerWinSocket* ASocket);
	virtual void __fastcall Execute(void);
	__property TServerWinSocket* ServerSocket = {read=FServerSocket};
public:
	#pragma option push -w-inl
	/* TThread.Destroy */ inline __fastcall virtual ~TServerAcceptThread(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TThreadNotifyEvent)(System::TObject* Sender, TServerClientThread* Thread);

class PASCALIMPLEMENTATION TServerWinSocket : public TCustomWinSocket 
{
	typedef TCustomWinSocket inherited;
	
private:
	TServerType FServerType;
	int FThreadCacheSize;
	Classes::TList* FConnections;
	Classes::TList* FActiveThreads;
	Syncobjs::TCriticalSection* FListLock;
	TServerAcceptThread* FServerAcceptThread;
	TGetSocketEvent FOnGetSocket;
	TGetThreadEvent FOnGetThread;
	TThreadNotifyEvent FOnThreadStart;
	TThreadNotifyEvent FOnThreadEnd;
	TSocketNotifyEvent FOnClientConnect;
	TSocketNotifyEvent FOnClientDisconnect;
	TSocketNotifyEvent FOnClientRead;
	TSocketNotifyEvent FOnClientWrite;
	TSocketErrorEvent FOnClientError;
	void __fastcall AddClient(TServerClientWinSocket* AClient);
	void __fastcall RemoveClient(TServerClientWinSocket* AClient);
	void __fastcall AddThread(TServerClientThread* AThread);
	void __fastcall RemoveThread(TServerClientThread* AThread);
	void __fastcall ClientEvent(System::TObject* Sender, TCustomWinSocket* Socket, TSocketEvent SocketEvent);
	void __fastcall ClientError(System::TObject* Sender, TCustomWinSocket* Socket, TErrorEvent ErrorEvent, int &ErrorCode);
	int __fastcall GetActiveConnections(void);
	int __fastcall GetActiveThreads(void);
	TCustomWinSocket* __fastcall GetConnections(int Index);
	int __fastcall GetIdleThreads(void);
	
protected:
	virtual TServerClientThread* __fastcall DoCreateThread(TServerClientWinSocket* ClientSocket);
	HIDESBASE void __fastcall Listen(AnsiString &Name, AnsiString &Address, AnsiString &Service, Word Port, int QueueSize);
	void __fastcall SetServerType(TServerType Value);
	void __fastcall SetThreadCacheSize(int Value);
	DYNAMIC void __fastcall ThreadEnd(TServerClientThread* AThread);
	DYNAMIC void __fastcall ThreadStart(TServerClientThread* AThread);
	DYNAMIC TServerClientWinSocket* __fastcall GetClientSocket(int Socket);
	DYNAMIC TServerClientThread* __fastcall GetServerThread(TServerClientWinSocket* ClientSocket);
	DYNAMIC void __fastcall ClientRead(TCustomWinSocket* Socket);
	DYNAMIC void __fastcall ClientWrite(TCustomWinSocket* Socket);
	DYNAMIC void __fastcall ClientConnect(TCustomWinSocket* Socket);
	DYNAMIC void __fastcall ClientDisconnect(TCustomWinSocket* Socket);
	DYNAMIC void __fastcall ClientErrorEvent(TCustomWinSocket* Socket, TErrorEvent ErrorEvent, int &ErrorCode);
	
public:
	__fastcall TServerWinSocket(int ASocket);
	__fastcall virtual ~TServerWinSocket(void);
	virtual void __fastcall Accept(int Socket);
	virtual void __fastcall Disconnect(int Socket);
	TServerClientThread* __fastcall GetClientThread(TServerClientWinSocket* ClientSocket);
	__property int ActiveConnections = {read=GetActiveConnections, nodefault};
	__property int ActiveThreads = {read=GetActiveThreads, nodefault};
	__property TCustomWinSocket* Connections[int Index] = {read=GetConnections};
	__property int IdleThreads = {read=GetIdleThreads, nodefault};
	__property TServerType ServerType = {read=FServerType, write=SetServerType, nodefault};
	__property int ThreadCacheSize = {read=FThreadCacheSize, write=SetThreadCacheSize, nodefault};
	__property TGetSocketEvent OnGetSocket = {read=FOnGetSocket, write=FOnGetSocket};
	__property TGetThreadEvent OnGetThread = {read=FOnGetThread, write=FOnGetThread};
	__property TThreadNotifyEvent OnThreadStart = {read=FOnThreadStart, write=FOnThreadStart};
	__property TThreadNotifyEvent OnThreadEnd = {read=FOnThreadEnd, write=FOnThreadEnd};
	__property TSocketNotifyEvent OnClientConnect = {read=FOnClientConnect, write=FOnClientConnect};
	__property TSocketNotifyEvent OnClientDisconnect = {read=FOnClientDisconnect, write=FOnClientDisconnect};
	__property TSocketNotifyEvent OnClientRead = {read=FOnClientRead, write=FOnClientRead};
	__property TSocketNotifyEvent OnClientWrite = {read=FOnClientWrite, write=FOnClientWrite};
	__property TSocketErrorEvent OnClientError = {read=FOnClientError, write=FOnClientError};
};


class PASCALIMPLEMENTATION TServerClientWinSocket : public TCustomWinSocket 
{
	typedef TCustomWinSocket inherited;
	
private:
	TServerWinSocket* FServerWinSocket;
	
public:
	__fastcall TServerClientWinSocket(int Socket, TServerWinSocket* ServerWinSocket);
	__fastcall virtual ~TServerClientWinSocket(void);
	__property TServerWinSocket* ServerWinSocket = {read=FServerWinSocket};
};


class PASCALIMPLEMENTATION TServerClientThread : public Classes::TThread 
{
	typedef Classes::TThread inherited;
	
private:
	TServerClientWinSocket* FClientSocket;
	TServerWinSocket* FServerSocket;
	Sysutils::Exception* FException;
	Syncobjs::TSimpleEvent* FEvent;
	bool FKeepInCache;
	void *FData;
	void __fastcall HandleEvent(System::TObject* Sender, TCustomWinSocket* Socket, TSocketEvent SocketEvent);
	void __fastcall HandleError(System::TObject* Sender, TCustomWinSocket* Socket, TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall DoHandleException(void);
	void __fastcall DoRead(void);
	void __fastcall DoWrite(void);
	
protected:
	virtual void __fastcall DoTerminate(void);
	virtual void __fastcall Execute(void);
	virtual void __fastcall ClientExecute(void);
	virtual void __fastcall Event(TSocketEvent SocketEvent);
	virtual void __fastcall Error(TErrorEvent ErrorEvent, int &ErrorCode);
	virtual void __fastcall HandleException(void);
	void __fastcall ReActivate(TServerClientWinSocket* ASocket);
	bool __fastcall StartConnect(void);
	bool __fastcall EndConnect(void);
	
public:
	__fastcall TServerClientThread(bool CreateSuspended, TServerClientWinSocket* ASocket);
	__fastcall virtual ~TServerClientThread(void);
	__property TServerClientWinSocket* ClientSocket = {read=FClientSocket};
	__property TServerWinSocket* ServerSocket = {read=FServerSocket};
	__property bool KeepInCache = {read=FKeepInCache, write=FKeepInCache, nodefault};
	__property void * Data = {read=FData, write=FData};
};


class DELPHICLASS TAbstractSocket;
class PASCALIMPLEMENTATION TAbstractSocket : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	bool FActive;
	int FPort;
	AnsiString FAddress;
	AnsiString FHost;
	AnsiString FService;
	void __fastcall DoEvent(System::TObject* Sender, TCustomWinSocket* Socket, TSocketEvent SocketEvent);
	void __fastcall DoError(System::TObject* Sender, TCustomWinSocket* Socket, TErrorEvent ErrorEvent, int &ErrorCode);
	
protected:
	virtual void __fastcall Event(TCustomWinSocket* Socket, TSocketEvent SocketEvent) = 0 ;
	virtual void __fastcall Error(TCustomWinSocket* Socket, TErrorEvent ErrorEvent, int &ErrorCode) = 0 ;
	virtual void __fastcall DoActivate(bool Value) = 0 ;
	void __fastcall InitSocket(TCustomWinSocket* Socket);
	virtual void __fastcall Loaded(void);
	void __fastcall SetActive(bool Value);
	void __fastcall SetAddress(AnsiString Value);
	void __fastcall SetHost(AnsiString Value);
	void __fastcall SetPort(int Value);
	void __fastcall SetService(AnsiString Value);
	__property bool Active = {read=FActive, write=SetActive, nodefault};
	__property AnsiString Address = {read=FAddress, write=SetAddress};
	__property AnsiString Host = {read=FHost, write=SetHost};
	__property int Port = {read=FPort, write=SetPort, nodefault};
	__property AnsiString Service = {read=FService, write=SetService};
	
public:
	void __fastcall Open(void);
	void __fastcall Close(void);
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TAbstractSocket(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TAbstractSocket(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomSocket;
class PASCALIMPLEMENTATION TCustomSocket : public TAbstractSocket 
{
	typedef TAbstractSocket inherited;
	
private:
	TSocketNotifyEvent FOnLookup;
	TSocketNotifyEvent FOnConnect;
	TSocketNotifyEvent FOnConnecting;
	TSocketNotifyEvent FOnDisconnect;
	TSocketNotifyEvent FOnListen;
	TSocketNotifyEvent FOnAccept;
	TSocketNotifyEvent FOnRead;
	TSocketNotifyEvent FOnWrite;
	TSocketErrorEvent FOnError;
	
protected:
	virtual void __fastcall Event(TCustomWinSocket* Socket, TSocketEvent SocketEvent);
	virtual void __fastcall Error(TCustomWinSocket* Socket, TErrorEvent ErrorEvent, int &ErrorCode);
	__property TSocketNotifyEvent OnLookup = {read=FOnLookup, write=FOnLookup};
	__property TSocketNotifyEvent OnConnecting = {read=FOnConnecting, write=FOnConnecting};
	__property TSocketNotifyEvent OnConnect = {read=FOnConnect, write=FOnConnect};
	__property TSocketNotifyEvent OnDisconnect = {read=FOnDisconnect, write=FOnDisconnect};
	__property TSocketNotifyEvent OnListen = {read=FOnListen, write=FOnListen};
	__property TSocketNotifyEvent OnAccept = {read=FOnAccept, write=FOnAccept};
	__property TSocketNotifyEvent OnRead = {read=FOnRead, write=FOnRead};
	__property TSocketNotifyEvent OnWrite = {read=FOnWrite, write=FOnWrite};
	__property TSocketErrorEvent OnError = {read=FOnError, write=FOnError};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TCustomSocket(Classes::TComponent* AOwner) : TAbstractSocket(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCustomSocket(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWinSocketStream;
class PASCALIMPLEMENTATION TWinSocketStream : public Classes::TStream 
{
	typedef Classes::TStream inherited;
	
private:
	TCustomWinSocket* FSocket;
	int FTimeout;
	Syncobjs::TSimpleEvent* FEvent;
	
public:
	__fastcall TWinSocketStream(TCustomWinSocket* ASocket, int TimeOut);
	__fastcall virtual ~TWinSocketStream(void);
	bool __fastcall WaitForData(int Timeout);
	virtual int __fastcall Read(void *Buffer, int Count);
	virtual int __fastcall Write(const void *Buffer, int Count);
	virtual int __fastcall Seek(int Offset, Word Origin)/* overload */;
	__property int TimeOut = {read=FTimeout, write=FTimeout, nodefault};
	
/* Hoisted overloads: */
	
public:
	inline __int64 __fastcall  Seek(const __int64 Offset, Classes::TSeekOrigin Origin){ return TStream::Seek(Offset, Origin); }
	
};


class DELPHICLASS TClientSocket;
class PASCALIMPLEMENTATION TClientSocket : public TCustomSocket 
{
	typedef TCustomSocket inherited;
	
private:
	TClientWinSocket* FClientSocket;
	
protected:
	virtual void __fastcall DoActivate(bool Value);
	TClientType __fastcall GetClientType(void);
	void __fastcall SetClientType(TClientType Value);
	
public:
	__fastcall virtual TClientSocket(Classes::TComponent* AOwner);
	__fastcall virtual ~TClientSocket(void);
	__property TClientWinSocket* Socket = {read=FClientSocket};
	
__published:
	__property Active ;
	__property Address ;
	__property TClientType ClientType = {read=GetClientType, write=SetClientType, nodefault};
	__property Host ;
	__property Port ;
	__property Service ;
	__property OnLookup ;
	__property OnConnecting ;
	__property OnConnect ;
	__property OnDisconnect ;
	__property OnRead ;
	__property OnWrite ;
	__property OnError ;
};


class DELPHICLASS TCustomServerSocket;
class PASCALIMPLEMENTATION TCustomServerSocket : public TCustomSocket 
{
	typedef TCustomSocket inherited;
	
protected:
	TServerWinSocket* FServerSocket;
	virtual void __fastcall DoActivate(bool Value);
	TServerType __fastcall GetServerType(void);
	TGetThreadEvent __fastcall GetGetThreadEvent();
	TGetSocketEvent __fastcall GetGetSocketEvent();
	int __fastcall GetThreadCacheSize(void);
	TThreadNotifyEvent __fastcall GetOnThreadStart();
	TThreadNotifyEvent __fastcall GetOnThreadEnd();
	TSocketNotifyEvent __fastcall GetOnClientEvent(int Index);
	TSocketErrorEvent __fastcall GetOnClientError();
	void __fastcall SetServerType(TServerType Value);
	void __fastcall SetGetThreadEvent(TGetThreadEvent Value);
	void __fastcall SetGetSocketEvent(TGetSocketEvent Value);
	void __fastcall SetThreadCacheSize(int Value);
	void __fastcall SetOnThreadStart(TThreadNotifyEvent Value);
	void __fastcall SetOnThreadEnd(TThreadNotifyEvent Value);
	void __fastcall SetOnClientEvent(int Index, TSocketNotifyEvent Value);
	void __fastcall SetOnClientError(TSocketErrorEvent Value);
	__property TServerType ServerType = {read=GetServerType, write=SetServerType, nodefault};
	__property int ThreadCacheSize = {read=GetThreadCacheSize, write=SetThreadCacheSize, nodefault};
	__property TGetThreadEvent OnGetThread = {read=GetGetThreadEvent, write=SetGetThreadEvent};
	__property TGetSocketEvent OnGetSocket = {read=GetGetSocketEvent, write=SetGetSocketEvent};
	__property TThreadNotifyEvent OnThreadStart = {read=GetOnThreadStart, write=SetOnThreadStart};
	__property TThreadNotifyEvent OnThreadEnd = {read=GetOnThreadEnd, write=SetOnThreadEnd};
	__property TSocketNotifyEvent OnClientConnect = {read=GetOnClientEvent, write=SetOnClientEvent, index=2};
	__property TSocketNotifyEvent OnClientDisconnect = {read=GetOnClientEvent, write=SetOnClientEvent, index=3};
	__property TSocketNotifyEvent OnClientRead = {read=GetOnClientEvent, write=SetOnClientEvent, index=0};
	__property TSocketNotifyEvent OnClientWrite = {read=GetOnClientEvent, write=SetOnClientEvent, index=1};
	__property TSocketErrorEvent OnClientError = {read=GetOnClientError, write=SetOnClientError};
	
public:
	__fastcall virtual ~TCustomServerSocket(void);
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TCustomServerSocket(Classes::TComponent* AOwner) : TCustomSocket(AOwner) { }
	#pragma option pop
	
};


class DELPHICLASS TServerSocket;
class PASCALIMPLEMENTATION TServerSocket : public TCustomServerSocket 
{
	typedef TCustomServerSocket inherited;
	
public:
	__fastcall virtual TServerSocket(Classes::TComponent* AOwner);
	__property TServerWinSocket* Socket = {read=FServerSocket};
	
__published:
	__property Active ;
	__property Port ;
	__property Service ;
	__property ServerType ;
	__property ThreadCacheSize  = {default=10};
	__property OnListen ;
	__property OnAccept ;
	__property OnGetThread ;
	__property OnGetSocket ;
	__property OnThreadStart ;
	__property OnThreadEnd ;
	__property OnClientConnect ;
	__property OnClientDisconnect ;
	__property OnClientRead ;
	__property OnClientWrite ;
	__property OnClientError ;
public:
	#pragma option push -w-inl
	/* TCustomServerSocket.Destroy */ inline __fastcall virtual ~TServerSocket(void) { }
	#pragma option pop
	
};


typedef void __fastcall (*TSocketErrorProc)(int ErrorCode);

//-- var, const, procedure ---------------------------------------------------
static const Word CM_SOCKETMESSAGE = 0x401;
static const Word CM_DEFERFREE = 0x402;
static const Word CM_LOOKUPCOMPLETE = 0x403;
extern PACKAGE TSocketErrorProc __fastcall SetErrorProc(TSocketErrorProc ErrorProc);

}	/* namespace Scktcomp */
using namespace Scktcomp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ScktComp
