// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ReqImpl.pas' rev: 6.00

#ifndef ReqImplHPP
#define ReqImplHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ComObj.hpp>	// Pascal unit
#include <WebLib.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Reqimpl
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TWebRequestImpl;
class PASCALIMPLEMENTATION TWebRequestImpl : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Httpapp::TWebRequest* FWebRequest;
	Httpapp::TWebResponse* FWebResponse;
	bool FUsingStub;
	
public:
	__fastcall TWebRequestImpl(Httpapp::TWebRequest* AWebRequest, Httpapp::TWebResponse* AWebResponse, bool AUsingStub);
	HRESULT __safecall GetFieldByName(const WideString Name, WideString &GetFieldByName_result);
	HRESULT __safecall ReadClient(OleVariant &ABuffer, int ACount, int &ReadClient_result);
	HRESULT __safecall ReadString(OleVariant &ABuffer, int ACount, int &ReadString_result);
	HRESULT __safecall TranslateURI(const WideString Value, WideString &TranslateURI_result);
	HRESULT __safecall WriteClient(const OleVariant Buffer, int &WriteClient_result);
	HRESULT __safecall GetStringVariable(int Index, OleVariant &GetStringVariable_result);
	HRESULT __safecall WriteHeaders(int StatusCode, const OleVariant StatusText, const OleVariant Headers, Word &WriteHeaders_result);
	HRESULT __safecall UsingStub(Word &UsingStub_result);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TWebRequestImpl(void) { }
	#pragma option pop
	
private:
	void *__IWebRequest;	/* Weblib::IWebRequest */
	
public:
	operator IWebRequest*(void) { return (IWebRequest*)&__IWebRequest; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall SearchForCoClass(Httpapp::TWebRequest* Request, AnsiString &ID, GUID &ClsID);
extern PACKAGE bool __fastcall FileNameToClassID(const AnsiString AFileName, GUID &AGuid);

}	/* namespace Reqimpl */
using namespace Reqimpl;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ReqImpl
