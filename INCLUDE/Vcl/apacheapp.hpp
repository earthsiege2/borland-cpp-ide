// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ApacheApp.pas' rev: 6.00

#ifndef ApacheAppHPP
#define ApacheAppHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <WebBroker.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <ApacheHTTP.hpp>	// Pascal unit
#include <HTTPD.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Apacheapp
{
//-- type declarations -------------------------------------------------------
typedef int __fastcall (*TApacheRequestEvent)(Httpd::Prequest_rec Req);

typedef void __fastcall (*TApacheInitEvent)(Httpd::Pserver_rec Server, void * Pool);

typedef void * __fastcall (*TApacheCreateDirConfigEvent)(void * Pool, char * szDir);

typedef void * __fastcall (*TApacheCreateSvrConfigEvent)(void * Pool, Httpd::Pserver_rec Server);

typedef void * __fastcall (*TApacheMergeConfigEvent)(void * Pool, void * BaseConf, void * NewConf);

class DELPHICLASS TApacheApplication;
class DELPHICLASS TApacheFactory;
class PASCALIMPLEMENTATION TApacheFactory : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TApacheApplication* FApplication;
	
protected:
	virtual Apachehttp::TApacheRequest* __fastcall NewRequest(Httpd::request_rec &r);
	virtual Apachehttp::TApacheResponse* __fastcall NewResponse(Apachehttp::TApacheRequest* ApacheRequest);
	
public:
	__fastcall TApacheFactory(void);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TApacheFactory(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TApacheApplication : public Webbroker::TWebApplication 
{
	typedef Webbroker::TWebApplication inherited;
	
private:
	TApacheFactory* FFactory;
	void __fastcall SetFactory(TApacheFactory* Value);
	TApacheFactory* __fastcall GetFactory(void);
	void __fastcall ApacheHandleException(System::TObject* Sender);
	
protected:
	Apachehttp::TApacheRequest* __fastcall NewRequest(Httpd::request_rec &r);
	Apachehttp::TApacheResponse* __fastcall NewResponse(Apachehttp::TApacheRequest* ApacheRequest);
	
public:
	__fastcall virtual TApacheApplication(Classes::TComponent* AOwner);
	__fastcall virtual ~TApacheApplication(void);
	virtual void __fastcall Initialize(void);
	int __fastcall ProcessRequest(Httpd::request_rec &r);
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE char ContentType[256];
extern PACKAGE Httpd::handler_rec default_handler[2];
extern PACKAGE Httpd::handler_rec *request_handlers;
extern PACKAGE TApacheInitEvent ApacheOnInit;
extern PACKAGE TApacheInitEvent ApacheOnChildInit;
extern PACKAGE TApacheInitEvent ApacheOnChildExit;
extern PACKAGE TApacheCreateDirConfigEvent ApacheOnCreateDirConfig;
extern PACKAGE TApacheMergeConfigEvent ApacheOnMergeDirConfig;
extern PACKAGE TApacheCreateSvrConfigEvent ApacheOnCreateServerConfig;
extern PACKAGE TApacheMergeConfigEvent ApacheOnMergeServerConfig;
extern PACKAGE TApacheRequestEvent ApacheOnLogger;
extern PACKAGE TApacheRequestEvent ApacheOnFixUps;
extern PACKAGE TApacheRequestEvent ApacheOnTypeChecker;
extern PACKAGE TApacheRequestEvent ApacheOnAuthChecker;
extern PACKAGE TApacheRequestEvent ApacheOnCheckUserId;
extern PACKAGE TApacheRequestEvent ApacheOnHeaderParser;
extern PACKAGE TApacheRequestEvent ApacheOnAccessChecker;
extern PACKAGE TApacheRequestEvent ApacheOnPostReadRequest;
extern PACKAGE TApacheRequestEvent ApacheOnTranslateHandler;
extern PACKAGE char ModuleName[256];
extern PACKAGE void __fastcall set_module(Httpd::Pmodule defModule);
extern PACKAGE int __cdecl apache_handlers(Httpd::Prequest_rec r);

}	/* namespace Apacheapp */
using namespace Apacheapp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ApacheApp
