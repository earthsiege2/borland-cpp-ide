// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'CGIApp.pas' rev: 6.00

#ifndef CGIAppHPP
#define CGIAppHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <CGIHTTP.hpp>	// Pascal unit
#include <WebBroker.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cgiapp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCGIApplication;
class DELPHICLASS TCGIFactory;
class PASCALIMPLEMENTATION TCGIFactory : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TCGIApplication* FApplication;
	AnsiString __fastcall GetOutputFileName();
	void __fastcall SetOutputFileName(const AnsiString Value);
	
protected:
	virtual Cgihttp::TCGIRequest* __fastcall NewRequest(void);
	virtual Cgihttp::TCGIResponse* __fastcall NewResponse(Cgihttp::TCGIRequest* CGIRequest);
	__property AnsiString OutputFileName = {read=GetOutputFileName, write=SetOutputFileName};
	
public:
	__fastcall TCGIFactory(void);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TCGIFactory(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TCGIApplication : public Webbroker::TWebApplication 
{
	typedef Webbroker::TWebApplication inherited;
	
private:
	AnsiString FOutputFileName;
	TCGIFactory* FFactory;
	Cgihttp::TCGIRequest* __fastcall NewRequest(void);
	Cgihttp::TCGIResponse* __fastcall NewResponse(Cgihttp::TCGIRequest* CGIRequest);
	void __fastcall SetFactory(TCGIFactory* Value);
	TCGIFactory* __fastcall GetFactory(void);
	void __fastcall CGIHandleException(System::TObject* Sender);
	
public:
	__fastcall virtual ~TCGIApplication(void);
	virtual void __fastcall Run(void);
public:
	#pragma option push -w-inl
	/* TWebApplication.Create */ inline __fastcall virtual TCGIApplication(Classes::TComponent* AOwner) : Webbroker::TWebApplication(AOwner) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Cgiapp */
using namespace Cgiapp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CGIApp
