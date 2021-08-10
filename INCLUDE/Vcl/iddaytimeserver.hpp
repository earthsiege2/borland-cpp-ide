// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdDayTimeServer.pas' rev: 6.00

#ifndef IdDayTimeServerHPP
#define IdDayTimeServerHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdComponent.hpp>	// Pascal unit
#include <IdTCPServer.hpp>	// Pascal unit
#include <IdGlobal.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iddaytimeserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdDayTimeServer;
class PASCALIMPLEMENTATION TIdDayTimeServer : public Idtcpserver::TIdTCPServer 
{
	typedef Idtcpserver::TIdTCPServer inherited;
	
protected:
	AnsiString FTimeZone;
	virtual bool __fastcall DoExecute(Idtcpserver::TIdPeerThread* AThread);
	
public:
	__fastcall virtual TIdDayTimeServer(Classes::TComponent* AOwner);
	
__published:
	__property AnsiString TimeZone = {read=FTimeZone, write=FTimeZone};
	__property DefaultPort  = {default=13};
public:
	#pragma option push -w-inl
	/* TIdTCPServer.Destroy */ inline __fastcall virtual ~TIdDayTimeServer(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Iddaytimeserver */
using namespace Iddaytimeserver;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdDayTimeServer
