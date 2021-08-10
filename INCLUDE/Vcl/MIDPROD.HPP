// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MidProd.pas' rev: 5.00

#ifndef MidProdHPP
#define MidProdHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <WebComp.hpp>	// Pascal unit
#include <CompProd.hpp>	// Pascal unit
#include <XMLBrokr.hpp>	// Pascal unit
#include <PagItems.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <ImgList.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Midprod
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TXMLDataEvent)(System::TObject* Sender, Httpapp::TWebRequest* Request
	, Xmlbrokr::TXMLBroker* XMLBroker, OleVariant &OwnerData);

class DELPHICLASS TMidasPageElements;
class PASCALIMPLEMENTATION TMidasPageElements : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	AnsiString IncludesContent;
	AnsiString StylesContent;
	AnsiString FormsContent;
	AnsiString ScriptContent;
	AnsiString WarningsContent;
	virtual AnsiString __fastcall BodyContent();
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TMidasPageElements(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMidasPageElements(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TStdInclude { jsDom, jsDB, jsDisp, jsBind, jsErrDisp, jsShow };
#pragma option pop

typedef Set<TStdInclude, jsDom, jsShow>  TStdIncludes;

class DELPHICLASS TCustomMidasPageProducer;
class PASCALIMPLEMENTATION TCustomMidasPageProducer : public Pagitems::TPageItemsProducer 
{
	typedef Pagitems::TPageItemsProducer inherited;
	
private:
	TMidasPageElements* FPageElements;
	Classes::TStrings* FStyles;
	bool FEnableXMLIslands;
	AnsiString FIncludePathURL;
	Webcomp::_di_IScriptManager FScriptManager;
	TXMLDataEvent FBeforeGetXMLData;
	TXMLDataEvent FAfterGetXMLData;
	AnsiString FStylesFile;
	Classes::TNotifyEvent FBeforeGetContent;
	Classes::TNotifyEvent FAfterGetContent;
	
protected:
	bool __fastcall CanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual bool __fastcall ImplCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	void __fastcall DoBeforeGetXMLData(Xmlbrokr::TXMLBroker* XMLBroker, OleVariant &OwnerData);
	void __fastcall DoAfterGetXMLData(Xmlbrokr::TXMLBroker* XMLBroker, OleVariant &OwnerData);
	void __fastcall DoBeforeGetContent(void);
	void __fastcall DoAfterGetContent(void);
	virtual void __fastcall GeneratePageElements(void);
	DYNAMIC void __fastcall DoTagEvent(Httpapp::TTag Tag, const AnsiString TagString, Classes::TStrings* 
		TagParams, AnsiString &ReplaceText);
	virtual Webcomp::TWebContentOptions* __fastcall GetContentOptions(bool &Owned);
	AnsiString __fastcall WebContent(Webcomp::TWebContentOptions* Options, System::TObject* Layout);
	Webcomp::_di_IScriptManager __fastcall GetScriptManager();
	AnsiString __fastcall GetXMLDelta(Xmlbrokr::TXMLBroker* XMLBroker);
	AnsiString __fastcall GetXMLErrors(Xmlbrokr::TXMLBroker* XMLBroker);
	virtual AnsiString __fastcall GetDefaultTemplate();
	virtual bool __fastcall GetUseXMLIslands(void);
	virtual AnsiString __fastcall DeclareRowSets();
	virtual AnsiString __fastcall DeclareXMLDocuments();
	virtual AnsiString __fastcall DeclareXMLIslands();
	virtual AnsiString __fastcall DeclareIncludes();
	virtual AnsiString __fastcall DeclareStyles();
	virtual AnsiString __fastcall DeclareFunctions();
	virtual AnsiString __fastcall DeclareWarnings(Classes::TStrings* Warnings);
	virtual AnsiString __fastcall DeclareScript(bool XMLIslands);
	virtual void __fastcall AddScriptComponents(void);
	virtual void __fastcall AddIncludes(void);
	virtual System::TObject* __fastcall CreateScriptManager(Webcomp::TWebContentOptions* Options);
	virtual TMidasPageElements* __fastcall CreatePageElements(void);
	__property Webcomp::_di_IScriptManager ScriptManager = {read=GetScriptManager};
	__property TMidasPageElements* PageElements = {read=FPageElements};
	
public:
	__fastcall virtual TCustomMidasPageProducer(Classes::TComponent* AComponent);
	__fastcall virtual ~TCustomMidasPageProducer(void);
	virtual Xmlbrokr::TXMLBroker* __fastcall FindXMLBroker(Classes::TStrings* TagParams);
	virtual AnsiString __fastcall FindXMLBrokerName(Classes::TStrings* TagParams);
	virtual AnsiString __fastcall GetXMLData(Xmlbrokr::TXMLBroker* XMLBroker, Xmlbrokr::TXMLOptions XMLOptions
		);
	virtual AnsiString __fastcall Content();
	void __fastcall SetIncludePathURL(const AnsiString Value);
	void __fastcall SetStyles(Classes::TStrings* Value);
	void __fastcall SetStylesFile(const AnsiString Value);
	__property AnsiString IncludePathURL = {read=FIncludePathURL, write=SetIncludePathURL};
	__property TXMLDataEvent OnBeforeGetXMLData = {read=FBeforeGetXMLData, write=FBeforeGetXMLData};
	__property TXMLDataEvent OnAfterGetXMLData = {read=FAfterGetXMLData, write=FAfterGetXMLData};
	__property Classes::TNotifyEvent OnBeforeGetContent = {read=FBeforeGetContent, write=FBeforeGetContent
		};
	__property Classes::TNotifyEvent OnAfterGetContent = {read=FAfterGetContent, write=FAfterGetContent
		};
	__property Classes::TStrings* Styles = {read=FStyles, write=SetStyles};
	__property AnsiString StylesFile = {read=FStylesFile, write=SetStylesFile};
	__property bool EnableXMLIslands = {read=FEnableXMLIslands, write=FEnableXMLIslands, default=1};
private:
		
	void *__IWebContent;	/* Webcomp::IWebContent [Content=WebContent] */
	void *__IWebComponentEditor;	/* Webcomp::IWebComponentEditor */
	void *__IScriptProducer;	/* Webcomp::IScriptProducer */
	
public:
	operator IScriptProducer*(void) { return (IScriptProducer*)&__IScriptProducer; }
	operator IWebComponentEditor*(void) { return (IWebComponentEditor*)&__IWebComponentEditor; }
	operator IWebContent*(void) { return (IWebContent*)&__IWebContent; }
	
};


class DELPHICLASS TMidasPageProducer;
class PASCALIMPLEMENTATION TMidasPageProducer : public TCustomMidasPageProducer 
{
	typedef TCustomMidasPageProducer inherited;
	
__published:
	__property IncludePathURL ;
	__property OnBeforeGetXMLData ;
	__property OnAfterGetXMLData ;
	__property OnBeforeGetContent ;
	__property OnAfterGetContent ;
	__property Styles ;
	__property StylesFile ;
	__property WebPageItems ;
	__property EnableXMLIslands ;
public:
	#pragma option push -w-inl
	/* TCustomMidasPageProducer.Create */ inline __fastcall virtual TMidasPageProducer(Classes::TComponent* 
		AComponent) : TCustomMidasPageProducer(AComponent) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomMidasPageProducer.Destroy */ inline __fastcall virtual ~TMidasPageProducer(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define sXMLBroker "XMLBROKER"
#define sXMLReadyVar "xml_ready"
extern PACKAGE AnsiString __fastcall PathInfoToRelativePath(const AnsiString PathInfo);
extern PACKAGE void __fastcall AddStdIncludes(TStdIncludes StdIncludes, Webcomp::_di_IAddScriptElements 
	AddIntf);

}	/* namespace Midprod */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Midprod;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MidProd
