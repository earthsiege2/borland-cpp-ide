// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WSDLPub.pas' rev: 6.00

#ifndef WSDLPubHPP
#define WSDLPubHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Types.hpp>	// Pascal unit
#include <Masks.hpp>	// Pascal unit
#include <AutoDisp.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <InvokeRegistry.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Wsdlpub
{
//-- type declarations -------------------------------------------------------
__interface IWSDLPublish;
typedef System::DelphiInterface<IWSDLPublish> _di_IWSDLPublish;
__interface INTERFACE_UUID("{ECD820DD-F242-11D4-928A-00C04F990435}") IWSDLPublish  : public IInvokable 
{
	
public:
	virtual void __stdcall GetPortTypeList(TWideStringDynArray &PortTypes) = 0 ;
	virtual WideString __stdcall GetWSDLForPortType(WideString PortType) = 0 ;
	virtual void __stdcall GetTypeSystemsList(TWideStringDynArray TypeSystems) = 0 ;
	virtual WideString __stdcall GetXSDForTypeSystem(WideString TypeSystem) = 0 ;
};

typedef DynamicArray<WideString >  WSDLPub__2;

typedef DynamicArray<WideString >  WSDLPub__3;

class DELPHICLASS TWSDLPublish;
class PASCALIMPLEMENTATION TWSDLPublish : public Invokeregistry::TInvokableClass 
{
	typedef Invokeregistry::TInvokableClass inherited;
	
private:
	DynamicArray<WideString >  Locations;
	DynamicArray<WideString >  PortNames;
	WideString FTargetNamespace;
	
public:
	__property WideString TargetNamespace = {read=FTargetNamespace, write=FTargetNamespace};
	void __fastcall GetPortTypeEntries(Invokeregistry::TInvRegIntfEntryArray &Entries);
	void __stdcall GetPortTypeList(TWideStringDynArray &PortTypes);
	void __stdcall GetTypeSystemsList(TWideStringDynArray TypeSystems);
	WideString __stdcall GetWSDLForPortType(WideString PortType);
	WideString __stdcall GetXSDForTypeSystem(WideString TypeSystem);
public:
	#pragma option push -w-inl
	/* TInvokableClass.Create */ inline __fastcall virtual TWSDLPublish(void) : Invokeregistry::TInvokableClass() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TWSDLPublish(void) { }
	#pragma option pop
	
private:
	void *__IWSDLPublish;	/* Wsdlpub::IWSDLPublish */
	
public:
	operator IWSDLPublish*(void) { return (IWSDLPublish*)&__IWSDLPublish; }
	
};


#pragma option push -b-
enum SOAPPublishOptions { poDefault, poPublishLocationAsSecure };
#pragma option pop

typedef Set<SOAPPublishOptions, poDefault, poPublishLocationAsSecure>  TSOAPPublishOptions;

class DELPHICLASS TWSDLHTMLPublish;
class PASCALIMPLEMENTATION TWSDLHTMLPublish : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TWSDLPublish* Pub;
	Autodisp::TWebDispatch* FWebDispatch;
	bool FAdminEnabled;
	WideString FTargetNamespace;
	TSOAPPublishOptions FPublishOptions;
	void __fastcall SetWebDispatch(const Autodisp::TWebDispatch* Value);
	
protected:
	void __fastcall AddInterfaceList(Classes::TStringList* htmldoc, const AnsiString WSDLBaseURL);
	void __fastcall AddPortList(Classes::TStringList* htmldoc, const AnsiString PortType);
	void __fastcall UpdatePortList(Classes::TStrings* PortList, const AnsiString PortType, const AnsiString Command);
	AnsiString __fastcall GetHostScriptBaseURL(Httpapp::TWebRequest* Request);
	
public:
	__fastcall virtual TWSDLHTMLPublish(Classes::TComponent* AOwner);
	__fastcall virtual ~TWSDLHTMLPublish(void);
	bool __fastcall DispatchEnabled(void);
	Masks::TMask* __fastcall DispatchMask(void);
	Httpapp::TMethodType __fastcall DispatchMethodType(void);
	bool __fastcall DispatchRequest(System::TObject* Sender, Httpapp::TWebRequest* Request, Httpapp::TWebResponse* Response);
	void __fastcall ServiceInfo(System::TObject* Sender, Httpapp::TWebRequest* Request, Httpapp::TWebResponse* Response, bool &Handled);
	int __fastcall HandleRequest(Classes::TStringList* Resp, const AnsiString Path, const AnsiString HostScriptBaseURL, AnsiString &ContentType, Httpapp::TWebRequest* Request);
	WideString __fastcall GetTargetNamespace();
	
__published:
	__property Autodisp::TWebDispatch* WebDispatch = {read=FWebDispatch, write=SetWebDispatch};
	__property bool AdminEnabled = {read=FAdminEnabled, write=FAdminEnabled, nodefault};
	__property WideString TargetNamespace = {read=GetTargetNamespace, write=FTargetNamespace};
	__property TSOAPPublishOptions PublishOptions = {read=FPublishOptions, write=FPublishOptions, nodefault};
private:
	void *__IWebDispatch;	/* Httpapp::IWebDispatch */
	
public:
	operator IWebDispatch*(void) { return (IWebDispatch*)&__IWebDispatch; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall WSDLPubFactory(/* out */ System::TObject* &obj);

}	/* namespace Wsdlpub */
using namespace Wsdlpub;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WSDLPub
