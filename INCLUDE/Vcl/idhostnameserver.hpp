// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdHostnameServer.pas' rev: 6.00

#ifndef IdHostnameServerHPP
#define IdHostnameServerHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdComponent.hpp>	// Pascal unit
#include <IdTCPServer.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idhostnameserver
{
//-- type declarations -------------------------------------------------------
typedef AnsiString IdHostnameServer__1[9];

typedef void __fastcall (__closure *THostNameGetEvent)(Idtcpserver::TIdPeerThread* Thread);

typedef void __fastcall (__closure *THostNameOneParmEvent)(Idtcpserver::TIdPeerThread* Thread, AnsiString Parm);

class DELPHICLASS TIdHostNameServer;
class PASCALIMPLEMENTATION TIdHostNameServer : public Idtcpserver::TIdTCPServer 
{
	typedef Idtcpserver::TIdTCPServer inherited;
	
protected:
	THostNameOneParmEvent FOnCommandHNAME;
	THostNameOneParmEvent FOnCommandHADDR;
	THostNameGetEvent FOnCommandALL;
	THostNameGetEvent FOnCommandHELP;
	THostNameGetEvent FOnCommandVERSION;
	THostNameGetEvent FOnCommandALLOLD;
	THostNameGetEvent FOnCommandDOMAINS;
	THostNameGetEvent FOnCommandALLDOM;
	THostNameGetEvent FOnCommandALLINGWAY;
	virtual bool __fastcall DoExecute(Idtcpserver::TIdPeerThread* Thread);
	
public:
	__fastcall virtual TIdHostNameServer(Classes::TComponent* AOwner);
	
__published:
	__property THostNameOneParmEvent OnCommandHNAME = {read=FOnCommandHNAME, write=FOnCommandHNAME};
	__property THostNameOneParmEvent OnCommandHADDR = {read=FOnCommandHADDR, write=FOnCommandHADDR};
	__property THostNameGetEvent OnCommandALL = {read=FOnCommandALL, write=FOnCommandALL};
	__property THostNameGetEvent OnCommandHELP = {read=FOnCommandHELP, write=FOnCommandHELP};
	__property THostNameGetEvent OnCommandVERSION = {read=FOnCommandVERSION, write=FOnCommandVERSION};
	__property THostNameGetEvent OnCommandALLOLD = {read=FOnCommandALLOLD, write=FOnCommandALLOLD};
	__property THostNameGetEvent OnCommandDOMAINS = {read=FOnCommandDOMAINS, write=FOnCommandDOMAINS};
	__property THostNameGetEvent OnCommandALLDOM = {read=FOnCommandALLDOM, write=FOnCommandALLDOM};
	__property THostNameGetEvent OnCommandALLINGWAY = {read=FOnCommandALLINGWAY, write=FOnCommandALLINGWAY};
public:
	#pragma option push -w-inl
	/* TIdTCPServer.Destroy */ inline __fastcall virtual ~TIdHostNameServer(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString KnownCommands[9];

}	/* namespace Idhostnameserver */
using namespace Idhostnameserver;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdHostnameServer
