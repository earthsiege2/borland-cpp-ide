// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdTelnetServer.pas' rev: 6.00

#ifndef IdTelnetServerHPP
#define IdTelnetServerHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdComponent.hpp>	// Pascal unit
#include <IdTCPServer.hpp>	// Pascal unit
#include <IdGlobal.hpp>	// Pascal unit
#include <IdException.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idtelnetserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTelnetData;
class PASCALIMPLEMENTATION TTelnetData : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	AnsiString Username;
	AnsiString Password;
	unsigned HUserToken;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TTelnetData(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TTelnetData(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TIdTelnetNegotiateEvent)(Idtcpserver::TIdPeerThread* AThread);

typedef void __fastcall (__closure *TAuthenticationEvent)(Idtcpserver::TIdPeerThread* AThread, const AnsiString AUsername, const AnsiString APassword, bool &AAuthenticated);

class DELPHICLASS TIdTelnetServer;
class PASCALIMPLEMENTATION TIdTelnetServer : public Idtcpserver::TIdTCPServer 
{
	typedef Idtcpserver::TIdTCPServer inherited;
	
protected:
	int FLoginAttempts;
	TAuthenticationEvent FOnAuthentication;
	AnsiString FLoginMessage;
	TIdTelnetNegotiateEvent FOnNegotiate;
	
public:
	__fastcall virtual TIdTelnetServer(Classes::TComponent* AOwner);
	virtual bool __fastcall DoAuthenticate(Idtcpserver::TIdPeerThread* AThread, const AnsiString AUsername, const AnsiString APassword);
	virtual void __fastcall DoNegotiate(Idtcpserver::TIdPeerThread* AThread);
	virtual void __fastcall DoConnect(Idtcpserver::TIdPeerThread* AThread);
	
__published:
	__property DefaultPort  = {default=23};
	__property int LoginAttempts = {read=FLoginAttempts, write=FLoginAttempts, default=3};
	__property AnsiString LoginMessage = {read=FLoginMessage, write=FLoginMessage};
	__property TAuthenticationEvent OnAuthentication = {read=FOnAuthentication, write=FOnAuthentication};
	__property TIdTelnetNegotiateEvent OnNegotiate = {read=FOnNegotiate, write=FOnNegotiate};
public:
	#pragma option push -w-inl
	/* TIdTCPServer.Destroy */ inline __fastcall virtual ~TIdTelnetServer(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdTelnetServerException;
class PASCALIMPLEMENTATION EIdTelnetServerException : public Idexception::EIdException 
{
	typedef Idexception::EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdTelnetServerException(const AnsiString Msg) : Idexception::EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdTelnetServerException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdTelnetServerException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdTelnetServerException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdTelnetServerException(const AnsiString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTelnetServerException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdTelnetServerException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTelnetServerException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdTelnetServerException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdNoOnAuthentication;
class PASCALIMPLEMENTATION EIdNoOnAuthentication : public EIdTelnetServerException 
{
	typedef EIdTelnetServerException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdNoOnAuthentication(const AnsiString Msg) : EIdTelnetServerException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdNoOnAuthentication(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdTelnetServerException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdNoOnAuthentication(int Ident)/* overload */ : EIdTelnetServerException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdNoOnAuthentication(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdTelnetServerException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdNoOnAuthentication(const AnsiString Msg, int AHelpContext) : EIdTelnetServerException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNoOnAuthentication(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdTelnetServerException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdNoOnAuthentication(int Ident, int AHelpContext)/* overload */ : EIdTelnetServerException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNoOnAuthentication(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTelnetServerException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdNoOnAuthentication(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdLoginException;
class PASCALIMPLEMENTATION EIdLoginException : public EIdTelnetServerException 
{
	typedef EIdTelnetServerException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdLoginException(const AnsiString Msg) : EIdTelnetServerException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdLoginException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdTelnetServerException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdLoginException(int Ident)/* overload */ : EIdTelnetServerException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdLoginException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdTelnetServerException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdLoginException(const AnsiString Msg, int AHelpContext) : EIdTelnetServerException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdLoginException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdTelnetServerException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdLoginException(int Ident, int AHelpContext)/* overload */ : EIdTelnetServerException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdLoginException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdTelnetServerException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdLoginException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdMaxLoginAttempt;
class PASCALIMPLEMENTATION EIdMaxLoginAttempt : public EIdLoginException 
{
	typedef EIdLoginException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdMaxLoginAttempt(const AnsiString Msg) : EIdLoginException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdMaxLoginAttempt(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdLoginException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdMaxLoginAttempt(int Ident)/* overload */ : EIdLoginException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdMaxLoginAttempt(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdLoginException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdMaxLoginAttempt(const AnsiString Msg, int AHelpContext) : EIdLoginException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdMaxLoginAttempt(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdLoginException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdMaxLoginAttempt(int Ident, int AHelpContext)/* overload */ : EIdLoginException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdMaxLoginAttempt(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdLoginException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdMaxLoginAttempt(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint GLoginAttempts = 0x3;

}	/* namespace Idtelnetserver */
using namespace Idtelnetserver;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdTelnetServer
