// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SiteComp.pas' rev: 6.00

#ifndef SiteCompHPP
#define SiteCompHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <WebCntxt.hpp>	// Pascal unit
#include <HTTPProd.hpp>	// Pascal unit
#include <ComObj.hpp>	// Pascal unit
#include <WebContnrs.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <WebComp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Sitecomp
{
//-- type declarations -------------------------------------------------------
__interface IWebApplicationInfo;
typedef System::DelphiInterface<IWebApplicationInfo> _di_IWebApplicationInfo;
__interface INTERFACE_UUID("{B2E0A3B9-6FA7-11D4-A4B8-00C04F6BB853}") IWebApplicationInfo  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetApplicationTitle(void) = 0 ;
	virtual Classes::TComponent* __fastcall GetApplicationAdapter(void) = 0 ;
	__property AnsiString ApplicationTitle = {read=GetApplicationTitle};
	__property Classes::TComponent* ApplicationAdapter = {read=GetApplicationAdapter};
};

__interface IDefaultPageFileName;
typedef System::DelphiInterface<IDefaultPageFileName> _di_IDefaultPageFileName;
__interface INTERFACE_UUID("{7F76F283-065E-11D4-A43E-00C04F6BB853}") IDefaultPageFileName  : public IInterface 
{
	
public:
	virtual void __fastcall SetDefaultPageFileName(const AnsiString APageFile) = 0 ;
};

__interface IGetDefaultAction;
typedef System::DelphiInterface<IGetDefaultAction> _di_IGetDefaultAction;
__interface INTERFACE_UUID("{F8094BDD-3DBB-445C-805B-80D68624BAD4}") IGetDefaultAction  : public IInterface 
{
	
public:
	virtual Classes::TComponent* __fastcall GetDefaultAction(void) = 0 ;
	__property Classes::TComponent* DefaultAction = {read=GetDefaultAction};
};

#pragma option push -b-
enum TDispatchPageFlag { dpPublished };
#pragma option pop

typedef Set<TDispatchPageFlag, dpPublished, dpPublished>  TDispatchPageFlags;

__interface IPageDispatcher;
typedef System::DelphiInterface<IPageDispatcher> _di_IPageDispatcher;
__interface INTERFACE_UUID("{C9FD165A-8F1C-11D4-A4E4-00C04F6BB853}") IPageDispatcher  : public IWebRequestHandler 
{
	
public:
	virtual AnsiString __fastcall GetDefaultPageName(void) = 0 ;
	virtual bool __fastcall DispatchPageName(const AnsiString APageName, Httpapp::TWebResponse* AResponse, TDispatchPageFlags AFlags) = 0 ;
	virtual bool __fastcall RedirectToPageName(const AnsiString APageName, Classes::TStrings* AParams, Httpapp::TWebResponse* AResponse, TDispatchPageFlags AFlags) = 0 ;
	virtual AnsiString __fastcall PageNameOfRequest(Httpapp::TWebRequest* ARequest) = 0 ;
	virtual bool __fastcall GetLoginRequired(const AnsiString APageName) = 0 ;
	virtual bool __fastcall GetCanView(const AnsiString APageName) = 0 ;
	__property AnsiString DefaultPageName = {read=GetDefaultPageName};
};

#pragma option push -b-
enum TAdapterItemRequestParamOption { roExcludeID };
#pragma option pop

typedef Set<TAdapterItemRequestParamOption, roExcludeID, roExcludeID>  TAdapterItemRequestParamOptions;

__interface IAdapterItemRequestParams;
typedef System::DelphiInterface<IAdapterItemRequestParams> _di_IAdapterItemRequestParams;
__interface INTERFACE_UUID("{AB707788-9328-45B7-B071-8A785610474F}") IAdapterItemRequestParams  : public IInterface 
{
	
public:
	virtual void __fastcall SetSuccessPage(const AnsiString AValue) = 0 ;
	virtual void __fastcall SetFailurePage(const AnsiString AValue) = 0 ;
	virtual AnsiString __fastcall GetSuccessPage(void) = 0 ;
	virtual AnsiString __fastcall GetFailurePage(void) = 0 ;
	virtual Classes::TStrings* __fastcall GetParamValues(void) = 0 ;
	__property AnsiString SuccessPage = {read=GetSuccessPage, write=SetSuccessPage};
	__property AnsiString FailurePage = {read=GetFailurePage, write=SetFailurePage};
	__property Classes::TStrings* ParamValues = {read=GetParamValues};
};

__interface IAdapterDispatcher;
typedef System::DelphiInterface<IAdapterDispatcher> _di_IAdapterDispatcher;
__interface INTERFACE_UUID("{C9FD1655-8F1C-11D4-A4E4-00C04F6BB853}") IAdapterDispatcher  : public IWebRequestHandler 
{
	
public:
	virtual AnsiString __fastcall EncodeAdapterItemRequestAsHREF(System::_di_IInterface AHandler, TAdapterItemRequestParamOptions AOptions) = 0 ;
	virtual AnsiString __fastcall EncodeAdapterItemRequestAsFieldValue(System::_di_IInterface AHandler, TAdapterItemRequestParamOptions AOptions) = 0 ;
	virtual void __fastcall GetAdapterItemRequestParams(System::_di_IInterface AHandler, TAdapterItemRequestParamOptions AOptions, _di_IAdapterItemRequestParams AParams) = 0 ;
};

__interface IPageResult;
typedef System::DelphiInterface<IPageResult> _di_IPageResult;
__interface INTERFACE_UUID("{608D1F61-F223-4574-89F7-F29A73372FFC}") IPageResult  : public IInterface 
{
	
public:
	virtual bool __fastcall DispatchPage(const AnsiString APageName, Httpapp::TWebResponse* AWebResponse) = 0 ;
	virtual Classes::TStream* __fastcall IncludePage(const AnsiString APageName, bool &AOwned) = 0 ;
	virtual bool __fastcall RedirectToPage(const AnsiString APageName, Classes::TStrings* AParams, Httpapp::TWebResponse* AWebResponse) = 0 ;
};

__interface IAdapterDispatchParams;
typedef System::DelphiInterface<IAdapterDispatchParams> _di_IAdapterDispatchParams;
__interface INTERFACE_UUID("{87018D80-0450-4CAB-BE8C-58F54040BCEB}") IAdapterDispatchParams  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetRequestIdentifier(void) = 0 ;
	virtual AnsiString __fastcall GetObjectIdentifier(void) = 0 ;
	virtual Classes::TStrings* __fastcall GetParams(void) = 0 ;
	virtual System::TObject* __fastcall GetHandler(void) = 0 ;
	__property AnsiString RequestIdentifier = {read=GetRequestIdentifier};
	__property AnsiString ObjectIdentifier = {read=GetObjectIdentifier};
	__property Classes::TStrings* Params = {read=GetParams};
	__property System::TObject* Handler = {read=GetHandler};
};

__interface IAdapterRequestHandler;
typedef System::DelphiInterface<IAdapterRequestHandler> _di_IAdapterRequestHandler;
__interface INTERFACE_UUID("{48C27474-2E1F-4797-9E72-AFA6CE42F826}") IAdapterRequestHandler  : public IInterface 
{
	
public:
	virtual void __fastcall CreateRequestContext(_di_IAdapterDispatchParams DispatchParams) = 0 ;
	virtual bool __fastcall HandleRequest(_di_IAdapterDispatchParams DispatchParams) = 0 ;
};

__interface IGetAdapterItemRequestParams;
typedef System::DelphiInterface<IGetAdapterItemRequestParams> _di_IGetAdapterItemRequestParams;
__interface INTERFACE_UUID("{14D978F5-D1E9-11D4-A532-00C04F6BB853}") IGetAdapterItemRequestParams  : public IInterface 
{
	
public:
	virtual void __fastcall GetAdapterItemRequestParams(AnsiString &AIdentifier, _di_IAdapterItemRequestParams AParams) = 0 ;
};

__interface IGetAdapterRequestDefaultResponse;
typedef System::DelphiInterface<IGetAdapterRequestDefaultResponse> _di_IGetAdapterRequestDefaultResponse;
__interface INTERFACE_UUID("{14D978F4-D1E9-11D4-A532-00C04F6BB853}") IGetAdapterRequestDefaultResponse  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetSuccessPage(void) = 0 ;
	virtual AnsiString __fastcall GetFailurePage(void) = 0 ;
	__property AnsiString SuccessPage = {read=GetSuccessPage};
	__property AnsiString FailurePage = {read=GetFailurePage};
};

__interface IWebFormComponentContainer;
typedef System::DelphiInterface<IWebFormComponentContainer> _di_IWebFormComponentContainer;
__interface INTERFACE_UUID("{F7E1CF51-F759-11D3-ABDA-EFF689219731}") IWebFormComponentContainer  : public IInterface 
{
	
public:
	virtual int __fastcall GetCount(void) = 0 ;
	virtual Classes::TComponent* __fastcall GetItem(int I) = 0 ;
	__property int Count = {read=GetCount};
	__property Classes::TComponent* Items[int I] = {read=GetItem};
};

__interface IWebUserList;
typedef System::DelphiInterface<IWebUserList> _di_IWebUserList;
__interface INTERFACE_UUID("{0877DEAF-AB5D-11D4-A503-00C04F6BB853}") IWebUserList  : public IInterface 
{
	
public:
	virtual Variant __fastcall ValidateUser(Classes::TStrings* Strings) = 0 ;
	virtual bool __fastcall CheckAccessRights(const Variant &UserID, AnsiString Rights) = 0 ;
};

__interface IGetWebAppComponents;
typedef System::DelphiInterface<IGetWebAppComponents> _di_IGetWebAppComponents;
__interface INTERFACE_UUID("{19CD2F0D-E68F-4A6F-92AA-4C7659E83708}") IGetWebAppComponents  : public IInterface 
{
	
public:
	virtual Httpprod::_di_ILocateFileService __fastcall GetLocateFileService(void) = 0 ;
	virtual _di_IPageDispatcher __fastcall GetPageDispatcher(void) = 0 ;
	virtual _di_IAdapterDispatcher __fastcall GetAdapterDispatcher(void) = 0 ;
	virtual _di_IWebApplicationInfo __fastcall GetWebApplicationInfo(void) = 0 ;
	virtual Webcntxt::_di_IWebEndUser __fastcall GetWebEndUser(void) = 0 ;
	virtual _di_IWebUserList __fastcall GetWebUserList(void) = 0 ;
	__property Webcntxt::_di_IWebEndUser WebEndUser = {read=GetWebEndUser};
	__property _di_IWebApplicationInfo WebApplicationInfo = {read=GetWebApplicationInfo};
};

class DELPHICLASS TAbstractDesigntimeWarnings;
class PASCALIMPLEMENTATION TAbstractDesigntimeWarnings : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual void __fastcall AddString(AnsiString AWarning) = 0 ;
	virtual void __fastcall AddObject(System::TObject* AObject) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TAbstractDesigntimeWarnings(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractDesigntimeWarnings(void) { }
	#pragma option pop
	
};


__interface IGetDesigntimeWarnings;
typedef System::DelphiInterface<IGetDesigntimeWarnings> _di_IGetDesigntimeWarnings;
__interface INTERFACE_UUID("{20508BF7-A9CE-11D4-A501-00C04F6BB853}") IGetDesigntimeWarnings  : public IInterface 
{
	
public:
	virtual void __fastcall GetDesigntimeWarnings(TAbstractDesigntimeWarnings* AWarnings) = 0 ;
};

__interface INotifyList;
typedef System::DelphiInterface<INotifyList> _di_INotifyList;
__interface INTERFACE_UUID("{0444FED2-835C-4DAD-9C79-49BDC62AFA8A}") INotifyList  : public IInterface 
{
	
public:
	virtual void __fastcall AddNotify(System::TObject* ANotify) = 0 ;
	virtual void __fastcall RemoveNotify(System::TObject* ANotify) = 0 ;
};

__interface INotifyAdapterChange;
typedef System::DelphiInterface<INotifyAdapterChange> _di_INotifyAdapterChange;
__interface INTERFACE_UUID("{442FC843-4F85-4137-8564-FF6EEDBA1465}") INotifyAdapterChange  : public IInterface 
{
	
public:
	virtual void __fastcall NotifyAdapterChange(Classes::TComponent* Sender) = 0 ;
};

__interface IIteratorSupport;
typedef System::DelphiInterface<IIteratorSupport> _di_IIteratorSupport;
__interface INTERFACE_UUID("{BDFABA24-F5C3-11D3-ABD8-A00CB821173C}") IIteratorSupport  : public IInterface 
{
	
public:
	virtual bool __fastcall StartIterator(void * &OwnerData) = 0 ;
	virtual bool __fastcall NextIteration(void * &OwnerData) = 0 ;
	virtual void __fastcall EndIterator(void * OwnerData) = 0 ;
};

__interface IIteratorIndex;
typedef System::DelphiInterface<IIteratorIndex> _di_IIteratorIndex;
__interface INTERFACE_UUID("{A6CBA53A-8326-4F7A-BFFE-02A2C6E41B67}") IIteratorIndex  : public IInterface 
{
	
public:
	virtual bool __fastcall InIterator(void) = 0 ;
	virtual int __fastcall GetIteratorIndex(void) = 0 ;
	__property int IteratorIndex = {read=GetIteratorIndex};
};

__interface IIterateObjectSupport;
typedef System::DelphiInterface<IIterateObjectSupport> _di_IIterateObjectSupport;
__interface INTERFACE_UUID("{76159C52-A181-4F16-B27E-35F7979BE87F}") IIterateObjectSupport  : public IIteratorSupport 
{
	
public:
	virtual System::TObject* __fastcall GetCurrentObject(void * OwnerData) = 0 ;
};

__interface IIterateIntfSupport;
typedef System::DelphiInterface<IIterateIntfSupport> _di_IIterateIntfSupport;
__interface INTERFACE_UUID("{064EFCF2-B422-4720-B364-633D28CD3216}") IIterateIntfSupport  : public IIteratorSupport 
{
	
public:
	virtual System::_di_IInterface __fastcall GetCurrentIntf(void * OwnerData) = 0 ;
};

typedef TMetaClass*TScriptComponentClass;

__interface IGetScriptObject;
typedef System::DelphiInterface<IGetScriptObject> _di_IGetScriptObject;
__interface INTERFACE_UUID("{CAC16452-9BAD-11D4-A4F2-00C04F6BB853}") IGetScriptObject  : public IInterface 
{
	
public:
	virtual _di_IDispatch __fastcall GetScriptObject(void) = 0 ;
};

__interface IWebContainerSubComponent;
typedef System::DelphiInterface<IWebContainerSubComponent> _di_IWebContainerSubComponent;
__interface IWebContainerSubComponent  : public IInterface 
{
	
};

typedef AnsiString TSessionID;

__interface IWebSession;
typedef System::DelphiInterface<IWebSession> _di_IWebSession;
__interface INTERFACE_UUID("{D2727F50-2399-495C-B2C3-649A3512D087}") IWebSession  : public IInterface 
{
	
public:
	virtual void __fastcall Terminate(void) = 0 ;
};

__interface IWebSessionValues;
typedef System::DelphiInterface<IWebSessionValues> _di_IWebSessionValues;
__interface INTERFACE_UUID("{26F78C60-0D62-42AE-B890-57EF475FB5D3}") IWebSessionValues  : public IInterface 
{
	
public:
	virtual void __fastcall GetItems(Webcontnrs::TAbstractNamedVariants* &AItems) = 0 ;
	virtual int __fastcall GetItemCount(void) = 0 ;
	virtual void __fastcall SetValue(const AnsiString AName, const Variant &AValue) = 0 ;
	virtual Variant __fastcall GetValue(const AnsiString AName) = 0 ;
	__property Variant Values[AnsiString AName] = {read=GetValue, write=SetValue};
};

__interface IWebSessionID;
typedef System::DelphiInterface<IWebSessionID> _di_IWebSessionID;
__interface INTERFACE_UUID("{FF5D064E-FF1B-480E-BA9D-6B7F8AA4E477}") IWebSessionID  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetID(void) = 0 ;
	__property AnsiString ID = {read=GetID};
};

__interface IWebSessionAttributes;
typedef System::DelphiInterface<IWebSessionAttributes> _di_IWebSessionAttributes;
__interface INTERFACE_UUID("{29D2BFB7-4336-4F14-B1FE-417AEC40A12F}") IWebSessionAttributes  : public IInterface 
{
	
public:
	virtual System::TDateTime __fastcall GetStartTime(void) = 0 ;
	__property System::TDateTime StartTime = {read=GetStartTime};
	virtual int __fastcall GetTimeoutMinutes(void) = 0 ;
	virtual void __fastcall SetTimeoutMinutes(int AValue) = 0 ;
	__property int TimeoutMinutes = {read=GetTimeoutMinutes, write=SetTimeoutMinutes};
	virtual System::TDateTime __fastcall GetTouchTime(void) = 0 ;
	__property System::TDateTime TouchTime = {read=GetTouchTime};
	virtual System::TDateTime __fastcall GetExpirationTime(void) = 0 ;
	__property System::TDateTime ExpirationTime = {read=GetExpirationTime};
	virtual bool __fastcall GetExpired(void) = 0 ;
	__property bool Expired = {read=GetExpired};
	virtual bool __fastcall GetTerminated(void) = 0 ;
	__property bool Terminated = {read=GetTerminated};
	virtual bool __fastcall GetIsActive(void) = 0 ;
	__property bool IsActive = {read=GetIsActive};
};

__interface ISessionsServiceConnectID;
typedef System::DelphiInterface<ISessionsServiceConnectID> _di_ISessionsServiceConnectID;
__interface INTERFACE_UUID("{FA0C1658-726C-47DF-9810-84A207EFCA65}") ISessionsServiceConnectID  : public IInterface 
{
	
public:
	virtual _di_IWebSession __fastcall Connect(AnsiString AID) = 0 ;
	virtual _di_IWebSession __fastcall ConnectActive(AnsiString AID) = 0 ;
};

__interface ISessionsServiceStoreID;
typedef System::DelphiInterface<ISessionsServiceStoreID> _di_ISessionsServiceStoreID;
__interface INTERFACE_UUID("{2BA89434-8F6B-4119-B700-1D1400E9CC87}") ISessionsServiceStoreID  : public IInterface 
{
	
public:
	virtual bool __fastcall ReadSessionID(Httpapp::TWebRequest* ARequest, Httpapp::TWebResponse* AResponse, /* out */ AnsiString &AID) = 0 ;
	virtual void __fastcall WriteSessionID(Httpapp::TWebResponse* AResponse, AnsiString AID) = 0 ;
};

__interface IWebSessionIDs;
typedef System::DelphiInterface<IWebSessionIDs> _di_IWebSessionIDs;
__interface INTERFACE_UUID("{CC119E2C-6574-4A59-A3EE-952DB537F76B}") IWebSessionIDs  : public IInterface 
{
	
public:
	virtual int __fastcall GetIDCount(void) = 0 ;
	virtual AnsiString __fastcall GetID(int I) = 0 ;
	__property int IDCount = {read=GetIDCount};
	__property AnsiString IDs[int I] = {read=GetID};
};

__interface IWebGetSessionIDs;
typedef System::DelphiInterface<IWebGetSessionIDs> _di_IWebGetSessionIDs;
__interface INTERFACE_UUID("{6D14F7B1-F503-4B53-B364-2BE7229D33EC}") IWebGetSessionIDs  : public IInterface 
{
	
public:
	virtual _di_IWebSessionIDs __fastcall GetSessionIDs(void) = 0 ;
};

__interface ISessionsService;
typedef System::DelphiInterface<ISessionsService> _di_ISessionsService;
__interface INTERFACE_UUID("{6EAAC21D-42CF-4486-A8E6-D9C8562BD681}") ISessionsService  : public IInterface 
{
	
public:
	virtual _di_IWebSession __fastcall NewSession(void) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall CheckStatusChange(void) = 0 ;
	virtual void __fastcall NotifyStatusChange(void) = 0 ;
};

__interface ISessionsServicePersist;
typedef System::DelphiInterface<ISessionsServicePersist> _di_ISessionsServicePersist;
__interface INTERFACE_UUID("{6FFA990F-183E-468E-8246-2E1093CEA13D}") ISessionsServicePersist  : public IInterface 
{
	
public:
	virtual void __fastcall LoadFromFile(const AnsiString Filename) = 0 ;
	virtual void __fastcall SaveToFile(const AnsiString Filename) = 0 ;
	virtual void __fastcall LoadFromStream(Classes::TStream* S) = 0 ;
	virtual void __fastcall SaveToStream(Classes::TStream* S) = 0 ;
};

__interface IFindIncludeFile;
typedef System::DelphiInterface<IFindIncludeFile> _di_IFindIncludeFile;
__interface INTERFACE_UUID("{93895ECC-E8BA-4F8E-80D0-785D28359932}") IFindIncludeFile  : public IInterface 
{
	
public:
	virtual bool __fastcall FindIncludeFile(Classes::TComponent* AComponent, const AnsiString AFileName, AnsiString &AResult) = 0 ;
};

class DELPHICLASS TAbstractInetFileType;
class PASCALIMPLEMENTATION TAbstractInetFileType : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	virtual AnsiString __fastcall GetTypeID(void) = 0 ;
	virtual int __fastcall GetExtCount(void) = 0 ;
	virtual AnsiString __fastcall GetFileExt(int I) = 0 ;
	
public:
	__property AnsiString TypeID = {read=GetTypeID};
	__property int FileExtCount = {read=GetExtCount, nodefault};
	__property AnsiString FileExt[int I] = {read=GetFileExt};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TAbstractInetFileType(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractInetFileType(void) { }
	#pragma option pop
	
};


__interface IInternetFileTypes;
typedef System::DelphiInterface<IInternetFileTypes> _di_IInternetFileTypes;
__interface INTERFACE_UUID("{0257655C-F868-11D4-A55F-00C04F6BB853}") IInternetFileTypes  : public IInterface 
{
	
public:
	virtual TAbstractInetFileType* __fastcall FindFileExt(const AnsiString AFileExt) = 0 ;
};

__interface IInternetScriptDebugger;
typedef System::DelphiInterface<IInternetScriptDebugger> _di_IInternetScriptDebugger;
__interface INTERFACE_UUID("{0257655B-F868-11D4-A55F-00C04F6BB853}") IInternetScriptDebugger  : public IInterface 
{
	
public:
	virtual void __fastcall DebugScript(System::_di_IInterface AContext) = 0 ;
	virtual bool __fastcall CanDebugScript(System::_di_IInterface AContext) = 0 ;
};

__interface IInternetExecuteScript;
typedef System::DelphiInterface<IInternetExecuteScript> _di_IInternetExecuteScript;
__interface INTERFACE_UUID("{0257655E-F868-11D4-A55F-00C04F6BB853}") IInternetExecuteScript  : public IInterface 
{
	
public:
	virtual void __fastcall ExecuteScript(System::_di_IInterface AContext) = 0 ;
	virtual bool __fastcall CanExecuteScript(System::_di_IInterface AContext) = 0 ;
};

__interface IInternetEnvOptions;
typedef System::DelphiInterface<IInternetEnvOptions> _di_IInternetEnvOptions;
__interface INTERFACE_UUID("{F92A39B5-C7D1-4E10-A67C-AC775042DA0E}") IInternetEnvOptions  : public IInterface 
{
	
public:
	virtual bool __fastcall GetDisableDebugging(void) = 0 ;
	virtual AnsiString __fastcall GetHTMLExt(void) = 0 ;
	virtual AnsiString __fastcall GetSampleImageFile(void) = 0 ;
	virtual int __fastcall GetScriptTimeoutSecs(void) = 0 ;
	__property bool DisableDebugger = {read=GetDisableDebugging};
	__property AnsiString HTMLExt = {read=GetHTMLExt};
	__property AnsiString SampleImageFile = {read=GetSampleImageFile};
	__property int ScriptTimeoutSecs = {read=GetScriptTimeoutSecs};
};

__interface IIDEFileManager;
typedef System::DelphiInterface<IIDEFileManager> _di_IIDEFileManager;
__interface INTERFACE_UUID("{B61156EF-7265-43E9-9FAF-D6E1D2EA2075}") IIDEFileManager  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall SearchFile(const AnsiString AFileName) = 0 ;
};

__interface IAdapterError;
typedef System::DelphiInterface<IAdapterError> _di_IAdapterError;
__interface INTERFACE_UUID("{27A6D8A1-58E1-11D4-A493-00C04F6BB853}") IAdapterError  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetErrorText(void) = 0 ;
	virtual int __fastcall GetID(void) = 0 ;
	virtual Classes::TComponent* __fastcall GetField(void) = 0 ;
	__property AnsiString ErrorText = {read=GetErrorText};
	__property int ID = {read=GetID};
	__property Classes::TComponent* Field = {read=GetField};
};

__interface IAdapterHiddenField;
typedef System::DelphiInterface<IAdapterHiddenField> _di_IAdapterHiddenField;
__interface INTERFACE_UUID("{90E9C34B-D054-11D4-A530-00C04F6BB853}") IAdapterHiddenField  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetName(void) = 0 ;
	virtual AnsiString __fastcall GetValue(void) = 0 ;
	__property AnsiString Name = {read=GetName};
	__property AnsiString Value = {read=GetValue};
};

__interface IAdapterAccess;
typedef System::DelphiInterface<IAdapterAccess> _di_IAdapterAccess;
__interface INTERFACE_UUID("{179232C0-CC77-11D4-A52B-00C04F6BB853}") IAdapterAccess  : public IInterface 
{
	
public:
	virtual bool __fastcall HasViewAccess(void) = 0 ;
	virtual bool __fastcall HasModifyAccess(void) = 0 ;
	virtual bool __fastcall HasExecuteAccess(void) = 0 ;
};

__interface IGetAdapterErrors;
typedef System::DelphiInterface<IGetAdapterErrors> _di_IGetAdapterErrors;
__interface INTERFACE_UUID("{27A6D89F-58E1-11D4-A493-00C04F6BB853}") IGetAdapterErrors  : public IInterface 
{
	
public:
	virtual System::TObject* __fastcall GetAdapterErrors(void) = 0 ;
};

__interface IAdapterHiddenFields;
typedef System::DelphiInterface<IAdapterHiddenFields> _di_IAdapterHiddenFields;
__interface INTERFACE_UUID("{90E9C34C-D054-11D4-A530-00C04F6BB853}") IAdapterHiddenFields  : public IInterface 
{
	
public:
	virtual int __fastcall GetFieldCount(void) = 0 ;
	virtual _di_IAdapterHiddenField __fastcall GetField(int I) = 0 ;
	__property int FieldCount = {read=GetFieldCount};
	__property _di_IAdapterHiddenField Fields[int I] = {read=GetField};
};

__interface IGetAdapterHiddenFields;
typedef System::DelphiInterface<IGetAdapterHiddenFields> _di_IGetAdapterHiddenFields;
__interface INTERFACE_UUID("{90E9C34D-D054-11D4-A530-00C04F6BB853}") IGetAdapterHiddenFields  : public IInterface 
{
	
public:
	virtual System::TObject* __fastcall GetAdapterHiddenFields(void) = 0 ;
	virtual System::TObject* __fastcall GetAdapterHiddenRecordFields(void) = 0 ;
};

__interface IAdapterMode;
typedef System::DelphiInterface<IAdapterMode> _di_IAdapterMode;
__interface INTERFACE_UUID("{9E6E6A7C-574F-11D4-A491-00C04F6BB853}") IAdapterMode  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetAdapterMode(void) = 0 ;
	virtual bool __fastcall GetNeedAdapterMode(void) = 0 ;
	virtual void __fastcall SetAdapterMode(const AnsiString AValue) = 0 ;
	virtual void __fastcall RestoreDefaultAdapterMode(void) = 0 ;
	__property AnsiString AdapterMode = {read=GetAdapterMode, write=SetAdapterMode};
	__property bool NeedAdapterMode = {read=GetNeedAdapterMode};
};

__interface IAdapterErrors;
typedef System::DelphiInterface<IAdapterErrors> _di_IAdapterErrors;
__interface INTERFACE_UUID("{27A6D8A0-58E1-11D4-A493-00C04F6BB853}") IAdapterErrors  : public IInterface 
{
	
public:
	virtual void __fastcall ClearErrors(void) = 0 ;
	virtual int __fastcall GetErrorCount(void) = 0 ;
	virtual _di_IAdapterError __fastcall GetError(int I) = 0 ;
	virtual void __fastcall DefineLabel(const AnsiString AName, const AnsiString ALabel) = 0 ;
	__property int ErrorCount = {read=GetErrorCount};
	__property _di_IAdapterError Errors[int I] = {read=GetError};
	virtual bool __fastcall HasObjectErrors(const AnsiString AName) = 0 ;
	virtual System::TObject* __fastcall GetObjectErrors(const AnsiString AName) = 0 ;
};

__interface IWebGetFieldValue;
typedef System::DelphiInterface<IWebGetFieldValue> _di_IWebGetFieldValue;
__interface INTERFACE_UUID("{9E6E6A7F-574F-11D4-A491-00C04F6BB853}") IWebGetFieldValue  : public IInterface 
{
	
public:
	virtual Variant __fastcall GetValue(void) = 0 ;
	__property Variant Value = {read=GetValue};
};

__interface IAsFormatted;
typedef System::DelphiInterface<IAsFormatted> _di_IAsFormatted;
__interface INTERFACE_UUID("{18138862-52C0-11D4-A48D-00C04F6BB853}") IAsFormatted  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall AsFormatted(void) = 0 ;
};

__interface IWebGetDisplayWidth;
typedef System::DelphiInterface<IWebGetDisplayWidth> _di_IWebGetDisplayWidth;
__interface INTERFACE_UUID("{A23C86B6-672A-11D4-A4A7-00C04F6BB853}") IWebGetDisplayWidth  : public IInterface 
{
	
public:
	virtual int __fastcall GetDisplayWidth(void) = 0 ;
};

__interface IImageProducer;
typedef System::DelphiInterface<IImageProducer> _di_IImageProducer;
__interface INTERFACE_UUID("{BD76DC8D-BE4B-403D-9080-71DDA287EA5A}") IImageProducer  : public IInterface 
{
	
public:
	virtual System::_di_IInterface __fastcall GetAdapterImage(Classes::TComponent* Sender, const WideString ACaption) = 0 ;
};

__interface IActionImageProducer;
typedef System::DelphiInterface<IActionImageProducer> _di_IActionImageProducer;
__interface INTERFACE_UUID("{5622A0AA-DD67-4DAC-871A-9C621A762538}") IActionImageProducer  : public IImageProducer 
{
	
public:
	virtual AnsiString __fastcall GetDisplayStyle(Classes::TComponent* Sender) = 0 ;
	virtual System::_di_IInterface __fastcall GetAdapterEventImage(Classes::TComponent* Sender, const WideString AEvent, const WideString ACaption) = 0 ;
};

__interface IWebGetDisplayLabel;
typedef System::DelphiInterface<IWebGetDisplayLabel> _di_IWebGetDisplayLabel;
__interface INTERFACE_UUID("{A23C86B7-672A-11D4-A4A7-00C04F6BB853}") IWebGetDisplayLabel  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetDisplayLabel(void) = 0 ;
};

__interface IWebGetMaxLength;
typedef System::DelphiInterface<IWebGetMaxLength> _di_IWebGetMaxLength;
__interface INTERFACE_UUID("{772D7639-8209-4744-9146-2B6D3A5F220F}") IWebGetMaxLength  : public IInterface 
{
	
public:
	virtual int __fastcall GetMaxLength(void) = 0 ;
};

__interface IWebInputName;
typedef System::DelphiInterface<IWebInputName> _di_IWebInputName;
__interface INTERFACE_UUID("{CD1644C0-41E8-4C06-9AB8-CD6B05367E27}") IWebInputName  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetInputName(void) = 0 ;
	__property AnsiString InputName = {read=GetInputName};
};

__interface IValuesListAdapter;
typedef System::DelphiInterface<IValuesListAdapter> _di_IValuesListAdapter;
__interface INTERFACE_UUID("{CAC16451-9BAD-11D4-A4F2-00C04F6BB853}") IValuesListAdapter  : public IInterface 
{
	
public:
	virtual Variant __fastcall GetListValue(void) = 0 ;
	virtual AnsiString __fastcall GetListName(void) = 0 ;
	virtual AnsiString __fastcall GetListNameOfValue(const Variant &Value) = 0 ;
	virtual System::_di_IInterface __fastcall GetListImage(void) = 0 ;
	virtual System::_di_IInterface __fastcall GetListImageOfValue(const Variant &Value) = 0 ;
};

__interface IGetAdapterImage;
typedef System::DelphiInterface<IGetAdapterImage> _di_IGetAdapterImage;
__interface INTERFACE_UUID("{59FD8382-A09A-11D4-A4F7-00C04F6BB853}") IGetAdapterImage  : public IInterface 
{
	
public:
	virtual System::_di_IInterface __fastcall GetAdapterImage(void) = 0 ;
};

__interface IGetHTMLStyle;
typedef System::DelphiInterface<IGetHTMLStyle> _di_IGetHTMLStyle;
__interface INTERFACE_UUID("{1C1557D1-CA79-4BEE-86E2-253BEC8925E2}") IGetHTMLStyle  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetDisplayStyle(const AnsiString AAdapterMode) = 0 ;
	virtual AnsiString __fastcall GetInputStyle(const AnsiString AAdapterMode) = 0 ;
	virtual AnsiString __fastcall GetViewMode(const AnsiString AAdapterMode) = 0 ;
};

__interface IAdapterFieldAccess;
typedef System::DelphiInterface<IAdapterFieldAccess> _di_IAdapterFieldAccess;
__interface INTERFACE_UUID("{98C3D564-3CE4-412C-A7FE-DA05A1A37953}") IAdapterFieldAccess  : public IInterface 
{
	
public:
	virtual bool __fastcall HasViewAccess(void) = 0 ;
	virtual bool __fastcall HasModifyAccess(void) = 0 ;
};

__interface IGetFieldValuesAdapter;
typedef System::DelphiInterface<IGetFieldValuesAdapter> _di_IGetFieldValuesAdapter;
__interface INTERFACE_UUID("{87BDFE12-CA10-11D4-A528-00C04F6BB853}") IGetFieldValuesAdapter  : public IInterface 
{
	
public:
	virtual Classes::TComponent* __fastcall GetFieldValuesAdapter(void) = 0 ;
};

__interface IWebValueIsEqual;
typedef System::DelphiInterface<IWebValueIsEqual> _di_IWebValueIsEqual;
__interface INTERFACE_UUID("{495042FB-97CE-4CA1-921F-9A09DD3B65F2}") IWebValueIsEqual  : public IInterface 
{
	
public:
	virtual bool __fastcall IsEqual(const Variant &Value) = 0 ;
};

__interface IAdapterFieldAttributes;
typedef System::DelphiInterface<IAdapterFieldAttributes> _di_IAdapterFieldAttributes;
__interface INTERFACE_UUID("{179232BF-CC77-11D4-A52B-00C04F6BB853}") IAdapterFieldAttributes  : public IInterface 
{
	
public:
	virtual bool __fastcall GetVisible(void) = 0 ;
	virtual bool __fastcall GetRequired(void) = 0 ;
	__property bool Visible = {read=GetVisible};
	__property bool Required = {read=GetRequired};
};

__interface IIsAdapterActionList;
typedef System::DelphiInterface<IIsAdapterActionList> _di_IIsAdapterActionList;
__interface INTERFACE_UUID("{AFA05E90-DDAA-4B7F-B7A6-D3F9093D9427}") IIsAdapterActionList  : public IInterface 
{
	
public:
	virtual bool __fastcall GetIsAdapterActionList(void) = 0 ;
	__property bool IsAdapterActionList = {read=GetIsAdapterActionList};
};

__interface IAdapterActionAccess;
typedef System::DelphiInterface<IAdapterActionAccess> _di_IAdapterActionAccess;
__interface INTERFACE_UUID("{55285C44-A3BE-4821-9994-0051647699A7}") IAdapterActionAccess  : public IInterface 
{
	
public:
	virtual bool __fastcall HasExecuteAccess(void) = 0 ;
};

__interface IGetAdapterValuesList;
typedef System::DelphiInterface<IGetAdapterValuesList> _di_IGetAdapterValuesList;
__interface INTERFACE_UUID("{59D7E94D-9BA9-11D4-A4F2-00C04F6BB853}") IGetAdapterValuesList  : public IInterface 
{
	
public:
	virtual _di_IValuesListAdapter __fastcall GetAdapterValuesList(void) = 0 ;
};

__interface IWebEnabled;
typedef System::DelphiInterface<IWebEnabled> _di_IWebEnabled;
__interface INTERFACE_UUID("{648F97D7-B299-444A-89CA-E60BD1FB9EA3}") IWebEnabled  : public IInterface 
{
	
public:
	virtual bool __fastcall WebEnabled(void) = 0 ;
};

__interface IGetAdapterFields;
typedef System::DelphiInterface<IGetAdapterFields> _di_IGetAdapterFields;
__interface INTERFACE_UUID("{30B45B2F-B5B7-4BAE-A6FC-EC47E5B0C941}") IGetAdapterFields  : public IInterface 
{
	
public:
	virtual Classes::TComponent* __fastcall GetAdapterFields(void) = 0 ;
};

__interface IAdapterActionAttributes;
typedef System::DelphiInterface<IAdapterActionAttributes> _di_IAdapterActionAttributes;
__interface INTERFACE_UUID("{B86F48C3-BEEB-43A7-9BEF-1ABE1311E419}") IAdapterActionAttributes  : public IInterface 
{
	
public:
	virtual bool __fastcall GetVisible(void) = 0 ;
	__property bool Visible = {read=GetVisible};
};

__interface IGetAdapterActions;
typedef System::DelphiInterface<IGetAdapterActions> _di_IGetAdapterActions;
__interface INTERFACE_UUID("{0C2D1ECE-7BBA-43FE-A466-2D8BC70CC85D}") IGetAdapterActions  : public IInterface 
{
	
public:
	virtual Classes::TComponent* __fastcall GetAdapterActions(void) = 0 ;
};

__interface IWebImageHREF;
typedef System::DelphiInterface<IWebImageHREF> _di_IWebImageHREF;
__interface INTERFACE_UUID("{10E873A2-A6DD-4AE9-8AB5-4597142E4631}") IWebImageHREF  : public IInterface 
{
	
public:
	virtual bool __fastcall WebImageHREF(AnsiString &AHREF) = 0 ;
};

__interface IFieldValuesAdapter;
typedef System::DelphiInterface<IFieldValuesAdapter> _di_IFieldValuesAdapter;
__interface INTERFACE_UUID("{87BDFE13-CA10-11D4-A528-00C04F6BB853}") IFieldValuesAdapter  : public IInterface 
{
	
public:
	virtual System::TObject* __fastcall GetField(void) = 0 ;
	virtual int __fastcall GetValueIndex(void) = 0 ;
};

__interface IWebGetFieldValues;
typedef System::DelphiInterface<IWebGetFieldValues> _di_IWebGetFieldValues;
__interface INTERFACE_UUID("{5DC0D607-1C9C-4E67-B3BA-35CE2A5872A0}") IWebGetFieldValues  : public IInterface 
{
	
public:
	virtual Variant __fastcall GetCurrentValue(void) = 0 ;
	virtual bool __fastcall HasValue(const Variant &AValue) = 0 ;
	virtual bool __fastcall StartValueIterator(void * &OwnerData) = 0 ;
	virtual bool __fastcall NextValueIteration(void * &OwnerData) = 0 ;
	virtual void __fastcall EndValueIterator(void * OwnerData) = 0 ;
};

__interface IWebActionsList;
typedef System::DelphiInterface<IWebActionsList> _di_IWebActionsList;
__interface INTERFACE_UUID("{CB84BC93-4C65-11D4-A48B-00C04F6BB853}") IWebActionsList  : public IInterface 
{
	
public:
	virtual void __fastcall GetActionsList(Classes::TStrings* AList) = 0 ;
	virtual Classes::TComponent* __fastcall FindAction(const AnsiString AName) = 0 ;
	virtual bool __fastcall IsActionInUse(const AnsiString AName) = 0 ;
	virtual Webcomp::TWebComponentList* __fastcall GetVisibleActions(void) = 0 ;
	__property Webcomp::TWebComponentList* VisibleActions = {read=GetVisibleActions};
};

__interface IWebDataFields;
typedef System::DelphiInterface<IWebDataFields> _di_IWebDataFields;
__interface INTERFACE_UUID("{D62DBBBD-2C40-11D4-A46E-00C04F6BB853}") IWebDataFields  : public IInterface 
{
	
public:
	virtual void __fastcall GetFieldsList(Classes::TStrings* AList) = 0 ;
	virtual bool __fastcall IsFieldInUse(const AnsiString AName) = 0 ;
	virtual Classes::TComponent* __fastcall FindField(const AnsiString AName) = 0 ;
	virtual Webcomp::TWebComponentList* __fastcall GetVisibleFields(void) = 0 ;
	__property Webcomp::TWebComponentList* VisibleFields = {read=GetVisibleFields};
};

__interface IWebGetFieldName;
typedef System::DelphiInterface<IWebGetFieldName> _di_IWebGetFieldName;
__interface INTERFACE_UUID("{D62DBBC0-2C40-11D4-A46E-00C04F6BB853}") IWebGetFieldName  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetFieldName(void) = 0 ;
	__property AnsiString FieldName = {read=GetFieldName};
};

__interface IWebSetFieldName;
typedef System::DelphiInterface<IWebSetFieldName> _di_IWebSetFieldName;
__interface INTERFACE_UUID("{CB84BC94-4C65-11D4-A48B-00C04F6BB853}") IWebSetFieldName  : public IInterface 
{
	
public:
	virtual void __fastcall SetFieldName(const AnsiString AFieldName) = 0 ;
};

__interface IWebGetActionName;
typedef System::DelphiInterface<IWebGetActionName> _di_IWebGetActionName;
__interface INTERFACE_UUID("{5DC620F7-C14A-4D49-868E-656041ADF017}") IWebGetActionName  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall GetActionName(void) = 0 ;
	__property AnsiString ActionName = {read=GetActionName};
};

__interface IWebSetActionName;
typedef System::DelphiInterface<IWebSetActionName> _di_IWebSetActionName;
__interface INTERFACE_UUID("{005FC2A6-92C1-4F7D-BC69-F4254672E6C0}") IWebSetActionName  : public IInterface 
{
	
public:
	virtual void __fastcall SetActionName(const AnsiString AFieldName) = 0 ;
};

#pragma option push -b-
enum TAdapterDisplayCharacteristic { dcMultipleRecordView, dcCurrentRecordView, dcChangeCurrentRecordView };
#pragma option pop

typedef Set<TAdapterDisplayCharacteristic, dcMultipleRecordView, dcChangeCurrentRecordView>  TAdapterDisplayCharacteristics;

__interface IGetAdapterDisplayCharacteristics;
typedef System::DelphiInterface<IGetAdapterDisplayCharacteristics> _di_IGetAdapterDisplayCharacteristics;
__interface INTERFACE_UUID("{CA500563-1298-400F-814D-DA836E08D8B4}") IGetAdapterDisplayCharacteristics  : public IInterface 
{
	
public:
	virtual TAdapterDisplayCharacteristics __fastcall GetAdapterDisplayCharacteristics(void) = 0 ;
};

#pragma option push -b-
enum TAdapterInputHTMLElementType { htmliNone, htmliTextInput, htmliPasswordInput, htmliSelect, htmliSelectMultiple, htmliRadio, htmliCheckBox, htmliTextArea, htmliFile };
#pragma option pop

#pragma option push -b-
enum TAdapterDisplayHTMLElementType { htmldText, htmldImage, htmldList, htmldNone };
#pragma option pop

#pragma option push -b-
enum TAdapterDisplayViewModeType { htmlvmInput, htmlvmDisplay, htmlvmToggleOnAccess, htmlvmNone };
#pragma option pop

#pragma option push -b-
enum TAdapterActionHTMLElementType { htmlaButton, htmlaImage, htmlaAnchor, htmlaEventImages };
#pragma option pop

class DELPHICLASS TNotifyList;
class PASCALIMPLEMENTATION TNotifyList : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	System::TObject* operator[](int Index) { return Items[Index]; }
	
private:
	Classes::TList* FList;
	
public:
	__fastcall TNotifyList(void);
	__fastcall virtual ~TNotifyList(void);
	System::TObject* __fastcall GetItem(int Index);
	int __fastcall GetCount(void);
	void __fastcall AddNotify(System::TObject* ANotify);
	void __fastcall RemoveNotify(System::TObject* ANotify);
	__property System::TObject* Items[int Index] = {read=GetItem/*, default*/};
	__property int Count = {read=GetCount, nodefault};
};


__interface IWebIsDefaultField;
typedef System::DelphiInterface<IWebIsDefaultField> _di_IWebIsDefaultField;
__interface INTERFACE_UUID("{A22A7CE1-AC68-4DD5-BE09-18CBBAB57890}") IWebIsDefaultField  : public IInterface 
{
	
public:
	virtual bool __fastcall IsDefaultField(System::TObject* ADisplay) = 0 ;
};

__interface IWebIsDefaultAction;
typedef System::DelphiInterface<IWebIsDefaultAction> _di_IWebIsDefaultAction;
__interface INTERFACE_UUID("{E9FD2BD8-CD66-4C91-96FE-8B59C7CD048F}") IWebIsDefaultAction  : public IInterface 
{
	
public:
	virtual bool __fastcall IsDefaultAction(System::TObject* ADisplay) = 0 ;
};

__interface IGetProducerComponent;
typedef System::DelphiInterface<IGetProducerComponent> _di_IGetProducerComponent;
__interface INTERFACE_UUID("{75E6B9BB-5AE1-45DB-BACA-314BBE845B4F}") IGetProducerComponent  : public IInterface 
{
	
public:
	virtual Classes::TComponent* __fastcall GetProducerComponent(void) = 0 ;
};

#pragma option push -b-
enum TQualifyOption { qaUseModulesVar, qaNoModulesVar, qaNoModuleName };
#pragma option pop

typedef AnsiString SiteComp__6[9];

typedef AnsiString SiteComp__7[4];

typedef AnsiString SiteComp__8[4];

typedef AnsiString SiteComp__9[4];

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString AdapterInputHTMLElementTypeNames[9];
extern PACKAGE AnsiString AdapterDisplayHTMLElementTypeNames[4];
extern PACKAGE AnsiString AdapterActionHTMLElementTypeNames[4];
extern PACKAGE AnsiString AdapterDisplayViewModeTypeNames[4];
extern PACKAGE _di_IInternetFileTypes InetFileTypes;
extern PACKAGE _di_IInternetScriptDebugger ScriptDebugger;
extern PACKAGE _di_IInternetEnvOptions InternetEnvOptions;
extern PACKAGE _di_IInternetExecuteScript ExecuteScript;
extern PACKAGE _di_IIDEFileManager IDEFileManager;
extern PACKAGE AnsiString __fastcall (*GetHTMLSampleImage)(void);
extern PACKAGE AnsiString __fastcall FullyQualifiedName(Classes::TComponent* AComponent, TQualifyOption AOption);
extern PACKAGE AnsiString __fastcall FullyQualifiedFieldName(Classes::TComponent* AComponent);

}	/* namespace Sitecomp */
using namespace Sitecomp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SiteComp
