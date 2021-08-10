// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SvrLog.pas' rev: 6.00

#ifndef SvrLogHPP
#define SvrLogHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SvrConst.hpp>	// Pascal unit
#include <ScktComp.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SyncObjs.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <WinSock.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Svrlog
{
//-- type declarations -------------------------------------------------------
#pragma pack(push, 4)
struct TWmLogMessage
{
	unsigned Msg;
	int Unused0;
	int Unused1;
	int Result;
} ;
#pragma pack(pop)

struct TRequestTime
{
	unsigned ThreadID;
	System::TDateTime StartTime;
} ;

typedef TRequestTime *PRequestTime;

class DELPHICLASS TTransactionLogEntry;
typedef void __fastcall (__closure *THTTPLogEvent)(System::TObject* Sender, TTransactionLogEntry* Transaction, bool &Release);

typedef DynamicArray<TRequestTime >  SvrLog__2;

class DELPHICLASS TCustomServerLog;
class PASCALIMPLEMENTATION TCustomServerLog : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Syncobjs::TCriticalSection* FLock;
	Classes::TList* FBuffer;
	HWND FHandle;
	THTTPLogEvent FOnLog;
	DynamicArray<TRequestTime >  FRequestTimes;
	TTransactionLogEntry* __fastcall GetLogEntry(void);
	void __fastcall LogTransaction(TTransactionLogEntry* Transaction);
	MESSAGE void __fastcall WMLogMessage(TWmLogMessage &Msg);
	void __fastcall WndProc(Messages::TMessage &Message);
	void __fastcall SetRequestTime(unsigned AThreadID, System::TDateTime AStartTime);
	System::TDateTime __fastcall GetRequestTime(unsigned AThreadID);
	PRequestTime __fastcall FindRequestTime(unsigned AThreadID);
	
protected:
	virtual void __fastcall DoOnLog(TTransactionLogEntry* Transaction, bool &Release);
	
public:
	__fastcall TCustomServerLog(void);
	__fastcall virtual ~TCustomServerLog(void);
	virtual void __fastcall DefaultHandler(void *Message);
	void __fastcall LogError(Scktcomp::TErrorEvent AErrorEvent, int AErrorCode, const AnsiString AErrorMsg);
	void __fastcall LogRequest(Httpapp::TWebRequest* Request);
	void __fastcall LogResponse(const AnsiString Buffer);
	__property System::TDateTime RequestTime[unsigned AThreadID] = {read=GetRequestTime, write=SetRequestTime};
};


#pragma option push -b-
enum TLogColumn { lcEvent, lcTime, lcDate, lcElapsed, lcPath, lcStatus, lcContentLength, lcContentType, lcThreadID };
#pragma option pop

class PASCALIMPLEMENTATION TTransactionLogEntry : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	AnsiString FEventName;
	System::TDateTime FDateTime;
	System::TDateTime FElapsedTime;
	unsigned FThreadID;
	virtual AnsiString __fastcall GetLogString(void) = 0 ;
	virtual AnsiString __fastcall GetColumn(TLogColumn I);
	
public:
	__fastcall TTransactionLogEntry(void);
	__property AnsiString LogString = {read=GetLogString};
	__property System::TDateTime ElapsedTime = {read=FElapsedTime};
	__property AnsiString Columns[TLogColumn I] = {read=GetColumn};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TTransactionLogEntry(void) { }
	#pragma option pop
	
};


class DELPHICLASS THTTPTransaction;
class PASCALIMPLEMENTATION THTTPTransaction : public TTransactionLogEntry 
{
	typedef TTransactionLogEntry inherited;
	
protected:
	int FContentLength;
	AnsiString FContentType;
	AnsiString FBuffer;
	virtual AnsiString __fastcall GetColumn(TLogColumn I);
	virtual AnsiString __fastcall GetLogString();
public:
	#pragma option push -w-inl
	/* TTransactionLogEntry.Create */ inline __fastcall THTTPTransaction(void) : TTransactionLogEntry() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~THTTPTransaction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TRequestTransaction;
class PASCALIMPLEMENTATION TRequestTransaction : public THTTPTransaction 
{
	typedef THTTPTransaction inherited;
	
private:
	AnsiString FPath;
	
protected:
	virtual AnsiString __fastcall GetColumn(TLogColumn I);
	
public:
	__fastcall TRequestTransaction(Httpapp::TWebRequest* ARequest);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TRequestTransaction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TResponseTransaction;
class PASCALIMPLEMENTATION TResponseTransaction : public THTTPTransaction 
{
	typedef THTTPTransaction inherited;
	
private:
	AnsiString FStatus;
	AnsiString FFirstLine;
	void __fastcall ParseBuffer(System::TObject* AParser);
	
protected:
	virtual AnsiString __fastcall GetColumn(TLogColumn I);
	
public:
	__fastcall TResponseTransaction(const AnsiString Buffer);
	__fastcall virtual ~TResponseTransaction(void);
};


class DELPHICLASS TErrorTransaction;
class PASCALIMPLEMENTATION TErrorTransaction : public TTransactionLogEntry 
{
	typedef TTransactionLogEntry inherited;
	
private:
	Scktcomp::TErrorEvent FErrorEvent;
	AnsiString FErrorMsg;
	int FErrorCode;
	
public:
	__fastcall TErrorTransaction(Scktcomp::TErrorEvent AErrorEvent, int AErrorCode, const AnsiString AErrorMsg);
	virtual AnsiString __fastcall GetLogString();
	__property Scktcomp::TErrorEvent ErrorType = {read=FErrorEvent, nodefault};
	__property AnsiString ErrorMsg = {read=FErrorMsg};
	__property int ErrorCode = {read=FErrorCode, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TErrorTransaction(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word WM_LOGMESSAGE = 0x500;

}	/* namespace Svrlog */
using namespace Svrlog;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SvrLog
