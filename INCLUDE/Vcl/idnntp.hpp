// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdNNTP.pas' rev: 6.00

#ifndef IdNNTPHPP
#define IdNNTPHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdComponent.hpp>	// Pascal unit
#include <IdTCPClient.hpp>	// Pascal unit
#include <IdMessageClient.hpp>	// Pascal unit
#include <IdMessage.hpp>	// Pascal unit
#include <IdTCPConnection.hpp>	// Pascal unit
#include <IdGlobal.hpp>	// Pascal unit
#include <IdException.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idnntp
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TModeType { mtStream, mtIHAVE, mtReader };
#pragma option pop

#pragma option push -b-
enum TConnectionResult { crCanPost, crNoPost, crAuthRequired, crTempUnavailable };
#pragma option pop

#pragma option push -b-
enum TModeSetResult { mrCanStream, mrNoStream, mrCanIHAVE, mrNoIHAVE, mrCanPost, mrNoPost };
#pragma option pop

typedef void __fastcall (__closure *TEventStreaming)(const AnsiString AMesgID, bool &AAccepted);

typedef void __fastcall (__closure *TNewsTransportEvent)(Classes::TStringList* AMsg);

typedef void __fastcall (__closure *TEventNewsgroupList)(const AnsiString ANewsgroup, const unsigned ALow, const unsigned AHigh, const AnsiString AType, bool &ACanContinue);

typedef void __fastcall (__closure *TEventNewNewsList)(const AnsiString AMsgID, bool &ACanContinue);

class DELPHICLASS TIdNNTP;
class PASCALIMPLEMENTATION TIdNNTP : public Idmessageclient::TIdMessageClient 
{
	typedef Idmessageclient::TIdMessageClient inherited;
	
protected:
	unsigned FlMsgHigh;
	unsigned FlMsgLow;
	unsigned FlMsgNo;
	AnsiString FsMsgID;
	unsigned FlMsgCount;
	AnsiString FNewsAgent;
	TEventNewsgroupList FOnNewsgroupList;
	TEventNewsgroupList FOnNewGroupsList;
	TEventNewNewsList FOnNewNewsList;
	TNewsTransportEvent fOnSendCheck;
	TNewsTransportEvent fOnSendTakethis;
	TModeType fModeType;
	TConnectionResult fConectionResult;
	TModeSetResult fModeResult;
	TNewsTransportEvent fOnSendIHAVE;
	bool FbSetMode;
	AnsiString fPassword;
	AnsiString fUserId;
	AnsiString __fastcall ConvertDateTimeDist(System::TDateTime ADate, bool AGMT, const AnsiString ADistributions);
	void __fastcall SetModeType(const TModeType AValue);
	void __fastcall setConnectionResult(const TConnectionResult AValue);
	void __fastcall SetModeResult(const TModeSetResult AValue);
	bool __fastcall Get(const AnsiString ACmd, const unsigned AMsgNo, const AnsiString AMsgID, Idmessage::TIdMessage* AMsg);
	bool __fastcall SetArticle(const AnsiString ACmd, const unsigned AMsgNo, const AnsiString AMsgID);
	void __fastcall ProcessGroupList(const AnsiString ACmd, const int AResponse, const TEventNewsgroupList AListEvent);
	
public:
	__fastcall virtual TIdNNTP(Classes::TComponent* AOwner);
	virtual void __fastcall Connect(void);
	virtual void __fastcall Disconnect(void);
	bool __fastcall GetArticle(const unsigned AMsgNo, const AnsiString AMsgID, Idmessage::TIdMessage* AMsg);
	bool __fastcall GetBody(const unsigned AMsgNo, const AnsiString AMsgID, Idmessage::TIdMessage* AMsg);
	bool __fastcall GetHeader(const unsigned AMsgNo, const AnsiString AMsgID, Idmessage::TIdMessage* AMsg);
	void __fastcall GetNewsgroupList(void)/* overload */;
	void __fastcall GetNewsgroupList(Classes::TStrings* AList)/* overload */;
	void __fastcall GetNewGroupsList(const System::TDateTime ADate, const bool AGMT, const AnsiString ADistributions)/* overload */;
	void __fastcall GetNewGroupsList(const System::TDateTime ADate, const bool AGMT, const AnsiString ADistributions, Classes::TStrings* AList)/* overload */;
	void __fastcall GetNewNewsList(const AnsiString ANewsgroups, const System::TDateTime ADate, const bool AGMT, AnsiString ADistributions)/* overload */;
	void __fastcall GetNewNewsList(const AnsiString ANewsgroups, const System::TDateTime ADate, const bool AGMT, AnsiString ADistributions, Classes::TStrings* AList)/* overload */;
	void __fastcall GetOverviewFMT(Classes::TStringList* &AResponse);
	bool __fastcall Next(void);
	bool __fastcall Previous(void);
	bool __fastcall SelectArticle(const unsigned AMsgNo);
	void __fastcall SelectGroup(const AnsiString AGroup);
	void __fastcall Send(Idmessage::TIdMessage* AMsg);
	void __fastcall SendIHAVE(Classes::TStringList* AMsg);
	void __fastcall SendCheck(Classes::TStringList* AMsgID, Classes::TStringList* &AResponses);
	virtual short __fastcall SendCmd(const AnsiString AOut, const short * AResponse, const int AResponse_Size)/* overload */;
	AnsiString __fastcall SendTakeThis(Classes::TStringList* AMsg);
	void __fastcall SendXHDR(const AnsiString AHeader, const AnsiString AParam, Classes::TStringList* &AResponse);
	void __fastcall SendXOVER(const AnsiString AParm, Classes::TStringList* &AResponse);
	__property AnsiString MsgID = {read=FsMsgID};
	__property unsigned MsgNo = {read=FlMsgNo, nodefault};
	__property unsigned MsgHigh = {read=FlMsgHigh, nodefault};
	__property unsigned MsgLow = {read=FlMsgLow, nodefault};
	__property TConnectionResult GreetingResult = {read=fConectionResult, write=setConnectionResult, nodefault};
	__property TModeSetResult ModeResult = {read=fModeResult, write=SetModeResult, nodefault};
	__property unsigned MsgCount = {read=FlMsgCount, write=FlMsgCount, nodefault};
	
__published:
	__property AnsiString NewsAgent = {read=FNewsAgent, write=FNewsAgent};
	__property TModeType Mode = {read=fModeType, write=SetModeType, default=2};
	__property AnsiString Password = {read=fPassword, write=fPassword};
	__property AnsiString UserId = {read=fUserId, write=fUserId};
	__property bool SetMode = {read=FbSetMode, write=FbSetMode, default=1};
	__property TNewsTransportEvent OnSendCheck = {read=fOnSendCheck, write=fOnSendCheck};
	__property TNewsTransportEvent OnSendIHAVE = {read=fOnSendIHAVE, write=fOnSendIHAVE};
	__property TNewsTransportEvent OnSendTakeThis = {read=fOnSendTakethis, write=fOnSendTakethis};
	__property TEventNewsgroupList OnNewsgroupList = {read=FOnNewsgroupList, write=FOnNewsgroupList};
	__property TEventNewsgroupList OnNewGroupsList = {read=FOnNewGroupsList, write=FOnNewGroupsList};
	__property TEventNewNewsList OnNewNewsList = {read=FOnNewNewsList, write=FOnNewNewsList};
	__property Port  = {default=119};
public:
	#pragma option push -w-inl
	/* TIdTCPClient.Destroy */ inline __fastcall virtual ~TIdNNTP(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline short __fastcall  SendCmd(const AnsiString AOut, const short AResponse = (short)(0xffffffff)){ return TIdTCPConnection::SendCmd(AOut, AResponse); }
	
};


class DELPHICLASS EIdNNTPException;
class PASCALIMPLEMENTATION EIdNNTPException : public Idexception::EIdException 
{
	typedef Idexception::EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdNNTPException(const AnsiString Msg) : Idexception::EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdNNTPException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdNNTPException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdNNTPException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdNNTPException(const AnsiString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNNTPException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdNNTPException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNNTPException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdNNTPException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdNNTPNoOnNewGroupsList;
class PASCALIMPLEMENTATION EIdNNTPNoOnNewGroupsList : public EIdNNTPException 
{
	typedef EIdNNTPException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdNNTPNoOnNewGroupsList(const AnsiString Msg) : EIdNNTPException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdNNTPNoOnNewGroupsList(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdNNTPException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdNNTPNoOnNewGroupsList(int Ident)/* overload */ : EIdNNTPException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdNNTPNoOnNewGroupsList(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdNNTPException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdNNTPNoOnNewGroupsList(const AnsiString Msg, int AHelpContext) : EIdNNTPException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNNTPNoOnNewGroupsList(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdNNTPException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdNNTPNoOnNewGroupsList(int Ident, int AHelpContext)/* overload */ : EIdNNTPException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNNTPNoOnNewGroupsList(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdNNTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdNNTPNoOnNewGroupsList(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdNNTPNoOnNewNewsList;
class PASCALIMPLEMENTATION EIdNNTPNoOnNewNewsList : public EIdNNTPException 
{
	typedef EIdNNTPException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdNNTPNoOnNewNewsList(const AnsiString Msg) : EIdNNTPException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdNNTPNoOnNewNewsList(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdNNTPException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdNNTPNoOnNewNewsList(int Ident)/* overload */ : EIdNNTPException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdNNTPNoOnNewNewsList(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdNNTPException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdNNTPNoOnNewNewsList(const AnsiString Msg, int AHelpContext) : EIdNNTPException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNNTPNoOnNewNewsList(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdNNTPException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdNNTPNoOnNewNewsList(int Ident, int AHelpContext)/* overload */ : EIdNNTPException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNNTPNoOnNewNewsList(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdNNTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdNNTPNoOnNewNewsList(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdNNTPNoOnNewsgroupList;
class PASCALIMPLEMENTATION EIdNNTPNoOnNewsgroupList : public EIdNNTPException 
{
	typedef EIdNNTPException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdNNTPNoOnNewsgroupList(const AnsiString Msg) : EIdNNTPException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdNNTPNoOnNewsgroupList(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdNNTPException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdNNTPNoOnNewsgroupList(int Ident)/* overload */ : EIdNNTPException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdNNTPNoOnNewsgroupList(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdNNTPException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdNNTPNoOnNewsgroupList(const AnsiString Msg, int AHelpContext) : EIdNNTPException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNNTPNoOnNewsgroupList(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdNNTPException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdNNTPNoOnNewsgroupList(int Ident, int AHelpContext)/* overload */ : EIdNNTPException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNNTPNoOnNewsgroupList(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdNNTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdNNTPNoOnNewsgroupList(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdNNTPStringListNotInitialized;
class PASCALIMPLEMENTATION EIdNNTPStringListNotInitialized : public EIdNNTPException 
{
	typedef EIdNNTPException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdNNTPStringListNotInitialized(const AnsiString Msg) : EIdNNTPException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdNNTPStringListNotInitialized(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdNNTPException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdNNTPStringListNotInitialized(int Ident)/* overload */ : EIdNNTPException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdNNTPStringListNotInitialized(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdNNTPException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdNNTPStringListNotInitialized(const AnsiString Msg, int AHelpContext) : EIdNNTPException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNNTPStringListNotInitialized(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdNNTPException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdNNTPStringListNotInitialized(int Ident, int AHelpContext)/* overload */ : EIdNNTPException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNNTPStringListNotInitialized(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdNNTPException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdNNTPStringListNotInitialized(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdNNTPConnectionRefused;
class PASCALIMPLEMENTATION EIdNNTPConnectionRefused : public Idexception::EIdProtocolReplyError 
{
	typedef Idexception::EIdProtocolReplyError inherited;
	
public:
	#pragma option push -w-inl
	/* EIdProtocolReplyError.CreateError */ inline __fastcall virtual EIdNNTPConnectionRefused(const int anErrCode, const AnsiString asReplyMessage) : Idexception::EIdProtocolReplyError(anErrCode, asReplyMessage) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdNNTPConnectionRefused(const AnsiString Msg) : Idexception::EIdProtocolReplyError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdNNTPConnectionRefused(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Idexception::EIdProtocolReplyError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdNNTPConnectionRefused(int Ident)/* overload */ : Idexception::EIdProtocolReplyError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdNNTPConnectionRefused(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Idexception::EIdProtocolReplyError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdNNTPConnectionRefused(const AnsiString Msg, int AHelpContext) : Idexception::EIdProtocolReplyError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdNNTPConnectionRefused(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Idexception::EIdProtocolReplyError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdNNTPConnectionRefused(int Ident, int AHelpContext)/* overload */ : Idexception::EIdProtocolReplyError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdNNTPConnectionRefused(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdProtocolReplyError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdNNTPConnectionRefused(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ParseXOVER(AnsiString Aline, unsigned &AArticleIndex, AnsiString &ASubject, AnsiString &AFrom, System::TDateTime &ADate, AnsiString &AMsgId, AnsiString &AReferences, unsigned &AByteCount, unsigned &ALineCount, AnsiString &AExtraData);
extern PACKAGE void __fastcall ParseNewsGroup(AnsiString ALine, AnsiString &ANewsGroup, unsigned &AHi, unsigned &ALo, AnsiString &AStatus);

}	/* namespace Idnntp */
using namespace Idnntp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdNNTP
