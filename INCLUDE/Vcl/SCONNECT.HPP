// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SConnect.pas' rev: 5.00

#ifndef SConnectHPP
#define SConnectHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Db.hpp>	// Pascal unit
#include <WinInet.hpp>	// Pascal unit
#include <WinSock.hpp>	// Pascal unit
#include <ScktComp.hpp>	// Pascal unit
#include <MConnect.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#pragma comment(lib, "wininet.lib")

namespace Sconnect
{
//-- type declarations -------------------------------------------------------
__interface IDataBlock;
typedef System::DelphiInterface<IDataBlock> _di_IDataBlock;
__interface INTERFACE_UUID("{CA6564C2-4683-11D1-88D4-00A0248E5091}") IDataBlock  : public IUnknown 
{
	
public:
	virtual int __stdcall GetBytesReserved(void) = 0 ;
	virtual void * __stdcall GetMemory(void) = 0 ;
	virtual int __stdcall GetSize(void) = 0 ;
	virtual void __stdcall SetSize(int Value) = 0 ;
	virtual Classes::TStream* __stdcall GetStream(void) = 0 ;
	virtual int __stdcall GetSignature(void) = 0 ;
	virtual void __stdcall SetSignature(int Value) = 0 ;
	virtual void __stdcall Clear(void) = 0 ;
	virtual int __stdcall Write(const void *Buffer, int Count) = 0 ;
	virtual int __stdcall Read(void *Buffer, int Count) = 0 ;
	virtual void __stdcall IgnoreStream(void) = 0 ;
	virtual int __stdcall InitData(void * Data, int DataLen, bool CheckLen) = 0 ;
	__property int BytesReserved = {read=GetBytesReserved};
	__property void * Memory = {read=GetMemory};
	__property int Signature = {read=GetSignature, write=SetSignature};
	__property int Size = {read=GetSize, write=SetSize};
	__property Classes::TStream* Stream = {read=GetStream};
};

__interface ISendDataBlock;
typedef System::DelphiInterface<ISendDataBlock> _di_ISendDataBlock;
__interface INTERFACE_UUID("{87AD1043-470E-11D1-88D5-00A0248E5091}") ISendDataBlock  : public IUnknown 
	
{
	
public:
	virtual _di_IDataBlock __stdcall Send(const _di_IDataBlock Data, bool WaitForResult) = 0 ;
};

__interface ITransport;
typedef System::DelphiInterface<ITransport> _di_ITransport;
__interface INTERFACE_UUID("{CA6564C1-4683-11D1-88D4-00A0248E5091}") ITransport  : public IUnknown 
{
	
public:
	virtual unsigned __stdcall GetWaitEvent(void) = 0 ;
	virtual bool __stdcall GetConnected(void) = 0 ;
	virtual void __stdcall SetConnected(bool Value) = 0 ;
	virtual _di_IDataBlock __stdcall Receive(bool WaitForInput, int Context) = 0 ;
	virtual int __stdcall Send(const _di_IDataBlock Data) = 0 ;
	__property bool Connected = {read=GetConnected, write=SetConnected};
};

__interface IDataIntercept;
typedef System::DelphiInterface<IDataIntercept> _di_IDataIntercept;
__interface INTERFACE_UUID("{B249776B-E429-11D1-AAA4-00C04FA35CFA}") IDataIntercept  : public IUnknown 
	
{
	
public:
	virtual void __stdcall DataIn(const _di_IDataBlock Data) = 0 ;
	virtual void __stdcall DataOut(const _di_IDataBlock Data) = 0 ;
};

class DELPHICLASS TDataBlock;
class PASCALIMPLEMENTATION TDataBlock : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Classes::TMemoryStream* FStream;
	int FReadPos;
	int FWritePos;
	bool FIgnoreStream;
	
protected:
	int __stdcall GetBytesReserved(void);
	void * __stdcall GetMemory(void);
	int __stdcall GetSize(void);
	void __stdcall SetSize(int Value);
	Classes::TStream* __stdcall GetStream(void);
	int __stdcall GetSignature(void);
	void __stdcall SetSignature(int Value);
	void __stdcall Clear(void);
	int __stdcall Write(const void *Buffer, int Count);
	int __stdcall Read(void *Buffer, int Count);
	void __stdcall IgnoreStream(void);
	int __stdcall InitData(void * Data, int DataLen, bool CheckLen);
	__property int BytesReserved = {read=GetBytesReserved, nodefault};
	__property void * Memory = {read=GetMemory};
	__property int Signature = {read=GetSignature, write=SetSignature, nodefault};
	__property int Size = {read=GetSize, write=SetSize, nodefault};
	__property Classes::TStream* Stream = {read=GetStream};
	
public:
	__fastcall TDataBlock(void);
	__fastcall virtual ~TDataBlock(void);
private:
	void *__IDataBlock;	/* Sconnect::IDataBlock */
	
public:
	operator IDataBlock*(void) { return (IDataBlock*)&__IDataBlock; }
	
};


typedef int TIntArray[1];

typedef int *PIntArray;

typedef OleVariant TVariantArray[1];

typedef OleVariant *PVariantArray;

#pragma option push -b-
enum TVarFlag { vfByRef, vfVariant };
#pragma option pop

typedef Set<TVarFlag, vfByRef, vfVariant>  TVarFlags;

class DELPHICLASS EInterpreterError;
class PASCALIMPLEMENTATION EInterpreterError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInterpreterError(const AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInterpreterError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInterpreterError(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInterpreterError(int Ident, const System::TVarRec * 
		Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInterpreterError(const AnsiString Msg, int AHelpContext
		) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInterpreterError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInterpreterError(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInterpreterError(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInterpreterError(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataBlockInterpreter;
class DELPHICLASS TDataDispatch;
class PASCALIMPLEMENTATION TDataBlockInterpreter : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* FDispatchList;
	OleVariant FDispList;
	_di_ISendDataBlock FSendDataBlock;
	AnsiString FCheckRegValue;
	void * __fastcall GetVariantPointer(const OleVariant &Value);
	void __fastcall CopyDataByRef(const System::TVarData &Source, System::TVarData &Dest);
	OleVariant __fastcall ReadArray(int VType, const _di_IDataBlock Data);
	void __fastcall WriteArray(const OleVariant &Value, const _di_IDataBlock Data);
	void __fastcall DoException(const _di_IDataBlock Data);
	
protected:
	void __fastcall AddDispatch(TDataDispatch* Value);
	void __fastcall RemoveDispatch(TDataDispatch* Value);
	virtual OleVariant __fastcall InternalCreateObject(const GUID &ClassID);
	virtual OleVariant __fastcall CreateObject(const AnsiString Name);
	virtual int __fastcall StoreObject(const OleVariant &Value);
	virtual _di_IDispatch __fastcall LockObject(int ID);
	virtual void __fastcall UnlockObject(int ID, const _di_IDispatch Disp);
	virtual void __fastcall ReleaseObject(int ID);
	virtual bool __fastcall CanCreateObject(const GUID &ClassID);
	void __fastcall CallFreeObject(int DispatchIndex);
	HRESULT __stdcall CallGetIDsOfNames(int DispatchIndex, const GUID &IID, void * Names, int NameCount
		, int LocaleID, void * DispIDs);
	HRESULT __stdcall CallInvoke(int DispatchIndex, int DispID, const GUID &IID, int LocaleID, Word Flags
		, void *Params, void * VarResult, void * ExcepInfo, void * ArgErr);
	OleVariant __fastcall CallGetServerList();
	void __fastcall DoCreateObject(const _di_IDataBlock Data);
	void __fastcall DoFreeObject(const _di_IDataBlock Data);
	void __fastcall DoGetIDsOfNames(const _di_IDataBlock Data);
	void __fastcall DoInvoke(const _di_IDataBlock Data);
	virtual bool __fastcall DoCustomAction(int Action, const _di_IDataBlock Data);
	void __fastcall DoGetAppServerList(const _di_IDataBlock Data);
	void __fastcall DoGetServerList(const _di_IDataBlock Data);
	
public:
	__fastcall TDataBlockInterpreter(_di_ISendDataBlock SendDataBlock, AnsiString CheckRegValue);
	__fastcall virtual ~TDataBlockInterpreter(void);
	OleVariant __fastcall CallCreateObject(AnsiString Name);
	void __fastcall InterpretData(const _di_IDataBlock Data);
	OleVariant __fastcall ReadVariant(/* out */ TVarFlags &Flags, const _di_IDataBlock Data);
	void __fastcall WriteVariant(const OleVariant &Value, const _di_IDataBlock Data);
};


class PASCALIMPLEMENTATION TDataDispatch : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	int FDispatchIndex;
	TDataBlockInterpreter* FInterpreter;
	
protected:
	__property int DispatchIndex = {read=FDispatchIndex, nodefault};
	HRESULT __stdcall GetTypeInfoCount(/* out */ int &Count);
	HRESULT __stdcall GetTypeInfo(int Index, int LocaleID, /* out */ void *TypeInfo);
	HRESULT __stdcall GetIDsOfNames(const GUID &IID, void * Names, int NameCount, int LocaleID, void * 
		DispIDs);
	HRESULT __stdcall Invoke(int DispID, const GUID &IID, int LocaleID, Word Flags, void *Params, void * 
		VarResult, void * ExcepInfo, void * ArgErr);
	
public:
	__fastcall TDataDispatch(TDataBlockInterpreter* Interpreter, int DispatchIndex);
	__fastcall virtual ~TDataDispatch(void);
private:
	void *__IDispatch;	/* IDispatch */
	
public:
	operator IDispatch*(void) { return (IDispatch*)&__IDispatch; }
	
};


class DELPHICLASS TTransportThread;
class PASCALIMPLEMENTATION TTransportThread : public Classes::TThread 
{
	typedef Classes::TThread inherited;
	
private:
	unsigned FParentHandle;
	unsigned FSemaphore;
	_di_ITransport FTransport;
	
public:
	__fastcall virtual TTransportThread(unsigned AHandle, _di_ITransport Transport);
	__fastcall virtual ~TTransportThread(void);
	__property unsigned Semaphore = {read=FSemaphore, nodefault};
	virtual void __fastcall Execute(void);
};


class DELPHICLASS TStreamedConnection;
class PASCALIMPLEMENTATION TStreamedConnection : public Mconnect::TDispatchConnection 
{
	typedef Mconnect::TDispatchConnection inherited;
	
private:
	int FRefCount;
	unsigned FHandle;
	TTransportThread* FTransport;
	_di_ITransport FTransIntf;
	TDataBlockInterpreter* FInterpreter;
	bool FSupportCallbacks;
	unsigned __fastcall GetHandle(void);
	void __fastcall TransportTerminated(System::TObject* Sender);
	void __fastcall SetSupportCallbacks(bool Value);
	
protected:
	HIDESBASE HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	HIDESBASE int __stdcall _AddRef(void);
	HIDESBASE int __stdcall _Release(void);
	_di_IDataBlock __stdcall Send(const _di_IDataBlock Data, bool WaitForResult);
	virtual void __fastcall InternalOpen(void);
	virtual void __fastcall InternalClose(void);
	MESSAGE void __fastcall ThreadReceivedStream(Messages::TMessage &Message);
	MESSAGE void __fastcall ThreadException(Messages::TMessage &Message);
	void __fastcall WndProc(Messages::TMessage &Message);
	virtual _di_ITransport __fastcall CreateTransport();
	virtual void __fastcall DoConnect(void);
	virtual void __fastcall DoDisconnect(void);
	virtual void __fastcall DoError(Sysutils::Exception* E);
	virtual OleVariant __fastcall GetServerList();
	__property TDataBlockInterpreter* Interpreter = {read=FInterpreter};
	__property unsigned Handle = {read=GetHandle, nodefault};
	__property bool SupportCallbacks = {read=FSupportCallbacks, write=SetSupportCallbacks, default=1};
	
public:
	__fastcall virtual TStreamedConnection(Classes::TComponent* AOwner);
	__fastcall virtual ~TStreamedConnection(void);
private:
	void *__ISendDataBlock;	/* Sconnect::ISendDataBlock */
	
public:
	operator ISendDataBlock*(void) { return (ISendDataBlock*)&__ISendDataBlock; }
	
};


class DELPHICLASS ESocketConnectionError;
class PASCALIMPLEMENTATION ESocketConnectionError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ESocketConnectionError(const AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ESocketConnectionError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ESocketConnectionError(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ESocketConnectionError(int Ident, const System::TVarRec 
		* Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ESocketConnectionError(const AnsiString Msg, int AHelpContext
		) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ESocketConnectionError(const AnsiString Msg, const 
		System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size
		, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ESocketConnectionError(int Ident, int AHelpContext)
		/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ESocketConnectionError(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ESocketConnectionError(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSocketTransport;
class PASCALIMPLEMENTATION TSocketTransport : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	unsigned FEvent;
	AnsiString FAddress;
	AnsiString FHost;
	int FPort;
	Scktcomp::TClientSocket* FClientSocket;
	Scktcomp::TCustomWinSocket* FSocket;
	AnsiString FInterceptGUID;
	_di_IDataIntercept FInterceptor;
	bool FCreateAttempted;
	bool __fastcall CheckInterceptor(void);
	void __fastcall InterceptIncoming(const _di_IDataBlock Data);
	void __fastcall InterceptOutgoing(const _di_IDataBlock Data);
	
protected:
	unsigned __stdcall GetWaitEvent(void);
	bool __stdcall GetConnected(void);
	void __stdcall SetConnected(bool Value);
	_di_IDataBlock __stdcall Receive(bool WaitForInput, int Context);
	int __stdcall Send(const _di_IDataBlock Data);
	
public:
	__fastcall TSocketTransport(void);
	__fastcall virtual ~TSocketTransport(void);
	__property AnsiString Host = {read=FHost, write=FHost};
	__property AnsiString Address = {read=FAddress, write=FAddress};
	__property int Port = {read=FPort, write=FPort, nodefault};
	__property Scktcomp::TCustomWinSocket* Socket = {read=FSocket, write=FSocket};
	__property AnsiString InterceptGUID = {read=FInterceptGUID, write=FInterceptGUID};
private:
	void *__ITransport;	/* Sconnect::ITransport */
	
public:
	operator ITransport*(void) { return (ITransport*)&__ITransport; }
	
};


class DELPHICLASS TSocketConnection;
class PASCALIMPLEMENTATION TSocketConnection : public TStreamedConnection 
{
	typedef TStreamedConnection inherited;
	
private:
	AnsiString FAddress;
	AnsiString FHost;
	int FPort;
	AnsiString FInterceptGUID;
	void __fastcall SetAddress(AnsiString Value);
	void __fastcall SetHost(AnsiString Value);
	bool __fastcall IsHostStored(void);
	bool __fastcall IsAddressStored(void);
	
protected:
	virtual _di_ITransport __fastcall CreateTransport();
	virtual void __fastcall DoConnect(void);
	
public:
	__fastcall virtual TSocketConnection(Classes::TComponent* AOwner);
	
__published:
	__property AnsiString Address = {read=FAddress, write=SetAddress, stored=IsAddressStored};
	__property AnsiString Host = {read=FHost, write=SetHost, stored=IsHostStored};
	__property AnsiString InterceptGUID = {read=FInterceptGUID, write=FInterceptGUID};
	__property int Port = {read=FPort, write=FPort, default=211};
	__property SupportCallbacks ;
	__property ObjectBroker ;
public:
	#pragma option push -w-inl
	/* TStreamedConnection.Destroy */ inline __fastcall virtual ~TSocketConnection(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWebConnection;
class PASCALIMPLEMENTATION TWebConnection : public TStreamedConnection 
{
	typedef TStreamedConnection inherited;
	
private:
	AnsiString FAgent;
	AnsiString FUserName;
	AnsiString FPassword;
	AnsiString FURL;
	AnsiString FURLHost;
	AnsiString FURLSite;
	int FURLPort;
	int FURLScheme;
	AnsiString FProxy;
	AnsiString FProxyByPass;
	void *FInetRoot;
	void *FInetConnect;
	TDataBlockInterpreter* FInterpreter;
	void __fastcall Check(bool Error);
	bool __fastcall IsURLStored(void);
	void __fastcall SetURL(const AnsiString Value);
	
protected:
	unsigned __stdcall GetWaitEvent(void);
	bool __stdcall Transport_GetConnected(void);
	void __stdcall Transport_SetConnected(bool Value);
	_di_IDataBlock __stdcall Receive(bool WaitForInput, int Context);
	HIDESBASE int __stdcall Send(const _di_IDataBlock Data);
	virtual _di_ITransport __fastcall CreateTransport();
	virtual void __fastcall DoConnect(void);
	__property SupportCallbacks ;
	
public:
	__fastcall virtual TWebConnection(Classes::TComponent* AOwner);
	__fastcall virtual ~TWebConnection(void);
	
__published:
	__property AnsiString Agent = {read=FAgent, write=FAgent};
	__property AnsiString UserName = {read=FUserName, write=FUserName};
	__property AnsiString Password = {read=FPassword, write=FPassword};
	__property AnsiString URL = {read=FURL, write=SetURL, stored=IsURLStored};
	__property AnsiString Proxy = {read=FProxy, write=FProxy};
	__property AnsiString ProxyByPass = {read=FProxyByPass, write=FProxyByPass};
	__property ObjectBroker ;
private:
	void *__ITransport;	/* Sconnect::ITransport [SetConnected=Transport_SetConnected, GetConnected=Transport_GetConnected
		] */
	
public:
	operator ITransport*(void) { return (ITransport*)&__ITransport; }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word CallSig = 0xda00;
static const Word ResultSig = 0xdb00;
static const Shortint asError = 0x1;
static const Shortint asInvoke = 0x2;
static const Shortint asGetID = 0x3;
static const Shortint asCreateObject = 0x4;
static const Shortint asFreeObject = 0x5;
static const Shortint asGetServers = 0x10;
static const Shortint asGetGUID = 0x11;
static const Shortint asGetAppServers = 0x12;
static const Byte asMask = 0xff;
static const Word THREAD_SENDSTREAM = 0x401;
static const Word THREAD_RECEIVEDSTREAM = 0x402;
static const Word THREAD_EXCEPTION = 0x403;
static const Word THREAD_SENDNOTIFY = 0x404;
static const Word THREAD_REPLACETRANSPORT = 0x405;
extern PACKAGE unsigned __stdcall (*WSACreateEvent)(void);
extern PACKAGE bool __stdcall (*WSAResetEvent)(unsigned hEvent);
extern PACKAGE bool __stdcall (*WSACloseEvent)(unsigned hEvent);
extern PACKAGE int __stdcall (*WSAEventSelect)(int s, unsigned hEventObject, int lNetworkEvents);
extern PACKAGE bool __fastcall LoadWinSock2(void);

}	/* namespace Sconnect */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Sconnect;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SConnect
