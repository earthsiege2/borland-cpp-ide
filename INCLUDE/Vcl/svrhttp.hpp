// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SvrHTTP.pas' rev: 6.00

#ifndef SvrHTTPHPP
#define SvrHTTPHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <HTTPParse.hpp>	// Pascal unit
#include <SvrLog.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <ComObj.hpp>	// Pascal unit
#include <WebLib.hpp>	// Pascal unit
#include <ReqImpl.hpp>	// Pascal unit
#include <WinSock.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <WebBroker.hpp>	// Pascal unit
#include <ScktComp.hpp>	// Pascal unit
#include <SyncObjs.hpp>	// Pascal unit
#include <Registry.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Svrhttp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EWebServerException;
class DELPHICLASS TWebServerRequest;
typedef AnsiString SvrHTTP__3[29];

class PASCALIMPLEMENTATION TWebServerRequest : public Httpapp::TWebRequest 
{
	typedef Httpapp::TWebRequest inherited;
	
private:
	Scktcomp::TServerClientWinSocket* FClientSocket;
	Classes::TStream* FRequestBufferStream;
	AnsiString FRequestBuffer;
	AnsiString FParserContent;
	int FReadParserContent;
	AnsiString FLogBuffer;
	AnsiString FRequestLine;
	AnsiString FUserName;
	AnsiString FPassword;
	System::TDateTime FLastModified;
	AnsiString FStringVariable[29];
	Classes::TStringList* FExtHeaders;
	void __fastcall SetStringVariable(int Index, const AnsiString Value);
	void __fastcall SetIntegerVariable(int Index, int Value);
	void __fastcall SetDateVariable(int Index, System::TDateTime Value);
	__property AnsiString StringVariable[int I] = {read=GetStringVariable, write=SetStringVariable};
	__property int IntegerVariable[int I] = {read=GetIntegerVariable, write=SetIntegerVariable};
	__property System::TDateTime DateVariable[int I] = {read=GetDateVariable, write=SetDateVariable};
	AnsiString __fastcall GetRequestBuffer();
	
protected:
	virtual AnsiString __fastcall GetStringVariable(int Index);
	virtual System::TDateTime __fastcall GetDateVariable(int Index);
	virtual int __fastcall GetIntegerVariable(int Index);
	
public:
	__fastcall TWebServerRequest(int APort, AnsiString ARemoteAddress, AnsiString ARemoteHost);
	__fastcall virtual ~TWebServerRequest(void);
	virtual AnsiString __fastcall GetFieldByName(const AnsiString Name);
	virtual int __fastcall ReadClient(void *Buffer, int Count);
	virtual AnsiString __fastcall ReadString(int Count);
	virtual AnsiString __fastcall TranslateURI(const AnsiString URI);
	virtual int __fastcall WriteClient(void *Buffer, int Count);
	virtual bool __fastcall WriteString(const AnsiString AString);
	__property AnsiString RequestBuffer = {read=GetRequestBuffer};
	virtual bool __fastcall WriteHeaders(int StatusCode, const AnsiString StatusString, const AnsiString Headers);
	void __fastcall AddExtHeader(AnsiString Name, AnsiString Value);
};


class PASCALIMPLEMENTATION EWebServerException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
private:
	TWebServerRequest* FRequest;
	
public:
	__fastcall EWebServerException(const AnsiString Message, TWebServerRequest* ARequest);
	__property TWebServerRequest* Request = {read=FRequest};
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EWebServerException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EWebServerException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EWebServerException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EWebServerException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EWebServerException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EWebServerException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EWebServerException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EWebServerException(void) { }
	#pragma option pop
	
};


typedef AnsiString SvrHTTP__5[12];

class DELPHICLASS TWebServerResponse;
class PASCALIMPLEMENTATION TWebServerResponse : public Httpapp::TWebResponse 
{
	typedef Httpapp::TWebResponse inherited;
	
private:
	Scktcomp::TServerClientWinSocket* FClientSocket;
	TWebServerRequest* FRequest;
	System::TDateTime FDate;
	AnsiString FVersion;
	int FStatusCode;
	AnsiString FReasonString;
	AnsiString FServer;
	AnsiString FWWWAuthenticate;
	AnsiString FRealm;
	AnsiString FAllow;
	AnsiString FContentEncoding;
	AnsiString FContentType;
	int FContentLength;
	AnsiString FContentVersion;
	AnsiString FDerivedFrom;
	System::TDateTime FExpires;
	System::TDateTime FLastModified;
	AnsiString FTitle;
	AnsiString FContent;
	Classes::TStream* FContentStream;
	AnsiString FStringVariables[12];
	int FIntegerVariables[1];
	System::TDateTime FDateVariables[3];
	bool FSent;
	
protected:
	virtual void __fastcall SetStatusCode(int Value);
	virtual void __fastcall SetContent(const AnsiString Value);
	virtual void __fastcall SetContentStream(Classes::TStream* Value);
	virtual AnsiString __fastcall GetStringVariable(int Index);
	virtual void __fastcall SetStringVariable(int Index, const AnsiString Value);
	virtual System::TDateTime __fastcall GetDateVariable(int Index);
	virtual void __fastcall SetDateVariable(int Index, const System::TDateTime Value);
	virtual int __fastcall GetIntegerVariable(int Index);
	virtual void __fastcall SetIntegerVariable(int Index, int Value);
	virtual AnsiString __fastcall GetContent();
	virtual int __fastcall GetStatusCode(void);
	virtual AnsiString __fastcall GetLogMessage();
	virtual void __fastcall SetLogMessage(const AnsiString Value);
	
public:
	virtual void __fastcall SendResponse(void);
	virtual void __fastcall SendRedirect(const AnsiString URI);
	virtual void __fastcall SendStream(Classes::TStream* AStream);
	virtual bool __fastcall Sent(void);
	__fastcall TWebServerResponse(TWebServerRequest* Request, Scktcomp::TServerClientWinSocket* AClientSocket);
	__fastcall virtual ~TWebServerResponse(void);
	__property TWebServerRequest* Request = {read=FRequest};
	__property AnsiString Version = {read=FVersion, write=FVersion};
	__property int StatusCode = {read=FStatusCode, write=SetStatusCode, nodefault};
	__property AnsiString ReasonString = {read=FReasonString, write=FReasonString};
	__property System::TDateTime Date = {read=FDate};
	__property AnsiString Server = {read=FServer, write=FServer};
	__property AnsiString WWWAuthenticate = {read=FWWWAuthenticate, write=FWWWAuthenticate};
	__property AnsiString Realm = {read=FRealm, write=FRealm};
	__property AnsiString Allow = {read=FAllow, write=FAllow};
	__property AnsiString ContentEncoding = {read=FContentEncoding, write=FContentEncoding};
	__property AnsiString ContentType = {read=FContentType, write=FContentType};
	__property int ContentLength = {read=FContentLength, write=FContentLength, nodefault};
	__property AnsiString ContentVersion = {read=FContentVersion, write=FContentVersion};
	__property AnsiString DerivedFrom = {read=FDerivedFrom, write=FDerivedFrom};
	__property System::TDateTime Expires = {read=FExpires, write=FExpires};
	__property System::TDateTime LastModified = {read=FLastModified, write=FLastModified};
	__property AnsiString Title = {read=FTitle, write=FTitle};
	__property AnsiString Content = {read=FContent, write=SetContent};
	__property Classes::TStream* ContentStream = {read=FContentStream, write=SetContentStream};
};


class DELPHICLASS TWebServerThread;
class PASCALIMPLEMENTATION TWebServerThread : public Scktcomp::TServerClientThread 
{
	typedef Scktcomp::TServerClientThread inherited;
	
private:
	Registry::TRegistry* FRegistry;
	bool __fastcall DoFileAccess(TWebServerRequest* Request, bool IsHeadMethod);
	void __fastcall ParseCommand(Httpparse::THTTPParser* Parser, TWebServerRequest* Request);
	void __fastcall LogRequest(TWebServerRequest* Request);
	bool __fastcall GetFile(TWebServerRequest* Request);
	bool __fastcall Head(TWebServerRequest* Request);
	void __fastcall CommandError(TWebServerRequest* Request);
	void __fastcall URLNotFound(TWebServerRequest* Request);
	void __fastcall ServerError(TWebServerRequest* Request, const AnsiString ErrorMsg);
	
protected:
	virtual void __fastcall HandleException(void);
	virtual void __fastcall Error(Scktcomp::TErrorEvent ErrorEvent, int &ErrorCode);
	
public:
	__fastcall TWebServerThread(bool CreateSuspended, Scktcomp::TServerClientWinSocket* ASocket);
	__fastcall virtual ~TWebServerThread(void);
	virtual void __fastcall ClientExecute(void);
	AnsiString __fastcall GetMIMEType(const AnsiString FileName);
};


class DELPHICLASS TWebServerWinSocket;
class DELPHICLASS TCustomWebServer;
class DELPHICLASS TServerLog;
class PASCALIMPLEMENTATION TServerLog : public Svrlog::TCustomServerLog 
{
	typedef Svrlog::TCustomServerLog inherited;
	
private:
	TCustomWebServer* FWebServer;
	
protected:
	virtual void __fastcall DoOnLog(Svrlog::TTransactionLogEntry* Transaction, bool &Release);
	
public:
	__fastcall TServerLog(TCustomWebServer* AServer);
public:
	#pragma option push -w-inl
	/* TCustomServerLog.Destroy */ inline __fastcall virtual ~TServerLog(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TCustomWebServer : public Scktcomp::TCustomServerSocket 
{
	typedef Scktcomp::TCustomServerSocket inherited;
	
private:
	TServerLog* FLog;
	Svrlog::THTTPLogEvent FOnLog;
	AnsiString FSearchPath;
	AnsiString FDefaultURL;
	AnsiString FExpandedSearchPath;
	void __fastcall EventEvent(System::TObject* Sender, Scktcomp::TCustomWinSocket* Socket, Scktcomp::TSocketEvent SocketEvent);
	void __fastcall ErrorEvent(System::TObject* Sender, Scktcomp::TCustomWinSocket* Socket, Scktcomp::TErrorEvent ErrorEvent, int &ErrorCode);
	AnsiString __fastcall GetTranslatedDefaultURL();
	AnsiString __fastcall GetExpandedSearchPath();
	void __fastcall SetSearchPath(const AnsiString Value);
	
protected:
	virtual void __fastcall DoActivate(bool Value);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall LogRequest(TWebServerRequest* Request, Scktcomp::TServerClientWinSocket* ClientSocket);
	void __fastcall LogError(Scktcomp::TErrorEvent AErrorEvent, int AErrorCode, const AnsiString AErrorMsg);
	
public:
	__property Svrlog::THTTPLogEvent OnLog = {read=FOnLog, write=FOnLog};
	__property AnsiString SearchPath = {read=FSearchPath, write=SetSearchPath};
	__property AnsiString ExpandedSearchPath = {read=GetExpandedSearchPath};
	__property AnsiString DefaultURL = {read=FDefaultURL, write=FDefaultURL};
	__property AnsiString TranslatedDefaultURL = {read=GetTranslatedDefaultURL};
	__property Port ;
	__property Active ;
	__fastcall virtual TCustomWebServer(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomWebServer(void);
};


class PASCALIMPLEMENTATION TWebServerWinSocket : public Scktcomp::TServerWinSocket 
{
	typedef Scktcomp::TServerWinSocket inherited;
	
private:
	TCustomWebServer* FServerComponent;
	
protected:
	virtual Scktcomp::TServerClientThread* __fastcall DoCreateThread(Scktcomp::TServerClientWinSocket* ClientSocket);
	
public:
	__fastcall TWebServerWinSocket(TCustomWebServer* AOwner, int ASocket);
	__property TCustomWebServer* ServerComponent = {read=FServerComponent};
public:
	#pragma option push -w-inl
	/* TServerWinSocket.Destroy */ inline __fastcall virtual ~TWebServerWinSocket(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *THTTPMethodEvent)(System::TObject* Sender, Scktcomp::TServerClientWinSocket* ClientSocket, TWebServerRequest* Request, bool &Handled);

typedef void __fastcall (__closure *THTTPErrorEvent)(System::TObject* Sender, Scktcomp::TServerClientWinSocket* ClientSocket, TWebServerRequest* Request, bool &Handled);

typedef void __fastcall (__closure *TWebServerErrorEvent)(System::TObject* Sender, Scktcomp::TServerClientWinSocket* ClientSocket, TWebServerRequest* Request, const AnsiString ErrorMsg, bool &Handled);

typedef AnsiString SvrHTTP__01[5];

//-- var, const, procedure ---------------------------------------------------
static const char toEOL = '\x5';
static const char toGET = '\x6';
static const char toHEAD = '\x7';
static const char toPUT = '\x8';
static const char toDELETE = '\x9';
static const char toPOST = '\xa';
static const char toPATCH = '\xb';
static const char toCOPY = '\xc';
static const char toUserAgent = '\xd';
static const char toAccept = '\xe';
static const char toContentType = '\xf';
static const char toContentLength = '\x10';
static const char toReferer = '\x11';
static const char toAuthorization = '\x12';
static const char toCacheControl = '\x13';
static const char toDate = '\x14';
static const char toFrom = '\x15';
static const char toHost = '\x16';
static const char toIfModified = '\x17';
static const char toContentEncoding = '\x18';
static const char toContentVersion = '\x19';
static const char toAllow = '\x1a';
static const char toConnection = '\x1b';
static const char toCookie = '\x1c';
static const Word hcGET = 0x14f5;
static const Word hcPUT = 0x4af5;
static const Word hcDELETE = 0x92b2;
static const Word hcPOST = 0x361d;
static const Word hcCacheControl = 0x4ff6;
static const Word hcDate = 0xee6;
static const Word hcFrom = 0x418f;
static const Word hcHost = 0x3611;
static const Word hcIfModified = 0xddf0;
static const Word hcAllow = 0x3d80;
static const Word hcUserAgent = 0xe890;
static const Word hcAccept = 0x1844;
static const Word hcContentEncoding = 0xc586;
static const Word hcContentVersion = 0xedf4;
static const Word hcContentType = 0xf0e0;
static const Word hcContentLength = 0xb0c4;
static const Word hcReferer = 0xcea5;
static const Word hcAuthorization = 0xabca;
static const Word hcConnection = 0xede;
static const Word hcCookie = 0x27b3;
#define DateFormat "ddd, dd mmm yyyy hh:mm:ss"
extern PACKAGE AnsiString Methods[5];
extern PACKAGE char __fastcall HexToChar(char Hi, char Lo);

}	/* namespace Svrhttp */
using namespace Svrhttp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SvrHTTP
