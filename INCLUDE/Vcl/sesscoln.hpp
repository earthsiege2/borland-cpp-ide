// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SessColn.pas' rev: 6.00

#ifndef SessColnHPP
#define SessColnHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <HTTPApp.hpp>	// Pascal unit
#include <WebContnrs.hpp>	// Pascal unit
#include <SiteComp.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SyncObjs.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Sesscoln
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TSessionStatusFlag { ssStarted, ssTerminated, ssTimeOut };
#pragma option pop

typedef Set<TSessionStatusFlag, ssStarted, ssTimeOut>  TSessionStatusFlags;

class DELPHICLASS TSessionItem;
class PASCALIMPLEMENTATION TSessionItem : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	Webcontnrs::TAbstractNamedVariants* FItems;
	AnsiString FID;
	bool FExpired;
	bool FTerminated;
	int FTimeoutMinutes;
	System::TDateTime FStartTime;
	System::TDateTime FTouchTime;
	TSessionStatusFlags FStatusFlags;
	void __fastcall SetItems(const Webcontnrs::TAbstractNamedVariants* Value);
	System::TDateTime __fastcall GetExpirationTime(void);
	void __fastcall SetExpired(const bool Value);
	void __fastcall SetTerminated(const bool Value);
	
public:
	__fastcall virtual TSessionItem(Classes::TCollection* Collection);
	__fastcall virtual ~TSessionItem(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property System::TDateTime ExpirationTime = {read=GetExpirationTime};
	bool __fastcall IsActive(void);
	
__published:
	__property AnsiString ID = {read=FID, write=FID};
	__property System::TDateTime StartTime = {read=FStartTime, write=FStartTime};
	__property int TimeoutMinutes = {read=FTimeoutMinutes, write=FTimeoutMinutes, nodefault};
	__property System::TDateTime TouchTime = {read=FTouchTime, write=FTouchTime};
	__property bool Expired = {read=FExpired, write=SetExpired, nodefault};
	__property bool Terminated = {read=FTerminated, write=SetTerminated, nodefault};
	__property TSessionStatusFlags StatusFlags = {read=FStatusFlags, write=FStatusFlags, nodefault};
	__property Webcontnrs::TAbstractNamedVariants* Items = {read=FItems, write=SetItems};
};


class DELPHICLASS TSessions;
class DELPHICLASS TAbstractSessionIDGen;
class PASCALIMPLEMENTATION TAbstractSessionIDGen : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual AnsiString __fastcall NextID(void) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TAbstractSessionIDGen(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractSessionIDGen(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAbstractSessionStatusChange;
class PASCALIMPLEMENTATION TSessions : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
private:
	AnsiString FFileName;
	Sysutils::TMultiReadExclusiveWriteSynchronizer* FLock;
	TAbstractSessionIDGen* FSessionIDGen;
	int FMaxSessions;
	TSessionItem* __fastcall FindSession(AnsiString AID);
	AnsiString __fastcall NextSessionID();
	TSessionItem* __fastcall NewSession(void);
	AnsiString __fastcall NewSessionID();
	void __fastcall ReadLock(void);
	void __fastcall ReadUnlock(void);
	void __fastcall WriteLock(void);
	void __fastcall WriteUnlock(void);
	int __fastcall GetMaxSessions(void);
	void __fastcall SetMaxSessions(const int Value);
	int __fastcall GetActiveCount(void);
	
public:
	__fastcall TSessions(void);
	__fastcall virtual ~TSessions(void);
	TAbstractSessionIDGen* __fastcall GetSessionIDGen(void);
	virtual TAbstractSessionIDGen* __fastcall CreateSessionIDGen(void);
	bool __fastcall ConnectSession(AnsiString AID);
	bool __fastcall ConnectActiveSession(AnsiString AID);
	void __fastcall DisconnectSession(AnsiString AID);
	bool __fastcall TerminateSession(AnsiString AID);
	void __fastcall GetIDs(Classes::TList* &AList);
	int __fastcall GetIDCount(void);
	AnsiString __fastcall StartSession();
	bool __fastcall SessionExists(AnsiString AID);
	bool __fastcall TouchSession(AnsiString AID);
	void __fastcall SetItemValue(AnsiString AID, const AnsiString AName, const Variant &AValue);
	Variant __fastcall ItemValue(AnsiString AID, const AnsiString AName);
	void __fastcall GetItems(AnsiString AID, Webcontnrs::TAbstractNamedVariants* &AItems);
	int __fastcall GetItemCount(AnsiString AID);
	bool __fastcall GetSession(AnsiString AID, TSessionItem* &AItem);
	System::TDateTime __fastcall GetStartTime(AnsiString AID);
	int __fastcall GetTimeoutMinutes(AnsiString AID);
	void __fastcall SetTimeoutMinutes(AnsiString AID, int AValue);
	System::TDateTime __fastcall GetTouchTime(AnsiString AID);
	bool __fastcall GetExpired(AnsiString AID);
	System::TDateTime __fastcall GetExpirationTime(AnsiString AID);
	bool __fastcall GetTerminated(AnsiString AID);
	bool __fastcall GetIsActive(AnsiString AID);
	bool __fastcall CheckStatusChange(void);
	void __fastcall NotifyStatusChange(TAbstractSessionStatusChange* AStatusChange);
	void __fastcall LoadFromFile(const AnsiString Filename);
	void __fastcall SaveToFile(const AnsiString Filename);
	void __fastcall LoadFromStream(Classes::TStream* S);
	void __fastcall SaveToStream(Classes::TStream* S);
	__property AnsiString FileName = {read=FFileName, write=FFileName};
	__property int MaxSessions = {read=GetMaxSessions, write=SetMaxSessions, nodefault};
	__property int ActiveCount = {read=GetActiveCount, nodefault};
};


class PASCALIMPLEMENTATION TAbstractSessionStatusChange : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	virtual void __fastcall SessionTerminated(AnsiString AID, bool &AHandled) = 0 ;
	virtual void __fastcall SessionTimeout(AnsiString AID, bool &AHandled) = 0 ;
	virtual void __fastcall SessionStarted(AnsiString AID, bool &AHandled) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TAbstractSessionStatusChange(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractSessionStatusChange(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSessionIDGen;
class PASCALIMPLEMENTATION TSessionIDGen : public TAbstractSessionIDGen 
{
	typedef TAbstractSessionIDGen inherited;
	
private:
	int FIDSize;
	char FCharMap[62];
	void __fastcall InitCharMap(void);
	
public:
	__fastcall TSessionIDGen(void);
	virtual AnsiString __fastcall NextID();
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TSessionIDGen(void) { }
	#pragma option pop
	
};


class DELPHICLASS ESessionsException;
class PASCALIMPLEMENTATION ESessionsException : public Httpapp::EWebBrokerException 
{
	typedef Httpapp::EWebBrokerException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ESessionsException(const AnsiString Msg) : Httpapp::EWebBrokerException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ESessionsException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Httpapp::EWebBrokerException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ESessionsException(int Ident)/* overload */ : Httpapp::EWebBrokerException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ESessionsException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Httpapp::EWebBrokerException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ESessionsException(const AnsiString Msg, int AHelpContext) : Httpapp::EWebBrokerException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ESessionsException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Httpapp::EWebBrokerException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ESessionsException(int Ident, int AHelpContext)/* overload */ : Httpapp::EWebBrokerException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ESessionsException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Httpapp::EWebBrokerException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ESessionsException(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TSessions* Sessions;

}	/* namespace Sesscoln */
using namespace Sesscoln;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SessColn
