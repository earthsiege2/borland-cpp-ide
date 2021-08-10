// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdMessage.pas' rev: 6.00

#ifndef IdMessageHPP
#define IdMessageHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <IdHeaderList.hpp>	// Pascal unit
#include <IdEMailAddress.hpp>	// Pascal unit
#include <IdException.hpp>	// Pascal unit
#include <IdCoderText.hpp>	// Pascal unit
#include <IdCoder3To4.hpp>	// Pascal unit
#include <IdCoderIMF.hpp>	// Pascal unit
#include <IdCoder.hpp>	// Pascal unit
#include <IdBaseComponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idmessage
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdMessagePriority { mpHighest, mpHigh, mpNormal, mpLow, mpLowest };
#pragma option pop

typedef void __fastcall (__closure *TOnGetMessagePartStream)(Classes::TStream* AStream);

class DELPHICLASS TIdMessagePart;
class PASCALIMPLEMENTATION TIdMessagePart : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	AnsiString FBoundary;
	bool FBoundaryBegin;
	bool FBoundaryEnd;
	AnsiString FContentMD5;
	AnsiString FContentTransfer;
	AnsiString FContentType;
	AnsiString FEndBoundary;
	Idheaderlist::TIdHeaderList* FExtraHeaders;
	Idheaderlist::TIdHeaderList* FHeaders;
	bool FIsEncoded;
	TOnGetMessagePartStream FOnGetMessagePartStream;
	AnsiString FStoredPathName;
	AnsiString __fastcall GetContentType();
	AnsiString __fastcall GetContentTransfer();
	void __fastcall SetContentType(const AnsiString Value);
	void __fastcall SetContentTransfer(const AnsiString Value);
	void __fastcall SetExtraHeaders(const Idheaderlist::TIdHeaderList* Value);
	
public:
	__fastcall virtual TIdMessagePart(Classes::TCollection* Collection);
	__fastcall virtual ~TIdMessagePart(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property AnsiString Boundary = {read=FBoundary, write=FBoundary};
	__property bool BoundaryBegin = {read=FBoundaryBegin, write=FBoundaryBegin, nodefault};
	__property bool BoundaryEnd = {read=FBoundaryEnd, write=FBoundaryEnd, nodefault};
	__property bool IsEncoded = {read=FIsEncoded, nodefault};
	__property TOnGetMessagePartStream OnGetMessagePartStream = {read=FOnGetMessagePartStream, write=FOnGetMessagePartStream};
	__property AnsiString StoredPathName = {read=FStoredPathName, write=FStoredPathName};
	__property Idheaderlist::TIdHeaderList* Headers = {read=FHeaders};
	
__published:
	__property AnsiString ContentTransfer = {read=GetContentTransfer, write=SetContentTransfer};
	__property AnsiString ContentType = {read=GetContentType, write=SetContentType};
	__property Idheaderlist::TIdHeaderList* ExtraHeaders = {read=FExtraHeaders, write=SetExtraHeaders};
};


typedef TMetaClass*TIdMessagePartClass;

class DELPHICLASS TIdAttachment;
class DELPHICLASS TIdMessageParts;
class PASCALIMPLEMENTATION TIdAttachment : public TIdMessagePart 
{
	typedef TIdMessagePart inherited;
	
protected:
	AnsiString FContentDisposition;
	AnsiString FFileName;
	AnsiString __fastcall GetContentDisposition();
	void __fastcall SetContentDisposition(const AnsiString Value);
	
public:
	bool __fastcall SaveToFile(const AnsiString FileName);
	__fastcall TIdAttachment(TIdMessageParts* Collection, const AnsiString AFileName);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property AnsiString ContentDisposition = {read=GetContentDisposition, write=SetContentDisposition};
	__property AnsiString FileName = {read=FFileName, write=FFileName};
public:
	#pragma option push -w-inl
	/* TIdMessagePart.Destroy */ inline __fastcall virtual ~TIdAttachment(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIdText;
class PASCALIMPLEMENTATION TIdText : public TIdMessagePart 
{
	typedef TIdMessagePart inherited;
	
protected:
	Classes::TStrings* FBody;
	void __fastcall SetBody(const Classes::TStrings* AStrs);
	
public:
	__fastcall TIdText(TIdMessageParts* Collection, Classes::TStrings* ABody);
	__fastcall virtual ~TIdText(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property Classes::TStrings* Body = {read=FBody, write=SetBody};
};


class PASCALIMPLEMENTATION TIdMessageParts : public Classes::TOwnedCollection 
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TIdMessagePart* operator[](int Index) { return Items[Index]; }
	
protected:
	HIDESBASE TIdMessagePart* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TIdMessagePart* Value);
	
public:
	HIDESBASE TIdMessagePart* __fastcall Add(void);
	__fastcall TIdMessageParts(Classes::TPersistent* AOwner);
	__property TIdMessagePart* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdMessageParts(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIdMessage;
class PASCALIMPLEMENTATION TIdMessage : public Idbasecomponent::TIdBaseComponent 
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	Idemailaddress::TIdEMailAddressList* FBccList;
	Classes::TStrings* FBody;
	AnsiString FCharSet;
	Idemailaddress::TIdEMailAddressList* FCcList;
	AnsiString FContentType;
	AnsiString FContentTransferEncoding;
	System::TDateTime FDate;
	bool FIsEncoded;
	Idheaderlist::TIdHeaderList* FExtraHeaders;
	Idemailaddress::TIdEMailAddressItem* FFrom;
	Idheaderlist::TIdHeaderList* FHeaders;
	TIdMessageParts* FMessageParts;
	AnsiString FMsgId;
	Classes::TStrings* FNewsGroups;
	bool FNoDecode;
	AnsiString FOrganization;
	TIdMessagePriority FPriority;
	AnsiString FSubject;
	Idemailaddress::TIdEMailAddressItem* FReceiptRecipient;
	Idemailaddress::TIdEMailAddressList* FRecipients;
	AnsiString FReferences;
	Idemailaddress::TIdEMailAddressList* FReplyTo;
	Idemailaddress::TIdEMailAddressItem* FSender;
	AnsiString FXProgram;
	
public:
	void __fastcall AddHeader(const AnsiString Value);
	virtual void __fastcall Clear(void);
	void __fastcall ClearBody(void);
	void __fastcall ClearHeader(void);
	__fastcall virtual TIdMessage(Classes::TComponent* AOwner);
	__fastcall virtual ~TIdMessage(void);
	void __fastcall GetHeader(void);
	Idheaderlist::TIdHeaderList* __fastcall GenerateHeader(void);
	bool __fastcall GetUseNowForDate(void);
	void __fastcall SetBody(const Classes::TStrings* Value);
	void __fastcall SetNewsGroups(const Classes::TStrings* Value);
	void __fastcall SetExtraHeaders(const Idheaderlist::TIdHeaderList* Value);
	void __fastcall SetUseNowForDate(const bool Value);
	__property bool IsEncoded = {read=FIsEncoded, write=FIsEncoded, nodefault};
	__property AnsiString MsgId = {read=FMsgId, write=FMsgId};
	__property Idheaderlist::TIdHeaderList* Headers = {read=FHeaders};
	__property TIdMessageParts* MessageParts = {read=FMessageParts};
	
__published:
	__property Classes::TStrings* Body = {read=FBody, write=SetBody};
	__property Idemailaddress::TIdEMailAddressList* BccList = {read=FBccList, write=FBccList};
	__property AnsiString CharSet = {read=FCharSet, write=FCharSet};
	__property Idemailaddress::TIdEMailAddressList* CCList = {read=FCcList, write=FCcList};
	__property AnsiString ContentType = {read=FContentType, write=FContentType};
	__property AnsiString ContentTransferEncoding = {read=FContentTransferEncoding, write=FContentTransferEncoding};
	__property System::TDateTime Date = {read=FDate, write=FDate};
	__property Idheaderlist::TIdHeaderList* ExtraHeaders = {read=FExtraHeaders, write=SetExtraHeaders};
	__property Idemailaddress::TIdEMailAddressItem* From = {read=FFrom, write=FFrom};
	__property Classes::TStrings* NewsGroups = {read=FNewsGroups, write=SetNewsGroups};
	__property bool NoDecode = {read=FNoDecode, write=FNoDecode, default=0};
	__property AnsiString Organization = {read=FOrganization, write=FOrganization};
	__property TIdMessagePriority Priority = {read=FPriority, write=FPriority, default=2};
	__property Idemailaddress::TIdEMailAddressItem* ReceiptRecipient = {read=FReceiptRecipient, write=FReceiptRecipient};
	__property Idemailaddress::TIdEMailAddressList* Recipients = {read=FRecipients, write=FRecipients};
	__property AnsiString References = {read=FReferences, write=FReferences};
	__property Idemailaddress::TIdEMailAddressList* ReplyTo = {read=FReplyTo, write=FReplyTo};
	__property AnsiString Subject = {read=FSubject, write=FSubject};
	__property Idemailaddress::TIdEMailAddressItem* Sender = {read=FSender, write=FSender};
	__property bool UseNowForDate = {read=GetUseNowForDate, write=SetUseNowForDate, default=1};
};


typedef void __fastcall (__closure *TIdMessageEvent)(Classes::TComponent* ASender, TIdMessage* &AMsg);

typedef void __fastcall (__closure *TIdStringMessageEvent)(Classes::TComponent* ASender, const AnsiString AString, TIdMessage* &AMsg);

class DELPHICLASS EIdMessageException;
class PASCALIMPLEMENTATION EIdMessageException : public Idexception::EIdException 
{
	typedef Idexception::EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdMessageException(const AnsiString Msg) : Idexception::EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdMessageException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdMessageException(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdMessageException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdMessageException(const AnsiString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdMessageException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdMessageException(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdMessageException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdMessageException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdCanNotCreateMessagePart;
class PASCALIMPLEMENTATION EIdCanNotCreateMessagePart : public EIdMessageException 
{
	typedef EIdMessageException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdCanNotCreateMessagePart(const AnsiString Msg) : EIdMessageException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdCanNotCreateMessagePart(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdMessageException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdCanNotCreateMessagePart(int Ident)/* overload */ : EIdMessageException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdCanNotCreateMessagePart(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdMessageException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdCanNotCreateMessagePart(const AnsiString Msg, int AHelpContext) : EIdMessageException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdCanNotCreateMessagePart(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdMessageException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdCanNotCreateMessagePart(int Ident, int AHelpContext)/* overload */ : EIdMessageException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdCanNotCreateMessagePart(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdMessageException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdCanNotCreateMessagePart(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdTextInvalidCount;
class PASCALIMPLEMENTATION EIdTextInvalidCount : public EIdMessageException 
{
	typedef EIdMessageException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdTextInvalidCount(const AnsiString Msg) : EIdMessageException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdTextInvalidCount(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdMessageException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdTextInvalidCount(int Ident)/* overload */ : EIdMessageException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdTextInvalidCount(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdMessageException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdTextInvalidCount(const AnsiString Msg, int AHelpContext) : EIdMessageException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTextInvalidCount(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdMessageException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdTextInvalidCount(int Ident, int AHelpContext)/* overload */ : EIdMessageException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTextInvalidCount(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdMessageException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdTextInvalidCount(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const bool ID_MSG_NODECODE = false;
static const bool ID_MSG_USENOWFORDATE = true;
#define ID_MSG_PRIORITY (TIdMessagePriority)(2)

}	/* namespace Idmessage */
using namespace Idmessage;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdMessage
