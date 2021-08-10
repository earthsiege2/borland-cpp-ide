// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdSocks.pas' rev: 6.00

#ifndef IdSocksHPP
#define IdSocksHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdStack.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsocks
{
//-- type declarations -------------------------------------------------------
#pragma pack(push, 4)
struct TIdSocksRequest
{
	Byte Version;
	Byte OpCode;
	Word Port;
	Idstack::TIdInAddr IpAddr;
	System::SmallString<255>  UserId;
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TIdSocksResponse
{
	Byte Version;
	Byte OpCode;
	Word Port;
	Idstack::TIdInAddr IpAddr;
} ;
#pragma pack(pop)

#pragma option push -b-
enum TSocksVersion { svNoSocks, svSocks4, svSocks4A, svSocks5 };
#pragma option pop

#pragma option push -b-
enum TSocksAuthentication { saNoAuthentication, saUsernamePassword };
#pragma option pop

class DELPHICLASS TSocksInfo;
class PASCALIMPLEMENTATION TSocksInfo : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
protected:
	TSocksAuthentication FAuthentication;
	AnsiString FHost;
	AnsiString FPassword;
	int FPort;
	AnsiString FUserID;
	TSocksVersion FVersion;
	
public:
	__fastcall TSocksInfo(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property TSocksAuthentication Authentication = {read=FAuthentication, write=FAuthentication, default=0};
	__property AnsiString Host = {read=FHost, write=FHost};
	__property AnsiString Password = {read=FPassword, write=FPassword};
	__property int Port = {read=FPort, write=FPort, default=0};
	__property AnsiString UserID = {read=FUserID, write=FUserID};
	__property TSocksVersion Version = {read=FVersion, write=FVersion, default=0};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TSocksInfo(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define ID_SOCKS_AUTH (TSocksAuthentication)(0)
#define ID_SOCKS_VER (TSocksVersion)(0)
static const Shortint ID_SOCKS_PORT = 0x0;

}	/* namespace Idsocks */
using namespace Idsocks;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdSocks
