// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdHTTPServer.pas' rev: 6.00

#ifndef IdHTTPServerHPP
#define IdHTTPServerHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdComponent.hpp>	// Pascal unit
#include <IdThread.hpp>	// Pascal unit
#include <IdTCPServer.hpp>	// Pascal unit
#include <IdHeaderList.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SyncObjs.hpp>	// Pascal unit
#include <IdGlobal.hpp>	// Pascal unit
#include <IdException.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idhttpserver
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdHTTPSession;
typedef void __fastcall (__closure *TOnSessionEndEvent)(TIdHTTPSession* Sender);

typedef void __fastcall (__closure *TOnSessionStartEvent)(TIdHTTPSession* Sender);

class DELPHICLASS TIdHTTPSessionList;
class PASCALIMPLEMENTATION TIdHTTPSessionList : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	Classes::TThreadList* SessionList;
	unsigned FSessionTimeout;
	TOnSessionEndEvent FOnSessionEnd;
	TOnSessionStartEvent FOnSessionStart;
	void __fastcall RemoveSession(TIdHTTPSession* Session);
	void __fastcall RemoveSessionFromLockedList(int index, Classes::TList* lockedsessionlist);
	
public:
	__fastcall virtual TIdHTTPSessionList(void);
	__fastcall virtual ~TIdHTTPSessionList(void);
	virtual void __fastcall Clear(void);
	void __fastcall PurgeStaleSessions(bool PurgeAll = false);
	TIdHTTPSession* __fastcall CreateSession(const AnsiString RemoteIP, const AnsiString SessionID);
	TIdHTTPSession* __fastcall GetSession(const AnsiString SessionID, const AnsiString RemoteIP);
	__property unsigned SessionTimeout = {read=FSessionTimeout, write=FSessionTimeout, nodefault};
	__property TOnSessionEndEvent OnSessionEnd = {read=FOnSessionEnd, write=FOnSessionEnd};
	__property TOnSessionStartEvent OnSessionStart = {read=FOnSessionStart, write=FOnSessionStart};
};


class PASCALIMPLEMENTATION TIdHTTPSession : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	TIdHTTPSessionList* FOwner;
	AnsiString FSessionID;
	System::TDateTime FLastTimeStamp;
	AnsiString FRemoteHost;
	Classes::TStrings* FContent;
	Syncobjs::TCriticalSection* FLock;
	void __fastcall SetContent(const Classes::TStrings* Value);
	Classes::TStrings* __fastcall GetContent(void);
	virtual bool __fastcall IsSessionStale(void);
	virtual void __fastcall DoSessionEnd(void);
	
public:
	void __fastcall Lock(void);
	void __fastcall Unlock(void);
	__fastcall virtual TIdHTTPSession(TIdHTTPSessionList* AOwner);
	__fastcall virtual TIdHTTPSession(TIdHTTPSessionList* AOwner, const AnsiString SessionID, const AnsiString RemoteIP);
	__fastcall virtual ~TIdHTTPSession(void);
	__property AnsiString SessionID = {read=FSessionID};
	__property System::TDateTime LastTimeStamp = {read=FLastTimeStamp};
	__property AnsiString RemoteHost = {read=FRemoteHost};
	__property Classes::TStrings* Content = {read=GetContent, write=SetContent};
};


class DELPHICLASS TIdCookie;
class PASCALIMPLEMENTATION TIdCookie : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	bool FSecure;
	AnsiString FComment;
	AnsiString FDomain;
	AnsiString FName;
	AnsiString FPath;
	AnsiString FValue;
	int FMaxAge;
	AnsiString __fastcall GetCookieText();
	
public:
	void __fastcall AddAttribute(const AnsiString Attribute, const AnsiString Value);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__fastcall virtual TIdCookie(Classes::TCollection* Collection);
	
__published:
	__property AnsiString Name = {read=FName, write=FName};
	__property AnsiString Value = {read=FValue, write=FValue};
	__property AnsiString Domain = {read=FDomain, write=FDomain};
	__property AnsiString Path = {read=FPath, write=FPath};
	__property AnsiString Comment = {read=FComment, write=FComment};
	__property bool Secure = {read=FSecure, write=FSecure, nodefault};
	__property int MaxAge = {read=FMaxAge, write=FMaxAge, default=-1};
	__property AnsiString CookieText = {read=GetCookieText};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdCookie(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIdCookieCollection;
class PASCALIMPLEMENTATION TIdCookieCollection : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
public:
	TIdCookie* operator[](int Index) { return Items[Index]; }
	
protected:
	TIdCookie* __fastcall GetCookie(const AnsiString name);
	HIDESBASE TIdCookie* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TIdCookie* Value);
	
public:
	HIDESBASE TIdCookie* __fastcall Add(void);
	__fastcall TIdCookieCollection(void);
	void __fastcall AddSrcCookie(const AnsiString sCookie);
	virtual int __fastcall GetCookieIndex(int FirstIndex, const AnsiString Name);
	__property TIdCookie* Cookie[AnsiString name] = {read=GetCookie};
	__property TIdCookie* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdCookieCollection(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIdHTTPRequestInfo;
class PASCALIMPLEMENTATION TIdHTTPRequestInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	TIdHTTPSession* FSession;
	AnsiString FRemoteIP;
	AnsiString FHost;
	AnsiString FDocument;
	AnsiString FCommand;
	AnsiString FVersion;
	AnsiString FAuthUsername;
	AnsiString FAuthPassword;
	AnsiString FUnparsedParams;
	bool FAuthExists;
	Idheaderlist::TIdHeaderList* FHeaders;
	Classes::TStrings* FParams;
	TIdCookieCollection* FCookies;
	void __fastcall SetCookies(const TIdCookieCollection* Value);
	void __fastcall SetHeaders(const Idheaderlist::TIdHeaderList* AValue);
	void __fastcall SetParams(const Classes::TStrings* AValue);
	void __fastcall DecodeAndSetParams(const AnsiString AValue);
	
public:
	__fastcall TIdHTTPRequestInfo(void);
	__fastcall virtual ~TIdHTTPRequestInfo(void);
	__property TIdHTTPSession* Session = {read=FSession};
	__property bool AuthExists = {read=FAuthExists, write=FAuthExists, nodefault};
	__property AnsiString AuthPassword = {read=FAuthPassword, write=FAuthPassword};
	__property AnsiString AuthUsername = {read=FAuthUsername, write=FAuthUsername};
	__property AnsiString Command = {read=FCommand};
	__property TIdCookieCollection* Cookies = {read=FCookies, write=SetCookies};
	__property AnsiString Document = {read=FDocument};
	__property Idheaderlist::TIdHeaderList* Headers = {read=FHeaders, write=SetHeaders};
	__property Classes::TStrings* Params = {read=FParams, write=SetParams};
	__property AnsiString UnparsedParams = {read=FUnparsedParams};
	__property AnsiString Version = {read=FVersion};
	__property AnsiString Host = {read=FHost};
	__property AnsiString RemoteIP = {read=FRemoteIP};
};


class DELPHICLASS TIdHTTPResponseInfo;
class PASCALIMPLEMENTATION TIdHTTPResponseInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	TIdHTTPSession* FSession;
	AnsiString FServerSoftware;
	AnsiString FAuthRealm;
	AnsiString FResponseText;
	AnsiString FContentType;
	Idtcpserver::TIdTCPServerConnection* FConnection;
	bool FHeaderHasBeenWritten;
	int FResponseNo;
	int FContentLength;
	TIdCookieCollection* FCookies;
	Idheaderlist::TIdHeaderList* FHeaders;
	Classes::TStream* FContentStream;
	AnsiString FContentText;
	void __fastcall SetCookies(const TIdCookieCollection* AValue);
	void __fastcall SetHeaders(const Idheaderlist::TIdHeaderList* AValue);
	void __fastcall SetResponseNo(const int AValue);
	
public:
	__fastcall TIdHTTPResponseInfo(Idtcpserver::TIdTCPServerConnection* AConnection);
	__fastcall virtual ~TIdHTTPResponseInfo(void);
	void __fastcall Redirect(const AnsiString AURL);
	void __fastcall WriteHeader(void);
	void __fastcall WriteContent(void);
	__property TIdHTTPSession* Session = {read=FSession};
	__property AnsiString AuthRealm = {read=FAuthRealm, write=FAuthRealm};
	__property Classes::TStream* ContentStream = {read=FContentStream, write=FContentStream};
	__property AnsiString ContentText = {read=FContentText, write=FContentText};
	__property TIdCookieCollection* Cookies = {read=FCookies, write=SetCookies};
	__property Idheaderlist::TIdHeaderList* Headers = {read=FHeaders, write=SetHeaders};
	__property bool HeaderHasBeenWritten = {read=FHeaderHasBeenWritten, nodefault};
	__property int ResponseNo = {read=FResponseNo, write=SetResponseNo, nodefault};
	__property AnsiString ResponseText = {read=FResponseText, write=FResponseText};
	__property int ContentLength = {read=FContentLength, write=FContentLength, nodefault};
	__property AnsiString ContentType = {read=FContentType, write=FContentType};
	__property AnsiString ServerSoftware = {read=FServerSoftware, write=FServerSoftware};
};


typedef void __fastcall (__closure *TIdHTTPGetEvent)(Idtcpserver::TIdPeerThread* AThread, TIdHTTPRequestInfo* RequestInfo, TIdHTTPResponseInfo* ResponseInfo);

typedef void __fastcall (__closure *TIdHTTPOtherEvent)(Idtcpserver::TIdPeerThread* Thread, const AnsiString asCommand, const AnsiString asData, const AnsiString asVersion);

class DELPHICLASS TIdHTTPServer;
class PASCALIMPLEMENTATION TIdHTTPServer : public Idtcpserver::TIdTCPServer 
{
	typedef Idtcpserver::TIdTCPServer inherited;
	
protected:
	AnsiString FServerSoftware;
	bool FParseParams;
	TIdHTTPGetEvent FOnCommandGet;
	TIdHTTPOtherEvent FOnCommandOther;
	TIdHTTPSessionList* FSessionList;
	bool FSessionState;
	int FSessionTimeOut;
	TOnSessionEndEvent FOnSessionEnd;
	TOnSessionStartEvent FOnSessionStart;
	bool FAutoStartSession;
	Idglobal::TIdMimeTable* FMIMETable;
	Idthread::TIdThread* FSessionCleanupThread;
	virtual void __fastcall SetActive(bool AValue);
	void __fastcall SetSessionState(const bool Value);
	virtual void __fastcall CaptureHeader(Idtcpserver::TIdPeerThread* AThread, TIdHTTPRequestInfo* rsiDest);
	TIdHTTPSession* __fastcall GetSessionFromCookie(TIdHTTPRequestInfo* HTTPrequest, TIdHTTPResponseInfo* HTTPResponse);
	
public:
	bool __fastcall EndSession(const AnsiString SessionName);
	__property TIdHTTPSessionList* SessionList = {read=FSessionList};
	__property Idglobal::TIdMimeTable* MIMETable = {read=FMIMETable};
	TIdHTTPSession* __fastcall CreateSession(TIdHTTPResponseInfo* HTTPResponse, TIdHTTPRequestInfo* HTTPRequest);
	__fastcall virtual TIdHTTPServer(Classes::TComponent* AOwner);
	__fastcall virtual ~TIdHTTPServer(void);
	virtual bool __fastcall DoExecute(Idtcpserver::TIdPeerThread* AThread);
	virtual unsigned __fastcall ServeFile(Idtcpserver::TIdPeerThread* AThread, TIdHTTPResponseInfo* ResponseInfo, AnsiString aFile);
	
__published:
	__property TIdHTTPGetEvent OnCommandGet = {read=FOnCommandGet, write=FOnCommandGet};
	__property TIdHTTPOtherEvent OnCommandOther = {read=FOnCommandOther, write=FOnCommandOther};
	__property bool ParseParams = {read=FParseParams, write=FParseParams, default=1};
	__property AnsiString ServerSoftware = {read=FServerSoftware, write=FServerSoftware};
	__property bool SessionState = {read=FSessionState, write=SetSessionState, default=0};
	__property bool AutoStartSession = {read=FAutoStartSession, write=FAutoStartSession, default=0};
	__property int SessionTimeOut = {read=FSessionTimeOut, write=FSessionTimeOut, default=0};
	__property TOnSessionStartEvent OnSessionStart = {read=FOnSessionStart, write=FOnSessionStart};
	__property TOnSessionEndEvent OnSessionEnd = {read=FOnSessionEnd, write=FOnSessionEnd};
	__property DefaultPort  = {default=80};
};


class DELPHICLASS EIdHTTPServerError;
class PASCALIMPLEMENTATION EIdHTTPServerError : public Idexception::EIdException 
{
	typedef Idexception::EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdHTTPServerError(const AnsiString Msg) : Idexception::EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdHTTPServerError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdHTTPServerError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdHTTPServerError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdHTTPServerError(const AnsiString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdHTTPServerError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdHTTPServerError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdHTTPServerError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdHTTPServerError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdHTTPHeaderAlreadyWritten;
class PASCALIMPLEMENTATION EIdHTTPHeaderAlreadyWritten : public EIdHTTPServerError 
{
	typedef EIdHTTPServerError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdHTTPHeaderAlreadyWritten(const AnsiString Msg) : EIdHTTPServerError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdHTTPHeaderAlreadyWritten(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdHTTPServerError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdHTTPHeaderAlreadyWritten(int Ident)/* overload */ : EIdHTTPServerError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdHTTPHeaderAlreadyWritten(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdHTTPServerError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdHTTPHeaderAlreadyWritten(const AnsiString Msg, int AHelpContext) : EIdHTTPServerError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdHTTPHeaderAlreadyWritten(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdHTTPServerError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdHTTPHeaderAlreadyWritten(int Ident, int AHelpContext)/* overload */ : EIdHTTPServerError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdHTTPHeaderAlreadyWritten(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdHTTPServerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdHTTPHeaderAlreadyWritten(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdHTTPErrorParsingCommand;
class PASCALIMPLEMENTATION EIdHTTPErrorParsingCommand : public EIdHTTPServerError 
{
	typedef EIdHTTPServerError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdHTTPErrorParsingCommand(const AnsiString Msg) : EIdHTTPServerError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdHTTPErrorParsingCommand(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdHTTPServerError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdHTTPErrorParsingCommand(int Ident)/* overload */ : EIdHTTPServerError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdHTTPErrorParsingCommand(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdHTTPServerError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdHTTPErrorParsingCommand(const AnsiString Msg, int AHelpContext) : EIdHTTPServerError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdHTTPErrorParsingCommand(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdHTTPServerError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdHTTPErrorParsingCommand(int Ident, int AHelpContext)/* overload */ : EIdHTTPServerError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdHTTPErrorParsingCommand(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdHTTPServerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdHTTPErrorParsingCommand(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdHTTPUnsupportedAuthorisationScheme;
class PASCALIMPLEMENTATION EIdHTTPUnsupportedAuthorisationScheme : public EIdHTTPServerError 
{
	typedef EIdHTTPServerError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdHTTPUnsupportedAuthorisationScheme(const AnsiString Msg) : EIdHTTPServerError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdHTTPUnsupportedAuthorisationScheme(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdHTTPServerError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdHTTPUnsupportedAuthorisationScheme(int Ident)/* overload */ : EIdHTTPServerError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdHTTPUnsupportedAuthorisationScheme(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdHTTPServerError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdHTTPUnsupportedAuthorisationScheme(const AnsiString Msg, int AHelpContext) : EIdHTTPServerError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdHTTPUnsupportedAuthorisationScheme(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdHTTPServerError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdHTTPUnsupportedAuthorisationScheme(int Ident, int AHelpContext)/* overload */ : EIdHTTPServerError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdHTTPUnsupportedAuthorisationScheme(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdHTTPServerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdHTTPUnsupportedAuthorisationScheme(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdHTTPCannotSwitchSessionStateWhenActive;
class PASCALIMPLEMENTATION EIdHTTPCannotSwitchSessionStateWhenActive : public EIdHTTPServerError 
{
	typedef EIdHTTPServerError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdHTTPCannotSwitchSessionStateWhenActive(const AnsiString Msg) : EIdHTTPServerError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdHTTPCannotSwitchSessionStateWhenActive(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdHTTPServerError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdHTTPCannotSwitchSessionStateWhenActive(int Ident)/* overload */ : EIdHTTPServerError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdHTTPCannotSwitchSessionStateWhenActive(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdHTTPServerError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdHTTPCannotSwitchSessionStateWhenActive(const AnsiString Msg, int AHelpContext) : EIdHTTPServerError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdHTTPCannotSwitchSessionStateWhenActive(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdHTTPServerError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdHTTPCannotSwitchSessionStateWhenActive(int Ident, int AHelpContext)/* overload */ : EIdHTTPServerError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdHTTPCannotSwitchSessionStateWhenActive(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdHTTPServerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdHTTPCannotSwitchSessionStateWhenActive(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const bool Id_TId_HTTPServer_ParseParams = true;
static const bool Id_TId_HTTPServer_SessionState = false;
static const Shortint Id_TId_HTTPSessionTimeOut = 0x0;
static const bool Id_TId_HTTPAutoStartSession = false;
static const Shortint GFMaxAge = 0xffffffff;
static const Byte GResponseNo = 0xc8;
static const Shortint GFContentLength = 0xffffffff;
#define GServerSoftware "Indy/8.0.25"
#define GContentType "text/html"

}	/* namespace Idhttpserver */
using namespace Idhttpserver;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdHTTPServer
