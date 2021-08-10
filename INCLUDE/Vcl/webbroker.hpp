// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WebBroker.pas' rev: 6.00

#ifndef WebBrokerHPP
#define WebBrokerHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <WebReq.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Webbroker
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TServerExceptionEvent)(Sysutils::Exception* E, Httpapp::TWebResponse* wr);

class DELPHICLASS TWebApplication;
class PASCALIMPLEMENTATION TWebApplication : public Webreq::TWebRequestHandler 
{
	typedef Webreq::TWebRequestHandler inherited;
	
private:
	AnsiString FTitle;
	
public:
	__fastcall virtual TWebApplication(Classes::TComponent* AOwner);
	__fastcall virtual ~TWebApplication(void);
	virtual void __fastcall CreateForm(TMetaClass* InstanceClass, void *Reference);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall Run(void);
	__property AnsiString Title = {read=FTitle, write=FTitle};
};


typedef void __fastcall (*THandleShutdownException)(Sysutils::Exception* E);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TWebApplication* Application;
extern PACKAGE THandleShutdownException HandleShutdownException;

}	/* namespace Webbroker */
using namespace Webbroker;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WebBroker
