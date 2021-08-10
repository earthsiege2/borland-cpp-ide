// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Sockets.pas' rev: 6.00

#ifndef SocketsHPP
#define SocketsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <WinSock.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Sockets
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TSocketDomain { pfUnspec, pfUnix, pfInet, pfImpLink, pfPup, pfChaos, pfIpx, pfNs, pfIso, pfOsi, pfEcma, pfDataKit, pfCcitt, pfSna, pfDecNet, pfDli, pfLat, pfHylink, pfAppleTalk, pfVoiceView, pfFireFox, pfUnknown1, pfBan, pfMax };
#pragma option pop

typedef Word TSocketProtocol;

#pragma option push -b-
enum TServerSocketBlockMode { bmBlocking, bmNonBlocking, bmThreadBlocking };
#pragma option pop

typedef TServerSocketBlockMode TSocketBlockMode;

#pragma option push -b-
enum TSocketType { stStream, stDgram, stRaw, stRdm, stSeqPacket };
#pragma option pop

typedef void __fastcall (__closure *TSocketNotifyEvent)(System::TObject* Sender);

typedef void __fastcall (__closure *TSocketDataEvent)(System::TObject* Sender, char * Buf, int &DataLen);

typedef void __fastcall (__closure *TSocketErrorEvent)(System::TObject* Sender, int SocketError);

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


class DELPHICLASS TBaseSocket;
class PASCALIMPLEMENTATION TBaseSocket : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	bool FActive;
	TServerSocketBlockMode FBlockMode;
	unsigned FBytesReceived;
	unsigned FBytesSent;
	TSocketDomain FDomain;
	Word FProtocol;
	int FSocket;
	TSocketType FSockType;
	TSocketNotifyEvent FOnCreateHandle;
	TSocketNotifyEvent FOnDestroyHandle;
	TSocketErrorEvent FOnError;
	TSocketDataEvent FOnReceive;
	TSocketDataEvent FOnSend;
	void __fastcall SetActive(bool Value);
	void __fastcall SetBlockMode(TSocketBlockMode Value);
	void __fastcall SetDomain(TSocketDomain Value);
	void __fastcall SetProtocol(Word Value);
	void __fastcall SetSockType(TSocketType Value);
	
protected:
	DYNAMIC void __fastcall DoCreateHandle(void);
	DYNAMIC void __fastcall DoDestroyHandle(void);
	DYNAMIC void __fastcall DoHandleError(void);
	virtual void __fastcall DoReceive(char * Buf, int &DataLen);
	virtual void __fastcall DoSend(char * Buf, int &DataLen);
	virtual int __fastcall ErrorCheck(int rc);
	virtual void __fastcall Loaded(void);
	void __fastcall SetBytesReceived(unsigned Value);
	void __fastcall SetBytesSent(unsigned Value);
	
public:
	__fastcall virtual TBaseSocket(Classes::TComponent* AOwner);
	__fastcall virtual ~TBaseSocket(void);
	virtual void __fastcall Open(void);
	virtual void __fastcall Close(void);
	int __fastcall MapDomain(TSocketDomain sd);
	int __fastcall MapSockType(TSocketType st);
	int __fastcall PeekBuf(void *Buf, int BufSize);
	int __fastcall ReceiveBuf(void *Buf, int BufSize, int Flags = 0x0);
	AnsiString __fastcall Receiveln(const AnsiString eol = "\r\n");
	bool __fastcall Select(System::PBoolean ReadReady, System::PBoolean WriteReady, System::PBoolean ExceptFlag, int TimeOut = 0x0);
	int __fastcall SendBuf(void *Buf, int BufSize, int Flags = 0x0);
	int __fastcall Sendln(AnsiString s, const AnsiString eol = "\r\n");
	int __fastcall SendStream(Classes::TStream* AStream);
	bool __fastcall WaitForData(int TimeOut = 0x0);
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property TSocketBlockMode BlockMode = {read=FBlockMode, write=SetBlockMode, default=0};
	__property unsigned BytesReceived = {read=FBytesReceived, nodefault};
	__property unsigned BytesSent = {read=FBytesSent, nodefault};
	__property TSocketDomain Domain = {read=FDomain, write=SetDomain, default=0};
	__property int Handle = {read=FSocket, nodefault};
	__property Word Protocol = {read=FProtocol, write=SetProtocol, nodefault};
	__property TSocketType SockType = {read=FSockType, write=SetSockType, default=0};
	__property TSocketNotifyEvent OnCreateHandle = {read=FOnCreateHandle, write=FOnCreateHandle};
	__property TSocketNotifyEvent OnDestroyHandle = {read=FOnDestroyHandle, write=FOnDestroyHandle};
	__property TSocketErrorEvent OnError = {read=FOnError, write=FOnError};
	__property TSocketDataEvent OnReceive = {read=FOnReceive, write=FOnReceive};
	__property TSocketDataEvent OnSend = {read=FOnSend, write=FOnSend};
};


#pragma pack(push, 1)
struct TIPHeader
{
	Byte iph_verlen;
	Byte iph_tos;
	Word iph_length;
	Word iph_id;
	Word iph_offset;
	Byte iph_ttl;
	Byte iph_protocol;
	Word iph_xsum;
	unsigned iph_src;
	unsigned iph_dest;
} ;
#pragma pack(pop)

typedef AnsiString TSocketHost;

typedef AnsiString TSocketPort;

class DELPHICLASS TIpSocket;
class PASCALIMPLEMENTATION TIpSocket : public TBaseSocket 
{
	typedef TBaseSocket inherited;
	
private:
	AnsiString FLocalHost;
	AnsiString FLocalPort;
	AnsiString FRemoteHost;
	AnsiString FRemotePort;
	void __fastcall SetLocalHost(AnsiString Value);
	void __fastcall SetLocalPort(AnsiString Value);
	void __fastcall SetRemoteHost(AnsiString Value);
	void __fastcall SetRemotePort(AnsiString Value);
	
protected:
	bool __fastcall Bind(void);
	
public:
	__fastcall virtual TIpSocket(Classes::TComponent* AOwner);
	sockaddr_in __fastcall GetSocketAddr(AnsiString h, AnsiString p);
	AnsiString __fastcall LookupHostName(const AnsiString ipaddr);
	AnsiString __fastcall LookupHostAddr(const AnsiString hn);
	Word __fastcall LookupPort(const AnsiString sn, char * pn = (void *)(0x0));
	Word __fastcall LookupProtocol(const AnsiString pn);
	AnsiString __fastcall LocalDomainName();
	AnsiString __fastcall LocalHostName();
	AnsiString __fastcall LocalHostAddr();
	int __fastcall ReceiveFrom(void *buf, int bufsize, const sockaddr_in &ToAddr, int &len, int flags = 0x0);
	int __fastcall SendTo(void *buf, int bufsize, const sockaddr_in &ToAddr, int flags = 0x0);
	__property AnsiString LocalHost = {read=FLocalHost, write=SetLocalHost};
	__property AnsiString LocalPort = {read=FLocalPort, write=SetLocalPort};
	__property AnsiString RemoteHost = {read=FRemoteHost, write=SetRemoteHost};
	__property AnsiString RemotePort = {read=FRemotePort, write=SetRemotePort};
	__property Domain  = {default=2};
public:
	#pragma option push -w-inl
	/* TBaseSocket.Destroy */ inline __fastcall virtual ~TIpSocket(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomIpClient;
class DELPHICLASS TClientSocketThread;
class PASCALIMPLEMENTATION TCustomIpClient : public TIpSocket 
{
	typedef TIpSocket inherited;
	
private:
	bool FConnected;
	TSocketNotifyEvent FOnConnect;
	TSocketNotifyEvent FOnDisconnect;
	
protected:
	virtual void __fastcall DoConnect(void);
	virtual void __fastcall DoDisconnect(void);
	
public:
	__fastcall virtual TCustomIpClient(Classes::TComponent* AOwner);
	virtual void __fastcall Open(void);
	virtual void __fastcall Close(void);
	bool __fastcall Connect(void);
	void __fastcall Disconnect(void);
	TClientSocketThread* __fastcall GetThreadObject(void);
	__property bool Connected = {read=FConnected, nodefault};
	__property TSocketNotifyEvent OnConnect = {read=FOnConnect, write=FOnConnect};
	__property TSocketNotifyEvent OnDisconnect = {read=FOnDisconnect, write=FOnDisconnect};
public:
	#pragma option push -w-inl
	/* TBaseSocket.Destroy */ inline __fastcall virtual ~TCustomIpClient(void) { }
	#pragma option pop
	
};


class DELPHICLASS TRawSocket;
class PASCALIMPLEMENTATION TRawSocket : public TIpSocket 
{
	typedef TIpSocket inherited;
	
public:
	__fastcall virtual TRawSocket(Classes::TComponent* AOwner);
	__property SockType  = {default=2};
public:
	#pragma option push -w-inl
	/* TBaseSocket.Destroy */ inline __fastcall virtual ~TRawSocket(void) { }
	#pragma option pop
	
};


class DELPHICLASS TUdpSocket;
class PASCALIMPLEMENTATION TUdpSocket : public TCustomIpClient 
{
	typedef TCustomIpClient inherited;
	
public:
	__fastcall virtual TUdpSocket(Classes::TComponent* AOwner);
	
__published:
	__property Active  = {default=0};
	__property BlockMode  = {default=0};
	__property LocalHost ;
	__property LocalPort ;
	__property RemoteHost ;
	__property RemotePort ;
	__property OnCreateHandle ;
	__property OnDestroyHandle ;
	__property OnConnect ;
	__property OnDisconnect ;
	__property OnReceive ;
	__property OnSend ;
	__property OnError ;
public:
	#pragma option push -w-inl
	/* TBaseSocket.Destroy */ inline __fastcall virtual ~TUdpSocket(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTcpClient;
class PASCALIMPLEMENTATION TTcpClient : public TCustomIpClient 
{
	typedef TCustomIpClient inherited;
	
__published:
	__property Active  = {default=0};
	__property BlockMode  = {default=0};
	__property Connected ;
	__property RemoteHost ;
	__property RemotePort ;
	__property OnCreateHandle ;
	__property OnDestroyHandle ;
	__property OnConnect ;
	__property OnDisconnect ;
	__property OnReceive ;
	__property OnSend ;
	__property OnError ;
public:
	#pragma option push -w-inl
	/* TCustomIpClient.Create */ inline __fastcall virtual TTcpClient(Classes::TComponent* AOwner) : TCustomIpClient(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TBaseSocket.Destroy */ inline __fastcall virtual ~TTcpClient(void) { }
	#pragma option pop
	
};


class DELPHICLASS TServerSocketThread;
class DELPHICLASS TCustomTcpServer;
typedef void __fastcall (__closure *TSocketAcceptEvent)(System::TObject* Sender, TCustomIpClient* ClientSocket);

typedef void __fastcall (__closure *TGetThreadEvent)(System::TObject* Sender, TClientSocketThread* &ClientSocketThread);

class PASCALIMPLEMENTATION TCustomTcpServer : public TIpSocket 
{
	typedef TIpSocket inherited;
	
private:
	TServerSocketBlockMode FServerBlockMode;
	bool FListening;
	TServerSocketThread* FServerSocketThread;
	TSocketAcceptEvent FOnAccept;
	TGetThreadEvent FOnGetThread;
	Classes::TNotifyEvent FOnListening;
	void __fastcall GetThread(System::TObject* Sender, TClientSocketThread* &ClientSocketThread);
	TServerSocketThread* __fastcall GetServerSocketThread(void);
	void __fastcall SetServerSocketThread(TServerSocketThread* Value);
	void __fastcall SetServerBlockMode(TServerSocketBlockMode Value);
	
protected:
	virtual void __fastcall DoAccept(TCustomIpClient* ClientSocket);
	bool __fastcall Listen(int backlog = 0x5);
	
public:
	__fastcall virtual TCustomTcpServer(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomTcpServer(void);
	virtual void __fastcall Open(void);
	virtual void __fastcall Close(void);
	bool __fastcall Accept(void)/* overload */;
	bool __fastcall Accept(TCustomIpClient* &ClientSocket)/* overload */;
	bool __fastcall WaitForConnection(void);
	__property TServerSocketBlockMode BlockMode = {read=FServerBlockMode, write=SetServerBlockMode, default=2};
	__property bool Listening = {read=FListening, nodefault};
	__property TServerSocketThread* ServerSocketThread = {read=GetServerSocketThread, write=SetServerSocketThread};
	__property TSocketAcceptEvent OnAccept = {read=FOnAccept, write=FOnAccept};
	__property TGetThreadEvent OnGetThread = {read=FOnGetThread, write=FOnGetThread};
	__property Classes::TNotifyEvent OnListening = {read=FOnListening, write=FOnListening};
};


class PASCALIMPLEMENTATION TServerSocketThread : public Classes::TThread 
{
	typedef Classes::TThread inherited;
	
private:
	int FPoolIndex;
	TCustomTcpServer* FServerSocket;
	int FThreadCacheSize;
	Classes::TList* FThreadPool;
	TGetThreadEvent FOnGetThread;
	void __fastcall SetThreadCacheSize(int Value);
	
protected:
	TClientSocketThread* __fastcall AddClientSocketThread(void);
	virtual TClientSocketThread* __fastcall CreateThread(void);
	TClientSocketThread* __fastcall FetchClientSocketThread(void);
	void __fastcall RemoveClientSocketThread(TClientSocketThread* ClientSocketThread);
	
public:
	__fastcall TServerSocketThread(TCustomTcpServer* AServerSocket);
	__fastcall virtual ~TServerSocketThread(void);
	void __fastcall ClearThreadPool(void);
	virtual void __fastcall Execute(void);
	__property TCustomTcpServer* ServerSocket = {read=FServerSocket};
	__property int ThreadCacheSize = {read=FThreadCacheSize, write=SetThreadCacheSize, default=10};
	__property Classes::TList* ThreadPool = {read=FThreadPool};
	__property TGetThreadEvent OnGetThread = {read=FOnGetThread, write=FOnGetThread};
};


class PASCALIMPLEMENTATION TClientSocketThread : public Classes::TThread 
{
	typedef Classes::TThread inherited;
	
private:
	TCustomIpClient* FClientSocket;
	TServerSocketThread* FServerSocketThread;
	
protected:
	virtual void __fastcall SyncProc(void);
	
public:
	__fastcall TClientSocketThread(TServerSocketThread* ServerSocketThread);
	__fastcall virtual ~TClientSocketThread(void);
	virtual void __fastcall Execute(void);
	void __fastcall ExecuteSyncProc(void);
	__property TCustomIpClient* ClientSocket = {read=FClientSocket};
	__property TServerSocketThread* ServerSocketThread = {read=FServerSocketThread};
};


class DELPHICLASS TTcpServer;
class PASCALIMPLEMENTATION TTcpServer : public TCustomTcpServer 
{
	typedef TCustomTcpServer inherited;
	
__published:
	__property Active  = {default=0};
	__property BlockMode  = {default=2};
	__property LocalHost ;
	__property LocalPort ;
	__property OnAccept ;
	__property OnGetThread ;
	__property OnListening ;
	__property OnCreateHandle ;
	__property OnDestroyHandle ;
public:
	#pragma option push -w-inl
	/* TCustomTcpServer.Create */ inline __fastcall virtual TTcpServer(Classes::TComponent* AOwner) : TCustomTcpServer(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomTcpServer.Destroy */ inline __fastcall virtual ~TTcpServer(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define CRLF "\r\n"

}	/* namespace Sockets */
using namespace Sockets;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Sockets
