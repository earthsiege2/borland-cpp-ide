// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WebModu.pas' rev: 6.00

#ifndef WebModuHPP
#define WebModuHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <SiteComp.hpp>	// Pascal unit
#include <WebDisp.hpp>	// Pascal unit
#include <WebComp.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <HTTPProd.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Webmodu
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSiteModuleHelper;
class DELPHICLASS TWebNotifyContainer;
class PASCALIMPLEMENTATION TWebNotifyContainer : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	Contnrs::TComponentList* FList;
	int __fastcall GetCount(void);
	
public:
	__fastcall TWebNotifyContainer(void);
	__fastcall virtual ~TWebNotifyContainer(void);
	void __fastcall NotifyWebActivate(void);
	void __fastcall NotifyWebDeactivate(void);
	void __fastcall Add(Classes::TComponent* AComponent);
};


class PASCALIMPLEMENTATION TSiteModuleHelper : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Httpapp::TWebRequest* FRequest;
	Httpapp::TWebResponse* FResponse;
	Httpapp::TAbstractWebSession* FSession;
	Classes::TComponent* FModule;
	Classes::TNotifyEvent FOnActivate;
	Classes::TNotifyEvent FOnDeactivate;
	System::TObject* FWebModuleContext;
	TWebNotifyContainer* FWebNotifyContainer;
	int FIteratorIndex;
	int FIteratorCount;
	System::TObject* __fastcall GetWebModuleContext(void);
	
protected:
	Classes::TComponent* __fastcall FindVariable(const AnsiString AName);
	Classes::TComponent* __fastcall FindVariableContainer(const AnsiString AName);
	int __fastcall GetVariableCount(void);
	Classes::TComponent* __fastcall GetVariable(int I);
	virtual Classes::TComponent* __fastcall FindNamedVariable(const AnsiString AName);
	bool __fastcall StartIterator(void * &OwnerData);
	bool __fastcall NextIteration(void * &OwnerData);
	void __fastcall EndIterator(void * OwnerData);
	System::TObject* __fastcall GetCurrentObject(void * OwnerData);
	void __fastcall NotifyActivate(void);
	void __fastcall NotifyDeactivate(void);
	__property Classes::TComponent* Module = {read=FModule};
	
public:
	__fastcall virtual TSiteModuleHelper(Classes::TComponent* AModule);
	__fastcall virtual ~TSiteModuleHelper(void);
	void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	__property System::TObject* WebModuleContext = {read=GetWebModuleContext};
	__property Classes::TNotifyEvent OnActivate = {read=FOnActivate, write=FOnActivate};
	__property Classes::TNotifyEvent OnDeactivate = {read=FOnDeactivate, write=FOnDeactivate};
	__property Httpapp::TWebRequest* Request = {read=FRequest};
	__property Httpapp::TWebResponse* Response = {read=FResponse};
	__property Httpapp::TAbstractWebSession* Session = {read=FSession};
};


class DELPHICLASS TAdapterActionName;
class PASCALIMPLEMENTATION TAdapterActionName : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Classes::TComponent* FModule;
	Classes::TComponent* FAdapter;
	AnsiString FActionName;
	void __fastcall SetAdapter(const Classes::TComponent* Value);
	Classes::TComponent* __fastcall GetAction(void);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	__property Classes::TComponent* Action = {read=GetAction};
	
__published:
	__fastcall TAdapterActionName(Classes::TComponent* AModule);
	__property Classes::TComponent* Adapter = {read=FAdapter, write=SetAdapter};
	__property AnsiString ActionName = {read=FActionName, write=FActionName};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TAdapterActionName(void) { }
	#pragma option pop
	
};


typedef void __fastcall (*TGetParamsEvent)(System::TObject* Sender, Classes::TStrings* Params);

class DELPHICLASS TSitePageModuleHelper;
class PASCALIMPLEMENTATION TSitePageModuleHelper : public TSiteModuleHelper 
{
	typedef TSiteModuleHelper inherited;
	
private:
	TAdapterActionName* FDefaultAction;
	AnsiString FDefaultPageFileName;
	Webdisp::TDispatchPageHandledEvent FOnBeforeDispatchPage;
	Webdisp::TDispatchPageEvent FOnAfterDispatchPage;
	Webdisp::TDispatchPageEvent FOnAfterRedirectToPage;
	Webdisp::TDispatchPageParamsHandledEvent FOnBeforeRedirectToPage;
	void __fastcall SetDefaultActionName(const TAdapterActionName* Value);
	
protected:
	void __fastcall GetRedirectParams(const AnsiString APageName, Classes::TStrings* AParams);
	AnsiString __fastcall HTMLFromTemplate(Classes::TStream* AStream);
	Classes::TComponent* __fastcall GetProducerComponent(void);
	bool __fastcall HasScriptView(void);
	bool __fastcall HasXMLBrowserView(void);
	bool __fastcall HasXSLBrowserView(void);
	bool __fastcall HasHTMLBrowserView(void);
	Classes::TStream* __fastcall GetXMLData(bool &Owned);
	Classes::TStream* __fastcall GetXSLData(bool &Owned);
	AnsiString __fastcall GetTemplateFileType();
	Classes::TComponent* __fastcall GetDefaultAction(void);
	void __fastcall SetDefaultPageFileName(const AnsiString AValue);
	bool __fastcall DispatchPage(const AnsiString APageName, Httpapp::TWebResponse* AWebResponse);
	virtual bool __fastcall ImplDispatchPage(const AnsiString APageName, Httpapp::TWebResponse* AWebResponse);
	Classes::TStream* __fastcall IncludePage(const AnsiString APageName, bool &AOwned);
	virtual Classes::TStream* __fastcall ImplIncludePage(const AnsiString APageName, bool &AOwned);
	bool __fastcall RedirectToPage(const AnsiString APageName, Classes::TStrings* AParams, Httpapp::TWebResponse* AResponse);
	virtual bool __fastcall ImplRedirectToPage(const AnsiString APageName, Classes::TStrings* AParams, Httpapp::TWebResponse* AResponse);
	void __fastcall SetWebContentOptions(Webcomp::TWebContentOptions* AOptions);
	virtual void __fastcall ImplSetWebContentOptions(Webcomp::TWebContentOptions* AOptions);
	virtual Httpapp::_di_IProduceContent __fastcall GetPageProducer();
	Classes::TStream* __fastcall GetTemplateStream(const AnsiString APage, /* out */ bool &AOwned);
	
public:
	__fastcall virtual TSitePageModuleHelper(Classes::TComponent* AModule);
	__fastcall virtual ~TSitePageModuleHelper(void);
	__property Webdisp::TDispatchPageHandledEvent OnBeforeDispatchPage = {read=FOnBeforeDispatchPage, write=FOnBeforeDispatchPage};
	__property Webdisp::TDispatchPageEvent OnAfterDispatchPage = {read=FOnAfterDispatchPage, write=FOnAfterDispatchPage};
	__property Webdisp::TDispatchPageParamsHandledEvent OnBeforeRedirectToPage = {read=FOnBeforeRedirectToPage, write=FOnBeforeRedirectToPage};
	__property Webdisp::TDispatchPageEvent OnAfterRedirectToPage = {read=FOnAfterRedirectToPage, write=FOnAfterRedirectToPage};
	__property TAdapterActionName* DefaultAction = {read=FDefaultAction, write=SetDefaultActionName};
};


class DELPHICLASS TCustomWebDataModule;
class PASCALIMPLEMENTATION TCustomWebDataModule : public Classes::TDataModule 
{
	typedef Classes::TDataModule inherited;
	
private:
	TSiteModuleHelper* FSiteModuleHelper;
	Classes::TNotifyEvent __fastcall GetOnActivate();
	Classes::TNotifyEvent __fastcall GetOnDeactivate();
	Httpapp::TWebRequest* __fastcall GetRequest(void);
	Httpapp::TWebResponse* __fastcall GetResponse(void);
	Httpapp::TAbstractWebSession* __fastcall GetSession(void);
	void __fastcall SetOnActivate(const Classes::TNotifyEvent Value);
	void __fastcall SetOnDeactivate(const Classes::TNotifyEvent Value);
	
protected:
	virtual TSiteModuleHelper* __fastcall GetSiteModuleHelper(void);
	__property TSiteModuleHelper* SiteModuleHelper = {read=GetSiteModuleHelper};
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	_di_IDispatch __fastcall GetScriptObject();
	virtual _di_IDispatch __fastcall ImplGetScriptObject();
	
public:
	__fastcall virtual TCustomWebDataModule(Classes::TComponent* AOwner);
	__fastcall virtual TCustomWebDataModule(Classes::TComponent* AOwner, int Dummy);
	__fastcall virtual ~TCustomWebDataModule(void);
	__property Httpapp::TWebRequest* Request = {read=GetRequest};
	__property Httpapp::TWebResponse* Response = {read=GetResponse};
	__property Httpapp::TAbstractWebSession* Session = {read=GetSession};
	__property Classes::TNotifyEvent OnActivate = {read=GetOnActivate, write=SetOnActivate};
	__property Classes::TNotifyEvent OnDeactivate = {read=GetOnDeactivate, write=SetOnDeactivate};
private:
	void *__IWebVariablesContainer;	/* Httpprod::IWebVariablesContainer */
	void *__INotifyWebActivate;	/* Webcomp::INotifyWebActivate */
	void *__IGetScriptObject;	/* Sitecomp::IGetScriptObject */
	void *__IIterateObjectSupport;	/* Sitecomp::IIterateObjectSupport */
	
public:
	operator IIterateObjectSupport*(void) { return (IIterateObjectSupport*)&__IIterateObjectSupport; }
	operator IGetScriptObject*(void) { return (IGetScriptObject*)&__IGetScriptObject; }
	operator INotifyWebActivate*(void) { return (INotifyWebActivate*)&__INotifyWebActivate; }
	operator IWebVariablesContainer*(void) { return (IWebVariablesContainer*)&__IWebVariablesContainer; }
	
};


class DELPHICLASS TWebDataModule;
class PASCALIMPLEMENTATION TWebDataModule : public TCustomWebDataModule 
{
	typedef TCustomWebDataModule inherited;
	
__published:
	__property OnActivate ;
	__property OnDeactivate ;
public:
	#pragma option push -w-inl
	/* TCustomWebDataModule.Create */ inline __fastcall virtual TWebDataModule(Classes::TComponent* AOwner) : TCustomWebDataModule(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomWebDataModule.CreateNew */ inline __fastcall virtual TWebDataModule(Classes::TComponent* AOwner, int Dummy) : TCustomWebDataModule(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomWebDataModule.Destroy */ inline __fastcall virtual ~TWebDataModule(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWebPageModuleHelper;
class PASCALIMPLEMENTATION TWebPageModuleHelper : public TSitePageModuleHelper 
{
	typedef TSitePageModuleHelper inherited;
	
protected:
	virtual Httpapp::_di_IProduceContent __fastcall GetPageProducer();
public:
	#pragma option push -w-inl
	/* TSitePageModuleHelper.Create */ inline __fastcall virtual TWebPageModuleHelper(Classes::TComponent* AModule) : TSitePageModuleHelper(AModule) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TSitePageModuleHelper.Destroy */ inline __fastcall virtual ~TWebPageModuleHelper(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomWebPageModule;
class PASCALIMPLEMENTATION TCustomWebPageModule : public TCustomWebDataModule 
{
	typedef TCustomWebDataModule inherited;
	
private:
	Httpapp::_di_IProduceContent FPageProducer;
	TSitePageModuleHelper* FSitePageModuleHelper;
	void __fastcall SetPageProducer(Httpapp::_di_IProduceContent Value);
	Webdisp::TDispatchPageEvent __fastcall GetOnAfterDispatchPage();
	Webdisp::TDispatchPageHandledEvent __fastcall GetOnBeforeDispatchPage();
	void __fastcall SetOnAfterDispatchPage(const Webdisp::TDispatchPageEvent Value);
	void __fastcall SetOnBeforeDispatchPage(const Webdisp::TDispatchPageHandledEvent Value);
	Webdisp::TDispatchPageEvent __fastcall GetOnAfterRedirectToPage();
	Webdisp::TDispatchPageParamsHandledEvent __fastcall GetOnBeforeRedirectToPage();
	void __fastcall SetOnAfterRedirectToPage(const Webdisp::TDispatchPageEvent Value);
	void __fastcall SetOnBeforeRedirectToPage(const Webdisp::TDispatchPageParamsHandledEvent Value);
	TAdapterActionName* __fastcall GetDefaultActionName(void);
	void __fastcall SetDefaultActionName(TAdapterActionName* Value);
	
protected:
	virtual TSiteModuleHelper* __fastcall GetSiteModuleHelper(void);
	virtual TSitePageModuleHelper* __fastcall GetSitePageModuleHelper(void);
	__property TSitePageModuleHelper* SitePageModuleHelper = {read=GetSitePageModuleHelper};
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__fastcall virtual TCustomWebPageModule(Classes::TComponent* AOwner);
	__fastcall virtual TCustomWebPageModule(Classes::TComponent* AOwner, int Dummy);
	__fastcall virtual ~TCustomWebPageModule(void);
	__property Httpapp::_di_IProduceContent PageProducer = {read=FPageProducer, write=SetPageProducer};
	__property Webdisp::TDispatchPageHandledEvent OnBeforeDispatchPage = {read=GetOnBeforeDispatchPage, write=SetOnBeforeDispatchPage};
	__property Webdisp::TDispatchPageEvent OnAfterDispatchPage = {read=GetOnAfterDispatchPage, write=SetOnAfterDispatchPage};
	__property Webdisp::TDispatchPageParamsHandledEvent OnBeforeRedirectToPage = {read=GetOnBeforeRedirectToPage, write=SetOnBeforeRedirectToPage};
	__property Webdisp::TDispatchPageEvent OnAfterRedirectToPage = {read=GetOnAfterRedirectToPage, write=SetOnAfterRedirectToPage};
	__property TAdapterActionName* DefaultAction = {read=GetDefaultActionName, write=SetDefaultActionName};
private:
	void *__IDefaultPageFileName;	/* Sitecomp::IDefaultPageFileName */
	void *__IPageResult;	/* Sitecomp::IPageResult */
	void *__ISetWebContentOptions;	/* Webcomp::ISetWebContentOptions */
	void *__IGetDefaultAction;	/* Sitecomp::IGetDefaultAction */
	void *__IGetProducerComponent;	/* Sitecomp::IGetProducerComponent */
	void *__IProducerEditorViewSupport;	/* Webcomp::IProducerEditorViewSupport */
	
public:
	operator IProducerEditorViewSupport*(void) { return (IProducerEditorViewSupport*)&__IProducerEditorViewSupport; }
	operator IGetProducerComponent*(void) { return (IGetProducerComponent*)&__IGetProducerComponent; }
	operator IGetDefaultAction*(void) { return (IGetDefaultAction*)&__IGetDefaultAction; }
	operator ISetWebContentOptions*(void) { return (ISetWebContentOptions*)&__ISetWebContentOptions; }
	operator IPageResult*(void) { return (IPageResult*)&__IPageResult; }
	operator IDefaultPageFileName*(void) { return (IDefaultPageFileName*)&__IDefaultPageFileName; }
	
};


class DELPHICLASS TWebPageModule;
class PASCALIMPLEMENTATION TWebPageModule : public TCustomWebPageModule 
{
	typedef TCustomWebPageModule inherited;
	
__published:
	__property OnActivate ;
	__property OnDeactivate ;
	__property PageProducer ;
	__property OnBeforeDispatchPage ;
	__property OnAfterDispatchPage ;
	__property DefaultAction ;
public:
	#pragma option push -w-inl
	/* TCustomWebPageModule.Create */ inline __fastcall virtual TWebPageModule(Classes::TComponent* AOwner) : TCustomWebPageModule(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomWebPageModule.CreateNew */ inline __fastcall virtual TWebPageModule(Classes::TComponent* AOwner, int Dummy) : TCustomWebPageModule(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomWebPageModule.Destroy */ inline __fastcall virtual ~TWebPageModule(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomWebAppDataModule;
class PASCALIMPLEMENTATION TCustomWebAppDataModule : public TCustomWebDataModule 
{
	typedef TCustomWebDataModule inherited;
	
private:
	Httpapp::_di_IWebAppServices FAppServices;
	void __fastcall SetAppServices(const Httpapp::_di_IWebAppServices Value);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	Httpapp::_di_IWebAppServices __fastcall GetWebAppServices();
	
public:
	__fastcall virtual TCustomWebAppDataModule(Classes::TComponent* AOwner);
	__fastcall virtual TCustomWebAppDataModule(Classes::TComponent* AOwner, int Dummy);
	__fastcall virtual ~TCustomWebAppDataModule(void);
	__property Httpapp::_di_IWebAppServices AppServices = {read=FAppServices, write=SetAppServices};
private:
	void *__IGetWebAppServices;	/* Httpapp::IGetWebAppServices */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IGetWebAppServices; }
	operator IGetWebAppServices*(void) { return (IGetWebAppServices*)&__IGetWebAppServices; }
	
};


class DELPHICLASS TWebAppDataModule;
class PASCALIMPLEMENTATION TWebAppDataModule : public TCustomWebAppDataModule 
{
	typedef TCustomWebAppDataModule inherited;
	
__published:
	__property OnActivate ;
	__property OnDeactivate ;
	__property AppServices ;
public:
	#pragma option push -w-inl
	/* TCustomWebAppDataModule.Create */ inline __fastcall virtual TWebAppDataModule(Classes::TComponent* AOwner) : TCustomWebAppDataModule(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomWebAppDataModule.CreateNew */ inline __fastcall virtual TWebAppDataModule(Classes::TComponent* AOwner, int Dummy) : TCustomWebAppDataModule(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomWebAppDataModule.Destroy */ inline __fastcall virtual ~TWebAppDataModule(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomWebAppPageModule;
class PASCALIMPLEMENTATION TCustomWebAppPageModule : public TCustomWebPageModule 
{
	typedef TCustomWebPageModule inherited;
	
private:
	Httpapp::_di_IWebAppServices FAppServices;
	
protected:
	void __fastcall SetAppServices(const Httpapp::_di_IWebAppServices Value);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	Httpapp::_di_IWebAppServices __fastcall GetWebAppServices();
	
public:
	__fastcall virtual TCustomWebAppPageModule(Classes::TComponent* AOwner);
	__fastcall virtual TCustomWebAppPageModule(Classes::TComponent* AOwner, int Dummy);
	__fastcall virtual ~TCustomWebAppPageModule(void);
	__property Httpapp::_di_IWebAppServices AppServices = {read=FAppServices, write=SetAppServices};
private:
	void *__IGetWebAppServices;	/* Httpapp::IGetWebAppServices */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IGetWebAppServices; }
	operator IGetWebAppServices*(void) { return (IGetWebAppServices*)&__IGetWebAppServices; }
	
};


class DELPHICLASS TWebAppPageModule;
class PASCALIMPLEMENTATION TWebAppPageModule : public TCustomWebAppPageModule 
{
	typedef TCustomWebAppPageModule inherited;
	
__published:
	__property OnBeforeDispatchPage ;
	__property OnAfterDispatchPage ;
	__property OnActivate ;
	__property OnDeactivate ;
	__property PageProducer ;
	__property AppServices ;
	__property DefaultAction ;
public:
	#pragma option push -w-inl
	/* TCustomWebAppPageModule.Create */ inline __fastcall virtual TWebAppPageModule(Classes::TComponent* AOwner) : TCustomWebAppPageModule(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomWebAppPageModule.CreateNew */ inline __fastcall virtual TWebAppPageModule(Classes::TComponent* AOwner, int Dummy) : TCustomWebAppPageModule(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomWebAppPageModule.Destroy */ inline __fastcall virtual ~TWebAppPageModule(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWebAppPageModuleHelper;
class PASCALIMPLEMENTATION TWebAppPageModuleHelper : public TSitePageModuleHelper 
{
	typedef TSitePageModuleHelper inherited;
	
protected:
	virtual Httpapp::_di_IProduceContent __fastcall GetPageProducer();
public:
	#pragma option push -w-inl
	/* TSitePageModuleHelper.Create */ inline __fastcall virtual TWebAppPageModuleHelper(Classes::TComponent* AModule) : TSitePageModuleHelper(AModule) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TSitePageModuleHelper.Destroy */ inline __fastcall virtual ~TWebAppPageModuleHelper(void) { }
	#pragma option pop
	
};


class DELPHICLASS EWebModuleException;
class PASCALIMPLEMENTATION EWebModuleException : public Httpapp::EWebBrokerException 
{
	typedef Httpapp::EWebBrokerException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EWebModuleException(const AnsiString Msg) : Httpapp::EWebBrokerException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EWebModuleException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Httpapp::EWebBrokerException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EWebModuleException(int Ident)/* overload */ : Httpapp::EWebBrokerException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EWebModuleException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Httpapp::EWebBrokerException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EWebModuleException(const AnsiString Msg, int AHelpContext) : Httpapp::EWebBrokerException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EWebModuleException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Httpapp::EWebBrokerException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EWebModuleException(int Ident, int AHelpContext)/* overload */ : Httpapp::EWebBrokerException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EWebModuleException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Httpapp::EWebBrokerException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EWebModuleException(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Classes::TComponent* __fastcall FindNamedModuleVariable(Classes::TComponent* AModule, const AnsiString AName);
extern PACKAGE Classes::TComponent* __fastcall GetModuleVariable(Classes::TComponent* AModule, int Index);
extern PACKAGE int __fastcall GetModuleVariableCount(Classes::TComponent* AModule);

}	/* namespace Webmodu */
using namespace Webmodu;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WebModu
