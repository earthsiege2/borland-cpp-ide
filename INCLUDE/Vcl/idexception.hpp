// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdException.pas' rev: 6.00

#ifndef IdExceptionHPP
#define IdExceptionHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idexception
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIdException;
class PASCALIMPLEMENTATION EIdException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdException(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TClassIdException;

class DELPHICLASS EIdAlreadyConnected;
class PASCALIMPLEMENTATION EIdAlreadyConnected : public EIdException 
{
	typedef EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdAlreadyConnected(const AnsiString Msg) : EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdAlreadyConnected(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdAlreadyConnected(int Ident)/* overload */ : EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdAlreadyConnected(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdAlreadyConnected(const AnsiString Msg, int AHelpContext) : EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdAlreadyConnected(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdAlreadyConnected(int Ident, int AHelpContext)/* overload */ : EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdAlreadyConnected(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdAlreadyConnected(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdSilentException;
class PASCALIMPLEMENTATION EIdSilentException : public EIdException 
{
	typedef EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdSilentException(const AnsiString Msg) : EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdSilentException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdSilentException(int Ident)/* overload */ : EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdSilentException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdSilentException(const AnsiString Msg, int AHelpContext) : EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSilentException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdSilentException(int Ident, int AHelpContext)/* overload */ : EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSilentException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdSilentException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdInvalidServiceName;
class PASCALIMPLEMENTATION EIdInvalidServiceName : public EIdException 
{
	typedef EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdInvalidServiceName(const AnsiString Msg) : EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdInvalidServiceName(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdInvalidServiceName(int Ident)/* overload */ : EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdInvalidServiceName(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdInvalidServiceName(const AnsiString Msg, int AHelpContext) : EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdInvalidServiceName(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdInvalidServiceName(int Ident, int AHelpContext)/* overload */ : EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdInvalidServiceName(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdInvalidServiceName(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdProtocolReplyError;
class PASCALIMPLEMENTATION EIdProtocolReplyError : public EIdException 
{
	typedef EIdException inherited;
	
protected:
	int FReplyErrorCode;
	
public:
	__fastcall virtual EIdProtocolReplyError(const int anErrCode, const AnsiString asReplyMessage);
	__property int ReplyErrorCode = {read=FReplyErrorCode, nodefault};
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdProtocolReplyError(const AnsiString Msg) : EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdProtocolReplyError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdProtocolReplyError(int Ident)/* overload */ : EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdProtocolReplyError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdProtocolReplyError(const AnsiString Msg, int AHelpContext) : EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdProtocolReplyError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdProtocolReplyError(int Ident, int AHelpContext)/* overload */ : EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdProtocolReplyError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdProtocolReplyError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdDnsResolverError;
class PASCALIMPLEMENTATION EIdDnsResolverError : public EIdException 
{
	typedef EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdDnsResolverError(const AnsiString Msg) : EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdDnsResolverError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdDnsResolverError(int Ident)/* overload */ : EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdDnsResolverError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdDnsResolverError(const AnsiString Msg, int AHelpContext) : EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdDnsResolverError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdDnsResolverError(int Ident, int AHelpContext)/* overload */ : EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdDnsResolverError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdDnsResolverError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdInvalidSocket;
class PASCALIMPLEMENTATION EIdInvalidSocket : public EIdException 
{
	typedef EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdInvalidSocket(const AnsiString Msg) : EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdInvalidSocket(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdInvalidSocket(int Ident)/* overload */ : EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdInvalidSocket(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdInvalidSocket(const AnsiString Msg, int AHelpContext) : EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdInvalidSocket(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdInvalidSocket(int Ident, int AHelpContext)/* overload */ : EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdInvalidSocket(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdInvalidSocket(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdSocketError;
class PASCALIMPLEMENTATION EIdSocketError : public EIdException 
{
	typedef EIdException inherited;
	
private:
	int FLastError;
	
public:
	__fastcall virtual EIdSocketError(const int anErr, const AnsiString asMsg);
	__property int LastError = {read=FLastError, nodefault};
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdSocketError(const AnsiString Msg) : EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdSocketError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdSocketError(int Ident)/* overload */ : EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdSocketError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdSocketError(const AnsiString Msg, int AHelpContext) : EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocketError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdSocketError(int Ident, int AHelpContext)/* overload */ : EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocketError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdSocketError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdConnClosedGracefully;
class PASCALIMPLEMENTATION EIdConnClosedGracefully : public EIdSilentException 
{
	typedef EIdSilentException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdConnClosedGracefully(const AnsiString Msg) : EIdSilentException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdConnClosedGracefully(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdSilentException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdConnClosedGracefully(int Ident)/* overload */ : EIdSilentException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdConnClosedGracefully(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdSilentException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdConnClosedGracefully(const AnsiString Msg, int AHelpContext) : EIdSilentException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdConnClosedGracefully(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdSilentException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdConnClosedGracefully(int Ident, int AHelpContext)/* overload */ : EIdSilentException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdConnClosedGracefully(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSilentException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdConnClosedGracefully(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdResponseError;
class PASCALIMPLEMENTATION EIdResponseError : public EIdException 
{
	typedef EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdResponseError(const AnsiString Msg) : EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdResponseError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdResponseError(int Ident)/* overload */ : EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdResponseError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdResponseError(const AnsiString Msg, int AHelpContext) : EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdResponseError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdResponseError(int Ident, int AHelpContext)/* overload */ : EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdResponseError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdResponseError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdClosedSocket;
class PASCALIMPLEMENTATION EIdClosedSocket : public EIdException 
{
	typedef EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdClosedSocket(const AnsiString Msg) : EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdClosedSocket(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdClosedSocket(int Ident)/* overload */ : EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdClosedSocket(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdClosedSocket(const AnsiString Msg, int AHelpContext) : EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdClosedSocket(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdClosedSocket(int Ident, int AHelpContext)/* overload */ : EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdClosedSocket(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdClosedSocket(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdTFTPException;
class PASCALIMPLEMENTATION EIdTFTPException : public EIdException 
{
	typedef EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdTFTPException(const AnsiString Msg) : EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdTFTPException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdTFTPException(int Ident)/* overload */ : EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdTFTPException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdTFTPException(const AnsiString Msg, int AHelpContext) : EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTFTPException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdTFTPException(int Ident, int AHelpContext)/* overload */ : EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTFTPException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdTFTPException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdTFTPFileNotFound;
class PASCALIMPLEMENTATION EIdTFTPFileNotFound : public EIdTFTPException 
{
	typedef EIdTFTPException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdTFTPFileNotFound(const AnsiString Msg) : EIdTFTPException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdTFTPFileNotFound(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdTFTPException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdTFTPFileNotFound(int Ident)/* overload */ : EIdTFTPException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdTFTPFileNotFound(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdTFTPException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdTFTPFileNotFound(const AnsiString Msg, int AHelpContext) : EIdTFTPException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTFTPFileNotFound(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdTFTPException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdTFTPFileNotFound(int Ident, int AHelpContext)/* overload */ : EIdTFTPException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTFTPFileNotFound(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdTFTPFileNotFound(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdTFTPAccessViolation;
class PASCALIMPLEMENTATION EIdTFTPAccessViolation : public EIdTFTPException 
{
	typedef EIdTFTPException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdTFTPAccessViolation(const AnsiString Msg) : EIdTFTPException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdTFTPAccessViolation(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdTFTPException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdTFTPAccessViolation(int Ident)/* overload */ : EIdTFTPException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdTFTPAccessViolation(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdTFTPException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdTFTPAccessViolation(const AnsiString Msg, int AHelpContext) : EIdTFTPException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTFTPAccessViolation(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdTFTPException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdTFTPAccessViolation(int Ident, int AHelpContext)/* overload */ : EIdTFTPException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTFTPAccessViolation(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdTFTPAccessViolation(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdTFTPAllocationExceeded;
class PASCALIMPLEMENTATION EIdTFTPAllocationExceeded : public EIdTFTPException 
{
	typedef EIdTFTPException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdTFTPAllocationExceeded(const AnsiString Msg) : EIdTFTPException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdTFTPAllocationExceeded(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdTFTPException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdTFTPAllocationExceeded(int Ident)/* overload */ : EIdTFTPException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdTFTPAllocationExceeded(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdTFTPException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdTFTPAllocationExceeded(const AnsiString Msg, int AHelpContext) : EIdTFTPException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTFTPAllocationExceeded(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdTFTPException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdTFTPAllocationExceeded(int Ident, int AHelpContext)/* overload */ : EIdTFTPException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTFTPAllocationExceeded(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdTFTPAllocationExceeded(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdTFTPIllegalOperation;
class PASCALIMPLEMENTATION EIdTFTPIllegalOperation : public EIdTFTPException 
{
	typedef EIdTFTPException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdTFTPIllegalOperation(const AnsiString Msg) : EIdTFTPException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdTFTPIllegalOperation(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdTFTPException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdTFTPIllegalOperation(int Ident)/* overload */ : EIdTFTPException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdTFTPIllegalOperation(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdTFTPException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdTFTPIllegalOperation(const AnsiString Msg, int AHelpContext) : EIdTFTPException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTFTPIllegalOperation(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdTFTPException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdTFTPIllegalOperation(int Ident, int AHelpContext)/* overload */ : EIdTFTPException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTFTPIllegalOperation(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdTFTPIllegalOperation(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdTFTPUnknownTransferID;
class PASCALIMPLEMENTATION EIdTFTPUnknownTransferID : public EIdTFTPException 
{
	typedef EIdTFTPException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdTFTPUnknownTransferID(const AnsiString Msg) : EIdTFTPException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdTFTPUnknownTransferID(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdTFTPException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdTFTPUnknownTransferID(int Ident)/* overload */ : EIdTFTPException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdTFTPUnknownTransferID(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdTFTPException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdTFTPUnknownTransferID(const AnsiString Msg, int AHelpContext) : EIdTFTPException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTFTPUnknownTransferID(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdTFTPException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdTFTPUnknownTransferID(int Ident, int AHelpContext)/* overload */ : EIdTFTPException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTFTPUnknownTransferID(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdTFTPUnknownTransferID(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdTFTPFileAlreadyExists;
class PASCALIMPLEMENTATION EIdTFTPFileAlreadyExists : public EIdTFTPException 
{
	typedef EIdTFTPException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdTFTPFileAlreadyExists(const AnsiString Msg) : EIdTFTPException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdTFTPFileAlreadyExists(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdTFTPException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdTFTPFileAlreadyExists(int Ident)/* overload */ : EIdTFTPException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdTFTPFileAlreadyExists(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdTFTPException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdTFTPFileAlreadyExists(const AnsiString Msg, int AHelpContext) : EIdTFTPException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTFTPFileAlreadyExists(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdTFTPException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdTFTPFileAlreadyExists(int Ident, int AHelpContext)/* overload */ : EIdTFTPException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTFTPFileAlreadyExists(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdTFTPFileAlreadyExists(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdTFTPNoSuchUser;
class PASCALIMPLEMENTATION EIdTFTPNoSuchUser : public EIdTFTPException 
{
	typedef EIdTFTPException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdTFTPNoSuchUser(const AnsiString Msg) : EIdTFTPException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdTFTPNoSuchUser(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdTFTPException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdTFTPNoSuchUser(int Ident)/* overload */ : EIdTFTPException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdTFTPNoSuchUser(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdTFTPException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdTFTPNoSuchUser(const AnsiString Msg, int AHelpContext) : EIdTFTPException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTFTPNoSuchUser(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdTFTPException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdTFTPNoSuchUser(int Ident, int AHelpContext)/* overload */ : EIdTFTPException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTFTPNoSuchUser(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdTFTPNoSuchUser(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdTFTPOptionNegotiationFailed;
class PASCALIMPLEMENTATION EIdTFTPOptionNegotiationFailed : public EIdTFTPException 
{
	typedef EIdTFTPException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdTFTPOptionNegotiationFailed(const AnsiString Msg) : EIdTFTPException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdTFTPOptionNegotiationFailed(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdTFTPException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdTFTPOptionNegotiationFailed(int Ident)/* overload */ : EIdTFTPException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdTFTPOptionNegotiationFailed(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdTFTPException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdTFTPOptionNegotiationFailed(const AnsiString Msg, int AHelpContext) : EIdTFTPException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTFTPOptionNegotiationFailed(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdTFTPException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdTFTPOptionNegotiationFailed(int Ident, int AHelpContext)/* overload */ : EIdTFTPException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTFTPOptionNegotiationFailed(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTFTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdTFTPOptionNegotiationFailed(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdIcmpException;
class PASCALIMPLEMENTATION EIdIcmpException : public EIdException 
{
	typedef EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdIcmpException(const AnsiString Msg) : EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdIcmpException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdIcmpException(int Ident)/* overload */ : EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdIcmpException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdIcmpException(const AnsiString Msg, int AHelpContext) : EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdIcmpException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdIcmpException(int Ident, int AHelpContext)/* overload */ : EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdIcmpException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdIcmpException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdSetSizeExceeded;
class PASCALIMPLEMENTATION EIdSetSizeExceeded : public EIdException 
{
	typedef EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdSetSizeExceeded(const AnsiString Msg) : EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdSetSizeExceeded(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdSetSizeExceeded(int Ident)/* overload */ : EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdSetSizeExceeded(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdSetSizeExceeded(const AnsiString Msg, int AHelpContext) : EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSetSizeExceeded(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdSetSizeExceeded(int Ident, int AHelpContext)/* overload */ : EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSetSizeExceeded(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdSetSizeExceeded(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idexception */
using namespace Idexception;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdException
