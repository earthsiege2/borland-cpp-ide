// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SOAPHTTPClient.pas' rev: 6.00

#ifndef SOAPHTTPClientHPP
#define SOAPHTTPClientHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <XMLIntf.hpp>	// Pascal unit
#include <WebNode.hpp>	// Pascal unit
#include <SOAPHTTPTrans.hpp>	// Pascal unit
#include <OPToSOAPDomConv.hpp>	// Pascal unit
#include <OPConvert.hpp>	// Pascal unit
#include <WSDLItems.hpp>	// Pascal unit
#include <WSDLNode.hpp>	// Pascal unit
#include <Rio.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Soaphttpclient
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS THTTPRIO;
class PASCALIMPLEMENTATION THTTPRIO : public Rio::TRIO 
{
	typedef Rio::TRIO inherited;
	
private:
	Wsdlitems::TWSDLItems* FWSDLItems;
	Xmlintf::_di_IXMLDocument WSDLItemDoc;
	Wsdlnode::TWSDLView* FWSDLView;
	AnsiString FWSDLLocation;
	Optosoapdomconv::TOPToSoapDomConvert* FDOMConverter;
	Soaphttptrans::THTTPReqResp* FHTTPWebNode;
	void __fastcall ClearDependentWSDLView(void);
	void __fastcall SetWSDLLocation(AnsiString Value);
	AnsiString __fastcall GetPort();
	void __fastcall SetPortValue(AnsiString Value);
	AnsiString __fastcall GetService();
	void __fastcall SetService(AnsiString Value);
	void __fastcall CheckWSDLView(void);
	void __fastcall SetURL(AnsiString Value);
	void __fastcall SetDomConverter(Optosoapdomconv::TOPToSoapDomConvert* Value);
	void __fastcall SetHTTPWebNode(Soaphttptrans::THTTPReqResp* Value);
	AnsiString __fastcall GetURL();
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__fastcall virtual THTTPRIO(Classes::TComponent* AOwner);
	__fastcall virtual ~THTTPRIO(void);
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	/**
	 * Template function to ease querying for a
	 * smart-Interface-object
	 */
	template <typename T>
	HRESULT __stdcall QueryInterface(DelphiInterface<T>& smartIntf)
	{
	  return QueryInterface(__uuidof(T), reinterpret_cast<void*>(static_cast<T**>(&smartIntf)));
	}
	__property Wsdlitems::TWSDLItems* WSDLItems = {read=FWSDLItems};
	
__published:
	__property AnsiString WSDLLocation = {read=FWSDLLocation, write=SetWSDLLocation};
	__property AnsiString Service = {read=GetService, write=SetService};
	__property AnsiString Port = {read=GetPort, write=SetPortValue};
	__property AnsiString URL = {read=GetURL, write=SetURL};
	__property Soaphttptrans::THTTPReqResp* HTTPWebNode = {read=FHTTPWebNode, write=SetHTTPWebNode};
	__property Optosoapdomconv::TOPToSoapDomConvert* Converter = {read=FDOMConverter, write=SetDomConverter};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Soaphttpclient */
using namespace Soaphttpclient;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SOAPHTTPClient
