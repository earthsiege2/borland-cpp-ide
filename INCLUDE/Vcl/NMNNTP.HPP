// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NMNNTP.pas' rev: 5.00

#ifndef NMNNTPHPP
#define NMNNTPHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <NMConst.hpp>	// Pascal unit
#include <NMExtstr.hpp>	// Pascal unit
#include <NMUUE.hpp>	// Pascal unit
#include <Psock.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Nmnntp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TPostRecordType;
class PASCALIMPLEMENTATION TPostRecordType : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Nmextstr::TExStringList* FPostheader;
	AnsiString __fastcall GetPrFromAddress();
	void __fastcall SetPrFromAddress(AnsiString index);
	AnsiString __fastcall GetPrReplyTo();
	void __fastcall SetPrReplyTo(AnsiString index);
	AnsiString __fastcall GetPrSubject();
	void __fastcall SetPrSubject(AnsiString index);
	AnsiString __fastcall GetPrDistribution();
	void __fastcall SetPrDistribution(AnsiString index);
	AnsiString __fastcall GetPrAppName();
	void __fastcall SetPrAppName(AnsiString index);
	AnsiString __fastcall GetPrTimeDate();
	void __fastcall SetPrTimeDate(AnsiString index);
	AnsiString __fastcall GetNewsGroups();
	void __fastcall SetNewsGroups(AnsiString index);
	int __fastcall GetArticleId(void);
	int __fastcall GetPrByteCount(void);
	int __fastcall GetPrLineCount(void);
	
__published:
	__property AnsiString PrFromAddress = {read=GetPrFromAddress, write=SetPrFromAddress};
	__property AnsiString PrReplyTo = {read=GetPrReplyTo, write=SetPrReplyTo};
	__property AnsiString PrSubject = {read=GetPrSubject, write=SetPrSubject};
	__property AnsiString PrDistribution = {read=GetPrDistribution, write=SetPrDistribution};
	__property AnsiString PrAppName = {read=GetPrAppName, write=SetPrAppName};
	__property AnsiString PrTimeDate = {read=GetPrTimeDate, write=SetPrTimeDate};
	__property AnsiString PrNewsGroups = {read=GetNewsGroups, write=SetNewsGroups};
	__property int PrByteCount = {read=GetPrByteCount, nodefault};
	__property int PrLineCount = {read=GetPrLineCount, nodefault};
	__property int PrArticleId = {read=GetArticleId, nodefault};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TPostRecordType(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TPostRecordType(void) : Classes::TPersistent() { }
	#pragma option pop
	
};


#pragma option push -b-
enum TCacheMode { cmMixed, cmRemote, cmLocal };
#pragma option pop

class DELPHICLASS NNTPError;
class PASCALIMPLEMENTATION NNTPError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall NNTPError(const AnsiString Msg) : Sysutils::Exception(Msg)
		 { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall NNTPError(const AnsiString Msg, const System::TVarRec * 
		Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall NNTPError(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall NNTPError(int Ident, const System::TVarRec * Args, const 
		int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall NNTPError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(
		Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall NNTPError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall NNTPError(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall NNTPError(System::PResStringRec ResStringRec, const 
		System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~NNTPError(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TGroupRetrievedEvent)(AnsiString name, int FirstArticle, int LastArticle
	, bool Posting);

typedef void __fastcall (__closure *TGroupRetrievedCacheEvent)(bool &Handled, AnsiString name, int FirstArticle
	, int LastArticle, bool Posting);

typedef void __fastcall (__closure *THeaderEvent)(int IdNo, AnsiString From, AnsiString Subject, AnsiString 
	MsgId, AnsiString Date, int NumberLines);

typedef void __fastcall (__closure *THeaderCacheEvent)(bool &Handled, int IdNo, AnsiString From, AnsiString 
	Subject, AnsiString MsgId, AnsiString Date, int ArticleNo);

typedef void __fastcall (__closure *TVarFileNameEvent)(AnsiString &FileName);

class DELPHICLASS TNMNNTP;
class PASCALIMPLEMENTATION TNMNNTP : public Psock::TPowersock 
{
	typedef Psock::TPowersock inherited;
	
private:
	int FTransType;
	AnsiString FUserId;
	AnsiString FPassword;
	TCacheMode FCacheMode;
	bool FParseAttachments;
	bool FPosting;
	AnsiString FSelectedGroup;
	int FLoMessage;
	int FHiMessage;
	Nmextstr::TExStringList* FHeader;
	TPostRecordType* FHeaderRecord;
	Nmextstr::TExStringList* FBody;
	Classes::TStringList* FAttachments;
	Nmextstr::TExStringList* FPostHeader;
	TPostRecordType* FPostRecord;
	Nmextstr::TExStringList* FPostBody;
	Classes::TStringList* FPostAttachments;
	Classes::TStringList* FArticleList;
	AnsiString FAttachmentPath;
	Classes::TStringList* FGroupList;
	AnsiString FNewsDir;
	bool FTransactionInProgress;
	AnsiString FBoundary;
	int FCurrentArticle;
	int WaitforReset;
	TVarFileNameEvent FOnDecodeStart;
	Classes::TNotifyEvent FOnDecodeEnd;
	Classes::TNotifyEvent FOnConnect;
	Classes::TNotifyEvent FOnGroupSelect;
	TGroupRetrievedEvent FOnGroupListUpdate;
	TGroupRetrievedCacheEvent FOnGroupListCacheUpdate;
	Psock::THandlerEvent FOnGroupSelectRequired;
	Classes::TNotifyEvent FOnHeaderList;
	Psock::THandlerEvent FOnHeaderListCacheUpdate;
	Classes::TNotifyEvent FOnHeader;
	THeaderCacheEvent FOnHeaderCacheUpdate;
	Classes::TNotifyEvent FOnArticle;
	THeaderCacheEvent FOnArticleCacheUpdate;
	Classes::TNotifyEvent FOnBody;
	Psock::THandlerEvent FOnBodyCacheUpdate;
	Psock::THandlerEvent FOnAuthenticationNeeded;
	Classes::TNotifyEvent FOnAuthenticationFailed;
	Classes::TNotifyEvent FOnAbort;
	Classes::TNotifyEvent FOnPosted;
	Psock::TOnErrorEvent FOnPostFailed;
	Classes::TNotifyEvent FOnInvalidArticle;
	void __fastcall InternalConnect(void);
	void __fastcall RetreiveArticle(int HBMode, int Ref);
	void __fastcall RetreiveList(int AGMode, int Ref);
	void __fastcall AbortResume(System::TObject* Sender);
	void __fastcall SetAttachmentPath(AnsiString Path);
	void __fastcall SetNewsDir(AnsiString Dir);
	bool __fastcall ReadTillDot(Classes::TStringList* DestinationList, AnsiString Command);
	void __fastcall ReadTillBlankLine(int Ref);
	void __fastcall Readfromcache(Classes::TStringList* DestinationList, int ArticleNo);
	void __fastcall ExtractAttachments(void);
	void __fastcall ExtractEmbedded(void);
	void __fastcall ExtractMultipart(void);
	void __fastcall Decode(Classes::TStream* AStream, AnsiString &TFileName);
	void __fastcall SetPostAttachments(Classes::TStringList* Value);
	void __fastcall SetPostBody(Nmextstr::TExStringList* Value);
	void __fastcall SetPostHeader(Nmextstr::TExStringList* Value);
	
public:
	__fastcall virtual TNMNNTP(Classes::TComponent* AOwner);
	__fastcall virtual ~TNMNNTP(void);
	virtual void __fastcall Connect(void);
	virtual void __fastcall Disconnect(void);
	virtual void __fastcall Abort(void);
	void __fastcall SetGroup(AnsiString Group);
	void __fastcall PostArticle(void);
	void __fastcall GetArticle(int Ref);
	void __fastcall GetArticleHeader(int Ref);
	void __fastcall GetArticleBody(int Ref);
	void __fastcall GetGroupList(void);
	void __fastcall GetArticleList(bool All, int ArticleNumber);
	virtual AnsiString __fastcall Transaction(const AnsiString CommandString);
	__property AnsiString SelectedGroup = {read=FSelectedGroup};
	__property int LoMessage = {read=FLoMessage, nodefault};
	__property int HiMessage = {read=FHiMessage, nodefault};
	__property bool Posting = {read=FPosting, nodefault};
	__property Nmextstr::TExStringList* Header = {read=FHeader};
	__property TPostRecordType* HeaderRecord = {read=FHeaderRecord, write=FHeaderRecord};
	__property Nmextstr::TExStringList* Body = {read=FBody};
	__property Classes::TStringList* Attachments = {read=FAttachments};
	__property Classes::TStringList* GroupList = {read=FGroupList};
	__property int CurrentArticle = {read=FCurrentArticle, nodefault};
	
__published:
	__property OnPacketRecvd ;
	__property AnsiString UserId = {read=FUserId, write=FUserId};
	__property AnsiString Password = {read=FPassword, write=FPassword};
	__property TCacheMode CacheMode = {read=FCacheMode, write=FCacheMode, nodefault};
	__property bool ParseAttachments = {read=FParseAttachments, write=FParseAttachments, nodefault};
	__property AnsiString AttachFilePath = {read=FAttachmentPath, write=SetAttachmentPath};
	__property AnsiString NewsDir = {read=FNewsDir, write=SetNewsDir};
	__property Nmextstr::TExStringList* PostHeader = {read=FPostHeader, write=SetPostHeader};
	__property Nmextstr::TExStringList* PostBody = {read=FPostBody, write=SetPostBody};
	__property Classes::TStringList* PostAttachments = {read=FPostAttachments, write=SetPostAttachments
		};
	__property TPostRecordType* PostRecord = {read=FPostRecord, write=FPostRecord};
	__property OnConnectionRequired ;
	__property Classes::TNotifyEvent OnConnect = {read=FOnConnect, write=FOnConnect};
	__property Classes::TNotifyEvent OnGroupSelect = {read=FOnGroupSelect, write=FOnGroupSelect};
	__property TGroupRetrievedEvent OnGroupListUpdate = {read=FOnGroupListUpdate, write=FOnGroupListUpdate
		};
	__property TGroupRetrievedCacheEvent OnGroupListCacheUpdate = {read=FOnGroupListCacheUpdate, write=
		FOnGroupListCacheUpdate};
	__property Psock::THandlerEvent OnGroupSelectRequired = {read=FOnGroupSelectRequired, write=FOnGroupSelectRequired
		};
	__property Classes::TNotifyEvent OnHeaderList = {read=FOnHeaderList, write=FOnHeaderList};
	__property Psock::THandlerEvent OnHeaderListCacheUpdate = {read=FOnHeaderListCacheUpdate, write=FOnHeaderListCacheUpdate
		};
	__property Classes::TNotifyEvent OnHeader = {read=FOnHeader, write=FOnHeader};
	__property THeaderCacheEvent OnHeaderCacheUpdate = {read=FOnHeaderCacheUpdate, write=FOnHeaderCacheUpdate
		};
	__property Classes::TNotifyEvent OnArticle = {read=FOnArticle, write=FOnArticle};
	__property THeaderCacheEvent OnArticleCacheUpdate = {read=FOnArticleCacheUpdate, write=FOnArticleCacheUpdate
		};
	__property Classes::TNotifyEvent OnBody = {read=FOnBody, write=FOnBody};
	__property Psock::THandlerEvent OnBodyCacheUpdate = {read=FOnBodyCacheUpdate, write=FOnBodyCacheUpdate
		};
	__property Psock::THandlerEvent OnAuthenticationNeeded = {read=FOnAuthenticationNeeded, write=FOnAuthenticationNeeded
		};
	__property Classes::TNotifyEvent OnAuthenticationFailed = {read=FOnAuthenticationFailed, write=FOnAuthenticationFailed
		};
	__property Classes::TNotifyEvent OnAbort = {read=FOnAbort, write=FOnAbort};
	__property Classes::TNotifyEvent OnPosted = {read=FOnPosted, write=FOnPosted};
	__property Psock::TOnErrorEvent OnPostFailed = {read=FOnPostFailed, write=FOnPostFailed};
	__property Classes::TNotifyEvent OnInvalidArticle = {read=FOnInvalidArticle, write=FOnInvalidArticle
		};
	__property TVarFileNameEvent OnDecodeStart = {read=FOnDecodeStart, write=FOnDecodeStart};
	__property Classes::TNotifyEvent OnDecodeEnd = {read=FOnDecodeEnd, write=FOnDecodeEnd};
};


typedef AnsiString NMNNTP__4[9];

//-- var, const, procedure ---------------------------------------------------
static const Shortint Trans_None = 0x0;
static const Shortint Trans_List = 0x1;
#define Cons_USerCmd "USER "
#define Cons_PassCmd "PASS "
#define Cons_QuitCmd "QUIT"
#define Cons_GrpCmd "GROUP "
#define Cons_GrpPost "POST"
#define Cons_GrpArtl "ARTICLE "
#define Cons_GrpList "LIST"
#define Cons_GrpHead "HEAD "
#define Cons_GrpBody "BODY "
#define Cons_HdCSubj "SUBJECT:"
#define Cons_HdCFrom "FROM:"
#define Cons_HdCType "CONTENT-TYPE:"
#define Cons_HdCMId "MESSAGE-ID:"
#define Cons_HdDate "DATE:"
#define Cons_HdLine "LINES:"
#define Cons_HdFrom "From: "
#define Cons_HdSubj "Subject: "
#define Cons_HdRply "Reply-To: "
#define Cons_HdNews "NewsGroups: "
#define Cons_HdDist "Distribution: "
#define Cons_HdOrgz "Organization: "
#define Cons_HdMime "Mime-Version: 1.0"
#define Cons_HdText "Content-Type: text/plain, charset=\"us-ascii\""
#define Cons_HdMult "Content-Type: multipart/mixed;      boundary=\""
#define Cons_HdApp "Content-Type: application/octet-stream;  name=\""
#define Cons_HdBase64 "Content-Transfer-Encoding: base64"
#define Cons_HdDisp "Content-Disposition: attachment; filename=\""
extern PACKAGE AnsiString Stable[9];

}	/* namespace Nmnntp */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Nmnntp;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NMNNTP
