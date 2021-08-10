// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WebSess.pas' rev: 6.00

#ifndef WebSessHPP
#define WebSessHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <WebDisp.hpp>	// Pascal unit
#include <SessColn.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <WebContnrs.hpp>	// Pascal unit
#include <SiteComp.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Websess
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TEndSessionReason { esTimeout, esTerminate };
#pragma option pop

typedef void __fastcall (__closure *TStartSessionEvent)(System::TObject* ASender, Httpapp::TAbstractWebSession* ASession);

typedef void __fastcall (__closure *TEndSessionEvent)(System::TObject* ASender, Httpapp::TAbstractWebSession* ASession, TEndSessionReason AReason);

class DELPHICLASS TCustomSessionsService;
class PASCALIMPLEMENTATION TCustomSessionsService : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TStartSessionEvent FOnStartSession;
	TEndSessionEvent FOnEndSession;
	int FDefaultTimeout;
	void __fastcall SetMaxSessions(const int Value);
	int __fastcall GetMaxSessions(void);
	
protected:
	Sitecomp::_di_IWebSession __fastcall NewSession();
	void __fastcall Clear(void);
	bool __fastcall CheckStatusChange(void);
	void __fastcall NotifyStatusChange(void);
	Sitecomp::_di_IWebSession __fastcall Connect(AnsiString AID);
	Sitecomp::_di_IWebSession __fastcall ConnectActive(AnsiString AID);
	Sitecomp::_di_IWebSessionIDs __fastcall GetSessionIDs();
	void __fastcall LoadFromFile(const AnsiString Filename);
	void __fastcall SaveToFile(const AnsiString Filename);
	void __fastcall LoadFromStream(Classes::TStream* S);
	void __fastcall SaveToStream(Classes::TStream* S);
	
public:
	__fastcall virtual TCustomSessionsService(Classes::TComponent* AOwner);
	__property int DefaultTimeout = {read=FDefaultTimeout, write=FDefaultTimeout, default=20};
	__property TStartSessionEvent OnStartSession = {read=FOnStartSession, write=FOnStartSession};
	__property TEndSessionEvent OnEndSession = {read=FOnEndSession, write=FOnEndSession};
	__property int MaxSessions = {read=GetMaxSessions, write=SetMaxSessions, default=-1};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCustomSessionsService(void) { }
	#pragma option pop
	
private:
	void *__ISessionsService;	/* Sitecomp::ISessionsService */
	void *__ISessionsServiceConnectID;	/* Sitecomp::ISessionsServiceConnectID */
	void *__IWebGetSessionIDs;	/* Sitecomp::IWebGetSessionIDs */
	void *__ISessionsServicePersist;	/* Sitecomp::ISessionsServicePersist */
	
public:
	operator ISessionsServicePersist*(void) { return (ISessionsServicePersist*)&__ISessionsServicePersist; }
	operator IWebGetSessionIDs*(void) { return (IWebGetSessionIDs*)&__IWebGetSessionIDs; }
	operator ISessionsServiceConnectID*(void) { return (ISessionsServiceConnectID*)&__ISessionsServiceConnectID; }
	operator ISessionsService*(void) { return (ISessionsService*)&__ISessionsService; }
	
};


class DELPHICLASS TSessionsService;
class PASCALIMPLEMENTATION TSessionsService : public TCustomSessionsService 
{
	typedef TCustomSessionsService inherited;
	
__published:
	__property OnStartSession ;
	__property OnEndSession ;
	__property DefaultTimeout  = {default=20};
	__property MaxSessions  = {default=-1};
public:
	#pragma option push -w-inl
	/* TCustomSessionsService.Create */ inline __fastcall virtual TSessionsService(Classes::TComponent* AOwner) : TCustomSessionsService(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TSessionsService(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWebSessionImpl;
class PASCALIMPLEMENTATION TWebSessionImpl : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	AnsiString FID;
	
protected:
	void __fastcall Terminate(void);
	void __fastcall GetItems(Webcontnrs::TAbstractNamedVariants* &AItems);
	int __fastcall GetItemCount(void);
	void __fastcall SetValue(const AnsiString AName, const Variant &AValue);
	Variant __fastcall GetValue(const AnsiString AName);
	__property Variant Values[AnsiString AName] = {read=GetValue, write=SetValue};
	System::TDateTime __fastcall GetStartTime(void);
	__property System::TDateTime StartTime = {read=GetStartTime};
	int __fastcall GetTimeoutMinutes(void);
	void __fastcall SetTimeoutMinutes(int AValue);
	__property int TimeoutMinutes = {read=GetTimeoutMinutes, nodefault};
	System::TDateTime __fastcall GetTouchTime(void);
	__property System::TDateTime TouchTime = {read=GetTouchTime};
	bool __fastcall GetExpired(void);
	__property bool Expired = {read=GetExpired, nodefault};
	bool __fastcall GetTerminated(void);
	__property bool Terminated = {read=GetTerminated, nodefault};
	System::TDateTime __fastcall GetExpirationTime(void);
	__property System::TDateTime ExpirationTime = {read=GetExpirationTime};
	bool __fastcall GetIsActive(void);
	AnsiString __fastcall GetID();
	__property AnsiString ID = {read=GetID};
	
public:
	__fastcall TWebSessionImpl(AnsiString AID);
	__fastcall virtual ~TWebSessionImpl(void);
private:
	void *__IWebSession;	/* Sitecomp::IWebSession */
	void *__IWebSessionID;	/* Sitecomp::IWebSessionID */
	void *__IWebSessionValues;	/* Sitecomp::IWebSessionValues */
	void *__IWebSessionAttributes;	/* Sitecomp::IWebSessionAttributes */
	
public:
	operator IWebSessionAttributes*(void) { return (IWebSessionAttributes*)&__IWebSessionAttributes; }
	operator IWebSessionValues*(void) { return (IWebSessionValues*)&__IWebSessionValues; }
	operator IWebSessionID*(void) { return (IWebSessionID*)&__IWebSessionID; }
	operator IWebSession*(void) { return (IWebSession*)&__IWebSession; }
	
};


class DELPHICLASS TWebSessionIDsImpl;
class PASCALIMPLEMENTATION TWebSessionIDsImpl : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Classes::TList* FList;
	
protected:
	int __fastcall GetIDCount(void);
	AnsiString __fastcall GetID(int I);
	
public:
	__fastcall TWebSessionIDsImpl(void);
	__fastcall virtual ~TWebSessionIDsImpl(void);
private:
	void *__IWebSessionIDs;	/* Sitecomp::IWebSessionIDs */
	
public:
	operator IWebSessionIDs*(void) { return (IWebSessionIDs*)&__IWebSessionIDs; }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Websess */
using namespace Websess;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WebSess
