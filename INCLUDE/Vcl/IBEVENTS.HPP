// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBEvents.pas' rev: 6.00

#ifndef IBEventsHPP
#define IBEventsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IBDatabase.hpp>	// Pascal unit
#include <IB.hpp>	// Pascal unit
#include <IBExternals.hpp>	// Pascal unit
#include <IBHeader.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibevents
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TEventAlert)(System::TObject* Sender, AnsiString EventName, int EventCount, bool &CancelAlerts);

typedef void __fastcall (__closure *TErrorEvent)(System::TObject* Sender, int ErrorCode);

class DELPHICLASS TIBEvents;
class PASCALIMPLEMENTATION TIBEvents : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Classes::TStrings* FEvents;
	TEventAlert FOnEventAlert;
	Classes::TList* FThreads;
	void * *FNativeHandle;
	bool ThreadException;
	Ibdatabase::TIBDatabase* FDatabase;
	TErrorEvent FOnError;
	bool FAutoRegister;
	bool FRegistered;
	void __fastcall SetDatabase(Ibdatabase::TIBDatabase* value);
	void __fastcall SetEvents(Classes::TStrings* Value);
	bool __fastcall GetRegistered(void);
	void __fastcall SetRegistered(const bool Value);
	
protected:
	virtual Ibexternals::PVoid __fastcall GetNativeHandle(void);
	virtual void __fastcall EventChange(System::TObject* Sender);
	virtual void __fastcall ThreadEnded(System::TObject* Sender);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall ValidateDatabase(Ibdatabase::TIBDatabase* DataBase);
	
public:
	__fastcall virtual TIBEvents(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBEvents(void);
	virtual void __fastcall RegisterEvents(void);
	virtual void __fastcall UnRegisterEvents(void);
	__property Ibexternals::PVoid NativeHandle = {read=GetNativeHandle};
	void __fastcall SetAutoRegister(const bool Value);
	bool __fastcall GetAutoRegister(void);
	
__published:
	__property bool AutoRegister = {read=GetAutoRegister, write=SetAutoRegister, nodefault};
	__property Ibdatabase::TIBDatabase* Database = {read=FDatabase, write=SetDatabase};
	__property Classes::TStrings* Events = {read=FEvents, write=SetEvents};
	__property bool Registered = {read=GetRegistered, write=SetRegistered, nodefault};
	__property TEventAlert OnEventAlert = {read=FOnEventAlert, write=FOnEventAlert};
	__property TErrorEvent OnError = {read=FOnError, write=FOnError};
private:
	void *__IIBEventNotifier;	/* Ibdatabase::IIBEventNotifier */
	
public:
	operator IIBEventNotifier*(void) { return (IIBEventNotifier*)&__IIBEventNotifier; }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Ibevents */
using namespace Ibevents;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBEvents
