// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WebDisp.pas' rev: 6.00

#ifndef WebDispHPP
#define WebDispHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SiteComp.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <WebComp.hpp>	// Pascal unit
#include <Masks.hpp>	// Pascal unit
#include <WebCntxt.hpp>	// Pascal unit
#include <HTTPProd.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Webdisp
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TActivateWebModuleEvent)(System::TObject* Sender, Classes::TComponent* WebModule);

typedef void __fastcall (__closure *TDispatchPageHandledEvent)(System::TObject* Sender, const AnsiString PageName, bool &Handled);

typedef void __fastcall (__closure *TDispatchPageParamsHandledEvent)(System::TObject* Sender, const AnsiString PageName, Classes::TStrings* Params, bool &Handled);

typedef void __fastcall (__closure *TDispatchPageEvent)(System::TObject* Sender, const AnsiString PageName);

class DELPHICLASS TMultiModuleWebAppServices;
class PASCALIMPLEMENTATION TMultiModuleWebAppServices : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Webcntxt::TAbstractWebContext* FWebContext;
	Httpapp::TWebRequest* FRequest;
	Httpapp::TWebResponse* FResponse;
	Httpapp::TAbstractWebModuleList* FWebModules;
	Httpapp::THTTPMethodEvent FOnBeforeDispatch;
	Httpapp::THTTPMethodEvent FOnAfterDispatch;
	
protected:
	bool __fastcall DoAfterDispatch(Httpapp::TWebRequest* Request, Httpapp::TWebResponse* Response);
	bool __fastcall DoBeforeDispatch(Httpapp::TWebRequest* Request, Httpapp::TWebResponse* Response);
	void __fastcall ModuleAdded(Classes::TComponent* AWebModule);
	virtual void __fastcall InitModules(void);
	virtual void __fastcall InitModule(Classes::TComponent* AWebModule);
	virtual void __fastcall DoneModule(Classes::TComponent* AWebModule);
	virtual Webcntxt::TAbstractWebContext* __fastcall CreateContext(void);
	void __fastcall HandleException(Sysutils::Exception* E, bool &Handled);
	virtual void __fastcall ImplHandleException(Sysutils::Exception* E, bool &Handled);
	Httpapp::TWebRequest* __fastcall Access_Request(void);
	Httpapp::TWebResponse* __fastcall Access_Response(void);
	void __fastcall InitContext(Httpapp::TAbstractWebModuleList* WebModuleList, Httpapp::TWebRequest* Request, Httpapp::TWebResponse* Response);
	bool __fastcall HandleRequest(void);
	void __fastcall FinishContext(void);
	System::TObject* __fastcall GetExceptionHandler(void);
	virtual void __fastcall ImplInitContext(Httpapp::TAbstractWebModuleList* AWebModuleList, Httpapp::TWebRequest* ARequest, Httpapp::TWebResponse* AResponse);
	virtual bool __fastcall ImplHandleRequest(void);
	virtual void __fastcall ImplFinishContext(void);
	__property Httpapp::TWebRequest* Request = {read=FRequest};
	__property Httpapp::TWebResponse* Response = {read=FResponse};
	__property Httpapp::TAbstractWebModuleList* WebModules = {read=FWebModules};
	__property Httpapp::THTTPMethodEvent OnBeforeDispatch = {read=FOnBeforeDispatch, write=FOnBeforeDispatch};
	__property Httpapp::THTTPMethodEvent OnAfterDispatch = {read=FOnAfterDispatch, write=FOnAfterDispatch};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TMultiModuleWebAppServices(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TMultiModuleWebAppServices(void) { }
	#pragma option pop
	
private:
	void *__IWebAppServices;	/* Httpapp::IWebAppServices */
	void *__IWebDispatcherAccess;	/* Httpapp::IWebDispatcherAccess [Response=Access_Response, Request=Access_Request] */
	void *__IWebExceptionHandler;	/* Httpapp::IWebExceptionHandler */
	
public:
	operator IWebExceptionHandler*(void) { return (IWebExceptionHandler*)&__IWebExceptionHandler; }
	operator IWebDispatcherAccess*(void) { return (IWebDispatcherAccess*)&__IWebDispatcherAccess; }
	operator IWebAppServices*(void) { return (IWebAppServices*)&__IWebAppServices; }
	
};


class DELPHICLASS TCustomWebAppComponents;
class PASCALIMPLEMENTATION TCustomWebAppComponents : public TMultiModuleWebAppServices 
{
	typedef TMultiModuleWebAppServices inherited;
	
private:
	Httpapp::_di_IWebDispatchActions FDispatchActions;
	Httpapp::TAbstractWebSession* FSession;
	Sitecomp::_di_ISessionsService FSessions;
	Httpprod::_di_ILocateFileService FLocateFileService;
	Sitecomp::_di_IPageDispatcher FPageDispatcher;
	Sitecomp::_di_IAdapterDispatcher FAdapterDispatcher;
	Sitecomp::_di_IWebApplicationInfo FApplicationAdapter;
	Webcntxt::_di_IWebEndUser FEndUserAdapter;
	Sitecomp::_di_IWebUserList FUserListService;
	Httpapp::TWebExceptionEvent FOnException;
	void __fastcall SetLocateFileService(const Httpprod::_di_ILocateFileService Value);
	void __fastcall SetDispatcher(const Httpapp::_di_IWebDispatchActions Value);
	void __fastcall CheckSessionsStatus(bool ANotify = true);
	void __fastcall SetSessions(const Sitecomp::_di_ISessionsService Value);
	void __fastcall SetAdapterDispatcher(const Sitecomp::_di_IAdapterDispatcher Value);
	void __fastcall SetPageDispatcher(const Sitecomp::_di_IPageDispatcher Value);
	void __fastcall SetApplicationAdapter(const Sitecomp::_di_IWebApplicationInfo Value);
	void __fastcall SetEndUserAdapter(const Webcntxt::_di_IWebEndUser Value);
	void __fastcall SetUserListService(const Sitecomp::_di_IWebUserList Value);
	AnsiString __fastcall ExceptionAsContent(Sysutils::Exception* E);
	
protected:
	virtual void __fastcall ListRequestHandlers(Classes::_di_IInterfaceList L);
	Httpprod::_di_ILocateFileService __fastcall GetLocateFileService();
	Sitecomp::_di_IPageDispatcher __fastcall GetPageDispatcher();
	Sitecomp::_di_IAdapterDispatcher __fastcall GetAdapterDispatcher();
	Sitecomp::_di_IWebApplicationInfo __fastcall GetWebApplicationInfo();
	Webcntxt::_di_IWebEndUser __fastcall GetWebEndUser();
	Sitecomp::_di_IWebUserList __fastcall GetWebUserList();
	virtual bool __fastcall ImplHandleRequest(void);
	virtual void __fastcall ImplHandleException(Sysutils::Exception* E, bool &Handled);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall ImplInitContext(Httpapp::TAbstractWebModuleList* AWebModuleList, Httpapp::TWebRequest* ARequest, Httpapp::TWebResponse* AResponse);
	virtual void __fastcall ImplFinishContext(void);
	virtual void __fastcall InitModules(void);
	virtual void __fastcall InitModule(Classes::TComponent* AModule);
	virtual Webcntxt::TAbstractWebContext* __fastcall CreateContext(void);
	
public:
	__property Httpapp::_di_IWebDispatchActions DispatchActions = {read=FDispatchActions, write=SetDispatcher};
	__property Sitecomp::_di_ISessionsService Sessions = {read=FSessions, write=SetSessions};
	__property Httpprod::_di_ILocateFileService LocateFileService = {read=FLocateFileService, write=SetLocateFileService};
	__property Sitecomp::_di_IPageDispatcher PageDispatcher = {read=FPageDispatcher, write=SetPageDispatcher};
	__property Sitecomp::_di_IAdapterDispatcher AdapterDispatcher = {read=FAdapterDispatcher, write=SetAdapterDispatcher};
	__property Sitecomp::_di_IWebApplicationInfo ApplicationAdapter = {read=FApplicationAdapter, write=SetApplicationAdapter};
	__property Webcntxt::_di_IWebEndUser EndUserAdapter = {read=FEndUserAdapter, write=SetEndUserAdapter};
	__property Sitecomp::_di_IWebUserList UserListService = {read=FUserListService, write=SetUserListService};
	__property Httpapp::TWebExceptionEvent OnException = {read=FOnException, write=FOnException};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TCustomWebAppComponents(Classes::TComponent* AOwner) : TMultiModuleWebAppServices(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCustomWebAppComponents(void) { }
	#pragma option pop
	
private:
	void *__IGetWebAppComponents;	/* Sitecomp::IGetWebAppComponents */
	void *__IGetLocateFileService;	/* Httpprod::IGetLocateFileService */
	
public:
	operator IGetLocateFileService*(void) { return (IGetLocateFileService*)&__IGetLocateFileService; }
	operator IGetWebAppComponents*(void) { return (IGetWebAppComponents*)&__IGetWebAppComponents; }
	
};


class DELPHICLASS TWebAppComponents;
class PASCALIMPLEMENTATION TWebAppComponents : public TCustomWebAppComponents 
{
	typedef TCustomWebAppComponents inherited;
	
__published:
	__property DispatchActions ;
	__property Sessions ;
	__property LocateFileService ;
	__property PageDispatcher ;
	__property AdapterDispatcher ;
	__property ApplicationAdapter ;
	__property EndUserAdapter ;
	__property UserListService ;
	__property OnBeforeDispatch ;
	__property OnAfterDispatch ;
	__property OnException ;
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TWebAppComponents(Classes::TComponent* AOwner) : TCustomWebAppComponents(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TWebAppComponents(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TLocateFileServiceFindFileEvent)(System::TObject* ASender, Classes::TComponent* AComponent, const AnsiString AFileName, AnsiString &AFoundFile, bool &AHandled);

typedef void __fastcall (__closure *TLocateFileServiceFindStreamEvent)(System::TObject* ASender, Classes::TComponent* AComponent, const AnsiString AFileName, Classes::TStream* &AFoundStream, bool &AOwned, bool &AHandled);

class DELPHICLASS TCustomLocateFileService;
class PASCALIMPLEMENTATION TCustomLocateFileService : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TLocateFileServiceFindFileEvent FOnFindTemplateFile;
	TLocateFileServiceFindFileEvent FOnFindIncludeFile;
	TLocateFileServiceFindStreamEvent FOnFindStream;
	
protected:
	bool __fastcall FindIncludeFile(Classes::TComponent* AComponent, const AnsiString AFileName, AnsiString &AResult);
	virtual bool __fastcall ImplFindIncludeFile(Classes::TComponent* AComponent, const AnsiString AFileName, AnsiString &AResult);
	Classes::TStream* __fastcall GetTemplateStream(Classes::TComponent* AComponent, AnsiString AFileName, /* out */ bool &AOwned);
	virtual Classes::TStream* __fastcall ImplGetTemplateStream(Classes::TComponent* AComponent, AnsiString AFileName, /* out */ bool &AOwned);
	bool __fastcall FindTemplateFile(Classes::TComponent* AComponent, const AnsiString AFileName, AnsiString &AResult);
	virtual bool __fastcall FindStream(Classes::TComponent* AComponent, const AnsiString AFileName, /* out */ Classes::TStream* &AResult, /* out */ bool &AOwned);
	virtual Classes::TStream* __fastcall GetFileStream(const AnsiString AFileName, /* out */ bool &AOwned);
	__property TLocateFileServiceFindFileEvent OnFindIncludeFile = {read=FOnFindIncludeFile, write=FOnFindIncludeFile};
	__property TLocateFileServiceFindFileEvent OnFindTemplateFile = {read=FOnFindTemplateFile, write=FOnFindTemplateFile};
	__property TLocateFileServiceFindStreamEvent OnFindStream = {read=FOnFindStream, write=FOnFindStream};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TCustomLocateFileService(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCustomLocateFileService(void) { }
	#pragma option pop
	
private:
	void *__ILocateFileService;	/* Httpprod::ILocateFileService */
	void *__IFindIncludeFile;	/* Sitecomp::IFindIncludeFile */
	
public:
	operator IFindIncludeFile*(void) { return (IFindIncludeFile*)&__IFindIncludeFile; }
	operator ILocateFileService*(void) { return (ILocateFileService*)&__ILocateFileService; }
	
};


class DELPHICLASS TLocateFileService;
class PASCALIMPLEMENTATION TLocateFileService : public TCustomLocateFileService 
{
	typedef TCustomLocateFileService inherited;
	
__published:
	__property OnFindTemplateFile ;
	__property OnFindIncludeFile ;
	__property OnFindStream ;
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TLocateFileService(Classes::TComponent* AOwner) : TCustomLocateFileService(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TLocateFileService(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBaseRequestHandler;
class PASCALIMPLEMENTATION TBaseRequestHandler : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Classes::TComponent* FAppDispatcher;
	
protected:
	void __fastcall SetAppDispatcher(const Classes::TComponent* AWebAppDispatcher);
	bool __fastcall HandleRequest(Httpapp::TWebRequest* ARequest, Httpapp::TWebResponse* AResponse);
	virtual bool __fastcall ImplHandleRequest(Httpapp::TWebRequest* ARequest, Httpapp::TWebResponse* AResponse);
	__property Classes::TComponent* AppDispatcher = {read=FAppDispatcher};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TBaseRequestHandler(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TBaseRequestHandler(void) { }
	#pragma option pop
	
private:
	void *__IWebRequestHandler;	/* Httpapp::IWebRequestHandler */
	void *__ISetAppDispatcher;	/* Httpapp::ISetAppDispatcher */
	
public:
	operator ISetAppDispatcher*(void) { return (ISetAppDispatcher*)&__ISetAppDispatcher; }
	operator IWebRequestHandler*(void) { return (IWebRequestHandler*)&__IWebRequestHandler; }
	
};


class DELPHICLASS TAdapterDispatchParams;
class PASCALIMPLEMENTATION TAdapterDispatchParams : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	AnsiString FObjectIdentifier;
	AnsiString FRequestIdentifier;
	AnsiString FSuccessPage;
	AnsiString FFailurePage;
	Classes::TStrings* FParams;
	System::TObject* FHandler;
	
protected:
	AnsiString __fastcall GetRequestIdentifier();
	AnsiString __fastcall GetObjectIdentifier();
	Classes::TStrings* __fastcall GetParams(void);
	System::TObject* __fastcall GetHandler(void);
	AnsiString __fastcall GetSuccessPage();
	AnsiString __fastcall GetFailurePage();
	
public:
	__fastcall TAdapterDispatchParams(Httpapp::TWebRequest* ARequest);
	__fastcall virtual ~TAdapterDispatchParams(void);
	__property AnsiString RequestIdentifier = {read=GetRequestIdentifier};
	__property AnsiString ObjectIdentifier = {read=GetObjectIdentifier};
	__property System::TObject* Handler = {read=GetHandler};
private:
	void *__IAdapterDispatchParams;	/* Sitecomp::IAdapterDispatchParams */
	void *__IGetAdapterRequestDefaultResponse;	/* Sitecomp::IGetAdapterRequestDefaultResponse */
	
public:
	operator IGetAdapterRequestDefaultResponse*(void) { return (IGetAdapterRequestDefaultResponse*)&__IGetAdapterRequestDefaultResponse; }
	operator IAdapterDispatchParams*(void) { return (IAdapterDispatchParams*)&__IAdapterDispatchParams; }
	
};


typedef void __fastcall (__closure *TGetAdapterRequestParamsEvent)(System::TObject* Sender, System::_di_IInterface Handler, AnsiString &Identifer, Classes::TStrings* Params);

typedef void __fastcall (__closure *TDispatchActionEvent)(System::TObject* Sender, System::TObject* Action, Classes::TStrings* Params);

typedef void __fastcall (__closure *TDispatchActionHandledEvent)(System::TObject* Sender, System::TObject* Action, Classes::TStrings* Params, bool &Handled);

typedef void __fastcall (__closure *TDispatchImageEvent)(System::TObject* Sender, System::TObject* Image, Classes::TStrings* Params);

typedef void __fastcall (__closure *TDispatchImageHandledEvent)(System::TObject* Sender, System::TObject* Image, Classes::TStrings* Params, bool &Handled);

class DELPHICLASS TCustomAdapterDispatcher;
class PASCALIMPLEMENTATION TCustomAdapterDispatcher : public TBaseRequestHandler 
{
	typedef TBaseRequestHandler inherited;
	
private:
	TGetAdapterRequestParamsEvent FOnGetAdapterRequestParams;
	TDispatchActionEvent FOnAfterDispatchAction;
	TDispatchActionHandledEvent FOnBeforeDispatchAction;
	TDispatchImageEvent FOnAfterDispatchImage;
	TDispatchImageHandledEvent FOnBeforeDispatchImage;
	TDispatchActionHandledEvent FOnActionRequestNotHandled;
	TDispatchImageHandledEvent FOnImageRequestNotHandled;
	bool __fastcall GetActionRequestParams(Classes::TStrings* &AStrings);
	bool __fastcall GetImageRequestParams(Classes::TStrings* &AStrings);
	
protected:
	void __fastcall DoAdapterRequestNotHandled(System::TObject* AObject, bool &AHandled);
	void __fastcall DoAfterDispatchAdapterRequest(System::TObject* AObject);
	void __fastcall DoBeforeDispatchAdapterRequest(System::TObject* AObject, bool &AHandled);
	virtual void __fastcall AddSpecialParams(System::_di_IInterface AHandler, Sitecomp::_di_IAdapterItemRequestParams Params);
	virtual TAdapterDispatchParams* __fastcall GetDispatchParams(Httpapp::TWebRequest* Request);
	AnsiString __fastcall EncodeAdapterItemRequestAsHREF(System::_di_IInterface AHandler, Sitecomp::TAdapterItemRequestParamOptions AOptions);
	virtual AnsiString __fastcall ImplEncodeAdapterItemRequestAsHREF(System::_di_IInterface AHandler, Sitecomp::TAdapterItemRequestParamOptions AOptions);
	AnsiString __fastcall EncodeAdapterItemRequestAsFieldValue(System::_di_IInterface AHandler, Sitecomp::TAdapterItemRequestParamOptions AOptions);
	virtual AnsiString __fastcall ImplEncodeAdapterItemRequestAsFieldValue(System::_di_IInterface AHandler, Sitecomp::TAdapterItemRequestParamOptions AOptions);
	void __fastcall GetAdapterItemRequestParams(System::_di_IInterface AHandler, Sitecomp::TAdapterItemRequestParamOptions AOptions, Sitecomp::_di_IAdapterItemRequestParams Params);
	virtual void __fastcall ImplGetAdapterItemRequestParams(System::_di_IInterface AHandler, Sitecomp::TAdapterItemRequestParamOptions AOptions, Sitecomp::_di_IAdapterItemRequestParams Params);
	virtual bool __fastcall ImplHandleRequest(Httpapp::TWebRequest* Request, Httpapp::TWebResponse* Response);
	
public:
	__property TGetAdapterRequestParamsEvent OnGetAdapterRequestParams = {read=FOnGetAdapterRequestParams, write=FOnGetAdapterRequestParams};
	__property TDispatchActionHandledEvent OnBeforeDispatchAction = {read=FOnBeforeDispatchAction, write=FOnBeforeDispatchAction};
	__property TDispatchActionEvent OnAfterDispatchAction = {read=FOnAfterDispatchAction, write=FOnAfterDispatchAction};
	__property TDispatchImageHandledEvent OnBeforeDispatchImage = {read=FOnBeforeDispatchImage, write=FOnBeforeDispatchImage};
	__property TDispatchImageEvent OnAfterDispatchImage = {read=FOnAfterDispatchImage, write=FOnAfterDispatchImage};
	__property TDispatchActionHandledEvent OnActionRequestNotHandled = {read=FOnActionRequestNotHandled, write=FOnActionRequestNotHandled};
	__property TDispatchImageHandledEvent OnImageRequestNotHandled = {read=FOnImageRequestNotHandled, write=FOnImageRequestNotHandled};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TCustomAdapterDispatcher(Classes::TComponent* AOwner) : TBaseRequestHandler(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCustomAdapterDispatcher(void) { }
	#pragma option pop
	
private:
	void *__IAdapterDispatcher;	/* Sitecomp::IAdapterDispatcher */
	
public:
	operator IAdapterDispatcher*(void) { return (IAdapterDispatcher*)&__IAdapterDispatcher; }
	
};


class DELPHICLASS TAdapterDispatcher;
class PASCALIMPLEMENTATION TAdapterDispatcher : public TCustomAdapterDispatcher 
{
	typedef TCustomAdapterDispatcher inherited;
	
__published:
	__property OnGetAdapterRequestParams ;
	__property OnBeforeDispatchAction ;
	__property OnBeforeDispatchImage ;
	__property OnAfterDispatchAction ;
	__property OnAfterDispatchImage ;
	__property OnActionRequestNotHandled ;
	__property OnImageRequestNotHandled ;
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TAdapterDispatcher(Classes::TComponent* AOwner) : TCustomAdapterDispatcher(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TAdapterDispatcher(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TPageAccessDenied { adLoginRequired, adCantView };
#pragma option pop

typedef void __fastcall (__closure *TLoginRequiredEvent)(System::TObject* Sender, const AnsiString PageName, bool &Required);

typedef void __fastcall (__closure *TLoginPagedHandledEvent)(System::TObject* Sender, const AnsiString PageName, bool &Handled);

typedef void __fastcall (__closure *TCanViewPageEvent)(System::TObject* Sender, const AnsiString PageName, bool &CanView, bool &AHandled);

typedef void __fastcall (__closure *TPageAccessDeniedEvent)(System::TObject* Sender, const AnsiString PageName, TPageAccessDenied Reason, bool &Handled);

class DELPHICLASS TCustomPageDispatcher;
class PASCALIMPLEMENTATION TCustomPageDispatcher : public TBaseRequestHandler 
{
	typedef TBaseRequestHandler inherited;
	
private:
	TLoginRequiredEvent FOnIsLoginRequired;
	Webcntxt::_di_IWebEndUser FEndUserAdapter;
	AnsiString FDefaultPage;
	TDispatchPageEvent FOnAfterDispatchPage;
	TDispatchPageHandledEvent FOnBeforeDispatchPage;
	TDispatchPageHandledEvent FOnPageNotFound;
	TDispatchPageEvent FOnAfterRedirectToPage;
	TDispatchPageParamsHandledEvent FOnBeforeRedirectToPage;
	TCanViewPageEvent FOnCanViewPage;
	TPageAccessDeniedEvent FOnPageAccessDenied;
	
protected:
	Webcntxt::_di_IWebEndUser __fastcall EndUser();
	bool __fastcall ProduceLoginPage(void);
	bool __fastcall IsLoggedIn(void);
	bool __fastcall ValidatePage(const AnsiString APage, bool &AHandled);
	System::TObject* __fastcall GetRequestedPage(const AnsiString APageName, Sitecomp::TDispatchPageFlags AFlags);
	AnsiString __fastcall PageNameOfRequest(Httpapp::TWebRequest* Request);
	virtual AnsiString __fastcall ImplPageNameOfRequest(Httpapp::TWebRequest* Request);
	bool __fastcall DispatchPageName(const AnsiString APageName, Httpapp::TWebResponse* AResponse, Sitecomp::TDispatchPageFlags AFlags);
	bool __fastcall ImplDispatchPageName(const AnsiString APageName, Httpapp::TWebResponse* AResponse, Sitecomp::TDispatchPageFlags AFlags);
	bool __fastcall RedirectToPageName(const AnsiString APageName, Classes::TStrings* AParams, Httpapp::TWebResponse* AResponse, Sitecomp::TDispatchPageFlags AFlags);
	bool __fastcall ImplRedirectToPageName(const AnsiString APageName, Classes::TStrings* AParams, Httpapp::TWebResponse* AResponse, Sitecomp::TDispatchPageFlags AFlags);
	AnsiString __fastcall GetDefaultPageName();
	virtual AnsiString __fastcall ImplGetDefaultPageName();
	bool __fastcall GetLoginRequired(const AnsiString APageName);
	bool __fastcall GetCanView(const AnsiString APageName);
	virtual bool __fastcall ImplGetLoginRequired(const AnsiString APageName);
	virtual bool __fastcall ImplGetCanView(const AnsiString APageName);
	virtual bool __fastcall ImplHandleRequest(Httpapp::TWebRequest* Request, Httpapp::TWebResponse* Response);
	
public:
	__property TLoginRequiredEvent OnIsLoginRequired = {read=FOnIsLoginRequired, write=FOnIsLoginRequired};
	__property AnsiString DefaultPage = {read=FDefaultPage, write=FDefaultPage};
	__property TDispatchPageHandledEvent OnBeforeDispatchPage = {read=FOnBeforeDispatchPage, write=FOnBeforeDispatchPage};
	__property TDispatchPageEvent OnAfterDispatchPage = {read=FOnAfterDispatchPage, write=FOnAfterDispatchPage};
	__property TDispatchPageParamsHandledEvent OnBeforeRedirectToPage = {read=FOnBeforeRedirectToPage, write=FOnBeforeRedirectToPage};
	__property TDispatchPageEvent OnAfterRedirectToPage = {read=FOnAfterRedirectToPage, write=FOnAfterRedirectToPage};
	__property TDispatchPageHandledEvent OnPageNotFound = {read=FOnPageNotFound, write=FOnPageNotFound};
	__property TCanViewPageEvent OnCanViewPage = {read=FOnCanViewPage, write=FOnCanViewPage};
	__property TPageAccessDeniedEvent OnPageAccessDenied = {read=FOnPageAccessDenied, write=FOnPageAccessDenied};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TCustomPageDispatcher(Classes::TComponent* AOwner) : TBaseRequestHandler(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCustomPageDispatcher(void) { }
	#pragma option pop
	
private:
	void *__IPageDispatcher;	/* Sitecomp::IPageDispatcher */
	
public:
	operator IPageDispatcher*(void) { return (IPageDispatcher*)&__IPageDispatcher; }
	
};


class DELPHICLASS TPageDispatcher;
class PASCALIMPLEMENTATION TPageDispatcher : public TCustomPageDispatcher 
{
	typedef TCustomPageDispatcher inherited;
	
__published:
	__property OnIsLoginRequired ;
	__property DefaultPage ;
	__property OnBeforeDispatchPage ;
	__property OnAfterDispatchPage ;
	__property OnPageNotFound ;
	__property OnCanViewPage ;
	__property OnPageAccessDenied ;
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TPageDispatcher(Classes::TComponent* AOwner) : TCustomPageDispatcher(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TPageDispatcher(void) { }
	#pragma option pop
	
};


class DELPHICLASS EPageDispatcherException;
class PASCALIMPLEMENTATION EPageDispatcherException : public Httpapp::EWebBrokerException 
{
	typedef Httpapp::EWebBrokerException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EPageDispatcherException(const AnsiString Msg) : Httpapp::EWebBrokerException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EPageDispatcherException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Httpapp::EWebBrokerException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EPageDispatcherException(int Ident)/* overload */ : Httpapp::EWebBrokerException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EPageDispatcherException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Httpapp::EWebBrokerException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EPageDispatcherException(const AnsiString Msg, int AHelpContext) : Httpapp::EWebBrokerException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EPageDispatcherException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Httpapp::EWebBrokerException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EPageDispatcherException(int Ident, int AHelpContext)/* overload */ : Httpapp::EWebBrokerException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EPageDispatcherException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Httpapp::EWebBrokerException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EPageDispatcherException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EAdapterDispatcherException;
class PASCALIMPLEMENTATION EAdapterDispatcherException : public Httpapp::EWebBrokerException 
{
	typedef Httpapp::EWebBrokerException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EAdapterDispatcherException(const AnsiString Msg) : Httpapp::EWebBrokerException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EAdapterDispatcherException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Httpapp::EWebBrokerException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EAdapterDispatcherException(int Ident)/* overload */ : Httpapp::EWebBrokerException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EAdapterDispatcherException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Httpapp::EWebBrokerException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EAdapterDispatcherException(const AnsiString Msg, int AHelpContext) : Httpapp::EWebBrokerException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EAdapterDispatcherException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Httpapp::EWebBrokerException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EAdapterDispatcherException(int Ident, int AHelpContext)/* overload */ : Httpapp::EWebBrokerException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EAdapterDispatcherException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Httpapp::EWebBrokerException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EAdapterDispatcherException(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAdapterItemRequestParams;
class PASCALIMPLEMENTATION TAdapterItemRequestParams : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	AnsiString FSuccessPage;
	AnsiString FFailurePage;
	Classes::TStrings* FParamValues;
	
protected:
	void __fastcall SetSuccessPage(const AnsiString AValue);
	void __fastcall SetFailurePage(const AnsiString AValue);
	AnsiString __fastcall GetSuccessPage();
	AnsiString __fastcall GetFailurePage();
	Classes::TStrings* __fastcall GetParamValues(void);
	
public:
	__fastcall TAdapterItemRequestParams(void);
	__fastcall virtual ~TAdapterItemRequestParams(void);
	__property AnsiString SuccessPage = {read=GetSuccessPage, write=SetSuccessPage};
	__property AnsiString FailurePage = {read=GetFailurePage, write=SetFailurePage};
	__property Classes::TStrings* ParamValues = {read=GetParamValues};
private:
	void *__IAdapterItemRequestParams;	/* Sitecomp::IAdapterItemRequestParams */
	
public:
	operator IAdapterItemRequestParams*(void) { return (IAdapterItemRequestParams*)&__IAdapterItemRequestParams; }
	
};


class DELPHICLASS ESessionException;
class PASCALIMPLEMENTATION ESessionException : public Httpapp::EWebBrokerException 
{
	typedef Httpapp::EWebBrokerException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ESessionException(const AnsiString Msg) : Httpapp::EWebBrokerException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ESessionException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Httpapp::EWebBrokerException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ESessionException(int Ident)/* overload */ : Httpapp::EWebBrokerException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ESessionException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Httpapp::EWebBrokerException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ESessionException(const AnsiString Msg, int AHelpContext) : Httpapp::EWebBrokerException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ESessionException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Httpapp::EWebBrokerException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ESessionException(int Ident, int AHelpContext)/* overload */ : Httpapp::EWebBrokerException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ESessionException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Httpapp::EWebBrokerException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ESessionException(void) { }
	#pragma option pop
	
};


__interface IWebSessionAccess;
typedef System::DelphiInterface<IWebSessionAccess> _di_IWebSessionAccess;
__interface INTERFACE_UUID("{2C0D625A-9A26-4633-891B-38048E5265F3}") IWebSessionAccess  : public IInterface 
{
	
public:
	virtual Sitecomp::_di_IWebSession __fastcall GetWebSession(void) = 0 ;
	virtual Sitecomp::_di_ISessionsService __fastcall GetSessionsService(void) = 0 ;
};

class DELPHICLASS TWebSession;
class PASCALIMPLEMENTATION TWebSession : public Httpapp::TAbstractWebSession 
{
	typedef Httpapp::TAbstractWebSession inherited;
	
private:
	Sitecomp::_di_ISessionsService FSessions;
	Sitecomp::_di_IWebSession FWebSession;
	void __fastcall ReadSessionIDFromStore(Sitecomp::_di_ISessionsService ASessionsService, Httpapp::TWebRequest* ARequest, Httpapp::TWebResponse* AResponse);
	bool __fastcall ReadSessionCookie(Httpapp::TWebRequest* ARequest, Httpapp::TWebResponse* AResponse, /* out */ AnsiString &AID);
	__fastcall TWebSession(Sitecomp::_di_ISessionsService ASessions, Sitecomp::_di_IWebSession AWebSession)/* overload */;
	void __fastcall WriteSessionIDToStore(Httpapp::TWebResponse* AResponse, const AnsiString AValue);
	void __fastcall WriteSessionCookie(Httpapp::TWebResponse* AResponse, const AnsiString AValue);
	Sitecomp::_di_IWebSession __fastcall GetWebSession();
	Sitecomp::_di_ISessionsService __fastcall GetSessionsService();
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	
protected:
	virtual Variant __fastcall GetValue(const AnsiString AName);
	virtual void __fastcall SetValue(const AnsiString AName, const Variant &AValue);
	virtual int __fastcall GetTimeoutMinutes(void);
	virtual void __fastcall SetTimeoutMinutes(int AValue);
	virtual AnsiString __fastcall GetSessionID();
	
public:
	virtual void __fastcall UpdateResponse(Httpapp::TWebResponse* AResponse);
	virtual void __fastcall Terminate(void);
	__fastcall TWebSession(Sitecomp::_di_ISessionsService ASessions, Httpapp::TWebRequest* ARequest, Httpapp::TWebResponse* AResponse)/* overload */;
	__fastcall TWebSession(Sitecomp::_di_ISessionsService ASessions, AnsiString AID)/* overload */;
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TWebSession(void) { }
	#pragma option pop
	
private:
	void *__IWebSessionAccess;	/* Webdisp::IWebSessionAccess */
	
public:
	operator IWebSessionAccess*(void) { return (IWebSessionAccess*)&__IWebSessionAccess; }
	
};


class DELPHICLASS TInvalidWebSession;
class PASCALIMPLEMENTATION TInvalidWebSession : public Httpapp::TAbstractWebSession 
{
	typedef Httpapp::TAbstractWebSession inherited;
	
private:
	AnsiString FMsg;
	void __fastcall RaiseInvalidWebSession(void);
	
protected:
	virtual Variant __fastcall GetValue(const AnsiString AName);
	virtual void __fastcall SetValue(const AnsiString AName, const Variant &AValue);
	virtual int __fastcall GetTimeoutMinutes(void);
	virtual void __fastcall SetTimeoutMinutes(int AValue);
	virtual AnsiString __fastcall GetSessionID();
	
public:
	virtual void __fastcall UpdateResponse(Httpapp::TWebResponse* AResponse);
	virtual void __fastcall Terminate(void);
	__fastcall TInvalidWebSession(const AnsiString AMsg);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TInvalidWebSession(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define sRequestIDParamName "__id"
#define sSuccessPageParamName "__sp"
#define sFailurePageParamName "__fp"
#define sPageParamName "__p"
#define sSessionCookieName "WebBrokerSessionID"
extern PACKAGE void __fastcall SafeRedirect(Httpapp::TWebResponse* AResponse, const AnsiString AURL);
extern PACKAGE void __fastcall RegisterAdapterRequestIdentifier(const AnsiString AIdentifier);
extern PACKAGE void __fastcall RaiseDispatchBlankPageNameException(void);
extern PACKAGE void __fastcall RaisePageDoesNotProvideContent(const AnsiString APageName);
extern PACKAGE void __fastcall RaisePageNotFound(const AnsiString APageName);
extern PACKAGE AnsiString __fastcall EncodeParamsAsHTTPQuery(Classes::TStrings* AParams);
extern PACKAGE AnsiString __fastcall EncodeParamNameValues(Classes::TStrings* ParamValues);
extern PACKAGE void __fastcall ExtractParamNameValues(const AnsiString AParam, Classes::TStrings* AList);
extern PACKAGE AnsiString __fastcall PageNameOfRequest(Httpapp::TWebRequest* ARequest);
extern PACKAGE bool __fastcall DispatchPageName(const AnsiString APageName, Httpapp::TWebResponse* AResponse, Sitecomp::TDispatchPageFlags AFlags);
extern PACKAGE bool __fastcall RedirectToPageName(const AnsiString APageName, Classes::TStrings* AParams, Httpapp::TWebResponse* AResponse, Sitecomp::TDispatchPageFlags AFlags);
extern PACKAGE Classes::TStrings* __fastcall AdapterRequestParamsAsStrings(System::_di_IInterface AAdapterRequest);
extern PACKAGE AnsiString __fastcall FindDefaultAppPageName();
extern PACKAGE AnsiString __fastcall ExpandScriptException(Httpprod::EScriptError* E);

}	/* namespace Webdisp */
using namespace Webdisp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WebDisp
