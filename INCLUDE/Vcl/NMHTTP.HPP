// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NMHttp.pas' rev: 5.00

#ifndef NMHttpHPP
#define NMHttpHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <WinSock.hpp>	// Pascal unit
#include <NMURL.hpp>	// Pascal unit
#include <NMUUE.hpp>	// Pascal unit
#include <NMConst.hpp>	// Pascal unit
#include <NMExtstr.hpp>	// Pascal unit
#include <Psock.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Nmhttp
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum CmdType { CmdGET, CmdOPTIONS, CmdHEAD, CmdPOST, CmdPUT, CmdPATCH, CmdCOPY, CmdMOVE, CmdDELETE, 
	CmdLINK, CmdUNLINK, CmdTRACE, CmdWRAPPED };
#pragma option pop

class DELPHICLASS HTTPException;
class PASCALIMPLEMENTATION HTTPException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall HTTPException(const AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall HTTPException(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall HTTPException(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall HTTPException(int Ident, const System::TVarRec * Args
		, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall HTTPException(const AnsiString Msg, int AHelpContext) : 
		Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall HTTPException(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall HTTPException(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall HTTPException(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~HTTPException(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TResultEvent)(CmdType Cmd);

class DELPHICLASS THeaderInfo;
class PASCALIMPLEMENTATION THeaderInfo : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	AnsiString FLocalAddress;
	AnsiString FLocalProgram;
	AnsiString FCookie;
	AnsiString FReferer;
	AnsiString FUserId;
	AnsiString FPassword;
	
__published:
	__property AnsiString LocalMailAddress = {read=FLocalAddress, write=FLocalAddress};
	__property AnsiString LocalProgram = {read=FLocalProgram, write=FLocalProgram};
	__property AnsiString Cookie = {read=FCookie, write=FCookie};
	__property AnsiString Referer = {read=FReferer, write=FReferer};
	__property AnsiString UserId = {read=FUserId, write=FUserId};
	__property AnsiString Password = {read=FPassword, write=FPassword};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~THeaderInfo(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall THeaderInfo(void) : Classes::TPersistent() { }
	#pragma option pop
	
};


class DELPHICLASS TNMHTTP;
class PASCALIMPLEMENTATION TNMHTTP : public Psock::TPowersock 
{
	typedef Psock::TPowersock inherited;
	
private:
	AnsiString FBody;
	AnsiString FHeader;
	AnsiString FSelector;
	Nmextstr::TExStringList* FSendHeader;
	AnsiString FLocation;
	THeaderInfo* FHeaderInfo;
	AnsiString FCookieIn;
	bool FInputFileMode;
	bool FOutPutFileMode;
	bool FEncodePosts;
	AnsiString TheSendFile;
	AnsiString TheDestURL;
	AnsiString URL_Holder;
	CmdType ConnType;
	TResultEvent FOnSuccess;
	TResultEvent FOnFailure;
	Classes::TNotifyEvent FOnAboutToSend;
	Psock::THandlerEvent FOnRedirect;
	Classes::TNotifyEvent FOnAuthenticationNeeded;
	
protected:
	virtual void __fastcall HTTPConnect(void);
	virtual void __fastcall ParseURL(void);
	virtual void __fastcall AssembleHTTPHeader(void);
	virtual void __fastcall RemoveHeader(void);
	virtual void __fastcall SendHTTP(void);
	
public:
	__fastcall virtual TNMHTTP(Classes::TComponent* AOwner);
	__fastcall virtual ~TNMHTTP(void);
	virtual void __fastcall Options(AnsiString URL);
	virtual void __fastcall Get(AnsiString URL);
	virtual void __fastcall Post(AnsiString URL, AnsiString PostData);
	virtual void __fastcall Put(AnsiString URL, AnsiString PutData);
	virtual void __fastcall Head(AnsiString URL);
	virtual void __fastcall Patch(AnsiString URL, AnsiString PatchData);
	virtual void __fastcall Delete(AnsiString URL);
	virtual void __fastcall Trace(AnsiString URL, AnsiString TraceData);
	virtual void __fastcall Copy(AnsiString URL1, AnsiString URL2);
	virtual void __fastcall Move(AnsiString URL1, AnsiString URL2);
	virtual void __fastcall Link(AnsiString URL, AnsiString link);
	virtual void __fastcall UnLink(AnsiString URL, AnsiString link);
	virtual void __fastcall Wrapped(AnsiString URL, AnsiString WrappedData);
	virtual void __fastcall Abort(void);
	__property Nmextstr::TExStringList* SendHeader = {read=FSendHeader, write=FSendHeader};
	__property AnsiString CookieIn = {read=FCookieIn};
	
__published:
	__property OnPacketRecvd ;
	__property OnPacketSent ;
	__property AnsiString Body = {read=FBody, write=FBody};
	__property AnsiString Header = {read=FHeader, write=FHeader};
	__property THeaderInfo* HeaderInfo = {read=FHeaderInfo, write=FHeaderInfo};
	__property bool InputFileMode = {read=FInputFileMode, write=FInputFileMode, nodefault};
	__property bool OutputFileMode = {read=FOutPutFileMode, write=FOutPutFileMode, nodefault};
	__property Classes::TNotifyEvent OnAboutToSend = {read=FOnAboutToSend, write=FOnAboutToSend};
	__property TResultEvent OnSuccess = {read=FOnSuccess, write=FOnSuccess};
	__property TResultEvent OnFailure = {read=FOnFailure, write=FOnFailure};
	__property Psock::THandlerEvent OnRedirect = {read=FOnRedirect, write=FOnRedirect};
	__property Classes::TNotifyEvent OnAuthenticationNeeded = {read=FOnAuthenticationNeeded, write=FOnAuthenticationNeeded
		};
	__property Proxy ;
	__property ProxyPort ;
};


//-- var, const, procedure ---------------------------------------------------
#define Prt_gopher "gopher"
#define Prt_ftp "ftp"
#define Prt_str_http " HTTP/1.0"
#define Prox_Head_Str "Proxy-Connection: Keep-Alive"
#define Prox_Host_Str "Host: "
#define Host_Accpt_Str1 "Accept: www/source, text/html, video/mpeg, image/jpeg, ima"\
	"ge/x-tiff"
#define Host_Accpt_Str2 "Accept: image/x-rgb, image/x-xbm, image/gif, */*, applicat"\
	"ion/postscript"
#define Host_UserAgent "User-Agent"
#define Head_From "From"
#define Head_Host "Host"
#define Head_Cookie "Cookie"
#define Head_Referer "Referer"
#define Head_Content "Content-type: application/x-www-form-urlencoded"
#define Head_Link "Link: "
#define Head_URI "URI-header: "
#define Head_ContentLength "Content-Length: "
#define Head_SetCookie "SET-COOKIE:"
#define Head_CL2 "CONTENT-LENGTH:"
#define Head_length "ENGTH:"
#define Head_Location "LOCATION:"
#define Cmd_Get "GET "
#define Cmd_Options "OPTIONS "
#define Cmd_Post "POST "
#define Cmd_Put "PUT "
#define Cmd_Head "HEAD "
#define Cmd_Patch "PATCH "
#define Cmd_Copy "COPY "
#define Cmd_Move "MOVE "
#define Cmd_Link "LINK "
#define Cmd_Unlink "UNLINK "
#define Cmd_Delete "DELETE "
#define Cmd_Trace "TRACE "

}	/* namespace Nmhttp */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Nmhttp;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NMHttp
