// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdThread.pas' rev: 6.00

#ifndef IdThreadHPP
#define IdThreadHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idthread
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdThreadStopMode { smTerminate, smSuspend };
#pragma option pop

typedef void __fastcall (__closure *TIdExceptionEvent)(System::TObject* Sender, Sysutils::Exception* E);

class DELPHICLASS TIdThread;
class PASCALIMPLEMENTATION TIdThread : public Classes::TThread 
{
	typedef Classes::TThread inherited;
	
protected:
	System::TObject* FData;
	TIdThreadStopMode FStopMode;
	bool FStopped;
	AnsiString FTerminatingException;
	TIdExceptionEvent FOnException;
	bool __fastcall GetStopped(void);
	virtual void __fastcall Execute(void);
	virtual void __fastcall Run(void) = 0 ;
	virtual void __fastcall AfterRun(void);
	virtual void __fastcall BeforeRun(void);
	
public:
	__fastcall virtual TIdThread(bool ACreateSuspended);
	__fastcall virtual ~TIdThread(void);
	void __fastcall Start(void);
	void __fastcall Stop(void);
	HIDESBASE void __fastcall Synchronize(Classes::TThreadMethod Method);
	virtual void __fastcall TerminateAndWaitFor(void);
	__property AnsiString TerminatingException = {read=FTerminatingException};
	__property System::TObject* Data = {read=FData, write=FData};
	__property TIdThreadStopMode StopMode = {read=FStopMode, write=FStopMode, nodefault};
	__property bool Stopped = {read=GetStopped, nodefault};
	__property TIdExceptionEvent OnException = {read=FOnException, write=FOnException};
	__property Terminated ;
};


typedef TMetaClass*TIdThreadClass;

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idthread */
using namespace Idthread;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdThread
