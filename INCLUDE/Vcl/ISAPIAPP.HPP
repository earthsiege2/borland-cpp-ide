// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ISAPIApp.pas' rev: 6.00

#ifndef ISAPIAppHPP
#define ISAPIAppHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Isapi2.hpp>	// Pascal unit
#include <IsapiHTTP.hpp>	// Pascal unit
#include <WebBroker.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SyncObjs.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Isapiapp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TISAPIApplication;
class DELPHICLASS TISAPIFactory;
class PASCALIMPLEMENTATION TISAPIFactory : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TISAPIApplication* FApplication;
	
protected:
	virtual Isapihttp::TISAPIRequest* __fastcall NewRequest(Isapi2::TEXTENSION_CONTROL_BLOCK &AECB);
	virtual Isapihttp::TISAPIResponse* __fastcall NewResponse(Isapihttp::TISAPIRequest* ISAPIRequest);
	
public:
	__fastcall TISAPIFactory(void);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TISAPIFactory(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TISAPIApplication : public Webbroker::TWebApplication 
{
	typedef Webbroker::TWebApplication inherited;
	
private:
	TISAPIFactory* FFactory;
	void __fastcall SetFactory(TISAPIFactory* Value);
	TISAPIFactory* __fastcall GetFactory(void);
	Isapihttp::TISAPIRequest* __fastcall NewRequest(Isapi2::TEXTENSION_CONTROL_BLOCK &AECB);
	Isapihttp::TISAPIResponse* __fastcall NewResponse(Isapihttp::TISAPIRequest* ISAPIRequest);
	void __fastcall ISAPIHandleException(System::TObject* Sender);
	
public:
	BOOL __fastcall GetExtensionVersion(Isapi2::HSE_VERSION_INFO &Ver);
	unsigned __fastcall HttpExtensionProc(Isapi2::TEXTENSION_CONTROL_BLOCK &ECB);
	BOOL __fastcall TerminateExtension(unsigned dwFlags);
	__fastcall virtual TISAPIApplication(Classes::TComponent* AOwner);
	__fastcall virtual ~TISAPIApplication(void);
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall (__closure *DispatchThread)(Isapi2::PEXTENSION_CONTROL_BLOCK AECB);
extern PACKAGE BOOL __stdcall GetExtensionVersion(Isapi2::HSE_VERSION_INFO &Ver);
extern PACKAGE unsigned __stdcall HttpExtensionProc(Isapi2::TEXTENSION_CONTROL_BLOCK &ECB);
extern PACKAGE BOOL __stdcall TerminateExtension(unsigned dwFlags);

}	/* namespace Isapiapp */
using namespace Isapiapp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ISAPIApp
