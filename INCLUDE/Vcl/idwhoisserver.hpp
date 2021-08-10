// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdWhoIsServer.pas' rev: 6.00

#ifndef IdWhoIsServerHPP
#define IdWhoIsServerHPP

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

namespace Idwhoisserver
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TGetEvent)(Idtcpserver::TIdPeerThread* AThread, AnsiString ALookup);

class DELPHICLASS TIdWhoIsServer;
class PASCALIMPLEMENTATION TIdWhoIsServer : public Idtcpserver::TIdTCPServer 
{
	typedef Idtcpserver::TIdTCPServer inherited;
	
protected:
	TGetEvent FOnCommandLookup;
	virtual bool __fastcall DoExecute(Idtcpserver::TIdPeerThread* AThread);
	
public:
	__fastcall virtual TIdWhoIsServer(Classes::TComponent* AOwner);
	
__published:
	__property TGetEvent OnCommandLookup = {read=FOnCommandLookup, write=FOnCommandLookup};
	__property DefaultPort  = {default=43};
public:
	#pragma option push -w-inl
	/* TIdTCPServer.Destroy */ inline __fastcall virtual ~TIdWhoIsServer(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idwhoisserver */
using namespace Idwhoisserver;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdWhoIsServer
