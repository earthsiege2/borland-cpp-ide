// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Psock.pas' rev: 6.00

#ifndef PsockHPP
#define PsockHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <NMConst.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <WinSock.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Psock
{
//-- type declarations -------------------------------------------------------
typedef Word TSocket;

#pragma pack(push, 4)
struct TErrorMessage
{
	int ErrorCode;
	System::SmallString<50>  Text;
} ;
#pragma pack(pop)

class DELPHICLASS TNMReg;
class PASCALIMPLEMENTATION TNMReg : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TNMReg(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TNMReg(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TOnErrorEvent)(Classes::TComponent* Sender, Word Errno, AnsiString Errmsg);

typedef void __fastcall (__closure *TOnHostResolved)(Classes::TComponent* Sender);

typedef void __fastcall (__closure *TOnStatus)(Classes::TComponent* Sender, AnsiString Status);

typedef void __fastcall (__closure *THandlerEvent)(bool &Handled);

typedef int *PLongint;

typedef PLongint *PPLongInt;

typedef char * *PPChar;

typedef System::PInteger *PINT;

#pragma pack(push, 4)
struct THostInfo
{
	char *name;
	char * *AliasList;
	int AddressType;
	int AddressSize;
	PLongint *AddressList;
	char Reserved[1024];
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TServerInfo
{
	char *name;
	char * *Aliases;
	int PORT;
	char *Protocol;
	char Reserved[1024];
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TProtocolInfo
{
	char *name;
	char * *Aliases;
	int ProtocolID;
	char Reserved[1024];
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TSocketAddress
{
	int Family;
	Word PORT;
	int Address;
	char Unused[8];
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TSocketList
{
	int Count;
	int DescriptorList[64];
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TTimeValue
{
	int Sec;
	int uSec;
} ;
#pragma pack(pop)

typedef WSAData *PWSAData;

typedef THostInfo *PHostInfo;

typedef TServerInfo *PServerInfo;

typedef TProtocolInfo *PProtocolInfo;

typedef TSocketAddress *PSocketAddress;

typedef TSocketList *PSocketList;

typedef TTimeValue *PTimeValue;

class DELPHICLASS ESockError;
class PASCALIMPLEMENTATION ESockError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ESockError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ESockError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ESockError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ESockError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ESockError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ESockError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ESockError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ESockError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ESockError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EAbortError;
class PASCALIMPLEMENTATION EAbortError : public ESockError 
{
	typedef ESockError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EAbortError(const AnsiString Msg) : ESockError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EAbortError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : ESockError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EAbortError(int Ident)/* overload */ : ESockError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EAbortError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : ESockError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EAbortError(const AnsiString Msg, int AHelpContext) : ESockError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EAbortError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : ESockError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EAbortError(int Ident, int AHelpContext)/* overload */ : ESockError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EAbortError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : ESockError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EAbortError(void) { }
	#pragma option pop
	
};


class DELPHICLASS TThreadTimer;
class PASCALIMPLEMENTATION TThreadTimer : public Classes::TComponent 
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
	void __fastcall Wndproc(Messages::TMessage &Msg);
	
protected:
	DYNAMIC void __fastcall Timer(void);
	
public:
	__fastcall virtual TThreadTimer(Classes::TComponent* AOwner);
	__fastcall virtual ~TThreadTimer(void);
	
__published:
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property unsigned Interval = {read=FInterval, write=SetInterval, default=1000};
	__property Classes::TNotifyEvent OnTimer = {read=FOnTimer, write=SetOnTimer};
};


class DELPHICLASS TPowersock;
class PASCALIMPLEMENTATION TPowersock : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	char Buf[65537];
	TNMReg* FAbout;
	Classes::TNotifyEvent FOnReadEvent;
	Classes::TNotifyEvent FOnAcceptEvent;
	Classes::TNotifyEvent FOnConnect;
	Classes::TNotifyEvent FOnDisconnect;
	TOnErrorEvent FOnErrorEvent;
	THandlerEvent FInvalidHost;
	TOnHostResolved FOnHostResolved;
	THandlerEvent FOnConnectionRequired;
	TOnStatus FOnStatus;
	Classes::TNotifyEvent FOnConnectionFailed;
	Classes::TStringList* FWSAInfo;
	int FBytesSent;
	bool Canceled;
	bool DestroySocket;
	int FLastErrorno;
	int FTimeOut;
	int FReportLevel;
	AnsiString _Status;
	AnsiString FProxy;
	int FProxyPort;
	TThreadTimer* Timer;
	void __fastcall TimerFired(System::TObject* Sender);
	void __fastcall Wndproc(Messages::TMessage &message);
	
protected:
	bool Succeed;
	bool TimedOut;
	int FPort;
	int FBytesTotal;
	int FBytesRecvd;
	Classes::TNotifyEvent FPacketRecvd;
	Classes::TNotifyEvent FPacketSent;
	bool Wait_Flag;
	WSAData MyWSAData;
	sockaddr_in RemoteAddress;
	AnsiString ServerName;
	hostent *RemoteHost;
	AnsiString FTransactionReply;
	short FReplyNumber;
	bool DataGate;
	bool AbortGate;
	bool StrmType;
	Classes::TNotifyEvent OnAbortrestart;
	void __fastcall TimerOn(void);
	void __fastcall TimerOff(void);
	void __fastcall InitWinsock(void);
	void __fastcall SetLastErrorNo(int Value);
	AnsiString __fastcall SocketErrorStr(Word Errno);
	int __fastcall GetLastErrorNo(void);
	AnsiString __fastcall ErrorManager(Word Ignore);
	void __fastcall SetWSAError(Word ErrorNo, AnsiString ErrorMsg);
	void __fastcall StatusMessage(Byte Level, AnsiString Value);
	AnsiString __fastcall GetRemoteIP();
	AnsiString __fastcall GetLocalIP();
	__property Classes::TNotifyEvent OnAccept = {read=FOnAcceptEvent, write=FOnAcceptEvent};
	__property TOnErrorEvent OnError = {read=FOnErrorEvent, write=FOnErrorEvent};
	__property THandlerEvent OnConnectionRequired = {read=FOnConnectionRequired, write=FOnConnectionRequired};
	__property AnsiString Proxy = {read=FProxy, write=FProxy};
	__property int ProxyPort = {read=FProxyPort, write=FProxyPort, nodefault};
	
public:
	Word ThisSocket;
	HWND FSocketWindow;
	bool FConnected;
	__fastcall virtual TPowersock(Classes::TComponent* AOwner);
	__fastcall virtual ~TPowersock(void);
	virtual Word __fastcall Accept(void);
	void __fastcall Cancel(void);
	virtual void __fastcall Connect(void);
	virtual void __fastcall Disconnect(void);
	void __fastcall Listen(bool sync);
	void __fastcall SendBuffer(char * Value, Word BufLen);
	void __fastcall Write(AnsiString Value);
	void __fastcall Writeln(AnsiString Value);
	AnsiString __fastcall Read(Word Value);
	AnsiString __fastcall ReadLn();
	virtual AnsiString __fastcall Transaction(const AnsiString CommandString);
	void __fastcall SendFile(AnsiString Filename);
	void __fastcall SendStream(Classes::TStream* MainStream);
	void __fastcall CaptureFile(AnsiString Filename);
	void __fastcall AppendFile(AnsiString Filename);
	void __fastcall CaptureStream(Classes::TStream* MainStream, int Size);
	void __fastcall CaptureString(AnsiString &AString, int Size);
	void __fastcall FilterHeader(Classes::TFileStream* HeaderStream);
	void __fastcall ResolveRemoteHost(void);
	void __fastcall RequestCloseSocket(void);
	void __fastcall Close(unsigned Socket);
	virtual void __fastcall Abort(void);
	void __fastcall CertifyConnect(void);
	bool __fastcall DataAvailable(void);
	void __fastcall ClearInput(void);
	AnsiString __fastcall GetLocalAddress();
	AnsiString __fastcall GetPortString();
	__property Classes::TStringList* WSAInfo = {read=FWSAInfo};
	__property bool Connected = {read=FConnected, nodefault};
	__property int LastErrorNo = {read=GetLastErrorNo, write=SetLastErrorNo, nodefault};
	__property bool BeenCanceled = {read=Canceled, write=Canceled, nodefault};
	__property bool BeenTimedOut = {read=TimedOut, nodefault};
	__property short ReplyNumber = {read=FReplyNumber, nodefault};
	__property AnsiString RemoteIP = {read=GetRemoteIP};
	__property AnsiString LocalIP = {read=GetLocalIP};
	__property AnsiString TransactionReply = {read=FTransactionReply};
	__property int BytesTotal = {read=FBytesTotal, nodefault};
	__property int BytesSent = {read=FBytesSent, nodefault};
	__property int BytesRecvd = {read=FBytesRecvd, nodefault};
	__property Word Handle = {read=ThisSocket, nodefault};
	__property AnsiString Status = {read=_Status};
	__property Classes::TNotifyEvent OnRead = {read=FOnReadEvent, write=FOnReadEvent};
	__property Classes::TNotifyEvent OnPacketRecvd = {read=FPacketRecvd, write=FPacketRecvd};
	__property Classes::TNotifyEvent OnPacketSent = {read=FPacketSent, write=FPacketSent};
	
__published:
	__property AnsiString Host = {read=ServerName, write=ServerName};
	__property int Port = {read=FPort, write=FPort, nodefault};
	__property int TimeOut = {read=FTimeOut, write=FTimeOut, default=0};
	__property int ReportLevel = {read=FReportLevel, write=FReportLevel, default=1};
	__property Classes::TNotifyEvent OnDisconnect = {read=FOnDisconnect, write=FOnDisconnect};
	__property Classes::TNotifyEvent OnConnect = {read=FOnConnect, write=FOnConnect};
	__property THandlerEvent OnInvalidHost = {read=FInvalidHost, write=FInvalidHost};
	__property TOnHostResolved OnHostResolved = {read=FOnHostResolved, write=FOnHostResolved};
	__property TOnStatus OnStatus = {read=FOnStatus, write=FOnStatus};
	__property Classes::TNotifyEvent OnConnectionFailed = {read=FOnConnectionFailed, write=FOnConnectionFailed};
	__property TNMReg* About = {read=FAbout, write=FAbout};
};


class DELPHICLASS TNMGeneralServer;
typedef TNMGeneralServer* *PTNMGeneralServer;

class PASCALIMPLEMENTATION TNMGeneralServer : public TPowersock 
{
	typedef TPowersock inherited;
	
private:
	Classes::TThreadList* ATlist;
	Classes::TNotifyEvent FOnClientContact;
	
protected:
	TNMGeneralServer* Chief;
	
public:
	Classes::TThread* ItsThread;
	__fastcall virtual TNMGeneralServer(Classes::TComponent* AOwner);
	virtual void __fastcall Connect(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Serve(void);
	virtual void __fastcall Abort(void);
	__fastcall virtual ~TNMGeneralServer(void);
	void __fastcall ServerAccept(System::TObject* Sender);
	
__published:
	__property Classes::TNotifyEvent OnClientContact = {read=FOnClientContact, write=FOnClientContact};
};


class DELPHICLASS InstantiateServethread;
class PASCALIMPLEMENTATION InstantiateServethread : public Classes::TThread 
{
	typedef Classes::TThread inherited;
	
private:
	TNMGeneralServer* ServSock;
	
protected:
	virtual void __fastcall Execute(void);
	
public:
	__fastcall InstantiateServethread(Classes::TComponent* Owner, Word ItsSocket);
	__fastcall virtual ~InstantiateServethread(void);
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint FD_ALL = 0x3f;
static const int MAX_RECV_BUF = 0x10000;
static const Shortint Status_None = 0x0;
static const Shortint Status_Informational = 0x1;
static const Shortint Status_Basic = 0x2;
static const Shortint Status_Routines = 0x4;
static const Shortint Status_Debug = 0x8;
static const Shortint Status_Trace = 0x10;
static const char CR = '\xd';
static const char LF = '\xa';
#define CRLF "\r\n"
static const Word WM_ASYNCHRONOUSPROCESS = 0x465;
static const Word WM_WAITFORRESPONSE = 0x466;
extern PACKAGE TErrorMessage WinsockMessage[51];
extern PACKAGE AnsiString __fastcall NthWord(AnsiString InputString, char Delimiter, int Number);
extern PACKAGE int __fastcall NthPos(AnsiString InputString, char Delimiter, int Number);
extern PACKAGE void __fastcall StreamLn(Classes::TStream* AStream, AnsiString AString);
extern PACKAGE HWND __fastcall PsockAllocateHWnd(System::TObject* Obj);
extern PACKAGE HWND __fastcall TmrAllocateHWnd(System::TObject* Obj);

}	/* namespace Psock */
using namespace Psock;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Psock
