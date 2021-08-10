// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'CGIHTTP.pas' rev: 6.00

#ifndef CGIHTTPHPP
#define CGIHTTPHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IniFiles.hpp>	// Pascal unit
#include <WebBroker.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cgihttp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCGIRequest;
class PASCALIMPLEMENTATION TCGIRequest : public Httpapp::TWebRequest 
{
	typedef Httpapp::TWebRequest inherited;
	
private:
	AnsiString FContent;
	
protected:
	virtual AnsiString __fastcall GetStringVariable(int Index);
	virtual System::TDateTime __fastcall GetDateVariable(int Index);
	virtual int __fastcall GetIntegerVariable(int Index);
	
public:
	__fastcall TCGIRequest(void);
	virtual AnsiString __fastcall GetFieldByName(const AnsiString Name);
	virtual int __fastcall ReadClient(void *Buffer, int Count);
	virtual AnsiString __fastcall ReadString(int Count);
	virtual AnsiString __fastcall TranslateURI(const AnsiString URI);
	virtual int __fastcall WriteClient(void *Buffer, int Count);
	virtual bool __fastcall WriteString(const AnsiString AString);
	virtual bool __fastcall WriteHeaders(int StatusCode, const AnsiString StatusString, const AnsiString Headers);
public:
	#pragma option push -w-inl
	/* TWebRequest.Destroy */ inline __fastcall virtual ~TCGIRequest(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TCGIRequestClass;

typedef AnsiString CGIHTTP__3[12];

class DELPHICLASS TCGIResponse;
class PASCALIMPLEMENTATION TCGIResponse : public Httpapp::TWebResponse 
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
	virtual void __fastcall InitResponse(void);
	
public:
	__fastcall TCGIResponse(Httpapp::TWebRequest* HTTPRequest);
	virtual void __fastcall SendResponse(void);
	virtual void __fastcall SendRedirect(const AnsiString URI);
	virtual void __fastcall SendStream(Classes::TStream* AStream);
	virtual bool __fastcall Sent(void);
public:
	#pragma option push -w-inl
	/* TWebResponse.Destroy */ inline __fastcall virtual ~TCGIResponse(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TCGIResponseClass;

class DELPHICLASS TWinCGIRequest;
class PASCALIMPLEMENTATION TWinCGIRequest : public TCGIRequest 
{
	typedef TCGIRequest inherited;
	
private:
	Inifiles::TIniFile* FIniFile;
	Classes::TFileStream* FClientData;
	Classes::TFileStream* FServerData;
	
protected:
	virtual AnsiString __fastcall GetStringVariable(int Index);
	
public:
	__fastcall TWinCGIRequest(AnsiString IniFileName, AnsiString ContentFile, AnsiString OutputFile);
	__fastcall virtual ~TWinCGIRequest(void);
	virtual AnsiString __fastcall GetFieldByName(const AnsiString Name);
	virtual int __fastcall ReadClient(void *Buffer, int Count);
	virtual AnsiString __fastcall ReadString(int Count);
	virtual int __fastcall WriteClient(void *Buffer, int Count);
	virtual bool __fastcall WriteString(const AnsiString AString);
};


typedef TMetaClass*TWinCGIRequestClass;

class DELPHICLASS TWinCGIResponse;
class PASCALIMPLEMENTATION TWinCGIResponse : public TCGIResponse 
{
	typedef TCGIResponse inherited;
	
public:
	#pragma option push -w-inl
	/* TCGIResponse.Create */ inline __fastcall TWinCGIResponse(Httpapp::TWebRequest* HTTPRequest) : TCGIResponse(HTTPRequest) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebResponse.Destroy */ inline __fastcall virtual ~TWinCGIResponse(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TWinCGIResponseClass;

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Cgihttp */
using namespace Cgihttp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CGIHTTP
