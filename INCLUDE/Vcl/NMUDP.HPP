// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NMUDP.pas' rev: 5.00

#ifndef NMUDPHPP
#define NMUDPHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Forms.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <WinSock.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Nmudp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS UDPSockError;
class PASCALIMPLEMENTATION UDPSockError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall UDPSockError(const AnsiString Msg) : Sysutils::Exception(Msg
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall UDPSockError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall UDPSockError(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall UDPSockError(int Ident, const System::TVarRec * Args
		, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall UDPSockError(const AnsiString Msg, int AHelpContext) : 
		Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall UDPSockError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall UDPSockError(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall UDPSockError(System::PResStringRec ResStringRec, 
		const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~UDPSockError(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TOnErrorEvent)(Classes::TComponent* Sender, Word errno, AnsiString 
	Errmsg);

typedef void __fastcall (__closure *TOnStatus)(Classes::TComponent* Sender, AnsiString status);

typedef void __fastcall (__closure *TOnReceive)(Classes::TComponent* Sender, int NumberBytes, AnsiString 
	FromIP, int Port);

typedef void __fastcall (__closure *THandlerEvent)(bool &handled);

typedef void __fastcall (__closure *TBuffInvalid)(bool &handled, char * Buff, const int Buff_Size, int 
	&length);

typedef void __fastcall (__closure *TStreamInvalid)(bool &handled, Classes::TStream* Stream);

class DELPHICLASS TNMUDP;
class PASCALIMPLEMENTATION TNMUDP : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	char IBuff[2049];
	int IBuffSize;
	AnsiString FRemoteHost;
	int FRemotePort;
	int FLocalPort;
	sockaddr_in RemoteAddress;
	sockaddr_in RemoteAddress2;
	HWND FSocketWindow;
	bool Wait_Flag;
	hostent *RemoteHostS;
	bool Canceled;
	bool Succeed;
	WSAData MyWSAData;
	TOnStatus FOnStatus;
	int FReportLevel;
	AnsiString _status;
	bool _ProcMsg;
	int FLastErrorno;
	TOnErrorEvent FOnErrorEvent;
	TOnReceive FOnDataReceived;
	Classes::TNotifyEvent FOnDataSend;
	THandlerEvent FOnInvalidHost;
	TStreamInvalid FOnStreamInvalid;
	TBuffInvalid FOnBufferInvalid;
	void __fastcall WndProc(Messages::TMessage &message);
	void __fastcall ResolveRemoteHost(void);
	virtual void __fastcall Loaded(void);
	void __fastcall SetLocalPort(int NewLocalPort);
	void __fastcall ProcessIncomingdata(void);
	
protected:
	void __fastcall StatusMessage(Byte Level, AnsiString value);
	AnsiString __fastcall ErrorManager(Word ignore);
	AnsiString __fastcall SocketErrorStr(Word Errno);
	
public:
	int ThisSocket;
	__fastcall virtual TNMUDP(Classes::TComponent* AOwner);
	__fastcall virtual ~TNMUDP(void);
	void __fastcall SendStream(Classes::TStream* DataStream);
	void __fastcall SendBuffer(const char * Buff, const int Buff_Size, int length);
	void __fastcall ReadStream(Classes::TStream* DataStream);
	void __fastcall ReadBuffer(char * Buff, const int Buff_Size, int &length);
	
__published:
	__property AnsiString RemoteHost = {read=FRemoteHost, write=FRemoteHost};
	__property int RemotePort = {read=FRemotePort, write=FRemotePort, nodefault};
	__property int LocalPort = {read=FLocalPort, write=SetLocalPort, nodefault};
	__property int ReportLevel = {read=FReportLevel, write=FReportLevel, nodefault};
	__property TOnReceive OnDataReceived = {read=FOnDataReceived, write=FOnDataReceived};
	__property Classes::TNotifyEvent OnDataSend = {read=FOnDataSend, write=FOnDataSend};
	__property TOnStatus OnStatus = {read=FOnStatus, write=FOnStatus};
	__property THandlerEvent OnInvalidHost = {read=FOnInvalidHost, write=FOnInvalidHost};
	__property TStreamInvalid OnStreamInvalid = {read=FOnStreamInvalid, write=FOnStreamInvalid};
	__property TBuffInvalid OnBufferInvalid = {read=FOnBufferInvalid, write=FOnBufferInvalid};
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint Status_None = 0x0;
static const Shortint Status_Informational = 0x1;
static const Shortint Status_Basic = 0x2;
static const Shortint Status_Routines = 0x4;
static const Shortint Status_Debug = 0x8;
static const Shortint Status_Trace = 0x10;
static const Word WM_ASYNCHRONOUSPROCESS = 0x465;
#define Const_cmd_true "TRUE"
extern PACKAGE System::ResourceString _Cons_Palette_Inet;
#define Nmudp_Cons_Palette_Inet System::LoadResourceString(&Nmudp::_Cons_Palette_Inet)
extern PACKAGE System::ResourceString _Cons_Msg_Wsk;
#define Nmudp_Cons_Msg_Wsk System::LoadResourceString(&Nmudp::_Cons_Msg_Wsk)
extern PACKAGE System::ResourceString _Cons_Msg_Lkp;
#define Nmudp_Cons_Msg_Lkp System::LoadResourceString(&Nmudp::_Cons_Msg_Lkp)
extern PACKAGE System::ResourceString _Cons_Msg_Data;
#define Nmudp_Cons_Msg_Data System::LoadResourceString(&Nmudp::_Cons_Msg_Data)
extern PACKAGE System::ResourceString _Cons_Msg_InvStrm;
#define Nmudp_Cons_Msg_InvStrm System::LoadResourceString(&Nmudp::_Cons_Msg_InvStrm)
extern PACKAGE System::ResourceString _Cons_Msg_Echk;
#define Nmudp_Cons_Msg_Echk System::LoadResourceString(&Nmudp::_Cons_Msg_Echk)
extern PACKAGE System::ResourceString _Cons_Msg_Eno;
#define Nmudp_Cons_Msg_Eno System::LoadResourceString(&Nmudp::_Cons_Msg_Eno)
extern PACKAGE System::ResourceString _Cons_Msg_ELkp;
#define Nmudp_Cons_Msg_ELkp System::LoadResourceString(&Nmudp::_Cons_Msg_ELkp)
extern PACKAGE System::ResourceString _Cons_Err_Addr;
#define Nmudp_Cons_Err_Addr System::LoadResourceString(&Nmudp::_Cons_Err_Addr)
extern PACKAGE System::ResourceString _Cons_Err_Buffer;
#define Nmudp_Cons_Err_Buffer System::LoadResourceString(&Nmudp::_Cons_Err_Buffer)

}	/* namespace Nmudp */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Nmudp;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NMUDP
