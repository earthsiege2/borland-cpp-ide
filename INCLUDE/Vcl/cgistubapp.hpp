// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'CGIStubApp.pas' rev: 6.00

#ifndef CGIStubAppHPP
#define CGIStubAppHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IniFiles.hpp>	// Pascal unit
#include <WebBroker.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <CGIHTTP.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cgistubapp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCGIStubRequest;
class PASCALIMPLEMENTATION TCGIStubRequest : public Cgihttp::TCGIRequest 
{
	typedef Cgihttp::TCGIRequest inherited;
	
public:
	virtual AnsiString __fastcall TranslateURI(const AnsiString URI);
public:
	#pragma option push -w-inl
	/* TCGIRequest.Create */ inline __fastcall TCGIStubRequest(void) : Cgihttp::TCGIRequest() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebRequest.Destroy */ inline __fastcall virtual ~TCGIStubRequest(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCGIStubResponse;
class PASCALIMPLEMENTATION TCGIStubResponse : public Cgihttp::TCGIResponse 
{
	typedef Cgihttp::TCGIResponse inherited;
	
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
	/* TCGIResponse.Create */ inline __fastcall TCGIStubResponse(Httpapp::TWebRequest* HTTPRequest) : Cgihttp::TCGIResponse(HTTPRequest) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebResponse.Destroy */ inline __fastcall virtual ~TCGIStubResponse(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWinCGIStubRequest;
class PASCALIMPLEMENTATION TWinCGIStubRequest : public Cgihttp::TWinCGIRequest 
{
	typedef Cgihttp::TWinCGIRequest inherited;
	
public:
	virtual AnsiString __fastcall ReadString(int Count);
	virtual AnsiString __fastcall TranslateURI(const AnsiString URI);
	virtual bool __fastcall WriteString(const AnsiString AString);
public:
	#pragma option push -w-inl
	/* TWinCGIRequest.Create */ inline __fastcall TWinCGIStubRequest(AnsiString IniFileName, AnsiString ContentFile, AnsiString OutputFile) : Cgihttp::TWinCGIRequest(IniFileName, ContentFile, OutputFile) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinCGIRequest.Destroy */ inline __fastcall virtual ~TWinCGIStubRequest(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWinCGIStubResponse;
class PASCALIMPLEMENTATION TWinCGIStubResponse : public TCGIStubResponse 
{
	typedef TCGIStubResponse inherited;
	
public:
	#pragma option push -w-inl
	/* TCGIResponse.Create */ inline __fastcall TWinCGIStubResponse(Httpapp::TWebRequest* HTTPRequest) : TCGIStubResponse(HTTPRequest) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebResponse.Destroy */ inline __fastcall virtual ~TWinCGIStubResponse(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Cgistubapp */
using namespace Cgistubapp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CGIStubApp
