// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdTCPConnection.pas' rev: 6.00

#ifndef IdTCPConnectionHPP
#define IdTCPConnectionHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdIntercept.hpp>	// Pascal unit
#include <IdSocketHandle.hpp>	// Pascal unit
#include <IdGlobal.hpp>	// Pascal unit
#include <IdComponent.hpp>	// Pascal unit
#include <IdException.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idtcpconnection
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdBuffer;
class PASCALIMPLEMENTATION TIdBuffer : public Classes::TMemoryStream 
{
	typedef Classes::TMemoryStream inherited;
	
public:
	void __fastcall RemoveXBytes(const int AByteCount);
public:
	#pragma option push -w-inl
	/* TMemoryStream.Destroy */ inline __fastcall virtual ~TIdBuffer(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TIdBuffer(void) : Classes::TMemoryStream() { }
	#pragma option pop
	
};


class DELPHICLASS TIdTCPConnection;
class PASCALIMPLEMENTATION TIdTCPConnection : public Idcomponent::TIdComponent 
{
	typedef Idcomponent::TIdComponent inherited;
	
protected:
	bool FASCIIFilter;
	Idsockethandle::TIdSocketHandle* FBinding;
	TIdBuffer* FBuffer;
	bool FClosedGracefully;
	Classes::TStrings* FCmdResultDetails;
	Idintercept::TIdConnectionIntercept* FIntercept;
	bool FInterceptEnabled;
	Classes::TNotifyEvent FOnDisconnected;
	bool FReadLnTimedOut;
	TIdBuffer* FRecvBuffer;
	short FResultNo;
	int FSendBufferSize;
	TIdBuffer* FWriteBuffer;
	int FWriteBufferThreshhold;
	virtual void __fastcall DoOnDisconnected(void);
	AnsiString __fastcall GetCmdResult();
	int __fastcall GetRecvBufferSize(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall ResetConnection(void);
	void __fastcall SetIntercept(Idintercept::TIdConnectionIntercept* AValue);
	void __fastcall SetInterceptEnabled(bool AValue);
	void __fastcall SetRecvBufferSize(const int Value);
	
public:
	virtual AnsiString __fastcall AllData();
	void __fastcall CancelWriteBuffer(void);
	void __fastcall Capture(System::TObject* ADest, const AnsiString ADelim = ".", const bool AIsRFCMessage = false);
	virtual void __fastcall CheckForDisconnect(const bool ARaiseExceptionIfDisconnected = true, const bool AIgnoreBuffer = false);
	virtual void __fastcall CheckForGracefulDisconnect(const bool ARaiseExceptionIfDisconnected = true);
	virtual short __fastcall CheckResponse(const short AResponse, const short * AAllowedResponses, const int AAllowedResponses_Size);
	void __fastcall ClearWriteBuffer(void);
	void __fastcall CloseWriteBuffer(void);
	virtual bool __fastcall Connected(void);
	__fastcall virtual TIdTCPConnection(Classes::TComponent* AOwner);
	AnsiString __fastcall CurrentReadBuffer();
	int __fastcall CurrentReadBufferSize(void);
	__fastcall virtual ~TIdTCPConnection(void);
	virtual void __fastcall Disconnect(void);
	virtual void __fastcall DisconnectSocket(void);
	virtual AnsiString __fastcall ExtractXBytesFromBuffer(const int AByteCount);
	void __fastcall FlushWriteBuffer(const int AByteCount = 0xffffffff);
	virtual short __fastcall GetResponse(const short * AAllowedResponses, const int AAllowedResponses_Size);
	AnsiString __fastcall InputLn(const AnsiString AMask = "");
	void __fastcall OpenWriteBuffer(const int AThreshhold = 0xffffffff);
	virtual void __fastcall RaiseExceptionForCmdResult(void)/* overload */;
	virtual void __fastcall RaiseExceptionForCmdResult(TMetaClass* axException)/* overload */;
	void __fastcall ReadBuffer(void *ABuffer, const int AByteCount);
	unsigned __fastcall ReadCardinal(const bool AConvert = true);
	virtual int __fastcall ReadFromStack(const bool ARaiseExceptionIfDisconnected = true, const int ATimeout = 0xfffffffe, const bool AUseBuffer = true, TIdBuffer* ADestStream = (TIdBuffer*)(0x0));
	int __fastcall ReadInteger(const bool AConvert = true);
	virtual AnsiString __fastcall ReadLn(const AnsiString ATerminator = "", const int ATimeout = 0xfffffffe);
	AnsiString __fastcall ReadLnWait();
	short __fastcall ReadSmallInt(const bool AConvert = true);
	void __fastcall ReadStream(Classes::TStream* AStream, int AByteCount = 0xffffffff, const bool AReadUntilDisconnect = false);
	AnsiString __fastcall ReadString(const int ABytes);
	virtual void __fastcall RemoveXBytesFromBuffer(const int AByteCount);
	short __fastcall SendCmd(const AnsiString AOut, const short AResponse = (short)(0xffffffff))/* overload */;
	virtual short __fastcall SendCmd(const AnsiString AOut, const short * AResponse, const int AResponse_Size)/* overload */;
	AnsiString __fastcall WaitFor(const AnsiString AString);
	virtual void __fastcall Write(AnsiString AOut);
	void __fastcall WriteBuffer(const void *ABuffer, int AByteCount, const bool AWriteNow = false);
	void __fastcall WriteCardinal(unsigned AValue, const bool AConvert = true);
	void __fastcall WriteHeader(Classes::TStrings* axHeader);
	void __fastcall WriteInteger(int AValue, const bool AConvert = true);
	virtual void __fastcall WriteLn(const AnsiString AOut = "");
	void __fastcall WriteSmallInt(short AValue, const bool AConvert = true);
	virtual void __fastcall WriteStream(Classes::TStream* AStream, const bool AAll = true, const bool AWriteByteCount = false);
	void __fastcall WriteStrings(Classes::TStrings* AValue);
	virtual unsigned __fastcall WriteFile(AnsiString AFile, const bool AEnableTransferFile = false);
	__property Idsockethandle::TIdSocketHandle* Binding = {read=FBinding};
	__property bool ClosedGracefully = {read=FClosedGracefully, nodefault};
	__property AnsiString CmdResult = {read=GetCmdResult};
	__property Classes::TStrings* CmdResultDetails = {read=FCmdResultDetails};
	__property bool ReadLnTimedOut = {read=FReadLnTimedOut, nodefault};
	__property short ResultNo = {read=FResultNo, nodefault};
	
__published:
	__property bool ASCIIFilter = {read=FASCIIFilter, write=FASCIIFilter, default=0};
	__property Idintercept::TIdConnectionIntercept* Intercept = {read=FIntercept, write=SetIntercept};
	__property bool InterceptEnabled = {read=FInterceptEnabled, write=SetInterceptEnabled, default=0};
	__property Classes::TNotifyEvent OnDisconnected = {read=FOnDisconnected, write=FOnDisconnected};
	__property OnWork ;
	__property OnWorkBegin ;
	__property OnWorkEnd ;
	__property int RecvBufferSize = {read=GetRecvBufferSize, write=SetRecvBufferSize, default=32768};
	__property int SendBufferSize = {read=FSendBufferSize, write=FSendBufferSize, default=32768};
};


class DELPHICLASS EIdTCPConnectionError;
class PASCALIMPLEMENTATION EIdTCPConnectionError : public Idexception::EIdException 
{
	typedef Idexception::EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdTCPConnectionError(const AnsiString Msg) : Idexception::EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdTCPConnectionError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdTCPConnectionError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdTCPConnectionError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdTCPConnectionError(const AnsiString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTCPConnectionError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdTCPConnectionError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTCPConnectionError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdTCPConnectionError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdObjectTypeNotSupported;
class PASCALIMPLEMENTATION EIdObjectTypeNotSupported : public EIdTCPConnectionError 
{
	typedef EIdTCPConnectionError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdObjectTypeNotSupported(const AnsiString Msg) : EIdTCPConnectionError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdObjectTypeNotSupported(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdTCPConnectionError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdObjectTypeNotSupported(int Ident)/* overload */ : EIdTCPConnectionError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdObjectTypeNotSupported(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdTCPConnectionError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdObjectTypeNotSupported(const AnsiString Msg, int AHelpContext) : EIdTCPConnectionError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdObjectTypeNotSupported(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdTCPConnectionError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdObjectTypeNotSupported(int Ident, int AHelpContext)/* overload */ : EIdTCPConnectionError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdObjectTypeNotSupported(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTCPConnectionError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdObjectTypeNotSupported(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdNotEnoughDataInBuffer;
class PASCALIMPLEMENTATION EIdNotEnoughDataInBuffer : public EIdTCPConnectionError 
{
	typedef EIdTCPConnectionError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdNotEnoughDataInBuffer(const AnsiString Msg) : EIdTCPConnectionError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdNotEnoughDataInBuffer(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdTCPConnectionError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdNotEnoughDataInBuffer(int Ident)/* overload */ : EIdTCPConnectionError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdNotEnoughDataInBuffer(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdTCPConnectionError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdNotEnoughDataInBuffer(const AnsiString Msg, int AHelpContext) : EIdTCPConnectionError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNotEnoughDataInBuffer(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdTCPConnectionError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdNotEnoughDataInBuffer(int Ident, int AHelpContext)/* overload */ : EIdTCPConnectionError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNotEnoughDataInBuffer(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTCPConnectionError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdNotEnoughDataInBuffer(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdInterceptPropIsNil;
class PASCALIMPLEMENTATION EIdInterceptPropIsNil : public EIdTCPConnectionError 
{
	typedef EIdTCPConnectionError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdInterceptPropIsNil(const AnsiString Msg) : EIdTCPConnectionError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdInterceptPropIsNil(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdTCPConnectionError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdInterceptPropIsNil(int Ident)/* overload */ : EIdTCPConnectionError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdInterceptPropIsNil(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdTCPConnectionError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdInterceptPropIsNil(const AnsiString Msg, int AHelpContext) : EIdTCPConnectionError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdInterceptPropIsNil(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdTCPConnectionError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdInterceptPropIsNil(int Ident, int AHelpContext)/* overload */ : EIdTCPConnectionError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdInterceptPropIsNil(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTCPConnectionError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdInterceptPropIsNil(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdInterceptPropInvalid;
class PASCALIMPLEMENTATION EIdInterceptPropInvalid : public EIdTCPConnectionError 
{
	typedef EIdTCPConnectionError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdInterceptPropInvalid(const AnsiString Msg) : EIdTCPConnectionError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdInterceptPropInvalid(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdTCPConnectionError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdInterceptPropInvalid(int Ident)/* overload */ : EIdTCPConnectionError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdInterceptPropInvalid(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdTCPConnectionError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdInterceptPropInvalid(const AnsiString Msg, int AHelpContext) : EIdTCPConnectionError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdInterceptPropInvalid(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdTCPConnectionError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdInterceptPropInvalid(int Ident, int AHelpContext)/* overload */ : EIdTCPConnectionError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdInterceptPropInvalid(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTCPConnectionError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdInterceptPropInvalid(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdNoDataToRead;
class PASCALIMPLEMENTATION EIdNoDataToRead : public EIdTCPConnectionError 
{
	typedef EIdTCPConnectionError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdNoDataToRead(const AnsiString Msg) : EIdTCPConnectionError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdNoDataToRead(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdTCPConnectionError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdNoDataToRead(int Ident)/* overload */ : EIdTCPConnectionError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdNoDataToRead(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdTCPConnectionError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdNoDataToRead(const AnsiString Msg, int AHelpContext) : EIdTCPConnectionError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNoDataToRead(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdTCPConnectionError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdNoDataToRead(int Ident, int AHelpContext)/* overload */ : EIdTCPConnectionError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNoDataToRead(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTCPConnectionError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdNoDataToRead(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word GRecvBufferSizeDefault = 0x8000;
static const Word GSendBufferSizeDefault = 0x8000;

}	/* namespace Idtcpconnection */
using namespace Idtcpconnection;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdTCPConnection
