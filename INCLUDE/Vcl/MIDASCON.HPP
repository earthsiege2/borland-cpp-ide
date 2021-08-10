// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MidasCon.pas' rev: 5.00

#ifndef MidasConHPP
#define MidasConHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Db.hpp>	// Pascal unit
#include <SConnect.hpp>	// Pascal unit
#include <MConnect.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Midascon
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TRemoteServer;
class PASCALIMPLEMENTATION TRemoteServer : public Mconnect::TDCOMConnection 
{
	typedef Mconnect::TDCOMConnection inherited;
	
public:
	#pragma option push -w-inl
	/* TDCOMConnection.Create */ inline __fastcall virtual TRemoteServer(Classes::TComponent* AOwner) : 
		Mconnect::TDCOMConnection(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomConnection.Destroy */ inline __fastcall virtual ~TRemoteServer(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TConnectType { ctDCOM, ctSockets, ctOLEnterprise };
#pragma option pop

class DELPHICLASS TMidasConnection;
class PASCALIMPLEMENTATION TMidasConnection : public Mconnect::TDCOMConnection 
{
	typedef Mconnect::TDCOMConnection inherited;
	
private:
	Mconnect::TDispatchConnection* FSubConnection;
	TConnectType FConnectType;
	int FServerPort;
	bool FUseBroker;
	
protected:
	virtual void __fastcall SetConnectType(TConnectType Value);
	virtual void __fastcall SetUseBroker(bool Value);
	virtual void __fastcall DoConnect(void);
	virtual void __fastcall DoDisconnect(void);
	
public:
	__fastcall virtual TMidasConnection(Classes::TComponent* AOwner);
	
__published:
	__property TConnectType ConnectType = {read=FConnectType, write=SetConnectType, nodefault};
	__property int ServerPort = {read=FServerPort, write=FServerPort, default=211};
	__property bool UseBroker = {read=FUseBroker, write=SetUseBroker, nodefault};
public:
	#pragma option push -w-inl
	/* TCustomConnection.Destroy */ inline __fastcall virtual ~TMidasConnection(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Midascon */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Midascon;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MidasCon
