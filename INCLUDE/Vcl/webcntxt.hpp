// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WebCntxt.pas' rev: 6.00

#ifndef WebCntxtHPP
#define WebCntxtHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Contnrs.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Webcntxt
{
//-- type declarations -------------------------------------------------------
__interface IWebPageInfo;
typedef System::DelphiInterface<IWebPageInfo> _di_IWebPageInfo;
__interface INTERFACE_UUID("{1CFF50D1-6995-11D4-A4AA-00C04F6BB853}") IWebPageInfo  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetPageName(void) = 0 ;
	__property AnsiString PageName = {read=GetPageName};
	virtual AnsiString __fastcall GetPageHREF(void) = 0 ;
	__property AnsiString PageHREF = {read=GetPageHREF};
	virtual AnsiString __fastcall GetPageTitle(void) = 0 ;
	__property AnsiString PageTitle = {read=GetPageTitle};
	virtual AnsiString __fastcall GetPageDescription(void) = 0 ;
	__property AnsiString PageDescription = {read=GetPageDescription};
	virtual bool __fastcall GetPageIsPublished(void) = 0 ;
	__property bool PageIsPublished = {read=GetPageIsPublished};
	virtual bool __fastcall GetLoginRequired(void) = 0 ;
	__property bool LoginRequired = {read=GetLoginRequired};
	virtual bool __fastcall GetHasViewAccess(void) = 0 ;
	__property bool HasViewAccess = {read=GetHasViewAccess};
};

#pragma option push -b-
enum TFindPageOption { fpPublished, fpLoginRequired };
#pragma option pop

typedef Set<TFindPageOption, fpPublished, fpLoginRequired>  TFindPageOptions;

__interface IWebEndUser;
typedef System::DelphiInterface<IWebEndUser> _di_IWebEndUser;
__interface INTERFACE_UUID("{2DBBD12D-3C07-4F7E-BD11-B3A4E1E287CD}") IWebEndUser  : public IInterface 
{
	
public:
	virtual bool __fastcall HasExecuteRights(AnsiString ARights) = 0 ;
	virtual bool __fastcall HasViewRights(AnsiString ARights) = 0 ;
	virtual bool __fastcall HasModifyRights(AnsiString ARights) = 0 ;
	virtual AnsiString __fastcall GetDisplayName(void) = 0 ;
	virtual bool __fastcall GetLoggedIn(void) = 0 ;
	virtual Classes::TComponent* __fastcall GetLogoutAction(void) = 0 ;
	virtual Classes::TComponent* __fastcall GetLoginFormAction(void) = 0 ;
	virtual Classes::TComponent* __fastcall GetEndUserAdapter(void) = 0 ;
	virtual void __fastcall LogIn(const Variant &UserID) = 0 ;
	virtual bool __fastcall ProduceLoginPage(void) = 0 ;
	__property AnsiString DisplayName = {read=GetDisplayName};
	__property bool LoggedIn = {read=GetLoggedIn};
	__property Classes::TComponent* LoginFormAction = {read=GetLoginFormAction};
	__property Classes::TComponent* LogoutAction = {read=GetLogoutAction};
	__property Classes::TComponent* EndUserAdapter = {read=GetEndUserAdapter};
};

class DELPHICLASS TAbstractWebContext;
class PASCALIMPLEMENTATION TAbstractWebContext : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	virtual _di_IWebEndUser __fastcall GetEndUser(void) = 0 ;
	virtual Httpapp::TWebRequest* __fastcall GetWebRequest(void) = 0 ;
	virtual Httpapp::TWebResponse* __fastcall GetWebResponse(void) = 0 ;
	virtual System::_di_IInterface __fastcall GetAdapterRequest(void) = 0 ;
	virtual System::_di_IInterface __fastcall GetAdapterResponse(void) = 0 ;
	virtual void __fastcall SetAdapterRequest(System::_di_IInterface Intf) = 0 ;
	virtual void __fastcall SetAdapterResponse(System::_di_IInterface Intf) = 0 ;
	virtual Httpapp::TAbstractWebModuleList* __fastcall GetWebModules(void) = 0 ;
	virtual Httpapp::TAbstractWebSession* __fastcall GetSession(void) = 0 ;
	virtual int __fastcall GetPageCount(void) = 0 ;
	virtual _di_IWebPageInfo __fastcall GetPageInfo(int I) = 0 ;
	virtual AnsiString __fastcall GetDispatchedPageName(void) = 0 ;
	virtual void __fastcall SetDispatchedPageName(const AnsiString APageName) = 0 ;
	virtual AnsiString __fastcall GetRequestedPageName(void) = 0 ;
	virtual void __fastcall SetRequestedPageName(const AnsiString APageName) = 0 ;
	
public:
	__fastcall TAbstractWebContext(void);
	__fastcall virtual ~TAbstractWebContext(void);
	virtual Classes::TComponent* __fastcall FindApplicationModule(System::TObject* WebModuleContext) = 0 ;
	virtual Classes::TComponent* __fastcall FindModuleClass(TMetaClass* AClass) = 0 ;
	virtual Classes::TComponent* __fastcall FindModuleName(const AnsiString AClass) = 0 ;
	virtual bool __fastcall FindPage(const AnsiString APage, TFindPageOptions AOptions, /* out */ System::TObject* &AComponent) = 0 ;
	virtual bool __fastcall FindPageInfo(const AnsiString APage, TFindPageOptions AOptions, /* out */ Httpapp::TAbstractWebPageInfo* &APageInfo) = 0 ;
	virtual bool __fastcall FindDefaultPageInfo(TMetaClass* AComponentClass, /* out */ Httpapp::TAbstractWebPageInfo* &APageInfo) = 0 ;
	virtual Classes::TComponent* __fastcall FindVariableContainer(const AnsiString AIdent) = 0 ;
	__property Httpapp::TWebRequest* Request = {read=GetWebRequest};
	__property Httpapp::TWebResponse* Response = {read=GetWebResponse};
	__property System::_di_IInterface AdapterRequest = {read=GetAdapterRequest};
	__property System::_di_IInterface AdapterResponse = {read=GetAdapterResponse};
	__property Httpapp::TAbstractWebSession* Session = {read=GetSession};
	__property Httpapp::TAbstractWebModuleList* WebModules = {read=GetWebModules};
	__property int PageCount = {read=GetPageCount, nodefault};
	__property _di_IWebPageInfo Pages[int I] = {read=GetPageInfo};
	__property _di_IWebEndUser EndUser = {read=GetEndUser};
	__property AnsiString DispatchedPageName = {read=GetDispatchedPageName, write=SetDispatchedPageName};
	__property AnsiString RequestedPageName = {read=GetRequestedPageName, write=SetRequestedPageName};
};


class DELPHICLASS TWebContext;
class PASCALIMPLEMENTATION TWebContext : public TAbstractWebContext 
{
	typedef TAbstractWebContext inherited;
	
private:
	Httpapp::TAbstractWebModuleList* FWebModules;
	Httpapp::TWebRequest* FRequest;
	Httpapp::TWebResponse* FResponse;
	Httpapp::TAbstractWebSession* FSession;
	Classes::_di_IInterfaceList FWebPageInfoList;
	Classes::TComponent* FApplicationModule;
	_di_IWebEndUser FEndUser;
	System::_di_IInterface FAdapterRequest;
	System::_di_IInterface FAdapterResponse;
	AnsiString FDispatchedPageName;
	AnsiString FRequestedPageName;
	
protected:
	virtual _di_IWebEndUser __fastcall GetEndUser();
	virtual Httpapp::TAbstractWebModuleList* __fastcall GetWebModules(void);
	virtual Httpapp::TWebRequest* __fastcall GetWebRequest(void);
	virtual Httpapp::TWebResponse* __fastcall GetWebResponse(void);
	virtual int __fastcall GetPageCount(void);
	virtual _di_IWebPageInfo __fastcall GetPageInfo(int I);
	virtual Httpapp::TAbstractWebSession* __fastcall GetSession(void);
	virtual System::_di_IInterface __fastcall GetAdapterRequest();
	virtual System::_di_IInterface __fastcall GetAdapterResponse();
	virtual void __fastcall SetAdapterRequest(System::_di_IInterface Intf);
	virtual void __fastcall SetAdapterResponse(System::_di_IInterface Intf);
	virtual AnsiString __fastcall GetDispatchedPageName();
	virtual void __fastcall SetDispatchedPageName(const AnsiString APageName);
	virtual AnsiString __fastcall GetRequestedPageName();
	virtual void __fastcall SetRequestedPageName(const AnsiString APageName);
	
public:
	__fastcall TWebContext(Httpapp::TAbstractWebModuleList* AWebModuleList, Httpapp::TWebRequest* ARequest, Httpapp::TWebResponse* AResponse, Httpapp::TAbstractWebSession* ASession);
	__fastcall virtual ~TWebContext(void);
	virtual Classes::TComponent* __fastcall FindApplicationModule(System::TObject* WebModuleContext);
	virtual Classes::TComponent* __fastcall FindModuleClass(TMetaClass* AClass);
	virtual Classes::TComponent* __fastcall FindModuleName(const AnsiString AName);
	virtual bool __fastcall FindPage(const AnsiString APage, TFindPageOptions AOptions, /* out */ System::TObject* &AComponent);
	virtual bool __fastcall FindPageInfo(const AnsiString APage, TFindPageOptions AOptions, /* out */ Httpapp::TAbstractWebPageInfo* &APageInfo);
	virtual bool __fastcall FindDefaultPageInfo(TMetaClass* AComponentClass, /* out */ Httpapp::TAbstractWebPageInfo* &APageInfo);
	virtual Classes::TComponent* __fastcall FindVariableContainer(const AnsiString AIdent);
};


class DELPHICLASS TAbstractAdapterRequest;
class PASCALIMPLEMENTATION TAbstractAdapterRequest : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Httpapp::TWebRequest* __fastcall GetRequest(void);
	
protected:
	__property Httpapp::TWebRequest* Request = {read=GetRequest};
	
public:
	__fastcall TAbstractAdapterRequest(void);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractAdapterRequest(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAbstractAdapterResponse;
class PASCALIMPLEMENTATION TAbstractAdapterResponse : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Httpapp::TWebResponse* __fastcall GetResponse(void);
	
protected:
	__property Httpapp::TWebResponse* Response = {read=GetResponse};
	
public:
	__fastcall TAbstractAdapterResponse(void);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractAdapterResponse(void) { }
	#pragma option pop
	
};


typedef TAbstractWebContext* __fastcall (*TGetWebContextProc)(void);

typedef void __fastcall (*TSetWebContextProc)(TAbstractWebContext* AWebContext);

typedef _di_IWebEndUser __fastcall (*TGetWebEndUserProc)(void);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TGetWebContextProc GetWebContextProc;
extern PACKAGE TSetWebContextProc SetWebContextProc;
extern PACKAGE TGetWebEndUserProc GetWebEndUserProc;
extern PACKAGE AnsiString __fastcall (*GetModuleFileNameProc)(void);
extern PACKAGE TAbstractWebContext* __fastcall WebContext(void);

}	/* namespace Webcntxt */
using namespace Webcntxt;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WebCntxt
