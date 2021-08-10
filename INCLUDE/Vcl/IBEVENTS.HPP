// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBEvents.pas' rev: 5.00

#ifndef IBEventsHPP
#define IBEventsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IBDatabase.hpp>	// Pascal unit
#include <IB.hpp>	// Pascal unit
#include <IBExternals.hpp>	// Pascal unit
#include <IBHeader.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
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

namespace Ibevents
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TEventAlert)(System::TObject* Sender, AnsiString EventName, int 
	EventCount, bool &CancelAlerts);

typedef char TEventBuffer[15][64];

class DELPHICLASS TIBEvents;
class PASCALIMPLEMENTATION TIBEvents : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	bool FIBLoaded;
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
	Ibdatabase::TIBDatabase* FDatabase;
	void __fastcall SetDatabase(Ibdatabase::TIBDatabase* value);
	void __fastcall ValidateDatabase(Ibdatabase::TIBDatabase* Database);
	void __fastcall DoQueueEvents(void);
	void __fastcall EventChange(System::TObject* sender);
	void __fastcall UpdateResultBuffer(short length, char * updated);
	
protected:
	void __fastcall HandleEvent(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	void __fastcall SetEvents(Classes::TStrings* value);
	void __fastcall SetRegistered(bool value);
	Ibexternals::PVoid __fastcall GetNativeHandle(void);
	
public:
	__fastcall virtual TIBEvents(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBEvents(void);
	void __fastcall CancelEvents(void);
	void __fastcall QueueEvents(void);
	void __fastcall RegisterEvents(void);
	void __fastcall UnRegisterEvents(void);
	__property bool Queued = {read=FQueued, nodefault};
	
__published:
	__property Ibdatabase::TIBDatabase* Database = {read=FDatabase, write=SetDatabase};
	__property Classes::TStrings* Events = {read=FEvents, write=SetEvents};
	__property bool Registered = {read=FRegistered, write=SetRegistered, nodefault};
	__property TEventAlert OnEventAlert = {read=FOnEventAlert, write=FOnEventAlert};
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint MaxEvents = 0xf;
static const Shortint EventLength = 0x40;

}	/* namespace Ibevents */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ibevents;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBEvents
