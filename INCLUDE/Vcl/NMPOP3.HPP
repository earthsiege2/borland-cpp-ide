// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NMpop3.pas' rev: 6.00

#ifndef NMpop3HPP
#define NMpop3HPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <NMConst.hpp>	// Pascal unit
#include <NMExtstr.hpp>	// Pascal unit
#include <NMUUE.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Psock.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Nmpop3
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TListEvent)(int Msg, int Size);

typedef void __fastcall (__closure *TVarFileNameEvent)(AnsiString &FileName);

class DELPHICLASS TMailMessage;
class PASCALIMPLEMENTATION TMailMessage : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Nmextstr::TExStringList* FHead;
	Classes::TStringList* FRawBody;
	Classes::TStringList* FBody;
	Classes::TStringList* FAttachments;
	Classes::TList* FPartHeaders;
	AnsiString FContentType;
	AnsiString FFrom;
	AnsiString FSubject;
	AnsiString FMessageId;
	
public:
	AnsiString FBoundary;
	__fastcall TMailMessage(void);
	__fastcall virtual ~TMailMessage(void);
	__property AnsiString Subject = {read=FSubject};
	__property AnsiString From = {read=FFrom};
	__property Classes::TStringList* RawBody = {read=FRawBody};
	__property Classes::TStringList* Body = {read=FBody};
	__property Nmextstr::TExStringList* Head = {read=FHead};
	__property AnsiString MessageId = {read=FMessageId, write=FMessageId};
	__property AnsiString ContentType = {read=FContentType, write=FContentType};
	__property Classes::TStringList* Attachments = {read=FAttachments};
	__property Classes::TList* PartHeaders = {read=FPartHeaders};
};


class DELPHICLASS TSummary;
class PASCALIMPLEMENTATION TSummary : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	AnsiString FSubject;
	AnsiString FFrom;
	int FBytes;
	AnsiString FMessageId;
	Nmextstr::TExStringList* FHeader;
	
__published:
	__fastcall TSummary(void);
	__fastcall virtual ~TSummary(void);
	__property AnsiString Subject = {read=FSubject, write=FSubject};
	__property AnsiString From = {read=FFrom, write=FFrom};
	__property AnsiString MessageId = {read=FMessageId, write=FMessageId};
	__property int Bytes = {read=FBytes, write=FBytes, nodefault};
	__property Nmextstr::TExStringList* Header = {read=FHeader, write=FHeader};
};


class DELPHICLASS TNMPOP3;
class PASCALIMPLEMENTATION TNMPOP3 : public Psock::TPowersock 
{
	typedef Psock::TPowersock inherited;
	
private:
	TVarFileNameEvent FOnDecodeStart;
	Classes::TNotifyEvent FOnDecodeEnd;
	Nmuue::TNMUUProcessor* NMUUProcessor1;
	AnsiString FAttachFilePath;
	AnsiString FFilename;
	AnsiString FContent_type;
	TSummary* FSummary;
	bool FParse;
	TMailMessage* FMailMessage;
	AnsiString FUserID;
	AnsiString FPassword;
	bool FAbort;
	bool FDeleteOnRead;
	bool FTransactionInProgress;
	int FMailCount;
	int FFirstPart;
	Psock::THandlerEvent FOnAuthenticationNeeded;
	Psock::THandlerEvent FOnAuthenticationFailed;
	Classes::TNotifyEvent FOnReset;
	TListEvent FOnList;
	Classes::TNotifyEvent FOnRetrieveStart;
	Classes::TNotifyEvent FOnRetrieveEnd;
	Classes::TNotifyEvent FOnSuccess;
	Classes::TNotifyEvent FOnFailure;
	Classes::TNotifyEvent FOnConnect;
	int WaitForReset;
	void __fastcall ReadMailParts(void);
	bool __fastcall ReadBody(TMailMessage* &MailMessage);
	void __fastcall ReadHeader(bool Readfile, TMailMessage* &MailMessage);
	void __fastcall AbortResume(System::TObject* Sender);
	void __fastcall SetAttachFilePath(AnsiString Value);
	
public:
	__fastcall virtual TNMPOP3(Classes::TComponent* AOwner);
	__fastcall virtual ~TNMPOP3(void);
	virtual void __fastcall Connect(void);
	virtual void __fastcall Disconnect(void);
	void __fastcall GetMailMessage(int MailNumber);
	void __fastcall GetSummary(int MailNumber);
	void __fastcall DeleteMailMessage(int MailNumber);
	void __fastcall Extract(AnsiString InString, AnsiString &OutString);
	AnsiString __fastcall UniqueID(int MailNumber);
	void __fastcall Reset(void);
	void __fastcall List(void);
	virtual void __fastcall Abort(void);
	__property int MailCount = {read=FMailCount, nodefault};
	__property TSummary* Summary = {read=FSummary};
	__property TMailMessage* MailMessage = {read=FMailMessage};
	__property Classes::TNotifyEvent OnRetriveStart = {read=FOnRetrieveStart, write=FOnRetrieveStart};
	__property Classes::TNotifyEvent OnRetriveEnd = {read=FOnRetrieveEnd, write=FOnRetrieveEnd};
	
__published:
	__property OnConnectionRequired ;
	__property OnPacketRecvd ;
	__property BytesRecvd ;
	__property BytesTotal ;
	__property AnsiString UserID = {read=FUserID, write=FUserID};
	__property bool Parse = {read=FParse, write=FParse, nodefault};
	__property AnsiString Password = {read=FPassword, write=FPassword};
	__property bool DeleteOnRead = {read=FDeleteOnRead, write=FDeleteOnRead, nodefault};
	__property AnsiString AttachFilePath = {read=FAttachFilePath, write=SetAttachFilePath};
	__property Classes::TNotifyEvent OnConnect = {read=FOnConnect, write=FOnConnect};
	__property Psock::THandlerEvent OnAuthenticationNeeded = {read=FOnAuthenticationNeeded, write=FOnAuthenticationNeeded};
	__property Psock::THandlerEvent OnAuthenticationFailed = {read=FOnAuthenticationFailed, write=FOnAuthenticationFailed};
	__property Classes::TNotifyEvent OnReset = {read=FOnReset, write=FOnReset};
	__property TListEvent OnList = {read=FOnList, write=FOnList};
	__property Classes::TNotifyEvent OnRetrieveStart = {read=FOnRetrieveStart, write=FOnRetrieveStart};
	__property Classes::TNotifyEvent OnRetrieveEnd = {read=FOnRetrieveEnd, write=FOnRetrieveEnd};
	__property Classes::TNotifyEvent OnSuccess = {read=FOnSuccess, write=FOnSuccess};
	__property Classes::TNotifyEvent OnFailure = {read=FOnFailure, write=FOnFailure};
	__property TVarFileNameEvent OnDecodeStart = {read=FOnDecodeStart, write=FOnDecodeStart};
	__property Classes::TNotifyEvent OnDecodeEnd = {read=FOnDecodeEnd, write=FOnDecodeEnd};
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint POP3_PORT = 0x6e;
#define Cons_OK_Resp "+OK"
#define Cons_Err_Resp "-ERR"
#define Cons_Cmd_User "USER "
#define Cons_Cmd_Pass "PASS "
#define Cons_Cmd_Stat "STAT"
#define Cons_Cmd_Quit "QUIT"
#define Cons_Cmd_Top "TOP "
#define Cons_Cmd_List "LIST "
#define Cons_Cmd_Retr "RETR "
#define Cons_Cmd_Dele "DELE "
#define Cons_Cmd_Rset "RSET"
#define Cons_Cmd_Uidl "UIDL "
#define Cons_Head_CSubj "SUBJECT:"
#define Cons_Head_CFrom "FROM:"
#define Cons_Head_CType "CONTENT-TYPE:"
#define Cons_Head_CMid "MESSAGE-ID:"
#define Cons_Head_CBoun "BOUNDARY="
#define Cons_Head_CCTE "CONTENT-TRANSFER-ENCODING"
#define Cons_Head_FileN "FILENAME"
#define Cons_Head_Subj "Subject:"
#define Cons_Head_From "From:"
#define Cons_Head_MId "Message-ID:"
#define Cons_Head_Mult "multipart"
#define Cons_Head_UUEn "X-UUENCODE"
#define Cons_Head_B641 "base64"
#define Cons_Head_B642 "Base64"

}	/* namespace Nmpop3 */
using namespace Nmpop3;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NMpop3
