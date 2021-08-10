// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBCtrls.pas' rev: 6.00

#ifndef IBCtrlsHPP
#define IBCtrlsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <BDE.hpp>	// Pascal unit
#include <IBProc32.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibctrls
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIBComponent;
class PASCALIMPLEMENTATION TIBComponent : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Dbtables::TDatabase* FDatabase;
	void __fastcall SetDatabase(Dbtables::TDatabase* value);
	void __fastcall ValidateDatabase(Dbtables::TDatabase* Database);
	
protected:
	void * __fastcall GetNativeHandle(void);
	void __fastcall HandleIBErrors(Ibproc32::pstatus_vector status);
	bool __fastcall IsInterbaseDatabase(Dbtables::TDatabase* Database);
	
__published:
	__property Dbtables::TDatabase* Database = {read=FDatabase, write=SetDatabase};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TIBComponent(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TIBComponent(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TEventAlert)(System::TObject* Sender, AnsiString EventName, int EventCount, bool &CancelAlerts);

typedef char TEventBuffer[15][64];

class DELPHICLASS TIBEventAlerter;
class PASCALIMPLEMENTATION TIBEventAlerter : public TIBComponent 
{
	typedef TIBComponent inherited;
	
private:
	unsigned LibHandle;
	Classes::TStrings* FEvents;
	TEventAlert FOnEventAlert;
	bool FQueued;
	bool FRegistered;
	char Buffer[15][64];
	bool Changing;
	_RTL_CRITICAL_SECTION CS;
	char *EventBuffer;
	int EventBufferLen;
	int EventID;
	bool ProcessingEvents;
	bool RegisteredState;
	char *ResultBuffer;
	void __fastcall DoQueueEvents(void);
	void __fastcall EventChange(System::TObject* sender);
	void __fastcall UpdateResultBuffer(Word length, char * updated);
	
protected:
	void __fastcall HandleEvent(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall SetEvents(Classes::TStrings* value);
	HIDESBASE void __fastcall SetDatabase(Dbtables::TDatabase* value);
	void __fastcall SetRegistered(bool value);
	
public:
	__fastcall virtual TIBEventAlerter(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBEventAlerter(void);
	void __fastcall CancelEvents(void);
	void __fastcall QueueEvents(void);
	void __fastcall RegisterEvents(void);
	void __fastcall UnRegisterEvents(void);
	__property bool Queued = {read=FQueued, nodefault};
	
__published:
	__property Classes::TStrings* Events = {read=FEvents, write=SetEvents};
	__property bool Registered = {read=FRegistered, write=SetRegistered, nodefault};
	__property TEventAlert OnEventAlert = {read=FOnEventAlert, write=FOnEventAlert};
};


class DELPHICLASS EIBError;
class PASCALIMPLEMENTATION EIBError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIBError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIBError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIBError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIBError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIBError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIBError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIBError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIBError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIBError(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint MaxEvents = 0xf;
static const Shortint EventLength = 0x40;

}	/* namespace Ibctrls */
using namespace Ibctrls;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBCtrls
