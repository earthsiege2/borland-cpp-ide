// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ComHTTP.pas' rev: 6.00

#ifndef ComHTTPHPP
#define ComHTTPHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <WebLib.hpp>	// Pascal unit
#include <IniFiles.hpp>	// Pascal unit
#include <WebReq.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Comhttp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCOMWebRequest;
class PASCALIMPLEMENTATION TCOMWebRequest : public Httpapp::TWebRequest 
{
	typedef Httpapp::TWebRequest inherited;
	
private:
	Weblib::_di_IWebRequest FIntf;
	bool __fastcall UsingStub(void);
	
protected:
	virtual AnsiString __fastcall GetStringVariable(int Index);
	virtual System::TDateTime __fastcall GetDateVariable(int Index);
	virtual int __fastcall GetIntegerVariable(int Index);
	virtual AnsiString __fastcall GetInternalPathInfo();
	virtual AnsiString __fastcall GetInternalScriptName();
	
public:
	__fastcall TCOMWebRequest(Weblib::_di_IWebRequest ARequest);
	virtual AnsiString __fastcall GetFieldByName(const AnsiString Name);
	virtual int __fastcall ReadClient(void *Buffer, int Count);
	virtual AnsiString __fastcall ReadString(int Count);
	virtual AnsiString __fastcall TranslateURI(const AnsiString URI);
	virtual int __fastcall WriteClient(void *Buffer, int Count);
	virtual bool __fastcall WriteString(const AnsiString AString);
	virtual bool __fastcall WriteHeaders(int StatusCode, const AnsiString StatusString, const AnsiString Headers);
public:
	#pragma option push -w-inl
	/* TWebRequest.Destroy */ inline __fastcall virtual ~TCOMWebRequest(void) { }
	#pragma option pop
	
};


typedef AnsiString ComHTTP__3[12];

class DELPHICLASS TCOMWebResponse;
class PASCALIMPLEMENTATION TCOMWebResponse : public Httpapp::TWebResponse 
{
	typedef Httpapp::TWebResponse inherited;
	
private:
	int FStatusCode;
	AnsiString FStringVariables[12];
	int FIntegerVariables[1];
	System::TDateTime FDateVariables[3];
	AnsiString FContent;
	bool FSent;
	
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
	
public:
	__fastcall TCOMWebResponse(Httpapp::TWebRequest* HTTPRequest);
	virtual void __fastcall SendResponse(void);
	virtual void __fastcall SendRedirect(const AnsiString URI);
	virtual void __fastcall SendStream(Classes::TStream* AStream);
	virtual bool __fastcall Sent(void);
public:
	#pragma option push -w-inl
	/* TWebResponse.Destroy */ inline __fastcall virtual ~TCOMWebResponse(void) { }
	#pragma option pop
	
};


class DELPHICLASS TComWebRequestHandler;
class PASCALIMPLEMENTATION TComWebRequestHandler : public Webreq::TWebRequestHandler 
{
	typedef Webreq::TWebRequestHandler inherited;
	
private:
	TCOMWebRequest* __fastcall NewRequest(Weblib::_di_IWebRequest ARequest);
	TCOMWebResponse* __fastcall NewResponse(TCOMWebRequest* COMWebRequest);
	void __fastcall HandleServerException(Sysutils::Exception* E, Weblib::_di_IWebRequest ARequest);
	HIDESBASE void __fastcall HandleException(System::TObject* Sender);
	
public:
	__fastcall virtual TComWebRequestHandler(Classes::TComponent* AOwner);
	__fastcall virtual ~TComWebRequestHandler(void);
	void __fastcall Run(Weblib::_di_IWebRequest ARequest);
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Comhttp */
using namespace Comhttp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ComHTTP
