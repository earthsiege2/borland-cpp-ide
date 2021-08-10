// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdMappedPortTCP.pas' rev: 6.00

#ifndef IdMappedPortTCPHPP
#define IdMappedPortTCPHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdComponent.hpp>	// Pascal unit
#include <IdTCPServer.hpp>	// Pascal unit
#include <IdTCPClient.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idmappedporttcp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdMappedPortTCPData;
class PASCALIMPLEMENTATION TIdMappedPortTCPData : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	Idtcpclient::TIdTCPClient* OutboundClient;
	Classes::TList* ReadList;
	__fastcall TIdMappedPortTCPData(void);
	__fastcall virtual ~TIdMappedPortTCPData(void);
};


typedef void __fastcall (__closure *TBeforeClientConnectEvent)(Classes::TComponent* ASender, Idtcpserver::TIdPeerThread* AThread, Idtcpclient::TIdTCPClient* AClient);

class DELPHICLASS TIdMappedPortTCP;
class PASCALIMPLEMENTATION TIdMappedPortTCP : public Idtcpserver::TIdTCPServer 
{
	typedef Idtcpserver::TIdTCPServer inherited;
	
protected:
	int FMappedPort;
	AnsiString FMappedHost;
	TBeforeClientConnectEvent FOnBeforeClientConnect;
	virtual void __fastcall DoConnect(Idtcpserver::TIdPeerThread* AThread);
	virtual bool __fastcall DoExecute(Idtcpserver::TIdPeerThread* AThread);
	
public:
	__fastcall virtual TIdMappedPortTCP(Classes::TComponent* AOwner);
	
__published:
	__property AnsiString MappedHost = {read=FMappedHost, write=FMappedHost};
	__property int MappedPort = {read=FMappedPort, write=FMappedPort, default=0};
	__property TBeforeClientConnectEvent OnBeforeClientConnect = {read=FOnBeforeClientConnect, write=FOnBeforeClientConnect};
public:
	#pragma option push -w-inl
	/* TIdTCPServer.Destroy */ inline __fastcall virtual ~TIdMappedPortTCP(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint ID_MAPPED_PORT_TCP_PORT = 0x0;

}	/* namespace Idmappedporttcp */
using namespace Idmappedporttcp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdMappedPortTCP
