// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MidProd.pas' rev: 6.00

#ifndef MidProdHPP
#define MidProdHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <MidComp.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <WebComp.hpp>	// Pascal unit
#include <CompProd.hpp>	// Pascal unit
#include <XMLBrokr.hpp>	// Pascal unit
#include <PagItems.hpp>	// Pascal unit
#include <HTTPProd.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
namespace Midprod {
  using Midcomp::IScriptProducer;
};

namespace Midprod
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TXMLDataEvent)(System::TObject* Sender, Httpapp::TWebRequest* Request, Xmlbrokr::TXMLBroker* XMLBroker, OleVariant &OwnerData);

class DELPHICLASS TInetXPageElements;
class PASCALIMPLEMENTATION TInetXPageElements : public System::TObject 
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
	/* TObject.Create */ inline __fastcall TInetXPageElements(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TInetXPageElements(void) { }
	#pragma option pop
	
};


typedef TInetXPageElements TMidasPageElements;
;

#pragma option push -b-
enum TStdInclude { jsDom, jsDB, jsDisp, jsBind, jsErrDisp, jsShow };
#pragma option pop

typedef Set<TStdInclude, jsDom, jsShow>  TStdIncludes;

class DELPHICLASS TBaseInetXPageProducer;
class PASCALIMPLEMENTATION TBaseInetXPageProducer : public Pagitems::TBasePageItemsProducer 
{
	typedef Pagitems::TBasePageItemsProducer inherited;
	
private:
	TInetXPageElements* FPageElements;
	Classes::TStrings* FStyles;
	bool FEnableXMLIslands;
	AnsiString FIncludePathURL;
	Midcomp::_di_IScriptManager FScriptManager;
	TXMLDataEvent FBeforeGetXMLData;
	TXMLDataEvent FAfterGetXMLData;
	AnsiString FStylesFile;
	Classes::TNotifyEvent FBeforeGetContent;
	Classes::TNotifyEvent FAfterGetContent;
	Webcomp::TWebContentOptions* FContentOptions;
	
protected:
	void __fastcall SetWebContentOptions(Webcomp::TWebContentOptions* AOptions);
	bool __fastcall CanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual bool __fastcall ImplCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	void __fastcall DoBeforeGetXMLData(Xmlbrokr::TXMLBroker* XMLBroker, OleVariant &OwnerData);
	void __fastcall DoAfterGetXMLData(Xmlbrokr::TXMLBroker* XMLBroker, OleVariant &OwnerData);
	void __fastcall DoBeforeGetContent(void);
	void __fastcall DoAfterGetContent(void);
	virtual void __fastcall GeneratePageElements(void);
	DYNAMIC void __fastcall DoTagEvent(Httpprod::TTag Tag, const AnsiString TagString, Classes::TStrings* TagParams, AnsiString &ReplaceText);
	virtual Webcomp::TWebContentOptions* __fastcall GetContentOptions(bool &Owned);
	Midcomp::_di_IScriptManager __fastcall GetScriptManager();
	AnsiString __fastcall GetXMLDelta(Xmlbrokr::TXMLBroker* XMLBroker);
	AnsiString __fastcall GetXMLErrors(Xmlbrokr::TXMLBroker* XMLBroker);
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
	virtual TInetXPageElements* __fastcall CreatePageElements(void);
	__property Midcomp::_di_IScriptManager ScriptManager = {read=GetScriptManager};
	__property TInetXPageElements* PageElements = {read=FPageElements};
	virtual AnsiString __fastcall GetDefaultTemplate();
	
public:
	__fastcall virtual TBaseInetXPageProducer(Classes::TComponent* AComponent);
	__fastcall virtual ~TBaseInetXPageProducer(void);
	virtual Xmlbrokr::TXMLBroker* __fastcall FindXMLBroker(Classes::TStrings* TagParams);
	virtual AnsiString __fastcall FindXMLBrokerName(Classes::TStrings* TagParams);
	virtual AnsiString __fastcall GetXMLData(Xmlbrokr::TXMLBroker* XMLBroker, Xmlbrokr::TXMLOptions XMLOptions);
	virtual AnsiString __fastcall ContentFromStream(Classes::TStream* InStream);
	/* virtual class method */ virtual AnsiString __fastcall GetRequiredTags(TMetaClass* vmt);
	void __fastcall SetIncludePathURL(const AnsiString Value);
	void __fastcall SetStyles(Classes::TStrings* Value);
	void __fastcall SetStylesFile(const AnsiString Value);
	__property AnsiString IncludePathURL = {read=FIncludePathURL, write=SetIncludePathURL};
	__property TXMLDataEvent OnBeforeGetXMLData = {read=FBeforeGetXMLData, write=FBeforeGetXMLData};
	__property TXMLDataEvent OnAfterGetXMLData = {read=FAfterGetXMLData, write=FAfterGetXMLData};
	__property Classes::TNotifyEvent OnBeforeGetContent = {read=FBeforeGetContent, write=FBeforeGetContent};
	__property Classes::TNotifyEvent OnAfterGetContent = {read=FAfterGetContent, write=FAfterGetContent};
	__property Classes::TStrings* Styles = {read=FStyles, write=SetStyles};
	__property AnsiString StylesFile = {read=FStylesFile, write=SetStylesFile};
	__property bool EnableXMLIslands = {read=FEnableXMLIslands, write=FEnableXMLIslands, default=1};
private:
	void *__IWebComponentEditor;	/* Webcomp::IWebComponentEditor */
	void *__IScriptProducer;	/* Midcomp::IScriptProducer */
	void *__ISetWebContentOptions;	/* Webcomp::ISetWebContentOptions */
	
public:
	operator ISetWebContentOptions*(void) { return (ISetWebContentOptions*)&__ISetWebContentOptions; }
	operator IScriptProducer*(void) { return (IScriptProducer*)&__IScriptProducer; }
	operator IWebComponentEditor*(void) { return (IWebComponentEditor*)&__IWebComponentEditor; }
	
};


typedef TBaseInetXPageProducer TBaseMidasPageProducer;
;

class DELPHICLASS TCustomInetXPageProducer;
class PASCALIMPLEMENTATION TCustomInetXPageProducer : public TBaseInetXPageProducer 
{
	typedef TBaseInetXPageProducer inherited;
	
private:
	AnsiString FHTMLFile;
	Classes::TStrings* FHTMLDoc;
	void __fastcall SetHTMLDoc(const Classes::TStrings* Value);
	void __fastcall SetHTMLFile(const AnsiString Value);
	
protected:
	virtual AnsiString __fastcall GetTemplateFileName();
	virtual Classes::TStream* __fastcall GetTemplateStream(/* out */ bool &AOwned);
	AnsiString __fastcall WebContent(Webcomp::TWebContentOptions* Options, System::TObject* Layout);
	
public:
	__fastcall virtual TCustomInetXPageProducer(Classes::TComponent* AOwner);
	virtual AnsiString __fastcall Content();
	__fastcall virtual ~TCustomInetXPageProducer(void);
	__property Classes::TStrings* HTMLDoc = {read=FHTMLDoc, write=SetHTMLDoc};
	__property AnsiString HTMLFile = {read=FHTMLFile, write=SetHTMLFile};
private:
	void *__IWebContent;	/* Webcomp::IWebContent [Content=WebContent] */
	
public:
	operator IWebContent*(void) { return (IWebContent*)&__IWebContent; }
	
};


typedef TCustomInetXPageProducer TCustomMidasPageProducer;
;

class DELPHICLASS TInetXPageProducer;
class PASCALIMPLEMENTATION TInetXPageProducer : public TCustomInetXPageProducer 
{
	typedef TCustomInetXPageProducer inherited;
	
__published:
	__property IncludePathURL ;
	__property OnBeforeGetXMLData ;
	__property OnAfterGetXMLData ;
	__property OnBeforeGetContent ;
	__property OnAfterGetContent ;
	__property Styles ;
	__property StylesFile ;
	__property WebPageItems ;
	__property EnableXMLIslands  = {default=1};
	__property HTMLDoc ;
	__property HTMLFile ;
	__property ScriptEngine ;
public:
	#pragma option push -w-inl
	/* TCustomInetXPageProducer.Create */ inline __fastcall virtual TInetXPageProducer(Classes::TComponent* AOwner) : TCustomInetXPageProducer(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomInetXPageProducer.Destroy */ inline __fastcall virtual ~TInetXPageProducer(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMidasPageProducer;
class PASCALIMPLEMENTATION TMidasPageProducer : public TInetXPageProducer 
{
	typedef TInetXPageProducer inherited;
	
public:
	#pragma option push -w-inl
	/* TCustomInetXPageProducer.Create */ inline __fastcall virtual TMidasPageProducer(Classes::TComponent* AOwner) : TInetXPageProducer(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomInetXPageProducer.Destroy */ inline __fastcall virtual ~TMidasPageProducer(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define sXMLBroker "XMLBROKER"
#define sXMLReadyVar "xml_ready"
extern PACKAGE AnsiString __fastcall PathInfoToRelativePath(const AnsiString PathInfo);
extern PACKAGE void __fastcall AddStdIncludes(TStdIncludes StdIncludes, Midcomp::_di_IAddScriptElements AddIntf);

}	/* namespace Midprod */
using namespace Midprod;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MidProd
