// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IsapiStubApp.pas' rev: 6.00

#ifndef IsapiStubAppHPP
#define IsapiStubAppHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Isapi2.hpp>	// Pascal unit
#include <IniFiles.hpp>	// Pascal unit
#include <WebBroker.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <IsapiHTTP.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Isapistubapp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TISAPIStubRequest;
class PASCALIMPLEMENTATION TISAPIStubRequest : public Isapihttp::TISAPIRequest 
{
	typedef Isapihttp::TISAPIRequest inherited;
	
public:
	virtual AnsiString __fastcall TranslateURI(const AnsiString URI);
	virtual bool __fastcall WriteString(const AnsiString AString);
public:
	#pragma option push -w-inl
	/* TISAPIRequest.Create */ inline __fastcall TISAPIStubRequest(Isapi2::PEXTENSION_CONTROL_BLOCK AECB) : Isapihttp::TISAPIRequest(AECB) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebRequest.Destroy */ inline __fastcall virtual ~TISAPIStubRequest(void) { }
	#pragma option pop
	
};


class DELPHICLASS TISAPIStubResponse;
class PASCALIMPLEMENTATION TISAPIStubResponse : public Isapihttp::TISAPIResponse 
{
	typedef Isapihttp::TISAPIResponse inherited;
	
protected:
	virtual AnsiString __fastcall GetContent();
	virtual System::TDateTime __fastcall GetDateVariable(int Index);
	virtual int __fastcall GetIntegerVariable(int Index);
	virtual AnsiString __fastcall GetLogMessage();
	virtual int __fastcall GetStatusCode(void);
	virtual AnsiString __fastcall GetStringVariable(int Index);
	virtual void __fastcall SetContent(const AnsiString Value);
	virtual void __fastcall SetDateVariable(int Index, const System::TDateTime Value);
	virtual void __fastcall SetIntegerVariable(int Index, int Value);
	virtual void __fastcall SetLogMessage(const AnsiString Value);
	virtual void __fastcall SetStatusCode(int Value);
	virtual void __fastcall SetStringVariable(int Index, const AnsiString Value);
	virtual void __fastcall InitResponse(void);
	
public:
	virtual void __fastcall SendResponse(void);
	virtual void __fastcall SendRedirect(const AnsiString URI);
	virtual void __fastcall SendStream(Classes::TStream* AStream);
public:
	#pragma option push -w-inl
	/* TISAPIResponse.Create */ inline __fastcall TISAPIStubResponse(Httpapp::TWebRequest* HTTPRequest) : Isapihttp::TISAPIResponse(HTTPRequest) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebResponse.Destroy */ inline __fastcall virtual ~TISAPIStubResponse(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Isapistubapp */
using namespace Isapistubapp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IsapiStubApp
