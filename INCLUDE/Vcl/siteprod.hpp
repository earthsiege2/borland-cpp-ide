// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SiteProd.pas' rev: 6.00

#ifndef SiteProdHPP
#define SiteProdHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <WebForm.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <SiteComp.hpp>	// Pascal unit
#include <DSProd.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <WebComp.hpp>	// Pascal unit
#include <CompProd.hpp>	// Pascal unit
#include <MidProd.hpp>	// Pascal unit
#include <PagItems.hpp>	// Pascal unit
#include <HTTPProd.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Siteprod
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSitePageElements;
class PASCALIMPLEMENTATION TSitePageElements : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	AnsiString StylesContent;
	AnsiString WarningsContent;
	AnsiString ServerScriptContent;
	AnsiString ServerFunctionsContent;
	AnsiString ServerVariablesContent;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TSitePageElements(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TSitePageElements(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBaseAdapterPageProducer;
class PASCALIMPLEMENTATION TBaseAdapterPageProducer : public Pagitems::TBasePageItemsProducer 
{
	typedef Pagitems::TBasePageItemsProducer inherited;
	
private:
	TSitePageElements* FPageElements;
	Classes::TStrings* FStyles;
	AnsiString FStylesFile;
	Classes::TNotifyEvent FBeforeGetContent;
	Classes::TNotifyEvent FAfterGetContent;
	int FLockContent;
	Webcomp::TWebContentOptions* FContentOptions;
	void __fastcall LockContent(void);
	void __fastcall UnlockContent(void);
	AnsiString __fastcall DeclareScriptFunctions(Webform::TGeneratedFunctions* AGeneratedFunctions);
	AnsiString __fastcall DeclareScriptVariables(Classes::TStrings* AVariables);
	
protected:
	bool __fastcall HasScriptView(void);
	bool __fastcall HasXMLBrowserView(void);
	bool __fastcall HasXSLBrowserView(void);
	bool __fastcall HasHTMLBrowserView(void);
	Classes::TStream* __fastcall GetXMLData(bool &Owned);
	Classes::TStream* __fastcall GetXSLData(bool &Owned);
	AnsiString __fastcall GetTemplateFileType();
	void __fastcall SetWebContentOptions(Webcomp::TWebContentOptions* AOptions);
	bool __fastcall CanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	virtual bool __fastcall ImplCanAddClass(Classes::TComponent* AParent, TMetaClass* AClass);
	void __fastcall DoBeforeGetContent(void);
	void __fastcall DoAfterGetContent(void);
	virtual void __fastcall GeneratePageElements(void);
	DYNAMIC void __fastcall DoTagEvent(Httpprod::TTag Tag, const AnsiString TagString, Classes::TStrings* TagParams, AnsiString &ReplaceText);
	virtual bool __fastcall HandleScriptTag(const AnsiString TagString, Classes::TStrings* TagParams, AnsiString &ReplaceString);
	virtual AnsiString __fastcall DeclareStyles();
	virtual AnsiString __fastcall DeclareWarnings(Classes::TStrings* Warnings);
	virtual TSitePageElements* __fastcall CreatePageElements(void);
	__property TSitePageElements* PageElements = {read=FPageElements};
	virtual Webcomp::TWebContentOptions* __fastcall GetContentOptions(bool &Owned);
	virtual AnsiString __fastcall GetDefaultTemplate();
	
public:
	__fastcall virtual TBaseAdapterPageProducer(Classes::TComponent* AComponent);
	__fastcall virtual ~TBaseAdapterPageProducer(void);
	virtual AnsiString __fastcall ContentFromStream(Classes::TStream* InStream);
	/*         class method */ static AnsiString __fastcall GetRequiredTags(TMetaClass* vmt);
	/*         class method */ static void __fastcall GetScriptEngines(TMetaClass* vmt, Classes::TStrings* S);
	void __fastcall SetStyles(Classes::TStrings* Value);
	void __fastcall SetStylesFile(const AnsiString Value);
	__property Classes::TNotifyEvent OnBeforeGetContent = {read=FBeforeGetContent, write=FBeforeGetContent};
	__property Classes::TNotifyEvent OnAfterGetContent = {read=FAfterGetContent, write=FAfterGetContent};
	__property Classes::TStrings* Styles = {read=FStyles, write=SetStyles};
	__property AnsiString StylesFile = {read=FStylesFile, write=SetStylesFile};
private:
	void *__IWebComponentEditor;	/* Webcomp::IWebComponentEditor */
	void *__ISetWebContentOptions;	/* Webcomp::ISetWebContentOptions */
	void *__IProducerEditorViewSupport;	/* Webcomp::IProducerEditorViewSupport */
	
public:
	operator IProducerEditorViewSupport*(void) { return (IProducerEditorViewSupport*)&__IProducerEditorViewSupport; }
	operator ISetWebContentOptions*(void) { return (ISetWebContentOptions*)&__ISetWebContentOptions; }
	operator IWebComponentEditor*(void) { return (IWebComponentEditor*)&__IWebComponentEditor; }
	
};


class DELPHICLASS TCustomAdapterPageProducer;
class PASCALIMPLEMENTATION TCustomAdapterPageProducer : public TBaseAdapterPageProducer 
{
	typedef TBaseAdapterPageProducer inherited;
	
private:
	AnsiString FHTMLFile;
	Classes::TStrings* FHTMLDoc;
	
protected:
	virtual AnsiString __fastcall GetTemplateFileName();
	virtual Classes::TStream* __fastcall GetTemplateStream(/* out */ bool &AOwned);
	AnsiString __fastcall WebContent(Webcomp::TWebContentOptions* Options, System::TObject* Layout);
	void __fastcall SetHTMLDoc(const Classes::TStrings* Value);
	void __fastcall SetHTMLFile(const AnsiString Value);
	
public:
	__fastcall virtual TCustomAdapterPageProducer(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomAdapterPageProducer(void);
	__property Classes::TStrings* HTMLDoc = {read=FHTMLDoc, write=SetHTMLDoc};
	__property AnsiString HTMLFile = {read=FHTMLFile, write=SetHTMLFile};
private:
	void *__IWebContent;	/* Webcomp::IWebContent [Content=WebContent] */
	
public:
	operator IWebContent*(void) { return (IWebContent*)&__IWebContent; }
	
};


class DELPHICLASS TAdapterPageProducer;
class PASCALIMPLEMENTATION TAdapterPageProducer : public TCustomAdapterPageProducer 
{
	typedef TCustomAdapterPageProducer inherited;
	
__published:
	__property OnBeforeGetContent ;
	__property OnAfterGetContent ;
	__property Styles ;
	__property StylesFile ;
	__property WebPageItems ;
	__property HTMLDoc ;
	__property HTMLFile ;
public:
	#pragma option push -w-inl
	/* TCustomAdapterPageProducer.Create */ inline __fastcall virtual TAdapterPageProducer(Classes::TComponent* AOwner) : TCustomAdapterPageProducer(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAdapterPageProducer.Destroy */ inline __fastcall virtual ~TAdapterPageProducer(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Siteprod */
using namespace Siteprod;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SiteProd
