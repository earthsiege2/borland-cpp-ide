// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'HTTPApp.pas' rev: 6.00

#ifndef HTTPAppHPP
#define HTTPAppHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Contnrs.hpp>	// Pascal unit
#include <Masks.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Httpapp
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TWebExceptionEvent)(System::TObject* Sender, Sysutils::Exception* E, bool &Handled);

#pragma option push -b-
enum TMethodType { mtAny, mtGet, mtPut, mtPost, mtHead };
#pragma option pop

class DELPHICLASS TWebRequest;
class DELPHICLASS TAbstractContentParser;
class DELPHICLASS TAbstractWebRequestFiles;
class PASCALIMPLEMENTATION TAbstractContentParser : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TWebRequest* FWebRequest;
	
protected:
	__property TWebRequest* WebRequest = {read=FWebRequest};
	virtual Classes::TStrings* __fastcall GetContentFields(void) = 0 ;
	virtual TAbstractWebRequestFiles* __fastcall GetFiles(void) = 0 ;
	
public:
	__fastcall virtual TAbstractContentParser(TWebRequest* AWebRequest);
	/* virtual class method */ virtual bool __fastcall CanParse(TMetaClass* vmt, TWebRequest* AWebRequest);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractContentParser(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TWebRequest : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TAbstractContentParser* FContentParser;
	TMethodType FMethodType;
	Classes::TStrings* FContentFields;
	Classes::TStrings* FCookieFields;
	Classes::TStrings* FQueryFields;
	TAbstractContentParser* __fastcall GetContentParser(void);
	Classes::TStrings* __fastcall GetContentFields(void);
	Classes::TStrings* __fastcall GetCookieFields(void);
	Classes::TStrings* __fastcall GetQueryFields(void);
	TAbstractWebRequestFiles* __fastcall GetFiles(void);
	
protected:
	virtual AnsiString __fastcall GetStringVariable(int Index) = 0 ;
	virtual System::TDateTime __fastcall GetDateVariable(int Index) = 0 ;
	virtual int __fastcall GetIntegerVariable(int Index) = 0 ;
	virtual AnsiString __fastcall GetInternalPathInfo();
	virtual AnsiString __fastcall GetInternalScriptName();
	void __fastcall UpdateMethodType(void);
	
public:
	__fastcall TWebRequest(void);
	__fastcall virtual ~TWebRequest(void);
	virtual int __fastcall ReadClient(void *Buffer, int Count) = 0 ;
	virtual AnsiString __fastcall ReadString(int Count) = 0 ;
	virtual AnsiString __fastcall TranslateURI(const AnsiString URI) = 0 ;
	virtual int __fastcall WriteClient(void *Buffer, int Count) = 0 ;
	virtual bool __fastcall WriteString(const AnsiString AString) = 0 ;
	virtual bool __fastcall WriteHeaders(int StatusCode, const AnsiString ReasonString, const AnsiString Headers) = 0 ;
	void __fastcall ExtractFields(const Sysutils::TSysCharSet &Separators, const Sysutils::TSysCharSet &WhiteSpace, char * Content, Classes::TStrings* Strings);
	void __fastcall ExtractContentFields(Classes::TStrings* Strings);
	void __fastcall ExtractCookieFields(Classes::TStrings* Strings);
	void __fastcall ExtractQueryFields(Classes::TStrings* Strings);
	virtual AnsiString __fastcall GetFieldByName(const AnsiString Name) = 0 ;
	__property TMethodType MethodType = {read=FMethodType, nodefault};
	__property TAbstractContentParser* ContentParser = {read=GetContentParser};
	__property Classes::TStrings* ContentFields = {read=GetContentFields};
	__property Classes::TStrings* CookieFields = {read=GetCookieFields};
	__property Classes::TStrings* QueryFields = {read=GetQueryFields};
	__property AnsiString Method = {read=GetStringVariable, index=0};
	__property AnsiString ProtocolVersion = {read=GetStringVariable, index=1};
	__property AnsiString URL = {read=GetStringVariable, index=2};
	__property AnsiString Query = {read=GetStringVariable, index=3};
	__property AnsiString PathInfo = {read=GetStringVariable, index=4};
	__property AnsiString PathTranslated = {read=GetStringVariable, index=5};
	__property AnsiString Authorization = {read=GetStringVariable, index=28};
	__property AnsiString CacheControl = {read=GetStringVariable, index=6};
	__property AnsiString Cookie = {read=GetStringVariable, index=27};
	__property System::TDateTime Date = {read=GetDateVariable, index=7};
	__property AnsiString Accept = {read=GetStringVariable, index=8};
	__property AnsiString From = {read=GetStringVariable, index=9};
	__property AnsiString Host = {read=GetStringVariable, index=10};
	__property System::TDateTime IfModifiedSince = {read=GetDateVariable, index=11};
	__property AnsiString Referer = {read=GetStringVariable, index=12};
	__property AnsiString UserAgent = {read=GetStringVariable, index=13};
	__property AnsiString ContentEncoding = {read=GetStringVariable, index=14};
	__property AnsiString ContentType = {read=GetStringVariable, index=15};
	__property int ContentLength = {read=GetIntegerVariable, index=16, nodefault};
	__property AnsiString ContentVersion = {read=GetStringVariable, index=17};
	__property AnsiString Content = {read=GetStringVariable, index=25};
	__property AnsiString Connection = {read=GetStringVariable, index=26};
	__property AnsiString DerivedFrom = {read=GetStringVariable, index=18};
	__property System::TDateTime Expires = {read=GetDateVariable, index=19};
	__property AnsiString Title = {read=GetStringVariable, index=20};
	__property AnsiString RemoteAddr = {read=GetStringVariable, index=21};
	__property AnsiString RemoteHost = {read=GetStringVariable, index=22};
	__property AnsiString ScriptName = {read=GetStringVariable, index=23};
	__property int ServerPort = {read=GetIntegerVariable, index=24, nodefault};
	__property AnsiString InternalPathInfo = {read=GetInternalPathInfo};
	__property AnsiString InternalScriptName = {read=GetInternalScriptName};
	__property TAbstractWebRequestFiles* Files = {read=GetFiles};
};


class DELPHICLASS TContentParser;
class PASCALIMPLEMENTATION TContentParser : public TAbstractContentParser 
{
	typedef TAbstractContentParser inherited;
	
private:
	Classes::TStrings* FContentFields;
	TAbstractWebRequestFiles* FFiles;
	
public:
	__fastcall virtual ~TContentParser(void);
	virtual Classes::TStrings* __fastcall GetContentFields(void);
	virtual TAbstractWebRequestFiles* __fastcall GetFiles(void);
	/* virtual class method */ virtual bool __fastcall CanParse(TMetaClass* vmt, TWebRequest* AWebRequest);
public:
	#pragma option push -w-inl
	/* TAbstractContentParser.Create */ inline __fastcall virtual TContentParser(TWebRequest* AWebRequest) : TAbstractContentParser(AWebRequest) { }
	#pragma option pop
	
};


typedef TMetaClass*TContentParserClass;

class DELPHICLASS TAbstractWebRequestFile;
class PASCALIMPLEMENTATION TAbstractWebRequestFiles : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TAbstractWebRequestFile* operator[](int I) { return Items[I]; }
	
protected:
	virtual int __fastcall GetCount(void) = 0 ;
	virtual TAbstractWebRequestFile* __fastcall GetItem(int I) = 0 ;
	
public:
	__property TAbstractWebRequestFile* Items[int I] = {read=GetItem/*, default*/};
	__property int Count = {read=GetCount, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TAbstractWebRequestFiles(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractWebRequestFiles(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TAbstractWebRequestFile : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	virtual AnsiString __fastcall GetFieldName(void) = 0 ;
	virtual AnsiString __fastcall GetFileName(void) = 0 ;
	virtual Classes::TStream* __fastcall GetStream(void) = 0 ;
	virtual AnsiString __fastcall GetContentType(void) = 0 ;
	
public:
	__property AnsiString FieldName = {read=GetFieldName};
	__property AnsiString FileName = {read=GetFileName};
	__property Classes::TStream* Stream = {read=GetStream};
	__property AnsiString ContentType = {read=GetContentType};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TAbstractWebRequestFile(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractWebRequestFile(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCookie;
class PASCALIMPLEMENTATION TCookie : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	AnsiString FName;
	AnsiString FValue;
	AnsiString FPath;
	AnsiString FDomain;
	System::TDateTime FExpires;
	bool FSecure;
	
protected:
	AnsiString __fastcall GetHeaderValue();
	
public:
	__fastcall virtual TCookie(Classes::TCollection* Collection);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	__property AnsiString Name = {read=FName, write=FName};
	__property AnsiString Value = {read=FValue, write=FValue};
	__property AnsiString Domain = {read=FDomain, write=FDomain};
	__property AnsiString Path = {read=FPath, write=FPath};
	__property System::TDateTime Expires = {read=FExpires, write=FExpires};
	__property bool Secure = {read=FSecure, write=FSecure, nodefault};
	__property AnsiString HeaderValue = {read=GetHeaderValue};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TCookie(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCookieCollection;
class DELPHICLASS TWebResponse;
class PASCALIMPLEMENTATION TWebResponse : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TStream* FContentStream;
	TCookieCollection* FCookies;
	void __fastcall SetCustomHeaders(Classes::TStrings* Value);
	
protected:
	TWebRequest* FHTTPRequest;
	Classes::TStrings* FCustomHeaders;
	void __fastcall AddCustomHeaders(AnsiString &Headers);
	virtual AnsiString __fastcall GetStringVariable(int Index) = 0 ;
	virtual void __fastcall SetStringVariable(int Index, const AnsiString Value) = 0 ;
	virtual System::TDateTime __fastcall GetDateVariable(int Index) = 0 ;
	virtual void __fastcall SetDateVariable(int Index, const System::TDateTime Value) = 0 ;
	virtual int __fastcall GetIntegerVariable(int Index) = 0 ;
	virtual void __fastcall SetIntegerVariable(int Index, int Value) = 0 ;
	virtual AnsiString __fastcall GetContent(void) = 0 ;
	virtual void __fastcall SetContent(const AnsiString Value) = 0 ;
	virtual void __fastcall SetContentStream(Classes::TStream* Value);
	virtual int __fastcall GetStatusCode(void) = 0 ;
	virtual void __fastcall SetStatusCode(int Value) = 0 ;
	virtual AnsiString __fastcall GetLogMessage(void) = 0 ;
	virtual void __fastcall SetLogMessage(const AnsiString Value) = 0 ;
	
public:
	__fastcall TWebResponse(TWebRequest* HTTPRequest);
	__fastcall virtual ~TWebResponse(void);
	AnsiString __fastcall GetCustomHeader(const AnsiString Name);
	virtual void __fastcall SendResponse(void) = 0 ;
	virtual void __fastcall SendRedirect(const AnsiString URI) = 0 ;
	virtual void __fastcall SendStream(Classes::TStream* AStream) = 0 ;
	virtual bool __fastcall Sent(void);
	void __fastcall SetCookieField(Classes::TStrings* Values, const AnsiString ADomain, const AnsiString APath, System::TDateTime AExpires, bool ASecure);
	void __fastcall SetCustomHeader(const AnsiString Name, const AnsiString Value);
	__property TCookieCollection* Cookies = {read=FCookies};
	__property TWebRequest* HTTPRequest = {read=FHTTPRequest};
	__property AnsiString Version = {read=GetStringVariable, write=SetStringVariable, index=0};
	__property AnsiString ReasonString = {read=GetStringVariable, write=SetStringVariable, index=1};
	__property AnsiString Server = {read=GetStringVariable, write=SetStringVariable, index=2};
	__property AnsiString WWWAuthenticate = {read=GetStringVariable, write=SetStringVariable, index=3};
	__property AnsiString Realm = {read=GetStringVariable, write=SetStringVariable, index=4};
	__property AnsiString Allow = {read=GetStringVariable, write=SetStringVariable, index=5};
	__property AnsiString Location = {read=GetStringVariable, write=SetStringVariable, index=6};
	__property AnsiString ContentEncoding = {read=GetStringVariable, write=SetStringVariable, index=7};
	__property AnsiString ContentType = {read=GetStringVariable, write=SetStringVariable, index=8};
	__property AnsiString ContentVersion = {read=GetStringVariable, write=SetStringVariable, index=9};
	__property AnsiString DerivedFrom = {read=GetStringVariable, write=SetStringVariable, index=10};
	__property AnsiString Title = {read=GetStringVariable, write=SetStringVariable, index=11};
	__property int StatusCode = {read=GetStatusCode, write=SetStatusCode, nodefault};
	__property int ContentLength = {read=GetIntegerVariable, write=SetIntegerVariable, index=0, nodefault};
	__property System::TDateTime Date = {read=GetDateVariable, write=SetDateVariable, index=0};
	__property System::TDateTime Expires = {read=GetDateVariable, write=SetDateVariable, index=1};
	__property System::TDateTime LastModified = {read=GetDateVariable, write=SetDateVariable, index=2};
	__property AnsiString Content = {read=GetContent, write=SetContent};
	__property Classes::TStream* ContentStream = {read=FContentStream, write=SetContentStream};
	__property AnsiString LogMessage = {read=GetLogMessage, write=SetLogMessage};
	__property Classes::TStrings* CustomHeaders = {read=FCustomHeaders, write=SetCustomHeaders};
};


class PASCALIMPLEMENTATION TCookieCollection : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
public:
	TCookie* operator[](int Index) { return Items[Index]; }
	
private:
	TWebResponse* FWebResponse;
	
protected:
	TCookie* __fastcall GetCookie(int Index);
	void __fastcall SetCookie(int Index, TCookie* Cookie);
	
public:
	__fastcall TCookieCollection(TWebResponse* WebResponse, TMetaClass* ItemClass);
	HIDESBASE TCookie* __fastcall Add(void);
	__property TWebResponse* WebResponse = {read=FWebResponse};
	__property TCookie* Items[int Index] = {read=GetCookie, write=SetCookie/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TCookieCollection(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAbstractWebSession;
class PASCALIMPLEMENTATION TAbstractWebSession : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	virtual Variant __fastcall GetValue(const AnsiString AName) = 0 ;
	virtual void __fastcall SetValue(const AnsiString AName, const Variant &AValue) = 0 ;
	virtual int __fastcall GetTimeoutMinutes(void) = 0 ;
	virtual void __fastcall SetTimeoutMinutes(int AValue) = 0 ;
	virtual AnsiString __fastcall GetSessionID(void) = 0 ;
	
public:
	virtual void __fastcall UpdateResponse(TWebResponse* AResponse) = 0 ;
	virtual void __fastcall Terminate(void) = 0 ;
	__property int TimeoutMinutes = {read=GetTimeoutMinutes, write=SetTimeoutMinutes, nodefault};
	__property Variant Values[AnsiString AName] = {read=GetValue, write=SetValue};
	__property AnsiString SessionID = {read=GetSessionID};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TAbstractWebSession(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractWebSession(void) { }
	#pragma option pop
	
};


__interface ISetAppDispatcher;
typedef System::DelphiInterface<ISetAppDispatcher> _di_ISetAppDispatcher;
__interface INTERFACE_UUID("{2F5E959E-DA65-11D3-A411-00C04F6BB853}") ISetAppDispatcher  : public IInterface 
{
	
public:
	virtual void __fastcall SetAppDispatcher(const Classes::TComponent* ADispatcher) = 0 ;
};

__interface IGetAppDispatcher;
typedef System::DelphiInterface<IGetAppDispatcher> _di_IGetAppDispatcher;
__interface INTERFACE_UUID("{2BF38474-E821-11D4-A54A-00C04F6BB853}") IGetAppDispatcher  : public IInterface 
{
	
public:
	virtual Classes::TComponent* __fastcall GetAppDispatcher(void) = 0 ;
};

__interface IProduceContent;
typedef System::DelphiInterface<IProduceContent> _di_IProduceContent;
__interface INTERFACE_UUID("{AAFA17B7-E814-11D4-A54A-00C04F6BB853}") IProduceContent  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall ProduceContent(void) = 0 ;
};

__interface IProduceContentFrom;
typedef System::DelphiInterface<IProduceContentFrom> _di_IProduceContentFrom;
__interface INTERFACE_UUID("{AA0CC875-E81B-11D4-A54A-00C04F6BB853}") IProduceContentFrom  : public IInterface 
{
	
public:
	virtual AnsiString __fastcall ProduceContentFromStream(Classes::TStream* Stream) = 0 ;
	virtual AnsiString __fastcall ProduceContentFromString(const AnsiString S) = 0 ;
};

__interface IMultiModuleSupport;
typedef System::DelphiInterface<IMultiModuleSupport> _di_IMultiModuleSupport;
__interface INTERFACE_UUID("{06F13260-8FF8-11D4-A4E5-00C04F6BB853}") IMultiModuleSupport  : public IInterface 
{
	
public:
	virtual void __fastcall InitContext(TWebRequest* Request, TWebResponse* Response) = 0 ;
	virtual void __fastcall InitModule(Classes::TComponent* AModule) = 0 ;
	virtual void __fastcall FinishContext(void) = 0 ;
};

__interface IWebAppServices;
typedef System::DelphiInterface<IWebAppServices> _di_IWebAppServices;
class DELPHICLASS TAbstractWebModuleList;
__interface INTERFACE_UUID("{D62F1586-E307-11D3-A418-00C04F6BB853}") IWebAppServices  : public IInterface 
{
	
public:
	virtual void __fastcall InitContext(TAbstractWebModuleList* WebModuleList, TWebRequest* Request, TWebResponse* Response) = 0 ;
	virtual bool __fastcall HandleRequest(void) = 0 ;
	virtual void __fastcall FinishContext(void) = 0 ;
	virtual System::TObject* __fastcall GetExceptionHandler(void) = 0 ;
	__property System::TObject* ExceptionHandler = {read=GetExceptionHandler};
};

__interface IWebExceptionHandler;
typedef System::DelphiInterface<IWebExceptionHandler> _di_IWebExceptionHandler;
__interface INTERFACE_UUID("{7664268F-9629-11D4-A4EC-00C04F6BB853}") IWebExceptionHandler  : public IInterface 
{
	
public:
	virtual void __fastcall HandleException(Sysutils::Exception* E, bool &Handled) = 0 ;
};

__interface IGetWebAppServices;
typedef System::DelphiInterface<IGetWebAppServices> _di_IGetWebAppServices;
__interface INTERFACE_UUID("{0BA86C6E-8E85-11D4-A4E3-00C04F6BB853}") IGetWebAppServices  : public IInterface 
{
	
public:
	virtual _di_IWebAppServices __fastcall GetWebAppServices(void) = 0 ;
};

__interface IWebRequestHandler;
typedef System::DelphiInterface<IWebRequestHandler> _di_IWebRequestHandler;
__interface INTERFACE_UUID("{6FCCB05F-8FE0-11D4-A4E5-00C04F6BB853}") IWebRequestHandler  : public IInterface 
{
	
public:
	virtual bool __fastcall HandleRequest(TWebRequest* Request, TWebResponse* Response) = 0 ;
};

__interface IWebDispatchActions;
typedef System::DelphiInterface<IWebDispatchActions> _di_IWebDispatchActions;
__interface INTERFACE_UUID("{C6E0CEA2-9483-4DCD-B75C-FFAE749729EC}") IWebDispatchActions  : public IInterface 
{
	
};

__interface IGetWebRequestHandler;
typedef System::DelphiInterface<IGetWebRequestHandler> _di_IGetWebRequestHandler;
__interface INTERFACE_UUID("{6FCCB060-8FE0-11D4-A4E5-00C04F6BB853}") IGetWebRequestHandler  : public IInterface 
{
	
public:
	virtual _di_IWebRequestHandler __fastcall GetWebRequestHandler(void) = 0 ;
};

__interface IWebDispatcherAccess;
typedef System::DelphiInterface<IWebDispatcherAccess> _di_IWebDispatcherAccess;
__interface INTERFACE_UUID("{BD6000E1-177A-11D4-ABF9-C3E8C8ACE95A}") IWebDispatcherAccess  : public IInterface 
{
	
public:
	virtual TWebRequest* __fastcall Request(void) = 0 ;
	virtual TWebResponse* __fastcall Response(void) = 0 ;
};

class DELPHICLASS TCustomContentProducer;
class PASCALIMPLEMENTATION TCustomContentProducer : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Classes::TComponent* FDispatcher;
	_di_IWebDispatcherAccess __fastcall GetDispatcher();
	void __fastcall SetDispatcher(Classes::TComponent* Value);
	
protected:
	AnsiString __fastcall ProduceContent();
	AnsiString __fastcall ProduceContentFromStream(Classes::TStream* Stream);
	AnsiString __fastcall ProduceContentFromString(const AnsiString S);
	void __fastcall SetAppDispatcher(const Classes::TComponent* ADispatcher);
	Classes::TComponent* __fastcall GetAppDispatcher(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	virtual AnsiString __fastcall Content();
	virtual AnsiString __fastcall ContentFromStream(Classes::TStream* Stream);
	virtual AnsiString __fastcall ContentFromString(const AnsiString S);
	__property _di_IWebDispatcherAccess Dispatcher = {read=GetDispatcher};
	__property Classes::TComponent* DispatcherComponent = {read=FDispatcher};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TCustomContentProducer(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCustomContentProducer(void) { }
	#pragma option pop
	
private:
	void *__ISetAppDispatcher;	/* Httpapp::ISetAppDispatcher */
	void *__IGetAppDispatcher;	/* Httpapp::IGetAppDispatcher */
	void *__IProduceContent;	/* Httpapp::IProduceContent */
	void *__IProduceContentFrom;	/* Httpapp::IProduceContentFrom */
	
public:
	operator IProduceContentFrom*(void) { return (IProduceContentFrom*)&__IProduceContentFrom; }
	operator IProduceContent*(void) { return (IProduceContent*)&__IProduceContent; }
	operator IGetAppDispatcher*(void) { return (IGetAppDispatcher*)&__IGetAppDispatcher; }
	operator ISetAppDispatcher*(void) { return (ISetAppDispatcher*)&__ISetAppDispatcher; }
	
};


typedef void __fastcall (__closure *THTTPMethodEvent)(System::TObject* Sender, TWebRequest* Request, TWebResponse* Response, bool &Handled);

class DELPHICLASS TWebActionItem;
class PASCALIMPLEMENTATION TWebActionItem : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	THTTPMethodEvent FOnAction;
	AnsiString FPathInfo;
	TMethodType FMethodType;
	bool FDefault;
	bool FEnabled;
	AnsiString FMaskPathInfo;
	Masks::TMask* FMask;
	AnsiString FName;
	TCustomContentProducer* FProducer;
	Classes::TComponent* FProducerContent;
	bool __fastcall DispatchAction(TWebRequest* Request, TWebResponse* Response, bool DoDefault);
	void __fastcall SetDefault(bool Value);
	void __fastcall SetEnabled(bool Value);
	void __fastcall SetMethodType(TMethodType Value);
	void __fastcall SetOnAction(THTTPMethodEvent Value);
	void __fastcall SetPathInfo(const AnsiString Value);
	void __fastcall SetProducer(const TCustomContentProducer* Value);
	Masks::TMask* __fastcall GetMask(void);
	AnsiString __fastcall ProducerPathInfo();
	void __fastcall SetProducerContent(const Classes::TComponent* Value);
	
protected:
	virtual AnsiString __fastcall GetDisplayName();
	virtual void __fastcall SetDisplayName(const AnsiString Value);
	AnsiString __fastcall GetPathInfo();
	
public:
	__fastcall virtual TWebActionItem(Classes::TCollection* Collection);
	__fastcall virtual ~TWebActionItem(void);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
__published:
	__property bool Default = {read=FDefault, write=SetDefault, default=0};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property TMethodType MethodType = {read=FMethodType, write=SetMethodType, default=0};
	__property AnsiString Name = {read=GetDisplayName, write=SetDisplayName};
	__property AnsiString PathInfo = {read=GetPathInfo, write=SetPathInfo};
	__property TCustomContentProducer* Producer = {read=FProducer, write=SetProducer};
	__property Classes::TComponent* ProducerContent = {read=FProducerContent, write=SetProducerContent};
	__property THTTPMethodEvent OnAction = {read=FOnAction, write=SetOnAction};
};


class DELPHICLASS TWebActionItems;
class DELPHICLASS TCustomWebDispatcher;
class PASCALIMPLEMENTATION TCustomWebDispatcher : public Classes::TDataModule 
{
	typedef Classes::TDataModule inherited;
	
private:
	TWebRequest* FRequest;
	TWebResponse* FResponse;
	TWebActionItems* FActions;
	THTTPMethodEvent FBeforeDispatch;
	THTTPMethodEvent FAfterDispatch;
	Contnrs::TComponentList* FDispatchList;
	TWebExceptionEvent FOnException;
	TWebActionItem* __fastcall GetAction(int Index);
	void __fastcall SetActions(TWebActionItems* Value);
	TWebRequest* __fastcall GetRequest(void);
	TWebResponse* __fastcall GetResponse(void);
	
protected:
	bool __fastcall HandleRequest(TWebRequest* Request, TWebResponse* Response);
	void __fastcall InitContext(TWebRequest* Request, TWebResponse* Response);
	void __fastcall InitModule(Classes::TComponent* AModule);
	void __fastcall FinishContext(void);
	TWebRequest* __fastcall Access_Request(void);
	TWebResponse* __fastcall Access_Response(void);
	void __fastcall HandleException(Sysutils::Exception* E, bool &Handled);
	bool __fastcall DoAfterDispatch(TWebRequest* Request, TWebResponse* Response);
	bool __fastcall DoBeforeDispatch(TWebRequest* Request, TWebResponse* Response);
	bool __fastcall DispatchAction(TWebRequest* Request, TWebResponse* Response);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	__property THTTPMethodEvent BeforeDispatch = {read=FBeforeDispatch, write=FBeforeDispatch};
	__property THTTPMethodEvent AfterDispatch = {read=FAfterDispatch, write=FAfterDispatch};
	
public:
	__fastcall virtual TCustomWebDispatcher(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomWebDispatcher(void);
	TWebActionItem* __fastcall ActionByName(const AnsiString AName);
	__property TWebActionItems* Actions = {read=FActions, write=SetActions};
	__property TWebActionItem* Action[int Index] = {read=GetAction};
	__property TWebRequest* Request = {read=GetRequest};
	__property TWebResponse* Response = {read=GetResponse};
	__property TWebExceptionEvent OnException = {read=FOnException, write=FOnException};
public:
	#pragma option push -w-inl
	/* TDataModule.CreateNew */ inline __fastcall virtual TCustomWebDispatcher(Classes::TComponent* AOwner, int Dummy) : Classes::TDataModule(AOwner, Dummy) { }
	#pragma option pop
	
private:
	void *__IWebRequestHandler;	/* Httpapp::IWebRequestHandler */
	void *__IWebDispatchActions;	/* Httpapp::IWebDispatchActions */
	void *__IWebDispatcherAccess;	/* Httpapp::IWebDispatcherAccess [Response=Access_Response, Request=Access_Request] */
	void *__IMultiModuleSupport;	/* Httpapp::IMultiModuleSupport */
	void *__IWebExceptionHandler;	/* Httpapp::IWebExceptionHandler */
	
public:
	operator IWebExceptionHandler*(void) { return (IWebExceptionHandler*)&__IWebExceptionHandler; }
	operator IMultiModuleSupport*(void) { return (IMultiModuleSupport*)&__IMultiModuleSupport; }
	operator IWebDispatcherAccess*(void) { return (IWebDispatcherAccess*)&__IWebDispatcherAccess; }
	operator IWebDispatchActions*(void) { return (IWebDispatchActions*)&__IWebDispatchActions; }
	operator IWebRequestHandler*(void) { return (IWebRequestHandler*)&__IWebRequestHandler; }
	
};


class PASCALIMPLEMENTATION TWebActionItems : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
public:
	TWebActionItem* operator[](int Index) { return Items[Index]; }
	
private:
	TCustomWebDispatcher* FWebDispatcher;
	TWebActionItem* __fastcall GetActionItem(int Index);
	void __fastcall SetActionItem(int Index, TWebActionItem* Value);
	
protected:
	DYNAMIC int __fastcall GetAttrCount(void);
	DYNAMIC AnsiString __fastcall GetAttr(int Index);
	DYNAMIC AnsiString __fastcall GetItemAttr(int Index, int ItemIndex);
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall SetItemName(Classes::TCollectionItem* Item);
	virtual void __fastcall Update(Classes::TCollectionItem* Item);
	
public:
	__fastcall TWebActionItems(TCustomWebDispatcher* WebDispatcher, TMetaClass* ItemClass);
	HIDESBASE TWebActionItem* __fastcall Add(void);
	__property TCustomWebDispatcher* WebDispatcher = {read=FWebDispatcher};
	__property TWebActionItem* Items[int Index] = {read=GetActionItem, write=SetActionItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TWebActionItems(void) { }
	#pragma option pop
	
};


__interface IWebDispatch;
typedef System::DelphiInterface<IWebDispatch> _di_IWebDispatch;
__interface INTERFACE_UUID("{F358F272-DB6D-11D2-AA3F-00A024C11562}") IWebDispatch  : public IInterface 
{
	
public:
	virtual bool __fastcall DispatchEnabled(void) = 0 ;
	virtual TMethodType __fastcall DispatchMethodType(void) = 0 ;
	virtual bool __fastcall DispatchRequest(System::TObject* Sender, TWebRequest* Request, TWebResponse* Response) = 0 ;
	virtual Masks::TMask* __fastcall DispatchMask(void) = 0 ;
	__property bool Enabled = {read=DispatchEnabled};
	__property TMethodType MethodType = {read=DispatchMethodType};
	__property Masks::TMask* Mask = {read=DispatchMask};
};

class DELPHICLASS TWebDispatcher;
class PASCALIMPLEMENTATION TWebDispatcher : public TCustomWebDispatcher 
{
	typedef TCustomWebDispatcher inherited;
	
__published:
	__property Actions ;
	__property BeforeDispatch ;
	__property AfterDispatch ;
	__property OnException ;
public:
	#pragma option push -w-inl
	/* TCustomWebDispatcher.Create */ inline __fastcall virtual TWebDispatcher(Classes::TComponent* AOwner) : TCustomWebDispatcher(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomWebDispatcher.Destroy */ inline __fastcall virtual ~TWebDispatcher(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TDataModule.CreateNew */ inline __fastcall virtual TWebDispatcher(Classes::TComponent* AOwner, int Dummy) : TCustomWebDispatcher(AOwner, Dummy) { }
	#pragma option pop
	
};


typedef TObject TWebModuleContext;
;

class DELPHICLASS TWebModule;
class PASCALIMPLEMENTATION TWebModule : public TCustomWebDispatcher 
{
	typedef TCustomWebDispatcher inherited;
	
public:
	__fastcall virtual TWebModule(Classes::TComponent* AOwner);
	
__published:
	__property Actions ;
	__property BeforeDispatch ;
	__property AfterDispatch ;
	__property OnException ;
public:
	#pragma option push -w-inl
	/* TCustomWebDispatcher.Destroy */ inline __fastcall virtual ~TWebModule(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TDataModule.CreateNew */ inline __fastcall virtual TWebModule(Classes::TComponent* AOwner, int Dummy) : TCustomWebDispatcher(AOwner, Dummy) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TWebModuleCreateMode { crOnDemand, crAlways };
#pragma option pop

#pragma option push -b-
enum TWebModuleCacheMode { caCache, caDestroy };
#pragma option pop

class DELPHICLASS TAbstractWebModuleFactory;
class DELPHICLASS TAbstractWebPageInfo;
class PASCALIMPLEMENTATION TAbstractWebModuleFactory : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	virtual AnsiString __fastcall GetModuleName(void) = 0 ;
	virtual bool __fastcall GetIsAppModule(void) = 0 ;
	virtual TWebModuleCreateMode __fastcall GetCreateMode(void) = 0 ;
	virtual TWebModuleCacheMode __fastcall GetCacheMode(void) = 0 ;
	virtual TMetaClass* __fastcall GetComponentClass(void) = 0 ;
	virtual TAbstractWebPageInfo* __fastcall GetWebPageInfo(void);
	
public:
	virtual Classes::TComponent* __fastcall GetModule(void) = 0 ;
	virtual void __fastcall PreventDestruction(void) = 0 ;
	__property AnsiString ModuleName = {read=GetModuleName};
	__property bool IsAppModule = {read=GetIsAppModule, nodefault};
	__property TMetaClass* ComponentClass = {read=GetComponentClass};
	__property TWebModuleCreateMode CreateMode = {read=GetCreateMode, nodefault};
	__property TWebModuleCacheMode CacheMode = {read=GetCacheMode, nodefault};
	__property TAbstractWebPageInfo* WebPageInfo = {read=GetWebPageInfo};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TAbstractWebModuleFactory(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractWebModuleFactory(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAbstractWebPageModuleFactory;
class PASCALIMPLEMENTATION TAbstractWebPageModuleFactory : public TAbstractWebModuleFactory 
{
	typedef TAbstractWebModuleFactory inherited;
	
private:
	TAbstractWebPageInfo* FWebPageInfo;
	
protected:
	virtual TAbstractWebPageInfo* __fastcall GetWebPageInfo(void);
	
public:
	__fastcall TAbstractWebPageModuleFactory(TAbstractWebPageInfo* AWebPageInfo);
	__fastcall virtual ~TAbstractWebPageModuleFactory(void);
};


class PASCALIMPLEMENTATION TAbstractWebPageInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TAbstractWebPageModuleFactory* FFactory;
	
protected:
	virtual AnsiString __fastcall GetPageFile(void) = 0 ;
	virtual AnsiString __fastcall GetPageHREF();
	virtual AnsiString __fastcall GetPageName(void) = 0 ;
	virtual AnsiString __fastcall GetPageDescription();
	virtual AnsiString __fastcall GetPageTitle();
	virtual bool __fastcall GetIsPublished(void);
	virtual bool __fastcall GetIsLoginRequired(void);
	virtual AnsiString __fastcall GetViewAccess();
	TAbstractWebPageModuleFactory* __fastcall GetFactory(void);
	virtual void __fastcall SetFactory(TAbstractWebPageModuleFactory* AFactory);
	
public:
	__property AnsiString PageHREF = {read=GetPageHREF};
	__property AnsiString PageDescription = {read=GetPageDescription};
	__property AnsiString PageTitle = {read=GetPageTitle};
	__property AnsiString PageName = {read=GetPageName};
	__property bool IsPublished = {read=GetIsPublished, nodefault};
	__property bool IsLoginRequired = {read=GetIsLoginRequired, nodefault};
	__property AnsiString PageFile = {read=GetPageFile};
	__property AnsiString ViewAccess = {read=GetViewAccess};
	__property TAbstractWebPageModuleFactory* Factory = {read=GetFactory, write=SetFactory};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TAbstractWebPageInfo(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractWebPageInfo(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TModuleAddedProc)(Classes::TComponent* AWebModule);

class PASCALIMPLEMENTATION TAbstractWebModuleList : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	Classes::TComponent* operator[](int I) { return Items[I]; }
	
protected:
	virtual Classes::TComponent* __fastcall GetItem(int I) = 0 ;
	virtual int __fastcall GetItemCount(void) = 0 ;
	virtual TModuleAddedProc __fastcall GetOnModuleAdded(void) = 0 ;
	virtual void __fastcall SetOnModuleAdded(TModuleAddedProc AProc) = 0 ;
	virtual int __fastcall GetFactoryCount(void) = 0 ;
	virtual TAbstractWebModuleFactory* __fastcall GetFactory(int I) = 0 ;
	
public:
	virtual Classes::TComponent* __fastcall FindModuleClass(TMetaClass* AClass) = 0 ;
	virtual Classes::TComponent* __fastcall FindModuleName(const AnsiString AClass) = 0 ;
	virtual Classes::TComponent* __fastcall AddModuleClass(TMetaClass* AClass) = 0 ;
	virtual Classes::TComponent* __fastcall AddModuleName(const AnsiString AClass) = 0 ;
	__property Classes::TComponent* Items[int I] = {read=GetItem/*, default*/};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property int FactoryCount = {read=GetFactoryCount, nodefault};
	__property TAbstractWebModuleFactory* Factory[int I] = {read=GetFactory};
	__property TModuleAddedProc OnModuleAdded = {read=GetOnModuleAdded, write=SetOnModuleAdded};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TAbstractWebModuleList(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractWebModuleList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDefaultWebAppServices;
class PASCALIMPLEMENTATION TDefaultWebAppServices : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	_di_IWebRequestHandler FRequestHandler;
	TWebRequest* FRequest;
	TAbstractWebModuleList* FWebModules;
	TWebResponse* FResponse;
	Classes::TComponent* __fastcall FindWebDispatcher(void);
	
protected:
	void __fastcall InitContext(TAbstractWebModuleList* WebModuleList, TWebRequest* Request, TWebResponse* Response);
	void __fastcall FinishContext(void);
	bool __fastcall HandleRequest(void);
	System::TObject* __fastcall GetExceptionHandler(void);
	bool __fastcall InvokeDispatcher(void);
	virtual _di_IWebRequestHandler __fastcall FindRequestHandler();
	_di_IWebRequestHandler __fastcall GetRequestHandler();
	__property TWebRequest* Request = {read=FRequest};
	__property TWebResponse* Response = {read=FResponse};
	__property TAbstractWebModuleList* WebModules = {read=FWebModules};
	__property _di_IWebRequestHandler RequestHandler = {read=GetRequestHandler};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TDefaultWebAppServices(void) : System::TInterfacedObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TDefaultWebAppServices(void) { }
	#pragma option pop
	
private:
	void *__IWebAppServices;	/* Httpapp::IWebAppServices */
	
public:
	operator IWebAppServices*(void) { return (IWebAppServices*)&__IWebAppServices; }
	
};


class DELPHICLASS EWebBrokerException;
class PASCALIMPLEMENTATION EWebBrokerException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EWebBrokerException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EWebBrokerException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EWebBrokerException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EWebBrokerException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EWebBrokerException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EWebBrokerException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EWebBrokerException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EWebBrokerException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EWebBrokerException(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define sDateFormat "\"%s\", dd \"%s\" yyyy hh:mm:ss"
static const Shortint MAX_STRINGS = 0xc;
static const Shortint MAX_INTEGERS = 0x1;
static const Shortint MAX_DATETIMES = 0x3;
extern PACKAGE void __fastcall RegisterContentParser(TMetaClass* AClass);
extern PACKAGE AnsiString __fastcall HTTPDecode(const AnsiString AStr);
extern PACKAGE AnsiString __fastcall HTTPEncode(const AnsiString AStr);
extern PACKAGE AnsiString __fastcall HTMLEncode(const AnsiString AStr);
extern PACKAGE AnsiString __fastcall HTMLDecode(const AnsiString AStr);
extern PACKAGE System::TDateTime __fastcall ParseDate(const AnsiString DateStr);
extern PACKAGE void __fastcall ExtractHeaderFields(const Sysutils::TSysCharSet &Separators, const Sysutils::TSysCharSet &WhiteSpace, char * Content, Classes::TStrings* Strings, bool Decode, bool StripQuotes = false);
extern PACKAGE void __fastcall ExtractHTTPFields(const Sysutils::TSysCharSet &Separators, const Sysutils::TSysCharSet &WhiteSpace, char * Content, Classes::TStrings* Strings, bool StripQuotes = false);
extern PACKAGE AnsiString __fastcall StatusString(int StatusCode);
extern PACKAGE AnsiString __fastcall UnixPathToDosPath(const AnsiString Path);
extern PACKAGE AnsiString __fastcall DosPathToUnixPath(const AnsiString Path);
extern PACKAGE AnsiString __fastcall MonthStr(System::TDateTime DateTime);
extern PACKAGE AnsiString __fastcall DayOfWeekStr(System::TDateTime DateTime);

}	/* namespace Httpapp */
using namespace Httpapp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// HTTPApp
