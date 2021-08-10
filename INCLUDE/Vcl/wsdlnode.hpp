// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WSDLNode.pas' rev: 6.00

#ifndef WSDLNodeHPP
#define WSDLNodeHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IntfInfo.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <WSDLItems.hpp>	// Pascal unit
#include <XMLIntf.hpp>	// Pascal unit
#include <XMLDoc.hpp>	// Pascal unit
#include <OPConvert.hpp>	// Pascal unit
#include <WebNode.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Wsdlnode
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EWSDLLoadException;
class PASCALIMPLEMENTATION EWSDLLoadException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EWSDLLoadException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EWSDLLoadException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EWSDLLoadException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EWSDLLoadException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EWSDLLoadException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EWSDLLoadException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EWSDLLoadException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EWSDLLoadException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EWSDLLoadException(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWSDLView;
class PASCALIMPLEMENTATION TWSDLView : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	AnsiString FUserName;
	AnsiString FPassword;
	AnsiString FProxy;
	AnsiString FPortType;
	AnsiString FPort;
	AnsiString FOperation;
	AnsiString FService;
	Wsdlitems::TWSDLItems* FWSDL;
	Xmlintf::_di_IXMLDocument FIWSDL;
	void __fastcall SetWSDL(Wsdlitems::TWSDLItems* Value);
	void __fastcall SetOperation(const AnsiString Op);
	AnsiString __fastcall GetService();
	AnsiString __fastcall GetPort();
	
public:
	Typinfo::TTypeInfo *IntfInfo;
	void __fastcall Activate(void);
	void __fastcall SetDesignState(bool Designing);
	
__published:
	__property AnsiString PortType = {read=FPortType, write=FPortType};
	__property AnsiString Port = {read=GetPort, write=FPort};
	__property AnsiString Operation = {read=FOperation, write=SetOperation};
	__property AnsiString Service = {read=GetService, write=FService};
	__property AnsiString UserName = {read=FUserName, write=FUserName};
	__property AnsiString Password = {read=FPassword, write=FPassword};
	__property AnsiString Proxy = {read=FProxy, write=FProxy};
	__property Wsdlitems::TWSDLItems* WSDL = {read=FWSDL, write=SetWSDL};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TWSDLView(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TWSDLView(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWSDLClientNode;
class PASCALIMPLEMENTATION TWSDLClientNode : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TWSDLView* FWSDLView;
	Webnode::_di_IWebNode FTransportNode;
	void __fastcall SetTransportNode(Webnode::_di_IWebNode Value);
	
public:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall Execute(const WideString DataMsg, Classes::TStream* Resp);
	void __fastcall BeforeExecute(const Intfinfo::TIntfMetaData &IntfMetaData, const Intfinfo::TIntfMethEntry &MethodMetaData);
	
__published:
	__property TWSDLView* WSDLView = {read=FWSDLView, write=FWSDLView};
	__property Webnode::_di_IWebNode TransportNode = {read=FTransportNode, write=SetTransportNode};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TWSDLClientNode(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TWSDLClientNode(void) { }
	#pragma option pop
	
private:
	void *__IWebNode;	/* Webnode::IWebNode */
	
public:
	operator IWebNode*(void) { return (IWebNode*)&__IWebNode; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall ActivateWSDL(Wsdlitems::TWSDLItems* WSDL, const AnsiString Name, const AnsiString Password, const AnsiString Proxy);

}	/* namespace Wsdlnode */
using namespace Wsdlnode;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WSDLNode
