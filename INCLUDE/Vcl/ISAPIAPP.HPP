// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ISAPIApp.pas' rev: 5.00

#ifndef ISAPIAppHPP
#define ISAPIAppHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Isapi2.hpp>	// Pascal unit
#include <WebBroker.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Isapiapp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TISAPIRequest;
class PASCALIMPLEMENTATION TISAPIRequest : public Httpapp::TWebRequest 
{
	typedef Httpapp::TWebRequest inherited;
	
private:
	Isapi2::TEXTENSION_CONTROL_BLOCK *FECB;
	
protected:
	virtual AnsiString __fastcall GetStringVariable(int Index);
	virtual System::TDateTime __fastcall GetDateVariable(int Index);
	virtual int __fastcall GetIntegerVariable(int Index);
	
public:
	__fastcall TISAPIRequest(Isapi2::PEXTENSION_CONTROL_BLOCK AECB);
	virtual AnsiString __fastcall GetFieldByName(const AnsiString Name);
	virtual int __fastcall ReadClient(void *Buffer, int Count);
	virtual AnsiString __fastcall ReadString(int Count);
	virtual AnsiString __fastcall TranslateURI(const AnsiString URI);
	virtual int __fastcall WriteClient(void *Buffer, int Count);
	virtual bool __fastcall WriteString(const AnsiString AString);
	__property Isapi2::PEXTENSION_CONTROL_BLOCK ECB = {read=FECB};
public:
	#pragma option push -w-inl
	/* TWebRequest.Destroy */ inline __fastcall virtual ~TISAPIRequest(void) { }
	#pragma option pop
	
};


typedef AnsiString ISAPIApp__3[12];

class DELPHICLASS TISAPIResponse;
class PASCALIMPLEMENTATION TISAPIResponse : public Httpapp::TWebResponse 
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
	__fastcall TISAPIResponse(Httpapp::TWebRequest* HTTPRequest);
	virtual void __fastcall SendResponse(void);
	virtual void __fastcall SendRedirect(const AnsiString URI);
	virtual void __fastcall SendStream(Classes::TStream* AStream);
	virtual bool __fastcall Sent(void);
public:
	#pragma option push -w-inl
	/* TWebResponse.Destroy */ inline __fastcall virtual ~TISAPIResponse(void) { }
	#pragma option pop
	
};


class DELPHICLASS TISAPIApplication;
class PASCALIMPLEMENTATION TISAPIApplication : public Webbroker::TWebApplication 
{
	typedef Webbroker::TWebApplication inherited;
	
private:
	TISAPIRequest* __fastcall NewRequest(Isapi2::TEXTENSION_CONTROL_BLOCK &AECB);
	TISAPIResponse* __fastcall NewResponse(TISAPIRequest* ISAPIRequest);
	
public:
	BOOL __fastcall GetExtensionVersion(Isapi2::HSE_VERSION_INFO &Ver);
	unsigned __fastcall HttpExtensionProc(Isapi2::TEXTENSION_CONTROL_BLOCK &ECB);
	BOOL __fastcall TerminateExtension(unsigned dwFlags);
public:
	#pragma option push -w-inl
	/* TWebApplication.Create */ inline __fastcall virtual TISAPIApplication(Classes::TComponent* AOwner
		) : Webbroker::TWebApplication(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebApplication.Destroy */ inline __fastcall virtual ~TISAPIApplication(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE BOOL __stdcall GetExtensionVersion(Isapi2::HSE_VERSION_INFO &Ver);
extern PACKAGE unsigned __stdcall HttpExtensionProc(Isapi2::TEXTENSION_CONTROL_BLOCK &ECB);
extern PACKAGE BOOL __stdcall TerminateExtension(unsigned dwFlags);

}	/* namespace Isapiapp */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Isapiapp;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ISAPIApp
