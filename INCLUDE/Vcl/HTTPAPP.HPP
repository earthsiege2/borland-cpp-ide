// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'HTTPApp.pas' rev: 5.00

#ifndef HTTPAppHPP
#define HTTPAppHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Contnrs.hpp>	// Pascal unit
#include <Masks.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SyncObjs.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Httpapp
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TMethodType { mtAny, mtGet, mtPut, mtPost, mtHead };
#pragma option pop

class DELPHICLASS TWebRequest;
class PASCALIMPLEMENTATION TWebRequest : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TMethodType FMethodType;
	Classes::TStrings* FContentFields;
	Classes::TStrings* FCookieFields;
	Classes::TStrings* FQueryFields;
	Classes::TStrings* __fastcall GetContentFields(void);
	Classes::TStrings* __fastcall GetCookieFields(void);
	Classes::TStrings* __fastcall GetQueryFields(void);
	
protected:
	virtual AnsiString __fastcall GetStringVariable(int Index) = 0 ;
	virtual System::TDateTime __fastcall GetDateVariable(int Index) = 0 ;
	virtual int __fastcall GetIntegerVariable(int Index) = 0 ;
	
public:
	__fastcall TWebRequest(void);
	__fastcall virtual ~TWebRequest(void);
	virtual int __fastcall ReadClient(void *Buffer, int Count) = 0 ;
	virtual AnsiString __fastcall ReadString(int Count) = 0 ;
	virtual AnsiString __fastcall TranslateURI(const AnsiString URI) = 0 ;
	virtual int __fastcall WriteClient(void *Buffer, int Count) = 0 ;
	virtual bool __fastcall WriteString(const AnsiString AString) = 0 ;
	void __fastcall ExtractFields(const Sysutils::TSysCharSet &Separators, const Sysutils::TSysCharSet 
		&WhiteSpace, char * Content, Classes::TStrings* Strings);
	void __fastcall ExtractContentFields(Classes::TStrings* Strings);
	void __fastcall ExtractCookieFields(Classes::TStrings* Strings);
	void __fastcall ExtractQueryFields(Classes::TStrings* Strings);
	virtual AnsiString __fastcall GetFieldByName(const AnsiString Name) = 0 ;
	__property TMethodType MethodType = {read=FMethodType, nodefault};
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
	Classes::TStrings* FCustomHeaders;
	TCookieCollection* FCookies;
	void __fastcall SetCustomHeaders(Classes::TStrings* Value);
	
protected:
	TWebRequest* FHTTPRequest;
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
	void __fastcall SetCookieField(Classes::TStrings* Values, const AnsiString ADomain, const AnsiString 
		APath, System::TDateTime AExpires, bool ASecure);
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
	__property int ContentLength = {read=GetIntegerVariable, write=SetIntegerVariable, index=0, nodefault
		};
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


#pragma option push -b-
enum THTMLAlign { haDefault, haLeft, haRight, haCenter };
#pragma option pop

#pragma option push -b-
enum THTMLVAlign { haVDefault, haTop, haMiddle, haBottom, haBaseline };
#pragma option pop

typedef AnsiString THTMLBgColor;

class DELPHICLASS THTMLTagAttributes;
class DELPHICLASS TCustomContentProducer;
class DELPHICLASS TCustomWebDispatcher;
class DELPHICLASS TWebActionItems;
class DELPHICLASS TWebActionItem;
class PASCALIMPLEMENTATION TWebActionItems : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
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
	__property TWebActionItem* Items[int Index] = {read=GetActionItem, write=SetActionItem/*, default*/
		};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TWebActionItems(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *THTTPMethodEvent)(System::TObject* Sender, TWebRequest* Request, 
	TWebResponse* Response, bool &Handled);

class PASCALIMPLEMENTATION TCustomWebDispatcher : public Forms::TDataModule 
{
	typedef Forms::TDataModule inherited;
	
private:
	TWebRequest* FRequest;
	TWebResponse* FResponse;
	TWebActionItems* FActions;
	THTTPMethodEvent FBeforeDispatch;
	THTTPMethodEvent FAfterDispatch;
	Contnrs::TComponentList* FDispatchList;
	TWebActionItem* __fastcall GetAction(int Index);
	void __fastcall SetActions(TWebActionItems* Value);
	
protected:
	bool __fastcall DoAfterDispatch(TWebRequest* Request, TWebResponse* Response);
	bool __fastcall DoBeforeDispatch(TWebRequest* Request, TWebResponse* Response);
	bool __fastcall DispatchAction(TWebRequest* Request, TWebResponse* Response);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	__property THTTPMethodEvent BeforeDispatch = {read=FBeforeDispatch, write=FBeforeDispatch};
	__property THTTPMethodEvent AfterDispatch = {read=FAfterDispatch, write=FAfterDispatch};
	
public:
	__fastcall virtual TCustomWebDispatcher(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomWebDispatcher(void);
	TWebActionItem* __fastcall ActionByName(const AnsiString AName);
	__property TWebActionItems* Actions = {read=FActions, write=SetActions};
	__property TWebActionItem* Action[int Index] = {read=GetAction};
	__property TWebRequest* Request = {read=FRequest};
	__property TWebResponse* Response = {read=FResponse};
public:
	#pragma option push -w-inl
	/* TDataModule.CreateNew */ inline __fastcall virtual TCustomWebDispatcher(Classes::TComponent* AOwner
		, int Dummy) : Forms::TDataModule(AOwner, Dummy) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TCustomContentProducer : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TCustomWebDispatcher* FDispatcher;
	
protected:
	virtual void __fastcall SetDispatcher(TCustomWebDispatcher* Value);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	
public:
	virtual AnsiString __fastcall Content();
	virtual AnsiString __fastcall ContentFromStream(Classes::TStream* Stream);
	virtual AnsiString __fastcall ContentFromString(const AnsiString S);
	
__published:
	__property TCustomWebDispatcher* Dispatcher = {read=FDispatcher, write=SetDispatcher, stored=false}
		;
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TCustomContentProducer(Classes::TComponent* AOwner
		) : Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCustomContentProducer(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION THTMLTagAttributes : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TCustomContentProducer* FProducer;
	AnsiString FCustom;
	Classes::TNotifyEvent FOnChange;
	void __fastcall SetCustom(const AnsiString Value);
	
protected:
	void __fastcall Changed(void);
	
public:
	__fastcall THTMLTagAttributes(TCustomContentProducer* Producer);
	virtual void __fastcall RestoreDefaults(void);
	__property TCustomContentProducer* Producer = {read=FProducer};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
__published:
	__property AnsiString Custom = {read=FCustom, write=SetCustom};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~THTMLTagAttributes(void) { }
	#pragma option pop
	
};


class DELPHICLASS THTMLTableAttributes;
class PASCALIMPLEMENTATION THTMLTableAttributes : public THTMLTagAttributes 
{
	typedef THTMLTagAttributes inherited;
	
private:
	THTMLAlign FAlign;
	int FBorder;
	AnsiString FBgColor;
	int FCellSpacing;
	int FCellPadding;
	int FWidth;
	void __fastcall SetAlign(THTMLAlign Value);
	void __fastcall SetBorder(int Value);
	void __fastcall SetBGColor(AnsiString Value);
	void __fastcall SetCellSpacing(int Value);
	void __fastcall SetCellPadding(int Value);
	void __fastcall SetWidth(int Value);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	__fastcall THTMLTableAttributes(TCustomContentProducer* Producer);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property THTMLAlign Align = {read=FAlign, write=SetAlign, default=0};
	__property AnsiString BgColor = {read=FBgColor, write=SetBGColor};
	__property int Border = {read=FBorder, write=SetBorder, default=-1};
	__property int CellSpacing = {read=FCellSpacing, write=SetCellSpacing, default=-1};
	__property int CellPadding = {read=FCellPadding, write=SetCellPadding, default=-1};
	__property int Width = {read=FWidth, write=SetWidth, default=100};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~THTMLTableAttributes(void) { }
	#pragma option pop
	
};


class DELPHICLASS THTMLTableElementAttributes;
class PASCALIMPLEMENTATION THTMLTableElementAttributes : public THTMLTagAttributes 
{
	typedef THTMLTagAttributes inherited;
	
private:
	THTMLAlign FAlign;
	AnsiString FBgColor;
	THTMLVAlign FVAlign;
	void __fastcall SetAlign(THTMLAlign Value);
	void __fastcall SetBGColor(AnsiString Value);
	void __fastcall SetVAlign(THTMLVAlign Value);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property THTMLAlign Align = {read=FAlign, write=SetAlign, default=0};
	__property AnsiString BgColor = {read=FBgColor, write=SetBGColor};
	__property THTMLVAlign VAlign = {read=FVAlign, write=SetVAlign, default=0};
public:
	#pragma option push -w-inl
	/* THTMLTagAttributes.Create */ inline __fastcall THTMLTableElementAttributes(TCustomContentProducer* 
		Producer) : THTMLTagAttributes(Producer) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~THTMLTableElementAttributes(void) { }
	#pragma option pop
	
};


class DELPHICLASS THTMLTableHeaderAttributes;
class PASCALIMPLEMENTATION THTMLTableHeaderAttributes : public THTMLTableElementAttributes 
{
	typedef THTMLTableElementAttributes inherited;
	
private:
	AnsiString FCaption;
	void __fastcall SetCaption(AnsiString Value);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property AnsiString Caption = {read=FCaption, write=SetCaption};
public:
	#pragma option push -w-inl
	/* THTMLTagAttributes.Create */ inline __fastcall THTMLTableHeaderAttributes(TCustomContentProducer* 
		Producer) : THTMLTableElementAttributes(Producer) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~THTMLTableHeaderAttributes(void) { }
	#pragma option pop
	
};


class DELPHICLASS THTMLTableRowAttributes;
class PASCALIMPLEMENTATION THTMLTableRowAttributes : public THTMLTableElementAttributes 
{
	typedef THTMLTableElementAttributes inherited;
	
public:
	#pragma option push -w-inl
	/* THTMLTagAttributes.Create */ inline __fastcall THTMLTableRowAttributes(TCustomContentProducer* Producer
		) : THTMLTableElementAttributes(Producer) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~THTMLTableRowAttributes(void) { }
	#pragma option pop
	
};


class DELPHICLASS THTMLTableCellAttributes;
class PASCALIMPLEMENTATION THTMLTableCellAttributes : public THTMLTableElementAttributes 
{
	typedef THTMLTableElementAttributes inherited;
	
public:
	#pragma option push -w-inl
	/* THTMLTagAttributes.Create */ inline __fastcall THTMLTableCellAttributes(TCustomContentProducer* 
		Producer) : THTMLTableElementAttributes(Producer) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~THTMLTableCellAttributes(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomPageProducer;
class PASCALIMPLEMENTATION TCustomPageProducer : public TCustomContentProducer 
{
	typedef TCustomContentProducer inherited;
	
private:
	AnsiString FHTMLFile;
	Classes::TStrings* FHTMLDoc;
	bool FStripParamQuotes;
	void __fastcall SetHTMLFile(const AnsiString Value);
	void __fastcall SetHTMLDoc(Classes::TStrings* Value);
	
protected:
	virtual AnsiString __fastcall HandleTag(const AnsiString TagString, Classes::TStrings* TagParams);
	__property Classes::TStrings* HTMLDoc = {read=FHTMLDoc, write=SetHTMLDoc};
	__property AnsiString HTMLFile = {read=FHTMLFile, write=SetHTMLFile};
	__property bool StripParamQuotes = {read=FStripParamQuotes, write=FStripParamQuotes, default=1};
	
public:
	__fastcall virtual TCustomPageProducer(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomPageProducer(void);
	virtual AnsiString __fastcall Content();
	virtual AnsiString __fastcall ContentFromStream(Classes::TStream* Stream);
	virtual AnsiString __fastcall ContentFromString(const AnsiString S);
};


#pragma option push -b-
enum TTag { tgCustom, tgLink, tgImage, tgTable, tgImageMap, tgObject, tgEmbed };
#pragma option pop

typedef void __fastcall (__closure *THTMLTagEvent)(System::TObject* Sender, TTag Tag, const AnsiString 
	TagString, Classes::TStrings* TagParams, AnsiString &ReplaceText);

class DELPHICLASS TPageProducer;
class PASCALIMPLEMENTATION TPageProducer : public TCustomPageProducer 
{
	typedef TCustomPageProducer inherited;
	
private:
	THTMLTagEvent FOnHTMLTag;
	
protected:
	virtual AnsiString __fastcall HandleTag(const AnsiString TagString, Classes::TStrings* TagParams);
	DYNAMIC void __fastcall DoTagEvent(TTag Tag, const AnsiString TagString, Classes::TStrings* TagParams
		, AnsiString &ReplaceText);
	
__published:
	__property HTMLDoc ;
	__property HTMLFile ;
	__property StripParamQuotes ;
	__property THTMLTagEvent OnHTMLTag = {read=FOnHTMLTag, write=FOnHTMLTag};
public:
	#pragma option push -w-inl
	/* TCustomPageProducer.Create */ inline __fastcall virtual TPageProducer(Classes::TComponent* AOwner
		) : TCustomPageProducer(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomPageProducer.Destroy */ inline __fastcall virtual ~TPageProducer(void) { }
	#pragma option pop
	
};


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
	bool __fastcall DispatchAction(TWebRequest* Request, TWebResponse* Response, bool DoDefault);
	void __fastcall SetDefault(bool Value);
	void __fastcall SetEnabled(bool Value);
	void __fastcall SetMethodType(TMethodType Value);
	void __fastcall SetOnAction(THTTPMethodEvent Value);
	void __fastcall SetPathInfo(const AnsiString Value);
	void __fastcall SetProducer(const TCustomContentProducer* Value);
	Masks::TMask* __fastcall GetMask(void);
	AnsiString __fastcall ProducerPathInfo();
	
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
	__property THTTPMethodEvent OnAction = {read=FOnAction, write=SetOnAction};
};


__interface IWebDispatch;
typedef System::DelphiInterface<IWebDispatch> _di_IWebDispatch;
__interface INTERFACE_UUID("{F358F272-DB6D-11D2-AA3F-00A024C11562}") IWebDispatch  : public IUnknown 
	
{
	
public:
	virtual bool __fastcall DispatchEnabled(void) = 0 ;
	virtual TMethodType __fastcall DispatchMethodType(void) = 0 ;
	virtual bool __fastcall DispatchRequest(System::TObject* Sender, TWebRequest* Request, TWebResponse* 
		Response) = 0 ;
	virtual Masks::TMask* __fastcall DispatchMask(void) = 0 ;
	virtual Classes::_di_IInterfaceList __fastcall DispatchSubItems(void) = 0 ;
	__property bool Enabled = {read=DispatchEnabled};
	__property TMethodType MethodType = {read=DispatchMethodType};
	__property Masks::TMask* Mask = {read=DispatchMask};
	__property Classes::_di_IInterfaceList SubItems = {read=DispatchSubItems};
};

class DELPHICLASS TWebDispatcher;
class PASCALIMPLEMENTATION TWebDispatcher : public TCustomWebDispatcher 
{
	typedef TCustomWebDispatcher inherited;
	
__published:
	__property Actions ;
	__property BeforeDispatch ;
	__property AfterDispatch ;
public:
	#pragma option push -w-inl
	/* TCustomWebDispatcher.Create */ inline __fastcall virtual TWebDispatcher(Classes::TComponent* AOwner
		) : TCustomWebDispatcher(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomWebDispatcher.Destroy */ inline __fastcall virtual ~TWebDispatcher(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TDataModule.CreateNew */ inline __fastcall virtual TWebDispatcher(Classes::TComponent* AOwner, int 
		Dummy) : TCustomWebDispatcher(AOwner, Dummy) { }
	#pragma option pop
	
};


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
public:
	#pragma option push -w-inl
	/* TCustomWebDispatcher.Destroy */ inline __fastcall virtual ~TWebModule(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TDataModule.CreateNew */ inline __fastcall virtual TWebModule(Classes::TComponent* AOwner, int Dummy
		) : TCustomWebDispatcher(AOwner, Dummy) { }
	#pragma option pop
	
};


typedef AnsiString HTTPApp__91[4];

typedef AnsiString HTTPApp__02[5];

//-- var, const, procedure ---------------------------------------------------
#define sDateFormat "\"%s\", dd \"%s\" yyyy hh:mm:ss"
static const Shortint MAX_STRINGS = 0xc;
static const Shortint MAX_INTEGERS = 0x1;
static const Shortint MAX_DATETIMES = 0x3;
extern PACKAGE AnsiString HTMLAlign[4];
extern PACKAGE AnsiString HTMLVAlign[5];
extern PACKAGE AnsiString __fastcall HTTPDecode(const AnsiString AStr);
extern PACKAGE AnsiString __fastcall HTTPEncode(const AnsiString AStr);
extern PACKAGE System::TDateTime __fastcall ParseDate(const AnsiString DateStr);
extern PACKAGE void __fastcall ExtractHeaderFields(const Sysutils::TSysCharSet &Separators, const Sysutils::TSysCharSet 
	&WhiteSpace, char * Content, Classes::TStrings* Strings, bool Decode, bool StripQuotes);
extern PACKAGE void __fastcall ExtractHTTPFields(const Sysutils::TSysCharSet &Separators, const Sysutils::TSysCharSet 
	&WhiteSpace, char * Content, Classes::TStrings* Strings, bool StripQuotes);
extern PACKAGE AnsiString __fastcall StatusString(int StatusCode);
extern PACKAGE AnsiString __fastcall UnixPathToDosPath(const AnsiString Path);
extern PACKAGE AnsiString __fastcall DosPathToUnixPath(const AnsiString Path);
extern PACKAGE AnsiString __fastcall MonthStr(System::TDateTime DateTime);
extern PACKAGE AnsiString __fastcall DayOfWeekStr(System::TDateTime DateTime);

}	/* namespace Httpapp */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Httpapp;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// HTTPApp
