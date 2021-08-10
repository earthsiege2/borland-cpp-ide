// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdHTTP.pas' rev: 6.00

#ifndef IdHTTPHPP
#define IdHTTPHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdComponent.hpp>	// Pascal unit
#include <IdTCPConnection.hpp>	// Pascal unit
#include <IdTCPClient.hpp>	// Pascal unit
#include <IdSSLIntercept.hpp>	// Pascal unit
#include <IdHeaderList.hpp>	// Pascal unit
#include <IdGlobal.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idhttp
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdHTTPMethod { hmHead, hmGet, hmPost };
#pragma option pop

#pragma option push -b-
enum TIdHTTPProtocolVersion { pv1_0, pv1_1 };
#pragma option pop

typedef void __fastcall (__closure *TIdHTTPOnRedirectEvent)(System::TObject* Sender, AnsiString &dest, int &NumRedirect, bool &Handled);

class DELPHICLASS TIdHeaderInfo;
class PASCALIMPLEMENTATION TIdHeaderInfo : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
protected:
	AnsiString FAccept;
	AnsiString FAcceptCharSet;
	AnsiString FAcceptEncoding;
	AnsiString FAcceptLanguage;
	Classes::TComponent* FComponent;
	AnsiString FConnection;
	AnsiString FContentEncoding;
	AnsiString FContentLanguage;
	int FContentLength;
	unsigned FContentRangeEnd;
	unsigned FContentRangeStart;
	AnsiString FContentType;
	AnsiString FContentVersion;
	System::TDateTime FDate;
	System::TDateTime FExpires;
	Idheaderlist::TIdHeaderList* FExtraHeaders;
	AnsiString FFrom;
	System::TDateTime FLastModified;
	AnsiString FLocation;
	AnsiString FPassword;
	AnsiString FProxyAuthenticate;
	AnsiString FProxyPassword;
	int FProxyPort;
	AnsiString FProxyServer;
	AnsiString FProxyUsername;
	AnsiString FReferer;
	AnsiString FServer;
	AnsiString FUserAgent;
	AnsiString FUserName;
	AnsiString FWWWAuthenticate;
	virtual void __fastcall AssignTo(Classes::TPersistent* Destination);
	void __fastcall GetHeaders(Idheaderlist::TIdHeaderList* Headers);
	void __fastcall SetHeaders(Idheaderlist::TIdHeaderList* &Headers);
	void __fastcall SetExtraHeaders(const Idheaderlist::TIdHeaderList* Value);
	
public:
	void __fastcall Clear(void);
	__fastcall virtual TIdHeaderInfo(Classes::TComponent* Component);
	__fastcall virtual ~TIdHeaderInfo(void);
	
__published:
	__property AnsiString Accept = {read=FAccept, write=FAccept};
	__property AnsiString AcceptCharSet = {read=FAcceptCharSet, write=FAcceptCharSet};
	__property AnsiString AcceptEncoding = {read=FAcceptEncoding, write=FAcceptEncoding};
	__property AnsiString AcceptLanguage = {read=FAcceptLanguage, write=FAcceptLanguage};
	__property AnsiString Connection = {read=FConnection, write=FConnection};
	__property AnsiString ContentEncoding = {read=FContentEncoding, write=FContentEncoding};
	__property AnsiString ContentLanguage = {read=FContentLanguage, write=FContentLanguage};
	__property int ContentLength = {read=FContentLength, write=FContentLength, nodefault};
	__property unsigned ContentRangeEnd = {read=FContentRangeEnd, write=FContentRangeEnd, nodefault};
	__property unsigned ContentRangeStart = {read=FContentRangeStart, write=FContentRangeStart, nodefault};
	__property AnsiString ContentType = {read=FContentType, write=FContentType};
	__property AnsiString ContentVersion = {read=FContentVersion, write=FContentVersion};
	__property System::TDateTime Date = {read=FDate, write=FDate};
	__property System::TDateTime Expires = {read=FExpires, write=FExpires};
	__property Idheaderlist::TIdHeaderList* ExtraHeaders = {read=FExtraHeaders, write=SetExtraHeaders};
	__property AnsiString From = {read=FFrom, write=FFrom};
	__property System::TDateTime LastModified = {read=FLastModified, write=FLastModified};
	__property AnsiString Location = {read=FLocation, write=FLocation};
	__property AnsiString Password = {read=FPassword, write=FPassword};
	__property AnsiString ProxyAuthenticate = {read=FProxyAuthenticate, write=FProxyAuthenticate};
	__property AnsiString ProxyPassword = {read=FProxyPassword, write=FProxyPassword};
	__property int ProxyPort = {read=FProxyPort, write=FProxyPort, nodefault};
	__property AnsiString ProxyServer = {read=FProxyServer, write=FProxyServer};
	__property AnsiString ProxyUsername = {read=FProxyUsername, write=FProxyUsername};
	__property AnsiString Referer = {read=FReferer, write=FReferer};
	__property AnsiString Server = {read=FServer, write=FServer};
	__property AnsiString UserAgent = {read=FUserAgent, write=FUserAgent};
	__property AnsiString Username = {read=FUserName, write=FUserName};
	__property AnsiString WWWAuthenticate = {read=FWWWAuthenticate, write=FWWWAuthenticate};
};


class DELPHICLASS TIdHTTP;
class PASCALIMPLEMENTATION TIdHTTP : public Idtcpclient::TIdTCPClient 
{
	typedef Idtcpclient::TIdTCPClient inherited;
	
protected:
	Idheaderlist::TIdHeaderList* FInternalHeaders;
	TIdHTTPProtocolVersion FProtocolVersion;
	int FRedirectCount;
	int FRedirectMax;
	TIdHeaderInfo* FRequest;
	TIdHeaderInfo* FResponse;
	int FResponseCode;
	AnsiString FResponseText;
	bool FHandleRedirects;
	AnsiString FTunnelProxyHost;
	int FTunnelProxyPort;
	AnsiString FTunnelProxyProtocol;
	TIdHTTPOnRedirectEvent FOnRedirect;
	virtual bool __fastcall DoOnRedirect(AnsiString &Location, int RedirectCount);
	void __fastcall RetrieveHeaders(void);
	void __fastcall DoProxyConnectMethod(System::TObject* ASender);
	
public:
	AnsiString HostHeader;
	AnsiString ProtoHeader;
	__fastcall virtual TIdHTTP(Classes::TComponent* AOwner);
	__fastcall virtual ~TIdHTTP(void);
	virtual void __fastcall DoRequest(const TIdHTTPMethod AMethod, AnsiString AURL, const System::TObject* ASource, const Classes::TStream* AResponseContent);
	void __fastcall Get(AnsiString AURL, const Classes::TStream* AResponseContent)/* overload */;
	AnsiString __fastcall Get(AnsiString AURL)/* overload */;
	void __fastcall Head(AnsiString URL);
	void __fastcall Post(AnsiString URL, const Classes::TStrings* Source, const Classes::TStream* AResponseContent)/* overload */;
	void __fastcall Post(AnsiString URL, const Classes::TStream* Source, const Classes::TStream* AResponseContent)/* overload */;
	__property int ResponseCode = {read=FResponseCode, nodefault};
	__property AnsiString ResponseText = {read=FResponseText};
	__property TIdHeaderInfo* Response = {read=FResponse};
	
__published:
	__property bool HandleRedirects = {read=FHandleRedirects, write=FHandleRedirects, default=0};
	__property TIdHTTPProtocolVersion ProtocolVersion = {read=FProtocolVersion, write=FProtocolVersion, default=1};
	__property int RedirectMaximum = {read=FRedirectMax, write=FRedirectMax, default=15};
	__property TIdHeaderInfo* Request = {read=FRequest, write=FRequest};
	__property TIdHTTPOnRedirectEvent OnRedirect = {read=FOnRedirect, write=FOnRedirect};
	__property Port  = {default=80};
};


//-- var, const, procedure ---------------------------------------------------
#define Id_TIdHTTP_ProtocolVersion (TIdHTTPProtocolVersion)(1)
static const Shortint Id_TIdHTTP_RedirectMax = 0xf;
static const bool Id_TIdHTTP_HandleRedirects = false;

}	/* namespace Idhttp */
using namespace Idhttp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdHTTP
