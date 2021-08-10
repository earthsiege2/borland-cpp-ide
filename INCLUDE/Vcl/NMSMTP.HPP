// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NMsmtp.pas' rev: 5.00

#ifndef NMsmtpHPP
#define NMsmtpHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <NMS_Stream.hpp>	// Pascal unit
#include <NMExtstr.hpp>	// Pascal unit
#include <NMConst.hpp>	// Pascal unit
#include <NMUUE.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Psock.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Nmsmtp
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TSubType { mtPlain, mtEnriched, mtSgml, mtTabSeperated, mtHtml };
#pragma option pop

typedef void __fastcall (__closure *THeaderInComplete)(bool &handled, int hiType);

typedef void __fastcall (__closure *TRecipientNotFound)(AnsiString Recipient);

typedef void __fastcall (__closure *TMailListReturn)(AnsiString MailAddress);

typedef void __fastcall (__closure *TFileItem)(AnsiString Filename);

class DELPHICLASS TPostMessage;
class PASCALIMPLEMENTATION TPostMessage : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	AnsiString FFromName;
	AnsiString FFrom;
	AnsiString FSubject;
	AnsiString FLocalProgram;
	AnsiString FDate;
	AnsiString FReplyTo;
	Classes::TStringList* FAttachments;
	Classes::TStringList* FTo;
	Classes::TStringList* FCC;
	Classes::TStringList* FBCC;
	Classes::TStringList* FBody;
	
protected:
	void __fastcall SetLinesTo(Classes::TStringList* Value);
	void __fastcall SetLinesCC(Classes::TStringList* Value);
	void __fastcall SetLinesBCC(Classes::TStringList* Value);
	void __fastcall SetLinesBody(Classes::TStringList* Value);
	void __fastcall SetLinesAttachments(Classes::TStringList* Value);
	
public:
	__fastcall TPostMessage(void);
	__fastcall virtual ~TPostMessage(void);
	
__published:
	__property AnsiString FromAddress = {read=FFrom, write=FFrom};
	__property AnsiString FromName = {read=FFromName, write=FFromName};
	__property Classes::TStringList* ToAddress = {read=FTo, write=SetLinesTo};
	__property Classes::TStringList* ToCarbonCopy = {read=FCC, write=SetLinesCC};
	__property Classes::TStringList* ToBlindCarbonCopy = {read=FBCC, write=SetLinesBCC};
	__property Classes::TStringList* Body = {read=FBody, write=SetLinesBody};
	__property Classes::TStringList* Attachments = {read=FAttachments, write=SetLinesAttachments};
	__property AnsiString Subject = {read=FSubject, write=FSubject};
	__property AnsiString LocalProgram = {read=FLocalProgram, write=FLocalProgram};
	__property AnsiString Date = {read=FDate, write=FDate};
	__property AnsiString ReplyTo = {read=FReplyTo, write=FReplyTo};
};


class DELPHICLASS TNMSMTP;
class PASCALIMPLEMENTATION TNMSMTP : public Psock::TPowersock 
{
	typedef Psock::TPowersock inherited;
	
private:
	AnsiString FCharset;
	Classes::TNotifyEvent FOnConnect;
	TPostMessage* FPostMessage;
	Classes::TMemoryStream* FsenFmem;
	Classes::TMemoryStream* FSendFile;
	Nmextstr::TExStringList* FFinalHeader;
	bool FTransactionInProgress;
	bool FAbort;
	AnsiString FUserID;
	AnsiString FBoundary;
	TSubType FSubType;
	THeaderInComplete FOnHeaderInComplete;
	Classes::TNotifyEvent FOnSendStart;
	Classes::TNotifyEvent FOnSuccess;
	Classes::TNotifyEvent FOnFailure;
	TFileItem FOnEncodeStart;
	TFileItem FOnEncodeEnd;
	TFileItem FOnAttachmentNotFound;
	TRecipientNotFound FRecipientNotFound;
	TMailListReturn FMailListReturn;
	Psock::THandlerEvent FOnAuthenticationFailed;
	Nmuue::UUMethods fUUMethod;
	bool FClearParams;
	int WaitForReset;
	void __fastcall ReadExtraLines(AnsiString &ReplyMess);
	void __fastcall SendAttachments(int i);
	void __fastcall AssembleMail(void);
	void __fastcall AbortResume(System::TObject* Sender);
	void __fastcall SetFinalHeader(Nmextstr::TExStringList* Value);
	
public:
	__fastcall virtual TNMSMTP(Classes::TComponent* AOwner);
	__fastcall virtual ~TNMSMTP(void);
	virtual void __fastcall Connect(void);
	virtual void __fastcall Disconnect(void);
	void __fastcall SendMail(void);
	virtual void __fastcall Abort(void);
	void __fastcall ClearParameters(void);
	AnsiString __fastcall ExtractAddress(AnsiString TotalAddress);
	bool __fastcall Verify(AnsiString UserName);
	bool __fastcall ExpandList(AnsiString MailList);
	
__published:
	__property OnPacketSent ;
	__property OnConnectionRequired ;
	__property Classes::TNotifyEvent OnConnect = {read=FOnConnect, write=FOnConnect};
	__property AnsiString UserID = {read=FUserID, write=FUserID};
	__property TPostMessage* PostMessage = {read=FPostMessage, write=FPostMessage};
	__property Nmextstr::TExStringList* FinalHeader = {read=FFinalHeader, write=SetFinalHeader};
	__property Nmuue::UUMethods EncodeType = {read=fUUMethod, write=fUUMethod, nodefault};
	__property bool ClearParams = {read=FClearParams, write=FClearParams, nodefault};
	__property TSubType SubType = {read=FSubType, write=FSubType, nodefault};
	__property AnsiString Charset = {read=FCharset, write=FCharset};
	__property TRecipientNotFound OnRecipientNotFound = {read=FRecipientNotFound, write=FRecipientNotFound
		};
	__property THeaderInComplete OnHeaderIncomplete = {read=FOnHeaderInComplete, write=FOnHeaderInComplete
		};
	__property Classes::TNotifyEvent OnSendStart = {read=FOnSendStart, write=FOnSendStart};
	__property Classes::TNotifyEvent OnSuccess = {read=FOnSuccess, write=FOnSuccess};
	__property Classes::TNotifyEvent OnFailure = {read=FOnFailure, write=FOnFailure};
	__property TFileItem OnEncodeStart = {read=FOnEncodeStart, write=FOnEncodeStart};
	__property TFileItem OnEncodeEnd = {read=FOnEncodeEnd, write=FOnEncodeEnd};
	__property TMailListReturn OnMailListReturn = {read=FMailListReturn, write=FMailListReturn};
	__property TFileItem OnAttachmentNotFound = {read=FOnAttachmentNotFound, write=FOnAttachmentNotFound
		};
	__property Psock::THandlerEvent OnAuthenticationFailed = {read=FOnAuthenticationFailed, write=FOnAuthenticationFailed
		};
};


//-- var, const, procedure ---------------------------------------------------
#define uuMime (Nmuue::UUMethods)(0)
#define uuCode (Nmuue::UUMethods)(1)
static const Shortint SMTP_PORT = 0x19;
#define CRLF "\r\n"
static const Shortint hiFromAddress = 0x1;
static const Shortint hiToAddress = 0x2;
#define Cons_Helo "HELO "
#define Cons_Quit "QUIT"
#define Cons_Rset "RSET"
#define Cons_From "MAIL FROM:<"
#define Cons_To "RCPT TO:<"
#define Cons_Date "DATA"
#define Cons_Expn "EXPN "
#define Cons_Vrfy "VRFY "
#define Cons_Head_subj "Subject"
#define Cons_Head_from "From: "
#define Cons_Head_To "To: "
#define Cons_Head_CC "CC: "
#define Cons_Head_mail "X-Mailer"
#define Cons_Head_ReplyTo "Reply-To"
#define Cons_Head_Date "Date"
#define Cons_Head_mime "Mime-Version: 1.0"
#define Cons_Head_disp "Content-Disposition: attachment; filename=\""
#define Cons_Head_ba64 "Content-Transfer-Encoding: base64"
#define Cons_Head_appl "Content-Type: application/octet-stream; name=\""
#define Cons_Head_text "Content-Type: text/plain; charset="
#define Cons_Head_Enriched "Content-Type: text/enriched; charset="
#define Cons_Head_Sgml "Content-Type: text/sgml; charset="
#define Cons_Head_TabSeperated "Content-Type: text/tab-separated-values; charset="
#define Cons_Head_mtHtml "Content-Type: text/html; charset="
#define Cons_Head_mult "Content-Type: multipart/mixed; boundary=\""
#define Cons_Head_7Bit "Content-Transfer-Encoding: 7Bit"

}	/* namespace Nmsmtp */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Nmsmtp;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NMsmtp
