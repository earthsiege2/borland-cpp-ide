// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WebLib.pas' rev: 6.00

#ifndef WebLibHPP
#define WebLibHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <StdVCL.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Weblib
{
//-- type declarations -------------------------------------------------------
__interface IWebBroker;
typedef System::DelphiInterface<IWebBroker> _di_IWebBroker;
__interface IWebRequest;
typedef System::DelphiInterface<IWebRequest> _di_IWebRequest;
__interface INTERFACE_UUID("{B0A08BEE-8E23-11D3-B08A-00C04FB16EC3}") IWebBroker  : public IInterface 
{
	
public:
	virtual HRESULT __safecall HandleRequest(const _di_IWebRequest Request) = 0 ;
};

__dispinterface IWebBrokerDisp;
typedef System::DelphiInterface<IWebBrokerDisp> _di_IWebBrokerDisp;
__dispinterface INTERFACE_UUID("{B0A08BEE-8E23-11D3-B08A-00C04FB16EC3}") IWebBrokerDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{E72A0846-8C34-11D3-AAF7-A0AC2E78CD57}") IWebRequest  : public IInterface 
{
	
public:
	virtual HRESULT __safecall GetFieldByName(const WideString Name, WideString &GetFieldByName_result) = 0 ;
	virtual HRESULT __safecall ReadClient(OleVariant &Buffer, int Count, int &ReadClient_result) = 0 ;
	virtual HRESULT __safecall TranslateURI(const WideString Value, WideString &TranslateURI_result) = 0 ;
	virtual HRESULT __safecall WriteClient(const OleVariant Buffer, int &WriteClient_result) = 0 ;
	virtual HRESULT __safecall GetStringVariable(int Index, OleVariant &GetStringVariable_result) = 0 ;
	virtual HRESULT __safecall WriteHeaders(int StatusCode, const OleVariant StatusText, const OleVariant Headers, Word &WriteHeaders_result) = 0 ;
	virtual HRESULT __safecall UsingStub(Word &UsingStub_result) = 0 ;
	virtual HRESULT __safecall ReadString(OleVariant &Buffer, int Count, int &ReadString_result) = 0 ;
};

__dispinterface IWebRequestDisp;
typedef System::DelphiInterface<IWebRequestDisp> _di_IWebRequestDisp;
__dispinterface INTERFACE_UUID("{E72A0846-8C34-11D3-AAF7-A0AC2E78CD57}") IWebRequestDisp  : public IDispatch 
{
	
};

//-- var, const, procedure ---------------------------------------------------
static const Shortint WebLibMajorVersion = 0x1;
static const Shortint WebLibMinorVersion = 0x0;
extern PACKAGE GUID LIBID_WebLib;
extern PACKAGE GUID IID_IWebBroker;
extern PACKAGE GUID IID_IWebRequest;

}	/* namespace Weblib */
using namespace Weblib;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WebLib
