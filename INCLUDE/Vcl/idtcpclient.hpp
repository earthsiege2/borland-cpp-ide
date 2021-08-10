// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdTCPClient.pas' rev: 6.00

#ifndef IdTCPClientHPP
#define IdTCPClientHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdComponent.hpp>	// Pascal unit
#include <IdTCPConnection.hpp>	// Pascal unit
#include <IdSocks.hpp>	// Pascal unit
#include <IdGlobal.hpp>	// Pascal unit
#include <IdException.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idtcpclient
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TProceduralEvent)(void);

class DELPHICLASS TIdTCPClient;
class PASCALIMPLEMENTATION TIdTCPClient : public Idtcpconnection::TIdTCPConnection 
{
	typedef Idtcpconnection::TIdTCPConnection inherited;
	
protected:
	AnsiString FBoundIP;
	AnsiString FHost;
	Classes::TNotifyEvent FOnConnected;
	int FPort;
	Idsocks::TSocksInfo* FSocksInfo;
	bool FUseNagle;
	virtual void __fastcall DoOnConnected(void);
	void __fastcall SetSocksInfo(Idsocks::TSocksInfo* ASocks);
	
public:
	virtual void __fastcall Connect(void);
	virtual AnsiString __fastcall ConnectAndGetAll();
	__fastcall virtual TIdTCPClient(Classes::TComponent* AOwner);
	__fastcall virtual ~TIdTCPClient(void);
	
__published:
	__property AnsiString BoundIP = {read=FBoundIP, write=FBoundIP};
	__property AnsiString Host = {read=FHost, write=FHost};
	__property Classes::TNotifyEvent OnConnected = {read=FOnConnected, write=FOnConnected};
	__property int Port = {read=FPort, write=FPort, nodefault};
	__property bool UseNagle = {read=FUseNagle, write=FUseNagle, default=1};
	__property Idsocks::TSocksInfo* SocksInfo = {read=FSocksInfo, write=SetSocksInfo};
};


class DELPHICLASS EIdSocksError;
class PASCALIMPLEMENTATION EIdSocksError : public Idexception::EIdException 
{
	typedef Idexception::EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdSocksError(const AnsiString Msg) : Idexception::EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdSocksError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdSocksError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdSocksError(const AnsiString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdSocksError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdSocksRequestFailed;
class PASCALIMPLEMENTATION EIdSocksRequestFailed : public EIdSocksError 
{
	typedef EIdSocksError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdSocksRequestFailed(const AnsiString Msg) : EIdSocksError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdSocksRequestFailed(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdSocksRequestFailed(int Ident)/* overload */ : EIdSocksError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksRequestFailed(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdSocksRequestFailed(const AnsiString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksRequestFailed(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksRequestFailed(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksRequestFailed(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdSocksRequestFailed(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdSocksRequestServerFailed;
class PASCALIMPLEMENTATION EIdSocksRequestServerFailed : public EIdSocksError 
{
	typedef EIdSocksError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdSocksRequestServerFailed(const AnsiString Msg) : EIdSocksError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdSocksRequestServerFailed(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdSocksRequestServerFailed(int Ident)/* overload */ : EIdSocksError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksRequestServerFailed(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdSocksRequestServerFailed(const AnsiString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksRequestServerFailed(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksRequestServerFailed(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksRequestServerFailed(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdSocksRequestServerFailed(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdSocksRequestIdentFailed;
class PASCALIMPLEMENTATION EIdSocksRequestIdentFailed : public EIdSocksError 
{
	typedef EIdSocksError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdSocksRequestIdentFailed(const AnsiString Msg) : EIdSocksError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdSocksRequestIdentFailed(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdSocksRequestIdentFailed(int Ident)/* overload */ : EIdSocksError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksRequestIdentFailed(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdSocksRequestIdentFailed(const AnsiString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksRequestIdentFailed(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksRequestIdentFailed(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksRequestIdentFailed(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdSocksRequestIdentFailed(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdSocksUnknownError;
class PASCALIMPLEMENTATION EIdSocksUnknownError : public EIdSocksError 
{
	typedef EIdSocksError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdSocksUnknownError(const AnsiString Msg) : EIdSocksError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdSocksUnknownError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdSocksUnknownError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksUnknownError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdSocksUnknownError(const AnsiString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksUnknownError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksUnknownError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksUnknownError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdSocksUnknownError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdSocksServerRespondError;
class PASCALIMPLEMENTATION EIdSocksServerRespondError : public EIdSocksError 
{
	typedef EIdSocksError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdSocksServerRespondError(const AnsiString Msg) : EIdSocksError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdSocksServerRespondError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdSocksServerRespondError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksServerRespondError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdSocksServerRespondError(const AnsiString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksServerRespondError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksServerRespondError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksServerRespondError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdSocksServerRespondError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdSocksAuthMethodError;
class PASCALIMPLEMENTATION EIdSocksAuthMethodError : public EIdSocksError 
{
	typedef EIdSocksError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdSocksAuthMethodError(const AnsiString Msg) : EIdSocksError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdSocksAuthMethodError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdSocksAuthMethodError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksAuthMethodError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdSocksAuthMethodError(const AnsiString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksAuthMethodError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksAuthMethodError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksAuthMethodError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdSocksAuthMethodError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdSocksAuthError;
class PASCALIMPLEMENTATION EIdSocksAuthError : public EIdSocksError 
{
	typedef EIdSocksError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdSocksAuthError(const AnsiString Msg) : EIdSocksError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdSocksAuthError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdSocksAuthError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksAuthError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdSocksAuthError(const AnsiString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksAuthError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksAuthError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksAuthError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdSocksAuthError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdSocksServerGeneralError;
class PASCALIMPLEMENTATION EIdSocksServerGeneralError : public EIdSocksError 
{
	typedef EIdSocksError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdSocksServerGeneralError(const AnsiString Msg) : EIdSocksError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdSocksServerGeneralError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdSocksServerGeneralError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksServerGeneralError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdSocksServerGeneralError(const AnsiString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksServerGeneralError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksServerGeneralError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksServerGeneralError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdSocksServerGeneralError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdSocksServerPermissionError;
class PASCALIMPLEMENTATION EIdSocksServerPermissionError : public EIdSocksError 
{
	typedef EIdSocksError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdSocksServerPermissionError(const AnsiString Msg) : EIdSocksError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdSocksServerPermissionError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdSocksServerPermissionError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksServerPermissionError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdSocksServerPermissionError(const AnsiString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksServerPermissionError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksServerPermissionError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksServerPermissionError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdSocksServerPermissionError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdSocksServerNetUnreachableError;
class PASCALIMPLEMENTATION EIdSocksServerNetUnreachableError : public EIdSocksError 
{
	typedef EIdSocksError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdSocksServerNetUnreachableError(const AnsiString Msg) : EIdSocksError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdSocksServerNetUnreachableError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdSocksServerNetUnreachableError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksServerNetUnreachableError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdSocksServerNetUnreachableError(const AnsiString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksServerNetUnreachableError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksServerNetUnreachableError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksServerNetUnreachableError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdSocksServerNetUnreachableError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdSocksServerHostUnreachableError;
class PASCALIMPLEMENTATION EIdSocksServerHostUnreachableError : public EIdSocksError 
{
	typedef EIdSocksError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdSocksServerHostUnreachableError(const AnsiString Msg) : EIdSocksError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdSocksServerHostUnreachableError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdSocksServerHostUnreachableError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksServerHostUnreachableError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdSocksServerHostUnreachableError(const AnsiString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksServerHostUnreachableError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksServerHostUnreachableError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksServerHostUnreachableError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdSocksServerHostUnreachableError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdSocksServerConnectionRefusedError;
class PASCALIMPLEMENTATION EIdSocksServerConnectionRefusedError : public EIdSocksError 
{
	typedef EIdSocksError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdSocksServerConnectionRefusedError(const AnsiString Msg) : EIdSocksError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdSocksServerConnectionRefusedError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdSocksServerConnectionRefusedError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksServerConnectionRefusedError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdSocksServerConnectionRefusedError(const AnsiString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksServerConnectionRefusedError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksServerConnectionRefusedError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksServerConnectionRefusedError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdSocksServerConnectionRefusedError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdSocksServerTTLExpiredError;
class PASCALIMPLEMENTATION EIdSocksServerTTLExpiredError : public EIdSocksError 
{
	typedef EIdSocksError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdSocksServerTTLExpiredError(const AnsiString Msg) : EIdSocksError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdSocksServerTTLExpiredError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdSocksServerTTLExpiredError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksServerTTLExpiredError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdSocksServerTTLExpiredError(const AnsiString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksServerTTLExpiredError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksServerTTLExpiredError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksServerTTLExpiredError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdSocksServerTTLExpiredError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdSocksServerCommandError;
class PASCALIMPLEMENTATION EIdSocksServerCommandError : public EIdSocksError 
{
	typedef EIdSocksError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdSocksServerCommandError(const AnsiString Msg) : EIdSocksError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdSocksServerCommandError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdSocksServerCommandError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksServerCommandError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdSocksServerCommandError(const AnsiString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksServerCommandError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksServerCommandError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksServerCommandError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdSocksServerCommandError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdSocksServerAddressError;
class PASCALIMPLEMENTATION EIdSocksServerAddressError : public EIdSocksError 
{
	typedef EIdSocksError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdSocksServerAddressError(const AnsiString Msg) : EIdSocksError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdSocksServerAddressError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdSocksError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdSocksServerAddressError(int Ident)/* overload */ : EIdSocksError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdSocksServerAddressError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdSocksError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdSocksServerAddressError(const AnsiString Msg, int AHelpContext) : EIdSocksError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdSocksServerAddressError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdSocksError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdSocksServerAddressError(int Ident, int AHelpContext)/* overload */ : EIdSocksError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdSocksServerAddressError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdSocksError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdSocksServerAddressError(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idtcpclient */
using namespace Idtcpclient;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdTCPClient
