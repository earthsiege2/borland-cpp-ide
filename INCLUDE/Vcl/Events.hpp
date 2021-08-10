// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Events.pas' rev: 6.00

#ifndef EventsHPP
#define EventsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Events
{
//-- type declarations -------------------------------------------------------
struct THandler;
typedef THandler *PHandler;

struct THandler
{
	Classes::TNotifyEvent Handler;
} ;

class DELPHICLASS TEvent;
class PASCALIMPLEMENTATION TEvent : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	Classes::TList* List;
	
public:
	__fastcall TEvent(void);
	__fastcall virtual ~TEvent(void);
	void __fastcall Add(Classes::TNotifyEvent AHandler);
	int __fastcall IndexOf(Classes::TNotifyEvent AHandler);
	void __fastcall Remove(Classes::TNotifyEvent AHandler);
	void __fastcall Send(System::TObject* Sender);
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Events */
using namespace Events;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Events
