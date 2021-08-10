// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SOAPHTTPTrans.pas' rev: 6.00

#ifndef SOAPHTTPTransHPP
#define SOAPHTTPTransHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <WinInet.hpp>	// Pascal unit
#include <WinSock.hpp>	// Pascal unit
#include <IntfInfo.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <WSDLNode.hpp>	// Pascal unit
#include <WebNode.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#pragma link "wininet.lib"

namespace Soaphttptrans
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum SOAPInvokeOptions { soNoValueForEmptySOAPAction, soIgnoreInvalidCerts };
#pragma option pop

typedef Set<SOAPInvokeOptions, soNoValueForEmptySOAPAction, soIgnoreInvalidCerts>  TSOAPInvokeOptions;

__interface IHTTPReqResp;
typedef System::DelphiInterface<IHTTPReqResp> _di_IHTTPReqResp;
class DELPHICLASS THTTPReqResp;
__interface INTERFACE_UUID("{5FA6A197-32DE-4225-BC85-216CB80D1561}") IHTTPReqResp  : public IInterface 
{
	
public:
	virtual THTTPReqResp* __fastcall GetHTTPReqResp(void) = 0 ;
};

class PASCALIMPLEMENTATION THTTPReqResp : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	bool FUserSetURL;
	int FRefCount;
	bool FOwnerIsComponent;
	bool FConnected;
	AnsiString FURL;
	AnsiString FAgent;
	AnsiString FUserName;
	AnsiString FPassword;
	AnsiString FURLHost;
	AnsiString FURLSite;
	int FURLPort;
	int FURLScheme;
	AnsiString FProxy;
	AnsiString FProxyByPass;
	void *FInetRoot;
	void *FInetConnect;
	Wsdlnode::TWSDLView* FWSDLView;
	AnsiString FSoapAction;
	bool FUseUTF8InHeader;
	TSOAPInvokeOptions FInvokeOptions;
	void __fastcall SetURL(const AnsiString Value);
	AnsiString __fastcall GetSOAPAction();
	void __fastcall SetSOAPAction(const AnsiString SOAPAction);
	void __fastcall SetWSDLView(const Wsdlnode::TWSDLView* WSDLVIew);
	AnsiString __fastcall GetSOAPActionHeader();
	void __fastcall InitURL(const AnsiString Value);
	void __fastcall SetUsername(const AnsiString NameValue);
	void __fastcall SetPassword(const AnsiString PasswordValue);
	void __fastcall SetProxy(const AnsiString ProxyValue);
	
protected:
	HIDESBASE int __stdcall _AddRef(void);
	HIDESBASE int __stdcall _Release(void);
	
public:
	__fastcall virtual THTTPReqResp(Classes::TComponent* Owner);
	/* virtual class method */ virtual System::TObject* __fastcall NewInstance(TMetaClass* vmt);
	virtual void __fastcall AfterConstruction(void);
	__fastcall virtual ~THTTPReqResp(void);
	THTTPReqResp* __fastcall GetHTTPReqResp(void);
	void __fastcall Check(bool Error, bool ShowSOAPAction = true);
	void __fastcall Connect(bool Value);
	int __fastcall Send(const WideString S);
	int __fastcall SendGet(void);
	void __fastcall Receive(int Context, Classes::TStream* Resp);
	virtual void __fastcall Get(Classes::TStream* Resp);
	virtual void __fastcall BeforeExecute(const Intfinfo::TIntfMetaData &IntfMD, const Intfinfo::TIntfMethEntry &MethMD);
	virtual void __fastcall Execute(const WideString DataMsg, Classes::TStream* Resp);
	__property AnsiString URL = {read=FURL, write=SetURL};
	__property AnsiString SoapAction = {read=GetSOAPAction, write=SetSOAPAction};
	
__published:
	__property Wsdlnode::TWSDLView* WSDLView = {read=FWSDLView, write=SetWSDLView};
	__property AnsiString Agent = {read=FAgent, write=FAgent};
	__property AnsiString UserName = {read=FUserName, write=SetUsername};
	__property AnsiString Password = {read=FPassword, write=SetPassword};
	__property AnsiString Proxy = {read=FProxy, write=SetProxy};
	__property AnsiString ProxyByPass = {read=FProxyByPass, write=FProxyByPass};
	__property bool UseUTF8InHeader = {read=FUseUTF8InHeader, write=FUseUTF8InHeader, nodefault};
	__property TSOAPInvokeOptions InvokeOptions = {read=FInvokeOptions, write=FInvokeOptions, nodefault};
private:
	void *__IWebNode;	/* Webnode::IWebNode */
	void *__IHTTPReqResp;	/* Soaphttptrans::IHTTPReqResp */
	
public:
	operator IHTTPReqResp*(void) { return (IHTTPReqResp*)&__IHTTPReqResp; }
	operator IWebNode*(void) { return (IWebNode*)&__IWebNode; }
	operator IInterface*(void) { return (IInterface*)&__IHTTPReqResp; }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Soaphttptrans */
using namespace Soaphttptrans;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SOAPHTTPTrans
