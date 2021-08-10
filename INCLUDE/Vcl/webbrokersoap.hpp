// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WebBrokerSOAP.pas' rev: 6.00

#ifndef WebBrokerSOAPHPP
#define WebBrokerSOAPHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SOAPHTTPDisp.hpp>	// Pascal unit
#include <WebNode.hpp>	// Pascal unit
#include <Masks.hpp>	// Pascal unit
#include <AutoDisp.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Webbrokersoap
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS THTTPSoapDispatcher;
class PASCALIMPLEMENTATION THTTPSoapDispatcher : public Soaphttpdisp::THTTPSoapDispatchNode 
{
	typedef Soaphttpdisp::THTTPSoapDispatchNode inherited;
	
private:
	Autodisp::TWebDispatch* FWebDispatch;
	void __fastcall SetWebDispatch(const Autodisp::TWebDispatch* Value);
	
protected:
	bool __fastcall DispatchEnabled(void);
	Masks::TMask* __fastcall DispatchMask(void);
	Httpapp::TMethodType __fastcall DispatchMethodType(void);
	bool __fastcall DispatchRequest(System::TObject* Sender, Httpapp::TWebRequest* Request, Httpapp::TWebResponse* Response);
	
public:
	__fastcall virtual THTTPSoapDispatcher(Classes::TComponent* AOwner);
	__fastcall virtual ~THTTPSoapDispatcher(void);
	
__published:
	__property Autodisp::TWebDispatch* WebDispatch = {read=FWebDispatch, write=SetWebDispatch};
private:
	void *__IWebDispatch;	/* Httpapp::IWebDispatch */
	
public:
	operator IWebDispatch*(void) { return (IWebDispatch*)&__IWebDispatch; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Httpapp::TWebModule* __fastcall GetSOAPWebModule(void);

}	/* namespace Webbrokersoap */
using namespace Webbrokersoap;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WebBrokerSOAP
