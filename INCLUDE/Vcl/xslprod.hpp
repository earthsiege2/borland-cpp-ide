// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'XSLProd.pas' rev: 6.00

#ifndef XSLProdHPP
#define XSLProdHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <WebComp.hpp>	// Pascal unit
#include <XMLIntf.hpp>	// Pascal unit
#include <xmldom.hpp>	// Pascal unit
#include <XMLDoc.hpp>	// Pascal unit
#include <HTTPProd.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Xslprod
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomXSLPageProducer;
class PASCALIMPLEMENTATION TCustomXSLPageProducer : public Xmldoc::TXMLDocument 
{
	typedef Xmldoc::TXMLDocument inherited;
	
private:
	Classes::TComponent* FXMLData;
	Classes::TComponent* FDispatcher;
	void __fastcall SetXMLData(const Classes::TComponent* Value);
	Classes::TStream* __fastcall GetXSLStream(bool &AOwned);
	Httpapp::_di_IWebDispatcherAccess __fastcall GetDispatcher();
	void __fastcall SetDispatcher(Classes::TComponent* Value);
	
protected:
	bool __fastcall GetXMLDocument(/* out */ Xmlintf::_di_IXMLDocument &AXMLDocument);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	Classes::TStream* __fastcall GetTemplateStream(/* out */ bool &AOwned);
	Classes::TStream* __fastcall GetProducerTemplateStream(/* out */ bool &AOwned);
	AnsiString __fastcall GetProducerTemplateFileName();
	bool __fastcall HasScriptView(void);
	bool __fastcall HasXMLBrowserView(void);
	bool __fastcall HasXSLBrowserView(void);
	bool __fastcall HasHTMLBrowserView(void);
	Classes::TStream* __fastcall GetXMLData(bool &Owned);
	Classes::TStream* __fastcall GetXSLData(bool &Owned);
	AnsiString __fastcall GetTemplateFileType();
	void __fastcall SetAppDispatcher(const Classes::TComponent* ADispatcher);
	Classes::TComponent* __fastcall GetAppDispatcher(void);
	AnsiString __fastcall ProduceContent();
	AnsiString __fastcall ProduceContentFromStream(Classes::TStream* Stream);
	AnsiString __fastcall ProduceContentFromString(const AnsiString S);
	
public:
	AnsiString __fastcall ContentFromString(const AnsiString S);
	virtual AnsiString __fastcall ContentFromStream(Classes::TStream* InStream);
	virtual AnsiString __fastcall Content();
	virtual AnsiString __fastcall ContentFromWideString(const WideString S);
	__property Httpapp::_di_IWebDispatcherAccess Dispatcher = {read=GetDispatcher};
	__property Classes::TComponent* DispatcherComponent = {read=FDispatcher};
	__property Classes::TComponent* XMLData = {read=FXMLData, write=SetXMLData};
public:
	#pragma option push -w-inl
	/* TXMLDocument.Create */ inline __fastcall TCustomXSLPageProducer(const WideString AFileName)/* overload */ : Xmldoc::TXMLDocument(AFileName) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLDocument.Destroy */ inline __fastcall virtual ~TCustomXSLPageProducer(void) { }
	#pragma option pop
	
private:
	void *__IProduceContent;	/* Httpapp::IProduceContent */
	void *__IProduceContentFrom;	/* Httpapp::IProduceContentFrom */
	void *__ISetAppDispatcher;	/* Httpapp::ISetAppDispatcher */
	void *__IGetAppDispatcher;	/* Httpapp::IGetAppDispatcher */
	void *__IProducerEditorViewSupport;	/* Webcomp::IProducerEditorViewSupport */
	void *__IGetProducerTemplate;	/* Httpprod::IGetProducerTemplate */
	
public:
	operator IGetProducerTemplate*(void) { return (IGetProducerTemplate*)&__IGetProducerTemplate; }
	operator IProducerEditorViewSupport*(void) { return (IProducerEditorViewSupport*)&__IProducerEditorViewSupport; }
	operator IGetAppDispatcher*(void) { return (IGetAppDispatcher*)&__IGetAppDispatcher; }
	operator ISetAppDispatcher*(void) { return (ISetAppDispatcher*)&__ISetAppDispatcher; }
	operator IProduceContentFrom*(void) { return (IProduceContentFrom*)&__IProduceContentFrom; }
	operator IProduceContent*(void) { return (IProduceContent*)&__IProduceContent; }
	
};


class DELPHICLASS TXSLPageProducer;
class PASCALIMPLEMENTATION TXSLPageProducer : public TCustomXSLPageProducer 
{
	typedef TCustomXSLPageProducer inherited;
	
__published:
	__property XMLData ;
public:
	#pragma option push -w-inl
	/* TXMLDocument.Create */ inline __fastcall TXSLPageProducer(const WideString AFileName)/* overload */ : TCustomXSLPageProducer(AFileName) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXMLDocument.Destroy */ inline __fastcall virtual ~TXSLPageProducer(void) { }
	#pragma option pop
	
};


class DELPHICLASS EXSLPageProducerError;
class PASCALIMPLEMENTATION EXSLPageProducerError : public Httpapp::EWebBrokerException 
{
	typedef Httpapp::EWebBrokerException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EXSLPageProducerError(const AnsiString Msg) : Httpapp::EWebBrokerException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EXSLPageProducerError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Httpapp::EWebBrokerException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EXSLPageProducerError(int Ident)/* overload */ : Httpapp::EWebBrokerException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EXSLPageProducerError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Httpapp::EWebBrokerException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EXSLPageProducerError(const AnsiString Msg, int AHelpContext) : Httpapp::EWebBrokerException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EXSLPageProducerError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Httpapp::EWebBrokerException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EXSLPageProducerError(int Ident, int AHelpContext)/* overload */ : Httpapp::EWebBrokerException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EXSLPageProducerError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Httpapp::EWebBrokerException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EXSLPageProducerError(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Xslprod */
using namespace Xslprod;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// XSLProd
