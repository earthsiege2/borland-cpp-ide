// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SOAPConn.pas' rev: 6.00

#ifndef SOAPConnHPP
#define SOAPConnHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DB.hpp>	// Pascal unit
#include <SOAPMidas.hpp>	// Pascal unit
#include <SOAPHTTPClient.hpp>	// Pascal unit
#include <Rio.hpp>	// Pascal unit
#include <SOAPHTTPTrans.hpp>	// Pascal unit
#include <DBClient.hpp>	// Pascal unit
#include <Midas.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Soapconn
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSoapConnection;
class PASCALIMPLEMENTATION TSoapConnection : public Dbclient::TCustomRemoteServer 
{
	typedef Dbclient::TCustomRemoteServer inherited;
	
private:
	Soaphttpclient::THTTPRIO* FRIO;
	AnsiString FURL;
	Midas::_di_IAppServer FAppServer;
	Soapmidas::_di_IAppServerSOAP FSOAPServer;
	bool FUseSOAPAdapter;
	Rio::TAfterExecuteEvent FOnAfterExecute;
	Rio::TBeforeExecuteEvent FOnBeforeExecute;
	AnsiString __fastcall GetAgent();
	AnsiString __fastcall GetPassword();
	AnsiString __fastcall GetProxy();
	AnsiString __fastcall GetProxyByPass();
	AnsiString __fastcall GetUserName();
	void __fastcall SetAgent(const AnsiString Value);
	void __fastcall SetPassword(const AnsiString Value);
	void __fastcall SetProxy(const AnsiString Value);
	void __fastcall SetProxyByPass(const AnsiString Value);
	void __fastcall SetURL(const AnsiString Value);
	void __fastcall SetUserName(const AnsiString Value);
	
protected:
	virtual void __fastcall DoConnect(void);
	virtual bool __fastcall GetConnected(void);
	virtual OleVariant __fastcall GetServerList();
	virtual void __fastcall DoDisconnect(void);
	virtual void __fastcall GetProviderNames(Classes::TGetStrProc Proc);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__fastcall virtual TSoapConnection(Classes::TComponent* AOwner);
	__fastcall virtual ~TSoapConnection(void);
	virtual Midas::_di_IAppServer __fastcall GetServer();
	Soapmidas::_di_IAppServerSOAP __fastcall GetSOAPServer();
	
__published:
	__property AnsiString Agent = {read=GetAgent, write=SetAgent};
	__property Connected  = {default=0};
	__property AfterConnect ;
	__property BeforeConnect ;
	__property AfterDisconnect ;
	__property BeforeDisconnect ;
	__property AnsiString Password = {read=GetPassword, write=SetPassword};
	__property AnsiString Proxy = {read=GetProxy, write=SetProxy};
	__property AnsiString ProxyByPass = {read=GetProxyByPass, write=SetProxyByPass};
	__property AnsiString URL = {read=FURL, write=SetURL};
	__property AnsiString UserName = {read=GetUserName, write=SetUserName};
	__property bool UseSOAPAdapter = {read=FUseSOAPAdapter, write=FUseSOAPAdapter, nodefault};
	__property Rio::TAfterExecuteEvent OnAfterExecute = {read=FOnAfterExecute, write=FOnAfterExecute};
	__property Rio::TBeforeExecuteEvent OnBeforeExecute = {read=FOnBeforeExecute, write=FOnBeforeExecute};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Soapconn */
using namespace Soapconn;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SOAPConn
