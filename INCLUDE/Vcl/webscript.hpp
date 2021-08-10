// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WebScript.pas' rev: 6.00

#ifndef WebScriptHPP
#define WebScriptHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ComObj.hpp>	// Pascal unit
#include <WebCntxt.hpp>	// Pascal unit
#include <WebAuto.hpp>	// Pascal unit
#include <WebScript_TLB.hpp>	// Pascal unit
#include <SiteComp.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <AscrLib.hpp>	// Pascal unit
#include <HTTPProd.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Webscript
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EActiveScriptError;
class PASCALIMPLEMENTATION EActiveScriptError : public Httpapp::EWebBrokerException 
{
	typedef Httpapp::EWebBrokerException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EActiveScriptError(const AnsiString Msg) : Httpapp::EWebBrokerException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EActiveScriptError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Httpapp::EWebBrokerException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EActiveScriptError(int Ident)/* overload */ : Httpapp::EWebBrokerException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EActiveScriptError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Httpapp::EWebBrokerException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EActiveScriptError(const AnsiString Msg, int AHelpContext) : Httpapp::EWebBrokerException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EActiveScriptError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Httpapp::EWebBrokerException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EActiveScriptError(int Ident, int AHelpContext)/* overload */ : Httpapp::EWebBrokerException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EActiveScriptError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Httpapp::EWebBrokerException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EActiveScriptError(void) { }
	#pragma option pop
	
};


class DELPHICLASS ECannotCreateScriptEngine;
class PASCALIMPLEMENTATION ECannotCreateScriptEngine : public EActiveScriptError 
{
	typedef EActiveScriptError inherited;
	
private:
	AnsiString FProgID;
	HRESULT FHR;
	
public:
	__fastcall ECannotCreateScriptEngine(const AnsiString AProgID, HRESULT AHR);
	__property AnsiString ProgID = {read=FProgID};
	__property HRESULT HR = {read=FHR, nodefault};
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ECannotCreateScriptEngine(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EActiveScriptError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ECannotCreateScriptEngine(int Ident)/* overload */ : EActiveScriptError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ECannotCreateScriptEngine(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EActiveScriptError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ECannotCreateScriptEngine(const AnsiString Msg, int AHelpContext) : EActiveScriptError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ECannotCreateScriptEngine(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EActiveScriptError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ECannotCreateScriptEngine(int Ident, int AHelpContext)/* overload */ : EActiveScriptError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ECannotCreateScriptEngine(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EActiveScriptError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ECannotCreateScriptEngine(void) { }
	#pragma option pop
	
};


class DELPHICLASS ERecursiveIncludeFile;
class PASCALIMPLEMENTATION ERecursiveIncludeFile : public EActiveScriptError 
{
	typedef EActiveScriptError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ERecursiveIncludeFile(const AnsiString Msg) : EActiveScriptError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ERecursiveIncludeFile(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EActiveScriptError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ERecursiveIncludeFile(int Ident)/* overload */ : EActiveScriptError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ERecursiveIncludeFile(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EActiveScriptError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ERecursiveIncludeFile(const AnsiString Msg, int AHelpContext) : EActiveScriptError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ERecursiveIncludeFile(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EActiveScriptError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ERecursiveIncludeFile(int Ident, int AHelpContext)/* overload */ : EActiveScriptError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ERecursiveIncludeFile(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EActiveScriptError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ERecursiveIncludeFile(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TIncludeType { incFile, incPage };
#pragma option pop

typedef TMetaClass*TScriptSiteClass;

class DELPHICLASS TVariableLookup;
class PASCALIMPLEMENTATION TVariableLookup : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Variant FValue;
	AnsiString FIdent;
	System::TObject* FObject;
	System::TObject* FWebModuleContext;
	Classes::TComponent* __fastcall FindFieldVariable(Classes::TComponent* AParent, const AnsiString AName);
	Classes::TComponent* __fastcall FindVariable(const AnsiString AName);
	void __fastcall SetIdent(const AnsiString Value);
	System::TObject* __fastcall GetObject(void);
	
public:
	Classes::TComponent* __fastcall FindGlobalVariable(const AnsiString AName);
	Classes::TComponent* __fastcall FindGlobalVariableContainer(const AnsiString AName);
	__fastcall TVariableLookup(const AnsiString AIdent, System::TObject* AWebModuleContext);
	bool __fastcall LookupObject(void);
	__property AnsiString Ident = {read=FIdent, write=SetIdent};
	__property System::TObject* Obj = {read=GetObject};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TVariableLookup(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TGlobalScriptVariables { svPage, svPages, svModules, svApplication, svSession, svEndUser, svResponse, svRequest, svHTMLItems, svProducer };
#pragma option pop

class DELPHICLASS TScriptSite;
class PASCALIMPLEMENTATION TScriptSite : public TBaseScriptSite 
{
	typedef TBaseScriptSite inherited;
	
public:
	#pragma option push -w-inl
	/* TBaseScriptSite.Create */ inline __fastcall virtual TScriptSite(Httpprod::_di_IScriptProducer AProducer) : TBaseScriptSite(AProducer) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBaseScriptSite.Destroy */ inline __fastcall virtual ~TScriptSite(void) { }
	#pragma option pop
	
};


class DELPHICLASS TScriptErrors;
class PASCALIMPLEMENTATION TScriptErrors : public Httpprod::TAbstractScriptErrors 
{
	typedef Httpprod::TAbstractScriptErrors inherited;
	
private:
	Contnrs::TObjectList* FList;
	
protected:
	virtual Httpprod::TAbstractScriptError* __fastcall GetError(int I);
	virtual int __fastcall GetErrorCount(void);
	
public:
	__fastcall TScriptErrors(void);
	__fastcall virtual ~TScriptErrors(void);
	virtual void __fastcall Add(const Httpprod::TAbstractScriptError* AError);
};


class DELPHICLASS TScriptError;
class DELPHICLASS TLineNumberMap;
class PASCALIMPLEMENTATION TScriptError : public Httpprod::TAbstractScriptError 
{
	typedef Httpprod::TAbstractScriptError inherited;
	
private:
	int FLine;
	int FCharPos;
	AnsiString FDescription;
	AnsiString FSourceLine;
	AnsiString FFileName;
	
protected:
	virtual AnsiString __fastcall GetSourceLine();
	virtual int __fastcall GetCharPos(void);
	virtual int __fastcall GetLine(void);
	virtual AnsiString __fastcall GetDescription();
	virtual void __fastcall SetDescription(const AnsiString AValue);
	virtual AnsiString __fastcall GetFileName();
	
public:
	__fastcall TScriptError(const Ascrlib::_di_IActiveScriptError ScriptError, TLineNumberMap* ALineNumberMap)/* overload */;
	__fastcall TScriptError(Sysutils::Exception* E)/* overload */;
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TScriptError(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWebRequestWrapper;
class PASCALIMPLEMENTATION TWebRequestWrapper : public TScriptObject 
{
	typedef TScriptObject inherited;
	
protected:
	Httpapp::TWebRequest* __fastcall Request(void);
	HRESULT __safecall Get_PathInfo(WideString &Get_PathInfo_result);
	HRESULT __safecall Get_ScriptName(WideString &Get_ScriptName_result);
	HRESULT __safecall Get_Host(WideString &Get_Host_result);
	
public:
	__fastcall TWebRequestWrapper(Httpprod::_di_IScriptContext AContext);
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TWebRequestWrapper(const System::_di_IInterface Controller) : TScriptObject(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TWebRequestWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TScriptObject(Factory, Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.Destroy */ inline __fastcall virtual ~TWebRequestWrapper(void) { }
	#pragma option pop
	
private:
	void *__IRequestWrapper;	/* Webscript_tlb::IRequestWrapper */
	
public:
	operator IRequestWrapper*(void) { return (IRequestWrapper*)&__IRequestWrapper; }
	
};


class DELPHICLASS TWebSessionIDWrapper;
class PASCALIMPLEMENTATION TWebSessionIDWrapper : public TScriptObject 
{
	typedef TScriptObject inherited;
	
protected:
	HRESULT __safecall Get_Value(WideString &Get_Value_result);
public:
	#pragma option push -w-inl
	/* TComObject.Create */ inline __fastcall TWebSessionIDWrapper(void) : TScriptObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TWebSessionIDWrapper(const System::_di_IInterface Controller) : TScriptObject(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TWebSessionIDWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TScriptObject(Factory, Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.Destroy */ inline __fastcall virtual ~TWebSessionIDWrapper(void) { }
	#pragma option pop
	
private:
	void *__ISessionIDWrapper;	/* Webscript_tlb::ISessionIDWrapper */
	
public:
	operator ISessionIDWrapper*(void) { return (ISessionIDWrapper*)&__ISessionIDWrapper; }
	
};


class DELPHICLASS TWebSessionWrapper;
class PASCALIMPLEMENTATION TWebSessionWrapper : public TScriptObject 
{
	typedef TScriptObject inherited;
	
private:
	Webscript_tlb::_di_ISessionIDWrapper FSessionIDWrapper;
	
protected:
	HRESULT __safecall Get_Values(const WideString Name, OleVariant &Get_Values_result);
	HRESULT __safecall Get_SessionID(Webscript_tlb::_di_ISessionIDWrapper &Get_SessionID_result);
public:
	#pragma option push -w-inl
	/* TComObject.Create */ inline __fastcall TWebSessionWrapper(void) : TScriptObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TWebSessionWrapper(const System::_di_IInterface Controller) : TScriptObject(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TWebSessionWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TScriptObject(Factory, Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.Destroy */ inline __fastcall virtual ~TWebSessionWrapper(void) { }
	#pragma option pop
	
private:
	void *__ISessionWrapper;	/* Webscript_tlb::ISessionWrapper */
	
public:
	operator ISessionWrapper*(void) { return (ISessionWrapper*)&__ISessionWrapper; }
	
};


class DELPHICLASS TCurrentWebPageInfo;
class PASCALIMPLEMENTATION TCurrentWebPageInfo : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Httpprod::_di_IScriptContext FContext;
	Webcntxt::_di_IWebPageInfo FWebPageInfo;
	
protected:
	Webcntxt::_di_IWebPageInfo __fastcall WebPageInfo();
	AnsiString __fastcall GetPageName();
	AnsiString __fastcall GetPageHREF();
	AnsiString __fastcall GetPageDescription();
	AnsiString __fastcall GetPageTitle();
	bool __fastcall GetPageIsPublished(void);
	bool __fastcall GetLoginRequired(void);
	bool __fastcall GetHasViewAccess(void);
	
public:
	__fastcall TCurrentWebPageInfo(Httpprod::_di_IScriptContext AContext);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TCurrentWebPageInfo(void) { }
	#pragma option pop
	
private:
	void *__IWebPageInfo;	/* Webcntxt::IWebPageInfo */
	
public:
	operator IWebPageInfo*(void) { return (IWebPageInfo*)&__IWebPageInfo; }
	
};


class DELPHICLASS TSampleWebPageInfo;
class PASCALIMPLEMENTATION TSampleWebPageInfo : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	AnsiString FPageName;
	
protected:
	AnsiString __fastcall GetPageName();
	AnsiString __fastcall GetPageHREF();
	AnsiString __fastcall GetPageDescription();
	AnsiString __fastcall GetPageTitle();
	bool __fastcall GetPageIsPublished(void);
	bool __fastcall GetLoginRequired(void);
	bool __fastcall GetHasViewAccess(void);
	
public:
	__fastcall TSampleWebPageInfo(const AnsiString APageName);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TSampleWebPageInfo(void) { }
	#pragma option pop
	
private:
	void *__IWebPageInfo;	/* Webcntxt::IWebPageInfo */
	
public:
	operator IWebPageInfo*(void) { return (IWebPageInfo*)&__IWebPageInfo; }
	
};


class DELPHICLASS TWebPageWrapper;
class PASCALIMPLEMENTATION TWebPageWrapper : public TScriptObject 
{
	typedef TScriptObject inherited;
	
private:
	Webcntxt::_di_IWebPageInfo FPageInfo;
	Sitecomp::_di_IPageDispatcher FPageDispatcher;
	Httpprod::_di_IScriptContext FContext;
	
protected:
	HRESULT __safecall Get_Name(WideString &Get_Name_result);
	HRESULT __safecall Get_HREF(WideString &Get_HREF_result);
	HRESULT __safecall Get_Title(WideString &Get_Title_result);
	HRESULT __safecall Get_Description(WideString &Get_Description_result);
	HRESULT __safecall Get_Published_(Word &Get_Published__result);
	HRESULT __safecall Get_LoginRequired(Word &Get_LoginRequired_result);
	HRESULT __safecall Get_CanView(Word &Get_CanView_result);
	HRESULT __safecall Get_DefaultAction(Webscript_tlb::_di_IAdapterActionWrapper &Get_DefaultAction_result);
	
public:
	__fastcall TWebPageWrapper(Httpprod::_di_IScriptContext AContext, const Webcntxt::_di_IWebPageInfo APageInfo);
	Sitecomp::_di_IPageDispatcher __fastcall PageDispatcher();
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Name() { WideString r; HRESULT hr = Get_Name(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Name = {read=_scw_Get_Name};
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TWebPageWrapper(const System::_di_IInterface Controller) : TScriptObject(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TWebPageWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TScriptObject(Factory, Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.Destroy */ inline __fastcall virtual ~TWebPageWrapper(void) { }
	#pragma option pop
	
private:
	void *__IPageWrapper;	/* Webscript_tlb::IPageWrapper */
	
public:
	operator IPageWrapper*(void) { return (IPageWrapper*)&__IPageWrapper; }
	
};


class DELPHICLASS TWebModulesWrapper;
class PASCALIMPLEMENTATION TWebModulesWrapper : public Webauto::TWebComponentsWrapper 
{
	typedef Webauto::TWebComponentsWrapper inherited;
	
protected:
	HRESULT __safecall Get_NewEnum(System::_di_IInterface &Get_NewEnum_result);
	virtual System::TObject* __fastcall FindObject(const AnsiString AName);
public:
	#pragma option push -w-inl
	/* TWebComponentsWrapper.Create */ inline __fastcall virtual TWebModulesWrapper(Classes::TComponent* AObject) : Webauto::TWebComponentsWrapper(AObject) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebComponentsWrapper.Destroy */ inline __fastcall virtual ~TWebModulesWrapper(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TWebModulesWrapper(const System::_di_IInterface Controller) : Webauto::TWebComponentsWrapper(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TWebModulesWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : Webauto::TWebComponentsWrapper(Factory, Controller) { }
	#pragma option pop
	
private:
	void *__IModulesWrapper;	/* Webscript_tlb::IModulesWrapper */
	
public:
	operator IModulesWrapper*(void) { return (IModulesWrapper*)&__IModulesWrapper; }
	
};


class DELPHICLASS TWebPagesWrapper;
class PASCALIMPLEMENTATION TWebPagesWrapper : public Webauto::TWebComponentsWrapper 
{
	typedef Webauto::TWebComponentsWrapper inherited;
	
private:
	Classes::_di_IInterfaceList FSamplePages;
	Httpprod::_di_IScriptContext FContext;
	
protected:
	HRESULT __safecall Get_NewEnum(System::_di_IInterface &Get_NewEnum_result);
	virtual _di_IDispatch __fastcall DispatchOfName(const AnsiString AName);
	Webcntxt::_di_IWebPageInfo __fastcall FindPageInfo(const AnsiString AName);
	Webcntxt::_di_IWebPageInfo __fastcall FindSamplePage(const AnsiString AName);
	
public:
	__fastcall TWebPagesWrapper(Httpprod::_di_IScriptContext AContext);
public:
	#pragma option push -w-inl
	/* TWebComponentsWrapper.Destroy */ inline __fastcall virtual ~TWebPagesWrapper(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TWebPagesWrapper(const System::_di_IInterface Controller) : Webauto::TWebComponentsWrapper(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TWebPagesWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : Webauto::TWebComponentsWrapper(Factory, Controller) { }
	#pragma option pop
	
private:
	void *__IPagesWrapper;	/* Webscript_tlb::IPagesWrapper */
	
public:
	operator IPagesWrapper*(void) { return (IPagesWrapper*)&__IPagesWrapper; }
	
};


class DELPHICLASS TListEnumerator;
class PASCALIMPLEMENTATION TListEnumerator : public TScriptObject 
{
	typedef TScriptObject inherited;
	
private:
	bool FReset;
	int FCurrentIndex;
	
protected:
	virtual int __fastcall GetListCount(void);
	virtual _di_IDispatch __fastcall GetListItem(int I);
	HRESULT __stdcall Clone(/* out */ _di_IEnumVariant &ppenum);
	HRESULT __stdcall Next(unsigned celt, OleVariant &rgvar, /* out */ unsigned &pceltFetched);
	HRESULT __stdcall Reset(void);
	HRESULT __stdcall Skip(unsigned celt);
	bool __fastcall EOF(void);
	
public:
	__fastcall TListEnumerator(void);
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TListEnumerator(const System::_di_IInterface Controller) : TScriptObject(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TListEnumerator(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TScriptObject(Factory, Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.Destroy */ inline __fastcall virtual ~TListEnumerator(void) { }
	#pragma option pop
	
private:
	void *__IEnumVariant;	/* IEnumVariant */
	
public:
	operator IEnumVariant*(void) { return (IEnumVariant*)&__IEnumVariant; }
	
};


class DELPHICLASS TWebPagesEnumerator;
class PASCALIMPLEMENTATION TWebPagesEnumerator : public TListEnumerator 
{
	typedef TListEnumerator inherited;
	
private:
	Httpprod::_di_IScriptContext FContext;
	
protected:
	virtual int __fastcall GetListCount(void);
	virtual _di_IDispatch __fastcall GetListItem(int I);
	
public:
	__fastcall TWebPagesEnumerator(Httpprod::_di_IScriptContext AContext);
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TWebPagesEnumerator(const System::_di_IInterface Controller) : TListEnumerator(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TWebPagesEnumerator(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TListEnumerator(Factory, Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.Destroy */ inline __fastcall virtual ~TWebPagesEnumerator(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWebModulesEnumerator;
class PASCALIMPLEMENTATION TWebModulesEnumerator : public TListEnumerator 
{
	typedef TListEnumerator inherited;
	
protected:
	virtual int __fastcall GetListCount(void);
	virtual _di_IDispatch __fastcall GetListItem(int I);
public:
	#pragma option push -w-inl
	/* TListEnumerator.Create */ inline __fastcall TWebModulesEnumerator(void) : TListEnumerator() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TWebModulesEnumerator(const System::_di_IInterface Controller) : TListEnumerator(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TWebModulesEnumerator(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TListEnumerator(Factory, Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.Destroy */ inline __fastcall virtual ~TWebModulesEnumerator(void) { }
	#pragma option pop
	
};


#pragma pack(push, 4)
struct TLineNumbers
{
	int SourceStartLine;
	int SourceLineCount;
	int DestStartLine;
	int DestLineCount;
	TScriptIncludeFile* ScriptIncludeFile;
} ;
#pragma pack(pop)

typedef TLineNumbers *PLineNumbers;

typedef DynamicArray<TLineNumbers >  WebScript__83;

class PASCALIMPLEMENTATION TLineNumberMap : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	PLineNumbers operator[](int I) { return Items[I]; }
	
private:
	AnsiString FFileName;
	DynamicArray<TLineNumbers >  FArray;
	int __fastcall GetCount(void);
	PLineNumbers __fastcall GetLineNumbers(int I);
	
public:
	PLineNumbers __fastcall New(void);
	int __fastcall DestLineToSourceLine(int ALine, AnsiString &AFileName);
	__property int Count = {read=GetCount, nodefault};
	__property PLineNumbers Items[int I] = {read=GetLineNumbers/*, default*/};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TLineNumberMap(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TLineNumberMap(void) { }
	#pragma option pop
	
};


typedef AnsiString WebScript__93[10];

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TMetaClass*ScriptSiteClass;
extern PACKAGE AnsiString GlobalScriptVariableNames[10];

}	/* namespace Webscript */
using namespace Webscript;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WebScript
